_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf2b5:FAR
    EXTRN mf2c8:FAR
    EXTRN mf792:FAR
    EXTRN mf1f4:FAR
    EXTRN mf35:FAR
    EXTRN md1e5:NEAR
    EXTRN mf771:FAR
    EXTRN mf334:FAR
    EXTRN mff5:FAR
    EXTRN mf4da:FAR
    EXTRN md163:NEAR
    EXTRN mf276:FAR
    EXTRN md2eb:NEAR
    EXTRN mi4b:NEAR
    EXTRN mf4c7:FAR
    EXTRN mf231:FAR
    EXTRN mi678:NEAR
    EXTRN mf3ee:FAR
    EXTRN mf7f2:FAR
    EXTRN mf140:FAR
    EXTRN mi53c:NEAR
    EXTRN mfcf:FAR
    EXTRN mi77:NEAR
    EXTRN mf1af:FAR
    EXTRN mi74d:NEAR
    EXTRN md267:NEAR
    EXTRN mfb9:FAR
    EXTRN mf1c2:FAR
    EXTRN mi74a:NEAR
    EXTRN mf172:FAR
    EXTRN mi651:NEAR
    EXTRN mf3c2:FAR
    EXTRN mi705:NEAR
    EXTRN mf12d:FAR
    EXTRN mfe2:FAR
    EXTRN mf9b:FAR
    EXTRN mf244:FAR
    EXTRN mf2fa:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,0B0h
    push di
    push si
    sub ax,ax
    mov word ptr [bp-6h],ax
    mov word ptr [bp-8h],ax
    mov word ptr [bp-14h],ax
    cmp word ptr [bp+8h],ax
    jg short lbl1Cf
    db 0E9h, 0E6h, 07h ; override
lbl1Cf:
    mov ax,word ptr ds:[84Ch]
    cmp word ptr [bp+8h],ax
    jna short lbl27f
    db 0E9h, 0DBh, 07h ; override
lbl27f:
    lea ax,word ptr [bp+0Ah]
    mov word ptr [bp-98h],ax
    mov word ptr [bp-96h],ss
    push word ptr [bp+8h]
    call mf35
    add sp,2h
    mov word ptr [bp-0Ch],ax
    mov word ptr [bp-0Ah],dx
    mov byte ptr [bp-94h],0h
    mov al,byte ptr [bp+6h]
    and ax, offset mi4b
    mov word ptr [bp-12h],ax
    or ax,ax
    jnz short lbl58f
    db 0E9h, 0E7h, 03h ; override
lbl58f:
    test byte ptr [bp+6h],10h
    jz short lbl66f
    mov word ptr [bp-10h],1h
    jmp short lbl75f
    nop
lbl66f:
    mov byte ptr [bp-94h],20h
    mov word ptr [bp-14h],1h
    mov word ptr [bp-10h],0h
lbl75f:
    dec ax
    dec ax
    cmp ax, offset mi77
    jna short lbl7Ff
    db 0E9h, 9Ch, 02h ; override
lbl7Ff:
    add ax,ax
    xchg ax,bx
    jmp word ptr cs:[bx+46CAh]
    nop
    db 0D6h, 46h, 0F4h, 46h, 58h, 47h, 0DAh, 47h, 5Ch, 48h, 0E0h, 48h
    mov ax,2h
    push ax
    push word ptr [bp+8h]
    call mf9b
    add sp,4h
    or ax,ax
    jz short lblAAf
    db 0E9h, 71h, 02h ; override
lblAAf:
    mov word ptr [bp-8h],15Ah
    db 0E9h, 66h, 02h ; override
    mov ax,2h
    push ax
    push word ptr [bp+8h]
    call mfb9
    add sp,4h
    or ax,ax
    jz short lblC8f
    db 0E9h, 53h, 02h ; override
lblC8f:
    mov ax,3h
    push ax
    push word ptr [bp+8h]
    call mfcf
    add sp,4h
    or ax,ax
    jnz short lbl10Ef
    mov ax,1h
    push ax
    push word ptr [bp+8h]
    call mfe2
    add sp,4h
    or ax,ax
    jnz short lbl10Ef
    mov ax,4h
    push ax
    push word ptr [bp+8h]
    call mff5
    add sp,4h
    or ax,ax
    jz short lbl108f
    mov ax,163h
    db 0E9h, 0Eh, 02h ; override
    nop
