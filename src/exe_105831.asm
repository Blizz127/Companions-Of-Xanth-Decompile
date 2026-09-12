_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf24:FAR
    EXTRN mf43:FAR
    EXTRN mf50:FAR
    EXTRN mf63:FAR
    EXTRN mf72:FAR
    EXTRN mf74:FAR
    EXTRN mf78:FAR
    EXTRN mf78:FAR
    EXTRN mf78:FAR
    EXTRN mf78:FAR
    EXTRN mf78:FAR
    EXTRN mf78:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,8h
    push si
    les bx, dword ptr [bp+6h]
    cmp byte ptr es:[bx],0h
    jnz short lbl13f
    jmp near ptr lblDAf
lbl13f:
    mov ax,word ptr es:[bx+2h]
    add ax,word ptr ds:[4F46h]
    mov word ptr [bp-2h],ax
    mov cx,word ptr es:[bx+4h]
    add cx,word ptr ds:[4F48h]
    mov word ptr [bp-4h],cx
    mov dx,ax
    add ax,word ptr es:[bx+6h]
    mov word ptr [bp-6h],ax
    mov si,cx
    add cx,word ptr es:[bx+8h]
    mov word ptr [bp-8h],cx
    push cx
    push ax
    push si
    push dx
    call mf24
    add sp,8h
    les bx, dword ptr [bp+6h]
    test byte ptr es:[bx+1h],80h
    jz short lbl80f
    cmp byte ptr es:[bx+1h],83h
    jnz short lbl5Ef
    mov ax,1h
    jmp short lbl60f
    nop
lbl5Ef:
    xor ax,ax
lbl60f:
    push ax
    xor ax,ax
    push ax
    push word ptr es:[bx+6h]
    push word ptr [bp-4h]
    push word ptr [bp-2h]
    push word ptr es:[bx+0Eh]
    push word ptr es:[bx+0Ch]
    call mf43
    add sp,0Eh
    jmp short lblD5f
lbl80f:
    cmp byte ptr es:[bx+1h],0h
    jnz short lblB4f
    push es
    push bx
    call mf50
    add sp,4h
    les bx, dword ptr [bp+6h]
    push word ptr es:[bx+12h]
    push word ptr es:[bx+10h]
    xor ax,ax
    push ax
    push ax
    push word ptr [bp-2h]
    push word ptr [bp-4h]
    push word ptr [bp-6h]
    push word ptr [bp-8h]
    push ax
    call mf63
    jmp short lblD5f
lblB4f:
    push word ptr es:[bx+8h]
    push word ptr es:[bx+6h]
    push word ptr [bp-4h]
    push word ptr [bp-2h]
    les bx, dword ptr es:[bx+0Ch]
    push word ptr es:[bx+2h]
    push word ptr es:[bx]
    call mf72
    add sp,0Ch
lblD5f:
    call mf74
lblDAf:
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
