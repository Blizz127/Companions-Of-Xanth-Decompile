_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf8:FAR
    EXTRN mf13:FAR
    EXTRN mf19:FAR
    EXTRN mf21:FAR
    EXTRN mf24:FAR
    EXTRN mf29:FAR
    EXTRN mf33:FAR
    EXTRN mf42:FAR
    EXTRN mf44:FAR
    EXTRN mf53:FAR
    EXTRN mf83:FAR
    EXTRN mf93:FAR
    EXTRN mf103:FAR
    EXTRN mf114:FAR
    EXTRN mf118:FAR
    EXTRN mi120:NEAR
    EXTRN mi123:NEAR
    EXTRN mi129:NEAR
    EXTRN mi135:NEAR
    EXTRN mi138:NEAR
    EXTRN mi141:NEAR
    EXTRN mi144:NEAR
    EXTRN mi147:NEAR
    EXTRN mi165:NEAR
    EXTRN mi168:NEAR
    EXTRN mi171:NEAR
    EXTRN mi174:NEAR
    EXTRN mi177:NEAR
    EXTRN mi180:NEAR
    EXTRN mi183:NEAR
    EXTRN mi186:NEAR
    EXTRN mi189:NEAR
    EXTRN mi191:NEAR
    EXTRN mf200:FAR
    EXTRN mf204:FAR
    EXTRN mf210:FAR
    EXTRN mf215:FAR
    EXTRN mf222:FAR
    EXTRN mf258:FAR
    EXTRN mi268:NEAR
    EXTRN mi269:NEAR
    EXTRN mf297:FAR
    EXTRN mf302:FAR
    EXTRN mf307:FAR
    EXTRN mf312:FAR
    EXTRN mf317:FAR
    EXTRN mf321:FAR
    EXTRN mf327:FAR
    EXTRN mi336:NEAR
    EXTRN mi344:NEAR
    EXTRN mf350:FAR
    EXTRN mf358:FAR
    EXTRN mi368:NEAR
    EXTRN mi373:NEAR
    EXTRN mf393:FAR
    EXTRN mi400:NEAR
    EXTRN mi405:NEAR
    EXTRN mf423:FAR
    EXTRN mf431:FAR
    EXTRN mf435:FAR
    EXTRN mf441:FAR
    EXTRN mf445:FAR
    EXTRN mf491:FAR
    EXTRN mf502:FAR
    EXTRN mf508:FAR
    EXTRN mf540:FAR
    EXTRN mi545:NEAR
    EXTRN mi550:NEAR
    EXTRN mf558:FAR
    EXTRN mf567:FAR
    EXTRN mf576:FAR
    EXTRN mf581:FAR
    EXTRN mf586:FAR
    EXTRN mf606:FAR
    EXTRN mf614:FAR
    EXTRN mf618:FAR
    EXTRN mf622:FAR
    EXTRN mf629:FAR
    EXTRN mi634:NEAR
    EXTRN mi642:NEAR
    EXTRN mf648:FAR
    EXTRN mf664:FAR
    EXTRN mf673:FAR
    EXTRN mf678:FAR
    EXTRN mf697:FAR
    EXTRN mf701:FAR
    EXTRN mf702:FAR
    EXTRN mf709:FAR
    EXTRN mf725:FAR
    EXTRN mi728:NEAR
    EXTRN mf742:FAR
    EXTRN mf814:FAR
    EXTRN mf823:FAR
    EXTRN mf829:FAR
    EXTRN mi834:NEAR
    EXTRN mi838:NEAR
    EXTRN mf844:FAR
    EXTRN mf847:FAR
    EXTRN mf852:FAR
    EXTRN mf862:FAR
    EXTRN mf864:FAR
    EXTRN mf867:FAR
    EXTRN mf869:FAR
    EXTRN mf872:FAR
    EXTRN mf876:FAR
    EXTRN mf883:FAR
    EXTRN mf883:FAR
    EXTRN mf883:FAR
    EXTRN mf883:FAR
    EXTRN mf883:FAR
    EXTRN mf883:FAR
    EXTRN mf883:FAR
    EXTRN mf883:FAR
    EXTRN mf883:FAR
    EXTRN mf883:FAR
    EXTRN mf883:FAR
    EXTRN mf883:FAR
    EXTRN mf883:FAR
    EXTRN mf883:FAR
    EXTRN mf883:FAR
    EXTRN mf883:FAR
    EXTRN mf883:FAR
    EXTRN mf883:FAR
    EXTRN mf883:FAR
    EXTRN mf883:FAR
    EXTRN mf883:FAR
    EXTRN mf883:FAR
    EXTRN mf883:FAR
    EXTRN mf883:FAR
    EXTRN mf883:FAR
    EXTRN mf883:FAR
    EXTRN mf883:FAR
    EXTRN mf883:FAR
    EXTRN mf883:FAR
    EXTRN mf883:FAR
    EXTRN mf883:FAR
    EXTRN mf883:FAR
    EXTRN mf883:FAR
    EXTRN mf883:FAR
    EXTRN mf883:FAR
    EXTRN mf883:FAR
    EXTRN mf883:FAR
    EXTRN mf883:FAR
    EXTRN mf883:FAR
    EXTRN mf883:FAR
    EXTRN mf883:FAR
    EXTRN mf883:FAR
    EXTRN mf883:FAR
    EXTRN mf883:FAR
    EXTRN mf883:FAR
    EXTRN mf883:FAR
    EXTRN mf883:FAR
    EXTRN mf883:FAR
    EXTRN mf883:FAR
    EXTRN mf883:FAR
    EXTRN mf883:FAR
    EXTRN mf883:FAR
    EXTRN mf883:FAR
    EXTRN mf883:FAR
    EXTRN mf883:FAR
    EXTRN mf883:FAR
    EXTRN mf883:FAR
    EXTRN mf883:FAR
    EXTRN mf883:FAR
    EXTRN mf883:FAR
    EXTRN mf883:FAR
    EXTRN mf883:FAR
    EXTRN mf883:FAR
    EXTRN mf883:FAR
    EXTRN mf883:FAR
    EXTRN mf883:FAR
    EXTRN mf883:FAR
    EXTRN mf883:FAR
    EXTRN mf883:FAR
    EXTRN mf883:FAR
    EXTRN mf883:FAR
    EXTRN mf883:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,4Eh
    push di
    push si
    lea ax,word ptr [bp-38h]
    push ss
    push ax
    call mf8
    add sp,4h
    mov ax,18h
    push ax
    push word ptr ds:[256h]
    call mf13
    add sp,4h
    mov ax,20h
    mov cx,2199h
    push cx
    push ax
    call mf19
    add sp,4h
    call mf21
    mov ax,1h
    push ax
    call mf24
    add sp,2h
    xor ax,ax
    push ax
    push ax
    call mf29
    add sp,4h
    mov ax,20h
    push ax
    call mf33
    add sp,2h
    mov ax,0C7h
    push ax
    mov ax,13Fh
    push ax
    xor ax,ax
    push ax
    push ax
    call mf42
    add sp,8h
    call mf44
    mov word ptr [bp-2h],0h
