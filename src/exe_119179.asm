_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf14:FAR
    EXTRN mf58:FAR
    EXTRN mi75:NEAR
    EXTRN mi111:NEAR
    EXTRN mi158:NEAR
    EXTRN mi194:NEAR
    EXTRN mi195:NEAR
    EXTRN mf267:FAR
    EXTRN mf279:FAR
    EXTRN mf288:FAR
    EXTRN mf304:FAR
    EXTRN mf337:FAR
    EXTRN mi355:NEAR
    EXTRN mf370:FAR
    EXTRN mf389:FAR
    EXTRN mf397:FAR
    EXTRN mf409:FAR
    EXTRN mf428:FAR
    EXTRN mf445:FAR
    EXTRN mi460:NEAR
    EXTRN mf483:FAR
    EXTRN mf489:FAR
    EXTRN mf489:FAR
    EXTRN mf489:FAR
    EXTRN mf489:FAR
    EXTRN mf489:FAR
    EXTRN mf489:FAR
    EXTRN mf489:FAR
    EXTRN mf489:FAR
    EXTRN mf489:FAR
    EXTRN mf489:FAR
    EXTRN mf489:FAR
    EXTRN mf489:FAR
    EXTRN mf489:FAR
    EXTRN mf489:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,84h
    push di
    push si
    cmp word ptr ds:[51E0h],0h
    jnl short lbl13f
    jmp near ptr lbl4DFf
lbl13f:
    mov ax,word ptr [bp+6h]
    mov dx,word ptr [bp+8h]
    mov word ptr [bp-80h],ax
    mov word ptr [bp-7Eh],dx
    push dx
    push ax
    call mf14
    add sp,4h
    mov word ptr [bp+6h],ax
    mov word ptr [bp+8h],dx
    mov ax,dx
    or ax,word ptr [bp+6h]
    jnz short lbl3Cf
    mov ax,522Eh
    jmp short lbl48f
    nop
lbl3Cf:
    les bx, dword ptr [bp+6h]
    cmp byte ptr es:[bx],0h
    jnz short lbl4Cf
    mov ax,5236h
lbl48f:
    push ds
    jmp near ptr lbl4D2f
lbl4Cf:
    lea ax,word ptr [bp+0Ah]
    mov word ptr [bp-7Ch],ax
    mov word ptr [bp-7Ah],ss
    mov word ptr [bp-6h],0FFFFh
    xor ax,ax
    mov word ptr [bp-4h],ax
    mov word ptr [bp-2h],ax
    les bx, dword ptr [bp+6h]
    cmp byte ptr es:[bx],al
    jnz short lbl6Df
    jmp near ptr lbl4C1f
lbl6Db:
lbl6Df:
    mov bx,word ptr [bp+6h]
    mov si,word ptr [bp-2h]
    cmp byte ptr es:[bx+si],25h
    jz short lbl7Cf
    jmp near ptr lbl41Bf
lbl7Cf:
    xor ax,ax
    mov word ptr [bp-0Eh],ax
    mov word ptr [bp-10h],ax
    mov word ptr [bp-12h],ax
    cmp word ptr [bp-4h],ax
    jng short lblA8f
    mov si,word ptr [bp-4h]
    mov byte ptr [bp+si-64h],al
    lea ax,word ptr [bp-64h]
    push ss
    push ax
    push word ptr ds:[51E0h]
    call mf58
    add sp,6h
    mov word ptr [bp-4h],0h
lblA8f:
    mov byte ptr [bp-64h],0h
    les bx, dword ptr [bp+6h]
    mov si,word ptr [bp-2h]
    mov al,byte ptr es:[bx+si]
    mov byte ptr [bp-74h],al
    lea ax,word ptr [bp-73h]
    mov word ptr [bp-78h],ax
    mov word ptr [bp-76h],ss
    mov word ptr [bp-0Ch],0h
    inc word ptr [bp-2h]
    mov bx,word ptr [bp-2h]
    mov si,word ptr [bp+6h]
    mov al,byte ptr es:[bx+si]
    cbw
    sub ax, offset mi75
    jz short lblE1f
    dec ax
    dec ax
    jnz short lblFBf
    mov word ptr [bp-0Ch],1h
lblE1f:
    mov bx,si
    mov si,word ptr [bp-2h]
    mov al,byte ptr es:[bx+si]
    mov byte ptr [bp-73h],al
    inc word ptr [bp-2h]
    lea ax,word ptr [bp-73h]
    mov dx,ss
    inc ax
    mov word ptr [bp-78h],ax
    mov word ptr [bp-76h],ss
