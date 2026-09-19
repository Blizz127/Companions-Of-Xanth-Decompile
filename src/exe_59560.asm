_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf87:FAR
    EXTRN mf26b:FAR
    EXTRN mf1c7:FAR
    EXTRN mf144:FAR
    EXTRN mf191:FAR
    EXTRN mf226:FAR
    EXTRN mf1f0:FAR
    EXTRN mff2:FAR
    EXTRN mf44:FAR
    EXTRN mf11d:FAR
    EXTRN mi17d:NEAR
    EXTRN mf27a:FAR
    EXTRN mfd6:FAR
    EXTRN mf170:FAR
    EXTRN mf1e:FAR
    EXTRN mf24b:FAR
    EXTRN mf57:FAR
    EXTRN mf23b:FAR
    EXTRN mfdf:FAR
    EXTRN mffe:FAR
    EXTRN mf20f:FAR
    EXTRN mf107:FAR
    EXTRN mf68:FAR
    EXTRN mf1b7:FAR
    EXTRN mf1a7:FAR
    EXTRN mfb0:FAR
    EXTRN mf1d7:FAR
    EXTRN mf31:FAR
    EXTRN mi178:NEAR
    EXTRN mf9a:FAR
    EXTRN mf1ff:FAR
    EXTRN mf128:FAR
    EXTRN mf134:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,0Ah
    cmp word ptr [bp+6h],0h
    jg short lbl0Ff
    jmp near ptr lbl28Cf
lbl0Ff:
    mov ax,word ptr ds:[84Ch]
    cmp word ptr [bp+6h],ax
    jng short lbl1Af
    jmp near ptr lbl28Cf
lbl1Af:
    mov ax,1h
    push ax
    call mf1e
    add sp,2h
    mov word ptr [bp-4h],ax
    push word ptr ds:[256h]
    mov ax,1h
    push ax
    call mf31
    add sp,4h
    or ax,ax
    jnz short lblA2f
    mov ax,10h
    push ax
    push word ptr [bp-4h]
    call mf44
    add sp,4h
    or ax,ax
    jnz short lblA2f
    push word ptr [bp-4h]
    mov ax,2h
    push ax
    call mf57
    add sp,4h
    push dx
    push ax
    mov ax,0Bh
    push ax
    push word ptr [bp-4h]
    call mf68
    add sp,4h
    or ax,ax
    jz short lbl7Af
    mov ax,79Ah
    jmp short lbl7Df
    nop
lbl7Af:
    mov ax,79Eh
lbl7Df:
    push ds
    push ax
    mov ax,1h
    mov dx,0F007h
    push dx
    push ax
    call mf87
    add sp,0Ch
    xor ax,ax
    push ax
    push word ptr ds:[256h]
    mov ax,1h
    push ax
    call mf9a
    add sp,6h
lblA2f:
    mov ax,word ptr [bp+6h]
    mov word ptr ds:[6A20h],ax
    mov ax,0Fh
    push ax
    push word ptr ds:[256h]
    call mfb0
    add sp,4h
    or ax,ax
    jz short lblBFf
    jmp near ptr lbl28Cf
lblBFf:
    mov ax,word ptr ds:[256h]
    mov word ptr ds:[6A22h],ax
    mov ax,word ptr [bp+6h]
    mov word ptr ds:[256h],ax
    mov ax,10h
    push ax
    mov ax,word ptr ds:[258h]
    mov word ptr [bp-2h],ax
    push ax
    call mfd6
    add sp,2h
    push ax
    call mfdf
    add sp,4h
    or ax,ax
    jz short lbl113f
lblEBb:
    mov ax,10h
    push ax
    push word ptr [bp-2h]
    call mff2
    add sp,2h
    mov word ptr [bp-2h],ax
    push ax
    call mffe
    add sp,2h
    push ax
    call mf107
    add sp,4h
    or ax,ax
    jnz short lblEBb
lbl113f:
    xor ax,ax
    push ax
    push word ptr ds:[256h]
    push word ptr [bp-2h]
    call mf11d
    add sp,6h
    xor ax,ax
    push ax
    call mf128
    add sp,2h
    push word ptr ds:[256h]
    call mf134
    add sp,2h
    mov ax,0Dh
    push ax
    push word ptr ds:[256h]
    call mf144
    add sp,4h
    cmp byte ptr ds:[25Ah],2h
    jnz short lbl15Af
    mov word ptr [bp-8h],0Bh
    jmp short lbl183f
lbl15Af:
    cmp byte ptr ds:[25Ah],0h
    jnz short lbl168f
    mov word ptr [bp-8h],0Ch
    jmp short lbl183f
lbl168f:
    mov ax,5h
    push ax
    push word ptr ds:[256h]
    call mf170
    add sp,4h
    cmp ax, offset mi178
    db 1Bh, 0C0h ; override
    add ax, offset mi17d
    mov word ptr [bp-8h],ax
lbl183f:
    cmp byte ptr ds:[783h],0h
    jnz short lbl19Cf
    push word ptr [bp-8h]
    push word ptr ds:[256h]
    call mf191
    add sp,4h
    jmp short lbl1AFf
    nop
lbl19Cf:
    cmp byte ptr ds:[784h],0h
    jz short lbl1AFf
    mov ax,20h
    push ax
    call mf1a7
    add sp,2h
lbl1AFf:
    mov ax,0Eh
    push ax
    push word ptr ds:[256h]
    call mf1b7
    add sp,4h
    mov ax,5h
    push ax
    push word ptr ds:[256h]
    call mf1c7
    add sp,4h
    or ax,ax
    jnz short lbl217f
    push word ptr ds:[256h]
    call mf1d7
    add sp,2h
    mov word ptr [bp-0Ah],ax
    or ax,ax
    jz short lbl207f
    xor ax,ax
    push ax
    mov cx,1h
    push cx
    push word ptr [bp-0Ah]
    call mf1f0
    add sp,6h
    xor ax,ax
    push ax
    push word ptr ds:[256h]
    call mf1ff
    add sp,4h
lbl207f:
    mov ax,5h
    push ax
    push word ptr ds:[256h]
    call mf20f
    add sp,4h
lbl217f:
    cmp word ptr ds:[798h],0h
    jz short lbl282f
    push word ptr ds:[256h]
    push word ptr ds:[798h]
    call mf226
    add sp,4h
    or ax,ax
    jnz short lbl282f
    push ax
    push word ptr ds:[256h]
    push word ptr ds:[798h]
    call mf23b
    add sp,6h
    mov ax,1Ah
    push ax
    push word ptr ds:[798h]
    call mf24b
    add sp,4h
    or ax,ax
    jnz short lbl282f
    cmp byte ptr ds:[783h],0h
    jnz short lbl282f
    mov ax,7A2h
    push ds
    push ax
    push word ptr ds:[798h]
    mov ax,52h
    push ax
    call mf26b
    add sp,8h
    push dx
    push ax
    mov ax,7A9h
    push ds
    push ax
    call mf27a
    add sp,8h
lbl282f:
    mov byte ptr ds:[783h],0h
    mov ax,1h
    jmp short lbl28Ef
lbl28Cf:
    xor ax,ax
lbl28Ef:
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
