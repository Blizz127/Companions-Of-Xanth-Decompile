_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi11:NEAR
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
    mov word ptr [bp-2h],0FFFAh
    mov ax,word ptr ds:[5242h]
    cmp ax, offset mi11
    ja short lbl1Ff
    mov word ptr [bp-2h],ax
lbl1Ff:
    mov ax,word ptr [bp-2h]
    pop di
    pop si
    pop es
    pop ds
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
