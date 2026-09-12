_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN md23:NEAR
    EXTRN md31:NEAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,4h
    mov word ptr [bp-2h],0h
    mov word ptr [bp-4h],0h
lbl10b:
    mov ax,word ptr [bp+6h]
    mov es, ds:[5A5Ah]
    mov bx,word ptr [bp-4h]
    cmp word ptr es:[bx],ax
    jz short lbl30f
    inc word ptr [bp-2h]
    add word ptr [bp-4h],6h
    cmp word ptr [bp-4h],102h
    jc short lbl10b
    jmp short lbl5Cf
    nop
lbl30f:
    test byte ptr ds:[416Eh],4h
    jz short lbl4Af
    mov bx,word ptr [bp-2h]
    mov ax,bx
    add bx,bx
    add bx,ax
    add bx,bx
    mov ax,word ptr es:[bx+md23]
    jmp short lbl5Ef
    nop
lbl4Af:
    mov bx,word ptr [bp-2h]
    mov ax,bx
    add bx,bx
    add bx,ax
    add bx,bx
    mov ax,word ptr es:[bx+md31]
    jmp short lbl5Ef
lbl5Cf:
    xor ax,ax
lbl5Ef:
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
