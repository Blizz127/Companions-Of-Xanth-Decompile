_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN md17:NEAR
    EXTRN md19:NEAR
    EXTRN md20:NEAR
    EXTRN md27:NEAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,6h
    push si
    cmp word ptr [bp+6h],0h
    jg short lbl10f
    jmp near ptr lbl96f
lbl10f:
    mov ax,word ptr ds:[84Ch]
    cmp word ptr [bp+6h],ax
    ja short lbl96f
    mov es, ds:[5A24h]
    mov bx,word ptr [bp+6h]
    mov ax,bx
    add bx,bx
    add bx,ax
    add bx,bx
    sub ah,ah
    mov al,byte ptr es:[bx+md17]
    mov word ptr [bp-2h],ax
    mov cx,word ptr es:[bx+md19]
    mov dx,word ptr es:[bx+md20]
    mov word ptr [bp-6h],cx
    mov word ptr [bp-4h],dx
    mov bx,ax
    add bx,bx
    add bx,ax
    mov es, ds:[5A28h]
    mov al,byte ptr es:[bx+md27]
    cmp ax,word ptr [bp+8h]
    jng short lbl96f
    mov ax,word ptr [bp-2h]
    dec ax
    jz short lbl84f
    dec ax
    jz short lbl6Af
    dec ax
    jz short lbl74f
    dec ax
    jz short lbl84f
    dec ax
    jz short lbl8Ef
    jmp short lbl96f
    nop
lbl6Af:
    les bx, dword ptr [bp-6h]
    mov ax,word ptr es:[bx+0Eh]
    jmp short lbl98f
    nop
lbl74f:
    les bx, dword ptr [bp-6h]
    add bx,0Eh
lbl7Ab:
    mov si,word ptr [bp+8h]
    add si,si
    mov ax,word ptr es:[bx+si]
    jmp short lbl98f
lbl84f:
    les bx, dword ptr [bp-6h]
    mov ax,word ptr es:[bx+6h]
    jmp short lbl98f
    nop
lbl8Ef:
    les bx, dword ptr [bp-6h]
    add bx,0Ch
    jmp short lbl7Ab
lbl96f:
    xor ax,ax
lbl98f:
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
