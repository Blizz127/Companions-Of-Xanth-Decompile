extern int __near mn0256;
extern int __near mn5A46;
extern int __near mn5A48;
extern int __near mn5A4A;
extern char __near mb6E5C;
extern int __near mn084C;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
int far exe_56284(int a)
{
    _asm {
        sub sp,0x1a
        mov word ptr [bp-0x6],0x0
        push word ptr mn0256
        call far ptr helper_0
        add sp,0x2
        mov [bp-0xe],ax
        push word ptr mn0256
        call far ptr helper_1
        add sp,0x2
        mov [bp-0x10],ax
        or ax,ax
        jnz short $+5
        jmp L122
L2D:
        dec word ptr [bp-0x10]
        cmp word ptr [bp-0xe],0x0
        jnz short $+5
        jmp L11F
L39:
        mov ax,[bp-0x10]
        add ax,ax
        add ax,ax
        add ax,0x10fa
        mov [bp-0x16],ax
        mov ax,[bp-0xe]
        mov [bp-0x18],ax
L4C:
        mov word ptr [bp-0x8],0x0
        mov word ptr [bp-0xc],0x0
        mov word ptr [bp-0x14],0x908
        mov bx,[bp-0x16]
        mov es, mn5A46
        mov al,es:[bx]
        mov [bp-0x1a],al
L68:
        mov al,[bp-0x1a]
        mov es, mn5A48
        mov bx,[bp-0x14]
        cmp es:[bx],al
        jz short $+18
        inc word ptr [bp-0xc]
        add word ptr [bp-0x14],0x4
        cmp word ptr [bp-0x14],0x930
        jc short $-27
        jmp short $+17
L87:
        mov bx,[bp-0xc]
        add bx,bx
        add bx,bx
        mov ax,es:[bx+0x90a]
        mov [bp-0x8],ax
L96:
        mov bx,[bp-0x16]
        mov es, mn5A46
        mov ax,es:[bx+0x2]
        mov [bp-0x12],ax
        sub ah,ah
        mov al,es:[bx+0x1]
        dec ax
        jz short $+98
        dec ax
        jz short $+11
        dec ax
        jz short $+92
        dec ax
        jz short $+39
        jmp short $+93
        nop
LB9:
        mov ax,0xe
        push ax
        mov es, mn5A4A
        mov bx,[bp-0x12]
        add bx,bx
        add bx,bx
        push word ptr es:[bx+0x850]
        call far ptr helper_2
        add sp,0x4
        or ax,ax
        jz short $+60
        jmp short $+52
LDB:
        mov al,mb6E5C
        mov [bp-0x2],al
        mov al,es:[bx]
        mov mb6E5C,al
        mov ax,0x1
        push ax
        push word ptr [bp-0x12]
        call far ptr helper_3
        add sp,0x4
        mov [bp-0x4],ax
        mov al,[bp-0x2]
        mov mb6E5C,al
        cmp word ptr [bp-0x4],0x0
        jng short $+16
        mov ax,mn084C
        cmp [bp-0x4],ax
        jg short $+8
L10D:
        mov ax,[bp-0x8]
        or [bp-0x6],ax
L113:
        add word ptr [bp-0x16],0x4
        dec word ptr [bp-0x18]
        jz short $+5
        jmp L4C
L11F:
        mov ax,[bp-0x6]
L122:
    }
}
