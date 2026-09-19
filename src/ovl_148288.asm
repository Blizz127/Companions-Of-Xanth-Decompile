_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi6:NEAR
    EXTRN mi9:NEAR
    EXTRN mf87:FAR
    EXTRN mfb1:FAR
    EXTRN mfeb:FAR
    EXTRN mf44:FAR
    EXTRN md14:NEAR
    EXTRN mf53:FAR
    EXTRN mf82:FAR
    EXTRN mfd9:FAR
    EXTRN mf75:FAR
    EXTRN mfa0:FAR
    EXTRN mf9b:FAR
    EXTRN mfc4:FAR
    EXTRN mf66:FAR
mnem_unit:
    push bp
    mov bp,sp
    mov ax,word ptr [bp+6h]
    sub ax, offset mi6
    cmp ax, offset mi9
    jna short lbl11f
    db 0E9h, 0DFh, 00h ; override
lbl11f:
    add ax,ax
    xchg ax,bx
    jmp word ptr cs:[bx+md14]
    nop
    db 3Ch, 00h, 7Eh, 00h, 7Eh, 00h, 7Eh, 00h, 0F0h, 00h, 0F0h, 00h, 0F0h, 00h, 82h, 00h
    db 0F0h, 00h, 0F0h, 00h, 0F0h, 00h, 0F0h, 00h, 0F0h, 00h, 0F0h, 00h, 94h, 00h, 0E2h, 00h
    db 82h, 00h
    mov ax,1h
    mov dx,0F018h
    push dx
    push ax
    call mf44
    mov sp,bp
    mov ax,0Dh
    push ax
    mov ax,0BDh
    push ax
    call mf53
    mov sp,bp
    or ax,ax
    jz short lbl6Df
    mov ax,2h
    mov dx,0F018h
    push dx
    push ax
    call mf66
    mov sp,bp
lbl6Df:
    mov ax,3h
lbl70b:
    mov dx,0F018h
    push dx
    push ax
    call mf75
    mov sp,bp
    jmp short lblF0f
    xor ax,ax
    jmp short lbl70b
    call mf82
    call mf87
    mov byte ptr ds:[29FCh],0h
    jmp short lblF0f
    nop
    cmp byte ptr ds:[29FCh],0h
    jnz short lblD0f
    call mf9b
    call mfa0
    xor ax,ax
    push ax
    push ax
    mov cx,16h
    push cx
    mov cx,650h
    push cx
    call mfb1
    mov sp,bp
    xor ax,ax
    push ax
    push ax
    mov ax,6h
    push ax
    mov ax,666h
    push ax
    call mfc4
    mov sp,bp
    mov byte ptr ds:[29FCh],1h
lblD0f:
    mov ax,1h
    push ax
    mov ax,29FEh
    push ds
    push ax
    call mfd9
    mov sp,bp
    jmp short lblF2f
    mov ax,1h
    push ax
    mov ax,2A0Ah
    push ds
    push ax
    call mfeb
lblF0f:
    xor ax,ax
lblF2f:
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
