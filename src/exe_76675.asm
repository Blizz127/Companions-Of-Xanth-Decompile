_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi2:NEAR
    EXTRN mf9:FAR
    EXTRN mi14:NEAR
    EXTRN mf16:FAR
    EXTRN mi17:NEAR
    EXTRN mf22:FAR
    EXTRN mi23:NEAR
    EXTRN mf30:FAR
    EXTRN mf33:FAR
    EXTRN mi36:NEAR
    EXTRN mi39:NEAR
    EXTRN mi42:NEAR
    EXTRN mf52:FAR
    EXTRN mf52:FAR
    EXTRN mf52:FAR
    EXTRN mf52:FAR
    EXTRN mf52:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp, offset mi2
    push si
    push di
    mov ax,word ptr [bp+8h]
    mov word ptr ds:[4172h],ax
    mov ax,word ptr [bp+0Ah]
    mov word ptr ds:[4174h],ax
    call mf9
    mov ax,0h
    or ax,word ptr [bp+6h]
    mov word ptr ds:[416Eh],ax
    mov ax,word ptr [bp+6h]
    and ax, offset mi14
    jmp near ptr lbl6Ef
lbl2Cb:
    call mf16
    cmp ax, offset mi17
    jnz short lbl39f
    jmp near ptr lbl3Ef
lbl39f:
    or word ptr ds:[416Eh],2h
lbl3Ef:
    jmp near ptr lbl89f
lbl41b:
    call mf22
    cmp ax, offset mi23
    jnz short lbl4Ef
    jmp near ptr lbl68f
lbl4Ef:
    mov ax,0EAh
    mov dx,2263h
    push dx
    push ax
    call mf30
    add sp,4h
    or word ptr ds:[416Eh],4h
    call mf33
lbl68f:
    jmp near ptr lbl89f
    jmp near ptr lbl89f
lbl6Ef:
    cmp ax, offset mi36
    jnz short lbl76f
    jmp near ptr lbl2Cb
lbl76f:
    cmp ax, offset mi39
    jnz short lbl7Ef
    jmp near ptr lbl2Cb
lbl7Ef:
    cmp ax, offset mi42
    jnz short lbl86f
    jmp near ptr lbl41b
lbl86f:
    jmp near ptr lbl89f
lbl89f:
    mov ax,word ptr ds:[416Eh]
    jmp near ptr lbl8Ff
lbl8Ff:
    pop di
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
