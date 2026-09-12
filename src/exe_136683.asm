_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
mnem_unit:
    push bp
    mov bp,sp
    mov es,ax
    mov cx,word ptr es:[2Ch]
    jcxz lbl4Df
    mov es,cx
    xor di,di
lbl10b:
    mov al,byte ptr es:[di]
    or al,al
    jz short lbl4Df
    mov si,word ptr [bp+6h]
lbl1Ab:
    lodsb
    or al,al
    jnz short lbl27f
    cmp byte ptr es:[di],3Dh
    jz short lbl38f
    jmp short lbl2Ff
lbl27f:
    mov ah,byte ptr es:[di]
    inc di
    cmp al,ah
    jz short lbl1Ab
lbl2Ff:
    xor al,al
    mov cx,0FFFFh
    repne scasb
    jmp short lbl10b
lbl38f:
    mov ax,es
    mov ds,ax
    mov si,di
    inc si
    mov es, [bp+2h]
    mov di,word ptr [bp+8h]
lbl45b:
    lodsb
    stosb
    or al,al
    jnz short lbl45b
    jmp short lbl4Ef
lbl4Df:
    stc
lbl4Ef:
    pop bp
    pop es
    pop ds
    pop si
    pop di
    pop cx
    pop ax
    retf
_TEXT ENDS
    END
