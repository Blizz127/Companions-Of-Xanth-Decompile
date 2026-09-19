_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN md3c7:NEAR
    EXTRN mf16d:FAR
    EXTRN mf34e:FAR
    EXTRN mf1e2:FAR
    EXTRN md590:NEAR
    EXTRN mi489:NEAR
    EXTRN mf6d1:FAR
    EXTRN mfe7:FAR
    EXTRN mf774:FAR
    EXTRN mf38a:FAR
    EXTRN mf374:FAR
    EXTRN mf5d8:FAR
    EXTRN md567:NEAR
    EXTRN md543:NEAR
    EXTRN mi2c5:NEAR
    EXTRN mf633:FAR
    EXTRN md85:NEAR
    EXTRN mi7ca:NEAR
    EXTRN mf330:FAR
    EXTRN mf3ec:FAR
    EXTRN mf157:FAR
    EXTRN mf140:FAR
    EXTRN mf2bd:FAR
    EXTRN mf361:FAR
    EXTRN md270:NEAR
    EXTRN mf3ff:FAR
    EXTRN mf1fb:FAR
    EXTRN md460:NEAR
    EXTRN mf730:FAR
    EXTRN mf6e4:FAR
    EXTRN md1d7:NEAR
    EXTRN mi6b7:NEAR
    EXTRN mf12d:FAR
    EXTRN mf443:FAR
    EXTRN mf42d:FAR
    EXTRN mi338:NEAR
    EXTRN mf3a9:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,28h
    push di
    push si
    xor ax,ax
    mov word ptr [bp-4h],ax
    mov word ptr [bp-6h],ax
    cmp word ptr [bp+6h],ax
    jz short lbl18f
    db 0E9h, 80h, 01h ; override
lbl18f:
    mov word ptr [bp-2h],ax
    mov word ptr [bp-14h],4DAh
lbl20b:
    mov ax,word ptr [bp+8h]
    mov es, ds:[5A4Eh]
    mov bx,word ptr [bp-14h]
    cmp word ptr es:[bx],ax
    jnz short lbl38f
    mov ax,word ptr [bp+0Ah]
    cmp word ptr es:[bx+2h],ax
    jz short lbl48f
lbl38f:
    inc word ptr [bp-2h]
    add word ptr [bp-14h],6h
    cmp word ptr [bp-14h],67Eh
    jc short lbl20b
    jmp short lbl64f
lbl48f:
    mov bx,word ptr [bp-2h]
    mov ax,bx
    add bx,bx
    add bx,ax
    add bx,bx
    mov ax,word ptr es:[bx+4D8h]
    mov word ptr [bp+6h],ax
    mov ax,1h
    mov word ptr [bp-4h],ax
    mov word ptr [bp-6h],ax
lbl64f:
    cmp word ptr [bp-4h],0h
    jz short lbl6Df
    db 0E9h, 8Bh, 00h ; override
lbl6Df:
    cmp word ptr [bp+0Ah],0h
    jnz short lbl76f
    db 0E9h, 0B0h, 00h ; override
lbl76f:
    mov es, ds:[5A50h]
    mov bx,word ptr [bp+0Ah]
    mov ax,bx
    add bx,bx
    add bx,ax
    add bx,bx
    cmp byte ptr es:[bx+md85],5h
    jnz short lbl92f
    mov ax,19h
    jmp short lbl95f
lbl92f:
    mov ax,38h
lbl95f:
    mov word ptr [bp+6h],ax
    mov word ptr [bp-2h],0h
    mov word ptr [bp-16h],4DAh
lblA2b:
    mov ax,word ptr [bp+0Ah]
    mov es, ds:[5A4Eh]
    mov bx,word ptr [bp-16h]
    cmp word ptr es:[bx],ax
    jnz short lblBAf
    mov ax,word ptr [bp+8h]
    cmp word ptr es:[bx+2h],ax
    jz short lblCAf
lblBAf:
    inc word ptr [bp-2h]
    add word ptr [bp-16h],6h
    cmp word ptr [bp-16h],67Eh
    jc short lblA2b
    jmp short lblF8f
lblCAf:
    mov bx,word ptr [bp-2h]
    mov ax,bx
    add bx,bx
    add bx,ax
    add bx,bx
    mov ax,word ptr es:[bx+4D8h]
    mov word ptr [bp+6h],ax
    lea ax,word ptr [bp+0Ah]
    push ss
    push ax
    lea ax,word ptr [bp+8h]
    push ss
    push ax
    call mfe7
    add sp,8h
