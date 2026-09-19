_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mda1:NEAR
    EXTRN mf123:FAR
    EXTRN mfd:FAR
    EXTRN mf44:FAR
    EXTRN mfa6:FAR
    EXTRN mf107:FAR
    EXTRN md9c:NEAR
    EXTRN md5f:NEAR
    EXTRN md11e:NEAR
    EXTRN md119:NEAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,8h
    push di
    push si
    mov ax,2EBAh
    push ds
    push ax
    call mfd
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
    call mf44
    mov cx,13h
    sub dx,dx
    div cx
    mov bx,dx
    add bx,dx
    add bx,dx
    add bx,bx
    mov word ptr [bp-8h],bx
    mov es, ds:[5AD0h]
    cmp byte ptr es:[bx+md5f],ch
    jz short lbl95f
    mov di,2EC3h
    mov cx,ds
    mov es,cx
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
lbl95f:
    mov es, ds:[5AD0h]
    mov bx,word ptr [bp-8h]
    push word ptr es:[bx+md9c]
    push word ptr es:[bx+mda1]
    call mfa6
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
    mov di,2EC8h
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
    call mf107
    mov bx,ax
    and bx,0Fh
    add bx,bx
    add bx,bx
    mov es, ds:[5AD2h]
    push word ptr es:[bx+md119]
    push word ptr es:[bx+md11e]
    call mf123
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
    mov ax,word ptr [bp-6h]
    mov dx,word ptr [bp-4h]
    pop si
    pop di
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
