_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi2:NEAR
    EXTRN mi6:NEAR
    EXTRN mi7:NEAR
    EXTRN mf25:FAR
    EXTRN mf37:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp, offset mi2
    push si
    push di
    mov ax,word ptr ds:[416Eh]
    and ax, offset mi6
    cmp ax, offset mi7
    jnz short lbl17f
    jmp near ptr lbl2Af
lbl17f:
    mov bx,word ptr [bp+6h]
    shl bx,1
    shl bx,1
    mov es, ds:[5B3Ch]
    mov ax,word ptr es:[bx+836h]
    jmp near ptr lbl3Ff
lbl2Af:
    mov ax,word ptr [bp+6h]
    shl ax,1
    shl ax,1
    mov bx,836h
    mov cx,38AFh
    add bx,ax
    mov es,cx
    mov ax,word ptr es:[bx+2h]
lbl3Ff:
    mov word ptr [bp-4h],ax
    call mf25
    cmp ax,word ptr [bp-4h]
    jg short lbl4Ff
    jmp near ptr lbl55f
lbl4Ff:
    mov ax,1h
    jmp near ptr lbl58f
lbl55f:
    mov ax,0h
lbl58f:
    jmp near ptr lbl5Bf
lbl5Bf:
    pop di
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
