_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf17:FAR
    EXTRN md35:NEAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,6h
    cmp word ptr [bp+6h],0h
    db 74h, 34h ; override
    mov ax,word ptr ds:[84Ch]
    cmp word ptr [bp+6h],ax
    db 7Fh, 2Ch ; override
    push word ptr [bp+6h]
    call mf17
    add sp,2h
    or ax,ax
    db 74h, 1Dh ; override
    cmp ax,1C0h
    db 77h, 18h ; override
    push word ptr [bp+8h]
    mov es, ds:[5A62h]
    mov bx,ax
    add bx,ax
    add bx,bx
    call dword ptr es:[bx+md35]
    add sp,2h
    jmp short lbl42f
    nop
lbl40f:
    xor ax,ax
lbl42f:
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
