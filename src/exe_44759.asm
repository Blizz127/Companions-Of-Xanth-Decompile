_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf12:FAR
    EXTRN md24:NEAR
    EXTRN md25:NEAR
    EXTRN md28:NEAR
    EXTRN mi46:NEAR
    EXTRN mf59:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,0Ah
    mov word ptr [bp-0Ah],0h
    cmp word ptr [bp+6h],0h
    jng short lbl90f
    mov ax,word ptr ds:[84Ch]
    cmp word ptr [bp+6h],ax
    ja short lbl90f
    mov ax,11h
    push ax
    push word ptr [bp+6h]
    call mf12
    add sp,4h
    mov word ptr [bp-8h],ax
    mov word ptr [bp-6h],dx
    or dx,ax
    jnz short lbl85f
    mov es, ds:[5A24h]
    mov bx,word ptr [bp+6h]
    mov ax,bx
    add bx,bx
    add bx,ax
    add bx,bx
    mov ax,word ptr es:[bx+md24]
    mov dx,word ptr es:[bx+md25]
    mov word ptr [bp-4h],ax
    mov word ptr [bp-2h],dx
    mov al,byte ptr es:[bx+md28]
    sub ah,ah
    dec ax
    jz short lbl67f
    dec ax
    jz short lbl67f
    dec ax
    jz short lbl67f
    dec ax
    jz short lbl67f
    dec ax
    jnz short lbl71f
lbl67f:
    les bx, dword ptr [bp-4h]
    mov ax,word ptr es:[bx+2h]
    mov word ptr [bp-0Ah],ax
lbl71f:
    cmp word ptr [bp-0Ah],0h
    jz short lbl85f
    mov ax,word ptr [bp-0Ah]
    add ax, offset mi46
    mov word ptr [bp-8h],ax
    mov word ptr [bp-6h],3420h
lbl85f:
    mov ax,word ptr [bp-8h]
    mov dx,word ptr [bp-6h]
    jmp short lbl93f
    nop
    nop
    nop
lbl90f:
    xor ax,ax
    cwd
lbl93f:
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
