_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf9:FAR
    EXTRN mf15:FAR
    EXTRN mf17:FAR
    EXTRN mf20:FAR
    EXTRN mf25:FAR
    EXTRN mf30:FAR
    EXTRN mf34:FAR
    EXTRN mf43:FAR
    EXTRN mf47:FAR
    EXTRN mf53:FAR
    EXTRN mf62:FAR
    EXTRN mf66:FAR
    EXTRN mf74:FAR
    EXTRN mf84:FAR
    EXTRN mf89:FAR
    EXTRN mf93:FAR
    EXTRN mf103:FAR
    EXTRN mf115:FAR
    EXTRN mf119:FAR
    EXTRN mf131:FAR
    EXTRN mf174:FAR
    EXTRN mf175:FAR
    EXTRN mf178:FAR
    EXTRN mf189:FAR
    EXTRN mf200:FAR
    EXTRN mf211:FAR
    EXTRN mf222:FAR
    EXTRN mf233:FAR
    EXTRN mf355:FAR
    EXTRN mf375:FAR
    EXTRN mf385:FAR
    EXTRN mf387:FAR
    EXTRN mf393:FAR
    EXTRN mf398:FAR
    EXTRN mi400:NEAR
    EXTRN mi406:NEAR
    EXTRN mi412:NEAR
    EXTRN mi418:NEAR
    EXTRN mi424:NEAR
    EXTRN mi427:NEAR
    EXTRN mi433:NEAR
    EXTRN mi439:NEAR
    EXTRN mi442:NEAR
    EXTRN mi445:NEAR
    EXTRN mi520:NEAR
    EXTRN mi522:NEAR
    EXTRN mf532:FAR
    EXTRN mf537:FAR
    EXTRN md556:NEAR
    EXTRN mf570:FAR
    EXTRN mf575:FAR
    EXTRN md583:NEAR
    EXTRN md584:NEAR
    EXTRN mf585:FAR
    EXTRN md618:NEAR
    EXTRN mf630:FAR
    EXTRN mf632:FAR
    EXTRN mf639:FAR
    EXTRN mf641:FAR
    EXTRN mf652:FAR
    EXTRN mf682:FAR
    EXTRN mf694:FAR
    EXTRN mf703:FAR
    EXTRN mf708:FAR
    EXTRN md716:NEAR
    EXTRN md717:NEAR
    EXTRN mf718:FAR
    EXTRN mf725:FAR
    EXTRN mf730:FAR
    EXTRN mf735:FAR
    EXTRN mf748:FAR
    EXTRN mf753:FAR
    EXTRN mf763:FAR
    EXTRN mf812:FAR
    EXTRN mf836:FAR
    EXTRN mf845:FAR
    EXTRN mf869:FAR
    EXTRN mf873:FAR
    EXTRN md884:NEAR
    EXTRN mf891:FAR
    EXTRN md898:NEAR
    EXTRN md899:NEAR
    EXTRN mf904:FAR
    EXTRN mf943:FAR
    EXTRN mf976:FAR
    EXTRN mf982:FAR
    EXTRN mf986:FAR
    EXTRN mf1005:FAR
    EXTRN mf1031:FAR
    EXTRN mf1091:FAR
    EXTRN mf1116:FAR
    EXTRN mf1127:FAR
    EXTRN mf1129:FAR
    EXTRN mf1132:FAR
    EXTRN mf1134:FAR
    EXTRN mf1146:FAR
    EXTRN mf1154:FAR
    EXTRN mf1161:FAR
    EXTRN mf1163:FAR
    EXTRN mf1166:FAR
    EXTRN mf1170:FAR
    EXTRN mf1172:FAR
    EXTRN mf1175:FAR
    EXTRN mf1191:FAR
    EXTRN mf1191:FAR
    EXTRN mf1191:FAR
    EXTRN mf1191:FAR
    EXTRN mf1191:FAR
    EXTRN mf1191:FAR
    EXTRN mf1191:FAR
    EXTRN mf1191:FAR
    EXTRN mf1191:FAR
    EXTRN mf1191:FAR
    EXTRN mf1191:FAR
    EXTRN mf1191:FAR
    EXTRN mf1191:FAR
    EXTRN mf1191:FAR
    EXTRN mf1191:FAR
    EXTRN mf1191:FAR
    EXTRN mf1191:FAR
    EXTRN mf1191:FAR
    EXTRN mf1191:FAR
    EXTRN mf1191:FAR
    EXTRN mf1191:FAR
    EXTRN mf1191:FAR
    EXTRN mf1191:FAR
    EXTRN mf1191:FAR
    EXTRN mf1191:FAR
    EXTRN mf1191:FAR
    EXTRN mf1191:FAR
    EXTRN mf1191:FAR
    EXTRN mf1191:FAR
    EXTRN mf1191:FAR
    EXTRN mf1191:FAR
    EXTRN mf1191:FAR
    EXTRN mf1191:FAR
    EXTRN mf1191:FAR
    EXTRN mf1191:FAR
    EXTRN mf1191:FAR
    EXTRN mf1191:FAR
    EXTRN mf1191:FAR
    EXTRN mf1191:FAR
    EXTRN mf1191:FAR
    EXTRN mf1191:FAR
    EXTRN mf1191:FAR
    EXTRN mf1191:FAR
    EXTRN mf1191:FAR
    EXTRN mf1191:FAR
    EXTRN mf1191:FAR
    EXTRN mf1191:FAR
    EXTRN mf1191:FAR
    EXTRN mf1191:FAR
    EXTRN mf1191:FAR
    EXTRN mf1191:FAR
    EXTRN mf1191:FAR
    EXTRN mf1191:FAR
    EXTRN mf1191:FAR
    EXTRN mf1191:FAR
    EXTRN mf1191:FAR
    EXTRN mf1191:FAR
    EXTRN mf1191:FAR
    EXTRN mf1191:FAR
    EXTRN mf1191:FAR
    EXTRN mf1191:FAR
    EXTRN mf1191:FAR
    EXTRN mf1191:FAR
    EXTRN mf1191:FAR
    EXTRN mf1191:FAR
    EXTRN mf1191:FAR
    EXTRN mf1191:FAR
    EXTRN mf1191:FAR
    EXTRN mf1191:FAR
    EXTRN mf1191:FAR
    EXTRN mf1191:FAR
    EXTRN mf1191:FAR
    EXTRN mf1191:FAR
    EXTRN mf1191:FAR
    EXTRN mf1191:FAR
    EXTRN mf1191:FAR
    EXTRN mf1191:FAR
    EXTRN mf1191:FAR
    EXTRN mf1191:FAR
    EXTRN mf1191:FAR
    EXTRN mf1191:FAR
    EXTRN mf1191:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,60h
    push di
    push si
    mov word ptr [bp-8h],0h
    mov ax,18h
    push ax
    push word ptr ds:[256h]
    call mf9
    add sp,4h
    mov ax,20h
    mov cx,2199h
    push cx
    push ax
    call mf15
    add sp,4h
    call mf17
    mov ax,1h
    push ax
    call mf20
    add sp,2h
    xor ax,ax
    push ax
    push ax
    call mf25
    add sp,4h
    lea ax,word ptr [bp-36h]
    push ss
    push ax
    call mf30
    add sp,4h
    mov ax,20h
    push ax
    call mf34
    add sp,2h
    mov ax,0C7h
    push ax
    mov cx,13Fh
    push cx
    xor dx,dx
    push dx
    push dx
    call mf43
    add sp,8h
    mov ax,0Dh
    push ax
    call mf47
    add sp,2h
    mov ax,17h
    push ax
    mov cx,0Fh
    push cx
    call mf53
    add sp,4h
    mov ax,0C7h
    push ax
    mov ax,13Fh
    push ax
    xor ax,ax
    push ax
    push ax
    call mf62
    add sp,8h
    xor ax,ax
    push ax
    call mf66
    add sp,2h
    mov ax,22h
    sub ax,word ptr ds:[69F8h]
    push ax
    mov ax,3292h
    push ds
    push ax
    call mf74
    add sp,4h
    cwd
    sub ax,dx
    sar ax,1
    sub ax,122h
    neg ax
    push ax
    xor ax,ax
    push ax
    call mf84
    add sp,6h
    mov ax,3292h
    push ds
    push ax
    call mf89
    add sp,4h
    mov ax,0FFFFh
    push ax
    call mf93
    add sp,2h
    mov ax,34h
    push ax
    mov cx,13Ah
    push cx
    mov dx,24h
    push dx
    mov bx,10Ah
    push bx
    call mf103
    add sp,8h
    mov ax,18h
    push ax
    mov ax,34h
    push ax
    mov ax,13Ah
    push ax
    mov ax,24h
    push ax
    mov ax,10Ah
    push ax
    call mf115
    add sp,0Ah
    mov ax,17h
    push ax
    call mf119
    add sp,2h
    mov ax,33h
    push ax
    mov ax,139h
    push ax
    mov ax,25h
    push ax
    mov ax,10Bh
    push ax
    mov ax,2h
    push ax
    call mf131
    add sp,0Ah
    mov bx,word ptr ds:[5AECh]
    mov ax,bx
    add bx,bx
    add bx,ax
    mov es, ds:[5B06h]
    lea di,word ptr [bx+6A24h]
    mov si,3268h
    movsw
    movsb
    mov bx,word ptr ds:[5AEEh]
    mov ax,bx
    add bx,bx
    add bx,ax
    lea di,word ptr [bx+6A24h]
    mov si,326Ch
    movsw
    movsb
    mov bx,word ptr ds:[5AF0h]
    mov ax,bx
    add bx,bx
    add bx,ax
    lea di,word ptr [bx+6A24h]
    mov si,3270h
    movsw
    movsb
    mov bx,word ptr ds:[5AF2h]
    mov ax,bx
    add bx,bx
    add bx,ax
    lea di,word ptr [bx+6A24h]
    mov si,3274h
    movsw
    movsb
    mov bx,word ptr ds:[5AF4h]
    mov ax,bx
    add bx,bx
    add bx,ax
    lea di,word ptr [bx+6A24h]
    mov si,3278h
    movsw
    movsb
    call mf174
    call mf175
    mov ax,1h
    push ax
    call mf178
    add sp,2h
    mov ax,30h
    push ax
    mov cx,3299h
    push ds
    push cx
    mov cx,78h
    push cx
    mov cx,10Ah
    push cx
    call mf189
    add sp,0Ah
    mov ax,30h
    push ax
    mov cx,329Eh
    push ds
    push cx
    mov cx,88h
    push cx
    mov cx,10Ah
    push cx
    call mf200
    add sp,0Ah
    mov ax,30h
    push ax
    mov cx,32A3h
    push ds
    push cx
    mov cx,98h
    push cx
    mov cx,10Ah
    push cx
    call mf211
    add sp,0Ah
    mov ax,30h
    push ax
    mov cx,32A8h
    push ds
    push cx
    mov cx,0A8h
    push cx
    mov cx,10Ah
    push cx
    call mf222
    add sp,0Ah
    mov ax,30h
    push ax
    mov ax,32ADh
    push ds
    push ax
    mov ax,0B8h
    push ax
    mov ax,10Ah
    push ax
    call mf233
    add sp,0Ah
