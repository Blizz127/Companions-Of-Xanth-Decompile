_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf22:FAR
    EXTRN mf44:FAR
    EXTRN mf52:FAR
    EXTRN mf54:FAR
    EXTRN mf58:FAR
    EXTRN mf58:FAR
    EXTRN mf58:FAR
    EXTRN mf58:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,2h
    push si
    cmp word ptr ds:[5E26h],0h
    jnz short lbl11f
    jmp near ptr lblA1f
lbl11f:
    dec word ptr ds:[5E26h]
    mov bx,word ptr ds:[5E26h]
    mov ax,bx
    add bx,bx
    add bx,ax
    add bx,bx
    les si, dword ptr ds:[5E22h]
    mov ax,word ptr es:[bx+si]
    mov word ptr [bp-2h],ax
    mov bx,ax
    add bx,ax
    add bx,bx
    les si, dword ptr ds:[5E16h]
    push word ptr es:[bx+si+2h]
    push word ptr es:[bx+si]
    call mf22
    add sp,4h
    mov si,word ptr ds:[5E26h]
    mov ax,si
    add si,si
    add si,ax
    add si,si
    les bx, dword ptr ds:[5E22h]
    mov ax,word ptr es:[bx+si+2h]
    mov dx,word ptr es:[bx+si+4h]
    mov bx,word ptr [bp-2h]
    add bx,bx
    add bx,bx
    les si, dword ptr ds:[5E16h]
    mov word ptr es:[bx+si],ax
    mov word ptr es:[bx+si+2h],dx
    mov ax,word ptr [bp-2h]
    inc ax
    push ax
    les si, dword ptr ds:[5E16h]
    push word ptr es:[bx+si+2h]
    push word ptr es:[bx+si]
    call mf44
    add sp,6h
    cmp word ptr ds:[5E26h],0h
    jnz short lbl9Cf
    mov ax,3h
    push ax
    xor ax,ax
    push ax
    call mf52
    add sp,4h
lbl9Cf:
    call mf54
lblA1f:
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
