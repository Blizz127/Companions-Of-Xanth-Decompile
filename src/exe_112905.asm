_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf10:FAR
    EXTRN mf20:FAR
    EXTRN mf28:FAR
    EXTRN mf46:FAR
    EXTRN mf54:FAR
    EXTRN mi56:NEAR
    EXTRN mf95:FAR
    EXTRN mf104:FAR
    EXTRN mf122:FAR
    EXTRN mf127:FAR
    EXTRN mi130:NEAR
    EXTRN mf133:FAR
    EXTRN mf139:FAR
    EXTRN mf145:FAR
    EXTRN mf151:FAR
    EXTRN mf166:FAR
    EXTRN mf176:FAR
    EXTRN mf181:FAR
    EXTRN mf188:FAR
    EXTRN mf202:FAR
    EXTRN mf207:FAR
    EXTRN mf207:FAR
    EXTRN mf207:FAR
    EXTRN mf207:FAR
    EXTRN mf207:FAR
    EXTRN mf207:FAR
    EXTRN mf207:FAR
    EXTRN mf207:FAR
    EXTRN mf207:FAR
    EXTRN mf207:FAR
    EXTRN mf207:FAR
    EXTRN mf207:FAR
    EXTRN mf207:FAR
    EXTRN mf207:FAR
    EXTRN mf207:FAR
    EXTRN mf207:FAR
    EXTRN mf207:FAR
    EXTRN mf207:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,1Ch
    push si
    cmp word ptr [bp+6h],0h
    jnl short lbl20f
    push word ptr [bp+6h]
    mov ax,5188h
    push ds
    push ax
    call mf10
    add sp,6h
    jmp near ptr lbl275f
lbl20f:
    mov al,byte ptr [bp+7h]
    cbw
    cmp ax,word ptr ds:[4FB6h]
    jz short lbl62f
    cmp word ptr ds:[4FB6h],0FFFFFFFFFFFFFFFFh
    jz short lbl3Df
    push word ptr ds:[67BEh]
    call mf20
    add sp,2h
lbl3Df:
    mov al,byte ptr [bp+7h]
    cbw
    mov word ptr ds:[4FB6h],ax
    push ax
    mov ax,1h
    push ax
    call mf28
    add sp,4h
    mov word ptr ds:[67BEh],ax
    or ax,ax
    jnz short lbl62f
    mov word ptr ds:[4FB6h],0FFFFh
    jmp near ptr lbl275f
    nop
lbl62f:
    mov al,byte ptr [bp+6h]
    sub ah,ah
    mov cx,ax
    add ax,ax
    add ax,cx
    add ax,ax
    sub dx,dx
    push dx
    push ax
    push word ptr ds:[67BEh]
    call mf46
    mov ax,6h
    add sp,ax
    push ax
    lea cx,word ptr [bp-14h]
    push ss
    push cx
    push word ptr ds:[67BEh]
    call mf54
    add sp,8h
    cmp ax, offset mi56
    jz short lbl9Bf
    jmp near ptr lbl275f
lbl9Bf:
    cmp word ptr [bp-14h],0h
    jnz short lblA4f
    jmp near ptr lbl275f
lblA4f:
    mov bx,word ptr ds:[67C0h]
    add bx,bx
    add bx,bx
    les bx, dword ptr [bx+67C2h]
    mov word ptr [bp-18h],bx
    mov word ptr [bp-16h],es
    mov byte ptr es:[bx],3h
    les bx, dword ptr [bp-18h]
    mov byte ptr es:[bx+1h],0h
    mov ax,word ptr [bp-12h]
    mov word ptr es:[bx+0Ah],ax
    xor ax,ax
    mov word ptr es:[bx+0Ch],ax
    mov word ptr es:[bx+0Eh],ax
    mov word ptr es:[bx+12h],ax
    mov word ptr es:[bx+10h],ax
    mov ax,word ptr [bp-10h]
    inc ax
    mov word ptr [bp-8h],ax
    mov bx,word ptr ds:[67C0h]
    add bx,bx
    mov word ptr [bx+67E2h],ax
    mov ax,14h
    imul word ptr [bp-8h]
    sub dx,dx
    push dx
    push ax
    mov bx,word ptr ds:[67C0h]
    add bx,bx
    add bx,bx
    push word ptr [bx+67C4h]
    push word ptr [bx+67C2h]
    mov si,bx
    call mf95
    add sp,8h
    mov word ptr [si+67C2h],ax
    mov word ptr [si+67C4h],dx
    mov ax,word ptr [bp-14h]
    cwd
    push dx
    push ax
    push word ptr ds:[67BEh]
    call mf104
    add sp,6h
    mov word ptr [bp-2h],1h
    cmp word ptr [bp-8h],1h
    jg short lbl138f
    jmp near ptr lbl275f
