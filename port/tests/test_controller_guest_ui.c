#include "controller_guest_ui.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MEM_SIZE 0x100000u
static uint8_t memory[MEM_SIZE], before[MEM_SIZE];
static controller_guest_ui_view view = {memory, MEM_SIZE, 0x3961};
static const size_t ds = (0x00b2u + 0x38afu) * 16u;
static const size_t records = 0x50000u;
static int failures;
#define CHECK(c) do { if (!(c)) { fprintf(stderr,"line %d: %s\n",__LINE__,#c); failures++; } } while(0)
static void w(size_t p, uint16_t v) {memory[p]=(uint8_t)v;memory[p+1]=(uint8_t)(v>>8);}
static void reset(uint16_t count) {
    memset(memory,0,sizeof(memory));w(ds+0x51de,1);w(ds+0x67c2,0);w(ds+0x67c4,0x5000);w(ds+0x67e2,count);
}
static void region(unsigned i, uint8_t type, uint8_t flags, int x0,int y0,int x1,int y1,uint16_t object) {
    size_t p=records+i*20u;memory[p]=type;memory[p+1]=flags;
    w(p+2,(uint16_t)x0);w(p+4,(uint16_t)y0);w(p+6,(uint16_t)x1);w(p+8,(uint16_t)y1);w(p+10,object);
}
static void polygon(unsigned i,const int16_t points[][2],unsigned n) {
    size_t p=records+i*20u;w(p+14,(uint16_t)n);w(p+16,0);w(p+18,0x6000);
    for(unsigned j=0;j<n;j++){w(0x60000+j*4u,(uint16_t)points[j][0]);w(0x60002+j*4u,(uint16_t)points[j][1]);}
}
int main(void) {
    controller_guest_ui_region hit,list[2];size_t count;int16_t sx,sy;
    reset(3);region(0,3,0,10,10,90,90,1);region(1,7,0,40,40,60,60,2);region(2,5,0x80,0,0,100,100,3);
    memcpy(before,memory,sizeof(memory));
    CHECK(controller_guest_ui_hit(&view,50,50,&hit)==CONTROLLER_GUEST_UI_HIT && hit.index==1 && hit.object_id==2);
    CHECK(controller_guest_ui_hit(&view,10,10,&hit)==CONTROLLER_GUEST_UI_HIT && hit.index==0);
    CHECK(controller_guest_ui_hit(&view,9,10,&hit)==CONTROLLER_GUEST_UI_NONE);
    CHECK(controller_guest_ui_candidates(&view,list,2,&count)==CONTROLLER_GUEST_UI_HIT && count==2);
    CHECK(controller_guest_ui_snap(&view,0,0,50,50,&sx,&sy)==CONTROLLER_GUEST_UI_HIT);
    CHECK(controller_guest_ui_hit(&view,sx,sy,&hit)==CONTROLLER_GUEST_UI_HIT && hit.index==0);
    CHECK(!memcmp(before,memory,sizeof(memory)));
    /* No rectangle centre shortcut: the centre of this C-shaped polygon is outside. */
    const int16_t concave[][2]={{10,10},{90,10},{90,30},{30,30},{30,70},{90,70},{90,90},{10,90}};
    reset(1);region(0,3,0,10,10,90,90,9);polygon(0,concave,8);
    CHECK(controller_guest_ui_hit(&view,50,50,&hit)==CONTROLLER_GUEST_UI_NONE);
    CHECK(controller_guest_ui_hit(&view,20,50,&hit)==CONTROLLER_GUEST_UI_HIT);
    CHECK(controller_guest_ui_snap(&view,0,0,50,50,&sx,&sy)==CONTROLLER_GUEST_UI_HIT);
    CHECK(controller_guest_ui_hit(&view,sx,sy,&hit)==CONTROLLER_GUEST_UI_HIT);
    /* Inclusive horizontal boundaries, vertex scanlines, repeated vertices. */
    const int16_t edges[][2]={{0,0},{5,0},{10,0},{10,10},{10,10},{0,10}};
    polygon(0,edges,6);region(0,3,0,0,0,10,10,9);
    for(int y=0;y<=10;y++)for(int x=0;x<=10;x++)
        CHECK(controller_guest_ui_hit(&view,(int16_t)x,(int16_t)y,&hit)==CONTROLLER_GUEST_UI_HIT);
    /* Complete occlusion and state changes re-read without a cache. */
    reset(2);region(0,3,0,0,0,10,10,1);region(1,7,0,0,0,10,10,2);
    CHECK(controller_guest_ui_snap(&view,0,0,5,5,&sx,&sy)==CONTROLLER_GUEST_UI_NONE);
    memory[records+21]=0x80;
    CHECK(controller_guest_ui_snap(&view,0,0,5,5,&sx,&sy)==CONTROLLER_GUEST_UI_HIT && sx==5 && sy==5);
    /* Group order participates in last-wins precedence. */
    w(ds+0x51de,2);w(ds+0x67c6,20);w(ds+0x67c8,0x5000);w(ds+0x67e4,1);memory[records+21]=0;
    CHECK(controller_guest_ui_hit(&view,5,5,&hit)==CONTROLLER_GUEST_UI_HIT && hit.group==1 && hit.index==0);
    /* Invalid layouts decline, including signed-negative counts and all far span wraps. */
    w(ds+0x51de,9);CHECK(controller_guest_ui_hit(&view,5,5,&hit)==CONTROLLER_GUEST_UI_INVALID);
    reset(0xffff);CHECK(controller_guest_ui_hit(&view,5,5,&hit)==CONTROLLER_GUEST_UI_INVALID);
    reset(1);w(ds+0x67c2,0xfff8);CHECK(controller_guest_ui_hit(&view,5,5,&hit)==CONTROLLER_GUEST_UI_INVALID);
    reset(1);w(ds+0x67c2,0xfff8);w(ds+0x67c4,0xffff);CHECK(controller_guest_ui_hit(&view,5,5,&hit)==CONTROLLER_GUEST_UI_INVALID);
    reset(1);region(0,3,0,0,0,10,10,1);w(records+14,257);CHECK(controller_guest_ui_hit(&view,5,5,&hit)==CONTROLLER_GUEST_UI_INVALID);
    w(records+14,3);w(records+16,0xfffe);w(records+18,0x6000);CHECK(controller_guest_ui_hit(&view,5,5,&hit)==CONTROLLER_GUEST_UI_INVALID);
    w(records+16,0);w(records+18,0);CHECK(controller_guest_ui_hit(&view,5,5,&hit)==CONTROLLER_GUEST_UI_INVALID);
    view.memory_size=16;CHECK(controller_guest_ui_hit(&view,5,5,&hit)==CONTROLLER_GUEST_UI_INVALID);view.memory_size=MEM_SIZE;
    /* Only observer-verified DGROUP is accepted; there is no CPU DS field. */
    view.dgroup_segment=0;CHECK(controller_guest_ui_hit(&view,0,0,&hit)==CONTROLLER_GUEST_UI_INVALID);view.dgroup_segment=0xffff;CHECK(controller_guest_ui_hit(&view,0,0,&hit)==CONTROLLER_GUEST_UI_INVALID);view.dgroup_segment=0x3961;
    CHECK(controller_guest_ui_hit(NULL,0,0,&hit)==CONTROLLER_GUEST_UI_INVALID);
    /* Actual lists, live font pitch, inclusive blank bottom, and occlusion. */
    controller_guest_ui_verb_row rows[10];
    reset(8);region(6,8,0,2,4,49,74,0);region(7,8,0,2,84,49,104,0);
    w(ds+0x5c32,10);w(ds+0x5a32,0x7000);w(ds+0x0102,7);
    for(unsigned i=0;i<7;i++)w(0x70000+i*2u,(uint16_t)(20+i));
    w(ds+0x5c34,0);w(ds+0x5c36,0x7100);w(0x71000,58);w(0x71002,73);
    memcpy(before,memory,sizeof(memory));
    CHECK(controller_guest_ui_verb_rows(&view,rows,10,&count)==CONTROLLER_GUEST_UI_HIT && count==9);
    CHECK(rows[0].verb_id==20 && rows[0].row_top==4 && rows[6].row_top==64);
    CHECK(rows[7].verb_id==58 && rows[7].row_top==84 && rows[8].verb_id==73 && rows[8].row_top==94);
    for(size_t i=0;i<count;i++)CHECK(controller_guest_ui_hit(&view,rows[i].x,rows[i].y,&hit)==CONTROLLER_GUEST_UI_HIT && hit.group==rows[i].group && hit.index==rows[i].index);
    CHECK(!memcmp(before,memory,sizeof(memory)));
    CHECK(controller_guest_ui_verb_rows(&view,rows,1,&count)==CONTROLLER_GUEST_UI_HIT && count==9);
    /* Font/table mutations are read live, never remembered. */
    w(ds+0x5c32,20);CHECK(controller_guest_ui_verb_rows(&view,rows,10,&count)==CONTROLLER_GUEST_UI_HIT && count==6);
    w(ds+0x5c32,0);CHECK(controller_guest_ui_verb_rows(&view,rows,10,&count)==CONTROLLER_GUEST_UI_INVALID);
    w(ds+0x5c32,10);w(ds+0x0102,65);CHECK(controller_guest_ui_verb_rows(&view,rows,10,&count)==CONTROLLER_GUEST_UI_INVALID && count==0);
    w(ds+0x0102,7);w(0x7000e,1);CHECK(controller_guest_ui_verb_rows(&view,rows,10,&count)==CONTROLLER_GUEST_UI_INVALID);w(0x7000e,0);
    w(ds+0x5c34,0xfffe);w(0x80ffe,1);CHECK(controller_guest_ui_verb_rows(&view,rows,10,&count)==CONTROLLER_GUEST_UI_INVALID);
    w(ds+0x5c34,0);w(ds+0x5c36,0);CHECK(controller_guest_ui_verb_rows(&view,rows,10,&count)==CONTROLLER_GUEST_UI_INVALID);
    w(ds+0x5c36,0x7100);for(unsigned i=0;i<=64;i++)w(0x71000+i*2u,1);
    CHECK(controller_guest_ui_verb_rows(&view,rows,10,&count)==CONTROLLER_GUEST_UI_INVALID);
    w(0x71004,0);memory[records+7*20+1]=0x80;
    CHECK(controller_guest_ui_verb_rows(&view,rows,10,&count)==CONTROLLER_GUEST_UI_HIT && count==7);
    reset(17);
    for(unsigned i=0;i<17;i++){region(i,3,0,0,0,10,10,1);w(records+i*20u+14,256);w(records+i*20u+18,0x6000);}
    CHECK(controller_guest_ui_hit(&view,1,1,&hit)==CONTROLLER_GUEST_UI_INVALID);
    /* Disabled malformed polygons are skipped exactly as retail does. */
    reset(1);region(0,3,0x80,0,0,10,10,1);w(records+14,0xffff);
    CHECK(controller_guest_ui_hit(&view,1,1,&hit)==CONTROLLER_GUEST_UI_NONE);
    CHECK(controller_guest_ui_candidates(&view,list,2,&count)==CONTROLLER_GUEST_UI_NONE && count==0);
    if(!failures)puts("Guest UI synthetic geometry/overlap/read-only/bounds checks passed");
    return failures?1:0;
}
