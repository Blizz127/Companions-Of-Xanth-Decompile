_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi19:NEAR
    EXTRN mi28:NEAR
    EXTRN mf31:FAR
    EXTRN mf38:FAR
    EXTRN mi40:NEAR
    EXTRN mf50:FAR
    EXTRN mf58:FAR
    EXTRN mf68:FAR
    EXTRN mf84:FAR
    EXTRN mf93:FAR
    EXTRN mi107:NEAR
    EXTRN mi115:NEAR
    EXTRN mf118:FAR
    EXTRN mf130:FAR
    EXTRN mf138:FAR
    EXTRN mf148:FAR
    EXTRN mf163:FAR
    EXTRN mf163:FAR
    EXTRN mf163:FAR
    EXTRN mf163:FAR
    EXTRN mf163:FAR
    EXTRN mf163:FAR
    EXTRN mf163:FAR
    EXTRN mf163:FAR
    EXTRN mf163:FAR
    EXTRN mf163:FAR
    EXTRN mf163:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,0Ch
    push di
    mov word ptr [bp-4h],0h
    cmp word ptr ds:[69F2h],0h
    jz short lbl1Ff
    xor ax,ax
    mov cx,40h
    mov di,5C5Eh
    push ds
    pop es
    rep stosw
lbl1Ff:
    mov word ptr [bp-2h],0h
    cmp word ptr [bp+0Ah],0h
    jg short lbl2Df
    jmp near ptr lbl113f
lbl2Df:
    mov ax,word ptr [bp+6h]
    mov dx,word ptr [bp+8h]
    add ax, offset mi19
    mov word ptr [bp-8h],ax
    mov word ptr [bp-6h],dx
lbl3Cb:
    mov bx,word ptr [bp-2h]
    cmp byte ptr [bx+5C5Eh],0h
    jnz short lbl49f
    jmp near ptr lblCBf
lbl49f:
    mov ax,word ptr [bp-8h]
    mov dx,word ptr [bp-6h]
    sub ax, offset mi28
    push dx
    push ax
    call mf31
    add sp,4h
    or ax,ax
    jnz short lblCBf
    mov word ptr [bp-4h],1h
    les bx, dword ptr [bp-8h]
    push word ptr es:[bx]
    call mf38
    add sp,2h
    cmp ax, offset mi40
    jnz short lblE0f
    mov ax,1h
    push ax
    les bx, dword ptr [bp-8h]
    push word ptr es:[bx]
    mov ax,20h
    mov cx,2199h
    push cx
    push ax
    call mf50
    add sp,8h
    or ax,ax
    jnz short lblC3f
    test byte ptr ds:[416Eh],10h
    jz short lblC3f
    mov ax,0FFFFh
    push ax
    call mf58
    add sp,2h
    mov ax,1h
    push ax
    les bx, dword ptr [bp-8h]
    push word ptr es:[bx]
    mov ax,20h
    mov cx,2199h
    push cx
    push ax
    call mf68
    add sp,8h
lblC3f:
    mov bx,word ptr [bp-2h]
    mov byte ptr [bx+5C5Eh],0h
lblCBf:
    add word ptr [bp-8h],0Ch
    mov ax,word ptr [bp+0Ah]
    inc word ptr [bp-2h]
    cmp word ptr [bp-2h],ax
    jnl short lblDDf
    jmp near ptr lbl3Cb
lblDDf:
    jmp short lbl113f
    nop
lblE0f:
    mov ax,20h
    mov cx,2199h
    push cx
    push ax
    call mf84
    add sp,4h
    xor ax,ax
    push ax
    push word ptr ds:[69F4h]
    mov cx,20h
    mov dx,2199h
    push dx
    push cx
    call mf93
    add sp,8h
    xor ax,ax
    mov cx,40h
    mov di,5C5Eh
    push ds
    pop es
    rep stosw
lbl113f:
    mov word ptr [bp-2h],0h
    cmp word ptr [bp+0Ah],0h
    jg short lbl121f
    jmp near ptr lbl1BBf
lbl121f:
    mov ax,word ptr [bp+6h]
    mov dx,word ptr [bp+8h]
    add ax, offset mi107
    mov word ptr [bp-0Ch],ax
    mov word ptr [bp-0Ah],dx
lbl130b:
    mov bx,word ptr [bp-2h]
    cmp byte ptr [bx+5C5Eh],0h
    jnz short lbl1A9f
    mov ax,word ptr [bp-0Ch]
    mov dx,word ptr [bp-0Ah]
    sub ax, offset mi115
    push dx
    push ax
    call mf118
    add sp,4h
    or ax,ax
    jz short lbl1A9f
    mov ax,1h
    push ax
    les bx, dword ptr [bp-0Ch]
    push word ptr es:[bx]
    mov ax,20h
    mov cx,2199h
    push cx
    push ax
    call mf130
    add sp,8h
    or ax,ax
    jnz short lbl19Cf
    test byte ptr ds:[416Eh],10h
    jz short lbl19Cf
    mov ax,0FFFFh
    push ax
    call mf138
    add sp,2h
    mov ax,1h
    push ax
    les bx, dword ptr [bp-0Ch]
    push word ptr es:[bx]
    mov ax,20h
    mov cx,2199h
    push cx
    push ax
    call mf148
    add sp,8h
lbl19Cf:
    mov bx,word ptr [bp-2h]
    mov byte ptr [bx+5C5Eh],1h
    mov word ptr [bp-4h],1h
lbl1A9f:
    add word ptr [bp-0Ch],0Ch
    mov ax,word ptr [bp+0Ah]
    inc word ptr [bp-2h]
    cmp word ptr [bp-2h],ax
    jnl short lbl1BBf
    jmp near ptr lbl130b
lbl1BBf:
    mov ax,word ptr [bp-4h]
    pop di
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
