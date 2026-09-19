_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf2f9:FAR
    EXTRN mf324:FAR
    EXTRN mf52:FAR
    EXTRN mf163:FAR
    EXTRN mf1cd:FAR
    EXTRN mifb:NEAR
    EXTRN mf26b:FAR
    EXTRN mf198:FAR
    EXTRN mf1c8:FAR
    EXTRN mf2a5:FAR
    EXTRN mi9:NEAR
    EXTRN mf188:FAR
    EXTRN mf38a:FAR
    EXTRN mf27b:FAR
    EXTRN mf148:FAR
    EXTRN mf21b:FAR
    EXTRN mf3a0:FAR
    EXTRN mf22f:FAR
    EXTRN mf331:FAR
    EXTRN mf2f1:FAR
    EXTRN mic:NEAR
    EXTRN mf17c:FAR
    EXTRN mf34f:FAR
    EXTRN mf382:FAR
    EXTRN mf243:FAR
    EXTRN mf1e6:FAR
    EXTRN md378:NEAR
    EXTRN mf200:FAR
    EXTRN mf1fb:FAR
    EXTRN mfc9:FAR
    EXTRN mf253:FAR
    EXTRN mfa4:FAR
    EXTRN mf342:FAR
    EXTRN md37d:NEAR
    EXTRN mf78:FAR
    EXTRN mf1c0:FAR
    EXTRN mf365:FAR
    EXTRN mfd9:FAR
    EXTRN mf2bb:FAR
    EXTRN mf2de:FAR
    EXTRN mf70:FAR
    EXTRN mf88:FAR
    EXTRN mf1b2:FAR
    EXTRN mf2cb:FAR
    EXTRN mf8e:FAR
    EXTRN mf292:FAR
    EXTRN mief:NEAR
    EXTRN mf134:FAR
    EXTRN mf3be:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,10h
    mov ax,word ptr [bp+6h]
    sub ax, offset mi9
    cmp ax, offset mic
    jna short lbl14f
    db 0E9h, 0AFh, 03h ; override
lbl14f:
    add ax,ax
    xchg ax,bx
    jmp word ptr cs:[bx+1DBh]
    db 05h, 02h, 82h, 05h, 1Dh, 02h, 82h, 05h, 27h, 02h, 0FFh, 02h, 0FFh, 02h, 0FFh, 02h
    db 82h, 05h, 13h, 03h, 82h, 05h, 87h, 03h, 82h, 05h, 82h, 05h, 82h, 05h, 82h, 05h
    db 82h, 05h, 82h, 05h, 99h, 03h, 71h, 05h, 87h, 03h
    mov ax,13Fh
    push ax
    push word ptr ds:[6A04h]
lbl4Eb:
    push word ptr ds:[6A06h]
    call mf52
    add sp,6h
    db 0E9h, 68h, 03h ; override
    nop
    push word ptr ds:[6A02h]
    mov ax,13Fh
    push ax
    jmp short lbl4Eb
    mov ax,0Ah
    push ax
    mov ax,13Eh
    push ax
    call mf70
    add sp,4h
    call mf78
    or ax,ax
    jnz short lbl88f
    mov ax,34BBh
    mov dx,ds
    jmp short lbl96f
lbl88f:
    call mf88
    push ax
    call mf8e
    add sp,2h
lbl96f:
    mov word ptr [bp-0Eh],ax
    mov word ptr [bp-0Ch],dx
    mov ax,0Eh
    push ax
    mov ax,144h
    push ax
    call mfa4
    add sp,4h
    or ax,ax
    jz short lblB6f
    mov ax,34ACh
    jmp short lblB9f
    nop
lblB6f:
    mov ax,34B3h
lblB9f:
    push ds
    push ax
    push word ptr [bp-0Ch]
    push word ptr [bp-0Eh]
    mov ax,2h
    mov dx,0F028h
    push dx
    push ax
    call mfc9
    add sp,0Ch
    mov ax,1h
    push ax
    mov ax,145h
    push ax
    call mfd9
    add sp,4h
    or ax,ax
    jnz short lblE8f
    db 0E9h, 0DBh, 02h ; override
lblE8f:
    cmp ax,0ADh
    jz short lbl10Ef
    jg short lblF6f
    sub ax, offset mief
    jz short lbl106f
    jmp short lbl126f
lblF6f:
    sub ax,149h
    jl short lbl126f
    sub ax, offset mifb
    jng short lbl116f
    dec ax
    jz short lbl11Ef
    jmp short lbl126f
    nop
lbl106f:
    mov word ptr [bp-0Ah],34D3h
    jmp short lbl123f
    nop
lbl10Ef:
    mov word ptr [bp-0Ah],34CAh
    jmp short lbl123f
    nop
lbl116f:
    mov word ptr [bp-0Ah],34BEh
    jmp short lbl123f
    nop
lbl11Ef:
    mov word ptr [bp-0Ah],34DAh
lbl123f:
    mov word ptr [bp-8h],ds
lbl126f:
    push word ptr [bp-8h]
    push word ptr [bp-0Ah]
    mov ax,3h
    mov dx,0F028h
    push dx
    push ax
    call mf134
    add sp,8h
    db 0E9h, 84h, 02h ; override
    nop
    mov ax,1h
    mov dx,0F028h
    push dx
    push ax
    call mf148
    add sp,4h
    db 0E9h, 70h, 02h ; override
    nop
    cmp word ptr ds:[6A22h],5Ah
    jnz short lbl1A0f
    mov ax,1h
    push ax
    mov ax,14Eh
    push ax
    call mf163
    add sp,4h
    or ax,ax
    jz short lbl1A0f
    mov byte ptr ds:[1D00h],0h
    mov ax,5A03h
    push ax
    mov ax,144h
    push ax
    call mf17c
    add sp,4h
    mov ax,0BB8h
    push ax
    call mf188
    add sp,2h
    mov ax,0E19h
    push ax
    mov ax,37Dh
    push ax
    call mf198
    add sp,4h
