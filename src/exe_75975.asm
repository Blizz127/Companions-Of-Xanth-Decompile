_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi2:NEAR
    EXTRN mf5:FAR
    EXTRN mf6:FAR
    EXTRN mf9:FAR
    EXTRN mf13:FAR
    EXTRN mf17:FAR
    EXTRN mf21:FAR
    EXTRN mf26:FAR
    EXTRN mf31:FAR
    EXTRN mi34:NEAR
    EXTRN mi38:NEAR
    EXTRN mf44:FAR
    EXTRN mf46:FAR
    EXTRN mf51:FAR
    EXTRN mf51:FAR
    EXTRN mf51:FAR
    EXTRN mf51:FAR
    EXTRN mf51:FAR
    EXTRN mf51:FAR
    EXTRN mf51:FAR
    EXTRN mf51:FAR
    EXTRN mf51:FAR
    EXTRN mf51:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp, offset mi2
    push si
    push di
    call mf5
    call mf6
    mov ax,10h
    push ax
    call mf9
    add sp,2h
    mov ax,0h
    push ax
    call mf13
    add sp,2h
    mov ax,1h
    push ax
    call mf17
    add sp,2h
    mov ax,0h
    push ax
    call mf21
    add sp,2h
    mov ax,word ptr [bp+6h]
    cbw
    push ax
    call mf26
    add sp,2h
    mov ax,word ptr [bp+8h]
    cbw
    push ax
    call mf31
    add sp,2h
    mov ax,word ptr [bp+6h]
    add ax, offset mi34
    add ax,word ptr [bp+8h]
    mov word ptr [bp-4h],ax
    mov ax,word ptr [bp-4h]
    and ax, offset mi38
    mov cx,80h
    sub cx,ax
    mov ax,cx
    cbw
    push ax
    call mf44
    add sp,2h
    call mf46
    pop di
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
