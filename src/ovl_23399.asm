_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf47:FAR
    EXTRN mf55:FAR
    EXTRN mi58:NEAR
    EXTRN mi61:NEAR
    EXTRN mi64:NEAR
    EXTRN mi67:NEAR
    EXTRN mf71:FAR
    EXTRN mf75:FAR
    EXTRN mf79:FAR
    EXTRN mi83:NEAR
    EXTRN mi85:NEAR
    EXTRN mi88:NEAR
    EXTRN mi90:NEAR
    EXTRN mi93:NEAR
    EXTRN mi97:NEAR
    EXTRN mi98:NEAR
    EXTRN mf104:FAR
    EXTRN mf109:FAR
    EXTRN mf111:FAR
    EXTRN mi117:NEAR
    EXTRN mi120:NEAR
    EXTRN mf124:FAR
    EXTRN mf127:FAR
    EXTRN mf135:FAR
    EXTRN mf217:FAR
    EXTRN mf238:FAR
    EXTRN mf284:FAR
    EXTRN mi289:NEAR
    EXTRN mf296:FAR
    EXTRN mi298:NEAR
    EXTRN mi301:NEAR
    EXTRN mf304:FAR
    EXTRN mi306:NEAR
    EXTRN mf309:FAR
    EXTRN mf312:FAR
    EXTRN mi315:NEAR
    EXTRN mf322:FAR
    EXTRN mi324:NEAR
    EXTRN mi327:NEAR
    EXTRN mf330:FAR
    EXTRN mi332:NEAR
    EXTRN mf350:FAR
    EXTRN mi354:NEAR
    EXTRN mi355:NEAR
    EXTRN mi358:NEAR
    EXTRN mi359:NEAR
    EXTRN mi362:NEAR
    EXTRN mi366:NEAR
    EXTRN mi367:NEAR
    EXTRN mf378:FAR
    EXTRN mf393:FAR
    EXTRN mf457:FAR
    EXTRN mf483:FAR
    EXTRN mf525:FAR
    EXTRN mf548:FAR
    EXTRN mf548:FAR
    EXTRN mf548:FAR
    EXTRN mf548:FAR
    EXTRN mf548:FAR
    EXTRN mf548:FAR
    EXTRN mf548:FAR
    EXTRN mf548:FAR
    EXTRN mf548:FAR
    EXTRN mf548:FAR
    EXTRN mf548:FAR
    EXTRN mf548:FAR
    EXTRN mf548:FAR
    EXTRN mf548:FAR
    EXTRN mf548:FAR
    EXTRN mf548:FAR
    EXTRN mf548:FAR
    EXTRN mf548:FAR
    EXTRN mf548:FAR
    EXTRN mf548:FAR
    EXTRN mf548:FAR
    EXTRN mf548:FAR
    EXTRN mf548:FAR
    EXTRN mf548:FAR
    EXTRN mf548:FAR
    EXTRN mf548:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,3Ch
    push di
    push si
    mov ax,word ptr [bp+6h]
    mov word ptr [bp-12h],ax
    xor cx,cx
    mov word ptr ds:[5D9Ch],cx
    mov word ptr [bp-0Ah],cx
    mov word ptr [bp-18h],cx
    cmp ax,cx
    jnz short lbl21f
    jmp near ptr lbl62Df
lbl21b:
lbl21f:
    cmp word ptr [bp-18h],0h
    jnz short lbl97f
    mov word ptr [bp-2h],0h
    cmp word ptr ds:[108h],0h
    jz short lbl97f
    mov word ptr [bp-2Ah],0h
lbl38b:
    mov ax,word ptr [bp-12h]
    mov es, ds:[5A7Ah]
    mov bx,word ptr [bp-2Ah]
    cmp word ptr es:[bx],ax
    jz short lbl58f
    add word ptr [bp-2Ah],2h
    mov ax,word ptr ds:[108h]
    inc word ptr [bp-2h]
    cmp word ptr [bp-2h],ax
    jc short lbl38b
    jmp short lbl97f
lbl58f:
    cmp word ptr ds:[1924h],0h
    jz short lbl7Cf
    mov es, ds:[5A80h]
    mov bx,word ptr ds:[1924h]
    mov ax,bx
    add bx,bx
    add bx,ax
    add bx,bx
    add bx,bx
    mov ax,word ptr es:[bx+0F4h]
    mov word ptr [bp-28h],ax
    jmp short lbl81f
    nop
