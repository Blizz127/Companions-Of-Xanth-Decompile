_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi3:NEAR
    EXTRN mi7:NEAR
    EXTRN mf26:FAR
    EXTRN mf41:FAR
    EXTRN mf43:FAR
    EXTRN mf47:FAR
    EXTRN mf51:FAR
    EXTRN mf53:FAR
    EXTRN mf61:FAR
    EXTRN mf63:FAR
    EXTRN mf68:FAR
    EXTRN mf74:FAR
    EXTRN mf81:FAR
    EXTRN mf81:FAR
    EXTRN mf81:FAR
    EXTRN mf81:FAR
    EXTRN mf81:FAR
    EXTRN mf81:FAR
    EXTRN mf81:FAR
    EXTRN mf81:FAR
    EXTRN mf81:FAR
    EXTRN mf81:FAR
mnem_unit:
    push bp
    mov bp,sp
    mov ax,word ptr [bp+6h]
    sub ax, offset mi3
    jz short lbl0Ef
    jmp near ptr lblC8f
lbl0Ef:
    mov ax,word ptr ds:[6A06h]
    cmp ax, offset mi7
    jnz short lbl19f
    jmp near ptr lblC2f
lbl19f:
    jna short lbl1Ef
    jmp near ptr lblC8f
lbl1Ef:
    sub al,8h
    jz short lbl32f
    sub al,0Bh
    jz short lbl48f
    sub al,19h
    jz short lbl4Ef
    sub al,18h
    jz short lbl54f
    jmp near ptr lblC8f
    nop
lbl32f:
    mov ax,17h
lbl35b:
    mov dx,0F00Bh
    push dx
    push ax
    call mf26
lbl3Fb:
    mov sp,bp
lbl41b:
    mov ax,1h
    jmp near ptr lblCAf
    nop
lbl48f:
    mov ax,14h
    jmp short lbl35b
    nop
lbl4Ef:
    mov ax,16h
    jmp short lbl35b
    nop
lbl54f:
    mov ax,15h
    mov dx,0F00Bh
    push dx
    push ax
    call mf41
    mov sp,bp
    call mf43
    mov ax,2ED4h
    push ds
    push ax
    call mf47
    mov sp,bp
    mov ax,1B58h
    push ax
    call mf51
    mov sp,bp
    call mf53
    mov byte ptr ds:[310h],1h
    xor ax,ax
    push ax
    mov ax,0CDh
    push ax
    mov ax,0CEh
    push ax
    call mf61
    mov sp,bp
    call mf63
    cmp word ptr ds:[290h],5h
    jnz short lbl41b
    mov ax,7D0h
    push ax
    call mf68
    mov sp,bp
    mov ax,5A03h
    push ax
    mov ax,146h
    push ax
    call mf74
    jmp near ptr lbl3Fb
lblC2f:
    mov ax,18h
    jmp near ptr lbl35b
lblC8f:
    xor ax,ax
lblCAf:
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
