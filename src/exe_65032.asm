_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi2:NEAR
    EXTRN mf22:FAR
    EXTRN mf31:FAR
    EXTRN mf37:FAR
    EXTRN mf37:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp, offset mi2
    push si
    push di
    cmp word ptr [bp+6h],0h
    jnz short lbl12f
    jmp near ptr lbl18f
lbl12f:
    mov ax,20h
    jmp near ptr lbl1Bf
lbl18f:
    mov ax,0h
lbl1Bf:
    mov word ptr ds:[5E36h],ax
    mov word ptr [bp-4h],0h
    jmp near ptr lbl47f
lbl26b:
    mov ax,0h
    push ax
    mov bx,word ptr [bp-4h]
    mov es, ds:[5B36h]
    mov al,byte ptr es:[bx+194h]
    cbw
    add ax,0E0h
    push ax
    call mf22
    add sp,4h
    add word ptr [bp-4h],1h
lbl47f:
    cmp word ptr [bp-4h],12h
    jnl short lbl50f
    jmp near ptr lbl26b
lbl50f:
    push word ptr ds:[5E36h]
    mov ax,1h
    push ax
    call mf31
    add sp,4h
    pop di
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
