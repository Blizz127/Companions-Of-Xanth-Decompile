_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi2:NEAR
    EXTRN mf9:FAR
    EXTRN mf15:FAR
    EXTRN mf18:FAR
    EXTRN mf25:FAR
    EXTRN mf31:FAR
    EXTRN mf36:FAR
    EXTRN mf43:FAR
    EXTRN mf50:FAR
    EXTRN mf56:FAR
    EXTRN mi60:NEAR
    EXTRN mf76:FAR
    EXTRN mf76:FAR
    EXTRN mf76:FAR
    EXTRN mf76:FAR
    EXTRN mf76:FAR
    EXTRN mf76:FAR
    EXTRN mf76:FAR
    EXTRN mf76:FAR
    EXTRN mf76:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp, offset mi2
    push si
    push di
    mov ax,60h
    push ax
    mov ax,4h
    push ax
    call mf9
    add sp,4h
    mov ax,80h
    push ax
    mov ax,4h
    push ax
    call mf15
    add sp,4h
    push word ptr ds:[6DE0h]
    call mf18
    add sp,2h
    mov word ptr [bp-6h],ax
    mov ax,0FFh
    push ax
    mov ax,2h
    push ax
    call mf25
    add sp,4h
    mov ax,21h
    push ax
    mov ax,4h
    push ax
    call mf31
    add sp,4h
    mov word ptr [bp-4h],0h
    jmp near ptr lbl70f
lbl60b:
    push word ptr ds:[6DE0h]
    call mf36
    add sp,2h
    add word ptr [bp-4h],1h
lbl70f:
    cmp word ptr [bp-4h],0C8h
    jnc short lbl7Af
    jmp near ptr lbl60b
lbl7Af:
    push word ptr ds:[6DE0h]
    call mf43
    add sp,2h
    mov word ptr [bp-8h],ax
    mov ax,60h
    push ax
    mov ax,4h
    push ax
    call mf50
    add sp,4h
    mov ax,80h
    push ax
    mov ax,4h
    push ax
    call mf56
    add sp,4h
    mov ax,word ptr [bp-6h]
    and ax,0E0h
    cmp ax, offset mi60
    jz short lblB7f
    jmp near ptr lblCBf
lblB7f:
    mov ax,word ptr [bp-8h]
    and ax,0E0h
    cmp ax,0C0h
    jz short lblC5f
    jmp near ptr lblCBf
lblC5f:
    mov ax,1h
    jmp near ptr lblCEf
lblCBf:
    mov ax,0h
lblCEf:
    jmp near ptr lblD1f
lblD1f:
    pop di
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
