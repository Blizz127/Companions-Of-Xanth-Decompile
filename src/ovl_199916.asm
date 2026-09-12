_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi3:NEAR
    EXTRN mi10:NEAR
    EXTRN mf16:FAR
    EXTRN mf23:FAR
    EXTRN mf30:FAR
    EXTRN mf38:FAR
    EXTRN mi45:NEAR
    EXTRN mf83:FAR
    EXTRN mf92:FAR
    EXTRN mf101:FAR
    EXTRN mf101:FAR
    EXTRN mf101:FAR
    EXTRN mf101:FAR
    EXTRN mf101:FAR
    EXTRN mf101:FAR
mnem_unit:
    push bp
    mov bp,sp
    mov ax,word ptr [bp+6h]
    sub ax, offset mi3
    jz short lbl12f
    dec ax
    dec ax
    jz short lbl68f
    jmp near ptr lblE2f
lbl12f:
    mov ax,word ptr ds:[6A06h]
    sub ax, offset mi10
    jz short lbl1Df
    jmp near ptr lblE2f
lbl1Df:
    push word ptr ds:[6A04h]
    mov ax,26h
    push ax
    call mf16
    mov sp,bp
    push dx
    push ax
    push word ptr ds:[6A02h]
    mov ax,2h
    push ax
    call mf23
    add sp,4h
    push dx
    push ax
    push word ptr ds:[6A04h]
    mov ax,2h
    push ax
    call mf30
    add sp,4h
    push dx
    push ax
    mov ax,7h
lbl55b:
    mov dx,0F024h
    push dx
    push ax
    call mf38
    mov sp,bp
    mov ax,1h
    jmp short lblE4f
    nop
    nop
lbl68f:
    mov ax,word ptr ds:[6A06h]
    cmp ax, offset mi45
    jz short lblCAf
    ja short lblE2f
    cmp al,13h
    jz short lblAEf
    ja short lbl84f
    sub al,7h
    jz short lbl92f
    dec al
    jz short lbl98f
    jmp short lblE2f
    nop
    nop
lbl84f:
    sub al,2Ch
    jz short lbl98f
    sub al,0Ch
    jz short lblB4f
    sub al,0Ch
    jz short lblB4f
    jmp short lblE2f
lbl92f:
    mov ax,6h
    jmp short lbl55b
    nop
lbl98f:
    cmp word ptr ds:[6A06h],2Ch
    jnz short lblA4f
    mov ax,316Dh
    jmp short lblA7f
lblA4f:
    mov ax,3172h
lblA7f:
    push ds
    push ax
    mov ax,3h
    jmp short lbl55b
lblAEf:
    mov ax,2h
    jmp short lbl55b
    nop
lblB4f:
    push word ptr ds:[6A04h]
    mov ax,21h
    push ax
    call mf83
    mov sp,bp
    push dx
    push ax
    mov ax,4h
    jmp short lbl55b
lblCAf:
    push word ptr ds:[6A04h]
    mov ax,22h
    push ax
    call mf92
    add sp,4h
    push dx
    push ax
    mov ax,5h
    jmp near ptr lbl55b
lblE2f:
    xor ax,ax
lblE4f:
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
