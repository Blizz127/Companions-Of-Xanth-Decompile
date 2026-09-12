_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi4:NEAR
    EXTRN mi12:NEAR
    EXTRN mf18:FAR
    EXTRN mf26:FAR
    EXTRN mi32:NEAR
    EXTRN mf63:FAR
    EXTRN mf70:FAR
    EXTRN mf79:FAR
    EXTRN mf87:FAR
    EXTRN mf92:FAR
    EXTRN mf97:FAR
    EXTRN mf102:FAR
    EXTRN mf111:FAR
    EXTRN mf118:FAR
    EXTRN mf125:FAR
    EXTRN mf133:FAR
    EXTRN mf145:FAR
    EXTRN mf157:FAR
    EXTRN mf172:FAR
    EXTRN mf179:FAR
    EXTRN mf188:FAR
    EXTRN mf195:FAR
    EXTRN mf204:FAR
    EXTRN mf212:FAR
    EXTRN mf217:FAR
    EXTRN mf222:FAR
    EXTRN mf229:FAR
    EXTRN mf240:FAR
    EXTRN mf247:FAR
    EXTRN mf269:FAR
    EXTRN mf274:FAR
    EXTRN mf283:FAR
    EXTRN mf283:FAR
    EXTRN mf283:FAR
    EXTRN mf283:FAR
    EXTRN mf283:FAR
    EXTRN mf283:FAR
    EXTRN mf283:FAR
    EXTRN mf283:FAR
    EXTRN mf283:FAR
    EXTRN mf283:FAR
    EXTRN mf283:FAR
    EXTRN mf283:FAR
    EXTRN mf283:FAR
    EXTRN mf283:FAR
    EXTRN mf283:FAR
    EXTRN mf283:FAR
    EXTRN mf283:FAR
    EXTRN mf283:FAR
    EXTRN mf283:FAR
    EXTRN mf283:FAR
    EXTRN mf283:FAR
    EXTRN mf283:FAR
    EXTRN mf283:FAR
    EXTRN mf283:FAR
    EXTRN mf283:FAR
    EXTRN mf283:FAR
    EXTRN mf283:FAR
    EXTRN mf283:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,4h
    mov ax,word ptr [bp+6h]
    sub ax, offset mi4
    jz short lbl16f
    dec ax
    dec ax
    jz short lbl4Af
    jmp near ptr lbl2F4f
    nop
lbl16f:
    mov ax,word ptr ds:[6A06h]
    sub ax, offset mi12
    jz short lbl21f
    jmp near ptr lbl2F4f
lbl21f:
    push word ptr ds:[6A02h]
    mov ax,2h
    push ax
    call mf18
    add sp,4h
    push dx
    push ax
    mov ax,2Ch
lbl36b:
    mov dx,0F005h
    push dx
    push ax
    call mf26
    add sp,8h
lbl43b:
    mov ax,1h
    jmp near ptr lbl2F6f
    nop
lbl4Af:
    mov ax,word ptr ds:[6A06h]
    cmp ax, offset mi32
    jnz short lbl55f
    jmp near ptr lbl2B8f
lbl55f:
    jna short lbl5Af
    jmp near ptr lbl2F4f
lbl5Af:
    cmp al,2Ch
    jnz short lbl61f
    jmp near ptr lbl1BEf
lbl61f:
    ja short lbl78f
    sub al,8h
    jz short lbl90f
    sub al,7h
    jnz short lbl6Ef
    jmp near ptr lbl112f
lbl6Ef:
    sub al,4h
    jnz short lbl75f
    jmp near ptr lbl1A4f
lbl75f:
    jmp near ptr lbl2F4f
lbl78f:
    sub al,38h
    jnz short lbl7Ff
    jmp near ptr lbl2F4f
lbl7Ff:
    sub al,7h
    jnz short lbl86f
    jmp near ptr lbl25Ef
lbl86f:
    sub al,5h
    jnz short lbl8Df
    jmp near ptr lbl27Ef
lbl8Df:
    jmp near ptr lbl2F4f
lbl90f:
    mov ax,0Eh
    push ax
    push word ptr ds:[6A04h]
    call mf63
    add sp,4h
    or ax,ax
    jnz short lblBCf
    push word ptr ds:[6A04h]
    mov ax,12h
    push ax
    call mf70
    add sp,4h
    push dx
    push ax
    mov ax,21h
    jmp near ptr lbl36b
lblBCf:
    push word ptr ds:[6A04h]
    mov ax,2h
    push ax
    call mf79
    add sp,4h
    push dx
    push ax
    mov ax,22h
    mov dx,0F005h
    push dx
    push ax
    call mf87
    add sp,8h
    mov ax,0Eh
    push ax
    push word ptr ds:[6A04h]
    call mf92
    add sp,4h
    mov ax,2Ch
    push ax
    push word ptr ds:[6A04h]
    call mf97
    add sp,4h
    mov ax,12Ah
