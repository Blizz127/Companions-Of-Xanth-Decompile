_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mn25:NEAR
    EXTRN mn28:NEAR
    EXTRN mn34:NEAR
    EXTRN mn37:NEAR
    EXTRN mf38:FAR
    EXTRN mn48:NEAR
    EXTRN mn58:NEAR
    EXTRN mn58:NEAR
    EXTRN mn58:NEAR
    EXTRN mn58:NEAR
    EXTRN mf58:FAR
    EXTRN mn58:NEAR
mnem_unit:
    push bp
    mov bp,sp
    xor cx,cx
    jmp short lbl21f
    push bp
    mov bp,sp
    mov cx,1h
    jmp short lbl21f
    push bp
    mov bp,sp
    push si
    push di
    mov cx,100h
    jmp short lbl21f
    push bp
    mov bp,sp
    push si
    push di
    mov cx,101h
lbl21f:
    mov byte ptr ds:[53F7h],ch
    push cx
    or cl,cl
    jnz short lbl48f
    mov si,69DEh
    mov di,69DEh
    call mn25
    mov si,5A18h
    mov di,5A1Ch
    call mn28
    cmp word ptr ds:[59FAh],0D6D6h
    jnz short lbl48f
    call word ptr ds:[5A00h]
lbl48f:
    mov si,5A1Ch
    mov di,5A1Ch
    call mn34
    mov si,5A1Ch
    mov di,5A1Ch
    call mn37
    call mf38
    or ax,ax
    jz short lbl74f
    pop ax
    or ah,ah
    push ax
    jnz short lbl74f
    cmp word ptr [bp+6h],0h
    jnz short lbl74f
    mov word ptr [bp+6h],0FFh
lbl74f:
    call mn48
    pop ax
    or ah,ah
    jnz short lbl83f
    mov ax,word ptr [bp+6h]
    mov ah,4Ch
    int 21h
lbl83f:
    pop di
    pop si
    pop bp
    retf
_TEXT ENDS
    END
