_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi5:NEAR
    EXTRN mi33:NEAR
    EXTRN mf56:FAR
    EXTRN mf69:FAR
    EXTRN mi104:NEAR
    EXTRN mf113:FAR
    EXTRN mi188:NEAR
    EXTRN mi292:NEAR
    EXTRN mf374:FAR
    EXTRN mf374:FAR
    EXTRN mf374:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,24h
    push si
    mov ax,word ptr [bp+6h]
    sub ax, offset mi5
    jnz short lbl12f
    jmp near ptr lbl3FCf
lbl12f:
    dec ax
    jnz short lbl18f
    jmp near ptr lbl416f
lbl18f:
    les bx, dword ptr ds:[6340h]
    cmp byte ptr es:[bx+0Bh],0h
    jl short lbl2Af
    mov al,byte ptr es:[bx+0Bh]
    jmp short lbl37f
    nop
lbl2Af:
    les bx, dword ptr es:[bx+0Eh]
    les bx, dword ptr es:[bx]
    mov si,word ptr [bp+6h]
    mov al,byte ptr es:[bx+si]
lbl37f:
    cbw
    mov word ptr [bp-4h],ax
    les bx, dword ptr ds:[6340h]
    cmp byte ptr es:[bx+0Ch],0h
    jnl short lbl6Af
    les bx, dword ptr es:[bx+12h]
    les bx, dword ptr es:[bx]
    mov si,word ptr [bp+6h]
    mov al,byte ptr es:[bx+si]
    cbw
    mov word ptr [bp-2h],ax
    mov cx,ax
    and ax, offset mi33
    and cx,0F0h
    mov dx,cx
    mov cl,4h
    sar dx,cl
    add ax,dx
    jmp short lbl6Ff
lbl6Af:
    mov al,byte ptr es:[bx+0Ch]
    cbw
lbl6Ff:
    add ax,word ptr [bp-4h]
    mov word ptr [bp-8h],ax
    les bx, dword ptr ds:[6340h]
    mov al,byte ptr es:[bx+0Ah]
    cbw
    mov word ptr [bp-6h],ax
    cmp word ptr ds:[6DFEh],0h
    jl short lblBFf
    cmp word ptr ds:[6346h],0h
    jnl short lblBFf
    xor ax,ax
    push ax
    push word ptr ds:[6DFEh]
    push ax
    call mf56
    push word ptr ds:[6348h]
    push word ptr ds:[634Ah]
    mov ax,word ptr [bp-8h]
    add ax,word ptr ds:[6348h]
    dec ax
    push ax
    mov ax,word ptr ds:[634Ah]
    add ax,word ptr ds:[69F8h]
    dec ax
    push ax
    mov ax,2h
    push ax
    call mf69
lblBFf:
    les bx, dword ptr ds:[6340h]
    cmp byte ptr es:[bx+0Ch],0h
    jnl short lblDBf
    mov cl,4h
    mov al,byte ptr [bp-2h]
    and ax,0F0h
    sar ax,cl
    add word ptr ds:[6348h],ax
    sub word ptr [bp-8h],ax
lblDBf:
    sub ah,ah
    mov al,byte ptr es:[bx+7h]
    cmp ax,word ptr [bp+6h]
    jng short lblE9f
    jmp near ptr lbl3E8f
lblE9f:
    mov al,byte ptr es:[bx+8h]
    cmp ax,word ptr [bp+6h]
    jnl short lblF5f
    jmp near ptr lbl3E8f
lblF5f:
    mov al,byte ptr es:[bx+6h]
    cbw
    mov cx,ax
    mov ax,word ptr [bp+6h]
    mov dl,byte ptr es:[bx+7h]
    sub dh,dh
    sub ax,dx
    imul cx
    imul word ptr [bp-6h]
    les bx, dword ptr es:[bx+16h]
    add ax,word ptr es:[bx]
    mov dx,word ptr es:[bx+2h]
    mov word ptr [bp-1Eh],ax
    mov word ptr [bp-1Ch],dx
    mov word ptr [bp-0Ch],cx
    mov ax,word ptr [bp-4h]
    add ax, offset mi104
    cwd
    and dx,7h
    add ax,dx
    mov cx,3h
    sar ax,cl
    mov word ptr [bp-0Ah],ax
    push word ptr ds:[634Ah]
    push word ptr ds:[6348h]
    call mf113
    add sp,4h
    mov word ptr [bp-22h],ax
    mov word ptr [bp-20h],dx
    cmp word ptr ds:[6346h],0h
    jnl short lbl1C6f
    mov ax,word ptr [bp-6h]
    mov word ptr [bp-10h],ax
    or ax,ax
    jg short lbl15Ef
    jmp near ptr lbl3E8f
lbl15Eb:
lbl15Ef:
    mov ax,word ptr [bp-4h]
    mov word ptr [bp-0Eh],ax
    or ax,ax
    jng short lbl1A7f
lbl168b:
    les bx, dword ptr [bp-1Eh]
    inc word ptr [bp-1Eh]
    mov al,byte ptr es:[bx]
    sub ah,ah
    mov word ptr [bp-12h],ax
    mov word ptr [bp-18h],80h
