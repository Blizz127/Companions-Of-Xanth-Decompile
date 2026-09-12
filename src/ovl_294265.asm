_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi4:NEAR
    EXTRN mi12:NEAR
    EXTRN mf18:FAR
    EXTRN mf25:FAR
    EXTRN mf33:FAR
    EXTRN mi39:NEAR
    EXTRN mf72:FAR
    EXTRN mf82:FAR
    EXTRN mf116:FAR
    EXTRN mf124:FAR
    EXTRN mf137:FAR
    EXTRN mf151:FAR
    EXTRN mf158:FAR
    EXTRN mf187:FAR
    EXTRN mf195:FAR
    EXTRN mf205:FAR
    EXTRN mf211:FAR
    EXTRN mf216:FAR
    EXTRN mf222:FAR
    EXTRN mf222:FAR
    EXTRN mf222:FAR
    EXTRN mf222:FAR
    EXTRN mf222:FAR
    EXTRN mf222:FAR
    EXTRN mf222:FAR
    EXTRN mf222:FAR
    EXTRN mf222:FAR
    EXTRN mf222:FAR
    EXTRN mf222:FAR
    EXTRN mf222:FAR
    EXTRN mf222:FAR
    EXTRN mf222:FAR
    EXTRN mf222:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,8h
    mov ax,word ptr [bp+6h]
    sub ax, offset mi4
    jz short lbl16f
    dec ax
    dec ax
    jz short lbl5Cf
    jmp near ptr lbl234f
    nop
lbl16f:
    mov ax,word ptr ds:[6A06h]
    sub ax, offset mi12
    jz short lbl21f
    jmp near ptr lbl234f
lbl21f:
    push word ptr ds:[6A02h]
    mov ax,2h
    push ax
    call mf18
    add sp,4h
    push dx
    push ax
    push word ptr ds:[6A04h]
    mov ax,2h
    push ax
    call mf25
    add sp,4h
    push dx
    push ax
    mov ax,1Dh
lbl48b:
    mov dx,0F01Eh
    push dx
    push ax
    call mf33
    add sp,0Ch
lbl55b:
    mov ax,1h
    jmp near ptr lbl236f
    nop
lbl5Cf:
    mov ax,word ptr ds:[6A06h]
    cmp ax, offset mi39
    jnz short lbl67f
    jmp near ptr lbl16Cf
lbl67f:
    jna short lbl6Cf
    jmp near ptr lbl234f
lbl6Cf:
    cmp al,2Ch
    jnz short lbl73f
    jmp near ptr lbl114f
lbl73f:
    ja short lbl80f
    sub al,8h
    jz short lbl95f
    sub al,0Bh
    jz short lblD2f
    jmp near ptr lbl234f
lbl80f:
    sub al,45h
    jnz short lbl87f
    jmp near ptr lbl154f
lbl87f:
    sub al,12h
    jnz short lbl8Ef
    jmp near ptr lbl114f
lbl8Ef:
    dec al
    jz short lbl95f
    jmp near ptr lbl234f
lbl95f:
    cmp word ptr ds:[2DCh],0h
    jnz short lblA2f
    mov ax,12h
    jmp short lblC3f
    nop
lblA2f:
    cmp word ptr ds:[2DCh],3h
    jnl short lblC0f
    push word ptr ds:[6A04h]
    mov ax,2h
    push ax
    call mf72
    add sp,4h
    push dx
    push ax
    mov ax,13h
    jmp short lbl130f
lblC0f:
    mov ax,14h
lblC3b:
lblC3f:
    mov dx,0F01Eh
    push dx
    push ax
    call mf82
lblCDb:
    add sp,4h
    jmp short lbl55b
lblD2f:
    mov ax,word ptr ds:[2DCh]
    or ax,ax
    jz short lblE4f
    dec ax
    jz short lblECf
    dec ax
    jz short lblF4f
    dec ax
    jz short lblFEf
    jmp short lbl108f
lblE4f:
    mov word ptr [bp-4h],0Dh
    jmp short lbl103f
    nop
lblECf:
    mov word ptr [bp-4h],0Eh
    jmp short lbl103f
    nop
lblF4f:
    mov word ptr [bp-4h],38A3h
    mov word ptr [bp-2h],ds
    jmp short lbl108f
lblFEf:
    mov word ptr [bp-4h],0Fh
lbl103f:
    mov word ptr [bp-2h],0F01Eh
lbl108f:
    push word ptr [bp-2h]
    push word ptr [bp-4h]
    mov ax,10h
    jmp short lbl130f
    nop
lbl114f:
    cmp word ptr ds:[2DCh],3h
    jnz short lbl140f
    push word ptr ds:[6A04h]
    mov ax,22h
    push ax
    call mf116
    add sp,4h
    push dx
    push ax
    mov ax,15h
lbl130b:
lbl130f:
    mov dx,0F01Eh
    push dx
    push ax
    call mf124
    add sp,8h
    jmp near ptr lbl55b
lbl140f:
    cmp word ptr ds:[2DCh],0h
    jz short lbl14Ef
    mov ax,16h
    jmp near ptr lblC3b
    nop
lbl14Ef:
    mov ax,17h
    jmp near ptr lblC3b
lbl154f:
    push word ptr ds:[6A04h]
    mov ax,3h
    push ax
    call mf137
    add sp,4h
    push dx
    push ax
    mov ax,11h
    jmp short lbl130b
    nop
lbl16Cf:
    cmp word ptr ds:[6A02h],18Bh
    jz short lbl1A6f
    cmp word ptr ds:[6A02h],15h
    jz short lbl1A6f
    push word ptr ds:[6A02h]
    mov ax,22h
    push ax
    call mf151
    add sp,4h
    push dx
    push ax
    push word ptr ds:[6A04h]
    mov ax,2h
    push ax
    call mf158
    add sp,4h
    push dx
    push ax
    mov ax,18h
    jmp near ptr lbl48b
    nop
lbl1A6f:
    cmp word ptr ds:[256h],18Ah
    jz short lbl1B4f
    mov ax,19h
    jmp near ptr lblC3b
lbl1B4f:
    cmp word ptr ds:[2DCh],3h
    jnz short lbl1C2f
    mov ax,1Ah
    jmp near ptr lblC3b
    nop
lbl1C2f:
    cmp word ptr ds:[2DCh],0h
    jz short lbl1D0f
    mov ax,38B3h
    mov dx,ds
    jmp short lbl1D3f
lbl1D0f:
    xor ax,ax
    cwd
lbl1D3f:
    push dx
    push ax
    mov ax,1Bh
    mov dx,0F01Eh
    push dx
    push ax
    call mf187
    add sp,8h
    xor ax,ax
    push ax
    mov ax,1h
    push ax
    mov cx,4h
    push cx
    call mf195
    add sp,6h
    inc word ptr ds:[2DCh]
    cmp word ptr ds:[2DCh],3h
    jz short lbl206f
    jmp near ptr lbl55b
lbl206f:
    mov ax,1Ch
    mov dx,0F01Eh
    push dx
    push ax
    call mf205
    add sp,4h
    mov ax,0Eh
    push ax
    mov ax,18Ch
    push ax
    call mf211
    add sp,4h
    mov ax,38BAh
    push ds
    push ax
    call mf216
    jmp near ptr lblCDb
    nop
lbl234f:
    xor ax,ax
lbl236f:
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
