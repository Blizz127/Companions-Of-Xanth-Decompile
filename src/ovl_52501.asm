_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf9be:FAR
    EXTRN mi1e0:NEAR
    EXTRN mf1ea:FAR
    EXTRN mf118:FAR
    EXTRN mf9eb:FAR
    EXTRN mf1d0:FAR
    EXTRN mf5c:FAR
    EXTRN mf173:FAR
    EXTRN mfa8c:FAR
    EXTRN mf163:FAR
    EXTRN mf1b1:FAR
    EXTRN mf940:FAR
    EXTRN mf41c:FAR
    EXTRN mf566:FAR
    EXTRN mfa35:FAR
    EXTRN mf3fc:FAR
    EXTRN mdb7:NEAR
    EXTRN mf969:FAR
    EXTRN mf57c:FAR
    EXTRN mf23c:FAR
    EXTRN mi59b:NEAR
    EXTRN mi90f:NEAR
    EXTRN mf8ed:FAR
    EXTRN mf482:FAR
    EXTRN mf538:FAR
    EXTRN mia55:NEAR
    EXTRN mf3a2:FAR
    EXTRN mf3c7:FAR
    EXTRN mdd2:NEAR
    EXTRN mfa2d:FAR
    EXTRN mfa95:FAR
    EXTRN mf4d7:FAR
    EXTRN mf1bd:FAR
    EXTRN mf10b:FAR
    EXTRN mf2e3:FAR
    EXTRN mf835:FAR
    EXTRN mf764:FAR
    EXTRN mf9f0:FAR
    EXTRN mi860:NEAR
    EXTRN mfa12:FAR
    EXTRN mf48:FAR
    EXTRN mf86f:FAR
    EXTRN mf156:FAR
    EXTRN mf29f:FAR
    EXTRN mf56e:FAR
    EXTRN mf982:FAR
    EXTRN mf95d:FAR
    EXTRN mi8e9:NEAR
    EXTRN mdbf:NEAR
    EXTRN mf12b:FAR
    EXTRN mf774:FAR
    EXTRN mi8da:NEAR
    EXTRN mff0:FAR
    EXTRN mf38c:FAR
    EXTRN mf881:FAR
    EXTRN mf786:FAR
    EXTRN mf334:FAR
    EXTRN mf2c:FAR
    EXTRN mdc7:NEAR
    EXTRN mi19d:NEAR
    EXTRN mf6fd:FAR
    EXTRN mf6ac:FAR
    EXTRN mf144:FAR
    EXTRN mf6ca:FAR
    EXTRN mf78f:FAR
    EXTRN mf933:FAR
    EXTRN mf9e3:FAR
    EXTRN mf9:FAR
    EXTRN mf2fc:FAR
    EXTRN mf225:FAR
    EXTRN mf6ea:FAR
    EXTRN mf4fa:FAR
    EXTRN mf731:FAR
    EXTRN mfa75:FAR
    EXTRN mf895:FAR
    EXTRN mf3d4:FAR
    EXTRN mf38:FAR
    EXTRN mf70:FAR
    EXTRN mf528:FAR
    EXTRN mf70d:FAR
    EXTRN mf9ae:FAR
    EXTRN mf1f5:FAR
    EXTRN mf496:FAR
    EXTRN mi24e:NEAR
    EXTRN mf31c:FAR
    EXTRN mf186:FAR
    EXTRN mfa41:FAR
    EXTRN mfa84:FAR
    EXTRN mf8cf:FAR
    EXTRN mf99a:FAR
    EXTRN mfe:FAR
    EXTRN mfa62:FAR
    EXTRN mf414:FAR
    EXTRN mf751:FAR
    EXTRN mf13:FAR
    EXTRN mf8b9:FAR
    EXTRN mf81c:FAR
    EXTRN mf4c1:FAR
    EXTRN mf1c:FAR
    EXTRN mf293:FAR
    EXTRN mf22a:FAR
    EXTRN mf3f0:FAR
    EXTRN mf234:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,0D8h
    push di
    push si
    call mf9
    call mfe
    call mf13
    mov ax,1h
    push ax
    call mf1c
    add sp,2h
    mov ax,20h
    mov cx,2199h
    push cx
    push ax
    call mf2c
    add sp,4h
    mov ax,0Ah
    push ax
    call mf38
    add sp,2h
    mov ax,0FFFFh
    push ax
    mov ax,0Fh
    push ax
    call mf48
    add sp,4h
    mov ax,0C7h
    push ax
    mov cx,13Fh
    push cx
    xor dx,dx
    push dx
    push dx
    call mf5c
    add sp,8h
    mov ax,0C7h
    push ax
    mov ax,13Fh
    push ax
    xor ax,ax
    push ax
    push ax
    call mf70
    add sp,8h
    mov word ptr [bp-7Ch],0h
    mov word ptr [bp-7Eh],0h
    mov word ptr [bp-0C2h],0h
