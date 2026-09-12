_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN md15:NEAR
    EXTRN md16:NEAR
    EXTRN md19:NEAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,6h
    mov word ptr [bp-6h],0h
    cmp word ptr [bp+6h],0h
    jng short lbl62f
    mov ax,word ptr ds:[84Ch]
    cmp word ptr [bp+6h],ax
    ja short lbl62f
    mov es, ds:[5A24h]
    mov bx,word ptr [bp+6h]
    mov ax,bx
    add bx,bx
    add bx,ax
    add bx,bx
    mov ax,word ptr es:[bx+md15]
    mov dx,word ptr es:[bx+md16]
    mov word ptr [bp-4h],ax
    mov word ptr [bp-2h],dx
    mov al,byte ptr es:[bx+md19]
    sub ah,ah
    dec ax
    dec ax
    jz short lbl4Ef
    dec ax
    jz short lbl58f
    dec ax
    jz short lbl76f
    dec ax
    jz short lbl58f
    jmp short lbl62f
lbl4Ef:
    les bx, dword ptr [bp-4h]
    mov ax,word ptr es:[bx+18h]
    jmp short lbl5Ff
    nop
lbl58f:
    les bx, dword ptr [bp-4h]
    mov ax,word ptr es:[bx+1Ch]
lbl5Fb:
lbl5Ff:
    mov word ptr [bp-6h],ax
lbl62f:
    cmp word ptr [bp-6h],0h
    jz short lbl80f
    mov ax,word ptr [bp-6h]
    add ax,ax
    add ax,0C16h
    mov dx,23A1h
    jmp short lbl85f
    nop
lbl76f:
    les bx, dword ptr [bp-4h]
    mov ax,word ptr es:[bx+0Ah]
    jmp short lbl5Fb
    nop
lbl80f:
    mov ax,0F0h
    mov dx,ds
lbl85f:
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
