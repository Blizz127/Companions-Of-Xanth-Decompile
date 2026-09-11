extern char __near mb53F7;
void far helper_0(void);
void far helper_1(void);
int far exe_7548(int a)
{
    _asm {
        call far ptr helper_0
        mov al,mb53F7
        or al,al
        jz short $+7
        call far ptr helper_1
L11:
    }
}
