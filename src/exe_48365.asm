_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi33:NEAR
    EXTRN mf66:FAR
    EXTRN mi79:NEAR
    EXTRN mf84:FAR
    EXTRN mi94:NEAR
    EXTRN mf109:FAR
    EXTRN mf109:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,18h
    push si
    cmp word ptr ds:[0F2h],0h
    jnz short lbl11f
    jmp near ptr lbl12Af
lbl11f:
    mov word ptr [bp-2h],0FFFFh
    xor ax,ax
    mov word ptr [bp-6h],ax
    mov word ptr [bp-4h],ax
    cmp word ptr ds:[0F2h],ax
    jz short lbl50f
    mov word ptr [bp-12h],6h
lbl29b:
    mov bx,word ptr [bp-12h]
    mov es, ds:[5A2Ah]
    mov ax,word ptr es:[bx]
    cmp ax,word ptr [bp-6h]
    jna short lbl41f
    mov word ptr [bp-6h],ax
    mov ax,word ptr [bp-4h]
    mov word ptr [bp-2h],ax
lbl41f:
    add word ptr [bp-12h],8h
    mov ax,word ptr ds:[0F2h]
    inc word ptr [bp-4h]
    cmp word ptr [bp-4h],ax
    jc short lbl29b
lbl50f:
    cmp word ptr [bp-2h],0h
    jnl short lbl59f
    jmp near ptr lbl12Af
lbl59f:
    mov cl,3h
    mov ax,word ptr [bp-2h]
    shl ax,cl
    add ax, offset mi33
    mov cx,21AAh
    mov word ptr [bp-10h],ax
    mov word ptr [bp-0Eh],cx
    mov bx,ax
    mov es,cx
    mov dx,word ptr es:[bx+4h]
    mov word ptr [bp-0Ah],dx
    mov word ptr [bp-8h],0h
    mov bx,dx
    les si, dword ptr ds:[5C3Eh]
    cmp byte ptr es:[bx+si],0h
    jz short lbl9Bf
lbl88b:
    mov bx,word ptr ds:[5C3Eh]
    add bx,word ptr [bp-0Ah]
    inc word ptr [bp-8h]
    mov si,word ptr [bp-8h]
    cmp byte ptr es:[bx+si],0h
    jnz short lbl88b
lbl9Bf:
    mov ax,word ptr ds:[5C44h]
    inc word ptr [bp-8h]
    sub ax,word ptr [bp-8h]
    sub ax,word ptr [bp-0Ah]
    jz short lblC1f
    push ax
    mov ax,word ptr ds:[5C3Eh]
    add ax,word ptr [bp-0Ah]
    mov cx,ax
    add ax,word ptr [bp-8h]
    push es
    push ax
    push es
    push cx
    call mf66
    add sp,0Ah
lblC1f:
    mov ax,word ptr [bp-8h]
    sub word ptr ds:[5C44h],ax
    mov ax,word ptr ds:[0F2h]
    sub ax,word ptr [bp-2h]
    dec ax
    jz short lblEDf
    mov cl,3h
    shl ax,cl
    push ax
    mov ax,word ptr [bp-10h]
    mov dx,word ptr [bp-0Eh]
    add ax, offset mi79
    push dx
    push ax
    push dx
    push word ptr [bp-10h]
    call mf84
    add sp,0Ah
lblEDf:
    inc word ptr ds:[0FEh]
    mov ax,word ptr [bp-2h]
    mov word ptr [bp-4h],ax
    dec word ptr ds:[0F2h]
    cmp word ptr ds:[0F2h],ax
    jna short lbl12Af
    mov cl,3h
    shl ax,cl
    add ax, offset mi94
    mov word ptr [bp-14h],ax
    mov ax,word ptr ds:[0F2h]
    sub ax,word ptr [bp-4h]
    mov word ptr [bp-16h],ax
    mov es, ds:[5A2Ah]
lbl118b:
    mov ax,word ptr [bp-8h]
    mov bx,word ptr [bp-14h]
    sub word ptr es:[bx],ax
    add word ptr [bp-14h],8h
    dec word ptr [bp-16h]
    jnz short lbl118b
lbl12Af:
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
