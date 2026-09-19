_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf1a:FAR
mnem_unit:
    push bp
    mov bp,sp
    mov cx,word ptr [bp+0Eh]
    push ds
    push di
    push si
    or cx,cx
    jnz short lbl10f
    jmp near ptr lblBFf
lbl10f:
    lds si, dword ptr [bp+0Ah]
    les di, dword ptr [bp+6h]
    push ds
    push si
    push es
    push di
    call mf1a
    mov cx,word ptr [bp+0Eh]
    or dx,dx
    js short lbl7Df
    sub ax,cx
    sbb dx,0h
    jnc short lbl7Df
    dec cx
    add si,cx
    jnc short lbl39f
    mov ax,ds
    add ax,1000h
    mov ds,ax
lbl39f:
    add di,cx
    jnc short lbl44f
    mov ax,es
    add ax,1000h
    mov es,ax
lbl44f:
    inc cx
lbl45b:
    mov ax,cx
    dec ax
    sub ax,di
    db 1Bh, 0DBh ; override
    and ax,bx
    add ax,di
    sub ax,si
    db 1Bh, 0DBh ; override
    and ax,bx
    add ax,si
    inc ax
    xchg ax,cx
    sub ax,cx
    std
    rep movsb
    cld
    xchg ax,cx
    jcxz lblBFf
    cmp si,0FFFFFFFFFFFFFFFFh
    jnz short lbl6Ff
    mov ax,ds
    sub ax,1000h
    mov ds,ax
lbl6Ff:
    cmp di,0FFFFFFFFFFFFFFFFh
    jnz short lbl45b
    mov ax,es
    sub ax,1000h
    mov es,ax
    jmp short lbl45b
lbl7Db:
lbl7Df:
    mov ax,cx
    dec ax
    mov dx,di
    not dx
    sub ax,dx
    db 1Bh, 0DBh ; override
    and ax,bx
    add ax,dx
    mov dx,si
    not dx
    sub ax,dx
    db 1Bh, 0DBh ; override
    and ax,bx
    add ax,dx
    inc ax
    xchg ax,cx
    sub ax,cx
    shr cx,1
    rep movsw
    adc cx,cx
    rep movsb
    xchg ax,cx
    jcxz lblBFf
    or si,si
    jnz short lblB2f
    mov ax,ds
    add ax,1000h
    mov ds,ax
lblB2f:
    or di,di
    jnz short lbl7Db
    mov ax,es
    add ax,1000h
    mov es,ax
    jmp short lbl7Db
lblBFf:
    mov ax,word ptr [bp+6h]
    mov dx,word ptr [bp+8h]
    pop si
    pop di
    pop ds
    pop bp
    retf
_TEXT ENDS
    END
