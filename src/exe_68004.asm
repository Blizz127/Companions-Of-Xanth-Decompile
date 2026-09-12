_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi2:NEAR
    EXTRN mf18:FAR
    EXTRN mf19:FAR
    EXTRN mf28:FAR
    EXTRN mf28:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp, offset mi2
    push si
    push di
    mov byte ptr ds:[6288h],0h
    mov ax,word ptr [bp+6h]
    mov dx,word ptr [bp+8h]
    mov word ptr ds:[6DE6h],ax
    mov word ptr ds:[6DE8h],dx
    cmp word ptr ds:[6DE6h],0h
    jz short lbl25f
    jmp near ptr lbl35f
lbl25f:
    cmp word ptr ds:[6DE8h],0h
    jz short lbl2Ff
    jmp near ptr lbl35f
lbl2Ff:
    mov ax,0h
    jmp near ptr lbl4Ff
lbl35f:
    call mf18
    call mf19
    or word ptr ds:[416Eh],40h
    and word ptr ds:[416Eh],0FFFFFFFFFFFFFFDFh
    mov ax,1h
    jmp near ptr lbl4Ff
lbl4Ff:
    pop di
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
