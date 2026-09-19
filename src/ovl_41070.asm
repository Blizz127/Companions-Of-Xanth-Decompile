_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf13:FAR
    EXTRN mfa5:FAR
    EXTRN mf47:FAR
    EXTRN mfd5:FAR
    EXTRN mff8:FAR
    EXTRN mf23:FAR
    EXTRN mf11e:FAR
    EXTRN mf172:FAR
    EXTRN mf8c:FAR
    EXTRN mf12e:FAR
    EXTRN mf33:FAR
    EXTRN mf7b:FAR
    EXTRN mfb5:FAR
    EXTRN mfe8:FAR
    EXTRN mfc5:FAR
    EXTRN mf5b:FAR
    EXTRN mf10b:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,6h
    push di
    push si
    xor ax,ax
    mov byte ptr [bp-2h],al
    push ax
    push ax
    mov cx,9Bh
    push cx
    call mf13
    add sp,6h
    xor ax,ax
    push ax
    push ax
    mov cx,0BDh
    push cx
    call mf23
    add sp,6h
    mov ax,88h
    push ax
    mov ax,76h
    push ax
    call mf33
    add sp,4h
    or ax,ax
    jnz short lbl53f
    mov ax,89h
    push ax
    mov ax,76h
    push ax
    call mf47
    add sp,4h
    or ax,ax
    jz short lbl67f
lbl53f:
    xor ax,ax
    push ax
    push ax
    mov ax,76h
    push ax
    call mf5b
    add sp,6h
    mov byte ptr [bp-2h],1h
lbl67f:
    cmp byte ptr ds:[343h],0h
    jz short lbl77f
    mov byte ptr ds:[343h],0h
    mov byte ptr [bp-2h],1h
lbl77f:
    mov ax,88h
    push ax
    call mf7b
    add sp,2h
    cmp ax,14Ah
    jz short lbl99f
    mov ax,89h
    push ax
    call mf8c
    add sp,2h
    cmp ax,14Ah
    jnz short lbl9Df
lbl99f:
    mov byte ptr [bp-2h],1h
lbl9Df:
    mov ax,0Ah
    push ax
    mov cx,88h
    push cx
    call mfa5
    add sp,4h
    mov ax,147h
    push ax
    mov cx,88h
    push cx
    call mfb5
    add sp,4h
    mov ax,0Ah
    push ax
    mov ax,89h
    push ax
    call mfc5
    add sp,4h
    mov ax,147h
    push ax
    mov ax,89h
    push ax
    call mfd5
    add sp,4h
    xor ax,ax
    mov byte ptr ds:[31Dh],al
    push ax
    push ax
    mov cx,88h
    push cx
    call mfe8
    add sp,6h
    xor ax,ax
    push ax
    push ax
    mov cx,89h
    push cx
    call mff8
    add sp,6h
    xor ax,ax
    push ax
    mov cx,1h
    push cx
    mov dx,88h
    push dx
    call mf10b
    add sp,6h
    xor ax,ax
    push ax
    mov ax,1h
    push ax
    mov ax,89h
    push ax
    call mf11e
    add sp,6h
    mov ax,0Dh
    mov dx,0F037h
    push dx
    push ax
    call mf12e
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
    cmp byte ptr [bp-2h],al
    jz short lbl1A6f
    mov ax,0Eh
    mov dx,0F037h
    push dx
    push ax
    call mf172
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
lbl1A6f:
    mov di,1C9Fh
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
    mov ax,word ptr [bp-6h]
    mov dx,word ptr [bp-4h]
    pop si
    pop di
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
