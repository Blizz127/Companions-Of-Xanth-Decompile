_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf7a1:FAR
    EXTRN mie83:NEAR
    EXTRN mf78e:FAR
    EXTRN mf3c5:FAR
    EXTRN mf9de:FAR
    EXTRN mfd7c:FAR
    EXTRN mfad0:FAR
    EXTRN mfab6:FAR
    EXTRN mn51d:NEAR
    EXTRN mfd6a:FAR
    EXTRN mi195:NEAR
    EXTRN mi26c:NEAR
    EXTRN mnd61:NEAR
    EXTRN mi1eb:NEAR
    EXTRN mi937:NEAR
    EXTRN mf408:FAR
    EXTRN mic01:NEAR
    EXTRN mic1d:NEAR
    EXTRN mfaa3:FAR
    EXTRN mf73b:FAR
    EXTRN mf997:FAR
    EXTRN mf38a:FAR
    EXTRN mf4c9:FAR
    EXTRN mf371:FAR
    EXTRN mi1f6:NEAR
    EXTRN mi926:NEAR
    EXTRN mf427:FAR
    EXTRN mf2e3:FAR
    EXTRN mfde4:FAR
    EXTRN mf483:FAR
    EXTRN mic12:NEAR
    EXTRN miece:NEAR
    EXTRN mfa26:FAR
    EXTRN mfa4d:FAR
    EXTRN mi942:NEAR
    EXTRN mnedd:NEAR
    EXTRN mif31:NEAR
    EXTRN mfa65:FAR
    EXTRN mf526:FAR
    EXTRN mfd94:FAR
    EXTRN mi157:NEAR
    EXTRN mf2c4:FAR
    EXTRN mf4a6:FAR
    EXTRN mf673:FAR
    EXTRN mf6ba:FAR
    EXTRN mi1ad:NEAR
    EXTRN mf46b:FAR
    EXTRN mf552:FAR
    EXTRN mfc9b:FAR
    EXTRN mi267:NEAR
    EXTRN mf720:FAR
    EXTRN mf539:FAR
    EXTRN mi271:NEAR
    EXTRN mf30f:FAR
    EXTRN mn78b:NEAR
    EXTRN mf7ba:FAR
    EXTRN mnaa0:NEAR
    EXTRN mf3de:FAR
    EXTRN mne4b:NEAR
    EXTRN mf6f9:FAR
    EXTRN mi1da:NEAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,0B2h
    push ds
    push es
    push si
    push di
    mov ax,38AFh
    mov ds,ax
    mov word ptr [bp-16h],0h
    mov word ptr [bp-20h],0h
    lds si, dword ptr [bp+18h]
    les di, dword ptr [bp+0Ch]
    mov al,byte ptr [si+12h]
    cmp al,byte ptr es:[di+12h]
    jz short lbl31f
    mov word ptr [bp-2h],0FFFAh
    jmp near ptr lbl4DDf
lbl31f:
    mov al,byte ptr [si+13h]
    xor ah,ah
    mov word ptr [bp-4h],ax
    cmp al,byte ptr es:[di+13h]
    jz short lbl47f
    mov word ptr [bp-2h],0FFFAh
    jmp near ptr lbl4DDf
lbl47f:
    mov ax,word ptr [bp+16h]
    or ax,ax
    jnl short lbl58f
    neg ax
    add word ptr [bp+0Ah],ax
    xor ax,ax
    mov word ptr [bp+16h],ax
lbl58f:
    cmp ax,word ptr [si+0Ah]
    jna short lbl65f
    mov word ptr [bp-2h],0h
    jmp near ptr lbl4DDf
lbl65f:
    mov ax,word ptr [bp+12h]
    or ax,ax
    jnl short lbl74f
    mov word ptr [bp-2h],0h
    jmp near ptr lbl4DDf
lbl74f:
    cmp ax,word ptr [si+0Ah]
    jna short lbl7Ff
    mov ax,word ptr [si+0Ah]
    mov word ptr [bp+12h],ax
lbl7Ff:
    mov ax,word ptr es:[di+0Ah]
    cmp word ptr [bp+0Ah],ax
    jna short lbl90f
    mov word ptr [bp-2h],0h
    jmp near ptr lbl4DDf
lbl90f:
    sub ax,word ptr [bp+0Ah]
    inc ax
    mov bx,word ptr [bp+12h]
    sub bx,word ptr [bp+16h]
    inc bx
    cmp ax,bx
    jna short lblA1f
    mov ax,bx
lblA1f:
    mul word ptr [bp-4h]
    mov word ptr [bp-6h],ax
    mov bx,8h
    div bx
    xor bx,bx
    or dx,dx
    jz short lblB4f
    inc ax
    inc bx
lblB4f:
    mov word ptr [bp-0Ah],ax
    mov word ptr [bp-0Ch],ax
    mov word ptr [bp-28h],1h
    dec ax
    mov word ptr [bp-2Ah],ax
    mov word ptr [bp-2Ch],bx
    mov ax,word ptr [bp+14h]
    or ax,ax
    jnl short lblD7f
    neg ax
    add word ptr [bp+8h],ax
    xor ax,ax
    mov word ptr [bp+14h],ax
lblD7f:
    cmp ax,word ptr [si+0Ch]
    jna short lblE4f
    mov word ptr [bp-2h],0h
    jmp near ptr lbl4DDf
lblE4f:
    mov ax,word ptr [bp+10h]
    or ax,ax
    jnl short lblF3f
    mov word ptr [bp-2h],0h
    jmp near ptr lbl4DDf
lblF3f:
    cmp ax,word ptr [si+0Ch]
    jna short lblFEf
    mov ax,word ptr [si+0Ch]
    mov word ptr [bp+10h],ax
lblFEf:
    mov ax,word ptr es:[di+0Ch]
    cmp word ptr [bp+8h],ax
    jna short lbl10Ff
    mov word ptr [bp-2h],0h
    jmp near ptr lbl4DDf
lbl10Ff:
    sub ax,word ptr [bp+8h]
    inc ax
    mov bx,word ptr [bp+10h]
    sub bx,word ptr [bp+14h]
    inc bx
    cmp ax,bx
    jna short lbl120f
    mov ax,bx
lbl120f:
    mov bl,byte ptr es:[di+12h]
    xor bh,bh
    mul bx
    mov word ptr [bp-8h],ax
    cmp si,di
    jnz short lbl14Ef
    push ds
    pop ax
    push es
    pop bx
    cmp ax,bx
    jnz short lbl14Ef
    mov ax,ss
    mov es,ax
    lea di,word ptr [bp-0B2h]
    mov word ptr [bp+0Eh],ax
    mov word ptr [bp+0Ch],di
    mov cx,40h
    push si
    push di
    rep movsw
    pop di
    pop si