lbl17Bb:
    cmp word ptr [bp-0Eh],0h
    jng short lbl1A1f
    mov ax,word ptr [bp-12h]
    test word ptr [bp-18h],ax
    jz short lbl192f
    mov al,byte ptr ds:[6344h]
    les bx, dword ptr [bp-22h]
    mov byte ptr es:[bx],al
lbl192f:
    inc word ptr [bp-22h]
    dec word ptr [bp-0Eh]
    shr word ptr [bp-18h],1
    cmp word ptr [bp-18h],0h
    jnz short lbl17Bb
lbl1A1f:
    cmp word ptr [bp-0Eh],0h
    jg short lbl168b
lbl1A7f:
    mov ax,140h
    sub ax,word ptr [bp-4h]
    add word ptr [bp-22h],ax
    mov ax,word ptr [bp-0Ch]
    sub ax,word ptr [bp-0Ah]
    add word ptr [bp-1Eh],ax
    dec word ptr [bp-10h]
    cmp word ptr [bp-10h],0h
    jg short lbl15Eb
    jmp near ptr lbl3E8f
    nop
lbl1C6f:
    add word ptr [bp-4h],2h
    mov word ptr [bp-10h],0h
    add word ptr [bp-6h],2h
    cmp word ptr [bp-6h],0h
    jg short lbl1DCf
    jmp near ptr lbl3E8f
lbl1DCf:
    mov ax,word ptr [bp-6h]
    dec ax
    mov word ptr [bp-24h],ax
lbl1E3b:
    xor ax,ax
    mov word ptr [bp-16h],ax
    mov word ptr [bp-14h],ax
    cmp word ptr [bp-10h],1h
    jng short lbl1FDf
    les bx, dword ptr [bp-1Eh]
    sub bx,word ptr [bp-0Ch]
    mov al,byte ptr es:[bx]
    mov word ptr [bp-14h],ax
lbl1FDf:
    mov ax,word ptr [bp-10h]
    cmp word ptr [bp-24h],ax
    jng short lbl210f
    les bx, dword ptr [bp-1Eh]
    sub ah,ah
    mov al,byte ptr es:[bx]
    or word ptr [bp-14h],ax
lbl210f:
    cmp word ptr [bp-10h],0h
    jng short lbl22Ff
    mov ax,word ptr [bp-6h]
    sub ax, offset mi188
    cmp ax,word ptr [bp-10h]
    jng short lbl22Ff
    les bx, dword ptr [bp-1Eh]
    mov si,word ptr [bp-0Ch]
    mov al,byte ptr es:[bx+si]
    sub ah,ah
    or word ptr [bp-14h],ax
lbl22Ff:
    cmp word ptr [bp-10h],0h
    jng short lbl24Ef
    mov ax,word ptr [bp-10h]
    cmp word ptr [bp-24h],ax
    jng short lbl24Ef
    les bx, dword ptr [bp-1Eh]
    inc word ptr [bp-1Eh]
    mov al,byte ptr es:[bx]
    sub ah,ah
    mov word ptr [bp-12h],ax
    jmp short lbl256f
    nop
lbl24Ef:
    mov word ptr [bp-12h],0h
    inc word ptr [bp-1Eh]
lbl256f:
    test byte ptr [bp-14h],80h
    jnz short lbl262f
    inc word ptr [bp-22h]
    jmp short lbl26Ef
    nop
lbl262f:
    mov al,byte ptr ds:[6346h]
    les bx, dword ptr [bp-22h]
    inc word ptr [bp-22h]
    mov byte ptr es:[bx],al
lbl26Ef:
    mov ax,word ptr [bp-4h]
    dec ax
    mov word ptr [bp-0Eh],ax
    or ax,ax
    jg short lbl27Cf
    jmp near ptr lbl3BAf
lbl27Cb:
lbl27Cf:
    test byte ptr [bp-12h],80h
    jz short lbl288f
    mov al,byte ptr ds:[6344h]
    jmp short lbl29Df
    nop
lbl288f:
    test byte ptr [bp-16h],1h
    jnz short lbl29Af
    test byte ptr [bp-14h],0C0h
    jnz short lbl29Af
    inc word ptr [bp-22h]
    jmp short lbl2A6f
    nop
lbl29Af:
    mov al,byte ptr ds:[6346h]
lbl29Df:
    les bx, dword ptr [bp-22h]
    inc word ptr [bp-22h]
    mov byte ptr es:[bx],al
lbl2A6f:
    dec word ptr [bp-0Eh]
    mov word ptr [bp-1Ah],0E0h
    mov word ptr [bp-18h],40h
lbl2B3b:
    cmp word ptr [bp-0Eh],0h
    jng short lbl2F0f
    mov ax,word ptr [bp-12h]
    test word ptr [bp-18h],ax
    jz short lbl2D0f
    mov al,byte ptr ds:[6344h]
