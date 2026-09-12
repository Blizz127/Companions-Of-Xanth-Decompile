_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
mnem_unit:
    push bp
    mov bp,sp
    sub sp,2h
    push ds
    push es
    push si
    push di
    mov ax,38AFh
    mov ds,ax
    mov ax,word ptr [bp+6h]
    push bp
    mov ah,0h
    int 10h
    pop bp
    mov word ptr [bp-2h],0h
    mov ax,word ptr [bp-2h]
    pop di
    pop si
    pop es
    pop ds
    mov sp,bp
    pop bp
    retf 2h
_TEXT ENDS
    END
