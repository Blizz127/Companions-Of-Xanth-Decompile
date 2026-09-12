_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf6:FAR
    EXTRN mf12:FAR
    EXTRN mf17:FAR
    EXTRN mf30:FAR
    EXTRN mf34:FAR
    EXTRN mf40:FAR
    EXTRN mf50:FAR
    EXTRN mf60:FAR
    EXTRN mf71:FAR
    EXTRN mf83:FAR
    EXTRN mf95:FAR
    EXTRN mf98:FAR
    EXTRN mf109:FAR
    EXTRN mf120:FAR
    EXTRN mf131:FAR
    EXTRN mf142:FAR
    EXTRN mf153:FAR
    EXTRN mf164:FAR
    EXTRN mf178:FAR
    EXTRN mf191:FAR
    EXTRN mf203:FAR
    EXTRN mf207:FAR
    EXTRN mf218:FAR
    EXTRN mf222:FAR
    EXTRN mf234:FAR
    EXTRN mf242:FAR
    EXTRN mf248:FAR
    EXTRN mi253:NEAR
    EXTRN mi256:NEAR
    EXTRN mf273:FAR
    EXTRN mi275:NEAR
    EXTRN mf281:FAR
    EXTRN mi284:NEAR
    EXTRN mf290:FAR
    EXTRN mf297:FAR
    EXTRN mf304:FAR
    EXTRN mf306:FAR
    EXTRN mf313:FAR
    EXTRN mi334:NEAR
    EXTRN mi337:NEAR
    EXTRN mi349:NEAR
    EXTRN mf397:FAR
    EXTRN mi412:NEAR
    EXTRN mi418:NEAR
    EXTRN mi420:NEAR
    EXTRN mf423:FAR
    EXTRN mf428:FAR
    EXTRN mf431:FAR
    EXTRN mi443:NEAR
    EXTRN mf446:FAR
    EXTRN mi448:NEAR
    EXTRN mf451:FAR
    EXTRN mf457:FAR
    EXTRN mf462:FAR
    EXTRN mf467:FAR
    EXTRN mf470:FAR
    EXTRN mf475:FAR
    EXTRN mf475:FAR
    EXTRN mf475:FAR
    EXTRN mf475:FAR
    EXTRN mf475:FAR
    EXTRN mf475:FAR
    EXTRN mf475:FAR
    EXTRN mf475:FAR
    EXTRN mf475:FAR
    EXTRN mf475:FAR
    EXTRN mf475:FAR
    EXTRN mf475:FAR
    EXTRN mf475:FAR
    EXTRN mf475:FAR
    EXTRN mf475:FAR
    EXTRN mf475:FAR
    EXTRN mf475:FAR
    EXTRN mf475:FAR
    EXTRN mf475:FAR
    EXTRN mf475:FAR
    EXTRN mf475:FAR
    EXTRN mf475:FAR
    EXTRN mf475:FAR
    EXTRN mf475:FAR
    EXTRN mf475:FAR
    EXTRN mf475:FAR
    EXTRN mf475:FAR
    EXTRN mf475:FAR
    EXTRN mf475:FAR
    EXTRN mf475:FAR
    EXTRN mf475:FAR
    EXTRN mf475:FAR
    EXTRN mf475:FAR
    EXTRN mf475:FAR
    EXTRN mf475:FAR
    EXTRN mf475:FAR
    EXTRN mf475:FAR
    EXTRN mf475:FAR
    EXTRN mf475:FAR
    EXTRN mf475:FAR
    EXTRN mf475:FAR
    EXTRN mf475:FAR
    EXTRN mf475:FAR
    EXTRN mf475:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,3Eh
    push si
    xor ax,ax
    push ax
    call mf6
    add sp,2h
    mov word ptr [bp-18h],ax
    lea ax,word ptr [bp-14h]
    push ss
    push ax
    call mf12
    add sp,4h
    xor ax,ax
    push ax
    push ax
    call mf17
    add sp,4h
    mov ax,0A4h
    push ax
    mov cx,0D9h
    push cx
    mov dx,1Fh
    push dx
    mov bx,65h
    push bx
    lea si,word ptr [bp-14h]
    push ss
    push si
    call mf30
    add sp,0Ch
    mov ax,1h
    push ax
    call mf34
    add sp,2h
    mov ax,0FFFFh
    push ax
    mov ax,0Fh
    push ax
    call mf40
    add sp,4h
    mov ax,0A4h
    push ax
    mov cx,0D9h
    push cx
    mov dx,1Fh
    push dx
    mov bx,65h
    push bx
    call mf50
    add sp,8h
    mov ax,0A4h
    push ax
    mov cx,0D9h
    push cx
    mov dx,1Fh
    push dx
    mov bx,65h
    push bx
    call mf60
    add sp,8h
    mov word ptr [bp-16h],ax
    mov ax,0A4h
    push ax
    mov cx,0D9h
    push cx
    mov dx,1Fh
    push dx
    mov bx,65h
    push bx
    call mf71
    add sp,8h
    mov ax,14h
    push ax
    mov cx,0A4h
    push cx
    mov cx,0D9h
    push cx
    mov cx,1Fh
    push cx
    mov cx,65h
    push cx
    call mf83
    add sp,0Ah
    mov ax,14h
    push ax
    mov ax,0A3h
    push ax
    mov ax,0D8h
    push ax
    mov ax,20h
    push ax
    mov ax,66h
    push ax
    call mf95
    add sp,0Ah
    push word ptr [bp-16h]
    call mf98
    add sp,2h
    mov ax,30h
    push ax
    mov cx,17DCh
    push ds
    push cx
    mov cx,26h
    push cx
    mov cx,6Dh
    push cx
    call mf109
    add sp,0Ah
    mov ax,30h
    push ax
    mov cx,17E2h
    push ds
    push cx
    mov cx,4Ch
    push cx
    mov cx,6Dh
    push cx
    call mf120
    add sp,0Ah
    mov ax,30h
    push ax
    mov cx,17E8h
    push ds
    push cx
    mov cx,65h
    push cx
    mov cx,6Dh
    push cx
    call mf131
    add sp,0Ah
    mov ax,30h
    push ax
    mov cx,17EEh
    push ds
    push cx
    mov cx,79h
    push cx
    mov cx,6Dh
    push cx
    call mf142
    add sp,0Ah
    mov ax,30h
    push ax
    mov cx,17F3h
    push ds
    push cx
    mov cx,93h
    push cx
    mov dx,6Dh
    push dx
    call mf153
    add sp,0Ah
    mov ax,30h
    push ax
    mov ax,17F6h
    push ds
    push ax
    mov ax,93h
    push ax
    mov ax,0A2h
    push ax
    call mf164
    add sp,0Ah
    xor ax,ax
    push ax
    push ax
    mov cx,3Dh
    push cx
    mov dx,0CDh
    push dx
    mov bx,35h
    push bx
    mov si,6Dh
    push si
    push word ptr [bp-16h]
    call mf178
    add sp,0Eh
    mov word ptr [bp-28h],ax
    mov ax,18h
    push ax
    mov cx,3Fh
    push cx
    mov cx,0CFh
    push cx
    mov cx,33h
    push cx
    mov cx,6Bh
    push cx
    call mf191
    add sp,0Ah
    mov ax,18h
    push ax
    mov ax,3Eh
    push ax
    mov ax,0CEh
    push ax
    mov ax,34h
    push ax
    mov ax,6Ch
    push ax
    call mf203
    add sp,0Ah
    mov ax,0Fh
    push ax
    call mf207
    add sp,2h
    mov ax,3Dh
    push ax
    mov ax,0CDh
    push ax
    mov ax,35h
    push ax
    push si
    mov ax,1h
    push ax
    call mf218
    add sp,0Ah
    xor ax,ax
    push ax
    call mf222
    add sp,2h
    mov ax,3Ch
    push ax
    mov ax,0CCh
    push ax
    mov ax,36h
    push ax
    mov ax,6Eh
    push ax
    mov ax,2h
    push ax
    call mf234
    add sp,0Ah
    mov word ptr [bp-3Eh],77h
