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
    jng short lbl6Cf
    mov ax,word ptr ds:[84Ch]
    cmp word ptr [bp+6h],ax
    ja short lbl6Cf
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
    jz short lbl4Af
    dec ax
    jz short lbl56f
    dec ax
    jz short lbl62f
    dec ax
    dec ax
    jz short lbl62f
    jmp short lbl6Cf
    nop
lbl4Af:
    mov ax,word ptr [bp+8h]
    les bx, dword ptr [bp-4h]
    mov word ptr es:[bx+0Ch],ax
    jmp short lbl6Cf
lbl56f:
    mov ax,word ptr [bp+8h]
    les bx, dword ptr [bp-4h]
    mov word ptr es:[bx+14h],ax
    jmp short lbl6Cf
lbl62f:
    mov ax,word ptr [bp+8h]
    les bx, dword ptr [bp-4h]
    mov word ptr es:[bx+18h],ax
lbl6Cf:
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
