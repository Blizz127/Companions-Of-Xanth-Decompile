extern int __near mn5ABA;
extern int __near mn6A04;

int near ovl_64065(void)
{
    _asm {
        mov es, mn5ABA
        mov bx,mn6A04
        mov ax,bx
    }
}
