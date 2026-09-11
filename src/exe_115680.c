extern int __near mn6DDA;
extern int __near mn69F8;
extern int __near mn6D48;
extern int __near mn51DC;
extern int __near mn51DA;
extern int __near mn5218;
extern int __near mn6DFE;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
void far helper_5(void);
void far helper_6(void);
void far helper_7(void);
void far helper_8(void);
void far helper_9(void);
void far helper_10(void);
int far exe_115680(int a)
{
    _asm {
        sub sp,0xe
        mov bx,[bp+0x6]
        add bx,bx
        mov [bp-0xe],bx
        mov ax,[bx+0x6880]
        add ax,mn6DDA
        mov [bp-0x2],ax
        mov ax,[bx+0x6850]
        mov [bp-0x4],ax
        mov cx,[bx+0x6870]
        mov [bp-0x8],cx
        sub cx,ax
        mov ax,mn69F8
        add ax,ax
        sub cx,ax
        cmp cx,[bx+0x68b0]
        jnl short $+48
        mov ax,[bp-0x8]
        sub ax,mn6D48
        push ax
        mov ax,[bx+0x6860]
        dec ax
        push ax
        mov ax,[bp-0x4]
        add ax,mn6D48
        push ax
        mov ax,[bx+0x6840]
        add ax,mn6DDA
        push ax
        push word ptr mn69F8
        call far ptr helper_0
        add sp,0xa
        jmp short $+10
        nop
L61:
        mov ax,mn69F8
        add [bx+0x68b0],ax
L68:
        mov bx,[bp-0xe]
        mov ax,mn6DDA
        mov [bx+0x68a0],ax
        mov word ptr [bp-0xa],0x0
        mov ax,mn69F8
        add ax,ax
        sub ax,[bp-0x8]
        neg ax
        sub ax,[bp-0x4]
        cmp ax,[bx+0x68b0]
        jl short $+5
        jmp L15D
L8D:
        mov bx,[bp-0xe]
        mov ax,[bx+0x68b0]
        add [bp-0x4],ax
        mov ax,mn51DC
        or ax,mn51DA
        jz short $+11
        mov word ptr [bp-0xa],0x1
        jmp L167
        nop
LA9:
        mov ax,mn69F8
        cmp [bx+0x68c0],ax
        jl short $+9
        sub [bx+0x68c0],ax
        jmp L167
LB9:
        cmp word ptr [bx+0x68c0],-1
        jnz short $+5
        jmp L167
LC3:
        mov ax,[bx+0x68b0]
        sub ax,mn6D48
        sub ax,mn69F8
        mov [bx+0x68c0],ax
        push word ptr [bp-0x4]
        push word ptr [bp-0x2]
        call far ptr helper_1
        add sp,0x4
        mov ax,0x521a
        push ds
        push ax
        call far ptr helper_2
        add sp,0x4
        push word ptr mn5218
        call far ptr helper_3
        add sp,0x2
LFA:
        call far ptr helper_4
        or ax,ax
        jnz short $+11
        call far ptr helper_5
        or ax,ax
        jz short $-16
L10C:
        call far ptr helper_6
        call far ptr helper_7
        mov ax,mn6DFE
        or ax,ax
        jnl short $+4
        xor ax,ax
L11F:
        push ax
        call far ptr helper_8
        add sp,0x2
        mov ax,0x5223
        push ds
        push ax
        call far ptr helper_9
        add sp,0x4
        add ax,[bp-0x2]
        dec ax
        mov [bp-0x6],ax
        mov ax,[bp-0x4]
        add ax,mn69F8
        dec ax
        push ax
        push word ptr [bp-0x6]
        push word ptr [bp-0x4]
        push word ptr [bp-0x2]
        mov ax,0x2
        push ax
        call far ptr helper_10
        add sp,0xa
        jmp short $+13
        nop
L15D:
        mov bx,[bp-0xe]
        mov ax,[bx+0x68b0]
        add [bp-0x4],ax
L167:
        push word ptr [bp-0x4]
        push word ptr [bp-0x2]
        call far ptr helper_1
        mov ax,[bp-0xa]
    }
}
