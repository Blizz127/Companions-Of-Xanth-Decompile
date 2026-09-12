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
    mov cl,byte ptr [bp+0Ah]
    mov byte ptr cs:[451h],0h
    mov ch,byte ptr es:[si+5h]
    mov bx,word ptr es:[si+7h]
    add si,20h
    call word ptr ds:[41FAh]
    pop es
    pop di
    pop si
    pop bp
    retf
_TEXT ENDS
    END