lbl14Ef:
    mov ax,word ptr [si+16h]
    cmp ax,word ptr es:[di+16h]
    jnz short lbl17Bf
    cmp ax, offset mi157
    jz short lbl17Bf
    mov bx,8000h
    mov word ptr [si+28h],0h
    mov word ptr [si+2Ah],2h
    mov word ptr [bp-16h],bx
    mov word ptr es:[di+28h],2h
    mov word ptr es:[di+2Ah],2h
    mov word ptr [bp-20h],bx
lbl17Bf:
    mov word ptr [bp-22h],0FFh
    mov word ptr [bp-24h],0h
    cmp byte ptr [bp-4h],8h
    jnz short lbl18Ef
    jmp near ptr lbl23Ff
lbl18Ef:
    mov ax,word ptr [bp+0Ah]
    mul word ptr [bp-4h]
    push ax
    and ax, offset mi195
    mov cx,ax
    mov al,0FFh
    shr al,cl
    mov byte ptr [bp-22h],al
    mov bx,8h
    sub bx,cx
    mov word ptr [bp-26h],bx
    pop ax
    add ax,word ptr [bp-6h]
    and ax, offset mi1ad
    mov cx,ax
    mov ah,0FFh
    shr ah,cl
    not ah
    mov byte ptr [bp-21h],ah
    cmp bx,word ptr [bp-6h]
    jl short lbl1D1f
    mov bx,word ptr [bp-6h]
    mov word ptr [bp-26h],bx
    or ah,ah
    jz short lbl1D1f
    and byte ptr [bp-22h],ah
    mov byte ptr [bp-21h],0h
lbl1D1f:
    mov ax,word ptr [bp+0Ah]
    sub ax,word ptr [bp+16h]
    mul word ptr [bp-4h]
    and ax, offset mi1da
    mov word ptr [bp-24h],ax
    mov word ptr [bp-28h],1h
    mov ax,word ptr [bp+16h]
    mul word ptr [bp-4h]
    and ax, offset mi1eb
    mov bx,ax
    mov ax,word ptr [bp+0Ah]
    mul word ptr [bp-4h]
    and ax, offset mi1f6
    cmp bx,ax
    jng short lbl200f
    inc word ptr [bp-28h]
lbl200f:
    mov ax,word ptr [bp-6h]
    sub ax,word ptr [bp-26h]
    mov bx,8h
    xor dx,dx
    div bx
    mov word ptr [bp-2Ah],ax
    or dx,dx
    jnz short lbl218f
    mov byte ptr [bp-21h],0h
lbl218f:
    mov word ptr [bp-2Ch],0h
    cmp dx,word ptr [bp-24h]
    jna short lbl225f
    inc word ptr [bp-2Ch]
lbl225f:
    mov ax,word ptr [bp-28h]
    add ax,word ptr [bp-2Ah]
    add ax,word ptr [bp-2Ch]
    mov word ptr [bp-0Ah],ax
    mov ax,word ptr [bp-2Ah]
    inc ax
    cmp byte ptr [bp-21h],0h
    jz short lbl23Cf
    inc ax
lbl23Cf:
    mov word ptr [bp-0Ch],ax
lbl23Ff:
    mov ax,word ptr [bp-16h]
    sub ax,word ptr [bp-0Ah]
    mov word ptr [bp-14h],ax
    mov ax,word ptr [si+14h]
    sub ax,word ptr [bp-0Ah]
    mov word ptr [bp-12h],ax
    mov ax,word ptr [bp-20h]
    sub ax,word ptr [bp-0Ch]
    mov word ptr [bp-1Eh],ax
    mov ax,word ptr es:[di+14h]
    sub ax,word ptr [bp-0Ch]
    mov word ptr [bp-1Ch],ax
    mov ax,word ptr [bp+6h]
    cmp ax, offset mi267
    jz short lbl287f
    cmp ax, offset mi26c
    jz short lbl298f
    cmp ax, offset mi271
    jz short lbl2A9f
    mov word ptr [bp-2Eh],342h
    mov word ptr [bp-30h],3B4h
    mov word ptr [bp-32h],457h
    jmp short lbl2B8f
lbl287f:
    mov word ptr [bp-2Eh],32Fh
    mov word ptr [bp-30h],3A5h
    mov word ptr [bp-32h],446h
    jmp short lbl2B8f
lbl298f:
    mov word ptr [bp-2Eh],334h
    mov word ptr [bp-30h],3AAh
    mov word ptr [bp-32h],44Bh
    jmp short lbl2B8f
lbl2A9f:
    mov word ptr [bp-2Eh],33Dh
    mov word ptr [bp-30h],3AFh
    mov word ptr [bp-32h],452h
lbl2B8f:
    push ds
    push si
    push word ptr [bp+16h]
    push word ptr [bp+14h]
    mov ax,0h
    push ax
    call mf2c4
    or dx,dx
    jnz short lbl2D3f
    mov word ptr [bp-2h],ax
    jmp near ptr lbl4DDf
lbl2D3f:
    mov ds,dx
    mov si,ax
    push es
    push di
    push word ptr [bp+0Ah]
    push word ptr [bp+8h]
    mov ax,1h
    push ax
    call mf2e3
    or dx,dx
    jnz short lbl2F2f
    mov word ptr [bp-2h],ax
    jmp near ptr lbl4DDf
lbl2F2f:
    mov es,dx
    mov di,ax
    cld
lbl2F7b:
    mov cx,word ptr [bp-24h]
    cmp byte ptr [bp-28h],1h
    jz short lbl31Cf
    lodsb
    mov ch,al
    cmp si,word ptr [bp-16h]
    jnz short lbl31Cf
    mov dx,word ptr [bp+1Ah]
    mov ax,word ptr [bp+18h]
    clc
    call mf30f
    jnc short lbl31Cf
    mov word ptr [bp-2h],ax
    jmp near ptr lbl4DDf
lbl31Cf:
    lodsb
    mov ah,ch
    mov ch,al
    ror ax,cl
    mov bl,byte ptr [bp-22h]
    and al,bl
    jmp word ptr [bp-2Eh]
    xor byte ptr es:[di],al
    jmp short lbl346f
    not bl
    or al,bl
    and byte ptr es:[di],al
    jmp short lbl346f
    or byte ptr es:[di],al
    jmp short lbl346f
    not bl
    and byte ptr es:[di],bl
    or byte ptr es:[di],al
lbl346f:
    inc di
    mov bx,word ptr [bp-2Ah]
    or bx,bx
    jnz short lbl351f
    jmp near ptr lbl3F5f
