_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi4:NEAR
    EXTRN mi5:NEAR
    EXTRN mf27:FAR
    EXTRN mf47:FAR
    EXTRN mf60:FAR
    EXTRN mf71:FAR
    EXTRN mf77:FAR
    EXTRN mf96:FAR
    EXTRN mf102:FAR
    EXTRN mf144:FAR
    EXTRN mf147:FAR
    EXTRN mf148:FAR
    EXTRN mf154:FAR
    EXTRN mf155:FAR
    EXTRN mf165:FAR
    EXTRN mf174:FAR
    EXTRN mf184:FAR
    EXTRN mf188:FAR
    EXTRN mf188:FAR
    EXTRN mf188:FAR
    EXTRN mf188:FAR
    EXTRN mf188:FAR
    EXTRN mf188:FAR
    EXTRN mf188:FAR
    EXTRN mf188:FAR
    EXTRN mf188:FAR
    EXTRN mf188:FAR
    EXTRN mf188:FAR
    EXTRN mf188:FAR
    EXTRN mf188:FAR
    EXTRN mf188:FAR
    EXTRN mf188:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,6h
    mov ax,word ptr [bp+6h]
    sub ax, offset mi4
    cmp ax, offset mi5
    jna short lbl14f
    jmp near ptr lbl1DDf
lbl14f:
    add ax,ax
    xchg ax,bx
    jmp word ptr cs:[bx+44Ah]
    insb
    add al,2Ah
    add ax,52Ah
    sub al,byte ptr [di]
    or ax,word ptr ds:[60Bh]
    or ax,word ptr ds:[5A0h]
    or ax,word ptr ds:[60Bh]
    or ax,word ptr ds:[60Bh]
    or ax,word ptr ds:[60Bh]
    mov dl,5h
    cli
    add ax,5A0h
    mov ax,0Ah
    push ax
    mov ax,174h
    push ax
    call mf27
    add sp,4h
    mov ax,word ptr ds:[2DAh]
    or ax,ax
    jz short lbl6Af
    dec ax
    jnl short lbl5Bf
    jmp near ptr lbl1DDf
lbl5Bf:
    jno short lbl60f
    jmp near ptr lbl1DDf
lbl60f:
    dec ax
    jng short lbl7Af
    dec ax
    jz short lbl90f
    jmp near ptr lbl1DDf
    nop
lbl6Af:
    mov ax,4h
    mov dx,0F040h
    push dx
    push ax
    call mf47
    add sp,4h
lbl7Af:
    cmp byte ptr ds:[6E5Ch],9h
    jz short lblCEf
    cmp word ptr ds:[2DAh],0h
    jz short lblCEf
    mov word ptr [bp-6h],3711h
    jmp short lblD3f
    nop
lbl90f:
    mov ax,175h
    push ax
    mov ax,177h
    push ax
    call mf60
    add sp,4h
    or ax,ax
    jz short lblAAf
    mov ax,6h
    jmp short lblADf
    nop
lblAAf:
    mov ax,7h
lblADf:
    mov dx,0F040h
    push dx
    push ax
    call mf71
    add sp,4h
    mov ax,8h
    mov dx,0F040h
    push dx
    push ax
    call mf77
    add sp,4h
    jmp near ptr lbl1DDf
    nop
lblCEf:
    mov word ptr [bp-6h],370Eh
lblD3f:
    cmp byte ptr ds:[6E5Ch],9h
    jnz short lblE0f
    mov ax,3704h
    jmp short lblE3f
    nop
lblE0f:
    mov ax,3709h
lblE3f:
    push ds
    push ax
    push ds
    push word ptr [bp-6h]
    mov ax,5h
    mov dx,0F040h
    push dx
    push ax
    call mf96
    add sp,0Ch
    jmp near ptr lbl1DDf
    mov ax,36D3h
    push ds
    push ax
    call mf102
    add sp,4h
    mov ax,word ptr ds:[2DAh]
    or ax,ax
    jz short lbl11Cf
    dec ax
    jz short lbl124f
    dec ax
    jz short lbl13Ef
    dec ax
    jz short lbl152f
    jmp short lbl15Af
    nop
lbl11Cf:
    mov word ptr [bp-4h],36DBh
    jmp short lbl157f
    nop
lbl124f:
    cmp byte ptr ds:[6E5Ch],9h
    jnz short lbl130f
    xor ax,ax
    jmp short lbl133f
    nop
lbl130f:
    mov ax,1h
lbl133b:
lbl133f:
    mov dx,0F040h
lbl136b:
    mov word ptr [bp-4h],ax
    mov word ptr [bp-2h],dx
    jmp short lbl15Af
lbl13Ef:
    cmp byte ptr ds:[6E5Ch],9h
    jnz short lbl14Cf
    mov ax,36E9h
    mov dx,ds
    jmp short lbl136b
lbl14Cf:
    mov ax,2h
    jmp short lbl133b
    nop
lbl152f:
    mov word ptr [bp-4h],36F9h
lbl157f:
    mov word ptr [bp-2h],ds
lbl15Af:
    push word ptr [bp-2h]
    push word ptr [bp-4h]
    mov ax,3h
    mov dx,0F040h
    push dx
    push ax
    call mf144
    add sp,8h
    jmp short lbl1DDf
    call mf147
    call mf148
    mov byte ptr ds:[36D2h],0h
    jmp short lbl1DDf
    nop
    cmp byte ptr ds:[36D2h],0h
    jnz short lbl1B5f
    call mf154
    call mf155
    cmp word ptr ds:[2DAh],3h
    jnz short lbl1B0f
    xor ax,ax
    push ax
    push ax
    mov ax,15h
    push ax
    mov ax,0FCDh
    push ax
    call mf165
    add sp,8h
lbl1B0f:
    mov byte ptr ds:[36D2h],1h
lbl1B5f:
    mov ax,4h
    push ax
    mov ax,0h
    mov cx,32C1h
    push cx
    push ax
    call mf174
    add sp,6h
    jmp short lbl1DFf
    nop
    mov ax,2h
    push ax
    mov ax,30h
    mov cx,32C1h
    push cx
    push ax
    call mf184
lbl1DDf:
    xor ax,ax
lbl1DFf:
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