lbl236b:
    push word ptr [bp-3Eh]
    mov ax,36h
    push ax
    mov ax,0Fh
    push ax
    call mf242
    push word ptr [bp-3Eh]
    mov ax,3Ch
    push ax
    mov ax,0Fh
    push ax
    call mf248
    add word ptr [bp-3Eh],9h
    cmp word ptr [bp-3Eh],0C8h
    jng short lbl236b
    mov al,byte ptr ds:[416Eh]
    and ax, offset mi253
    mov word ptr [bp-2Ch],ax
    mov al,byte ptr ds:[416Eh]
    and ax, offset mi256
    mov word ptr [bp-2Eh],ax
    mov ax,word ptr ds:[6A1Ch]
    mov word ptr [bp-32h],ax
    mov ax,word ptr ds:[6A1Ah]
    mov word ptr [bp-30h],ax
    mov ax,word ptr ds:[27Eh]
    mov word ptr [bp-2Ah],ax
    mov cx,ax
    add ax,ax
    add ax,ax
    add ax,cx
    add ax,ax
    mov cx,7Fh
    cwd
    idiv cx
    mov word ptr ds:[5D96h],ax
    call mf273
    mov al,byte ptr ds:[416Eh]
    and ax, offset mi275
    push ax
    mov ax,26h
    push ax
    mov ax,0A5h
    push ax
    call mf281
    add sp,6h
    mov al,byte ptr ds:[416Eh]
    and ax, offset mi284
    push ax
    mov ax,4Ch
    push ax
    mov ax,0A5h
    push ax
    call mf290
    add sp,6h
    push word ptr ds:[6A1Ch]
    mov ax,65h
    push ax
    mov ax,0A5h
    push ax
    call mf297
    add sp,6h
    push word ptr ds:[6A1Ah]
    mov ax,79h
    push ax
    mov ax,0A5h
    push ax
    call mf304
    add sp,6h
    call mf306
