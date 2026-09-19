_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi6:NEAR
    EXTRN mf56:FAR
    EXTRN mi9:NEAR
    EXTRN mf81:FAR
    EXTRN mf13c:FAR
    EXTRN mfa6:FAR
    EXTRN md14:NEAR
    EXTRN mf113:FAR
    EXTRN mfec:FAR
    EXTRN mi41:NEAR
    EXTRN mfb7:FAR
    EXTRN mfca:FAR
    EXTRN mf100:FAR
    EXTRN mf72:FAR
    EXTRN mi46:NEAR
    EXTRN mf90:FAR
    EXTRN mf126:FAR
mnem_unit:
    push bp
    mov bp,sp
    mov ax,word ptr [bp+6h]
    sub ax, offset mi6
    cmp ax, offset mi9
    jna short lbl11f
    db 0E9h, 30h, 01h ; override
lbl11f:
    add ax,ax
    xchg ax,bx
    jmp word ptr cs:[bx+md14]
    nop
    db 62h, 00h, 65h, 01h, 8Eh, 00h, 0E6h, 00h, 0E6h, 00h, 0E6h, 00h, 65h, 01h, 65h, 01h
    db 08h, 01h, 65h, 01h, 65h, 01h, 65h, 01h, 65h, 01h, 65h, 01h, 65h, 01h, 65h, 01h
    db 3Eh, 01h, 54h, 01h
    mov ax,word ptr ds:[6A06h]
    sub ax, offset mi41
    jz short lbl4Ef
    sub ax, offset mi46
    jz short lbl64f
    jmp near ptr lbl141f
lbl4Ef:
    mov ax,3h
lbl51b:
    mov dx,0F047h
    push dx
    push ax
    call mf56
    mov sp,bp
    mov ax,1h
    jmp near ptr lbl143f
    nop
lbl64f:
    mov ax,4h
    jmp short lbl51b
    nop
    mov ax,0Ah
    push ax
    mov ax,19Ah
    push ax
    call mf72
    mov sp,bp
    mov ax,1h
    mov dx,0F047h
    push dx
    push ax
    call mf81
    mov sp,bp
    mov ax,19Ah
    push ax
    mov ax,199h
    push ax
    call mf90
    mov sp,bp
    or ax,ax
    jnz short lbl9Ef
    jmp near ptr lbl141f
lbl9Ef:
    mov ax,195h
    push ax
    mov ax,1h
    push ax
    call mfa6
    mov sp,bp
    push dx
    push ax
    mov ax,2h
lblB2b:
    mov dx,0F047h
    push dx
    push ax
    call mfb7
    mov sp,bp
    jmp near ptr lbl141f
    nop
    mov ax,0Eh
    push ax
    mov ax,19Bh
    push ax
    call mfca
    mov sp,bp
    or ax,ax
    jz short lblDAf
    mov ax,3932h
    jmp short lblDDf
lblDAf:
    mov ax,3939h
lblDDf:
    push ds
    push ax
    xor ax,ax
    jmp short lblB2b
    nop
    mov ax,0Ah
    push ax
    mov ax,19Ah
    push ax
    call mfec
    add sp,4h
    or ax,ax
    jnz short lbl141f
    mov ax,0Ah
    push ax
    mov ax,19Ah
    push ax
    call mf100
    add sp,4h
    xor ax,ax
    push ax
    mov ax,1h
    push ax
    mov ax,0Ah
    push ax
    call mf113
    jmp short lbl141f
    mov ax,2h
    push ax
    mov ax,0h
    mov cx,3352h
    push cx
    push ax
    call mf126
    add sp,6h
    jmp short lbl143f
    mov ax,3h
    push ax
    mov ax,18h
    mov cx,3352h
    push cx
    push ax
    call mf13c
lbl141f:
    xor ax,ax
lbl143f:
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
