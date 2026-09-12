_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf9:FAR
    EXTRN mf15:FAR
    EXTRN mf17:FAR
    EXTRN mf20:FAR
    EXTRN mf26:FAR
    EXTRN mf31:FAR
    EXTRN mf35:FAR
    EXTRN mf44:FAR
    EXTRN mf50:FAR
    EXTRN mf62:FAR
    EXTRN mf74:FAR
    EXTRN mf91:FAR
    EXTRN mf107:FAR
    EXTRN mf113:FAR
    EXTRN mf122:FAR
    EXTRN mf135:FAR
    EXTRN mf168:FAR
    EXTRN mf169:FAR
    EXTRN mf179:FAR
    EXTRN mf190:FAR
    EXTRN mf201:FAR
    EXTRN mf212:FAR
    EXTRN mf223:FAR
    EXTRN mf255:FAR
    EXTRN mf302:FAR
    EXTRN mf310:FAR
    EXTRN mf315:FAR
    EXTRN mi317:NEAR
    EXTRN mi323:NEAR
    EXTRN mi329:NEAR
    EXTRN mi335:NEAR
    EXTRN mi341:NEAR
    EXTRN mi344:NEAR
    EXTRN mi350:NEAR
    EXTRN mi356:NEAR
    EXTRN mi359:NEAR
    EXTRN mi362:NEAR
    EXTRN mi377:NEAR
    EXTRN mi379:NEAR
    EXTRN mf389:FAR
    EXTRN mf395:FAR
    EXTRN mf397:FAR
    EXTRN mi440:NEAR
    EXTRN mi445:NEAR
    EXTRN mf464:FAR
    EXTRN mf475:FAR
    EXTRN mf481:FAR
    EXTRN mf483:FAR
    EXTRN mf555:FAR
    EXTRN mf557:FAR
    EXTRN mf568:FAR
    EXTRN mf577:FAR
    EXTRN mf583:FAR
    EXTRN mf588:FAR
    EXTRN mf595:FAR
    EXTRN mf597:FAR
    EXTRN mf608:FAR
    EXTRN mf637:FAR
    EXTRN mf643:FAR
    EXTRN mf645:FAR
    EXTRN mf651:FAR
    EXTRN mf688:FAR
    EXTRN mf699:FAR
    EXTRN mf724:FAR
    EXTRN mf733:FAR
    EXTRN mf788:FAR
    EXTRN mf804:FAR
    EXTRN mf812:FAR
    EXTRN mf819:FAR
    EXTRN mf860:FAR
    EXTRN mf877:FAR
    EXTRN mf883:FAR
    EXTRN mf887:FAR
    EXTRN mf899:FAR
    EXTRN mf902:FAR
    EXTRN mf909:FAR
    EXTRN mf922:FAR
    EXTRN mf932:FAR
    EXTRN mf939:FAR
    EXTRN mf949:FAR
    EXTRN mf959:FAR
    EXTRN mf969:FAR
    EXTRN mf979:FAR
    EXTRN mf981:FAR
    EXTRN mf984:FAR
    EXTRN mf988:FAR
    EXTRN mf990:FAR
    EXTRN mf993:FAR
    EXTRN mf1000:FAR
    EXTRN mf1000:FAR
    EXTRN mf1000:FAR
    EXTRN mf1000:FAR
    EXTRN mf1000:FAR
    EXTRN mf1000:FAR
    EXTRN mf1000:FAR
    EXTRN mf1000:FAR
    EXTRN mf1000:FAR
    EXTRN mf1000:FAR
    EXTRN mf1000:FAR
    EXTRN mf1000:FAR
    EXTRN mf1000:FAR
    EXTRN mf1000:FAR
    EXTRN mf1000:FAR
    EXTRN mf1000:FAR
    EXTRN mf1000:FAR
    EXTRN mf1000:FAR
    EXTRN mf1000:FAR
    EXTRN mf1000:FAR
    EXTRN mf1000:FAR
    EXTRN mf1000:FAR
    EXTRN mf1000:FAR
    EXTRN mf1000:FAR
    EXTRN mf1000:FAR
    EXTRN mf1000:FAR
    EXTRN mf1000:FAR
    EXTRN mf1000:FAR
    EXTRN mf1000:FAR
    EXTRN mf1000:FAR
    EXTRN mf1000:FAR
    EXTRN mf1000:FAR
    EXTRN mf1000:FAR
    EXTRN mf1000:FAR
    EXTRN mf1000:FAR
    EXTRN mf1000:FAR
    EXTRN mf1000:FAR
    EXTRN mf1000:FAR
    EXTRN mf1000:FAR
    EXTRN mf1000:FAR
    EXTRN mf1000:FAR
    EXTRN mf1000:FAR
    EXTRN mf1000:FAR
    EXTRN mf1000:FAR
    EXTRN mf1000:FAR
    EXTRN mf1000:FAR
    EXTRN mf1000:FAR
    EXTRN mf1000:FAR
    EXTRN mf1000:FAR
    EXTRN mf1000:FAR
    EXTRN mf1000:FAR
    EXTRN mf1000:FAR
    EXTRN mf1000:FAR
    EXTRN mf1000:FAR
    EXTRN mf1000:FAR
    EXTRN mf1000:FAR
    EXTRN mf1000:FAR
    EXTRN mf1000:FAR
    EXTRN mf1000:FAR
    EXTRN mf1000:FAR
    EXTRN mf1000:FAR
    EXTRN mf1000:FAR
    EXTRN mf1000:FAR
    EXTRN mf1000:FAR
    EXTRN mf1000:FAR
    EXTRN mf1000:FAR
    EXTRN mf1000:FAR
    EXTRN mf1000:FAR
    EXTRN mf1000:FAR
    EXTRN mf1000:FAR
    EXTRN mf1000:FAR
    EXTRN mf1000:FAR
    EXTRN mf1000:FAR
    EXTRN mf1000:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,54h
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
    mov word ptr [bp-2h],ax
    push ax
    push ax
    call mf26
    add sp,4h
    lea ax,word ptr [bp-3Ah]
    push ss
    push ax
    call mf31
    add sp,4h
    mov ax,20h
    push ax
    call mf35
    add sp,2h
    mov ax,0C7h
    push ax
    mov ax,13Fh
    push ax
    xor ax,ax
    push ax
    push ax
    call mf44
    add sp,8h
    mov ax,40h
    cwd
    push dx
    push ax
    call mf50
    add sp,4h
    mov word ptr ds:[5E16h],ax
    mov word ptr ds:[5E18h],dx
    mov ax,dx
    or ax,word ptr ds:[5E16h]
    jnz short lbl9Af
    jmp near ptr lbl9EFf
