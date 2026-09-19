_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
mnem_unit:
    push bp
    mov bp,sp
    mov dx,di
    mov bx,si
    push ds
    les di, dword ptr [bp+6h]
    xor ax,ax
    mov cx,0FFFFh
    repne scasb
    lea si,word ptr [di-1h]
    les di, dword ptr [bp+0Ah]
    mov cx,0FFFFh
    repne scasb
    not cx
    jz short lbl24f
    sub di,cx
    inc cx
lbl24f:
    sub di,cx
    mov ax,es
    mov ds,ax
    mov es, [bp+8h]
    db 87h, 0FEh ; override
    mov ax,word ptr [bp+6h]
    or cx,cx
    jnz short lbl3Bf
    movsw
    dec cx
    dec cx
    jmp short lbl43f
lbl3Bf:
    test si,1h
    jz short lbl43f
    movsb
    dec cx
lbl43f:
    shr cx,1
    rep movsw
    adc cx,cx
    rep movsb
    mov si,bx
    mov di,dx
    pop ds
    mov dx,es
    pop bp
    retf
_TEXT ENDS
    END
