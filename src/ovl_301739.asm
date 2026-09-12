_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi4:NEAR
    EXTRN mi12:NEAR
    EXTRN mf20:FAR
    EXTRN mf28:FAR
    EXTRN mf38:FAR
    EXTRN mf45:FAR
    EXTRN mf52:FAR
    EXTRN mf60:FAR
    EXTRN mi65:NEAR
    EXTRN mf93:FAR
    EXTRN mf104:FAR
    EXTRN mf110:FAR
    EXTRN mf130:FAR
    EXTRN mf139:FAR
    EXTRN mf146:FAR
    EXTRN mf159:FAR
    EXTRN mf172:FAR
    EXTRN mf183:FAR
    EXTRN mf183:FAR
    EXTRN mf183:FAR
    EXTRN mf183:FAR
    EXTRN mf183:FAR
    EXTRN mf183:FAR
    EXTRN mf183:FAR
    EXTRN mf183:FAR
    EXTRN mf183:FAR
    EXTRN mf183:FAR
    EXTRN mf183:FAR
    EXTRN mf183:FAR
    EXTRN mf183:FAR
    EXTRN mf183:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,4h
    mov ax,word ptr [bp+6h]
    sub ax, offset mi4
    jz short lbl18f
    dec ax
    dec ax
    jnz short lbl15f
    jmp near ptr lblAAf
lbl15f:
    jmp near ptr lbl1F0f
lbl18f:
    mov ax,word ptr ds:[6A06h]
    sub ax, offset mi12
    jz short lbl23f
    jmp near ptr lbl1F0f
lbl23f:
    cmp word ptr ds:[256h],19Ah
    jz short lbl50f
    push word ptr ds:[6A02h]
    mov ax,2h
    push ax
    call mf20
    add sp,4h
    push dx
    push ax
    mov ax,11h
lbl40b:
    mov dx,0F047h
    push dx
    push ax
    call mf28
    add sp,8h
    jmp short lblA4f
    nop
lbl50f:
    cmp word ptr ds:[6A04h],124h
    jnz short lbl70f
    push word ptr ds:[6A02h]
    push word ptr ds:[6A04h]
    mov ax,4Fh
lbl63b:
    push ax
    call mf38
    add sp,6h
    jmp near ptr lbl1F2f
    nop
lbl70f:
    push word ptr ds:[6A02h]
    mov ax,2h
    push ax
    call mf45
    add sp,4h
    push dx
    push ax
    push word ptr ds:[6A04h]
    mov ax,2h
    push ax
    call mf52
    add sp,4h
    push dx
    push ax
    mov ax,12h
    mov dx,0F047h
    push dx
    push ax
    call mf60
    add sp,0Ch
lblA4b:
lblA4f:
    mov ax,1h
    jmp near ptr lbl1F2f
lblAAf:
    mov ax,word ptr ds:[6A06h]
    cmp ax, offset mi65
    jnz short lblB5f
    jmp near ptr lbl1CAf
lblB5f:
    jna short lblBAf
    jmp near ptr lbl1F0f
lblBAf:
    sub al,8h
    jz short lblD4f
    sub al,0Bh
    jz short lbl116f
    sub al,19h
    jnz short lblC9f
    jmp near ptr lbl150f
lblC9f:
    sub al,18h
    jnz short lblD0f
    jmp near ptr lbl1A2f
lblD0f:
    jmp near ptr lbl1F0f
    nop
lblD4f:
    cmp word ptr ds:[256h],19Ah
    jz short lblEAf
    xor ax,ax
    push ax
    push word ptr ds:[6A04h]
    mov ax,2Ch
    jmp near ptr lbl63b
    nop
lblEAf:
    mov ax,0Eh
    push ax
    push word ptr ds:[6A04h]
    call mf93
    add sp,4h
    or ax,ax
    jnz short lbl104f
    mov ax,0Dh
    jmp short lbl107f
    nop
lbl104f:
    mov ax,0Eh
lbl107b:
lbl107f:
    mov dx,0F047h
    push dx
    push ax
    call mf104
    add sp,4h
    jmp short lblA4b
lbl116f:
    mov ax,0Eh
    push ax
    push word ptr ds:[6A04h]
    call mf110
    add sp,4h
    or ax,ax
    jz short lbl13Af
    cmp word ptr ds:[256h],19Ah
    jnz short lbl13Af
    mov word ptr [bp-4h],6h
    jmp short lbl13Ff
    nop
lbl13Af:
    mov word ptr [bp-4h],7h
lbl13Ff:
    mov word ptr [bp-2h],0F047h
    push word ptr [bp-2h]
    push word ptr [bp-4h]
    mov ax,5h
    jmp near ptr lbl40b
lbl150f:
    cmp word ptr ds:[256h],19Ah
    jz short lbl170f
lbl158b:
    push word ptr ds:[6A04h]
    mov ax,2h
    push ax
    call mf130
    add sp,4h
    push dx
    push ax
    mov ax,8h
    jmp near ptr lbl40b
lbl170f:
    mov ax,0Eh
    push ax
    push word ptr ds:[6A04h]
    call mf139
    add sp,4h
    or ax,ax
    jz short lbl19Cf
    push word ptr ds:[6A04h]
    mov ax,12h
    push ax
    call mf146
    add sp,4h
    push dx
    push ax
    mov ax,0Bh
    jmp near ptr lbl40b
lbl19Cf:
    mov ax,0Ch
    jmp near ptr lbl107b
lbl1A2f:
    cmp word ptr ds:[256h],19Ah
    jnz short lbl158b
    mov ax,0Eh
    push ax
    push word ptr ds:[6A04h]
    call mf159
    add sp,4h
    or ax,ax
    jz short lbl1C4f
    mov ax,9h
    jmp near ptr lbl107b
lbl1C4f:
    mov ax,0Ah
    jmp near ptr lbl107b
lbl1CAf:
    cmp word ptr ds:[256h],19Ah
    jz short lbl1EAf
    push word ptr ds:[6A04h]
    mov ax,12h
    push ax
    call mf172
    add sp,4h
    push dx
    push ax
    mov ax,0Fh
    jmp near ptr lbl40b
lbl1EAf:
    mov ax,10h
    jmp near ptr lbl107b
lbl1F0f:
    xor ax,ax
lbl1F2f:
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
