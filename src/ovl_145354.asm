_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi6:NEAR
    EXTRN mfed:FAR
    EXTRN mi9:NEAR
    EXTRN mfb1:FAR
    EXTRN mfd5:FAR
    EXTRN mf96:FAR
    EXTRN mf53:FAR
    EXTRN mf89:FAR
    EXTRN mf68:FAR
    EXTRN mf9b:FAR
    EXTRN mfc4:FAR
    EXTRN mi43:NEAR
    EXTRN mfbf:FAR
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
    jmp word ptr cs:[bx+624h]
    nop
    db 4Ah, 06h, 0FCh, 06h, 6Ah, 06h, 9Ch, 06h, 9Ch, 06h, 9Ch, 06h, 0FCh, 06h, 0FCh, 06h
    db 0FCh, 06h, 0A0h, 06h, 0FCh, 06h, 0FCh, 06h, 0FCh, 06h, 0FCh, 06h, 0FCh, 06h, 0FCh, 06h
    db 0B2h, 06h, 0EEh, 06h, 0A0h, 06h
    mov ax,word ptr ds:[6A06h]
    sub ax, offset mi43
    jz short lbl4Bf
    jmp near ptr lblF2f
lbl4Bf:
    mov ax,3h
    mov dx,0F013h
    push dx
    push ax
    call mf53
    mov sp,bp
lbl5Ab:
    mov ax,1h
    jmp near ptr lblF4f
    mov ax,0B0h
    push ax
    mov ax,0B1h
    push ax
    call mf68
    mov sp,bp
    or ax,ax
    jz short lbl7Cf
    mov ax,2h
    mov dx,0F013h
    jmp short lbl7Ff
    nop
lbl7Cf:
    xor ax,ax
    cwd
lbl7Ff:
    push dx
    push ax
    mov ax,1h
lbl84b:
    mov dx,0F013h
    push dx
    push ax
    call mf89
    mov sp,bp
    jmp short lblF2f
    xor ax,ax
    jmp short lbl84b
    call mf96
    call mf9b
    mov byte ptr ds:[29C0h],0h
    jmp short lblF2f
    nop
    mov ax,1h
    push ax
    mov ax,29C2h
    push ds
    push ax
    call mfb1
    mov sp,bp
    cmp byte ptr ds:[29C0h],0h
    jnz short lbl5Ab
    call mfbf
    call mfc4
    xor ax,ax
    push ax
    push ax
    mov ax,23h
    push ax
    mov ax,62Bh
    push ax
    call mfd5
    mov sp,bp
    mov byte ptr ds:[29C0h],1h
    jmp near ptr lbl5Ab
    mov ax,1h
    push ax
    mov ax,29CEh
    push ds
    push ax
    call mfed
lblF2f:
    xor ax,ax
lblF4f:
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
