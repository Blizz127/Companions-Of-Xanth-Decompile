_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf12:FAR
    EXTRN mf42:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,8h
    push di
    push si
    mov word ptr [bp-6h],0FFFFh
    mov ax,word ptr [bp+8h]
    or ax,word ptr [bp+6h]
    jz short lbl70f
    les bx, dword ptr [bp+6h]
    push word ptr es:[bx+2h]
    push word ptr es:[bx]
    call mf12
    add sp,4h
    mov word ptr [bp-4h],ax
    mov word ptr [bp-2h],dx
    or dx,ax
    jz short lbl70f
    les bx, dword ptr [bp-4h]
    test byte ptr es:[bx+0Ah],80h
    jz short lbl70f
    mov bx,word ptr es:[bx+4h]
    add bx,bx
    add bx,bx
    les si, dword ptr ds:[63E4h]
    les si, dword ptr [bp+6h]
    les di, dword ptr ds:[63E4h]
    mov ax,word ptr es:[bx+di]
    mov dx,word ptr es:[bx+di+2h]
    les bx, dword ptr [bp+6h]
    cmp ax,word ptr es:[bx]
    jnz short lbl70f
    cmp dx,word ptr es:[bx+2h]
    jnz short lbl70f
    les bx, dword ptr [bp-4h]
    and byte ptr es:[bx+0Ah],0EFh
    mov word ptr [bp-6h],0h
lbl70f:
    mov ax,word ptr [bp-6h]
    pop si
    pop di
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
