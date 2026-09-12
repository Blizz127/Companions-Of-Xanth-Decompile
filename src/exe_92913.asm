_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf5:FAR
    EXTRN mf28:FAR
    EXTRN mi31:NEAR
    EXTRN mi39:NEAR
    EXTRN mf45:FAR
    EXTRN mf48:FAR
    EXTRN mf82:FAR
    EXTRN mf105:FAR
    EXTRN mf128:FAR
    EXTRN mf153:FAR
    EXTRN mf191:FAR
    EXTRN mf224:FAR
    EXTRN mf231:FAR
    EXTRN mf241:FAR
    EXTRN mf241:FAR
    EXTRN mf241:FAR
    EXTRN mf241:FAR
    EXTRN mf241:FAR
    EXTRN mf241:FAR
    EXTRN mf241:FAR
    EXTRN mf241:FAR
    EXTRN mf241:FAR
    EXTRN mf241:FAR
    EXTRN mf241:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,64h
    push si
    push word ptr ds:[4D38h]
    call mf5
    add sp,2h
    mov word ptr [bp-2h],ax
    or ax,ax
    jnl short lbl1Df
    jmp near ptr lbl297f
lbl1Df:
    mov bx,ax
    add bx,ax
    mov ax,word ptr [bx+6370h]
    mov word ptr [bp-10h],ax
    mov ax,word ptr [bx+636Ch]
    mov word ptr [bp-12h],ax
    mov ax,word ptr [bx+637Ch]
    mov word ptr [bp-0Eh],ax
    mov ax,word ptr [bx+6388h]
    mov word ptr [bp-0Ch],ax
    lea ax,word ptr [bp-6h]
    push ss
    push ax
    lea cx,word ptr [bp-4h]
    push ss
    push cx
    push word ptr ds:[4D38h]
    call mf28
    add sp,0Ah
    mov ax,word ptr [bp-4h]
    add ax, offset mi31
    cwd
    and dx,7h
    add ax,dx
    mov cx,3h
    sar ax,cl
    mov word ptr [bp-4h],ax
    mov ax,word ptr [bp-6h]
    add ax, offset mi39
    cwd
    and dx,7h
    add ax,dx
    sar ax,cl
    mov word ptr [bp-6h],ax
    call mf45
    xor ax,ax
    push ax
    call mf48
    add sp,2h
    mov ax,word ptr ds:[4DA0h]
    cmp word ptr [bp-2h],ax
    jz short lbl93f
    jmp near ptr lbl1C8f
lbl93f:
    mov ax,word ptr ds:[4DA2h]
    cmp word ptr [bp-10h],ax
    jz short lbl9Ef
    jmp near ptr lbl1C8f
lbl9Ef:
    mov ax,word ptr ds:[4DA4h]
    cmp word ptr [bp-12h],ax
    jz short lbl122f
    or ax,ax
    jl short lbl122f
    mov bx,word ptr [bp-2h]
    add bx,bx
    cmp word ptr [bx+6378h],ax
    jng short lbl122f
    sub ax,word ptr [bp-10h]
    mov word ptr [bp-8h],ax
    push word ptr [bp-0Ch]
    mov bx,word ptr [bp-2h]
    add bx,bx
    add bx,bx
    les bx, dword ptr [bx+6364h]
    mov si,word ptr ds:[4DA4h]
    add si,si
    add si,si
    push word ptr es:[bx+si+2h]
    push word ptr es:[bx+si]
    lea ax,word ptr [bp-62h]
    push ss
    push ax
    call mf82
    add sp,0Ah
    mov bx,word ptr [bp-2h]
    test byte ptr [bx+6376h],1h
    jz short lbl100f
    mov al,byte ptr [bp-62h]
    cbw
    mov bx,ax
    test byte ptr [bx+56A5h],2h
    jz short lbl100f
    sub byte ptr [bp-62h],20h
lbl100f:
    mov si,word ptr [bp-0Ch]
    mov byte ptr [bp+si-62h],0h
    push si
    lea ax,word ptr [bp-62h]
    push ss
    push ax
    mov ax,word ptr [bp-8h]
    add ax,word ptr [bp-6h]
    push ax
    push word ptr [bp-4h]
    xor ax,ax
    push ax
    call mf105
    add sp,0Ch
