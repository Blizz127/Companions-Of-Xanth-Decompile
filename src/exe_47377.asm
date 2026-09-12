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
    jng short lbl74f
    mov ax,word ptr ds:[84Ch]
    cmp word ptr [bp+6h],ax
    ja short lbl74f
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
    jz short lbl4Cf
    dec ax
    jz short lbl56f
    dec ax
    jz short lbl6Af
    dec ax
    jz short lbl60f
    dec ax
    jz short lbl6Af
    jmp short lbl74f
    nop
lbl4Cf:
    les bx, dword ptr [bp-4h]
    mov ax,word ptr es:[bx+0Ah]
    jmp short lbl76f
    nop
lbl56f:
    les bx, dword ptr [bp-4h]
    mov ax,word ptr es:[bx+1Ah]
    jmp short lbl76f
    nop
lbl60f:
    les bx, dword ptr [bp-4h]
    mov ax,word ptr es:[bx+0Ch]
    jmp short lbl76f
    nop
lbl6Af:
    les bx, dword ptr [bp-4h]
    mov ax,word ptr es:[bx+1Eh]
    jmp short lbl76f
    nop
lbl74f:
    xor ax,ax
lbl76f:
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
