_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi11:NEAR
    EXTRN mf6a:FAR
    EXTRN mf4f:FAR
    EXTRN mf7e:FAR
    EXTRN mf34:FAR
    EXTRN mf92:FAR
    EXTRN mf98:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,2h
    mov word ptr [bp-2h],1h
    mov ax,word ptr [bp+6h]
    sub ax,147h
    cmp ax, offset mi11
    ja short lbl34f
    add ax,ax
    xchg ax,bx
    jmp word ptr cs:[bx-1ADFh]
    db 61h, 0E5h, 67h, 0E5h, 6Dh, 0E5h, 37h, 0E5h, 77h, 0E5h, 37h, 0E5h, 7Dh, 0E5h, 37h, 0E5h
    db 89h, 0E5h, 8Fh, 0E5h, 95h, 0E5h
lbl34f:
    call mf34
    or ax,ax
    jz short lbl56f
    cmp word ptr [bp+6h],0FFh
    jnl short lbl56f
    mov bx,word ptr [bp+6h]
    test byte ptr [bx+56A5h],3h
    jz short lbl56f
    push bx
    call mf4f
    jmp short lbl9Df
lbl56f:
    mov word ptr [bp-2h],0h
    jmp short lbl9Df
    nop
    mov ax,0D8F1h
    jmp short lbl97f
    nop
    mov ax,0FFFFh
    jmp short lbl97f
    nop
    call mf6a
    neg ax
    jmp short lbl97f
    nop
    mov ax,0FFFFh
    jmp short lbl7Df
    nop
    mov ax,1h
lbl7Df:
    push ax
    call mf7e
    jmp short lbl9Df
    nop
    mov ax,270Fh
    jmp short lbl97f
    nop
    mov ax,1h
    jmp short lbl97f
    nop
    call mf92
lbl97f:
    push ax
    call mf98
lbl9Df:
    mov ax,word ptr [bp-2h]
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
