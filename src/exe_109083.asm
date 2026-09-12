_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf24:FAR
    EXTRN mf26:FAR
    EXTRN mf33:FAR
    EXTRN mf35:FAR
    EXTRN mf40:FAR
    EXTRN mf40:FAR
    EXTRN mf40:FAR
    EXTRN mf40:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,14h
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
    push word ptr ds:[6E52h]
    call mf24
    add sp,2h
    call mf26
    push word ptr [bp-0Ch]
    push word ptr [bp-0Eh]
    push word ptr [bp-10h]
    push word ptr [bp-12h]
    mov ax,2h
    push ax
    call mf33
    add sp,0Ah
    call mf35
    pop si
    pop di
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
