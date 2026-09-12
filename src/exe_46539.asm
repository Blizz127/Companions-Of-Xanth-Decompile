_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN md15:NEAR
    EXTRN md16:NEAR
    EXTRN md19:NEAR
    EXTRN mi21:NEAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,4h
    push si
    cmp word ptr [bp+6h],0h
    jng short lbl60f
    mov ax,word ptr ds:[84Ch]
    cmp word ptr [bp+6h],ax
    ja short lbl60f
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
    sub ax, offset mi21
    jz short lbl46f
    dec ax
    dec ax
    jz short lbl50f
    jmp short lbl60f
lbl46f:
    les bx, dword ptr [bp-4h]
    mov ax,word ptr es:[bx+14h]
    jmp short lbl62f
    nop
lbl50f:
    les bx, dword ptr [bp-4h]
    add bx,14h
    mov si,word ptr [bp+8h]
    add si,si
    mov ax,word ptr es:[bx+si]
    jmp short lbl62f
lbl60f:
    xor ax,ax
lbl62f:
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