lbl9Af:
    mov ax,20h
    cwd
    push dx
    push ax
    call mf62
    add sp,4h
    mov word ptr ds:[5E1Ch],ax
    mov word ptr ds:[5E1Eh],dx
    mov ax,dx
    or ax,word ptr ds:[5E1Ch]
    jnz short lblBAf
    jmp near ptr lbl9EFf
lblBAf:
    mov ax,1Eh
    cwd
    push dx
    push ax
    call mf74
    add sp,4h
    mov word ptr ds:[5E2Ah],ax
    mov word ptr ds:[5E2Ch],dx
    mov ax,dx
    or ax,word ptr ds:[5E2Ah]
    jnz short lblDAf
    jmp near ptr lbl9EFf
lblDAf:
    mov word ptr ds:[5E28h],100h
lblE0b:
    mov ax,word ptr ds:[5E28h]
    mov cx,ax
    add ax,ax
    add ax,cx
    add ax,ax
    sub dx,dx
    push dx
    push ax
    call mf91
    add sp,4h
    mov word ptr ds:[5E22h],ax
    mov word ptr ds:[5E24h],dx
    mov ax,dx
    or ax,word ptr ds:[5E22h]
    jnz short lbl112f
    sub word ptr ds:[5E28h],10h
    cmp word ptr ds:[5E28h],10h
    jnc short lblE0b
lbl112f:
    mov ax,dx
    or ax,word ptr ds:[5E22h]
    jnz short lbl120f
    mov word ptr ds:[5E28h],0h
