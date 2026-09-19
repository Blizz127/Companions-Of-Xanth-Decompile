_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mn76:NEAR
    EXTRN mjn41:NEAR
    EXTRN mn18:NEAR
mnem_unit:
    push bp
    mov bp,sp
    push ax
    push bx
    push cx
    push dx
    push di
    push si
    push ds
    pushf
    mov dx,1DC1h
    mov ds,dx
    test word ptr ds:[0D27h],100h
    jz short lbl1Bf
    call mn18
lbl1Bf:
    mov bx,word ptr [bp+2h]
    mov ax,word ptr [bx+5h]
    push ax
    mov si,word ptr ds:[0B7Ah]
    mov ax,word ptr ds:[0B78h]
    add si,ax
    add ax,6h
    mov word ptr ds:[0B78h],ax
    cmp ax,word ptr ds:[0B7Eh]
    jc short lbl44f
    mov ax,2h
    mov cx,2h
    mov bx,word ptr ds:[16h]
    jmp mjn41
lbl44f:
    pop cx
    mov ds, ds:[0B7Ch]
    mov word ptr [si],cx
    test word ptr cs:[0D27h],1h
    jnz short lbl59f
    mov ax,1DC1h
    jmp short lbl61f
lbl59f:
    mov ax,word ptr [bp+6h]
    mov word ptr [bp+6h],1DC1h
lbl61f:
    mov word ptr [si+4h],ax
    mov ax,word ptr [bp+4h]
    mov word ptr [si+2h],ax
    mov word ptr [bp+4h],7CAh
    mov ax,cs
    mov ds,ax
    mov ax,cx
    push cs
    call mn76
    popf
    pop ds
    pop si
    pop di
    pop dx
    pop cx
    pop bx
    pop ax
    pop bp
    ret
lbl558f:
_TEXT ENDS
    END
