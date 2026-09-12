_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi2:NEAR
    EXTRN mf9:FAR
    EXTRN mi14:NEAR
    EXTRN mf21:FAR
    EXTRN mi31:NEAR
    EXTRN mf41:FAR
    EXTRN mf41:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp, offset mi2
    push si
    push di
    mov word ptr [bp-6h],0h
    mov word ptr [bp-4h],0h
lbl13b:
    mov ax,0h
    push ax
    call mf9
    add sp,2h
    and ax,0FFh
    mov word ptr [bp-8h],ax
    mov ax,word ptr [bp-8h]
    and ax, offset mi14
    cwd
    mov cx,7h
    mov word ptr [bp-0Ch],ax
    mov word ptr [bp-0Ah],dx
    mov ax,word ptr [bp-6h]
    mov dx,word ptr [bp-4h]
    call mf21
    mov cx,word ptr [bp-0Ch]
    mov bx,word ptr [bp-0Ah]
    or ax,cx
    or dx,bx
    mov word ptr [bp-6h],ax
    mov word ptr [bp-4h],dx
    add word ptr ds:[627Ch],1h
    mov ax,word ptr [bp-8h]
    and ax,80h
    cmp ax, offset mi31
    jz short lbl63f
    jmp near ptr lbl13b
lbl63f:
    mov ax,word ptr [bp-6h]
    mov dx,word ptr [bp-4h]
    jmp near ptr lbl6Cf
lbl6Cf:
    pop di
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
