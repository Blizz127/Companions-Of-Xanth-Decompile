_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi2:NEAR
    EXTRN mf10:FAR
    EXTRN mf29:FAR
    EXTRN mf39:FAR
    EXTRN mf45:FAR
    EXTRN mf45:FAR
    EXTRN mf45:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp, offset mi2
    push si
    push di
    cmp word ptr [bp+0Ah],0h
    jz short lbl12f
    jmp near ptr lbl32f
lbl12f:
    mov ax,word ptr [bp+6h]
    push ax
    call mf10
    add sp,2h
    mov bx,word ptr [bp+6h]
    shl bx,1
    mov ax,word ptr [bp+0Ah]
    mov es, ds:[5B38h]
    mov word ptr es:[bx+48D8h],ax
    jmp near ptr lbl78f
lbl32f:
    mov bx,word ptr [bp+6h]
    shl bx,1
    mov ax,word ptr [bp+0Ah]
    mov es, ds:[5B38h]
    cmp word ptr es:[bx+48D8h],ax
    jnz short lbl48f
    jmp near ptr lbl69f
lbl48f:
    mov ax,word ptr [bp+0Ah]
    push ax
    mov ax,word ptr [bp+6h]
    push ax
    call mf29
    add sp,4h
    mov bx,word ptr [bp+6h]
    shl bx,1
    mov ax,word ptr [bp+0Ah]
    mov es, ds:[5B38h]
    mov word ptr es:[bx+48D8h],ax
lbl69f:
    push word ptr [bp+8h]
    mov ax,word ptr [bp+6h]
    push ax
    call mf39
    add sp,4h
lbl78f:
    pop di
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
