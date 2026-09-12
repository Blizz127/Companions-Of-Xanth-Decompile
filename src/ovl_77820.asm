_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi4:NEAR
    EXTRN mi12:NEAR
    EXTRN mf22:FAR
    EXTRN mf30:FAR
    EXTRN mf38:FAR
    EXTRN mi44:NEAR
    EXTRN mf64:FAR
    EXTRN mf71:FAR
    EXTRN mf81:FAR
    EXTRN mf89:FAR
    EXTRN mf98:FAR
    EXTRN mf106:FAR
    EXTRN mf114:FAR
    EXTRN mf118:FAR
    EXTRN mf125:FAR
    EXTRN mf132:FAR
    EXTRN mf140:FAR
    EXTRN mf151:FAR
    EXTRN mf158:FAR
    EXTRN mf163:FAR
    EXTRN mf168:FAR
    EXTRN mf174:FAR
    EXTRN mf188:FAR
    EXTRN mf202:FAR
    EXTRN mf211:FAR
    EXTRN mf219:FAR
    EXTRN mf224:FAR
    EXTRN mf231:FAR
    EXTRN mf237:FAR
    EXTRN mf244:FAR
    EXTRN mf250:FAR
    EXTRN mf257:FAR
    EXTRN mf270:FAR
    EXTRN mf276:FAR
    EXTRN mf284:FAR
    EXTRN mf291:FAR
    EXTRN mf296:FAR
    EXTRN mf304:FAR
    EXTRN mf311:FAR
    EXTRN mf320:FAR
    EXTRN mf329:FAR
    EXTRN mf329:FAR
    EXTRN mf329:FAR
    EXTRN mf329:FAR
    EXTRN mf329:FAR
    EXTRN mf329:FAR
    EXTRN mf329:FAR
    EXTRN mf329:FAR
    EXTRN mf329:FAR
    EXTRN mf329:FAR
    EXTRN mf329:FAR
    EXTRN mf329:FAR
    EXTRN mf329:FAR
    EXTRN mf329:FAR
    EXTRN mf329:FAR
    EXTRN mf329:FAR
    EXTRN mf329:FAR
    EXTRN mf329:FAR
    EXTRN mf329:FAR
    EXTRN mf329:FAR
    EXTRN mf329:FAR
    EXTRN mf329:FAR
    EXTRN mf329:FAR
    EXTRN mf329:FAR
    EXTRN mf329:FAR
    EXTRN mf329:FAR
    EXTRN mf329:FAR
    EXTRN mf329:FAR
    EXTRN mf329:FAR
    EXTRN mf329:FAR
    EXTRN mf329:FAR
    EXTRN mf329:FAR
    EXTRN mf329:FAR
    EXTRN mf329:FAR
    EXTRN mf329:FAR
    EXTRN mf329:FAR
    EXTRN mf329:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,4h
    mov ax,word ptr [bp+6h]
    sub ax, offset mi4
    jz short lbl16f
    dec ax
    dec ax
    jz short lbl66f
    jmp near ptr lbl350f
    nop
lbl16f:
    mov ax,word ptr ds:[6A06h]
    sub ax, offset mi12
    jz short lbl21f
    jmp near ptr lbl350f
lbl21f:
    cmp word ptr ds:[6A04h],56h
    jnz short lbl2Bf
    jmp near ptr lbl350f
lbl2Bf:
    mov ax,31h
    push ax
    mov ax,1h
    push ax
    call mf22
    add sp,4h
    push dx
    push ax
    mov ax,56h
    push ax
    mov ax,1h
    push ax
    call mf30
    add sp,4h
    push dx
    push ax
    mov ax,11h
lbl52b:
    mov dx,0F032h
    push dx
    push ax
    call mf38
    add sp,0Ch
lbl5Fb:
    mov ax,1h
    jmp near ptr lbl352f
    nop
lbl66f:
    mov ax,word ptr ds:[6A06h]
    cmp ax, offset mi44
    jnz short lbl71f
    jmp near ptr lbl338f
lbl71f:
    jna short lbl76f
    jmp near ptr lbl350f
lbl76f:
    sub al,8h
    jz short lbl92f
    sub al,0Bh
    jnz short lbl81f
    jmp near ptr lbl1BAf
lbl81f:
    sub al,19h
    jnz short lbl88f
    jmp near ptr lbl27Af
lbl88f:
    sub al,18h
    jnz short lbl8Ff
    jmp near ptr lbl30Ef
lbl8Ff:
    jmp near ptr lbl350f
lbl92f:
    mov ax,0Eh
    push ax
    push word ptr ds:[6A04h]
    call mf64
    add sp,4h
    or ax,ax
    jnz short lblBEf
    push word ptr ds:[6A04h]
    mov ax,12h
    push ax
    call mf71
    add sp,4h
    push dx
    push ax
    mov ax,0Dh
    jmp near ptr lbl2A3f
lblBEf:
    mov ax,31h
    push ax
    mov ax,56h
    push ax
    call mf81
    add sp,4h
    or ax,ax
    jz short lbl122f
    mov ax,0Ah
    push ax
    mov ax,29h
    push ax
    call mf89
    add sp,4h
    or ax,ax
    jz short lbl122f
    mov byte ptr ds:[324h],1h
    mov ax,0Ah
    push ax
    mov ax,27h
    push ax
    call mf98
    add sp,4h
    or ax,ax
    jnz short lbl122f
    mov ax,0Ah
    push ax
    mov ax,27h
    push ax
    call mf106
    add sp,4h
    xor ax,ax
    push ax
    mov ax,1h
    push ax
    mov ax,9h
    push ax
    call mf114
    add sp,6h
