_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mfd3:FAR
    EXTRN mf4f:FAR
    EXTRN mf10:FAR
    EXTRN midb:NEAR
    EXTRN mf97:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,4h
    push di
    push si
    mov ax,1Fh
    mov dx,0F035h
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
    mov ax,0BDh
    push ax
    call mf4f
    add sp,4h
    or ax,ax
    jz short lbl60f
    mov ax,1B4Bh
    jmp short lbl63f
lbl60f:
    mov ax,1B52h
lbl63f:
    mov cx,ds
    mov di,ax
    mov es,cx
    push ds
    lds si, dword ptr [bp-4h]
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
    mov ax,20h
    mov dx,0F035h
    push dx
    push ax
    call mf97
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
    mov ax,0BDh
    push ax
    call mfd3
    add sp,4h
    cmp ax, offset midb
    db 1Bh, 0C0h ; override
    add ax,52Ch
    mov word ptr ds:[6A10h],ax
    mov ax,word ptr [bp-4h]
    mov dx,word ptr [bp-2h]
    pop si
    pop di
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
