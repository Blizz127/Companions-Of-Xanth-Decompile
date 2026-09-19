_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mfad:FAR
    EXTRN mf1d2:FAR
    EXTRN mf1f4:FAR
    EXTRN mf52:FAR
    EXTRN mibf:NEAR
    EXTRN mf1b6:FAR
    EXTRN mf20d:FAR
    EXTRN mf17f:FAR
    EXTRN mf10d:FAR
    EXTRN mia:NEAR
    EXTRN mf1e3:FAR
    EXTRN mf1be:FAR
    EXTRN mf121:FAR
    EXTRN mffd:FAR
    EXTRN mf140:FAR
    EXTRN mf14c:FAR
    EXTRN mf15b:FAR
    EXTRN mf16e:FAR
    EXTRN md15:NEAR
    EXTRN mf224:FAR
    EXTRN mf1de:FAR
    EXTRN mf17a:FAR
    EXTRN mfd4:FAR
    EXTRN mf12d:FAR
    EXTRN mf1a6:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,4h
    mov ax,word ptr [bp+6h]
    dec ax
    cmp ax, offset mia
    jna short lbl12f
    db 0E9h, 17h, 02h ; override
lbl12f:
    add ax,ax
    xchg ax,bx
    jmp word ptr cs:[bx+md15]
    db 0AAh, 00h, 89h, 02h, 89h, 02h, 89h, 02h, 89h, 02h, 1Ch, 01h, 89h, 02h, 2Ch, 01h
    db 98h, 01h, 98h, 01h, 98h, 01h, 89h, 02h, 89h, 02h, 89h, 02h, 0DAh, 01h, 89h, 02h
    db 89h, 02h, 89h, 02h, 89h, 02h, 89h, 02h, 89h, 02h, 0ECh, 01h, 78h, 02h, 0DAh, 01h
    mov ax,0Ah
    push ax
    mov ax,3Dh
    push ax
    call mf52
    add sp,4h
    or ax,ax
    jz short lbl61f
    jmp near ptr lbl229f
lbl61f:
    cmp word ptr ds:[6A06h],37h
    jnz short lbl72f
    cmp word ptr ds:[6A04h],3Dh
    jnz short lbl72f
    jmp near ptr lbl229f
lbl72f:
    cmp word ptr ds:[6A06h],4Ch
    jnz short lbl83f
    cmp word ptr ds:[6A04h],3Ch
    jnz short lbl83f
    jmp near ptr lbl229f
lbl83f:
    cmp word ptr ds:[6A06h],4Bh
    jnz short lbl94f
    cmp word ptr ds:[6A04h],3Ch
    jnz short lbl94f
    jmp near ptr lbl229f
lbl94f:
    cmp word ptr ds:[6A06h],51h
    jnz short lblA5f
    cmp byte ptr ds:[6E5Ch],4h
    jnz short lblA5f
    jmp near ptr lbl229f
lblA5f:
    mov ax,9h
lblA8b:
    mov dx,0F004h
    push dx
    push ax
    call mfad
    add sp,4h
    mov ax,1h
    jmp near ptr lbl22Bf
    nop
    mov ax,word ptr ds:[6A06h]
    sub ax, offset mibf
    jz short lblC7f
    jmp near ptr lbl229f
lblC7f:
    mov ax,0Fh
    jmp short lblA8b
    mov ax,0Eh
    push ax
    mov ax,34h
    push ax
    call mfd4
    add sp,4h
    or ax,ax
    jz short lblE8f
    mov ax,0Dh
    mov dx,0F004h
    jmp short lblEDf
lblE8f:
    mov ax,21C7h
    mov dx,ds
lblEDf:
    mov word ptr [bp-4h],ax
    mov word ptr [bp-2h],dx
    push dx
    push ax
    mov ax,0Ch
    mov dx,0F004h
    push dx
    push ax
    call mffd
    add sp,8h
    mov ax,3Eh
    push ax
    mov ax,50h
    push ax
    call mf10d
    add sp,4h
    or ax,ax
    jz short lbl129f
    mov ax,0Eh
    mov dx,0F004h
    push dx
    push ax
    call mf121
    add sp,4h
lbl129f:
    mov ax,2Eh
    push ax
    call mf12d
    add sp,2h
    jmp near ptr lbl229f
    mov ax,0Ah
    push ax
    mov ax,3Dh
    push ax
    call mf140
    add sp,4h
    or ax,ax
    jz short lbl166f
    call mf14c
    push dx
    push ax
    mov ax,0Ah
    mov dx,0F004h
    push dx
    push ax
    call mf15b
    add sp,8h
    jmp near ptr lbl229f
lbl166f:
    mov ax,0Bh
    mov dx,0F004h
    push dx
    push ax
    call mf16e
    add sp,4h
    jmp near ptr lbl229f
    nop
    call mf17a
    call mf17f
    mov byte ptr ds:[2042h],0h
    jmp near ptr lbl229f
    cmp byte ptr ds:[2043h],0h
    jz short lbl1C3f
    mov byte ptr ds:[2043h],0h
    cmp word ptr ds:[58h],0h
    jnz short lbl1C3f
    cmp word ptr ds:[56h],1h
    jz short lbl1C3f
    call mf1a6
    xor al,al
    push ax
    mov ax,3h
    push ax
    mov ax,241h
    push ax
    call mf1b6
    add sp,6h
    call mf1be
lbl1C3f:
    cmp byte ptr ds:[2042h],0h
    jnz short lbl201f
    mov ax,0Eh
    push ax
    mov ax,34h
    push ax
    call mf1d2
    add sp,4h
    or ax,ax
    jz short lbl201f
    call mf1de
    call mf1e3
    xor ax,ax
    push ax
    push ax
    mov ax,14h
    push ax
    mov ax,22Dh
    push ax
    call mf1f4
    add sp,8h
    mov byte ptr ds:[2042h],1h
lbl201f:
    mov ax,3h
    push ax
    mov ax,98h
    mov cx,32CFh
    push cx
    push ax
    call mf20d
    add sp,6h
    jmp short lbl22Bf
    nop
    mov ax,5h
    push ax
    mov ax,0BCh
    mov cx,32CFh
    push cx
    push ax
    call mf224
lbl229f:
    xor ax,ax
lbl22Bf:
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