lbl7Cb:
    mov ax,0C7h
    push ax
    mov ax,13Fh
    push ax
    xor ax,ax
    push ax
    push ax
    call mf53
    add sp,8h
    mov bx,word ptr ds:[31FCh]
    mov ax,bx
    add bx,bx
    add bx,ax
    mov es, ds:[5AE2h]
    lea di,word ptr [bx+6A24h]
    mov si,3216h
    mov cx,6h
    rep movsw
    mov bx,word ptr ds:[3204h]
    mov ax,bx
    add bx,bx
    add bx,ax
    lea di,word ptr [bx+6A24h]
    mov si,3222h
    movsw
    movsw
    movsw
    movsw
    movsb
    mov bx,word ptr ds:[320Ah]
    mov ax,bx
    add bx,bx
    add bx,ax
    lea di,word ptr [bx+6A24h]
    mov si,322Ch
    movsw
    movsb
    call mf83
    mov es, ds:[5AE4h]
    mov ax,33DCh
    push ds
    mov di,46E4h
    mov si,20h
    mov ds,ax
    mov cx,36h
    rep movsw
    pop ds
    call mf93
    or ax,ax
    jnz short lblFAf
    jmp near ptr lbl955f
lblFAf:
    mov word ptr [bp-42h],46E4h
