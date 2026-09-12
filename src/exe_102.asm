_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi14:NEAR
    EXTRN mi29:NEAR
    EXTRN mi56:NEAR
    EXTRN mf76:FAR
    EXTRN mf92:FAR
    EXTRN mf96:FAR
    EXTRN mf96:FAR
mnem_unit:
    push bp
    mov bp,sp
    mov ax,word ptr [bp+0Ah]
    sub ax,2000h
    jz short lbl3Cf
    sar ax,1
    sar ax,1
    sar ax,1
    sar ax,1
    sar ax,1
    mov cx,ax
    mov bx,word ptr ds:[6DE2h]
    shl bx,1
    neg bx
    add bx, offset mi14
    jmp bx
    nop
    add ax,cx
    add ax,cx
    add ax,cx
    add ax,cx
    add ax,cx
    add ax,cx
    add ax,cx
    add ax,cx
    add ax,cx
    add ax,cx
    add ax,cx
lbl3Cf:
    add ah,byte ptr [bp+8h]
    add ax, offset mi29
    sar ax,1
    sar ax,1
    sar ax,1
    sar ax,1
    jnl short lbl51f
    xor ax,ax
    jmp short lbl59f
    nop
lbl51f:
    cmp ax,5FFh
    jl short lbl59f
    mov ax,5FFh
lbl59f:
    mov di,ax
    shr di,1
    shr di,1
    shr di,1
    shr di,1
    mov dx,di
    mov bl,byte ptr [di+3D8Eh]
    xor bh,bh
    mov di,bx
    shl di,1
    shl di,1
    shl di,1
    shl di,1
    shl di,1
    shl ax,1
    and ax, offset mi56
    add di,ax
    mov ax,word ptr [di+3BAEh]
    mov di,dx
    mov bl,byte ptr [di+3D2Eh]
    dec bl
    or ax,ax
    jnl short lbl90f
    inc bl
lbl90f:
    or bl,bl
    jnl short lbl98f
    inc bl
    sar ax,1
lbl98f:
    push bx
    push ax
    xor ah,ah
    push ax
    mov al,0A0h
    add al,byte ptr [bp+6h]
    push ax
    call mf76
    add sp,4h
    pop ax
    pop bx
    mov al,ah
    and al,3h
    shl bl,1
    shl bl,1
    add al,bl
    add al,byte ptr [bp+0Ch]
    xor ah,ah
    push ax
    push ax
    mov ax,0B0h
    add ax,word ptr [bp+6h]
    push ax
    call mf92
    add sp,4h
    pop ax
    pop bp
    retf
_TEXT ENDS
    END
