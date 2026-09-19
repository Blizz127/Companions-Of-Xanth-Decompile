_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf2a:FAR
    EXTRN mf63:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,4h
    push di
    push si
    cmp byte ptr ds:[2F7h],0h
    jnz short lbl22f
    cmp byte ptr ds:[2F8h],0h
    jnz short lbl22f
    cmp byte ptr ds:[2F9h],0h
    jnz short lbl22f
    mov ax,0Ch
    jmp short lbl25f
lbl22f:
    mov ax,0Bh
lbl25f:
    mov dx,0F034h
    push dx
    push ax
    call mf2a
    add sp,4h
    mov bx,1396h
    mov cx,3420h
    push ds
    push cx
    mov di,ax
    mov si,bx
    mov es,dx
    pop ds
    mov cx,0FFFFh
    xor ax,ax
    repne scasb
    not cx
    sub di,cx
    db 87h, 0FEh ; override
    push ds
    push dx
    pop ds
    pop es
    shr cx,1
    rep movsw
    adc cx,cx
    rep movsb
    pop ds
    mov ax,0Dh
    mov dx,0F034h
    push dx
    push ax
    call mf63
    add sp,4h
    mov bx,1396h
    mov cx,3420h
    mov word ptr [bp-4h],bx
    mov word ptr [bp-2h],cx
    push ds
    push cx
    mov di,ax
    mov si,bx
    mov es,dx
    pop ds
    mov cx,0FFFFh
    xor ax,ax
    repne scasb
    not cx
    sub di,cx
    push cx
    db 87h, 0FEh ; override
    push ds
    push dx
    pop ds
    pop es
    mov cx,0FFFFh
    repne scasb
    dec di
    pop cx
    shr cx,1
    rep movsw
    adc cx,cx
    rep movsb
    pop ds
    mov ax,word ptr [bp-4h]
    mov dx,word ptr [bp-2h]
    pop si
    pop di
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
