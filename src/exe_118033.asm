_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf407:FAR
    EXTRN mf31a:FAR
    EXTRN mi378:NEAR
    EXTRN mf223:FAR
    EXTRN mf187:FAR
    EXTRN mf1d4:FAR
    EXTRN mfe4:FAR
    EXTRN mi261:NEAR
    EXTRN mf14:FAR
    EXTRN mf444:FAR
    EXTRN mf2dc:FAR
    EXTRN mf342:FAR
    EXTRN mf450:FAR
    EXTRN mf1ec:FAR
    EXTRN mf3c2:FAR
    EXTRN mf439:FAR
    EXTRN mf100:FAR
    EXTRN mfd0:FAR
    EXTRN mf1f:FAR
    EXTRN mf2f7:FAR
    EXTRN mf3d0:FAR
    EXTRN mf23e:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,96h
    push di
    push si
    cmp word ptr [bp+6h],0h
    jnl short lbl14f
    xor ax,ax
    jmp near ptr lbl45Bf
lbl14f:
    call mf14
    mov word ptr ds:[5218h],ax
    xor ax,ax
    push ax
    call mf1f
    add sp,2h
    mov word ptr [bp-0Ch],ax
    mov bx,word ptr [bp+6h]
    add bx,bx
    mov word ptr [bp-96h],bx
    cmp word ptr [bx+68D0h],0h
    jz short lblAEf
    mov bx,word ptr [bp+6h]
    add bx,bx
    add bx,bx
    mov ax,word ptr [bx+6962h]
    or ax,word ptr [bx+6960h]
    jnz short lblAEf
    mov cl,4h
    mov bx,word ptr [bp+6h]
    shl bx,cl
    add bx,68E0h
    mov dx,ds
    mov di,bx
    lea si,word ptr [bp-94h]
    mov es,dx
    push ds
    mov cx,0FFFFh
    xor ax,ax
    repne scasb
    not cx
    sub di,cx
    db 87h, 0FEh ; override
    shr cx,1
    rep movsw
    adc cx,cx
    rep movsb
    pop ds
    lea si,word ptr [bp-94h]
    push ds
    les di, dword ptr [bp+8h]
    mov cx,0FFFFh
    repne scasb
    not cx
    sub di,cx
    push cx
    db 87h, 0FEh ; override
    push ds
    push es
    pop ds
    pop es
    mov cx,0FFFFh
    repne scasb
    dec di
    pop cx
    shr cx,1
    rep movsw
    adc cx,cx
    rep movsb
    pop ds
    mov byte ptr [bx],al
    lea ax,word ptr [bp-94h]
    mov word ptr [bp-10h],ax
    mov word ptr [bp-0Eh],ss
    jmp short lblBAf
    nop
lblAEf:
    mov ax,word ptr [bp+8h]
    mov dx,word ptr [bp+0Ah]
    mov word ptr [bp-10h],ax
    mov word ptr [bp-0Eh],dx
lblBAf:
    mov bx,word ptr [bp-96h]
    mov ax,word ptr [bx+6880h]
    mov word ptr [bp-2h],ax
    mov ax,word ptr [bx+6850h]
    mov word ptr [bp-4h],ax
    push word ptr [bx+6810h]
    call mfd0
    add sp,2h
    mov bx,word ptr [bp-96h]
    push word ptr [bx+6830h]
    push word ptr [bx+6820h]
    call mfe4
    mov bx,word ptr [bp-96h]
    add sp,4h
    mov ax,word ptr [bx+68B0h]
    add ax,word ptr [bp-4h]
    push ax
    mov ax,word ptr [bx+68A0h]
    add ax,word ptr [bp-2h]
    push ax
    call mf100
    add sp,4h
    mov word ptr [bp-0Ah],0h
lbl10Db:
    les bx, dword ptr [bp-10h]
    cmp byte ptr es:[bx],0h
    jnz short lbl119f
    jmp near ptr lbl35Cf
lbl119f:
    mov word ptr [bp-14h],bx
    mov word ptr [bp-12h],es
    cmp byte ptr es:[bx],0h
    jz short lbl149f
lbl125b:
    cmp byte ptr es:[bx],20h
    jz short lbl149f
    cmp byte ptr es:[bx],9h
    jz short lbl149f
    cmp byte ptr es:[bx],0Ah
    jz short lbl149f
    cmp byte ptr es:[bx],2Dh
    jz short lbl149f
    inc word ptr [bp-14h]
    mov bx,word ptr [bp-14h]
    cmp byte ptr es:[bx],0h
    jnz short lbl125b
