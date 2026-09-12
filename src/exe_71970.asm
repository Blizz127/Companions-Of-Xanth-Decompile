_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi2:NEAR
    EXTRN mf9:FAR
    EXTRN mf18:FAR
    EXTRN mf25:FAR
    EXTRN mf34:FAR
    EXTRN mf41:FAR
    EXTRN mf57:FAR
    EXTRN mf60:FAR
    EXTRN mf67:FAR
    EXTRN mi69:NEAR
    EXTRN mf75:FAR
    EXTRN mf81:FAR
    EXTRN mf85:FAR
    EXTRN mf90:FAR
    EXTRN mf96:FAR
    EXTRN mf105:FAR
    EXTRN mf105:FAR
    EXTRN mf105:FAR
    EXTRN mf105:FAR
    EXTRN mf105:FAR
    EXTRN mf105:FAR
    EXTRN mf105:FAR
    EXTRN mf105:FAR
    EXTRN mf105:FAR
    EXTRN mf105:FAR
    EXTRN mf105:FAR
    EXTRN mf105:FAR
    EXTRN mf105:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp, offset mi2
    push si
    push di
    mov ax,2h
    push ax
    mov ax,word ptr [bp+6h]
    push ax
    call mf9
    add sp,4h
    and ax,0FFh
    mov dx,0h
    mov word ptr ds:[62B2h],ax
    mov word ptr ds:[62B4h],dx
    mov cx,8h
    mov ax,word ptr ds:[62B2h]
    mov dx,word ptr ds:[62B4h]
    call mf18
    mov word ptr ds:[62B2h],ax
    mov word ptr ds:[62B4h],dx
    mov ax,3h
    push ax
    mov ax,word ptr [bp+6h]
    push ax
    call mf25
    add sp,4h
    and ax,0FFh
    cwd
    or word ptr ds:[62B2h],ax
    or word ptr ds:[62B4h],dx
    mov cx,8h
    mov ax,word ptr ds:[62B2h]
    mov dx,word ptr ds:[62B4h]
    call mf34
    mov word ptr ds:[62B2h],ax
    mov word ptr ds:[62B4h],dx
    mov ax,4h
    push ax
    mov ax,word ptr [bp+6h]
    push ax
    call mf41
    add sp,4h
    and ax,0FFh
    cwd
    or word ptr ds:[62B2h],ax
    or word ptr ds:[62B4h],dx
    push word ptr ds:[62B4h]
    push word ptr ds:[62B2h]
    mov ax,0A120h
    mov dx,7h
    push dx
    push ax
    mov ax,word ptr ds:[62ACh]
    cwd
    push dx
    push ax
    call mf57
    push dx
    push ax
    call mf60
    mov word ptr ds:[62B6h],ax
    cmp word ptr ds:[4120h],0h
    jz short lblB9f
    jmp near ptr lblDFf
lblB9f:
    mov ax,0E0h
    push ax
    call mf67
    add sp,2h
    cmp ax, offset mi69
    jnz short lblCDf
    jmp near ptr lblDFf
lblCDf:
    mov ax,word ptr ds:[62B6h]
    and ax,0FFh
    push ax
    call mf75
    add sp,2h
    jmp near ptr lbl10Cf
lblDFf:
    mov word ptr ds:[4120h],1h
    mov ax,0F8h
    push ax
    call mf81
    add sp,2h
    mov ax,0E0h
    push ax
    call mf85
    add sp,2h
    mov ax,word ptr ds:[62B6h]
    and ax,0FFh
    push ax
    call mf90
    add sp,2h
lbl10Cf:
    mov bx,word ptr [bp+6h]
    shl bx,1
    add word ptr [bx+62BAh],1h
    push word ptr [bp+6h]
    call mf96
    add sp,2h
    mov bx,word ptr [bp+6h]
    shl bx,1
    add word ptr [bx+62BAh],ax
    pop di
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
