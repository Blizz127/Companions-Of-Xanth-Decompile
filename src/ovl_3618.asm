_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf5:FAR
    EXTRN mf8:FAR
    EXTRN mf13:FAR
    EXTRN mf18:FAR
    EXTRN mf23:FAR
    EXTRN mf28:FAR
    EXTRN mf48:FAR
    EXTRN mf48:FAR
    EXTRN mf48:FAR
    EXTRN mf48:FAR
    EXTRN mf48:FAR
    EXTRN mf48:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,0Ch
    push di
    push si
    call mf5
    mov word ptr [bp-2h],ax
    push word ptr [bp+6h]
    call mf8
    add sp,2h
    push word ptr [bp+0Ah]
    xor ax,ax
    push ax
    call mf13
    add sp,4h
    mov word ptr [bp-6h],ax
    mov word ptr [bp-4h],dx
    push word ptr [bp+8h]
    call mf18
    add sp,2h
    push word ptr [bp+0Ah]
    xor ax,ax
    push ax
    call mf23
    add sp,4h
    mov word ptr [bp-0Ah],ax
    mov word ptr [bp-8h],dx
    push word ptr [bp-2h]
    call mf28
    add sp,2h
    mov ax,140h
    imul word ptr [bp+0Ch]
    mov cx,ax
    mov ax,word ptr [bp-6h]
    mov dx,word ptr [bp-4h]
    push ds
    mov si,ax
    mov ds,dx
    les di, dword ptr [bp-0Ah]
    shr cx,1
    rep movsw
    adc cx,cx
    rep movsb
    pop ds
    pop si
    pop di
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
