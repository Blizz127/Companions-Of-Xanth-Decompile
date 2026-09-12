_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
mnem_unit:
    push bp
    mov bp,sp
    mov dx,di
    mov bx,si
    push ds
    lds si, dword ptr [bp+0Ah]
    mov di,si
    mov ax,ds
    mov es,ax
    xor ax,ax
    mov cx,0FFFFh
    repne scasb
    not cx
    les di, dword ptr [bp+6h]
    mov ax,di
    jz short lbl25f
    movsw
    dec cx
    jmp short lbl2Bf
lbl25f:
    test al,1h
    jz short lbl2Bf
    movsb
    dec cx
lbl2Bf:
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
