_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi6:NEAR
    EXTRN mi9:NEAR
    EXTRN mf42:FAR
    EXTRN mff4:FAR
    EXTRN mf8a:FAR
    EXTRN md14:NEAR
    EXTRN mf99:FAR
    EXTRN mfbd:FAR
    EXTRN mf64:FAR
    EXTRN mfb2:FAR
    EXTRN mfe0:FAR
    EXTRN mf10a:FAR
    EXTRN mf51:FAR
    EXTRN mfd1:FAR
    EXTRN mfa4:FAR
mnem_unit:
    push bp
    mov bp,sp
    mov ax,word ptr [bp+6h]
    sub ax, offset mi6
    cmp ax, offset mi9
    jna short lbl11f
    db 0E9h, 0FEh, 00h ; override
lbl11f:
    add ax,ax
    xchg ax,bx
    jmp word ptr cs:[bx+md14]
    nop
    db 3Ah, 00h, 5Ch, 00h, 5Ch, 00h, 5Ch, 00h, 0Fh, 01h, 0Fh, 01h, 82h, 00h, 0Fh, 01h
    db 0Fh, 01h, 0Fh, 01h, 0Fh, 01h, 0Fh, 01h, 0Fh, 01h, 0Fh, 01h, 0E8h, 00h, 0FEh, 00h
    mov ax,0Ah
    push ax
    mov ax,1D5h
    push ax
    call mf42
    mov ax,4h
    mov sp,bp
    mov dx,0F04Bh
lbl4Fb:
    push dx
    push ax
    call mf51
lbl56b:
    mov sp,bp
    jmp near ptr lbl10Ff
    nop
    mov ax,1D5h
    push ax
    mov ax,1DCh
    push ax
    call mf64
    mov sp,bp
    or ax,ax
    jz short lbl74f
    mov ax,2h
    jmp short lbl77f
lbl74f:
    mov ax,3h
lbl77f:
    mov dx,0F04Bh
    push dx
    push ax
    mov ax,1h
    jmp short lbl4Fb
    nop
    mov ax,1D5h
    push ax
    mov ax,5h
    push ax
    call mf8a
    mov sp,bp
    or ax,ax
    jz short lbl10Ff
    mov ax,0Bh
    push ax
    call mf99
    mov sp,bp
    mov ax,0BB8h
    push ax
    call mfa4
    mov sp,bp
    xor ax,ax
    mov dx,0F04Bh
    push dx
    push ax
    call mfb2
    mov sp,bp
    mov ax,1388h
    push ax
    call mfbd
    mov sp,bp
    mov byte ptr ds:[1D00h],0h
    mov ax,5A05h
    push ax
    mov ax,1A5h
    push ax
    call mfd1
    mov sp,bp
    mov ax,5A01h
    push ax
    mov ax,2DDh
    push ax
    call mfe0
    jmp near ptr lbl56b
    mov ax,2h
    push ax
    mov ax,0h
    mov cx,3286h
    push cx
    push ax
    call mff4
    add sp,6h
    jmp short lbl111f
    mov ax,5h
    push ax
    mov ax,18h
    mov cx,3286h
    push cx
    push ax
    call mf10a
lbl10Ff:
    xor ax,ax
lbl111f:
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
