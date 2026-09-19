_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf63:FAR
    EXTRN mf1a:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,8h
    push di
    push si
    cmp byte ptr ds:[2FEh],0h
    jnz short lbl12f
    jmp near ptr lblD8f
lbl12f:
    mov ax,17h
    mov dx,0F036h
    push dx
    push ax
    call mf1a
    add sp,4h
    mov bx,1396h
    mov cx,3420h
    mov word ptr [bp-8h],bx
    mov word ptr [bp-6h],cx
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
    cmp byte ptr ds:[2F3h],al
    jz short lbl5Ef
    mov ax,1B75h
    mov dx,ds
    jmp short lbl6Bf
lbl5Ef:
    mov ax,1B77h
    push ds
    push ax
    call mf63
    add sp,4h
lbl6Bf:
    mov word ptr [bp-4h],ax
    mov word ptr [bp-2h],dx
    les di, dword ptr [bp-4h]
    push ds
    lds si, dword ptr [bp-8h]
    mov cx,0FFFFh
    xor ax,ax
    repne scasb
    not cx
    sub di,cx
    mov bx,cx
    db 87h, 0FEh ; override
    push ds
    push es
    pop ds
    pop es
    mov cx,0FFFFh
    repne scasb
    dec di
    mov cx,bx
    shr cx,1
    rep movsw
    adc cx,cx
    rep movsb
    pop ds
    mov di,1B80h
    mov cx,ds
    mov es,cx
    push ds
    lds si, dword ptr [bp-8h]
    mov cx,0FFFFh
    repne scasb
    not cx
    sub di,cx
    mov bx,cx
    db 87h, 0FEh ; override
    push ds
    push es
    pop ds
    pop es
    mov cx,0FFFFh
    repne scasb
    dec di
    mov cx,bx
    shr cx,1
    rep movsw
    adc cx,cx
    rep movsb
    pop ds
    mov word ptr ds:[6A10h],47Ah
    mov ax,word ptr [bp-8h]
    mov dx,word ptr [bp-6h]
    jmp short lblE9f
    nop
lblD8f:
    mov byte ptr ds:[2FEh],1h
    mov word ptr ds:[6A10h],47Bh
    mov ax,18h
    mov dx,0F036h
lblE9f:
    pop si
    pop di
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