lbl248b:
    cmp word ptr [bp+6h],0h
    jz short lbl284f
    mov word ptr [bp-4h],0h
lbl253b:
    mov bx,word ptr [bp-8h]
    cmp byte ptr [bx+327Ch],0h
    jz short lbl274f
    inc word ptr [bp-8h]
    cmp word ptr [bp-8h],0Bh
    jc short lbl26Bf
    mov word ptr [bp-8h],0h
lbl26Bf:
    inc word ptr [bp-4h]
    cmp word ptr [bp-4h],0Bh
    jc short lbl253b
lbl274f:
    cmp word ptr [bp-4h],0Bh
    jc short lbl284f
    mov word ptr [bp+6h],0h
    mov word ptr [bp-8h],0h
lbl284f:
    mov es, ds:[5B04h]
    mov cl,3h
    mov bx,word ptr [bp-8h]
    shl bx,cl
    sub ah,ah
    mov al,byte ptr es:[bx+278h]
    mov word ptr ds:[5E0Ch],ax
    mov al,byte ptr es:[bx+279h]
    mov word ptr ds:[5E0Eh],ax
    mov ax,word ptr es:[bx+27Ah]
    mov word ptr ds:[5E0Ah],ax
    mov dx,word ptr es:[bx+27Ch]
    mov si,word ptr es:[bx+27Eh]
    mov cx,ax
    add cx,ax
    add cx,cx
    push ds
    push si
    mov di,0h
    mov si,dx
    pop ds
    shr cx,1
    rep movsw
    adc cx,cx
    rep movsb
    pop ds
    xor ax,ax
    mov word ptr [bp-1Eh],ax
    mov word ptr [bp-1Ch],ax
    mov word ptr [bp-4h],ax
    cmp word ptr ds:[5E0Ah],ax
    jz short lbl325f
    mov word ptr [bp-54h],3h
    mov ax,word ptr ds:[5E0Ah]
    mov word ptr [bp-56h],ax
