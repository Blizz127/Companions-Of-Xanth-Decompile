_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi4b0:NEAR
    EXTRN mf1c2:FAR
    EXTRN mf122:FAR
    EXTRN mf3e2:FAR
    EXTRN mi41c:NEAR
    EXTRN mi200:NEAR
    EXTRN mf587:FAR
    EXTRN mf371:FAR
    EXTRN mf158:FAR
    EXTRN mf18a:FAR
    EXTRN mf38c:FAR
    EXTRN mi292:NEAR
    EXTRN mf5a2:FAR
    EXTRN mf13e:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,2Ch
    push di
    push si
    mov al,byte ptr ds:[6A12h]
    sub ah,ah
    mov word ptr ds:[5DECh],ax
    mov al,byte ptr ds:[6A13h]
    mov word ptr ds:[5DEEh],ax
    mov al,byte ptr ds:[6A14h]
    mov word ptr ds:[5DF0h],ax
    mov al,byte ptr ds:[6A15h]
    mov word ptr ds:[5DF2h],ax
    mov al,byte ptr ds:[6A16h]
    mov word ptr ds:[5DF4h],ax
    mov al,byte ptr ds:[6A17h]
    mov word ptr ds:[5DF6h],ax
    mov al,byte ptr ds:[6A18h]
    mov word ptr ds:[5DF8h],ax
    mov ax,0FFFFh
    mov word ptr [bp-0Eh],ax
    mov word ptr [bp-0Ch],ax
    mov word ptr [bp-0Ah],ax
    mov word ptr [bp-8h],ax
    xor ax,ax
    mov word ptr [bp-10h],ax
    mov word ptr [bp-12h],ax
    mov word ptr [bp-6h],ax
    mov word ptr [bp-1Ch],ax
lbl51b:
    mov bx,word ptr [bp-1Ch]
    mov ax,word ptr [bx+5DECh]
    cmp word ptr [bx+1B8Ah],ax
    jnz short lbl6Ef
    inc word ptr [bp-6h]
    add word ptr [bp-1Ch],2h
    cmp word ptr [bp-1Ch],0Eh
    jl short lbl51b
    jmp short lbl74f
    nop
lbl6Ef:
    mov ax,word ptr [bp-6h]
    mov word ptr [bp-0Ch],ax
lbl74f:
    mov word ptr [bp-6h],6h
    mov word ptr [bp-1Eh],0Ch
lbl7Eb:
    mov bx,word ptr [bp-1Eh]
    mov ax,word ptr [bx+5DECh]
    cmp word ptr [bx+1B8Ah],ax
    jnz short lbl96f
    dec word ptr [bp-6h]
    sub word ptr [bp-1Eh],2h
    jns short lbl7Eb
    jmp short lbl9Cf
lbl96f:
    mov ax,word ptr [bp-6h]
    mov word ptr [bp-0Eh],ax
lbl9Cf:
    mov word ptr [bp-6h],0h
    mov word ptr [bp-20h],5DECh
lblA6b:
    mov bx,word ptr [bp-20h]
    cmp word ptr [bx],0h
    jnz short lblBEf
    inc word ptr [bp-6h]
    add word ptr [bp-20h],2h
    cmp word ptr [bp-20h],5DFAh
    jc short lblA6b
    jmp short lblC4f
lblBEf:
    mov ax,word ptr [bp-6h]
    mov word ptr [bp-8h],ax
lblC4f:
    mov word ptr [bp-6h],6h
    mov word ptr [bp-22h],5DF8h
lblCEb:
    mov bx,word ptr [bp-22h]
    cmp word ptr [bx],0h
    jnz short lblE6f
    dec word ptr [bp-6h]
    sub word ptr [bp-22h],2h
    cmp word ptr [bp-22h],5DECh
    jnc short lblCEb
    jmp short lblECf
lblE6f:
    mov ax,word ptr [bp-6h]
    mov word ptr [bp-0Ah],ax
lblECf:
    mov word ptr [bp-24h],0h