lbl149f:
    les bx, dword ptr [bp-14h]
    cmp byte ptr es:[bx],0h
    jnz short lbl171f
    mov bx,word ptr [bp-96h]
    cmp word ptr [bx+68D0h],0h
    jz short lbl171f
    mov bx,word ptr [bp+6h]
    add bx,bx
    add bx,bx
    mov ax,word ptr [bx+6962h]
    or ax,word ptr [bx+6960h]
    jnz short lbl171f
    jmp near ptr lbl35Cf
lbl171f:
    mov bx,word ptr [bp-14h]
    cmp byte ptr es:[bx],2Dh
    jnz short lbl17Df
    inc word ptr [bp-14h]
lbl17Df:
    push es
    push word ptr [bp-14h]
    push word ptr [bp-0Eh]
    push word ptr [bp-10h]
    call mf187
    add sp,8h
    mov word ptr [bp-6h],ax
    mov bx,word ptr [bp-96h]
    mov ax,word ptr [bx+6860h]
    sub ax,word ptr [bp-2h]
    sub ax,word ptr ds:[6DDAh]
    mov word ptr [bp-8h],ax
    sub ax,word ptr ds:[6DDAh]
    cmp ax,word ptr [bp-6h]
    jnl short lbl206f
    mov ax,word ptr [bx+68A0h]
    sub word ptr [bp-8h],ax
    mov word ptr [bp-6h],0h
    mov ax,word ptr [bp-10h]
    mov dx,word ptr [bp-0Eh]
    mov word ptr [bp-14h],ax
    mov word ptr [bp-12h],dx
    mov es,dx
    mov bx,ax
    cmp byte ptr es:[bx],0h
    jz short lbl232f
lbl1CFb:
    mov al,byte ptr es:[bx]
    cbw
    push ax
    call mf1d4
    add sp,2h
    add ax,word ptr [bp-6h]
    cmp ax,word ptr [bp-8h]
    jg short lbl232f
    les bx, dword ptr [bp-14h]
    mov al,byte ptr es:[bx]
    cbw
    push ax
    call mf1ec
    add sp,2h
    add word ptr [bp-6h],ax
    inc word ptr [bp-14h]
    les bx, dword ptr [bp-14h]
    cmp byte ptr es:[bx],0h
    jnz short lbl1CFb
    jmp short lbl232f
    nop
lbl206f:
    mov ax,word ptr [bp-6h]
    mov cx,word ptr [bx+68A0h]
    sub word ptr [bp-8h],cx
    cmp word ptr [bp-8h],ax
    jnl short lbl232f
    mov ax,word ptr [bp-8h]
    cwd
    idiv word ptr ds:[6D24h]
    add word ptr [bp-0Ah],ax
    push word ptr [bp+6h]
    call mf223
    add sp,2h
    or ax,ax
    jz short lbl232f
    jmp near ptr lbl40Ff
lbl232f:
    push word ptr [bp-12h]
    push word ptr [bp-14h]
    push word ptr [bp-0Eh]
    push word ptr [bp-10h]
    call mf23e
    add sp,8h
    mov bx,word ptr [bp-96h]
    mov ax,word ptr [bp-6h]
    add word ptr [bx+68A0h],ax
    mov ax,word ptr [bp-14h]
    sub ax,word ptr [bp-10h]
    add word ptr [bp-0Ah],ax
    les bx, dword ptr [bp-14h]
    mov al,byte ptr es:[bx]
    cbw
    cmp ax, offset mi261
    jnz short lbl269f
    jmp near ptr lbl30Af
lbl269f:
    ja short lbl273f
    sub al,9h
    jz short lbl27Cf
    dec al
    jz short lbl2E8f
lbl273f:
    mov word ptr [bp-10h],bx
    mov word ptr [bp-0Eh],es
    jmp near ptr lbl10Db
lbl27Cf:
    inc word ptr [bp-14h]
    mov ax,word ptr [bp-14h]
    mov word ptr [bp-10h],ax
    mov word ptr [bp-0Eh],es
    mov bx,word ptr [bp-96h]
    mov ax,word ptr [bx+6860h]
    sub ax,word ptr [bx+68A0h]
    sub ax,word ptr [bp-2h]
    sub ax,word ptr ds:[6DDAh]
    cmp ax,word ptr ds:[6DFCh]
    jg short lbl2A4f
    jmp near ptr lbl10Db
