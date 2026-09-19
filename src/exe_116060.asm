_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf19f:FAR
    EXTRN mfc1:FAR
    EXTRN mf303:FAR
    EXTRN mf1e0:FAR
    EXTRN mi337:NEAR
    EXTRN mf4c:FAR
    EXTRN mf214:FAR
    EXTRN mf2a0:FAR
    EXTRN mf316:FAR
    EXTRN mf3c3:FAR
    EXTRN mf1d4:FAR
    EXTRN mf35c:FAR
    EXTRN mfa8:FAR
    EXTRN mf294:FAR
    EXTRN mf374:FAR
    EXTRN mf2ce:FAR
    EXTRN mf1eb:FAR
    EXTRN mf3a0:FAR
    EXTRN mf3b1:FAR
    EXTRN mf2b8:FAR
    EXTRN mf245:FAR
    EXTRN mf352:FAR
    EXTRN mf357:FAR
    EXTRN mf193:FAR
    EXTRN mf183:FAR
    EXTRN mf2a:FAR
    EXTRN mf1ba:FAR
    EXTRN mf398:FAR
    EXTRN mf361:FAR
    EXTRN mf208:FAR
    EXTRN mf23d:FAR
    EXTRN mf1c9:FAR
    EXTRN mi38c:NEAR
    EXTRN mf286:FAR
    EXTRN mf27e:FAR
    EXTRN mf344:FAR
    EXTRN mf24e:FAR
    EXTRN mf33c:FAR
    EXTRN mf3a9:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,1Ch
    push di
    push si
    mov bx,word ptr [bp+6h]
    add bx,bx
    add bx,bx
    mov ax,word ptr [bx+6960h]
    mov dx,word ptr [bx+6962h]
    mov word ptr [bp-4h],ax
    mov word ptr [bp-2h],dx
    or dx,ax
    jnz short lbl36f
    push word ptr [bp+0Ah]
    push word ptr [bp+8h]
    push word ptr [bp+6h]
    call mf2a
    add sp,6h
    jmp near ptr lbl3DFf
    nop
lbl36f:
    mov ax,word ptr ds:[51E0h]
    mov word ptr [bp-16h],ax
    mov ax,word ptr [bp+6h]
    mov word ptr ds:[51E0h],ax
    mov ax,0Bh
    push ax
    push word ptr [bp+0Ah]
    push word ptr [bp+8h]
    call mf4c
    add sp,6h
    mov word ptr [bp-1Ah],ax
    mov word ptr [bp-18h],dx
    or dx,ax
    jz short lbl65f
    les bx, dword ptr [bp-1Ah]
    mov byte ptr es:[bx],0h
lbl65f:
    les di, dword ptr [bp+8h]
    mov cx,0FFFFh
    xor ax,ax
    repne scasb
    not cx
    mov word ptr [bp-0Ah],cx
    les bx, dword ptr [bp-4h]
    mov ax,word ptr es:[bx+2h]
    or ax,word ptr es:[bx]
    jz short lblBCf
    mov ax,word ptr es:[bx]
    mov dx,word ptr es:[bx+2h]
    mov di,ax
    mov es,dx
    mov cx,0FFFFh
    xor ax,ax
    repne scasb
    not cx
    dec cx
    add word ptr [bp-0Ah],cx
    mov ax,word ptr [bp-0Ah]
    cwd
    push dx
    push ax
    les bx, dword ptr [bp-4h]
    push word ptr es:[bx+2h]
    push word ptr es:[bx]
    call mfa8
    add sp,8h
    les bx, dword ptr [bp-4h]
    mov word ptr es:[bx],ax
    mov word ptr es:[bx+2h],dx
    jmp short lblDAf
lblBCf:
    mov ax,cx
    cwd
    push dx
    push cx
    call mfc1
    add sp,4h
    les bx, dword ptr [bp-4h]
    mov word ptr es:[bx],ax
    mov word ptr es:[bx+2h],dx
    les bx, dword ptr es:[bx]
    mov byte ptr es:[bx],0h