lblFFb:
    mov ax,1h
    push ax
    mov ax,3420h
    push ax
    push word ptr [bp-42h]
    call mf103
    add sp,6h
    add word ptr [bp-42h],9h
    cmp word ptr [bp-42h],4750h
    jc short lblFFb
    sub ax,ax
    mov word ptr [bp-22h],ax
    mov word ptr [bp-24h],ax
    mov word ptr [bp-0Ah],0FFFFh
    mov word ptr [bp-0Ch],ax
    mov word ptr [bp-20h],ax
lbl130b:
    call mf114
    or ax,ax
    jnz short lbl13Cf
    jmp near ptr lbl560f
lbl13Cf:
    call mf118
    mov word ptr [bp-12h],ax
    cmp ax, offset mi120
    jnz short lbl14Cf
    jmp near ptr lbl93Df
lbl14Cf:
    cmp ax, offset mi123
    jnz short lbl154f
    jmp near ptr lbl93Df
lbl154f:
    cmp ax,13Ch
    jnz short lbl15Cf
    jmp near ptr lbl93Df
lbl15Cf:
    cmp ax, offset mi129
    jnz short lbl164f
    jmp near ptr lbl763f
lbl164f:
    cmp ax,13Bh
    jnz short lbl16Cf
    jmp near ptr lbl763f
lbl16Cf:
    cmp ax, offset mi135
    jnz short lbl174f
    jmp near ptr lbl486f
lbl174f:
    cmp ax, offset mi138
    jnz short lbl17Cf
    jmp near ptr lbl486f
lbl17Cf:
    cmp ax, offset mi141
    jnz short lbl184f
    jmp near ptr lbl486f
lbl184f:
    cmp ax, offset mi144
    jnz short lbl18Cf
    jmp near ptr lbl486f
lbl18Cf:
    cmp ax, offset mi147
    jnz short lbl194f
    jmp near ptr lbl486f
lbl194f:
    cmp ax,10Fh
    jnz short lbl19Cf
    jmp near ptr lbl486f
lbl19Cf:
    cmp ax,14Bh
    jnz short lbl1A4f
    jmp near ptr lbl3DCf
lbl1A4f:
    cmp ax,14Dh
    jnz short lbl1ACf
    jmp near ptr lbl3DCf
lbl1ACf:
    cmp ax,148h
    jnz short lbl1B4f
    jmp near ptr lbl3DCf
lbl1B4f:
    cmp ax,150h
    jnz short lbl1BCf
    jmp near ptr lbl3DCf
lbl1BCf:
    cmp ax, offset mi165
    jnz short lbl1C4f
    jmp near ptr lbl2D4f
lbl1C4f:
    cmp ax, offset mi168
    jnz short lbl1CCf
    jmp near ptr lbl2D4f
lbl1CCf:
    cmp ax, offset mi171
    jnz short lbl1D4f
    jmp near ptr lbl2D4f
lbl1D4f:
    cmp ax, offset mi174
    jnz short lbl1DCf
    jmp near ptr lbl2D4f
lbl1DCf:
    cmp ax, offset mi177
    jnz short lbl1E4f
    jmp near ptr lbl2D4f
lbl1E4f:
    cmp ax, offset mi180
    jnz short lbl1ECf
    jmp near ptr lbl2D4f
lbl1ECf:
    cmp ax, offset mi183
    jnz short lbl1F4f
    jmp near ptr lbl2D4f
lbl1F4f:
    cmp ax, offset mi186
    jnz short lbl1FCf
    jmp near ptr lbl2D4f
lbl1FCf:
    cmp ax, offset mi189
    jz short lbl209f
    cmp ax, offset mi191
    jz short lbl209f
    jmp near ptr lbl835f
lbl209f:
    mov ax,word ptr [bp-22h]
    or ax,word ptr [bp-24h]
    jnz short lbl214f
    jmp near ptr lbl296f
lbl214f:
    push word ptr [bp-22h]
    push word ptr [bp-24h]
    call mf200
    add sp,4h
    or ax,ax
    jz short lbl22Ef
lbl226b:
    call mf204
    jmp near ptr lbl835f
lbl22Ef:
    mov ax,1h
    push ax
    push word ptr [bp-22h]
    push word ptr [bp-24h]
    call mf210
    add sp,6h
    lea ax,word ptr [bp-38h]
    push ss
    push ax
    call mf215
    add sp,4h
    sub ax,ax
    mov word ptr [bp-22h],ax
    mov word ptr [bp-24h],ax
    cmp word ptr [bp-20h],ax
    jz short lbl25Ff
    call mf222
