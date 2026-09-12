_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi2:NEAR
    EXTRN mf19:FAR
    EXTRN mf24:FAR
    EXTRN mi26:NEAR
    EXTRN mf31:FAR
    EXTRN mi32:NEAR
    EXTRN mf37:FAR
    EXTRN mf44:FAR
    EXTRN mf44:FAR
    EXTRN mf44:FAR
    EXTRN mf44:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp, offset mi2
    push si
    push di
    mov ax,word ptr [bp+6h]
    mov dx,word ptr [bp+8h]
    mov word ptr ds:[6DF4h],ax
    mov word ptr ds:[6DF6h],dx
    cmp word ptr ds:[6DF4h],0h
    jz short lbl20f
    jmp near ptr lbl30f
lbl20f:
    cmp word ptr ds:[6DF6h],0h
    jz short lbl2Af
    jmp near ptr lbl30f
lbl2Af:
    mov ax,0h
    jmp near ptr lbl7Df
lbl30f:
    push word ptr [bp+0Ch]
    push word ptr [bp+0Ah]
    call mf19
    add sp,4h
    les bx, dword ptr ds:[6DF4h]
    push word ptr es:[bx+2h]
    push word ptr es:[bx]
    call mf24
    add sp,4h
    cmp ax, offset mi26
    jz short lbl59f
    jmp near ptr lbl5Ff
lbl59f:
    mov ax,0h
    jmp near ptr lbl7Df
lbl5Ff:
    call mf31
    cmp ax, offset mi32
    jz short lbl6Cf
    jmp near ptr lbl72f
lbl6Cf:
    mov ax,0h
    jmp near ptr lbl7Df
lbl72f:
    call mf37
    mov ax,1h
    jmp near ptr lbl7Df
lbl7Df:
    pop di
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
