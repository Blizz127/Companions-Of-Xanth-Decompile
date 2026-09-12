_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi2:NEAR
    EXTRN mf13:FAR
    EXTRN mf21:FAR
    EXTRN mf32:FAR
    EXTRN mf42:FAR
    EXTRN mf49:FAR
    EXTRN mf55:FAR
    EXTRN mf63:FAR
    EXTRN mf79:FAR
    EXTRN mf86:FAR
    EXTRN mf86:FAR
    EXTRN mf86:FAR
    EXTRN mf86:FAR
    EXTRN mf86:FAR
    EXTRN mf86:FAR
    EXTRN mf86:FAR
    EXTRN mf86:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp, offset mi2
    push si
    push di
    cmp word ptr ds:[4196h],4h
    jnz short lbl13f
    jmp near ptr lbl16f
lbl13f:
    jmp near ptr lblFCf
lbl16f:
    mov ax,1h
    push ax
    mov ax,6h
    push ax
    call mf13
    add sp,4h
    mov word ptr ds:[4234h],ax
    cmp word ptr ds:[4234h],0h
    jz short lbl33f
    jmp near ptr lbl36f
lbl33f:
    jmp near ptr lblFCf
lbl36f:
    push word ptr ds:[4234h]
    call mf21
    add sp,2h
    mov word ptr ds:[4236h],ax
    mov ax,word ptr ds:[4236h]
    shl ax,1
    shl ax,1
    mov word ptr [bp-4h],ax
    mov ax,word ptr [bp-4h]
    cwd
    push dx
    push ax
    call mf32
    add sp,4h
    mov word ptr ds:[4238h],ax
    mov word ptr ds:[423Ah],dx
    cmp word ptr ds:[4238h],0h
    jz short lbl6Ef
    jmp near ptr lbl80f
lbl6Ef:
    cmp word ptr ds:[423Ah],0h
    jz short lbl78f
    jmp near ptr lbl80f
lbl78f:
    call mf42
    jmp near ptr lblFCf
lbl80f:
    mov ax,word ptr [bp-4h]
    push ax
    push word ptr ds:[423Ah]
    push word ptr ds:[4238h]
    push word ptr ds:[4234h]
    call mf49
    add sp,8h
    mov ax,1020h
    mov dx,0h
    push dx
    push ax
    call mf55
    add sp,4h
    mov word ptr ds:[423Ch],ax
    mov word ptr ds:[423Eh],dx
    mov ax,1020h
    mov dx,0h
    push dx
    push ax
    call mf63
    add sp,4h
    mov word ptr ds:[4240h],ax
    mov word ptr ds:[4242h],dx
    cmp word ptr ds:[423Ch],0h
    jz short lblD0f
    jmp near ptr lblDAf
lblD0f:
    cmp word ptr ds:[423Eh],0h
    jnz short lblDAf
    jmp near ptr lblEEf
lblDAf:
    cmp word ptr ds:[4240h],0h
    jz short lblE4f
    jmp near ptr lblF6f
lblE4f:
    cmp word ptr ds:[4242h],0h
    jz short lblEEf
    jmp near ptr lblF6f
lblEEf:
    call mf79
    jmp near ptr lblFCf
lblF6f:
    mov word ptr ds:[4232h],1h
lblFCf:
    pop di
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
