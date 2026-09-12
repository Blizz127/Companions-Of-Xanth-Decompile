_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi3:NEAR
    EXTRN mi14:NEAR
    EXTRN mi23:NEAR
mnem_unit:
    push bp
    mov bp,sp
    mov ax,word ptr [bp+6h]
    sub ax, offset mi3
    jz short lbl10f
    xor ax,ax
    cwd
    jmp short lbl40f
lbl10f:
    mov ax,word ptr ds:[256h]
    cmp ax,9Ah
    jz short lbl3Bf
    jg short lbl2Af
    sub ax,80h
    jz short lbl3Bf
    sub ax, offset mi14
    jz short lbl3Bf
lbl24b:
    mov ax,2AA0h
    jmp short lbl3Ef
    nop
lbl2Af:
    sub ax,9Ch
    jl short lbl24b
    dec ax
    jng short lbl3Bf
    sub ax, offset mi23
    jz short lbl3Bf
    dec ax
    dec ax
    jnz short lbl24b
lbl3Bf:
    mov ax,2A9Bh
lbl3Ef:
    mov dx,ds
lbl40f:
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