lbl88b:
    mov ax,word ptr [bp+8h]
    mov es, ds:[5AACh]
    mov bx,word ptr [bp-0C2h]
    cmp word ptr es:[bx],ax
    db 74h, 12h ; override
    inc word ptr [bp-7Eh]
    add word ptr [bp-0C2h],0Ah
    db 81h, 0BEh, 3Eh, 0FFh, 3Ch, 00h ; override
    jc short lbl88b
    db 0EBh, 38h ; override
lblAAf:
    mov bx,word ptr [bp-7Eh]
    mov ax,bx
    add bx,bx
    add bx,bx
    add bx,ax
    add bx,bx
    mov ax,word ptr es:[bx+mdb7]
    mov word ptr [bp-72h],ax
    mov cx,word ptr es:[bx+mdbf]
    mov word ptr [bp-74h],cx
    sub ax,word ptr es:[bx+mdc7]
    neg ax
    inc ax
    mov word ptr [bp-76h],ax
    sub cx,word ptr es:[bx+mdd2]
    neg cx
    inc cx
    mov word ptr [bp-78h],cx
    mov word ptr [bp-7Ch],1h
lblE2f:
    cmp word ptr [bp-7Ch],0h
    jnz short lblEBf
    jmp near ptr lbl16Ef
lblEBf:
    lea ax,word ptr [bp-68h]
    push ss
    push ax
    call mff0
    add sp,4h
    mov ax,word ptr [bp-78h]
    dec ax
    push ax
    mov ax,word ptr [bp-76h]
    dec ax
    push ax
    xor ax,ax
    push ax
    push ax
    lea cx,word ptr [bp-68h]
    push ss
    push cx
    call mf10b
    add sp,0Ch
    lea ax,word ptr [bp-54h]
    push ss
    push ax
    call mf118
    add sp,4h
    xor ax,ax
    push ax
    push word ptr [bp+8h]
    lea ax,word ptr [bp-54h]
    push ss
    push ax
    call mf12b
    add sp,8h
    mov ax,word ptr [bp-74h]
    neg ax
    push ax
    mov ax,word ptr [bp-72h]
    neg ax
    push ax
    lea ax,word ptr [bp-54h]
    push ss
    push ax
    call mf144
    add sp,8h
    lea ax,word ptr [bp-54h]
    push ss
    push ax
    lea ax,word ptr [bp-68h]
    push ss
    push ax
    call mf156
    add sp,8h
    lea ax,word ptr [bp-54h]
    push ss
    push ax
    call mf163
    add sp,4h
    jmp short lbl19Af
    nop
lbl16Ef:
    lea ax,word ptr [bp-68h]
    push ss
    push ax
    call mf173
    add sp,4h
    xor ax,ax
    push ax
    push word ptr [bp+8h]
    lea ax,word ptr [bp-68h]
    push ss
    push ax
    call mf186
    add sp,8h
    mov ax,word ptr [bp-62h]
    mov word ptr [bp-76h],ax
    mov ax,word ptr [bp-60h]
    mov word ptr [bp-78h],ax
