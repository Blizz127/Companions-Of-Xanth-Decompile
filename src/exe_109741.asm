_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
mnem_unit:
    push bp
    mov bp,sp
    sub sp,14h
    push di
    push si
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
    test byte ptr [bp-13h],80h
    jz short lbl3Cf
    xor ax,ax
    jmp short lbl61f
    nop
lbl3Cf:
    mov ax,word ptr [bp+0Ch]
    or ax,word ptr [bp+0Ah]
    jz short lbl4Df
    mov ax,word ptr [bp-12h]
    les bx, dword ptr [bp+0Ah]
    mov word ptr es:[bx],ax
lbl4Df:
    mov ax,word ptr [bp+10h]
    or ax,word ptr [bp+0Eh]
    jz short lbl5Ef
    mov ax,word ptr [bp-10h]
    les bx, dword ptr [bp+0Eh]
    mov word ptr es:[bx],ax
lbl5Ef:
    mov ax,1h
lbl61f:
    pop si
    pop di
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
