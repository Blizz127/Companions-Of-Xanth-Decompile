_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi2:NEAR
    EXTRN mi7:NEAR
    EXTRN mf27:FAR
    EXTRN mi32:NEAR
    EXTRN mf44:FAR
    EXTRN mf49:FAR
    EXTRN mf49:FAR
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
    jc short lbl27f
    jmp near ptr lbl52f
lbl27f:
    mov bx,word ptr [bp+6h]
    mov byte ptr [bx+5E44h],0h
    mov bx,word ptr [bp+6h]
    and byte ptr [bx+5E60h],0DFh
    mov bx,word ptr [bp+6h]
    mov al,byte ptr [bx+5E60h]
    cbw
    push ax
    mov ax,word ptr [bp+6h]
    add ax,0B0h
    push ax
    call mf27
    add sp,4h
    jmp near ptr lbl7Df
lbl52f:
    mov al,byte ptr ds:[5E7Bh]
    cbw
    cmp ax, offset mi32
    jnz short lbl5Ef
    jmp near ptr lbl7Df
lbl5Ef:
    cmp word ptr [bp+6h],0Ah
    jna short lbl67f
    jmp near ptr lbl7Df
lbl67f:
    mov bx,word ptr [bp+6h]
    add bx,0FFFFFFFFFFFFFFFAh
    mov al,byte ptr [bx+3FF0h]
    cbw
    not ax
    and byte ptr ds:[5E38h],al
    call mf44
lbl7Df:
    pop di
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
