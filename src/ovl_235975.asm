_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf35:FAR
    EXTRN mf49:FAR
    EXTRN mf60:FAR
    EXTRN mf62:FAR
    EXTRN mf67:FAR
    EXTRN mf67:FAR
    EXTRN mf67:FAR
    EXTRN mf67:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,6h
    push di
    push si
    mov ax,word ptr ds:[5E16h]
    mov dx,word ptr ds:[5E18h]
    les bx, dword ptr ds:[5E12h]
    mov si,word ptr es:[bx+8h]
    mov di,word ptr es:[bx+0Ah]
    mov cx,word ptr ds:[5E1Ah]
    add cx,cx
    add cx,cx
    push ds
    push di
    mov di,ax
    mov es,dx
    pop ds
    shr cx,1
    rep movsw
    adc cx,cx
    rep movsb
    pop ds
    xor ax,ax
    mov cx,0Fh
    mov bx,word ptr ds:[5E2Ah]
    mov dx,word ptr ds:[5E2Ch]
    mov di,bx
    mov es,dx
    rep stosw
    les bx, dword ptr ds:[5E12h]
    mov al,byte ptr es:[bx+1h]
    push ax
    mov al,byte ptr es:[bx]
    push ax
    call mf35
    add sp,4h
    mov word ptr [bp-2h],0h
    cmp word ptr ds:[5E1Ah],0h
    jz short lbl96f
    mov word ptr [bp-6h],0h
lbl6Cb:
    mov ax,word ptr [bp-2h]
    inc ax
    push ax
    les bx, dword ptr ds:[5E16h]
    mov si,word ptr [bp-6h]
    push word ptr es:[bx+si+2h]
    push word ptr es:[bx+si]
    mov si,ax
    call mf49
    add sp,6h
    add word ptr [bp-6h],4h
    mov word ptr [bp-2h],si
    cmp si,word ptr ds:[5E1Ah]
    jc short lbl6Cb
lbl96f:
    mov word ptr ds:[5E26h],0h
    mov ax,3h
    push ax
    xor ax,ax
    push ax
    call mf60
    add sp,4h
    call mf62
    pop si
    pop di
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