lblF1b:
    mov bx,word ptr [bp-24h]
    mov ax,word ptr [bx+5DECh]
    cmp word ptr [bx+1B8Ah],ax
    jz short lbl104f
    inc word ptr [bp-12h]
    jmp short lbl107f
    nop
lbl104f:
    inc word ptr [bp-10h]
lbl107f:
    add word ptr [bp-24h],2h
    cmp word ptr [bp-24h],0Eh
    jl short lblF1b
    mov bx,1396h
    mov es, ds:[5A90h]
    mov word ptr [bp-2Ch],bx
    mov word ptr [bp-2Ah],es
    mov byte ptr es:[bx],0h
    call mf122
    or ax,ax
    jz short lbl136f
    mov word ptr ds:[6A10h],529h
    xor ax,ax
    jmp short lbl153f
    nop
lbl136f:
    mov ax,1h
    push ax
    mov ax,9Bh
    push ax
    call mf13e
    add sp,4h
    or ax,ax
    jnz short lbl17Cf
    mov word ptr ds:[6A10h],52Ah
    mov ax,1h
lbl153f:
    mov dx,0F037h
    push dx
    push ax
    call mf158
    add sp,4h
    mov di,ax
    mov es,dx
    push ds
    lds si, dword ptr [bp-2Ch]
    mov cx,0FFFFh
    xor ax,ax
    repne scasb
    not cx
    sub di,cx
    db 87h, 0FEh ; override
    push ds
    push dx
    pop ds
    pop es
    jmp near ptr lbl615f
lbl17Cf:
    mov word ptr ds:[6A10h],0FFFFh
    mov ax,2h
    mov dx,0F037h
    push dx
    push ax
    call mf18a
    add sp,4h
    mov di,ax
    mov es,dx
    push ds
    lds si, dword ptr [bp-2Ch]
    mov cx,0FFFFh
    xor ax,ax
    repne scasb
    not cx
    sub di,cx
    db 87h, 0FEh ; override
    push ds
    push dx
    pop ds
    pop es
    shr cx,1
    rep movsw
    adc cx,cx
    rep movsb
    pop ds
    cmp word ptr [bp-8h],0FFFFFFFFFFFFFFFFh
    jnz short lbl1FAf
    mov ax,3h
    mov dx,0F037h
    push dx
    push ax
    call mf1c2
    add sp,4h
    mov di,ax
    mov es,dx
    push ds
    lds si, dword ptr [bp-2Ch]
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
    jmp near ptr lbl3DAf
    nop
lbl1FAf:
    mov ax,word ptr [bp-8h]
    mov word ptr [bp-6h],ax
    cmp ax, offset mi200
    jc short lbl208f
    jmp near ptr lbl3DAf
lbl208f:
    add ax,ax
    add ax,5DECh
    mov word ptr [bp-26h],ax
lbl210b:
    mov bx,word ptr [bp-26h]
    cmp word ptr [bx],0h
    jnz short lbl21Bf
    jmp near ptr lbl3C9f
lbl21Bf:
    mov ax,word ptr [bp-6h]
    cmp word ptr [bp-8h],ax
    jz short lbl252f
    mov di,1B98h
    mov cx,ds
    mov es,cx
    push ds
    lds si, dword ptr [bp-2Ch]
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
lbl252f:
    mov ax,word ptr [bp-6h]
    cmp word ptr [bp-0Ah],ax
    jnz short lbl28Ff
    cmp word ptr [bp-10h],1h
    jng short lbl28Ff
    mov di,1B9Bh
    mov cx,ds
    mov es,cx
    push ds
    lds si, dword ptr [bp-2Ch]
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
lbl28Ff:
    mov ax,word ptr [bp-6h]
    cmp ax, offset mi292
    jna short lbl29Af
    jmp near ptr lbl3C9f
