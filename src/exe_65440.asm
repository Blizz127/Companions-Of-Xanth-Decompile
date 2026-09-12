_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi2:NEAR
    EXTRN mi19:NEAR
    EXTRN mf41:FAR
    EXTRN mf53:FAR
    EXTRN mf59:FAR
    EXTRN mf59:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp, offset mi2
    push si
    push di
    mov ax,word ptr ds:[5E76h]
    cmp word ptr [bp+6h],ax
    jnc short lbl14f
    jmp near ptr lbl17f
lbl14f:
    jmp near ptr lbl9Bf
lbl17f:
    cmp word ptr [bp+8h],7Fh
    ja short lbl20f
    jmp near ptr lbl25f
lbl20f:
    mov word ptr [bp+8h],7Fh
lbl25f:
    mov ax,word ptr [bp+8h]
    mov bx,word ptr [bp+6h]
    mov byte ptr [bx+5E6Ah],al
    mov al,byte ptr ds:[5E7Bh]
    cbw
    cmp ax, offset mi19
    jnz short lbl3Bf
    jmp near ptr lbl51f
lbl3Bf:
    mov ax,word ptr [bp+6h]
    shl ax,1
    mov cx,17Eh
    mov dx,2E8Eh
    add cx,ax
    mov word ptr [bp-6h],cx
    mov word ptr [bp-4h],dx
    jmp near ptr lbl64f
lbl51f:
    mov ax,word ptr [bp+6h]
    shl ax,1
    mov cx,16Ch
    mov dx,2E8Eh
    add cx,ax
    mov word ptr [bp-6h],cx
    mov word ptr [bp-4h],dx
lbl64f:
    les bx, dword ptr [bp-6h]
    mov al,byte ptr es:[bx]
    and ax,0FFh
    push ax
    call mf41
    add sp,2h
    les bx, dword ptr [bp-6h]
    mov al,byte ptr es:[bx+1h]
    and ax,0FFh
    cmp ax,0FFh
    jnz short lbl88f
    jmp near ptr lbl9Bf
lbl88f:
    les bx, dword ptr [bp-6h]
    mov al,byte ptr es:[bx+1h]
    and ax,0FFh
    push ax
    call mf53
    add sp,2h
lbl9Bf:
    pop di
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
