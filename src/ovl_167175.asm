_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi9:NEAR
    EXTRN mfc8:FAR
    EXTRN mff1:FAR
    EXTRN mic:NEAR
    EXTRN mf108:FAR
    EXTRN mf44:FAR
    EXTRN mf7d:FAR
    EXTRN mfb8:FAR
    EXTRN mf90:FAR
    EXTRN mf54:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,4h
    mov ax,word ptr [bp+6h]
    sub ax, offset mi9
    cmp ax, offset mic
    jna short lbl14f
    jmp near ptr lbl10Df
lbl14f:
    add ax,ax
    xchg ax,bx
    jmp word ptr cs:[bx+9D3h]
    db 0F3h, 09h, 3Fh, 0Ah, 3Fh, 0Ah, 3Fh, 0Ah, 0C4h, 0Ah, 63h, 0Ah, 0C4h, 0Ah, 89h, 0Ah
    db 0C4h, 0Ah, 0C4h, 0Ah, 0C4h, 0Ah, 0C4h, 0Ah, 0C4h, 0Ah, 0C4h, 0Ah, 9Fh, 0Ah, 0B3h, 0Ah
    mov ax,0Ah
    push ax
    mov ax,0C9h
    push ax
    call mf44
    add sp,4h
    mov ax,0Eh
    push ax
    mov ax,0CAh
    push ax
    call mf54
    add sp,4h
    or ax,ax
    jz short lbl68f
    mov ax,2h
    mov dx,0F01Ch
    jmp short lbl6Df
lbl68f:
    mov ax,2C31h
    mov dx,ds
lbl6Df:
    mov word ptr [bp-4h],ax
    mov word ptr [bp-2h],dx
    push dx
    push ax
    mov ax,1h
lbl78b:
    mov dx,0F01Ch
    push dx
    push ax
    call mf7d
    add sp,8h
    jmp near ptr lbl10Df
    mov ax,0Eh
    push ax
    mov ax,0CAh
    push ax
    call mf90
    add sp,4h
    or ax,ax
    jz short lblA2f
    mov ax,2C22h
    jmp short lblA5f
    nop
lblA2f:
    mov ax,2C29h
lblA5f:
    push ds
    push ax
    xor ax,ax
    jmp short lbl78b
    nop
    cmp word ptr ds:[6A22h],0CDh
    jnz short lbl10Df
    mov ax,14h
    push ax
    call mfb8
    add sp,2h
    or ax,ax
    jz short lbl10Df
    mov ax,14h
    push ax
    call mfc8
    add sp,2h
    jmp short lbl10Df
    cmp byte ptr ds:[6E5Ch],1h
    jnz short lbl10Df
    mov word ptr ds:[2EAh],1h
    mov word ptr ds:[2ECh],4h
    jmp short lbl10Df
    nop
    mov ax,1h
    push ax
    mov ax,2C16h
    push ds
    push ax
    call mff1
    add sp,6h
    jmp short lbl10Ff
    nop
    mov ax,7h
    push ax
    mov ax,0h
    mov cx,32FFh
    push cx
    push ax
    call mf108
lbl10Df:
    xor ax,ax
lbl10Ff:
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