lbl2A4f:
    mov ax,word ptr [bx+68A0h]
    sub ax,word ptr ds:[6DDAh]
    cwd
    idiv word ptr ds:[6DFCh]
    inc ax
    imul word ptr ds:[6DFCh]
    mov word ptr [bp-6h],ax
    add ax,word ptr ds:[6DDAh]
    mov word ptr [bx+68A0h],ax
    mov ax,word ptr [bp-6h]
    cwd
    idiv word ptr ds:[6D24h]
    add word ptr [bp-0Ah],ax
    mov ax,word ptr [bx+68B0h]
    add ax,word ptr [bp-4h]
    push ax
    mov ax,word ptr [bx+68A0h]
    add ax,word ptr [bp-2h]
    push ax
    call mf2dc
    add sp,4h
    jmp near ptr lbl10Db
    nop
lbl2E8f:
    inc word ptr [bp-14h]
    mov ax,word ptr [bp-14h]
    mov word ptr [bp-10h],ax
    mov word ptr [bp-0Eh],es
lbl2F4b:
    push word ptr [bp+6h]
    call mf2f7
    add sp,2h
    or ax,ax
    jnz short lbl306f
    jmp near ptr lbl10Db
lbl306f:
    jmp near ptr lbl40Ff
    nop
lbl30Af:
    inc word ptr [bp-14h]
    mov ax,word ptr [bp-14h]
    mov word ptr [bp-10h],ax
    mov word ptr [bp-0Eh],es
    mov ax,20h
    push ax
    call mf31a
    add sp,2h
    mov word ptr [bp-6h],ax
    mov bx,word ptr [bp-96h]
    mov ax,word ptr [bx+6860h]
    sub ax,word ptr [bx+68A0h]
    sub ax,word ptr [bp-2h]
    sub ax,word ptr ds:[6DDAh]
    cmp ax,word ptr [bp-6h]
    jl short lbl2F4b
    mov ax,522Ch
    push ds
    push ax
    call mf342
    add sp,4h
    mov bx,word ptr [bp-96h]
    mov ax,word ptr [bp-6h]
    add word ptr [bx+68A0h],ax
    inc word ptr [bp-0Ah]
    jmp near ptr lbl10Db
    nop
lbl35Cf:
    mov ax,word ptr [bp-10h]
    cmp word ptr [bp-14h],ax
    ja short lbl367f
    jmp near ptr lbl3E9f
lbl367f:
    mov bx,word ptr [bp-96h]
    cmp word ptr [bx+68D0h],0h
    jz short lbl3BCf
    mov ax,word ptr [bp-14h]
    sub ax,word ptr [bp-10h]
    cmp ax, offset mi378
    jnc short lbl3BCf
    mov bx,word ptr [bp+6h]
    add bx,bx
    add bx,bx
    mov ax,word ptr [bx+6962h]
    or ax,word ptr [bx+6960h]
    jnz short lbl3BCf
    mov cl,4h
    mov bx,word ptr [bp+6h]
    shl bx,cl
    add bx,68E0h
    push ds
    mov si,bx
    les di, dword ptr [bp-10h]
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
    jmp short lbl3E9f
    nop
lbl3BCf:
    push word ptr [bp-0Eh]
    push word ptr [bp-10h]
    call mf3c2
    add sp,4h
    push word ptr [bp-0Eh]
    push word ptr [bp-10h]
    call mf3d0
    mov bx,word ptr [bp-96h]
    add sp,4h
    add word ptr [bx+68A0h],ax
    mov ax,word ptr [bp-14h]
    sub ax,word ptr [bp-10h]
    add word ptr [bp-0Ah],ax
lbl3E9f:
    mov bx,word ptr [bp-96h]
    mov ax,word ptr [bx+6860h]
    sub ax,word ptr [bp-2h]
    sub ax,word ptr ds:[6DDAh]
    cmp ax,word ptr [bx+68A0h]
    jg short lbl40Ff
    cmp word ptr [bp-0Ch],0h
    jz short lbl40Ff
    push word ptr [bp+6h]
    call mf407
    add sp,2h
lbl40Ff:
    mov ax,word ptr ds:[51DCh]
    or ax,word ptr ds:[51DAh]
    jz short lbl425f
    mov ax,word ptr [bp-10h]
    mov dx,word ptr [bp-0Eh]
    mov word ptr ds:[51DAh],ax
    mov word ptr ds:[51DCh],dx
lbl425f:
    mov bx,word ptr [bp-96h]
    mov ax,word ptr [bx+68B0h]
    add ax,word ptr [bp-4h]
    push ax
    mov ax,word ptr [bx+68A0h]
    add ax,word ptr [bp-2h]
    push ax
    call mf439
    add sp,4h
    push word ptr [bp-0Ch]
    call mf444
    add sp,2h
    push word ptr ds:[5218h]
    call mf450
    add sp,2h
    mov ax,word ptr [bp-0Ah]
lbl45Bf:
    pop si
    pop di
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
