_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi2:NEAR
    EXTRN mi12:NEAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp, offset mi2
    push si
    push di
    cmp word ptr ds:[4232h],0h
    jz short lbl13f
    jmp near ptr lbl1Cf
lbl13f:
    mov ax,0h
    mov dx,0h
    jmp near ptr lbl58f
lbl1Cf:
    mov ax,word ptr [bp+6h]
    add ax, offset mi12
    shl ax,1
    shl ax,1
    mov bx,word ptr ds:[4238h]
    mov cx,word ptr ds:[423Ah]
    add bx,ax
    mov es,cx
    mov ax,word ptr es:[bx]
    mov dx,word ptr es:[bx+2h]
    mov bx,word ptr [bp+6h]
    shl bx,1
    shl bx,1
    mov si,word ptr ds:[4238h]
    mov cx,word ptr ds:[423Ah]
    add si,bx
    mov bx,si
    mov es,cx
    sub ax,word ptr es:[bx]
    sbb dx,word ptr es:[bx+2h]
    jmp near ptr lbl58f
lbl58f:
    pop di
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
