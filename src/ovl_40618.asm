_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf10:FAR
    EXTRN mf4f:FAR
    EXTRN mfa8:FAR
    EXTRN mf63:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,4h
    push di
    push si
    mov ax,9h
    mov dx,0F037h
    push dx
    push ax
    call mf10
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
    mov ax,1h
    push ax
    mov ax,8Bh
    push ax
    call mf4f
    add sp,4h
    or ax,ax
    jz short lblA0f
    mov ax,0Ah
    mov dx,0F037h
    push dx
    push ax
    call mf63
    add sp,4h
    mov di,ax
    mov es,dx
    push ds
    lds si, dword ptr [bp-4h]
    mov cx,0FFFFh
    xor ax,ax
    repne scasb
    not cx
    sub di,cx
    mov bx,cx
    db 87h, 0FEh ; override
    push ds
    push dx
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
    mov word ptr ds:[6A10h],494h
    jmp short lblE2f
    nop
lblA0f:
    mov ax,0Bh
    mov dx,0F037h
    push dx
    push ax
    call mfa8
    add sp,4h
    mov di,ax
    mov es,dx
    push ds
    lds si, dword ptr [bp-4h]
    mov cx,0FFFFh
    xor ax,ax
    repne scasb
    not cx
    sub di,cx
    mov bx,cx
    db 87h, 0FEh ; override
    push ds
    push dx
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
    mov word ptr ds:[6A10h],495h
lblE2f:
    mov ax,word ptr [bp-4h]
    mov dx,word ptr [bp-2h]
    pop si
    pop di
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