lbl19Af:
    mov ax,word ptr [bp-78h]
    add ax, offset mi19d
    push ax
    mov cx,word ptr [bp-76h]
    add cx,4h
    push cx
    mov dx,4h
    push dx
    push dx
    mov si,ax
    mov di,cx
    call mf1b1
    add sp,8h
    mov word ptr [bp-7Ah],ax
    push ax
    call mf1bd
    add sp,2h
    mov ax,10h
    push ax
    push si
    push di
    mov ax,3h
    push ax
    push ax
    call mf1d0
    add sp,0Ah
    mov word ptr [bp-80h],4h
    mov ax,word ptr [bp-78h]
    add ax, offset mi1e0
    mov word ptr [bp-82h],ax
    push word ptr [bp-7Ah]
    call mf1ea
    add sp,2h
    push word ptr [bp+8h]
    call mf1f5
    add sp,2h
    mov es, ds:[5AAEh]
    mov ax,3420h
    push ds
    mov di,6A54h
    mov si,46B4h
    mov ds,ax
    mov cx,18h
    rep movsw
    pop ds
    mov ax,38AFh
    push ds
    mov di,6A84h
    mov si,6D4Ah
    mov ds,ax
    mov cx,48h
    rep movsw
    pop ds
    call mf225
    call mf22a
    lea ax,word ptr [bp-68h]
    push ss
    push ax
    call mf234
    add sp,4h
    call mf23c
    mov word ptr [bp-8Ch],0FFFFh
    mov ax,word ptr [bp+6h]
    mov word ptr [bp-8Ah],ax
    cmp ax, offset mi24e
    jnz short lbl256f
    jmp near ptr lblA5Df
lbl256b:
lbl256f:
    cmp ax,8000h
    jnc short lbl25Ef
    jmp near ptr lbl804f
lbl25Ef:
    mov bx,ax
    add bx,ax
    add bx,ax
    add bx,bx
    add bx,31E0h
    mov es, ds:[5AB0h]
    mov word ptr [bp-0A8h],bx
    mov word ptr [bp-0A6h],es
    mov ax,word ptr es:[bx+2h]
    add ax,ax
    add ax,ax
    add ax,1AB8h
    mov word ptr [bp-0ACh],ax
    mov word ptr [bp-0AAh],2ADAh
    mov ax,0Ah
    push ax
    mov si,bx
    mov di,es
    call mf293
    add sp,2h
    mov ax,0FFFFh
    push ax
    call mf29f
    add sp,2h
    mov ax,word ptr ds:[6D48h]
    mov word ptr [bp-9Ch],ax
    xor ax,ax
    mov word ptr [bp-9Ah],ax
    mov word ptr [bp-98h],ax
    mov word ptr [bp-7Eh],ax
    mov es,di
    cmp byte ptr es:[si],al
    jnz short lbl2C5f
    jmp near ptr lbl38Cf
lbl2C5f:
    lea ax,word ptr [bp-40h]
    mov word ptr [bp-0C4h],ax
    mov ax,word ptr [bp-0ACh]
    mov dx,word ptr [bp-0AAh]
    mov word ptr [bp-0C8h],ax
    mov word ptr [bp-0C6h],dx
lbl2DCb:
    push word ptr [bp-7Eh]
    push word ptr [bp-8Ah]
    call mf2e3
    add sp,4h
    mov es,dx
    mov bx,ax
    test byte ptr es:[bx],1h
    jz short lbl373f
    les bx, dword ptr [bp-0C8h]
    push word ptr es:[bx]
    call mf2fc
    add sp,2h
    mov word ptr [bp-94h],ax
    mov word ptr [bp-92h],dx
    mov ax,13Bh
    push ax
    xor ax,ax
    push ax
    mov ax,4h
    push ax
    push dx
    push word ptr [bp-94h]
    call mf31c
    add sp,0Ah
    sub ax,word ptr ds:[6D48h]
    add word ptr [bp-9Ch],ax
    push word ptr [bp-92h]
    push word ptr [bp-94h]
    call mf334
    add sp,4h
    add ax,word ptr ds:[6D24h]
    mov word ptr [bp-0AEh],ax
    cmp ax,137h
    jc short lbl34Ff
    mov word ptr [bp-0AEh],137h