lbl7Cf:
    mov word ptr [bp-28h],0h
lbl81f:
    push word ptr [bp-28h]
    push word ptr [bp-12h]
    call mf47
    add sp,4h
    mov word ptr [bp-0Ah],ax
    mov word ptr [bp-18h],1h
lbl97f:
    cmp word ptr ds:[5D9Ch],0h
    jnz short lblD2f
    mov ax,10h
    push ax
    call mf55
    add sp,2h
    mov ax,word ptr [bp+0Ah]
    add ax, offset mi58
    push ax
    mov ax,word ptr [bp+8h]
    add ax, offset mi61
    push ax
    mov ax,word ptr [bp+0Ah]
    sub ax, offset mi64
    push ax
    mov ax,word ptr [bp+8h]
    sub ax, offset mi67
    push ax
    mov ax,1h
    push ax
    call mf71
    add sp,0Ah
lblD2f:
    cmp word ptr [bp-18h],0h
    jz short lblE0f
    call mf75
    jmp short lblEBf
    nop
lblE0f:
    push word ptr [bp-12h]
    call mf79
    add sp,2h
lblEBf:
    mov word ptr [bp-16h],ax
    mov ax,word ptr [bp+8h]
    sub ax, offset mi83
    mov word ptr [bp-32h],ax
    cmp ax, offset mi85
    jl short lbl16Af
    mov ax,word ptr [bp+0Ah]
    sub ax, offset mi88
    mov word ptr [bp-34h],ax
    cmp ax, offset mi90
    jl short lbl16Af
    mov ax,word ptr [bp+8h]
    add ax, offset mi93
    cmp ax,13Ah
    jg short lbl16Af
    mov ax,word ptr [bp+0Ah]
    add ax, offset mi97
    cmp ax, offset mi98
    jg short lbl16Af
    cmp word ptr [bp-16h],0h
    jng short lbl14Af
    push word ptr [bp-34h]
    push word ptr [bp-32h]
    call mf104
    add sp,4h
    xor ax,ax
    push ax
    push word ptr [bp-16h]
    call mf109
    add sp,4h
    call mf111
    jmp short lbl16Af
    nop
lbl14Af:
    mov ax,4h
    push ax
    mov ax,word ptr [bp+0Ah]
    add ax, offset mi117
    push ax
    mov ax,word ptr [bp+8h]
    add ax, offset mi120
    push ax
    push word ptr [bp-34h]
    push word ptr [bp-32h]
    call mf124
    add sp,0Ah
lbl16Af:
    push word ptr [bp-12h]
    call mf127
    add sp,2h
    mov word ptr [bp-6h],ax
    or ax,ax
    jnz short lbl17Ff
    jmp near ptr lbl62Df
lbl17Ff:
    dec word ptr [bp-6h]
    push word ptr [bp-12h]
    call mf135
    add sp,2h
    mov word ptr [bp-4h],ax
    or ax,ax
    jnz short lbl197f
    jmp near ptr lbl624f
lbl197b:
lbl197f:
    mov es, ds:[5A7Ch]
    mov bx,word ptr [bp-6h]
    add bx,bx
    add bx,bx
    mov word ptr [bp-36h],bx
    mov al,byte ptr es:[bx+10FAh]
    mov byte ptr [bp-1Ch],al
    xor ax,ax
    mov word ptr [bp-10h],ax
    mov word ptr [bp-0Eh],ax
    mov word ptr [bp-2h],ax
    mov word ptr [bp-2Ch],400h
lbl1BDb:
    mov al,byte ptr [bp-1Ch]
    mov es, ds:[5A82h]
    mov bx,word ptr [bp-2Ch]
    cmp byte ptr es:[bx],al
    jz short lbl1DCf
    inc word ptr [bp-2h]
    add word ptr [bp-2Ch],3h
    cmp word ptr [bp-2Ch],418h
    jc short lbl1BDb
    jmp short lbl1F7f
lbl1DCf:
    mov bx,word ptr [bp-2h]
    mov ax,bx
    add bx,bx
    add bx,ax
    mov al,byte ptr es:[bx+401h]
    cbw
    mov word ptr [bp-0Eh],ax
    mov al,byte ptr es:[bx+402h]
    cbw
    mov word ptr [bp-10h],ax