lbl2E6b:
    mov bx,word ptr [bp-54h]
    mov es, ds:[5B04h]
    mov al,byte ptr es:[bx]
    mov byte ptr [bp-60h],al
    mov cl,2h
    cbw
    idiv cl
    mov al,ah
    cbw
    dec bx
    mov cx,ax
    mov al,byte ptr es:[bx]
    cbw
    sub ax,cx
    mov word ptr [bp-5Eh],ax
    cmp ax,word ptr [bp-1Ch]
    jng short lbl30Ff
    mov word ptr [bp-1Ch],ax
lbl30Ff:
    mov al,byte ptr [bp-60h]
    cbw
    cmp ax,word ptr [bp-1Eh]
    jng short lbl31Cf
    cbw
    mov word ptr [bp-1Eh],ax
lbl31Cf:
    add word ptr [bp-54h],4h
    dec word ptr [bp-56h]
    jnz short lbl2E6b
lbl325f:
    mov ax,word ptr ds:[5B00h]
    sub ax,word ptr [bp-1Ch]
    dec ax
    cwd
    sub ax,dx
    sar ax,1
    mov word ptr [bp-1Ch],ax
    mov ax,word ptr ds:[5B02h]
    sub ax,word ptr [bp-1Eh]
    cwd
    and dx,3h
    add ax,dx
    mov cx,2h
    sar ax,cl
    add ax,ax
    mov word ptr [bp-1Eh],ax
    mov word ptr [bp-4h],0h
    cmp word ptr ds:[5E0Ah],0h
    jz short lbl37Df
    mov word ptr [bp-58h],2h
    mov ax,word ptr ds:[5E0Ah]
    mov word ptr [bp-5Ah],ax
lbl361b:
    mov al,byte ptr [bp-1Ch]
    mov bx,word ptr [bp-58h]
    add byte ptr es:[bx],al
    mov bx,word ptr [bp-58h]
    mov al,byte ptr [bp-1Eh]
    add byte ptr es:[bx+1h],al
    add word ptr [bp-58h],4h
    dec word ptr [bp-5Ah]
    jnz short lbl361b
lbl37Df:
    mov word ptr [bp-4h],0h
    cmp word ptr ds:[5E0Ah],0h
    jz short lbl3B6f
    mov word ptr [bp-5Ch],0h
lbl38Eb:
    xor ax,ax
    push ax
    mov es, ds:[5B04h]
    mov bx,word ptr [bp-5Ch]
    push word ptr es:[bx+2h]
    push word ptr es:[bx]
    call mf355
    add sp,6h
    add word ptr [bp-5Ch],4h
    mov ax,word ptr ds:[5E0Ah]
    inc word ptr [bp-4h]
    cmp word ptr [bp-4h],ax
    jc short lbl38Eb
lbl3B6f:
    push word ptr ds:[5E0Eh]
    cmp word ptr ds:[5E0Ch],1h
    jnz short lbl3C6f
    mov ax,32B2h
    jmp short lbl3C9f
lbl3C6f:
    mov ax,32B3h
