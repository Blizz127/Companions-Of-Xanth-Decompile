_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi2:NEAR
    EXTRN mf11:FAR
    EXTRN mi16:NEAR
    EXTRN mf23:FAR
    EXTRN mi35:NEAR
    EXTRN mf45:FAR
    EXTRN mf45:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp, offset mi2
    push si
    push di
    mov word ptr ds:[62AEh],0h
    mov word ptr ds:[62B0h],0h
lbl15b:
    mov ax,0h
    push ax
    mov ax,word ptr [bp+6h]
    push ax
    call mf11
    add sp,4h
    and ax,0FFh
    mov word ptr [bp-4h],ax
    mov ax,word ptr [bp-4h]
    and ax, offset mi16
    cwd
    mov cx,7h
    mov word ptr [bp-8h],ax
    mov word ptr [bp-6h],dx
    mov ax,word ptr ds:[62AEh]
    mov dx,word ptr ds:[62B0h]
    call mf23
    mov cx,word ptr [bp-8h]
    mov bx,word ptr [bp-6h]
    or ax,cx
    or dx,bx
    mov word ptr ds:[62AEh],ax
    mov word ptr ds:[62B0h],dx
    mov bx,word ptr [bp+6h]
    shl bx,1
    add word ptr [bx+62BAh],1h
    mov ax,word ptr [bp-4h]
    and ax,80h
    cmp ax, offset mi35
    jz short lbl70f
    jmp near ptr lbl15b
lbl70f:
    mov ax,word ptr ds:[62AEh]
    mov dx,word ptr ds:[62B0h]
    jmp near ptr lbl7Af
lbl7Af:
    pop di
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
