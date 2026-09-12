_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf34:FAR
    EXTRN mf36:FAR
    EXTRN mf40:FAR
    EXTRN mf44:FAR
    EXTRN mi47:NEAR
    EXTRN mi50:NEAR
    EXTRN mf63:FAR
    EXTRN mi66:NEAR
    EXTRN mi69:NEAR
    EXTRN mf74:FAR
    EXTRN mf78:FAR
    EXTRN mf86:FAR
    EXTRN mf88:FAR
    EXTRN mf91:FAR
    EXTRN mf93:FAR
    EXTRN mf94:FAR
    EXTRN mf100:FAR
    EXTRN mf105:FAR
    EXTRN mf109:FAR
    EXTRN mf122:FAR
    EXTRN mf126:FAR
    EXTRN mf130:FAR
    EXTRN mf133:FAR
    EXTRN mf136:FAR
    EXTRN mf139:FAR
    EXTRN mf143:FAR
    EXTRN mf146:FAR
    EXTRN mf149:FAR
    EXTRN mf150:FAR
    EXTRN mf151:FAR
    EXTRN mf163:FAR
    EXTRN mf163:FAR
    EXTRN mf163:FAR
    EXTRN mf163:FAR
    EXTRN mf163:FAR
    EXTRN mf163:FAR
    EXTRN mf163:FAR
    EXTRN mf163:FAR
    EXTRN mf163:FAR
    EXTRN mf163:FAR
    EXTRN mf163:FAR
    EXTRN mf163:FAR
    EXTRN mf163:FAR
    EXTRN mf163:FAR
    EXTRN mf163:FAR
    EXTRN mf163:FAR
    EXTRN mf163:FAR
    EXTRN mf163:FAR
    EXTRN mf163:FAR
    EXTRN mf163:FAR
    EXTRN mf163:FAR
    EXTRN mf163:FAR
    EXTRN mf163:FAR
    EXTRN mf163:FAR
    EXTRN mf163:FAR
    EXTRN mf163:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,32h
    push di
    push si
    mov ax,14h
    imul word ptr [bp+8h]
    mov bx,word ptr [bp+6h]
    add bx,bx
    add bx,bx
    mov dx,word ptr [bx+67C2h]
    mov si,word ptr [bx+67C4h]
    add dx,ax
    push ds
    push si
    lea di,word ptr [bp-14h]
    mov si,dx
    mov ax,ss
    mov es,ax
    pop ds
    mov cx,0Ah
    rep movsw
    pop ds
    mov ax,word ptr [bp-12h]
    mov word ptr [bp-2Ah],ax
    mov ax,word ptr [bp-10h]
    mov word ptr [bp-2Ch],ax
    mov ax,word ptr [bp-0Eh]
    mov word ptr [bp-2Eh],ax
    mov ax,word ptr [bp-0Ch]
    mov word ptr [bp-30h],ax
    xor ax,ax
    push ax
    push ax
    call mf34
    add sp,4h
    call mf36
    lea ax,word ptr [bp-28h]
    push ss
    push ax
    call mf40
    add sp,4h
    mov ax,0FFFFh
    push ax
    call mf44
    add sp,2h
    mov ax,word ptr [bp-30h]
    sub ax, offset mi47
    push ax
    mov ax,word ptr [bp-2Eh]
    sub ax, offset mi50
    push ax
    mov ax,word ptr [bp-2Ch]
    inc ax
    push ax
    mov cx,word ptr [bp-2Ah]
    inc cx
    push cx
    lea dx,word ptr [bp-28h]
    push ss
    push dx
    mov si,ax
    mov di,cx
    call mf63
    add sp,0Ch
    mov ax,word ptr [bp-2Ch]
    add ax, offset mi66
    push ax
    mov ax,word ptr [bp-2Ah]
    add ax, offset mi69
    push ax
    lea ax,word ptr [bp-28h]
    push ss
    push ax
    call mf74
    add sp,8h
    mov ax,4h
    push ax
    call mf78
    add sp,2h
    push word ptr [bp-30h]
    push word ptr [bp-2Eh]
    push word ptr [bp-2Ch]
    push word ptr [bp-2Ah]
    mov ax,1h
    push ax
    call mf86
    add sp,0Ah
    call mf88
    mov ax,96h
    push ax
    call mf91
    add sp,2h
    call mf93
    call mf94
    push si
    push di
    lea ax,word ptr [bp-28h]
    push ss
    push ax
    call mf100
    add sp,8h
    lea ax,word ptr [bp-28h]
    push ss
    push ax
    call mf105
    add sp,4h
    mov ax,0Ah
    push ax
    call mf109
    add sp,2h
    mov ax,word ptr [bp-30h]
    dec ax
    push ax
    mov cx,word ptr [bp-2Eh]
    dec cx
    push cx
    push si
    push di
    mov cx,1h
    push cx
    mov word ptr [bp-32h],ax
    call mf122
    add sp,0Ah
    mov ax,0Fh
    push ax
    call mf126
    add sp,2h
    push word ptr [bp-2Ah]
    push word ptr [bp-32h]
    call mf130
    push word ptr [bp-2Ah]
    push word ptr [bp-2Ch]
    call mf133
    push word ptr [bp-2Eh]
    push word ptr [bp-2Ch]
    call mf136
    mov ax,6h
    push ax
    call mf139
    add sp,2h
    push di
    push word ptr [bp-30h]
    call mf143
    push word ptr [bp-2Eh]
    push word ptr [bp-30h]
    call mf146
    push word ptr [bp-2Eh]
    push si
    call mf149
    call mf150
    call mf151
    test byte ptr [bp-13h],80h
    jz short lbl1A4f
    xor ax,ax
    cwd
    jmp short lbl1AAf
lbl1A4f:
    mov ax,word ptr [bp-0Ah]
    mov dx,word ptr [bp-8h]
lbl1AAf:
    pop si
    pop di
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
