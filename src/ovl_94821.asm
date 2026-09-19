_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf1c6:FAR
    EXTRN mf1e0:FAR
    EXTRN mf144:FAR
    EXTRN mfe8:FAR
    EXTRN mf165:FAR
    EXTRN mia:NEAR
    EXTRN mfd6:FAR
    EXTRN mf16a:FAR
    EXTRN mf1ae:FAR
    EXTRN mf12f:FAR
    EXTRN mfb4:FAR
    EXTRN mff9:FAR
    EXTRN mfc3:FAR
    EXTRN mf10f:FAR
    EXTRN mf17b:FAR
    EXTRN mf194:FAR
    EXTRN mf14c:FAR
    EXTRN mf72:FAR
    EXTRN mf86:FAR
    EXTRN mf62:FAR
    EXTRN mf9a:FAR
    EXTRN mf151:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,2h
    mov ax,word ptr [bp+6h]
    dec ax
    cmp ax, offset mia
    jna short lbl12f
    jmp near ptr lbl1E5f
lbl12f:
    add ax,ax
    xchg ax,bx
    jmp word ptr cs:[bx+7DFh]
    db 0Fh, 08h, 0AAh, 09h, 0AAh, 09h, 0AAh, 09h, 0AAh, 09h, 0AAh, 09h, 0AAh, 09h, 1Fh, 08h
    db 93h, 08h, 93h, 08h, 93h, 08h, 0AAh, 09h, 0C9h, 08h, 0E5h, 08h, 05h, 09h, 0AAh, 09h
    db 0AAh, 09h, 0AAh, 09h, 0AAh, 09h, 0AAh, 09h, 0AAh, 09h, 23h, 09h, 99h, 09h, 05h, 09h
    cmp byte ptr ds:[29Ah],0h
    jnz short lbl54f
    jmp near ptr lbl1E5f
lbl54f:
    mov ax,1h
    jmp near ptr lbl1E7f
    mov ax,1h
    mov dx,0F016h
    push dx
    push ax
    call mf62
    add sp,4h
    mov ax,0Eh
    push ax
    mov ax,5Ch
    push ax
    call mf72
    add sp,4h
    or ax,ax
    jnz short lblACf
    mov ax,0Eh
    push ax
    mov ax,5Dh
    push ax
    call mf86
    add sp,4h
    or ax,ax
    jnz short lblACf
    mov ax,0Eh
    push ax
    mov ax,5Eh
    push ax
    call mf9a
    add sp,4h
    or ax,ax
    jnz short lblACf
    mov ax,3h
    jmp short lblAFf
    nop
lblACf:
    mov ax,2h
lblAFf:
    mov dx,0F016h
    push dx
    push ax
    call mfb4
    mov ax,4h
    add sp,ax
    mov dx,0F016h
    push dx
    push ax
    call mfc3
lblC8b:
    add sp,4h
    jmp near ptr lbl1E5f
    push word ptr ds:[290h]
    mov ax,5h
    push ax
    call mfd6
    add sp,4h
    push dx
    push ax
    push word ptr ds:[290h]
    mov ax,11h
    push ax
    call mfe8
    add sp,4h
    push dx
    push ax
    xor ax,ax
    mov dx,0F016h
    push dx
    push ax
    call mff9
    add sp,0Ch
    jmp near ptr lbl1E5f
    xor ax,ax
    push ax
    push word ptr ds:[256h]
    push word ptr ds:[290h]
    call mf10f
    add sp,6h
    mov ax,word ptr ds:[290h]
    mov word ptr ds:[798h],ax
    jmp near ptr lbl1E5f
    cmp word ptr ds:[290h],5h
    jnz short lbl136f
    mov ax,1h
    push ax
    mov ax,5h
lbl12Eb:
    push ax
    call mf12f
    jmp short lblC8b
lbl136f:
    mov ax,3h
    push ax
    mov ax,4h
    jmp short lbl12Eb
    nop
    mov ax,1Eh
    push ax
    call mf144
    add sp,2h
    call mf14c
    call mf151
    mov byte ptr ds:[2374h],0h
    jmp near ptr lbl1E5f
    cmp byte ptr ds:[2374h],0h
    jnz short lbl188f
    call mf165
    call mf16a
    xor ax,ax
    push ax
    push ax
    mov ax,17h
    push ax
    mov ax,366h
    push ax
    call mf17b
    add sp,8h
    mov byte ptr ds:[2374h],1h
lbl188f:
    mov ax,3h
    push ax
    mov ax,0h
    mov cx,333Eh
    push cx
    push ax
    call mf194
    add sp,6h
    mov word ptr [bp-2h],ax
    xor ax,ax
    push ax
    mov ax,96h
    push ax
    mov ax,0F2h
    push ax
    mov ax,0F0h
    push ax
    call mf1ae
    add sp,8h
    mov ax,1h
    push ax
    mov ax,64h
    push ax
    mov ax,0F4h
    push ax
    mov ax,0F3h
    push ax
    call mf1c6
    add sp,8h
    mov ax,word ptr [bp-2h]
    jmp short lbl1E7f
    nop
    mov ax,3h
    push ax
    mov ax,24h
    mov cx,333Eh
    push cx
    push ax
    call mf1e0
lbl1E5f:
    xor ax,ax
lbl1E7f:
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
