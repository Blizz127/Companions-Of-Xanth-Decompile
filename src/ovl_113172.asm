_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi6:NEAR
    EXTRN mf19f:FAR
    EXTRN mf255:FAR
    EXTRN mf163:FAR
    EXTRN mf1cd:FAR
    EXTRN mf114:FAR
    EXTRN mf1d9:FAR
    EXTRN mf147:FAR
    EXTRN mi9:NEAR
    EXTRN mf23c:FAR
    EXTRN mf44:FAR
    EXTRN mf99:FAR
    EXTRN mf206:FAR
    EXTRN mfa8:FAR
    EXTRN mf21f:FAR
    EXTRN mf18f:FAR
    EXTRN mfbe:FAR
    EXTRN mf1ba:FAR
    EXTRN mf157:FAR
    EXTRN mf17b:FAR
    EXTRN mf20b:FAR
    EXTRN mf12b:FAR
    EXTRN mf7a:FAR
    EXTRN mf26c:FAR
    EXTRN mf224:FAR
    EXTRN mf13b:FAR
    EXTRN mf1e1:FAR
    EXTRN mfe2:FAR
    EXTRN mf1ee:FAR
    EXTRN mf1fe:FAR
mnem_unit:
    push bp
    mov bp,sp
    mov ax,word ptr [bp+6h]
    sub ax, offset mi6
    cmp ax, offset mi9
    jna short lbl11f
    jmp near ptr lbl271f
lbl11f:
    add ax,ax
    xchg ax,bx
    jmp word ptr cs:[bx+9Eh]
    nop
    db 0C0h, 00h, 4Ch, 01h, 4Ch, 01h, 4Ch, 01h, 0F5h, 02h, 62h, 01h, 7Ch, 01h, 8Ah, 02h
    db 0F5h, 02h, 0F5h, 02h, 0F5h, 02h, 0F5h, 02h, 0F5h, 02h, 0F5h, 02h, 9Ch, 02h, 0E4h, 02h
    db 8Ah, 02h
    mov ax,80h
    push ax
    mov ax,3h
    push ax
    call mf44
    mov sp,bp
    or ax,ax
    jz short lbl58f
    mov ax,3h
    mov dx,0F00Ch
    jmp short lbl5Bf
    nop
lbl58f:
    xor ax,ax
    cwd
lbl5Bf:
    push dx
    push ax
    cmp word ptr ds:[2A6h],2h
    jl short lbl6Af
    xor ax,ax
    cwd
    jmp short lbl70f
    nop
lbl6Af:
    mov ax,2h
    mov dx,0F00Ch
lbl70f:
    push dx
    push ax
    mov ax,0Eh
    push ax
    mov ax,83h
    push ax
    call mf7a
    add sp,4h
    or ax,ax
    jz short lbl8Cf
    mov ax,25ABh
    jmp short lbl8Ff
    nop
lbl8Cf:
    mov ax,25B2h
lbl8Ff:
    push ds
    push ax
    mov ax,1h
    mov dx,0F00Ch
    push dx
    push ax
    call mf99
    mov sp,bp
    mov ax,80h
    push ax
    mov ax,8Ah
    push ax
    call mfa8
    mov sp,bp
    or ax,ax
    jnz short lblB6f
    jmp near ptr lbl271f
lblB6f:
    mov ax,4h
lblB9b:
    mov dx,0F00Ch
    push dx
    push ax
    call mfbe
    mov sp,bp
    jmp near ptr lbl271f
    cmp byte ptr ds:[300h],0h
    jz short lblD4f
    mov ax,2597h
    jmp short lblD7f
lblD4f:
    mov ax,25A1h
lblD7f:
    push ds
    push ax
    xor ax,ax
    jmp short lblB9b
    nop
    mov ax,7h
    push ax
    call mfe2
    mov sp,bp
    or ax,ax
    jz short lblF0f
    jmp near ptr lbl271f
lblF0f:
    push ax
    mov ax,80h
    jmp near ptr lbl1F9f
    nop
    cmp byte ptr ds:[30Ch],0h
    jnz short lbl102f
    jmp near ptr lbl1A8f
lbl102f:
    cmp byte ptr ds:[2F2h],0h
    jz short lbl10Cf
    jmp near ptr lbl1A8f
lbl10Cf:
    mov ax,1h
    push ax
    mov ax,73h
    push ax
    call mf114
    add sp,4h
    or ax,ax
    jz short lbl123f
    jmp near ptr lbl1A8f
lbl123f:
    mov ax,99h
    push ax
    mov ax,73h
    push ax
    call mf12b
    add sp,4h
    or ax,ax
    jnz short lbl1A8f
    mov ax,0Bh
    push ax
    call mf13b
    add sp,2h
    mov ax,1388h
    push ax
    call mf147
    add sp,2h
    mov ax,5A0Bh
    push ax
    mov ax,281h
    push ax
    call mf157
    add sp,4h
    mov ax,73h
    push ax
    call mf163
    add sp,2h
    cmp ax,12Dh
    jz short lbl173f
    jmp near ptr lbl1F6f
lbl173f:
    mov ax,0Ah
    push ax
    mov ax,80h
    push ax
    call mf17b
    add sp,4h
    or ax,ax
    jnz short lbl1F6f
    mov ax,0Ah
    push ax
    mov ax,80h
    push ax
    call mf18f
    add sp,4h
    xor ax,ax
    push ax
    push ax
    mov ax,9h
    push ax
    call mf19f
    jmp near ptr lbl271f
    nop
lbl1A8f:
    cmp word ptr ds:[2A6h],2h
    jz short lbl1B2f
    jmp near ptr lbl271f
lbl1B2f:
    mov ax,1h
    push ax
    mov ax,8Bh
    push ax
    call mf1ba
    add sp,4h
    or ax,ax
    jz short lbl1C9f
    jmp near ptr lbl271f
lbl1C9f:
    mov ax,0Bh
    push ax
    call mf1cd
    add sp,2h
    mov ax,0BB8h
    push ax
    call mf1d9
    add sp,2h
    call mf1e1
    mov ax,5A0Bh
    push ax
    mov ax,282h
    push ax
    call mf1ee
    add sp,4h
lbl1F6f:
    xor ax,ax
    push ax
lbl1F9f:
    push ax
    mov ax,3h
    push ax
    call mf1fe
    jmp short lbl271f
    nop
    call mf206
    call mf20b
    mov byte ptr ds:[2596h],0h
    jmp short lbl271f
    nop
    cmp byte ptr ds:[2596h],0h
    jnz short lbl249f
    call mf21f
    call mf224
    cmp word ptr ds:[2A6h],2h
    jz short lbl244f
    xor ax,ax
    push ax
    push ax
    mov ax,13h
    push ax
    mov ax,44Bh
    push ax
    call mf23c
    add sp,8h
lbl244f:
    mov byte ptr ds:[2596h],1h
lbl249f:
    mov ax,9h
    push ax
    mov ax,0h
    mov cx,338Bh
    push cx
    push ax
    call mf255
    add sp,6h
    jmp short lbl273f
    nop
    mov ax,0Ah
    push ax
    mov ax,6Ch
    mov cx,338Bh
    push cx
    push ax
    call mf26c
lbl271f:
    xor ax,ax
lbl273f:
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
