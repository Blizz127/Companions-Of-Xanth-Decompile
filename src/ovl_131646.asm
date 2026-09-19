_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi6:NEAR
    EXTRN mfdc:FAR
    EXTRN mi9:NEAR
    EXTRN mf42:FAR
    EXTRN mfb9:FAR
    EXTRN mf8a:FAR
    EXTRN mf116:FAR
    EXTRN mf124:FAR
    EXTRN mfec:FAR
    EXTRN mf105:FAR
    EXTRN mf51:FAR
    EXTRN mf67:FAR
    EXTRN mfa3:FAR
    EXTRN mffe:FAR
    EXTRN mf137:FAR
mnem_unit:
    push bp
    mov bp,sp
    mov ax,word ptr [bp+6h]
    sub ax, offset mi6
    cmp ax, offset mi9
    jna short lbl11f
    jmp near ptr lbl13Cf
lbl11f:
    add ax,ax
    xchg ax,bx
    jmp word ptr cs:[bx+4A8h]
    nop
    db 0C8h, 04h, 00h, 05h, 00h, 05h, 00h, 05h, 0CAh, 05h, 0CAh, 05h, 0CAh, 05h, 06h, 05h
    db 0CAh, 05h, 0CAh, 05h, 0CAh, 05h, 0CAh, 05h, 0CAh, 05h, 0CAh, 05h, 50h, 05h, 0BCh, 05h
    mov ax,0Fh
    mov dx,0F00Fh
    push dx
    push ax
    call mf42
    mov sp,bp
    mov ax,9Ch
    push ax
    mov ax,9Bh
    push ax
    call mf51
    mov sp,bp
    or ax,ax
    jnz short lbl5Ff
    jmp near ptr lbl13Cf
lbl5Ff:
    mov ax,0Ch
lbl62b:
    mov dx,0F00Fh
    push dx
    push ax
    call mf67
    mov sp,bp
    jmp near ptr lbl13Cf
    nop
    mov ax,0Eh
    jmp short lbl62b
    nop
    cmp byte ptr ds:[2F2h],0h
    jz short lbl82f
    jmp near ptr lbl13Cf
lbl82f:
    mov ax,9Ch
    push ax
    mov ax,9Bh
    push ax
    call mf8a
    mov sp,bp
    or ax,ax
    jnz short lbl98f
    jmp near ptr lbl13Cf
lbl98f:
    xor ax,ax
    push ax
    mov ax,9Ah
    push ax
    mov ax,9Bh
    push ax
    call mfa3
    mov sp,bp
    cmp byte ptr ds:[6E5Ch],2h
    jz short lblB4f
    jmp near ptr lbl13Cf
lblB4f:
    mov byte ptr ds:[278Bh],1h
    call mfb9
    jmp short lbl13Cf
    nop
    nop
    cmp byte ptr ds:[278Bh],0h
    jz short lbl11Bf
    mov byte ptr ds:[278Bh],0h
    cmp word ptr ds:[58h],0h
    jnz short lbl10Af
    cmp word ptr ds:[56h],1h
    jz short lbl10Af
    call mfdc
    xor al,al
    push ax
    mov cx,20h
    push cx
    mov cx,599h
    push cx
    call mfec
    mov sp,bp
    xor al,al
    push ax
    mov ax,8h
    push ax
    mov ax,5B9h
    push ax
    call mffe
    mov sp,bp
    call mf105
lbl10Af:
    cmp byte ptr ds:[278Ch],0h
    jz short lbl11Bf
    mov byte ptr ds:[278Ch],0h
    call mf116
lbl11Bf:
    mov ax,1h
    push ax
    mov ax,27A4h
    push ds
    push ax
    call mf124
    mov sp,bp
    jmp short lbl13Ef
    nop
    mov ax,1h
    push ax
    mov ax,27B0h
    push ds
    push ax
    call mf137
lbl13Cf:
    xor ax,ax
lbl13Ef:
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
