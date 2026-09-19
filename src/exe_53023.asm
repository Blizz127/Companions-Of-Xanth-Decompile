_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi127:NEAR
    EXTRN mi102:NEAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,6h
    push si
    mov ax,word ptr ds:[5CE2h]
    sub ax,0CDh
    jz short lbl12f
    jmp near ptr lbl130f
lbl12f:
    cmp word ptr ds:[5CDEh],4h
    jnz short lbl2Cf
    cmp word ptr ds:[5CE0h],1h
    jnz short lbl2Cf
    cmp word ptr [bp+6h],0Ah
    jnz short lbl2Cf
    mov ax,0EDh
    jmp near ptr lbl130f
lbl2Cf:
    cmp word ptr ds:[5CDEh],8h
    jnz short lbl4Ef
    cmp word ptr ds:[5CE0h],6h
    jnz short lbl4Ef
    cmp word ptr [bp+6h],1h
    jnz short lbl4Ef
    cmp byte ptr ds:[311h],1h
    cmc
    db 1Bh, 0C0h ; override
    and ax,0F4h
    jmp near ptr lbl130f
lbl4Ef:
    cmp word ptr ds:[5CDEh],1h
    jnz short lbl76f
    cmp word ptr ds:[5CE0h],4h
    jnz short lbl76f
    cmp word ptr [bp+6h],5h
    jnz short lbl76f
    les bx, dword ptr [bp+8h]
    mov word ptr es:[bx],0h
    mov word ptr es:[bx+2h],2h
    mov ax,0C9h
    jmp near ptr lbl130f
lbl76f:
    mov word ptr [bp-6h],0h
    mov ax,word ptr ds:[5CDEh]
    mov word ptr [bp-2h],ax
    mov ax,word ptr ds:[5CE0h]
    mov word ptr [bp-4h],ax
    mov ax,word ptr [bp+6h]
    dec ax
    jz short lbl9Cf
    dec ax
    dec ax
    jz short lblA6f
    dec ax
    dec ax
    jz short lblB0f
    dec ax
    dec ax
    jz short lblBAf
    jmp short lblC2f
    nop
lbl9Cf:
    inc word ptr [bp-2h]
    mov word ptr [bp-6h],8h
    jmp short lblC2f
lblA6f:
    inc word ptr [bp-4h]
    mov word ptr [bp-6h],2h
    jmp short lblC2f
lblB0f:
    dec word ptr [bp-2h]
    mov word ptr [bp-6h],4h
    jmp short lblC2f
lblBAf:
    dec word ptr [bp-4h]
    mov word ptr [bp-6h],1h
lblC2f:
    cmp word ptr [bp-2h],0h
    jl short lbl10Cf
    cmp word ptr [bp-2h],9h
    jnl short lbl10Cf
    cmp word ptr [bp-4h],0h
    jl short lbl10Cf
    cmp word ptr [bp-4h],0Ah
    jnl short lbl10Cf
    mov ax,word ptr [bp-2h]
    mov cx,ax
    add ax,ax
    add ax,ax
    add ax,cx
    add ax,ax
    add ax,word ptr [bp-4h]
    les bx, dword ptr [bp+8h]
    mov word ptr es:[bx+6h],ax
    mov si,word ptr [bp-2h]
    add si,si
    mov cl,byte ptr [bp-4h]
    mov ax,1h
    shl ax,cl
    and ax,word ptr [si+2C7Eh]
    cmp ax, offset mi102
    db 1Bh, 0C0h ; override
    inc ax
    mov word ptr es:[bx+4h],ax
lbl10Cf:
    mov bx,word ptr ds:[5CDEh]
    mov ax,bx
    add bx,bx
    add bx,bx
    add bx,ax
    add bx,bx
    add bx,word ptr ds:[5CE0h]
    add bx,bx
    mov ax,word ptr [bx+2C90h]
    and ax,word ptr [bp-6h]
    cmp ax, offset mi127
    cmc
    db 1Bh, 0C0h ; override
    and ax,0CDh
lbl130f:
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
