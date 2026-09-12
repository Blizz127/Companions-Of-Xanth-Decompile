_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf23:FAR
    EXTRN md32:NEAR
    EXTRN md34:NEAR
    EXTRN mf41:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,4h
    mov word ptr [bp-2h],0h
    cmp word ptr ds:[0ECh],0h
    jng short lbl35f
    mov word ptr [bp-4h],32h
lbl17b:
    mov al,byte ptr [bp+6h]
    mov es, ds:[5A22h]
    mov bx,word ptr [bp-4h]
    cmp byte ptr es:[bx],al
    jz short lbl35f
    add word ptr [bp-4h],4h
    mov ax,word ptr ds:[0ECh]
    inc word ptr [bp-2h]
    cmp word ptr [bp-2h],ax
    jl short lbl17b
lbl35f:
    cmp word ptr [bp-2h],10h
    jl short lbl4Ef
    mov ax,0h
    mov cx,21A6h
    push cx
    push ax
    call mf23
    add sp,4h
    jmp short lbl75f
    nop
lbl4Ef:
    mov al,byte ptr [bp+6h]
    mov es, ds:[5A22h]
    mov bx,word ptr [bp-2h]
    add bx,bx
    add bx,bx
    mov byte ptr es:[bx+md32],al
    mov ax,word ptr [bp+8h]
    mov word ptr es:[bx+md34],ax
    mov ax,word ptr ds:[0ECh]
    cmp word ptr [bp-2h],ax
    jl short lbl75f
    inc word ptr ds:[0ECh]
lbl75f:
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
