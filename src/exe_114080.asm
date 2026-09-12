_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf13:FAR
    EXTRN mf30:FAR
    EXTRN mf66:FAR
    EXTRN mf77:FAR
    EXTRN mf77:FAR
    EXTRN mf77:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,2h
    push di
    push si
    cmp word ptr ds:[51DEh],8h
    jnz short lbl16f
    mov ax,0FFFFh
    jmp near ptr lblD1f
    nop
lbl16f:
    mov ax,word ptr ds:[51DEh]
    mov word ptr [bp-2h],ax
    inc word ptr ds:[51DEh]
    call mf13
    mov bx,ax
    mov es,dx
    mov al,byte ptr es:[bx+3h]
    cbw
    mov bx,word ptr [bp-2h]
    add bx,bx
    mov word ptr [bx+6810h],ax
    mov ax,bx
    add bx,6830h
    push ds
    push bx
    mov cx,ax
    add ax,6820h
    push ds
    push ax
    mov si,cx
    call mf30
    add sp,8h
    mov ax,word ptr [bp+6h]
    mov word ptr [si+6840h],ax
    mov cx,word ptr [bp+8h]
    mov word ptr [si+6850h],cx
    mov dx,word ptr [bp+0Ah]
    mov word ptr [si+6860h],dx
    mov bx,word ptr [bp+0Ch]
    mov word ptr [si+6870h],bx
    mov word ptr [si+6880h],ax
    mov word ptr [si+6890h],dx
    mov di,word ptr ds:[6DDAh]
    mov word ptr [si+68A0h],di
    mov di,word ptr ds:[6D48h]
    mov word ptr [si+68B0h],di
    mov word ptr [si+68C0h],0FFFFh
    mov cl,4h
    mov di,word ptr [bp-2h]
    shl di,cl
    mov byte ptr [di+68E0h],0h
    mov di,word ptr [bp-2h]
    add di,di
    add di,di
    sub cx,cx
    mov word ptr [di+6962h],cx
    mov word ptr [di+6960h],cx
    mov word ptr [si+68D0h],cx
    push cx
    mov si,1h
    push si
    push bx
    push dx
    push word ptr [bp+8h]
    push ax
    push word ptr [bp-2h]
    call mf66
    add sp,0Eh
    cmp word ptr ds:[51E0h],0h
    jnl short lblCEf
    mov ax,word ptr [bp-2h]
    mov word ptr ds:[51E0h],ax
lblCEf:
    mov ax,word ptr [bp-2h]
lblD1f:
    pop si
    pop di
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
