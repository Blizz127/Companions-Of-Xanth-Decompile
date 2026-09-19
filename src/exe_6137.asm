_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf43:FAR
    EXTRN mn8:NEAR
    EXTRN mjn59:NEAR
mnem_unit:
    push bp
    mov bp,sp
    push di
    push word ptr [bp+6h]
    push cs
    call mn8
    or ax,ax
    jz short lbl2Ff
    xchg ax,dx
    mov di,dx
    xor ax,ax
    mov cx,0FFFFh
    repne scasb
    not cx
    dec cx
    mov bx,2h
    cmp word ptr ds:[59FAh],0D6D6h
    jnz short lbl2Bf
    call word ptr ds:[59FCh]
lbl2Bf:
    mov ah,40h
    int 21h
lbl2Ff:
    pop di
    mov sp,bp
    pop bp
    retf 2h
    add byte ptr [bp+di+6h],dl
    push cx
    mov cx,400h
    xchg cx,word ptr ds:[5680h]
    push cx
    push ax
    call mf43
    pop bx
    pop word ptr ds:[5680h]
    pop cx
    mov bx,dx
    or bx,ax
    jz short lbl57f
    pop es
    pop bx
    ret
lbl57f:
    mov ax,cx
    jmp mjn59
    add byte ptr [bp+si+15h],dh
    xor ax,ax
    mov sp,bp
    pop bp
    retf
lblFB73f:
_TEXT ENDS
    END
