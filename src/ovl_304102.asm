_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf56:FAR
    EXTRN mi8b:NEAR
    EXTRN mfaf:FAR
    EXTRN mf7a:FAR
    EXTRN mfcd:FAR
    EXTRN mff0:FAR
    EXTRN mf68:FAR
    EXTRN mi1b:NEAR
    EXTRN mib:NEAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,0Eh
    push di
    push si
    mov ax,word ptr [bp+6h]
    sub ax, offset mib
    jz short lbl18f
    dec ax
    dec ax
    jz short lbl88f
    jmp near ptr lbl156f
    nop
lbl18f:
    mov ax,word ptr ds:[6A06h]
    sub ax, offset mi1b
    jz short lbl23f
    jmp near ptr lbl156f
lbl23f:
    cmp word ptr ds:[6A02h],19Fh
    jz short lbl4Ef
    cmp word ptr ds:[6A02h],1A0h
    jz short lbl4Ef
    cmp word ptr ds:[6A02h],1A1h
    jz short lbl4Ef
    cmp word ptr ds:[6A02h],1A2h
    jz short lbl4Ef
    cmp word ptr ds:[6A02h],1A3h
    jz short lbl4Ef
    jmp near ptr lbl156f
lbl4Ef:
    push word ptr ds:[6A02h]
    mov ax,22h
    push ax
    call mf56
    add sp,4h
    push dx
    push ax
    push word ptr ds:[6A04h]
    mov ax,2h
    push ax
    call mf68
    add sp,4h
    push dx
    push ax
    mov ax,30h
lbl75b:
    mov dx,0F047h
    push dx
    push ax
    call mf7a
    add sp,0Ch
lbl82b:
    mov ax,1h
    jmp near ptr lbl158f
lbl88f:
    mov ax,word ptr ds:[6A06h]
    cmp ax, offset mi8b
    jnz short lbl93f
    jmp near ptr lbl150f
lbl93f:
    jna short lbl98f
    jmp near ptr lbl156f
lbl98f:
    sub al,8h
    jz short lblA7f
    sub al,0Bh
    jz short lblBAf
    sub al,19h
    jz short lblA7f
    jmp near ptr lbl156f
lblA7f:
    mov ax,2Eh
lblAAb:
    mov dx,0F047h
    push dx
    push ax
    call mfaf
    add sp,4h
    jmp short lbl82b
    nop
lblBAf:
    mov word ptr [bp-4h],0h
    mov word ptr [bp-0Ah],394Ch
lblC4b:
    mov ax,0Ah
    push ax
    mov bx,word ptr [bp-0Ah]
    push word ptr [bx]
    call mfcd
    add sp,4h
    or ax,ax
    jz short lblDCf
    inc word ptr [bp-4h]
lblDCf:
    add word ptr [bp-0Ah],2h
    cmp word ptr [bp-0Ah],3956h
    jc short lblC4b
    cmp word ptr [bp-4h],0h
    jz short lbl100f
    push word ptr [bp-4h]
    call mff0
    add sp,2h
    mov word ptr [bp-8h],ax
    mov word ptr [bp-6h],dx
    jmp short lbl108f
lbl100f:
    mov word ptr [bp-8h],395Bh
    mov word ptr [bp-6h],ds
lbl108f:
    mov bx,1396h
    mov ax,3420h
    mov dx,ax
    push ds
    mov si,bx
    mov ds,ax
    les di, dword ptr [bp-8h]
    mov cx,0FFFFh
    xor ax,ax
    repne scasb
    not cx
    sub di,cx
    db 87h, 0FEh ; override
    push ds
    push es
    pop ds
    pop es
    shr cx,1
    rep movsw
    adc cx,cx
    rep movsb
    pop ds
    mov word ptr [bp-0Ch],dx
    cmp word ptr [bp-4h],1h
    jz short lbl140f
    mov ax,3960h
    jmp short lbl143f
lbl140f:
    mov ax,3964h
lbl143f:
    push ds
    push ax
    push word ptr [bp-0Ch]
    push bx
    mov ax,2Dh
    jmp near ptr lbl75b
    nop
lbl150f:
    mov ax,2Fh
    jmp near ptr lblAAb
lbl156f:
    xor ax,ax
lbl158f:
    pop si
    pop di
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