lbl2F8b:
    mov word ptr [bp-1Ah],0h
    lea ax,word ptr [bp-3Ah]
    push ss
    push ax
    mov cx,3FFh
    push cx
    call mf313
    add sp,6h
    mov ax,word ptr [bp-3Ah]
    dec ax
    jz short lbl324f
    dec ax
    jnz short lbl31Af
    jmp near ptr lbl3BEf
lbl31Af:
    dec ax
    dec ax
    jnz short lbl321f
    jmp near ptr lbl3C4f
lbl321f:
    jmp near ptr lbl422f
lbl324f:
    mov bx,word ptr [bp-34h]
    test byte ptr [bx+56A5h],2h
    jz short lbl334f
    lea ax,word ptr [bx-20h]
    jmp short lbl336f
    nop
lbl334f:
    mov ax,bx
lbl336f:
    mov word ptr [bp-3Ch],ax
    cmp ax, offset mi334
    jz short lbl372f
    jg short lbl35Af
    cmp ax, offset mi337
    jz short lbl382f
    jna short lbl34Af
    jmp near ptr lbl422f
lbl34Af:
    sub al,0Dh
    jz short lbl372f
    sub al,0Eh
    jz short lbl37Af
    sub al,28h
    jz short lbl37Af
    jmp near ptr lbl422f
    nop
lbl35Af:
    sub ax, offset mi349
    jz short lbl38Af
    dec ax
    jz short lbl392f
    dec ax
    dec ax
    jz short lbl39Af
    sub ax,0F5h
    jz short lbl3A2f
    dec ax
    dec ax
    jz short lbl3B0f
    jmp near ptr lbl422f
