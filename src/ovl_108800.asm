_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi6:NEAR
    EXTRN mf6c:FAR
    EXTRN mf149:FAR
    EXTRN mf17e:FAR
    EXTRN mf112:FAR
    EXTRN mf125:FAR
    EXTRN mf18e:FAR
    EXTRN mi9:NEAR
    EXTRN mf44:FAR
    EXTRN md14:NEAR
    EXTRN mf82:FAR
    EXTRN mf193:FAR
    EXTRN mf14e:FAR
    EXTRN mf15b:FAR
    EXTRN mfee:FAR
    EXTRN mf138:FAR
    EXTRN mf5a:FAR
    EXTRN mfda:FAR
    EXTRN mfc6:FAR
    EXTRN mfb6:FAR
    EXTRN mfff:FAR
mnem_unit:
    push bp
    mov bp,sp
    mov ax,word ptr [bp+6h]
    sub ax, offset mi6
    cmp ax, offset mi9
    jna short lbl11f
    db 0E9h, 8Ch, 01h ; override
lbl11f:
    add ax,ax
    xchg ax,bx
    jmp word ptr cs:[bx+md14]
    nop
    db 3Ch, 00h, 4Eh, 00h, 4Eh, 00h, 4Eh, 00h, 9Dh, 01h, 52h, 00h, 0D2h, 00h, 0F6h, 00h
    db 9Dh, 01h, 9Dh, 01h, 9Dh, 01h, 9Dh, 01h, 9Dh, 01h, 9Dh, 01h, 42h, 01h, 9Dh, 01h
    db 8Eh, 01h
    mov ax,1h
lbl3Fb:
    mov dx,0F00Ah
    push dx
    push ax
    call mf44
lbl49b:
    mov sp,bp
    jmp near ptr lbl19Df
    xor ax,ax
    jmp short lbl3Fb
    mov ax,1h
    push ax
    mov ax,0BDh
    push ax
    call mf5a
    mov sp,bp
    or ax,ax
    jz short lblBEf
    xor ax,ax
    push ax
    mov ax,0Ch
    push ax
    call mf6c
    mov sp,bp
    cmp byte ptr ds:[315h],0h
    jnz short lbl9Af
    mov ax,0Ah
    push ax
    mov ax,7Dh
    push ax
    call mf82
    mov sp,bp
    or ax,ax
    jnz short lbl9Af
    mov ax,1h
    mov byte ptr ds:[315h],al
    push ax
    mov ax,9h
    jmp short lblB1f
    nop
lbl9Af:
    cmp byte ptr ds:[6A16h],0h
    jnz short lblAAf
    mov ax,1h
    push ax
    mov ax,0Ah
    jmp short lblB1f
lblAAf:
    mov ax,1h
    push ax
    mov ax,0Bh
lblB1f:
    push ax
    mov ax,8026h
    push ax
    call mfb6
    add sp,6h
lblBEf:
    xor ax,ax
    push ax
    push ax
    mov ax,8026h
    push ax
    call mfc6
    add sp,6h
    jmp near ptr lbl19Df
    nop
    mov ax,1h
    push ax
    mov ax,0BDh
    push ax
    call mfda
    add sp,4h
    or ax,ax
    jz short lblE9f
    jmp near ptr lbl19Df
lblE9f:
    mov ax,254Fh
    push ds
    push ax
    call mfee
    jmp near ptr lbl49b
    mov byte ptr ds:[316h],0h
    mov ax,0Ch
    push ax
    call mfff
    add sp,2h
    xor ax,ax
    push ax
    mov cx,9h
    push cx
    mov cx,8026h
    push cx
    call mf112
    add sp,6h
    xor ax,ax
    push ax
    mov cx,0Ah
    push cx
    mov cx,8026h
    push cx
    call mf125
    add sp,6h
    xor ax,ax
    push ax
    mov ax,0Bh
    push ax
    mov ax,8026h
    push ax
    call mf138
    add sp,6h
    jmp short lbl18Ef
    cmp byte ptr ds:[254Eh],0h
    jnz short lbl19Df
    call mf149
    call mf14e
    mov ax,1h
    push ax
    mov ax,0BDh
    push ax
    call mf15b
    add sp,4h
    or ax,ax
    jnz short lbl172f
    push ax
    push ax
    mov ax,21h
    push ax
    mov ax,422h
    jmp short lbl17Df
lbl172f:
    xor ax,ax
    push ax
    push ax
    mov ax,0Bh
    push ax
    mov ax,417h
lbl17Df:
    push ax
    call mf17e
    add sp,8h
    mov byte ptr ds:[254Eh],1h
    jmp short lbl19Df
    nop
lbl18Ef:
    call mf18e
    call mf193
    mov byte ptr ds:[254Eh],0h
lbl19Df:
    xor ax,ax
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
