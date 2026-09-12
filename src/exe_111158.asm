_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf25:FAR
    EXTRN mf37:FAR
    EXTRN mf46:FAR
    EXTRN mf54:FAR
    EXTRN mf54:FAR
    EXTRN mf54:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,1Ah
    push di
    push si
    mov ax,14h
    imul word ptr ds:[680Ch]
    mov bx,word ptr ds:[680Ah]
    add bx,bx
    add bx,bx
    mov dx,word ptr [bx+67C2h]
    mov si,word ptr [bx+67C4h]
    add dx,ax
    push ds
    push si
    lea di,word ptr [bp-14h]
    mov si,dx
    mov ax,ss
    mov es,ax
    pop ds
    mov cx,0Ah
    rep movsw
    pop ds
    push word ptr [bp-10h]
    push word ptr [bp-12h]
    call mf25
    add sp,4h
    mov word ptr [bp-16h],1h
    mov word ptr [bp-1Ah],4FCEh
lbl4Bb:
    mov ax,word ptr [bp-16h]
    and ax,word ptr ds:[680Eh]
    mov cx,word ptr [bp-16h]
    and cx,word ptr [bp+6h]
    cmp cx,ax
    jz short lbl68f
    push ds
    push word ptr [bp-1Ah]
    call mf37
    add sp,4h
lbl68f:
    add word ptr [bp-1Ah],14h
    shl word ptr [bp-16h],1
    cmp word ptr [bp-16h],200h
    jng short lbl4Bb
    xor ax,ax
    push ax
    push ax
    call mf46
    add sp,4h
    mov ax,word ptr [bp+6h]
    mov word ptr ds:[680Eh],ax
    pop si
    pop di
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
