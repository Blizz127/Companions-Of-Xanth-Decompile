extern int __near mn5A56;
extern char __near mb0020;
void far helper_0(void);
int far exe_61482(int a)
{
    _asm {
        sub sp,0x4
        mov ax,0x10
        push ax
        call far ptr helper_0
        add sp,0x2
        mov [bp-0x2],ax
        mov word ptr [bp-0x4],0xfa0
        mov es, mn5A56
        cmp byte ptr es:mb0020,0x0
        jz short $+7
        mov word ptr [bp-0x4],0x7d0
L28:
        cmp [bp-0x4],ax
        jna short $+10
        mov word ptr [bp-0x2],0x0
        jmp short $+9
        nop
L35:
        mov ax,[bp-0x4]
        sub [bp-0x2],ax
L3B:
        mov ax,[bp-0x2]
    }
}