lbl3C9f:
    push ds
    push ax
    push word ptr ds:[5E0Ch]
    mov ax,1h
    mov dx,0F041h
    push dx
    push ax
    call mf375
    add sp,0Ch
    mov word ptr ds:[5E10h],0h
    mov ax,4h
    push ax
    xor ax,ax
    mov word ptr [bp-0Eh],ax
    mov word ptr [bp-0Ch],ax
    mov word ptr [bp-0Ah],ax
    push ax
    call mf385
    add sp,4h
    call mf387
    mov ax,word ptr ds:[5E0Ah]
    mov word ptr [bp-6h],ax
    cmp word ptr ds:[5E0Ch],0h
    jnz short lbl412f
    jmp near ptr lblB86f
lbl412b:
lbl412f:
    call mf393
    or ax,ax
    jnz short lbl41Ef
    jmp near ptr lbl6C6f
lbl41Ef:
    mov word ptr [bp-10h],0h
    call mf398
    mov word ptr [bp-12h],ax
    cmp ax, offset mi400
    jnz short lbl433f
    jmp near ptr lbl6AEf
lbl433f:
    cmp ax,13Bh
    jnz short lbl43Bf
    jmp near ptr lbl6AEf
lbl43Bf:
    cmp ax, offset mi406
    jnz short lbl443f
    jmp near ptr lblAD2f
lbl443f:
    cmp ax,13Ch
    jnz short lbl44Bf
    jmp near ptr lblAD2f
lbl44Bf:
    cmp ax, offset mi412
    jnz short lbl453f
    jmp near ptr lblA86f
lbl453f:
    cmp ax,13Dh
    jnz short lbl45Bf
    jmp near ptr lblA86f
lbl45Bf:
    cmp ax, offset mi418
    jnz short lbl463f
    jmp near ptr lbl696f
lbl463f:
    cmp ax,13Eh
    jnz short lbl46Bf
    jmp near ptr lbl696f
lbl46Bf:
    cmp ax, offset mi424
    jnz short lbl473f
    jmp near ptr lblC40f
lbl473f:
    cmp ax, offset mi427
    jnz short lbl47Bf
    jmp near ptr lblC40f
lbl47Bf:
    cmp ax,13Fh
    jnz short lbl483f
    jmp near ptr lblC40f
lbl483f:
    cmp ax, offset mi433
    jnz short lbl48Bf
    jmp near ptr lbl5DEf
lbl48Bf:
    cmp ax,10Fh
    jnz short lbl493f
    jmp near ptr lbl5DEf
lbl493f:
    cmp ax, offset mi439
    jnz short lbl49Bf
    jmp near ptr lbl5DEf
lbl49Bf:
    cmp ax, offset mi442
    jnz short lbl4A3f
    jmp near ptr lbl5DEf
lbl4A3f:
    cmp ax, offset mi445
    jnz short lbl4ABf
    jmp near ptr lbl5DEf
lbl4ABf:
    cmp ax,14Bh
    jnz short lbl4CEf
    cmp word ptr [bp-0Ah],0h
    jnz short lbl4B9f
    jmp near ptr lbl7C5f
lbl4B9f:
    cmp byte ptr [bp-20h],0h
    jg short lbl4C2f
    jmp near ptr lbl7C5f
lbl4C2b:
lbl4C2f:
    dec byte ptr [bp-20h]
lbl4C5b:
    mov word ptr [bp-0Eh],1h
    jmp near ptr lbl7C5f
    nop
lbl4CEf:
    cmp ax,14Dh
    jnz short lbl4FEf
    cmp word ptr [bp-0Ah],0h
    jnz short lbl4DCf
    jmp near ptr lbl7C5f
lbl4DCf:
    mov al,byte ptr [bp-1Fh]
    mov cl,2h
    cbw
    idiv cl
    mov al,ah
    cbw
    add ax,word ptr ds:[5B00h]
    dec ax
    mov cx,ax
    mov al,byte ptr [bp-20h]
    cbw
    cmp cx,ax
    jg short lbl4F9f
    jmp near ptr lbl7C5f
lbl4F9f:
    inc byte ptr [bp-20h]
    jmp short lbl4C5b
lbl4FEf:
    cmp ax,148h
    jnz short lbl51Af
    cmp word ptr [bp-0Ah],0h
    jnz short lbl50Cf
    jmp near ptr lbl7C5f
lbl50Cf:
    cmp byte ptr [bp-1Fh],0h
    jg short lbl515f
    jmp near ptr lbl7C5f
lbl515f:
    dec byte ptr [bp-1Fh]
    jmp short lbl53Bf
lbl51Af:
    cmp ax,150h
    jnz short lbl55Cf
    cmp word ptr [bp-0Ah],0h
    jnz short lbl528f
    jmp near ptr lbl7C5f
lbl528f:
    mov al,byte ptr [bp-1Fh]
    cbw
    mov cx,word ptr ds:[5B02h]
    dec cx
    cmp cx,ax
    jg short lbl538f
    jmp near ptr lbl7C5f
lbl538f:
    inc byte ptr [bp-1Fh]
lbl53Bf:
    mov al,byte ptr [bp-1Fh]
    mov cl,2h
    cbw
    idiv cl
    mov al,ah
    cbw
    add ax,word ptr ds:[5B00h]
    dec ax
    mov cx,ax
    mov al,byte ptr [bp-20h]
    cbw
    cmp cx,ax
    jng short lbl558f
    jmp near ptr lbl4C5b
lbl558f:
    jmp near ptr lbl4C2b
    nop
lbl55Cf:
    cmp ax, offset mi520
    jz short lbl569f
    cmp ax, offset mi522
    jz short lbl569f
    jmp near ptr lbl7C5f
lbl569f:
    cmp word ptr [bp-0Ah],0h
    jz short lbl59Ef
    cmp byte ptr [bp-36h],0h
    jz short lbl582f
    lea ax,word ptr [bp-36h]
    push ss
    push ax
    call mf532
    add sp,4h
