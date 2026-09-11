extern int __near mn53CA;
extern int __near mn53BA;
extern char __near mb53C2;
extern char __near mb53C3;
extern int __near mn53C8;
void far helper_0(void);
int far exe_15056(int a)
{
    _asm {
        mov si,[bp+0x6]
        or si,si
        jl short $+8
        cmp mn53CA,si
        jg short $+14
lbl0F:
        mov word ptr mn53BA,0x9
        mov ax,0xffff
        jmp short $+56
        nop
lbl1B:
        mov al,mb53C2
        mov ah,mb53C3
        cmp ax,0x31e
        jnl short $+6
        xor ax,ax
        jmp short $+39
lbl2B:
        test byte ptr [si+0x53cc],0x1
        jz short $+21
        push si
        call far ptr helper_0
        add sp,0x2
        mov di,ax
        or di,ax
        jz short $+15
        mov mn53C8,di
lbl45:
        mov word ptr mn53BA,0x9
        mov di,0xffff
lbl4E:
        mov ax,di
lbl50:
    }
}
