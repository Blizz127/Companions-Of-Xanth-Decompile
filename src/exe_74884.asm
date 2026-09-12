_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi2:NEAR
    EXTRN mf7:FAR
    EXTRN mi9:NEAR
    EXTRN mf78:FAR
    EXTRN mf84:FAR
    EXTRN mf84:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp, offset mi2
    push si
    push di
lbl09b:
    mov ax,5h
    push ax
    call mf7
    add sp,2h
    cmp ax, offset mi9
    jz short lbl1Df
    jmp near ptr lbl20f
lbl1Df:
    jmp near ptr lbl09b
lbl20f:
    mov word ptr ds:[411Ch],0h
    mov word ptr ds:[411Eh],1h
    mov word ptr ds:[6DF2h],0h
    jmp near ptr lbl35f
lbl35b:
lbl35f:
    cmp word ptr ds:[411Eh],0h
    jz short lbl3Ff
    jmp near ptr lbl35b
lbl3Ff:
    mov word ptr ds:[411Ah],0h
    add word ptr ds:[4158h],1h
    mov cx,4h
    mov ax,word ptr ds:[4158h]
    cwd
    idiv cx
    mov word ptr ds:[4158h],dx
    mov word ptr [bp-4h],0h
    jmp near ptr lbl94f
lbl5Fb:
    mov bx,word ptr ds:[4158h]
    shl bx,1
    shl bx,1
    cmp word ptr [bx+4134h],0h
    jz short lbl71f
    jmp near ptr lbl7Bf
lbl71f:
    cmp word ptr [bx+4136h],0h
    jnz short lbl7Bf
    jmp near ptr lbl7Ef
lbl7Bf:
    jmp near ptr lbl9Df
lbl7Ef:
    add word ptr ds:[4158h],1h
    mov cx,4h
    mov ax,word ptr ds:[4158h]
    cwd
    idiv cx
    mov word ptr ds:[4158h],dx
    add word ptr [bp-4h],1h
lbl94f:
    cmp word ptr [bp-4h],4h
    jnl short lbl9Df
    jmp near ptr lbl5Fb
lbl9Df:
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
    mov word ptr ds:[417Ah],0h
    mov word ptr ds:[417Ch],0h
    mov word ptr ds:[4176h],0h
    mov ax,word ptr ds:[4162h]
    mov word ptr ds:[4168h],ax
    mov bx,word ptr ds:[4158h]
    shl bx,1
    push word ptr [bx+4150h]
    mov bx,word ptr ds:[4158h]
    shl bx,1
    push word ptr [bx+4148h]
    mov bx,word ptr ds:[4158h]
    shl bx,1
    shl bx,1
    push word ptr [bx+4136h]
    push word ptr [bx+4134h]
    call mf78
    add sp,8h
    pop di
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
