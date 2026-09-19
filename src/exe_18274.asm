_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mn18b:NEAR
mnem_unit:
    push bp
    mov bp,sp
    push di
    push si
    push bx
    xor di,di
    mov ax,word ptr [bp+8h]
    or ax,ax
    jnl short lbl20f
    inc di
    mov dx,word ptr [bp+6h]
    neg ax
    neg dx
    sbb ax,0h
    mov word ptr [bp+8h],ax
    mov word ptr [bp+6h],dx
lbl20f:
    mov ax,word ptr [bp+0Ch]
    or ax,ax
    jnl short lbl38f
    inc di
    mov dx,word ptr [bp+0Ah]
    neg ax
    neg dx
    sbb ax,0h
    mov word ptr [bp+0Ch],ax
    mov word ptr [bp+0Ah],dx
lbl38f:
    or ax,ax
    jnz short lbl51f
    mov cx,word ptr [bp+0Ah]
    mov ax,word ptr [bp+8h]
    xor dx,dx
    div cx
    mov bx,ax
    mov ax,word ptr [bp+6h]
    div cx
    mov dx,bx
    jmp short lbl89f
lbl51f:
    mov bx,ax
    mov cx,word ptr [bp+0Ah]
    mov dx,word ptr [bp+8h]
    mov ax,word ptr [bp+6h]
lbl5Cb:
    shr bx,1
    rcr cx,1
    shr dx,1
    rcr ax,1
    or bx,bx
    jnz short lbl5Cb
    div cx
    mov si,ax
    mul word ptr [bp+0Ch]
    xchg ax,cx
    mov ax,word ptr [bp+0Ah]
    mul si
    add dx,cx
    jc short lbl85f
    cmp dx,word ptr [bp+8h]
    ja short lbl85f
    jc short lbl86f
    cmp ax,word ptr [bp+6h]
    jna short lbl86f
lbl85f:
    dec si
lbl86f:
    xor dx,dx
    xchg ax,si
lbl89f:
    dec di
    jnz short lbl93f
    neg dx
    neg ax
    sbb dx,0h
lbl93f:
    pop bx
    pop si
    pop di
    pop bp
    retf 8h
    push bp
    mov bp,sp
    mov ax,word ptr [bp+8h]
    mov cx,word ptr [bp+0Ch]
    or cx,ax
    mov cx,word ptr [bp+0Ah]
    jnz short lblB3f
    mov ax,word ptr [bp+6h]
    mul cx
    pop bp
    retf 8h
lblB3f:
    push bx
    mul cx
    mov bx,ax
    mov ax,word ptr [bp+6h]
    mul word ptr [bp+0Ch]
    add bx,ax
    mov ax,word ptr [bp+6h]
    mul cx
    add dx,bx
    pop bx
    pop bp
    retf 8h
    push bp
    mov bp,sp
    push bx
    push di
    xor di,di
    mov ax,word ptr [bp+8h]
    or ax,ax
    jnl short lblEBf
    inc di
    mov dx,word ptr [bp+6h]
    neg ax
    neg dx
    sbb ax,0h
    mov word ptr [bp+8h],ax
    mov word ptr [bp+6h],dx
lblEBf:
    mov ax,word ptr [bp+0Ch]
    or ax,ax
    jnl short lbl102f
    mov dx,word ptr [bp+0Ah]
    neg ax
    neg dx
    sbb ax,0h
    mov word ptr [bp+0Ch],ax
    mov word ptr [bp+0Ah],dx
lbl102f:
    or ax,ax
    jnz short lbl11Ef
    mov cx,word ptr [bp+0Ah]
    mov ax,word ptr [bp+8h]
    xor dx,dx
    div cx
    mov ax,word ptr [bp+6h]
    div cx
    mov ax,dx
    xor dx,dx
    dec di
    jns short lbl15Ff
    jmp short lbl166f
lbl11Ef:
    mov bx,ax
    mov cx,word ptr [bp+0Ah]
    mov dx,word ptr [bp+8h]
    mov ax,word ptr [bp+6h]
lbl129b:
    shr bx,1
    rcr cx,1
    shr dx,1
    rcr ax,1
    or bx,bx
    jnz short lbl129b
    div cx
    mov cx,ax
    mul word ptr [bp+0Ch]
    xchg ax,cx
    mul word ptr [bp+0Ah]
    add dx,cx
    jc short lbl150f
    cmp dx,word ptr [bp+8h]
    ja short lbl150f
    jc short lbl156f
    cmp ax,word ptr [bp+6h]
    jna short lbl156f
