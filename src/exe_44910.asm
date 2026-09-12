_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN md14:NEAR
    EXTRN md15:NEAR
    EXTRN md18:NEAR
    EXTRN mi32:NEAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,4h
    cmp word ptr [bp+6h],0h
    jng short lbl54f
    mov ax,word ptr ds:[84Ch]
    cmp word ptr [bp+6h],ax
    ja short lbl54f
    mov es, ds:[5A24h]
    mov bx,word ptr [bp+6h]
    mov ax,bx
    add bx,bx
    add bx,ax
    add bx,bx
    mov ax,word ptr es:[bx+md14]
    mov dx,word ptr es:[bx+md15]
    mov word ptr [bp-4h],ax
    mov word ptr [bp-2h],dx
    mov al,byte ptr es:[bx+md18]
    sub ah,ah
    dec ax
    jz short lbl49f
    dec ax
    jz short lbl49f
    dec ax
    jz short lbl49f
    dec ax
    jz short lbl49f
    dec ax
    jnz short lbl54f
lbl49f:
    mov ax,word ptr [bp-4h]
    mov dx,word ptr [bp-2h]
    add ax, offset mi32
    jmp short lbl57f
lbl54f:
    xor ax,ax
    cwd
lbl57f:
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
