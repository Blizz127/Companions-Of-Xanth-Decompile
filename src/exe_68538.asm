_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi2:NEAR
    EXTRN mf20:FAR
    EXTRN mf31:FAR
    EXTRN mf40:FAR
    EXTRN mf43:FAR
    EXTRN mf57:FAR
    EXTRN mf62:FAR
    EXTRN mf65:FAR
    EXTRN mf78:FAR
    EXTRN mf78:FAR
    EXTRN mf78:FAR
    EXTRN mf78:FAR
    EXTRN mf78:FAR
    EXTRN mf78:FAR
    EXTRN mf78:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp, offset mi2
    push si
    push di
    cmp word ptr [bp+6h],0h
    jz short lbl12f
    jmp near ptr lbl1Af
lbl12f:
    mov word ptr [bp-6h],0h
    jmp near ptr lbl9Cf
lbl1Af:
    mov ax,3E8h
    mov dx,0h
    push dx
    push ax
    mov ax,word ptr [bp+8h]
    mov dx,word ptr [bp+0Ah]
    add ax,1F4h
    adc dx,0h
    push dx
    push ax
    call mf20
    mov word ptr [bp+8h],ax
    mov word ptr [bp+0Ah],dx
    mov ax,3E8h
    mov dx,0h
    push dx
    push ax
    mov ax,word ptr [bp+6h]
    mov dx,0h
    push dx
    push ax
    call mf31
    push dx
    push ax
    mov ax,34DCh
    mov dx,12h
    push dx
    push ax
    push word ptr [bp+0Ah]
    push word ptr [bp+8h]
    call mf40
    push dx
    push ax
    call mf43
    mov word ptr [bp-6h],ax
    mov ax,34DCh
    mov dx,12h
    push dx
    push ax
    mov ax,86A0h
    mov dx,1h
    push dx
    push ax
    mov ax,word ptr [bp-6h]
    mov dx,0h
    push dx
    push ax
    call mf57
    add ax,1A6Eh
    adc dx,9h
    push dx
    push ax
    call mf62
    mov word ptr [bp-4h],ax
lbl9Cf:
    push word ptr [bp-6h]
    call mf65
    add sp,2h
    cmp word ptr [bp-6h],0h
    jnz short lblB0f
    jmp near ptr lblB9f
lblB0f:
    mov ax,word ptr [bp-4h]
    mov word ptr ds:[6DE4h],ax
    jmp near ptr lblBFf
lblB9f:
    mov word ptr ds:[6DE4h],1575h
lblBFf:
    pop di
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
