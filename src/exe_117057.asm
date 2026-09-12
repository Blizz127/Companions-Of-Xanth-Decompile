_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi32:NEAR
    EXTRN mf35:FAR
    EXTRN mi39:NEAR
    EXTRN mf42:FAR
    EXTRN mf53:FAR
    EXTRN mi57:NEAR
    EXTRN mf60:FAR
    EXTRN mf62:FAR
    EXTRN mf72:FAR
    EXTRN mi76:NEAR
    EXTRN mf79:FAR
    EXTRN mf81:FAR
    EXTRN mf106:FAR
    EXTRN mf110:FAR
    EXTRN mf118:FAR
    EXTRN mf120:FAR
    EXTRN mf125:FAR
    EXTRN mf125:FAR
    EXTRN mf125:FAR
    EXTRN mf125:FAR
    EXTRN mf125:FAR
    EXTRN mf125:FAR
    EXTRN mf125:FAR
    EXTRN mf125:FAR
    EXTRN mf125:FAR
    EXTRN mf125:FAR
    EXTRN mf125:FAR
    EXTRN mf125:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,10h
    push di
    push si
    mov bx,word ptr ds:[51E0h]
    add bx,bx
    add bx,bx
    mov ax,word ptr [bx+6960h]
    mov dx,word ptr [bx+6962h]
    mov word ptr [bp-4h],ax
    mov word ptr [bp-2h],dx
    or dx,ax
    jnz short lbl25f
    jmp near ptr lbl14Ef
lbl25f:
    mov ax,word ptr [bp+6h]
    les bx, dword ptr [bp-4h]
    cmp word ptr es:[bx+2Ch],ax
    jnz short lbl34f
    jmp near ptr lbl14Ef
lbl34f:
    or ax,ax
    jz short lbl48f
    dec ax
    jz short lbl76f
    dec ax
    jz short lblB0f
    dec ax
    jnz short lbl44f
    jmp near ptr lblEAf
lbl44f:
    jmp near ptr lbl14Ef
    nop
lbl48f:
    mov ax,bx
    add ax, offset mi32
    push es
    push ax
    call mf35
    add sp,4h
    mov ax,word ptr [bp-4h]
    mov dx,word ptr [bp-2h]
    add ax, offset mi39
    push dx
    push ax
    call mf42
    add sp,4h
    les bx, dword ptr [bp-4h]
    mov word ptr es:[bx+2Ch],0h
    jmp near ptr lbl14Ef
lbl76f:
    cmp byte ptr es:[bx+4h],0h
    jnz short lbl80f
    jmp near ptr lbl14Ef
lbl80f:
    xor ax,ax
    push ax
    push ax
    call mf53
    add sp,4h
    mov ax,word ptr [bp-4h]
    mov dx,word ptr [bp-2h]
    add ax, offset mi57
    push dx
    push ax
    call mf60
    add sp,4h
    call mf62
    les bx, dword ptr [bp-4h]
    mov word ptr es:[bx+2Ch],1h
    jmp near ptr lbl14Ef
lblB0f:
    cmp byte ptr es:[bx+18h],0h
    jnz short lblBAf
    jmp near ptr lbl14Ef
lblBAf:
    xor ax,ax
    push ax
    push ax
    call mf72
    add sp,4h
    mov ax,word ptr [bp-4h]
    mov dx,word ptr [bp-2h]
    add ax, offset mi76
    push dx
    push ax
    call mf79
    add sp,4h
    call mf81
    les bx, dword ptr [bp-4h]
    mov word ptr es:[bx+2Ch],2h
    jmp short lbl14Ef
    nop
lblEAf:
    cmp byte ptr es:[bx+18h],0h
    jz short lbl14Ef
    cmp word ptr es:[bx+2Ch],2h
    jnz short lbl14Ef
    add bx,18h
    mov ax,word ptr es:[bx+2h]
    mov word ptr [bp-0Ah],ax
    mov cx,word ptr es:[bx+4h]
    mov word ptr [bp-0Ch],cx
    add ax,word ptr es:[bx+6h]
    dec ax
    mov word ptr [bp-0Eh],ax
    add cx,word ptr es:[bx+8h]
    dec cx
    mov word ptr [bp-10h],cx
    xor ax,ax
    push ax
    push ax
    mov si,bx
    mov di,es
    call mf106
    add sp,4h
    push di
    push si
    call mf110
    add sp,4h
    push word ptr [bp-10h]
    push word ptr [bp-0Eh]
    push word ptr [bp-0Ch]
    push word ptr [bp-0Ah]
    push di
    push si
    call mf118
    add sp,0Ch
    call mf120
lbl14Ef:
    pop si
    pop di
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
