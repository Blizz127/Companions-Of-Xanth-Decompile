_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf65:FAR
    EXTRN mfe9:FAR
    EXTRN mf16b:FAR
    EXTRN mf127:FAR
    EXTRN mf1e1:FAR
    EXTRN mf29:FAR
    EXTRN mf9e:FAR
    EXTRN mf1a7:FAR
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
    add ax,480h
    mov word ptr ds:[6A10h],ax
    mov ax,1CA2h
    push ds
    push ax
    call mf29
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
    mov ax,word ptr [bp-2h]
    inc ax
    push ax
    call mf65
    add sp,2h
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
    mov ax,1CADh
    push ds
    push ax
    call mf9e
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
    mov es, ds:[5A92h]
    mov cl,4h
    mov bx,word ptr [bp-2h]
    shl bx,cl
    push word ptr es:[bx+606h]
    push word ptr es:[bx+604h]
    mov si,bx
    call mfe9
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
    mov ax,1h
    mov dx,0F038h
    push dx
    push ax
    call mf127
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
    push word ptr es:[si+60Eh]
    push word ptr es:[si+60Ch]
    call mf16b
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
    mov ax,2h
    mov dx,0F038h
    push dx
    push ax
    call mf1a7
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
    push word ptr [bp-4h]
    push word ptr [bp-6h]
    call mf1e1
    add sp,4h
    pop si
    pop di
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
