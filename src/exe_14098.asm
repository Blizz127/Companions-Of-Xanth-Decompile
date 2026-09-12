_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
mnem_unit:
    push bp
    mov bp,sp
    mov dx,di
    les di, dword ptr [bp+6h]
    xor ax,ax
    mov cx,0FFFFh
    repne scasb
    not cx
    jnz short lbl14f
    dec cx
lbl14f:
    xchg ax,cx
    mov di,dx
    pop bp
    retf
_TEXT ENDS
    END
