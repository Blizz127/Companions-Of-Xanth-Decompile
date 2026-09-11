extern int __near mn5CE2;
extern int __near mn02EA;
extern int __near mn5CDE;
extern int __near mn02EC;
extern int __near mn5CE0;
void far helper_0(void);
int far exe_52720(int a)
{
    _asm {
        mov ax,[bp+0x6]
        mov mn5CE2,ax
        sub ax,0xcd
        jz short $+6
        xor ax,ax
        jmp short $+85
L0F:
        mov ax,[bp+0x8]
        or ax,ax
        jz short $+19
        sub ax,0xc9
        jz short $+28
        sub ax,0x24
        jz short $+37
        sub ax,0x7
        jz short $+46
        jmp short $+56
L27:
        mov ax,mn02EA
        mov mn5CDE,ax
        mov ax,mn02EC
        mov mn5CE0,ax
        jmp short $+42
L35:
        mov word ptr mn5CDE,0x1
        mov word ptr mn5CE0,0x4
        jmp short $+28
L43:
        mov word ptr mn5CDE,0x4
        mov word ptr mn5CE0,0x1
        jmp short $+14
L51:
        mov word ptr mn5CDE,0x8
        mov word ptr mn5CE0,0x6
L5D:
        call far ptr helper_0
L62:
    }
}
