_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf23:FAR
    EXTRN mi4a:NEAR
    EXTRN mf60:FAR
    EXTRN mf8c:FAR
    EXTRN mf9b:FAR
    EXTRN md5b:NEAR
    EXTRN mf7b:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,8h
    xor ax,ax
    mov word ptr [bp-4h],ax
    mov word ptr ds:[262h],ax
    mov word ptr [bp-2h],ax
    mov word ptr [bp-6h],2h
lbl16b:
    mov es, ds:[5AB4h]
    mov bx,word ptr [bp-6h]
    sub bx,2h
    push word ptr es:[bx]
    call mf23
    add sp,2h
    or ax,ax
    jz short lbl43f
    mov bx,word ptr [bp-6h]
    mov es, ds:[5AB4h]
    mov ax,word ptr es:[bx]
    cmp ax,word ptr ds:[256h]
    db 74h, 15h ; override
    or ax,ax
    db 74h, 11h ; override
lbl43f:
    inc word ptr [bp-2h]
    add word ptr [bp-6h],4h
    cmp word ptr [bp-6h], offset mi4a
    jc short lbl16b
    db 0EBh, 19h ; override
    nop
lbl54f:
    mov bx,word ptr [bp-2h]
    add bx,bx
    add bx,bx
    push word ptr es:[bx+md5b]
    call mf60
    add sp,2h
    inc ax
    mov word ptr [bp-4h],ax
lbl6Cf:
    cmp word ptr [bp-4h],0h
    jnz short lbl77f
    mov word ptr [bp-4h],1h
lbl77f:
    mov ax,5h
    push ax
    call mf7b
    add sp,2h
    or ax,ax
    jnz short lbl94f
    mov ax,1D08h
    push ds
    push ax
    call mf8c
    add sp,4h
lbl94f:
    push word ptr [bp-4h]
    mov ax,1h
    push ax
    call mf9b
    mov ax,1h
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