lbl25Ff:
    mov word ptr [bp-2h],1h
    mov word ptr [bp-44h],46EAh
lbl269b:
    mov es, ds:[5AE4h]
    mov bx,word ptr [bp-44h]
    cmp byte ptr es:[bx],0h
    jz short lbl284f
    add word ptr [bp-44h],9h
    cmp word ptr [bp-44h],4756h
    jc short lbl269b
    jmp short lbl289f
    nop
lbl284b:
lbl284f:
    mov word ptr [bp-2h],0h
lbl289b:
lbl289f:
    cmp word ptr [bp-2h],0h
    jnz short lbl292f
    jmp near ptr lbl835f
lbl292f:
    jmp near ptr lbl938f
    nop
lbl296f:
    cmp word ptr [bp-0Ah],0h
    jnl short lbl29Ff
    jmp near ptr lbl835f
lbl29Ff:
    cmp word ptr [bp-0Ah],0Ch
    jl short lbl2A8f
    jmp near ptr lbl835f
lbl2A8f:
    mov ax,word ptr [bp-0Ah]
    mov cx,ax
    add ax,ax
    add ax,ax
    add ax,ax
    add ax,cx
    add ax,46E4h
    mov cx,3420h
    mov word ptr [bp-24h],ax
    mov word ptr [bp-22h],cx
    push cx
    push ax
    call mf258
lbl2C8b:
    add sp,4h
lbl2CBb:
    mov word ptr [bp-0Ch],1h
    jmp near ptr lbl835f
    nop
lbl2D4f:
    mov ax,word ptr [bp-22h]
    or ax,word ptr [bp-24h]
    jnz short lbl2DFf
    jmp near ptr lbl835f
lbl2DFf:
    mov ax,word ptr [bp-12h]
    sub ax, offset mi268
    cmp ax, offset mi269
    ja short lbl354f
    add ax,ax
    xchg ax,bx
    jmp word ptr cs:[bx+145Ch]
    xchg dl,byte ptr [si]
    mov si,8614h
    adc al,0BEh
    adc al,0BEh
    adc al,0BEh
lbl2FDb:
    adc al,94h
    adc al,0BEh
    adc al,0BEh
    adc al,0BEh
    adc al,0BEh
    adc al,0BEh
    adc al,0A2h
    adc al,0BEh
    adc al,0BEh
    adc al,0BEh
    adc al,0B0h
    adc al,0BEh
    adc al,86h
    adc al,0B0h
    adc al,0A2h
    adc al,0FFh
    jna short lbl2FDb
    push word ptr [bp-24h]
    call mf297
    jmp short lbl351f
    nop
    push word ptr [bp-22h]
    push word ptr [bp-24h]
    call mf302
    jmp short lbl351f
    nop
    push word ptr [bp-22h]
    push word ptr [bp-24h]
    call mf307
    jmp short lbl351f
    nop
    push word ptr [bp-22h]
    push word ptr [bp-24h]
    call mf312
lbl351f:
    add sp,4h
lbl354f:
    lea ax,word ptr [bp-38h]
    push ss
    push ax
    call mf317
    add sp,4h
    push word ptr [bp-22h]
    push word ptr [bp-24h]
    call mf321
    add sp,4h
    or ax,ax
    jz short lbl3C8f
    push word ptr [bp-22h]
    push word ptr [bp-24h]
    call mf327
lbl37Eb:
    add sp,4h
    mov word ptr [bp-0Ch],1h
    cmp word ptr [bp-20h],0h
    jnz short lbl38Ff
    jmp near ptr lbl835f
lbl38Ff:
    les bx, dword ptr [bp-24h]
    mov al,byte ptr es:[bx+8h]
    cbw
    add ax, offset mi336
    imul word ptr ds:[320Eh]
    mov cx,word ptr ds:[320Eh]
    shr cx,1
    add ax,cx
    push ax
    mov al,byte ptr es:[bx+7h]
    cbw
    add ax, offset mi344
    imul word ptr ds:[320Ch]
    mov cx,word ptr ds:[320Ch]
    shr cx,1
    add ax,cx
    push ax
    call mf350
    add sp,4h
    jmp near ptr lbl835f
    nop
