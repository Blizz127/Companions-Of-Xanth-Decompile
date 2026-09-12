_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf11:FAR
    EXTRN mf43:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,2h
    push ds
    push es
    push si
    push di
    mov ax,38AFh
    mov ds,ax
    mov ax,word ptr [bp+0Ah]
    push ax
    call mf11
    jnc short lbl20f
    mov ax,0FC19h
    cwd
    jmp short lbl4Cf
lbl20f:
    mov di,ax
    mov es,dx
    xor ax,ax
    mov al,byte ptr es:[di+17h]
    mov bx,word ptr [bp+8h]
    mul bx
    mov bx,8h
    div bx
    or dx,dx
    jz short lbl39f
    inc ax
lbl39f:
    test ax,1h
    jz short lbl3Ff
    inc ax
lbl3Ff:
    xor bx,bx
    mov bl,byte ptr es:[di+1Eh]
    mul bx
    mov bx,word ptr [bp+6h]
    mul bx
lbl4Cf:
    mov word ptr [bp-2h],ax
    mov ax,word ptr [bp-2h]
    pop di
    pop si
    pop es
    pop ds
    mov sp,bp
    pop bp
    retf 6h
_TEXT ENDS
    END
