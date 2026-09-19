_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
mnem_unit:
    not word ptr [di+57h]
    push si
    push ds
    lds si, dword ptr ds:[44A0h]
    mov dx,0FFh
    mov bx,dx
lbl0Eb:
    shl bx,1
    mov di,word ptr cs:[bx+261h]
    shr bx,1
    xor cl,cl
    mov bp,2C1Eh
    mov al,byte ptr [bx+si+2F9Eh]
    cmp al,8h
    jna short lbl4Cf
    db 85h, 0FAh ; override
    jz short lbl47f
    mov bp,di
    and bp,dx
    mov byte ptr ds:[bp+si+2C1Eh],dl
    mov cl,4h
    mov bp,2D1Eh
    test di,3Fh
    jnz short lbl4Cf
    mov cl,6h
    mov bp,2E1Eh
    mov dx,7Fh
    jmp short lbl4Cf
    db 0F7h
lbl47f:
    mov cl,8h
    mov bp,2E9Eh
lbl4Cf:
    shr di,cl
    sub al,cl
    mov byte ptr [bx+si+2F9Eh],al
    xchg ax,cx
    mov ax,1h
    shl ax,cl
    add bp,si
lbl5Cb:
    mov byte ptr ds:[bp+di],bl
    add di,ax
    cmp di,dx
    jna short lbl5Cb
    mov dx,0FFh
    dec bx
    jnl short lbl0Eb
    pop ds
    pop si
    pop di
    pop bp
    ret
_TEXT ENDS
    END
