_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi2:NEAR
    EXTRN mf7:FAR
    EXTRN mi10:NEAR
    EXTRN mf18:FAR
    EXTRN mi21:NEAR
    EXTRN mf27:FAR
    EXTRN mf35:FAR
    EXTRN mf44:FAR
    EXTRN mf53:FAR
    EXTRN mf62:FAR
    EXTRN mf74:FAR
    EXTRN mf79:FAR
    EXTRN mi82:NEAR
    EXTRN mf86:FAR
    EXTRN mi99:NEAR
    EXTRN mi105:NEAR
    EXTRN mi111:NEAR
    EXTRN mf133:FAR
    EXTRN mf140:FAR
    EXTRN mf146:FAR
    EXTRN mf146:FAR
    EXTRN mf146:FAR
    EXTRN mf146:FAR
    EXTRN mf146:FAR
    EXTRN mf146:FAR
    EXTRN mf146:FAR
    EXTRN mf146:FAR
    EXTRN mf146:FAR
    EXTRN mf146:FAR
    EXTRN mf146:FAR
    EXTRN mf146:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp, offset mi2
    push si
    push di
    mov ax,0h
    push ax
    call mf7
    add sp,2h
    and ax,0FFh
    cmp ax, offset mi10
    jz short lbl20f
    jmp near ptr lbl2Df
lbl20f:
    mov byte ptr ds:[627Eh],2Fh
    sub word ptr ds:[627Ch],1h
    jmp near ptr lbl1A9f
lbl2Df:
    mov ax,0h
    push ax
    call mf18
    add sp,2h
    and ax,0FFh
    cmp ax, offset mi21
    jz short lbl44f
    jmp near ptr lblE3f
lbl44f:
    add word ptr ds:[627Ch],2h
    mov ax,0h
    push ax
    call mf27
    add sp,2h
    and ax,0FFh
    mov dx,0h
    mov word ptr [bp-6h],ax
    mov word ptr [bp-4h],dx
    mov ax,1h
    push ax
    call mf35
    add sp,2h
    and ax,0FFh
    cwd
    mov cx,8h
    mov word ptr [bp-0Ah],ax
    mov word ptr [bp-8h],dx
    mov ax,word ptr [bp-6h]
    mov dx,word ptr [bp-4h]
    call mf44
    mov cx,word ptr [bp-0Ah]
    mov bx,word ptr [bp-8h]
    add ax,cx
    adc dx,bx
    mov word ptr [bp-6h],ax
    mov word ptr [bp-4h],dx
    mov ax,2h
    push ax
    call mf53
    add sp,2h
    and ax,0FFh
    cwd
    mov cx,8h
    mov word ptr [bp-0Ah],ax
    mov word ptr [bp-8h],dx
    mov ax,word ptr [bp-6h]
    mov dx,word ptr [bp-4h]
    call mf62
    mov cx,word ptr [bp-0Ah]
    mov bx,word ptr [bp-8h]
    add ax,cx
    adc dx,bx
    mov word ptr [bp-6h],ax
    mov word ptr [bp-4h],dx
    add word ptr ds:[627Ch],3h
    push word ptr [bp-4h]
    push word ptr [bp-6h]
    mov ax,word ptr ds:[6286h]
    push ax
    call mf74
    add sp,6h
    jmp near ptr lbl1A9f
lblE3f:
    mov ax,0h
    push ax
    call mf79
    add sp,2h
    and ax,0FFh
    cmp ax, offset mi82
    jz short lblFAf
    jmp near ptr lbl19Bf
lblFAf:
    add word ptr ds:[627Ch],1h
    call mf86
    mov word ptr [bp-0Ah],ax
    mov word ptr [bp-8h],dx
    mov ax,word ptr ds:[627Ch]
    les bx, dword ptr ds:[6DE6h]
    mov cx,word ptr es:[bx]
    mov dx,word ptr es:[bx+2h]
    add cx,ax
    mov word ptr [bp-6h],cx
    mov word ptr [bp-4h],dx
    les bx, dword ptr [bp-6h]
    mov al,byte ptr es:[bx]
    and ax,0FFh
    cmp ax, offset mi99
    jz short lbl131f
    jmp near ptr lbl18Ef
lbl131f:
    les bx, dword ptr [bp-6h]
    mov al,byte ptr es:[bx+1h]
    and ax,0FFh
    cmp ax, offset mi105
    jz short lbl143f
    jmp near ptr lbl18Ef
lbl143f:
    les bx, dword ptr [bp-6h]
    mov al,byte ptr es:[bx+2h]
    and ax,0FFh
    cmp ax, offset mi111
    jz short lbl155f
    jmp near ptr lbl18Ef
lbl155f:
    mov ax,5h
    mov cx,word ptr [bp-6h]
    mov dx,word ptr [bp-4h]
    add cx,ax
    push dx
    push cx
    les bx, dword ptr [bp-6h]
    mov al,byte ptr es:[bx+4h]
    and ax,0FFh
    les bx, dword ptr [bp-6h]
    mov cl,byte ptr es:[bx+3h]
    mov word ptr [bp-0Ch],ax
    mov ax,cx
    and ax,0FFh
    mov cx,8h
    shl ax,cl
    mov cx,word ptr [bp-0Ch]
    or ax,cx
    push ax
    call mf133
    add sp,6h
lbl18Ef:
    mov ax,word ptr [bp-0Ah]
    mov dx,word ptr [bp-8h]
    add word ptr ds:[627Ch],ax
    jmp near ptr lbl1A9f
lbl19Bf:
    add word ptr ds:[627Ch],1h
    call mf140
    add word ptr ds:[627Ch],ax
lbl1A9f:
    pop di
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