lbl3C8f:
    xor ax,ax
    push ax
    push word ptr [bp-22h]
    push word ptr [bp-24h]
    call mf358
    add sp,6h
    jmp near ptr lbl835f
lbl3DCf:
    mov ax,word ptr [bp-22h]
    or ax,word ptr [bp-24h]
    jnz short lbl3E7f
    jmp near ptr lbl835f
lbl3E7f:
    mov ax,word ptr [bp-12h]
    sub ax,148h
    jz short lbl400f
    sub ax, offset mi368
    jz short lbl40Af
    dec ax
    dec ax
    jz short lbl414f
    sub ax, offset mi373
    jz short lbl41Ef
    jmp short lbl425f
    nop
lbl400f:
    les bx, dword ptr [bp-24h]
    dec byte ptr es:[bx+8h]
    jmp short lbl425f
    nop
lbl40Af:
    les bx, dword ptr [bp-24h]
    dec byte ptr es:[bx+7h]
    jmp short lbl425f
    nop
lbl414f:
    les bx, dword ptr [bp-24h]
    inc byte ptr es:[bx+7h]
    jmp short lbl425f
    nop
lbl41Ef:
    les bx, dword ptr [bp-24h]
    inc byte ptr es:[bx+8h]
lbl425f:
    push word ptr [bp-22h]
    push word ptr [bp-24h]
    call mf393
    add sp,4h
    or ax,ax
    jz short lbl478f
    mov ax,word ptr [bp-12h]
    sub ax,148h
    jz short lbl450f
    sub ax, offset mi400
    jz short lbl45Af
    dec ax
    dec ax
    jz short lbl464f
    sub ax, offset mi405
    jz short lbl46Ef
    jmp near ptr lbl835f
lbl450f:
    les bx, dword ptr [bp-24h]
    inc byte ptr es:[bx+8h]
    jmp near ptr lbl835f
lbl45Af:
    les bx, dword ptr [bp-24h]
    inc byte ptr es:[bx+7h]
    jmp near ptr lbl835f
lbl464f:
    les bx, dword ptr [bp-24h]
    dec byte ptr es:[bx+7h]
    jmp near ptr lbl835f
lbl46Ef:
    les bx, dword ptr [bp-24h]
    dec byte ptr es:[bx+8h]
    jmp near ptr lbl835f
lbl478f:
    lea ax,word ptr [bp-38h]
    push ss
    push ax
    call mf423
    jmp near ptr lbl37Eb
    nop
lbl486f:
    mov ax,word ptr [bp-22h]
    or ax,word ptr [bp-24h]
    jz short lbl4F8f
    push word ptr [bp-22h]
    push word ptr [bp-24h]
    call mf431
    add sp,4h
    or ax,ax
    jz short lbl4A8f
    call mf435
    jmp near ptr lbl130b
lbl4A8f:
    mov ax,1h
    push ax
    push word ptr [bp-22h]
    push word ptr [bp-24h]
    call mf441
    add sp,6h
    cmp word ptr [bp-20h],0h
    jz short lbl4C5f
    call mf445
lbl4C5f:
    mov word ptr [bp-2h],1h
    mov word ptr [bp-46h],46EAh
lbl4CFb:
    mov es, ds:[5AE4h]
    mov bx,word ptr [bp-46h]
    cmp byte ptr es:[bx],0h
    jz short lbl4EAf
    add word ptr [bp-46h],9h
    cmp word ptr [bp-46h],4756h
    jc short lbl4CFb
    jmp short lbl4EFf
    nop
lbl4EAf:
    mov word ptr [bp-2h],0h
lbl4EFf:
    cmp word ptr [bp-2h],0h
    jz short lbl4F8f
    jmp near ptr lbl938f
lbl4F8f:
    cmp word ptr [bp-12h],2Bh
    jz short lbl51Cf
    cmp word ptr [bp-12h],3Dh
    jz short lbl51Cf
    cmp word ptr [bp-12h],9h
    jz short lbl51Cf
    cmp word ptr [bp-0Ah],0h
    jl short lbl52Bf
    dec word ptr [bp-0Ah]
    jns short lbl530f
    mov word ptr [bp-0Ah],0Bh
    jmp short lbl530f
