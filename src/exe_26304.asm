_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi13:NEAR
mnem_unit:
    push bp
    mov bp,sp
    push bx
    push cx
    push di
    push es
    mov bx,0h
    jnc short lbl0Ff
    mov bx,1h
lbl0Ff:
    push bx
    mov es,dx
    mov di,ax
    mov ax,word ptr es:[di+16h]
    cmp ax, offset mi13
    jnz short lbl35f
    cmp word ptr [bp-0Ah],0h
    jnz short lbl2Df
    mov ax,ds
    add ax,1000h
    mov ds,ax
    jmp short lbl8Ff
    nop
lbl2Df:
    add word ptr [bp-8h],1000h
    jmp short lbl8Ff
    nop
lbl35f:
    mov ax,word ptr es:[di+2Ah]
    mov bx,4000h
    mul bx
    cmp word ptr [bp-0Ah],0h
    jnz short lbl48f
    sub si,ax
    jmp short lbl4Bf
lbl48f:
    sub word ptr [bp-6h],ax
lbl4Bf:
    mov cx,word ptr es:[di+24h]
    sub cx,word ptr es:[di+26h]
    ja short lbl5Bf
    mov ax,0FC19h
    jmp short lbl8Cf
    nop
lbl5Bf:
    mov ax,word ptr es:[di+28h]
    dec ax
    cmp cx,word ptr es:[di+2Ah]
    jna short lbl6Af
    mov cx,word ptr es:[di+2Ah]
lbl6Ab:
lbl6Af:
    mov dx,word ptr es:[di+22h]
    mov bx,word ptr es:[di+26h]
    inc word ptr es:[di+26h]
    inc ax
    push ax
    mov ah,44h
    int 67h
    or ah,ah
    pop ax
    loope lbl6Ab
    jnz short lbl86f
    jmp short lbl8Ff
    nop
lbl86f:
    mov ax,0FFEAh
    jmp short lbl8Cf
    nop
lbl8Cf:
    stc
    jmp short lbl90f
lbl8Ff:
    clc
lbl90f:
    mov es, [bp-8h]
    mov di,word ptr [bp-6h]
    mov cx,word ptr [bp-4h]
    mov bx,word ptr [bp-2h]
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