lblDAf:
    les bx, dword ptr [bp-4h]
    mov si,word ptr es:[bx]
    mov cx,word ptr es:[bx+2h]
    push ds
    mov ds,cx
    les di, dword ptr [bp+8h]
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
    mov ax,word ptr [bp-18h]
    or ax,word ptr [bp-1Ah]
    jnz short lbl117f
    jmp near ptr lbl3D7f
lbl117f:
    les bx, dword ptr [bp-4h]
    les bx, dword ptr es:[bx]
    mov word ptr [bp-1Ah],bx
    mov word ptr [bp-18h],es
    cmp byte ptr es:[bx],0h
    jz short lbl135f
lbl129b:
    inc word ptr [bp-1Ah]
    mov bx,word ptr [bp-1Ah]
    cmp byte ptr es:[bx],0h
    jnz short lbl129b
lbl135f:
    mov ax,bx
    les bx, dword ptr [bp-4h]
    cmp word ptr es:[bx],ax
    jnc short lbl155f
lbl13Fb:
    les bx, dword ptr [bp-1Ah]
    cmp byte ptr es:[bx-1h],0Ah
    jnz short lbl155f
    dec ax
    mov word ptr [bp-1Ah],ax
    les bx, dword ptr [bp-4h]
    cmp ax,word ptr es:[bx]
    ja short lbl13Fb
lbl155f:
    les bx, dword ptr [bp-1Ah]
    mov byte ptr es:[bx],0h
    mov bx,word ptr [bp+6h]
    add bx,bx
    mov ax,word ptr [bx+6840h]
    mov word ptr [bp-0Ch],ax
    mov ax,word ptr [bx+6850h]
    mov word ptr [bp-0Eh],ax
    mov ax,word ptr [bx+6860h]
    mov word ptr [bp-10h],ax
    mov ax,word ptr [bx+6870h]
    mov word ptr [bp-14h],ax
    push word ptr [bx+6810h]
    mov si,bx
    call mf183
    add sp,2h
    push word ptr [si+6830h]
    push word ptr [si+6820h]
    call mf193
    add sp,4h
    mov ax,0FFFFh
    push ax
    call mf19f
    add sp,2h
    push word ptr [bp-10h]
    push word ptr [bp-0Eh]
    push word ptr [bp-0Ch]
    les bx, dword ptr [bp-4h]
    push word ptr es:[bx+2h]
    push word ptr es:[bx]
    call mf1ba
    add sp,0Ah
    mov word ptr [bp-12h],ax
    mov ax,2h
    push ax
    call mf1c9
    add sp,2h
    xor ax,ax
    push ax
    call mf1d4
    add sp,2h
    mov ax,17h
    push ax
    call mf1e0
    add sp,2h
    push word ptr [bp+6h]
    call mf1eb
    add sp,2h
    mov ax,word ptr [bp-12h]
    cmp word ptr [bp-14h],ax
    jl short lbl214f
    les bx, dword ptr [bp-4h]
    push word ptr es:[bx+2h]
    push word ptr es:[bx]
    push word ptr [bp+6h]
    call mf208
    add sp,6h
    jmp near ptr lbl3AEf
    nop
lbl214f:
    call mf214
    cmp word ptr [bp-12h],0C5h
    jng short lbl24Af
    mov ax,word ptr ds:[6D48h]
    add word ptr [bp-12h],ax
    cmp word ptr [bp-12h],0C5h
    jng short lbl23Af
lbl22Db:
    mov ax,word ptr ds:[69F8h]
    sub word ptr [bp-12h],ax
    cmp word ptr [bp-12h],0C5h
    jg short lbl22Db
lbl23Af:
    push word ptr [bp+6h]
    call mf23d
    add sp,2h
    call mf245
