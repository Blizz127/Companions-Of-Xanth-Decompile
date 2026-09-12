_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi2:NEAR
    EXTRN mi16:NEAR
    EXTRN mf28:FAR
    EXTRN mf34:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp, offset mi2
    push si
    push di
    cmp word ptr ds:[5E36h],0h
    jnz short lbl13f
    jmp near ptr lbl31f
lbl13f:
    mov ax,0Eh
    imul word ptr [bp+6h]
    mov bx,0h
    mov cx,2E8Eh
    add bx,ax
    mov es,cx
    mov al,byte ptr es:[bx+0Dh]
    cbw
    and ax, offset mi16
    mov word ptr [bp-4h],ax
    jmp near ptr lbl36f
lbl31f:
    mov word ptr [bp-4h],0h
lbl36f:
    mov ax,word ptr [bp-4h]
    push ax
    mov bx,word ptr [bp+6h]
    mov es, ds:[5B36h]
    mov al,byte ptr es:[bx+194h]
    cbw
    add ax,0E0h
    push ax
    call mf28
    add sp,4h
    pop di
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
