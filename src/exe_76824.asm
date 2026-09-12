_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi2:NEAR
    EXTRN mf7:FAR
    EXTRN mi10:NEAR
    EXTRN mi11:NEAR
    EXTRN mf14:FAR
    EXTRN mf19:FAR
    EXTRN mf26:FAR
    EXTRN mf26:FAR
    EXTRN mf26:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp, offset mi2
    push si
    push di
    mov ax,0FFFFh
    push ax
    call mf7
    add sp,2h
    mov ax,word ptr ds:[416Eh]
    and ax, offset mi10
    cmp ax, offset mi11
    jnz short lbl23f
    jmp near ptr lbl38f
lbl23f:
    call mf14
    mov ax,100h
    mov dx,2263h
    push dx
    push ax
    call mf19
    add sp,4h
lbl38f:
    and word ptr ds:[416Eh],8h
    pop di
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
