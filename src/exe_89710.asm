_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf17:FAR
    EXTRN mf33:FAR
    EXTRN mf40:FAR
    EXTRN mf48:FAR
    EXTRN mf52:FAR
    EXTRN mf60:FAR
    EXTRN mf74:FAR
    EXTRN mf95:FAR
    EXTRN mf108:FAR
    EXTRN md120:NEAR
    EXTRN md131:NEAR
    EXTRN mf142:FAR
    EXTRN mf155:FAR
    EXTRN md167:NEAR
    EXTRN md178:NEAR
    EXTRN mf195:FAR
    EXTRN mi198:NEAR
    EXTRN mf209:FAR
    EXTRN mf244:FAR
    EXTRN mi247:NEAR
    EXTRN mf258:FAR
    EXTRN mf276:FAR
    EXTRN mf284:FAR
    EXTRN mf290:FAR
    EXTRN mf296:FAR
    EXTRN mf296:FAR
    EXTRN mf296:FAR
    EXTRN mf296:FAR
    EXTRN mf296:FAR
    EXTRN mf296:FAR
    EXTRN mf296:FAR
    EXTRN mf296:FAR
    EXTRN mf296:FAR
    EXTRN mf296:FAR
    EXTRN mf296:FAR
    EXTRN mf296:FAR
    EXTRN mf296:FAR
    EXTRN mf296:FAR
    EXTRN mf296:FAR
    EXTRN mf296:FAR
    EXTRN mf296:FAR
    EXTRN mf296:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,0B6h
    push di
    push si
    lea di,word ptr [bp-0Ch]
    mov si,4CB2h
    mov ax,ss
    mov es,ax
    mov cx,5h
    rep movsw
    movsb
    xor ax,ax
    push ax
    lea cx,word ptr [bp-0Ch]
    push ss
    push cx
    call mf17
    add sp,6h
    mov word ptr [bp-0Eh],ax
    or ax,ax
    jnz short lbl7Df
    lea ax,word ptr [bp-0Ch]
    push ss
    push ax
    push word ptr [bp+8h]
    push word ptr [bp+6h]
    mov ax,4CBDh
    push ds
    push ax
    lea ax,word ptr [bp-32h]
    push ss
    push ax
    call mf33
    add sp,10h
    xor ax,ax
    push ax
    lea cx,word ptr [bp-32h]
    push ss
    push cx
    call mf40
    add sp,6h
    mov word ptr [bp-0Eh],ax
    or ax,ax
    jnz short lbl7Df
    mov ax,4CC2h
    push ds
    push ax
    call mf48
    add sp,4h
    mov ax,1h
    push ax
    call mf52
    add sp,2h
lbl7Df:
    mov ax,4Fh
    push ax
    lea ax,word ptr [bp-82h]
    push ss
    push ax
    push word ptr [bp-0Eh]
    call mf60
    add sp,8h
    or ax,ax
    jnz short lbl99f
    jmp near ptr lbl2B1f
lbl99b:
lbl99f:
    lea ax,word ptr [bp-0A2h]
    push ss
    push ax
    mov ax,4CF5h
    push ds
    push ax
    lea ax,word ptr [bp-82h]
    push ss
    push ax
    call mf74
    add sp,0Ch
    dec ax
    jnz short lblC8f
    lea ax,word ptr [bp-0A2h]
    push ss
    push ax
    mov ax,8h
    push ax
    mov ax,0h
    mov cx,2EC4h
    jmp near ptr lbl28Bf
lblC8f:
    lea ax,word ptr [bp-0A2h]
    push ss
    push ax
    mov ax,4CFEh
    push ds
    push ax
    lea ax,word ptr [bp-82h]
    push ss
    push ax
    call mf95
    add sp,0Ch
    dec ax
    jnz short lbl138f
    lea ax,word ptr [bp-0A2h]
    push ss
    push ax
    mov ax,20h
    push ax
    mov ax,28h
    mov cx,2EC4h
    push cx
    push ax
    call mf108
    add sp,0Ah
    mov es, ds:[5B46h]
    mov ax,28h
    mov dx,ax
    mov di,ax
    mov cx,0FFFFh
    xor ax,ax
    repne scasb
    not cx
    dec cx
    mov bx,cx
    cmp byte ptr es:[bx+md120],5Ch
    jz short lbl120f
    jmp near ptr lbl295f
