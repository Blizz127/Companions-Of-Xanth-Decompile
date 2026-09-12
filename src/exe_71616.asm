_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi2:NEAR
    EXTRN mf8:FAR
    EXTRN md14:NEAR
    EXTRN md15:NEAR
    EXTRN md36:NEAR
    EXTRN md37:NEAR
    EXTRN md42:NEAR
    EXTRN md43:NEAR
    EXTRN mf53:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp, offset mi2
    push si
    push di
    mov word ptr [bp-4h],0h
    jmp near ptr lbl35f
lbl11b:
    push word ptr [bp-4h]
    call mf8
    add sp,2h
    mov bx,word ptr [bp-4h]
    shl bx,1
    shl bx,1
    mov es, ds:[5B3Ah]
    mov word ptr es:[bx+md14],ax
    mov word ptr es:[bx+md15],dx
    add word ptr [bp-4h],1h
lbl35f:
    mov ax,word ptr ds:[62AAh]
    cmp word ptr [bp-4h],ax
    jnl short lbl40f
    jmp near ptr lbl11b
lbl40f:
    cmp word ptr ds:[416Ah],0h
    jnz short lbl4Af
    jmp near ptr lbl9Df
lbl4Af:
    mov word ptr [bp-4h],0h
    jmp near ptr lbl92f
lbl52b:
    mov bx,word ptr [bp-4h]
    shl bx,1
    mov ax,word ptr [bx+62BAh]
    mov bx,word ptr [bp-4h]
    shl bx,1
    mov word ptr [bx+628Ah],ax
    mov bx,word ptr [bp-4h]
    shl bx,1
    shl bx,1
    mov es, ds:[5B3Ah]
    mov ax,word ptr es:[bx+md36]
    mov dx,word ptr es:[bx+md37]
    mov bx,word ptr [bp-4h]
    shl bx,1
    shl bx,1
    mov es, ds:[5B3Ah]
    mov word ptr es:[bx+md42],ax
    mov word ptr es:[bx+md43],dx
    add word ptr [bp-4h],1h
lbl92f:
    mov ax,word ptr ds:[62AAh]
    cmp word ptr [bp-4h],ax
    jnl short lbl9Df
    jmp near ptr lbl52b
lbl9Df:
    pop di
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