lbl120f:
    mov ax,0Dh
    push ax
    call mf107
    add sp,2h
    mov ax,17h
    push ax
    mov ax,0Fh
    push ax
    call mf113
    add sp,4h
    mov ax,0C7h
    push ax
    mov cx,13Fh
    push cx
    xor cx,cx
    push cx
    push cx
    call mf122
    add sp,8h
    mov ax,0C7h
    push ax
    mov ax,109h
    push ax
    mov ax,63h
    sub ax,word ptr ds:[69F8h]
    add ax,ax
    sub ax,word ptr ds:[6D48h]
    push ax
    xor ax,ax
    push ax
    call mf135
    add sp,8h
    mov bx,word ptr ds:[5B08h]
    mov ax,bx
    add bx,bx
    add bx,ax
    mov es, ds:[5B20h]
    lea di,word ptr [bx+6A24h]
    mov si,32C0h
    movsw
    movsw
    movsw
    movsw
    movsb
    mov bx,word ptr ds:[5B0Eh]
    mov ax,bx
    add bx,bx
    add bx,ax
    lea di,word ptr [bx+6A24h]
    mov si,32D4h
    mov cx,6h
    rep movsw
    mov bx,word ptr ds:[5B16h]
    mov ax,bx
    add bx,bx
    add bx,ax
    lea di,word ptr [bx+6A24h]
    mov si,32CAh
    movsw
    movsw
    movsw
    movsw
    movsb
    call mf168
    call mf169
    mov ax,30h
    push ax
    mov cx,3348h
    push ds
    push cx
    mov cx,78h
    push cx
    mov cx,10Ah
    push cx
    call mf179
    add sp,0Ah
    mov ax,30h
    push ax
    mov cx,334Dh
    push ds
    push cx
    mov cx,88h
    push cx
    mov cx,10Ah
    push cx
    call mf190
    add sp,0Ah
    mov ax,30h
    push ax
    mov cx,3352h
    push ds
    push cx
    mov cx,98h
    push cx
    mov cx,10Ah
    push cx
    call mf201
    add sp,0Ah
    mov ax,30h
    push ax
    mov cx,3357h
    push ds
    push cx
    mov cx,0A8h
    push cx
    mov cx,10Ah
    push cx
    call mf212
    add sp,0Ah
    mov ax,30h
    push ax
    mov ax,335Dh
    push ds
    push ax
    mov ax,0B8h
    push ax
    mov ax,10Ah
    push ax
    call mf223
    add sp,0Ah
lbl23Eb:
    mov bx,word ptr [bp-8h]
    mov ax,bx
    add bx,bx
    add bx,ax
    add bx,bx
    add bx,bx
    add bx,90h
    mov es, ds:[5B22h]
    mov word ptr ds:[5E12h],bx
    mov word ptr ds:[5E14h],es
    mov ax,word ptr es:[bx+6h]
    mov word ptr ds:[5E1Ah],ax
    mov al,byte ptr es:[bx]
    sub ah,ah
    imul word ptr ds:[5B1Ch]
    sub ax,140h
    neg ax
    cwd
    sub ax,dx
    sar ax,1
    mov word ptr ds:[332Eh],ax
    mov al,byte ptr es:[bx+1h]
    sub ah,ah
    imul word ptr ds:[5B1Eh]
    sub ax,0C8h
    neg ax
    cwd
    sub ax,dx
    sar ax,1
    mov word ptr ds:[3330h],ax
    call mf255
    les bx, dword ptr ds:[5E12h]
    cmp byte ptr es:[bx+4h],0h
    jz short lbl2A4f
    mov ax,331Ch
    jmp short lbl2A7f
lbl2A4f:
    mov ax,3316h
lbl2A7f:
    push ds
    push ax
    cmp byte ptr es:[bx+5h],0h
    jz short lbl2B6f
    mov ax,3328h
    jmp short lbl2B9f
    nop
lbl2B6f:
    mov ax,3322h
lbl2B9f:
    push ds
    push ax
    mov si,word ptr es:[bx+2h]
    add si,si
    add si,si
    mov cx,word ptr es:[bx+8h]
    mov dx,word ptr es:[bx+0Ah]
    mov es,dx
    add si,cx
    mov word ptr [bp-50h],si
    mov word ptr [bp-4Eh],es
    cmp byte ptr es:[si+2h],0h
    jz short lbl2E2f
    mov ax,331Ch
    jmp short lbl2E5f
    nop
lbl2E2f:
    mov ax,3316h
lbl2E5f:
    push ds
    push ax
    mov bx,si
    cmp byte ptr es:[bx+3h],0h
    jz short lbl2F6f
    mov ax,3328h
    jmp short lbl2F9f
    nop
lbl2F6f:
    mov ax,3322h
lbl2F9f:
    push ds
    push ax
    mov ax,1h
    mov dx,0F044h
    push dx
    push ax
    call mf302
    add sp,14h
    xor ax,ax
    mov word ptr [bp-0Eh],ax
    mov word ptr [bp-0Ch],ax
    mov word ptr [bp-0Ah],ax
    mov ax,word ptr ds:[5E1Ah]
    mov word ptr [bp-6h],ax
lbl31Cb:
    call mf310
    or ax,ax
    jnz short lbl328f
    jmp near ptr lbl648f
lbl328f:
    mov word ptr [bp-10h],0h
    call mf315
    mov word ptr [bp-12h],ax
    cmp ax, offset mi317
    jnz short lbl33Df
    jmp near ptr lbl630f
lbl33Df:
    cmp ax,13Bh
    jnz short lbl345f
    jmp near ptr lbl630f
lbl345f:
    cmp ax, offset mi323
    jnz short lbl34Df
    jmp near ptr lbl9A4f
lbl34Df:
    cmp ax,13Ch
    jnz short lbl355f
    jmp near ptr lbl9A4f
