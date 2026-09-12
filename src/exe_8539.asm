_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mn16:NEAR
    EXTRN mn30:NEAR
mnem_unit:
    push bp
    mov bp,sp
    push si
    push di
    mov si,word ptr [bp+6h]
    mov di,si
    sub di,5420h
    add di,5510h
    test byte ptr [di],10h
    jz short lbl43f
    xor bx,bx
    mov bl,byte ptr [si+0Bh]
    test byte ptr [bx+53CCh],40h
    jz short lbl43f
    push ds
    push si
    call mn16
    add sp,4h
    cmp word ptr [bp+4h],0h
    jz short lbl43f
    xor ax,ax
    mov byte ptr [di],al
    mov word ptr [di+2h],ax
    mov word ptr [si],ax
    mov word ptr [si+2h],ax
    mov word ptr [si+6h],ax
    mov word ptr [si+8h],ax
lbl43f:
    pop di
    pop si
    pop bp
    ret
_TEXT ENDS
    END
