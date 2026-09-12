_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf7:FAR
    EXTRN mf11:FAR
    EXTRN mf16:FAR
    EXTRN mf38:FAR
    EXTRN mf53:FAR
    EXTRN mf53:FAR
    EXTRN mf53:FAR
    EXTRN mf53:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,0Ch
    push si
    sub ax,ax
    mov word ptr [bp-6h],ax
    mov word ptr [bp-8h],ax
    call mf7
    mov word ptr [bp-0Ah],ax
    or ax,ax
    jl short lbl8Ef
    call mf11
    mov ax,1h
    push ax
    push word ptr [bp+8h]
    push word ptr [bp+6h]
    call mf16
    add sp,6h
    mov word ptr [bp-4h],ax
    mov word ptr [bp-2h],dx
    or dx,ax
    jz short lbl6Ff
    mov ax,word ptr [bp-0Ah]
    les bx, dword ptr [bp-4h]
    mov word ptr es:[bx+4h],ax
    mov byte ptr es:[bx+0Ah],80h
    add ax,ax
    add ax,ax
    add ax,word ptr ds:[63E4h]
    mov dx,word ptr ds:[63E6h]
    mov word ptr [bp-8h],ax
    mov word ptr [bp-6h],dx
    mov cx,word ptr es:[bx]
    mov si,word ptr es:[bx+2h]
    mov bx,ax
    mov es,dx
    mov word ptr es:[bx],cx
    mov word ptr es:[bx+2h],si
lbl6Ff:
    call mf38
    mov word ptr [bp-0Ch],ax
    mov ax,word ptr ds:[63E0h]
    cmp word ptr [bp-0Ch],ax
    jnc short lbl8Ef
    mov ax,word ptr [bp-0Ch]
    mov word ptr ds:[63E0h],ax
    cmp ax,word ptr ds:[63E2h]
    jnc short lbl8Ef
    mov word ptr ds:[63E2h],ax
lbl8Ef:
    mov ax,word ptr [bp-8h]
    mov dx,word ptr [bp-6h]
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
