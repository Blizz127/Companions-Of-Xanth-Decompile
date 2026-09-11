extern int __near mn630C;
void far helper_0(void);
int far exe_83988(int a)
{
    _asm {
        sub sp,0xe
        mov ax,mn630C
        mov [bp-0xc],ax
        mov word ptr [bp-0x8],0x630c
        mov word ptr [bp-0x6],ds
        or ax,ax
        jng short $+62
        mov word ptr [bp-0xe],0x6326
L1A:
        cmp word ptr [bp-0xe],0x6340
        jnc short $+50
        mov bx,[bp-0xe]
        mov [bp-0x4],bx
        mov word ptr [bp-0x2],ds
        cmp word ptr [bx],0x0
        jz short $+13
        mov ax,[bp-0xc]
        mov es, [bp-0x2]
        cmp es:[bx],ax
        jng short $+17
L3A:
        les bx, [bp-0x4]
        mov ax,es:[bx]
        mov [bp-0xc],ax
        mov [bp-0x8],bx
        mov word ptr [bp-0x6],es
L49:
        add word ptr [bp-0xe],0x1a
        or ax,ax
        jg short $-53
L51:
        push word ptr [bp-0x6]
        push word ptr [bp-0x8]
        call far ptr helper_0
        mov ax,[bp-0x8]
        mov dx,[bp-0x6]
    }
}
