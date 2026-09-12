_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf5:FAR
    EXTRN mf8:FAR
    EXTRN mf12:FAR
    EXTRN mf17:FAR
    EXTRN mf21:FAR
    EXTRN mf26:FAR
    EXTRN mf52:FAR
    EXTRN mf52:FAR
    EXTRN mf52:FAR
    EXTRN mf52:FAR
    EXTRN mf52:FAR
    EXTRN mf52:FAR
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
    push word ptr [bp+8h]
    call mf12
    add sp,4h
    mov word ptr [bp-6h],ax
    mov word ptr [bp-4h],dx
    push word ptr [bp+10h]
    call mf17
    add sp,2h
    push word ptr [bp+14h]
    push word ptr [bp+12h]
    call mf21
    add sp,4h
    mov word ptr [bp-0Ah],ax
    mov word ptr [bp-8h],dx
    push word ptr [bp-2h]
    call mf26
    add sp,2h
    jmp short lbl80f
    nop
lbl5Cb:
    mov ax,word ptr [bp-6h]
    mov dx,word ptr [bp-4h]
    mov cx,word ptr [bp+0Ch]
    push ds
    mov si,ax
    mov ds,dx
    les di, dword ptr [bp-0Ah]
    shr cx,1
    rep movsw
    adc cx,cx
    rep movsb
    pop ds
    add word ptr [bp-6h],140h
    add word ptr [bp-0Ah],140h
lbl80f:
    mov ax,word ptr [bp+0Eh]
    dec word ptr [bp+0Eh]
    or ax,ax
    jg short lbl5Cb
    pop si
    pop di
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
