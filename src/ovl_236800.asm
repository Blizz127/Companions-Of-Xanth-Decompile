_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf5:FAR
    EXTRN mf23:FAR
    EXTRN mf24:FAR
    EXTRN mf25:FAR
    EXTRN mf26:FAR
    EXTRN mf35:FAR
    EXTRN mf36:FAR
    EXTRN mf37:FAR
    EXTRN mf38:FAR
    EXTRN mf43:FAR
    EXTRN mf45:FAR
    EXTRN mf50:FAR
    EXTRN mf50:FAR
    EXTRN mf50:FAR
    EXTRN mf50:FAR
    EXTRN mf50:FAR
    EXTRN mf50:FAR
    EXTRN mf50:FAR
    EXTRN mf50:FAR
    EXTRN mf50:FAR
    EXTRN mf50:FAR
    EXTRN mf50:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,8h
    push di
    push si
    call mf5
    mov ax,word ptr ds:[5B08h]
    mov cx,ax
    add ax,ax
    add ax,cx
    add ax,6A24h
    mov cx,38AFh
    mov word ptr [bp-8h],ax
    mov word ptr [bp-6h],cx
    mov word ptr [bp-4h],8h
lbl27b:
    mov si,32CAh
    les di, dword ptr [bp-8h]
    movsw
    movsw
    movsw
    movsw
    movsb
    mov word ptr ds:[4F4Eh],1h
    call mf23
    call mf24
    call mf25
    call mf26
    mov si,32C0h
    les di, dword ptr [bp-8h]
    movsw
    movsw
    movsw
    movsw
    movsb
    mov word ptr ds:[4F4Eh],1h
    call mf35
    call mf36
    call mf37
    call mf38
    dec word ptr [bp-4h]
    jnz short lbl27b
    mov ax,3E8h
    push ax
    call mf43
    add sp,2h
    call mf45
    pop si
    pop di
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