lbl138f:
    mov word ptr [bp-1Ch],14h
lbl13Db:
    mov bx,word ptr ds:[67C0h]
    add bx,bx
    add bx,bx
    les bx, dword ptr [bx+67C2h]
    add bx,word ptr [bp-1Ch]
    mov word ptr [bp-18h],bx
    mov word ptr [bp-16h],es
    mov byte ptr es:[bx],3h
    les bx, dword ptr [bp-18h]
    mov byte ptr es:[bx+1h],0h
    push word ptr ds:[67BEh]
    call mf122
    add sp,2h
    les bx, dword ptr [bp-18h]
    mov word ptr es:[bx+0Ah],ax
    push word ptr ds:[67BEh]
    call mf127
    add sp,2h
    mov word ptr [bp-0Ah],ax
    cmp ax, offset mi130
    jnz short lbl1F6f
    push word ptr ds:[67BEh]
    call mf133
    add sp,2h
    add ax,word ptr ds:[4F46h]
    les bx, dword ptr [bp-18h]
    mov word ptr es:[bx+2h],ax
    push word ptr ds:[67BEh]
    call mf139
    add sp,2h
    add ax,word ptr ds:[4F48h]
    les bx, dword ptr [bp-18h]
    mov word ptr es:[bx+4h],ax
    push word ptr ds:[67BEh]
    call mf145
    add sp,2h
    add ax,word ptr ds:[4F46h]
    les bx, dword ptr [bp-18h]
    mov word ptr es:[bx+6h],ax
    push word ptr ds:[67BEh]
    call mf151
    add sp,2h
    add ax,word ptr ds:[4F48h]
    les bx, dword ptr [bp-18h]
    mov word ptr es:[bx+8h],ax
    xor ax,ax
    mov word ptr es:[bx+0Ch],ax
    mov word ptr es:[bx+0Eh],ax
    mov word ptr es:[bx+12h],ax
    mov word ptr es:[bx+10h],ax
    jmp short lbl254f
    nop
lbl1F6f:
    push ax
    push word ptr [bp-16h]
    push word ptr [bp-18h]
    call mf166
    add sp,6h
    or dx,ax
    jz short lbl268f
    mov word ptr [bp-4h],0h
    cmp word ptr [bp-0Ah],0h
    jng short lbl254f
    mov ax,word ptr [bp-0Ah]
    mov word ptr [bp-1Ah],ax
lbl21Ab:
    push word ptr ds:[67BEh]
    call mf176
    add sp,2h
    add ax,word ptr ds:[4F46h]
    mov word ptr [bp-0Ch],ax
    push word ptr ds:[67BEh]
    call mf181
    add sp,2h
    add ax,word ptr ds:[4F48h]
    push ax
    push word ptr [bp-0Ch]
    push word ptr [bp-16h]
    push word ptr [bp-18h]
    call mf188
    add sp,8h
    dec word ptr [bp-1Ah]
    jnz short lbl21Ab
lbl254f:
    add word ptr [bp-1Ch],14h
    mov ax,word ptr [bp-8h]
    inc word ptr [bp-2h]
    cmp word ptr [bp-2h],ax
    jnl short lbl266f
    jmp near ptr lbl13Db
lbl266f:
    jmp short lbl275f
lbl268f:
    mov ax,51ABh
    push ds
    push ax
    call mf202
    add sp,4h
lbl275f:
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
