_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi2:NEAR
    EXTRN mf26:FAR
    EXTRN mf38:FAR
    EXTRN mf43:FAR
    EXTRN mi46:NEAR
    EXTRN mf59:FAR
    EXTRN mi63:NEAR
    EXTRN mf68:FAR
    EXTRN mf82:FAR
    EXTRN mf89:FAR
    EXTRN mf94:FAR
    EXTRN mf96:FAR
    EXTRN mi103:NEAR
    EXTRN mi115:NEAR
    EXTRN mf121:FAR
    EXTRN mf138:FAR
    EXTRN mf138:FAR
    EXTRN mf138:FAR
    EXTRN mf138:FAR
    EXTRN mf138:FAR
    EXTRN mf138:FAR
    EXTRN mf138:FAR
    EXTRN mf138:FAR
    EXTRN mf138:FAR
    EXTRN mf138:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp, offset mi2
    push si
    push di
    mov word ptr [bp-4h],0h
    jmp near ptr lbl15f
lbl11b:
    add word ptr [bp-4h],1h
lbl15f:
    mov ax,word ptr ds:[4108h]
    cmp word ptr [bp-4h],ax
    jl short lbl20f
    jmp near ptr lbl31f
lbl20f:
    mov ax,word ptr ds:[6DE4h]
    mov dx,0h
    add word ptr ds:[4182h],ax
    adc word ptr ds:[4184h],dx
    jmp near ptr lbl11b
lbl31f:
    cmp word ptr ds:[4176h],0h
    jz short lbl3Bf
    jmp near ptr lbl76f
lbl3Bf:
    cmp word ptr ds:[4168h],0h
    jnz short lbl45f
    jmp near ptr lbl76f
lbl45f:
    cmp word ptr ds:[416Ah],0h
    jz short lbl4Ff
    jmp near ptr lbl76f
lbl4Ff:
    call mf26
    mov cx,word ptr ds:[4166h]
    add cx,0FFFFFFFFFFFFFF9Ch
    cmp ax,cx
    ja short lbl62f
    jmp near ptr lbl76f
lbl62f:
    mov ax,0h
    push ax
    mov ax,1h
    push ax
    mov ax,2h
    push ax
    call mf38
    add sp,6h
lbl76f:
    cmp word ptr ds:[4176h],0h
    jnz short lbl80f
    jmp near ptr lbl85f
lbl80f:
    call mf43
lbl85f:
    mov al,byte ptr ds:[6288h]
    cbw
    cmp ax, offset mi46
    jz short lbl91f
    jmp near ptr lblA0f
lbl91f:
    mov word ptr ds:[4108h],1h
    mov ax,1h
    mov word ptr ds:[410Ah],ax
    jmp near ptr lbl19Ef
lblA0f:
    mov ax,word ptr ds:[410Ah]
    cmp word ptr ds:[4108h],ax
    jnc short lblACf
    jmp near ptr lbl14Af
lblACb:
lblACf:
    mov ax,0h
    push ax
    call mf59
    add sp,2h
    and ax,0FFh
    and ax,80h
    cmp ax, offset mi63
    jnz short lblC6f
    jmp near ptr lblDAf
lblC6f:
    mov ax,0h
    push ax
    call mf68
    add sp,2h
    mov byte ptr ds:[627Eh],al
    add word ptr ds:[627Ch],1h
lblDAf:
    mov al,byte ptr ds:[627Eh]
    and ax,0FFh
    cmp ax,0F7h
    jnz short lblE8f
    jmp near ptr lblF6f
lblE8f:
    mov al,byte ptr ds:[627Eh]
    and ax,0FFh
    cmp ax,0F0h
    jz short lblF6f
    jmp near ptr lblFEf
lblF6f:
    call mf82
    jmp near ptr lbl123f
lblFEf:
    mov al,byte ptr ds:[627Eh]
    and ax,0FFh
    cmp ax,0FFh
    jz short lbl10Cf
    jmp near ptr lbl114f
lbl10Cf:
    call mf89
    jmp near ptr lbl123f
lbl114f:
    mov al,byte ptr ds:[627Eh]
    and ax,0FFh
    push ax
    call mf94
    add sp,2h
lbl123f:
    call mf96
    mov word ptr ds:[4108h],ax
    cmp word ptr ds:[4108h],0h
    jz short lbl135f
    jmp near ptr lbl141f
lbl135f:
    mov al,byte ptr ds:[6284h]
    cbw
    cmp ax, offset mi103
    jnz short lbl141f
    jmp near ptr lblACb
lbl141f:
    mov ax,word ptr ds:[4108h]
    mov word ptr ds:[410Ah],ax
    jmp near ptr lbl157f
lbl14Af:
    mov ax,word ptr ds:[4108h]
    sub word ptr ds:[410Ah],ax
    mov ax,word ptr ds:[410Ah]
    mov word ptr ds:[4108h],ax
lbl157f:
    mov al,byte ptr ds:[6284h]
    cbw
    cmp ax, offset mi115
    jnz short lbl163f
    jmp near ptr lbl172f
lbl163f:
    cmp word ptr ds:[415Ah],0h
    jnz short lbl16Df
    jmp near ptr lbl172f
lbl16Df:
    call mf121
lbl172f:
    cmp word ptr ds:[4108h],0h
    jz short lbl17Cf
    jmp near ptr lbl188f
lbl17Cf:
    mov word ptr ds:[4108h],1h
    mov ax,1h
    mov word ptr ds:[410Ah],ax
lbl188f:
    cmp word ptr ds:[4176h],0h
    jnz short lbl192f
    jmp near ptr lbl198f
lbl192f:
    mov word ptr ds:[4108h],1h
lbl198f:
    mov ax,word ptr ds:[4108h]
    jmp near ptr lbl19Ef
lbl19Ef:
    pop di
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
