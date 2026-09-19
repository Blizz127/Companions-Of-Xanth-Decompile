_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf1a1:FAR
    EXTRN mf8d:FAR
    EXTRN mf54:FAR
    EXTRN mf18b:FAR
    EXTRN mf16a:FAR
    EXTRN mf1ba:FAR
    EXTRN mf104:FAR
    EXTRN mf140:FAR
    EXTRN mf157:FAR
    EXTRN mie:NEAR
    EXTRN mf1ce:FAR
    EXTRN mf72:FAR
    EXTRN mf190:FAR
    EXTRN mib:NEAR
    EXTRN mf118:FAR
    EXTRN mfb0:FAR
    EXTRN mf172:FAR
    EXTRN mf177:FAR
    EXTRN mf12c:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,0Ah
    push di
    push si
    mov ax,word ptr [bp+6h]
    sub ax, offset mib
    cmp ax, offset mie
    jna short lbl16f
    jmp near ptr lbl1D6f
lbl16f:
    add ax,ax
    xchg ax,bx
    jmp word ptr cs:[bx+880h]
    db 0AAh, 08h, 38h, 0Ah, 0C2h, 08h, 38h, 0Ah, 0CCh, 08h, 86h, 09h, 86h, 09h, 86h, 09h
    db 38h, 0Ah, 38h, 0Ah, 9Ah, 09h, 0D4h, 09h, 38h, 0Ah, 38h, 0Ah, 38h, 0Ah, 38h, 0Ah
    db 38h, 0Ah, 38h, 0Ah, 0E6h, 09h, 24h, 0Ah, 0D4h, 09h
    mov ax,1A5h
    push ax
    push word ptr ds:[6A04h]
lbl50b:
    push word ptr ds:[6A06h]
    call mf54
lbl59b:
    add sp,6h
    jmp near ptr lbl1D8f
    nop
    push word ptr ds:[6A02h]
    mov ax,1A5h
    push ax
    jmp short lbl50b
    mov ax,0Ah
    push ax
    mov ax,1A4h
    push ax
    call mf72
    add sp,4h
    mov word ptr [bp-4h],0h
    mov word ptr [bp-0Ah],394Ch
lbl84b:
    mov ax,0Ah
    push ax
    mov bx,word ptr [bp-0Ah]
    push word ptr [bx]
    call mf8d
    add sp,4h
    or ax,ax
    jz short lbl9Cf
    inc word ptr [bp-4h]
lbl9Cf:
    add word ptr [bp-0Ah],2h
    cmp word ptr [bp-0Ah],3956h
    jc short lbl84b
    cmp word ptr [bp-4h],0h
    jz short lblC0f
    push word ptr [bp-4h]
    call mfb0
    add sp,2h
    mov word ptr [bp-8h],ax
    mov word ptr [bp-6h],dx
    jmp short lblC8f
lblC0f:
    mov word ptr [bp-8h],3956h
    mov word ptr [bp-6h],ds
lblC8f:
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
    mov es,dx
    sub byte ptr es:[bx],20h
    mov ax,1A7h
    push ax
    mov ax,1h
    push ax
    mov si,bx
    mov di,dx
    call mf104
    add sp,4h
    push dx
    push ax
    push di
    push si
    mov ax,2Ah
    mov dx,0F047h
    push dx
    push ax
    call mf118
    add sp,0Ch
    jmp near ptr lbl1D6f
    nop
    mov ax,29h
    mov dx,0F047h
    push dx
    push ax
    call mf12c
    add sp,4h
    jmp near ptr lbl1D6f
    nop
    mov ax,0Ah
    push ax
    mov ax,1A4h
    push ax
    call mf140
    add sp,4h
    or ax,ax
    jz short lbl14Ff
    jmp near ptr lbl1D6f
lbl14Ff:
    mov ax,0Ah
    push ax
    mov ax,1A4h
    push ax
    call mf157
    add sp,4h
    xor ax,ax
    push ax
    mov ax,1h
    push ax
    mov ax,5h
    push ax
    call mf16a
    jmp short lbl1D3f
    nop
    call mf172
    call mf177
    mov byte ptr ds:[394Ah],0h
    jmp short lbl1D6f
    nop
    cmp byte ptr ds:[394Ah],0h
    jnz short lbl1AEf
    call mf18b
    call mf190
    xor ax,ax
    push ax
    push ax
    mov ax,9h
    push ax
    mov ax,11A8h
    push ax
    call mf1a1
    add sp,8h
    mov byte ptr ds:[394Ah],1h
lbl1AEf:
    mov ax,6h
    push ax
    mov ax,84h
    mov cx,3352h
    push cx
    push ax
    call mf1ba
    jmp near ptr lbl59b
    mov ax,0Ah
    push ax
    mov ax,0CCh
    mov cx,3352h
    push cx
    push ax
    call mf1ce
lbl1D3f:
    add sp,6h
lbl1D6f:
    xor ax,ax
lbl1D8f:
    pop si
    pop di
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