lbl582f:
    push word ptr [bp-6h]
    push word ptr [bp-20h]
    push word ptr [bp-22h]
    call mf537
    add sp,6h
    xor ax,ax
    mov word ptr [bp-0Ch],ax
    mov word ptr [bp-0Ah],ax
    jmp near ptr lbl7C5f
lbl59Ef:
    mov word ptr [bp-4h],0h
    cmp word ptr ds:[5E0Ah],0h
    jnz short lbl5ADf
    jmp near ptr lbl4C5b
lbl5ADb:
lbl5ADf:
    mov ax,word ptr ds:[5E0Ah]
    inc word ptr [bp-6h]
    cmp word ptr [bp-6h],ax
    jc short lbl5BDf
    mov word ptr [bp-6h],0h
lbl5BDf:
    mov es, ds:[5B04h]
    mov bx,word ptr [bp-6h]
    add bx,bx
    add bx,bx
    cmp byte ptr es:[bx+md556],0h
    jnz short lbl5D3f
    jmp near ptr lbl4C5b
lbl5D3f:
    inc word ptr [bp-4h]
    cmp word ptr [bp-4h],ax
    jc short lbl5ADb
    jmp near ptr lbl4C5b
lbl5DEf:
    cmp word ptr [bp-0Ah],0h
    jz short lbl62Cf
    cmp byte ptr [bp-36h],0h
    jz short lbl604f
    lea ax,word ptr [bp-36h]
    push ss
    push ax
    call mf570
    add sp,4h
    lea ax,word ptr [bp-36h]
    push ss
    push ax
    call mf575
    add sp,4h
lbl604f:
    xor ax,ax
    push ax
    mov es, ds:[5B04h]
    mov bx,word ptr [bp-6h]
    add bx,bx
    add bx,bx
    push word ptr es:[bx+md583]
    push word ptr es:[bx+md584]
    call mf585
    add sp,6h
    xor ax,ax
    mov word ptr [bp-0Ch],ax
    mov word ptr [bp-0Ah],ax
lbl62Cf:
    mov word ptr [bp-4h],0h
    cmp word ptr ds:[5E0Ah],0h
    jnz short lbl63Bf
    jmp near ptr lbl4C5b
lbl63Bb:
lbl63Bf:
    cmp word ptr [bp-12h],9h
    jz short lbl662f
    cmp word ptr [bp-12h],2Bh
    jz short lbl662f
    cmp word ptr [bp-12h],3Dh
    jz short lbl662f
    cmp word ptr [bp-6h],0h
    jnz short lbl65Cf
    mov ax,word ptr ds:[5E0Ah]
    dec ax
    mov word ptr [bp-6h],ax
    jmp short lbl672f
lbl65Cf:
    dec word ptr [bp-6h]
    jmp short lbl672f
    nop
lbl662f:
    mov ax,word ptr ds:[5E0Ah]
    inc word ptr [bp-6h]
    cmp word ptr [bp-6h],ax
    jc short lbl672f
    mov word ptr [bp-6h],0h
lbl672f:
    mov es, ds:[5B04h]
    mov bx,word ptr [bp-6h]
    add bx,bx
    add bx,bx
    cmp byte ptr es:[bx+md618],0h
    jnz short lbl688f
    jmp near ptr lbl4C5b
lbl688f:
    mov ax,word ptr ds:[5E0Ah]
    inc word ptr [bp-4h]
    cmp word ptr [bp-4h],ax
    jc short lbl63Bb
    jmp near ptr lbl4C5b
lbl696f:
    mov ax,4h
    push ax
    xor ax,ax
    push ax
    call mf630
    add sp,4h
lbl6A5b:
    call mf632
    jmp near ptr lbl7C5f
    nop
lbl6AEf:
    mov ax,1h
    push ax
    xor ax,ax
    push ax
    call mf639
    add sp,4h
lbl6BDb:
    call mf641
    jmp near ptr lbl7C5f
    nop
lbl6C6f:
    mov ax,word ptr [bp-16h]
    mov word ptr [bp-14h],ax
    lea ax,word ptr [bp-1Ah]
    push ss
    push ax
    lea ax,word ptr [bp-18h]
    push ss
    push ax
    call mf652
    add sp,8h
    mov word ptr [bp-16h],ax
    mov word ptr [bp-10h],1h
    cmp word ptr [bp-0Ah],0h
    jnz short lbl6EFf
    jmp near ptr lbl8AEf
lbl6EFf:
    mov ax,word ptr [bp-14h]
    cmp word ptr [bp-16h],ax
    jnz short lbl6FAf
    jmp near ptr lbl7FAf
lbl6FAf:
    test word ptr [bp-16h],ax
    jz short lbl702f
    jmp near ptr lbl7FAf
lbl702f:
    cmp word ptr [bp-16h],0h
    jz short lbl70Ef
    cmp word ptr [bp-0Ch],0h
    jz short lbl720f
lbl70Ef:
    cmp word ptr [bp-16h],0h
    jz short lbl717f
    jmp near ptr lbl7C5f
lbl717f:
    cmp word ptr [bp-0Ch],0h
    jnz short lbl720f
    jmp near ptr lbl7C5f
