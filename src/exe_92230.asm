_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf4:FAR
    EXTRN mi38:NEAR
    EXTRN mf67:FAR
    EXTRN mf70:FAR
    EXTRN mf70:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,0Eh
    push word ptr ds:[4D38h]
    call mf4
    add sp,2h
    or ax,ax
    jnl short lbl19f
    jmp near ptr lblC4f
lbl19f:
    mov bx,ax
    add bx,ax
    mov word ptr [bp-0Ch],bx
    cmp word ptr [bx+6378h],1h
    jnl short lbl2Af
    jmp near ptr lblC4f
lbl2Af:
    mov bx,word ptr [bp+6h]
    test byte ptr [bx+56A5h],1h
    jz short lbl38f
    add word ptr [bp+6h],20h
lbl38f:
    mov bx,ax
    mov al,byte ptr [bx+6374h]
    cbw
    mov word ptr [bp-4h],ax
    add ax,ax
    add ax,ax
    add bx,bx
    add bx,bx
    add ax,word ptr [bx+6364h]
    mov dx,word ptr [bx+6366h]
    mov word ptr [bp-0Ah],ax
    mov word ptr [bp-8h],dx
lbl58b:
    les bx, dword ptr [bp-0Ah]
    les bx, dword ptr es:[bx]
    mov al,byte ptr es:[bx]
    cbw
    mov bx,ax
    test byte ptr [bx+56A5h],1h
    jz short lbl6Ef
    add ax, offset mi38
lbl6Ef:
    mov word ptr [bp-6h],ax
    mov al,byte ptr [bp+6h]
    cbw
    cmp ax,word ptr [bp-6h]
    jng short lbl90f
    mov ax,word ptr [bp-4h]
    mov bx,word ptr [bp-0Ch]
    cmp word ptr [bx+6378h],ax
    jng short lbl90f
    add word ptr [bp-0Ah],4h
    inc word ptr [bp-4h]
    jmp short lbl58b
    nop
lbl90f:
    mov bx,word ptr [bp-0Ch]
    mov ax,word ptr [bp-4h]
    mov word ptr [bx+636Ch],ax
    cmp ax,word ptr [bx+6370h]
    jng short lblBCf
    mov bx,word ptr [bp-0Ch]
    mov ax,word ptr [bx+6378h]
    sub ax,word ptr [bx+637Ch]
    mov word ptr [bx+6370h],ax
    or ax,ax
    jnl short lblBCf
    mov bx,word ptr [bp-0Ch]
    mov word ptr [bx+6370h],0h
lblBCf:
    xor ax,ax
    push ax
    call mf67
lblC4f:
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
