_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf1c0:FAR
    EXTRN mf1e7:FAR
    EXTRN mf17d:FAR
    EXTRN mf1f7:FAR
    EXTRN mf4b:FAR
    EXTRN mfc2:FAR
    EXTRN mf13a:FAR
    EXTRN mf7f:FAR
    EXTRN mffe:FAR
    EXTRN mf1d3:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,0Ah
    push di
    push si
    mov es, ds:[5A94h]
    mov bx,word ptr ds:[2D8h]
    mov ax,bx
    add bx,bx
    add bx,bx
    add bx,ax
    add bx,bx
    mov ax,word ptr es:[bx+6A8h]
    mov word ptr [bp-4h],ax
    add ax,word ptr es:[bx+6ACh]
    sub ax,word ptr ds:[5DFAh]
    dec ax
    jz short lbl31f
    jmp near ptr lbl23Af
lbl31f:
    mov ax,word ptr [bp-4h]
    mov word ptr [bp-2h],ax
    add ax,word ptr es:[bx+6AAh]
    cmp ax,word ptr [bp-4h]
    jng short lbl77f
lbl41b:
    xor ax,ax
    push ax
    push word ptr [bp-2h]
    mov ax,817Bh
    push ax
    call mf4b
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
    jg short lbl41b
lbl77f:
    mov ax,7h
    mov dx,0F038h
    push dx
    push ax
    call mf7f
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
    cmp word ptr ds:[2D8h],9h
    jnz short lblF6f
    mov ax,1CE0h
    push ds
    push ax
    call mfc2
    add sp,4h
    mov di,ax
    mov es,dx
    push ds
    lds si, dword ptr [bp-0Ah]
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
lblF6f:
    inc word ptr ds:[2D8h]
    push word ptr ds:[2D8h]
    call mffe
    add sp,2h
    mov di,ax
    mov es,dx
    push ds
    lds si, dword ptr [bp-0Ah]
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
    mov ax,8h
    mov dx,0F038h
    push dx
    push ax
    call mf13a
    add sp,4h
    mov di,ax
    mov es,dx
    push ds
    lds si, dword ptr [bp-0Ah]
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
    cmp word ptr ds:[2D8h],0Ah
    jnl short lbl1BAf
    mov ax,9h
    mov dx,0F038h
    push dx
    push ax
    call mf17d
    add sp,4h
    mov di,ax
    mov es,dx
    push ds
    lds si, dword ptr [bp-0Ah]
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
    mov word ptr ds:[6A10h],496h
    jmp short lbl231f
    nop
lbl1BAf:
    push ax
    push ax
    mov cx,817Ch
    push cx
    call mf1c0
    add sp,6h
    xor ax,ax
    push ax
    mov ax,1h
    push ax
    mov cx,817Ch
    push cx
    call mf1d3
    add sp,6h
    mov ax,1h
    push ax
    mov ax,2h
    push ax
    mov ax,817Ch
    push ax
    call mf1e7
    add sp,6h
    mov ax,0Ah
    mov dx,0F038h
    push dx
    push ax
    call mf1f7
    add sp,4h
    mov di,ax
    mov es,dx
    push ds
    lds si, dword ptr [bp-0Ah]
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
    mov word ptr ds:[6A10h],497h
lbl231f:
    mov ax,word ptr [bp-0Ah]
    mov dx,word ptr [bp-8h]
    jmp short lbl246f
    nop
lbl23Af:
    mov word ptr ds:[6A10h],498h
    mov ax,0Bh
    mov dx,0F038h
lbl246f:
    pop si
    pop di
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
