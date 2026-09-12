_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi2:NEAR
    EXTRN mi32:NEAR
    EXTRN mf57:FAR
    EXTRN mf72:FAR
    EXTRN mf78:FAR
    EXTRN mf78:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp, offset mi2
    push si
    push di
    mov ax,word ptr ds:[5E76h]
    cmp word ptr [bp+6h],ax
    jnc short lbl14f
    jmp near ptr lbl17f
lbl14f:
    jmp near ptr lblD0f
lbl17f:
    mov ax,34h
    mov cx,word ptr [bp+8h]
    mov dx,word ptr [bp+0Ah]
    add cx,ax
    mov word ptr [bp-10h],cx
    mov word ptr [bp-0Eh],dx
    mov bx,word ptr [bp-10h]
    mov es, [bp-0Eh]
    add word ptr [bp-10h],2h
    mov ax,word ptr es:[bx]
    mov word ptr [bp-12h],ax
    les bx, dword ptr [bp-10h]
    mov ax,word ptr es:[bx]
    mov word ptr [bp-8h],ax
    mov ax,1Ah
    mov cx,word ptr [bp+8h]
    mov dx,word ptr [bp+0Ah]
    add cx,ax
    mov word ptr [bp-6h],cx
    mov word ptr [bp-4h],dx
    mov al,byte ptr ds:[5E7Bh]
    cbw
    cmp ax, offset mi32
    jnz short lbl5Ef
    jmp near ptr lbl74f
lbl5Ef:
    mov ax,word ptr [bp+6h]
    shl ax,1
    mov cx,17Eh
    mov dx,2E8Eh
    add cx,ax
    mov word ptr [bp-0Ch],cx
    mov word ptr [bp-0Ah],dx
    jmp near ptr lbl87f
lbl74f:
    mov ax,word ptr [bp+6h]
    shl ax,1
    mov cx,16Ch
    mov dx,2E8Eh
    add cx,ax
    mov word ptr [bp-0Ch],cx
    mov word ptr [bp-0Ah],dx
lbl87f:
    push word ptr [bp-12h]
    push word ptr [bp+0Ah]
    push word ptr [bp+8h]
    les bx, dword ptr [bp-0Ch]
    mov al,byte ptr es:[bx]
    and ax,0FFh
    push ax
    call mf57
    add sp,8h
    les bx, dword ptr [bp-0Ch]
    mov al,byte ptr es:[bx+1h]
    and ax,0FFh
    cmp ax,0FFh
    jnz short lblB4f
    jmp near ptr lblD0f
lblB4f:
    push word ptr [bp-8h]
    push word ptr [bp-4h]
    push word ptr [bp-6h]
    les bx, dword ptr [bp-0Ch]
    mov al,byte ptr es:[bx+1h]
    and ax,0FFh
    push ax
    call mf72
    add sp,8h
lblD0f:
    pop di
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
