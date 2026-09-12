_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi4:NEAR
    EXTRN mi12:NEAR
    EXTRN mf18:FAR
    EXTRN mf25:FAR
    EXTRN mf33:FAR
    EXTRN mi39:NEAR
    EXTRN mf66:FAR
    EXTRN mf90:FAR
    EXTRN mf96:FAR
    EXTRN mf103:FAR
    EXTRN mf114:FAR
    EXTRN mf124:FAR
    EXTRN mf132:FAR
    EXTRN mf139:FAR
    EXTRN mf147:FAR
    EXTRN mf155:FAR
    EXTRN mf158:FAR
    EXTRN mf167:FAR
    EXTRN mf174:FAR
    EXTRN mf182:FAR
    EXTRN md196:NEAR
    EXTRN mf201:FAR
    EXTRN mf217:FAR
    EXTRN mf227:FAR
    EXTRN mf234:FAR
    EXTRN mf244:FAR
    EXTRN mf244:FAR
    EXTRN mf244:FAR
    EXTRN mf244:FAR
    EXTRN mf244:FAR
    EXTRN mf244:FAR
    EXTRN mf244:FAR
    EXTRN mf244:FAR
    EXTRN mf244:FAR
    EXTRN mf244:FAR
    EXTRN mf244:FAR
    EXTRN mf244:FAR
    EXTRN mf244:FAR
    EXTRN mf244:FAR
    EXTRN mf244:FAR
    EXTRN mf244:FAR
    EXTRN mf244:FAR
    EXTRN mf244:FAR
    EXTRN mf244:FAR
    EXTRN mf244:FAR
    EXTRN mf244:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,4h
    mov ax,word ptr [bp+6h]
    sub ax, offset mi4
    jz short lbl16f
    dec ax
    dec ax
    jz short lbl5Cf
    jmp near ptr lbl26Af
    nop
lbl16f:
    mov ax,word ptr ds:[6A06h]
    sub ax, offset mi12
    jz short lbl21f
    jmp near ptr lbl26Af
lbl21f:
    push word ptr ds:[6A04h]
    mov ax,2h
    push ax
    call mf18
    add sp,4h
    push dx
    push ax
    push word ptr ds:[6A02h]
    mov ax,12h
    push ax
    call mf25
    add sp,4h
    push dx
    push ax
    mov ax,27h
lbl48b:
    mov dx,0F048h
    push dx
    push ax
    call mf33
    add sp,0Ch
lbl55b:
    mov ax,1h
    jmp near ptr lbl26Cf
    nop
lbl5Cf:
    mov ax,word ptr ds:[6A06h]
    cmp ax, offset mi39
    jnz short lbl67f
    jmp near ptr lbl1A6f
lbl67f:
    jna short lbl6Cf
    jmp near ptr lbl26Af
lbl6Cf:
    cmp al,2Ch
    jz short lbl90f
    ja short lbl7Ef
    sub al,8h
    jz short lbl90f
    sub al,0Bh
    jz short lbl96f
    jmp near ptr lbl26Af
    nop
lbl7Ef:
    sub al,38h
    jz short lblBEf
    sub al,0Ch
    jz short lblE8f
    dec al
    jnz short lbl8Df
    jmp near ptr lbl1A0f
lbl8Df:
    jmp near ptr lbl26Af
lbl90f:
    mov ax,22h
    jmp near ptr lbl14Bf
lbl96f:
    mov ax,1B1h
    push ax
    push word ptr ds:[6A04h]
    call mf66
    add sp,4h
    or ax,ax
    jz short lblB2f
    mov ax,1Dh
    mov dx,0F048h
    jmp short lblB5f
lblB2f:
    xor ax,ax
    cwd
lblB5f:
    push dx
    push ax
    mov ax,1Ch
    jmp near ptr lbl1CFf
    nop
lblBEf:
    cmp word ptr ds:[6A02h],1DBh
    jz short lblD1f
    cmp word ptr ds:[6A02h],1DAh
    jz short lblD1f
    jmp near ptr lbl26Af
