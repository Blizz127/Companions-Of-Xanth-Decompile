extern char __near mb0327;
extern char __near mb0326;
extern char __near mb0328;
char g0;
char g1;
char g2;
void far helper_mkfp(void);
int far if15_195940(int a)
{
    _asm {
        cmp word ptr [bp+0x6],0xf
        jz short $+27
        cmp byte ptr mb0327,0x0
        jz short $+9
        cmp byte ptr mb0326,0x0
        jz short $+57
L14:
        cmp byte ptr mb0328,0x0
        jnz short $+50
L1B:
        xor ax,ax
        jmp short $+49
L1F:
        cmp byte ptr mb0327,0x0
        jnz short $+19
        mov ax,0x56
L29:
        mov dx,0xf021
        push dx
        push ax
        call far ptr helper_mkfp
        mov sp,bp
        jmp short $+-26
L37:
        cmp byte ptr mb0326,0x0
        jz short $+15
        cmp byte ptr mb0328,0x0
        jnz short $+8
        mov ax,0x57
        jmp short $+-31
        nop
L4B:
        mov ax,0x102
L4E:
    }
}
