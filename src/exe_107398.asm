_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf22:FAR
    EXTRN mf26:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,6h
    push di
    mov word ptr [bp-2h],0h
    cmp word ptr ds:[4F68h],0h
    jng short lbl3Cf
    xor ax,ax
    mov cx,word ptr ds:[4F68h]
    add cx,cx
    mov di,6776h
    push ds
    pop es
    rep stosw
lbl22b:
    mov bx,word ptr [bp-2h]
    cmp byte ptr [bx+676Ah],0h
    jz short lbl31f
    mov byte ptr [bx+676Ah],1h
lbl31f:
    mov ax,word ptr ds:[4F68h]
    inc word ptr [bp-2h]
    cmp word ptr [bp-2h],ax
    jl short lbl22b
lbl3Cf:
    call mf22
    pop di
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
