_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf56:FAR
    EXTRN mfa6:FAR
    EXTRN mf141:FAR
    EXTRN mf2ac:FAR
    EXTRN mfed:FAR
    EXTRN mf1bb:FAR
    EXTRN mf20:FAR
    EXTRN mf22a:FAR
    EXTRN mf295:FAR
    EXTRN mf32:FAR
    EXTRN mf157:FAR
    EXTRN mf101:FAR
    EXTRN mf117:FAR
    EXTRN mf1f1:FAR
    EXTRN mf92:FAR
    EXTRN mf2fe:FAR
    EXTRN mf12b:FAR
    EXTRN mf1a7:FAR
    EXTRN mf358:FAR
    EXTRN mf258:FAR
    EXTRN mf2e8:FAR
    EXTRN mf1db:FAR
    EXTRN mf203:FAR
    EXTRN mf16b:FAR
    EXTRN mf31e:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,0Eh
    push di
    push si
    mov ax,1396h
    mov cx,3420h
    mov word ptr [bp-0Eh],ax
    mov word ptr [bp-0Ch],cx
    mov di,ax
    mov si,2DB2h
    mov es,cx
    movsw
    movsb
    xor ax,ax
    push ax
    call mf20
    add sp,2h
    or ax,ax
    jnz short lbl2Ff
    jmp near ptr lblEAf
lbl2Ff:
    xor ax,ax
    push ax
    call mf32
    add sp,2h
    or ax,ax
    jz short lbl44f
    mov ax,0Ch
    jmp near ptr lbl2F7f
lbl44f:
    cmp byte ptr ds:[311h],0h
    jz short lbl4Ef
    jmp near ptr lblE4f
lbl4Ef:
    mov ax,0Dh
    mov dx,0F01Dh
    push dx
    push ax
    call mf56
    add sp,4h
    mov di,ax
    mov es,dx
    push ds
    lds si, dword ptr [bp-0Eh]
    mov cx,0FFFFh
    xor ax,ax
    repne scasb
    not cx
    sub di,cx
    mov bx,cx
    db 87h, 0FEh ; override
    push ds
    push dx
    pop ds
    pop es
    mov cx,0FFFFh
    repne scasb
    dec di
    mov cx,bx
    shr cx,1
    rep movsw
    adc cx,cx
    rep movsb
    pop ds
    mov ax,0CDh
    push ax
    mov ax,0CEh
    push ax
    call mf92
    add sp,4h
    or ax,ax
    jz short lblDAf
    mov ax,0Eh
    mov dx,0F01Dh
    push dx
    push ax
    call mfa6
    add sp,4h
    mov di,ax
    mov es,dx
    push ds
    lds si, dword ptr [bp-0Eh]
    mov cx,0FFFFh
    xor ax,ax
    repne scasb
    not cx
    sub di,cx
    mov bx,cx
    db 87h, 0FEh ; override
    push ds
    push dx
    pop ds
    pop es
    mov cx,0FFFFh
    repne scasb
    dec di
    mov cx,bx
    shr cx,1
    rep movsw
    adc cx,cx
    rep movsb
    pop ds
lblDAf:
    mov di,2DB5h
    mov cx,ds
    mov es,cx
    jmp near ptr lbl32Af
lblE4f:
    mov ax,0Fh
    jmp near ptr lbl2F7f
lblEAf:
    xor ax,ax
    push ax
    call mfed
    add sp,2h
    or ax,ax
    jz short lbl114f
    mov ax,0CDh
    push ax
    mov ax,0D9h
    push ax
    call mf101
    add sp,4h
    or ax,ax
    jz short lbl114f
    mov ax,10h
    jmp near ptr lbl2F7f
    nop
lbl114f:
    xor ax,ax
    push ax
    call mf117
    add sp,2h
    or ax,ax
    jz short lbl13Ef
    mov ax,0CDh
    push ax
    mov ax,0DAh
    push ax
    call mf12b
    add sp,4h
    or ax,ax
    jz short lbl13Ef
    mov ax,11h
    jmp near ptr lbl2F7f
    nop
lbl13Ef:
    xor ax,ax
    push ax
    call mf141
    add sp,2h
    or ax,ax
    jz short lbl154f
    mov ax,12h
    jmp near ptr lbl2F7f
    nop
lbl154f:
    xor ax,ax
    push ax
    call mf157
    add sp,2h
    or ax,ax
    jz short lbl1D8f
    mov ax,13h
    mov dx,0F01Dh
    push dx
    push ax
    call mf16b
    add sp,4h
    mov di,ax
    mov es,dx
    push ds
    lds si, dword ptr [bp-0Eh]
    mov cx,0FFFFh
    xor ax,ax
    repne scasb
    not cx
    sub di,cx
    mov bx,cx
    db 87h, 0FEh ; override
    push ds
    push dx
    pop ds
    pop es
    mov cx,0FFFFh
    repne scasb
    dec di
    mov cx,bx
    shr cx,1
    rep movsw
    adc cx,cx
    rep movsb
    pop ds
    mov ax,0D4h
    push ax
    mov ax,58h
    push ax
    call mf1a7
    add sp,4h
    or ax,ax
    jz short lbl1C6f
    mov ax,14h
    mov dx,0F01Dh
    push dx
    push ax
    call mf1bb
    add sp,4h
    jmp short lbl1CBf
    nop
