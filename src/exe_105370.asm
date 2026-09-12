_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi17:NEAR
    EXTRN mf35:FAR
    EXTRN mf52:FAR
    EXTRN mf92:FAR
    EXTRN mf96:FAR
    EXTRN mf109:FAR
    EXTRN mf110:FAR
    EXTRN mf118:FAR
    EXTRN mf118:FAR
    EXTRN mf118:FAR
    EXTRN mf118:FAR
    EXTRN mf118:FAR
    EXTRN mf118:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,6h
    push di
    push si
    les bx, dword ptr [bp+6h]
    cmp byte ptr es:[bx],0h
    jz short lbl14f
    jmp near ptr lbl144f
lbl14f:
    mov ax,word ptr [bp+0Eh]
    sub ax,word ptr [bp+0Ah]
    inc ax
    mov word ptr [bp-4h],ax
    mov cx,word ptr [bp+10h]
    sub cx,word ptr [bp+0Ch]
    inc cx
    mov word ptr [bp-6h],cx
    cmp ax, offset mi17
    jnl short lbl30f
    jmp near ptr lbl144f
lbl30f:
    cmp cx,1h
    jnl short lbl38f
    jmp near ptr lbl144f
lbl38f:
    test byte ptr [bp-4h],1h
    jz short lbl50f
    cmp word ptr [bp+0Eh],13Fh
    jnl short lbl4Af
    inc word ptr [bp+0Eh]
    jmp short lbl4Df
lbl4Af:
    dec word ptr [bp+0Ah]
lbl4Df:
    inc word ptr [bp-4h]
lbl50f:
    mov ax,80h
    cwd
    push dx
    push ax
    call mf35
    add sp,4h
    les bx, dword ptr [bp+6h]
    mov word ptr es:[bx+10h],ax
    mov word ptr es:[bx+12h],dx
    mov ax,dx
    or ax,word ptr es:[bx+10h]
    jnz short lbl74f
    jmp near ptr lbl144f
lbl74f:
    xor ax,ax
    push ax
    les bx, dword ptr [bp+6h]
    push word ptr es:[bx+12h]
    push word ptr es:[bx+10h]
    push ax
    push word ptr [bp-4h]
    push word ptr [bp-6h]
    call mf52
    or ax,ax
    jz short lbl95f
    jmp near ptr lbl144f
lbl95f:
    les bx, dword ptr [bp+6h]
    les bx, dword ptr es:[bx+10h]
    mov ax,word ptr es:[bx+18h]
    mov dx,word ptr es:[bx+1Ah]
    les bx, dword ptr [bp+6h]
    mov word ptr es:[bx+0Ch],ax
    mov word ptr es:[bx+0Eh],dx
    mov ax,word ptr [bp+0Ah]
    mov word ptr es:[bx+2h],ax
    mov ax,word ptr [bp+0Ch]
    mov word ptr es:[bx+4h],ax
    mov ax,word ptr [bp-4h]
    mov word ptr es:[bx+6h],ax
    mov ax,word ptr [bp-6h]
    mov word ptr es:[bx+8h],ax
    xor al,al
    mov byte ptr es:[bx+0Ah],al
    mov byte ptr es:[bx+0Bh],al
    mov byte ptr es:[bx],1h
    mov byte ptr es:[bx+1h],al
    mov ax,word ptr [bp+10h]
    add ax,word ptr ds:[4F48h]
    push ax
    mov cx,word ptr [bp+0Eh]
    add cx,word ptr ds:[4F46h]
    push cx
    mov dx,word ptr ds:[4F48h]
    add word ptr [bp+0Ch],dx
    mov dx,word ptr [bp+0Ch]
    push dx
    mov si,word ptr ds:[4F46h]
    add word ptr [bp+0Ah],si
    mov si,word ptr [bp+0Ah]
    push si
    mov di,ax
    mov si,cx
    call mf92
    add sp,8h
    push word ptr [bp+8h]
    push word ptr [bp+6h]
    call mf96
    add sp,4h
    push word ptr [bp+0Ah]
    push word ptr [bp+0Ch]
    push si
    push di
    xor ax,ax
    push ax
    les bx, dword ptr [bp+6h]
    push word ptr es:[bx+12h]
    push word ptr es:[bx+10h]
    push ax
    push ax
    call mf109
    call mf110
    mov ax,1h
    jmp short lbl146f
lbl144f:
    xor ax,ax
lbl146f:
    pop si
    pop di
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
