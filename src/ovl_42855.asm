_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf7a:FAR
    EXTRN mf172:FAR
    EXTRN mfcb:FAR
    EXTRN mf2c:FAR
    EXTRN mf10b:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,6h
    push di
    push si
    cmp word ptr ds:[2D0h],1h
    jnz short lbl14f
    xor ax,ax
    jmp short lbl17f
    nop
lbl14f:
    mov ax,5h
lbl17f:
    add ax,word ptr ds:[2D2h]
    mov word ptr [bp-2h],ax
    add ax,48Ah
    mov word ptr ds:[6A10h],ax
    mov ax,3h
    mov dx,0F038h
    push dx
    push ax
    call mf2c
    add sp,4h
    mov bx,1396h
    mov cx,3420h
    mov word ptr [bp-6h],bx
    mov word ptr [bp-4h],cx
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
    mov es, ds:[5A92h]
    mov cl,4h
    mov bx,word ptr [bp-2h]
    shl bx,cl
    push word ptr es:[bx+60Ah]
    push word ptr es:[bx+608h]
    mov si,bx
    call mf7a
    add sp,4h
    push si
    mov di,ax
    mov es,dx
    push ds
    lds si, dword ptr [bp-6h]
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
    pop si
    mov es, ds:[5A92h]
    cmp byte ptr es:[si+610h],58h
    jnz short lblC6f
    mov ax,4h
    mov dx,0F038h
    push dx
    jmp short lblCAf
    nop
lblC6f:
    mov ax,1CB1h
    push ds
lblCAf:
    push ax
    call mfcb
    add sp,4h
    mov di,ax
    mov es,dx
    push ds
    lds si, dword ptr [bp-6h]
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
    cmp word ptr ds:[2D2h],4h
    jz short lbl13Ff
    mov ax,1CC1h
    push ds
    push ax
    call mf10b
    add sp,4h
    mov di,ax
    mov es,dx
    push ds
    lds si, dword ptr [bp-6h]
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
lbl13Ff:
    mov di,1CCEh
    mov cx,ds
    mov es,cx
    push ds
    lds si, dword ptr [bp-6h]
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
    push word ptr [bp-4h]
    push word ptr [bp-6h]
    call mf172
    add sp,4h
    pop si
    pop di
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
