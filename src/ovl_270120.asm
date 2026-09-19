_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi6:NEAR
    EXTRN mfaf:FAR
    EXTRN mi9:NEAR
    EXTRN mfc8:FAR
    EXTRN mf44:FAR
    EXTRN md14:NEAR
    EXTRN mf53:FAR
    EXTRN mf65:FAR
    EXTRN mf99:FAR
    EXTRN mf80:FAR
    EXTRN mf85:FAR
    EXTRN mfde:FAR
    EXTRN mf9e:FAR
mnem_unit:
    push bp
    mov bp,sp
    mov ax,word ptr [bp+6h]
    sub ax, offset mi6
    cmp ax, offset mi9
    jna short lbl11f
    db 0E9h, 0D2h, 00h ; override
lbl11f:
    add ax,ax
    xchg ax,bx
    jmp word ptr cs:[bx+md14]
    nop
    db 54h, 00h, 76h, 00h, 76h, 00h, 76h, 00h, 0FBh, 00h, 0FBh, 00h, 0FBh, 00h, 98h, 00h
    db 0FBh, 00h, 0FBh, 00h, 0FBh, 00h, 0FBh, 00h, 0FBh, 00h, 0FBh, 00h, 0AAh, 00h, 0EAh, 00h
    db 98h, 00h
    mov ax,0Ah
    push ax
    mov ax,158h
    push ax
    call mf44
    mov sp,bp
    mov ax,1h
    mov dx,0F03Ah
    push dx
lbl52b:
    push ax
    call mf53
    mov sp,bp
    jmp near ptr lblE3f
    nop
    xor ax,ax
    mov dx,0F03Ah
    push dx
    push ax
    call mf65
    mov sp,bp
    cmp byte ptr ds:[35Ah],0h
    jnz short lbl7Af
    mov ax,35ADh
lbl76b:
    push ds
    jmp short lbl52b
    nop
lbl7Af:
    mov ax,35BBh
    jmp short lbl76b
    nop
    call mf80
    call mf85
    mov byte ptr ds:[35ACh],0h
    jmp short lblE3f
    nop
    cmp byte ptr ds:[35ACh],0h
    jnz short lblBCf
    call mf99
    call mf9e
    xor ax,ax
    push ax
    push ax
    mov ax,16h
    push ax
    mov ax,0F0Dh
    push ax
    call mfaf
    add sp,8h
    mov byte ptr ds:[35ACh],1h
lblBCf:
    mov ax,2h
    push ax
    mov ax,0h
    mov cx,32B6h
    push cx
    push ax
    call mfc8
    add sp,6h
    jmp short lblE5f
    mov ax,3h
    push ax
    mov ax,18h
    mov cx,32B6h
    push cx
    push ax
    call mfde
lblE3f:
    xor ax,ax
lblE5f:
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
