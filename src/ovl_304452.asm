_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf132:FAR
    EXTRN mf166:FAR
    EXTRN mf17e:FAR
    EXTRN mf142:FAR
    EXTRN mf1b8:FAR
    EXTRN mi9:NEAR
    EXTRN mi186:NEAR
    EXTRN mi5f:NEAR
    EXTRN mf231:FAR
    EXTRN mffe:FAR
    EXTRN mf216:FAR
    EXTRN mf1d6:FAR
    EXTRN mf156:FAR
    EXTRN mf1e6:FAR
    EXTRN mi19:NEAR
    EXTRN mf29:FAR
    EXTRN mfc9:FAR
    EXTRN mf1a7:FAR
    EXTRN mf1f2:FAR
    EXTRN mf1c9:FAR
    EXTRN mf3b:FAR
    EXTRN mf1c0:FAR
    EXTRN mf4d:FAR
    EXTRN mfaa:FAR
    EXTRN mf202:FAR
    EXTRN mf98:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,6h
    mov ax,word ptr [bp+6h]
    sub ax, offset mi9
    jz short lbl16f
    dec ax
    dec ax
    jz short lbl5Cf
    jmp near ptr lbl23Cf
    nop
lbl16f:
    mov ax,word ptr ds:[6A06h]
    sub ax, offset mi19
    jz short lbl21f
    jmp near ptr lbl23Cf
lbl21f:
    push word ptr ds:[6A02h]
    mov ax,2h
    push ax
    call mf29
    add sp,4h
    push dx
    push ax
    push word ptr ds:[6A04h]
    mov ax,2h
    push ax
    call mf3b
    add sp,4h
    push dx
    push ax
    mov ax,37h
    mov dx,0F047h
    push dx
    push ax
    call mf4d
    add sp,0Ch
lbl55b:
    mov ax,1h
    jmp near ptr lbl23Ef
    nop
lbl5Cf:
    mov ax,word ptr ds:[6A06h]
    cmp ax, offset mi5f
    jnz short lbl67f
    jmp near ptr lbl226f
lbl67f:
    jna short lbl6Cf
    jmp near ptr lbl23Cf
lbl6Cf:
    cmp al,17h
    jz short lblD4f
    ja short lbl7Ef
    sub al,8h
    jz short lbl94f
    sub al,0Bh
    jz short lblA2f
    jmp near ptr lbl23Cf
    nop
lbl7Ef:
    sub al,2Ch
    jz short lbl94f
    sub al,0Ch
    jnz short lbl89f
    jmp near ptr lbl20Ef
lbl89f:
    sub al,0Ch
    jnz short lbl90f
    jmp near ptr lbl20Ef
lbl90f:
    jmp near ptr lbl23Cf
    nop
lbl94f:
    push word ptr ds:[6A04h]
    call mf98
lbl9Db:
    add sp,2h
    jmp short lbl55b
lblA2f:
    mov ax,0Ah
    push ax
    push word ptr ds:[6A04h]
    call mfaa
    add sp,4h
    or ax,ax
    jz short lblBCf
    mov ax,3992h
    jmp short lblBFf
    nop
lblBCf:
    mov ax,3997h
lblBFf:
    push ds
    push ax
    mov ax,31h
lblC4b:
    mov dx,0F047h
    push dx
    push ax
    call mfc9
    add sp,8h
    jmp short lbl55b
    nop
lblD4f:
    mov word ptr [bp-2h],0h
    mov word ptr [bp-4h],394Ch
lblDEb:
    mov ax,word ptr ds:[6A04h]
    mov bx,word ptr [bp-4h]
    cmp word ptr [bx],ax
    jz short lblF6f
    inc word ptr [bp-2h]
    add word ptr [bp-4h],2h
    cmp word ptr [bp-4h],3956h
    jc short lblDEb
lblF6f:
    mov ax,0Ah
    push ax
    push word ptr ds:[6A04h]
    call mffe
    add sp,4h
    or ax,ax
    jz short lbl110f
    mov ax,399Ah
    jmp short lbl113f
    nop
lbl110f:
    mov ax,399Dh
lbl113f:
    push ds
    push ax
    mov es, ds:[5B2Eh]
    mov bx,word ptr [bp-2h]
    add bx,bx
    add bx,bx
    push word ptr es:[bx+146h]
    push word ptr es:[bx+144h]
    mov ax,33h
    mov dx,0F047h
    push dx
    push ax
    call mf132
    add sp,0Ch
    mov ax,0Ah
    push ax
    push word ptr ds:[6A04h]
    call mf142
    add sp,4h
    or ax,ax
    jz short lbl15Ef
    mov ax,0Ah
    push ax
    push word ptr ds:[6A04h]
    call mf156
    jmp short lbl16Bf
    nop
lbl15Ef:
    mov ax,0Ah
    push ax
    push word ptr ds:[6A04h]
    call mf166
lbl16Bf:
    add sp,4h
    mov word ptr [bp-6h],0h
lbl173b:
    mov ax,0Ah
    push ax
    mov bx,word ptr [bp-6h]
    push word ptr [bx+394Ch]
    call mf17e
    add sp,4h
    cmp ax, offset mi186
    db 1Bh, 0C0h ; override
    inc ax
    mov bx,word ptr [bp-6h]
    cmp ax,word ptr [bx+3988h]
    jnz short lbl1FAf
    add word ptr [bp-6h],2h
    cmp word ptr [bp-6h],0Ah
    jl short lbl173b
    mov ax,34h
    mov dx,0F047h
    push dx
    push ax
    call mf1a7
    add sp,4h
    mov ax,1h
    push ax
    push ax
    mov cx,0Fh
    push cx
    call mf1b8
    add sp,6h
    call mf1c0
    mov ax,0FA0h
    push ax
    call mf1c9
    add sp,2h
    mov ax,39A2h
    push ds
    push ax
    call mf1d6
    add sp,4h
    mov ax,35h
    mov dx,0F047h
    push dx
    push ax
    call mf1e6
    add sp,4h
    mov ax,1A8h
    push ax
    call mf1f2
    jmp near ptr lbl9Db
lbl1FAf:
    mov ax,36h
    mov dx,0F047h
    push dx
    push ax
    call mf202
    add sp,4h
    jmp near ptr lbl55b
    nop
lbl20Ef:
    push word ptr ds:[6A04h]
    mov ax,12h
    push ax
    call mf216
    add sp,4h
    push dx
    push ax
    mov ax,32h
    jmp near ptr lblC4b
lbl226f:
    xor ax,ax
    push ax
    mov ax,19Eh
    push ax
    push word ptr ds:[6A06h]
    call mf231
    add sp,6h
    jmp short lbl23Ef
    nop
lbl23Cf:
    xor ax,ax
lbl23Ef:
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
