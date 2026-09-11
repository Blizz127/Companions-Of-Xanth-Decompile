extern int __near mn67F2;
extern int __near mn67F4;
extern int __near mn67F6;
extern int __near mn67F8;
extern int __near mn67FA;
extern int __near mn67FC;
extern int __near mn67FE;
extern int __near mn6800;
extern int __near mn6802;
extern int __near mn6804;

int far exe_108117(int a)
{
    _asm {
        mov ax,[bp+0x6]
        mov dx,[bp+0x8]
        mov mn67F2,ax
        mov mn67F4,dx
        add ax,0x14
        mov mn67F6,ax
        mov mn67F8,dx
        mov ax,[bp+0x6]
        add ax,0x28
        mov mn67FA,ax
        mov mn67FC,dx
        mov ax,[bp+0x6]
        add ax,0x3c
        mov mn67FE,ax
        mov mn6800,dx
        mov ax,[bp+0x6]
        add ax,0x50
        mov mn6802,ax
        mov mn6804,dx
    }
}
