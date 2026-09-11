extern int __near mn4EA0;
extern int __near mn4E9E;
extern char __near mb4E9E;
extern int __near mn643A;
extern int __near mn6438;
extern int __near mn643E;
extern int __near mn643C;
extern int __near mn6442;
extern int __near mn6440;
extern int __near mn642A;
extern int __near mn6428;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
int far exe_99305(int a)
{
    _asm {
        sub sp,0x8
        mov ax,mn4EA0
        mov [bp-0x2],ax
        mov word ptr mn4EA0,0x1
        mov ax,mn4E9E
        mov [bp-0x4],ax
        or ax,ax
        jnz short $+5
        jmp LA8
L1C:
        test byte ptr mb4E9E,0x1
        jz short $+5
        jmp LA8
L26:
        cmp word ptr [bp+0x6],0x0
        jz short $+126
        or byte ptr mb4E9E,0x1
        lea ax,[bp-0x8]
        push ss
        push ax
        lea cx,[bp-0x6]
        push ss
        push cx
        call far ptr helper_0
        add sp,0x8
        mov ax,[bp-0x8]
        mov mn643A,ax
        push ax
        mov ax,[bp-0x6]
        mov mn6438,ax
        push ax
        push word ptr mn643E
        push word ptr mn643C
        call far ptr helper_1
        add sp,0x8
        push word ptr [bp-0x8]
        push word ptr [bp-0x6]
        push word ptr mn6442
        push word ptr mn6440
        call far ptr helper_1
        add sp,0x8
        push word ptr mn642A
        push word ptr mn6428
        push word ptr [bp-0x8]
        push word ptr [bp-0x6]
        push word ptr mn6442
        push word ptr mn6440
        call far ptr helper_2
        add sp,0xc
        push word ptr [bp-0x8]
        push word ptr [bp-0x6]
        push word ptr mn6442
        push word ptr mn6440
        call far ptr helper_3
LA8:
        mov ax,[bp-0x2]
        mov mn4EA0,ax
        mov al,[bp-0x4]
        and ax,0x1
    }
}
