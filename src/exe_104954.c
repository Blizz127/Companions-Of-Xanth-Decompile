extern int __near mn6E0A;
extern int __near mn6E0C;
extern int __near mn4F52;
extern int __near mn4F54;
extern char __near mb6E0E;
extern char __near mb6E0F;
extern char __near mb6E09;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
void far helper_5(void);
void far helper_6(void);
int far exe_104954(int a)
{
    _asm {
        sub sp,0x2
        les bx, [bp+0x6]
        cmp byte ptr es:[bx],0x0
        jz short $+7
L0C:
        xor ax,ax
        jmp L134
L11:
        xor al,al
        mov es:[bx+0xa],al
        mov es:[bx+0xb],al
        push word ptr [bp+0xc]
        push word ptr [bp+0xa]
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jz short $-31
        mov ax,0x80
        cwd
        push dx
        push ax
        call far ptr helper_1
        add sp,0x4
        les bx, [bp+0x6]
        mov es:[bx+0x10],ax
        mov es:[bx+0x12],dx
        mov ax,dx
        or ax,es:[bx+0x10]
        jz short $-64
        xor ax,ax
        push ax
        les bx, [bp+0x6]
        push word ptr es:[bx+0x12]
        push word ptr es:[bx+0x10]
        push ax
        push word ptr mn6E0A
        push word ptr mn6E0C
        call far ptr helper_2
        or ax,ax
        jz short $+23
        les bx, [bp+0x6]
        push word ptr es:[bx+0x12]
        push word ptr es:[bx+0x10]
        call far ptr helper_3
L7E:
        add sp,0x4
        jmp short $-117
L83:
        les bx, [bp+0x6]
        les bx, es:[bx+0x10]
        mov ax,es:[bx+0x18]
        mov dx,es:[bx+0x1a]
        les bx, [bp+0x6]
        mov es:[bx+0xc],ax
        mov es:[bx+0xe],dx
        les bx, es:[bx+0xc]
        mov ax,es:[bx]
        mov dx,es:[bx+0x2]
        les bx, [bp+0x6]
        les bx, es:[bx+0x10]
        mov es:[bx+0x18],ax
        mov es:[bx+0x1a],dx
        les bx, [bp+0x6]
        push word ptr es:[bx+0x12]
        push word ptr es:[bx+0x10]
        xor ax,ax
        push ax
        call far ptr helper_4
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
        mov es:[bx+0x1],al
        mov byte ptr es:[bx],0x1
        les bx, es:[bx+0x10]
        push word ptr es:[bx+0x1a]
        push word ptr es:[bx+0x18]
        call far ptr helper_5
        add sp,0x4
        or ax,ax
        jz short $+16
        push word ptr [bp+0x8]
        push word ptr [bp+0x6]
        call far ptr helper_6
        jmp L7E
L131:
        mov ax,0x1
L134:
    }
}
