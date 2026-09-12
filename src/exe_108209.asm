_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf46:FAR
    EXTRN mf62:FAR
    EXTRN mf66:FAR
    EXTRN mf74:FAR
    EXTRN mf80:FAR
    EXTRN mf80:FAR
    EXTRN mf80:FAR
    EXTRN mf80:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,1Eh
    push di
    push si
    mov ax,14h
    imul word ptr [bp+8h]
    mov bx,word ptr [bp+6h]
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
    mov al,byte ptr [bp-13h]
    cbw
    mov word ptr [bp-1Eh],ax
    test al,80h
    jnz short lblB7f
    mov ax,word ptr [bp-12h]
    mov word ptr [bp-16h],ax
    mov ax,word ptr [bp-10h]
    mov word ptr [bp-18h],ax
    mov ax,word ptr [bp-0Eh]
    mov word ptr [bp-1Ah],ax
    mov ax,word ptr [bp-0Ch]
    mov word ptr [bp-1Ch],ax
    cmp word ptr [bp-1Eh],1h
    jnz short lbl62f
    push word ptr ds:[6E52h]
    jmp short lbl6Cf
    nop
    nop
lbl62f:
    cmp word ptr [bp-1Eh],2h
    jnz short lblB7f
    mov ax,0Dh
    push ax
lbl6Cf:
    call mf46
    add sp,2h
    mov ax,word ptr [bp-1Ch]
    dec ax
    push ax
    mov ax,word ptr [bp-1Ah]
    dec ax
    push ax
    mov ax,word ptr [bp-18h]
    inc ax
    push ax
    mov ax,word ptr [bp-16h]
    inc ax
    push ax
    mov ax,2h
    push ax
    call mf62
    add sp,0Ah
    xor ax,ax
    push ax
    call mf66
    add sp,2h
    push word ptr [bp-1Ch]
    push word ptr [bp-1Ah]
    push word ptr [bp-18h]
    push word ptr [bp-16h]
    mov ax,1h
    push ax
    call mf74
    add sp,0Ah
lblB7f:
    pop si
    pop di
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
