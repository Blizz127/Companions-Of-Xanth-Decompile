_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mfb9:FAR
    EXTRN mfef:FAR
    EXTRN mfa9:FAR
    EXTRN mf14e:FAR
    EXTRN mf7c:FAR
    EXTRN mf122:FAR
    EXTRN mf173:FAR
    EXTRN mf132:FAR
    EXTRN mf1b2:FAR
    EXTRN mf184:FAR
    EXTRN mf153:FAR
    EXTRN mi7:NEAR
    EXTRN mf19d:FAR
    EXTRN md12:NEAR
    EXTRN mfff:FAR
    EXTRN mfc9:FAR
    EXTRN mf146:FAR
    EXTRN mf16e:FAR
mnem_unit:
    push bp
    mov bp,sp
    mov ax,word ptr [bp+6h]
    dec ax
    cmp ax, offset mi7
    jna short lbl0Ff
    db 0E9h, 0A8h, 01h ; override
lbl0Ff:
    add ax,ax
    xchg ax,bx
    jmp word ptr cs:[bx+md12]
    nop
    db 58h, 00h, 0C7h, 01h, 0C7h, 01h, 80h, 00h, 0C7h, 01h, 96h, 00h, 0C7h, 01h, 0A0h, 00h
    db 1Ah, 01h, 1Ah, 01h, 1Ah, 01h, 0C7h, 01h, 0C7h, 01h, 0C7h, 01h, 5Eh, 01h, 0C7h, 01h
    db 0C7h, 01h, 0C7h, 01h, 0C7h, 01h, 0C7h, 01h, 0C7h, 01h, 70h, 01h, 0B6h, 01h, 5Eh, 01h
    cmp word ptr ds:[6A06h],44h
    jz short lbl52f
    jmp near ptr lbl1B7f
lbl52f:
    cmp word ptr ds:[6A04h],104h
    jz short lbl5Df
    jmp near ptr lbl1B7f
lbl5Df:
    cmp byte ptr ds:[33Ah],0h
    jz short lbl67f
    jmp near ptr lbl1B7f
lbl67f:
    mov byte ptr ds:[33Ah],1h
    jmp near ptr lbl1B7f
    nop
    mov ax,103h
    push ax
    push word ptr ds:[6A04h]
lbl78b:
    push word ptr ds:[6A06h]
    call mf7c
lbl81b:
    mov sp,bp
    jmp near ptr lbl1B9f
    push word ptr ds:[6A02h]
    mov ax,103h
    push ax
    jmp short lbl78b
    cmp byte ptr ds:[329h],0h
    jz short lbl9Cf
    mov ax,5h
    jmp short lbl9Ff
lbl9Cf:
    mov ax,2h
lbl9Ff:
    mov dx,0F022h
    push dx
    push ax
    mov ax,4h
    push dx
    push ax
    call mfa9
    add sp,8h
    mov ax,6h
    mov dx,0F022h
    push dx
    push ax
    call mfb9
    add sp,4h
    mov ax,102h
    push ax
    mov ax,104h
    push ax
    call mfc9
    add sp,4h
    or ax,ax
    jz short lblF7f
    cmp byte ptr ds:[329h],0h
    jz short lblE2f
    mov ax,3109h
    jmp short lblE5f
    nop
lblE2f:
    mov ax,3111h
lblE5f:
    push ds
    push ax
    mov ax,7h
    mov dx,0F022h
    push dx
    push ax
    call mfef
    add sp,8h
lblF7f:
    mov ax,0Ah
    push ax
    mov ax,103h
    push ax
    call mfff
lbl104b:
    add sp,4h
    jmp near ptr lbl1B7f
    cmp byte ptr ds:[329h],0h
    jz short lbl116f
    mov ax,1h
    jmp short lbl119f
lbl116f:
    mov ax,2h
lbl119f:
    mov dx,0F022h
    push dx
    push ax
    xor ax,ax
    push dx
    push ax
    call mf122
    add sp,8h
    mov ax,102h
    push ax
    mov ax,104h
    push ax
    call mf132
    add sp,4h
    or ax,ax
    jz short lbl1B7f
    mov ax,3h
    mov dx,0F022h
    push dx
    push ax
    call mf146
    jmp short lbl104b
    nop
    call mf14e
    call mf153
    mov byte ptr ds:[3108h],0h
    jmp short lbl1B7f
    nop
    cmp byte ptr ds:[3108h],0h
    jnz short lbl191f
    cmp byte ptr ds:[329h],0h
    jnz short lbl191f
    call mf16e
    call mf173
    xor ax,ax
    push ax
    push ax
    mov ax,16h
    push ax
    mov ax,0ABBh
    push ax
    call mf184
    add sp,8h
    mov byte ptr ds:[3108h],1h
lbl191f:
    mov ax,4h
    push ax
    mov ax,0h
    mov cx,3336h
    push cx
    push ax
    call mf19d
    jmp near ptr lbl81b
    nop
    mov ax,3h
    push ax
    mov ax,30h
    mov cx,3336h
    push cx
    push ax
    call mf1b2
lbl1B7f:
    xor ax,ax
lbl1B9f:
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
