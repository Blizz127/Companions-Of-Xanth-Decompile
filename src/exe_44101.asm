_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN md22:NEAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,4h
    mov word ptr [bp-2h],0h
    cmp word ptr ds:[0ECh],0h
    jng short lbl46f
    mov word ptr [bp-4h],32h
lbl17b:
    mov al,byte ptr [bp+6h]
    mov es, ds:[5A22h]
    mov bx,word ptr [bp-4h]
    cmp byte ptr es:[bx],al
    jz short lbl38f
    add word ptr [bp-4h],4h
    mov ax,word ptr ds:[0ECh]
    inc word ptr [bp-2h]
    cmp word ptr [bp-2h],ax
    jl short lbl17b
    jmp short lbl46f
    nop
lbl38f:
    mov bx,word ptr [bp-2h]
    add bx,bx
    add bx,bx
    mov ax,word ptr es:[bx+md22]
    jmp short lbl49f
lbl46f:
    mov ax,7FFFh
lbl49f:
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
