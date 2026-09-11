extern int __near mn5AFC;
extern int __near mn5AF8;
extern int __near mn5AFE;
extern int __near mn5AFA;
void far helper_0(void);
int far ovl_223532(int a)
{
    _asm {
        sub sp,0x4
        mov al,[bp+0x8]
        cbw
        imul word ptr mn5AFC
        add ax,mn5AF8
        mov [bp-0x2],ax
        mov al,[bp+0x9]
        mov cl,0x2
        cbw
        idiv cl
        cbw
        imul word ptr mn5AFE
        add ax,mn5AFA
        mov [bp-0x4],ax
        test byte ptr [bp+0x9],0x1
        jz short $+21
        add word ptr [bp-0x4],0x4
        mov ax,[bp-0x4]
        add ax,0x19
        push ax
        mov ax,[bp-0x2]
        add ax,0x4
        jmp short $+16
L3F:
        add word ptr [bp-0x2],0x4
        add ax,0x4
        push ax
        mov ax,[bp-0x2]
        add ax,0x1e
L4D:
        push ax
        push word ptr [bp-0x4]
        push word ptr [bp-0x2]
        call far ptr helper_0
    }
}