lblEFb:
    mov ax,1h
    mov word ptr [bp-4h],ax
    mov word ptr [bp-6h],ax
lblF8b:
lblF8f:
    mov word ptr [bp-2h],0h
    mov word ptr [bp-1Ch],6h
lbl102b:
    mov ax,word ptr [bp+6h]
    mov es, ds:[5A4Ch]
    mov bx,word ptr [bp-1Ch]
    cmp word ptr es:[bx],ax
    jnz short lbl114f
    db 0E9h, 52h, 01h ; override
lbl114f:
    inc word ptr [bp-2h]
    add word ptr [bp-1Ch],8h
    cmp word ptr [bp-1Ch],2CEh
    jc short lbl102b
    db 0E9h, 7Bh, 01h ; override
    nop
lbl126f:
    mov ax,0Ch
    push ax
    push word ptr [bp+8h]
    call mf12d
    add sp,4h
    or ax,ax
    jz short lbl154f
    mov ax,1h
    push ax
    push word ptr [bp+8h]
    call mf140
    add sp,4h
    or ax,ax
    jnz short lbl154f
    mov word ptr [bp+6h],44h
    jmp short lblF8b
    nop
lbl154f:
    push word ptr [bp+8h]
    call mf157
    add sp,2h
    mov word ptr [bp+6h],ax
    or ax,ax
    jnz short lblEFb
    mov ax,17h
    push ax
    push word ptr [bp+8h]
    call mf16d
    add sp,4h
    or ax,ax
    jnz short lbl190f
    cmp word ptr [bp+8h],182h
    jz short lbl190f
    cmp word ptr [bp+8h],183h
    jz short lbl190f
    mov word ptr [bp+6h],13h
    jmp near ptr lblF8b
    nop
lbl190f:
    mov word ptr [bp+6h],45h
    jmp near ptr lblF8b
lbl198f:
    cmp word ptr [bp+6h],26h
    jnz short lbl1A8f
    cmp word ptr [bp+8h],ax
    jz short lbl1A8f
    mov word ptr [bp+6h],13h
lbl1A8f:
    mov word ptr [bp-2h],ax
    mov word ptr [bp-18h],6h
lbl1B0b:
    mov ax,word ptr [bp+6h]
    mov es, ds:[5A4Ch]
    mov bx,word ptr [bp-18h]
    cmp word ptr es:[bx],ax
    jz short lbl1D0f
    inc word ptr [bp-2h]
    add word ptr [bp-18h],8h
    cmp word ptr [bp-18h],2CEh
    jc short lbl1B0b
    db 0EBh, 10h ; override
    nop
lbl1D0f:
    mov cl,3h
    mov bx,word ptr [bp-2h]
    shl bx,cl
    mov al,byte ptr es:[bx+md1d7]
    mov byte ptr [bp-0Eh],al
lbl1DFf:
    push word ptr [bp+8h]
    call mf1e2
    add sp,2h
    cmp ax,word ptr [bp+6h]
    jnz short lbl1F8f
    cmp byte ptr [bp-0Eh],2h
    jz short lbl1F8f
    jmp near ptr lblEFb
lbl1F8f:
    push word ptr [bp+8h]
    call mf1fb
    add sp,2h
    mov es,dx
    mov bx,ax
    mov word ptr [bp-0Ch],ax
    cmp word ptr es:[bx],0h
    jz short lbl22Ff
lbl210b:
    mov ax,word ptr [bp+6h]
    mov bx,word ptr [bp-0Ch]
    cmp word ptr es:[bx],ax
    jz short lbl22Af
    add word ptr [bp-0Ch],2h
    mov bx,word ptr [bp-0Ch]
    cmp word ptr es:[bx],0h
    jnz short lbl210b
    jmp short lbl22Ff
lbl22Af:
    mov word ptr [bp-6h],1h
lbl22Ff:
    mov word ptr [bp-1Ah],4D8h
lbl234b:
    mov ax,word ptr [bp+6h]
    mov es, ds:[5A4Eh]
    mov bx,word ptr [bp-1Ah]
    cmp word ptr es:[bx],ax
    jnz short lbl258f
    mov ax,word ptr [bp+8h]
    cmp word ptr es:[bx+2h],ax
    jnz short lbl258f
    mov ax,word ptr [bp+0Ah]
    cmp word ptr es:[bx+4h],ax
    jnz short lbl258f
    jmp near ptr lblEFb
