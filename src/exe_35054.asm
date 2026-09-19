_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf1e:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,2h
    push ds
    push es
    push si
    push di
    mov ax,38AFh
    mov ds,ax
    mov si,52A6h
    mov ax,word ptr [bp+0Ah]
    mov bx,word ptr [bp+8h]
    cmp word ptr [si+18h],1h
    jnz short lbl25f
    call mf1e
    jc short lbl48f
lbl25f:
    mov si,52A2h
    mov dx,word ptr ds:[5242h]
    cmp dx,0h
    jna short lbl38f
    mov word ptr [bp-2h],0FFFAh
    jmp short lbl48f
lbl38f:
    push ax
    push bx
    push word ptr [bp+6h]
    shl dx,1
    shl dx,1
    add si,dx
    db 0FFh, 1Ch ; override
    mov word ptr [bp-2h],ax
lbl48f:
    mov ax,word ptr [bp-2h]
    pop di
    pop si
    pop es
    pop ds
    mov sp,bp
    pop bp
    retf 6h
_TEXT ENDS
    END
