_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi9:NEAR
    EXTRN mic:NEAR
    EXTRN mf6a:FAR
    EXTRN mf99:FAR
    EXTRN mf6f:FAR
    EXTRN mf5f:FAR
    EXTRN mf88:FAR
    EXTRN mf83:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,4h
    mov ax,word ptr [bp+6h]
    sub ax, offset mi9
    cmp ax, offset mic
    jna short lbl14f
    jmp near ptr lblACf
lbl14f:
    add ax,ax
    xchg ax,bx
    jmp word ptr cs:[bx+4B3h]
    db 0D5h, 04h, 0D5h, 04h, 0D5h, 04h, 0D5h, 04h, 43h, 05h, 43h, 05h, 43h, 05h, 01h, 05h
    db 43h, 05h, 43h, 05h, 43h, 05h, 43h, 05h, 43h, 05h, 43h, 05h, 13h, 05h, 43h, 05h
    db 01h, 05h
    cmp word ptr [bp+6h],9h
    jnz short lbl4Cf
    mov ax,2F96h
    mov dx,ds
    jmp short lbl4Ff
    nop
lbl4Cf:
    xor ax,ax
    cwd
lbl4Ff:
    mov word ptr [bp-4h],ax
    mov word ptr [bp-2h],dx
    push dx
    push ax
    mov ax,15h
    mov dx,0F033h
    push dx
    push ax
    call mf5f
    add sp,8h
    jmp short lblACf
    nop
    call mf6a
    call mf6f
    mov byte ptr ds:[2F95h],0h
    jmp short lblACf
    nop
    cmp byte ptr ds:[2F95h],0h
    jnz short lblA6f
    call mf83
    call mf88
    xor ax,ax
    push ax
    push ax
    mov ax,14h
    push ax
    mov ax,998h
    push ax
    call mf99
    add sp,8h
    mov byte ptr ds:[2F95h],1h
lblA6f:
    mov ax,1h
    jmp short lblAEf
    nop
lblACf:
    xor ax,ax
lblAEf:
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
