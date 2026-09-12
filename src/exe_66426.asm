_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi2:NEAR
    EXTRN mf31:FAR
    EXTRN mf37:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp, offset mi2
    push si
    push di
    mov ax,word ptr [bp+8h]
    mov dx,word ptr [bp+0Ah]
    mov word ptr [bp-24h],ax
    mov word ptr [bp-22h],dx
    mov word ptr [bp-4h],0h
    jmp near ptr lbl3Bf
lbl1Db:
    mov bx,word ptr [bp-24h]
    mov es, [bp-22h]
    add word ptr [bp-24h],1h
    mov al,byte ptr es:[bx]
    cbw
    mov dx,word ptr [bp-4h]
    shl dx,1
    lea bx,word ptr [bp-20h]
    add bx,dx
    mov word ptr [bx],ax
    add word ptr [bp-4h],1h
lbl3Bf:
    cmp word ptr [bp-4h],0Dh
    jnl short lbl44f
    jmp near ptr lbl1Db
lbl44f:
    push word ptr [bp+0Ch]
    lea ax,word ptr [bp-20h]
    mov dx,ss
    push dx
    push ax
    push word ptr [bp+6h]
    call mf31
    add sp,8h
    pop di
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
