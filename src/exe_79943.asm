_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi2:NEAR
    EXTRN md11:NEAR
    EXTRN md12:NEAR
    EXTRN mi15:NEAR
    EXTRN mf26:FAR
    EXTRN mi28:NEAR
    EXTRN mf39:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp, offset mi2
    push si
    push di
    mov word ptr [bp-4h],0h
    jmp near ptr lbl2Ef
lbl11b:
    mov bx,word ptr [bp-4h]
    shl bx,1
    shl bx,1
    mov es, ds:[5B44h]
    mov word ptr es:[bx+md11],0h
    mov word ptr es:[bx+md12],0h
    add word ptr [bp-4h],1h
lbl2Ef:
    mov ax,word ptr [bp-4h]
    cmp ax, offset mi15
    jnc short lbl39f
    jmp near ptr lbl11b
lbl39f:
    cmp word ptr [bp+6h],4h
    jz short lbl42f
    jmp near ptr lbl4Ef
lbl42f:
    mov ax,word ptr [bp+8h]
    mov word ptr ds:[421Fh],ax
    mov ax,word ptr [bp+0Ah]
    mov byte ptr ds:[4221h],al
lbl4Ef:
    push word ptr [bp+6h]
    call mf26
    add sp,2h
    cmp ax, offset mi28
    jz short lbl61f
    jmp near ptr lbl67f
lbl61f:
    mov ax,1h
    jmp near ptr lbl6Af
lbl67f:
    mov ax,0h
lbl6Af:
    jmp near ptr lbl6Df
lbl6Df:
    pop di
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
