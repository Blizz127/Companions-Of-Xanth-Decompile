_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi6:NEAR
    EXTRN mi9:NEAR
    EXTRN mf42:FAR
    EXTRN mf9c:FAR
    EXTRN mf122:FAR
    EXTRN mff8:FAR
    EXTRN mf64:FAR
    EXTRN mf10c:FAR
    EXTRN mfe0:FAR
    EXTRN mf51:FAR
    EXTRN mf86:FAR
    EXTRN mfe8:FAR
    EXTRN mfd0:FAR
    EXTRN mfae:FAR
mnem_unit:
    push bp
    mov bp,sp
    mov ax,word ptr [bp+6h]
    sub ax, offset mi6
    cmp ax, offset mi9
    jna short lbl11f
    jmp near ptr lbl127f
lbl11f:
    add ax,ax
    xchg ax,bx
    jmp word ptr cs:[bx+926h]
    nop
    db 46h, 09h, 68h, 09h, 68h, 09h, 68h, 09h, 33h, 0Ah, 33h, 0Ah, 8Ah, 09h, 33h, 0Ah
    db 33h, 0Ah, 33h, 0Ah, 33h, 0Ah, 33h, 0Ah, 33h, 0Ah, 33h, 0Ah, 0C2h, 09h, 22h, 0Ah
    mov ax,0Ah
    push ax
    mov ax,1B8h
    push ax
    call mf42
    mov sp,bp
    mov ax,2Ah
lbl4Cb:
    mov dx,0F048h
    push dx
    push ax
    call mf51
    mov sp,bp
    jmp near ptr lbl127f
    nop
    mov ax,0Eh
    push ax
    mov ax,1BAh
    push ax
    call mf64
    mov sp,bp
    or ax,ax
    jz short lbl74f
    mov ax,39C3h
    jmp short lbl77f
lbl74f:
    mov ax,39CEh
lbl77f:
    push ds
    push ax
    mov ax,29h
    jmp short lbl4Cb
    mov ax,0Ah
    push ax
    mov ax,1B8h
    push ax
    call mf86
    mov sp,bp
    or ax,ax
    jz short lbl94f
    jmp near ptr lbl127f
lbl94f:
    mov ax,0Ah
    push ax
    mov ax,1B8h
    push ax
    call mf9c
    mov sp,bp
    xor ax,ax
    push ax
    mov ax,1h
    push ax
    mov ax,5h
    push ax
    call mfae
    jmp short lbl127f
    nop
    cmp byte ptr ds:[39C2h],0h
    jz short lbl100f
    mov byte ptr ds:[39C2h],0h
    cmp word ptr ds:[58h],0h
    jnz short lblEDf
    cmp word ptr ds:[56h],1h
    jz short lblEDf
    call mfd0
    xor al,al
    push ax
    mov ax,4h
    push ax
    mov ax,120Eh
    push ax
    call mfe0
    add sp,6h
    call mfe8
lblEDf:
    xor ax,ax
    push ax
    mov ax,1B8h
    push ax
    mov ax,1BBh
    push ax
    call mff8
    add sp,6h
lbl100f:
    mov ax,2h
    push ax
    mov ax,0h
    mov cx,331Fh
    push cx
    push ax
    call mf10c
    add sp,6h
    jmp short lbl129f
    mov ax,6h
    push ax
    mov ax,18h
    mov cx,331Fh
    push cx
    push ax
    call mf122
lbl127f:
    xor ax,ax
lbl129f:
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