lbl351f:
    cmp word ptr [bp+6h],0h
    jnz short lbl365f
    or cl,cl
    jnz short lbl365f
    cmp si,word ptr [bp-14h]
    ja short lbl365f
    cmp di,word ptr [bp-1Eh]
    jna short lbl3B9f
lbl365b:
lbl365f:
    cmp di,word ptr [bp-20h]
    jnz short lbl37Ef
    mov dx,word ptr [bp+0Eh]
    mov ax,word ptr [bp+0Ch]
    stc
    call mf371
    jnc short lbl37Ef
    mov word ptr [bp-2h],ax
    jmp near ptr lbl4DDf
lbl37Ef:
    cmp si,word ptr [bp-16h]
    jnz short lbl397f
    mov dx,word ptr [bp+1Ah]
    mov ax,word ptr [bp+18h]
    clc
    call mf38a
    jnc short lbl397f
    mov word ptr [bp-2h],ax
    jmp near ptr lbl4DDf
lbl397f:
    lodsb
    mov ah,ch
    mov ch,al
    ror ax,cl
    jmp word ptr [bp-30h]
    xor byte ptr es:[di],al
    jmp short lbl3B3f
    and byte ptr es:[di],al
    jmp short lbl3B3f
    or byte ptr es:[di],al
    jmp short lbl3B3f
    mov byte ptr es:[di],al
lbl3B3f:
    inc di
    dec bx
    jnz short lbl365b
    jmp short lbl3F5f
lbl3B9f:
    cmp di,word ptr [bp-20h]
    jnz short lbl3D2f
    mov dx,word ptr [bp+0Eh]
    mov ax,word ptr [bp+0Ch]
    stc
    call mf3c5
    jnc short lbl3D2f
    mov word ptr [bp-2h],ax
    jmp near ptr lbl4DDf
lbl3D2f:
    cmp si,word ptr [bp-16h]
    jnz short lbl3EBf
    mov dx,word ptr [bp+1Ah]
    mov ax,word ptr [bp+18h]
    clc
    call mf3de
    jnc short lbl3EBf
    mov word ptr [bp-2h],ax
    jmp near ptr lbl4DDf
lbl3EBf:
    mov cx,bx
    shr cx,1
    rep movsw
    rcl cx,1
    rep movsb
lbl3F5f:
    mov bh,byte ptr [bp-21h]
    or bh,bh
    jz short lbl45Af
    cmp di,word ptr [bp-20h]
    jnz short lbl415f
    mov dx,word ptr [bp+0Eh]
    mov ax,word ptr [bp+0Ch]
    stc
    call mf408
    jnc short lbl415f
    mov word ptr [bp-2h],ax
    jmp near ptr lbl4DDf
lbl415f:
    cmp byte ptr [bp-2Ch],0h
    jz short lbl435f
    cmp si,word ptr [bp-16h]
    jnz short lbl434f
    mov dx,word ptr [bp+1Ah]
    mov ax,word ptr [bp+18h]
    clc
    call mf427
    jnc short lbl434f
    mov word ptr [bp-2h],ax
    jmp near ptr lbl4DDf
lbl434f:
    lodsb
lbl435f:
    mov ah,ch
    ror ax,cl
    mov dx,bx
    not dx
    and al,bh
    jmp word ptr [bp-32h]
    xor byte ptr es:[di],al
    jmp short lbl459f
    or al,dh
    and byte ptr es:[di],al
    jmp short lbl459f
    or byte ptr es:[di],al
    jmp short lbl459f
    and byte ptr es:[di],dh
    or byte ptr es:[di],al
lbl459f:
    inc di
lbl45Af:
    dec word ptr [bp-8h]
    jz short lbl4D8f
    cmp di,word ptr [bp-20h]
    jnz short lbl477f
    mov dx,word ptr [bp+0Eh]
    mov ax,word ptr [bp+0Ch]
    stc
    call mf46b
    jnc short lbl477f
    mov word ptr [bp-2h],ax
    jmp short lbl4DDf
lbl477f:
    cmp si,word ptr [bp-16h]
    jnz short lbl48Ff
    mov dx,word ptr [bp+1Ah]
    mov ax,word ptr [bp+18h]
    clc
    call mf483
    jnc short lbl48Ff
    mov word ptr [bp-2h],ax
    jmp short lbl4DDf
lbl48Ff:
    add si,word ptr [bp-12h]
    jc short lbl49Ff
    cmp word ptr [bp-16h],0h
    jz short lbl4B2f
    cmp si,word ptr [bp-16h]
    jc short lbl4B2f
lbl49Ff:
    mov dx,word ptr [bp+1Ah]
    mov ax,word ptr [bp+18h]
    clc
    call mf4a6
    jnc short lbl4B2f
    mov word ptr [bp-2h],ax
    jmp short lbl4DDf
lbl4B2f:
    add di,word ptr [bp-1Ch]
    jc short lbl4C2f
    cmp word ptr [bp-20h],0h
    jz short lbl4D5f
    cmp di,word ptr [bp-20h]
    jc short lbl4D5f
lbl4C2f:
    mov dx,word ptr [bp+0Eh]
    mov ax,word ptr [bp+0Ch]
    stc
    call mf4c9
    jnc short lbl4D5f
    mov word ptr [bp-2h],ax
    jmp short lbl4DDf
lbl4D5f:
    jmp near ptr lbl2F7b
lbl4D8f:
    mov word ptr [bp-2h],0h
lbl4DDf:
    lds si, dword ptr [bp+18h]
    mov word ptr [si+28h],0h
    mov word ptr [si+2Ah],4h
    les di, dword ptr [bp+0Ch]
    mov word ptr es:[di+28h],0h
    mov word ptr es:[di+2Ah],4h
    mov ax,word ptr [bp-2h]
    pop di
    pop si
    pop es
    pop ds
    mov sp,bp
    pop bp
    retf 16h
    push bp
    mov bp,sp
    sub sp,36h
    push ds
    push es
    push si
    push di
    mov ax,38AFh
    mov ds,ax
    cmp byte ptr ds:[525Bh],1h
    jz short lbl520f
    push cs
    call mn51d
lbl520f:
    mov ax,word ptr ds:[5254h]
    mov word ptr [bp-4h],ax
    call mf526
    or ax,ax
    jnl short lbl535f
    mov word ptr [bp-2h],ax
    jmp near ptr lbl6AAf
lbl535f:
    mov word ptr [bp-0Ch],ax
    push ax
    call mf539
    jnc short lbl548f
    mov word ptr [bp-2h],0FC19h
    jmp near ptr lbl6AAf
