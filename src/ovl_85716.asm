_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi6:NEAR
    EXTRN mi9:NEAR
    EXTRN mf44:FAR
    EXTRN md14:NEAR
    EXTRN mfa3:FAR
    EXTRN mf91:FAR
    EXTRN mf70:FAR
    EXTRN mfc3:FAR
    EXTRN mff6:FAR
    EXTRN mfe0:FAR
    EXTRN mf61:FAR
    EXTRN mfcf:FAR
    EXTRN mf9e:FAR
mnem_unit:
    push bp
    mov bp,sp
    mov ax,word ptr [bp+6h]
    sub ax, offset mi6
    cmp ax, offset mi9
    jna short lbl11f
    db 0E9h, 0EAh, 00h ; override
lbl11f:
    add ax,ax
    xchg ax,bx
    jmp word ptr cs:[bx+md14]
    nop
    db 60h, 00h, 0BEh, 00h, 0BEh, 00h, 0BEh, 00h, 1Fh, 01h, 1Fh, 01h, 1Fh, 01h, 0C2h, 00h
    db 1Fh, 01h, 1Fh, 01h, 1Fh, 01h, 1Fh, 01h, 1Fh, 01h, 1Fh, 01h, 0D4h, 00h, 0Eh, 01h
    db 0C2h, 00h
    mov ax,0Eh
    push ax
    mov ax,49h
    push ax
    call mf44
    mov sp,bp
    or ax,ax
    jz short lbl54f
    mov ax,2h
    jmp short lbl57f
lbl54f:
    mov ax,3h
lbl57f:
    mov dx,0F005h
    push dx
    push ax
    mov ax,1h
    push dx
    push ax
    call mf61
    mov sp,bp
    mov ax,40h
    push ax
    mov ax,4Eh
    push ax
    call mf70
    mov sp,bp
    or ax,ax
    jz short lbl84f
    mov ax,5h
    mov dx,0F005h
    jmp short lbl87f
    nop
lbl84f:
    xor ax,ax
    cwd
lbl87f:
    push dx
    push ax
    mov ax,4h
lbl8Cb:
    mov dx,0F005h
    push dx
    push ax
    call mf91
    mov sp,bp
    jmp short lblFBf
    xor ax,ax
    jmp short lbl8Cb
    call mf9e
    call mfa3
    mov byte ptr ds:[2232h],0h
    jmp short lblFBf
    nop
    cmp byte ptr ds:[2232h],0h
    jnz short lblD4f
    xor ax,ax
    push ax
    push ax
    mov ax,0Ah
    push ax
    mov ax,24Ah
    push ax
    call mfc3
    mov sp,bp
    mov byte ptr ds:[2232h],1h
    call mfcf
lblD4f:
    mov ax,5h
    push ax
    mov ax,0h
    mov cx,3381h
    push cx
    push ax
    call mfe0
    mov sp,bp
    jmp short lblFDf
    nop
    mov ax,5h
    push ax
    mov ax,3Ch
    mov cx,3381h
    push cx
    push ax
    call mff6
lblFBf:
    xor ax,ax
lblFDf:
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
