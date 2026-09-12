_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
mnem_unit:
    push bp
    mov bp,sp
    sub sp,0Eh
    push di
    push si
    mov ax,word ptr [bp+6h]
    mov dx,word ptr [bp+8h]
    push ds
    lea di,word ptr [bp-0Ch]
    mov si,ax
    push ss
    pop es
    mov ds,dx
    movsw
    movsw
    movsw
    movsw
    movsb
    pop ds
    mov word ptr [bp-2h],0h
    lea ax,word ptr [bp-0Ch]
    mov word ptr [bp-0Eh],ax
    mov es, [bp+8h]
lbl2Cb:
    mov bx,word ptr [bp+6h]
    sub bx,word ptr [bp-2h]
    mov al,byte ptr es:[bx+4h]
    mov bx,word ptr [bp-0Eh]
    inc word ptr [bp-0Eh]
    mov byte ptr [bx],al
    inc word ptr [bp-2h]
    lea ax,word ptr [bp-7h]
    cmp word ptr [bp-0Eh],ax
    jc short lbl2Cb
    lea si,word ptr [bp-0Ch]
    les di, dword ptr [bp+6h]
    movsw
    movsw
    movsw
    movsw
    movsb
    pop si
    pop di
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
