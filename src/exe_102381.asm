_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf13:FAR
    EXTRN mf21:FAR
    EXTRN mf31:FAR
    EXTRN mf78:FAR
    EXTRN mf81:FAR
    EXTRN mf85:FAR
    EXTRN mf105:FAR
    EXTRN mf116:FAR
    EXTRN mf128:FAR
    EXTRN mf128:FAR
    EXTRN mf128:FAR
    EXTRN mf128:FAR
    EXTRN mf128:FAR
    EXTRN mf128:FAR
    EXTRN mf128:FAR
    EXTRN mf128:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,2h
    push di
    push si
    mov al,byte ptr [bp+7h]
    sub ah,ah
    mov word ptr [bp-2h],ax
    cmp ax,word ptr ds:[4F50h]
    jz short lbl61f
    cmp word ptr ds:[4F44h],0h
    jz short lbl2Ff
    push word ptr ds:[4F44h]
    call mf13
    add sp,2h
    mov word ptr ds:[4F44h],0h
lbl2Ff:
    mov ax,word ptr [bp-2h]
    mov word ptr ds:[4F50h],ax
    push ax
    xor ax,ax
    push ax
    call mf21
    add sp,4h
    mov word ptr ds:[4F44h],ax
    or ax,ax
    jnz short lbl52f
    mov word ptr ds:[4F50h],0FFFFh
    jmp near ptr lbl15Af
    nop
lbl52f:
    push word ptr [bp+6h]
    push word ptr ds:[4F50h]
    call mf31
    add sp,4h
lbl61f:
    mov al,byte ptr [bp+6h]
    sub ah,ah
    mov cx,ax
    add ax,ax
    add ax,cx
    add ax,ax
    add ax,ax
    add ax,word ptr ds:[67B6h]
    mov dx,word ptr ds:[67B8h]
    push ds
    mov di,6E04h
    mov si,ax
    push ds
    pop es
    mov ds,dx
    mov cx,6h
    rep movsw
    pop ds
    mov ax,word ptr ds:[6E06h]
    or ax,word ptr ds:[6E04h]
    jnz short lbl94f
    jmp near ptr lbl15Af
lbl94f:
    cmp word ptr ds:[4F56h],0h
    jz short lblA5f
    test byte ptr ds:[6E09h],10h
    jz short lblA5f
    jmp near ptr lbl15Af
lblA5f:
    mov al,byte ptr ds:[6E08h]
    cbw
    cmp ax,word ptr [bp+8h]
    jnl short lblB2f
    cbw
    mov word ptr [bp+8h],ax
lblB2f:
    cmp word ptr [bp+8h],0h
    jng short lblF4f
    mov ax,word ptr [bp+8h]
    dec ax
    add ax,ax
    add ax,ax
    cwd
    add ax,word ptr ds:[6E04h]
    adc dx,word ptr ds:[6E06h]
    push dx
    push ax
    push word ptr ds:[4F44h]
    call mf78
    add sp,6h
    push word ptr ds:[4F44h]
    call mf81
    add sp,2h
    mov word ptr ds:[4F52h],ax
    push word ptr ds:[4F44h]
    call mf85
    add sp,2h
    jmp short lblF9f
lblF4f:
    xor ax,ax
    mov word ptr ds:[4F52h],ax
lblF9f:
    mov word ptr ds:[4F54h],ax
    cmp word ptr ds:[4F58h],0h
    jz short lbl108f
lbl103b:
    mov ax,1h
    jmp short lbl15Cf
lbl108f:
    mov al,byte ptr ds:[6E08h]
    cbw
    add ax,ax
    add ax,ax
    cwd
    add ax,word ptr ds:[6E04h]
    adc dx,word ptr ds:[6E06h]
    push dx
    push ax
    push word ptr ds:[4F44h]
    call mf105
    add sp,6h
    test byte ptr ds:[6E09h],10h
    jz short lbl14Cf
    mov ax,300h
    push ax
    mov ax,6A24h
    mov cx,38AFh
    push cx
    push ax
    push word ptr ds:[4F44h]
    call mf116
    add sp,8h
    mov word ptr ds:[4F4Eh],1h
lbl14Cf:
    cmp word ptr ds:[6E0Ah],0h
    jz short lbl15Af
    cmp word ptr ds:[6E0Ch],0h
    jnz short lbl103b
lbl15Af:
    xor ax,ax
lbl15Cf:
    pop si
    pop di
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
