_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf17:FAR
    EXTRN mf33:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,4h
    push di
    push si
    mov word ptr [bp-4h],434Ah
lbl0Db:
    mov bx,word ptr [bp-4h]
    add word ptr [bp-4h],18h
    mov word ptr [bx],0FFFFh
    cmp word ptr [bp-4h],449Ah
    jc short lbl0Db
    xor ax,ax
    push ax
    push word ptr [bp+6h]
    mov ax,4336h
    push ds
    push ax
    call mf17
    add sp,8h
    mov ax,38AFh
    push ds
    mov di,6D4Ah
    mov si,6A84h
    push ds
    pop es
    mov ds,ax
    mov cx,48h
    rep movsw
    pop ds
    pop si
    pop di
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
