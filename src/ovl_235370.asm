_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf5:FAR
    EXTRN mf7:FAR
    EXTRN mi10:NEAR
    EXTRN mi16:NEAR
    EXTRN mi26:NEAR
    EXTRN mf34:FAR
    EXTRN mf37:FAR
    EXTRN mf41:FAR
    EXTRN mf44:FAR
    EXTRN mf47:FAR
    EXTRN mi49:NEAR
    EXTRN mi52:NEAR
    EXTRN mf55:FAR
    EXTRN mi57:NEAR
    EXTRN mf61:FAR
    EXTRN mi64:NEAR
    EXTRN mf66:FAR
    EXTRN mf68:FAR
    EXTRN mi71:NEAR
    EXTRN mf75:FAR
    EXTRN mi78:NEAR
    EXTRN mf81:FAR
    EXTRN mf84:FAR
    EXTRN mf89:FAR
    EXTRN mf92:FAR
    EXTRN mf95:FAR
    EXTRN mf96:FAR
    EXTRN mf101:FAR
    EXTRN mf101:FAR
    EXTRN mf101:FAR
    EXTRN mf101:FAR
    EXTRN mf101:FAR
    EXTRN mf101:FAR
    EXTRN mf101:FAR
    EXTRN mf101:FAR
    EXTRN mf101:FAR
    EXTRN mf101:FAR
    EXTRN mf101:FAR
    EXTRN mf101:FAR
    EXTRN mf101:FAR
    EXTRN mf101:FAR
    EXTRN mf101:FAR
    EXTRN mf101:FAR
    EXTRN mf101:FAR
    EXTRN mf101:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,8h
    push di
    push si
    call mf5
    push word ptr ds:[5B10h]
    call mf7
    add sp,2h
    mov ax,word ptr ds:[332Eh]
    sub ax, offset mi10
    mov word ptr [bp-2h],ax
    mov cx,ax
    mov ax,word ptr [bp+6h]
    imul word ptr ds:[5B1Ch]
    add ax,word ptr ds:[332Eh]
    add ax, offset mi16
    mov word ptr [bp-6h],ax
    mov dx,word ptr ds:[3330h]
    sub dx,5h
    mov word ptr [bp-4h],dx
    mov bx,ax
    mov ax,word ptr [bp+8h]
    mov si,dx
    imul word ptr ds:[5B1Eh]
    add ax,word ptr ds:[3330h]
    add ax, offset mi26
    mov word ptr [bp-8h],ax
    push ax
    push bx
    push si
    push cx
    mov ax,2h
    push ax
    call mf34
    add sp,0Ah
    push word ptr ds:[5B0Eh]
    call mf37
    add sp,2h
    push word ptr [bp-2h]
    push word ptr [bp-8h]
    call mf41
    push word ptr [bp-2h]
    push word ptr [bp-4h]
    call mf44
    push word ptr [bp-6h]
    push word ptr [bp-4h]
    call mf47
    mov ax,word ptr [bp-2h]
    add ax, offset mi49
    push ax
    mov ax,word ptr [bp-8h]
    sub ax, offset mi52
    push ax
    mov si,ax
    call mf55
    mov ax,word ptr [bp-6h]
    sub ax, offset mi57
    push ax
    push si
    mov di,ax
    call mf61
    push di
    mov ax,word ptr [bp-4h]
    add ax, offset mi64
    push ax
    call mf66
    push word ptr ds:[5B14h]
    call mf68
    add sp,2h
    mov ax,word ptr [bp-2h]
    add ax, offset mi71
    push ax
    push si
    mov si,ax
    call mf75
    push si
    mov ax,word ptr [bp-4h]
    add ax, offset mi78
    push ax
    mov si,ax
    call mf81
    push di
    push si
    call mf84
    mov ax,word ptr [bp-2h]
    inc ax
    push ax
    push word ptr [bp-8h]
    call mf89
    push word ptr [bp-6h]
    push word ptr [bp-8h]
    call mf92
    push word ptr [bp-6h]
    push word ptr [bp-4h]
    call mf95
    call mf96
    pop si
    pop di
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
