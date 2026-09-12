_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi2:NEAR
    EXTRN mi6:NEAR
    EXTRN mi7:NEAR
    EXTRN mf20:FAR
    EXTRN mf33:FAR
    EXTRN mf39:FAR
    EXTRN mf39:FAR
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
    jmp near ptr lbl3Bf
lbl17f:
    mov ax,3E8h
    mov dx,0h
    push dx
    push ax
    mov ax,word ptr ds:[4182h]
    mov dx,word ptr ds:[4184h]
    sub ax,word ptr ds:[6DEEh]
    sbb dx,word ptr ds:[6DF0h]
    push dx
    push ax
    call mf20
    jmp near ptr lbl5Cf
    jmp near ptr lbl5Cf
lbl3Bf:
    mov ax,3E8h
    mov dx,0h
    push dx
    push ax
    mov ax,word ptr ds:[4182h]
    mov dx,word ptr ds:[4184h]
    sub ax,word ptr ds:[6DEEh]
    sbb dx,word ptr ds:[6DF0h]
    push dx
    push ax
    call mf33
    jmp near ptr lbl5Cf
lbl5Cf:
    pop di
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
