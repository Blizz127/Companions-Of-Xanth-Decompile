_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN md14:NEAR
    EXTRN md15:NEAR
    EXTRN md18:NEAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,4h
    cmp word ptr [bp+6h],0h
    jng short lbl68f
    mov ax,word ptr ds:[84Ch]
    cmp word ptr [bp+6h],ax
    ja short lbl68f
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
    jz short lbl46f
    dec ax
    jz short lbl52f
    dec ax
    jz short lbl5Ef
    jmp short lbl68f
    nop
lbl46f:
    mov ax,word ptr [bp+8h]
    les bx, dword ptr [bp-4h]
    mov word ptr es:[bx+8h],ax
    jmp short lbl68f
lbl52f:
    mov ax,word ptr [bp+8h]
    les bx, dword ptr [bp-4h]
    mov word ptr es:[bx+12h],ax
    jmp short lbl68f
lbl5Ef:
    mov ax,word ptr [bp+8h]
    les bx, dword ptr [bp-4h]
    mov word ptr es:[bx+16h],ax
lbl68f:
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
