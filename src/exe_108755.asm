_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf26:FAR
    EXTRN mf42:FAR
    EXTRN mf61:FAR
    EXTRN mf72:FAR
    EXTRN mf72:FAR
    EXTRN mf72:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,8h
    push si
    mov ax,word ptr [bp+8h]
    mov word ptr [bp-2h],ax
    mov bx,word ptr [bp+6h]
    add bx,bx
    add bx,67E2h
    mov word ptr [bp-6h],bx
    cmp word ptr [bx],ax
    jng short lbl59f
    mov ax,14h
    imul word ptr [bp-2h]
    mov word ptr [bp-4h],ax
    mov ax,word ptr [bp+6h]
    add ax,ax
    add ax,ax
    add ax,67C2h
    mov word ptr [bp-8h],ax
lbl33b:
    mov bx,word ptr [bp-8h]
    mov ax,word ptr [bx]
    mov dx,word ptr [bx+2h]
    add ax,word ptr [bp-4h]
    push dx
    push ax
    call mf26
    add sp,4h
    add word ptr [bp-4h],14h
    inc word ptr [bp-2h]
    mov ax,word ptr [bp-2h]
    mov bx,word ptr [bp-6h]
    cmp word ptr [bx],ax
    jg short lbl33b
lbl59f:
    cmp word ptr [bp+8h],0h
    jnz short lbl84f
    mov bx,word ptr [bp+6h]
    add bx,bx
    add bx,bx
    push word ptr [bx+67C4h]
    push word ptr [bx+67C2h]
    mov si,bx
    call mf42
    add sp,4h
    sub ax,ax
    mov word ptr [si+67C4h],ax
    mov word ptr [si+67C2h],ax
    jmp short lblB2f
lbl84f:
    mov ax,word ptr [bp+8h]
    inc ax
    mov cx,14h
    imul cx
    sub dx,dx
    push dx
    push ax
    mov bx,word ptr [bp+6h]
    add bx,bx
    add bx,bx
    push word ptr [bx+67C4h]
    push word ptr [bx+67C2h]
    mov si,bx
    call mf61
    add sp,8h
    mov word ptr [si+67C2h],ax
    mov word ptr [si+67C4h],dx
lblB2f:
    mov al,byte ptr [bp+8h]
    cbw
    mov bx,word ptr [bp-6h]
    mov word ptr [bx],ax
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
