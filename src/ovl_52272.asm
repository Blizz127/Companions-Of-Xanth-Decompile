_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN md27:NEAR
    EXTRN md2c:NEAR
    EXTRN md15:NEAR
mnem_unit:
    push bp
    mov bp,sp
    cmp word ptr [bp+6h],8000h
    db 72h, 12h ; override
    mov es, ds:[5AA8h]
    mov bx,word ptr [bp+6h]
    add bx,bx
    add bx,bx
    call dword ptr es:[bx+md15]
    db 0EBh, 15h ; override
lbl1Cf:
    mov es, ds:[5AAAh]
    mov bx,word ptr [bp+6h]
    add bx,bx
    add bx,bx
    mov ax,word ptr es:[bx+md27]
    mov dx,word ptr es:[bx+md2c]
lbl31f:
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
