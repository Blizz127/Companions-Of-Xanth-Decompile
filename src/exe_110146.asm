_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf21:FAR
    EXTRN mf24:FAR
    EXTRN mf30:FAR
    EXTRN mf44:FAR
    EXTRN mi57:NEAR
    EXTRN mf62:FAR
    EXTRN mf66:FAR
    EXTRN mf68:FAR
    EXTRN mf71:FAR
    EXTRN mf71:FAR
    EXTRN mf71:FAR
    EXTRN mf71:FAR
    EXTRN mf71:FAR
    EXTRN mf71:FAR
    EXTRN mf71:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,0Ah
    mov ax,14h
    imul word ptr [bp+8h]
    mov bx,word ptr [bp+6h]
    add bx,bx
    add bx,bx
    les bx, dword ptr [bx+67C2h]
    add bx,ax
    mov word ptr [bp-4h],bx
    mov word ptr [bp-2h],es
    cmp byte ptr es:[bx],5h
    jz short lbl28f
    jmp near ptr lblCFf
lbl28f:
    les bx, dword ptr es:[bx+0Ah]
    cmp byte ptr es:[bx],0h
    jnz short lbl35f
    jmp near ptr lblCFf
lbl35f:
    les bx, dword ptr [bp-4h]
    and byte ptr es:[bx+1h],7Fh
    call mf21
    mov ax,1h
    push ax
    call mf24
    add sp,2h
    mov ax,0FFFFh
    push ax
    xor ax,ax
    push ax
    call mf30
    add sp,4h
    les bx, dword ptr [bp-4h]
    les bx, dword ptr es:[bx+0Ah]
    mov word ptr [bp-0Ah],bx
    mov word ptr [bp-8h],es
    cmp byte ptr es:[bx],7Eh
    jnz short lbl78f
    inc word ptr [bp-0Ah]
    mov ax,word ptr ds:[6D24h]
    jmp short lbl9Ef
lbl78f:
    les bx, dword ptr [bp-4h]
    push word ptr es:[bx+0Ch]
    push word ptr es:[bx+0Ah]
    call mf44
    add sp,4h
    les bx, dword ptr [bp-4h]
    sub ax,word ptr es:[bx+6h]
    neg ax
    sub ax,word ptr es:[bx+2h]
    inc ax
    cwd
    sub ax,dx
    sar ax,1
lbl9Ef:
    mov word ptr [bp-6h],ax
    les bx, dword ptr [bp-4h]
    mov ax,word ptr es:[bx+4h]
    add ax, offset mi57
    push ax
    mov ax,word ptr es:[bx+2h]
    add ax,word ptr [bp-6h]
    push ax
    call mf62
    add sp,4h
    push word ptr [bp-8h]
    push word ptr [bp-0Ah]
    call mf66
    add sp,4h
    call mf68
lblCFf:
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
