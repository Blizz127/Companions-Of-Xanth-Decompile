_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf47:FAR
    EXTRN mie:NEAR
    EXTRN mi23:NEAR
    EXTRN mi2f:NEAR
    EXTRN mf12:FAR
    EXTRN mi5a:NEAR
    EXTRN mf68:FAR
    EXTRN mf5e:FAR
    EXTRN mi3b:NEAR
    EXTRN mf76:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,0Ah
    push di
    push si
    cmp word ptr [bp+6h],1h
    db 1Bh, 0C0h ; override
    and ax, offset mie
    push ax
    call mf12
    add sp,2h
    mov cl,3h
    mov ax,word ptr [bp+0Ah]
    shl ax,cl
    mov dx,ax
    add ax, offset mi23
    push ax
    mov ax,word ptr [bp+10h]
    add ax,word ptr [bp+8h]
    shl ax,cl
    add ax, offset mi2f
    push ax
    push dx
    mov ax,word ptr [bp+8h]
    shl ax,cl
    mov cx,ax
    sub ax, offset mi3b
    push ax
    mov ax,2h
    push ax
    mov si,cx
    mov di,dx
    call mf47
    add sp,0Ah
    mov ax,0FFFFh
    push ax
    cmp word ptr [bp+6h],1h
    cmc
    db 1Bh, 0C0h ; override
    and ax, offset mi5a
    push ax
    call mf5e
    add sp,4h
    push di
    push si
    call mf68
    add sp,4h
    push word ptr [bp+0Eh]
    push word ptr [bp+0Ch]
    call mf76
    add sp,4h
    pop si
    pop di
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
