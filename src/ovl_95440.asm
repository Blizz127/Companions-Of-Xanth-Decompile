_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi3:NEAR
    EXTRN mi7:NEAR
    EXTRN mi10:NEAR
    EXTRN mi13:NEAR
    EXTRN mi15:NEAR
    EXTRN mi18:NEAR
    EXTRN mf25:FAR
    EXTRN mf31:FAR
    EXTRN mf36:FAR
    EXTRN mf44:FAR
    EXTRN mf52:FAR
    EXTRN mf66:FAR
    EXTRN mf78:FAR
    EXTRN mf78:FAR
    EXTRN mf78:FAR
    EXTRN mf78:FAR
    EXTRN mf78:FAR
    EXTRN mf78:FAR
mnem_unit:
    push bp
    mov bp,sp
    mov ax,word ptr [bp+6h]
    sub ax, offset mi3
    jz short lbl0Ef
    jmp near ptr lblBAf
lbl0Ef:
    mov ax,word ptr ds:[6A06h]
    cmp ax, offset mi7
    jz short lbl7Af
    ja short lbl20f
    sub ax, offset mi10
    jz short lbl36f
    jmp near ptr lblBAf
lbl20f:
    sub ax, offset mi13
    jz short lbl9Cf
    sub ax, offset mi15
    jnc short lbl2Df
    jmp near ptr lblBAf
lbl2Df:
    sub ax, offset mi18
    jna short lbl9Cf
    jmp near ptr lblBAf
    nop
lbl36f:
    mov ax,0Eh
    push ax
    push word ptr ds:[6A04h]
    call mf25
    mov sp,bp
    or ax,ax
    jz short lbl54f
    mov ax,1h
    push ax
    call mf31
    jmp short lbl72f
lbl54f:
    push word ptr ds:[6A04h]
    mov ax,2h
    push ax
    call mf36
    mov sp,bp
    push dx
    push ax
    mov ax,0Ch
lbl68b:
    mov dx,0F016h
    push dx
    push ax
    call mf44
lbl72f:
    mov sp,bp
    mov ax,1h
    jmp short lblBCf
    nop
lbl7Af:
    mov ax,0Eh
    push ax
    push word ptr ds:[6A04h]
    call mf52
    mov sp,bp
    or ax,ax
    jz short lbl92f
    mov ax,2375h
    jmp short lbl95f
lbl92f:
    mov ax,237Ah
lbl95f:
    push ds
    push ax
    mov ax,9h
    jmp short lbl68b
lbl9Cf:
    mov ax,0Eh
    push ax
    push word ptr ds:[6A04h]
    call mf66
    mov sp,bp
    or ax,ax
    jz short lblB4f
    mov ax,0Ah
    jmp short lbl68b
lblB4f:
    mov ax,0Bh
    jmp short lbl68b
    nop
lblBAf:
    xor ax,ax
lblBCf:
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
