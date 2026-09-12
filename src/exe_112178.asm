_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi94:NEAR
    EXTRN mf149:FAR
    EXTRN mf177:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,1Ch
    push si
    mov ax,word ptr [bp+8h]
    or ax,word ptr [bp+6h]
    jnz short lbl12f
    jmp near ptr lbl1C3f
lbl12f:
    mov ax,word ptr [bp+0Ah]
    les bx, dword ptr [bp+6h]
    cmp word ptr es:[bx+2h],ax
    jng short lbl21f
    jmp near ptr lbl1C3f
lbl21f:
    cmp word ptr es:[bx+6h],ax
    jnl short lbl2Af
    jmp near ptr lbl1C3f
lbl2Af:
    mov ax,word ptr [bp+0Ch]
    cmp word ptr es:[bx+4h],ax
    jng short lbl36f
    jmp near ptr lbl1C3f
lbl36f:
    cmp word ptr es:[bx+8h],ax
    jnl short lbl3Ff
    jmp near ptr lbl1C3f
lbl3Ff:
    cmp byte ptr es:[bx],3h
    jz short lbl48f
    jmp near ptr lblCCf
lbl48f:
    cmp word ptr es:[bx+0Eh],0h
    jz short lblCCf
    mov ax,word ptr es:[bx+0Eh]
    mov word ptr [bp-0Ch],ax
    mov cx,ax
    dec ax
    mov word ptr [bp-4h],ax
    xor ax,ax
    mov word ptr [bp-8h],ax
    mov word ptr [bp-0Ah],ax
    mov word ptr [bp-2h],ax
    cmp cx,ax
    jg short lbl6Ef
    jmp near ptr lbl1B4f
lbl6Ef:
    mov ax,word ptr es:[bx+10h]
    mov dx,word ptr es:[bx+12h]
    mov word ptr [bp-1Ch],ax
    mov word ptr [bp-1Ah],dx
lbl7Cb:
    les bx, dword ptr [bp+6h]
    les bx, dword ptr es:[bx+10h]
    mov si,word ptr [bp-4h]
    add si,si
    add si,si
    mov ax,word ptr es:[bx+si]
    add bx,si
    mov word ptr [bp-0Eh],ax
    mov ax,word ptr es:[bx+2h]
    mov word ptr [bp-10h],ax
    les bx, dword ptr [bp-1Ch]
    mov cx,word ptr es:[bx]
    mov word ptr [bp-12h],cx
    mov cx,word ptr es:[bx+2h]
    cmp ax,word ptr [bp+0Ch]
    jnz short lblD4f
    cmp cx,ax
    jnz short lblD4f
    mov ax,word ptr [bp+0Ah]
    cmp word ptr [bp-0Eh],ax
    jg short lblBCf
    cmp word ptr [bp-12h],ax
    jnl short lblCCf
lblBCf:
    cmp word ptr [bp-12h],ax
    jng short lblC4f
    jmp near ptr lbl19Cf
lblC4f:
    cmp word ptr [bp-0Eh],ax
    jnl short lblCCf
    jmp near ptr lbl19Cf
lblCCb:
lblCCf:
    mov ax,1h
    jmp near ptr lbl1C5f
    nop
    nop
lblD4f:
    mov ax,word ptr [bp+0Ch]
    cmp cx,ax
    jnz short lbl154f
    mov ax,word ptr [bp-2h]
    inc ax
    cwd
    idiv word ptr [bp-0Ch]
    mov si,dx
    add si,dx
    add si,si
    les bx, dword ptr [bp+6h]
    les bx, dword ptr es:[bx+10h]
    mov ax,word ptr es:[bx+si+2h]
    mov word ptr [bp-16h],ax
    cmp ax,cx
    jnz short lbl134f
    mov ax,word ptr [bp-2h]
    add ax, offset mi94
    cwd
    idiv word ptr [bp-0Ch]
    mov si,dx
    add si,dx
    add si,si
    les bx, dword ptr [bp+6h]
    les bx, dword ptr es:[bx+10h]
    mov ax,word ptr es:[bx+si+2h]
    mov word ptr [bp-18h],ax
    mov ax,word ptr [bp-10h]
    cmp cx,ax
    jnl short lbl125f
    cmp word ptr [bp-18h],cx
    jg short lbl19Cf
lbl125f:
    mov ax,word ptr [bp-10h]
    cmp cx,ax
    jng short lbl14Cf
    cmp word ptr [bp-18h],cx
    jnl short lbl14Cf
    jmp short lbl19Cf
    nop
lbl134f:
    mov ax,word ptr [bp-10h]
    cmp cx,ax
    jnl short lbl140f
    cmp word ptr [bp-16h],cx
    jg short lbl19Cf
lbl140f:
    mov ax,word ptr [bp-10h]
    cmp cx,ax
    jng short lbl14Cf
    cmp word ptr [bp-16h],cx
    jl short lbl19Cf
lbl14Cf:
    mov ax,word ptr [bp-12h]
    sub ax,word ptr [bp+0Ah]
    jmp short lbl189f
lbl154f:
    cmp word ptr [bp-10h],ax
    jnl short lbl15Df
    cmp cx,ax
    jg short lbl166f
lbl15Df:
    cmp cx,ax
    jnl short lbl19Cf
    cmp word ptr [bp-10h],ax
    jng short lbl19Cf
lbl166f:
    mov ax,cx
    sub ax,word ptr [bp-10h]
    cwd
    push dx
    push ax
    mov ax,word ptr [bp-12h]
    sub ax,word ptr [bp-0Eh]
    mov cx,word ptr [bp+0Ch]
    sub cx,word ptr [bp-10h]
    imul cx
    push dx
    push ax
    call mf149
    sub ax,word ptr [bp+0Ah]
    add ax,word ptr [bp-0Eh]
lbl189f:
    or ax,ax
    jnl short lbl192f
    inc word ptr [bp-8h]
    jmp short lbl19Cf
lbl192f:
    or ax,ax
    jg short lbl199f
    jmp near ptr lblCCb
lbl199f:
    inc word ptr [bp-0Ah]
lbl19Cf:
    mov ax,word ptr [bp-2h]
    mov word ptr [bp-4h],ax
    add word ptr [bp-1Ch],4h
    mov ax,word ptr [bp-0Ch]
    inc word ptr [bp-2h]
    cmp word ptr [bp-2h],ax
    jnl short lbl1B4f
    jmp near ptr lbl7Cb
lbl1B4f:
    test byte ptr [bp-8h],1h
    jz short lbl1C3f
    test byte ptr [bp-0Ah],1h
    jz short lbl1C3f
    jmp near ptr lblCCb
lbl1C3f:
    xor ax,ax
lbl1C5f:
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
