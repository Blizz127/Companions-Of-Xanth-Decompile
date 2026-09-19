_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN md2b7:NEAR
    EXTRN md287:NEAR
    EXTRN md28c:NEAR
    EXTRN md2bc:NEAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,18h
    push di
    push si
    mov byte ptr ds:[5DC4h],0h
    cmp word ptr [bp+6h],0h
    jnz short lbl24f
    mov ax,5DC4h
    mov di,ax
    mov si,1A54h
    push ds
    pop es
    movsw
    movsw
    movsb
    db 0E9h, 0C6h, 03h ; override
    nop
lbl24f:
    mov word ptr [bp-2h],0h
    mov word ptr [bp-0Eh],34h
lbl2Eb:
    mov bx,word ptr [bp-0Eh]
    mov es, ds:[5A88h]
    mov al,byte ptr es:[bx]
    sub ah,ah
    cmp ax,word ptr [bp+6h]
    jnz short lbl42f
    jmp near ptr lbl27Cf
lbl42f:
    inc word ptr [bp-2h]
    add word ptr [bp-0Eh],6h
    cmp word ptr [bp-0Eh],0D6h
    jc short lbl2Eb
    mov ax,word ptr [bp+6h]
    mov cx,3E8h
    cwd
    idiv cx
    mov word ptr [bp-4h],ax
    mov cx,0FC18h
    imul cx
    add ax,word ptr [bp+6h]
    mov cx,64h
    cwd
    idiv cx
    mov word ptr [bp-6h],ax
    mov cx,word ptr [bp-4h]
    mov dx,cx
    add cx,cx
    add cx,cx
    add cx,dx
    add cx,cx
    add ax,cx
    mov cx,0FF9Ch
    mov bx,ax
    imul cx
    add ax,word ptr [bp+6h]
    mov word ptr [bp-0Ch],ax
    mov ax,word ptr [bp+6h]
    mov cx,0Ah
    cwd
    idiv cx
    mov dx,bx
    add bx,bx
    add bx,bx
    add bx,dx
    add bx,bx
    sub ax,bx
    mov dx,ax
    add ax,ax
    add ax,ax
    add ax,dx
    add ax,ax
    mov word ptr [bp-8h],ax
    mov ax,word ptr [bp+6h]
    cwd
    idiv cx
    mov word ptr [bp-0Ah],dx
    cmp word ptr [bp-4h],0h
    jnz short lblBDf
    jmp near ptr lbl13Ff
lblBDf:
    mov word ptr [bp-10h],34h
lblC2b:
    mov bx,word ptr [bp-10h]
    mov es, ds:[5A88h]
    mov al,byte ptr es:[bx]
    sub ah,ah
    cmp ax,word ptr [bp-4h]
    jnz short lbl134f
    sub bx,4h
    mov si,word ptr es:[bx]
    mov cx,word ptr es:[bx+2h]
    mov di,si
    mov si,5DC4h
    mov es,cx
    push ds
    mov cx,0FFFFh
    xor ax,ax
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
    mov di,1A59h
    mov si,5DC4h
    mov cx,ds
    mov es,cx
    push ds
    mov cx,0FFFFh
    repne scasb
    not cx
    sub di,cx
    mov bx,cx
    db 87h, 0FEh ; override
    push ds
    push es
    pop ds
    pop es
    mov cx,0FFFFh
    repne scasb
    dec di
    mov cx,bx
    shr cx,1
    rep movsw
    adc cx,cx
    rep movsb
    pop ds
lbl134f:
    add word ptr [bp-10h],6h
    cmp word ptr [bp-10h],0D6h
    jc short lblC2b
lbl13Ff:
    cmp word ptr [bp-6h],0h
    jnz short lbl148f
    jmp near ptr lbl20Cf
lbl148f:
    mov word ptr [bp-12h],34h
lbl14Db:
    mov bx,word ptr [bp-12h]
    mov es, ds:[5A88h]
    mov al,byte ptr es:[bx]
    sub ah,ah
    cmp ax,word ptr [bp-6h]
    jz short lbl161f
    jmp near ptr lbl1FEf
lbl161f:
    cmp word ptr [bp-4h],0h
    jz short lbl196f
    mov di,1A63h
    mov si,5DC4h
    mov cx,ds
    mov es,cx
    push ds
    mov cx,0FFFFh
    xor ax,ax
    repne scasb
    not cx
    sub di,cx
    mov bx,cx
    db 87h, 0FEh ; override
    push ds
    push es
    pop ds
    pop es
    mov cx,0FFFFh
    repne scasb
    dec di
    mov cx,bx
    shr cx,1
    rep movsw
    adc cx,cx
    rep movsb
    pop ds
lbl196f:
    mov es, ds:[5A88h]
    mov bx,word ptr [bp-12h]
    sub bx,4h
    mov si,word ptr es:[bx]
    mov cx,word ptr es:[bx+2h]
    mov di,si
    mov si,5DC4h
    mov es,cx
    push ds
    mov cx,0FFFFh
    xor ax,ax
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
    mov di,1A65h
    mov si,5DC4h
    mov cx,ds
    mov es,cx
    push ds
    mov cx,0FFFFh
    repne scasb
    not cx
    sub di,cx
    mov bx,cx
    db 87h, 0FEh ; override
    push ds
    push es
    pop ds
    pop es
    mov cx,0FFFFh
    repne scasb
    dec di
    mov cx,bx
    shr cx,1
    rep movsw
    adc cx,cx
    rep movsb
    pop ds
