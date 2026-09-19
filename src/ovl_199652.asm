_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi6:NEAR
    EXTRN mf56:FAR
    EXTRN mi9:NEAR
    EXTRN mff1:FAR
    EXTRN mf73:FAR
    EXTRN mf65:FAR
    EXTRN mf44:FAR
    EXTRN mfba:FAR
    EXTRN mfab:FAR
    EXTRN mfc2:FAR
    EXTRN mf7e:FAR
    EXTRN mfe0:FAR
    EXTRN mfdb:FAR
    EXTRN mf8e:FAR
    EXTRN mfa1:FAR
    EXTRN mfc7:FAR
mnem_unit:
    push bp
    mov bp,sp
    mov ax,word ptr [bp+6h]
    sub ax, offset mi6
    cmp ax, offset mi9
    jna short lbl11f
    jmp near ptr lbl102f
lbl11f:
    add ax,ax
    xchg ax,bx
    jmp word ptr cs:[bx+83Eh]
    nop
    db 60h, 08h, 72h, 08h, 72h, 08h, 72h, 08h, 26h, 09h, 76h, 08h, 0AAh, 08h, 0E6h, 08h
    db 26h, 09h, 26h, 09h, 26h, 09h, 26h, 09h, 26h, 09h, 26h, 09h, 0F8h, 08h, 26h, 09h
    db 0E6h, 08h
    mov ax,1h
lbl3Fb:
    mov dx,0F024h
    push dx
    push ax
    call mf44
lbl49b:
    mov sp,bp
    jmp near ptr lbl102f
    xor ax,ax
    jmp short lbl3Fb
    mov ax,8Bh
    push ax
    call mf56
    mov sp,bp
    cmp ax,141h
    jz short lbl65f
    jmp near ptr lbl102f
lbl65f:
    call mf65
    mov ax,1h
    push ax
    push ax
    mov ax,2h
    push ax
    call mf73
    mov sp,bp
    mov ax,1388h
    push ax
    call mf7e
    jmp short lbl49b
    nop
    mov ax,0Ah
    push ax
    mov ax,107h
    push ax
    call mf8e
    mov sp,bp
    or ax,ax
    jnz short lbl102f
    mov ax,0Ah
    push ax
    mov ax,107h
    push ax
    call mfa1
    mov sp,bp
    xor ax,ax
    push ax
    call mfab
    mov sp,bp
    mov ax,5A03h
    push ax
    mov ax,162h
    push ax
    call mfba
    jmp short lbl49b
    nop
    call mfc2
    call mfc7
    mov byte ptr ds:[316Ch],0h
    jmp short lbl102f
    nop
    cmp byte ptr ds:[316Ch],0h
    jnz short lbl102f
    call mfdb
    call mfe0
    xor ax,ax
    push ax
    push ax
    mov ax,12h
    push ax
    mov ax,0B01h
    push ax
    call mff1
    add sp,8h
    mov ax,1h
    mov byte ptr ds:[316Ch],al
    jmp short lbl104f
    nop
lbl102f:
    xor ax,ax
lbl104f:
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
