_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf47:FAR
    EXTRN mi151:NEAR
    EXTRN mf176:FAR
    EXTRN mf94:FAR
    EXTRN mi66:NEAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,14h
    push di
    push si
    mov word ptr [bp-0Ch],4FAEh
lbl0Db:
    mov bx,word ptr [bp-0Ch]
    cmp word ptr [bx],0h
    jz short lbl17f
    inc word ptr [bx]
lbl17f:
    add word ptr [bp-0Ch],2h
    cmp word ptr [bp-0Ch],4FB2h
    jc short lbl0Db
    mov word ptr [bp-6h],0h
    mov word ptr [bp-0Eh],4FAAh
lbl2Cb:
    mov ax,word ptr [bp+6h]
    mov bx,word ptr [bp-0Eh]
    cmp word ptr [bx],ax
    jnz short lbl39f
    jmp near ptr lbl140f
lbl39f:
    inc word ptr [bp-6h]
    add word ptr [bp-0Eh],2h
    cmp word ptr [bp-0Eh],4FAEh
    jc short lbl2Cb
    call mf47
    mov bx,ax
    mov word ptr [bp-6h],ax
    add bx,ax
    mov ax,word ptr [bp+6h]
    mov word ptr [bx+4FAAh],ax
    mov word ptr [bx+4FAEh],1h
    mov ax,0C00h
    imul word ptr [bp-6h]
    add ax, offset mi66
    mov cx,2ECBh
    mov word ptr ds:[67B6h],ax
    mov word ptr ds:[67B8h],cx
    mov dx,cx
    mov cl,0Ah
    mov bx,word ptr [bp-6h]
    shl bx,cl
    add bx,1800h
    mov word ptr ds:[67BAh],bx
    mov word ptr ds:[67BCh],2ECBh
    mov cx,0C00h
    push cx
    push dx
    push ax
    push word ptr ds:[4F44h]
    call mf94
    add sp,8h
    xor ax,ax
    mov word ptr [bp-6h],ax
    mov word ptr [bp-10h],ax
    mov word ptr [bp-12h],ax
lblA7b:
    les bx, dword ptr ds:[67B6h]
    add bx,word ptr [bp-12h]
    mov word ptr [bp-4h],bx
    mov word ptr [bp-2h],es
    mov al,byte ptr es:[bx+4h]
    cbw
    add ax,ax
    add ax,ax
    mov word ptr [bp-8h],ax
    mov al,byte ptr es:[bx+5h]
    and al,10h
    cmp al,1h
    cmc
    db 1Bh, 0C0h ; override
    and ax,300h
    mov word ptr [bp-0Ah],ax
    mov ax,word ptr es:[bx+2h]
    or ax,word ptr es:[bx]
    jnz short lblDDf
    jmp near ptr lbl1B3f
lblDDf:
    mov bx,word ptr ds:[67B6h]
    add bx,word ptr [bp-12h]
    mov ax,word ptr es:[bx+0Eh]
    or ax,word ptr es:[bx+0Ch]
    jnz short lblF1f
    jmp near ptr lbl172f
lblF1f:
    mov ax,word ptr [bp-0Ah]
    cwd
    mov bx,word ptr ds:[67B6h]
    add bx,word ptr [bp-12h]
    mov cx,word ptr es:[bx+0Ch]
    mov si,word ptr es:[bx+0Eh]
    mov bx,word ptr [bp-4h]
    sub cx,word ptr es:[bx]
    sbb si,word ptr es:[bx+2h]
    sub cx,ax
    db 1Bh, 0F2h ; override
    mov ax,word ptr [bp-8h]
    cwd
    sub cx,ax
    db 1Bh, 0F2h ; override
    les bx, dword ptr ds:[67BAh]
    mov di,word ptr [bp-10h]
    mov word ptr es:[bx+di],cx
    mov word ptr es:[bx+di+2h],si
    add word ptr [bp-10h],4h
    inc word ptr [bp-6h]
    add word ptr [bp-12h],0Ch
    cmp word ptr [bp-12h],0C00h
    jnl short lbl13Df
    jmp near ptr lblA7b
lbl13Df:
    jmp short lbl1B3f
    nop
lbl140f:
    mov bx,word ptr [bp-6h]
    add bx,bx
    mov ax,0C00h
    mov word ptr [bx+4FAEh],1h
    imul word ptr [bp-6h]
    add ax, offset mi151
    mov word ptr ds:[67B6h],ax
    mov word ptr ds:[67B8h],2ECBh
    mov cl,0Ah
    mov ax,word ptr [bp-6h]
    shl ax,cl
    add ax,1800h
    mov word ptr ds:[67BAh],ax
    mov word ptr ds:[67BCh],2ECBh
    jmp short lbl1E3f
lbl172f:
    push word ptr ds:[4F44h]
    call mf176
    add sp,2h
    les bx, dword ptr [bp-4h]
    sub ax,word ptr es:[bx]
    sbb dx,word ptr es:[bx+2h]
    mov cx,ax
    mov ax,word ptr [bp-0Ah]
    mov bx,dx
    cwd
    sub cx,ax
    db 1Bh, 0DAh ; override
    mov ax,word ptr [bp-8h]
    cwd
    sub cx,ax
    db 1Bh, 0DAh ; override
    mov ax,bx
    mov bx,word ptr [bp-6h]
    add bx,bx
    add bx,bx
    les si, dword ptr ds:[67BAh]
    mov word ptr es:[bx+si],cx
    mov word ptr es:[bx+si+2h],ax
    inc word ptr [bp-6h]
lbl1B3f:
    cmp word ptr [bp-6h],100h
    jnl short lbl1E3f
    mov ax,word ptr [bp-6h]
    add ax,ax
    add ax,ax
    mov word ptr [bp-14h],ax
    mov es, ds:[67BCh]
lbl1C8b:
    mov bx,word ptr ds:[67BAh]
    mov si,word ptr [bp-14h]
    sub ax,ax
    mov word ptr es:[bx+si+2h],ax
    mov word ptr es:[bx+si],ax
    add word ptr [bp-14h],4h
    cmp word ptr [bp-14h],400h
    jl short lbl1C8b
lbl1E3f:
    pop si
    pop di
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
