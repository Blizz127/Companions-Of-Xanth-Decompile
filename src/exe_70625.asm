_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi2:NEAR
    EXTRN mf8:FAR
    EXTRN mi13:NEAR
    EXTRN mf16:FAR
    EXTRN mf27:FAR
    EXTRN mf31:FAR
    EXTRN mi38:NEAR
    EXTRN mi39:NEAR
    EXTRN mf47:FAR
    EXTRN mf47:FAR
    EXTRN mf47:FAR
    EXTRN mf47:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp, offset mi2
    push si
    push di
    mov byte ptr ds:[6288h],0h
    mov ax,0h
    push ax
    call mf8
    add sp,2h
    mov word ptr ds:[6DE4h],1575h
    mov al,byte ptr ds:[40F8h]
    cbw
    cmp ax, offset mi13
    jnz short lbl2Cf
    jmp near ptr lbl31f
lbl2Cf:
    call mf16
lbl31f:
    mov word ptr [bp-4h],0h
    jmp near ptr lbl69f
lbl39b:
    mov bx,word ptr [bp-4h]
    shl bx,1
    mov es, ds:[5B38h]
    mov word ptr es:[bx+48D8h],0h
    mov ax,0h
    push ax
    mov ax,word ptr [bp-4h]
    push ax
    call mf27
    add sp,4h
    mov ax,word ptr [bp-4h]
    push ax
    call mf31
    add sp,2h
    add word ptr [bp-4h],1h
lbl69f:
    cmp word ptr [bp-4h],0Bh
    jnl short lbl72f
    jmp near ptr lbl39b
lbl72f:
    mov ax,word ptr ds:[416Eh]
    and ax, offset mi38
    cmp ax, offset mi39
    jnz short lbl80f
    jmp near ptr lbl85f
lbl80f:
    and word ptr ds:[416Eh],0FFFFFFFFFFFFFF8Fh
lbl85f:
    pop di
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