lbl355f:
    cmp ax, offset mi329
    jnz short lbl35Df
    jmp near ptr lbl5E0f
lbl35Df:
    cmp ax,13Dh
    jnz short lbl365f
    jmp near ptr lbl5E0f
lbl365f:
    cmp ax, offset mi335
    jnz short lbl36Df
    jmp near ptr lbl5BEf
lbl36Df:
    cmp ax,13Eh
    jnz short lbl375f
    jmp near ptr lbl5BEf
lbl375f:
    cmp ax, offset mi341
    jnz short lbl37Df
    jmp near ptr lbl9E0f
lbl37Df:
    cmp ax, offset mi344
    jnz short lbl385f
    jmp near ptr lbl9E0f
lbl385f:
    cmp ax,13Fh
    jnz short lbl38Df
    jmp near ptr lbl9E0f
lbl38Df:
    cmp ax, offset mi350
    jnz short lbl395f
    jmp near ptr lbl4CEf
lbl395f:
    cmp ax,10Fh
    jnz short lbl39Df
    jmp near ptr lbl4CEf
lbl39Df:
    cmp ax, offset mi356
    jnz short lbl3A5f
    jmp near ptr lbl4CEf
lbl3A5f:
    cmp ax, offset mi359
    jnz short lbl3ADf
    jmp near ptr lbl4CEf
lbl3ADf:
    cmp ax, offset mi362
    jnz short lbl3B5f
    jmp near ptr lbl4CEf
lbl3B5f:
    cmp ax,14Bh
    jnz short lbl3BDf
    jmp near ptr lbl470f
lbl3BDf:
    cmp ax,148h
    jnz short lbl3C5f
    jmp near ptr lbl470f
lbl3C5f:
    cmp ax,14Dh
    jnz short lbl3CDf
    jmp near ptr lbl470f
lbl3CDf:
    cmp ax,150h
    jnz short lbl3D5f
    jmp near ptr lbl470f
lbl3D5f:
    cmp ax, offset mi377
    jz short lbl3E2f
    cmp ax, offset mi379
    jz short lbl3E2f
    jmp near ptr lbl859f
lbl3E2f:
    cmp word ptr [bp-0Ah],0h
    jz short lbl45Af
    cmp byte ptr [bp-3Ah],0h
    jz short lbl3FBf
    lea ax,word ptr [bp-3Ah]
    push ss
    push ax
    call mf389
    add sp,4h
lbl3FBf:
    push word ptr [bp-6h]
    lea ax,word ptr [bp-26h]
    push ss
    push ax
    call mf395
    add sp,6h
    call mf397
    xor ax,ax
    mov word ptr [bp-0Ch],ax
    mov word ptr [bp-0Ah],ax
    les bx, dword ptr ds:[5E12h]
    mov al,byte ptr es:[bx+4h]
    mov bx,word ptr es:[bx+2h]
    add bx,bx
    add bx,bx
    mov es, ds:[5E18h]
    add bx,word ptr ds:[5E16h]
    mov word ptr [bp-54h],bx
    mov word ptr [bp-52h],es
    cmp byte ptr es:[bx+2h],al
    jz short lbl43Ff
    jmp near ptr lbl859f
lbl43Ff:
    les bx, dword ptr ds:[5E12h]
    mov al,byte ptr es:[bx+5h]
    les bx, dword ptr [bp-54h]
    cmp byte ptr es:[bx+3h],al
    jz short lbl453f
    jmp near ptr lbl859f
lbl453f:
    mov ax,336Bh
    jmp near ptr lbl98Df
    nop
lbl45Af:
    mov ax,word ptr ds:[5E1Ah]
    cmp word ptr [bp-6h],ax
    jc short lbl467f
    mov word ptr [bp-6h],0h
lbl467b:
lbl467f:
    mov word ptr [bp-0Eh],1h
    jmp near ptr lbl859f
    nop
lbl470f:
    cmp word ptr [bp-0Ah],0h
    jnz short lbl479f
    jmp near ptr lbl859f
lbl479f:
    mov al,byte ptr [bp-23h]
    sub ah,ah
    mov word ptr [bp-22h],ax
    mov al,byte ptr [bp-24h]
    mov word ptr [bp-20h],ax
    mov ax,word ptr [bp-12h]
    sub ax,148h
    jz short lbl4A0f
    sub ax, offset mi440
    jz short lbl4A6f
    dec ax
    dec ax
    jz short lbl4ACf
    sub ax, offset mi445
    jz short lbl4B2f
    jmp short lbl4B5f
    nop
lbl4A0f:
    dec word ptr [bp-22h]
    jmp short lbl4B5f
    nop
lbl4A6f:
    dec word ptr [bp-20h]
    jmp short lbl4B5f
    nop