lbl122f:
    mov ax,56h
    push ax
    call mf118
    add sp,2h
    cmp ax,110h
    jz short lbl177f
    push word ptr ds:[6A04h]
    mov ax,56h
    push ax
    call mf125
    add sp,4h
    or ax,ax
    jnz short lbl172f
    push word ptr ds:[6A04h]
    mov ax,2h
    push ax
    call mf132
    add sp,4h
    push dx
    push ax
    mov ax,56h
    push ax
    mov ax,3h
    push ax
    call mf140
    add sp,4h
    push dx
    push ax
    mov ax,0Eh
    jmp near ptr lbl52b
    nop
lbl172f:
    mov byte ptr ds:[29Eh],1h
lbl177f:
    push word ptr ds:[6A04h]
    mov ax,22h
    push ax
    call mf151
    add sp,4h
    push dx
    push ax
    mov ax,1FCDh
    push ds
    push ax
    call mf158
    add sp,8h
    mov ax,0Eh
    push ax
    push word ptr ds:[6A04h]
    call mf163
    add sp,4h
    mov ax,2Ch
lbl1A9b:
    push ax
    push word ptr ds:[6A04h]
    call mf168
lbl1B3b:
    add sp,4h
    jmp near ptr lbl5Fb
    nop
lbl1BAf:
    mov ax,56h
    push ax
    call mf174
    add sp,2h
    cmp ax,110h
    jnz short lbl1D2f
    mov ax,1FA1h
    mov dx,ds
    jmp short lbl1D8f
lbl1D2f:
    mov ax,0Bh
    mov dx,0F032h
lbl1D8f:
    mov word ptr [bp-4h],ax
    mov word ptr [bp-2h],dx
    mov ax,0Eh
    push ax
    push word ptr ds:[6A04h]
    call mf188
    add sp,4h
    or ax,ax
    jz short lbl1F8f
    mov ax,1F95h
    jmp short lbl1FBf
    nop
lbl1F8f:
    mov ax,1F9Ah
lbl1FBf:
    push ds
    push ax
    mov ax,27h
    push ax
    mov ax,2h
    push ax
    call mf202
    add sp,4h
    push dx
    push ax
    push word ptr [bp-2h]
    push word ptr [bp-4h]
    push word ptr ds:[6A04h]
    mov ax,12h
    push ax
    call mf211
    add sp,4h
    push dx
    push ax
    mov ax,0Ah
    mov dx,0F032h
    push dx
    push ax
    call mf219
    add sp,14h
    push word ptr ds:[6A04h]
    mov ax,56h
    push ax
    call mf224
    add sp,4h
    or ax,ax
    jnz short lbl258f
    mov ax,1FB0h
    push ds
    push ax
    call mf231
    jmp near ptr lbl1B3b
lbl258f:
    mov ax,56h
    push ax
    mov ax,23h
    push ax
    call mf237
    add sp,4h
    push dx
    push ax
    mov ax,1FB7h
    push ds
lbl26Eb:
    push ax
    call mf244
    add sp,8h
    jmp near ptr lbl5Fb
lbl27Af:
    mov ax,0Eh
    push ax
    push word ptr ds:[6A04h]
    call mf250
    add sp,4h
    or ax,ax
    jz short lbl2AAf
    push word ptr ds:[6A04h]
    mov ax,12h
    push ax
    call mf257
    add sp,4h
    push dx
    push ax
    mov ax,0Ch
lbl2A3b:
lbl2A3f:
    mov dx,0F032h
    push dx
    jmp short lbl26Eb
    nop
lbl2AAf:
    mov byte ptr ds:[324h],0h
    push word ptr ds:[6A04h]
    mov ax,56h
    push ax
    call mf270
    add sp,4h
    or ax,ax
    jz short lbl2D9f
    mov ax,56h
    push ax
    call mf276
    add sp,2h
    cmp ax,110h
    jz short lbl2D9f
    mov byte ptr ds:[29Dh],1h
lbl2D9f:
    push word ptr ds:[6A04h]
    mov ax,22h
    push ax
    call mf284
    add sp,4h
    push dx
    push ax
    mov ax,1FC2h
    push ds
    push ax
    call mf291
    add sp,8h
    mov ax,0Eh
    push ax
    push word ptr ds:[6A04h]
    call mf296
    add sp,4h
    mov ax,8h
    jmp near ptr lbl1A9b
lbl30Ef:
    mov ax,27h
    push ax
    mov ax,2h
    push ax
    call mf304
    add sp,4h
    push dx
    push ax
    push word ptr ds:[6A04h]
    mov ax,2h
    push ax
    call mf311
    add sp,4h
    push dx
    push ax
    mov ax,0Fh
    jmp near ptr lbl52b
lbl338f:
    push word ptr ds:[6A04h]
    mov ax,21h
    push ax
    call mf320
    add sp,4h
    push dx
    push ax
    mov ax,10h
    jmp near ptr lbl2A3b
lbl350f:
    xor ax,ax
lbl352f:
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