lbl24Af:
    xor ax,ax
    push ax
    push ax
    call mf24e
    add sp,4h
    mov ax,0C7h
    push ax
    mov cx,word ptr [bp-10h]
    inc cx
    push cx
    inc word ptr [bp-0Eh]
    mov dx,word ptr [bp-0Eh]
    dec dx
    push dx
    mov bx,word ptr [bp-0Ch]
    dec bx
    push bx
    mov si,word ptr [bp-4h]
    mov di,word ptr [bp-2h]
    add si,18h
    push di
    push si
    mov si,cx
    mov di,dx
    mov word ptr [bp-1Ch],bx
    call mf27e
    add sp,0Ch
    call mf286
    mov ax,0C7h
    push ax
    push si
    push di
    push word ptr [bp-1Ch]
    call mf294
    add sp,8h
    mov ax,17h
    push ax
    call mf2a0
    add sp,2h
    push word ptr [bp-12h]
    push word ptr [bp-10h]
    push word ptr [bp-0Eh]
    push word ptr [bp-0Ch]
    mov ax,2h
    push ax
    call mf2b8
    add sp,0Ah
    mov ax,10h
    push ax
    mov ax,word ptr [bp-12h]
    inc ax
    push ax
    push si
    push di
    push word ptr [bp-1Ch]
    call mf2ce
    add sp,0Ah
    mov bx,word ptr [bp+6h]
    add bx,bx
    cmp word ptr [bx+68C0h],0FFFFFFFFFFFFFFFFh
    jnz short lbl2E8f
    mov ax,word ptr ds:[69F8h]
    add word ptr [bp-12h],ax
lbl2E8f:
    mov ax,word ptr [bp-12h]
    mov bx,word ptr [bp+6h]
    add bx,bx
    mov word ptr [bx+6870h],ax
    les si, dword ptr [bp-4h]
    push word ptr es:[si+2h]
    push word ptr es:[si]
    push word ptr [bp+6h]
    mov di,bx
    call mf303
    add sp,6h
    mov ax,word ptr [bp-14h]
    mov word ptr [di+6870h],ax
    xor ax,ax
    push ax
    push ax
    call mf316
    add sp,4h
    mov ax,0C7h
    push ax
    mov ax,word ptr [bp-10h]
    inc ax
    push ax
    mov ax,word ptr [bp-0Eh]
    dec ax
    push ax
    mov ax,word ptr [bp-0Ch]
    dec ax
    push ax
    mov ax,word ptr [bp-4h]
    mov dx,word ptr [bp-2h]
    add ax, offset mi337
    push dx
    push ax
    call mf33c
    add sp,0Ch
    call mf344
    les bx, dword ptr [bp-4h]
    mov word ptr es:[bx+2Ch],1h
    call mf352
    call mf357
    call mf35c
    call mf361
    or ax,ax
    jnz short lbl3A9f
lbl36Ab:
    lea ax,word ptr [bp-8h]
    push ss
    push ax
    lea ax,word ptr [bp-6h]
    push ss
    push ax
    call mf374
    add sp,8h
    or ax,ax
    jnz short lbl3A9f
    mov ax,word ptr [bp-0Ch]
    dec ax
    cmp ax,word ptr [bp-6h]
    jg short lbl3A9f
    mov ax,word ptr [bp-0Eh]
    add ax, offset mi38c
    cmp ax,word ptr [bp-8h]
    jg short lbl3A9f
    mov ax,1h
    push ax
    call mf398
    add sp,2h
    call mf3a0
    or ax,ax
    jz short lbl36Ab
lbl3A9f:
    call mf3a9
lbl3AEf:
    xor ax,ax
    push ax
    call mf3b1
    add sp,2h
    les bx, dword ptr [bp-4h]
    push word ptr es:[bx+2h]
    push word ptr es:[bx]
    call mf3c3
    add sp,4h
    les bx, dword ptr [bp-4h]
    sub ax,ax
    mov word ptr es:[bx+2h],ax
    mov word ptr es:[bx],ax
lbl3D7f:
    mov ax,word ptr [bp-16h]
    mov word ptr ds:[51E0h],ax
    xor ax,ax
lbl3DFf:
    pop si
    pop di
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