lbl4ACf:
    inc word ptr [bp-20h]
    jmp short lbl4B5f
    nop
lbl4B2f:
    inc word ptr [bp-22h]
lbl4B5f:
    push word ptr [bp-20h]
    push word ptr [bp-22h]
    lea ax,word ptr [bp-26h]
    push ss
    push ax
    call mf464
    add sp,8h
    mov word ptr [bp-0Eh],ax
    jmp near ptr lbl859f
lbl4CEf:
    cmp word ptr [bp-0Ah],0h
    jz short lbl504f
    cmp byte ptr [bp-3Ah],0h
    jz short lbl4E7f
    lea ax,word ptr [bp-3Ah]
    push ss
    push ax
    call mf475
    add sp,4h
lbl4E7f:
    push word ptr [bp-6h]
    lea ax,word ptr [bp-26h]
    push ss
    push ax
    call mf481
    add sp,6h
    call mf483
    xor ax,ax
    mov word ptr [bp-0Ch],ax
    mov word ptr [bp-0Ah],ax
lbl504f:
    les bx, dword ptr ds:[5E12h]
    mov al,byte ptr es:[bx+4h]
    mov bx,word ptr es:[bx+2h]
    add bx,bx
    add bx,bx
    mov es, ds:[5E18h]
    add bx,word ptr ds:[5E16h]
    mov word ptr [bp-54h],bx
    mov word ptr [bp-52h],es
    cmp byte ptr es:[bx+2h],al
    jnz short lbl53Cf
    les bx, dword ptr ds:[5E12h]
    mov al,byte ptr es:[bx+5h]
    les bx, dword ptr [bp-54h]
    cmp byte ptr es:[bx+3h],al
    jnz short lbl53Cf
    jmp near ptr lbl98Af
lbl53Cf:
    mov word ptr [bp-4h],0h
    cmp word ptr ds:[5E20h],0h
    jz short lbl59Df
    mov ax,word ptr ds:[5E1Ch]
    mov dx,word ptr ds:[5E1Eh]
    mov word ptr [bp-4Ch],ax
    mov word ptr [bp-4Ah],dx
lbl555b:
    les bx, dword ptr [bp-4Ch]
    mov ax,word ptr es:[bx]
    sub ax,word ptr [bp-6h]
    dec ax
    jz short lbl572f
    add word ptr [bp-4Ch],2h
    mov ax,word ptr ds:[5E20h]
    inc word ptr [bp-4h]
    cmp word ptr [bp-4h],ax
    jc short lbl555b
    jmp short lbl59Df
lbl572f:
    cmp word ptr [bp-12h],9h
    jz short lbl59Af
    cmp word ptr [bp-12h],2Bh
    jz short lbl59Af
    cmp word ptr [bp-12h],3Dh
    jz short lbl59Af
    cmp word ptr [bp-4h],0h
    jnz short lbl594f
    mov ax,word ptr ds:[5E20h]
    dec ax
    mov word ptr [bp-4h],ax
    jmp short lbl59Df
    nop
lbl594f:
    dec word ptr [bp-4h]
    jmp short lbl59Df
    nop
lbl59Af:
    inc word ptr [bp-4h]
lbl59Df:
    mov ax,word ptr ds:[5E20h]
    cmp word ptr [bp-4h],ax
    jc short lbl5AAf
    mov word ptr [bp-4h],0h
lbl5AAf:
    mov bx,word ptr [bp-4h]
    add bx,bx
    les si, dword ptr ds:[5E1Ch]
    mov ax,word ptr es:[bx+si]
    dec ax
    mov word ptr [bp-6h],ax
    jmp near ptr lbl467b
    nop
lbl5BEf:
    mov ax,4h
    push ax
    xor ax,ax
    push ax
    call mf555
    add sp,4h
lbl5CDb:
    call mf557
    mov ax,word ptr ds:[5E1Ah]
    mov word ptr [bp-6h],ax
    mov word ptr [bp-0Ah],0h
    jmp near ptr lbl859f
lbl5E0f:
    cmp word ptr ds:[5E26h],0h
    jz short lbl5F6f
    mov ax,3h
    push ax
    xor ax,ax
    push ax
    call mf568
    add sp,4h
lbl5F6b:
lbl5F6f:
    cmp word ptr [bp-0Ah],0h
    jz short lbl627f
    cmp byte ptr [bp-3Ah],0h
    jz short lbl60Ff
    lea ax,word ptr [bp-3Ah]
    push ss
    push ax
    call mf577
    add sp,4h
lbl60Ff:
    push word ptr [bp-6h]
    lea ax,word ptr [bp-26h]
    push ss
    push ax
    call mf583
    add sp,6h
    xor ax,ax
    mov word ptr [bp-0Ch],ax
    mov word ptr [bp-0Ah],ax
