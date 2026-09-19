_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf14b:FAR
    EXTRN mf1c6:FAR
    EXTRN mffc:FAR
    EXTRN mf8d:FAR
    EXTRN mf19b:FAR
    EXTRN mfb5:FAR
    EXTRN mi10e:NEAR
    EXTRN mfd7:FAR
    EXTRN mf11a:FAR
    EXTRN mfe7:FAR
    EXTRN mf18e:FAR
    EXTRN mf179:FAR
    EXTRN mf9c:FAR
    EXTRN mi51:NEAR
    EXTRN mf94:FAR
    EXTRN mfc7:FAR
    EXTRN mf109:FAR
    EXTRN mf123:FAR
    EXTRN mf49:FAR
    EXTRN mf1b5:FAR
    EXTRN mf1d6:FAR
    EXTRN mf39:FAR
    EXTRN mf15b:FAR
    EXTRN mf79:FAR
    EXTRN mff:FAR
    EXTRN mi1a0:NEAR
    EXTRN mf169:FAR
    EXTRN mf5f:FAR
    EXTRN mfaa:FAR
    EXTRN mf1ac:FAR
    EXTRN mf134:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,0Ch
    push si
    mov word ptr [bp-6h],0h
    push word ptr [bp+6h]
    call mff
    add sp,2h
    mov ax,word ptr [bp+8h]
    or ax,ax
    jz short lbl36f
    dec ax
    jz short lbl68f
    dec ax
    jnz short lbl27f
    jmp near ptr lblB2f
lbl27f:
    dec ax
    jnz short lbl2Df
    jmp near ptr lblC0f
lbl2Df:
    dec ax
    jnz short lbl33f
    jmp near ptr lbl144f
lbl33f:
    jmp near ptr lbl1DEf
lbl36f:
    push word ptr [bp+0Ah]
    call mf39
    add sp,2h
    or ax,ax
    jz short lbl5Ff
    mov ax,1h
    push ax
    call mf49
    add sp,2h
    cmp ax, offset mi51
    db 1Bh, 0C0h ; override
    and ax,0FE20h
    add ah,2h
    mov word ptr [bp-6h],ax
lbl5Fb:
lbl5Ff:
    call mf5f
    jmp near ptr lbl1DEf
    nop
lbl68f:
    lea ax,word ptr [bp-0Ah]
    push ss
    push ax
    lea ax,word ptr [bp-8h]
    push ss
    push ax
    mov ax,2h
    push ax
    push word ptr [bp+6h]
    call mf79
    add sp,0Ch
    or ax,ax
    jz short lblA6f
    mov ax,word ptr [bp+0Ah]
    cmp word ptr [bp-0Ah],ax
    jnl short lbl94f
    call mf8d
    jmp short lbl9Bf
lbl94f:
    call mf94
    neg ax
lbl9Bf:
    push ax
    call mf9c
lblA1b:
    add sp,2h
    jmp short lbl5Fb
lblA6f:
    mov ax,1h
    push ax
    call mfaa
    jmp short lblA1b
    nop
lblB2f:
    push word ptr [bp+0Ah]
    call mfb5
    add sp,2h
    jmp near ptr lbl1DEf
lblC0f:
    mov ax,3h
    push ax
    push word ptr [bp+6h]
    call mfc7
    add sp,4h
    mov word ptr [bp-0Ch],0h
lblD4b:
    push word ptr [bp+6h]
    call mfd7
    add sp,2h
    or ax,ax
    jng short lblF2f
    mov ax,0FFFFh
    push ax
    call mfe7
    add sp,2h
    jmp short lbl109f
    nop
lblF2f:
    cmp word ptr [bp-0Ch],0h
    jnz short lbl109f
    mov ax,1h
    push ax
    call mffc
    add sp,2h
    mov word ptr [bp-0Ch],1h
lbl109f:
    call mf109
    add ax, offset mi10e
    adc dx,0h
    mov word ptr [bp-4h],ax
    mov word ptr [bp-2h],dx
lbl11Ab:
    call mf11a
    or ax,ax
    jz short lbl134f
    call mf123
    cmp dx,word ptr [bp-2h]
    jl short lbl11Ab
    jg short lbl134f
    cmp ax,word ptr [bp-4h]
    jc short lbl11Ab
lbl134f:
    call mf134
    or ax,ax
    jnz short lblD4b
    mov ax,3h
    jmp near ptr lbl1D2f
    nop
lbl144f:
    mov ax,4h
    push ax
    push word ptr [bp+6h]
    call mf14b
    add sp,4h
    mov word ptr [bp-0Ch],0h
lbl158b:
    push word ptr [bp+6h]
    call mf15b
    add sp,2h
    inc ax
    push word ptr [bp+6h]
    mov si,ax
    call mf169
    add sp,2h
    cmp si,ax
    jnl short lbl184f
    mov ax,1h
    push ax
    call mf179
    add sp,2h
    jmp short lbl19Bf
    nop
lbl184f:
    cmp word ptr [bp-0Ch],0h
    jnz short lbl19Bf
    mov ax,1h
    push ax
    call mf18e
    add sp,2h
    mov word ptr [bp-0Ch],1h
lbl19Bf:
    call mf19b
    add ax, offset mi1a0
    adc dx,0h
    mov word ptr [bp-4h],ax
    mov word ptr [bp-2h],dx
lbl1ACb:
    call mf1ac
    or ax,ax
    jz short lbl1C6f
    call mf1b5
    cmp dx,word ptr [bp-2h]
    jl short lbl1ACb
    jg short lbl1C6f
    cmp ax,word ptr [bp-4h]
    jc short lbl1ACb
lbl1C6f:
    call mf1c6
    or ax,ax
    jnz short lbl158b
    mov ax,4h
lbl1D2f:
    push ax
    push word ptr [bp+6h]
    call mf1d6
    add sp,4h
lbl1DEf:
    mov ax,word ptr [bp-6h]
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
