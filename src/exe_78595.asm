_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi2:NEAR
    EXTRN mi6:NEAR
    EXTRN mi7:NEAR
    EXTRN mf18:FAR
    EXTRN mi24:NEAR
    EXTRN mi25:NEAR
    EXTRN mf43:FAR
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
    jmp near ptr lbl6Af
lbl17f:
    mov ax,86A0h
    mov dx,1h
    push dx
    push ax
    mov ax,word ptr [bp+8h]
    cwd
    push dx
    push ax
    call mf18
    mov word ptr ds:[417Ah],ax
    mov word ptr ds:[417Ch],dx
    mov ax,word ptr [bp+0Ah]
    mov word ptr ds:[4178h],ax
    mov ax,word ptr ds:[416Eh]
    and ax, offset mi24
    cmp ax, offset mi25
    jnz short lbl45f
    jmp near ptr lbl56f
lbl45f:
    mov ax,word ptr ds:[4182h]
    mov dx,word ptr ds:[4184h]
    mov word ptr ds:[417Eh],ax
    mov word ptr ds:[4180h],dx
    jmp near ptr lbl64f
lbl56f:
    mov ax,word ptr ds:[4182h]
    mov dx,word ptr ds:[4184h]
    mov word ptr ds:[417Eh],ax
    mov word ptr ds:[4180h],dx
lbl64f:
    mov ax,word ptr [bp+6h]
    mov word ptr ds:[4176h],ax
lbl6Af:
    pop di
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
