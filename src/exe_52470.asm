_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf10:FAR
    EXTRN mf21:FAR
    EXTRN mi39:NEAR
    EXTRN mi43:NEAR
    EXTRN mf46:FAR
    EXTRN md51:NEAR
    EXTRN mf56:FAR
    EXTRN mf56:FAR
    EXTRN mf56:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,2h
    mov word ptr ds:[106h],1h
    cmp word ptr ds:[102h],1Fh
    jnz short lbl28f
    mov ax,0A0h
    mov cx,2245h
    push cx
    push ax
    call mf10
    add sp,4h
    xor ax,ax
    jmp short lbl8Df
    nop
lbl28f:
    mov ax,word ptr [bp+8h]
    inc ax
    jz short lbl42f
    dec ax
    jz short lbl48f
    push word ptr [bp+8h]
    call mf21
    add sp,2h
    inc ax
lbl3Db:
    mov word ptr [bp-2h],ax
    jmp short lbl4Df
lbl42f:
    mov ax,word ptr ds:[102h]
    jmp short lbl3Db
    nop
lbl48f:
    mov word ptr [bp-2h],0h
lbl4Df:
    mov ax,word ptr ds:[102h]
    cmp word ptr [bp-2h],ax
    jnl short lbl75f
    sub ax,word ptr [bp-2h]
    add ax,ax
    push ax
    mov ax,word ptr [bp-2h]
    add ax,ax
    mov cx,ax
    add ax, offset mi39
    mov dx,2245h
    push dx
    push ax
    add cx, offset mi43
    push dx
    push cx
    call mf46
lbl75f:
    mov ax,word ptr [bp+6h]
    mov es, ds:[5A32h]
    mov bx,word ptr [bp-2h]
    add bx,bx
    mov word ptr es:[bx+md51],ax
    inc word ptr ds:[102h]
    mov ax,1h
lbl8Df:
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
