_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf56:FAR
    EXTRN mi9:NEAR
    EXTRN mfc8:FAR
    EXTRN mf84:FAR
    EXTRN mic:NEAR
    EXTRN mfbc:FAR
    EXTRN mf68:FAR
    EXTRN md17:NEAR
    EXTRN mfb0:FAR
    EXTRN mfa4:FAR
    EXTRN mf98:FAR
    EXTRN mf46:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,4h
    mov ax,word ptr [bp+6h]
    sub ax, offset mi9
    cmp ax, offset mic
    jna short lbl14f
    db 0E9h, 0B9h, 00h ; override
lbl14f:
    add ax,ax
    xchg ax,bx
    jmp word ptr cs:[bx+md17]
    db 3Eh, 00h, 60h, 00h, 60h, 00h, 60h, 00h, 0CDh, 00h, 64h, 00h, 7Ch, 00h, 0C4h, 00h
    db 0CDh, 00h, 0CDh, 00h, 0CDh, 00h, 0CDh, 00h, 0CDh, 00h, 0CDh, 00h, 0CDh, 00h, 0CDh, 00h
    db 0C4h, 00h
    mov ax,0Ah
    push ax
    mov ax,1AEh
    push ax
    call mf46
    add sp,4h
    mov ax,1h
lbl51b:
    mov dx,0F048h
    push dx
    push ax
    call mf56
    add sp,4h
    jmp short lblCDf
    xor ax,ax
    jmp short lbl51b
    mov ax,1AFh
    push ax
    call mf68
    add sp,2h
    mov bx,ax
    mov es,dx
    mov word ptr es:[bx],1Ah
    jmp short lblCDf
    nop
    mov ax,0Ah
    push ax
    mov ax,1AEh
    push ax
    call mf84
    add sp,4h
    or ax,ax
    jnz short lblCDf
    mov ax,0Ah
    push ax
    mov ax,1AEh
    push ax
    call mf98
    add sp,4h
    mov ax,0Bh
    push ax
    call mfa4
    add sp,2h
    mov ax,1388h
    push ax
    call mfb0
    add sp,2h
    mov ax,4h
    push ax
    call mfbc
    jmp short lblCDf
    nop
    mov ax,1AFh
    push ax
    call mfc8
lblCDf:
    xor ax,ax
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