lbl34Ff:
    mov ax,word ptr [bp-9Ah]
    cmp word ptr [bp-0AEh],ax
    jna short lbl361f
    mov ax,word ptr [bp-0AEh]
    mov word ptr [bp-9Ah],ax
lbl361f:
    mov ax,word ptr [bp-7Eh]
    mov bx,word ptr [bp-0C4h]
    add word ptr [bp-0C4h],4h
    mov word ptr [bx],ax
    inc word ptr [bp-98h]
lbl373f:
    add word ptr [bp-0C8h],4h
    les bx, dword ptr [bp-0A8h]
    sub ah,ah
    mov al,byte ptr es:[bx]
    inc word ptr [bp-7Eh]
    cmp ax,word ptr [bp-7Eh]
    jna short lbl38Cf
    jmp near ptr lbl2DCb
lbl38Cf:
    call mf38c
    mov ax,0C7h
    push ax
    mov ax,13Fh
    push ax
    mov ax,word ptr [bp-82h]
    dec ax
    push ax
    xor ax,ax
    push ax
    call mf3a2
    add sp,8h
    mov ax,word ptr [bp-9Ch]
    add ax,word ptr [bp-82h]
    push ax
    mov cx,word ptr [bp-9Ah]
    add cx,4h
    push cx
    push word ptr [bp-82h]
    mov dx,4h
    push dx
    mov si,ax
    mov di,cx
    call mf3c7
    add sp,8h
    mov word ptr [bp-88h],ax
    push ax
    call mf3d4
    add sp,2h
    mov ax,10h
    push ax
    lea ax,word ptr [si+1h]
    push ax
    lea ax,word ptr [di+1h]
    push ax
    push word ptr [bp-82h]
    mov ax,3h
    push ax
    call mf3f0
    add sp,0Ah
    mov ax,17h
    push ax
    call mf3fc
    add sp,2h
    push si
    push di
    mov ax,word ptr [bp-82h]
    inc ax
    push ax
    mov ax,4h
    push ax
    mov ax,2h
    push ax
    call mf414
    add sp,0Ah
    call mf41c
    mov word ptr [bp-90h],0h
    mov ax,word ptr [bp-8Ah]
    cmp word ptr [bp-8Ch],ax
    jnz short lbl46Ef
    mov word ptr [bp-7Eh],0h
    cmp word ptr [bp-98h],0h
    jz short lbl472f
    lea ax,word ptr [bp-40h]
    mov word ptr [bp-0CAh],ax
lbl444b:
    mov ax,word ptr [bp-8Eh]
    mov bx,word ptr [bp-0CAh]
    cmp word ptr [bx],ax
    jz short lbl464f
    add word ptr [bp-0CAh],4h
    mov ax,word ptr [bp-98h]
    inc word ptr [bp-7Eh]
    cmp word ptr [bp-7Eh],ax
    jc short lbl444b
    jmp short lbl472f
    nop
lbl464f:
    mov ax,word ptr [bp-7Eh]
    mov word ptr [bp-90h],ax
    jmp short lbl472f
    nop
lbl46Ef:
    mov word ptr [bp-8Ch],ax
lbl472f:
    mov ax,0FFFFh
    push ax
    mov ax,0Fh
    push ax
    mov ax,0Ah
    push ax
    push word ptr [bp-88h]
    call mf482
    add sp,8h
    push word ptr ds:[6D48h]
    push word ptr ds:[6DDAh]
    push word ptr [bp-88h]
    call mf496
    add sp,6h
    mov word ptr [bp-7Eh],0h
    cmp word ptr [bp-98h],0h
    jnz short lbl4ADf
    jmp near ptr lbl554f
lbl4ADf:
    lea ax,word ptr [bp-3Eh]
    mov word ptr [bp-0CCh],ax
