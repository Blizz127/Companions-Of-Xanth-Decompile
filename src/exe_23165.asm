_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
mnem_unit:
    push bp
    mov bp,sp
    sub sp,4h
    push ax
    push bx
    push di
    push si
    cld
    mov si,word ptr ds:[449Ch]
    mov word ptr [bp-2h],si
    sub ax,ax
    mov es, ds:[449Eh]
    mov cx,900h
    lea di,word ptr [si+9A8h]
    rep stosw
    lea di,word ptr [si+9A8h]
    mov dx,word ptr [bp-6h]
    mov si,word ptr [bp-8h]
    sub dx,si
    mov cl,3h
    sub ah,ah
    push ds
    push es
    pop ds
    nop
lbl35b:
    lodsb
    mov bl,byte ptr [si]
    sub bh,bh
    xchg ax,bx
    shl bx,cl
    add bx,ax
    shl bx,1
    add word ptr [bx+di],2h
    dec dx
    jnz short lbl35b
    mov si,word ptr [bp-2h]
    lea ax,word ptr [si+45B0h]
    mov cx,480h
    lea di,word ptr [si+9A8h]
lbl55b:
    add ax,word ptr [di]
    stosw
    add ax,word ptr [di]
    stosw
    loop lbl55b
    lea di,word ptr [si+9A8h]
    mov dx,word ptr [bp-6h]
    mov si,dx
    sub dx,word ptr [bp-8h]
    mov cl,3h
    sub ah,ah
    std
    nop
lbl6Fb:
    lodsb
    mov bl,byte ptr [si]
    sub bh,bh
    shl bx,cl
    add bx,ax
    shl bx,1
    sub word ptr [bx+di],2h
    mov bx,word ptr [bx+di]
    mov word ptr [bx],si
    dec dx
    jnz short lbl6Fb
    cld
    pop ds
    pop si
    pop di
    mov sp,bp
    pop bp
    ret
_TEXT ENDS
    END
