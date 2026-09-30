/* Synthetic guest INT33 handler regression; no retail assets or game-state edits. */
#ifndef _DEFAULT_SOURCE
#define _DEFAULT_SOURCE
#endif
#include "vm.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
/* 16-bit guest: install ES:0015 via INT33 AX=0014, CX=001F; wait with
 * INT16. The far handler preserves BP/BX, writes AX/BX/CX/DX to records
 * at 003F + count*8, increments word [003D], then RETF. This exercises
 * the real VM callback trampoline, including events posted while it runs. */
static const unsigned char code[] = { 0x0e, 0x1f, 0x0e, 0x07, 0xb8, 0x14, 0x00, 0xb9, 0x1f, 0x00, 0xba, 0x15, 0x00, 0xcd, 0x33, 0x31, 0xc0, 0xcd, 0x16, 0xeb, 0xfa, 0x55, 0x89, 0xe5, 0x53, 0x8b, 0x1e, 0x3d, 0x00, 0xd1, 0xe3, 0xd1, 0xe3, 0xd1, 0xe3, 0x89, 0x87, 0x3f, 0x00, 0x8b, 0x46, 0xfe, 0x89, 0x87, 0x41, 0x00, 0x89, 0x8f, 0x43, 0x00, 0x89, 0x97, 0x45, 0x00, 0xff, 0x06, 0x3d, 0x00, 0x5b, 0x5d, 0xcb, 0x00, 0x00 };
static void word(unsigned char *p, unsigned v) { p[0]=v; p[1]=v>>8; }
static unsigned read_word(unsigned s,unsigned o) { unsigned a=s*16+o; return g_dos_mem[a] | (g_dos_mem[a+1]<<8); }
int main(void) {
 char directory[]="/tmp/xanth-mouse-XXXXXX", path[512],err[512];
 vm_config cfg={0}; vm *v=calloc(1,sizeof(*v)); unsigned char exe[512]={0}; int failed=0;
 if(!mkdtemp(directory)||!v)return 2;
 snprintf(path,sizeof(path),"%s/CLICK.EXE",directory);
 word(exe,0x5a4d); word(exe+2,512); word(exe+4,1); word(exe+8,2);
 word(exe+10,0x100); word(exe+12,0xffff); word(exe+16,0xff0); word(exe+24,0x1c);
 memcpy(exe+32,code,sizeof(code)); FILE*f=fopen(path,"wb"); if(!f)return 2;
 fwrite(exe,1,sizeof(exe),f); fclose(f);
 snprintf(cfg.exe_path,sizeof(cfg.exe_path),"%s",path);
 snprintf(cfg.data_dir,sizeof(cfg.data_dir),"%s",directory);
 snprintf(cfg.save_dir,sizeof(cfg.save_dir),"%s",directory);
 if(!vm_init(v,&cfg,err,sizeof(err))){fprintf(stderr,"%s\n",err);return 2;}
 vm_run(v,1000);
 unsigned segment=v->m33_handler_seg;
 vm_post_mouse_move(v,10,20); vm_post_mouse_button(v,0,true);
 vm_post_mouse_move(v,50,60); vm_post_mouse_button(v,0,false);
 vm_run(v,1);
 if(!v->m33_in_callback)failed=1;
 vm_post_mouse_button(v,1,true); vm_post_mouse_button(v,1,false);
 vm_run(v,1000);
 unsigned count=read_word(segment,0x3d);
 printf("callback count=%u\n",count);
 for(unsigned i=0;i<count&&i<16;i++)printf("callback %u: cond=%u buttons=%u x=%u y=%u\n",i,read_word(segment,0x3f+8*i),read_word(segment,0x41+8*i),read_word(segment,0x43+8*i),read_word(segment,0x45+8*i));
 /* MOVE coalesces with its following edge only at matching coordinates.
  * The second pair arrives during a running handler and must queue, not recurse. */
 const unsigned expected[4][4] = {
     {3, 1, 20, 20}, {5, 0, 100, 60},
     {8, 2, 100, 60}, {16, 0, 100, 60}
 };
 if(count != 4) failed = 1;
 for(unsigned i = 0; i < 4; i++) {
     for(unsigned field = 0; field < 4; field++) {
         if(read_word(segment, 0x3f + 8*i + 2*field) != expected[i][field])
             failed = 1;
     }
 }
 if(v->cpu.fault || v->m33_in_callback)failed=1;
 vm_shutdown(v);free(v);unlink(path); snprintf(path,sizeof(path),"%s/LEGEND.INI",directory);unlink(path);rmdir(directory);
 printf("VM mouse callback order %s\n",failed?"FAIL":"PASS");return failed;
}