lbl4B4b:
    lea ax,word ptr [bp-3Eh]
    cmp word ptr [bp-0CCh],ax
    jz short lbl4C9f
    mov ax,0Ah
    push ax
    call mf4c1
    add sp,2h
lbl4C9f:
    lea ax,word ptr [bp-74h]
    push ss
    push ax
    lea cx,word ptr [bp-72h]
    push ss
    push cx
    push word ptr [bp-88h]
    call mf4d7
    add sp,0Ah
    mov bx,word ptr [bp-0CCh]
    mov ax,word ptr [bp-74h]
    mov word ptr [bx],ax
    mov bx,word ptr [bp-0CCh]
    mov bx,word ptr [bx-2h]
    add bx,bx
    add bx,bx
    les si, dword ptr [bp-0ACh]
    push word ptr es:[bx+si]
    call mf4fa
    add sp,2h
    mov word ptr [bp-94h],ax
    mov word ptr [bp-92h],dx
    mov ax,0FFFFh
    push ax
    mov ax,word ptr [bp-7Eh]
    cmp word ptr [bp-90h],ax
    jnz short lbl51Cf
    mov ax,10h
    jmp short lbl51Ff
lbl51Cf:
    mov ax,0Fh
lbl51Ff:
    push ax
    mov ax,0Ah
    push ax
    push word ptr [bp-88h]
    call mf528
    add sp,8h
    push word ptr [bp-92h]
    push word ptr [bp-94h]
    call mf538
    add sp,4h
    add word ptr [bp-0CCh],4h
    mov ax,word ptr [bp-98h]
    inc word ptr [bp-7Eh]
    cmp word ptr [bp-7Eh],ax
    jnc short lbl554f
    jmp near ptr lbl4B4b
lbl554f:
    mov ax,word ptr [bp-90h]
    mov word ptr [bp-96h],ax
    lea ax,word ptr [bp-74h]
    push ss
    push ax
    lea ax,word ptr [bp-72h]
    push ss
    push ax
    call mf566
    add sp,8h
    call mf56e
lbl573b:
    lea ax,word ptr [bp-70h]
    push ss
    push ax
    mov cx,0Fh
    push cx
    call mf57c
    add sp,6h
    xor ax,ax
    mov word ptr [bp-86h],ax
    mov word ptr [bp-84h],ax
    mov ax,word ptr [bp-70h]
    dec ax
    jz short lbl5A2f
    dec ax
    jz short lbl5ACf
    dec ax
    dec ax
    jz short lbl5ACf
    sub ax, offset mi59b
    jz short lbl5ACf
    jmp short lbl5BFf
lbl5A2f:
    mov ax,word ptr [bp-6Ah]
    mov word ptr [bp-86h],ax
    jmp short lbl5BFf
    nop
lbl5ACf:
    mov ax,word ptr [bp-6Ah]
    mov word ptr [bp-84h],ax
    mov ax,word ptr [bp-6Eh]
    mov word ptr [bp-72h],ax
    mov ax,word ptr [bp-6Ch]
    mov word ptr [bp-74h],ax
lbl5BFf:
    cmp word ptr [bp-86h],0Dh
    jnz short lbl5C9f
    jmp near ptr lbl786f
lbl5C9f:
    cmp word ptr [bp-86h],148h
    jnz short lbl5E0f
    cmp word ptr [bp-90h],0h
    jz short lbl5E0f
    mov ax,word ptr [bp-90h]
    dec ax
    jmp short lbl62Df
    nop
lbl5E0f:
    cmp word ptr [bp-86h],150h
    jnz short lbl5FAf
    mov ax,word ptr [bp-98h]
    dec ax
    cmp ax,word ptr [bp-90h]
    jna short lbl5FAf
    mov ax,word ptr [bp-90h]
    inc ax
    jmp short lbl62Df
