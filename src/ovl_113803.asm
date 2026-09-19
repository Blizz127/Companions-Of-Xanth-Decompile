_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mfaf:FAR
    EXTRN mf9d:FAR
    EXTRN mf1ea:FAR
    EXTRN mfc2:FAR
    EXTRN mf186:FAR
    EXTRN mi256:NEAR
    EXTRN mf1d3:FAR
    EXTRN mf125:FAR
    EXTRN mfed:FAR
    EXTRN mf275:FAR
    EXTRN mfd6:FAR
    EXTRN mf210:FAR
    EXTRN mf1c3:FAR
    EXTRN mf1fc:FAR
    EXTRN mf14c:FAR
    EXTRN mib:NEAR
    EXTRN mf2a6:FAR
    EXTRN mf13c:FAR
    EXTRN mf111:FAR
    EXTRN mf288:FAR
    EXTRN mf161:FAR
    EXTRN mf1b1:FAR
    EXTRN mf177:FAR
    EXTRN mf19a:FAR
    EXTRN mfff:FAR
    EXTRN mi7d:NEAR
    EXTRN mf2be:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,0Ah
    push di
    push si
    mov ax,word ptr [bp+6h]
    sub ax, offset mib
    jz short lbl1Af
    dec ax
    dec ax
    jnz short lbl17f
    jmp near ptr lbl21Ef
lbl17f:
    jmp near ptr lbl2CEf
lbl1Af:
    cmp word ptr ds:[6A02h],86h
    jnz short lbl28f
    mov ax,25C5h
    jmp short lbl2Bf
    nop
lbl28f:
    mov ax,25CAh
lbl2Bf:
    mov bx,ds
    mov di,ax
    lea si,word ptr [bp-6h]
    mov es,bx
    push ds
    mov cx,0FFFFh
    xor ax,ax
    repne scasb
    not cx
    sub di,cx
    db 87h, 0FEh ; override
    push ds
    push es
    pop ds
    pop es
    shr cx,1
    rep movsw
    adc cx,cx
    rep movsb
    pop ds
    cmp word ptr ds:[6A02h],86h
    jnz short lbl5Ef
    mov word ptr [bp-8h],87h
    jmp short lbl64f
lbl5Ef:
    mov ax,word ptr ds:[6A02h]
    mov word ptr [bp-8h],ax
lbl64f:
    cmp word ptr ds:[6A04h],88h
    jnz short lbl74f
    mov word ptr [bp-0Ah],89h
    jmp short lbl7Af
    nop
lbl74f:
    mov ax,word ptr ds:[6A04h]
    mov word ptr [bp-0Ah],ax
lbl7Af:
    mov ax,word ptr ds:[6A06h]
    sub ax, offset mi7d
    jz short lbl85f
    jmp near ptr lbl2CEf
lbl85f:
    cmp word ptr ds:[6A04h],88h
    jz short lblBAf
    cmp word ptr ds:[6A04h],89h
    jz short lblBAf
    push word ptr ds:[6A04h]
    mov ax,12h
    push ax
    call mf9d
    add sp,4h
    push dx
    push ax
    mov ax,0Eh
lblAAb:
    mov dx,0F00Ch
    push dx
    push ax
    call mfaf
    add sp,8h
    jmp near ptr lbl218f
lblBAf:
    push word ptr ds:[6A02h]
    push word ptr ds:[6A04h]
    call mfc2
    add sp,4h
    or ax,ax
    jz short lbl10Af
    push word ptr ds:[6A02h]
    mov ax,1h
    push ax
    call mfd6
    add sp,4h
    push dx
    push ax
    lea ax,word ptr [bp-6h]
    push ss
    push ax
    push word ptr ds:[6A04h]
    mov ax,2h
    push ax
    call mfed
    add sp,4h
    push dx
    push ax
    mov ax,9h
    mov dx,0F00Ch
    push dx
    push ax
    call mfff
    add sp,10h
    jmp near ptr lbl218f
lbl10Af:
    push word ptr ds:[6A02h]
    push word ptr [bp-0Ah]
    call mf111
    add sp,4h
    or ax,ax
    jz short lbl148f
    push word ptr ds:[6A02h]
    mov ax,1h
    push ax
    call mf125
    add sp,4h
    push dx
    push ax
    lea ax,word ptr [bp-6h]
    push ss
    push ax
    mov ax,0Ah
