_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi2:NEAR
    EXTRN mi7:NEAR
    EXTRN mi16:NEAR
    EXTRN mi25:NEAR
    EXTRN mf39:FAR
    EXTRN mf45:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp, offset mi2
    push si
    push di
    mov al,byte ptr ds:[5E78h]
    cbw
    cmp ax, offset mi7
    jnz short lbl15f
    jmp near ptr lbl1Bf
lbl15f:
    mov ax,80h
    jmp near ptr lbl1Ef
lbl1Bf:
    mov ax,0h
lbl1Ef:
    mov word ptr [bp-4h],ax
    mov al,byte ptr ds:[5E79h]
    cbw
    cmp ax, offset mi16
    jnz short lbl2Df
    jmp near ptr lbl33f
lbl2Df:
    mov ax,40h
    jmp near ptr lbl36f
lbl33f:
    mov ax,0h
lbl36f:
    or word ptr [bp-4h],ax
    mov al,byte ptr ds:[5E7Bh]
    cbw
    cmp ax, offset mi25
    jnz short lbl45f
    jmp near ptr lbl4Bf
lbl45f:
    mov ax,20h
    jmp near ptr lbl4Ef
lbl4Bf:
    mov ax,0h
lbl4Ef:
    or word ptr [bp-4h],ax
    mov al,byte ptr ds:[5E38h]
    cbw
    or word ptr [bp-4h],ax
    mov ax,word ptr [bp-4h]
    push ax
    mov ax,0BDh
    push ax
    call mf39
    add sp,4h
    pop di
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
