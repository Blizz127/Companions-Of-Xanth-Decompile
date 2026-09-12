_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi2:NEAR
    EXTRN mf53:FAR
    EXTRN mf59:FAR
    EXTRN mf66:FAR
    EXTRN mf66:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp, offset mi2
    push si
    push di
    add word ptr ds:[4158h],1h
    mov cx,4h
    mov ax,word ptr ds:[4158h]
    cwd
    idiv cx
    mov word ptr ds:[4158h],dx
    mov word ptr [bp-4h],0h
    jmp near ptr lbl58f
lbl23b:
    mov bx,word ptr ds:[4158h]
    shl bx,1
    shl bx,1
    cmp word ptr [bx+4134h],0h
    jz short lbl35f
    jmp near ptr lbl3Ff
lbl35f:
    cmp word ptr [bx+4136h],0h
    jnz short lbl3Ff
    jmp near ptr lbl42f
lbl3Ff:
    jmp near ptr lbl61f
lbl42f:
    add word ptr ds:[4158h],1h
    mov cx,4h
    mov ax,word ptr ds:[4158h]
    cwd
    idiv cx
    mov word ptr ds:[4158h],dx
    add word ptr [bp-4h],1h
lbl58f:
    cmp word ptr [bp-4h],4h
    jnl short lbl61f
    jmp near ptr lbl23b
lbl61f:
    mov bx,word ptr ds:[4158h]
    shl bx,1
    mov ax,word ptr [bx+4124h]
    mov word ptr ds:[416Ch],ax
    mov bx,word ptr ds:[4158h]
    shl bx,1
    mov ax,word ptr [bx+412Ch]
    mov word ptr ds:[4166h],ax
    mov ax,word ptr ds:[4182h]
    mov dx,word ptr ds:[4184h]
    mov word ptr ds:[6DEEh],ax
    mov word ptr ds:[6DF0h],dx
    or word ptr ds:[416Eh],30h
    mov bx,word ptr ds:[4158h]
    shl bx,1
    shl bx,1
    mov ax,word ptr [bx+4134h]
    mov dx,word ptr [bx+4136h]
    mov word ptr ds:[6DE6h],ax
    mov word ptr ds:[6DE8h],dx
    call mf53
    mov word ptr ds:[417Ah],0h
    mov word ptr ds:[417Ch],0h
    mov word ptr ds:[4176h],0h
    mov ax,word ptr ds:[4162h]
    mov word ptr ds:[4168h],ax
    call mf59
    or word ptr ds:[416Eh],40h
    and word ptr ds:[416Eh],0FFFFFFFFFFFFFFDFh
    pop di
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
