_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi2:NEAR
    EXTRN mf9:FAR
    EXTRN mi18:NEAR
    EXTRN mf38:FAR
    EXTRN mf41:FAR
    EXTRN mf53:FAR
    EXTRN mf60:FAR
    EXTRN mf72:FAR
    EXTRN mi75:NEAR
    EXTRN mf82:FAR
    EXTRN mf86:FAR
    EXTRN mf92:FAR
    EXTRN mf111:FAR
    EXTRN mf132:FAR
    EXTRN mf141:FAR
    EXTRN mf151:FAR
    EXTRN mf164:FAR
    EXTRN mi167:NEAR
    EXTRN mf174:FAR
    EXTRN mf196:FAR
    EXTRN mf215:FAR
    EXTRN mf224:FAR
    EXTRN mf232:FAR
    EXTRN mf232:FAR
    EXTRN mf232:FAR
    EXTRN mf232:FAR
    EXTRN mf232:FAR
    EXTRN mf232:FAR
    EXTRN mf232:FAR
    EXTRN mf232:FAR
    EXTRN mf232:FAR
    EXTRN mf232:FAR
    EXTRN mf232:FAR
    EXTRN mf232:FAR
    EXTRN mf232:FAR
    EXTRN mf232:FAR
    EXTRN mf232:FAR
    EXTRN mf232:FAR
    EXTRN mf232:FAR
    EXTRN mf232:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp, offset mi2
    push si
    push di
    mov ax,0h
    push ax
    mov ax,word ptr [bp+6h]
    push ax
    call mf9
    add sp,4h
    mov byte ptr ds:[62B8h],al
    mov bx,word ptr [bp+6h]
    shl bx,1
    add word ptr [bx+62BAh],1h
    mov al,byte ptr ds:[62B8h]
    and ax,0FFh
    and ax,80h
    cmp ax, offset mi18
    jnz short lbl37f
    jmp near ptr lbl1A0f
lbl37f:
    mov al,byte ptr ds:[62B8h]
    and ax,0FFh
    mov bx,word ptr [bp+6h]
    shl bx,1
    mov word ptr [bx+629Ah],ax
    mov al,byte ptr ds:[62B8h]
    and ax,0FFh
    cmp ax,0F0h
    jnz short lbl54f
    jmp near ptr lbl62f
lbl54f:
    mov al,byte ptr ds:[62B8h]
    and ax,0FFh
    cmp ax,0F7h
    jz short lbl62f
    jmp near ptr lbl85f
lbl62f:
    mov ax,0F8h
    push ax
    call mf38
    add sp,2h
    push word ptr [bp+6h]
    call mf41
    add sp,2h
    mov bx,word ptr [bp+6h]
    shl bx,1
    add word ptr [bx+62BAh],ax
    jmp near ptr lbl19Df
lbl85f:
    mov al,byte ptr ds:[62B8h]
    and ax,0FFh
    cmp ax,0FFh
    jz short lbl93f
    jmp near ptr lblA4f
lbl93f:
    push word ptr [bp+6h]
    call mf53
    add sp,2h
    jmp near ptr lbl27Ff
    jmp near ptr lbl19Df
lblA4f:
    mov al,byte ptr ds:[62B8h]
    and ax,0FFh
    push ax
    call mf60
    add sp,2h
    mov al,byte ptr ds:[62B8h]
    and ax,0FFh
    and ax,0F0h
    cmp ax,90h
    jz short lblC4f
    jmp near ptr lbl14Af
lblC4f:
    mov ax,1h
    push ax
    mov ax,word ptr [bp+6h]
    push ax
    call mf72
    add sp,4h
    and ax,0FFh
    cmp ax, offset mi75
    jg short lblDFf
    jmp near ptr lbl14Af
