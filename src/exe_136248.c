extern int __near mn010B;
extern int __near mn0056;
extern int __near mn000A;
extern int __near mn000C;

int far exe_136248(void)
{
    _asm {
        push bx
        push ax
        mov bx,0x150
L05:
        mov ax,cs:[bx]
        or ax,cs:[bx+0x2]
        jz short $+9
        add bx,0x6
        jmp short $-12
        add [bx+si],al
L15:
        test word ptr cs:mn010B,0xff
        jnz short $+36
        pop ax
        push ax
        test al,0x2
        jz short $+30
        mov word ptr cs:mn010B,0xff
        push es
        mov es, cs:mn0056
        cli
        mov word ptr es:mn000A,0x1db
        mov word ptr es:mn000C,cs
        sti
        pop es
L40:
        cmp bx,0x198
        jz short $+16
        mov cs:[bx],dx
        mov word ptr cs:[bx+0x2],ds
        pop ax
        mov cs:[bx+0x4],al
        pop bx
        retf
L54:
    }
}