lblD1f:
    mov ax,1DBh
    push ax
    push word ptr ds:[6A04h]
    mov ax,4Fh
    push ax
    call mf90
    add sp,6h
    jmp near ptr lbl26Cf
lblE8f:
    mov ax,1h
    push ax
    push word ptr ds:[6A04h]
    call mf96
    add sp,4h
    or ax,ax
    jz short lbl114f
    push word ptr ds:[6A04h]
    mov ax,2h
    push ax
    call mf103
    add sp,4h
    push dx
    push ax
    mov ax,1Eh
    jmp near ptr lbl1CFf
lbl114f:
    cmp word ptr ds:[256h],1B1h
    jnz short lbl134f
    push word ptr ds:[6A04h]
    mov ax,22h
    push ax
    call mf114
    add sp,4h
    push dx
    push ax
    mov ax,1Fh
    jmp near ptr lbl1CFf
lbl134f:
    mov ax,1CEh
    push ax
    mov ax,1D4h
    push ax
    call mf124
    add sp,4h
    or ax,ax
    jz short lbl15Cf
    mov ax,20h
lbl14Bb:
lbl14Bf:
    mov dx,0F048h
    push dx
    push ax
    call mf132
    add sp,4h
    jmp near ptr lbl55b
    nop
lbl15Cf:
    push word ptr ds:[6A04h]
    mov ax,2h
    push ax
    call mf139
    add sp,4h
    push dx
    push ax
    mov ax,21h
    mov dx,0F048h
    push dx
    push ax
    call mf147
    add sp,8h
    xor ax,ax
    push ax
    mov ax,1h
    push ax
    mov ax,0Ah
    push ax
    call mf155
    add sp,6h
    push word ptr ds:[6A04h]
    call mf158
    add sp,2h
    jmp near ptr lbl55b
lbl1A0f:
    mov ax,23h
    jmp short lbl14Bb
    nop
lbl1A6f:
    mov ax,1h
    push ax
    push word ptr ds:[6A04h]
    call mf167
    add sp,4h
    or ax,ax
    jnz short lbl1E0f
    push word ptr ds:[6A04h]
    mov ax,2h
    push ax
    call mf174
    add sp,4h
    push dx
    push ax
    mov ax,24h
lbl1CFf:
    mov dx,0F048h
    push dx
    push ax
    call mf182
    add sp,8h
    jmp near ptr lbl55b
    nop
lbl1E0f:
    mov ax,word ptr ds:[6A02h]
    sub ax,1DBh
    jnz short lbl1EBf
    jmp near ptr lbl55b
lbl1EBf:
    mov es, ds:[5B32h]
    mov bx,word ptr ds:[6A02h]
    mov ax,bx
    add bx,bx
    add bx,ax
    add bx,bx
    cmp byte ptr es:[bx+md196],5h
    jnz short lbl242f
    mov ax,16h
    push ax
    push word ptr ds:[6A02h]
    call mf201
    add sp,4h
    or ax,ax
    jz short lbl21Ef
    mov ax,39C0h
    mov dx,ds
    jmp short lbl221f
lbl21Ef:
    xor ax,ax
    cwd
lbl221f:
    mov word ptr [bp-4h],ax
    mov word ptr [bp-2h],dx
    push dx
    push ax
    push word ptr ds:[6A02h]
    mov ax,11h
    push ax
    call mf217
    add sp,4h
    push dx
    push ax
    mov ax,25h
    jmp near ptr lbl48b
    nop
lbl242f:
    push ax
    mov ax,2h
    push ax
    call mf227
    add sp,4h
    push dx
    push ax
    push word ptr ds:[6A04h]
    mov ax,2h
    push ax
    call mf234
    add sp,4h
    push dx
    push ax
    mov ax,26h
    jmp near ptr lbl48b
    nop
lbl26Af:
    xor ax,ax
lbl26Cf:
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
