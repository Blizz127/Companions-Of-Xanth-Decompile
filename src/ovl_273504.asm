_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi6:NEAR
    EXTRN mi9:NEAR
    EXTRN mfad:FAR
    EXTRN mfc1:FAR
    EXTRN mf44:FAR
    EXTRN md14:NEAR
    EXTRN mf53:FAR
    EXTRN mfa8:FAR
    EXTRN mf80:FAR
    EXTRN mfc6:FAR
    EXTRN mf75:FAR
    EXTRN mfea:FAR
    EXTRN mfa1:FAR
    EXTRN mf8f:FAR
    EXTRN mfd7:FAR
mnem_unit:
    push bp
    mov bp,sp
    mov ax,word ptr [bp+6h]
    sub ax, offset mi6
    cmp ax, offset mi9
    jna short lbl11f
    db 0E9h, 0E9h, 00h ; override
lbl11f:
    add ax,ax
    xchg ax,bx
    jmp word ptr cs:[bx+md14]
    nop
    db 3Ch, 00h, 5Eh, 00h, 5Eh, 00h, 5Eh, 00h, 0FAh, 00h, 0FAh, 00h, 62h, 00h, 0A8h, 00h
    db 0FAh, 00h, 0FAh, 00h, 0FAh, 00h, 0FAh, 00h, 0FAh, 00h, 0FAh, 00h, 0BAh, 00h, 0FAh, 00h
    db 0A8h, 00h
    mov ax,0Ah
    push ax
    mov ax,160h
    push ax
    call mf44
    mov sp,bp
    mov ax,1h
lbl4Eb:
    mov dx,0F03Bh
    push dx
    push ax
    call mf53
lbl58b:
    mov sp,bp
    jmp near ptr lblFAf
    nop
    xor ax,ax
    jmp short lbl4Eb
    cmp byte ptr ds:[35Bh],0h
    jz short lbl6Cf
    jmp near ptr lblFAf
lbl6Cf:
    mov byte ptr ds:[35Bh],1h
    mov ax,0Bh
    push ax
    call mf75
    mov sp,bp
    mov ax,1388h
    push ax
    call mf80
    mov sp,bp
    mov ax,5A13h
    push ax
    mov ax,3D2h
    push ax
    call mf8f
    mov sp,bp
    mov ax,1h
    push ax
    xor ax,ax
    push ax
    mov ax,0Ah
    push ax
    call mfa1
    jmp short lbl58b
    call mfa8
    call mfad
    mov byte ptr ds:[35FAh],0h
    jmp short lblFAf
    nop
    cmp byte ptr ds:[35FAh],0h
    jnz short lblFAf
    call mfc1
    call mfc6
    xor ax,ax
    push ax
    push ax
    mov cx,8h
    push cx
    mov cx,0F38h
    push cx
    call mfd7
    mov sp,bp
    xor ax,ax
    push ax
    push ax
    mov ax,2Dh
    push ax
    mov ax,0F40h
    push ax
    call mfea
    mov sp,bp
    mov ax,1h
    mov byte ptr ds:[35FAh],al
    jmp short lblFCf
    nop
lblFAf:
    xor ax,ax
lblFCf:
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