lbl120f:
    mov ax,dx
    mov di,ax
    mov cx,0FFFFh
    xor ax,ax
    repne scasb
    not cx
    dec cx
    mov bx,cx
    mov byte ptr es:[bx+md131],al
    jmp near ptr lbl295f
lbl138f:
    lea ax,word ptr [bp-0A2h]
    push ss
    push ax
    mov ax,4D0Ah
    push ds
    push ax
    lea ax,word ptr [bp-82h]
    push ss
    push ax
    call mf142
    add sp,0Ch
    dec ax
    jnz short lbl1A8f
    lea ax,word ptr [bp-0A2h]
    push ss
    push ax
    mov ax,20h
    push ax
    mov ax,48h
    mov cx,2EC4h
    push cx
    push ax
    call mf155
    add sp,0Ah
    mov es, ds:[5B48h]
    mov ax,48h
    mov dx,ax
    mov di,ax
    mov cx,0FFFFh
    xor ax,ax
    repne scasb
    not cx
    dec cx
    mov bx,cx
    cmp byte ptr es:[bx+md167],5Ch
    jz short lbl190f
    jmp near ptr lbl295f
lbl190f:
    mov ax,dx
    mov di,ax
    mov cx,0FFFFh
    xor ax,ax
    repne scasb
    not cx
    dec cx
    mov bx,cx
    mov byte ptr es:[bx+md178],al
    jmp near ptr lbl295f
lbl1A8f:
    lea ax,word ptr [bp-0B2h]
    push ss
    push ax
    lea ax,word ptr [bp-12h]
    push ss
    push ax
    lea ax,word ptr [bp-0A2h]
    push ss
    push ax
    mov ax,4D16h
    push ds
    push ax
    lea ax,word ptr [bp-82h]
    push ss
    push ax
    call mf195
    add sp,14h
    mov word ptr [bp-10h],ax
    cmp ax, offset mi198
    jl short lbl21Ef
    lea ax,word ptr [bp-0A2h]
    push ss
    push ax
    mov ax,8h
    push ax
    mov ax,8h
    mov cx,2EC4h
    push cx
    push ax
    call mf209
    add sp,0Ah
    cmp word ptr [bp-10h],2h
    jnl short lbl1F7f
    jmp near ptr lbl295f
lbl1F7f:
    mov al,byte ptr [bp-12h]
    mov es, ds:[5B4Ah]
    mov byte ptr es:[10h],al
    cmp word ptr [bp-10h],3h
    jnl short lbl20Bf
    jmp near ptr lbl295f
lbl20Bf:
    lea ax,word ptr [bp-0B2h]
    push ss
    push ax
    mov ax,4h
    push ax
    mov ax,12h
    mov cx,2EC4h
    jmp short lbl28Bf
    nop
lbl21Ef:
    lea ax,word ptr [bp-0B2h]
    push ss
    push ax
    lea ax,word ptr [bp-12h]
    push ss
    push ax
    lea ax,word ptr [bp-0A2h]
    push ss
    push ax
    mov ax,4D25h
    push ds
    push ax
    lea ax,word ptr [bp-82h]
    push ss
    push ax
    call mf244
    add sp,14h
    mov word ptr [bp-10h],ax
    cmp ax, offset mi247
    jl short lbl295f
    lea ax,word ptr [bp-0A2h]
    push ss
    push ax
    mov ax,0Ch
    push ax
    mov ax,16h
    mov cx,2EC4h
    push cx
    push ax
    call mf258
    add sp,0Ah
    cmp word ptr [bp-10h],2h
    jl short lbl295f
    mov al,byte ptr [bp-12h]
    mov es, ds:[5B4Ch]
    mov byte ptr es:[22h],al
    cmp word ptr [bp-10h],3h
    jl short lbl295f
    lea ax,word ptr [bp-0B2h]
    push ss
    push ax
    mov ax,4h
    push ax
    mov ax,24h
    mov cx,2EC4h
lbl28Bf:
    push cx
    push ax
    call mf276
    add sp,0Ah
lbl295f:
    mov ax,4Fh
    push ax
    lea ax,word ptr [bp-82h]
    push ss
    push ax
    push word ptr [bp-0Eh]
    call mf284
    add sp,8h
    or ax,ax
    jz short lbl2B1f
    jmp near ptr lbl99b
lbl2B1f:
    push word ptr [bp-0Eh]
    call mf290
    add sp,2h
    pop si
    pop di
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
