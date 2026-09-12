_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf5:FAR
    EXTRN mf9:FAR
    EXTRN mf16:FAR
    EXTRN mf33:FAR
    EXTRN mf35:FAR
    EXTRN mf48:FAR
    EXTRN mf56:FAR
    EXTRN mf108:FAR
    EXTRN mf116:FAR
    EXTRN mi122:NEAR
    EXTRN mf125:FAR
    EXTRN mf147:FAR
    EXTRN mf150:FAR
    EXTRN mf154:FAR
    EXTRN mf160:FAR
    EXTRN mf177:FAR
    EXTRN mf180:FAR
    EXTRN mi183:NEAR
    EXTRN mi186:NEAR
    EXTRN mf189:FAR
    EXTRN mf192:FAR
    EXTRN mf203:FAR
    EXTRN mf203:FAR
    EXTRN mf203:FAR
    EXTRN mf203:FAR
    EXTRN mf203:FAR
    EXTRN mf203:FAR
    EXTRN mf203:FAR
    EXTRN mf203:FAR
    EXTRN mf203:FAR
    EXTRN mf203:FAR
    EXTRN mf203:FAR
    EXTRN mf203:FAR
    EXTRN mf203:FAR
    EXTRN mf203:FAR
    EXTRN mf203:FAR
    EXTRN mf203:FAR
    EXTRN mf203:FAR
    EXTRN mf203:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,1Ch
    push di
    push si
    call mf5
    or ax,ax
    jz short lbl14f
    jmp near ptr lbl234f
lbl14f:
    call mf9
    or ax,ax
    jz short lbl20f
    jmp near ptr lbl234f
lbl20f:
    cmp word ptr ds:[5D8Ah],0F8BCh
    jnl short lbl2Bf
    jmp near ptr lbl234f
lbl2Bf:
    call mf16
    cmp dx,word ptr ds:[5D88h]
    jg short lbl44f
    jl short lbl3Ef
    cmp ax,word ptr ds:[5D86h]
    jnc short lbl44f
lbl3Eb:
lbl3Ef:
    mov ax,1h
    jmp near ptr lbl236f
lbl44f:
    dec word ptr ds:[5D8Ah]
    mov ax,0A1h
    push ax
    mov ax,14h
    push ax
    xor cx,cx
    push cx
    mov dx,1h
    push dx
    call mf33
    add sp,8h
    call mf35
    mov cx,ax
    mov ax,word ptr ds:[5D84h]
    mov bx,dx
    cwd
    add cx,ax
    adc bx,dx
    mov word ptr ds:[5D86h],cx
    mov word ptr ds:[5D88h],bx
    mov ax,14h
    push ax
    xor ax,ax
    push ax
    call mf48
    add sp,4h
    mov word ptr [bp-1Ah],ax
    mov word ptr [bp-18h],dx
    mov ax,15h
    push ax
    xor ax,ax
    push ax
    call mf56
    add sp,4h
    push ds
    mov si,ax
    mov ds,dx
    les di, dword ptr [bp-1Ah]
    mov cx,6AE0h
    rep movsw
    pop ds
    mov ax,0A4h
    sub ax,word ptr ds:[69F8h]
    mov word ptr [bp-0Eh],ax
    mov ax,word ptr ds:[5D8Ah]
    mov word ptr [bp-0Ch],ax
    mov word ptr [bp-1Ch],69Eh
lblBFb:
    cmp word ptr [bp-0Ch],0B4h
    jl short lblC9f
    jmp near ptr lbl3Eb
lblC9f:
    mov bx,word ptr [bp-1Ch]
    mov es, ds:[5A6Ch]
    mov ax,word ptr es:[bx]
    mov word ptr [bp-4h],ax
    dec ax
    dec ax
    jz short lblEAf
    sub ax,0FFh
    jz short lblF2f
    sub ax,100h
    jz short lblF8f
    add word ptr [bp-0Ch],14h
    jmp short lblFCf
lblEAf:
    mov ax,word ptr ds:[69F8h]
    add word ptr [bp-0Ch],ax
    jmp short lblFCf
lblF2f:
    add word ptr [bp-0Ch],28h
    jmp short lblFCf
lblF8f:
    add word ptr [bp-0Ch],50h
lblFCf:
    mov byte ptr [bp-3h],0h
    cmp word ptr [bp-0Ch],24h
    jl short lbl111f
    mov ax,word ptr [bp-0Ch]
    cmp word ptr [bp-0Eh],ax
    jl short lbl111f
    jmp near ptr lbl1C7f
lbl111f:
    mov bx,word ptr [bp-1Ch]
    mov es, ds:[5A6Ch]
    mov ax,word ptr es:[bx+2h]
    mov dx,word ptr es:[bx+4h]
    mov word ptr [bp-16h],ax
    mov word ptr [bp-14h],dx
    push dx
    push ax
    call mf108
    add sp,4h
    mov word ptr [bp-6h],ax
    mov ax,1762h
    push ds
    push ax
    push word ptr [bp-14h]
    push word ptr [bp-16h]
    call mf116
    add sp,8h
    mov word ptr [bp-10h],dx
    or dx,ax
    jz short lbl166f
    mov dx,word ptr [bp-10h]
    add ax, offset mi122
    push dx
    push ax
    call mf125
    add sp,4h
    sub ax,word ptr [bp-6h]
    add ax,0A0h
    jmp short lbl171f
    nop
lbl166f:
    mov ax,13Fh
    sub ax,word ptr [bp-6h]
    cwd
    sub ax,dx
    sar ax,1
lbl171f:
    mov word ptr [bp-8h],ax
    add ax,word ptr [bp-6h]
    mov word ptr [bp-0Ah],ax
    cmp word ptr [bp-0Ch],14h
    jl short lbl1C7f
    cmp word ptr [bp-0Ch],0B4h
    jg short lbl1C7f
    mov ax,0FFFFh
    push ax
    push word ptr [bp-0Ch]
    push word ptr [bp-4h]
    call mf147
    add sp,4h
    push ax
    call mf150
    add sp,4h
    push word ptr [bp-0Ch]
    push word ptr [bp-8h]
    call mf154
    add sp,4h
    mov es, ds:[5A6Ch]
    mov bx,word ptr [bp-1Ch]
    push word ptr es:[bx+4h]
    push word ptr es:[bx+2h]
    call mf160
    add sp,4h
lbl1C7f:
    cmp word ptr [bp-4h],1h
    jnz short lbl223f
    mov ax,word ptr ds:[69F8h]
    add word ptr [bp-0Ch],ax
    cmp word ptr [bp-0Ch],24h
    jl short lbl1E0f
    cmp word ptr [bp-0Ch],0A4h
    jng short lbl223f
lbl1E0f:
    cmp word ptr [bp-0Ch],14h
    jl short lbl223f
    cmp word ptr [bp-0Ch],0B1h
    jg short lbl223f
    push word ptr [bp-0Ch]
    mov ax,2h
    push ax
    call mf177
    add sp,4h
    push ax
    call mf180
    add sp,2h
    mov ax,word ptr [bp-8h]
    sub ax, offset mi183
    push ax
    mov ax,word ptr [bp-0Ch]
    add ax, offset mi186
    push ax
    mov si,ax
    call mf189
    push word ptr [bp-0Ah]
    push si
    call mf192
lbl223f:
    add word ptr [bp-1Ch],6h
    cmp word ptr [bp-1Ch],9B6h
    jnc short lbl231f
    jmp near ptr lblBFb
lbl231f:
    jmp near ptr lbl3Eb
lbl234f:
    xor ax,ax
lbl236f:
    pop si
    pop di
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
