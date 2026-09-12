_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf44:FAR
    EXTRN mf50:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,18h
    push di
    push si
    cmp word ptr [bp+6h],0h
    jl short lbl75f
    cmp word ptr [bp+8h],3h
    jz short lbl1Af
    cmp word ptr [bp+8h],4h
    jnz short lbl75f
lbl1Af:
    mov ax,14h
    imul word ptr [bp+8h]
    mov bx,word ptr [bp+6h]
    add bx,bx
    add bx,bx
    mov dx,word ptr [bx+67C2h]
    mov si,word ptr [bx+67C4h]
    add dx,ax
    push ds
    push si
    lea di,word ptr [bp-14h]
    mov si,dx
    mov ax,ss
    mov es,ax
    pop ds
    mov cx,0Ah
    rep movsw
    pop ds
    cmp byte ptr [bp-14h],4h
    jnz short lbl75f
    push word ptr [bp-10h]
    push word ptr [bp-12h]
    cmp word ptr [bp+8h],3h
    jnz short lbl5Ef
    mov ax,word ptr ds:[67FEh]
    mov dx,word ptr ds:[6800h]
    jmp short lbl65f
lbl5Ef:
    mov ax,word ptr ds:[6802h]
    mov dx,word ptr ds:[6804h]
lbl65f:
    mov word ptr [bp-18h],ax
    mov word ptr [bp-16h],dx
    push dx
    push ax
    call mf44
    add sp,8h
lbl75f:
    pop si
    pop di
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
