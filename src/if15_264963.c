extern char __near mb030E;
extern char __near mb1D00;
extern int __near mn02A8;
char gflag;
char gclear;
int g1;
void far helper3(void);
void far helper2(void);
void far helper1(void);
int far if15_264963(int a)
{
    _asm {
        cmp word ptr [bp+0x6],0xf
        jz short $+7
L06:
        mov ax,0x14f
        jmp short $+59
L0B:
        cmp byte ptr mb030E,0x0
        jnz short $+-10
        mov byte ptr mb1D00,0x0
        mov ax,0xe19
        push ax
        mov ax,0x369
        push ax
        call far ptr helper3
        mov sp,bp
        cmp word ptr mn02A8,0x16
        jnz short $+14
        mov ax,0x5a
        push ax
        call far ptr helper2
        jmp short $+12
        nop
L39:
        mov ax,0x10
        push ax
        call far ptr helper1
L42:
        xor ax,ax
L44:
    }
}
