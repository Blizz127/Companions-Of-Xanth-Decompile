_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf5:FAR
    EXTRN mf14:FAR
    EXTRN mf22:FAR
    EXTRN mf28:FAR
    EXTRN mf32:FAR
    EXTRN mf38:FAR
    EXTRN mf44:FAR
    EXTRN mf57:FAR
    EXTRN mf57:FAR
    EXTRN mf57:FAR
    EXTRN mf57:FAR
    EXTRN mf57:FAR
    EXTRN mf57:FAR
    EXTRN mf57:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,6h
    push si
    push word ptr [bp+8h]
    call mf5
    add sp,2h
    mov word ptr [bp-6h],ax
    or ax,ax
    jz short lbl33f
lbl19b:
    mov ax,word ptr [bp+6h]
    cmp word ptr [bp-6h],ax
    jz short lbl92f
    push word ptr [bp-6h]
    call mf14
    add sp,2h
    mov word ptr [bp-6h],ax
    or ax,ax
    jnz short lbl19b
lbl33f:
    mov word ptr [bp-2h],0h
    push word ptr [bp+0Ah]
    push word ptr [bp+8h]
    call mf22
    add sp,4h
    mov word ptr [bp-4h],ax
    or ax,ax
    jz short lbl6Bf
lbl4Db:
    push ax
    call mf28
    add sp,2h
    add word ptr [bp-2h],ax
    push word ptr [bp-4h]
    call mf32
    add sp,2h
    mov word ptr [bp-4h],ax
    or ax,ax
    jnz short lbl4Db
lbl6Bf:
    push word ptr [bp+6h]
    call mf38
    add sp,2h
    add ax,word ptr [bp-2h]
    push word ptr [bp+0Ah]
    push word ptr [bp+8h]
    mov si,ax
    call mf44
    add sp,4h
    cmp si,ax
    jng short lbl98f
    mov ax,1h
    jmp short lbl9Af
lbl92f:
    mov ax,2h
    jmp short lbl9Af
    nop
lbl98f:
    xor ax,ax
lbl9Af:
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
