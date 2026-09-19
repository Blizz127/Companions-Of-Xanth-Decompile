_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi9:NEAR
    EXTRN mic:NEAR
    EXTRN mf44:FAR
    EXTRN mfba:FAR
    EXTRN mfd0:FAR
    EXTRN mfa4:FAR
    EXTRN mf54:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,4h
    mov ax,word ptr [bp+6h]
    sub ax, offset mi9
    cmp ax, offset mic
    jna short lbl14f
    jmp near ptr lblD5f
lbl14f:
    add ax,ax
    xchg ax,bx
    jmp word ptr cs:[bx+82h]
    db 0A2h, 00h, 0C6h, 00h, 0C6h, 00h, 0C6h, 00h, 3Bh, 01h, 3Bh, 01h, 3Bh, 01h, 3Bh, 01h
    db 3Bh, 01h, 3Bh, 01h, 3Bh, 01h, 3Bh, 01h, 3Bh, 01h, 3Bh, 01h, 14h, 01h, 2Ah, 01h
    mov ax,0Ah
    push ax
    mov ax,18Ah
    push ax
    call mf44
    add sp,4h
    mov ax,2h
    mov dx,0F01Eh
    push dx
    push ax
    call mf54
    add sp,4h
    jmp short lblD5f
    nop
    nop
    mov ax,word ptr ds:[2DCh]
    or ax,ax
    jz short lbl72f
    dec ax
    jz short lbl7Af
    dec ax
    jz short lbl86f
    dec ax
    jz short lbl8Ef
    jmp short lbl96f
lbl72f:
    mov word ptr [bp-4h],3860h
    jmp short lbl93f
    nop
lbl7Af:
    mov word ptr [bp-4h],0h
    mov word ptr [bp-2h],0F01Eh
    jmp short lbl96f
lbl86f:
    mov word ptr [bp-4h],386Dh
    jmp short lbl93f
    nop
lbl8Ef:
    mov word ptr [bp-4h],387Ch
lbl93f:
    mov word ptr [bp-2h],ds
lbl96f:
    push word ptr [bp-2h]
    push word ptr [bp-4h]
    mov ax,1h
    mov dx,0F01Eh
    push dx
    push ax
    call mfa4
    add sp,8h
    jmp short lblD5f
    mov ax,3h
    push ax
    mov ax,0h
    mov cx,32E0h
    push cx
    push ax
    call mfba
    add sp,6h
    jmp short lblD7f
    mov ax,7h
    push ax
    mov ax,24h
    mov cx,32E0h
    push cx
    push ax
    call mfd0
lblD5f:
    xor ax,ax
lblD7f:
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
