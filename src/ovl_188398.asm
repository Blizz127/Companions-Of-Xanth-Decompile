_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi6:NEAR
    EXTRN mf81:FAR
    EXTRN mi9:NEAR
    EXTRN mf6e:FAR
    EXTRN mf44:FAR
    EXTRN mfe1:FAR
    EXTRN mfaa:FAR
    EXTRN mfb2:FAR
    EXTRN mfb7:FAR
    EXTRN mfcb:FAR
    EXTRN mf9f:FAR
    EXTRN mfd0:FAR
    EXTRN mf90:FAR
mnem_unit:
    push bp
    mov bp,sp
    mov ax,word ptr [bp+6h]
    sub ax, offset mi6
    cmp ax, offset mi9
    jna short lbl11f
    jmp near ptr lblF2f
lbl11f:
    add ax,ax
    xchg ax,bx
    jmp word ptr cs:[bx+9E8h]
    nop
    db 0Ah, 0Ah, 1Ch, 0Ah, 1Ch, 0Ah, 1Ch, 0Ah, 0C0h, 0Ah, 34h, 0Ah, 0C0h, 0Ah, 80h, 0Ah
    db 0C0h, 0Ah, 0C0h, 0Ah, 0C0h, 0Ah, 0C0h, 0Ah, 0C0h, 0Ah, 0C0h, 0Ah, 92h, 0Ah, 0C0h, 0Ah
    db 80h, 0Ah
    mov ax,1h
lbl3Fb:
    mov dx,0F020h
    push dx
    push ax
    call mf44
lbl49b:
    mov sp,bp
    jmp near ptr lblF2f
    cmp word ptr ds:[6A22h],0CDh
    jnz short lbl5Cf
    mov ax,3063h
    jmp short lbl5Ff
    nop
lbl5Cf:
    mov ax,3068h
lbl5Ff:
    push ds
    push ax
    xor ax,ax
    jmp short lbl3Fb
    nop
    mov ax,0Ah
    push ax
    mov ax,0F4h
    push ax
    call mf6e
    mov sp,bp
    or ax,ax
    jnz short lblF2f
    mov ax,0Ah
    push ax
    mov ax,0F4h
    push ax
    call mf81
    mov sp,bp
    mov ax,5A03h
    push ax
    mov ax,15Eh
    push ax
    call mf90
    mov sp,bp
    xor ax,ax
    push ax
    push ax
    mov ax,5h
    push ax
    call mf9f
    mov sp,bp
    mov ax,20h
    push ax
    call mfaa
    jmp short lbl49b
    nop
    call mfb2
    call mfb7
    mov byte ptr ds:[3062h],0h
    jmp short lblF2f
    nop
    cmp byte ptr ds:[3062h],0h
    jnz short lblEDf
    call mfcb
    call mfd0
    xor ax,ax
    push ax
    push ax
    mov ax,24h
    push ax
    mov ax,0A01h
    push ax
    call mfe1
    mov sp,bp
    mov byte ptr ds:[3062h],1h
lblEDf:
    mov ax,1h
    jmp short lblF4f
lblF2f:
    xor ax,ax
lblF4f:
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
