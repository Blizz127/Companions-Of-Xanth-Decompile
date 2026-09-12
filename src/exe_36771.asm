_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf6:FAR
    EXTRN mf20:FAR
    EXTRN mf38:FAR
    EXTRN mf38:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,8h
    push si
    cmp word ptr [bp+6h],6h
    jnz short lbl14f
    call mf6
    jmp short lbl1Bf
lbl14f:
    mov ax,word ptr ds:[5C34h]
    mov dx,word ptr ds:[5C36h]
lbl1Bf:
    mov word ptr [bp-4h],ax
    mov word ptr [bp-2h],dx
    lea ax,word ptr [bp-6h]
    push ss
    push ax
    sub cx,cx
    push cx
    push cx
    push word ptr [bp+6h]
    push cx
    call mf20
    add sp,0Ch
    les bx, dword ptr [bp+8h]
    mov ax,word ptr es:[bx]
    sub ax,word ptr [bp-6h]
    cwd
    idiv word ptr ds:[5C32h]
    mov word ptr [bp-8h],ax
    imul word ptr ds:[5C32h]
    add ax,word ptr [bp-6h]
    mov word ptr es:[bx],ax
    mov bx,word ptr [bp-8h]
    add bx,bx
    les si, dword ptr [bp-4h]
    mov ax,word ptr es:[bx+si]
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
