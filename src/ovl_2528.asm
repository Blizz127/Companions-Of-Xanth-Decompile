_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf13c:FAR
    EXTRN mf2a:FAR
    EXTRN mffd:FAR
    EXTRN mf60:FAR
    EXTRN mf7b:FAR
    EXTRN mf11b:FAR
    EXTRN mf1e:FAR
    EXTRN mff4:FAR
    EXTRN mf128:FAR
    EXTRN mfae:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,8h
    push di
    push si
    mov ax,1h
    push ax
    mov cx,7Fh
    push cx
    cmp byte ptr ds:[36Eh],al
    db 1Bh, 0C9h ; override
    and cl,9h
    add cx,302h
    push cx
    call mf1e
    add sp,6h
    mov ax,1h
    push ax
    call mf2a
    add sp,2h
    mov word ptr [bp-8h],300h
lbl37b:
    mov bx,word ptr [bp-8h]
    mov es, ds:[5A66h]
    mov word ptr [bp-4h],bx
    mov word ptr [bp-2h],es
    sub ax,ax
    mov word ptr es:[bx+2h],ax
    mov word ptr es:[bx],ax
    mov word ptr es:[bx+0Ch],ax
    mov ax,14h
    imul word ptr es:[bx+0Ah]
    sub dx,dx
    push dx
    push ax
    mov si,bx
    mov di,es
    call mf60
    add sp,4h
    mov es,di
    mov word ptr es:[si+0Eh],ax
    mov word ptr es:[si+10h],dx
    push word ptr es:[si+0Ah]
    push dx
    push word ptr es:[si+0Eh]
    call mf7b
    add sp,6h
    cmp word ptr [bp-8h],300h
    jz short lbl97f
    cmp word ptr [bp+6h],0h
    jz short lblB6f
    cmp word ptr [bp-8h],324h
    jnc short lblB6f
lbl97f:
    mov ax,1h
    push ax
    les bx, dword ptr [bp-4h]
    push word ptr es:[bx+8h]
    push word ptr es:[bx+0Ah]
    push word ptr es:[bx+10h]
    push word ptr es:[bx+0Eh]
    call mfae
    add sp,0Ah
lblB6f:
    add word ptr [bp-8h],12h
    cmp word ptr [bp-8h],35Ah
    jnc short lblC4f
    jmp near ptr lbl37b
lblC4f:
    mov ax,word ptr [bp+6h]
    mov word ptr ds:[5D82h],ax
    or ax,ax
    jz short lblD2f
    xor ax,ax
    jmp short lblDAf
lblD2f:
    mov es, ds:[5A66h]
    mov ax,word ptr es:[31Ch]
lblDAf:
    mov es, ds:[5A66h]
    mov word ptr es:[31Eh],ax
    cmp word ptr [bp+6h],0h
    jz short lblECf
    xor ax,ax
    jmp short lblF0f
lblECf:
    mov ax,word ptr es:[32Eh]
lblF0f:
    mov word ptr es:[330h],ax
    call mff4
    mov ax,632Ah
    push ax
    call mffd
    add sp,2h
    mov es, ds:[5A68h]
    mov ax,38AFh
    push ds
    mov di,0h
    mov si,6A24h
    mov ds,ax
    mov cx,180h
    rep movsw
    pop ds
    call mf11b
    mov ax,1h
    push ax
    mov ax,632Bh
    push ax
    call mf128
    add sp,4h
    mov word ptr ds:[5D80h],0h
    mov word ptr ds:[6D26h],0FFFFh
    call mf13c
    mov es, ds:[5A66h]
    mov word ptr es:[300h],ax
    mov word ptr es:[302h],dx
    pop si
    pop di
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