lbl720f:
    mov al,byte ptr [bp-1Fh]
    cbw
    push ax
    mov al,byte ptr [bp-20h]
    cbw
    push ax
    call mf682
    add sp,4h
    mov word ptr [bp-4h],ax
    or ax,ax
    jz short lbl794f
    sub ax,word ptr [bp-6h]
    dec ax
    jz short lbl794f
    mov ax,2h
    mov dx,0F041h
    push dx
    push ax
    call mf694
    add sp,4h
    cmp word ptr [bp-0Ch],0h
    jz short lbl7C0f
    cmp byte ptr [bp-36h],0h
    jz short lbl775f
    lea ax,word ptr [bp-36h]
    push ss
    push ax
    call mf703
    add sp,4h
    lea ax,word ptr [bp-36h]
    push ss
    push ax
    call mf708
    add sp,4h
lbl775f:
    xor ax,ax
    push ax
    mov es, ds:[5B04h]
    mov bx,word ptr [bp-6h]
    add bx,bx
    add bx,bx
    push word ptr es:[bx+md716]
    push word ptr es:[bx+md717]
    call mf718
    jmp short lbl7B5f
lbl794f:
    cmp byte ptr [bp-36h],0h
    jz short lbl7A7f
    lea ax,word ptr [bp-36h]
    push ss
    push ax
    call mf725
    add sp,4h
lbl7A7f:
    push word ptr [bp-6h]
    push word ptr [bp-20h]
    push word ptr [bp-22h]
    call mf730
lbl7B5f:
    add sp,6h
    xor ax,ax
    mov word ptr [bp-0Ch],ax
    mov word ptr [bp-0Ah],ax
lbl7C0b:
lbl7C0f:
    call mf735
lbl7C5b:
lbl7C5f:
    cmp word ptr [bp-0Eh],0h
    jnz short lbl7CEf
    jmp near ptr lblA78f
lbl7CEf:
    cmp word ptr [bp-0Ah],0h
    jnz short lbl7D7f
    jmp near ptr lbl96Ef
lbl7D7f:
    cmp byte ptr [bp-36h],0h
    jnz short lbl7E0f
    jmp near ptr lbl993f
lbl7E0f:
    lea ax,word ptr [bp-36h]
    push ss
    push ax
    call mf748
    add sp,4h
    lea ax,word ptr [bp-36h]
    push ss
    push ax
    call mf753
    jmp near ptr lbl990f
lbl7FAf:
    lea ax,word ptr [bp-1Eh]
    push ss
    push ax
    lea ax,word ptr [bp-1Ch]
    push ss
    push ax
    push word ptr [bp-1Ah]
    push word ptr [bp-18h]
    call mf763
    add sp,0Ch
    cmp word ptr [bp-1Ch],0h
    jnl short lbl820f
    mov word ptr [bp-1Ch],0h
    jmp short lbl83Af
    nop
lbl820f:
    mov ax,word ptr [bp-1Eh]
    mov cx,2h
    cwd
    idiv cx
    add dx,word ptr ds:[5B00h]
    dec dx
    cmp dx,word ptr [bp-1Ch]
    jnl short lbl83Af
    mov ax,word ptr ds:[5B00h]
    dec ax
    mov word ptr [bp-1Ch],ax
lbl83Af:
    cmp word ptr [bp-1Eh],0h
    jnl short lbl848f
    mov word ptr [bp-1Eh],0h
    jmp short lbl854f
    nop
lbl848f:
    mov ax,word ptr ds:[5B02h]
    cmp word ptr [bp-1Eh],ax
    jl short lbl854f
    dec ax
    mov word ptr [bp-1Eh],ax
lbl854f:
    mov al,byte ptr [bp-20h]
    cbw
    cmp ax,word ptr [bp-1Ch]
    jnz short lbl866f
    mov al,byte ptr [bp-1Fh]
    cbw
    cmp ax,word ptr [bp-1Eh]
    jz short lbl877f
lbl866f:
    mov al,byte ptr [bp-1Ch]
    mov byte ptr [bp-20h],al
    mov al,byte ptr [bp-1Eh]
    mov byte ptr [bp-1Fh],al
    mov word ptr [bp-0Eh],1h
lbl877f:
    cmp word ptr [bp-0Ch],0h
    jz short lbl880f
    jmp near ptr lbl7C5b
lbl880f:
    cmp word ptr [bp-16h],0h
    jnz short lbl889f
    jmp near ptr lbl7C5b
lbl889f:
    cmp word ptr [bp-0Eh],0h
    jnz short lbl8A6f
    call mf812
    cmp dx,word ptr [bp-38h]
    jnl short lbl89Cf
    jmp near ptr lbl7C5b
lbl89Cf:
    jg short lbl8A6f
    cmp ax,word ptr [bp-3Ah]
    jnc short lbl8A6f
    jmp near ptr lbl7C5b
lbl8A6f:
    mov word ptr [bp-0Ch],1h
    jmp near ptr lbl7C5b
lbl8AEf:
    or ax,ax
    jnz short lbl8B5f
    jmp near ptr lbl7C5b
lbl8B5f:
    lea ax,word ptr [bp-46h]
    push ss
    push ax
    lea ax,word ptr [bp-44h]
    push ss
    push ax
    lea ax,word ptr [bp-42h]
    push ss
    push ax
    push word ptr [bp-1Ah]
    push word ptr [bp-18h]
    call mf836
    add sp,10h
    or ax,ax
    jz short lbl912f
    cmp word ptr [bp-46h],5h
    jnz short lbl912f
    push word ptr [bp-44h]
    xor ax,ax
    push ax
    call mf845
    add sp,4h
    cmp word ptr [bp-44h],1h
    jnz short lbl8F3f
    jmp near ptr lbl6BDb
lbl8F3f:
    cmp word ptr [bp-44h],2h
    jnz short lbl8FCf
    jmp near ptr lblB1Af
