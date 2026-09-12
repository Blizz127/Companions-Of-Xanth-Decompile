_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi4:NEAR
    EXTRN mi12:NEAR
    EXTRN mf18:FAR
    EXTRN mf25:FAR
    EXTRN mf33:FAR
    EXTRN mi39:NEAR
    EXTRN mf58:FAR
    EXTRN mf64:FAR
    EXTRN mf72:FAR
    EXTRN mf82:FAR
    EXTRN md93:NEAR
    EXTRN mf101:FAR
    EXTRN mf108:FAR
    EXTRN mf118:FAR
    EXTRN mf126:FAR
    EXTRN mf134:FAR
    EXTRN mf146:FAR
    EXTRN mf153:FAR
    EXTRN mf161:FAR
    EXTRN mf168:FAR
    EXTRN mf176:FAR
    EXTRN mf182:FAR
    EXTRN mf187:FAR
    EXTRN mf194:FAR
    EXTRN mf200:FAR
    EXTRN mf200:FAR
    EXTRN mf200:FAR
    EXTRN mf200:FAR
    EXTRN mf200:FAR
    EXTRN mf200:FAR
    EXTRN mf200:FAR
    EXTRN mf200:FAR
    EXTRN mf200:FAR
    EXTRN mf200:FAR
    EXTRN mf200:FAR
    EXTRN mf200:FAR
    EXTRN mf200:FAR
    EXTRN mf200:FAR
    EXTRN mf200:FAR
    EXTRN mf200:FAR
    EXTRN mf200:FAR
    EXTRN mf200:FAR
    EXTRN mf200:FAR
    EXTRN mf200:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,2h
    mov ax,word ptr [bp+6h]
    sub ax, offset mi4
    jz short lbl16f
    dec ax
    dec ax
    jz short lbl5Cf
    jmp near ptr lbl1FCf
    nop
lbl16f:
    mov ax,word ptr ds:[6A06h]
    sub ax, offset mi12
    jz short lbl21f
    jmp near ptr lbl1FCf
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
    mov ax,1Ah
    mov dx,0F047h
    push dx
    push ax
    call mf33
    add sp,0Ch
lbl55b:
    mov ax,1h
    jmp near ptr lbl1FEf
    nop
lbl5Cf:
    mov ax,word ptr ds:[6A06h]
    cmp ax, offset mi39
    jz short lblC4f
    jna short lbl69f
    jmp near ptr lbl1FCf
lbl69f:
    cmp al,2Ch
    jz short lbl86f
    ja short lbl7Af
    sub al,8h
    jz short lbl86f
    sub al,0Bh
    jz short lbl94f
    jmp near ptr lbl1FCf
lbl7Af:
    sub al,44h
    jz short lblB8f
    dec al
    jz short lblBEf
    jmp near ptr lbl1FCf
    nop
lbl86f:
    push word ptr ds:[6A04h]
    call mf58
    add sp,2h
    jmp short lbl55b
lbl94f:
    push word ptr ds:[6A04h]
    mov ax,21h
    push ax
    call mf64
    add sp,4h
    push dx
    push ax
    mov ax,13h
    mov dx,0F047h
    push dx
    push ax
    call mf72
    add sp,8h
    jmp short lbl55b
lblB8f:
    mov ax,15h
    jmp near ptr lbl1EFf
lblBEf:
    mov ax,14h
    jmp near ptr lbl1EFf
lblC4f:
    mov ax,8h
    push ax
    push word ptr ds:[6A02h]
    call mf82
    add sp,4h
    or ax,ax
    jz short lblDBf
    jmp near ptr lbl1ECf
lblDBf:
    mov es, ds:[5B2Ch]
    mov bx,word ptr ds:[6A02h]
    mov ax,bx
    add bx,bx
    add bx,ax
    add bx,bx
    cmp byte ptr es:[bx+md93],5h
    jnz short lblF6f
    jmp near ptr lbl1ECf
lblF6f:
    cmp ax,19Bh
    jz short lbl16Af
    mov ax,11h
    push ax
    push word ptr ds:[6A02h]
    call mf101
    add sp,4h
    or ax,ax
    jnz short lbl12Af
    mov ax,1h
    push ax
    push word ptr ds:[6A02h]
    call mf108
    add sp,4h
    or ax,ax
    jnz short lbl12Af
    mov word ptr [bp-2h],6Fh
    jmp short lbl12Ff
lbl12Af:
    mov word ptr [bp-2h],69h
lbl12Ff:
    push word ptr ds:[6A02h]
    mov ax,2h
    push ax
    call mf118
    add sp,4h
    push dx
    push ax
    push word ptr [bp-2h]
    push word ptr ds:[6A04h]
    mov ax,12h
    push ax
    call mf126
    add sp,4h
    push dx
    push ax
    mov ax,17h
    mov dx,0F047h
    push dx
    push ax
    call mf134
    add sp,0Eh
    jmp near ptr lbl55b
    nop
lbl16Af:
    cmp word ptr ds:[256h],19Ah
    jz short lbl178f
    mov ax,18h
    jmp short lbl1EFf
    nop
lbl178f:
    push ax
    mov ax,2h
    push ax
    call mf146
    add sp,4h
    push dx
    push ax
    push word ptr ds:[6A04h]
    mov ax,2h
    push ax
    call mf153
    add sp,4h
    push dx
    push ax
    mov ax,19h
    mov dx,0F047h
    push dx
    push ax
    call mf161
    add sp,0Ch
    xor ax,ax
    push ax
    push ax
    mov cx,124h
    push cx
    call mf168
    add sp,6h
    xor ax,ax
    push ax
    mov ax,1h
    push ax
    mov ax,0Ah
    push ax
    call mf176
    add sp,6h
    mov ax,0Eh
    push ax
    mov ax,19Bh
    push ax
    call mf182
    add sp,4h
    mov ax,3941h
    push ds
    push ax
    call mf187
lbl1E6b:
    add sp,4h
    jmp near ptr lbl55b
lbl1ECf:
    mov ax,16h
lbl1EFf:
    mov dx,0F047h
    push dx
    push ax
    call mf194
    jmp short lbl1E6b
    nop
lbl1FCf:
    xor ax,ax
lbl1FEf:
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
