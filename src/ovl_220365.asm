_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf417:FAR
    EXTRN mi208:NEAR
    EXTRN mf17f:FAR
    EXTRN md2a0:NEAR
    EXTRN md2da:NEAR
    EXTRN mf198:FAR
    EXTRN mf5d:FAR
    EXTRN mf2a5:FAR
    EXTRN mf89:FAR
    EXTRN mf39:FAR
    EXTRN mi220:NEAR
    EXTRN md3ef:NEAR
    EXTRN mf4dc:FAR
    EXTRN mf6d:FAR
    EXTRN mi109:NEAR
    EXTRN md275:NEAR
    EXTRN mf342:FAR
    EXTRN mf320:FAR
    EXTRN mf494:FAR
    EXTRN md2bd:NEAR
    EXTRN mf175:FAR
    EXTRN md3df:NEAR
    EXTRN md299:NEAR
    EXTRN mf281:FAR
    EXTRN md270:NEAR
    EXTRN mf2c9:FAR
    EXTRN mf31:FAR
    EXTRN md2b1:NEAR
    EXTRN md27a:NEAR
    EXTRN mf3cc:FAR
    EXTRN mf96:FAR
    EXTRN mi1fc:NEAR
    EXTRN mf4a8:FAR
    EXTRN md2e4:NEAR
    EXTRN mf91:FAR
    EXTRN md3e4:NEAR
    EXTRN mi214:NEAR
    EXTRN mf1d4:FAR
    EXTRN md2d5:NEAR
    EXTRN md2c4:NEAR
    EXTRN mf7d:FAR
    EXTRN mf2e9:FAR
    EXTRN micd:NEAR
    EXTRN mf18:FAR
    EXTRN mid5:NEAR
    EXTRN md294:NEAR
    EXTRN md308:NEAR
    EXTRN mf4c3:FAR
    EXTRN mf452:FAR
    EXTRN mf252:FAR
    EXTRN mif1:NEAR
    EXTRN mf332:FAR
    EXTRN mf4ad:FAR
    EXTRN mf2f5:FAR
    EXTRN mf1bc:FAR
    EXTRN md2df:NEAR
    EXTRN mf3ff:FAR
    EXTRN mf36e:FAR
    EXTRN mi393:NEAR
    EXTRN mi22f:NEAR
    EXTRN mf382:FAR
    EXTRN md2b8:NEAR
    EXTRN mf52:FAR
    EXTRN mf3c0:FAR
    EXTRN md317:NEAR
    EXTRN mf424:FAR
    EXTRN mfad:FAR
    EXTRN mib5:NEAR
    EXTRN mf34d:FAR
    EXTRN mf480:FAR
    EXTRN md3f4:NEAR
    EXTRN mf407:FAR
    EXTRN midd:NEAR
    EXTRN md312:NEAR
    EXTRN md26b:NEAR
    EXTRN mibd:NEAR
    EXTRN mf42:FAR
    EXTRN mf16d:FAR
    EXTRN md28d:NEAR
    EXTRN md30d:NEAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,24h
    push si
    mov ax,28h
    push ax
    mov cx,323Ch
    push ds
    push cx
    mov cx,0A8h
    push cx
    mov cx,112h
    push cx
    call mf18
    add sp,0Ah
    mov ax,28h
    push ax
    mov ax,3242h
    push ds
    push ax
    mov ax,0B8h
    push ax
    mov ax,112h
    push ax
    call mf31
    add sp,0Ah
    call mf39
    mov ax,0Dh
    push ax
    call mf42
    add sp,2h
    mov ax,0FFFFh
    push ax
    mov cx,0Fh
    push cx
    call mf52
    add sp,4h
    xor ax,ax
    push ax
    call mf5d
    add sp,2h
    push word ptr ds:[6D48h]
    push word ptr ds:[6DDAh]
    call mf6d
    add sp,4h
    mov ax,1h
    mov dx,0F043h
    push dx
    push ax
    call mf7d
    add sp,4h
    mov ax,0FFFFh
    push ax
    call mf89
    add sp,2h
    call mf91
    call mf96
    mov word ptr [bp-4h],0FFFFh
    mov word ptr [bp-6h],0h
    jmp near ptr lbl17Ff
lblA8b:
    mov word ptr [bp-1Ah],0h
    call mfad
    mov word ptr [bp-12h],ax
    cmp ax, offset mib5
    jnz short lblBDf
    db 0E9h, 53h, 03h ; override
