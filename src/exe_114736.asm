_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf12:FAR
    EXTRN mf20:FAR
    EXTRN mf26:FAR
    EXTRN mf29:FAR
    EXTRN mf34:FAR
    EXTRN mf34:FAR
    EXTRN mf34:FAR
    EXTRN mf34:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,2h
    push si
    cmp word ptr [bp+6h],0h
    jnl short lbl13f
    mov ax,word ptr ds:[51E0h]
    mov word ptr [bp+6h],ax
lbl13f:
    mov bx,word ptr [bp+6h]
    add bx,bx
    push word ptr [bx+6810h]
    mov si,bx
    call mf12
    add sp,2h
    mov ax,word ptr ds:[6DDAh]
    mov word ptr [si+68A0h],ax
    mov ax,word ptr ds:[6D48h]
    mov word ptr [si+68B0h],ax
    mov word ptr [si+68C0h],0FFFFh
    push word ptr [si+6830h]
    call mf20
    add sp,2h
    mov word ptr [bp-2h],ax
    xor ax,ax
    push ax
    push word ptr [bp+6h]
    call mf26
    add sp,4h
    push word ptr [bp-2h]
    call mf29
    add sp,2h
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
