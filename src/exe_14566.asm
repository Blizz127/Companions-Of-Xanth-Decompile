_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf38:FAR
mnem_unit:
    push bp
    mov bp,sp
    mov ax,word ptr [bp+8h]
    sub ax,word ptr [bp+0Ch]
    db 1Bh, 0D2h ; override
    add ax,ax
    adc dx,dx
    add ax,ax
    adc dx,dx
    add ax,ax
    adc dx,dx
    add ax,ax
    adc dx,dx
    add ax,word ptr [bp+6h]
    adc dx,0h
    sub ax,word ptr [bp+0Ah]
    sbb dx,0h
    pop bp
    retf 8h
    add byte ptr [bx+56h],dl
    mov si,545Ch
    xor di,di
    jmp short lbl47f
    nop
lbl36b:
    push ds
    push si
    call mf38
    add sp,4h
    inc ax
    jz short lbl44f
    inc di
lbl44f:
    add si,0Ch
lbl47f:
    cmp word ptr ds:[5600h],si
    jnc short lbl36b
    mov ax,di
    pop si
    pop di
    retf
_TEXT ENDS
    END
