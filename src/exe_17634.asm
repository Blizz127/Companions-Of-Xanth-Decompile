_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
mnem_unit:
    push bp
    mov bp,sp
    mov cx,word ptr [bp+0Ch]
    jcxz lbl40f
    push di
    les di, dword ptr [bp+6h]
    mov dx,di
    neg dx
    jz short lbl1Ef
    sub dx,cx
    db 1Bh, 0DBh ; override
    and dx,bx
    add dx,cx
    db 87h, 0D1h ; override
    sub dx,cx
lbl1Ef:
    mov ax,word ptr [bp+0Ah]
    mov ah,al
    shr cx,1
    rep stosw
    adc cx,cx
    rep stosb
    db 87h, 0D1h ; override
    jcxz lbl3Ff
    mov bx,es
    add bx,1000h
    mov es,bx
    shr cx,1
    rep stosw
    adc cx,cx
    rep stosb
lbl3Ff:
    pop di
lbl40f:
    mov ax,word ptr [bp+6h]
    mov dx,word ptr [bp+8h]
    pop bp
    retf
_TEXT ENDS
    END