lbl548f:
    mov ds,dx
    mov si,ax
    cmp word ptr [bp-4h],1h
    jnz short lbl564f
    call mf552
    cmp al,byte ptr [si+16h]
    jz short lbl564f
    mov word ptr [bp-2h],0FFF9h
    jmp near ptr lbl6AAf
lbl564f:
    les di, dword ptr [bp+0Ah]
    mov al,byte ptr [si+17h]
    xor ah,ah
    mov word ptr [bp-0Eh],ax
    cmp al,byte ptr es:[di+13h]
    jz short lbl57Df
    mov word ptr [bp-2h],0FFFAh
    jmp near ptr lbl6AAf
lbl57Df:
    mov ax,word ptr [bp+16h]
    or ax,ax
    jnl short lbl58Ef
    neg ax
    add word ptr [bp+8h],ax
    xor ax,ax
    mov word ptr [bp+16h],ax
lbl58Ef:
    cmp ax,word ptr [si+18h]
    jc short lbl59Bf
    mov word ptr [bp-2h],0h
    jmp near ptr lbl6AAf
lbl59Bf:
    mov ax,word ptr [bp+12h]
    or ax,ax
    jnl short lbl5AAf
    mov word ptr [bp-2h],0h
    jmp near ptr lbl6AAf
lbl5AAf:
    cmp ax,word ptr [si+18h]
    jc short lbl5B6f
    mov ax,word ptr [si+18h]
    dec ax
    mov word ptr [bp+12h],ax
lbl5B6f:
    mov ax,word ptr es:[di+0Ah]
    cmp word ptr [bp+8h],ax
    jna short lbl5C7f
    mov word ptr [bp-2h],0h
    jmp near ptr lbl6AAf
lbl5C7f:
    sub ax,word ptr [bp+8h]
    inc ax
    mov bx,word ptr [bp+12h]
    sub bx,word ptr [bp+16h]
    inc bx
    cmp ax,bx
    jna short lbl5D8f
    mov ax,bx
lbl5D8f:
    mov word ptr [bp-12h],ax
    mul word ptr [bp-0Eh]
    mov word ptr [bp-14h],ax
    mov bx,8h
    div bx
    or dx,dx
    jz short lbl5EBf
    inc ax
lbl5EBf:
    mov word ptr [bp-1Ah],ax
    mov word ptr [bp-1Ch],ax
    mov ax,word ptr [bp+14h]
    or ax,ax
    jnl short lbl602f
    neg ax
    add word ptr [bp+6h],ax
    xor ax,ax
    mov word ptr [bp+14h],ax
lbl602f:
    cmp ax,word ptr [si+1Ah]
    jc short lbl60Ff
    mov word ptr [bp-2h],0h
    jmp near ptr lbl6AAf
lbl60Ff:
    mov ax,word ptr [bp+10h]
    or ax,ax
    jnl short lbl61Ef
    mov word ptr [bp-2h],0h
    jmp near ptr lbl6AAf
lbl61Ef:
    cmp ax,word ptr [si+1Ah]
    jc short lbl62Af
    mov ax,word ptr [si+1Ah]
    dec ax
    mov word ptr [bp+10h],ax
lbl62Af:
    mov ax,word ptr es:[di+0Ch]
    cmp word ptr [bp+6h],ax
    jna short lbl63Bf
    mov word ptr [bp-2h],0h
    jmp short lbl6AAf
    nop
lbl63Bf:
    sub ax,word ptr [bp+6h]
    inc ax
    mov bx,word ptr [bp+10h]
    sub bx,word ptr [bp+14h]
    inc bx
    cmp ax,bx
    jna short lbl64Cf
    mov ax,bx
lbl64Cf:
    mov word ptr [bp-16h],ax
    mov bl,byte ptr es:[di+12h]
    xor bh,bh
    mov word ptr [bp-10h],bx
    mul bx
    mov word ptr [bp-18h],ax
    mov word ptr [bp-2Ch],0FFFFh
    mov word ptr [bp-2Eh],0h
    push es
    push di
    push word ptr [bp+8h]
    push word ptr [bp+6h]
    mov ax,1h
    push ax
    call mf673
    or dx,dx
    jnz short lbl681f
    mov word ptr [bp-2h],ax
    jmp short lbl6AAf
lbl681f:
    mov word ptr [bp-8h],dx
    mov word ptr [bp-0Ah],ax
    mov ax,word ptr [si+1Ch]
    mov word ptr [bp-1Eh],ax
    sub ax,word ptr [bp-1Ah]
    mov word ptr [bp-20h],ax
    mov ax,word ptr es:[di+14h]
    neg ax
    mov word ptr [bp-2Ah],ax
    mov ax,word ptr es:[di+14h]
    sub ax,word ptr [bp-1Ch]
    mov word ptr [bp-22h],ax
    cld
    jmp word ptr [si+30h]
lbl6AAf:
    mov ax,word ptr [bp-2h]
    pop di
    pop si
    pop es
    pop ds
    mov sp,bp
    pop bp
    retf 12h
    xor ax,ax
    push ax
    call mf6ba
    mov bx,ax
    mov word ptr [bx+30h],1D3h
    add bx,36h
    mov byte ptr ds:[525Bh],1h
    retf
    mov bx,word ptr [bp+16h]
    mov ax,word ptr [bp+14h]
    db 0FFh, 5Ch, 26h ; override
    push dx
    mov dx,es
    mov ds,dx
    pop dx
    mov si,bx
    les di, dword ptr [bp-0Ah]
    mov bx,word ptr [bp-18h]
lbl6E6b:
    mov cx,word ptr [bp-1Ch]
    cmp di,word ptr [bp-2Ah]
    jna short lbl70Af
lbl6EEb:
    or di,di
    jnz short lbl705f
    mov dx,word ptr [bp+0Ch]
    mov ax,word ptr [bp+0Ah]
    stc
    call mf6f9
    jnc short lbl705f
    mov word ptr [bp-2h],ax
    jmp short lbl74Ef
lbl705f:
    movsb
    loop lbl6EEb
    jmp short lbl712f
lbl70Af:
    shr cx,1
    rep movsw
    rcl cx,1
    rep movsb
lbl712f:
    dec bx
    jz short lbl749f
    or di,di
    jnz short lbl72Cf
    mov dx,word ptr [bp+0Ch]
    mov ax,word ptr [bp+0Ah]
    stc
    call mf720
    jnc short lbl72Cf
    mov word ptr [bp-2h],ax
    jmp short lbl74Ef
lbl72Cf:
    add si,word ptr [bp-20h]
    add di,word ptr [bp-22h]
    jnc short lbl747f
    mov dx,word ptr [bp+0Ch]
    mov ax,word ptr [bp+0Ah]
    stc
    call mf73b
    jnc short lbl747f
    mov word ptr [bp-2h],ax
    jmp short lbl74Ef
