_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi2:NEAR
    EXTRN mf11:FAR
    EXTRN mi13:NEAR
    EXTRN mf24:FAR
    EXTRN mi26:NEAR
    EXTRN mf38:FAR
    EXTRN mi40:NEAR
    EXTRN mf51:FAR
    EXTRN mi53:NEAR
    EXTRN mf65:FAR
    EXTRN mi67:NEAR
    EXTRN mi78:NEAR
    EXTRN mf88:FAR
    EXTRN mi91:NEAR
    EXTRN mf103:FAR
    EXTRN mi105:NEAR
    EXTRN mi112:NEAR
    EXTRN mi113:NEAR
    EXTRN mi119:NEAR
    EXTRN mf129:FAR
    EXTRN mi132:NEAR
    EXTRN mf141:FAR
    EXTRN mf141:FAR
    EXTRN mf141:FAR
    EXTRN mf141:FAR
    EXTRN mf141:FAR
    EXTRN mf141:FAR
    EXTRN mf141:FAR
    EXTRN mf141:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp, offset mi2
    push si
    push di
    mov ax,41CEh
    mov dx,ds
    push dx
    push ax
    push word ptr [bp+8h]
    push word ptr [bp+6h]
    call mf11
    add sp,8h
    cmp ax, offset mi13
    jnz short lbl26f
    jmp near ptr lbl2Ff
lbl26f:
    mov word ptr ds:[4190h],0h
    jmp near ptr lbl199f
lbl2Ff:
    mov ax,41D4h
    mov dx,ds
    push dx
    push ax
    push word ptr [bp+8h]
    push word ptr [bp+6h]
    call mf24
    add sp,8h
    cmp ax, offset mi26
    jnz short lbl4Cf
    jmp near ptr lbl5Bf
lbl4Cf:
    mov word ptr ds:[4190h],8h
    mov word ptr ds:[4196h],1h
    jmp near ptr lbl199f
lbl5Bf:
    mov ax,41D9h
    mov dx,ds
    push dx
    push ax
    push word ptr [bp+8h]
    push word ptr [bp+6h]
    call mf38
    add sp,8h
    cmp ax, offset mi40
    jnz short lbl78f
    jmp near ptr lbl80f
lbl78f:
    and word ptr ds:[4190h],0FFFFFFFFFFFFFFF7h
    jmp near ptr lbl199f
lbl80f:
    mov ax,41E0h
    mov dx,ds
    push dx
    push ax
    push word ptr [bp+8h]
    push word ptr [bp+6h]
    call mf51
    add sp,8h
    cmp ax, offset mi53
    jnz short lbl9Df
    jmp near ptr lblACf
lbl9Df:
    mov word ptr ds:[4190h],2h
    mov word ptr ds:[4196h],2h
    jmp near ptr lbl199f
lblACf:
    mov ax,41E6h
    mov dx,ds
    push dx
    push ax
    push word ptr [bp+8h]
    push word ptr [bp+6h]
    call mf65
    add sp,8h
    cmp ax, offset mi67
    jnz short lblC9f
    jmp near ptr lbl11Ef
lblC9f:
    mov word ptr ds:[4190h],0Ch
    cmp word ptr [bp+0Ah],30h
    jnl short lblD8f
    jmp near ptr lbl11Bf
lblD8f:
    cmp word ptr [bp+0Ah],39h
    jng short lblE1f
    jmp near ptr lbl11Bf
lblE1f:
    mov ax,word ptr [bp+0Ah]
    add ax, offset mi78
    mov word ptr ds:[4192h],ax
    cmp word ptr [bp+0Ch],0h
    jz short lblF3f
    jmp near ptr lblFCf
lblF3f:
    cmp word ptr [bp+0Eh],0h
    jnz short lblFCf
    jmp near ptr lbl11Bf
lblFCf:
    push word ptr [bp+0Eh]
    push word ptr [bp+0Ch]
    call mf88
    add sp,4h
    mov word ptr [bp-4h],ax
    cmp ax, offset mi91
    jnz short lbl115f
    jmp near ptr lbl11Bf
lbl115f:
    mov ax,word ptr [bp-4h]
    mov word ptr ds:[4194h],ax
lbl11Bf:
    jmp near ptr lbl199f
lbl11Ef:
    mov ax,41EBh
    mov dx,ds
    push dx
    push ax
    push word ptr [bp+8h]
    push word ptr [bp+6h]
    call mf103
    add sp,8h
    cmp ax, offset mi105
    jnz short lbl13Bf
    jmp near ptr lbl199f
lbl13Bf:
    cmp word ptr ds:[4190h],0FFFFFFFFFFFFFFFFh
    jnz short lbl145f
    jmp near ptr lbl153f
lbl145f:
    mov ax,word ptr ds:[4190h]
    and ax, offset mi112
    cmp ax, offset mi113
    jz short lbl153f
    jmp near ptr lbl159f
lbl153f:
    mov word ptr ds:[4190h],0Ah
lbl159f:
    mov word ptr ds:[4196h],4h
    mov ax,word ptr [bp+0Ah]
    add ax, offset mi119
    mov word ptr ds:[4198h],ax
    cmp word ptr [bp+0Ch],0h
    jz short lbl171f
    jmp near ptr lbl17Af
lbl171f:
    cmp word ptr [bp+0Eh],0h
    jnz short lbl17Af
    jmp near ptr lbl199f
lbl17Af:
    push word ptr [bp+0Eh]
    push word ptr [bp+0Ch]
    call mf129
    add sp,4h
    mov word ptr [bp-4h],ax
    cmp ax, offset mi132
    jnz short lbl193f
    jmp near ptr lbl199f
lbl193f:
    mov ax,word ptr [bp-4h]
    mov word ptr ds:[419Ah],ax
lbl199f:
    pop di
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