lbl29Af:
    add ax,ax
    xchg ax,bx
    jmp word ptr cs:[bx+2A2h]
    db 0B0h, 02h, 0F2h, 02h, 0F8h, 02h, 5Ah, 03h, 60h, 03h, 84h, 03h, 9Ah, 03h
    cmp byte ptr ds:[6A12h],1h
    jnz short lbl2BCf
    mov ax,1BA0h
    jmp short lbl2BFf
lbl2BCf:
    mov ax,1BA9h
lbl2BFf:
    mov cx,ds
    mov di,ax
    mov es,cx
    push ds
    lds si, dword ptr [bp-2Ch]
    mov cx,0FFFFh
    xor ax,ax
    repne scasb
    not cx
    sub di,cx
    push cx
    db 87h, 0FEh ; override
    push ds
    push es
    pop ds
    pop es
    mov cx,0FFFFh
    repne scasb
    dec di
    pop cx
    shr cx,1
    rep movsw
    adc cx,cx
    rep movsb
    pop ds
    mov di,1BB4h
    jmp near ptr lbl39Df
    nop
    mov ax,4h
    jmp near ptr lbl387f
    mov al,byte ptr ds:[6A14h]
    sub ah,ah
    dec ax
    jz short lbl312f
    dec ax
    jz short lbl31Af
    dec ax
    jz short lbl322f
    mov word ptr [bp-4h],5h
    mov word ptr [bp-2h],0F037h
    jmp short lbl32Af
lbl312f:
    mov word ptr [bp-4h],1BC3h
    jmp short lbl327f
    nop
lbl31Af:
    mov word ptr [bp-4h],1BCAh
    jmp short lbl327f
    nop
lbl322f:
    mov word ptr [bp-4h],1BD4h
lbl327f:
    mov word ptr [bp-2h],ds
lbl32Af:
    les di, dword ptr [bp-4h]
    push ds
    lds si, dword ptr [bp-2Ch]
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
    mov di,1BE0h
    jmp short lbl39Df
    mov di,1BEAh
    jmp short lbl39Df
    nop
    cmp byte ptr ds:[6A16h],1h
    jnz short lbl36Cf
    mov ax,1BF1h
    jmp short lbl36Ff
lbl36Cf:
    mov ax,1C00h
lbl36Ff:
    push ds
    push ax
    call mf371
    add sp,4h
    mov word ptr [bp-16h],ax
    mov word ptr [bp-14h],dx
    les di, dword ptr [bp-16h]
    jmp short lbl3A1f
    mov ax,6h
lbl387f:
    mov dx,0F037h
    push dx
    push ax
    call mf38c
    add sp,4h
    mov di,ax
    mov es,dx
    jmp short lbl3A1f
    mov di,1C10h
lbl39Df:
    mov cx,ds
    mov es,cx
lbl3A1f:
    push ds
    lds si, dword ptr [bp-2Ch]
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
lbl3C9f:
    inc word ptr [bp-6h]
    add word ptr [bp-26h],2h
    cmp word ptr [bp-26h],5DFAh
    jnc short lbl3DAf
    jmp near ptr lbl210b
lbl3DAf:
    mov ax,7h
    mov dx,0F037h
    push dx
    push ax
    call mf3e2
    add sp,4h
    mov di,ax
    mov es,dx
    push ds
    lds si, dword ptr [bp-2Ch]
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
    mov ax,word ptr [bp-0Ch]
    mov word ptr [bp-6h],ax
    cmp ax, offset mi41c
    jc short lbl424f
    jmp near ptr lbl5EFf
lbl424f:
    add ax,ax
    mov word ptr [bp-28h],ax
lbl429b:
    mov bx,word ptr [bp-28h]
    mov ax,word ptr [bx+5DECh]
    cmp word ptr [bx+1B8Ah],ax
    jnz short lbl439f
    jmp near ptr lbl5DFf
