_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi6:NEAR
    EXTRN mf116:FAR
    EXTRN mf141:FAR
    EXTRN mf132:FAR
    EXTRN mf60:FAR
    EXTRN mf164:FAR
    EXTRN mfb5:FAR
    EXTRN mi9:NEAR
    EXTRN mf188:FAR
    EXTRN mf8a:FAR
    EXTRN mf6f:FAR
    EXTRN mfec:FAR
    EXTRN mf120:FAR
    EXTRN mf1b9:FAR
    EXTRN mfbc:FAR
    EXTRN mf4e:FAR
    EXTRN mf19c:FAR
    EXTRN mf193:FAR
    EXTRN mff9:FAR
    EXTRN mf10f:FAR
    EXTRN mfc9:FAR
    EXTRN mf12b:FAR
    EXTRN mf1a7:FAR
    EXTRN mfda:FAR
    EXTRN mf152:FAR
    EXTRN mf16b:FAR
    EXTRN mfd0:FAR
    EXTRN mf174:FAR
    EXTRN mf1cb:FAR
    EXTRN mfa3:FAR
    EXTRN mfe5:FAR
    EXTRN mf98:FAR
mnem_unit:
    push bp
    mov bp,sp
    mov ax,word ptr [bp+6h]
    sub ax, offset mi6
    cmp ax, offset mi9
    jna short lbl11f
    jmp near ptr lbl1D0f
lbl11f:
    add ax,ax
    xchg ax,bx
    jmp word ptr cs:[bx+0C79h]
    nop
    db 0A1h, 0Ch, 2Fh, 0Eh, 2Fh, 0Eh, 2Fh, 0Eh, 0B7h, 0Ch, 0D9h, 0Ch, 0D9h, 0Ch, 0D9h, 0Ch
    db 2Fh, 0Eh, 2Fh, 0Eh, 0DFh, 0Ch, 2Fh, 0Eh, 2Fh, 0Eh, 2Fh, 0Eh, 2Fh, 0Eh, 2Fh, 0Eh
    db 2Fh, 0Eh, 2Fh, 0Eh, 0Fh, 0Eh, 21h, 0Eh
    mov ax,10Dh
    push ax
    push word ptr ds:[6A04h]
    push word ptr ds:[6A06h]
    call mf4e
lbl53b:
    mov sp,bp
    jmp near ptr lbl1D2f
    mov ax,0Ah
    push ax
    mov ax,10Ch
    push ax
    call mf60
    mov sp,bp
    mov ax,1Ah
lbl6Ab:
    mov dx,0F024h
    push dx
    push ax
    call mf6f
lbl74b:
    mov sp,bp
    jmp near ptr lbl1D0f
    nop
    mov ax,19h
    jmp short lbl6Ab
    nop
    cmp byte ptr ds:[344h],0h
    jz short lbl8Af
    jmp near ptr lbl170f
lbl8Af:
    call mf8a
    mov byte ptr ds:[344h],1h
    mov ax,0Bh
    push ax
    call mf98
    mov sp,bp
    mov ax,0FA0h
    push ax
    call mfa3
    mov sp,bp
    xor ax,ax
    push ax
    mov ax,10Ch
    push ax
    mov ax,11h
    push ax
    call mfb5
    mov sp,bp
    call mfbc
    mov ax,17h
    mov dx,0F024h
    push dx
    push ax
    call mfc9
    mov sp,bp
    call mfd0
    mov ax,31A0h
    push ds
    push ax
    call mfda
    mov sp,bp
    mov ax,1B58h
    push ax
    call mfe5
    mov sp,bp
    call mfec
    mov ax,5A0Fh
    push ax
    mov ax,38Ah
    push ax
    call mff9
    mov sp,bp
    cmp byte ptr ds:[345h],0h
    jnz short lbl14Af
    mov ax,18h
    mov dx,0F024h
    push dx
    push ax
    call mf10f
    mov sp,bp
    call mf116
    mov ax,31A9h
    push ds
    push ax
    call mf120
    mov sp,bp
    mov ax,1770h
    push ax
    call mf12b
    mov sp,bp
    call mf132
    mov word ptr ds:[2A8h],14h
    mov ax,5Ah
    push ax
    call mf141
    mov sp,bp
    jmp short lbl170f
lbl14Af:
    xor ax,ax
    push ax
    push ax
    mov cx,5h
    push cx
    call mf152
    mov sp,bp
    xor ax,ax
    push ax
    mov ax,112h
    push ax
    mov ax,11h
    push ax
    call mf164
    mov sp,bp
    call mf16b
lbl170f:
    mov ax,8Bh
    push ax
    call mf174
    mov sp,bp
    cmp ax,142h
    jnz short lbl1D0f
    mov ax,1h
    push ax
    mov ax,124h
    push ax
    call mf188
    mov sp,bp
    or ax,ax
    jz short lbl1D0f
    call mf193
    mov ax,0Bh
    push ax
    call mf19c
    mov sp,bp
    mov ax,1388h
    push ax
    call mf1a7
    jmp near ptr lbl74b
    nop
    mov ax,1h
    push ax
    mov ax,3188h
    push ds
    push ax
    call mf1b9
    jmp near ptr lbl53b
    nop
    mov ax,1h
    push ax
    mov ax,3194h
    push ds
    push ax
    call mf1cb
lbl1D0f:
    xor ax,ax
lbl1D2f:
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
