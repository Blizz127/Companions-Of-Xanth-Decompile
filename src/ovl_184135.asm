_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf180:FAR
    EXTRN mf1f4:FAR
    EXTRN mi115:NEAR
    EXTRN mf198:FAR
    EXTRN mf240:FAR
    EXTRN mf133:FAR
    EXTRN mf230:FAR
    EXTRN mi9:NEAR
    EXTRN mf1d4:FAR
    EXTRN mf5c:FAR
    EXTRN mf158:FAR
    EXTRN mi10d:NEAR
    EXTRN mf9e:FAR
    EXTRN mf1c4:FAR
    EXTRN mf121:FAR
    EXTRN mfbd:FAR
    EXTRN mf80:FAR
    EXTRN mf220:FAR
    EXTRN mf208:FAR
    EXTRN mi112:NEAR
    EXTRN mf16c:FAR
    EXTRN mi14:NEAR
    EXTRN mf1e4:FAR
    EXTRN mfd4:FAR
    EXTRN mf1ac:FAR
    EXTRN mf146:FAR
    EXTRN mf105:FAR
    EXTRN mff3:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,2h
    mov ax,word ptr [bp+6h]
    sub ax, offset mi9
    jz short lbl11f
    jmp near ptr lbl24Ef
lbl11f:
    mov ax,word ptr ds:[6A06h]
    cmp ax, offset mi14
    jnz short lbl1Cf
    jmp near ptr lbl1ECf
lbl1Cf:
    jna short lbl21f
    jmp near ptr lbl24Ef
lbl21f:
    cmp al,3Ah
    jz short lbl54f
    ja short lbl3Cf
    sub al,13h
    jz short lbl54f
    sub al,19h
    jnz short lbl32f
    jmp near ptr lblCCf
lbl32f:
    sub al,0Ch
    jnz short lbl39f
    jmp near ptr lblE4f
lbl39f:
    jmp near ptr lbl24Ef
lbl3Cf:
    sub al,44h
    jnz short lbl43f
    jmp near ptr lbl164f
lbl43f:
    dec al
    jnz short lbl4Af
    jmp near ptr lbl178f
lbl4Af:
    sub al,6h
    jnz short lbl51f
    jmp near ptr lbl190f
lbl51f:
    jmp near ptr lbl24Ef
lbl54f:
    mov ax,0Ah
    push ax
    push word ptr ds:[6A04h]
    call mf5c
    add sp,4h
    or ax,ax
    jz short lbl8Ef
    cmp word ptr ds:[256h],0CDh
    jz short lbl78f
    cmp word ptr ds:[256h],0EDh
    jnz short lbl8Ef
lbl78f:
    push word ptr ds:[2ECh]
    push word ptr ds:[2EAh]
    call mf80
    add sp,4h
    mov word ptr [bp-2h],ax
    jmp short lbl93f
    nop
lbl8Ef:
    mov word ptr [bp-2h],0h
lbl93f:
    push word ptr [bp-2h]
    mov ax,0Ah
    push ax
    push word ptr ds:[6A04h]
    call mf9e
    add sp,4h
    or ax,ax
    jz short lblB0f
    mov ax,2FF8h
    jmp short lblB3f
    nop
lblB0f:
    mov ax,2FFAh
lblB3f:
    push ds
    push ax
    mov ax,33h
    mov dx,0F033h
    push dx
    push ax
    call mfbd
    add sp,0Ah
lblC5b:
    mov ax,1h
    jmp near ptr lbl250f
    nop
lblCCf:
    push word ptr ds:[6A04h]
    mov ax,2h
    push ax
    call mfd4
    add sp,4h
    push dx
    push ax
    mov ax,35h
    jmp short lbl153f
    nop
lblE4f:
    cmp word ptr ds:[290h],0h
    jz short lbl13Ef
    push word ptr ds:[6A02h]
    mov ax,22h
    push ax
    call mff3
    add sp,4h
    push dx
    push ax
    mov ax,11h
    push ax
    push word ptr ds:[6A02h]
    call mf105
    add sp,4h
    cmp ax, offset mi10d
    db 1Bh, 0C0h ; override
    and ax, offset mi112
    add ax, offset mi115
    push ax
    push word ptr ds:[6A04h]
    mov ax,12h
    push ax
    call mf121
    add sp,4h
    push dx
    push ax
    mov ax,37h
    mov dx,0F033h
    push dx
    push ax
    call mf133
    add sp,0Eh
    jmp short lblC5b
    nop
lbl13Ef:
    push word ptr ds:[6A04h]
    mov ax,12h
    push ax
    call mf146
    add sp,4h
    push dx
    push ax
    mov ax,38h
lbl153b:
lbl153f:
    mov dx,0F033h
    push dx
    push ax
    call mf158
    add sp,8h
    jmp near ptr lblC5b
    nop
lbl164f:
    mov ax,34h
    mov dx,0F033h
    push dx
    push ax
    call mf16c
lbl171b:
    add sp,4h
    jmp near ptr lblC5b
    nop
lbl178f:
    push word ptr ds:[6A04h]
    mov ax,2h
    push ax
    call mf180
    add sp,4h
    push dx
    push ax
    mov ax,36h
    jmp short lbl153b
    nop
lbl190f:
    mov ax,0Ah
    push ax
    push word ptr ds:[6A04h]
    call mf198
    add sp,4h
    or ax,ax
    jnz short lbl1BCf
    push word ptr ds:[6A04h]
    mov ax,12h
    push ax
    call mf1ac
    add sp,4h
    push dx
    push ax
    mov ax,3Bh
    jmp short lbl153b
    nop
lbl1BCf:
    mov ax,3Ch
    mov dx,0F033h
    push dx
    push ax
    call mf1c4
    add sp,4h
    mov ax,0Ah
    push ax
    push word ptr ds:[6A04h]
    call mf1d4
    add sp,4h
    mov ax,16Eh
lbl1DFb:
    push ax
    push word ptr ds:[6A04h]
    call mf1e4
    jmp short lbl171b
    nop
lbl1ECf:
    mov ax,0Ah
    push ax
    push word ptr ds:[6A04h]
    call mf1f4
    add sp,4h
    or ax,ax
    jz short lbl218f
    push word ptr ds:[6A04h]
    mov ax,12h
    push ax
    call mf208
    add sp,4h
    push dx
    push ax
    mov ax,39h
    jmp near ptr lbl153b
lbl218f:
    mov ax,3Ah
    mov dx,0F033h
    push dx
    push ax
    call mf220
    add sp,4h
    mov ax,0Ah
    push ax
    push word ptr ds:[6A04h]
    call mf230
    add sp,4h
    push word ptr ds:[2ECh]
    push word ptr ds:[2EAh]
    call mf240
    add sp,4h
    add ax,16Eh
    jmp short lbl1DFb
    nop
lbl24Ef:
    xor ax,ax
lbl250f:
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
