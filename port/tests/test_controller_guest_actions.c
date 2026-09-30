#include "controller_guest_actions.h"
#include <stdio.h>
#include <string.h>
static uint8_t mem[0x100000], before[0x100000];
static controller_guest_ui_view view = {mem,sizeof(mem),0x3961};
#define DS 0x39610u
#define RECORDS 0x50000u
static int failed;
#define CHECK(x) do {if(!(x)){fprintf(stderr,"line%d: %s\n",__LINE__,#x);failed++;}}while(0)
static void w(size_t p,uint16_t v){mem[p]=(uint8_t)v;mem[p+1]=(uint8_t)(v>>8);}
static void pointer(int x,int y){w(DS+0x69e4,(uint16_t)x);w(DS+0x69e6,(uint16_t)y);}
static void rec(unsigned i,unsigned type,int x0,int y0,int x1,int y1,unsigned object){
 size_t p=RECORDS+i*20u;mem[p]=(uint8_t)type;w(p+2,(uint16_t)x0);w(p+4,(uint16_t)y0);w(p+6,(uint16_t)x1);w(p+8,(uint16_t)y1);w(p+10,(uint16_t)object);
}
static void reset(unsigned count){memset(mem,0,sizeof(mem));w(DS+0x51de,1);w(DS+0x67c4,0x5000);w(DS+0x67e2,(uint16_t)count);view.dgroup_segment=0x3961;view.memory_size=sizeof(mem);}
int main(void){
 controller_guest_action_target t={0}, old;
 reset(2);rec(0,3,10,10,90,90,9);rec(1,7,40,40,60,60,10);pointer(20,20);w(DS+0x0062,9);
 memcpy(before,mem,sizeof(mem));
 CHECK(controller_guest_action_resolve(&view,CONTROLLER_GUEST_ACTION_SNAP,&t)==CONTROLLER_GUEST_UI_HIT && t.group==0 && t.index==0 && t.verb_id==0);
 controller_guest_ui_region hit;
 CHECK(controller_guest_ui_hit(&view,t.x,t.y,&hit)==CONTROLLER_GUEST_UI_HIT && hit.index==0);
 CHECK(!memcmp(mem,before,sizeof(mem)));
 old=t;w(DS+0x0062,10);CHECK(controller_guest_action_resolve(&view,CONTROLLER_GUEST_ACTION_SNAP,&t)==CONTROLLER_GUEST_UI_NONE && !memcmp(&old,&t,sizeof(t)));
 pointer(50,50);CHECK(controller_guest_action_resolve(&view,CONTROLLER_GUEST_ACTION_SNAP,&t)==CONTROLLER_GUEST_UI_HIT && t.index==1);
 mem[RECORDS+21]=0x80;CHECK(controller_guest_action_resolve(&view,CONTROLLER_GUEST_ACTION_SNAP,&t)==CONTROLLER_GUEST_UI_NONE);
 w(DS+0x0062,0);CHECK(controller_guest_action_resolve(&view,CONTROLLER_GUEST_ACTION_SNAP,&t)==CONTROLLER_GUEST_UI_NONE);
 /* Concave centre lies outside. Snap must still return this exact object. */
 reset(1);rec(0,3,10,10,90,90,9);pointer(20,50);w(DS+0x0062,9);w(RECORDS+14,8);w(RECORDS+18,0x6000);
 const int points[8][2]={{10,10},{90,10},{90,30},{30,30},{30,70},{90,70},{90,90},{10,90}};
 for(unsigned i=0;i<8;i++){w(0x60000+i*4u,(uint16_t)points[i][0]);w(0x60002+i*4u,(uint16_t)points[i][1]);}
 CHECK(controller_guest_action_resolve(&view,CONTROLLER_GUEST_ACTION_SNAP,&t)==CONTROLLER_GUEST_UI_HIT);
 CHECK(controller_guest_ui_hit(&view,t.x,t.y,&hit)==CONTROLLER_GUEST_UI_HIT && hit.object_id==9);
 /* Standard+context rows are live; inclusive blank bottom never cycles. */
 reset(8);rec(6,8,2,4,49,24,0);rec(7,8,2,34,49,54,0);
 w(DS+0x5c32,10);w(DS+0x5a32,0x7000);w(DS+0x0102,2);w(0x70000,11);w(0x70002,12);
 w(DS+0x5c36,0x7100);w(0x71000,21);w(0x71002,22);pointer(100,100);
 memcpy(before,mem,sizeof(mem));
 CHECK(controller_guest_action_resolve(&view,CONTROLLER_GUEST_ACTION_NEXT_VERB,&t)==CONTROLLER_GUEST_UI_HIT && t.verb_id==11);
 CHECK(controller_guest_action_resolve(&view,CONTROLLER_GUEST_ACTION_PREVIOUS_VERB,&t)==CONTROLLER_GUEST_UI_HIT && t.verb_id==22);
 pointer(t.x,t.y);CHECK(controller_guest_action_resolve(&view,CONTROLLER_GUEST_ACTION_NEXT_VERB,&t)==CONTROLLER_GUEST_UI_HIT && t.verb_id==11);
 pointer(t.x,t.y);CHECK(controller_guest_action_resolve(&view,CONTROLLER_GUEST_ACTION_PREVIOUS_VERB,&t)==CONTROLLER_GUEST_UI_HIT && t.verb_id==22);
 pointer(25,14);CHECK(controller_guest_action_resolve(&view,CONTROLLER_GUEST_ACTION_NEXT_VERB,&t)==CONTROLLER_GUEST_UI_HIT && t.verb_id==21);
 pointer(25,54);CHECK(controller_guest_action_resolve(&view,CONTROLLER_GUEST_ACTION_NEXT_VERB,&t)==CONTROLLER_GUEST_UI_HIT && t.verb_id==11);
 pointer(100,100);CHECK(!memcmp(mem,before,sizeof(mem)));
 w(0x71000,31);pointer(25,14);CHECK(controller_guest_action_resolve(&view,CONTROLLER_GUEST_ACTION_NEXT_VERB,&t)==CONTROLLER_GUEST_UI_HIT && t.verb_id==31);
 w(DS+0x0056,1);CHECK(controller_guest_action_resolve(&view,CONTROLLER_GUEST_ACTION_NEXT_VERB,&t)==CONTROLLER_GUEST_UI_NONE);w(DS+0x0056,0);
 pointer(-1,20);CHECK(controller_guest_action_resolve(&view,CONTROLLER_GUEST_ACTION_SNAP,&t)==CONTROLLER_GUEST_UI_INVALID);
 pointer(320,20);CHECK(controller_guest_action_resolve(&view,CONTROLLER_GUEST_ACTION_SNAP,&t)==CONTROLLER_GUEST_UI_INVALID);
 pointer(20,200);CHECK(controller_guest_action_resolve(&view,CONTROLLER_GUEST_ACTION_SNAP,&t)==CONTROLLER_GUEST_UI_INVALID);
 pointer(20,20);view.dgroup_segment=0;CHECK(controller_guest_action_resolve(&view,CONTROLLER_GUEST_ACTION_SNAP,&t)==CONTROLLER_GUEST_UI_INVALID);view.dgroup_segment=0x3961;
 CHECK(controller_guest_action_resolve(NULL,CONTROLLER_GUEST_ACTION_SNAP,&t)==CONTROLLER_GUEST_UI_INVALID);
 CHECK(controller_guest_action_resolve(&view,(controller_guest_action)0,&t)==CONTROLLER_GUEST_UI_INVALID);
 CHECK(controller_guest_action_resolve(&view,CONTROLLER_GUEST_ACTION_SNAP,NULL)==CONTROLLER_GUEST_UI_INVALID);
 w(DS+0x5c32,0);CHECK(controller_guest_action_resolve(&view,CONTROLLER_GUEST_ACTION_NEXT_VERB,&t)==CONTROLLER_GUEST_UI_INVALID);
 if(!failed)puts("Guest action snap/verb cycle/live/read-only/rejection tests passed");
 return failed?1:0;
}
