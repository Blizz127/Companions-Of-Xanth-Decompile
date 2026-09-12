_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi3:NEAR
    EXTRN mi4:NEAR
    EXTRN mf32:FAR
    EXTRN mf38:FAR
    EXTRN mf47:FAR
    EXTRN mf54:FAR
    EXTRN mf57:FAR
    EXTRN mf58:FAR
    EXTRN mf64:FAR
    EXTRN mf65:FAR
    EXTRN mf73:FAR
    EXTRN mf82:FAR
    EXTRN mf82:FAR
    EXTRN mf82:FAR
    EXTRN mf82:FAR
    EXTRN mf82:FAR
    EXTRN mf82:FAR
    EXTRN mf82:FAR
    EXTRN mf82:FAR
    EXTRN mf82:FAR
mnem_unit:
    push bp
    mov bp,sp
    mov ax,word ptr [bp+6h]
    sub ax, offset mi3
    cmp ax, offset mi4
    jna short lbl11f
    jmp near ptr lblC2f
lbl11f:
    add ax,ax
    xchg ax,bx
    jmp word ptr cs:[bx+2ADh]
    nop
    iret
    add ch,bh
    add ch,bh
    add ch,bh
    add dl,byte ptr [di+3h]
    push bp
    add si,bp
    add dl,byte ptr [di]
    add dx,word ptr [di+3h]
    push bp
    add dx,word ptr [di+3h]
    push bp
    add dx,word ptr [di+3h]
    push bp
    add sp,word ptr [bx]
    add dx,word ptr [di+3h]
    adc ax,0B803h
    or al,byte ptr [bx+si]
    push ax
    mov ax,1B1h
    push ax
    call mf32
    mov sp,bp
    mov ax,0Eh
lbl4Eb:
    mov dx,0F048h
    push dx
    push ax
    call mf38
lbl58b:
    mov sp,bp
    jmp short lblC2f
    mov ax,0Dh
    jmp short lbl4Eb
    nop
    mov ax,5h
    push ax
    push word ptr ds:[256h]
    call mf47
    mov sp,bp
    or ax,ax
    jnz short lblC2f
    mov ax,39B5h
    push ds
    push ax
    call mf54
    jmp short lbl58b
    nop
    call mf57
    call mf58
    mov byte ptr ds:[39B4h],0h
    jmp short lblC2f
    nop
    cmp byte ptr ds:[39B4h],0h
    jnz short lblC2f
    call mf64
    call mf65
    xor ax,ax
    push ax
    push ax
    mov ax,9h
    push ax
    mov ax,1202h
    push ax
    call mf73
    add sp,8h
    mov ax,1h
    mov byte ptr ds:[39B4h],al
    jmp short lblC4f
    nop
lblC2f:
    xor ax,ax
lblC4f:
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
