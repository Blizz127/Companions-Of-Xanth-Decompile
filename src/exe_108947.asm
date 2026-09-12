_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf37:FAR
    EXTRN mf39:FAR
    EXTRN mf46:FAR
    EXTRN mf48:FAR
    EXTRN mf53:FAR
    EXTRN mf53:FAR
    EXTRN mf53:FAR
    EXTRN mf53:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,1Ch
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
    inc ax
    mov word ptr [bp-16h],ax
    mov ax,word ptr [bp-10h]
    add ax,word ptr ds:[6D48h]
    mov word ptr [bp-18h],ax
    mov ax,word ptr [bp-0Eh]
    dec ax
    mov word ptr [bp-1Ah],ax
    mov ax,word ptr [bp-0Ch]
    sub ax,word ptr ds:[6D48h]
    dec ax
    mov word ptr [bp-1Ch],ax
    push word ptr ds:[6E52h]
    call mf37
    add sp,2h
    call mf39
    push word ptr [bp-1Ch]
    push word ptr [bp-1Ah]
    push word ptr [bp-18h]
    push word ptr [bp-16h]
    mov ax,2h
    push ax
    call mf46
    add sp,0Ah
    call mf48
    pop si
    pop di
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