lblDFf:
    mov ax,0h
    push ax
    mov ax,word ptr [bp+6h]
    push ax
    call mf82
    add sp,4h
    and ax,0FFh
    push ax
    call mf86
    add sp,2h
    mov ax,1h
    push ax
    mov ax,word ptr [bp+6h]
    push ax
    call mf92
    add sp,4h
    and ax,0FFh
    mov word ptr [bp-6h],ax
    mov ax,word ptr ds:[4168h]
    imul word ptr ds:[27Eh]
    mov cx,7Fh
    cwd
    idiv cx
    mov cx,ax
    mov ax,word ptr [bp-6h]
    imul cx
    mov cx,7Fh
    cwd
    idiv cx
    mov byte ptr ds:[62B9h],al
    mov al,byte ptr ds:[62B9h]
    and ax,0FFh
    push ax
    call mf111
    add sp,2h
    mov bx,word ptr [bp+6h]
    shl bx,1
    add word ptr [bx+62BAh],2h
    jmp near ptr lbl19Df
lbl14Af:
    mov al,byte ptr ds:[62B8h]
    and ax,0FFh
    mov bx,ax
    and bx,70h
    sar bx,1
    sar bx,1
    sar bx,1
    sar bx,1
    shl bx,1
    mov si,word ptr [bx+410Ch]
    jmp near ptr lbl195f
lbl166b:
    mov ax,0h
    push ax
    mov ax,word ptr [bp+6h]
    push ax
    call mf132
    add sp,4h
    mov byte ptr ds:[62B8h],al
    mov bx,word ptr [bp+6h]
    shl bx,1
    add word ptr [bx+62BAh],1h
    mov al,byte ptr ds:[62B8h]
    and ax,0FFh
    push ax
    call mf141
    add sp,2h
    sub si,1h
lbl195f:
    cmp si,0h
    jng short lbl19Df
    jmp near ptr lbl166b
lbl19Df:
    jmp near ptr lbl279f
lbl1A0f:
    mov al,byte ptr ds:[62B8h]
    and ax,0FFh
    push ax
    call mf151
    add sp,2h
    mov bx,word ptr [bp+6h]
    shl bx,1
    mov ax,word ptr [bx+629Ah]
    and ax,0F0h
    cmp ax,90h
    jz short lbl1C3f
    jmp near ptr lbl22Df
lbl1C3f:
    mov ax,0h
    push ax
    mov ax,word ptr [bp+6h]
    push ax
    call mf164
    add sp,4h
    and ax,0FFh
    cmp ax, offset mi167
    jg short lbl1DEf
    jmp near ptr lbl22Df
lbl1DEf:
    mov ax,0h
    push ax
    mov ax,word ptr [bp+6h]
    push ax
    call mf174
    add sp,4h
    and ax,0FFh
    mov word ptr [bp-4h],ax
    mov ax,word ptr ds:[4168h]
    imul word ptr ds:[27Eh]
    mov cx,7Fh
    cwd
    idiv cx
    mov cx,ax
    mov ax,word ptr [bp-4h]
    imul cx
    mov cx,7Fh
    cwd
    idiv cx
    mov byte ptr ds:[62B9h],al
    mov bx,word ptr [bp+6h]
    shl bx,1
    add word ptr [bx+62BAh],1h
    mov al,byte ptr ds:[62B9h]
    and ax,0FFh
    push ax
    call mf196
    add sp,2h
    jmp near ptr lbl279f
lbl22Df:
    mov bx,word ptr [bp+6h]
    shl bx,1
    mov bx,word ptr [bx+629Ah]
    and bx,70h
    sar bx,1
    sar bx,1
    sar bx,1
    sar bx,1
    shl bx,1
    cmp word ptr [bx+410Ch],2h
    jz short lbl24Df
    jmp near ptr lbl279f
lbl24Df:
    mov ax,0h
    push ax
    mov ax,word ptr [bp+6h]
    push ax
    call mf215
    add sp,4h
    mov byte ptr ds:[62B8h],al
    mov bx,word ptr [bp+6h]
    shl bx,1
    add word ptr [bx+62BAh],1h
    mov al,byte ptr ds:[62B8h]
    and ax,0FFh
    push ax
    call mf224
    add sp,2h
lbl279f:
    mov ax,1h
    jmp near ptr lbl27Ff
lbl27Ff:
    pop di
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
