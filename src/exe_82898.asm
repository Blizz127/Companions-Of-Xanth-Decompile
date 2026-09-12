_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf21:FAR
    EXTRN mf43:FAR
    EXTRN mf57:FAR
    EXTRN mf63:FAR
    EXTRN mf69:FAR
    EXTRN mf77:FAR
    EXTRN mf84:FAR
    EXTRN mf96:FAR
    EXTRN mf97:FAR
    EXTRN mf102:FAR
    EXTRN mf102:FAR
    EXTRN mf102:FAR
    EXTRN mf102:FAR
    EXTRN mf102:FAR
    EXTRN mf102:FAR
    EXTRN mf102:FAR
    EXTRN mf102:FAR
    EXTRN mf102:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,300h
    push di
    push si
    mov ax,word ptr [bp+6h]
    cmp word ptr [bp+0Ah],ax
    jnl short lbl14f
    jmp near ptr lbl116f
lbl14f:
    mov ax,word ptr [bp+8h]
    cmp word ptr [bp+0Ch],ax
    jnl short lbl1Ff
    jmp near ptr lbl116f
lbl1Ff:
    cmp word ptr ds:[4244h],0h
    jnl short lbl42f
    mov ax,4h
    push ax
    push word ptr [bp+0Ch]
    push word ptr [bp+0Ah]
    push word ptr [bp+8h]
    push word ptr [bp+6h]
    call mf21
    add sp,0Ah
    jmp near ptr lbl116f
    nop
lbl42f:
    cmp byte ptr ds:[4246h],0h
    jnz short lblA0f
    mov ax,38AFh
    push ds
    lea di,word ptr [bp-300h]
    mov si,6A24h
    push ss
    pop es
    mov ds,ax
    mov cx,180h
    rep movsw
    pop ds
    xor cx,cx
    push cx
    push word ptr ds:[4244h]
    mov cx,4246h
    push ds
    push cx
    call mf43
    add sp,8h
    mov ax,6A24h
    mov cx,38AFh
    mov di,ax
    lea si,word ptr [bp-300h]
    mov es,cx
    mov cx,180h
    rep movsw
    cmp byte ptr ds:[4246h],0h
    jz short lblA0f
    push word ptr ds:[425Ah]
    push word ptr ds:[4254h]
    push word ptr ds:[4252h]
    call mf57
    add sp,6h
lblA0f:
    push word ptr [bp+0Ch]
    push word ptr [bp+0Ah]
    push word ptr [bp+8h]
    push word ptr [bp+6h]
    call mf63
    add sp,8h
    cmp byte ptr ds:[4246h],0h
    jnz short lblE2f
    mov ax,14h
    push ax
    call mf69
    add sp,2h
    push word ptr [bp+0Ch]
    push word ptr [bp+0Ah]
    push word ptr [bp+8h]
    push word ptr [bp+6h]
    mov ax,2h
    push ax
    call mf77
    add sp,0Ah
    jmp short lbl111f
    nop
lblE2f:
    mov ax,4246h
    push ds
    push ax
    call mf84
    add sp,4h
    push word ptr ds:[4258h]
    push word ptr ds:[4256h]
    push word ptr [bp+6h]
    push word ptr [bp+8h]
    push word ptr [bp+6h]
    push word ptr [bp+8h]
    push word ptr [bp+0Ah]
    push word ptr [bp+0Ch]
    xor ax,ax
    push ax
    call mf96
lbl111f:
    call mf97
lbl116f:
    pop si
    pop di
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
