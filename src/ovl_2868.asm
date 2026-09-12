_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf13:FAR
    EXTRN mf18:FAR
    EXTRN mf27:FAR
    EXTRN mf28:FAR
    EXTRN mf33:FAR
    EXTRN mf33:FAR
    EXTRN mf33:FAR
    EXTRN mf33:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,8h
    push di
    push si
    mov word ptr [bp-8h],300h
lbl0Db:
    mov bx,word ptr [bp-8h]
    mov es, ds:[5A68h]
    push word ptr es:[bx+0Ah]
    push word ptr es:[bx+10h]
    push word ptr es:[bx+0Eh]
    mov si,bx
    mov di,es
    call mf13
    add sp,6h
    mov es,di
    push word ptr es:[si+10h]
    push word ptr es:[si+0Eh]
    call mf18
    add sp,4h
    mov es,di
    sub ax,ax
    mov word ptr es:[si+10h],ax
    mov word ptr es:[si+0Eh],ax
    add word ptr [bp-8h],12h
    cmp word ptr [bp-8h],35Ah
    jc short lbl0Db
    call mf27
    call mf28
    pop si
    pop di
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