lblFBf:
    mov word ptr [bp-8h],0h
    mov bx,word ptr [bp+6h]
    mov si,word ptr [bp-2h]
    mov al,byte ptr es:[bx+si]
    cbw
    mov bx,ax
    test byte ptr [bx+56A5h],4h
    jz short lbl153f
lbl113b:
    mov bx,word ptr [bp+6h]
    mov si,word ptr [bp-2h]
    mov al,byte ptr es:[bx+si]
    mov cx,ax
    cbw
    mov dx,word ptr [bp-8h]
    mov bx,dx
    add dx,dx
    add dx,dx
    add dx,bx
    add dx,dx
    add ax,dx
    sub ax, offset mi111
    mov word ptr [bp-8h],ax
    les bx, dword ptr [bp-78h]
    mov byte ptr es:[bx],cl
    inc word ptr [bp-78h]
    inc word ptr [bp-2h]
    mov bx,word ptr [bp-2h]
    les si, dword ptr [bp+6h]
    mov al,byte ptr es:[bx+si]
    cbw
    mov bx,ax
    test byte ptr [bx+56A5h],4h
    jnz short lbl113b
lbl153f:
    mov bx,word ptr [bp+6h]
    mov si,word ptr [bp-2h]
    cmp byte ptr es:[bx+si],2Eh
    jnz short lbl1A8f
    mov al,byte ptr es:[bx+si]
    les bx, dword ptr [bp-78h]
    mov byte ptr es:[bx],al
    inc word ptr [bp-78h]
    inc word ptr [bp-2h]
    mov bx,word ptr [bp-2h]
    les si, dword ptr [bp+6h]
    mov al,byte ptr es:[bx+si]
    cbw
    mov bx,ax
    test byte ptr [bx+56A5h],4h
    jz short lbl1A8f
lbl181b:
    mov bx,si
    mov si,word ptr [bp-2h]
    mov al,byte ptr es:[bx+si]
    les bx, dword ptr [bp-78h]
    mov byte ptr es:[bx],al
    inc word ptr [bp-78h]
    inc word ptr [bp-2h]
    mov bx,word ptr [bp-2h]
    les si, dword ptr [bp+6h]
    mov al,byte ptr es:[bx+si]
    cbw
    mov bx,ax
    test byte ptr [bx+56A5h],4h
    jnz short lbl181b
lbl1A8f:
    mov bx,word ptr [bp+6h]
    mov si,word ptr [bp-2h]
    mov al,byte ptr es:[bx+si]
    cbw
    cmp ax, offset mi158
    jz short lbl1D4f
    ja short lbl1F0f
    sub al,46h
    jz short lbl1CCf
    sub al,6h
    jz short lbl1D4f
    sub al,2h
    jz short lbl1DCf
    sub al,1Ah
    jz short lbl1D4f
    jmp short lbl1F0f
    nop
lbl1CCf:
    mov word ptr [bp-0Eh],1h
    jmp short lbl1E1f
    nop
lbl1D4f:
    mov word ptr [bp-12h],1h
    jmp short lbl1E1f
    nop
lbl1DCf:
    mov word ptr [bp-10h],1h
lbl1E1f:
    mov al,byte ptr es:[bx+si]
    les bx, dword ptr [bp-78h]
    mov byte ptr es:[bx],al
    inc word ptr [bp-2h]
    inc word ptr [bp-78h]
lbl1F0f:
    les bx, dword ptr [bp+6h]
    mov si,word ptr [bp-2h]
    mov al,byte ptr es:[bx+si]
    les bx, dword ptr [bp-78h]
    inc word ptr [bp-78h]
    mov byte ptr es:[bx],al
    les bx, dword ptr [bp-78h]
    mov byte ptr es:[bx],0h
    les bx, dword ptr [bp+6h]
    mov al,byte ptr es:[bx+si]
    cbw
    sub ax, offset mi194
    cmp ax, offset mi195
    jna short lbl21Bf
    jmp near ptr lbl3FCf