lbl108f:
    mov ax,166h
    db 0E9h, 07h, 02h ; override
lbl10Ef:
    mov word ptr [bp-8h],15Eh
    db 0E9h, 02h, 02h ; override
    mov ax,word ptr ds:[266h]
    cmp word ptr [bp+8h],ax
    db 74h, 72h ; override
    mov ax,word ptr ds:[268h]
    cmp word ptr [bp+8h],ax
    db 74h, 6Ah ; override
    mov ax,3h
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
    mov word ptr [bp-8h],16Ch
    db 0E9h, 0C4h, 01h ; override
lbl154f:
    mov es, ds:[5A38h]
    mov bx,word ptr [bp+8h]
    mov ax,bx
    add bx,bx
    add bx,ax
    add bx,bx
    cmp byte ptr es:[bx+md163],5h
    jnz short lbl18Af
    mov ax,16h
    push ax
    push word ptr [bp+8h]
    call mf172
    add sp,4h
    or ax,ax
    jz short lbl184f
    mov ax,171h
    db 0E9h, 91h, 01h ; override
lbl184f:
    mov ax,175h
    db 0E9h, 8Bh, 01h ; override
lbl18Af:
    mov ax,178h
    db 0E9h, 85h, 01h ; override
lbl190f:
    mov word ptr [bp-8h],168h
    db 0E9h, 80h, 01h ; override
    mov ax,word ptr ds:[266h]
    cmp word ptr [bp+8h],ax
    db 74h, 72h ; override
    mov ax,word ptr ds:[268h]
    cmp word ptr [bp+8h],ax
    db 74h, 6Ah ; override
    mov ax,3h
    push ax
    push word ptr [bp+8h]
    call mf1af
    add sp,4h
    or ax,ax
    jz short lbl1D6f
    mov ax,1h
    push ax
    push word ptr [bp+8h]
    call mf1c2
    add sp,4h
    or ax,ax
    jnz short lbl1D6f
    mov word ptr [bp-8h],180h
    db 0E9h, 42h, 01h ; override
lbl1D6f:
    mov es, ds:[5A38h]
    mov bx,word ptr [bp+8h]
    mov ax,bx
    add bx,bx
    add bx,ax
    add bx,bx
    cmp byte ptr es:[bx+md1e5],5h
    jnz short lbl20Cf
    mov ax,16h
    push ax
    push word ptr [bp+8h]
    call mf1f4
    add sp,4h
    or ax,ax
    jz short lbl206f
    mov ax,186h
    db 0E9h, 0Fh, 01h ; override
lbl206f:
    mov ax,18Ah
    db 0E9h, 09h, 01h ; override
lbl20Cf:
    mov ax,18Eh
    db 0E9h, 03h, 01h ; override
lbl212f:
    mov word ptr [bp-8h],17Bh
    db 0E9h, 0FEh, 00h ; override
    mov ax,word ptr ds:[266h]
    cmp word ptr [bp+8h],ax
    db 74h, 74h ; override
    mov ax,word ptr ds:[268h]
    cmp word ptr [bp+8h],ax
    db 74h, 6Ch ; override
    mov ax,3h
    push ax
    push word ptr [bp+8h]
    call mf231
    add sp,4h
    or ax,ax
    jz short lbl258f
    mov ax,1h
    push ax
    push word ptr [bp+8h]
    call mf244
    add sp,4h
    or ax,ax
    jnz short lbl258f
    mov word ptr [bp-8h],196h
    db 0E9h, 0C0h, 00h ; override
lbl258f:
    mov es, ds:[5A38h]
    mov bx,word ptr [bp+8h]
    mov ax,bx
    add bx,bx
    add bx,ax
    add bx,bx
    cmp byte ptr es:[bx+md267],5h
    jnz short lbl28Ef
    mov ax,16h
    push ax
    push word ptr [bp+8h]
    call mf276
    add sp,4h
    or ax,ax
    jz short lbl288f
    mov ax,19Bh
    db 0E9h, 8Dh, 00h ; override