lbl1FEf:
    add word ptr [bp-12h],6h
    cmp word ptr [bp-12h],0D6h
    jnc short lbl20Cf
    jmp near ptr lbl14Db
lbl20Cf:
    cmp word ptr [bp-0Ch],0h
    jnz short lbl215f
    db 0E9h, 0D9h, 00h ; override
lbl215f:
    cmp word ptr [bp-6h],0h
    jnz short lbl221f
    cmp word ptr [bp-4h],0h
    jz short lbl250f
lbl221f:
    mov di,1A6Eh
    mov si,5DC4h
    mov cx,ds
    mov es,cx
    push ds
    mov cx,0FFFFh
    xor ax,ax
    repne scasb
    not cx
    sub di,cx
    mov bx,cx
    db 87h, 0FEh ; override
    push ds
    push es
    pop ds
    pop es
    mov cx,0FFFFh
    repne scasb
    dec di
    mov cx,bx
    shr cx,1
    rep movsw
    adc cx,cx
    rep movsb
    pop ds
lbl250f:
    mov word ptr [bp-2h],0h
    mov word ptr [bp-14h],34h
lbl25Ab:
    mov bx,word ptr [bp-14h]
    mov es, ds:[5A88h]
    mov al,byte ptr es:[bx]
    sub ah,ah
    cmp ax,word ptr [bp-0Ch]
    db 74h, 41h ; override
    inc word ptr [bp-2h]
    add word ptr [bp-14h],6h
    cmp word ptr [bp-14h],0D6h
    jc short lbl25Ab
    db 0EBh, 73h ; override
    nop
lbl27Cf:
    mov bx,word ptr [bp-2h]
    mov ax,bx
    add bx,bx
    add bx,ax
    add bx,bx
    mov si,word ptr es:[bx+md287]
    mov cx,word ptr es:[bx+md28c]
    mov di,si
    mov si,5DC4h
    mov es,cx
    push ds
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
    db 0EBh, 36h ; override
lbl2ACf:
    mov bx,word ptr [bp-2h]
    mov ax,bx
    add bx,bx
    add bx,ax
    add bx,bx
    mov si,word ptr es:[bx+md2b7]
    mov cx,word ptr es:[bx+md2bc]
    mov di,si
    mov si,5DC4h
    mov es,cx
    push ds
    mov cx,0FFFFh
    xor ax,ax
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
lbl2E2f:
    shr cx,1
    rep movsw
    adc cx,cx
    rep movsb
    pop ds
    jmp near ptr lbl3E6f
lbl2EEf:
    cmp word ptr [bp-8h],0h
    jz short lbl349f
    mov word ptr [bp-16h],34h
lbl2F9b:
    mov bx,word ptr [bp-16h]
    mov es, ds:[5A88h]
    mov al,byte ptr es:[bx]
    sub ah,ah
    cmp ax,word ptr [bp-8h]
    jnz short lbl33Ef
    sub bx,4h
    mov si,word ptr es:[bx]
    mov cx,word ptr es:[bx+2h]
    mov di,si
    mov si,5DC4h
    mov es,cx
    push ds
    mov cx,0FFFFh
    xor ax,ax
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
lbl33Ef:
    add word ptr [bp-16h],6h
    cmp word ptr [bp-16h],0D6h
    jc short lbl2F9b
lbl349f:
    cmp word ptr [bp-0Ah],0h
    jnz short lbl352f
    jmp near ptr lbl3E6f
lbl352f:
    mov word ptr [bp-18h],34h
lbl357b:
    mov bx,word ptr [bp-18h]
    mov es, ds:[5A88h]
    mov al,byte ptr es:[bx]
    sub ah,ah
    cmp ax,word ptr [bp-0Ah]
    jnz short lbl3D8f
    cmp word ptr [bp-8h],0h
    jz short lbl39Df
    mov di,1A74h
    mov si,5DC4h
    mov cx,ds
    mov es,cx
    push ds
    mov cx,0FFFFh
    xor ax,ax
    repne scasb
    not cx
    sub di,cx
    mov bx,cx
    db 87h, 0FEh ; override
    push ds
    push es
    pop ds
    pop es
    mov cx,0FFFFh
    repne scasb
    dec di
    mov cx,bx
    shr cx,1
    rep movsw
    adc cx,cx
    rep movsb
    pop ds
lbl39Df:
    mov es, ds:[5A88h]
    mov bx,word ptr [bp-18h]
    sub bx,4h
    mov si,word ptr es:[bx]
    mov cx,word ptr es:[bx+2h]
    mov di,si
    mov si,5DC4h
    mov es,cx
    push ds
    mov cx,0FFFFh
    xor ax,ax
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
lbl3D8f:
    add word ptr [bp-18h],6h
    cmp word ptr [bp-18h],0D6h
    jnc short lbl3E6f
    jmp near ptr lbl357b
lbl3E6f:
    mov ax,5DC4h
lbl3E9f:
    mov dx,ds
    pop si
    pop di
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
