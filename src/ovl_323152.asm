_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi6:NEAR
    EXTRN mfaf:FAR
    EXTRN mf113:FAR
    EXTRN mf122:FAR
    EXTRN mf60:FAR
    EXTRN mf14d:FAR
    EXTRN mfd7:FAR
    EXTRN mfed:FAR
    EXTRN mi9:NEAR
    EXTRN mf42:FAR
    EXTRN mf8a:FAR
    EXTRN md14:NEAR
    EXTRN mf99:FAR
    EXTRN mf76:FAR
    EXTRN mfbe:FAR
    EXTRN mffd:FAR
    EXTRN mf51:FAR
    EXTRN mf139:FAR
    EXTRN mf105:FAR
mnem_unit:
    push bp
    mov bp,sp
    mov ax,word ptr [bp+6h]
    sub ax, offset mi6
    cmp ax, offset mi9
    jna short lbl11f
    db 0E9h, 41h, 01h ; override
lbl11f:
    add ax,ax
    xchg ax,bx
    jmp word ptr cs:[bx+md14]
    nop
    db 3Ah, 00h, 80h, 00h, 80h, 00h, 80h, 00h, 52h, 01h, 52h, 01h, 86h, 00h, 52h, 01h
    db 52h, 01h, 52h, 01h, 52h, 01h, 52h, 01h, 52h, 01h, 52h, 01h, 0C6h, 00h, 44h, 01h
    mov ax,0Ah
    push ax
    mov ax,1DEh
    push ax
    call mf42
    mov sp,bp
    mov ax,2h
    mov dx,0F04Ch
    push dx
    push ax
    call mf51
    mov sp,bp
    push word ptr ds:[256h]
    mov ax,1EEh
    push ax
    call mf60
    mov sp,bp
    or ax,ax
    jnz short lbl6Ef
    jmp near ptr lbl152f
lbl6Ef:
    mov ax,3h
lbl71b:
    mov dx,0F04Ch
    push dx
    push ax
    call mf76
lbl7Bb:
    mov sp,bp
    jmp near ptr lbl152f
    mov ax,1h
    jmp short lbl71b
    nop
    mov ax,1388h
    push ax
    call mf8a
    mov sp,bp
    mov ax,0Ah
    push ax
    mov ax,1EDh
    push ax
    call mf99
    mov sp,bp
    or ax,ax
    jz short lblA7f
    jmp near ptr lbl152f
lblA7f:
    mov ax,0Ah
    push ax
    mov ax,1EDh
    push ax
    call mfaf
    mov sp,bp
    mov ax,5A01h
    push ax
    mov ax,2DFh
    push ax
    call mfbe
    jmp short lbl7Bb
    nop
    cmp byte ptr ds:[3AF2h],0h
    jz short lbl130f
    mov byte ptr ds:[3AF2h],0h
    mov ax,3B0Ch
    push ds
    push ax
    call mfd7
    add sp,4h
    cmp word ptr ds:[58h],0h
    jnz short lbl10Af
    cmp word ptr ds:[56h],1h
    jz short lbl10Af
    call mfed
    xor al,al
    push ax
    mov ax,0Ah
    push ax
    mov ax,1234h
    push ax
    call mffd
    add sp,6h
    call mf105
lbl10Af:
    mov byte ptr ds:[783h],1h
    mov ax,1CEh
    push ax
    call mf113
    add sp,2h
    xor ax,ax
    mov dx,0F04Ch
    push dx
    push ax
    call mf122
    add sp,4h
    mov ax,1h
    jmp short lbl154f
    nop
lbl130f:
    mov ax,1h
    push ax
    mov ax,3AF4h
    push ds
    push ax
    call mf139
    add sp,6h
    jmp short lbl154f
    nop
    mov ax,1h
    push ax
    mov ax,3B00h
    push ds
    push ax
    call mf14d
lbl152f:
    xor ax,ax
lbl154f:
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
