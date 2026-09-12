_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi3:NEAR
    EXTRN mi10:NEAR
    EXTRN mf17:FAR
    EXTRN mi22:NEAR
    EXTRN mf40:FAR
    EXTRN mf46:FAR
    EXTRN mf56:FAR
    EXTRN mf60:FAR
    EXTRN mf64:FAR
    EXTRN mf71:FAR
    EXTRN mf79:FAR
    EXTRN mf85:FAR
    EXTRN mf85:FAR
    EXTRN mf85:FAR
    EXTRN mf85:FAR
    EXTRN mf85:FAR
    EXTRN mf85:FAR
    EXTRN mf85:FAR
    EXTRN mf85:FAR
mnem_unit:
    push bp
    mov bp,sp
    mov ax,word ptr [bp+6h]
    sub ax, offset mi3
    jz short lbl12f
    dec ax
    dec ax
    jz short lbl32f
    jmp near ptr lblD8f
lbl12f:
    mov ax,word ptr ds:[6A06h]
    sub ax, offset mi10
    jz short lbl1Df
    jmp near ptr lblD8f
lbl1Df:
    mov ax,5A00h
    push ax
    mov ax,5Ah
    push ax
    call mf17
lbl2Ab:
    mov sp,bp
lbl2Cb:
    mov ax,1h
    jmp near ptr lblDAf
lbl32f:
    mov ax,word ptr ds:[6A06h]
    cmp ax, offset mi22
    jz short lbl78f
    jna short lbl3Ff
    jmp near ptr lblD8f
lbl3Ff:
    sub al,13h
    jz short lbl4Af
    sub al,1Eh
    jz short lbl50f
    jmp near ptr lblD8f
lbl4Af:
    mov ax,1Dh
    jmp short lbl5Af
    nop
lbl50f:
    cmp byte ptr ds:[341h],0h
    jz short lbl66f
    mov ax,1Eh
lbl5Af:
    mov dx,0F006h
    push dx
    push ax
    call mf40
    jmp short lbl2Ab
lbl66f:
    mov ax,1Fh
    mov dx,0F006h
    push dx
    push ax
    call mf46
lbl73b:
    add sp,4h
    jmp short lbl2Cb
lbl78f:
    cmp word ptr ds:[290h],0h
    jnz short lblC8f
    mov byte ptr ds:[1D00h],0h
    mov ax,5A00h
    push ax
    mov ax,12h
    push ax
    call mf56
    add sp,4h
    cmp byte ptr ds:[309h],0h
    jz short lblA2f
    call mf60
    jmp short lbl2Cb
lblA2f:
    mov ax,10h
    push ax
    call mf64
    add sp,2h
    cmp byte ptr ds:[29Ah],0h
    jnz short lblB8f
    jmp near ptr lbl2Cb
lblB8f:
    mov ax,22h
    push ax
    call mf71
    add sp,2h
    jmp near ptr lbl2Cb
    nop
lblC8f:
    mov ax,5A00h
    push ax
    mov ax,30h
    push ax
    call mf79
    jmp short lbl73b
    nop
lblD8f:
    xor ax,ax
lblDAf:
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
