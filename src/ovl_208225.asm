_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi5:NEAR
    EXTRN mi14:NEAR
    EXTRN mf28:FAR
    EXTRN mf36:FAR
    EXTRN mf42:FAR
    EXTRN mf49:FAR
    EXTRN mf59:FAR
    EXTRN mf66:FAR
    EXTRN mf74:FAR
    EXTRN mf80:FAR
    EXTRN mf87:FAR
    EXTRN mf95:FAR
    EXTRN mf101:FAR
    EXTRN mi106:NEAR
    EXTRN mf121:FAR
    EXTRN mf132:FAR
    EXTRN mf137:FAR
    EXTRN mf145:FAR
    EXTRN mf163:FAR
    EXTRN mf171:FAR
    EXTRN mf175:FAR
    EXTRN mf183:FAR
    EXTRN mf190:FAR
    EXTRN mf190:FAR
    EXTRN mf190:FAR
    EXTRN mf190:FAR
    EXTRN mf190:FAR
    EXTRN mf190:FAR
    EXTRN mf190:FAR
    EXTRN mf190:FAR
    EXTRN mf190:FAR
    EXTRN mf190:FAR
    EXTRN mf190:FAR
    EXTRN mf190:FAR
    EXTRN mf190:FAR
    EXTRN mf190:FAR
    EXTRN mf190:FAR
    EXTRN mf190:FAR
    EXTRN mf190:FAR
    EXTRN mf190:FAR
    EXTRN mf190:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,6h
    mov word ptr [bp-2h],0h
    mov ax,word ptr [bp+6h]
    sub ax, offset mi5
    jz short lbl1Ef
    dec ax
    dec ax
    jnz short lbl1Af
    jmp near ptr lbl11Cf
lbl1Af:
    jmp near ptr lbl1EEf
    nop
lbl1Ef:
    mov ax,word ptr ds:[6A06h]
    sub ax, offset mi14
    jz short lbl29f
    jmp near ptr lbl1EEf
lbl29f:
    cmp word ptr ds:[6A04h],121h
    jnz short lbl34f
    jmp near ptr lblCEf
lbl34f:
    cmp word ptr ds:[6A04h],122h
    jnz short lbl3Ff
    jmp near ptr lblCEf
lbl3Ff:
    cmp word ptr ds:[6A04h],123h
    jnz short lbl6Cf
    push word ptr ds:[6A04h]
    mov ax,2h
    push ax
    call mf28
    add sp,4h
    push dx
    push ax
    mov ax,59h
lbl5Cb:
    mov dx,0F025h
    push dx
    push ax
    call mf36
    add sp,8h
    jmp near ptr lbl116f
lbl6Cf:
    mov ax,1h
    push ax
    push word ptr ds:[6A04h]
    call mf42
    add sp,4h
    or ax,ax
    jz short lbl98f
    push word ptr ds:[6A04h]
    mov ax,2h
    push ax
    call mf49
    add sp,4h
    push dx
    push ax
    mov ax,53h
    jmp short lbl5Cb
    nop
lbl98f:
    push word ptr ds:[6A02h]
    mov ax,2h
    push ax
    call mf59
    add sp,4h
    push dx
    push ax
    push word ptr ds:[6A04h]
    mov ax,2h
    push ax
    call mf66
    add sp,4h
    push dx
    push ax
    mov ax,54h
    mov dx,0F025h
    push dx
    push ax
    call mf74
    add sp,0Ch
    jmp short lbl116f
lblCEf:
    push word ptr ds:[6A02h]
    mov ax,22h
    push ax
    call mf80
    add sp,4h
    push dx
    push ax
    push word ptr ds:[6A04h]
    mov ax,2h
    push ax
    call mf87
    add sp,4h
    push dx
    push ax
    mov ax,51h
    mov dx,0F025h
    push dx
    push ax
    call mf95
    add sp,0Ch
    mov ax,1h
    push ax
    push word ptr ds:[6A02h]
    push word ptr ds:[6A04h]
    call mf101
    add sp,6h
lbl116b:
lbl116f:
    mov ax,1h
    jmp near ptr lbl1F0f
lbl11Cf:
    mov ax,word ptr ds:[6A06h]
    cmp ax, offset mi106
    jnz short lbl127f
    jmp near ptr lbl1DAf
lbl127f:
    jna short lbl12Cf
    jmp near ptr lbl1EEf
lbl12Cf:
    sub al,8h
    jz short lbl13Bf
    sub al,0Bh
    jz short lbl154f
    sub al,19h
    jz short lbl13Bf
    jmp near ptr lbl1EEf
lbl13Bf:
    push word ptr ds:[6A04h]
    mov ax,22h
    push ax
    call mf121
    add sp,4h
    push dx
    push ax
    mov ax,57h
    jmp near ptr lbl5Cb
    nop
lbl154f:
    mov ax,55h
    mov dx,0F025h
    push dx
    push ax
    call mf132
    add sp,4h
    push word ptr ds:[6A04h]
    mov ax,122h
    push ax
    call mf137
    add sp,4h
    or ax,ax
    jz short lbl17Df
    mov word ptr [bp-2h],1h
lbl17Df:
    push word ptr ds:[6A04h]
    mov ax,121h
    push ax
    call mf145
    add sp,4h
    or ax,ax
    jz short lbl194f
    inc word ptr [bp-2h]
lbl194f:
    cmp word ptr [bp-2h],0h
    jz short lbl1CAf
    cmp word ptr [bp-2h],1h
    jnz short lbl1A6f
    xor ax,ax
    cwd
    jmp short lbl1ABf
    nop
lbl1A6f:
    mov ax,31FAh
    mov dx,ds
lbl1ABf:
    push dx
    push ax
    push word ptr [bp-2h]
    call mf163
    add sp,2h
    push dx
    push ax
    mov ax,56h
    mov dx,0F025h
    push dx
    push ax
    call mf171
    add sp,0Ch
lbl1CAf:
    mov ax,2Eh
    push ax
    call mf175
    add sp,2h
    jmp near ptr lbl116b
    nop
lbl1DAf:
    mov ax,58h
    mov dx,0F025h
    push dx
    push ax
    call mf183
    add sp,4h
    jmp near ptr lbl116b
    nop
lbl1EEf:
    xor ax,ax
lbl1F0f:
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
