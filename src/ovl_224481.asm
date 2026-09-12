_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf8:FAR
    EXTRN md16:NEAR
    EXTRN md19:NEAR
    EXTRN md29:NEAR
    EXTRN md31:NEAR
    EXTRN md32:NEAR
    EXTRN md33:NEAR
    EXTRN md34:NEAR
    EXTRN mf40:FAR
    EXTRN mf42:FAR
    EXTRN md47:NEAR
    EXTRN md48:NEAR
    EXTRN mf52:FAR
    EXTRN mf52:FAR
    EXTRN mf52:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,2h
    push si
    xor ax,ax
    push ax
    push word ptr [bp+8h]
    push word ptr [bp+6h]
    call mf8
    add sp,6h
    mov al,byte ptr [bp+8h]
    mov es, ds:[5B04h]
    mov bx,word ptr [bp+0Ah]
    add bx,bx
    add bx,bx
    mov word ptr [bp-2h],bx
    cmp byte ptr es:[bx+md16],al
    jnz short lbl3Af
    mov al,byte ptr [bp+9h]
    cmp byte ptr es:[bx+md19],al
    jz short lbl85f
lbl3Af:
    dec word ptr ds:[5E0Ch]
    mov byte ptr [bp+7h],1h
    mov ax,word ptr [bp+0Ah]
    mov bx,word ptr ds:[5E10h]
    mov cx,bx
    add bx,bx
    add bx,cx
    add bx,bx
    mov word ptr es:[bx+md29],ax
    mov si,word ptr [bp-2h]
    mov ax,word ptr es:[si+md31]
    mov dx,word ptr es:[si+md32]
    mov word ptr es:[bx+md33],ax
    mov word ptr es:[bx+md34],dx
    inc word ptr ds:[5E10h]
    mov ax,4h
    push ax
    xor ax,ax
    push ax
    call mf40
    add sp,4h
    call mf42
lbl85f:
    mov ax,word ptr [bp+6h]
    mov dx,word ptr [bp+8h]
    mov bx,word ptr [bp-2h]
    mov es, ds:[5B04h]
    mov word ptr es:[bx+md47],ax
    mov word ptr es:[bx+md48],dx
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
