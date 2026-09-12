_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf14:FAR
    EXTRN mf25:FAR
    EXTRN mf30:FAR
    EXTRN mf30:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,4h
    push si
    mov byte ptr ds:[69ACh],49h
    mov ax,word ptr [bp+6h]
    mov dx,word ptr [bp+8h]
    mov word ptr ds:[69A8h],ax
    mov word ptr ds:[69AAh],dx
    mov si,69A2h
    mov word ptr [si],ax
    mov word ptr [si+2h],dx
    push dx
    push ax
    call mf14
    add sp,4h
    mov word ptr ds:[69A6h],ax
    lea ax,word ptr [bp+0Eh]
    push ss
    push ax
    push word ptr [bp+0Ch]
    push word ptr [bp+0Ah]
    mov ax,69A2h
    push ds
    push ax
    call mf25
    add sp,0Ch
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
