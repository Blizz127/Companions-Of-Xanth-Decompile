/* Test-only SDL driver. Uses ordinary SDL input and a neutral virtual pad.
 * No game memory access, VM callbacks, or guest-state observer. */
#define _GNU_SOURCE
#include <SDL.h>
#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {long frame; char kind; int a,b;} command;
static command commands[256];static int count,next,initialized;
static long frame;
static SDL_Joystick *pad;
static int (*poll_real)(SDL_Event*);
static void (*present_real)(SDL_Renderer*);
static void setup(void){
 initialized=1;
 /* Disabled-controller runs still receive a genuine virtual SDL device. */
 if (!(SDL_WasInit(SDL_INIT_GAMECONTROLLER) & SDL_INIT_GAMECONTROLLER))
     SDL_InitSubSystem(SDL_INIT_GAMECONTROLLER);
 SDL_VirtualJoystickDesc d={0};d.version=SDL_VIRTUAL_JOYSTICK_DESC_VERSION;
 d.type=SDL_JOYSTICK_TYPE_GAMECONTROLLER;d.naxes=SDL_CONTROLLER_AXIS_MAX;d.nbuttons=SDL_CONTROLLER_BUTTON_MAX;
 d.button_mask=(1u<<SDL_CONTROLLER_BUTTON_MAX)-1;d.axis_mask=(1u<<SDL_CONTROLLER_AXIS_MAX)-1;
 d.name="Xanth blackbox neutral pad";d.vendor_id=0x1234;d.product_id=0x5678;
 int index=SDL_JoystickAttachVirtualEx(&d);if(index>=0)pad=SDL_JoystickOpen(index);
 fprintf(stderr,"[padshim] neutral attach index=%d success=%d\n",index,pad!=NULL);
 const char *path=getenv("XANTH_PAD_SCRIPT");FILE*f=path?fopen(path,"r"):NULL;
 if(f){char line[128];while(count<256&&fgets(line,sizeof(line),f)){
 command c={0};if(sscanf(line,"%ld %c %d %d",&c.frame,&c.kind,&c.a,&c.b)>=2)commands[count++]=c;
 }fclose(f);}
}
int SDL_PollEvent(SDL_Event *e){
 if(!poll_real)poll_real=(int(*)(SDL_Event*))dlsym(RTLD_NEXT,"SDL_PollEvent");
 if(!initialized)setup();
 if(next<count&&frame>=commands[next].frame){
 command c=commands[next++];memset(e,0,sizeof(*e));
 fprintf(stderr,"[padshim] frame=%ld kind=%c a=%d b=%d\n",frame,c.kind,c.a,c.b);
 if(c.kind=='K'){e->type=c.a?SDL_KEYDOWN:SDL_KEYUP;e->key.state=c.a?SDL_PRESSED:SDL_RELEASED;e->key.keysym.sym=SDLK_SPACE;e->key.keysym.scancode=SDL_SCANCODE_SPACE;return 1;}
 if(c.kind=='M'){SDL_Window*w=SDL_GetKeyboardFocus();if(!w)w=SDL_GetWindowFromID(1);int ww=320,wh=200;if(w)SDL_GetWindowSize(w,&ww,&wh);e->type=SDL_MOUSEMOTION;e->motion.windowID=w?SDL_GetWindowID(w):1;e->motion.x=c.a*ww/320;e->motion.y=c.b*wh/200;return 1;}
 if(c.kind=='B'&&pad){SDL_JoystickSetVirtualButton(pad,c.a,(Uint8)c.b);SDL_JoystickUpdate();}
 }
 return poll_real(e);
}
void SDL_RenderPresent(SDL_Renderer *r){
 if(!present_real)present_real=(void(*)(SDL_Renderer*))dlsym(RTLD_NEXT,"SDL_RenderPresent");
 present_real(r);frame++;
}
