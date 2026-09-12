_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
mnem_unit:
    push bp
    mov bp,sp
    push si
    push di
    push ds
    pop es
    mov dx,word ptr [bp+6h]
    mov si,5B58h
lbl0Db:
    lodsw
    cmp ax,dx
    jz short lbl22f
    inc ax
    xchg ax,si
    jz short lbl22f
    xchg ax,di
    xor ax,ax
    mov cx,0FFFFh
    repne scasb
    mov si,di
    jmp short lbl0Db
lbl22f:
    xchg ax,si
    pop di
    pop si
    mov sp,bp
    pop bp
    retf 2h
_TEXT ENDS
    END
