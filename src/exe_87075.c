extern int __near mn42E8;
int g;
void far helper(void);
void far exe_87075(char far *p)
{
    _asm {
        call far ptr helper
        xor ax,ax
        mov dx,0x3c8
        out dx,al
        push si
        push ds
        mov si,[bp+0x6]
        mov ds, [bp+0x8]
        mov cx,0x100
        inc dx
L17:
        mov al,[si]
        inc si
        out dx,al
        mov al,[si]
        inc si
        out dx,al
        mov al,[si]
        inc si
        out dx,al
        loop L17
        pop ds
        pop si
        mov word ptr mn42E8,0x0
    }
}