lbl288f:
    mov ax,19Fh
    db 0E9h, 87h, 00h ; override
lbl28Ef:
    mov ax,1A3h
    db 0E9h, 81h, 00h ; override
    nop
    nop
lbl296f:
    mov word ptr [bp-8h],192h
    db 0EBh, 7Bh ; override
    nop
    mov ax,word ptr ds:[266h]
    cmp word ptr [bp+8h],ax
    jnz short lbl2AEf
    mov word ptr [bp-8h],1A6h
    db 0EBh, 6Bh ; override
    nop
lbl2AEf:
    mov ax,3h
    push ax
    push word ptr [bp+8h]
    call mf2b5
    add sp,4h
    or ax,ax
    jz short lbl2DCf
    mov ax,1h
    push ax
    push word ptr [bp+8h]
    call mf2c8
    add sp,4h
    or ax,ax
    jnz short lbl2DCf
    mov word ptr [bp-8h],1AFh
    db 0EBh, 3Dh ; override
    nop
lbl2DCf:
    mov es, ds:[5A38h]
    mov bx,word ptr [bp+8h]
    mov ax,bx
    add bx,bx
    add bx,ax
    add bx,bx
    cmp byte ptr es:[bx+md2eb],5h
    jnz short lbl312f
    mov ax,16h
    push ax
    push word ptr [bp+8h]
    call mf2fa
    add sp,4h
    or ax,ax
    jz short lbl30Cf
    mov ax,1BAh
    jmp short lbl315f
    nop
lbl30Cf:
    mov ax,1C2h
    jmp short lbl315f
    nop
lbl312f:
    mov ax,1CAh
lbl315f:
    mov word ptr [bp-8h],ax
lbl318f:
    mov word ptr [bp-6h],ds
lbl31Bf:
    mov ax,word ptr [bp-6h]
    or ax,word ptr [bp-8h]
    jnz short lbl326f
    jmp near ptr lbl3A7f
lbl326f:
    cmp word ptr [bp-10h],0h
    jz short lbl34Ef
    les bx, dword ptr [bp-8h]
    mov al,byte ptr es:[bx]
    cbw
    push ax
    call mf334
    add sp,2h
    mov si,word ptr [bp-14h]
    mov byte ptr [bp+si-94h],al
    inc word ptr [bp-14h]
    inc word ptr [bp-8h]
    mov word ptr [bp-10h],0h
lbl34Ef:
    les bx, dword ptr [bp-8h]
    cmp byte ptr es:[bx],0h
    jz short lbl38Af
    mov si,word ptr [bp-14h]
    lea ax,word ptr [bp+si-94h]
    mov word ptr [bp-0A4h],ax
lbl362b:
    lea ax,word ptr [bp-16h]
    cmp word ptr [bp-0A4h],ax
    jnc short lbl38Af
    les bx, dword ptr [bp-8h]
    mov al,byte ptr es:[bx]
    mov bx,word ptr [bp-0A4h]
    mov byte ptr [bx],al
    inc word ptr [bp-0A4h]
    inc word ptr [bp-14h]
    inc word ptr [bp-8h]
    les bx, dword ptr [bp-8h]
    cmp byte ptr es:[bx],0h
    jnz short lbl362b
lbl38Af:
    mov ax,word ptr [bp-12h]
    dec ax
    dec ax
    jl short lbl3A7f
    jo short lbl3A7f
    dec ax
    jg short lbl3A7f
    cmp word ptr [bp-14h],7Eh
    jnc short lbl3A7f
    mov si,word ptr [bp-14h]
    mov byte ptr [bp+si-94h],20h
    inc word ptr [bp-14h]
lbl3A7f:
    mov ax,word ptr [bp-12h]
    dec ax
    jnl short lbl3B0f
    jmp near ptr lbl43Ff
lbl3B0f:
    jno short lbl3B5f
    jmp near ptr lbl43Ff
lbl3B5f:
    dec ax
    dec ax
    jng short lbl3BCf
    jmp near ptr lbl43Ff
