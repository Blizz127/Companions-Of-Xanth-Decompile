_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi2:NEAR
    EXTRN mf13:FAR
    EXTRN mf19:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp, offset mi2
    push si
    push di
    mov ax,20h
    push ax
    mov ax,0h
    mov dx,2EC2h
    push dx
    push ax
    push word ptr [bp+8h]
    push word ptr [bp+6h]
    call mf13
    add sp,0Ah
    pop di
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
