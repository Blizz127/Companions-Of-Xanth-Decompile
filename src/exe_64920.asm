_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi2:NEAR
    EXTRN mf12:FAR
    EXTRN mf18:FAR
    EXTRN mf30:FAR
    EXTRN mf31:FAR
    EXTRN mf36:FAR
    EXTRN mf36:FAR
    EXTRN mf36:FAR
    EXTRN mf36:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp, offset mi2
    push si
    push di
    cmp word ptr [bp+6h],0h
    jnz short lbl12f
    jmp near ptr lbl40f
lbl12f:
    mov byte ptr ds:[5E42h],18h
    mov word ptr ds:[5E5Eh],2000h
    mov ax,8h
    push ax
    call mf12
    add sp,2h
    mov byte ptr ds:[5E41h],1Fh
    mov word ptr ds:[5E5Ch],2000h
    mov ax,7h
    push ax
    call mf18
    add sp,2h
lbl40f:
    mov ax,word ptr [bp+6h]
    mov byte ptr ds:[5E7Bh],al
    cmp word ptr [bp+6h],0h
    jnz short lbl4Ff
    jmp near ptr lbl55f
lbl4Ff:
    mov ax,0Bh
    jmp near ptr lbl58f
lbl55f:
    mov ax,9h
lbl58f:
    mov word ptr ds:[5E76h],ax
    mov byte ptr ds:[5E38h],0h
    call mf30
    call mf31
    pop di
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
