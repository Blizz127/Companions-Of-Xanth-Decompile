_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi26:NEAR
    EXTRN md3b:NEAR
    EXTRN md40:NEAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,4h
    mov word ptr [bp-2h],0h
    mov word ptr [bp-4h],0h
lbl10b:
    mov ax,word ptr [bp+6h]
    mov es, ds:[5A86h]
    mov bx,word ptr [bp-4h]
    cmp word ptr es:[bx],ax
    db 74h, 11h ; override
    inc word ptr [bp-2h]
    add word ptr [bp-4h],6h
    cmp word ptr [bp-4h], offset mi26
    jc short lbl10b
    db 0EBh, 19h ; override
    nop
lbl30f:
    mov bx,word ptr [bp-2h]
    mov ax,bx
    add bx,bx
    add bx,ax
    add bx,bx
    mov ax,word ptr es:[bx+md3b]
    mov dx,word ptr es:[bx+md40]
    jmp short lbl4Df
    nop
lbl48f:
    mov ax,1997h
    mov dx,ds
lbl4Df:
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