lbl258f:
    add word ptr [bp-1Ah],6h
    cmp word ptr [bp-1Ah],67Ch
    jc short lbl234b
    jmp near ptr lblF8b
lbl266f:
    mov cl,3h
    mov bx,word ptr [bp-2h]
    shl bx,cl
    mov word ptr [bp-22h],bx
    mov al,byte ptr es:[bx+md270]
    mov byte ptr [bp-20h],al
    sub ah,ah
    or ax,ax
    jz short lbl290f
    dec ax
    jz short lbl28Af
    dec ax
    jnz short lbl2A0f
    cmp word ptr [bp+0Ah],0h
    jz short lbl2A0f
lbl28Af:
    cmp word ptr [bp+8h],0h
    jz short lbl2A0f
lbl290f:
    mov word ptr [bp-4h],1h
    cmp byte ptr [bp-20h],0h
    jnz short lbl2A0f
    mov word ptr [bp-6h],1h
lbl2A0f:
    cmp word ptr [bp+8h],0h
    jz short lbl2DBf
    mov ax,word ptr [bp+6h]
    mov word ptr ds:[6A06h],ax
    mov ax,word ptr [bp+0Ah]
    mov word ptr ds:[6A02h],ax
    mov ax,1Dh
    push ax
    mov ax,word ptr [bp+8h]
    mov word ptr ds:[6A04h],ax
    push ax
    call mf2bd
    add sp,4h
    cmp ax, offset mi2c5
    jnz short lbl2D2f
lbl2CAb:
    mov word ptr [bp-6h],0h
    jmp short lbl2DBf
    nop
lbl2D2f:
    or ax,ax
    jz short lbl320f
lbl2D6b:
    mov word ptr [bp-6h],1h
lbl2DBb:
lbl2DBf:
    mov ax,word ptr [bp+0Eh]
    or ax,word ptr [bp+0Ch]
    jnz short lbl2E6f
    db 0E9h, 0C2h, 04h ; override
lbl2E6f:
    sub ax,ax
    mov word ptr [bp-10h],ax
    mov word ptr [bp-12h],ax
    les bx, dword ptr [bp+0Ch]
    mov byte ptr es:[bx],al
    mov word ptr [bp-2h],ax
    mov word ptr [bp-1Eh],6h
lbl2FCb:
    mov ax,word ptr [bp+6h]
    mov es, ds:[5A4Ch]
    mov bx,word ptr [bp-1Eh]
    cmp word ptr es:[bx],ax
    jnz short lbl30Ef
    db 0E9h, 48h, 01h ; override
lbl30Ef:
    inc word ptr [bp-2h]
    add word ptr [bp-1Eh],8h
    cmp word ptr [bp-1Eh],2CEh
    jc short lbl2FCb
    db 0E9h, 0A9h, 02h ; override
    nop
lbl320f:
    cmp word ptr [bp+0Ah],0h
    jnz short lbl329f
    db 0E9h, 0ADh, 00h ; override
lbl329f:
    mov ax,1Eh
    push ax
    push word ptr [bp+0Ah]
    call mf330
    add sp,4h
    cmp ax, offset mi338
    jz short lbl2CAb
    or ax,ax
    jnz short lbl2D6b
    cmp word ptr [bp+6h],38h
    jnz short lbl399f
    mov ax,0Ch
    push ax
    push word ptr [bp+8h]
    call mf34e
    add sp,4h
    or ax,ax
    jnz short lbl36Df
    mov ax,7h
    push ax
    push word ptr [bp+8h]
    call mf361
    add sp,4h
    or ax,ax
    jz short lbl399f
lbl36Df:
    mov ax,11h
    push ax
    push word ptr [bp+0Ah]
    call mf374
    add sp,4h
    or ax,ax
    jz short lbl383f
    jmp near ptr lbl2D6b
lbl383f:
    mov ax,0Bh
    push ax
    push word ptr [bp+0Ah]
    call mf38a
    add sp,4h
    or ax,ax
    jz short lbl399f
    jmp near ptr lbl2D6b
lbl399f:
    cmp word ptr [bp+6h],19h
    jz short lbl3A2f
    jmp near ptr lbl2DBb
lbl3A2f:
    mov ax,0Ch
    push ax
    push word ptr [bp+8h]
    call mf3a9
    add sp,4h
    or ax,ax
    jnz short lbl3B8f
    jmp near ptr lbl2DBb
