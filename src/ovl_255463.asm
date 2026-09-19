_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi6:NEAR
    EXTRN mfa5:FAR
    EXTRN mi9:NEAR
    EXTRN mfdc:FAR
    EXTRN mfed:FAR
    EXTRN mf8b:FAR
    EXTRN mf44:FAR
    EXTRN mf6a:FAR
    EXTRN mf53:FAR
    EXTRN mf96:FAR
    EXTRN mfbe:FAR
    EXTRN mfc3:FAR
    EXTRN mf80:FAR
    EXTRN mfb7:FAR
    EXTRN mfd7:FAR
mnem_unit:
    push bp
    mov bp,sp
    mov ax,word ptr [bp+6h]
    sub ax, offset mi6
    cmp ax, offset mi9
    jna short lbl11f
    jmp near ptr lblFCf
lbl11f:
    add ax,ax
    xchg ax,bx
    jmp word ptr cs:[bx+991h]
    nop
    db 0B3h, 09h, 0D5h, 09h, 0D5h, 09h, 0D5h, 09h, 73h, 0Ah, 73h, 0Ah, 0D9h, 09h, 35h, 0Ah
    db 73h, 0Ah, 73h, 0Ah, 73h, 0Ah, 73h, 0Ah, 73h, 0Ah, 73h, 0Ah, 47h, 0Ah, 73h, 0Ah
    db 35h, 0Ah
    mov ax,0Ah
    push ax
    mov ax,139h
    push ax
    call mf44
    mov sp,bp
    mov ax,1h
lbl4Eb:
    mov dx,0F042h
    push dx
    push ax
    call mf53
lbl58b:
    mov sp,bp
    jmp near ptr lblFCf
    nop
    xor ax,ax
    jmp short lbl4Eb
    mov ax,0Ah
    push ax
    mov ax,139h
    push ax
    call mf6a
    mov sp,bp
    or ax,ax
    jz short lbl78f
    jmp near ptr lblFCf
lbl78f:
    mov ax,0Ah
    push ax
    mov ax,139h
    push ax
    call mf80
    mov sp,bp
    mov ax,0Bh
    push ax
    call mf8b
    mov sp,bp
    mov ax,1388h
    push ax
    call mf96
    mov sp,bp
    mov ax,5A03h
    push ax
    mov ax,174h
    push ax
    call mfa5
    mov sp,bp
    mov ax,1h
    push ax
    xor ax,ax
    push ax
    mov ax,5h
    push ax
    call mfb7
    jmp short lbl58b
    call mfbe
    call mfc3
    mov byte ptr ds:[3496h],0h
    jmp short lblFCf
    nop
    cmp byte ptr ds:[3496h],0h
    jnz short lblFCf
    call mfd7
    call mfdc
    xor ax,ax
    push ax
    push ax
    mov ax,18h
    push ax
    mov ax,0E01h
    push ax
    call mfed
    mov sp,bp
    mov ax,1h
    mov byte ptr ds:[3496h],al
    jmp short lblFEf
lblFCf:
    xor ax,ax
lblFEf:
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
