_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi2:NEAR
    EXTRN mf9:FAR
    EXTRN mf15:FAR
    EXTRN mi21:NEAR
    EXTRN mf25:FAR
    EXTRN mf30:FAR
    EXTRN mf36:FAR
    EXTRN mf43:FAR
    EXTRN mf47:FAR
    EXTRN mf52:FAR
    EXTRN mf58:FAR
    EXTRN mi65:NEAR
    EXTRN mi68:NEAR
    EXTRN mi71:NEAR
    EXTRN mi74:NEAR
    EXTRN mf84:FAR
    EXTRN mf84:FAR
    EXTRN mf84:FAR
    EXTRN mf84:FAR
    EXTRN mf84:FAR
    EXTRN mf84:FAR
    EXTRN mf84:FAR
    EXTRN mf84:FAR
    EXTRN mf84:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp, offset mi2
    push si
    push di
    mov ax,0h
    push ax
    mov ax,word ptr [bp+6h]
    push ax
    call mf9
    add sp,4h
    and ax,0FFh
    jmp near ptr lblC8f
lbl1Fb:
    mov ax,0FCh
    push ax
    call mf15
    add sp,2h
    mov ax,0h
    jmp near ptr lblF1f
lbl31b:
    add word ptr ds:[4122h],1h
    mov ax,word ptr ds:[4122h]
    cmp ax, offset mi21
    jg short lbl41f
    jmp near ptr lbl4Ff
lbl41f:
    push word ptr [bp+6h]
    call mf25
    add sp,2h
    jmp near ptr lbl79f
lbl4Ff:
    mov ax,0F8h
    push ax
    call mf30
    add sp,2h
    mov bx,word ptr [bp+6h]
    shl bx,1
    add word ptr [bx+62BAh],1h
    push word ptr [bp+6h]
    call mf36
    add sp,2h
    mov bx,word ptr [bp+6h]
    shl bx,1
    add word ptr [bx+62BAh],ax
lbl79f:
    jmp near ptr lblEBf
lbl7Cb:
    push word ptr [bp+6h]
    call mf43
    add sp,2h
    jmp near ptr lblEBf
lbl8Ab:
    push word ptr [bp+6h]
    call mf47
    add sp,2h
    jmp near ptr lblEBf
lbl98b:
    mov ax,0F8h
    push ax
    call mf52
    add sp,2h
    mov bx,word ptr [bp+6h]
    shl bx,1
    add word ptr [bx+62BAh],1h
    push word ptr [bp+6h]
    call mf58
    add sp,2h
    mov bx,word ptr [bp+6h]
    shl bx,1
    add word ptr [bx+62BAh],ax
    jmp near ptr lblEBf
    jmp near ptr lblEBf
lblC8f:
    cmp ax, offset mi65
    jnz short lblD0f
    jmp near ptr lbl8Ab
lblD0f:
    cmp ax, offset mi68
    jnz short lblD8f
    jmp near ptr lbl1Fb
lblD8f:
    cmp ax, offset mi71
    jnz short lblE0f
    jmp near ptr lbl31b
lblE0f:
    cmp ax, offset mi74
    jnz short lblE8f
    jmp near ptr lbl7Cb
lblE8f:
    jmp near ptr lbl98b
lblEBf:
    mov ax,1h
    jmp near ptr lblF1f
lblF1f:
    pop di
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
