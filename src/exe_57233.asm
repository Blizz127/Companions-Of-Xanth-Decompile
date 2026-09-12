_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN md19:NEAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,4h
    mov word ptr [bp-2h],0h
    mov word ptr [bp-4h],6h
lbl10b:
    mov ax,word ptr [bp+6h]
    mov es, ds:[5A4Ch]
    mov bx,word ptr [bp-4h]
    cmp word ptr es:[bx],ax
    jz short lbl30f
    inc word ptr [bp-2h]
    add word ptr [bp-4h],8h
    cmp word ptr [bp-4h],2CEh
    jc short lbl10b
    jmp short lbl3Ef
    nop
lbl30f:
    mov cl,3h
    mov bx,word ptr [bp-2h]
    shl bx,cl
    mov ax,word ptr es:[bx+md19]
    jmp short lbl41f
lbl3Ef:
    mov ax,730h
lbl41f:
    mov dx,ds
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
