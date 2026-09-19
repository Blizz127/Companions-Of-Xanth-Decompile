_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi6:NEAR
    EXTRN mf53:FAR
    EXTRN mfde:FAR
    EXTRN mi9:NEAR
    EXTRN mf44:FAR
    EXTRN mf11d:FAR
    EXTRN mff8:FAR
    EXTRN mf16f:FAR
    EXTRN mf109:FAR
    EXTRN mf69:FAR
    EXTRN mfbe:FAR
    EXTRN mf80:FAR
    EXTRN mf15b:FAR
    EXTRN mfd1:FAR
    EXTRN mfd9:FAR
    EXTRN mf145:FAR
    EXTRN mfaa:FAR
    EXTRN mf12d:FAR
    EXTRN mf9a:FAR
    EXTRN mff3:FAR
mnem_unit:
    push bp
    mov bp,sp
    mov ax,word ptr [bp+6h]
    sub ax, offset mi6
    cmp ax, offset mi9
    jna short lbl11f
    jmp near ptr lbl174f
lbl11f:
    add ax,ax
    xchg ax,bx
    jmp word ptr cs:[bx+29Fh]
    nop
    db 0C1h, 02h, 0F9h, 02h, 0F9h, 02h, 0F9h, 02h, 0F9h, 03h, 0FDh, 02h, 27h, 03h, 4Bh, 03h
    db 0F9h, 03h, 0F9h, 03h, 0F9h, 03h, 0F9h, 03h, 0F9h, 03h, 0F9h, 03h, 71h, 03h, 0EBh, 03h
    db 4Bh, 03h
    mov ax,1h
    mov dx,0F01Bh
    push dx
    push ax
    call mf44
    mov sp,bp
    mov ax,0C7h
    push ax
    mov ax,0Ah
    push ax
    call mf53
    mov sp,bp
    or ax,ax
    jnz short lbl61f
    jmp near ptr lbl174f
lbl61f:
    mov ax,2h
lbl64b:
    mov dx,0F01Bh
    push dx
    push ax
    call mf69
lbl6Eb:
    mov sp,bp
    jmp near ptr lbl174f
    nop
    xor ax,ax
    jmp short lbl64b
    mov ax,0C7h
    push ax
    mov ax,0Ah
    push ax
    call mf80
    mov sp,bp
    or ax,ax
    jnz short lbl8Ef
    jmp near ptr lbl174f
lbl8Ef:
    mov ax,1h
    push ax
    mov ax,12h
    push ax
    mov ax,8026h
    push ax
    call mf9a
    jmp near ptr lbl174f
    mov ax,5h
    push ax
    mov ax,0C7h
    push ax
    call mfaa
    add sp,4h
    or ax,ax
    jz short lblB9f
    jmp near ptr lbl174f
lblB9f:
    push ax
    mov ax,13h
    push ax
    call mfbe
    jmp short lbl6Eb
    nop
    xor ax,ax
    push ax
    mov ax,12h
    push ax
    mov ax,8026h
    push ax
    call mfd1
    add sp,6h
    call mfd9
    call mfde
    mov byte ptr ds:[2BE0h],0h
    jmp near ptr lbl174f
    nop
    cmp byte ptr ds:[2BE0h],0h
    jnz short lbl152f
    call mff3
    call mff8
    xor ax,ax
    push ax
    push ax
    mov cx,27h
    push cx
    mov cx,835h
    push cx
    call mf109
    add sp,8h
    xor ax,ax
    push ax
    push ax
    mov cx,0Dh
    push cx
    mov cx,85Ch
    push cx
    call mf11d
    add sp,8h
    mov ax,0C7h
    push ax
    mov ax,0Ah
    push ax
    call mf12d
    add sp,4h
    or ax,ax
    jz short lbl14Df
    xor ax,ax
    push ax
    push ax
    mov ax,18h
    push ax
    mov ax,869h
    push ax
    call mf145
    add sp,8h
lbl14Df:
    mov byte ptr ds:[2BE0h],1h
lbl152f:
    mov ax,1h
    push ax
    mov ax,2BE2h
    push ds
    push ax
    call mf15b
    add sp,6h
    jmp short lbl176f
    nop
    mov ax,1h
    push ax
    mov ax,2BEEh
    push ds
    push ax
    call mf16f
lbl174f:
    xor ax,ax
lbl176f:
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