lbl3BCf:
    push word ptr [bp-0Ah]
    push word ptr [bp-0Ch]
    call mf3c2
    add sp,4h
    mov word ptr [bp-0Ch],ax
    mov word ptr [bp-0Ah],dx
    or dx,ax
    jz short lbl43Ff
    les bx, dword ptr [bp-0Ch]
    cmp byte ptr es:[bx],0h
    jz short lbl43Ff
    cmp word ptr [bp-10h],0h
    jz short lbl403f
    cmp word ptr [bp-14h],7Eh
    jnc short lbl403f
    mov al,byte ptr es:[bx]
    cbw
    push ax
    call mf3ee
    add sp,2h
    mov si,word ptr [bp-14h]
    mov byte ptr [bp+si-94h],al
    inc word ptr [bp-14h]
    inc word ptr [bp-0Ch]
lbl403f:
    les bx, dword ptr [bp-0Ch]
    cmp byte ptr es:[bx],0h
    jz short lbl43Ff
    mov si,word ptr [bp-14h]
    lea ax,word ptr [bp+si-94h]
    mov word ptr [bp-0A6h],ax
lbl417b:
    lea ax,word ptr [bp-16h]
    cmp word ptr [bp-0A6h],ax
    jnc short lbl43Ff
    les bx, dword ptr [bp-0Ch]
    mov al,byte ptr es:[bx]
    mov bx,word ptr [bp-0A6h]
    mov byte ptr [bx],al
    inc word ptr [bp-0A6h]
    inc word ptr [bp-14h]
    inc word ptr [bp-0Ch]
    les bx, dword ptr [bp-0Ch]
    cmp byte ptr es:[bx],0h
    jnz short lbl417b
lbl43Ff:
    test byte ptr [bp+6h],40h
    jnz short lbl448f
    jmp near ptr lbl741f
lbl448f:
    mov ax,word ptr [bp+0Ah]
    mov dx,word ptr [bp+0Ch]
    mov word ptr [bp-9Ch],ax
    mov word ptr [bp-9Ah],dx
    les di, dword ptr [bp-9Ch]
    mov cx,0FFFFh
    xor ax,ax
    repne scasb
    not cx
    dec cx
    mov word ptr [bp-9Eh],cx
    sub cx,2h
    mov word ptr [bp-0A0h],cx
    add cx,word ptr [bp-9Ch]
    mov ax,dx
    mov word ptr [bp-8h],cx
    mov word ptr [bp-6h],dx
    or ax,word ptr [bp-9Ch]
    jnz short lbl484f
    jmp near ptr lbl741f
lbl484f:
    mov bx,word ptr [bp-9Ch]
    cmp byte ptr es:[bx],0h
    jnz short lbl491f
    jmp near ptr lbl741f
lbl491f:
    cmp word ptr [bp-14h],7Eh
    jnc short lbl4A2f
    mov si,word ptr [bp-14h]
    mov byte ptr [bp+si-94h],20h
    inc word ptr [bp-14h]
lbl4A2f:
    mov si,word ptr [bp-14h]
    mov byte ptr [bp+si-94h],0h
    mov ax,word ptr ds:[266h]
    cmp word ptr [bp+8h],ax
    jnz short lbl4B5f
    jmp near ptr lbl6FEf
lbl4B5f:
    mov ax,word ptr ds:[268h]
    cmp word ptr [bp+8h],ax
    jnz short lbl4C0f
    jmp near ptr lbl6FEf
lbl4C0f:
    mov ax,3h
    push ax
    push word ptr [bp+8h]
    call mf4c7
    add sp,4h
    or ax,ax
    jz short lbl4E9f
    mov ax,1h
    push ax
    push word ptr [bp+8h]
    call mf4da
    add sp,4h
    or ax,ax
    jnz short lbl4E9f
    jmp near ptr lbl6FEf
lbl4E9f:
    mov word ptr [bp-0Eh],0h
    mov word ptr [bp-0A8h],10Ch