lbl51Cf:
    cmp word ptr [bp-0Ah],0h
    jl short lbl52Bf
    inc word ptr [bp-0Ah]
    cmp word ptr [bp-0Ah],0Bh
    jng short lbl530f
lbl52Bf:
    mov word ptr [bp-0Ah],0h
lbl530f:
    mov ax,word ptr [bp-0Ah]
    mov cx,ax
    add ax,ax
    add ax,ax
    add ax,ax
    add ax,cx
    add ax,46E4h
    mov cx,3420h
    mov word ptr [bp-24h],ax
    mov word ptr [bp-22h],cx
    push cx
    push ax
    call mf491
    add sp,4h
    mov word ptr [bp-0Ch],1h
    mov word ptr [bp-20h],0h
    jmp near ptr lbl835f
lbl560f:
    lea ax,word ptr [bp-18h]
    push ss
    push ax
    lea ax,word ptr [bp-16h]
    push ss
    push ax
    call mf502
    add sp,8h
    mov word ptr [bp-14h],ax
    or ax,ax
    jz short lbl582f
    push ax
    call mf508
    add sp,2h
lbl582f:
    mov ax,word ptr [bp-18h]
    sub dx,dx
    div word ptr ds:[320Eh]
    mov word ptr [bp-6h],ax
    mov ax,word ptr [bp-16h]
    sub dx,dx
    div word ptr ds:[320Ch]
    mov word ptr [bp-8h],ax
    mov ax,word ptr [bp-22h]
    or ax,word ptr [bp-24h]
    jnz short lbl5A5f
    jmp near ptr lbl71Cf
lbl5A5f:
    cmp word ptr [bp-20h],0h
    jnz short lbl5AEf
    jmp near ptr lbl71Cf
lbl5AEf:
    mov ax,word ptr [bp-6h]
    cmp word ptr [bp-0Eh],ax
    jnz short lbl5BEf
    mov ax,word ptr [bp-8h]
    cmp word ptr [bp-10h],ax
    jz short lbl612f
lbl5BEf:
    mov al,byte ptr [bp-8h]
    sub al,2h
    les bx, dword ptr [bp-24h]
    mov byte ptr es:[bx+7h],al
    mov al,byte ptr [bp-6h]
    sub al,2h
    mov byte ptr es:[bx+8h],al
    push es
    push bx
    call mf540
    add sp,4h
    les bx, dword ptr [bp-24h]
    mov al,byte ptr es:[bx+7h]
    cbw
    add ax, offset mi545
    mov word ptr [bp-8h],ax
    mov al,byte ptr es:[bx+8h]
    cbw
    sub ax,word ptr [bp-0Eh]
    cmp ax, offset mi550
    jnz short lbl600f
    mov ax,word ptr [bp-8h]
    cmp word ptr [bp-10h],ax
    jz short lbl612f
lbl600f:
    lea ax,word ptr [bp-38h]
    push ss
    push ax
    call mf558
    add sp,4h
    mov word ptr [bp-0Ch],1h
lbl612f:
    mov al,byte ptr [bp-14h]
    and al,3h
    cmp al,1h
    jnz short lbl68Af
    push word ptr [bp-22h]
    push word ptr [bp-24h]
    call mf567
    add sp,4h
    or ax,ax
    jz short lbl630f
    jmp near ptr lbl226b
lbl630f:
    mov ax,1h
    push ax
    push word ptr [bp-22h]
    push word ptr [bp-24h]
    call mf576
    add sp,6h
    lea ax,word ptr [bp-38h]
    push ss
    push ax
    call mf581
    add sp,4h
    sub ax,ax
    mov word ptr [bp-22h],ax
    mov word ptr [bp-24h],ax
    call mf586
    mov word ptr [bp-20h],0h
    mov word ptr [bp-2h],1h
    mov word ptr [bp-48h],46EAh
lbl66Bb:
    mov es, ds:[5AE4h]
    mov bx,word ptr [bp-48h]
    cmp byte ptr es:[bx],0h
    jnz short lbl67Bf
    jmp near ptr lbl284b
lbl67Bf:
    add word ptr [bp-48h],9h
    cmp word ptr [bp-48h],4756h
    jc short lbl66Bb
    jmp near ptr lbl289b
    nop
lbl68Af:
    cmp word ptr [bp-14h],0h
    jnz short lbl693f
    jmp near ptr lbl835f
