_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mfbe:FAR
    EXTRN mf171:FAR
    EXTRN mfce:FAR
    EXTRN mf156:FAR
    EXTRN mf149:FAR
    EXTRN mf10:FAR
    EXTRN mfe0:FAR
    EXTRN mfac:FAR
    EXTRN mf15e:FAR
    EXTRN mf5b:FAR
    EXTRN mf97:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,4h
    push di
    push si
    mov ax,30h
    mov dx,0F00Ah
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
    cmp byte ptr ds:[316h],al
    jnz short lbl50f
    jmp near ptr lblD8f
lbl50f:
    mov byte ptr ds:[316h],al
    mov ax,31h
    mov dx,0F00Ah
    push dx
    push ax
    call mf5b
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
    mov ax,1h
    push ax
    mov ax,7Eh
    push ax
    call mf97
    add sp,4h
    or ax,ax
    jnz short lblB6f
    push ax
    mov ax,1h
    push ax
    mov ax,7Eh
    push ax
    call mfac
    add sp,6h
    jmp short lbl114f
lblB6f:
    mov ax,3h
    push ax
    mov ax,7Eh
    push ax
    call mfbe
    add sp,4h
    mov ax,13Dh
    push ax
    mov ax,7Eh
    push ax
    call mfce
    add sp,4h
    jmp short lbl114f
lblD8f:
    mov ax,32h
    mov dx,0F00Ah
    push dx
    push ax
    call mfe0
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
lbl114f:
    mov di,258Ah
    mov cx,ds
    mov es,cx
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
    push word ptr [bp-2h]
    push word ptr [bp-4h]
    call mf149
    add sp,4h
    mov ax,258Ch
    push ds
    push ax
    call mf156
    add sp,4h
    call mf15e
    mov cx,5h
    cwd
    idiv cx
    add dx,2h
    push dx
    mov ax,0Ch
    push ax
    call mf171
    add sp,4h
    mov ax,1h
    pop si
    pop di
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
