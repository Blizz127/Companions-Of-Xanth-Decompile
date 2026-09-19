_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi6:NEAR
    EXTRN mf53:FAR
    EXTRN mff5:FAR
    EXTRN mfe8:FAR
    EXTRN mi9:NEAR
    EXTRN mf9c:FAR
    EXTRN mf44:FAR
    EXTRN md14:NEAR
    EXTRN mfce:FAR
    EXTRN mf109:FAR
    EXTRN mff0:FAR
    EXTRN mf14e:FAR
    EXTRN mf138:FAR
    EXTRN mf10e:FAR
    EXTRN mf62:FAR
    EXTRN mf84:FAR
    EXTRN mfd9:FAR
    EXTRN mf11f:FAR
    EXTRN mfab:FAR
    EXTRN mf75:FAR
mnem_unit:
    push bp
    mov bp,sp
    mov ax,word ptr [bp+6h]
    sub ax, offset mi6
    cmp ax, offset mi9
    jna short lbl11f
    db 0E9h, 42h, 01h ; override
lbl11f:
    add ax,ax
    xchg ax,bx
    jmp word ptr cs:[bx+md14]
    nop
    db 7Dh, 00h, 0F7h, 00h, 0F7h, 00h, 0F7h, 00h, 94h, 01h, 94h, 01h, 0FBh, 00h, 31h, 01h
    db 94h, 01h, 94h, 01h, 94h, 01h, 94h, 01h, 94h, 01h, 94h, 01h, 43h, 01h, 83h, 01h
    db 31h, 01h
    mov ax,0Ah
    push ax
    mov ax,14Fh
    push ax
    call mf44
    mov sp,bp
    mov ax,1h
    mov dx,0F039h
    push dx
    push ax
    call mf53
    mov sp,bp
    mov ax,0Ah
    push ax
    mov ax,155h
    push ax
    call mf62
    mov sp,bp
    or ax,ax
    jz short lbl94f
    mov ax,2h
    mov dx,0F039h
    push dx
    push ax
    call mf75
    mov sp,bp
    mov ax,14Fh
    push ax
    mov ax,157h
    push ax
    call mf84
    mov sp,bp
    or ax,ax
    jz short lblA3f
    mov ax,3h
    jmp short lbl97f
lbl94f:
    mov ax,4h
lbl97f:
    mov dx,0F039h
    push dx
    push ax
    call mf9c
    mov sp,bp
lblA3f:
    mov ax,5h
lblA6b:
    mov dx,0F039h
    push dx
    push ax
    call mfab
lblB0b:
    mov sp,bp
    jmp near ptr lbl153f
    nop
    xor ax,ax
    jmp short lblA6b
    cmp word ptr ds:[6A22h],13Eh
    jz short lblC5f
    jmp near ptr lbl153f
lblC5f:
    mov ax,1h
    push ax
    push ax
    mov ax,3h
    push ax
    call mfce
    mov sp,bp
    mov ax,1B58h
    push ax
    call mfd9
    mov sp,bp
    mov ax,5A03h
    push ax
    mov ax,18Bh
    push ax
    call mfe8
    jmp short lblB0b
    nop
    call mff0
    call mff5
    mov byte ptr ds:[3568h],0h
    jmp short lbl153f
    nop
    cmp byte ptr ds:[3568h],0h
    jnz short lbl12Cf
    call mf109
    call mf10e
    xor ax,ax
    push ax
    push ax
    mov ax,6h
    push ax
    mov ax,0F04h
    push ax
    call mf11f
    add sp,8h
    mov byte ptr ds:[3568h],1h
lbl12Cf:
    mov ax,3h
    push ax
    mov ax,0h
    mov cx,32D3h
    push cx
    push ax
    call mf138
    add sp,6h
    jmp short lbl155f
    mov ax,5h
    push ax
    mov ax,24h
    mov cx,32D3h
    push cx
    push ax
    call mf14e
lbl153f:
    xor ax,ax
lbl155f:
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
