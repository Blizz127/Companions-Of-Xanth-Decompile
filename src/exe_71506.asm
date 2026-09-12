_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi2:NEAR
    EXTRN mi29:NEAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp, offset mi2
    push si
    push di
    mov word ptr [bp-4h],0h
    jmp near ptr lbl5Df
lbl11b:
    les bx, dword ptr ds:[6DF4h]
    mov ax,word ptr es:[bx]
    mov dx,word ptr es:[bx+2h]
    mov cx,word ptr [bp+6h]
    mov dx,word ptr [bp+8h]
    sub cx,ax
    add cx,8h
    mov bx,word ptr [bp-4h]
    shl bx,1
    mov word ptr [bx+62BAh],cx
    les bx, dword ptr [bp+6h]
    mov al,byte ptr es:[bx+7h]
    and ax,0FFh
    les bx, dword ptr [bp+6h]
    mov cl,byte ptr es:[bx+6h]
    mov word ptr [bp-6h],ax
    mov ax,cx
    and ax,0FFh
    mov cx,8h
    shl ax,cl
    mov cx,word ptr [bp-6h]
    add ax,cx
    add ax, offset mi29
    add word ptr [bp+6h],ax
    add word ptr [bp-4h],1h
lbl5Df:
    mov ax,word ptr ds:[62AAh]
    cmp word ptr [bp-4h],ax
    jnl short lbl68f
    jmp near ptr lbl11b
lbl68f:
    pop di
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
