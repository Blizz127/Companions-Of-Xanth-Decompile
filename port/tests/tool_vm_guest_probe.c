/* Read-only evidence tool. Dumps owner guest memory only to an explicitly
 * requested scratch directory; never distributes or changes guest state. */
#include "vm.h"
#include <stdio.h>
#include <stdlib.h>
static unsigned snapshot_number;
static void snapshot(vm *v) {
    const char *directory=getenv("XANTH_GUEST_SNAPSHOTS");
    char path[1024];
    if(!directory || !*directory) return;
    snprintf(path,sizeof(path),"%s/%03u_%d_%d.bin",directory,
             snapshot_number++,v->mouse_x,v->mouse_y);
    FILE *file=fopen(path,"wb");
    if(!file) { perror(path); exit(2); }
    if(fwrite(g_dos_mem,1,DOS_MEM_SIZE,file)!=DOS_MEM_SIZE) exit(2);
    fclose(file);
    uint16_t dgroup=v->img.load_seg+0x38af;
    fprintf(stderr,"[guest snapshot] %s load=%04X dgroup=%04X hoververb=%04X hoverobject=%04X selectedverb=%04X\n",
            path,v->img.load_seg,dgroup,seg_r16(dgroup,0x60),
            seg_r16(dgroup,0x62),seg_r16(dgroup,0x50));
}
static void observed_move(vm *v,int x,int y) {
    snapshot(v);
    vm_post_mouse_move(v,x,y);
}
static void observed_shutdown(vm *v) { snapshot(v); vm_shutdown(v); }
#define vm_post_mouse_move observed_move
#define vm_shutdown observed_shutdown
#include "tool_vmboot.c"
