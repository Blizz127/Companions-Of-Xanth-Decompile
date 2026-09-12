_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi2:NEAR
    EXTRN mi7:NEAR
    EXTRN mf26:FAR
    EXTRN mf32:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp, offset mi2
    push si
    push di
    mov al,byte ptr ds:[5E7Bh]
    cbw
    cmp ax, offset mi7
    jz short lbl15f
    jmp near ptr lbl1Ef
lbl15f:
    cmp word ptr [bp+6h],9h
    jnc short lbl1Ef
    jmp near ptr lbl27f
lbl1Ef:
    cmp word ptr [bp+6h],6h
    jna short lbl27f
    jmp near ptr lbl4Ef
lbl27f:
    cmp word ptr [bp+8h],3FFFh
    ja short lbl31f
    jmp near ptr lbl36f
lbl31f:
    mov word ptr [bp+8h],3FFFh
lbl36f:
    mov bx,word ptr [bp+6h]
    shl bx,1
    mov ax,word ptr [bp+8h]
    mov word ptr [bx+5E4Eh],ax
    mov ax,word ptr [bp+6h]
    push ax
    call mf26
    add sp,2h
lbl4Ef:
    pop di
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
