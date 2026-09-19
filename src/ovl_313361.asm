_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi6:NEAR
    EXTRN mf81:FAR
    EXTRN mi9:NEAR
    EXTRN mf42:FAR
    EXTRN mfd9:FAR
    EXTRN md14:NEAR
    EXTRN mfa8:FAR
    EXTRN mfe9:FAR
    EXTRN mf64:FAR
    EXTRN mf100:FAR
    EXTRN mf51:FAR
    EXTRN mfb8:FAR
    EXTRN mfc7:FAR
    EXTRN mf90:FAR
mnem_unit:
    push bp
    mov bp,sp
    mov ax,word ptr [bp+6h]
    sub ax, offset mi6
    cmp ax, offset mi9
    jna short lbl11f
    db 0E9h, 0F4h, 00h ; override
lbl11f:
    add ax,ax
    xchg ax,bx
    jmp word ptr cs:[bx+md14]
    nop
    db 4Bh, 00h, 6Dh, 00h, 6Dh, 00h, 6Dh, 00h, 16h, 01h, 16h, 01h, 0B1h, 00h, 16h, 01h
    db 16h, 01h, 16h, 01h, 16h, 01h, 16h, 01h, 16h, 01h, 16h, 01h, 0F1h, 00h, 05h, 01h
    mov ax,0Ah
    push ax
    mov ax,1BDh
    push ax
    call mf42
    mov sp,bp
    mov ax,3h
lbl4Cb:
    mov dx,0F049h
    push dx
    push ax
    call mf51
    mov sp,bp
    jmp near ptr lbl105f
    nop
    mov ax,0Eh
    push ax
    mov ax,1BEh
    push ax
    call mf64
    mov sp,bp
    or ax,ax
    jz short lbl74f
    mov ax,3A06h
    jmp short lbl77f
lbl74f:
    mov ax,3A10h
lbl77f:
    push ds
    push ax
    mov ax,1h
    mov dx,0F049h
    push dx
    push ax
    call mf81
    mov sp,bp
    mov ax,0Eh
    push ax
    mov ax,1BEh
    push ax
    call mf90
    mov sp,bp
    or ax,ax
    jz short lbl105f
    mov ax,2h
    jmp short lbl4Cb
    mov ax,0Ah
    push ax
    mov ax,1BDh
    push ax
    call mfa8
    mov sp,bp
    or ax,ax
    jnz short lbl105f
    mov dx,0F049h
    push dx
    push ax
    call mfb8
    mov sp,bp
    mov ax,0Ah
    push ax
    mov ax,1BDh
    push ax
    call mfc7
    mov sp,bp
    xor ax,ax
    push ax
    mov ax,1h
    push ax
    mov ax,5h
    push ax
    call mfd9
    jmp short lbl105f
    mov ax,1h
    push ax
    mov ax,39FAh
    push ds
    push ax
    call mfe9
    add sp,6h
    jmp short lbl107f
    nop
    mov ax,2h
    push ax
    mov ax,0h
    mov cx,3325h
    push cx
    push ax
    call mf100
lbl105f:
    xor ax,ax
lbl107f:
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