lbl372f:
    mov word ptr [bp-1Ah],5h
    jmp near ptr lbl422f
lbl37Af:
    mov word ptr [bp-1Ah],6h
    jmp near ptr lbl422f
lbl382f:
    mov word ptr [bp-1Ah],1h
    jmp near ptr lbl422f
lbl38Af:
    mov word ptr [bp-1Ah],2h
    jmp near ptr lbl422f
lbl392f:
    mov word ptr [bp-1Ah],4h
    jmp near ptr lbl422f
lbl39Af:
    mov word ptr [bp-1Ah],3h
    jmp near ptr lbl422f
lbl3A2f:
    cmp word ptr ds:[5D96h],1h
    jng short lbl422f
    dec word ptr ds:[5D96h]
    jmp short lbl41Df
    nop
lbl3B0f:
    cmp word ptr ds:[5D96h],0Ah
    jnl short lbl422f
    inc word ptr ds:[5D96h]
    jmp short lbl41Df
    nop
lbl3BEf:
    cmp word ptr [bp-34h],0h
    jz short lbl422f
lbl3C4f:
    lea ax,word ptr [bp-20h]
    push ss
    push ax
    lea ax,word ptr [bp-1Eh]
    push ss
    push ax
    lea ax,word ptr [bp-1Ch]
    push ss
    push ax
    push word ptr [bp-36h]
    push word ptr [bp-38h]
    call mf397
    add sp,10h
    mov ax,word ptr [bp-16h]
    cmp word ptr [bp-1Ch],ax
    jnz short lbl422f
    cmp word ptr [bp-20h],5h
    jnz short lbl3F8f
    mov ax,word ptr [bp-1Eh]
    mov word ptr [bp-1Ah],ax
    jmp short lbl422f
    nop
lbl3F8f:
    mov ax,word ptr [bp-1Eh]
    cmp word ptr [bp-28h],ax
    jnz short lbl422f
    mov ax,word ptr [bp-38h]
    sub ax, offset mi412
    mov cx,9h
    cwd
    idiv cx
    inc ax
    mov word ptr [bp-26h],ax
    cmp ax, offset mi418
    jl short lbl422f
    cmp ax, offset mi420
    jg short lbl422f
    mov word ptr ds:[5D96h],ax
lbl41Df:
    call mf423
lbl422f:
    cmp word ptr [bp-1Ah],0h
    jz short lbl441f
    push word ptr [bp-1Ah]
    push word ptr [bp-16h]
    call mf428
    add sp,4h
    push word ptr [bp-1Ah]
    call mf431
    add sp,2h
lbl441f:
    cmp word ptr [bp-1Ah],6h
    jz short lbl450f
    cmp word ptr [bp-1Ah],5h
    jz short lbl450f
    jmp near ptr lbl2F8b
lbl450f:
    cmp word ptr [bp-1Ah],6h
    jnz short lbl488f
    mov ax,word ptr [bp-2Ah]
    mov word ptr ds:[27Eh],ax
    mov al,byte ptr ds:[416Eh]
    and ax, offset mi443
    cmp ax,word ptr [bp-2Ch]
    jz short lbl46Cf
    call mf446
lbl46Cf:
    mov al,byte ptr ds:[416Eh]
    and ax, offset mi448
    cmp ax,word ptr [bp-2Eh]
    jz short lbl47Cf
    call mf451
lbl47Cf:
    mov ax,word ptr [bp-32h]
    mov word ptr ds:[6A1Ch],ax
    mov ax,word ptr [bp-30h]
    mov word ptr ds:[6A1Ah],ax
lbl488f:
    push word ptr [bp-16h]
    call mf457
    add sp,2h
    lea ax,word ptr [bp-14h]
    push ss
    push ax
    call mf462
    add sp,4h
    lea ax,word ptr [bp-14h]
    push ss
    push ax
    call mf467
    add sp,4h
    push word ptr [bp-18h]
    call mf470
    add sp,2h
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