lbl747f:
    jmp short lbl6E6b
lbl749f:
    mov word ptr [bp-2h],0h
lbl74Ef:
    mov ax,word ptr [bp-2h]
    pop di
    pop si
    pop es
    pop ds
    mov sp,bp
    pop bp
    retf 12h
    add byte ptr [di-75h],dl
    in al,dx
    sub sp,38h
    push ds
    push es
    push si
    push di
    mov ax,38AFh
    mov ds,ax
    mov ax,word ptr ds:[5256h]
    mov word ptr [bp-38h],ax
    push dx
    mov dx,40h
    mov es,dx
    pop dx
    mov dx,word ptr es:[63h]
    add dx,6h
    mov word ptr [bp-36h],dx
    cmp byte ptr ds:[525Ah],1h
    jz short lbl78Ef
    push cs
    call mn78b
lbl78Ef:
    call mf78e
    or ax,ax
    jnl short lbl79Df
    mov word ptr [bp-2h],ax
    jmp near ptr lbl9CEf
lbl79Df:
    mov word ptr [bp-0Ch],ax
    push ax
    call mf7a1
    jnc short lbl7B0f
    mov word ptr [bp-2h],0FC19h
    jmp near ptr lbl9CEf
lbl7B0f:
    mov es,dx
    mov di,ax
    cmp word ptr [bp-4h],1h
    jnz short lbl7CDf
    call mf7ba
    cmp al,byte ptr es:[di+16h]
    jz short lbl7CDf
    mov word ptr [bp-2h],0FFF9h
    jmp near ptr lbl9CEf
lbl7CDf:
    lds si, dword ptr [bp+14h]
    mov al,byte ptr es:[di+17h]
    xor ah,ah
    mov word ptr [bp-0Eh],ax
    cmp al,byte ptr [si+13h]
    jz short lbl7E6f
    mov word ptr [bp-2h],0FFFAh
    jmp near ptr lbl9CEf
lbl7E6f:
    mov ax,word ptr [bp+0Eh]
    or ax,ax
    jnl short lbl7F7f
    neg ax
    add word ptr [bp+12h],ax
    xor ax,ax
    mov word ptr [bp+0Eh],ax
lbl7F7f:
    cmp ax,word ptr es:[di+18h]
    jc short lbl805f
    mov word ptr [bp-2h],0h
    jmp near ptr lbl9CEf
lbl805f:
    mov ax,word ptr [bp+0Ah]
    or ax,ax
    jnl short lbl814f
    mov word ptr [bp-2h],0h
    jmp near ptr lbl9CEf
lbl814f:
    cmp ax,word ptr es:[di+18h]
    jc short lbl822f
    mov ax,word ptr es:[di+18h]
    dec ax
    mov word ptr [bp+0Ah],ax
lbl822f:
    mov ax,word ptr [si+0Ah]
    cmp word ptr [bp+12h],ax
    jna short lbl832f
    mov word ptr [bp-2h],0h
    jmp near ptr lbl9CEf
lbl832f:
    sub ax,word ptr [bp+12h]
    inc ax
    mov bx,word ptr [bp+0Ah]
    sub bx,word ptr [bp+0Eh]
    inc bx
    cmp ax,bx
    jna short lbl843f
    mov ax,bx
lbl843f:
    mov word ptr [bp-12h],ax
    mul word ptr [bp-0Eh]
    mov word ptr [bp-14h],ax
    mov bx,8h
    div bx
    or dx,dx
    jz short lbl856f
    inc ax
lbl856f:
    mov word ptr [bp-1Ah],ax
    mov word ptr [bp-1Ch],ax
    mov ax,word ptr [bp+0Ch]
    or ax,ax
    jnl short lbl86Df
    neg ax
    add word ptr [bp+10h],ax
    xor ax,ax
    mov word ptr [bp+0Ch],ax
lbl86Df:
    cmp ax,word ptr es:[di+1Ah]
    jc short lbl87Bf
    mov word ptr [bp-2h],0h
    jmp near ptr lbl9CEf
lbl87Bf:
    mov ax,word ptr [bp+8h]
    or ax,ax
    jnl short lbl88Af
    mov word ptr [bp-2h],0h
    jmp near ptr lbl9CEf
lbl88Af:
    cmp ax,word ptr es:[di+1Ah]
    jc short lbl898f
    mov ax,word ptr es:[di+1Ah]
    dec ax
    mov word ptr [bp+8h],ax
lbl898f:
    mov ax,word ptr [si+0Ch]
    cmp word ptr [bp+10h],ax
    jna short lbl8A8f
    mov word ptr [bp-2h],0h
    jmp near ptr lbl9CEf
lbl8A8f:
    sub ax,word ptr [bp+10h]
    inc ax
    mov bx,word ptr [bp+8h]
    sub bx,word ptr [bp+0Ch]
    inc bx
    cmp ax,bx
    jna short lbl8B9f
    mov ax,bx
lbl8B9f:
    mov word ptr [bp-16h],ax
    mov bl,byte ptr [si+12h]
    xor bh,bh
    mov word ptr [bp-10h],bx
    mul bx
    mov word ptr [bp-18h],ax
    mov word ptr [bp-2Ah],0FFFFh
    mov word ptr [bp-2Ch],0h
    cmp byte ptr [bp-0Eh],8h
    jnz short lbl8DCf
    jmp near ptr lbl98Bf
lbl8DCf:
    mov ax,word ptr [bp+0Eh]
    mul word ptr [bp-0Eh]
    mov cx,ax
    and cx,7h
    mov bx,8h
    sub bx,cx
    mov word ptr [bp-2Eh],bx
    mov dl,0FFh
    shr dl,cl
    mov byte ptr [bp-2Ah],dl
    add ax,word ptr [bp-14h]
    mov cx,ax
    and cx,7h
    mov dh,0FFh
    shr dh,cl
    not dh
    mov byte ptr [bp-29h],dh
    cmp bx,word ptr [bp-14h]
    jl short lbl91Df
    mov bx,word ptr [bp-14h]
    mov word ptr [bp-2Eh],bx
    or dh,dh
    jz short lbl91Df
    and byte ptr [bp-2Ah],dh
    mov byte ptr [bp-29h],0h