lbl150f:
    sub ax,word ptr [bp+0Ah]
    sbb dx,word ptr [bp+0Ch]
lbl156f:
    sub ax,word ptr [bp+6h]
    sbb dx,word ptr [bp+8h]
    dec di
    jns short lbl166f
lbl15Ff:
    neg dx
    neg ax
    sbb dx,0h
lbl166f:
    pop di
    pop bx
    pop bp
    retf 8h
    xor ch,ch
    jcxz lbl176f
lbl170b:
    shl ax,1
    rcl dx,1
    loop lbl170b
lbl176f:
    retf
    add byte ptr [di-75h],dl
    in al,dx
    push bx
    mov bx,word ptr [bp+6h]
    push word ptr [bp+0Ah]
    push word ptr [bp+8h]
    push word ptr [bx+2h]
    push word ptr [bx]
    push cs
    call mn18b
    mov word ptr [bx+2h],dx
    mov word ptr [bx],ax
    pop bx
    pop bp
    retf 6h
    push bp
    mov bp,sp
    push bx
    push si
    mov ax,word ptr [bp+0Ch]
    or ax,ax
    jnz short lbl1B9f
    mov cx,word ptr [bp+0Ah]
    mov ax,word ptr [bp+8h]
    xor dx,dx
    div cx
    mov bx,ax
    mov ax,word ptr [bp+6h]
    div cx
    mov dx,bx
    jmp short lbl1F1f
lbl1B9f:
    mov cx,ax
    mov bx,word ptr [bp+0Ah]
    mov dx,word ptr [bp+8h]
    mov ax,word ptr [bp+6h]
lbl1C4b:
    shr cx,1
    rcr bx,1
    shr dx,1
    rcr ax,1
    or cx,cx
    jnz short lbl1C4b
    div bx
    mov si,ax
    mul word ptr [bp+0Ch]
    xchg ax,cx
    mov ax,word ptr [bp+0Ah]
    mul si
    add dx,cx
    jc short lbl1EDf
    cmp dx,word ptr [bp+8h]
    ja short lbl1EDf
    jc short lbl1EEf
    cmp ax,word ptr [bp+6h]
    jna short lbl1EEf
lbl1EDf:
    dec si
lbl1EEf:
    xor dx,dx
    xchg ax,si
lbl1F1f:
    pop si
    pop bx
    pop bp
    retf 8h
    add byte ptr [di-75h],dl
    in al,dx
    push bx
    mov ax,word ptr [bp+0Ch]
    or ax,ax
    jnz short lbl218f
    mov cx,word ptr [bp+0Ah]
    mov ax,word ptr [bp+8h]
    xor dx,dx
    div cx
    mov ax,word ptr [bp+6h]
    div cx
    mov ax,dx
    xor dx,dx
    jmp short lbl25Df
lbl218f:
    mov cx,ax
    mov bx,word ptr [bp+0Ah]
    mov dx,word ptr [bp+8h]
    mov ax,word ptr [bp+6h]
lbl223b:
    shr cx,1
    rcr bx,1
    shr dx,1
    rcr ax,1
    or cx,cx
    jnz short lbl223b
    div bx
    mov cx,ax
    mul word ptr [bp+0Ch]
    xchg ax,cx
    mul word ptr [bp+0Ah]
    add dx,cx
    jc short lbl24Af
    cmp dx,word ptr [bp+8h]
    ja short lbl24Af
    jc short lbl250f
    cmp ax,word ptr [bp+6h]
    jna short lbl250f
lbl24Af:
    sub ax,word ptr [bp+0Ah]
    sbb dx,word ptr [bp+0Ch]
lbl250f:
    sub ax,word ptr [bp+6h]
    sbb dx,word ptr [bp+8h]
    neg dx
    neg ax
    sbb dx,0h
lbl25Df:
    pop bx
    pop bp
    retf 8h
    push bp
    mov bp,sp
    mov cx,word ptr [bp+0Eh]
    push ds
    push di
    push si
    jcxz lbl2B5f
    lds si, dword ptr [bp+0Ah]
    les di, dword ptr [bp+6h]
lbl273b:
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
    jcxz lbl2B5f
    or si,si
    jnz short lbl2A8f
    mov ax,ds
    add ax,1000h
    mov ds,ax
lbl2A8f:
    or di,di
    jnz short lbl273b
    mov ax,es
    add ax,1000h
    mov es,ax
    jmp short lbl273b
lbl2B5f:
    mov ax,word ptr [bp+6h]
    mov dx,word ptr [bp+8h]
    pop si
    pop di
    pop ds
    pop bp
    retf
_TEXT ENDS
    END
