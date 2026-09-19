_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf10b:FAR
    EXTRN mf6c:FAR
    EXTRN mf19:FAR
    EXTRN mfa7:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,6h
    push di
    push si
    mov ax,word ptr ds:[2D8h]
    add ax,499h
    mov word ptr ds:[6A10h],ax
    mov ax,6h
    mov dx,0F038h
    push dx
    push ax
    call mf19
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
    mov es, ds:[5A94h]
    mov bx,word ptr ds:[2D8h]
    mov ax,bx
    add bx,bx
    add bx,bx
    add bx,ax
    add bx,bx
    push word ptr es:[bx+6A6h]
    push word ptr es:[bx+6A4h]
    call mf6c
    add sp,4h
    mov bx,ax
    mov di,bx
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
    mov ax,1CDDh
    push ds
    push ax
    call mfa7
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
    mov es, ds:[5A94h]
    mov bx,word ptr ds:[2D8h]
    mov ax,bx
    add bx,bx
    add bx,bx
    add bx,ax
    add bx,bx
    mov ax,word ptr es:[bx+6A8h]
    mov word ptr [bp-2h],ax
    mov cx,ax
    add ax,word ptr es:[bx+6AAh]
    cmp ax,cx
    jng short lbl137f
lbl100b:
    mov ax,1h
    push ax
    push word ptr [bp-2h]
    mov cx,817Bh
    push cx
    call mf10b
    add sp,6h
    mov es, ds:[5A94h]
    mov bx,word ptr ds:[2D8h]
    mov ax,bx
    add bx,bx
    add bx,bx
    add bx,ax
    add bx,bx
    mov ax,word ptr es:[bx+6A8h]
    add ax,word ptr es:[bx+6AAh]
    inc word ptr [bp-2h]
    cmp ax,word ptr [bp-2h]
    jg short lbl100b
lbl137f:
    mov ax,1396h
    mov dx,3420h
    pop si
    pop di
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
