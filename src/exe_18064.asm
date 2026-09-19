_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mjna:NEAR
mnem_unit:
    push bp
    mov bp,sp
    mov bx,word ptr [bp+6h]
    mov ah,68h
    int 21h
    jmp mjna
    add byte ptr [di-75h],dl
    in al,dx
    mov ax,word ptr [bp+6h]
    mov ah,35h
    int 21h
    mov dx,es
    mov ax,bx
    mov sp,bp
    pop bp
    retf
lblD1CEf:
_TEXT ENDS
    END
