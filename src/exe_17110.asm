_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
mnem_unit:
    push bp
    mov bp,sp
    push di
    les di, dword ptr [bp+6h]
    mov bx,di
    xor ax,ax
    mov cx,0FFFFh
    repne scasb
    not cx
    mov al,byte ptr [bp+0Ah]
    mov di,bx
    repne scasb
    jz short lbl28f
    or al,al
    jnz short lbl22f
    inc di
    jmp short lbl28f
lbl22f:
    xor ax,ax
    xor dx,dx
    jmp short lbl2Df
lbl28f:
    lea ax,word ptr [di-1h]
    mov dx,es
lbl2Df:
    pop di
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
