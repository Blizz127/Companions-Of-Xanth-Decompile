_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mn30:NEAR
    EXTRN mn31:NEAR
    EXTRN mn55:NEAR
    EXTRN mn55:NEAR
mnem_unit:
    push bp
    mov bp,sp
    push ds
    lds dx, dword ptr [bp+6h]
    mov ax,word ptr [bp+0Ah]
    jmp short lbl0Ef
    push bp
    push ds
lbl0Ef:
    pushf
    push ax
    push bx
    push cx
    push dx
    push di
    push si
    push es
    cld
    mov si,dx
    mov cx,ax
    mov ax,1DC1h
    mov es,ax
    lodsw
    sub cx,2h
    mov word ptr es:[0B78h],ax
    mov dl,byte ptr es:[0D0Ah]
    mov byte ptr es:[0D0Ah],0h
lbl33b:
    jcxz lbl65f
    lodsw
    sub cx,2h
    push cs
    call mn30
    call mn31
    test byte ptr es:[bx+7h],8h
    jz short lbl33b
    lodsw
    sub cx,2h
    mov di,word ptr es:[bx+2h]
    mov word ptr es:[di+0Ah],ax
    or ax,ax
    jz short lbl5Ef
    or byte ptr es:[bx+7h],10h
    jmp short lbl33b
lbl5Ef:
    and byte ptr es:[bx+7h],0EFh
    jmp short lbl33b
lbl65f:
    mov byte ptr es:[0D0Ah],dl
    pop es
    pop si
    pop di
    pop dx
    pop cx
    pop bx
    pop ax
    popf
    pop ds
    pop bp
    retf
_TEXT ENDS
    END
