_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
mnem_unit:
    db 81h
    push bp
    push di
    push si
    mov es, ds:[44A2h]
    mov si,cx
    mov di,dx
    mov dx,bx
    mov bx,ax
    dec bx
lbl11b:
    add bx,dx
    mov cl,byte ptr es:[bx]
    sub bx,dx
    mov ax,1h
    shl ax,cl
    mov bp,word ptr cs:[bx+si]
    and bp,0FFh
lbl24b:
    mov byte ptr es:[bp+di],bl
    add bp,ax
    cmp bp,0FFh
    jna short lbl24b
    dec bx
    jnl short lbl11b
    pop si
    pop di
    pop bp
    ret
_TEXT ENDS
    END
