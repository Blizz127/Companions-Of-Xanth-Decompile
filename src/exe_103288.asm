_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf13:FAR
    EXTRN mf19:FAR
    EXTRN mf64:FAR
    EXTRN mf64:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,8h
    push di
    push si
    xor ax,ax
    mov word ptr [bp-4h],ax
    mov word ptr ds:[6E10h],ax
    cmp word ptr ds:[4F4Eh],ax
    jz short lbl4Af
    mov word ptr ds:[4F4Eh],ax
    cmp word ptr ds:[42E8h],ax
    jz short lbl26f
    call mf13
    jmp short lbl36f
lbl26f:
    mov ax,6A24h
    mov cx,38AFh
    push cx
    push ax
    call mf19
    add sp,4h
lbl36f:
    mov ax,38AFh
    push ds
    mov di,645Ah
    mov si,6A24h
    push ds
    pop es
    mov ds,ax
    mov cx,180h
    rep movsw
    pop ds
lbl4Af:
    mov word ptr [bp-6h],0h
    mov cx,4h
    mov di,6E2Ah
    mov si,6E42h
    push ds
    pop es
    rep movsw
    mov cx,4h
    mov di,6E32h
    mov si,6E4Ah
    rep movsw
    xor ax,ax
    mov cx,8h
    mov di,6E12h
    rep stosw
lbl71b:
    mov bx,word ptr [bp-6h]
    mov ax,word ptr [bx+6E3Ah]
    mov word ptr [bx+6E22h],ax
    mov bx,word ptr [bp-6h]
    mov word ptr [bx+6E3Ah],0h
    mov bx,word ptr [bp-6h]
    cmp word ptr [bx+6E22h],0h
    jz short lbl94f
    mov word ptr [bp-4h],1h
lbl94f:
    add word ptr [bp-6h],2h
    cmp word ptr [bp-6h],8h
    jl short lbl71b
    mov ax,word ptr [bp-4h]
    mov word ptr ds:[6E10h],ax
    pop si
    pop di
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
