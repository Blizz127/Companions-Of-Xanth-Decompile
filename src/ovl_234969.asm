_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf10:FAR
    EXTRN mi42:NEAR
    EXTRN mi46:NEAR
    EXTRN mf51:FAR
    EXTRN mf79:FAR
    EXTRN mf91:FAR
    EXTRN mf91:FAR
    EXTRN mf91:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,2h
    push si
    mov ax,word ptr [bp+0Ah]
    inc ax
    push ax
    les bx, dword ptr [bp+6h]
    push word ptr es:[bx+2h]
    push word ptr es:[bx]
    call mf10
    add sp,6h
    les bx, dword ptr [bp+6h]
    mov al,byte ptr es:[bx+2h]
    mov bx,word ptr [bp+0Ah]
    add bx,bx
    add bx,bx
    mov word ptr [bp-2h],bx
    mov es, ds:[5E18h]
    add bx,word ptr ds:[5E16h]
    cmp byte ptr es:[bx+2h],al
    jnz short lbl58f
    les bx, dword ptr [bp+6h]
    mov al,byte ptr es:[bx+3h]
    mov bx,word ptr [bp-2h]
    mov es, ds:[5E18h]
    add bx,word ptr ds:[5E16h]
    cmp byte ptr es:[bx+3h],al
    jnz short lbl58f
    jmp near ptr lblE7f
lbl58f:
    cmp word ptr ds:[5E28h],0h
    jnz short lbl62f
    jmp near ptr lblE7f
lbl62f:
    mov ax,word ptr ds:[5E26h]
    inc ax
    cmp ax,word ptr ds:[5E28h]
    jc short lbl98f
    mov ax,word ptr ds:[5E28h]
    mov cx,ax
    add ax,ax
    add ax,cx
    add ax,ax
    sub ax, offset mi42
    push ax
    mov ax,word ptr ds:[5E22h]
    mov dx,word ptr ds:[5E24h]
    add ax, offset mi46
    push dx
    push ax
    push dx
    push word ptr ds:[5E22h]
    call mf51
    add sp,0Ah
    dec word ptr ds:[5E26h]
lbl98f:
    mov bx,word ptr ds:[5E26h]
    mov ax,bx
    add bx,bx
    add bx,ax
    add bx,bx
    les si, dword ptr ds:[5E22h]
    mov ax,word ptr [bp+0Ah]
    mov word ptr es:[bx+si],ax
    mov bx,word ptr [bp-2h]
    les si, dword ptr ds:[5E16h]
    mov ax,word ptr es:[bx+si]
    mov dx,word ptr es:[bx+si+2h]
    mov si,word ptr ds:[5E26h]
    mov cx,si
    add si,si
    add si,cx
    add si,si
    les bx, dword ptr ds:[5E22h]
    mov word ptr es:[bx+si+2h],ax
    mov word ptr es:[bx+si+4h],dx
    inc word ptr ds:[5E26h]
    mov ax,3h
    push ax
    xor ax,ax
    push ax
    call mf79
    add sp,4h
lblE7f:
    les bx, dword ptr [bp+6h]
    mov ax,word ptr es:[bx]
    mov dx,word ptr es:[bx+2h]
    mov bx,word ptr [bp-2h]
    les si, dword ptr ds:[5E16h]
    mov word ptr es:[bx+si],ax
    mov word ptr es:[bx+si+2h],dx
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
