_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi5:NEAR
    EXTRN mi9:NEAR
    EXTRN mf28:FAR
    EXTRN mf35:FAR
    EXTRN mf49:FAR
    EXTRN mf57:FAR
    EXTRN mf80:FAR
    EXTRN mf86:FAR
    EXTRN mf93:FAR
    EXTRN mf104:FAR
    EXTRN mf111:FAR
    EXTRN mf123:FAR
    EXTRN mf135:FAR
    EXTRN mf149:FAR
    EXTRN mf156:FAR
    EXTRN mf164:FAR
    EXTRN mf169:FAR
    EXTRN mf174:FAR
    EXTRN mf182:FAR
    EXTRN mf191:FAR
    EXTRN mf200:FAR
    EXTRN mf209:FAR
    EXTRN mf219:FAR
    EXTRN mf229:FAR
    EXTRN mf229:FAR
    EXTRN mf229:FAR
    EXTRN mf229:FAR
    EXTRN mf229:FAR
    EXTRN mf229:FAR
    EXTRN mf229:FAR
    EXTRN mf229:FAR
    EXTRN mf229:FAR
    EXTRN mf229:FAR
    EXTRN mf229:FAR
    EXTRN mf229:FAR
    EXTRN mf229:FAR
    EXTRN mf229:FAR
    EXTRN mf229:FAR
    EXTRN mf229:FAR
    EXTRN mf229:FAR
    EXTRN mf229:FAR
    EXTRN mf229:FAR
    EXTRN mf229:FAR
    EXTRN mf229:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,6h
    push si
    mov ax,word ptr [bp+6h]
    sub ax, offset mi5
    jz short lbl12f
    jmp near ptr lbl25Cf
lbl12f:
    mov ax,word ptr ds:[6A06h]
    cmp ax, offset mi9
    jnz short lbl1Df
    jmp near ptr lbl244f
lbl1Df:
    jna short lbl22f
    jmp near ptr lbl25Cf
lbl22f:
    sub al,8h
    jz short lbl38f
    sub al,0Bh
    jz short lbl4Ef
    sub al,19h
    jz short lbl38f
    sub al,8h
    jnz short lbl35f
    jmp near ptr lblD8f
lbl35f:
    jmp near ptr lbl25Cf
lbl38f:
    mov ax,48h
    mov dx,0F026h
    push dx
    push ax
    call mf28
    add sp,4h
lbl48b:
    mov ax,1h
    jmp near ptr lbl25Ef
lbl4Ef:
    mov ax,0Ah
    push ax
    push word ptr ds:[6A04h]
    call mf35
    add sp,4h
    or ax,ax
    jz short lbl6Af
    mov ax,46h
    mov dx,0F026h
    jmp short lbl6Df
lbl6Af:
    xor ax,ax
    cwd
lbl6Df:
    push dx
    push ax
    push word ptr ds:[6A04h]
    mov ax,1h
    push ax
    call mf49
    add sp,4h
    push dx
    push ax
    mov ax,45h
    mov dx,0F026h
    push dx
    push ax
    call mf57
    add sp,0Ch
    mov word ptr [bp-2h],0h
    mov word ptr [bp-4h],3442h
lbl9Bb:
    mov ax,word ptr ds:[6A04h]
    mov bx,word ptr [bp-4h]
    cmp word ptr [bx],ax
    jz short lblB6f
    inc word ptr [bp-2h]
    add word ptr [bp-4h],2h
    cmp word ptr [bp-4h],3448h
    jc short lbl9Bb
    jmp short lbl48b
    nop
lblB6f:
    mov bx,word ptr [bp-2h]
    add bx,bx
    add bx,bx
    push word ptr [bx+346Ch]
    push word ptr [bx+346Ah]
    mov ax,47h
lblC8b:
    mov dx,0F026h
    push dx
    push ax
    call mf80
    add sp,8h
    jmp near ptr lbl48b
lblD8f:
    mov ax,0Ah
    push ax
    push word ptr ds:[6A04h]
    call mf86
    add sp,4h
    or ax,ax
    jz short lbl104f
    push word ptr ds:[6A04h]
    mov ax,12h
    push ax
    call mf93
    add sp,4h
    push dx
    push ax
    mov ax,4Ah
    jmp short lblC8b
    nop
lbl104f:
    mov ax,126h
    push ax
    mov ax,12Eh
    push ax
    call mf104
    add sp,4h
    or ax,ax
    jz short lbl130f
    push word ptr ds:[6A04h]
    mov ax,12h
    push ax
    call mf111
    add sp,4h
    push dx
    push ax
    mov ax,4Bh
    jmp short lblC8b
    nop
lbl130f:
    cmp word ptr ds:[6A04h],12Fh
    jnz short lbl150f
    push word ptr ds:[6A04h]
    mov ax,12h
    push ax
    call mf123
    add sp,4h
    push dx
    push ax
    mov ax,4Ch
    jmp near ptr lblC8b
lbl150f:
    mov word ptr [bp-2h],0h
    mov word ptr [bp-6h],3442h
lbl15Ab:
    mov ax,0Ah
    push ax
    mov bx,word ptr [bp-6h]
    push word ptr [bx]
    call mf135
    add sp,4h
    or ax,ax
    jnz short lbl17Df
    inc word ptr [bp-2h]
    add word ptr [bp-6h],2h
    cmp word ptr [bp-6h],3448h
    jc short lbl15Ab
lbl17Df:
    mov bx,word ptr [bp-2h]
    add bx,bx
    push word ptr [bx+3442h]
    mov ax,2h
    push ax
    mov si,bx
    call mf149
    add sp,4h
    push dx
    push ax
    push word ptr ds:[6A04h]
    mov ax,2h
    push ax
    call mf156
    add sp,4h
    push dx
    push ax
    mov ax,4Dh
    mov dx,0F026h
    push dx
    push ax
    call mf164
    add sp,0Ch
    mov ax,0Ah
    push ax
    push word ptr ds:[6A04h]
    call mf169
    add sp,4h
    mov ax,0Ah
    push ax
    push word ptr [si+3442h]
    call mf174
    add sp,4h
    mov ax,0Bh
    push ax
    mov ax,0h
    mov cx,3373h
    push cx
    push ax
    call mf182
    add sp,6h
    cmp word ptr ds:[6A04h],130h
    jz short lbl1F7f
    jmp near ptr lbl48b
lbl1F7f:
    mov ax,128h
    push ax
    mov ax,12Dh
    push ax
    call mf191
    add sp,4h
    or ax,ax
    jnz short lbl20Ef
    jmp near ptr lbl48b
lbl20Ef:
    mov ax,128h
    push ax
    mov ax,138h
    push ax
    call mf200
    add sp,4h
    or ax,ax
    jnz short lbl225f
    jmp near ptr lbl48b
lbl225f:
    mov ax,126h
    push ax
    mov ax,12Eh
    push ax
    call mf209
    add sp,4h
    or ax,ax
    jz short lbl23Cf
    jmp near ptr lbl48b
lbl23Cf:
    mov byte ptr ds:[34Dh],1h
    jmp near ptr lbl48b
lbl244f:
    push word ptr ds:[6A04h]
    mov ax,22h
    push ax
    call mf219
    add sp,4h
    push dx
    push ax
    mov ax,49h
    jmp near ptr lblC8b
lbl25Cf:
    xor ax,ax
lbl25Ef:
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