lbl1F7f:
    mov bx,word ptr [bp-36h]
    mov es, ds:[5A7Ch]
    mov ax,word ptr es:[bx+10FCh]
    mov word ptr [bp-8h],ax
    xor ax,ax
    mov word ptr [bp-14h],ax
    mov word ptr [bp-0Ch],ax
    xor cl,cl
    mov byte ptr [bp-19h],cl
    mov byte ptr [bp-1Ah],cl
    mov cx,4h
    push es
    lea di,word ptr [bp-26h]
    push ss
    pop es
    rep stosw
    pop es
    mov al,byte ptr es:[bx+10FBh]
    dec ax
    jz short lbl234f
    dec ax
    jz short lbl23Cf
    dec ax
    dec ax
    jz short lbl24Ef
    jmp short lbl2AEf
    nop
lbl234f:
    mov ax,word ptr [bp-8h]
lbl237b:
    mov word ptr [bp-14h],ax
    jmp short lbl2AEf
lbl23Cf:
    mov es, ds:[5A7Eh]
    mov bx,word ptr [bp-8h]
    add bx,bx
    add bx,bx
    mov ax,word ptr es:[bx+84Eh]
    jmp short lbl237b
lbl24Ef:
    cmp word ptr [bp-18h],0h
    jz short lbl28Af
    lea ax,word ptr [bp-26h]
    push ss
    push ax
    mov cl,byte ptr [bp-1Ch]
    sub ch,ch
    push cx
    call mf217
    add sp,6h
    mov word ptr [bp-14h],ax
    mov ax,word ptr [bp-20h]
    mov word ptr [bp-0Ch],ax
    cmp word ptr [bp-26h],0h
    jnz short lbl27Cf
    cmp word ptr [bp-24h],0h
    jz short lbl2AEf
lbl27Cf:
    mov al,byte ptr [bp-26h]
    mov byte ptr [bp-1Ah],al
    mov al,byte ptr [bp-24h]
    mov byte ptr [bp-19h],al
    jmp short lbl2AEf
lbl28Af:
    mov al,byte ptr ds:[6E5Ch]
    mov byte ptr [bp-1Eh],al
    mov al,byte ptr [bp-1Ch]
    mov byte ptr ds:[6E5Ch],al
    mov ax,1h
    push ax
    push word ptr [bp-8h]
    call mf238
    add sp,4h
    mov word ptr [bp-14h],ax
    mov al,byte ptr [bp-1Eh]
    mov byte ptr ds:[6E5Ch],al
lbl2AEf:
    cmp word ptr [bp-18h],0h
    jz short lbl2C7f
    cmp word ptr [bp-14h],0h
    jz short lbl2C7f
    mov ax,word ptr [bp-12h]
    cmp word ptr [bp-14h],ax
    jz short lbl2C7f
    mov word ptr [bp-18h],0h
lbl2C7f:
    mov word ptr [bp-2h],0h
    cmp word ptr ds:[1924h],0h
    jz short lbl305f
    mov word ptr [bp-2Eh],100h
lbl2D8b:
    mov ax,word ptr [bp-14h]
    mov es, ds:[5A80h]
    mov bx,word ptr [bp-2Eh]
    cmp word ptr es:[bx],ax
    jnz short lbl2F6f
    cmp word ptr [bp-18h],0h
    jz short lbl305f
    mov ax,word ptr [bp-0Ch]
    cmp word ptr es:[bx+2h],ax
    jz short lbl305f
lbl2F6f:
    add word ptr [bp-2Eh],0Ch
    mov ax,word ptr ds:[1924h]
    inc word ptr [bp-2h]
    cmp word ptr [bp-2h],ax
    jc short lbl2D8b
lbl305f:
    mov ax,word ptr ds:[1924h]
    cmp word ptr [bp-2h],ax
    jnc short lbl310f
    jmp near ptr lbl468f
lbl310f:
    cmp word ptr [bp-14h],0h
    jnz short lbl319f
    jmp near ptr lbl3BAf
lbl319f:
    cmp byte ptr [bp-1Ch],9h
    jz short lbl328f
    cmp byte ptr [bp-1Ch],0Ah
    jz short lbl328f
    jmp near ptr lbl3BAf
