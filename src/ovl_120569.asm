_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi3:NEAR
    EXTRN mi4:NEAR
    EXTRN md9:NEAR
    EXTRN mf34:FAR
    EXTRN mf55:FAR
    EXTRN mf60:FAR
    EXTRN mf66:FAR
    EXTRN mf74:FAR
    EXTRN mf80:FAR
    EXTRN mf88:FAR
    EXTRN mf94:FAR
    EXTRN mf102:FAR
    EXTRN mf108:FAR
    EXTRN mf116:FAR
    EXTRN mf122:FAR
    EXTRN mf139:FAR
    EXTRN mf145:FAR
    EXTRN mf158:FAR
    EXTRN mf172:FAR
    EXTRN mf180:FAR
    EXTRN mf188:FAR
    EXTRN mf194:FAR
    EXTRN mf203:FAR
    EXTRN mf209:FAR
    EXTRN mf210:FAR
    EXTRN mf218:FAR
    EXTRN mf229:FAR
    EXTRN mf240:FAR
    EXTRN mf249:FAR
    EXTRN mf258:FAR
    EXTRN mf260:FAR
    EXTRN mf261:FAR
    EXTRN mf266:FAR
    EXTRN mf266:FAR
    EXTRN mf266:FAR
    EXTRN mf266:FAR
    EXTRN mf266:FAR
    EXTRN mf266:FAR
    EXTRN mf266:FAR
    EXTRN mf266:FAR
    EXTRN mf266:FAR
    EXTRN mf266:FAR
    EXTRN mf266:FAR
    EXTRN mf266:FAR
    EXTRN mf266:FAR
    EXTRN mf266:FAR
    EXTRN mf266:FAR
    EXTRN mf266:FAR
    EXTRN mf266:FAR
    EXTRN mf266:FAR
    EXTRN mf266:FAR
    EXTRN mf266:FAR
    EXTRN mf266:FAR
    EXTRN mf266:FAR
    EXTRN mf266:FAR
    EXTRN mf266:FAR
    EXTRN mf266:FAR
    EXTRN mf266:FAR
    EXTRN mf266:FAR
    EXTRN mf266:FAR
    EXTRN mf266:FAR
mnem_unit:
    push bp
    mov bp,sp
    mov ax,word ptr [bp+6h]
    sub ax, offset mi3
    cmp ax, offset mi4
    jna short lbl11f
    jmp near ptr lbl28Ff
lbl11f:
    add ax,ax
    xchg ax,bx
    jmp word ptr cs:[bx+md9]
    nop
    push bp
    add byte ptr [bp+di],al
    add word ptr [bp+di],ax
    add word ptr [bp+di],ax
    add word ptr [bx+si+4F02h],bp
    add word ptr [bx+si-54FEh],bp
    add word ptr [bx+si-57FEh],bp
    add ch,byte ptr [bx+si-57FEh]
    add ch,byte ptr [bx+si-57FEh]
    add cl,byte ptr [bx]
    add al,byte ptr [di-66FEh]
    add al,byte ptr [bp+di-59C2h]
    add al,byte ptr [bp+si]
    jl short lbl48f
    mov ax,2688h
    jmp short lbl4Bf
lbl48f:
    mov ax,2683h
lbl4Bf:
    push ds
    push ax
    mov ax,3h
    mov dx,0F00Dh
    push dx
    push ax
    call mf34
    mov sp,bp
    mov ax,word ptr ds:[2A6h]
    or ax,ax
    jz short lbl6Cf
    dec ax
    jz short lbl72f
    dec ax
    jz short lbl78f
    jmp short lbl87f
    nop
lbl6Cf:
    mov ax,4h
    jmp short lbl7Bf
    nop
lbl72f:
    mov ax,5h
    jmp short lbl7Bf
    nop
lbl78f:
    mov ax,6h
lbl7Bf:
    mov dx,0F00Dh
    push dx
    push ax
    call mf55
    mov sp,bp
lbl87f:
    mov ax,2691h
    push ds
    push ax
    call mf60
    mov sp,bp
    mov ax,8Dh
    push ax
    mov ax,91h
    push ax
    call mf66
    mov sp,bp
    or ax,ax
    jz short lblB5f
    mov ax,7h
    mov dx,0F00Dh
    push dx
    push ax
    call mf74
    mov sp,bp