lbl627f:
    call mf588
    jmp near ptr lbl859f
    nop
lbl630f:
    mov ax,1h
    push ax
    xor ax,ax
    push ax
    call mf595
    add sp,4h
lbl63Fb:
    call mf597
    jmp near ptr lbl859f
    nop
lbl648f:
    mov ax,word ptr [bp-16h]
    mov word ptr [bp-14h],ax
    lea ax,word ptr [bp-1Ah]
    push ss
    push ax
    lea ax,word ptr [bp-18h]
    push ss
    push ax
    call mf608
    add sp,8h
    mov word ptr [bp-16h],ax
    mov word ptr [bp-10h],1h
    cmp word ptr [bp-0Ah],0h
    jnz short lbl671f
    jmp near ptr lbl784f
lbl671f:
    mov ax,word ptr [bp-14h]
    cmp word ptr [bp-16h],ax
    jnz short lbl67Cf
    jmp near ptr lbl71Ef
lbl67Cf:
    test word ptr [bp-16h],ax
    jz short lbl684f
    jmp near ptr lbl71Ef
lbl684f:
    cmp word ptr [bp-16h],0h
    jz short lbl690f
    cmp word ptr [bp-0Ch],0h
    jz short lbl6A2f
lbl690f:
    cmp word ptr [bp-16h],0h
    jz short lbl699f
    jmp near ptr lbl859f
lbl699f:
    cmp word ptr [bp-0Ch],0h
    jnz short lbl6A2f
    jmp near ptr lbl859f
lbl6A2f:
    cmp byte ptr [bp-3Ah],0h
    jz short lbl6B5f
    lea ax,word ptr [bp-3Ah]
    push ss
    push ax
    call mf637
    add sp,4h
lbl6B5f:
    push word ptr [bp-6h]
    lea ax,word ptr [bp-26h]
    push ss
    push ax
    call mf643
    add sp,6h
    call mf645
    xor ax,ax
    mov word ptr [bp-0Ch],ax
    mov word ptr [bp-0Ah],ax
    cmp word ptr [bp-16h],ax
    jz short lbl6DCf
    call mf651
lbl6DCf:
    les bx, dword ptr ds:[5E12h]
    mov al,byte ptr es:[bx+4h]
    mov bx,word ptr es:[bx+2h]
    add bx,bx
    add bx,bx
    mov es, ds:[5E18h]
    add bx,word ptr ds:[5E16h]
    mov word ptr [bp-54h],bx
    mov word ptr [bp-52h],es
    cmp byte ptr es:[bx+2h],al
    jz short lbl703f
    jmp near ptr lbl859f
lbl703f:
    les bx, dword ptr ds:[5E12h]
    mov al,byte ptr es:[bx+5h]
    les bx, dword ptr [bp-54h]
    cmp byte ptr es:[bx+3h],al
    jz short lbl717f
    jmp near ptr lbl859f
lbl717f:
    mov ax,3374h
    jmp near ptr lbl98Df
    nop
lbl71Ef:
    mov ax,word ptr [bp-18h]
    sub ax,word ptr [bp-1Ch]
    sub ax,word ptr ds:[332Eh]
    cwd
    idiv word ptr ds:[5B1Ch]
    push ax
    mov ax,word ptr [bp-1Ah]
    sub ax,word ptr [bp-1Eh]
    sub ax,word ptr ds:[3330h]
    cwd
    idiv word ptr ds:[5B1Eh]
    push ax
    lea ax,word ptr [bp-26h]
    push ss
    push ax
    call mf688
    add sp,8h
    mov word ptr [bp-0Eh],ax
    cmp word ptr [bp-0Ch],0h
    jz short lbl757f
    jmp near ptr lbl859f
lbl757f:
    cmp word ptr [bp-16h],0h
    jnz short lbl760f
    jmp near ptr lbl859f
lbl760f:
    or ax,ax
    jnz short lbl77Bf
    call mf699
    cmp dx,word ptr [bp-3Ch]
    jnl short lbl771f
    jmp near ptr lbl859f
lbl771f:
    jg short lbl77Bf
    cmp ax,word ptr [bp-3Eh]
    jnc short lbl77Bf
    jmp near ptr lbl859f
lbl77Bf:
    mov word ptr [bp-0Ch],1h
    jmp near ptr lbl859f
    nop
lbl784f:
    or ax,ax
    jnz short lbl78Bf
    jmp near ptr lbl859f