lbl21Bf:
    add ax,ax
    xchg ax,bx
    jmp word ptr cs:[bx+495Fh]
    nop
    mov ax,word ptr ds:[3749h]
    dec bx
    aaa
    dec bx
    aaa
    dec bx
    aaa
    dec bx
    aaa
    dec bx
    aaa
    dec bx
    aaa
    dec bx
    aaa
    dec bx
    aaa
    dec bx
    aaa
    dec bx
    mov ax,word ptr ds:[0A149h]
    dec cx
    aaa
    dec bx
    aaa
    dec bx
    aaa
    dec bx
    aaa
    dec bx
    mov ax,word ptr ds:[3749h]
    dec bx
    aaa
    dec bx
    aaa
    dec bx
    aaa
    dec bx
    aaa
    dec bx
    mov ax,word ptr ds:[0A749h]
    dec cx
    aaa
lbl257b:
    dec bx
    aaa
    dec bx
    add cx,word ptr [bp+si+37h]
    dec bx
    mov ax,word ptr ds:[3749h]
    dec bx
    aaa
    dec bx
    mov ax,word ptr ds:[8349h]
    jng short lbl257b
    add byte ptr [si+22h],dh
    les bx, dword ptr [bp-7Ch]
    add word ptr [bp-7Ch],4h
    push word ptr es:[bx+2h]
    push word ptr es:[bx]
    lea ax,word ptr [bp-74h]
    push ss
    push ax
    lea ax,word ptr [bp-64h]
    push ss
    push ax
    call mf267
    add sp,0Ch
    jmp short lbl2AAf
    les bx, dword ptr [bp-7Ch]
    add word ptr [bp-7Ch],2h
    push word ptr es:[bx]
    lea ax,word ptr [bp-74h]
    push ss
    push ax
    lea ax,word ptr [bp-64h]
    push ss
    push ax
    call mf279
    add sp,0Ah
lbl2AAf:
    cmp byte ptr [bp-64h],0h
    jnz short lbl2B3f
    jmp near ptr lbl3FCf
lbl2B3f:
    lea ax,word ptr [bp-64h]
    push ss
    push ax
    push word ptr ds:[51E0h]
    call mf288
    add sp,6h
    jmp near ptr lbl3FCf
    nop
    cmp word ptr [bp-0Eh],0h
    jz short lbl328f
lbl2CEb:
    les bx, dword ptr [bp-7Ch]
    add word ptr [bp-7Ch],4h
    mov ax,word ptr es:[bx]
    mov dx,word ptr es:[bx+2h]
    mov word ptr [bp-78h],ax
    mov word ptr [bp-76h],dx
lbl2E2b:
    cmp word ptr [bp-10h],0h
    jnz short lbl2FAf
    push word ptr [bp-76h]
    push ax
    call mf304
    add sp,4h
    mov word ptr [bp-78h],ax
    mov word ptr [bp-76h],dx
lbl2FAf:
    mov ax,word ptr [bp-76h]
    or ax,word ptr [bp-78h]
    jnz short lbl305f
    jmp near ptr lbl3E2f
lbl305f:
    les di, dword ptr [bp-78h]
    mov cx,0FFFFh
    xor ax,ax
    repne scasb
    not cx
    dec cx
    mov word ptr [bp-0Ah],cx
    cmp word ptr [bp-0Ch],ax
    jnz short lbl35Bf
    mov ax,word ptr [bp-8h]
    cmp cx,ax
    jnl short lbl35Bf
    sub ax,cx
    mov word ptr [bp-4h],ax
    jmp short lbl34Cf
lbl328f:
    cmp word ptr [bp-10h],0h
    jz short lbl2CEb
    les bx, dword ptr [bp-7Ch]
    add word ptr [bp-7Ch],2h
    mov ax,word ptr es:[bx]
    mov word ptr [bp-78h],ax
    mov word ptr [bp-76h],ds
    jmp short lbl2E2b
lbl340b:
    mov ax,20h
    push ax
    call mf337
    add sp,2h
lbl34Cf:
    mov ax,word ptr [bp-4h]
    dec word ptr [bp-4h]
    or ax,ax
    jnl short lbl340b
    mov word ptr [bp-4h],0h
lbl35Bf:
    les bx, dword ptr [bp-78h]
    cmp byte ptr es:[bx],0h
    jz short lbl3B5f
lbl364b:
    mov si,word ptr [bp-4h]
    mov al,byte ptr es:[bx]
    mov byte ptr [bp+si-64h],al
    inc word ptr [bp-4h]
    inc word ptr [bp-78h]
    les bx, dword ptr [bp-78h]
    mov al,byte ptr es:[bx]
    cbw
    cmp ax, offset mi355
    jz short lbl38Ff
    ja short lbl389f
    or al,al
    jz short lbl38Ff
    sub al,0Ah
    jz short lbl38Ff