lbl3B8f:
    mov es, ds:[5A50h]
    mov bx,word ptr [bp+0Ah]
    mov ax,bx
    add bx,bx
    add bx,ax
    add bx,bx
    cmp byte ptr es:[bx+md3c7],5h
    jz short lbl3D2f
    jmp near ptr lbl2DBb
lbl3D2f:
    jmp near ptr lbl2D6b
    nop
lbl3D6f:
    cmp word ptr [bp+6h],2Ch
    jnz short lbl3DFf
    jmp near ptr lbl2D6b
lbl3DFf:
    cmp word ptr [bp+6h],8h
    jnz short lbl40Ef
    mov ax,11h
    push ax
    push word ptr [bp+8h]
    call mf3ec
    add sp,4h
    or ax,ax
    jz short lbl40Ef
    mov ax,0Fh
    push ax
    push word ptr [bp+8h]
    call mf3ff
    add sp,4h
    or ax,ax
    jz short lbl40Ef
    jmp near ptr lbl2D6b
lbl40Ef:
    cmp word ptr [bp+6h],13h
    jnz short lbl417f
    jmp near ptr lbl2D6b
lbl417f:
    cmp word ptr [bp+6h],45h
    jnz short lbl420f
    jmp near ptr lbl2D6b
lbl420f:
    cmp word ptr [bp+6h],44h
    jnz short lbl43Cf
    mov ax,0Ch
    push ax
    push word ptr [bp+8h]
    call mf42d
    add sp,4h
    or ax,ax
    jz short lbl43Cf
    jmp near ptr lbl2D6b
lbl43Cf:
    mov ax,7h
    push ax
    push word ptr [bp+8h]
    call mf443
    add sp,4h
    or ax,ax
    jnz short lbl452f
    jmp near ptr lbl2DBb
lbl452f:
    jmp near ptr lbl2D6b
    nop
lbl456f:
    mov cl,3h
    mov bx,word ptr [bp-2h]
    shl bx,cl
    mov word ptr [bp-22h],bx
    mov si,word ptr es:[bx+md460]
    mov dx,ds
    mov di,si
    mov es,dx
    push ds
    lds si, dword ptr [bp+0Ch]
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
    add bx, offset mi489
    mov es, ds:[5A4Ch]
    mov word ptr [bp-26h],bx
    mov word ptr [bp-24h],es
    cmp word ptr es:[bx],24h
    jnz short lbl4CAf
    mov di,73Eh
    mov cx,ds
    mov es,cx
    push ds
    lds si, dword ptr [bp+0Ch]
    mov cx,0FFFFh
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
lbl4CAf:
    les bx, dword ptr [bp-26h]
    cmp word ptr es:[bx],21h
    jz short lbl4D9f
    cmp word ptr es:[bx],1Ch
    jnz short lbl506f
lbl4D9f:
    mov di,742h
    mov cx,ds
    mov es,cx
    push ds
    lds si, dword ptr [bp+0Ch]
    mov cx,0FFFFh
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
lbl506f:
    les bx, dword ptr [bp-26h]
    cmp word ptr es:[bx],2Fh
    jnz short lbl53Cf
    mov di,746h
    mov cx,ds
    mov es,cx
    push ds
    lds si, dword ptr [bp+0Ch]
    mov cx,0FFFFh
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
lbl53Cf:
    mov bx,word ptr [bp-22h]
    mov es, ds:[5A4Ch]
    mov ax,word ptr es:[bx+md543]
    mov word ptr [bp-28h],ax
    or ax,ax
    db 74h, 79h ; override
    les bx, dword ptr [bp-26h]
    cmp word ptr es:[bx],47h
    db 75h, 20h ; override
    mov es, ds:[5A50h]
    mov bx,word ptr [bp+0Ah]
    mov ax,bx
    add bx,bx
    add bx,ax
    add bx,bx
    cmp byte ptr es:[bx+md567],5h
    jnz short lbl578f
    mov word ptr [bp-12h],74Ch
    db 0EBh, 4Fh ; override
    nop
    nop
lbl578f:
    les bx, dword ptr [bp-26h]
    cmp word ptr es:[bx],38h
    db 75h, 1Fh ; override
    mov es, ds:[5A50h]
    mov bx,word ptr [bp+0Ah]
    mov ax,bx
    add bx,bx
    add bx,ax
    add bx,bx
    cmp byte ptr es:[bx+md590],5h
    jnz short lbl5A0f
    mov word ptr [bp-12h],74Fh
    jmp short lbl5C5f
    nop
