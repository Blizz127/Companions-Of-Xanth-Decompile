_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
mnem_unit:
    push bp
    mov bp,sp
    push ds
    lds dx, dword ptr [bp+6h]
    jmp short lbl0Bf
    push bp
    push ds
lbl0Bf:
    pushf
    push ax
    push bx
    push cx
    push dx
    push di
    push si
    push es
    cld
    mov ax,ds
    mov es,ax
    mov di,dx
    mov ax,1DC1h
    mov ds,ax
    mov ax,word ptr ds:[0B78h]
    stosw
    mov cx,word ptr ds:[0D33h]
    dec cx
    xor dx,dx
    mov bx,0D39h
lbl2Db:
    test byte ptr [bx+7h],2h
    jz short lbl43f
    mov ax,dx
    stosw
    test byte ptr [bx+7h],8h
    jz short lbl43f
    mov si,word ptr [bx+2h]
    mov ax,word ptr [si+0Ah]
    stosw
lbl43f:
    add bx,12h
    inc dx
    loop lbl2Db
    pop es
    pop si
    pop di
    pop dx
    pop cx
    pop bx
    pop ax
    popf
    pop ds
    pop bp
    retf
_TEXT ENDS
    END