lbl78Bf:
    lea ax,word ptr [bp-44h]
    push ss
    push ax
    lea ax,word ptr [bp-42h]
    push ss
    push ax
    lea ax,word ptr [bp-40h]
    push ss
    push ax
    push word ptr [bp-1Ah]
    push word ptr [bp-18h]
    call mf724
    add sp,10h
    or ax,ax
    jz short lbl7E8f
    cmp word ptr [bp-44h],5h
    jnz short lbl7E8f
    push word ptr [bp-42h]
    xor ax,ax
    push ax
    call mf733
    add sp,4h
    cmp word ptr [bp-42h],1h
    jnz short lbl7C9f
    jmp near ptr lbl63Fb
lbl7C9f:
    cmp word ptr [bp-42h],2h
    jnz short lbl7D2f
    jmp near ptr lbl9B3f
lbl7D2f:
    cmp word ptr [bp-42h],3h
    jnz short lbl7DBf
    jmp near ptr lbl5F6b
lbl7DBf:
    cmp word ptr [bp-42h],4h
    jz short lbl7E4f
    jmp near ptr lbl9EFf
lbl7E4f:
    jmp near ptr lbl5CDb
    nop
lbl7E8f:
    mov ax,word ptr [bp-18h]
    sub ax,word ptr ds:[332Eh]
    cwd
    idiv word ptr ds:[5B1Ch]
    mov word ptr [bp-20h],ax
    mov ax,word ptr [bp-1Ah]
    sub ax,word ptr ds:[3330h]
    cwd
    idiv word ptr ds:[5B1Eh]
    mov word ptr [bp-22h],ax
    or ax,ax
    jl short lbl854f
    les bx, dword ptr ds:[5E12h]
    sub ah,ah
    mov al,byte ptr es:[bx+1h]
    cmp ax,word ptr [bp-22h]
    jng short lbl854f
    cmp word ptr [bp-20h],0h
    jl short lbl854f
    mov al,byte ptr es:[bx]
    cmp ax,word ptr [bp-20h]
    jng short lbl854f
    mov bx,word ptr [bp-22h]
    mov ax,bx
    add bx,bx
    add bx,ax
    add bx,bx
    mov es, ds:[5E2Ch]
    add bx,word ptr ds:[5E2Ah]
    mov si,word ptr [bp-20h]
    mov al,byte ptr es:[bx+si]
    sub ah,ah
    mov word ptr [bp-6h],ax
    or ax,ax
    jz short lbl854f
    mov word ptr [bp-0Eh],1h
    dec word ptr [bp-6h]
    jmp short lbl859f
    nop
lbl854f:
    call mf788
lbl859f:
    cmp word ptr [bp-0Eh],0h
    jnz short lbl862f
    jmp near ptr lbl31Cb
lbl862f:
    cmp word ptr [bp-0Ah],0h
    jnz short lbl88Af
    mov bx,word ptr [bp-6h]
    add bx,bx
    add bx,bx
    les si, dword ptr ds:[5E16h]
    mov ax,word ptr es:[bx+si]
    mov dx,word ptr es:[bx+si+2h]
    mov word ptr [bp-26h],ax
    mov word ptr [bp-24h],dx
    push dx
    push ax
    call mf804
    jmp short lbl89Af
    nop
lbl88Af:
    cmp byte ptr [bp-3Ah],0h
    jz short lbl89Df
    lea ax,word ptr [bp-3Ah]
    push ss
    push ax
    call mf812
lbl89Af:
    add sp,4h
lbl89Df:
    cmp byte ptr [bp-3Ah],0h
    jz short lbl8B0f
    lea ax,word ptr [bp-3Ah]
    push ss
    push ax
    call mf819
    add sp,4h
lbl8B0f:
    mov al,byte ptr [bp-24h]
    sub ah,ah
    imul word ptr ds:[5B1Ch]
    add ax,word ptr ds:[332Eh]
    mov word ptr [bp-46h],ax
    mov al,byte ptr [bp-23h]
    sub ah,ah
    imul word ptr ds:[5B1Eh]
    add ax,word ptr ds:[3330h]
    mov word ptr [bp-48h],ax
    cmp word ptr [bp-0Ah],0h
    jnz short lbl90Df
    cmp word ptr [bp-10h],0h
    jz short lbl8EEf
    mov ax,word ptr [bp-18h]
    sub ax,word ptr [bp-46h]
    mov word ptr [bp-1Ch],ax
    mov ax,word ptr [bp-1Ah]
    sub ax,word ptr [bp-48h]
    jmp short lbl90Af
    nop
lbl8EEf:
    mov bx,word ptr [bp-26h]
    add bx,bx
    mov ax,word ptr [bx+32DEh]
    mul word ptr ds:[5B1Ch]
    shr ax,1
    mov word ptr [bp-1Ch],ax
    mov ax,word ptr [bx+32E6h]
    mul word ptr ds:[5B1Eh]
    shr ax,1
