_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi6:NEAR
    EXTRN mf53:FAR
    EXTRN mf166:FAR
    EXTRN mi9:NEAR
    EXTRN md14:NEAR
    EXTRN mf7e:FAR
    EXTRN mf15c:FAR
    EXTRN mfdf:FAR
    EXTRN mi43:NEAR
    EXTRN mffb:FAR
    EXTRN mfbd:FAR
    EXTRN mf68:FAR
    EXTRN mf111:FAR
    EXTRN mf145:FAR
    EXTRN mf95:FAR
    EXTRN mfea:FAR
    EXTRN mf16b:FAR
    EXTRN mf100:FAR
    EXTRN mf12c:FAR
mnem_unit:
    push bp
    mov bp,sp
    mov ax,word ptr [bp+6h]
    sub ax, offset mi6
    cmp ax, offset mi9
    jna short lbl11f
    db 0E9h, 64h, 01h ; override
lbl11f:
    add ax,ax
    xchg ax,bx
    jmp word ptr cs:[bx+md14]
    nop
    db 63h, 00h, 98h, 01h, 83h, 00h, 0B1h, 00h, 0B1h, 00h, 0B1h, 00h, 98h, 01h, 0D1h, 00h
    db 98h, 01h, 09h, 01h, 98h, 01h, 98h, 01h, 98h, 01h, 98h, 01h, 98h, 01h, 98h, 01h
    db 17h, 01h, 73h, 01h, 89h, 01h
    mov ax,word ptr ds:[6A06h]
    sub ax, offset mi43
    jz short lbl4Bf
    jmp near ptr lbl175f
lbl4Bf:
    mov ax,6h
    mov dx,0F01Fh
    push dx
    push ax
    call mf53
    mov sp,bp
    mov ax,1h
    jmp near ptr lbl177f
    mov ax,3h
    mov dx,0F01Fh
    push dx
    push ax
    call mf68
    mov sp,bp
    cmp byte ptr ds:[321h],0h
    jz short lbl88f
    mov ax,4h
lbl79b:
    mov dx,0F01Fh
    push dx
    push ax
    call mf7e
lbl83b:
    mov sp,bp
    jmp near ptr lbl175f
lbl88f:
    mov ax,5h
    jmp short lbl79b
    nop
    xor ax,ax
    mov dx,0F01Fh
    push dx
    push ax
    call mf95
    mov sp,bp
    cmp byte ptr ds:[321h],0h
    jz short lblA8f
    mov ax,1h
    jmp short lbl79b
lblA8f:
    mov ax,2h
    jmp short lbl79b
    nop
    cmp byte ptr ds:[321h],0h
    jz short lblC4f
    mov ax,2h
    push ax
    mov ax,2Ch
    push ax
    call mfbd
    mov sp,bp
lblC4f:
    cmp byte ptr ds:[321h],0h
    jnz short lblCEf
    jmp near ptr lbl175f
lblCEf:
    cmp byte ptr ds:[32Eh],0h
    jz short lblD8f
    jmp near ptr lbl175f
lblD8f:
    xor ax,ax
    push ax
    mov ax,18h
    push ax
    call mfdf
    jmp short lbl83b
    mov ax,2Ch
    push ax
    call mfea
    add sp,2h
    jmp short lbl166f
    cmp byte ptr ds:[2FFEh],0h
    jnz short lbl139f
    call mffb
    call mf100
    xor ax,ax
    push ax
    push ax
    mov ax,14h
    push ax
    mov ax,9AFh
    push ax
    call mf111
    add sp,8h
    cmp byte ptr ds:[321h],0h
    jz short lbl134f
    xor ax,ax
    push ax
    push ax
    mov ax,9h
    push ax
    mov ax,9C3h
    push ax
    call mf12c
    add sp,8h
lbl134f:
    mov byte ptr ds:[2FFEh],1h
lbl139f:
    mov ax,2h
    push ax
    mov ax,0h
    mov cx,32FAh
    push cx
    push ax
    call mf145
    add sp,6h
    jmp short lbl177f
    nop
    mov ax,7h
    push ax
    mov ax,18h
    mov cx,32FAh
    push cx
    push ax
    call mf15c
    add sp,6h
    jmp short lbl175f
lbl166f:
    call mf166
    call mf16b
    mov byte ptr ds:[2FFEh],0h
lbl175f:
    xor ax,ax
lbl177f:
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