lbl4F4b:
    mov ax,word ptr [bp-0A8h]
    mov dx,ax
    mov di,ax
    mov ax,ds
    mov es,ax
    mov cx,0FFFFh
    xor ax,ax
    repne scasb
    not cx
    dec cx
    sub cx,word ptr [bp-9Eh]
    neg cx
    mov word ptr [bp-0A2h],cx
    or cx,cx
    jl short lbl559f
    mov bx,word ptr [bp-9Ch]
    mov cx,word ptr [bp-9Ah]
    add bx,word ptr [bp-0A2h]
    mov si,dx
    push ds
    push cx
    mov di,si
    mov si,bx
    pop ds
    mov cx,0FFFFh
    repne scasb
    not cx
    sub di,cx
    repe cmpsb
    jz short lbl53Ff
    db 1Bh, 0C0h ; override
    sbb ax, offset mi53c
lbl53Ff:
    pop ds
    or ax,ax
    jnz short lbl559f
    cmp word ptr [bp-0A2h],ax
    jz short lbl56Ef
    les bx, dword ptr [bp-9Ch]
    add bx,word ptr [bp-0A2h]
    cmp byte ptr es:[bx-1h],20h
    jz short lbl56Ef
lbl559f:
    inc word ptr [bp-0Eh]
    add word ptr [bp-0A8h],0Ch
    cmp word ptr [bp-0A8h],148h
    jc short lbl4F4b
    jmp near ptr lbl617f
    nop
    nop
lbl56Ef:
    mov ax,word ptr [bp-0Eh]
    mov cx,ax
    add ax,ax
    add ax,cx
    add ax,ax
    add ax,ax
    add ax,112h
    mov word ptr [bp-8h],ax
    mov word ptr [bp-6h],ds
    mov di,ax
    mov ax,ds
    mov es,ax
    mov cx,0FFFFh
    xor ax,ax
    repne scasb
    not cx
    dec cx
    add cx,word ptr [bp-0A2h]
    add cx,word ptr [bp-14h]
    cmp cx,7Eh
    jnc short lbl617f
    mov word ptr [bp-0Eh],ax
    cmp word ptr [bp-0A2h],ax
    jng short lbl5DFf
    mov si,word ptr [bp-14h]
    lea ax,word ptr [bp+si-94h]
    mov word ptr [bp-0AAh],ax
    mov ax,word ptr [bp-0A2h]
    add word ptr [bp-14h],ax
    mov es, [bp-9Ah]
lbl5BFb:
    mov bx,word ptr [bp-9Ch]
    mov si,word ptr [bp-0Eh]
    mov al,byte ptr es:[bx+si]
    mov bx,word ptr [bp-0AAh]
    inc word ptr [bp-0AAh]
    mov byte ptr [bx],al
    mov ax,word ptr [bp-0A2h]
    inc word ptr [bp-0Eh]
    cmp word ptr [bp-0Eh],ax
    jl short lbl5BFb
lbl5DFf:
    les bx, dword ptr [bp-8h]
    cmp byte ptr es:[bx],0h
    jz short lbl60Ff
    mov si,word ptr [bp-14h]
    lea ax,word ptr [bp+si-94h]
    mov word ptr [bp-0AEh],ax
lbl5F3b:
    mov al,byte ptr es:[bx]
    mov bx,word ptr [bp-0AEh]
    mov byte ptr [bx],al
    inc word ptr [bp-0AEh]
    inc word ptr [bp-14h]
    inc word ptr [bp-8h]
    les bx, dword ptr [bp-8h]
    cmp byte ptr es:[bx],0h
    jnz short lbl5F3b
lbl60Ff:
    mov si,word ptr [bp-14h]
    mov byte ptr [bp+si-94h],0h
lbl617f:
    cmp word ptr [bp-0Eh],5h
    jnc short lbl620f
    jmp near ptr lbl741f
lbl620f:
    cmp word ptr [bp-9Eh],2h
    jng short lbl66Cf
    mov word ptr [bp-0Eh],0h
    mov word ptr [bp-0B0h],148h
lbl632b:
    mov bx,word ptr [bp-0B0h]
    mov dx,ds
    mov di,bx
    mov es,dx
    push ds
    lds si, dword ptr [bp-8h]
    mov cx,0FFFFh
    xor ax,ax
    repne scasb
    not cx
    sub di,cx
    repe cmpsb
    jz short lbl654f
    db 1Bh, 0C0h ; override
    sbb ax, offset mi651