lbl5A0f:
    les bx, dword ptr [bp-26h]
    cmp word ptr es:[bx],4Fh
    jnz short lbl5B0f
    cmp word ptr [bp+8h],124h
    jz short lbl5C0f
lbl5B0f:
    cmp word ptr [bp+8h],1D4h
    jz short lbl5C0f
    mov ax,word ptr [bp-28h]
    mov word ptr [bp-12h],ax
    jmp short lbl5C5f
    nop
lbl5C0f:
    mov word ptr [bp-12h],752h
lbl5C5f:
    mov word ptr [bp-10h],ds
lbl5C8f:
    cmp word ptr [bp+8h],0h
    jnz short lbl5D1f
    jmp near ptr lbl667f
lbl5D1f:
    mov ax,2h
    push ax
    push word ptr [bp+8h]
    call mf5d8
    add sp,4h
    or ax,ax
    jz short lbl5EAf
    mov di,755h
    jmp short lbl5EDf
    nop
lbl5EAf:
    mov di,757h
lbl5EDf:
    mov cx,ds
    mov es,cx
    push ds
    lds si, dword ptr [bp+0Ch]
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
    cmp word ptr [bp+6h],1Dh
    jnz short lbl630f
    cmp word ptr [bp+8h],9Bh
    jnz short lbl630f
    mov di,75Dh
    mov cx,ds
    mov es,cx
    jmp short lbl63Ff
    nop
lbl630f:
    push word ptr [bp+8h]
    call mf633
    add sp,2h
    mov di,ax
    mov es,dx
lbl63Ff:
    push ds
    lds si, dword ptr [bp+0Ch]
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
lbl667f:
    mov ax,word ptr [bp-10h]
    or ax,word ptr [bp-12h]
    jnz short lbl672f
    jmp near ptr lbl723f
lbl672f:
    mov di,764h
    mov cx,ds
    mov es,cx
    push ds
    lds si, dword ptr [bp+0Ch]
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
    mov ax,ds
    mov cx,3h
    mov di,766h
    mov es,ax
    push ds
    lds si, dword ptr [bp-12h]
    xor ax,ax
    repe cmpsb
    jz short lbl6BAf
    db 1Bh, 0C0h ; override
    sbb ax, offset mi6b7
lbl6BAf:
    pop ds
    or ax,ax
    jnz short lbl6F8f
    cmp word ptr [bp+0Ah],ax
    jz short lbl6F8f
    cmp word ptr [bp+6h],59h
    jz short lbl6F8f
    mov ax,11h
    push ax
    push word ptr [bp+0Ah]
    call mf6d1
    add sp,4h
    or ax,ax
    jnz short lbl6F0f
    mov ax,1h
    push ax
    push word ptr [bp+0Ah]
    call mf6e4
    add sp,4h
    or ax,ax
    jz short lbl6F8f
lbl6F0f:
    mov word ptr [bp-12h],769h
    mov word ptr [bp-10h],ds
lbl6F8f:
    les di, dword ptr [bp-12h]
    push ds
    lds si, dword ptr [bp+0Ch]
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
lbl723f:
    cmp word ptr [bp+0Ah],0h
    jz short lbl7A8f
    mov ax,2h
    push ax
    push word ptr [bp+0Ah]
    call mf730
    add sp,4h
    or ax,ax
    jz short lbl742f
    mov di,76Ch
    jmp short lbl745f
    nop
lbl742f:
    mov di,76Eh
lbl745f:
    mov cx,ds
    mov es,cx
    push ds
    lds si, dword ptr [bp+0Ch]
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
    push word ptr [bp+0Ah]
    call mf774
    add sp,2h
    mov di,ax
    mov es,dx
    push ds
    lds si, dword ptr [bp+0Ch]
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
lbl7A8f:
    mov ax,word ptr [bp+6h]
    mov word ptr ds:[69FAh],ax
    mov ax,word ptr [bp+8h]
    mov word ptr ds:[6A0Ah],ax
    mov ax,word ptr [bp+0Ah]
    mov word ptr ds:[6A08h],ax
    cmp word ptr [bp-4h],0h
    jnz short lbl7C4f
    xor ax,ax
    jmp short lbl7CEf
lbl7C4f:
    cmp word ptr [bp-6h],1h
    db 1Bh, 0C0h ; override
    and ax, offset mi7ca
    inc ax
lbl7CEf:
    pop si
    pop di
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