lbl91Df:
    mov ax,word ptr [bp+0Eh]
    sub ax,word ptr [bp+12h]
    mul word ptr [bp-0Eh]
    and ax, offset mi926
    mov word ptr [bp-2Ch],ax
    mov word ptr [bp-30h],1h
    mov ax,word ptr [bp+12h]
    mul word ptr [bp-0Eh]
    and ax, offset mi937
    mov bx,ax
    mov ax,word ptr [bp+0Eh]
    mul word ptr [bp-0Eh]
    and ax, offset mi942
    cmp bx,ax
    jng short lbl94Cf
    inc word ptr [bp-30h]
lbl94Cf:
    mov ax,word ptr [bp-14h]
    sub ax,word ptr [bp-2Eh]
    mov bx,8h
    xor dx,dx
    div bx
    mov word ptr [bp-32h],ax
    or dx,dx
    jnz short lbl964f
    mov byte ptr [bp-29h],0h
lbl964f:
    mov word ptr [bp-34h],0h
    cmp dx,word ptr [bp-2Ch]
    jna short lbl971f
    inc word ptr [bp-34h]
lbl971f:
    mov ax,word ptr [bp-30h]
    add ax,word ptr [bp-32h]
    add ax,word ptr [bp-34h]
    mov word ptr [bp-1Ah],ax
    mov ax,word ptr [bp-32h]
    inc ax
    cmp byte ptr [bp-29h],0h
    jz short lbl988f
    inc ax
lbl988f:
    mov word ptr [bp-1Ch],ax
lbl98Bf:
    push ds
    push si
    push word ptr [bp+12h]
    push word ptr [bp+10h]
    mov ax,0h
    push ax
    call mf997
    or dx,dx
    jnz short lbl9A5f
    mov word ptr [bp-2h],ax
    jmp short lbl9CEf
lbl9A5f:
    mov word ptr [bp-8h],dx
    mov word ptr [bp-0Ah],ax
    mov ax,word ptr [si+14h]
    neg ax
    mov word ptr [bp-28h],ax
    mov ax,word ptr [si+14h]
    sub ax,word ptr [bp-1Ah]
    mov word ptr [bp-20h],ax
    mov ax,word ptr es:[di+1Ch]
    mov word ptr [bp-1Eh],ax
    sub ax,word ptr [bp-1Ch]
    mov word ptr [bp-22h],ax
    cld
    jmp word ptr es:[di+2Eh]
lbl9CEf:
    mov ax,word ptr [bp-2h]
    pop di
    pop si
    pop es
    pop ds
    mov sp,bp
    pop bp
    retf 12h
    xor ax,ax
    push ax
    call mf9de
    mov bx,ax
    mov word ptr [bx+2Eh],297h
    add bx,36h
    mov byte ptr ds:[525Ah],1h
    retf
    mov bx,word ptr [bp+0Eh]
    mov ax,word ptr [bp+0Ch]
    db 26h, 0FFh, 5Dh, 26h ; override
    mov di,bx
    lds si, dword ptr [bp-0Ah]
    mov bx,word ptr [bp-18h]
    cmp word ptr [bp-38h],0h
    jz short lblA13f
    mov dx,word ptr [bp-36h]
lblA0Eb:
    in al,dx
    test al,8h
    jz short lblA0Eb
lblA13b:
lblA13f:
    mov cx,word ptr [bp-1Ch]
    cmp si,word ptr [bp-28h]
    jna short lblA37f
lblA1Bb:
    or si,si
    jnz short lblA32f
    mov dx,word ptr [bp+16h]
    mov ax,word ptr [bp+14h]
    clc
    call mfa26
    jnc short lblA32f
    mov word ptr [bp-2h],ax
    jmp short lblA7Bf
lblA32f:
    movsb
    loop lblA1Bb
    jmp short lblA3Ff
lblA37f:
    shr cx,1
    rep movsw
    rcl cx,1
    rep movsb
lblA3Ff:
    dec bx
    jz short lblA76f
    or si,si
    jnz short lblA59f
    mov dx,word ptr [bp+16h]
    mov ax,word ptr [bp+14h]
    clc
    call mfa4d
    jnc short lblA59f
    mov word ptr [bp-2h],ax
    jmp short lblA7Bf
lblA59f:
    add si,word ptr [bp-20h]
    jnc short lblA71f
    mov dx,word ptr [bp+16h]
    mov ax,word ptr [bp+14h]
    clc
    call mfa65
    jnc short lblA71f
    mov word ptr [bp-2h],ax
    jmp short lblA7Bf
lblA71f:
    add di,word ptr [bp-22h]
    jmp short lblA13b
lblA76f:
    mov word ptr [bp-2h],0h
lblA7Bf:
    mov ax,word ptr [bp-2h]
    pop di
    pop si
    pop es
    pop ds
    mov sp,bp
    pop bp
    retf 12h
    push bp
    mov bp,sp
    sub sp,0D0h
    push ds
    push es
    push si
    push di
    mov ax,38AFh
    mov ds,ax
    cmp byte ptr ds:[525Dh],1h
    jz short lblAA3f
    push cs
    call mnaa0
lblAA3f:
    call mfaa3
    mov word ptr [bp-0Eh],ax
    or ax,ax
    jnl short lblAB5f
    mov word ptr [bp-2h],ax
    jmp near ptr lblC8Af
lblAB5f:
    push ax
    call mfab6
    jnc short lblAC5f
    mov word ptr [bp-2h],0FC19h
    jmp near ptr lblC8Af
lblAC5f:
    mov es,dx
    mov di,ax
    cmp word ptr ds:[5254h],1h
    jnz short lblAE3f
    call mfad0
    cmp al,byte ptr es:[di+16h]
    jz short lblAE3f
    mov word ptr [bp-2h],0FFF9h
    jmp near ptr lblC8Af
lblAE3f:
    mov al,byte ptr es:[di+17h]
    xor ah,ah
    mov word ptr [bp-28h],ax
    mov bx,word ptr es:[di+18h]
    dec bx
    cmp word ptr [bp+14h],bx
    jna short lblAFEf
    mov word ptr [bp-2h],0FFE5h
    jmp near ptr lblC8Af
lblAFEf:
    cmp word ptr [bp+10h],bx
    jna short lblB06f
    mov word ptr [bp+10h],bx
lblB06f:
    cmp word ptr [bp+0Ah],bx
    jna short lblB13f
    mov word ptr [bp-2h],0FFE5h
    jmp near ptr lblC8Af
lblB13f:
    mov ax,word ptr [bp+10h]
    sub ax,word ptr [bp+14h]
    add ax,word ptr [bp+0Ah]
    cmp ax,bx
    jna short lblB22f
    mov ax,bx