lblBDf:
    cmp ax, offset mibd
    jnz short lblC5f
    db 0E9h, 4Bh, 03h ; override
lblC5f:
    cmp ax,13Ch
    jnz short lblCDf
    db 0E9h, 43h, 03h ; override
lblCDf:
    cmp ax, offset micd
    jnz short lblD5f
    db 0E9h, 54h, 03h ; override
lblD5f:
    cmp ax, offset mid5
    jnz short lblDDf
    db 0E9h, 4Ch, 03h ; override
lblDDf:
    cmp ax, offset midd
    jnz short lblE5f
    jmp near ptr lbl166f
lblE5f:
    cmp ax,13Bh
    jz short lbl166f
    cmp ax,148h
    jz short lbl114f
    jg short lbl100f
    sub ax, offset mif1
    jz short lbl10Ef
    sub ax,106h
    jz short lbl114f
    jmp short lbl146f
    nop
    nop
    nop
lbl100f:
    sub ax,14Bh
    jz short lbl11Af
    dec ax
    dec ax
    jz short lbl11Af
    sub ax, offset mi109
    jnz short lbl146f
lbl10Ef:
    inc word ptr [bp-6h]
    jmp short lbl146f
    nop
lbl114f:
    dec word ptr [bp-6h]
    jmp short lbl146f
    nop
lbl11Af:
    cmp word ptr [bp-6h],2h
    jnl short lbl128f
    mov word ptr [bp-6h],4h
    jmp short lbl146f
    nop
lbl128f:
    cmp word ptr [bp-6h],4h
    jnl short lbl136f
    mov word ptr [bp-6h],5h
    jmp short lbl146f
    nop
lbl136f:
    cmp word ptr [bp-6h],5h
    jnl short lbl140f
    xor ax,ax
    jmp short lbl143f
lbl140f:
    mov ax,2h
lbl143f:
    mov word ptr [bp-6h],ax
lbl146f:
    cmp word ptr [bp-6h],0h
    jnl short lbl154f
    mov word ptr [bp-6h],5h
    db 0E9h, 0F3h, 00h ; override
lbl154f:
    cmp word ptr [bp-6h],5h
    jg short lbl15Df
    db 0E9h, 0EAh, 00h ; override
lbl15Df:
    mov word ptr [bp-6h],0h
    db 0E9h, 0E2h, 00h ; override
    nop
lbl166f:
    mov ax,1h
    push ax
    xor ax,ax
    push ax
    call mf16d
    add sp,4h
lbl175b:
    call mf175
    mov word ptr [bp-4h],0FFFFh
lbl17Fb:
lbl17Ff:
    call mf17f
    or ax,ax
    jz short lbl18Bf
    jmp near ptr lblA8b
lbl18Bf:
    mov word ptr [bp-1Ah],ax
    lea ax,word ptr [bp-0Eh]
    push ss
    push ax
    lea ax,word ptr [bp-0Ch]
    push ss
    push ax
    call mf198
    add sp,8h
    mov word ptr [bp-10h],ax
    or ax,ax
    jz short lbl1E8f
    lea ax,word ptr [bp-18h]
    push ss
    push ax
    lea ax,word ptr [bp-16h]
    push ss
    push ax
    lea ax,word ptr [bp-14h]
    push ss
    push ax
    push word ptr [bp-0Eh]
    push word ptr [bp-0Ch]
    call mf1bc
    add sp,10h
    or ax,ax
    jz short lbl1E8f
    cmp word ptr [bp-18h],5h
    jnz short lbl1E8f
    push word ptr [bp-16h]
    xor ax,ax
    push ax
    call mf1d4
    add sp,4h
    cmp word ptr [bp-16h],1h
    jz short lbl1E5f
    db 0E9h, 3Ah, 02h ; override
lbl1E5f:
    jmp short lbl175b
    nop
lbl1E8f:
    mov word ptr [bp-2h],0h
    mov word ptr [bp-20h],0h