lblB5f:
    mov ax,8Dh
    push ax
    mov ax,8Fh
    push ax
    call mf80
    mov sp,bp
    or ax,ax
    jz short lblD7f
    mov ax,8h
    mov dx,0F00Dh
    push dx
    push ax
    call mf88
    mov sp,bp
lblD7f:
    mov ax,9h
lblDAb:
    mov dx,0F00Dh
    push dx
    push ax
    call mf94
lblE4b:
    mov sp,bp
    jmp near ptr lbl28Ff
    nop
    xor ax,ax
    mov dx,0F00Dh
    push dx
    push ax
    call mf102
    mov sp,bp
    mov ax,8Dh
    push ax
    mov ax,8Fh
    push ax
    call mf108
    mov sp,bp
    or ax,ax
    jz short lbl11Af
    mov ax,1h
    mov dx,0F00Dh
    push dx
    push ax
    call mf116
    mov sp,bp
lbl11Af:
    mov ax,8Dh
    push ax
    mov ax,91h
    push ax
    call mf122
    mov sp,bp
    or ax,ax
    jnz short lbl130f
    jmp near ptr lbl28Ff
lbl130f:
    mov ax,2h
    jmp short lblDAb
    nop
    mov word ptr ds:[6A06h],13h
    cmp byte ptr ds:[307h],0h
    jnz short lbl156f
    mov ax,1h
    push ax
    mov ax,6h
    push ax
    mov ax,8026h
    push ax
    call mf139
    mov sp,bp
lbl156f:
    mov ax,8Dh
    push ax
    mov ax,91h
    push ax
    call mf145
    mov sp,bp
    or ax,ax
    jnz short lbl16Cf
    jmp near ptr lbl28Ff
lbl16Cf:
    cmp byte ptr ds:[306h],0h
    jnz short lbl188f
    mov ax,1h
    push ax
    mov ax,3h
lbl17Ab:
    push ax
    mov ax,8026h
    push ax
    call mf158
    jmp near ptr lblE4b
    nop
lbl188f:
    mov ax,1h
    push ax
    mov ax,4h
    jmp short lbl17Ab
    nop
    xor ax,ax
    push ax
    mov cx,3h
    push cx
    mov cx,8026h
    push cx
    call mf172
    add sp,6h
    xor ax,ax
    push ax
    mov cx,4h
    push cx
    mov cx,8026h
    push cx
    call mf180
    add sp,6h
    xor ax,ax
    push ax
    mov cx,6h
    push cx
    mov cx,8026h
    push cx
    call mf188
    add sp,6h
    mov ax,8Dh
    push ax
    mov ax,91h
    push ax
    call mf194
    add sp,4h
    or ax,ax
    jnz short lbl1E2f
    jmp near ptr lbl280f
lbl1E2f:
    mov ax,5h
    push ax
    mov ax,25h
    push ax
    call mf203
    add sp,4h
    jmp near ptr lbl280f
    nop
    cmp byte ptr ds:[2682h],0h
    jnz short lbl256f
    call mf209
    call mf210
    xor ax,ax
    push ax
    push ax
    mov ax,0Ch
    push ax
    mov ax,46Fh
    push ax
    call mf218
    add sp,8h
    cmp word ptr ds:[2A6h],2h
    jnl short lbl236f
    xor ax,ax
    push ax
    push ax
    mov ax,6h
    push ax
    mov ax,469h
    push ax
    call mf229
    add sp,8h
lbl236f:
    cmp word ptr ds:[2A6h],1h
    jnl short lbl251f
    xor ax,ax
    push ax
    push ax
    mov ax,6h
    push ax
    mov ax,463h
    push ax
    call mf240
    add sp,8h
lbl251f:
    mov byte ptr ds:[2682h],1h
lbl256f:
    mov ax,4h
    push ax
    mov ax,0h
    mov cx,3333h
    push cx
    push ax
    call mf249
    add sp,6h
    jmp short lbl291f
    mov ax,4h
    push ax
    mov ax,30h
    mov cx,3333h
    push cx
    push ax
    call mf258
    jmp near ptr lblE4b
lbl280f:
    call mf260
    call mf261
    mov byte ptr ds:[2682h],0h
lbl28Ff:
    xor ax,ax
lbl291f:
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
