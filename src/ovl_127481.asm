_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi6:NEAR
    EXTRN mi9:NEAR
    EXTRN mffb:FAR
    EXTRN mf106:FAR
    EXTRN mf89:FAR
    EXTRN mfba:FAR
    EXTRN mf10b:FAR
    EXTRN mf94:FAR
    EXTRN mfb5:FAR
    EXTRN mf72:FAR
    EXTRN mfd2:FAR
    EXTRN mfe8:FAR
    EXTRN mfa4:FAR
    EXTRN mf54:FAR
mnem_unit:
    push bp
    mov bp,sp
    mov ax,word ptr [bp+6h]
    sub ax, offset mi6
    cmp ax, offset mi9
    jna short lbl11f
    jmp near ptr lbl115f
lbl11f:
    add ax,ax
    xchg ax,bx
    jmp word ptr cs:[bx+653h]
    nop
    db 75h, 06h, 75h, 06h, 75h, 06h, 75h, 06h, 4Eh, 07h, 97h, 06h, 0B3h, 06h, 0C9h, 06h
    db 4Eh, 07h, 4Eh, 07h, 4Eh, 07h, 4Eh, 07h, 4Eh, 07h, 4Eh, 07h, 0E7h, 06h, 2Bh, 07h
    db 3Fh, 07h
    cmp word ptr ds:[2A6h],2h
    jl short lbl48f
    mov ax,2h
    jmp short lbl4Bf
lbl48f:
    mov ax,1h
lbl4Bf:
    mov dx,0F017h
    push dx
    push ax
    xor ax,ax
    push dx
    push ax
    call mf54
lbl59b:
    mov sp,bp
    jmp near ptr lbl115f
    cmp word ptr ds:[2A6h],2h
    jl short lbl68f
    jmp near ptr lbl115f
lbl68f:
    xor ax,ax
    mov word ptr ds:[2B4h],ax
    push ax
    mov ax,12h
    push ax
    call mf72
    jmp short lbl59b
    nop
    cmp word ptr ds:[2A6h],2h
    jl short lbl84f
    jmp near ptr lbl115f
lbl84f:
    mov ax,2762h
    push ds
    push ax
    call mf89
    jmp short lbl59b
    mov ax,12h
    push ax
    call mf94
    add sp,2h
    or ax,ax
    jz short lbl106f
    mov ax,12h
    push ax
    call mfa4
    add sp,2h
    jmp short lbl106f
    cmp byte ptr ds:[2748h],0h
    jnz short lblDFf
    call mfb5
    call mfba
    cmp word ptr ds:[2A6h],2h
    jnl short lblDAf
    xor ax,ax
    push ax
    push ax
    mov ax,5h
    push ax
    mov ax,48Ch
    push ax
    call mfd2
    add sp,8h
lblDAf:
    mov byte ptr ds:[2748h],1h
lblDFf:
    mov ax,1h
    push ax
    mov ax,274Ah
    push ds
    push ax
    call mfe8
    add sp,6h
    jmp short lbl117f
    mov ax,1h
    push ax
    mov ax,2756h
    push ds
    push ax
    call mffb
    add sp,6h
    jmp short lbl115f
    nop
lbl106f:
    call mf106
    call mf10b
    mov byte ptr ds:[2748h],0h
lbl115f:
    xor ax,ax
lbl117f:
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
