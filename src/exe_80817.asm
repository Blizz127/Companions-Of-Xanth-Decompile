_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi2:NEAR
    EXTRN mi6:NEAR
    EXTRN mi7:NEAR
    EXTRN mi11:NEAR
    EXTRN mi12:NEAR
    EXTRN md26:NEAR
    EXTRN md29:NEAR
    EXTRN mi34:NEAR
    EXTRN mi39:NEAR
    EXTRN mf42:FAR
    EXTRN mi43:NEAR
    EXTRN md53:NEAR
    EXTRN md54:NEAR
    EXTRN mf55:FAR
    EXTRN mi59:NEAR
    EXTRN mi64:NEAR
    EXTRN mf67:FAR
    EXTRN mi68:NEAR
    EXTRN mf77:FAR
    EXTRN mf77:FAR
    EXTRN mf77:FAR
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
    jmp near ptr lbl2Ff
lbl17f:
    mov ax,word ptr ds:[416Eh]
    and ax, offset mi11
    cmp ax, offset mi12
    jnz short lbl25f
    jmp near ptr lbl32f
lbl25f:
    cmp word ptr ds:[4196h],4h
    jnz short lbl2Ff
    jmp near ptr lbl32f
lbl2Ff:
    jmp near ptr lblDBf
lbl32f:
    mov word ptr [bp-4h],0h
    jmp near ptr lbl3Ef
lbl3Ab:
    add word ptr [bp-4h],1h
lbl3Ef:
    mov bx,word ptr [bp-4h]
    shl bx,1
    shl bx,1
    mov es, ds:[5B44h]
    cmp word ptr es:[bx+md26],0h
    jz short lbl54f
    jmp near ptr lbl5Ff
lbl54f:
    cmp word ptr es:[bx+md29],0h
    jnz short lbl5Ff
    jmp near ptr lblDBf
lbl5Ff:
    mov al,byte ptr ds:[41F5h]
    and ax,0FFh
    cmp ax, offset mi34
    jnz short lbl6Df
    jmp near ptr lbl7Bf
lbl6Df:
    mov al,byte ptr ds:[41F5h]
    and ax,0FFh
    cmp ax, offset mi39
    jz short lbl7Bf
    jmp near ptr lbl8Bf
lbl7Bf:
    call mf42
    cmp ax, offset mi43
    jnz short lbl88f
    jmp near ptr lbl8Bf
lbl88f:
    jmp near ptr lblDBf
lbl8Bf:
    mov ax,0h
    push ax
    mov bx,word ptr [bp-4h]
    shl bx,1
    shl bx,1
    mov es, ds:[5B44h]
    push word ptr es:[bx+md53]
    push word ptr es:[bx+md54]
    call mf55
    add sp,6h
    mov al,byte ptr ds:[41F5h]
    and ax,0FFh
    cmp ax, offset mi59
    jnz short lblBAf
    jmp near ptr lblC8f
lblBAf:
    mov al,byte ptr ds:[41F5h]
    and ax,0FFh
    cmp ax, offset mi64
    jz short lblC8f
    jmp near ptr lblD8f
lblC8b:
lblC8f:
    call mf67
    cmp ax, offset mi68
    jnz short lblD5f
    jmp near ptr lblD8f
lblD5f:
    jmp near ptr lblC8b
lblD8f:
    jmp near ptr lbl3Ab
lblDBf:
    pop di
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
