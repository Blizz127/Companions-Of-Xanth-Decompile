_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf176:FAR
    EXTRN mfa1:FAR
    EXTRN mf46:FAR
    EXTRN mi9:NEAR
    EXTRN mf18c:FAR
    EXTRN mfe4:FAR
    EXTRN mf67:FAR
    EXTRN mfb8:FAR
    EXTRN mic:NEAR
    EXTRN mff0:FAR
    EXTRN mf106:FAR
    EXTRN mf124:FAR
    EXTRN mfd1:FAR
    EXTRN mf16e:FAR
    EXTRN mf10b:FAR
    EXTRN mf7a:FAR
    EXTRN mf91:FAR
    EXTRN mf11f:FAR
    EXTRN mf1a2:FAR
    EXTRN mfff:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,4h
    mov ax,word ptr [bp+6h]
    sub ax, offset mi9
    cmp ax, offset mic
    jna short lbl14f
    jmp near ptr lbl1A7f
lbl14f:
    add ax,ax
    xchg ax,bx
    jmp word ptr cs:[bx+5F3h]
    db 15h, 06h, 49h, 06h, 49h, 06h, 49h, 06h, 7Eh, 07h, 0A1h, 06h, 7Eh, 07h, 0DDh, 06h
    db 7Eh, 07h, 7Eh, 07h, 7Eh, 07h, 7Eh, 07h, 7Eh, 07h, 7Eh, 07h, 0EFh, 06h, 6Dh, 07h
    db 0DDh, 06h
    mov ax,0Ah
    push ax
    mov ax,180h
    push ax
    call mf46
    add sp,4h
    cmp word ptr ds:[2E0h],4h
    jnz short lbl5Af
    mov ax,378Bh
    jmp short lbl5Df
lbl5Af:
    mov ax,3795h
lbl5Df:
    push ds
    push ax
    mov ax,5h
    mov dx,0F02Eh
    push dx
    push ax
    call mf67
    add sp,8h
    jmp near ptr lbl1A7f
    mov ax,1h
    mov dx,0F02Eh
    push dx
    push ax
    call mf7a
    add sp,4h
    cmp word ptr ds:[2E0h],4h
    jnz short lblC4f
    mov ax,2h
    mov dx,0F02Eh
    push dx
    push ax
    call mf91
    add sp,4h
    mov ax,0Ah
    push ax
    mov ax,182h
    push ax
    call mfa1
    add sp,4h
    or ax,ax
    jnz short lblB0f
    jmp near ptr lbl1A7f
lblB0f:
    mov ax,3h
lblB3b:
    mov dx,0F02Eh
    push dx
    push ax
    call mfb8
lblBDb:
    add sp,4h
    jmp near ptr lbl1A7f
    nop
lblC4f:
    mov ax,4h
    jmp short lblB3b
    nop
    xor ax,ax
    mov dx,0F02Eh
    push dx
    push ax
    call mfd1
    add sp,4h
    mov ax,1h
    push ax
    xor ax,ax
    push ax
    mov ax,5h
    push ax
    call mfe4
    add sp,6h
    mov ax,0BB8h
    push ax
    call mff0
    mov ax,2h
    add sp,ax
    push ax
    mov ax,26h
    push ax
    call mfff
    jmp short lblBDb
    call mf106
    call mf10b
    mov byte ptr ds:[378Ah],0h
    jmp near ptr lbl1A7f
    cmp byte ptr ds:[378Ah],0h
    jnz short lbl180f
    call mf11f
    call mf124
    mov ax,word ptr ds:[2E0h]
    dec ax
    jz short lbl13Af
    dec ax
    jz short lbl146f
    dec ax
    jz short lbl152f
    dec ax
    jz short lbl15Af
    jmp short lbl164f
lbl13Af:
    mov word ptr [bp-2h],100Dh
    mov word ptr [bp-4h],9h
    jmp short lbl164f
lbl146f:
    mov word ptr [bp-2h],1016h
lbl14Bb:
    mov word ptr [bp-4h],8h
    jmp short lbl164f
lbl152f:
    mov word ptr [bp-2h],101Eh
    jmp short lbl14Bb
    nop
lbl15Af:
    mov word ptr [bp-2h],1026h
    mov word ptr [bp-4h],6h
lbl164f:
    xor ax,ax
    push ax
    push ax
    push word ptr [bp-4h]
    push word ptr [bp-2h]
    call mf16e
    add sp,8h
    call mf176
    mov byte ptr ds:[378Ah],1h
lbl180f:
    mov ax,5h
    push ax
    mov ax,0h
    mov cx,32EAh
    push cx
    push ax
    call mf18c
    add sp,6h
    jmp short lbl1A9f
    mov ax,8h
    push ax
    mov ax,3Ch
    mov cx,32EAh
    push cx
    push ax
    call mf1a2
lbl1A7f:
    xor ax,ax
lbl1A9f:
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
