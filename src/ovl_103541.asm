_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mfa6:FAR
    EXTRN mf11d:FAR
    EXTRN mf1b:FAR
    EXTRN mf5f:FAR
    EXTRN mf13f:FAR
    EXTRN mf154:FAR
    EXTRN mf12b:FAR
    EXTRN mf137:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,0Ch
    push di
    push si
    mov ax,word ptr ds:[249Ch]
    mov es, ds:[5AC2h]
    mov word ptr es:[1396h],ax
    mov ax,6Dh
    push ax
    mov cx,12h
    push cx
    call mf1b
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
    mov ax,249Eh
    push ds
    push ax
    call mf5f
    add sp,4h
    mov di,ax
    mov es,dx
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
    cmp byte ptr ds:[2F3h],al
    jnz short lbl9Ef
    mov ax,4Bh
    jmp short lblA1f
lbl9Ef:
    mov ax,4Ch
lblA1f:
    mov dx,0F009h
    push dx
    push ax
    call mfa6
    add sp,4h
    mov word ptr [bp-4h],ax
    mov word ptr [bp-2h],dx
    mov bx,1396h
    mov ax,3420h
    mov word ptr [bp-0Ch],bx
    mov word ptr [bp-0Ah],ax
    push ds
    push ax
    mov si,bx
    pop ds
    les di, dword ptr [bp-4h]
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
    mov di,24AAh
    mov cx,ds
    mov es,cx
    push ds
    lds si, dword ptr [bp-0Ch]
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
    push ax
    push ax
    mov cx,6Dh
    push cx
    call mf11d
    add sp,6h
    push word ptr [bp-0Ah]
    push word ptr [bp-0Ch]
    call mf12b
    add sp,4h
    mov ax,1B58h
    push ax
    call mf137
    add sp,2h
    call mf13f
    mov word ptr ds:[798h],0h
    mov word ptr ds:[2A8h],8h
    mov ax,5Ah
    push ax
    call mf154
    add sp,2h
    mov ax,1h
    pop si
    pop di
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
