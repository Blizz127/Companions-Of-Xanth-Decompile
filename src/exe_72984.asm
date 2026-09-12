_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi2:NEAR
    EXTRN mf14:FAR
    EXTRN mf26:FAR
    EXTRN mf31:FAR
    EXTRN mf33:FAR
    EXTRN mi35:NEAR
    EXTRN md42:NEAR
    EXTRN md47:NEAR
    EXTRN mf52:FAR
    EXTRN md58:NEAR
    EXTRN md59:NEAR
    EXTRN md65:NEAR
    EXTRN md66:NEAR
    EXTRN mf69:FAR
    EXTRN mf72:FAR
    EXTRN mi74:NEAR
    EXTRN mf78:FAR
    EXTRN md84:NEAR
    EXTRN md85:NEAR
    EXTRN mf90:FAR
    EXTRN mf90:FAR
    EXTRN mf90:FAR
    EXTRN mf90:FAR
    EXTRN mf90:FAR
    EXTRN mf90:FAR
    EXTRN mf90:FAR
    EXTRN mf90:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp, offset mi2
    push si
    push di
    cmp word ptr ds:[4176h],0h
    jz short lbl13f
    jmp near ptr lbl4Ef
lbl13f:
    cmp word ptr ds:[4168h],0h
    jnz short lbl1Df
    jmp near ptr lbl4Ef
lbl1Df:
    cmp word ptr ds:[416Ah],0h
    jz short lbl27f
    jmp near ptr lbl4Ef
lbl27f:
    call mf14
    mov cx,word ptr ds:[4166h]
    add cx,0FFFFFFFFFFFFFF9Ch
    cmp ax,cx
    ja short lbl3Af
    jmp near ptr lbl4Ef
lbl3Af:
    mov ax,0h
    push ax
    mov ax,1h
    push ax
    mov ax,2h
    push ax
    call mf26
    add sp,6h
lbl4Ef:
    cmp word ptr ds:[4176h],0h
    jnz short lbl58f
    jmp near ptr lbl5Df
lbl58f:
    call mf31
lbl5Df:
    push word ptr [bp+6h]
    call mf33
    add sp,2h
    cmp ax, offset mi35
    jnz short lbl70f
    jmp near ptr lbl112f
lbl70f:
    mov bx,word ptr [bp+6h]
    shl bx,1
    shl bx,1
    mov es, ds:[5B3Ah]
    cmp word ptr es:[bx+md42],0h
    jnl short lbl86f
    jmp near ptr lblBEf
lbl86f:
    jng short lbl8Bf
    jmp near ptr lbl97f
lbl8Bf:
    cmp word ptr es:[bx+md47],0F0h
    jnc short lbl97f
    jmp near ptr lblBEf
lbl97f:
    mov ax,0FEh
    push ax
    call mf52
    add sp,2h
    mov bx,word ptr [bp+6h]
    shl bx,1
    shl bx,1
    mov es, ds:[5B3Ah]
    sub word ptr es:[bx+md58],0F0h
    sbb word ptr es:[bx+md59],0h
    jmp near ptr lbl112f
lblBEf:
    mov bx,word ptr [bp+6h]
    shl bx,1
    shl bx,1
    mov es, ds:[5B3Ah]
    mov ax,word ptr es:[bx+md65]
    mov dx,word ptr es:[bx+md66]
    and ax,0FFh
    push ax
    call mf69
    add sp,2h
    push word ptr [bp+6h]
    call mf72
    add sp,2h
    cmp ax, offset mi74
    jnz short lblF2f
    jmp near ptr lbl112f
lblF2f:
    push word ptr [bp+6h]
    call mf78
    add sp,2h
    mov bx,word ptr [bp+6h]
    shl bx,1
    shl bx,1
    mov es, ds:[5B3Ah]
    mov word ptr es:[bx+md84],ax
    mov word ptr es:[bx+md85],dx
lbl112f:
    pop di
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