lbl693f:
    lea ax,word ptr [bp-38h]
    push ss
    push ax
    call mf606
    add sp,4h
    mov al,byte ptr [bp-14h]
    and al,3h
    cmp al,2h
    jnz short lbl6B6f
    push word ptr [bp-22h]
    push word ptr [bp-24h]
    call mf614
    jmp short lbl6C1f
lbl6B6f:
    push word ptr [bp-22h]
    push word ptr [bp-24h]
    call mf618
lbl6C1f:
    add sp,4h
    push word ptr [bp-22h]
    push word ptr [bp-24h]
    call mf622
    add sp,4h
    or ax,ax
    jnz short lbl6D9f
    jmp near ptr lbl2CBb
lbl6D9f:
    push word ptr [bp-22h]
    push word ptr [bp-24h]
    call mf629
    add sp,4h
    les bx, dword ptr [bp-24h]
    mov al,byte ptr es:[bx+8h]
    cbw
    add ax, offset mi634
    imul word ptr ds:[320Eh]
    mov cx,word ptr ds:[320Eh]
    shr cx,1
    add ax,cx
    push ax
    mov al,byte ptr es:[bx+7h]
    cbw
    add ax, offset mi642
    imul word ptr ds:[320Ch]
    mov cx,word ptr ds:[320Ch]
    shr cx,1
    add ax,cx
    push ax
    call mf648
    jmp near ptr lbl2C8b
lbl71Cf:
    cmp word ptr [bp-14h],0h
    jnz short lbl725f
    jmp near ptr lbl835f
lbl725f:
    lea ax,word ptr [bp-1Eh]
    push ss
    push ax
    lea ax,word ptr [bp-1Ch]
    push ss
    push ax
    lea ax,word ptr [bp-1Ah]
    push ss
    push ax
    push word ptr [bp-18h]
    push word ptr [bp-16h]
    call mf664
    add sp,10h
    or ax,ax
    jz short lbl76Cf
    cmp word ptr [bp-1Eh],5h
    jnz short lbl76Cf
    push word ptr [bp-1Ch]
    xor ax,ax
    push ax
    call mf673
    add sp,4h
    cmp word ptr [bp-1Ch],1h
    jz short lbl763f
    jmp near ptr lbl93Df
lbl763f:
    call mf678
    jmp near ptr lbl835f
    nop
lbl76Cf:
    mov ax,17h
    imul word ptr [bp-6h]
    mov bx,ax
    add bx,word ptr [bp-8h]
    add bx,4750h
    mov es, ds:[5ADEh]
    mov word ptr [bp-4Eh],bx
    mov word ptr [bp-4Ch],es
    test byte ptr es:[bx],0Fh
    jnz short lbl78Ef
    jmp near ptr lbl835f
lbl78Ef:
    mov ax,word ptr [bp-22h]
    or ax,word ptr [bp-24h]
    jz short lbl7FAf
    push word ptr [bp-22h]
    push word ptr [bp-24h]
    call mf697
    add sp,4h
    or ax,ax
    jz short lbl7B6f
    call mf701
    call mf702
    jmp near ptr lbl130b
    nop
lbl7B6f:
    mov ax,1h
    push ax
    push word ptr [bp-22h]
    push word ptr [bp-24h]
    call mf709
    add sp,6h
    mov word ptr [bp-2h],1h
    mov word ptr [bp-4Ah],46EAh
lbl7D2b:
    mov es, ds:[5AE4h]
    mov bx,word ptr [bp-4Ah]
    cmp byte ptr es:[bx],0h
    jz short lbl7ECf
    add word ptr [bp-4Ah],9h
    cmp word ptr [bp-4Ah],4756h
    jc short lbl7D2b
    jmp short lbl7F1f
lbl7ECf:
    mov word ptr [bp-2h],0h
lbl7F1f:
    cmp word ptr [bp-2h],0h
    jz short lbl7FAf
    jmp near ptr lbl938f
lbl7FAf:
    call mf725
    les bx, dword ptr [bp-4Eh]
    mov al,byte ptr es:[bx]
    and ax, offset mi728
    dec ax
    mov word ptr [bp-0Ah],ax
    mov cx,ax
    add ax,ax
    add ax,ax
    add ax,ax
    add ax,cx
    add ax,46E4h
    mov cx,3420h
    mov word ptr [bp-24h],ax
    mov word ptr [bp-22h],cx
    push cx
    push ax
    call mf742
    add sp,4h
    mov ax,1h
    mov word ptr [bp-0Ch],ax
    mov word ptr [bp-20h],ax
