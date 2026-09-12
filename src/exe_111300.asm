_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf64:FAR
    EXTRN mf67:FAR
    EXTRN mf75:FAR
    EXTRN mf79:FAR
    EXTRN mf81:FAR
    EXTRN mf82:FAR
    EXTRN mf85:FAR
    EXTRN mf90:FAR
    EXTRN mf94:FAR
    EXTRN mf104:FAR
    EXTRN mf104:FAR
    EXTRN mf104:FAR
    EXTRN mf104:FAR
    EXTRN mf104:FAR
    EXTRN mf104:FAR
    EXTRN mf104:FAR
    EXTRN mf104:FAR
    EXTRN mf104:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,1Eh
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
    mov ax,word ptr [bp-12h]
    mov word ptr [bp-16h],ax
    mov cx,word ptr [bp-10h]
    mov word ptr [bp-18h],cx
    xor cx,cx
    mov word ptr [bp-1Ch],cx
    mov word ptr [bp-1Ah],cx
    mov word ptr [bp-1Eh],5160h
lbl4Cb:
    mov bx,word ptr [bp-1Eh]
    mov al,byte ptr [bx]
    cbw
    add ax,word ptr [bp-16h]
    cmp ax,word ptr [bp+6h]
    jg short lbl7Ef
    mov al,byte ptr [bx+2h]
    cbw
    add ax,word ptr [bp-16h]
    cmp ax,word ptr [bp+6h]
    jl short lbl7Ef
    mov al,byte ptr [bx+1h]
    cbw
    add ax,word ptr [bp-18h]
    cmp ax,word ptr [bp+8h]
    jg short lbl7Ef
    mov al,byte ptr [bx+3h]
    cbw
    add ax,word ptr [bp-18h]
    cmp ax,word ptr [bp+8h]
    jnl short lbl8Ef
lbl7Ef:
    inc word ptr [bp-1Ah]
    add word ptr [bp-1Eh],4h
    cmp word ptr [bp-1Eh],5188h
    jc short lbl4Cb
    jmp short lbl99f
lbl8Ef:
    mov cl,byte ptr [bp-1Ah]
    mov ax,1h
    shl ax,cl
    mov word ptr [bp-1Ch],ax
lbl99f:
    mov ax,word ptr ds:[680Eh]
    test word ptr [bp-1Ch],ax
    jz short lbl104f
    call mf64
    push word ptr [bp-18h]
    push word ptr [bp-16h]
    call mf67
    add sp,4h
    mov ax,14h
    imul word ptr [bp-1Ah]
    add ax,5096h
    push ds
    push ax
    mov si,ax
    call mf75
    add sp,4h
    mov ax,1h
    push ax
    call mf79
    add sp,2h
    call mf81
    call mf82
    push ds
    push si
    call mf85
    add sp,4h
    xor ax,ax
    push ax
    push ax
    call mf90
    add sp,4h
    mov ax,1h
    push ax
    call mf94
    add sp,2h
    jmp short lbl109f
    nop
lbl104f:
    mov word ptr [bp-1Ah],0FFFFh
lbl109f:
    mov ax,word ptr [bp-1Ah]
    pop si
    pop di
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