lbl328f:
    mov ax,0Fh
    push ax
    call mf284
    add sp,2h
    cmp byte ptr [bp-1Ch],9h
    jnz short lbl380f
    mov ax,word ptr [bp+8h]
    add ax, offset mi289
    push ax
    mov cx,word ptr [bp+0Ah]
    sub cx,8h
    push cx
    mov si,ax
    mov di,cx
    call mf296
    mov ax,word ptr [bp+8h]
    add ax, offset mi298
    push ax
    mov ax,word ptr [bp+0Ah]
    sub ax, offset mi301
    push ax
    mov word ptr [bp-38h],ax
    call mf304
    mov ax,word ptr [bp+8h]
    add ax, offset mi306
    push ax
    push word ptr [bp-38h]
lbl371b:
    call mf309
    push si
    push di
    call mf312
    jmp near ptr lbl468f
lbl380f:
    mov ax,word ptr [bp+8h]
    sub ax, offset mi315
    push ax
    mov cx,word ptr [bp+0Ah]
    add cx,7h
    push cx
    mov si,ax
    mov di,cx
    call mf322
    mov ax,word ptr [bp+8h]
    sub ax, offset mi324
    push ax
    mov ax,word ptr [bp+0Ah]
    add ax, offset mi327
    push ax
    mov word ptr [bp-3Ah],ax
    call mf330
    mov ax,word ptr [bp+8h]
    sub ax, offset mi332
    push ax
    push word ptr [bp-3Ah]
    jmp short lbl371b
    nop
lbl3BAf:
    cmp word ptr [bp-14h],0h
    jg short lbl3C3f
    jmp near ptr lbl468f
lbl3C3f:
    mov ax,word ptr ds:[84Ch]
    cmp word ptr [bp-14h],ax
    jng short lbl3CEf
    jmp near ptr lbl468f
lbl3CEf:
    cmp byte ptr [bp-1Ah],0h
    jnz short lbl3EBf
    cmp byte ptr [bp-19h],0h
    jnz short lbl3EBf
    push word ptr [bp-14h]
    push word ptr [bp-12h]
    call mf350
    add sp,4h
    mov word ptr [bp-1Ah],ax
lbl3EBf:
    mov ax,word ptr [bp+8h]
    sub ax, offset mi354
    cmp ax, offset mi355
    jl short lbl435f
    mov ax,word ptr [bp+0Ah]
    sub ax, offset mi358
    cmp ax, offset mi359
    jl short lbl435f
    mov ax,word ptr [bp+8h]
    add ax, offset mi362
    cmp ax,13Ah
    jg short lbl435f
    mov ax,word ptr [bp+0Ah]
    add ax, offset mi366
    cmp ax, offset mi367
    jg short lbl435f
    mov al,byte ptr [bp-19h]
    sub ah,ah
    push ax
    mov al,byte ptr [bp-1Ah]
    push ax
    push word ptr [bp-10h]
    push word ptr [bp-0Eh]
    push word ptr [bp+0Ah]
    push word ptr [bp+8h]
    call mf378
    add sp,0Ch
lbl435f:
    cmp word ptr [bp-18h],0h
    jz short lbl444f
    cmp word ptr [bp-22h],0h
    jz short lbl444f
    jmp near ptr lbl59Af
lbl444f:
    cmp word ptr [bp-18h],0h
    jnz short lbl468f
    mov ax,word ptr [bp-12h]
    cmp word ptr [bp-14h],ax
    jz short lbl468f
    mov ax,5h
    push ax
    push word ptr [bp-14h]
    call mf393
    add sp,4h
    or ax,ax
    jz short lbl468f
    jmp near ptr lbl59Af
lbl468f:
    cmp word ptr [bp-4h],1h
    jz short lbl471f
    jmp near ptr lbl58Bf
lbl471b:
lbl471f:
    cmp word ptr ds:[1924h],0h
    jnz short lbl47Bf
    jmp near ptr lbl586f
lbl47Bf:
    dec word ptr ds:[1924h]
    cmp word ptr [bp-18h],0h
    jz short lbl4AAf
    mov ax,word ptr [bp-12h]
    mov es, ds:[5A80h]
    mov bx,word ptr ds:[1924h]
    mov cx,bx
    add bx,bx
    add bx,cx
    add bx,bx
    add bx,bx
    cmp word ptr es:[bx+100h],ax
    jz short lbl4AAf
    mov word ptr [bp-18h],0h
    jmp short lbl523f
    nop
    nop