lblB22f:
    mov word ptr [bp-4h],ax
    sub ax,word ptr [bp+0Ah]
    add ax,word ptr [bp+14h]
    mov word ptr [bp+10h],ax
    sub ax,word ptr [bp+14h]
    inc ax
    mov word ptr [bp-10h],ax
    mul word ptr [bp-28h]
    mov word ptr [bp-2Ah],ax
    mov bx,8h
    xor dx,dx
    div bx
    or dx,dx
    jz short lblB47f
    inc ax
lblB47f:
    mov word ptr [bp-8h],ax
    mov word ptr [bp-0Ah],ax
    mov bx,word ptr es:[di+1Ah]
    dec bx
    cmp word ptr [bp+12h],bx
    jna short lblB5Ff
    mov word ptr [bp-2h],0FFE5h
    jmp near ptr lblC8Af
lblB5Ff:
    cmp word ptr [bp+0Eh],bx
    jna short lblB67f
    mov word ptr [bp+0Eh],bx
lblB67f:
    cmp word ptr [bp+8h],bx
    jna short lblB74f
    mov word ptr [bp-2h],0FFE5h
    jmp near ptr lblC8Af
lblB74f:
    mov ax,word ptr [bp+0Eh]
    sub ax,word ptr [bp+12h]
    add ax,word ptr [bp+8h]
    cmp ax,bx
    jna short lblB83f
    mov ax,bx
lblB83f:
    mov word ptr [bp-6h],ax
    sub ax,word ptr [bp+8h]
    add ax,word ptr [bp+12h]
    mov word ptr [bp+0Eh],ax
    sub ax,word ptr [bp+12h]
    inc ax
    mov word ptr [bp-12h],ax
    mov bl,byte ptr es:[di+1Eh]
    xor bh,bh
    mov word ptr [bp-2Ch],bx
    mul bx
    mov word ptr [bp-2Eh],ax
    mov word ptr [bp-1Ch],0FFFFh
    mov word ptr [bp-1Eh],0h
    cmp byte ptr [bp-28h],8h
    jnz short lblBB7f
    jmp near ptr lblC66f
lblBB7f:
    mov ax,word ptr [bp+0Ah]
    mul word ptr [bp-28h]
    mov cx,ax
    and cx,7h
    mov bx,8h
    sub bx,cx
    mov word ptr [bp-20h],bx
    mov dl,0FFh
    shr dl,cl
    mov byte ptr [bp-1Ch],dl
    add ax,word ptr [bp-2Ah]
    mov cx,ax
    and cx,7h
    mov dh,0FFh
    shr dh,cl
    not dh
    mov byte ptr [bp-1Bh],dh
    cmp bx,word ptr [bp-2Ah]
    jl short lblBF8f
    mov bx,word ptr [bp-2Ah]
    mov word ptr [bp-20h],bx
    or dh,dh
    jz short lblBF8f
    and byte ptr [bp-1Ch],dh
    mov byte ptr [bp-1Bh],0h
lblBF8f:
    mov ax,word ptr [bp+0Ah]
    sub ax,word ptr [bp+14h]
    mul word ptr [bp-28h]
    and ax, offset mic01
    mov word ptr [bp-1Eh],ax
    mov word ptr [bp-22h],1h
    mov ax,word ptr [bp+14h]
    mul word ptr [bp-28h]
    and ax, offset mic12
    mov bx,ax
    mov ax,word ptr [bp+0Ah]
    mul word ptr [bp-28h]
    and ax, offset mic1d
    cmp bx,ax
    jng short lblC27f
    inc word ptr [bp-22h]
lblC27f:
    mov ax,word ptr [bp-2Ah]
    sub ax,word ptr [bp-20h]
    mov bx,8h
    xor dx,dx
    div bx
    mov word ptr [bp-24h],ax
    or dx,dx
    jnz short lblC3Ff
    mov byte ptr [bp-1Bh],0h
lblC3Ff:
    mov word ptr [bp-26h],0h
    cmp dx,word ptr [bp-1Eh]
    jna short lblC4Cf
    inc word ptr [bp-26h]
lblC4Cf:
    mov ax,word ptr [bp-22h]
    add ax,word ptr [bp-24h]
    add ax,word ptr [bp-26h]
    mov word ptr [bp-8h],ax
    mov ax,word ptr [bp-24h]
    inc ax
    cmp byte ptr [bp-1Bh],0h
    jz short lblC63f
    inc ax
lblC63f:
    mov word ptr [bp-0Ah],ax
lblC66f:
    mov ax,word ptr es:[di+1Ch]
    neg ax
    mov word ptr [bp-48h],ax
    mov ax,word ptr es:[di+1Ch]
    mov word ptr [bp-0Ch],ax
    sub ax,word ptr [bp-8h]
    mov word ptr [bp-14h],ax
    mov ax,word ptr es:[di+1Ch]
    sub ax,word ptr [bp-0Ah]
    mov word ptr [bp-16h],ax
    jmp word ptr es:[di+34h]
lblC8Af:
    mov ax,word ptr [bp-2h]
    pop di
    pop si
    pop es
    pop ds
    mov sp,bp
    pop bp
    retf 10h
    push ds
    xor ax,ax
    push ax
    call mfc9b
    mov ds,dx
    mov bx,ax
    mov word ptr [bx+34h],237h
    add bx,36h
    mov byte ptr ds:[525Dh],1h
    pop ds
    retf
    mov ax,word ptr [bp+12h]
    cmp ax,word ptr [bp+8h]
    jng short lblCBDf
    jmp short lblCD5f
lblCBDf:
    cmp ax,word ptr [bp+8h]
    jz short lblCC4f
    jmp short lblCFAf
lblCC4f:
    mov ax,word ptr [bp+14h]
    cmp ax,word ptr [bp+0Ah]
    jnl short lblCCEf
    jmp short lblCFAf
lblCCEf:
    cmp ax,word ptr [bp+0Ah]
    jg short lblCD5f
    jmp short lblD36f
lblCD5f:
    push es
    push di
    mov bx,word ptr [bp+14h]
    mov ax,word ptr [bp+12h]
    db 26h, 0FFh, 5Dh, 26h ; override
    push dx
    mov dx,es
    mov ds,dx
    pop dx
    mov si,bx
    pop di
    pop es
    mov bx,word ptr [bp+0Ah]
    mov ax,word ptr [bp+8h]
    db 26h, 0FFh, 5Dh, 26h ; override
    mov di,bx
    cld
    jmp short lblD23f
lblCFAf:
    push es
    push di
    mov bx,word ptr [bp+10h]
    mov ax,word ptr [bp+0Eh]
    db 26h, 0FFh, 5Dh, 26h ; override
    push dx
    mov dx,es
    mov ds,dx
    pop dx
    mov si,bx
    pop di
    pop es
    mov bx,word ptr [bp-4h]
    mov ax,word ptr [bp-6h]
    db 26h, 0FFh, 5Dh, 26h ; override
    mov di,bx
    std
    neg word ptr [bp-14h]
    neg word ptr [bp-16h]
