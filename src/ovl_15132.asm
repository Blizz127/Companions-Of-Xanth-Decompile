_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf8:FAR
    EXTRN mf29:FAR
    EXTRN md53:NEAR
    EXTRN mf60:FAR
    EXTRN mf82:FAR
    EXTRN mf111:FAR
    EXTRN mf123:FAR
    EXTRN mf135:FAR
    EXTRN mf147:FAR
    EXTRN mf159:FAR
    EXTRN mf171:FAR
    EXTRN mf180:FAR
    EXTRN mf194:FAR
    EXTRN mf198:FAR
    EXTRN mf198:FAR
    EXTRN mf198:FAR
    EXTRN mf198:FAR
    EXTRN mf198:FAR
    EXTRN mf198:FAR
    EXTRN mf198:FAR
    EXTRN mf198:FAR
    EXTRN mf198:FAR
    EXTRN mf198:FAR
    EXTRN mf198:FAR
    EXTRN mf198:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,0Ch
    mov word ptr [bp-6h],0h
    mov ax,0h
    mov cx,3153h
    push cx
    push ax
    call mf8
    add sp,4h
    or ax,ax
    jz short lbl28f
    mov word ptr [bp-6h],0FFFFh
    jmp near ptr lbl1E5f
    nop
lbl28f:
    cmp word ptr [bp+6h],2h
    jz short lbl34f
    cmp word ptr [bp+6h],0Ah
    jnz short lbl52f
lbl34f:
    push word ptr [bp+6h]
    push word ptr [bp+0Ah]
    push word ptr [bp+8h]
    mov ax,1h
    push ax
    mov ax,20h
    push ax
    mov ax,6D28h
    push ds
    push ax
    call mf29
    add sp,0Eh
lbl52f:
    mov word ptr [bp-2h],0h
    cmp word ptr ds:[84Ch],0h
    jng short lblC1f
    mov word ptr [bp-0Ah],6Ch
lbl63b:
    mov bx,word ptr [bp-0Ah]
    mov es, ds:[5A74h]
    mov al,byte ptr es:[bx]
    sub ah,ah
    mov word ptr [bp-4h],ax
    or ax,ax
    jng short lblB2f
    push word ptr [bp+6h]
    push word ptr [bp+0Ah]
    push word ptr [bp+8h]
    mov ax,1h
    push ax
    mov es, ds:[5A76h]
    mov bx,word ptr [bp-4h]
    mov ax,bx
    add bx,bx
    add bx,ax
    sub ah,ah
    mov al,byte ptr es:[bx+md53]
    mov word ptr [bp-8h],ax
    push ax
    mov es, ds:[5A74h]
    mov bx,word ptr [bp-0Ah]
    push word ptr es:[bx+4h]
    push word ptr es:[bx+2h]
    call mf60
    add sp,0Eh
lblB2f:
    add word ptr [bp-0Ah],6h
    mov ax,word ptr ds:[84Ch]
    inc word ptr [bp-2h]
    cmp word ptr [bp-2h],ax
    jl short lbl63b
lblC1f:
    mov word ptr [bp-2h],0h
    cmp word ptr ds:[376h],0h
    jng short lbl10Af
    mov word ptr [bp-0Ch],11Ah
lblD2b:
    push word ptr [bp+6h]
    push word ptr [bp+0Ah]
    push word ptr [bp+8h]
    mov ax,1h
    push ax
    mov es, ds:[5A78h]
    mov bx,word ptr [bp-0Ch]
    push word ptr es:[bx]
    sub bx,4h
    push word ptr es:[bx+2h]
    push word ptr es:[bx]
    call mf82
    add sp,0Eh
    add word ptr [bp-0Ch],6h
    mov ax,word ptr ds:[376h]
    inc word ptr [bp-2h]
    cmp word ptr [bp-2h],ax
    jl short lblD2b
lbl10Af:
    cmp word ptr [bp+6h],2h
    jz short lbl116f
    cmp word ptr [bp+6h],3h
    jnz short lbl12Ef
lbl116f:
    mov ax,word ptr ds:[416Ch]
    mov word ptr ds:[69EEh],ax
    mov ax,word ptr ds:[415Ah]
    mov word ptr ds:[69F0h],ax
    mov ax,word ptr ds:[4168h]
    mov word ptr ds:[69EAh],ax
    mov ax,word ptr ds:[416Ah]
    mov word ptr ds:[69ECh],ax
lbl12Ef:
    push word ptr [bp+6h]
    push word ptr [bp+0Ah]
    push word ptr [bp+8h]
    mov ax,1h
    push ax
    mov cx,2h
    push cx
    mov dx,69EEh
    push ds
    push dx
    call mf111
    add sp,0Eh
    push word ptr [bp+6h]
    push word ptr [bp+0Ah]
    push word ptr [bp+8h]
    mov ax,1h
    push ax
    mov cx,2h
    push cx
    mov dx,69F0h
    push ds
    push dx
    call mf123
    add sp,0Eh
    push word ptr [bp+6h]
    push word ptr [bp+0Ah]
    push word ptr [bp+8h]
    mov ax,1h
    push ax
    mov cx,2h
    push cx
    mov dx,69EAh
    push ds
    push dx
    call mf135
    add sp,0Eh
    push word ptr [bp+6h]
    push word ptr [bp+0Ah]
    push word ptr [bp+8h]
    mov ax,1h
    push ax
    mov cx,2h
    push cx
    mov dx,69ECh
    push ds
    push dx
    call mf147
    add sp,0Eh
    push word ptr [bp+6h]
    push word ptr [bp+0Ah]
    push word ptr [bp+8h]
    mov ax,1h
    push ax
    mov ax,2h
    push ax
    mov ax,0ECh
    push ds
    push ax
    call mf159
    add sp,0Eh
    push word ptr [bp+6h]
    push word ptr [bp+0Ah]
    push word ptr [bp+8h]
    push word ptr ds:[0ECh]
    mov ax,4h
    push ax
    mov ax,32h
    mov cx,3420h
    push cx
    push ax
    call mf171
    add sp,0Eh
lbl1E5f:
    cmp word ptr [bp-6h],0h
    jnl short lbl21Ff
    cmp word ptr [bp+6h],2h
    jz short lbl1F7f
    cmp word ptr [bp+6h],0Ah
    jnz short lbl21Ff
lbl1F7f:
    push word ptr ds:[53BAh]
    call mf180
    add sp,2h
    push dx
    push ax
    cmp word ptr [bp+6h],2h
    jnz short lbl210f
    mov ax,18B8h
    jmp short lbl213f
lbl210f:
    mov ax,18BEh
lbl213f:
    push ds
    push ax
    mov ax,18C3h
    push ds
    push ax
    call mf194
lbl21Ff:
    mov ax,word ptr [bp-6h]
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
