extern int __near mn42EA;
extern int __near mn6DFC;
extern char __near mb6350;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
int far exe_87515(int a)
{
    _asm {
        sub sp,0x14
        push word ptr [bp+0x8]
        push word ptr [bp+0x6]
        call far ptr helper_0
        add sp,0x4
        mov [bp+0x6],ax
        mov [bp+0x8],dx
        cmp word ptr mn42EA,0x0
        jz short $+7
        call far ptr helper_1
L23:
        mov byte ptr [bp-0xd],0x3
        mov byte ptr [bp-0xb],0x0
        lea ax,[bp-0xe]
        push ss
        push ax
        push ss
        push ax
        mov ax,0x10
        push ax
        call far ptr helper_2
        add sp,0xa
        mov al,[bp-0x7]
        sub ah,ah
        mov [bp-0x10],ax
        mov cl,[bp-0x8]
        sub ch,ch
        mov [bp-0x12],cx
        or ax,ax
        jnl short $+5
        jmp L13A
L55:
        cmp ax,0x19
        jl short $+5
        jmp L13A
L5D:
        les bx, [bp+0x6]
        cmp es:[bx],ah
        jnz short $+5
        jmp L13A
L68:
        cmp byte ptr es:[bx],0xa
        jnz short $+31
        mov word ptr [bp-0x12],0x0
        mov byte ptr [bp-0xd],0x2
        mov byte ptr [bp-0xb],0x0
        inc word ptr [bp-0x10]
        mov al,[bp-0x10]
        mov [bp-0x7],al
        mov byte ptr [bp-0x8],0x0
        jmp L115
L8B:
        cmp byte ptr es:[bx],0x9
        jnz short $+52
        mov byte ptr [bp-0xd],0x2
        mov byte ptr [bp-0xb],0x0
        mov al,[bp-0x10]
        mov [bp-0x7],al
        mov ax,mn6DFC
        add ax,0x4
        cwd
        and dx,0x7
        add ax,dx
        mov cx,0x3
        sar ax,cl
        mov cx,ax
        mov ax,[bp-0x12]
        cwd
        idiv cx
        inc ax
        imul cx
        mov [bp-0x12],ax
        mov [bp-0x8],al
        jmp short $+84
LC3:
        cmp word ptr [bp-0x12],0x0
        jl short $+97
        cmp word ptr [bp-0x12],0x28
        jnl short $+91
        mov byte ptr [bp-0xd],0x2
        mov byte ptr [bp-0xb],0x0
        mov al,[bp-0x10]
        mov [bp-0x7],al
        mov al,[bp-0x12]
        mov [bp-0x8],al
        lea ax,[bp-0xe]
        push ss
        push ax
        lea cx,[bp-0xe]
        push ss
        push cx
        mov dx,0x10
        push dx
        call far ptr helper_2
        add sp,0xa
        mov byte ptr [bp-0xd],0x9
        les bx, [bp+0x6]
        mov al,es:[bx]
        mov [bp-0xe],al
        mov byte ptr [bp-0xb],0x0
        mov al,mb6350
        mov [bp-0xc],al
        mov word ptr [bp-0xa],0x1
L115:
        lea ax,[bp-0xe]
        push ss
        push ax
        push ss
        push ax
        mov ax,0x10
        push ax
        call far ptr helper_2
        add sp,0xa
L128:
        inc word ptr [bp-0x12]
        inc word ptr [bp+0x6]
        les bx, [bp+0x6]
        cmp byte ptr es:[bx],0x0
        jz short $+5
        jmp L68
L13A:
        mov byte ptr [bp-0xd],0x2
        mov byte ptr [bp-0xb],0x0
        mov al,[bp-0x10]
        mov [bp-0x7],al
        mov al,[bp-0x12]
        mov [bp-0x8],al
        lea ax,[bp-0xe]
        push ss
        push ax
        push ss
        push ax
        mov ax,0x10
        push ax
        call far ptr helper_2
        add sp,0xa
        cmp word ptr mn42EA,0x0
        jz short $+7
        call far ptr helper_1
L16D:
    }
}
