_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf36:FAR
    EXTRN mf39:FAR
    EXTRN mf76:FAR
    EXTRN mf89:FAR
    EXTRN mf89:FAR
    EXTRN mf89:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,0Eh
    mov word ptr [bp-2h],0h
    mov word ptr [bp-0Ah],1h
    mov ax,word ptr [bp+8h]
    or ax,word ptr [bp+6h]
    jnz short lbl26f
    mov byte ptr ds:[5DB4h],30h
    mov word ptr [bp-2h],1h
    jmp near ptr lblEBf
    nop
lbl26f:
    cmp word ptr [bp+8h],0h
    jnl short lbl40f
    neg word ptr [bp+6h]
    adc word ptr [bp+8h],0h
    neg word ptr [bp+8h]
    mov byte ptr ds:[5DB4h],2Dh
    mov word ptr [bp-2h],1h
lbl40f:
    mov word ptr [bp-0Eh],0CA00h
    mov word ptr [bp-0Ch],3B9Ah
lbl4Ab:
    mov ax,word ptr [bp+6h]
    mov dx,word ptr [bp+8h]
    cmp word ptr [bp-0Ch],dx
    jg short lblCEf
    jl short lbl5Cf
    cmp word ptr [bp-0Eh],ax
    ja short lblCEf
lbl5Cf:
    mov ax,3E8h
    cwd
    push dx
    push ax
    push word ptr [bp-0Ch]
    push word ptr [bp-0Eh]
    push word ptr [bp+8h]
    push word ptr [bp+6h]
    call mf36
    push dx
    push ax
    call mf39
    mov word ptr [bp-8h],ax
    cmp word ptr [bp-0Ah],0h
    jnz short lbl8Ef
    mov bx,word ptr [bp-2h]
    mov byte ptr [bx+5DB4h],2Ch
    inc word ptr [bp-2h]
lbl8Ef:
    mov word ptr [bp-6h],64h
lbl93b:
    mov ax,word ptr [bp-8h]
    cwd
    idiv word ptr [bp-6h]
    mov cx,0Ah
    cwd
    idiv cx
    mov word ptr [bp-4h],dx
    cmp word ptr [bp-0Ah],0h
    jz short lblADf
    or dx,dx
    jz short lblC1f
lblADf:
    mov al,byte ptr [bp-4h]
    mov bx,word ptr [bp-2h]
    add al,30h
    mov byte ptr [bx+5DB4h],al
    inc word ptr [bp-2h]
    mov word ptr [bp-0Ah],0h
lblC1f:
    mov ax,word ptr [bp-6h]
    cwd
    idiv cx
    mov word ptr [bp-6h],ax
    or ax,ax
    jg short lbl93b
lblCEf:
    mov ax,3E8h
    cwd
    push dx
    push ax
    lea ax,word ptr [bp-0Eh]
    push ax
    call mf76
    or dx,dx
    jz short lblE4f
    jmp near ptr lbl4Ab
lblE4f:
    or ax,ax
    jz short lblEBf
    jmp near ptr lbl4Ab
lblEBf:
    mov bx,word ptr [bp-2h]
    mov byte ptr [bx+5DB4h],0h
    mov ax,5DB4h
    mov dx,ds
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
