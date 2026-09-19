_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf4e:FAR
    EXTRN mf169:FAR
    EXTRN mf7e:FAR
    EXTRN mi70:NEAR
    EXTRN mi6d:NEAR
    EXTRN mib:NEAR
    EXTRN mf28:FAR
    EXTRN mf126:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,0Ah
    push di
    push si
    mov ax,word ptr [bp+6h]
    sub ax, offset mib
    jz short lbl20f
    dec ax
    dec ax
    jl short lbl1Af
    jo short lbl1Af
    dec ax
    dec ax
    jng short lbl46f
lbl1Af:
    xor ax,ax
    cwd
    jmp near ptr lbl1AEf
lbl20f:
    mov ax,0Eh
    push ax
    mov ax,4Ah
    push ax
    call mf28
    add sp,4h
    or ax,ax
    jz short lbl3Cf
    mov ax,22D6h
    mov dx,ds
    jmp near ptr lbl1AEf
lbl3Cf:
    mov ax,2Dh
    mov dx,0F005h
    jmp near ptr lbl1AEf
    nop
lbl46f:
    mov ax,0Eh
    push ax
    mov ax,4Ah
    push ax
    call mf4e
    add sp,4h
    or ax,ax
    jz short lbl66f
    cmp byte ptr ds:[323h],1h
    db 1Bh, 0C0h ; override
    neg ax
    jmp short lbl73f
    nop
lbl66f:
    cmp byte ptr ds:[323h],1h
    db 1Bh, 0C0h ; override
    and ax, offset mi6d
    add ax, offset mi70
lbl73f:
    mov word ptr [bp-2h],ax
    push word ptr ds:[6A04h]
    mov ax,12h
    push ax
    call mf7e
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
    mov di,22E4h
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
    mov bx,word ptr [bp-2h]
    add bx,bx
    add bx,bx
    mov si,word ptr [bx+22C6h]
    mov cx,word ptr [bx+22C8h]
    mov bx,cx
    mov di,si
    mov es,cx
    push ds
    lds si, dword ptr [bp-6h]
    mov cx,0FFFFh
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
    cmp byte ptr ds:[323h],al
    jz short lbl161f
    mov ax,22E6h
    push ds
    push ax
    call mf126
    add sp,4h
    mov bx,1396h
    mov cx,3420h
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
lbl161f:
    mov ax,2Eh
    mov dx,0F005h
    push dx
    push ax
    call mf169
    add sp,4h
    mov bx,1396h
    mov cx,3420h
    mov word ptr [bp-0Ah],bx
    mov word ptr [bp-8h],cx
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
    mov ax,word ptr [bp-0Ah]
    mov dx,word ptr [bp-8h]
lbl1AEf:
    pop si
    pop di
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
