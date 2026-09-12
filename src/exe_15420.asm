_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf27:FAR
    EXTRN mf32:FAR
    EXTRN mi38:NEAR
    EXTRN mf79:FAR
    EXTRN mf88:FAR
    EXTRN mf123:FAR
    EXTRN mi124:NEAR
    EXTRN mf135:FAR
    EXTRN mf149:FAR
    EXTRN mf162:FAR
    EXTRN mf162:FAR
    EXTRN mf162:FAR
    EXTRN mf162:FAR
    EXTRN mf162:FAR
    EXTRN mf162:FAR
    EXTRN mf162:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,0Ah
    push di
    push si
    mov word ptr [bp-6h],0h
    mov di,57DAh
    les bx, dword ptr [bp+6h]
    mov ax,word ptr es:[bx]
    mov dx,word ptr es:[bx+2h]
    mov word ptr [bp-4h],ax
    mov word ptr [bp-2h],dx
    or dx,dx
    jnl short lbl2Af
    xor ax,ax
    cwd
    jmp near ptr lbl19Af
lbl2Af:
    mov ax,0E080h
    mov dx,0F879h
    push dx
    push ax
    mov ax,1F80h
    mov dx,786h
    push dx
    push ax
    push word ptr [bp-2h]
    push word ptr [bp-4h]
    call mf27
    mov si,ax
    cwd
    push dx
    push ax
    call mf32
    add word ptr [bp-4h],ax
    adc word ptr [bp-2h],dx
    mov ax,si
    add ax,ax
    add ax,ax
    add ax, offset mi38
    mov si,ax
    cmp word ptr [bp-2h],1E1h
    jl short lblBFf
    jg short lbl70f
    cmp word ptr [bp-4h],3380h
    jc short lblBFf
lbl70f:
    inc si
    sub word ptr [bp-4h],3380h
    sbb word ptr [bp-2h],1E1h
    cmp word ptr [bp-2h],1E1h
    jl short lblBFf
    jg short lbl8Bf
    cmp word ptr [bp-4h],3380h
    jc short lblBFf
lbl8Bf:
    inc si
    mov ax,word ptr [bp-4h]
    mov dx,word ptr [bp-2h]
    sub ax,3380h
    sbb dx,1E1h
    mov word ptr [bp-4h],ax
    mov word ptr [bp-2h],dx
    cmp dx,1E2h
    jl short lblBCf
    jg short lblACf
    cmp ax,8500h
    jc short lblBCf
lblACf:
    inc si
    sub ax,8500h
    sbb dx,1E2h
    mov word ptr [bp-4h],ax
    mov word ptr [bp-2h],dx
    jmp short lblBFf
lblBCf:
    inc word ptr [bp-6h]
lblBFf:
    mov word ptr [di+0Ah],si
    mov ax,5180h
    mov dx,1h
    push dx
    push ax
    push word ptr [bp-2h]
    push word ptr [bp-4h]
    call mf79
    mov word ptr [di+0Eh],ax
    mov cx,0AE80h
    mov dx,0FFFEh
    push dx
    push cx
    cwd
    push dx
    push ax
    call mf88
    add word ptr [bp-4h],ax
    adc word ptr [bp-2h],dx
    cmp word ptr [bp-6h],0h
    jz short lblFCf
    mov word ptr [bp-0Ah],57A6h
    jmp short lbl101f
    nop
lblFCf:
    mov word ptr [bp-0Ah],57C0h
lbl101f:
    mov word ptr [bp-8h],ds
    mov si,1h
    jmp short lbl10Bf
    nop
lbl10Ab:
    inc si
lbl10Bf:
    mov ax,word ptr [di+0Eh]
    mov bx,si
    add bx,si
    add bx,word ptr [bp-0Ah]
    mov es, [bp-8h]
    cmp word ptr es:[bx],ax
    jl short lbl10Ab
    dec si
    mov word ptr [di+8h],si
    mov bx,si
    add bx,si
    add bx,word ptr [bp-0Ah]
    sub ax,word ptr es:[bx]
    mov word ptr [di+6h],ax
    mov ax,5180h
    mov dx,1h
    push dx
    push ax
    les bx, dword ptr [bp+6h]
    push word ptr es:[bx+2h]
    push word ptr es:[bx]
    call mf123
    add ax, offset mi124
    mov cx,7h
    cwd
    idiv cx
    mov word ptr [di+0Ch],dx
    mov ax,0E10h
    cwd
    push dx
    push ax
    push word ptr [bp-2h]
    push word ptr [bp-4h]
    call mf135
    mov word ptr [di+4h],ax
    mov cx,3Ch
    xor dx,dx
    push dx
    push cx
    mov cx,0F1F0h
    imul cx
    add word ptr [bp-4h],ax
    adc word ptr [bp-2h],dx
    mov ax,word ptr [bp-4h]
    mov dx,word ptr [bp-2h]
    push dx
    push ax
    call mf149
    mov word ptr [di+2h],ax
    mov cx,0FFC4h
    imul cx
    add ax,word ptr [bp-4h]
    mov word ptr [di],ax
    mov word ptr [di+10h],0h
    mov ax,di
    mov dx,ds
lbl19Af:
    pop si
    pop di
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