lbl439f:
    mov ax,word ptr [bp-6h]
    cmp word ptr [bp-0Ch],ax
    jz short lbl470f
    mov di,1C1Ah
    mov cx,ds
    mov es,cx
    push ds
    lds si, dword ptr [bp-2Ch]
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
lbl470f:
    mov ax,word ptr [bp-6h]
    cmp word ptr [bp-0Eh],ax
    jnz short lbl4ADf
    cmp word ptr [bp-12h],1h
    jng short lbl4ADf
    mov di,1C1Dh
    mov cx,ds
    mov es,cx
    push ds
    lds si, dword ptr [bp-2Ch]
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
lbl4ADf:
    mov ax,word ptr [bp-6h]
    cmp ax, offset mi4b0
    jna short lbl4B8f
    jmp near ptr lbl5DFf
lbl4B8f:
    add ax,ax
    xchg ax,bx
    jmp word ptr cs:[bx+4C0h]
    db 0CEh, 04h, 10h, 05h, 16h, 05h, 70h, 05h, 76h, 05h, 9Ah, 05h, 0B0h, 05h
    cmp byte ptr ds:[6A12h],0h
    jnz short lbl4DAf
    mov ax,1C22h
    jmp short lbl4DDf
lbl4DAf:
    mov ax,1C2Dh
lbl4DDf:
    mov cx,ds
    mov di,ax
    mov es,cx
    push ds
    lds si, dword ptr [bp-2Ch]
    mov cx,0FFFFh
    xor ax,ax
    repne scasb
    not cx
    sub di,cx
    push cx
    db 87h, 0FEh ; override
    push ds
    push es
    pop ds
    pop es
    mov cx,0FFFFh
    repne scasb
    dec di
    pop cx
    shr cx,1
    rep movsw
    adc cx,cx
    rep movsb
    pop ds
    mov di,1C36h
    jmp near ptr lbl5B3f
    nop
    mov ax,4h
    jmp near ptr lbl59Df
    mov al,byte ptr ds:[6A14h]
    sub ah,ah
    or ax,ax
    jz short lbl528f
    dec ax
    jz short lbl530f
    dec ax
    jz short lbl538f
    jmp short lbl540f
    nop
lbl528f:
    mov word ptr [bp-4h],1C45h
    jmp short lbl53Df
    nop
lbl530f:
    mov word ptr [bp-4h],1C51h
    jmp short lbl53Df
    nop
lbl538f:
    mov word ptr [bp-4h],1C5Bh
lbl53Df:
    mov word ptr [bp-2h],ds
lbl540f:
    les di, dword ptr [bp-4h]
    push ds
    lds si, dword ptr [bp-2Ch]
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
    mov di,1C62h
    jmp short lbl5B3f
    mov di,1C6Ch
    jmp short lbl5B3f
    nop
    cmp byte ptr ds:[6A16h],0h
    jnz short lbl582f
    mov ax,1C73h
    jmp short lbl585f
lbl582f:
    mov ax,1C83h
lbl585f:
    push ds
    push ax
    call mf587
    add sp,4h
    mov word ptr [bp-1Ah],ax
    mov word ptr [bp-18h],dx
    les di, dword ptr [bp-1Ah]
    jmp short lbl5B7f
    mov ax,8h
lbl59Df:
    mov dx,0F037h
    push dx
    push ax
    call mf5a2
    add sp,4h
    mov di,ax
    mov es,dx
    jmp short lbl5B7f
    mov di,1C92h
lbl5B3f:
    mov cx,ds
    mov es,cx
lbl5B7f:
    push ds
    lds si, dword ptr [bp-2Ch]
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
lbl5DFf:
    inc word ptr [bp-6h]
    add word ptr [bp-28h],2h
    cmp word ptr [bp-28h],0Eh
    jnl short lbl5EFf
    jmp near ptr lbl429b
lbl5EFf:
    mov di,1C9Ch
    mov cx,ds
    mov es,cx
    push ds
    lds si, dword ptr [bp-2Ch]
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
lbl615f:
    shr cx,1
    rep movsw
    adc cx,cx
    rep movsb
    pop ds
    mov ax,word ptr [bp-2Ch]
    mov dx,word ptr [bp-2Ah]
    pop si
    pop di
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
