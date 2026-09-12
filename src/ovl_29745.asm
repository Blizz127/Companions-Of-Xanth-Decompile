_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi3:NEAR
    EXTRN md14:NEAR
    EXTRN mf18:FAR
    EXTRN mf26:FAR
    EXTRN mf32:FAR
    EXTRN mf39:FAR
    EXTRN mf46:FAR
    EXTRN mf55:FAR
    EXTRN mf55:FAR
    EXTRN mf55:FAR
    EXTRN mf55:FAR
    EXTRN mf55:FAR
mnem_unit:
    push bp
    mov bp,sp
    mov ax,word ptr [bp+8h]
    cmp ax, offset mi3
    ja short lbl85f
    add ax,ax
    xchg ax,bx
    jmp word ptr cs:[bx+115h]
    nop
    and word ptr [bx+di],ax
    xor ax,word ptr [bx+di]
    inc bx
    add word ptr [bp+di],si
    add word ptr [bx+di+2101h],ax
    add word ptr [bx+si+md14],di
    push ax
    mov ax,0Dh
    push ax
    call mf18
lbl2Db:
    mov sp,bp
    jmp short lbl85f
    nop
    xor ax,ax
    push ax
    push word ptr [bp+8h]
lbl38b:
    push word ptr [bp+6h]
    call mf26
    jmp short lbl2Db
    xor ax,ax
    push ax
    push word ptr [bp+8h]
    push word ptr [bp+6h]
    call mf32
    mov sp,bp
    mov ax,1h
    push ax
    mov cx,3h
    push cx
    push word ptr [bp+6h]
    call mf39
    mov sp,bp
    mov ax,1h
    push ax
    mov cx,4h
    push cx
    push word ptr [bp+6h]
    call mf46
    mov sp,bp
    mov ax,1h
    push ax
    mov ax,5h
    push ax
    jmp short lbl38b
    mov byte ptr ds:[2F5h],1h
lbl85f:
    pop bp
    retf
_TEXT ENDS
    END
