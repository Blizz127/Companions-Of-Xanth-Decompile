_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf89:FAR
    EXTRN mib:NEAR
    EXTRN mf28:FAR
    EXTRN mf4a:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,4h
    push di
    push si
    mov ax,word ptr [bp+6h]
    sub ax, offset mib
    jz short lbl20f
    dec ax
    dec ax
    jl short lbl1Af
    jo short lbl1Af
    dec ax
    dec ax
    jng short lbl42f
lbl1Af:
    xor ax,ax
    cwd
    jmp near ptr lblC3f
lbl20f:
    mov ax,0Ah
    push ax
    mov ax,6Ch
    push ax
    call mf28
    add sp,4h
    or ax,ax
    jz short lbl3Af
    mov ax,240Fh
    jmp short lbl3Df
    nop
lbl3Af:
    mov ax,241Ch
lbl3Df:
    mov dx,ds
    jmp near ptr lblC3f
lbl42f:
    mov ax,6Ch
    push ax
    mov ax,12h
    push ax
    call mf4a
    add sp,4h
    mov bx,1396h
    mov cx,3420h
    mov word ptr [bp-4h],bx
    mov word ptr [bp-2h],cx
    push ds
    push cx
    mov di,ax
    mov si,bx
    mov es,dx
    pop ds
    mov cx,0FFFFh
    xor ax,ax
    repne scasb
    not cx
    sub di,cx
    db 87h, 0FEh ; override
    push ds
    push dx
    pop ds
    pop es
    shr cx,1
    rep movsw
    adc cx,cx
    rep movsb
    pop ds
    mov ax,16h
    mov dx,0F009h
    push dx
    push ax
    call mf89
    add sp,4h
    mov di,ax
    mov es,dx
    push ds
    lds si, dword ptr [bp-4h]
    mov cx,0FFFFh
    xor ax,ax
    repne scasb
    not cx
    sub di,cx
    mov bx,cx
    db 87h, 0FEh ; override
    push ds
    push dx
    pop ds
    pop es
    mov cx,0FFFFh
    repne scasb
    dec di
    mov cx,bx
    shr cx,1
    rep movsw
    adc cx,cx
    rep movsb
    pop ds
    mov ax,word ptr [bp-4h]
    mov dx,word ptr [bp-2h]
lblC3f:
    pop si
    pop di
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