lblD23f:
    mov bx,word ptr [bp-10h]
    mov dx,word ptr [bp-12h]
lblD29b:
    mov cx,bx
    rep movsb
    add si,word ptr [bp-14h]
    add di,word ptr [bp-16h]
    dec dx
    jnz short lblD29b
lblD36f:
    mov word ptr [bp-2h],0h
    cld
    mov ax,word ptr [bp-2h]
    pop di
    pop si
    pop es
    pop ds
    mov sp,bp
    pop bp
    retf 10h
    add byte ptr [di-75h],dl
    in al,dx
    sub sp,12h
    push ds
    push es
    push si
    push di
    mov ax,38AFh
    mov ds,ax
    cmp byte ptr ds:[525Ch],1h
    jz short lblD64f
    push cs
    call mnd61
lblD64f:
    mov ax,word ptr ds:[5254h]
    mov word ptr [bp-4h],ax
    call mfd6a
    or ax,ax
    jnl short lblD78f
    mov word ptr [bp-2h],ax
    jmp short lblDD4f
lblD78f:
    mov word ptr [bp-0Eh],ax
    push ax
    call mfd7c
    jnc short lblD8Af
    mov word ptr [bp-2h],0FC19h
    jmp short lblDD4f
lblD8Af:
    mov ds,dx
    mov si,ax
    cmp word ptr [bp-4h],1h
    jnz short lblDA5f
    call mfd94
    cmp al,byte ptr [si+16h]
    jz short lblDA5f
    mov word ptr [bp-2h],0FFF9h
    jmp short lblDD4f
lblDA5f:
    mov al,byte ptr [si+1Eh]
    xor ah,ah
    mov bx,word ptr [si+1Ah]
    mov word ptr [bp-8h],bx
    mul bx
    mov word ptr [bp-0Ah],ax
    mov ax,word ptr [si+18h]
    mov word ptr [bp-6h],ax
    mov ax,word ptr [si+1Ch]
    mov word ptr [bp-0Ch],ax
    mov ax,word ptr [si+22h]
    mov bx,word ptr [bp+6h]
    mul bx
    mov di,ax
    mov bx,word ptr [si+20h]
    mov es,bx
    cld
    jmp word ptr [si+32h]
lblDD4f:
    mov ax,word ptr [bp-2h]
    pop di
    pop si
    pop es
    pop ds
    mov sp,bp
    pop bp
    retf 4h
    xor ax,ax
    push ax
    call mfde4
    mov bx,ax
    mov word ptr [bx+32h],0BDh
    add bx,36h
    mov byte ptr ds:[525Ch],1h
    retf
    mov ax,word ptr [bp-0Ch]
    mov bx,word ptr [bp-0Ah]
    mul bx
    shr ax,1
    mov cx,ax
    mov ax,word ptr [bp+8h]
    mov ah,al
    rep stosw
    mov word ptr [bp-2h],0h
    mov ax,word ptr [bp-2h]
    pop di
    pop si
    pop es
    pop ds
    mov sp,bp
    pop bp
    retf 4h
    db 86h, 0E0h ; override
    add bx,ax
    shr ax,1
    shr ax,1
    add bx,ax
    push ax
    push ds
    mov ax,38AFh
    mov ds,ax
    mov ax,word ptr ds:[42E6h]
    pop ds
    mov es,ax
    pop ax
    retf
    add byte ptr [di-75h],dl
    in al,dx
    sub sp,2h
    push ds
    push es
    push si
    push di
    mov ax,38AFh
    mov ds,ax
    push word ptr [bp+6h]
    push cs
    call mne4b
    jnc short lblE57f
    mov word ptr [bp-2h],0FC19h
    jmp short lblE64f
lblE57f:
    mov es,dx
    mov di,ax
    mov al,byte ptr es:[di+3h]
    xor ah,ah
    mov word ptr [bp-2h],ax
lblE64f:
    mov ax,word ptr [bp-2h]
    pop di
    pop si
    pop es
    pop ds
    mov sp,bp
    pop bp
    retf 2h
    push bp
    mov bp,sp
    sub sp,2h
    push ds
    push es
    push si
    push di
    mov ax,38AFh
    mov ds,ax
    mov ax,word ptr [bp+6h]
    cmp ax, offset mie83
    jna short lblE90f
    mov word ptr [bp-2h],0FFFAh
    stc
    jmp short lblEAFf
lblE90f:
    mov si,5294h
    mov cx,4h
lblE96b:
    cmp al,byte ptr [si]
    jz short lblEA7f
    add si,6h
    loop lblE96b
    mov word ptr [bp-2h],0FC19h
    stc
    jmp short lblEAFf
lblEA7f:
    mov dx,ds
    mov ax,si
    mov word ptr [bp-2h],ax
    clc
lblEAFf:
    mov ax,word ptr [bp-2h]
    pop di
    pop si
    pop es
    pop ds
    mov sp,bp
    pop bp
    retf 2h
    push bp
    mov bp,sp
    sub sp,2h
    push ds
    push es
    push si
    push di
    mov ax,38AFh
    mov ds,ax
    mov ax,word ptr [bp+6h]
    cmp ax, offset miece
    jna short lblEDBf
    mov word ptr [bp-2h],0FFFAh
    stc
    jmp short lblF0Ff
lblEDBf:
    push ax
    push cs
    call mnedd
    jnc short lblEE8f
    mov word ptr [bp-2h],ax
    stc
    jmp short lblF0Ff
lblEE8f:
    mov es,dx
    mov di,ax
    mov si,525Eh
    mov al,36h
    mul byte ptr es:[di+3h]
    add si,ax
    mov al,byte ptr es:[di+2h]
    cmp al,byte ptr [si]
    jz short lblF07f
    mov word ptr [bp-2h],0FC19h
    stc
    jmp short lblF0Ff
lblF07f:
    mov dx,ds
    mov ax,si
    mov word ptr [bp-2h],ax
    clc
lblF0Ff:
    mov ax,word ptr [bp-2h]
    pop di
    pop si
    pop es
    pop ds
    mov sp,bp
    pop bp
    retf 2h
    push bp
    mov bp,sp
    sub sp,2h
    push ds
    push es
    push si
    push di
    mov ax,38AFh
    mov ds,ax
    push bp
    mov ah,0Fh
    int 10h
    pop bp
    and ax, offset mif31
    mov word ptr [bp-2h],ax
    mov ax,word ptr [bp-2h]
    pop di
    pop si
    pop es
    pop ds
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