lbl1F2b:
    mov bx,word ptr [bp-20h]
    mov es, ds:[5AE8h]
    mov ax,word ptr es:[bx]
    add ax, offset mi1fc
    cmp ax,word ptr [bp-0Ch]
    jnl short lbl228f
    mov ax,word ptr es:[bx+4h]
    sub ax, offset mi208
    cmp ax,word ptr [bp-0Ch]
    jng short lbl228f
    mov ax,word ptr es:[bx+2h]
    add ax, offset mi214
    cmp ax,word ptr [bp-0Eh]
    jnl short lbl228f
    mov ax,word ptr es:[bx+6h]
    sub ax, offset mi220
    cmp ax,word ptr [bp-0Eh]
    db 7Fh, 10h ; override
lbl228f:
    inc word ptr [bp-2h]
    add word ptr [bp-20h],8h
    cmp word ptr [bp-20h], offset mi22f
    jc short lbl1F2b
    jmp short lbl23Ef
lbl238f:
    mov ax,word ptr [bp-2h]
    mov word ptr [bp-6h],ax
lbl23Ef:
    cmp word ptr [bp-10h],0h
    jz short lbl247f
    db 0E9h, 0DDh, 01h ; override
lbl247f:
    mov ax,word ptr [bp-4h]
    cmp word ptr [bp-6h],ax
    jnz short lbl252f
    jmp near ptr lbl17Fb
lbl252f:
    call mf252
    cmp word ptr [bp-4h],0h
    jnl short lbl260f
    db 0E9h, 91h, 00h ; override
lbl260f:
    mov es, ds:[5AE8h]
    mov cl,3h
    mov bx,word ptr [bp-4h]
    shl bx,cl
    push word ptr es:[bx+md26b]
    push word ptr es:[bx+md270]
    push word ptr es:[bx+md275]
    push word ptr es:[bx+md27a]
    mov si,bx
    call mf281
    add sp,8h
    mov es, ds:[5AE8h]
    mov ax,word ptr es:[si+md28d]
    dec ax
    push ax
    push word ptr es:[si+md294]
    mov ax,word ptr es:[si+md299]
    inc ax
    push ax
    push word ptr es:[si+md2a0]
    call mf2a5
    add sp,8h
    mov es, ds:[5AE8h]
    mov ax,word ptr es:[si+md2b1]
    dec ax
    push ax
    push word ptr es:[si+md2b8]
    mov ax,word ptr es:[si+md2bd]
    inc ax
    push ax
    push word ptr es:[si+md2c4]
    call mf2c9
    add sp,8h
    mov es, ds:[5AE8h]
    push word ptr es:[si+md2d5]
    push word ptr es:[si+md2da]
    push word ptr es:[si+md2df]
    push word ptr es:[si+md2e4]
    call mf2e9
    add sp,8h
lbl2F1f:
    push word ptr ds:[320Ah]
    call mf2f5
    add sp,2h
    mov es, ds:[5AE8h]
    mov cl,3h
    mov bx,word ptr [bp-6h]
    shl bx,cl
    push word ptr es:[bx+md308]
    push word ptr es:[bx+md30d]
    push word ptr es:[bx+md312]
    push word ptr es:[bx+md317]
    mov ax,1h
    push ax
    call mf320
    add sp,0Ah
    mov ax,word ptr [bp-6h]
    mov word ptr [bp-4h],ax
    mov cx,0Dh
    push cx
    call mf332
    add sp,2h
    mov ax,0FFFFh
    push ax
    mov ax,0Fh
    push ax
    call mf342
    add sp,4h
    xor ax,ax
    push ax
    call mf34d
    add sp,2h
    mov ax,word ptr ds:[69F8h]
    add ax,ax
    add ax,word ptr ds:[6D48h]
    push ax
    mov ax,13Fh
    push ax
    mov ax,word ptr ds:[6D48h]
    add ax,word ptr ds:[69F8h]
    push ax
    xor ax,ax
    push ax
    call mf36e
    add sp,8h
    mov ax,word ptr ds:[6D48h]
    add ax,word ptr ds:[69F8h]
    push ax
    push word ptr ds:[6DDAh]
    call mf382
    add sp,4h
    mov ax,word ptr [bp-6h]
    or ax,ax
    jl short lbl3BAf
    jo short lbl3BAf
    sub ax, offset mi393
    jng short lbl3A0f
    dec ax
    jz short lbl3A8f
    dec ax
    jz short lbl3B0f
    jmp short lbl3BAf
lbl3A0f:
    mov word ptr [bp-1Eh],2h
    jmp short lbl3B5f
    nop
lbl3A8f:
    mov word ptr [bp-1Eh],3h
    jmp short lbl3B5f
    nop