lbl90Af:
    mov word ptr [bp-1Eh],ax
lbl90Df:
    cmp word ptr [bp-10h],0h
    jnz short lbl929f
    mov ax,word ptr [bp-48h]
    add ax,word ptr [bp-1Eh]
    push ax
    mov ax,word ptr [bp-46h]
    add ax,word ptr [bp-1Ch]
    push ax
    call mf860
    add sp,4h
lbl929f:
    mov ax,word ptr ds:[5B1Eh]
    add ax,ax
    add ax,word ptr [bp-48h]
    dec ax
    push ax
    mov ax,word ptr ds:[5B1Ch]
    add ax,ax
    add ax,word ptr [bp-46h]
    dec ax
    push ax
    push word ptr [bp-48h]
    push word ptr [bp-46h]
    lea ax,word ptr [bp-3Ah]
    push ss
    push ax
    call mf877
    add sp,0Ch
    xor ax,ax
    push ax
    push word ptr [bp-24h]
    push word ptr [bp-26h]
    call mf883
    add sp,6h
    cmp word ptr [bp-0Ah],0h
    jnz short lbl982f
    call mf887
    add ax,0FAh
    adc dx,0h
    mov word ptr [bp-3Eh],ax
    mov word ptr [bp-3Ch],dx
    mov word ptr [bp-0Ah],1h
    mov word ptr [bp-0Ch],0h
lbl982f:
    mov word ptr [bp-0Eh],0h
    jmp near ptr lbl31Cb
lbl98Af:
    mov ax,3362h
lbl98Df:
    push ds
    push ax
    call mf899
    add sp,4h
    mov word ptr [bp-2h],1h
    call mf902
    jmp short lbl9C1f
    nop
lbl9A4f:
    mov ax,2h
    push ax
    xor ax,ax
    push ax
    call mf909
    add sp,4h
lbl9B3f:
    inc word ptr [bp-8h]
    cmp word ptr [bp-8h],3h
    jc short lbl9C1f
    mov word ptr [bp-8h],0h
lbl9C1f:
    mov ax,0C7h
    push ax
    mov ax,109h
    push ax
    xor ax,ax
    push ax
    push ax
    call mf922
    add sp,8h
    cmp word ptr [bp-2h],0h
    jnz short lbl9DEf
    jmp near ptr lbl23Eb
lbl9DEf:
    jmp short lbl9EFf
lbl9E0f:
    mov ax,5h
    push ax
    xor ax,ax
    push ax
    call mf932
    add sp,4h
lbl9EFf:
    mov ax,word ptr ds:[5E24h]
    or ax,word ptr ds:[5E22h]
    jz short lblA10f
    push word ptr ds:[5E24h]
    push word ptr ds:[5E22h]
    call mf939
    add sp,4h
    sub ax,ax
    mov word ptr ds:[5E24h],ax
    mov word ptr ds:[5E22h],ax
lblA10f:
    mov ax,word ptr ds:[5E2Ch]
    or ax,word ptr ds:[5E2Ah]
    jz short lblA31f
    push word ptr ds:[5E2Ch]
    push word ptr ds:[5E2Ah]
    call mf949
    add sp,4h
    sub ax,ax
    mov word ptr ds:[5E2Ch],ax
    mov word ptr ds:[5E2Ah],ax
lblA31f:
    mov ax,word ptr ds:[5E1Eh]
    or ax,word ptr ds:[5E1Ch]
    jz short lblA52f
    push word ptr ds:[5E1Eh]
    push word ptr ds:[5E1Ch]
    call mf959
    add sp,4h
    sub ax,ax
    mov word ptr ds:[5E1Eh],ax
    mov word ptr ds:[5E1Ch],ax
lblA52f:
    mov ax,word ptr ds:[5E18h]
    or ax,word ptr ds:[5E16h]
    jz short lblA73f
    push word ptr ds:[5E18h]
    push word ptr ds:[5E16h]
    call mf969
    add sp,4h
    sub ax,ax
    mov word ptr ds:[5E18h],ax
    mov word ptr ds:[5E16h],ax
lblA73f:
    cmp byte ptr [bp-3Ah],0h
    jz short lblA86f
    lea ax,word ptr [bp-3Ah]
    push ss
    push ax
    call mf979
    add sp,4h
lblA86f:
    call mf981
    mov ax,1h
    push ax
    call mf984
    add sp,2h
    mov ax,1Fh
    push ax
    call mf988
    add sp,2h
    call mf990
    mov ax,10h
    push ax
    call mf993
    add sp,2h
    mov ax,word ptr [bp-2h]
    pop si
    pop di
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