lbl1A0f:
    cmp word ptr ds:[6A22h],139h
    jz short lbl1ABf
    db 0E9h, 18h, 02h ; override
lbl1ABf:
    xor ax,ax
    push ax
    mov ax,21h
    push ax
    call mf1b2
    add sp,4h
    mov word ptr ds:[2D0h],1h
    call mf1c0
    db 0E9h, 0FBh, 01h ; override
    call mf1c8
    call mf1cd
    mov byte ptr ds:[5E34h],0h
    db 0E9h, 0E9h, 01h ; override
    mov ax,0Ah
    push ax
    mov ax,14h
    mov cx,33BDh
    push cx
    push ax
    call mf1e6
    add sp,6h
    mov word ptr [bp-4h],ax
    cmp byte ptr ds:[5E34h],0h
    jz short lbl1FBf
    db 0E9h, 0B2h, 01h ; override
lbl1FBf:
    call mf1fb
    call mf200
    cmp byte ptr ds:[30Eh],0h
    jz short lbl20Ff
    db 0E9h, 99h, 01h ; override
lbl20Ff:
    xor ax,ax
    push ax
    push ax
    mov cx,14h
    push cx
    mov dx,0E24h
    push dx
    call mf21b
    add sp,8h
    xor ax,ax
    push ax
    push ax
    mov cx,0Ah
    push cx
    mov cx,0E38h
    push cx
    call mf22f
    add sp,8h
    xor ax,ax
    push ax
    push ax
    mov cx,14h
    push cx
    mov cx,0E42h
    push cx
    call mf243
    add sp,8h
    mov ax,0Eh
    push ax
    mov ax,144h
    push ax
    call mf253
    add sp,4h
    or ax,ax
    jz short lbl273f
    xor ax,ax
    push ax
    push ax
    mov ax,5h
    push ax
    mov ax,0E82h
    push ax
    call mf26b
    add sp,8h
lbl273f:
    mov ax,0Eh
    push ax
    mov ax,144h
    push ax
    call mf27b
    add sp,4h
    or ax,ax
    jz short lbl28Af
    db 0E9h, 1Eh, 01h ; override
lbl28Af:
    mov ax,1h
    push ax
    mov ax,145h
    push ax
    call mf292
    add sp,4h
    or ax,ax
    jnz short lbl2A1f
    db 0E9h, 07h, 01h ; override
lbl2A1f:
    mov ax,0Bh
    push ax
    call mf2a5
    add sp,2h
    cmp word ptr ds:[58h],0h
    jnz short lbl2FEf
    cmp word ptr ds:[56h],1h
    jz short lbl2FEf
    call mf2bb
    xor al,al
    push ax
    mov cx,0Dh
    push cx
    mov dx,0E87h
    push dx
    call mf2cb
    add sp,6h
    xor al,al
    push ax
    mov cx,0Dh
    push cx
    mov cx,0E94h
    push cx
    call mf2de
    add sp,6h
    xor al,al
    push ax
    mov ax,0Eh
    push ax
    mov ax,0EA1h
    push ax
    call mf2f1
    add sp,6h
    call mf2f9
lbl2FEf:
    mov word ptr [bp-2h],0h
    mov word ptr [bp-10h],3498h
lbl308b:
    mov ax,word ptr ds:[6A1Eh]
    mov bx,word ptr [bp-10h]
    cmp word ptr [bx],ax
    jz short lbl324f
    inc word ptr [bp-2h]
    add word ptr [bp-10h],2h
    cmp word ptr [bp-10h],34A2h
    jc short lbl308b
    db 0E9h, 85h, 00h ; override
    nop
lbl324f:
    call mf324
    push word ptr ds:[6A1Eh]
    mov ax,12h
    push ax
    call mf331
    add sp,4h
    push dx
    push ax
    xor ax,ax
    mov dx,0F028h
    push dx
    push ax
    call mf342
    add sp,8h
    mov ax,34A2h
    push ds
    push ax
    call mf34f
    add sp,4h
    cmp word ptr ds:[58h],0h
    db 75h, 31h ; override
    cmp word ptr ds:[56h],1h
    db 74h, 2Ah ; override
    call mf365
    xor al,al
    push ax
    mov es, ds:[5B28h]
    mov bx,word ptr [bp-2h]
    add bx,bx
    add bx,bx
    push word ptr es:[bx+md378]
    push word ptr es:[bx+md37d]
    call mf382
    add sp,6h
    call mf38a
lbl38Ff:
    mov ax,1h
    push ax
    mov ax,143h
    push ax
    mov bx,word ptr [bp-2h]
    add bx,bx
    push word ptr [bx+3498h]
    call mf3a0
    add sp,6h
lbl3A8f:
    mov byte ptr ds:[5E34h],1h
lbl3ADf:
    mov ax,word ptr [bp-4h]
    jmp short lbl3C5f
    mov ax,0Fh
    push ax
    mov ax,8Ch
    mov cx,33BDh
    push cx
    push ax
    call mf3be
lbl3C3f:
    xor ax,ax
lbl3C5f:
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
