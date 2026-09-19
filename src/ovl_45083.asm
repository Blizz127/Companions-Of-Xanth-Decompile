_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mfd5:FAR
    EXTRN mf99:FAR
    EXTRN mf4f:FAR
    EXTRN mf60:FAR
    EXTRN mf10:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,4h
    push di
    push si
    mov ax,1h
    mov dx,0F04Fh
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
    mov ax,0Ah
    push ax
    mov ax,0Eh
    push ax
    call mf4f
    add sp,4h
    or ax,ax
    jz short lbl94f
    mov ax,1CE6h
    push ds
    push ax
    call mf60
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
lbl94f:
    mov ax,1CF5h
    push ds
    push ax
    call mf99
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
    mov ax,0Ah
    push ax
    mov ax,0Eh
    push ax
    call mfd5
    add sp,4h
    mov ax,word ptr [bp-4h]
    mov dx,word ptr [bp-2h]
    pop si
    pop di
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
