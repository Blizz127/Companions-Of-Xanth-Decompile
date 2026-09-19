_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi6:NEAR
    EXTRN mi9:NEAR
    EXTRN mf42:FAR
    EXTRN mf71:FAR
    EXTRN mf99:FAR
    EXTRN mf80:FAR
    EXTRN mf51:FAR
    EXTRN mfae:FAR
mnem_unit:
    push bp
    mov bp,sp
    mov ax,word ptr [bp+6h]
    sub ax, offset mi6
    cmp ax, offset mi9
    jna short lbl11f
    jmp near ptr lblB3f
lbl11f:
    add ax,ax
    xchg ax,bx
    jmp word ptr cs:[bx+633h]
    nop
    db 53h, 06h, 0A3h, 06h, 0A3h, 06h, 0A3h, 06h, 0CCh, 06h, 0CCh, 06h, 0CCh, 06h, 0CCh, 06h
    db 0CCh, 06h, 0CCh, 06h, 0CCh, 06h, 0CCh, 06h, 0CCh, 06h, 0CCh, 06h, 0A9h, 06h, 0BBh, 06h
    mov ax,0Ah
    push ax
    mov ax,197h
    push ax
    call mf42
    mov sp,bp
    mov ax,0Ah
    push ax
    mov ax,195h
    push ax
    call mf51
    mov sp,bp
    or ax,ax
    jz short lbl64f
    mov ax,19h
    mov dx,0F046h
    jmp short lbl67f
lbl64f:
    xor ax,ax
    cwd
lbl67f:
    push dx
    push ax
    mov ax,18h
    mov dx,0F046h
    push dx
    push ax
    call mf71
    mov sp,bp
    mov ax,1Ah
lbl7Bb:
    mov dx,0F046h
    push dx
    push ax
    call mf80
    mov sp,bp
    jmp short lblB3f
    nop
    mov ax,17h
    jmp short lbl7Bb
    nop
    mov ax,1h
    push ax
    mov ax,3916h
    push ds
    push ax
    call mf99
    mov sp,bp
    jmp short lblB5f
    mov ax,6h
    push ax
    mov ax,30h
    mov cx,32A5h
    push cx
    push ax
    call mfae
lblB3f:
    xor ax,ax
lblB5f:
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
