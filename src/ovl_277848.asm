_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi6:NEAR
    EXTRN mf116:FAR
    EXTRN mf1c6:FAR
    EXTRN mf73:FAR
    EXTRN mf1e5:FAR
    EXTRN mf141:FAR
    EXTRN mf53:FAR
    EXTRN mf214:FAR
    EXTRN mf191:FAR
    EXTRN mf1f0:FAR
    EXTRN mf1d3:FAR
    EXTRN mi9:NEAR
    EXTRN mf1bf:FAR
    EXTRN mf44:FAR
    EXTRN mf82:FAR
    EXTRN mff8:FAR
    EXTRN mf18c:FAR
    EXTRN mfb8:FAR
    EXTRN mfa9:FAR
    EXTRN mf12a:FAR
    EXTRN mffd:FAR
    EXTRN mf159:FAR
    EXTRN mf200:FAR
    EXTRN mf1af:FAR
    EXTRN mf185:FAR
    EXTRN mf111:FAR
    EXTRN mf177:FAR
    EXTRN mf19a:FAR
mnem_unit:
    push bp
    mov bp,sp
    mov ax,word ptr [bp+6h]
    sub ax, offset mi6
    cmp ax, offset mi9
    jna short lbl11f
    jmp near ptr lbl219f
lbl11f:
    add ax,ax
    xchg ax,bx
    jmp word ptr cs:[bx+1B2h]
    nop
    db 0D4h, 01h, 5Ah, 02h, 5Ah, 02h, 5Ah, 02h, 0B1h, 03h, 0B1h, 03h, 0B1h, 03h, 90h, 02h
    db 0B1h, 03h, 0B1h, 03h, 0B1h, 03h, 0B1h, 03h, 0B1h, 03h, 0B1h, 03h, 0A2h, 02h, 0FCh, 02h
    db 90h, 02h
    mov ax,0Ah
    push ax
    mov ax,169h
    push ax
    call mf44
    mov sp,bp
    mov ax,16Ch
    push ax
    mov ax,16Eh
    push ax
    call mf53
    mov sp,bp
    or ax,ax
    jz short lbl66f
    mov ax,6h
    mov dx,0F03Eh
    jmp short lbl69f
lbl66f:
    xor ax,ax
    cwd
lbl69f:
    push dx
    push ax
    mov ax,5h
    mov dx,0F03Eh
    push dx
    push ax
    call mf73
    mov sp,bp
    mov ax,16Dh
    push ax
    mov ax,157h
    push ax
    call mf82
    mov sp,bp
    or ax,ax
    jz short lblB0f
    cmp byte ptr ds:[359h],0h
    jz short lbl9Cf
    mov ax,8h
    mov dx,0F03Eh
    jmp short lbl9Ff
lbl9Cf:
    xor ax,ax
    cwd
lbl9Ff:
    push dx
    push ax
    mov ax,7h
    mov dx,0F03Eh
    push dx
    push ax
    call mfa9
    mov sp,bp
lblB0f:
    mov ax,9h
    mov dx,0F03Eh
lblB6b:
    push dx
    push ax
    call mfb8
lblBDb:
    mov sp,bp
    jmp near ptr lbl219f
    cmp word ptr ds:[6A22h],170h
    jnz short lblCDf
    jmp near ptr lbl219f
lblCDf:
    cmp byte ptr ds:[359h],0h
    jz short lblDAf
    mov ax,3h
    jmp short lblDDf
    nop
lblDAf:
    mov ax,4h
lblDDf:
    mov dx,0F03Eh
    push dx
    push ax
    cmp byte ptr ds:[359h],0h
    jz short lblEEf
    mov ax,367Dh
    jmp short lblF1f
lblEEf:
    mov ax,3683h
lblF1f:
    push ds
    push ax
    mov ax,2h
    jmp short lblB6b
    call mff8
    call mffd
    mov byte ptr ds:[367Ch],0h
    jmp near ptr lbl219f
    cmp byte ptr ds:[367Ch],0h
    jnz short lbl14Df
    call mf111
    call mf116
    cmp byte ptr ds:[359h],0h
    jz short lbl148f
    mov ax,16Dh
    push ax
    mov ax,157h
    push ax
    call mf12a
    mov sp,bp
    or ax,ax
    jz short lbl148f
    xor ax,ax
    push ax
    push ax
    mov ax,0Ah
    push ax
    mov ax,0F9Ah
    push ax
    call mf141
    mov sp,bp
lbl148f:
    mov byte ptr ds:[367Ch],1h
lbl14Df:
    mov ax,4h
    push ax
    mov ax,0h
    mov cx,3321h
    push cx
    push ax
    call mf159
    mov sp,bp
    jmp near ptr lbl21Bf
    nop
    cmp byte ptr ds:[362h],0h
    jnz short lbl16Ef
    jmp near ptr lbl208f
lbl16Ef:
    mov byte ptr ds:[362h],0h
    mov ax,9C4h
    push ax
    call mf177
    mov sp,bp
    xor ax,ax
    mov dx,0F03Eh
    push dx
    push ax
    call mf185
    mov sp,bp
    call mf18c
    call mf191
    mov ax,7D0h
    push ax
    call mf19a
    mov sp,bp
    cmp word ptr ds:[56h],1h
    jz short lbl1CBf
    cmp word ptr ds:[58h],0h
    jnz short lbl1CBf
    call mf1af
    xor al,al
    push ax
    mov ax,0Fh
    push ax
    mov ax,0FA4h
    push ax
    call mf1bf
    mov sp,bp
    call mf1c6
lbl1CBf:
    mov ax,1h
    mov dx,0F03Eh
    push dx
    push ax
    call mf1d3
    mov sp,bp
    xor ax,ax
    push ax
    mov ax,170h
    push ax
    mov cx,16Dh
    push cx
    call mf1e5
    mov sp,bp
    mov ax,1388h
    push ax
    call mf1f0
    mov sp,bp
    mov byte ptr ds:[783h],1h
    mov ax,170h
    push ax
    call mf200
    jmp near ptr lblBDb
lbl208f:
    mov ax,5h
    push ax
    mov ax,30h
    mov cx,3321h
    push cx
    push ax
    call mf214
lbl219f:
    xor ax,ax
lbl21Bf:
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