lbl4AAf:
    cmp word ptr [bp-18h],0h
    jnz short lbl523f
    mov word ptr [bp-2h],0h
    cmp word ptr ds:[108h],0h
    jz short lbl523f
    mov word ptr [bp-30h],0h
    mov es, ds:[5A80h]
    mov bx,word ptr ds:[1924h]
    mov ax,bx
    add bx,bx
    add bx,ax
    add bx,bx
    add bx,bx
    mov ax,word ptr es:[bx+100h]
    mov word ptr [bp-3Ch],ax
lbl4DBb:
    mov bx,word ptr [bp-30h]
    mov es, ds:[5A7Ah]
    mov ax,word ptr es:[bx]
    cmp word ptr [bp-3Ch],ax
    jz short lbl4FCf
    add word ptr [bp-30h],2h
    mov ax,word ptr ds:[108h]
    inc word ptr [bp-2h]
    cmp word ptr [bp-2h],ax
    jc short lbl4DBb
    jmp short lbl523f
    nop
lbl4FCf:
    push word ptr [bp-12h]
    mov es, ds:[5A80h]
    mov bx,word ptr ds:[1924h]
    mov ax,bx
    add bx,bx
    add bx,ax
    add bx,bx
    add bx,bx
    push word ptr es:[bx+100h]
    call mf457
    add sp,4h
    mov word ptr [bp-18h],1h
lbl523f:
    mov es, ds:[5A80h]
    mov bx,word ptr ds:[1924h]
    mov ax,bx
    add bx,bx
    add bx,ax
    add bx,bx
    add bx,bx
    mov ax,word ptr es:[bx+100h]
    mov word ptr [bp-12h],ax
    mov ax,word ptr es:[bx+102h]
    mov word ptr [bp-0Ah],ax
    mov ax,word ptr es:[bx+104h]
    mov word ptr [bp+8h],ax
    mov ax,word ptr es:[bx+106h]
    mov word ptr [bp+0Ah],ax
    mov ax,word ptr es:[bx+108h]
    mov word ptr [bp-4h],ax
    mov ax,word ptr es:[bx+10Ah]
    mov word ptr [bp-6h],ax
    dec word ptr ds:[5D9Ch]
    cmp word ptr [bp-18h],0h
    jz short lbl57Af
    push word ptr [bp-0Ah]
    call mf483
    add sp,2h
lbl57Af:
    cmp word ptr [bp-4h],1h
    jnz short lbl583f
    jmp near ptr lbl471b
lbl583f:
    jmp short lbl58Bf
    nop
lbl586f:
    mov word ptr [bp-12h],0h
lbl58Bf:
    inc word ptr [bp-6h]
    dec word ptr [bp-4h]
    jz short lbl596f
    jmp near ptr lbl197b
lbl596f:
    jmp near ptr lbl624f
    nop
lbl59Af:
    mov ax,word ptr [bp-12h]
    mov es, ds:[5A80h]
    mov bx,word ptr ds:[1924h]
    mov cx,bx
    add bx,bx
    add bx,cx
    add bx,bx
    add bx,bx
    mov word ptr es:[bx+100h],ax
    mov ax,word ptr [bp-0Ah]
    mov word ptr es:[bx+102h],ax
    mov ax,word ptr [bp+8h]
    mov word ptr es:[bx+104h],ax
    mov ax,word ptr [bp+0Ah]
    mov word ptr es:[bx+106h],ax
    mov ax,word ptr [bp-4h]
    mov word ptr es:[bx+108h],ax
    mov ax,word ptr [bp-6h]
    mov word ptr es:[bx+10Ah],ax
    inc word ptr ds:[1924h]
    inc word ptr ds:[5D9Ch]
    cmp word ptr [bp-18h],0h
    jz short lbl5FEf
    mov ax,word ptr [bp-0Ch]
    mov word ptr [bp-0Ah],ax
    mov al,byte ptr [bp-1Ch]
    sub ah,ah
    push ax
    call mf525
    add sp,2h
lbl5FEf:
    mov ax,word ptr [bp-14h]
    mov word ptr [bp-12h],ax
    mov al,byte ptr [bp-1Ah]
    sub ah,ah
    imul word ptr [bp-0Eh]
    mov cx,1Eh
    imul cx
    add word ptr [bp+8h],ax
    mov al,byte ptr [bp-19h]
    sub ah,ah
    imul word ptr [bp-10h]
    mov cx,19h
    imul cx
    add word ptr [bp+0Ah],ax
lbl624f:
    cmp word ptr [bp-12h],0h
    jz short lbl62Df
    jmp near ptr lbl21b
lbl62Df:
    pop si
    pop di
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
