_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf18:FAR
    EXTRN mf28:FAR
    EXTRN mf37:FAR
    EXTRN mf43:FAR
    EXTRN mf47:FAR
    EXTRN mf47:FAR
    EXTRN mf47:FAR
    EXTRN mf47:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,7Ch
    cmp byte ptr ds:[189Ah],0h
    jz short lbl60f
    mov ax,26Ah
    push ds
    push ax
    mov ax,48h
    mov cx,2EC4h
    push cx
    push ax
    mov ax,18A4h
    push ds
    push ax
    lea ax,word ptr [bp-7Ch]
    push ss
    push ax
    call mf18
    add sp,10h
    lea ax,word ptr [bp-2Ch]
    push ss
    push ax
    xor ax,ax
    push ax
    lea cx,word ptr [bp-7Ch]
    push ss
    push cx
    call mf28
    add sp,0Ah
    or ax,ax
    jnz short lbl60f
    push ax
    push ax
    mov ax,18AFh
    push ds
    push ax
    call mf37
    add sp,8h
    dec ax
    jnz short lbl60f
    mov ax,2h
    push ax
    call mf43
lbl60f:
    mov byte ptr ds:[189Ah],0h
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