lbl137b:
    mov dx,0F00Ch
    push dx
    push ax
    call mf13c
    add sp,0Ch
    jmp near ptr lbl218f
    nop
lbl148f:
    push word ptr ds:[6A04h]
    call mf14c
    add sp,2h
    cmp ax,122h
    jz short lbl172f
    push word ptr ds:[6A02h]
    mov ax,2h
    push ax
    call mf161
    add sp,4h
    push dx
    push ax
    mov ax,0Bh
    jmp near ptr lblAAb
    nop
lbl172f:
    mov ax,25D0h
    push ds
    push ax
    call mf177
    add sp,4h
    push word ptr [bp-8h]
    push word ptr ds:[6A04h]
    call mf186
    add sp,4h
    or ax,ax
    jz short lbl1CBf
    push word ptr ds:[6A02h]
    mov ax,1h
    push ax
    call mf19a
    add sp,4h
    push dx
    push ax
    lea ax,word ptr [bp-6h]
    push ss
    push ax
    push word ptr ds:[6A04h]
    mov ax,2h
    push ax
    call mf1b1
    add sp,4h
    push dx
    push ax
    mov ax,0Ch
    mov dx,0F00Ch
    push dx
    push ax
    call mf1c3
    add sp,10h
lbl1CBf:
    push word ptr ds:[6A02h]
    mov ax,1h
    push ax
    call mf1d3
    add sp,4h
    push dx
    push ax
    lea ax,word ptr [bp-6h]
    push ss
    push ax
    push word ptr ds:[6A04h]
    mov ax,2h
    push ax
    call mf1ea
    add sp,4h
    push dx
    push ax
    mov ax,0Dh
    mov dx,0F00Ch
    push dx
    push ax
    call mf1fc
    add sp,10h
    mov ax,1h
    push ax
    push word ptr ds:[6A02h]
    push word ptr ds:[6A04h]
    call mf210
    add sp,6h
lbl218b:
lbl218f:
    mov ax,1h
    jmp near ptr lbl2D0f
lbl21Ef:
    cmp word ptr ds:[6A04h],86h
    jnz short lbl22Cf
    mov ax,25BAh
    jmp short lbl22Ff
    nop
lbl22Cf:
    mov ax,25BFh
lbl22Ff:
    mov bx,ds
    mov di,ax
    lea si,word ptr [bp-6h]
    mov es,bx
    push ds
    mov cx,0FFFFh
    xor ax,ax
    repne scasb
    not cx
    sub di,cx
    db 87h, 0FEh ; override
    push ds
    push es
    pop ds
    pop es
    shr cx,1
    rep movsw
    adc cx,cx
    rep movsb
    pop ds
    mov ax,word ptr ds:[6A06h]
    cmp ax, offset mi256
    jz short lbl2B6f
    ja short lbl2CEf
    sub al,8h
    jz short lbl26Df
    sub al,0Bh
    jz short lbl280f
    sub al,10h
    jz short lbl29Ef
    sub al,9h
    jnz short lbl2CEf
lbl26Df:
    mov ax,7h
    mov dx,0F00Ch
    push dx
    push ax
    call mf275
    add sp,4h
    jmp short lbl218b
    nop
lbl280f:
    push word ptr ds:[6A04h]
    mov ax,1h
    push ax
    call mf288
    add sp,4h
    push dx
    push ax
    lea ax,word ptr [bp-6h]
    push ss
    push ax
    mov ax,5h
    jmp near ptr lbl137b
    nop
lbl29Ef:
    push word ptr ds:[6A04h]
    mov ax,12h
    push ax
    call mf2a6
    add sp,4h
    push dx
    push ax
    mov ax,6h
    jmp near ptr lblAAb
lbl2B6f:
    push word ptr ds:[6A04h]
    mov ax,12h
    push ax
    call mf2be
    add sp,4h
    push dx
    push ax
    mov ax,8h
    jmp near ptr lblAAb
lbl2CEf:
    xor ax,ax
lbl2D0f:
    pop si
    pop di
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