lbl5FAf:
    mov ax,word ptr [bp-82h]
    add ax,word ptr ds:[6D48h]
    cmp ax,word ptr [bp-74h]
    jg short lbl631f
    mov ax,word ptr [bp-98h]
    imul word ptr ds:[69F8h]
    add ax,word ptr [bp-82h]
    add ax,word ptr ds:[6D48h]
    cmp ax,word ptr [bp-74h]
    jng short lbl631f
    mov ax,word ptr [bp-74h]
    sub ax,word ptr [bp-82h]
    sub ax,word ptr ds:[6D48h]
    sub dx,dx
    div word ptr ds:[69F8h]
lbl62Df:
    mov word ptr [bp-96h],ax
lbl631f:
    mov ax,word ptr [bp-90h]
    cmp word ptr [bp-96h],ax
    jnz short lbl63Ef
    jmp near ptr lbl77Cf
lbl63Ef:
    cmp word ptr [bp-86h],0h
    jz short lbl6B4f
    mov ax,word ptr [bp-74h]
    sub ax,word ptr [bp-82h]
    mov word ptr [bp-0D0h],ax
    mov si,word ptr [bp-90h]
    add si,si
    add si,si
    mov word ptr [bp-0CEh],si
    cmp word ptr [bp+si-3Eh],ax
    jg short lbl6B4f
    mov ax,word ptr [bp-90h]
    inc ax
    cmp ax,word ptr [bp-98h]
    jc short lbl67Ef
    mov ax,word ptr [bp+si-3Eh]
    add ax,word ptr ds:[69F8h]
    cmp ax,word ptr [bp-0D0h]
    jng short lbl687f
lbl679b:
    mov ax,1h
    jmp short lbl689f
lbl67Ef:
    mov ax,word ptr [bp-0D0h]
    cmp word ptr [bp+si-3Ah],ax
    jg short lbl679b
lbl687f:
    xor ax,ax
lbl689f:
    mov word ptr [bp-0B0h],ax
    or ax,ax
    jz short lbl6B4f
    mov si,word ptr [bp-96h]
    add si,si
    add si,si
    mov ax,word ptr [bp+si-3Eh]
    mov si,word ptr [bp-0CEh]
    sub ax,word ptr [bp+si-3Eh]
    add word ptr [bp-74h],ax
    push word ptr [bp-74h]
    push word ptr [bp-72h]
    call mf6ac
    add sp,4h
lbl6B4f:
    mov si,word ptr [bp-90h]
    add si,si
    add si,si
    mov bx,word ptr [bp+si-40h]
    add bx,bx
    add bx,bx
    les di, dword ptr [bp-0ACh]
    push word ptr es:[bx+di]
    call mf6ca
    add sp,2h
    mov word ptr [bp-94h],ax
    mov word ptr [bp-92h],dx
    mov ax,0FFFFh
    push ax
    mov cx,0Fh
    push cx
    mov cx,0Ah
    push cx
    push word ptr [bp-88h]
    call mf6ea
    add sp,8h
    push word ptr [bp+si-3Eh]
    push word ptr ds:[6DDAh]
    push word ptr [bp-88h]
    call mf6fd
    add sp,6h
    push word ptr [bp-92h]
    push word ptr [bp-94h]
    call mf70d
    add sp,4h
    mov ax,word ptr [bp-96h]
    mov word ptr [bp-90h],ax
    mov si,ax
    add si,ax
    add si,si
    mov bx,word ptr [bp+si-40h]
    add bx,bx
    add bx,bx
    les di, dword ptr [bp-0ACh]
    push word ptr es:[bx+di]
    call mf731
    add sp,2h
    mov word ptr [bp-94h],ax
    mov word ptr [bp-92h],dx
    mov ax,0FFFFh
    push ax
    mov ax,10h
    push ax
    mov ax,0Ah
    push ax
    push word ptr [bp-88h]
    call mf751
    add sp,8h
    push word ptr [bp+si-3Eh]
    push word ptr ds:[6DDAh]
    push word ptr [bp-88h]
    call mf764
    add sp,6h
    push word ptr [bp-92h]
    push word ptr [bp-94h]
    call mf774
    add sp,4h