lbl101b:
    push ax
    push word ptr ds:[6A04h]
    call mf102
lbl10Bb:
    add sp,4h
    jmp near ptr lbl43b
    nop
lbl112f:
    cmp byte ptr ds:[323h],0h
    jz short lbl194f
    mov ax,1h
    push ax
    push word ptr ds:[6A04h]
    call mf111
    add sp,4h
    or ax,ax
    jnz short lbl164f
    push word ptr ds:[6A04h]
    mov ax,26h
    push ax
    call mf118
    add sp,4h
    push dx
    push ax
    push word ptr ds:[6A04h]
    mov ax,2h
    push ax
    call mf125
    add sp,4h
    push dx
    push ax
    mov ax,27h
    mov dx,0F005h
    push dx
    push ax
    call mf133
    add sp,0Ch
    jmp near ptr lbl43b
lbl164f:
    inc word ptr ds:[2C4h]
    cmp word ptr ds:[2C4h],0Ch
    jng short lbl174f
    mov ax,28h
    jmp short lbl197f
lbl174f:
    mov ax,29h
    mov dx,0F005h
    push dx
    push ax
    call mf145
    add sp,4h
    cmp word ptr ds:[2C4h],0Ch
    jz short lbl18Ef
    jmp near ptr lbl43b
lbl18Ef:
    mov ax,2Ah
    jmp short lbl197f
    nop
lbl194f:
    mov ax,2Bh
lbl197b:
lbl197f:
    mov dx,0F005h
    push dx
    push ax
    call mf157
    jmp near ptr lbl10Bb
lbl1A4f:
    cmp byte ptr ds:[323h],0h
    jz short lbl1B0f
    mov ax,1Ah
    jmp short lbl1B3f
lbl1B0f:
    mov ax,1Bh
lbl1B3f:
    mov dx,0F005h
    push dx
    push ax
    mov ax,19h
    jmp near ptr lbl36b
lbl1BEf:
    mov ax,1h
    push ax
    push word ptr ds:[6A04h]
    call mf172
    add sp,4h
    or ax,ax
    jnz short lbl1EAf
    push word ptr ds:[6A04h]
    mov ax,2h
    push ax
    call mf179
    add sp,4h
    push dx
    push ax
    mov ax,1Eh
    jmp near ptr lbl36b
lbl1EAf:
    mov ax,0Eh
    push ax
    push word ptr ds:[6A04h]
    call mf188
    add sp,4h
    or ax,ax
    jz short lbl216f
    push word ptr ds:[6A04h]
    mov ax,12h
    push ax
    call mf195
    add sp,4h
    push dx
    push ax
    mov ax,1Fh
    jmp near ptr lbl36b
lbl216f:
    push word ptr ds:[6A04h]
    mov ax,2h
    push ax
    call mf204
    add sp,4h
    push dx
    push ax
    mov ax,20h
    mov dx,0F005h
    push dx
    push ax
    call mf212
    add sp,8h
    mov ax,0Eh
    push ax
    push word ptr ds:[6A04h]
    call mf217
    add sp,4h
    mov ax,8h
    push ax
    push word ptr ds:[6A04h]
    call mf222
    add sp,4h
    mov ax,13Ch
    jmp near ptr lbl101b
lbl25Ef:
    mov ax,0Eh
    push ax
    push word ptr ds:[6A04h]
    call mf229
    add sp,4h
    or ax,ax
    jnz short lbl278f
    mov ax,25h
    jmp near ptr lbl197b
lbl278f:
    mov ax,26h
    jmp near ptr lbl197b
lbl27Ef:
    mov ax,1h
    push ax
    push word ptr ds:[6A04h]
    call mf240
    add sp,4h
    or ax,ax
    jz short lbl2AAf
    push word ptr ds:[6A04h]
    mov ax,2h
    push ax
    call mf247
    add sp,4h
    push dx
    push ax
    mov ax,1Ch
    jmp near ptr lbl36b
lbl2AAf:
    cmp byte ptr ds:[323h],0h
    jz short lbl2F4f
    mov ax,1Dh
    jmp near ptr lbl197b
    nop
lbl2B8f:
    cmp byte ptr ds:[323h],0h
    jz short lbl2C6f
    mov ax,22A6h
    mov dx,ds
    jmp short lbl2CCf
lbl2C6f:
    mov ax,23h
    mov dx,0F005h
lbl2CCf:
    mov word ptr [bp-4h],ax
    mov word ptr [bp-2h],dx
    push dx
    push ax
    call mf269
    add sp,4h
    push word ptr ds:[6A04h]
    mov ax,22h
    push ax
    call mf274
    add sp,4h
    push dx
    push ax
    mov ax,24h
    jmp near ptr lbl36b
lbl2F4f:
    xor ax,ax
lbl2F6f:
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
