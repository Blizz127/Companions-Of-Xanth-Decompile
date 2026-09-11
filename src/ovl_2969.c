extern int __near mn5A68;
extern int __near mn0354;
extern int __near mn0352;

int far ovl_2969(void)
{
    _asm {
        mov es, mn5A68
        mov ax,es:mn0354
        cmp es:mn0352,ax
        jg short $+7
        mov ax,0x1
        jmp short $+4
L14:
        xor ax,ax
L16:
        retf
    }
}