lbl8FCf:
    cmp word ptr [bp-44h],3h
    jnz short lbl905f
    jmp near ptr lblB50f
lbl905f:
    cmp word ptr [bp-44h],4h
    jz short lbl90Ef
    jmp near ptr lblC4Ff
lbl90Ef:
    jmp near ptr lbl6A5b
    nop
lbl912f:
    lea ax,word ptr [bp-1Eh]
    push ss
    push ax
    lea cx,word ptr [bp-1Ch]
    push ss
    push cx
    push word ptr [bp-1Ah]
    push word ptr [bp-18h]
    call mf869
    add sp,0Ch
    push word ptr [bp-1Eh]
    push word ptr [bp-1Ch]
    call mf873
    add sp,4h
    mov word ptr [bp-6h],ax
    or ax,ax
    jnz short lbl942f
    jmp near ptr lbl7C0b
lbl942f:
    mov es, ds:[5B04h]
    dec word ptr [bp-6h]
    mov bx,word ptr [bp-6h]
    add bx,bx
    add bx,bx
    cmp byte ptr es:[bx+md884],0h
    jnz short lbl95Bf
    jmp near ptr lbl4C5b
lbl95Bf:
    mov ax,3h
    mov dx,0F041h
    push dx
    push ax
    call mf891
    add sp,4h
    jmp near ptr lbl7C0b
lbl96Ef:
    mov es, ds:[5B04h]
    mov bx,word ptr [bp-6h]
    add bx,bx
    add bx,bx
    mov ax,word ptr es:[bx+md898]
    mov dx,word ptr es:[bx+md899]
    mov word ptr [bp-22h],ax
    mov word ptr [bp-20h],dx
    push dx
    push ax
    call mf904
lbl990f:
    add sp,4h
lbl993f:
    cmp word ptr [bp-10h],0h
    jnz short lbl9F4f
    mov al,byte ptr [bp-1Fh]
    and al,1h
    jz short lbl9AAf
    mov ax,word ptr ds:[5AFEh]
    cwd
    sub ax,dx
    sar ax,1
    jmp short lbl9ADf
lbl9AAf:
    mov ax,2h
lbl9ADf:
    mov word ptr [bp-4Ch],ax
    mov al,byte ptr [bp-1Fh]
    and al,1h
    jz short lbl9BCf
    mov ax,2h
    jmp short lbl9C4f
lbl9BCf:
    mov ax,word ptr ds:[5AFCh]
    cwd
    sub ax,dx
    sar ax,1
lbl9C4f:
    mov word ptr [bp-4Eh],ax
    mov al,byte ptr [bp-1Fh]
    mov cl,2h
    cbw
    idiv cl
    cbw
    imul word ptr ds:[5AFEh]
    add ax,word ptr ds:[5AFAh]
    add ax,word ptr [bp-4Ch]
    push ax
    mov al,byte ptr [bp-20h]
    cbw
    imul word ptr ds:[5AFCh]
    add ax,word ptr ds:[5AF8h]
    add ax,word ptr [bp-4Eh]
    push ax
    call mf943
    add sp,4h
lbl9F4f:
    mov al,byte ptr [bp-1Fh]
    mov cl,2h
    cbw
    idiv cl
    cbw
    mov cx,ax
    inc ax
    imul word ptr ds:[5AFEh]
    add ax,word ptr ds:[5AFAh]
    dec ax
    push ax
    mov al,byte ptr [bp-20h]
    cbw
    mov dx,ax
    inc ax
    mov bx,dx
    imul word ptr ds:[5AFCh]
    add ax,word ptr ds:[5AF8h]
    dec ax
    push ax
    mov ax,cx
    imul word ptr ds:[5AFEh]
    add ax,word ptr ds:[5AFAh]
    push ax
    mov ax,bx
    imul word ptr ds:[5AFCh]
    add ax,word ptr ds:[5AF8h]
    push ax
    lea ax,word ptr [bp-36h]
    push ss
    push ax
    call mf976
    add sp,0Ch
    mov ax,1h
    push ax
    push word ptr [bp-20h]
    push word ptr [bp-22h]
    call mf982
    add sp,6h
    cmp word ptr [bp-0Ah],0h
    jnz short lblA73f
    call mf986
    add ax,0FAh
    adc dx,0h
    mov word ptr [bp-3Ah],ax
    mov word ptr [bp-38h],dx
    mov word ptr [bp-0Ah],1h
    mov word ptr [bp-0Ch],0h
lblA73f:
    mov word ptr [bp-0Eh],0h
lblA78f:
    cmp word ptr ds:[5E0Ch],0h
    jz short lblA82f
    jmp near ptr lbl412b
lblA82f:
    jmp near ptr lblB86f
    nop
lblA86f:
    mov ax,word ptr [bp-8h]
    mov word ptr [bp-40h],ax
    mov ax,3h
    push ax
    xor ax,ax
    push ax
    call mf1005
    add sp,4h
    mov word ptr [bp-4h],0h
lblAA0b:
    inc word ptr [bp-8h]
    cmp word ptr [bp-8h],0Bh
    jnc short lblACCf
    cmp word ptr [bp+6h],0h
    jnz short lblAB2f
    jmp near ptr lblB86f
lblAB2f:
    mov bx,word ptr [bp-8h]
    cmp byte ptr [bx+327Ch],0h
    jnz short lblABFf
    jmp near ptr lblB86f
lblABFf:
    inc word ptr [bp-4h]
    cmp word ptr [bp-4h],0Bh
    jc short lblAA0b
    jmp near ptr lblB86f
    nop
