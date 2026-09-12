_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi2:NEAR
    EXTRN mi7:NEAR
    EXTRN mf10:FAR
    EXTRN mi22:NEAR
    EXTRN mf28:FAR
    EXTRN mf54:FAR
    EXTRN mf54:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp, offset mi2
    push si
    push di
    mov al,byte ptr ds:[627Eh]
    and ax,0FFh
    cmp ax, offset mi7
    jnz short lbl17f
    jmp near ptr lbl33f
lbl17f:
    call mf10
    mov word ptr [bp-6h],ax
    mov word ptr [bp-4h],dx
    mov ax,word ptr [bp-6h]
    mov dx,word ptr [bp-4h]
    add word ptr ds:[6280h],ax
    adc word ptr ds:[6282h],dx
    jmp near ptr lbl3Ff
lbl33f:
    mov word ptr ds:[6280h],0FFFFh
    mov word ptr ds:[6282h],7FFFh
lbl3Ff:
    mov al,byte ptr ds:[627Eh]
    and ax,0FFh
    cmp ax, offset mi22
    jz short lbl4Df
    jmp near ptr lbl7Af
lbl4Df:
    cmp word ptr ds:[416Ah],0h
    jnz short lbl57f
    jmp near ptr lbl65f
lbl57f:
    call mf28
    mov ax,0h
    jmp near ptr lblA6f
    jmp near ptr lbl7Af
lbl65f:
    mov byte ptr ds:[6284h],1h
    mov byte ptr ds:[6288h],0h
    and word ptr ds:[416Eh],0FFFFFFFFFFFFFFBFh
    mov ax,0h
    jmp near ptr lblA6f
lbl7Af:
    mov ax,word ptr ds:[6280h]
    mov dx,word ptr ds:[6282h]
    sub ax,word ptr ds:[40F4h]
    sbb dx,word ptr ds:[40F6h]
    mov word ptr [bp-6h],ax
    mov word ptr [bp-4h],dx
    mov ax,word ptr ds:[6280h]
    mov dx,word ptr ds:[6282h]
    mov word ptr ds:[40F4h],ax
    mov word ptr ds:[40F6h],dx
    mov ax,word ptr [bp-6h]
    mov dx,word ptr [bp-4h]
    jmp near ptr lblA6f
lblA6f:
    pop di
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
