extern int __near mn5C38;
extern int __near mn00F4;
extern int __near mn5C40;
extern int __near mn5C3E;
extern int __near mn5C3C;
extern int __near mn5C3A;
extern int __near mn5C58;
extern int __near mn5C56;
extern int __near mn5C48;
extern int __near mn5C46;
void far helper_0(void);
void far helper_1(void);
int far exe_48275(void)
{
    _asm {
        cmp word ptr mn5C38,0x0
        jz short $+14
        push word ptr mn5C38
        call far ptr helper_0
        add sp,0x2
L13:
        mov word ptr mn00F4,0x0
        push word ptr mn5C40
        push word ptr mn5C3E
        call far ptr helper_1
        add sp,0x4
        push word ptr mn5C3C
        push word ptr mn5C3A
        call far ptr helper_1
        add sp,0x4
        push word ptr mn5C58
        push word ptr mn5C56
        call far ptr helper_1
        add sp,0x4
        push word ptr mn5C48
        push word ptr mn5C46
        call far ptr helper_1
        add sp,0x4
        retf
    }
}