lbl2C4b:
    les bx, dword ptr [bp-22h]
    inc word ptr [bp-22h]
    mov byte ptr es:[bx],al
    jmp short lbl2E1f
    nop
lbl2D0f:
    mov ax,word ptr [bp-14h]
    test word ptr [bp-1Ah],ax
    jz short lbl2DEf
    mov al,byte ptr ds:[6346h]
    jmp short lbl2C4b
    nop
lbl2DEf:
    inc word ptr [bp-22h]
lbl2E1f:
    dec word ptr [bp-0Eh]
    shr word ptr [bp-1Ah],1
    shr word ptr [bp-18h],1
    cmp word ptr [bp-18h],1h
    ja short lbl2B3b
lbl2F0f:
    cmp word ptr [bp-0Eh],0h
    jg short lbl2F9f
    jmp near ptr lbl3B1f
lbl2F9f:
    mov ax,word ptr [bp-14h]
    mov word ptr [bp-16h],ax
    mov word ptr [bp-14h],0h
    cmp word ptr [bp-0Eh],2h
    jng short lbl350f
    cmp word ptr [bp-10h],1h
    jng short lbl31Ef
    les bx, dword ptr [bp-1Eh]
    sub bx,word ptr [bp-0Ch]
    sub ah,ah
    mov al,byte ptr es:[bx]
    mov word ptr [bp-14h],ax
lbl31Ef:
    mov ax,word ptr [bp-10h]
    cmp word ptr [bp-24h],ax
    jng short lbl331f
    les bx, dword ptr [bp-1Eh]
    sub ah,ah
    mov al,byte ptr es:[bx]
    or word ptr [bp-14h],ax
lbl331f:
    cmp word ptr [bp-10h],0h
    jng short lbl350f
    mov ax,word ptr [bp-6h]
    sub ax, offset mi292
    cmp ax,word ptr [bp-10h]
    jng short lbl350f
    les bx, dword ptr [bp-1Eh]
    mov si,word ptr [bp-0Ch]
    mov al,byte ptr es:[bx+si]
    sub ah,ah
    or word ptr [bp-14h],ax
lbl350f:
    test byte ptr [bp-12h],1h
    jz short lbl35Cf
    mov al,byte ptr ds:[6344h]
    jmp short lbl371f
    nop
lbl35Cf:
    test byte ptr [bp-16h],3h
    jnz short lbl36Ef
    test byte ptr [bp-14h],80h
    jnz short lbl36Ef
    inc word ptr [bp-22h]
    jmp short lbl37Af
    nop
lbl36Ef:
    mov al,byte ptr ds:[6346h]
lbl371f:
    les bx, dword ptr [bp-22h]
    inc word ptr [bp-22h]
    mov byte ptr es:[bx],al
lbl37Af:
    dec word ptr [bp-0Eh]
    cmp word ptr [bp-0Eh],1h
    jng short lbl3ACf
    cmp word ptr [bp-10h],0h
    jng short lbl3A2f
    mov ax,word ptr [bp-10h]
    cmp word ptr [bp-24h],ax
    jng short lbl3A2f
    les bx, dword ptr [bp-1Eh]
    inc word ptr [bp-1Eh]
    mov al,byte ptr es:[bx]
    sub ah,ah
    mov word ptr [bp-12h],ax
    jmp short lbl3B1f
    nop
lbl3A2f:
    mov word ptr [bp-12h],0h
    inc word ptr [bp-1Eh]
    jmp short lbl3B1f
lbl3ACf:
    mov word ptr [bp-12h],0h
lbl3B1f:
    cmp word ptr [bp-0Eh],0h
    jng short lbl3BAf
    jmp near ptr lbl27Cb
lbl3BAf:
    mov ax,140h
    sub ax,word ptr [bp-4h]
    add word ptr [bp-22h],ax
    cmp word ptr [bp-10h],0h
    jng short lbl3D4f
    mov ax,word ptr [bp-0Ch]
    sub ax,word ptr [bp-0Ah]
    add word ptr [bp-1Eh],ax
    jmp short lbl3DAf
lbl3D4f:
    mov ax,word ptr [bp-0Ah]
    sub word ptr [bp-1Eh],ax
lbl3DAf:
    mov ax,word ptr [bp-6h]
    inc word ptr [bp-10h]
    cmp word ptr [bp-10h],ax
    jnl short lbl3E8f
    jmp near ptr lbl1E3b
lbl3E8f:
    mov ax,word ptr [bp-8h]
    add word ptr ds:[6348h],ax
    cmp word ptr ds:[6346h],0h
    jl short lbl423f
    inc word ptr ds:[6348h]
    jmp short lbl423f
lbl3FCf:
    mov ax,word ptr ds:[6348h]
    cwd
    idiv word ptr ds:[6DFCh]
    sub dx,word ptr ds:[6DFCh]
    neg dx
    add word ptr ds:[6348h],dx
    cmp word ptr ds:[6348h],13Fh
    jl short lbl423f
lbl416f:
    mov word ptr ds:[6348h],0h
    mov ax,word ptr ds:[69F8h]
    add word ptr ds:[634Ah],ax
lbl423f:
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
