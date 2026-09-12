_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
mnem_unit:
    push bp
    mov bp,sp
    sub sp,4h
    push si
    mov si,5420h
    sub ax,ax
    mov word ptr [bp-2h],ax
    mov word ptr [bp-4h],ax
    jmp short lbl17f
lbl14b:
    add si,0Ch
lbl17f:
    cmp word ptr ds:[5600h],si
    jc short lbl43f
    test byte ptr [si+0Ah],83h
    jnz short lbl14b
    mov byte ptr [si+0Ah],0h
    mov word ptr [si+4h],0h
    sub ax,ax
    mov word ptr [si+8h],ax
    mov word ptr [si+6h],ax
    mov word ptr [si+2h],ax
    mov word ptr [si],ax
    mov byte ptr [si+0Bh],0FFh
    mov word ptr [bp-4h],si
    mov word ptr [bp-2h],ds
lbl43f:
    mov ax,word ptr [bp-4h]
    mov dx,word ptr [bp-2h]
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