lblACCf:
    mov ax,word ptr [bp-40h]
    jmp near ptr lblB83f
lblAD2f:
    mov ax,word ptr [bp-8h]
    mov word ptr [bp-3Eh],ax
    mov ax,2h
    push ax
    xor ax,ax
    push ax
    call mf1031
    add sp,4h
    mov word ptr [bp-4h],0h
lblAECb:
    cmp word ptr [bp-8h],0h
    jz short lblB14f
    dec word ptr [bp-8h]
    cmp word ptr [bp+6h],0h
    jnz short lblAFEf
    jmp near ptr lblB86f
lblAFEf:
    mov bx,word ptr [bp-8h]
    cmp byte ptr [bx+327Ch],0h
    jz short lblB86f
    inc word ptr [bp-4h]
    cmp word ptr [bp-4h],0Bh
    jc short lblAECb
    jmp short lblB86f
    nop
lblB14f:
    mov ax,word ptr [bp-3Eh]
    jmp short lblB83f
    nop
lblB1Af:
    mov ax,word ptr [bp-8h]
    mov word ptr [bp-48h],ax
    mov word ptr [bp-4h],0h
lblB25b:
    cmp word ptr [bp-8h],0h
    jz short lblB4Af
    dec word ptr [bp-8h]
    cmp word ptr [bp+6h],0h
    jz short lblB86f
    mov bx,word ptr [bp-8h]
    cmp byte ptr [bx+327Ch],0h
    jz short lblB86f
    inc word ptr [bp-4h]
    cmp word ptr [bp-4h],0Bh
    jc short lblB25b
    jmp short lblB86f
    nop
lblB4Af:
    mov ax,word ptr [bp-48h]
    jmp short lblB83f
    nop
lblB50f:
    mov ax,word ptr [bp-8h]
    mov word ptr [bp-4Ah],ax
    mov word ptr [bp-4h],0h
lblB5Bb:
    inc word ptr [bp-8h]
    cmp word ptr [bp-8h],0Bh
    jnc short lblB80f
    cmp word ptr [bp+6h],0h
    jz short lblB86f
    mov bx,word ptr [bp-8h]
    cmp byte ptr [bx+327Ch],0h
    jz short lblB86f
    inc word ptr [bp-4h]
    cmp word ptr [bp-4h],0Bh
    jc short lblB5Bb
    jmp short lblB86f
    nop
lblB80f:
    mov ax,word ptr [bp-4Ah]
lblB83f:
    mov word ptr [bp-8h],ax
lblB86f:
    cmp word ptr ds:[5E0Ch],0h
    jz short lblB90f
    jmp near ptr lblC28f
lblB90f:
    call mf1091
    cmp ax,word ptr ds:[5E0Eh]
    jnz short lblBF6f
    mov bx,word ptr [bp-8h]
    mov byte ptr [bx+327Ch],1h
    mov word ptr [bp-2h],0h
    mov word ptr [bp-4h],0h
lblBADb:
    mov bx,word ptr [bp-4h]
    cmp byte ptr [bx+327Ch],0h
    jz short lblBBAf
    inc word ptr [bp-2h]
lblBBAf:
    inc word ptr [bp-4h]
    cmp word ptr [bp-4h],0Ch
    jc short lblBADb
    cmp word ptr [bp-2h],0Bh
    jnz short lblBD0f
    mov ax,32B6h
    mov dx,ds
    jmp short lblBD6f
lblBD0f:
    mov ax,4h
    mov dx,0F041h
lblBD6f:
    mov word ptr [bp-52h],ax
    mov word ptr [bp-50h],dx
    push dx
    push ax
    call mf1116
    add sp,4h
    inc word ptr [bp-8h]
    cmp word ptr [bp-8h],0Bh
    jc short lblC06f
    mov word ptr [bp-8h],0h
    jmp short lblC06f
lblBF6f:
    mov ax,5h
    mov dx,0F041h
    push dx
    push ax
    call mf1127
    add sp,4h
lblC06f:
    call mf1129
    mov ax,55Fh
    push ax
    call mf1132
    add sp,2h
    call mf1134
    cmp word ptr [bp-2h],0Bh
    jnz short lblC28f
    cmp word ptr [bp+6h],0h
    jnz short lblC4Ff
lblC28f:
    mov ax,0C7h
    push ax
    mov ax,109h
    push ax
    xor ax,ax
    push ax
    push ax
    call mf1146
    add sp,8h
    jmp near ptr lbl248b
    nop
lblC40f:
    mov ax,5h
    push ax
    xor ax,ax
    push ax
    call mf1154
    add sp,4h
lblC4Ff:
    cmp byte ptr [bp-36h],0h
    jz short lblC62f
    lea ax,word ptr [bp-36h]
    push ss
    push ax
    call mf1161
    add sp,4h
lblC62f:
    call mf1163
    mov ax,1h
    push ax
    call mf1166
    add sp,2h
    mov ax,1Fh
    push ax
    call mf1170
    add sp,2h
    call mf1172
    mov ax,10h
    push ax
    call mf1175
    add sp,2h
    mov word ptr [bp-2h],0h
    mov word ptr [bp-4h],0h
lblC9Ab:
    mov bx,word ptr [bp-4h]
    cmp byte ptr [bx+327Ch],0h
    jz short lblCA7f
    inc word ptr [bp-2h]
lblCA7f:
    inc word ptr [bp-4h]
    cmp word ptr [bp-4h],0Ch
    jc short lblC9Ab
    mov ax,word ptr [bp-2h]
    pop si
    pop di
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
