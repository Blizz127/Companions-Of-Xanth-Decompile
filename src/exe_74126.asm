_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi2:NEAR
    EXTRN mf9:FAR
    EXTRN mi11:NEAR
    EXTRN mf16:FAR
    EXTRN mf21:FAR
    EXTRN mf25:FAR
    EXTRN mf29:FAR
    EXTRN mf33:FAR
    EXTRN mf37:FAR
    EXTRN mf41:FAR
    EXTRN mf45:FAR
    EXTRN mf49:FAR
    EXTRN mf53:FAR
    EXTRN mf57:FAR
    EXTRN mf61:FAR
    EXTRN mf65:FAR
    EXTRN mf69:FAR
    EXTRN mf73:FAR
    EXTRN mf79:FAR
    EXTRN mf87:FAR
    EXTRN mf87:FAR
    EXTRN mf87:FAR
    EXTRN mf87:FAR
    EXTRN mf87:FAR
    EXTRN mf87:FAR
    EXTRN mf87:FAR
    EXTRN mf87:FAR
    EXTRN mf87:FAR
    EXTRN mf87:FAR
    EXTRN mf87:FAR
    EXTRN mf87:FAR
    EXTRN mf87:FAR
    EXTRN mf87:FAR
    EXTRN mf87:FAR
    EXTRN mf87:FAR
    EXTRN mf87:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp, offset mi2
    push si
    push di
    mov ax,word ptr ds:[4172h]
    push ax
    mov ax,word ptr ds:[4174h]
    push ax
    call mf9
    add sp,4h
    cmp ax, offset mi11
    jz short lbl21f
    jmp near ptr lbl27f
lbl21f:
    mov ax,0h
    jmp near ptr lblEEf
lbl27f:
    call mf16
    mov ax,139h
    mov dx,28h
    push dx
    push ax
    call mf21
    add sp,4h
    mov ax,0C5h
    push ax
    call mf25
    add sp,2h
    mov ax,80h
    push ax
    call mf29
    add sp,2h
    mov ax,84h
    push ax
    call mf33
    add sp,2h
    mov ax,8Ch
    push ax
    call mf37
    add sp,2h
    mov ax,8Eh
    push ax
    call mf41
    add sp,2h
    mov ax,33h
    push ax
    call mf45
    add sp,2h
    mov ax,88h
    push ax
    call mf49
    add sp,2h
    mov ax,31h
    push ax
    call mf53
    add sp,2h
    mov ax,3Ah
    push ax
    call mf57
    add sp,2h
    mov ax,8Ah
    push ax
    call mf61
    add sp,2h
    mov ax,90h
    push ax
    call mf65
    add sp,2h
    mov ax,96h
    push ax
    call mf69
    add sp,2h
    mov ax,87h
    push ax
    call mf73
    add sp,2h
    mov ax,0Eh
    mov dx,48h
    push dx
    push ax
    call mf79
    add sp,4h
    mov ax,1h
    jmp near ptr lblEEf
lblEEf:
    pop di
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
