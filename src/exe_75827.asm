_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi2:NEAR
    EXTRN mf5:FAR
    EXTRN mf8:FAR
    EXTRN mf12:FAR
    EXTRN mf16:FAR
    EXTRN mf31:FAR
    EXTRN mi38:NEAR
    EXTRN mf44:FAR
    EXTRN mf46:FAR
    EXTRN mf47:FAR
    EXTRN mf52:FAR
    EXTRN mf52:FAR
    EXTRN mf52:FAR
    EXTRN mf52:FAR
    EXTRN mf52:FAR
    EXTRN mf52:FAR
    EXTRN mf52:FAR
    EXTRN mf52:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp, offset mi2
    push si
    push di
    call mf5
    mov ax,20h
    push ax
    call mf8
    add sp,2h
    mov ax,0h
    push ax
    call mf12
    add sp,2h
    mov ax,0h
    push ax
    call mf16
    add sp,2h
    mov word ptr [bp-4h],20h
    mov word ptr [bp-6h],0h
    jmp near ptr lbl64f
lbl3Fb:
    les bx, dword ptr [bp+6h]
    mov al,byte ptr es:[bx]
    cbw
    add word ptr [bp-4h],ax
    mov bx,word ptr [bp+6h]
    mov es, [bp+8h]
    add word ptr [bp+6h],1h
    mov al,byte ptr es:[bx]
    cbw
    push ax
    call mf31
    add sp,2h
    add word ptr [bp-6h],1h
lbl64f:
    cmp word ptr [bp-6h],14h
    jnl short lbl6Df
    jmp near ptr lbl3Fb
lbl6Df:
    mov ax,word ptr [bp-4h]
    and ax, offset mi38
    mov cx,80h
    sub cx,ax
    mov ax,cx
    cbw
    push ax
    call mf44
    add sp,2h
    call mf46
    call mf47
    pop di
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