lbl389f:
    cmp word ptr [bp-4h],4Fh
    jc short lbl3ACf
lbl38Ff:
    mov si,word ptr [bp-4h]
    mov byte ptr [bp+si-64h],0h
    lea ax,word ptr [bp-64h]
    push ss
    push ax
    push word ptr ds:[51E0h]
    call mf370
    add sp,6h
    mov word ptr [bp-4h],0h
lbl3ACf:
    les bx, dword ptr [bp-78h]
    cmp byte ptr es:[bx],0h
    jnz short lbl364b
lbl3B5f:
    cmp word ptr [bp-0Ch],0h
    jz short lbl3E2f
    mov ax,word ptr [bp-8h]
    cmp word ptr [bp-0Ah],ax
    jnl short lbl3E2f
    sub ax,word ptr [bp-0Ah]
    mov word ptr [bp-4h],ax
lbl3C9b:
    mov ax,word ptr [bp-4h]
    dec word ptr [bp-4h]
    or ax,ax
    jl short lbl3E2f
    mov ax,20h
    push ax
    call mf389
    add sp,2h
    jmp short lbl3C9b
    nop
lbl3E2f:
    cmp word ptr [bp-10h],0h
    jnz short lbl3FCf
    push word ptr [bp-7Eh]
    push word ptr [bp-80h]
    call mf397
    add sp,4h
    mov word ptr [bp+6h],ax
    mov word ptr [bp+8h],dx
lbl3FCf:
    les bx, dword ptr [bp+6h]
    mov si,word ptr [bp-2h]
    mov al,byte ptr es:[bx+si]
    cbw
    push ax
    mov ax,5237h
    push ds
    push ax
    call mf409
    add sp,6h
    or dx,ax
    jz short lbl41Bf
    jmp near ptr lbl4AFf
lbl41Bf:
    cmp word ptr [bp-4h],4Fh
    jc short lbl484f
    cmp word ptr [bp-6h],0h
    jl short lbl432f
    mov si,word ptr [bp-6h]
    mov al,byte ptr [bp+si-64h]
    mov byte ptr [bp-14h],al
    jmp short lbl435f
lbl432f:
    mov si,word ptr [bp-4h]
lbl435f:
    mov byte ptr [bp+si-64h],0h
    lea ax,word ptr [bp-64h]
    push ss
    push ax
    push word ptr ds:[51E0h]
    call mf428
    add sp,6h
    cmp word ptr [bp-6h],0h
    jl short lbl47Af
    mov al,byte ptr [bp-14h]
    mov si,word ptr [bp-6h]
    mov byte ptr [bp+si-64h],al
    sub si,word ptr [bp-4h]
    neg si
    push si
    mov di,word ptr [bp-6h]
    lea ax,word ptr [bp+di-64h]
    push ss
    push ax
    lea ax,word ptr [bp-64h]
    push ss
    push ax
    call mf445
    add sp,0Ah
    mov word ptr [bp-4h],si
    jmp short lbl47Ff
    nop
lbl47Af:
    mov word ptr [bp-4h],0h
lbl47Ff:
    mov word ptr [bp-6h],0FFFFh
lbl484f:
    les bx, dword ptr [bp+6h]
    mov si,word ptr [bp-2h]
    mov al,byte ptr es:[bx+si]
    mov di,word ptr [bp-4h]
    mov byte ptr [bp+di-64h],al
    inc word ptr [bp-4h]
    mov al,byte ptr es:[bx+si]
    cbw
    cmp ax, offset mi460
    jz short lbl4A9f
    ja short lbl4AFf
    sub al,0Ah
    jz short lbl4A9f
    sub al,16h
    jnz short lbl4AFf
lbl4A9f:
    mov ax,word ptr [bp-4h]
    mov word ptr [bp-6h],ax
lbl4AFf:
    inc word ptr [bp-2h]
    mov bx,word ptr [bp-2h]
    les si, dword ptr [bp+6h]
    cmp byte ptr es:[bx+si],0h
    jz short lbl4C1f
    jmp near ptr lbl6Db
lbl4C1f:
    cmp word ptr [bp-4h],0h
    jng short lbl4DFf
    mov si,word ptr [bp-4h]
    mov byte ptr [bp+si-64h],0h
    lea ax,word ptr [bp-64h]
    push ss
lbl4D2f:
    push ax
    push word ptr ds:[51E0h]
    call mf483
    add sp,6h
lbl4DFf:
    pop si
    pop di
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
