_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi14:NEAR
    EXTRN mi16:NEAR
    EXTRN mi20:NEAR
    EXTRN mf26:FAR
    EXTRN mf37:FAR
    EXTRN mf41:FAR
    EXTRN mi51:NEAR
    EXTRN mi54:NEAR
    EXTRN mi58:NEAR
    EXTRN mf113:FAR
    EXTRN mf125:FAR
    EXTRN mf136:FAR
    EXTRN mi143:NEAR
    EXTRN mf149:FAR
    EXTRN mf161:FAR
    EXTRN mf171:FAR
    EXTRN mf175:FAR
    EXTRN mf180:FAR
    EXTRN mf180:FAR
    EXTRN mf180:FAR
    EXTRN mf180:FAR
    EXTRN mf180:FAR
    EXTRN mf180:FAR
    EXTRN mf180:FAR
    EXTRN mf180:FAR
    EXTRN mf180:FAR
    EXTRN mf180:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,1Ch
    push si
    cmp word ptr ds:[4D3Ah],2h
    jnz short lbl14f
    mov ax,0FFFFh
    jmp near ptr lbl203f
lbl14f:
    mov ax,word ptr ds:[4D3Ah]
    mov word ptr [bp-4h],ax
    inc word ptr ds:[4D3Ah]
    mov cl,3h
    mov ax,word ptr [bp+0Ah]
    shl ax,cl
    sub ax, offset mi14
    mov word ptr [bp-0Ah],ax
    sub ax, offset mi16
    mov word ptr [bp-0Eh],ax
    mov ax,word ptr [bp+8h]
    shl ax,cl
    sub ax, offset mi20
    mov word ptr [bp-8h],ax
    mov dx,word ptr [bp+0Ch]
    shl dx,cl
    sub dx,12h
    mov word ptr [bp-10h],dx
    call mf26
    mov ax,1h
    push ax
    mov ax,4h
    push ax
    xor ax,ax
    push ax
    push word ptr [bp+0Ch]
    push word ptr [bp+0Ah]
    push word ptr [bp+8h]
    push word ptr [bp+6h]
    call mf37
    add sp,8h
    mov word ptr [bp-2h],ax
    push ax
    call mf41
    add sp,8h
    mov ax,word ptr [bp-4h]
    mov bx,word ptr [bp-2h]
    add bx,bx
    mov word ptr [bx+6354h],ax
    mov bx,ax
    add bx,ax
    mov word ptr [bp-1Ch],bx
    mov ax,word ptr [bp-8h]
    add ax, offset mi51
    mov word ptr [bx+6380h],ax
    mov ax,word ptr [bp-10h]
    sub ax, offset mi54
    mov word ptr [bx+6384h],ax
    mov ax,word ptr [bp+0Ah]
    sub ax,word ptr [bp+6h]
    sub ax, offset mi58
    mov word ptr [bx+6388h],ax
    mov word ptr [bp-12h],0h
    les bx, dword ptr [bp+0Eh]
    mov ax,word ptr es:[bx+2h]
    or ax,word ptr es:[bx]
    jz short lblD2f
    mov word ptr [bp-1Ah],bx
lblBFb:
    inc word ptr [bp-12h]
    add word ptr [bp-1Ah],4h
    mov bx,word ptr [bp-1Ah]
    mov ax,word ptr es:[bx+2h]
    or ax,word ptr es:[bx]
    jnz short lblBFb
lblD2f:
    mov bx,word ptr [bp-1Ch]
    mov ax,word ptr [bp-12h]
    mov word ptr [bx+6378h],ax
    mov cx,word ptr [bp+0Ch]
    sub cx,word ptr [bp+8h]
    dec cx
    mov word ptr [bx+637Ch],cx
    xor dx,dx
    mov word ptr [bx+636Ch],dx
    mov word ptr [bx+6370h],dx
    mov dx,word ptr [bp+0Eh]
    mov bx,word ptr [bp+10h]
    mov si,word ptr [bp-4h]
    add si,si
    add si,si
    mov word ptr [si+6364h],dx
    mov word ptr [si+6366h],bx
    mov bx,word ptr [bp-4h]
    mov dl,byte ptr [bp+12h]
    mov byte ptr [bx+6374h],dl
    mov dl,byte ptr [bp+14h]
    mov byte ptr [bx+6376h],dl
    cmp cx,ax
    jl short lbl128f
    mov word ptr [bp-14h],1h
    mov word ptr [bp-16h],80h
    jmp short lbl132f
    nop
lbl128f:
    mov word ptr [bp-14h],2h
    mov word ptr [bp-16h],1h
lbl132f:
    push word ptr [bp-14h]
    mov ax,4h
    push ax
    push word ptr [bp-10h]
    push word ptr [bp-0Ah]
    mov cx,word ptr [bp-8h]
    add cx,0Eh
    push cx
    push word ptr [bp-0Eh]
    push word ptr [bp-2h]
    mov si,cx
    call mf113
    add sp,0Eh
    push word ptr [bp-16h]
    mov ax,4h
    push ax
    mov cx,word ptr [bp-8h]
    add cx,1Ch
    push cx
    push word ptr [bp-0Ah]
    push si
    push word ptr [bp-0Eh]
    push word ptr [bp-2h]
    call mf125
    add sp,0Eh
    mov ax,1h
    push ax
    mov cx,4h
    push cx
    push si
    push word ptr [bp-0Ah]
    push word ptr [bp-8h]
    push word ptr [bp-0Eh]
    push word ptr [bp-2h]
    call mf136
    add sp,0Eh
    mov ax,1h
    push ax
    mov ax,4h
    push ax
    mov ax,word ptr [bp-10h]
    add ax, offset mi143
    push ax
    push word ptr [bp-0Ah]
    push word ptr [bp-10h]
    push word ptr [bp-0Eh]
    push word ptr [bp-2h]
    call mf149
    add sp,0Eh
    mov ax,0FFFFh
    mov word ptr ds:[4DA0h],ax
    mov word ptr ds:[4DA2h],ax
    mov word ptr ds:[4DA4h],ax
    cmp word ptr ds:[4D38h],0h
    jnl short lbl1DEf
    mov ax,word ptr [bp-2h]
    mov word ptr ds:[4D38h],ax
    mov ax,1h
    push ax
    call mf161
    add sp,2h
    jmp short lbl1FBf
    nop
lbl1DEf:
    mov ax,word ptr ds:[4D38h]
    mov word ptr [bp-4h],ax
    mov ax,word ptr [bp-2h]
    mov word ptr ds:[4D38h],ax
    xor ax,ax
    push ax
    call mf171
    add sp,2h
    mov ax,word ptr [bp-4h]
    mov word ptr ds:[4D38h],ax
lbl1FBf:
    call mf175
    mov ax,word ptr [bp-2h]
lbl203f:
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
