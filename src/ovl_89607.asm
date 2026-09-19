_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi6:NEAR
    EXTRN mf73:FAR
    EXTRN mf1ea:FAR
    EXTRN mf1d0:FAR
    EXTRN mfde:FAR
    EXTRN mfc4:FAR
    EXTRN mf1ad:FAR
    EXTRN mf112:FAR
    EXTRN mf137:FAR
    EXTRN mf13e:FAR
    EXTRN mf1b8:FAR
    EXTRN mff2:FAR
    EXTRN mf82:FAR
    EXTRN mi6f:NEAR
    EXTRN mf119:FAR
    EXTRN mf5c:FAR
    EXTRN mf127:FAR
    EXTRN mf143:FAR
    EXTRN mf148:FAR
    EXTRN mf18b:FAR
    EXTRN mfa7:FAR
    EXTRN mf4e:FAR
    EXTRN mf12e:FAR
    EXTRN mfb9:FAR
    EXTRN mf103:FAR
    EXTRN mi11:NEAR
    EXTRN mf172:FAR
    EXTRN mf11e:FAR
    EXTRN mf19a:FAR
    EXTRN mf98:FAR
mnem_unit:
    push bp
    mov bp,sp
    mov ax,word ptr [bp+6h]
    sub ax, offset mi6
    jz short lbl0Ef
    jmp near ptr lbl1F8f
lbl0Ef:
    mov ax,word ptr ds:[6A06h]
    cmp ax, offset mi11
    jnz short lbl19f
    jmp near ptr lbl1F2f
lbl19f:
    jna short lbl1Ef
    jmp near ptr lbl1F8f
lbl1Ef:
    dec al
    jz short lbl3Af
    sub al,12h
    jnz short lbl29f
    jmp near ptr lbl154f
lbl29f:
    sub al,19h
    jnz short lbl30f
    jmp near ptr lbl15Af
lbl30f:
    sub al,18h
    jnz short lbl37f
    jmp near ptr lbl160f
lbl37f:
    jmp near ptr lbl1F8f
lbl3Af:
    mov ax,word ptr ds:[222Eh]
    dec ax
    jz short lbl58f
    dec ax
    jnz short lbl46f
    jmp near ptr lblDAf
lbl46f:
    mov ax,58h
lbl49b:
    mov dx,0F005h
    push dx
    push ax
    call mf4e
lbl53b:
    mov sp,bp
    jmp near ptr lbl14Df
lbl58f:
    mov ax,3h
    push ax
    call mf5c
    mov sp,bp
    mov ax,5A0Ah
    push ax
    cmp byte ptr ds:[323h],1h
    cmc
    db 1Bh, 0C0h ; override
    and ax, offset mi6f
    push ax
    call mf73
    mov sp,bp
    mov ax,56h
    mov dx,0F005h
    push dx
    push ax
    call mf82
    mov sp,bp
    cmp byte ptr ds:[2F5h],0h
    jz short lblC0f
    mov ax,57h
    mov dx,0F005h
    push dx
    push ax
    call mf98
    mov sp,bp
    mov ax,9h
    push ax
    mov ax,2h
    push ax
    call mfa7
    mov sp,bp
    xor ax,ax
    push ax
    mov ax,1h
    push ax
    mov ax,0Fh
    push ax
    call mfb9
    jmp short lblC9f
lblC0f:
    mov ax,2Eh
    push ax
    call mfc4
lblC9f:
    mov sp,bp
    mov word ptr ds:[222Eh],0h
    mov word ptr ds:[2230h],0h
    jmp short lbl14Df
    nop
lblDAf:
    mov ax,2Ah
    push ax
    call mfde
    mov sp,bp
    mov byte ptr ds:[1D00h],0h
    mov ax,5A0Ah
    push ax
    mov ax,264h
    push ax
    call mff2
    mov sp,bp
    mov word ptr ds:[222Eh],0h
    mov ax,0FA0h
    push ax
    call mf103
    mov sp,bp
    mov ax,20h
    mov cx,2199h
    push cx
    push ax
    call mf112
    mov sp,bp
    call mf119
    call mf11e
    mov ax,10h
    push ax
    call mf127
    mov sp,bp
    call mf12e
    mov ax,5h
    push ax
    call mf137
    mov sp,bp
    call mf13e
    call mf143
    call mf148
lbl14Df:
    mov ax,1h
    jmp near ptr lbl1FAf
    nop
lbl154f:
    mov ax,53h
    jmp near ptr lbl49b
lbl15Af:
    mov ax,55h
    jmp near ptr lbl49b
lbl160f:
    cmp word ptr ds:[222Eh],0h
    jz short lbl17Cf
lbl167b:
    xor ax,ax
    push ax
    push word ptr ds:[6A04h]
    mov ax,1h
    push ax
    call mf172
    mov sp,bp
    jmp short lbl1FAf
    nop
lbl17Cf:
    cmp byte ptr ds:[323h],0h
    jz short lbl1C8f
    mov ax,0Ah
    push ax
    mov ax,2Ch
    push ax
    call mf18b
    mov sp,bp
    or ax,ax
    jz short lbl1C8f
    mov ax,3h
    push ax
    call mf19a
    mov sp,bp
    or ax,ax
    jz short lbl1C8f
    mov ax,59h
    mov dx,0F005h
    push dx
    push ax
    call mf1ad
    mov sp,bp
    mov ax,0BB8h
    push ax
    call mf1b8
    mov sp,bp
    mov word ptr ds:[222Eh],1h
    jmp short lbl167b
    nop
lbl1C8f:
    mov ax,0Ah
    push ax
    mov ax,2Ch
    push ax
    call mf1d0
    mov sp,bp
    or ax,ax
    jnz short lbl1E2f
    mov ax,5Ah
    jmp near ptr lbl49b
    nop
lbl1E2f:
    mov ax,5A0Ah
    push ax
    mov ax,1FAh
    push ax
    call mf1ea
    jmp near ptr lbl53b
lbl1F2f:
    mov ax,54h
    jmp near ptr lbl49b
lbl1F8f:
    xor ax,ax
lbl1FAf:
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