lbl77Cf:
    cmp word ptr [bp-84h],0h
    jnz short lbl786f
    jmp near ptr lbl573b
lbl786f:
    call mf786
    push word ptr [bp-88h]
    call mf78f
    add sp,2h
    mov ax,word ptr [bp-90h]
    inc ax
    cmp ax,word ptr [bp-98h]
    jc short lbl7AAf
    mov word ptr [bp-8Eh],0FFFFh
    jmp short lbl7B9f
lbl7AAf:
    mov si,word ptr [bp-90h]
    add si,si
    add si,si
    mov ax,word ptr [bp+si-3Ch]
    mov word ptr [bp-8Eh],ax
lbl7B9f:
    les bx, dword ptr [bp-0A8h]
    mov ax,word ptr es:[bx+4h]
    mov word ptr [bp-0D2h],ax
    or ax,ax
    jz short lbl7EAf
    mov si,word ptr [bp-90h]
    add si,si
    add si,si
    push word ptr [bp+si-40h]
    push word ptr [bp-8Ah]
    mov es, ds:[5AB2h]
    mov bx,ax
    add bx,ax
    add bx,bx
    call dword ptr es:[bx+2F04h]
    add sp,4h
lbl7EAf:
    mov si,word ptr [bp-90h]
    add si,si
    add si,si
    mov si,word ptr [bp+si-40h]
    add si,si
    add si,si
    les bx, dword ptr [bp-0ACh]
    mov ax,word ptr es:[bx+si+2h]
    jmp near ptr lblA51f
lbl804f:
    add ax,ax
    add ax,ax
    add ax,574h
    mov word ptr [bp-0B4h],ax
    mov word ptr [bp-0B2h],2ADAh
    xor ax,ax
    push ax
    push word ptr [bp-8Ah]
    call mf81c
    add sp,4h
    mov es,dx
    mov bx,ax
    test byte ptr es:[bx],1h
    jnz short lbl831f
    jmp near ptr lblA49f
lbl831f:
    push word ptr [bp-8Ah]
    call mf835
    add sp,2h
    or dx,dx
    jl short lbl850f
    jg short lbl847f
    or ax,ax
    jz short lbl850f
lbl847f:
    mov ax,word ptr [bp-8Ah]
    mov word ptr ds:[6A10h],ax
    jmp short lbl856f
lbl850f:
    mov word ptr ds:[6A10h],0FFFFh
lbl856f:
    mov ax,13Bh
    push ax
    xor ax,ax
    push ax
    mov ax,word ptr [bp-76h]
    add ax, offset mi860
    mov word ptr [bp-0D4h],ax
    push ax
    les bx, dword ptr [bp-0B4h]
    push word ptr es:[bx]
    call mf86f
    add sp,2h
    mov word ptr [bp-94h],ax
    mov word ptr [bp-92h],dx
    push dx
    push ax
    call mf881
    add sp,0Ah
    mov word ptr [bp-0B6h],ax
    push word ptr [bp-92h]
    push word ptr [bp-94h]
    call mf895
    add sp,4h
    add ax,word ptr ds:[6D24h]
    mov word ptr [bp-0B8h],ax
    mov cx,133h
    sub cx,word ptr [bp-76h]
    cmp ax,cx
    jc short lbl8B9f
    mov ax,133h
    sub ax,word ptr [bp-76h]
    mov word ptr [bp-0B8h],ax
lbl8B9f:
    call mf8b9
    mov ax,0C7h
    push ax
    mov ax,13Fh
    push ax
    mov cx,word ptr [bp-82h]
    dec cx
    push cx
    xor cx,cx
    push cx
    call mf8cf
    add sp,8h
    mov ax,word ptr [bp-78h]
    add ax, offset mi8da
    push ax
    mov ax,13Fh
    push ax
    mov ax,4h
    push ax
    mov ax,word ptr [bp-76h]
    add ax, offset mi8e9
    push ax
    call mf8ed
    add sp,8h
    cmp word ptr ds:[6A1Ah],0h
    jnz short lbl906f
    cmp word ptr ds:[6A10h],0FFFFFFFFFFFFFFFFh
    jz short lbl906f
    jmp near ptr lbl9C6f
