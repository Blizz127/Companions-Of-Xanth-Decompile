_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf8:FAR
    EXTRN mf23:FAR
    EXTRN mf33:FAR
    EXTRN mf41:FAR
    EXTRN mf48:FAR
    EXTRN mf52:FAR
    EXTRN mf60:FAR
    EXTRN mf67:FAR
    EXTRN mf75:FAR
    EXTRN mf79:FAR
    EXTRN mf79:FAR
    EXTRN mf79:FAR
    EXTRN mf79:FAR
    EXTRN mf79:FAR
    EXTRN mf79:FAR
    EXTRN mf79:FAR
    EXTRN mf79:FAR
    EXTRN mf79:FAR
mnem_unit:
    push bp
    mov bp,sp
    cmp word ptr [bp+6h],0Fh
    jz short lbl30f
    mov ax,0BEh
    push ax
    mov ax,0BFh
    push ax
    call mf8
    mov sp,bp
    or ax,ax
    jz short lbl2Af
    cmp byte ptr ds:[6E5Ch],1h
    jnz short lbl2Af
lbl23b:
    mov ax,0C5h
    jmp near ptr lblBAf
    nop
lbl2Af:
    mov ax,0BEh
    jmp near ptr lblBAf
lbl30f:
    mov ax,0BEh
    push ax
    mov ax,0BFh
    push ax
    call mf23
    mov sp,bp
    or ax,ax
    jz short lbl9Cf
    cmp byte ptr ds:[6E5Ch],1h
    jnz short lbl8Af
    mov ax,0Eh
    push ax
    mov ax,0BFh
    push ax
    call mf33
    mov sp,bp
    or ax,ax
    jz short lbl8Af
    mov ax,1Dh
    mov dx,0F019h
    push dx
    push ax
    call mf41
    mov sp,bp
    mov ax,1h
    push ax
    push ax
    mov ax,2h
    push ax
    call mf48
    mov sp,bp
    mov ax,1770h
    push ax
    call mf52
    mov sp,bp
    jmp short lbl23b
    nop
lbl8Af:
    mov ax,1Eh
    mov dx,0F019h
    push dx
    push ax
    call mf60
    mov sp,bp
    jmp short lblB8f
    nop
lbl9Cf:
    mov al,byte ptr ds:[6E5Ch]
    sub ah,ah
    push ax
    call mf67
    mov sp,bp
    push dx
    push ax
    mov ax,1Fh
    mov dx,0F019h
    push dx
    push ax
    call mf75
lblB8f:
    xor ax,ax
lblBAf:
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
