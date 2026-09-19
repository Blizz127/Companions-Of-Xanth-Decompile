_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
mnem_unit:
    push bp
    mov bp,sp
    mov cx,word ptr [bp+0Eh]
    push ds
    push di
    push si
    jcxz lbl53f
    lds si, dword ptr [bp+0Ah]
    les di, dword ptr [bp+6h]
lbl11b:
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
    jcxz lbl53f
    or si,si
    jnz short lbl46f
    mov ax,ds
    add ax,1000h
    mov ds,ax
lbl46f:
    or di,di
    jnz short lbl11b
    mov ax,es
    add ax,1000h
    mov es,ax
    jmp short lbl11b
lbl53f:
    mov ax,word ptr [bp+6h]
    mov dx,word ptr [bp+8h]
    pop si
    pop di
    pop ds
    pop bp
    retf
_TEXT ENDS
    END
