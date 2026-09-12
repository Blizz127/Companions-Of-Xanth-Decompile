_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf10:FAR
    EXTRN mf14:FAR
    EXTRN mf22:FAR
    EXTRN mf31:FAR
    EXTRN mf74:FAR
    EXTRN mf74:FAR
    EXTRN mf74:FAR
    EXTRN mf74:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,4h
    push si
    mov bx,word ptr [bp+6h]
    add bx,bx
    les si, dword ptr ds:[18EEh]
    push word ptr es:[bx+si]
    mov ax,5h
    push ax
    call mf10
    add sp,4h
    push dx
    push ax
    call mf14
    add sp,4h
    or ax,ax
    jz short lbl40f
    mov ax,113h
    mov cx,3181h
    push cx
    push ax
    call mf22
    add sp,4h
    jmp near ptr lblD1f
lbl40f:
    mov bx,word ptr [bp+6h]
    add bx,bx
    add bx,bx
    les si, dword ptr ds:[18F2h]
    push word ptr es:[bx+si+2h]
    push word ptr es:[bx+si]
    call mf31
    add sp,4h
    mov ax,word ptr ds:[18F6h]
    cmp word ptr [bp+6h],ax
    jnl short lblABf
    mov ax,word ptr [bp+6h]
    add ax,ax
    add ax,ax
    mov word ptr [bp-2h],ax
    mov ax,word ptr [bp+6h]
    add ax,ax
    mov word ptr [bp-4h],ax
lbl74b:
    les bx, dword ptr ds:[18EEh]
    add bx,word ptr [bp-4h]
    mov ax,word ptr es:[bx+2h]
    mov word ptr es:[bx],ax
    les bx, dword ptr ds:[18F2h]
    add bx,word ptr [bp-2h]
    mov ax,word ptr es:[bx+4h]
    mov dx,word ptr es:[bx+6h]
    mov word ptr es:[bx],ax
    mov word ptr es:[bx+2h],dx
    add word ptr [bp-2h],4h
    add word ptr [bp-4h],2h
    mov ax,word ptr ds:[18F6h]
    inc word ptr [bp+6h]
    cmp word ptr [bp+6h],ax
    jl short lbl74b
lblABf:
    mov bx,word ptr [bp+6h]
    add bx,bx
    les si, dword ptr ds:[18EEh]
    mov word ptr es:[bx+si],0h
    mov bx,word ptr [bp+6h]
    add bx,bx
    add bx,bx
    les si, dword ptr ds:[18F2h]
    sub ax,ax
    mov word ptr es:[bx+si+2h],ax
    mov word ptr es:[bx+si],ax
    dec word ptr ds:[18F6h]
lblD1f:
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
