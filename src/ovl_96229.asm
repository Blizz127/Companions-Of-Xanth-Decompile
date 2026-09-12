_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi3:NEAR
    EXTRN mi10:NEAR
    EXTRN mf16:FAR
    EXTRN mf23:FAR
    EXTRN mf31:FAR
    EXTRN mi37:NEAR
    EXTRN mf59:FAR
    EXTRN mf67:FAR
    EXTRN mf72:FAR
    EXTRN mf76:FAR
    EXTRN mf80:FAR
    EXTRN mf84:FAR
    EXTRN mf89:FAR
    EXTRN mf95:FAR
    EXTRN mf107:FAR
    EXTRN mf107:FAR
    EXTRN mf107:FAR
    EXTRN mf107:FAR
    EXTRN mf107:FAR
    EXTRN mf107:FAR
    EXTRN mf107:FAR
    EXTRN mf107:FAR
    EXTRN mf107:FAR
    EXTRN mf107:FAR
    EXTRN mf107:FAR
mnem_unit:
    push bp
    mov bp,sp
    mov ax,word ptr [bp+6h]
    sub ax, offset mi3
    jz short lbl12f
    dec ax
    dec ax
    jz short lbl56f
    jmp near ptr lbl100f
lbl12f:
    mov ax,word ptr ds:[6A06h]
    sub ax, offset mi10
    jz short lbl1Df
    jmp near ptr lbl100f
lbl1Df:
    push word ptr ds:[6A02h]
    mov ax,2h
    push ax
    call mf16
    mov sp,bp
    push dx
    push ax
    push word ptr ds:[6A04h]
    mov ax,2h
    push ax
    call mf23
    add sp,4h
    push dx
    push ax
    mov ax,19h
lbl43b:
    mov dx,0F016h
    push dx
    push ax
    call mf31
lbl4Db:
    mov sp,bp
    mov ax,1h
    jmp near ptr lbl102f
    nop
lbl56f:
    mov ax,word ptr ds:[6A06h]
    cmp ax, offset mi37
    jnz short lbl61f
    jmp near ptr lblFAf
lbl61f:
    jna short lbl66f
    jmp near ptr lbl100f
lbl66f:
    cmp al,27h
    jz short lbl82f
    ja short lbl74f
    sub al,13h
    jz short lbl82f
    jmp near ptr lbl100f
    nop
lbl74f:
    sub al,36h
    jnc short lbl7Bf
    jmp near ptr lbl100f
lbl7Bf:
    sub al,1h
    jna short lblE2f
    jmp short lbl100f
    nop
lbl82f:
    push word ptr ds:[290h]
    mov ax,11h
    push ax
    call mf59
    mov sp,bp
    push dx
    push ax
    mov ax,16h
    mov dx,0F016h
    push dx
    push ax
    call mf67
    mov sp,bp
    mov ax,23B1h
    push ds
    push ax
    call mf72
    mov ax,4h
    mov sp,bp
    push ax
    call mf76
    mov sp,bp
    mov ax,5h
    push ax
    call mf80
    mov sp,bp
    mov ax,2710h
    push ax
    call mf84
    mov sp,bp
    mov word ptr ds:[2A8h],2h
    mov ax,5Ah
    push ax
    call mf89
    jmp near ptr lbl4Db
    nop
lblE2f:
    push word ptr ds:[6A04h]
    mov ax,2h
    push ax
    call mf95
    mov sp,bp
    push dx
    push ax
    mov ax,18h
    jmp near ptr lbl43b
    nop
lblFAf:
    mov ax,17h
    jmp near ptr lbl43b
lbl100f:
    xor ax,ax
lbl102f:
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
