_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN md1a:NEAR
mnem_unit:
    push bp
    mov bp,sp
    cmp word ptr [bp+6h],0h
    db 7Eh, 19h ; override
    cmp word ptr [bp+6h],2Dh
    db 77h, 13h ; override
    mov es, ds:[5A58h]
    mov bx,word ptr [bp+6h]
    add bx,bx
    add bx,bx
    call dword ptr es:[bx+md1a]
    jmp short lbl24f
    nop
lbl22f:
    xor ax,ax
lbl24f:
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
