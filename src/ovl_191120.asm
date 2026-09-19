_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi6:NEAR
    EXTRN mi9:NEAR
    EXTRN mf44:FAR
    EXTRN md14:NEAR
    EXTRN mf7c:FAR
    EXTRN mf8d:FAR
    EXTRN mf77:FAR
    EXTRN mf5e:FAR
    EXTRN mf57:FAR
    EXTRN mf63:FAR
mnem_unit:
    push bp
    mov bp,sp
    mov ax,word ptr [bp+6h]
    sub ax, offset mi6
    cmp ax, offset mi9
    jna short lbl11f
    db 0E9h, 8Fh, 00h ; override
lbl11f:
    add ax,ax
    xchg ax,bx
    jmp word ptr cs:[bx+md14]
    nop
    db 3Ch, 00h, 4Eh, 00h, 4Eh, 00h, 4Eh, 00h, 0A0h, 00h, 0A0h, 00h, 52h, 00h, 5Eh, 00h
    db 0A0h, 00h, 0A0h, 00h, 0A0h, 00h, 0A0h, 00h, 0A0h, 00h, 0A0h, 00h, 70h, 00h, 0A0h, 00h
    db 5Eh, 00h
    mov ax,1h
lbl3Fb:
    mov dx,0F021h
    push dx
    push ax
    call mf44
lbl49b:
    mov sp,bp
    jmp short lblA0f
    nop
    xor ax,ax
    jmp short lbl3Fb
    mov ax,306Dh
    push ds
    push ax
    call mf57
    jmp short lbl49b
    call mf5e
    call mf63
    mov byte ptr ds:[306Ch],0h
    jmp short lblA0f
    nop
    cmp byte ptr ds:[306Ch],0h
    jnz short lbl9Af
    call mf77
    call mf7c
    xor ax,ax
    push ax
    push ax
    mov ax,3Ch
    push ax
    mov ax,0A26h
    push ax
    call mf8d
    add sp,8h
    mov byte ptr ds:[306Ch],1h
lbl9Af:
    mov ax,1h
    jmp short lblA2f
    nop
lblA0f:
    xor ax,ax
lblA2f:
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
