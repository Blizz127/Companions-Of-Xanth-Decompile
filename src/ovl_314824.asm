_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi3:NEAR
    EXTRN mi10:NEAR
    EXTRN mf17:FAR
    EXTRN mi23:NEAR
    EXTRN mf36:FAR
    EXTRN mf43:FAR
    EXTRN mf48:FAR
    EXTRN mf56:FAR
    EXTRN mf58:FAR
    EXTRN mf67:FAR
    EXTRN mf73:FAR
    EXTRN mf73:FAR
    EXTRN mf73:FAR
    EXTRN mf73:FAR
    EXTRN mf73:FAR
    EXTRN mf73:FAR
    EXTRN mf73:FAR
mnem_unit:
    push bp
    mov bp,sp
    mov ax,word ptr [bp+6h]
    sub ax, offset mi3
    jz short lbl12f
    dec ax
    dec ax
    jz short lbl32f
    jmp near ptr lblAAf
lbl12f:
    mov ax,word ptr ds:[6A06h]
    sub ax, offset mi10
    jz short lbl1Df
    jmp near ptr lblAAf
lbl1Df:
    mov ax,1Fh
lbl20b:
    mov dx,0F049h
    push dx
    push ax
    call mf17
lbl2Ab:
    mov sp,bp
lbl2Cb:
    mov ax,1h
    jmp short lblACf
    nop
lbl32f:
    mov ax,word ptr ds:[6A06h]
    cmp ax, offset mi23
    jz short lbl9Ef
    ja short lblAAf
    sub al,8h
    jz short lbl4Ef
    sub al,0Bh
    jz short lbl5Af
    sub al,19h
    jz short lbl92f
    sub al,18h
    jz short lbl98f
    jmp short lblAAf
lbl4Ef:
    push word ptr ds:[6A04h]
    call mf36
    jmp short lbl2Ab
    nop
lbl5Af:
    mov ax,1Bh
    mov dx,0F049h
    push dx
    push ax
    call mf43
    mov sp,bp
    push word ptr ds:[6A04h]
    mov ax,1C2h
    push ax
    call mf48
    mov sp,bp
    or ax,ax
    jz short lbl8Bf
    mov ax,1Ch
    mov dx,0F049h
    push dx
    push ax
    call mf56
    mov sp,bp
lbl8Bf:
    call mf58
    jmp short lbl2Cb
lbl92f:
    mov ax,1Eh
    jmp short lbl20b
    nop
lbl98f:
    mov ax,1Dh
    jmp short lbl20b
    nop
lbl9Ef:
    push word ptr ds:[6A04h]
    call mf67
    jmp short lbl2Ab
    nop
lblAAf:
    xor ax,ax
lblACf:
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