lbl835f:
    cmp word ptr [bp-0Ch],0h
    jnz short lbl83Ef
    jmp near ptr lbl922f
lbl83Ef:
    les bx, dword ptr [bp-24h]
    mov al,byte ptr es:[bx+7h]
    cbw
    imul word ptr ds:[320Ch]
    mov word ptr [bp-3Ah],ax
    or ax,ax
    jl short lbl85Cf
    cmp ax,13Fh
    jng short lbl85Ef
    mov ax,13Fh
    jmp short lbl85Ef
    nop
lbl85Cf:
    xor ax,ax
lbl85Ef:
    mov word ptr [bp-3Ah],ax
    mov ax,word ptr ds:[320Ch]
    mov cx,ax
    add ax,ax
    add ax,ax
    add ax,cx
    add ax,word ptr [bp-3Ah]
    dec ax
    mov word ptr [bp-3Eh],ax
    or ax,ax
    jl short lbl882f
    cmp ax,13Fh
    jng short lbl884f
    mov ax,13Fh
    jmp short lbl884f
    nop
lbl882f:
    xor ax,ax
lbl884f:
    mov word ptr [bp-3Eh],ax
    mov al,byte ptr es:[bx+8h]
    cbw
    imul word ptr ds:[320Eh]
    mov word ptr [bp-3Ch],ax
    or ax,ax
    jl short lbl8A2f
    cmp ax,0C7h
    jng short lbl8A4f
    mov ax,0C7h
    jmp short lbl8A4f
    nop
lbl8A2f:
    xor ax,ax
lbl8A4f:
    mov word ptr [bp-3Ch],ax
    mov ax,word ptr ds:[320Eh]
    mov cx,ax
    add ax,ax
    add ax,ax
    add ax,cx
    add ax,word ptr [bp-3Ch]
    dec ax
    mov word ptr [bp-40h],ax
    or ax,ax
    jl short lbl8C8f
    cmp ax,0C7h
    jng short lbl8CAf
    mov ax,0C7h
    jmp short lbl8CAf
    nop
lbl8C8f:
    xor ax,ax
lbl8CAf:
    mov word ptr [bp-40h],ax
    lea ax,word ptr [bp-38h]
    push ss
    push ax
    call mf814
    add sp,4h
    push word ptr [bp-40h]
    push word ptr [bp-3Eh]
    push word ptr [bp-3Ch]
    push word ptr [bp-3Ah]
    lea ax,word ptr [bp-38h]
    push ss
    push ax
    call mf823
    add sp,0Ch
    xor ax,ax
    push ax
    push word ptr [bp-22h]
    push word ptr [bp-24h]
    call mf829
    add sp,6h
    les bx, dword ptr [bp-24h]
    mov al,byte ptr es:[bx+8h]
    cbw
    add ax, offset mi834
    mov word ptr [bp-0Eh],ax
    mov al,byte ptr es:[bx+7h]
    cbw
    add ax, offset mi838
    mov word ptr [bp-10h],ax
    mov word ptr [bp-0Ch],0h
lbl922f:
    cmp word ptr [bp-14h],0h
    jnz short lbl92Bf
    jmp near ptr lbl130b
lbl92Bf:
    call mf844
    mov word ptr [bp-14h],0h
    jmp near ptr lbl130b
lbl938f:
    call mf847
lbl93Df:
    mov ax,1h
    push ax
    xor ax,ax
    push ax
    call mf852
    add sp,4h
    cmp word ptr [bp-2h],0h
    jnz short lbl955f
    jmp near ptr lbl7Cb
lbl955f:
    cmp byte ptr [bp-38h],0h
    jz short lbl968f
    lea ax,word ptr [bp-38h]
    push ss
    push ax
    call mf862
    add sp,4h
lbl968f:
    call mf864
    mov ax,1h
    push ax
    call mf867
    add sp,2h
    call mf869
    mov ax,1Fh
    push ax
    call mf872
    add sp,2h
    mov ax,10h
    push ax
    call mf876
    add sp,2h
    mov ax,word ptr [bp-2h]
    pop si
    pop di
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
