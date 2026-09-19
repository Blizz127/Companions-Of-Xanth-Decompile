_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN md3f:NEAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,4h
    mov word ptr [bp-2h],0h
    mov word ptr [bp-4h],0h
lbl10b:
    mov ax,word ptr [bp+6h]
    mov es, ds:[5A60h]
    mov bx,word ptr [bp-4h]
    cmp word ptr es:[bx],ax
    jz short lbl30f
    inc word ptr [bp-2h]
    add word ptr [bp-4h],6h
    cmp word ptr [bp-4h],126h
    jc short lbl10b
    db 0EBh, 1Bh ; override
    nop
lbl30f:
    push ax
    push word ptr [bp+8h]
    mov bx,word ptr [bp-2h]
    mov ax,bx
    add bx,bx
    add bx,ax
    add bx,bx
    call dword ptr es:[bx+md3f]
    add sp,4h
    jmp short lbl4Df
    nop
lbl4Af:
    xor ax,ax
    cwd
lbl4Df:
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
