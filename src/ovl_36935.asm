_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf61:FAR
    EXTRN mfa2:FAR
    EXTRN mf17:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,4h
    push di
    push si
    cmp byte ptr ds:[305h],0h
    jz short lbl52f
    mov ax,0Ah
    mov dx,0F036h
    push dx
    push ax
    call mf17
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
    mov word ptr ds:[6A10h],477h
    jmp near ptr lblD9f
    nop
lbl52f:
    cmp byte ptr ds:[304h],0h
    jz short lbl9Af
    mov ax,0Bh
    mov dx,0F036h
    push dx
    push ax
    call mf61
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
    mov word ptr ds:[6A10h],478h
    jmp short lblD9f
lbl9Af:
    mov ax,0Ch
    mov dx,0F036h
    push dx
    push ax
    call mfa2
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
    mov word ptr ds:[6A10h],479h
lblD9f:
    mov bx,1396h
    mov ax,3420h
    mov word ptr [bp-4h],bx
    mov word ptr [bp-2h],ax
    push ds
    push ax
    mov di,1B72h
    mov si,bx
    mov cx,ds
    mov es,cx
    pop ds
    mov cx,0FFFFh
    xor ax,ax
    repne scasb
    not cx
    sub di,cx
    push cx
    db 87h, 0FEh ; override
    push ds
    push es
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