lbl1C6f:
    mov ax,2DB7h
    mov dx,ds
lbl1CBf:
    mov word ptr [bp-8h],ax
    mov word ptr [bp-6h],dx
    les di, dword ptr [bp-8h]
    jmp near ptr lbl32Af
    nop
lbl1D8f:
    xor ax,ax
    push ax
    call mf1db
    add sp,2h
    or ax,ax
    jz short lbl1EEf
    mov ax,15h
    jmp near ptr lbl2F7f
    nop
lbl1EEf:
    xor ax,ax
    push ax
    call mf1f1
    add sp,2h
    or ax,ax
    jnz short lbl200f
    jmp near ptr lbl2FEf
lbl200f:
    xor ax,ax
    push ax
    call mf203
    add sp,2h
    or ax,ax
    jnz short lbl212f
    jmp near ptr lbl292f
lbl212f:
    mov word ptr [bp-4h],0h
    mov word ptr [bp-0Ah],5E4h
lbl21Cb:
    mov ax,0Ah
    push ax
    mov es, ds:[5ACCh]
    mov bx,word ptr [bp-0Ah]
    push word ptr es:[bx]
    call mf22a
    add sp,4h
    or ax,ax
    jz short lbl239f
    inc word ptr [bp-4h]
lbl239f:
    add word ptr [bp-0Ah],2h
    cmp word ptr [bp-0Ah],604h
    jc short lbl21Cb
    cmp word ptr [bp-4h],0h
    jz short lbl250f
    mov ax,16h
    jmp short lbl253f
    nop
lbl250f:
    mov ax,17h
lbl253f:
    mov dx,0F01Dh
    push dx
    push ax
    call mf258
    add sp,4h
    mov di,ax
    mov es,dx
    push ds
    lds si, dword ptr [bp-0Eh]
    mov cx,0FFFFh
    xor ax,ax
    repne scasb
    not cx
    sub di,cx
    mov bx,cx
    db 87h, 0FEh ; override
    push ds
    push dx
    pop ds
    pop es
    mov cx,0FFFFh
    repne scasb
    dec di
    mov cx,bx
    shr cx,1
    rep movsw
    adc cx,cx
    rep movsb
    pop ds
    mov ax,18h
    jmp short lbl2F7f
    nop
lbl292f:
    xor ax,ax
    push ax
    call mf295
    add sp,2h
    or ax,ax
    jnz short lbl2A4f
    jmp near ptr lbl352f
lbl2A4f:
    mov ax,19h
    mov dx,0F01Dh
    push dx
    push ax
    call mf2ac
    add sp,4h
    mov di,ax
    mov es,dx
    push ds
    lds si, dword ptr [bp-0Eh]
    mov cx,0FFFFh
    xor ax,ax
    repne scasb
    not cx
    sub di,cx
    mov bx,cx
    db 87h, 0FEh ; override
    push ds
    push dx
    pop ds
    pop es
    mov cx,0FFFFh
    repne scasb
    dec di
    mov cx,bx
    shr cx,1
    rep movsw
    adc cx,cx
    rep movsb
    pop ds
    mov ax,0Eh
    push ax
    mov ax,0D7h
    push ax
    call mf2e8
    add sp,4h
    or ax,ax
    jz short lbl352f
    mov ax,1Ah
lbl2F7f:
    mov dx,0F01Dh
    push dx
    push ax
    jmp short lbl31Ef
lbl2FEf:
    call mf2fe
    mov cx,5h
    sub dx,dx
    div cx
    mov bx,dx
    add bx,dx
    add bx,bx
    mov es, ds:[5ACEh]
    push word ptr es:[bx+506h]
    push word ptr es:[bx+504h]
lbl31Ef:
    call mf31e
    add sp,4h
    mov di,ax
    mov es,dx
lbl32Af:
    push ds
    lds si, dword ptr [bp-0Eh]
    mov cx,0FFFFh
    xor ax,ax
    repne scasb
    not cx
    sub di,cx
    mov bx,cx
    db 87h, 0FEh ; override
    push ds
    push es
    pop ds
    pop es
    mov cx,0FFFFh
    repne scasb
    dec di
    mov cx,bx
    shr cx,1
    rep movsw
    adc cx,cx
    rep movsb
    pop ds
lbl352f:
    push word ptr [bp-0Ch]
    push word ptr [bp-0Eh]
    call mf358
    add sp,4h
    pop si
    pop di
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