lbl3B0f:
    mov word ptr [bp-1Eh],4h
lbl3B5f:
    mov word ptr [bp-1Ch],0F043h
lbl3BAf:
    push word ptr [bp-1Ch]
    push word ptr [bp-1Eh]
    call mf3c0
    add sp,4h
    mov ax,0FFFFh
    push ax
    call mf3cc
    add sp,2h
    mov es, ds:[5AE8h]
    mov cl,3h
    mov bx,word ptr [bp-6h]
    shl bx,cl
    mov ax,word ptr es:[bx+md3df]
    add ax,word ptr es:[bx+md3e4]
    cwd
    sub ax,dx
    sar ax,1
    push ax
    mov ax,word ptr es:[bx+md3ef]
    add ax,word ptr es:[bx+md3f4]
    cwd
    sub ax,dx
    sar ax,1
    push ax
    call mf3ff
    add sp,4h
    call mf407
    jmp near ptr lbl17Fb
    nop
lbl410f:
    mov ax,2h
    push ax
    xor ax,ax
    push ax
    call mf417
    add sp,4h
lbl41Ff:
    xor ax,ax
    jmp near ptr lbl540f
lbl424f:
    call mf424
lbl429f:
    cmp word ptr [bp-6h],0h
    jl short lbl44Af
    cmp word ptr [bp-6h],6h
    jnl short lbl44Af
    mov bx,word ptr [bp-6h]
    add bx,bx
    mov ax,word ptr [bx+3248h]
    mov word ptr [bp-8h],ax
    mov ax,word ptr [bx+3254h]
    mov word ptr [bp-0Ah],ax
    jmp short lbl452f
lbl44Af:
    xor ax,ax
    mov word ptr [bp-0Ah],ax
    mov word ptr [bp-8h],ax
lbl452f:
    call mf452
    cmp word ptr [bp-0Ah],6h
    jng short lbl479f
    mov es, ds:[5AEAh]
    sub byte ptr es:[46FDh],5h
    add byte ptr es:[46FEh],6h
    sub byte ptr es:[4706h],5h
    add byte ptr es:[4707h],6h
lbl479f:
    mov ax,1h
    push ax
    xor ax,ax
    push ax
    call mf480
    add sp,4h
    mov ax,0C7h
    push ax
    mov ax,13Fh
    push ax
    xor ax,ax
    push ax
    push ax
    call mf494
    add sp,8h
    mov ax,word ptr [bp-8h]
    mov word ptr ds:[6DDCh],ax
    mov ax,word ptr [bp-0Ah]
    mov word ptr ds:[6DDEh],ax
    call mf4a8
    call mf4ad
    mov ax,28h
    push ax
    mov cx,323Ch
    push ds
    push cx
    mov cx,0A8h
    push cx
    mov cx,112h
    push cx
    call mf4c3
    add sp,0Ah
    mov ax,28h
    push ax
    mov ax,3242h
    push ds
    push ax
    mov ax,0B8h
    push ax
    mov ax,112h
    push ax
    call mf4dc
    add sp,0Ah
    mov ax,0A7h
    sub dx,dx
    div word ptr ds:[320Eh]
    mov word ptr [bp-0Eh],ax
    cmp ax,word ptr ds:[3212h]
    jnl short lbl53Df
    mov ax,111h
    sub dx,dx
    div word ptr ds:[320Ch]
    mov word ptr [bp-22h],ax
lbl502b:
    mov ax,word ptr [bp-22h]
    mov word ptr [bp-0Ch],ax
    cmp ax,word ptr ds:[3210h]
    jnl short lbl532f
    mov ax,17h
    imul word ptr [bp-0Eh]
    mov word ptr [bp-24h],ax
    mov es, ds:[5AE6h]
lbl51Bb:
    mov bx,word ptr [bp-24h]
    add bx,word ptr [bp-0Ch]
    or byte ptr es:[bx+4750h],40h
    mov ax,word ptr ds:[3210h]
    inc word ptr [bp-0Ch]
    cmp word ptr [bp-0Ch],ax
    jl short lbl51Bb
lbl532f:
    mov ax,word ptr ds:[3212h]
    inc word ptr [bp-0Eh]
    cmp word ptr [bp-0Eh],ax
    jl short lbl502b
lbl53Df:
    mov ax,1h
lbl540f:
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
