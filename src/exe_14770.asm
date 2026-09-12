_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf21:FAR
    EXTRN mf35:FAR
    EXTRN mf42:FAR
    EXTRN mf42:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,4h
    push di
    push si
    mov byte ptr ds:[69A0h],42h
    mov ax,word ptr [bp+6h]
    mov dx,word ptr [bp+8h]
    mov word ptr ds:[699Ch],ax
    mov word ptr ds:[699Eh],dx
    mov si,6996h
    mov word ptr [si],ax
    mov word ptr [si+2h],dx
    mov word ptr ds:[699Ah],7FFFh
    lea ax,word ptr [bp+0Eh]
    push ss
    push ax
    push word ptr [bp+0Ch]
    push word ptr [bp+0Ah]
    push ds
    push si
    call mf21
    add sp,0Ch
    mov di,ax
    dec word ptr ds:[699Ah]
    js short lbl54f
    les bx, dword ptr ds:[6996h]
    inc word ptr ds:[6996h]
    mov byte ptr es:[bx],0h
    jmp short lbl61f
    nop
lbl54f:
    push ds
    push si
    xor ax,ax
    push ax
    call mf35
    add sp,6h
lbl61f:
    mov ax,di
    pop si
    pop di
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
