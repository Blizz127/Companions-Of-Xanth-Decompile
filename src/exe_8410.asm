_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf39:FAR
    EXTRN mf51:FAR
mnem_unit:
    push bp
    mov bp,sp
    push si
    push di
    mov si,word ptr [bp+4h]
    mov bx,5604h
    cmp si,542Ch
    jz short lbl23f
    mov bx,5608h
    cmp si,5438h
    jz short lbl23f
    mov bx,560Ch
    cmp si,5450h
    jnz short lbl7Bf
lbl23f:
    mov di,si
    sub di,5420h
    add di,5510h
    test byte ptr [si+0Ah],0Ch
    jnz short lbl7Bf
    test byte ptr [di],1h
    jnz short lbl7Bf
    mov ax,word ptr [bx]
    mov dx,word ptr [bx+2h]
    mov cx,ax
    or cx,dx
    jz short lbl64f
lbl43b:
    mov word ptr [si+6h],ax
    mov word ptr [si+8h],dx
    mov word ptr [si],ax
    mov word ptr [si+2h],dx
    mov word ptr [si+4h],200h
    mov word ptr [di+2h],200h
    or byte ptr [si+0Ah],2h
    mov byte ptr [di],11h
    mov ax,1h
    jmp short lbl7Df
lbl64f:
    push bx
    mov ax,200h
    push ax
    call mf39
    pop bx
    pop bx
    or dx,dx
    jz short lbl7Bf
    mov word ptr [bx],ax
    mov word ptr [bx+2h],dx
    jmp short lbl43b
lbl7Bf:
    xor ax,ax
lbl7Df:
    pop di
    pop si
    pop bp
    ret
_TEXT ENDS
    END
