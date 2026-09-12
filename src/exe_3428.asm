_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
mnem_unit:
    push bp
    mov bp,sp
    push si
    push di
    push es
    les si, dword ptr [bp+6h]
    cmp byte ptr ds:[41FEh],0h
    jz short lbl26f
    cld
    mov di,si
    add di,20h
lbl16b:
    mov al,byte ptr es:[di]
    or al,al
    jz short lbl26f
    shr al,1
    jnz short lbl23f
    inc al
lbl23f:
    stosb
    jmp short lbl16b
lbl26f:
    pop es
    pop di
    pop si
    pop bp
    retf
_TEXT ENDS
    END
