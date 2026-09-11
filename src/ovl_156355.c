extern char __near mb1132;
extern int __near mnE432;
extern char __near mb0132;

int far ovl_156355(void)
{
    _asm {
        add [bx+si],al
        add [bx+si],al
        add [bx+si],al
        add [bx+si],al
        add [bx+si],al
        add [bx+si],al
        add [bx+di+0x1e02],al
        xor bl,[si+0xa]
        push ds
        xor dh,[bx+0x2]
        push ds
        xor cl,[bp+di]
        add bl,mb1132
        add mnE432,bx
        add mb0132,bl
        push es
        push ds
    }
}