lbl654f:
    pop ds
    or ax,ax
    jz short lbl671f
    inc word ptr [bp-0Eh]
    add word ptr [bp-0B0h],3h
    cmp word ptr [bp-0B0h],15Ah
    jc short lbl632b
    jmp short lbl671f
    nop
lbl66Cf:
    mov word ptr [bp-0Eh],6h
lbl671f:
    mov ax,word ptr [bp-9Eh]
    add ax,word ptr [bp-14h]
    cmp ax, offset mi678
    jc short lbl680f
    jmp near ptr lbl741f
lbl680f:
    lea si,word ptr [bp-94h]
    push ds
    les di, dword ptr [bp-9Ch]
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
    cmp word ptr [bp-0Eh],2h
    jnl short lbl6CEf
    mov ax,word ptr ds:[1D1h]
    mov dx,word ptr ds:[1D3h]
    mov si,word ptr [bp-0A0h]
    add si,word ptr [bp-14h]
    mov word ptr [bp+si-94h],ax
    mov word ptr [bp+si-92h],dx
    lea ax,word ptr [si+3h]
    jmp short lbl73Ef
lbl6CEf:
    mov ax,word ptr [bp-9Eh]
    add ax,word ptr [bp-14h]
    mov word ptr [bp-14h],ax
    cmp word ptr [bp-0Eh],6h
    jnc short lbl6E8f
    mov si,ax
    mov byte ptr [bp+si-94h],65h
    inc word ptr [bp-14h]
lbl6E8f:
    mov si,word ptr [bp-14h]
    mov byte ptr [bp+si-94h],73h
    inc word ptr [bp-14h]
    mov si,word ptr [bp-14h]
    mov byte ptr [bp+si-94h],0h
    jmp short lbl741f
    nop
lbl6FEf:
    mov ax,word ptr [bp-9Eh]
    add ax,word ptr [bp-14h]
    cmp ax, offset mi705
    jnc short lbl741f
    lea si,word ptr [bp-94h]
    push ds
    les di, dword ptr [bp-9Ch]
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
    mov ax,word ptr [bp-9Eh]
    add ax,word ptr [bp-14h]
lbl73Ef:
    mov word ptr [bp-14h],ax
lbl741f:
    test byte ptr [bp+6h],20h
    jz short lbl75Df
    mov ax,word ptr [bp-14h]
    add ax, offset mi74a
    cmp ax, offset mi74d
    jnc short lbl75Df
    mov si,word ptr [bp-14h]
    mov byte ptr [bp+si-94h],2Eh
    inc word ptr [bp-14h]
lbl75Df:
    mov si,word ptr [bp-14h]
    mov byte ptr [bp+si-94h],0h
    test byte ptr [bp+6h],80h
    jz short lbl784f
lbl76Bb:
    lea ax,word ptr [bp-94h]
    push ss
    push ax
    call mf771
    add sp,4h
    sub ax,ax
    mov word ptr [bp-2h],ax
    mov word ptr [bp-4h],ax
    jmp short lbl7EBf
    nop
lbl784f:
    mov ax,word ptr [bp-14h]
    inc ax
    cmp ax,80h
    jc short lbl79Cf
    mov ax,1D5h
    push ds
    push ax
    call mf792
    add sp,4h
    jmp short lbl76Bb
lbl79Cf:
    mov ax,word ptr ds:[10Ah]
    add ax,word ptr [bp-14h]
    inc ax
    cmp ax,80h
    jc short lbl7AEf
    mov word ptr ds:[10Ah],0h
lbl7AEf:
    mov bx,word ptr ds:[10Ah]
    add bx,5CE4h
    mov dx,ds
    push ds
    lea di,word ptr [bp-94h]
    mov si,bx
    mov cx,ss
    mov es,cx
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
    mov word ptr [bp-4h],bx
    mov word ptr [bp-2h],dx
    mov ax,word ptr [bp-14h]
    inc ax
    add word ptr ds:[10Ah],ax
lbl7EBf:
    mov ax,6h
    push ax
    push word ptr [bp+8h]
    call mf7f2
    add sp,4h
    mov ax,word ptr [bp-4h]
    mov dx,word ptr [bp-2h]
    jmp short lbl805f
lbl802f:
    xor ax,ax
    cwd
lbl805f:
    pop si
    pop di
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
