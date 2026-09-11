extern int __near mn6A06;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
int far ovl_73228(int a)
{
    _asm {
        sub sp,0x4
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+10
        dec ax
        dec ax
        jz short $+46
        jmp LA3
        nop
L13:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+5
        jmp LA3
L1E:
        cmp word ptr mn6A04,0x24
        jz short $+128
        mov ax,0xe
L28:
        mov dx,0xf003
        push dx
        push ax
        call far ptr helper_0
        add sp,0x4
L35:
        mov ax,0x1
        jmp short $+109
        nop
L3B:
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+92
        ja short $+96
        sub al,0x8
        jz short $+16
        sub al,0xb
        jz short $+18
        sub al,0x19
        jz short $+8
        sub al,0x18
        jz short $+68
        jmp short $+78
L57:
        mov ax,0xc
        jmp short $-50
        nop
L5D:
        push word ptr mn6A04
        mov ax,0x24
        push ax
        call far ptr helper_1
        add sp,0x4
        or ax,ax
        jz short $+10
        mov ax,0x1f13
        mov dx,ds
        jmp short $+6
        nop
L79:
        xor ax,ax
        cwd
L7C:
        mov [bp-0x4],ax
        mov [bp-0x2],dx
        push dx
        push ax
        mov ax,0xb
        mov dx,0xf003
        push dx
        push ax
        call far ptr helper_0
        add sp,0x8
        jmp short $-95
        nop
L97:
        mov ax,0xa
        jmp short $-114
        nop
L9D:
        mov ax,0xd
        jmp short $-120
        nop
LA3:
        xor ax,ax
LA5:
    }
}
