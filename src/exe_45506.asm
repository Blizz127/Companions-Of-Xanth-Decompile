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
    jng short lbl5Ef
    mov ax,word ptr ds:[84Ch]
    cmp word ptr [bp+6h],ax
    ja short lbl5Ef
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
    dec ax
    jz short lbl48f
    dec ax
    jz short lbl48f
    dec ax
    dec ax
    jz short lbl54f
    jmp short lbl5Ef
    nop
lbl48f:
    les bx, dword ptr [bp-4h]
    mov al,byte ptr es:[bx+0Ah]
lbl4Fb:
    sub ah,ah
    jmp short lbl60f
    nop
lbl54f:
    les bx, dword ptr [bp-4h]
    mov al,byte ptr es:[bx+8h]
    jmp short lbl4Fb
    nop
lbl5Ef:
    xor ax,ax
lbl60f:
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