lbl122f:
    mov ax,word ptr [bp-12h]
    sub ax,word ptr [bp-10h]
    mov word ptr [bp-8h],ax
    mov ax,word ptr [bp-12h]
    mov bx,word ptr [bp-2h]
    add bx,bx
    cmp word ptr [bx+6378h],ax
    jng short lbl186f
    push word ptr [bp-0Ch]
    mov bx,word ptr [bp-2h]
    add bx,bx
    add bx,bx
    les bx, dword ptr [bx+6364h]
    mov si,ax
    add si,ax
    add si,si
    push word ptr es:[bx+si+2h]
    push word ptr es:[bx+si]
    lea ax,word ptr [bp-62h]
    push ss
    push ax
    call mf128
    add sp,0Ah
    mov bx,word ptr [bp-2h]
    test byte ptr [bx+6376h],1h
    jz short lbl17Cf
    mov al,byte ptr [bp-62h]
    cbw
    mov bx,ax
    test byte ptr [bx+56A5h],2h
    jz short lbl17Cf
    sub byte ptr [bp-62h],20h
lbl17Cf:
    mov si,word ptr [bp-0Ch]
    mov byte ptr [bp+si-62h],0h
    jmp short lbl18Af
    nop
lbl186f:
    mov byte ptr [bp-62h],0h
lbl18Af:
    push word ptr [bp-0Ch]
    lea ax,word ptr [bp-62h]
    push ss
    push ax
    mov ax,word ptr [bp-8h]
    add ax,word ptr [bp-6h]
    push ax
    push word ptr [bp-4h]
    push word ptr [bp+6h]
    call mf153
    mov bx,word ptr [bp-2h]
    add sp,0Ch
    mov al,byte ptr [bx+6374h]
    cbw
    cmp ax,word ptr ds:[4DA4h]
    jz short lbl1BEf
    cbw
    cmp ax,word ptr [bp-12h]
    jz short lbl1BEf
    jmp near ptr lbl280f
lbl1BEf:
    mov word ptr ds:[4DA2h],0FFFFh
    jmp near ptr lbl280f
    nop
lbl1C8f:
    mov word ptr [bp-8h],0h
    cmp word ptr [bp-0Eh],0h
    jg short lbl1D6f
    jmp near ptr lbl280f
lbl1D6b:
lbl1D6f:
    mov ax,word ptr [bp-10h]
    add ax,word ptr [bp-8h]
    mov word ptr [bp-0Ah],ax
    mov bx,word ptr [bp-2h]
    add bx,bx
    cmp ax,word ptr [bx+6378h]
    jnl short lbl236f
    push word ptr [bp-0Ch]
    mov bx,word ptr [bp-2h]
    add bx,bx
    add bx,bx
    les bx, dword ptr [bx+6364h]
    mov si,ax
    add si,ax
    add si,si
    push word ptr es:[bx+si+2h]
    push word ptr es:[bx+si]
    lea ax,word ptr [bp-62h]
    push ss
    push ax
    call mf191
    add sp,0Ah
    mov bx,word ptr [bp-2h]
    test byte ptr [bx+6376h],1h
    jz short lbl22Df
    mov al,byte ptr [bp-62h]
    cbw
    mov bx,ax
    test byte ptr [bx+56A5h],2h
    jz short lbl22Df
    sub byte ptr [bp-62h],20h
lbl22Df:
    mov si,word ptr [bp-0Ch]
    mov byte ptr [bp+si-62h],0h
    jmp short lbl23Af
lbl236f:
    mov byte ptr [bp-62h],0h
lbl23Af:
    mov ax,word ptr [bp-0Ah]
    cmp word ptr [bp-12h],ax
    jnz short lbl250f
    cmp word ptr [bp+6h],0h
    jz short lbl250f
    mov word ptr [bp-64h],1h
    jmp short lbl255f
    nop
lbl250f:
    mov word ptr [bp-64h],0h
lbl255f:
    push word ptr [bp-0Ch]
    lea ax,word ptr [bp-62h]
    push ss
    push ax
    mov ax,word ptr [bp-8h]
    add ax,word ptr [bp-6h]
    push ax
    push word ptr [bp-4h]
    push word ptr [bp-64h]
    call mf224
    add sp,0Ch
    mov ax,word ptr [bp-0Eh]
    inc word ptr [bp-8h]
    cmp word ptr [bp-8h],ax
    jnl short lbl280f
    jmp near ptr lbl1D6b
lbl280f:
    call mf231
    mov ax,word ptr [bp-2h]
    mov word ptr ds:[4DA0h],ax
    mov ax,word ptr [bp-10h]
    mov word ptr ds:[4DA2h],ax
    mov ax,word ptr [bp-12h]
    mov word ptr ds:[4DA4h],ax
lbl297f:
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