lbl906f:
    mov ax,word ptr [bp-78h]
    sub ax,word ptr [bp-0B6h]
    shr ax,1
    add ax, offset mi90f
    mov cx,ax
    add ax,word ptr [bp-0B6h]
    push ax
    mov dx,word ptr [bp-0D4h]
    add dx,word ptr [bp-0B8h]
    push dx
    push cx
    push word ptr [bp-0D4h]
    mov si,ax
    mov di,cx
    mov word ptr [bp-0D6h],dx
    mov word ptr [bp-0D8h],dx
    call mf933
    add sp,8h
    mov word ptr [bp-88h],ax
    push ax
    call mf940
    add sp,2h
    mov ax,10h
    push ax
    lea ax,word ptr [si+1h]
    push ax
    mov ax,word ptr [bp-0D6h]
    inc ax
    push ax
    push di
    mov ax,word ptr [bp-0D4h]
    dec ax
    push ax
    call mf95d
    add sp,0Ah
    mov ax,17h
    push ax
    call mf969
    add sp,2h
    push si
    push word ptr [bp-0D8h]
    lea ax,word ptr [di+1h]
    push ax
    push word ptr [bp-0D4h]
    mov ax,2h
    push ax
    call mf982
    add sp,0Ah
    mov ax,0FFFFh
    push ax
    mov ax,0Fh
    push ax
    mov ax,0Ah
    push ax
    push word ptr [bp-88h]
    call mf99a
    add sp,8h
    push word ptr ds:[6D48h]
    push word ptr ds:[6DDAh]
    push word ptr [bp-88h]
    call mf9ae
    add sp,6h
    push word ptr [bp-92h]
    push word ptr [bp-94h]
    call mf9be
    add sp,4h
lbl9C6f:
    cmp word ptr ds:[6A10h],0FFFFFFFFFFFFFFFFh
    jz short lbl9EBf
    cmp word ptr ds:[6A1Ch],0h
    jz short lbl9EBf
    cmp word ptr ds:[4232h],0h
    jz short lbl9EBf
    sub ax,ax
    push ax
    push ax
    push word ptr ds:[6A10h]
    call mf9e3
    add sp,6h
lbl9EBf:
    call mf9eb
    call mf9f0
    les bx, dword ptr [bp-0B4h]
    cmp word ptr es:[bx+2h],8000h
    jnc short lblA1Af
    mov ax,0C7h
    push ax
    mov ax,13Fh
    push ax
    mov ax,word ptr [bp-82h]
    dec ax
    push ax
    xor ax,ax
    push ax
    call mfa12
    add sp,8h
lblA1Af:
    les bx, dword ptr [bp-0B4h]
    cmp word ptr es:[bx+2h],0FFFFFFFFFFFFFFFFh
    jz short lblA2Df
    cmp word ptr es:[bx+2h],8000h
    jnc short lblA3Df
lblA2Df:
    call mfa2d
    xor ax,ax
    push ax
    call mfa35
    add sp,2h
lblA3Df:
    push word ptr [bp-88h]
    call mfa41
    add sp,2h
lblA49f:
    les bx, dword ptr [bp-0B4h]
    mov ax,word ptr es:[bx+2h]
lblA51f:
    mov word ptr [bp-8Ah],ax
    cmp ax, offset mia55
    jz short lblA5Df
    jmp near ptr lbl256b
lblA5Df:
    lea ax,word ptr [bp-68h]
    push ss
    push ax
    call mfa62
    add sp,4h
    cmp byte ptr ds:[1D00h],0h
    jz short lblA7Df
    mov ax,10h
    push ax
    call mfa75
    add sp,2h
lblA7Df:
    mov ax,1h
    mov byte ptr ds:[1D00h],al
    push ax
    call mfa84
    add sp,2h
    call mfa8c
    mov ax,1h
    push ax
    call mfa95
    add sp,2h
    pop si
    pop di
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
