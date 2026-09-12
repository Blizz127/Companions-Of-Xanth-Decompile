_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf6:FAR
    EXTRN mf12:FAR
    EXTRN mf17:FAR
    EXTRN mf30:FAR
    EXTRN mf34:FAR
    EXTRN mf40:FAR
    EXTRN mf50:FAR
    EXTRN mf61:FAR
    EXTRN mf73:FAR
    EXTRN mf85:FAR
    EXTRN mf88:FAR
    EXTRN md98:NEAR
    EXTRN md99:NEAR
    EXTRN mf105:FAR
    EXTRN mf109:FAR
    EXTRN mf111:FAR
    EXTRN mf113:FAR
    EXTRN mf118:FAR
    EXTRN mf123:FAR
    EXTRN mf126:FAR
    EXTRN mf131:FAR
    EXTRN mf131:FAR
    EXTRN mf131:FAR
    EXTRN mf131:FAR
    EXTRN mf131:FAR
    EXTRN mf131:FAR
    EXTRN mf131:FAR
    EXTRN mf131:FAR
    EXTRN mf131:FAR
    EXTRN mf131:FAR
    EXTRN mf131:FAR
    EXTRN mf131:FAR
    EXTRN mf131:FAR
    EXTRN mf131:FAR
    EXTRN mf131:FAR
    EXTRN mf131:FAR
    EXTRN mf131:FAR
    EXTRN mf131:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,18h
    push si
    xor ax,ax
    push ax
    call mf6
    add sp,2h
    mov word ptr [bp-16h],ax
    lea ax,word ptr [bp-14h]
    push ss
    push ax
    call mf12
    add sp,4h
    xor ax,ax
    push ax
    push ax
    call mf17
    add sp,4h
    mov ax,47h
    push ax
    mov cx,119h
    push cx
    mov dx,31h
    push dx
    mov bx,54h
    push bx
    lea si,word ptr [bp-14h]
    push ss
    push si
    call mf30
    add sp,0Ch
    mov ax,0Ah
    push ax
    call mf34
    add sp,2h
    mov ax,0FFFFh
    push ax
    mov ax,0Fh
    push ax
    call mf40
    add sp,4h
    mov ax,47h
    push ax
    mov cx,119h
    push cx
    mov dx,31h
    push dx
    mov bx,54h
    push bx
    call mf50
    add sp,8h
    mov word ptr [bp-18h],ax
    mov ax,47h
    push ax
    mov cx,119h
    push cx
    mov dx,31h
    push dx
    mov bx,54h
    push bx
    call mf61
    add sp,8h
    mov ax,14h
    push ax
    mov cx,47h
    push cx
    mov cx,119h
    push cx
    mov cx,31h
    push cx
    mov cx,54h
    push cx
    call mf73
    add sp,0Ah
    mov ax,14h
    push ax
    mov ax,46h
    push ax
    mov ax,118h
    push ax
    mov ax,32h
    push ax
    mov ax,55h
    push ax
    call mf85
    add sp,0Ah
    push word ptr [bp-18h]
    call mf88
    add sp,2h
    mov ax,word ptr ds:[264h]
    mov cx,64h
    cwd
    idiv cx
    mov bx,ax
    add bx,ax
    add bx,bx
    mov es, ds:[5A72h]
    push word ptr es:[bx+md98]
    push word ptr es:[bx+md99]
    push word ptr ds:[264h]
    mov ax,74h
    mov cx,3167h
    push cx
    push ax
    call mf105
    add sp,0Ah
    xor ax,ax
    push ax
    call mf109
    add sp,2h
    call mf111
    push word ptr [bp-18h]
    call mf113
    add sp,2h
    lea ax,word ptr [bp-14h]
    push ss
    push ax
    call mf118
    add sp,4h
    lea ax,word ptr [bp-14h]
    push ss
    push ax
    call mf123
    add sp,4h
    push word ptr [bp-16h]
    call mf126
    add sp,2h
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
