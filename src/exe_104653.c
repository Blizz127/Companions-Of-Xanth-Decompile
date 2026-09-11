extern int __near mn6E0A;
extern int __near mn6E0C;
extern int __near mn4F52;
extern int __near mn4F54;
extern char __near mb6E0E;
extern char __near mb6E0F;
extern char __near mb6E09;
extern int __near mn4F44;
extern int __near mn6E0A;
extern int __near mn6E0C;
extern int __near mn4F52;
extern int __near mn4F54;
extern char __near mb6E0E;
extern char __near mb6E0F;
extern char __near mb6E09;
extern int __near mn4F44;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
void far helper_5(void);
int far exe_104653(int a)
{
    _asm {
        sub sp,0x8
        les bx, [bp+0x6]
        cmp byte ptr es:[bx],0x0
        jz short $+7
lbl0C:
        xor ax,ax
        jmp lbl126
lbl11:
        xor al,al
        mov es:[bx+0xa],al
        mov es:[bx+0xb],al
        push word ptr [bp+0xc]
        push word ptr [bp+0xa]
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jz short $-31
        push word ptr [bp+0xa]
        call far ptr helper_1
        add sp,0x2
        mov [bp-0x4],ax
        mov [bp-0x2],dx
        mov ax,mn6E0A
        imul word ptr mn6E0C
        cmp dx,[bp-0x2]
        jg short $+33
        jl short $+7
        cmp ax,[bp-0x4]
        ja short $+26
lbl51:
        push word ptr [bp+0xc]
        push word ptr [bp+0xa]
        push word ptr [bp+0x8]
        push word ptr [bp+0x6]
        call far ptr helper_2
        add sp,0x8
        jmp lbl126
        nop
lbl69:
        cmp word ptr [bp-0x2],0x0
        jl short $+10
        jg short $-30
        cmp word ptr [bp-0x4],-16
        ja short $-36
lbl77:
        les bx, [bp+0x6]
        sub ax,ax
        mov es:[bx+0x12],ax
        mov es:[bx+0x10],ax
        push word ptr [bp-0x2]
        push word ptr [bp-0x4]
        call far ptr helper_3
        add sp,0x4
        les bx, [bp+0x6]
        mov es:[bx+0xc],ax
        mov es:[bx+0xe],dx
        mov ax,dx
        or ax,es:[bx+0xc]
        jnz short $+5
        jmp lbl0C
lblA8:
        mov ax,mn4F52
        les bx, [bp+0x6]
        mov es:[bx+0x2],ax
        mov ax,mn4F54
        mov es:[bx+0x4],ax
        mov ax,mn6E0A
        mov es:[bx+0x6],ax
        mov ax,mn6E0C
        mov es:[bx+0x8],ax
        mov al,mb6E0E
        mov es:[bx+0xa],al
        mov al,mb6E0F
        mov es:[bx+0xb],al
        mov al,mb6E09
        and al,0x40
        cmp al,0x1
        cmc
        sbb al,al
        and al,0x3
        or al,0x80
        mov es:[bx+0x1],al
        mov byte ptr es:[bx],0x1
        push word ptr [bp-0x4]
        les bx, es:[bx+0xc]
        push word ptr es:[bx+0x2]
        push word ptr es:[bx]
        push word ptr mn4F44
        call far ptr helper_4
        add sp,0x8
        sub dx,dx
        cmp ax,[bp-0x4]
        jnz short $+7
        cmp dx,[bp-0x2]
        jz short $+20
lbl111:
        push word ptr [bp+0x8]
        push word ptr [bp+0x6]
        call far ptr helper_5
        add sp,0x4
        jmp lbl0C
        nop
lbl123:
        mov ax,0x1
lbl126:
    }
}
