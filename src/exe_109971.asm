_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf16:FAR
    EXTRN mf21:FAR
    EXTRN mf35:FAR
    EXTRN mf55:FAR
    EXTRN mf59:FAR
    EXTRN mf61:FAR
    EXTRN mf67:FAR
    EXTRN mf67:FAR
    EXTRN mf67:FAR
    EXTRN mf67:FAR
    EXTRN mf67:FAR
    EXTRN mf67:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,0Ah
    push di
    push si
    lea ax,word ptr [bp-6h]
    push ss
    push ax
    lea ax,word ptr [bp-4h]
    push ss
    push ax
    lea cx,word ptr [bp-2h]
    push ss
    push cx
    push word ptr [bp+8h]
    push word ptr [bp+6h]
    call mf16
    add sp,10h
    mov ax,word ptr [bp+8h]
    add ax,word ptr ds:[4FB8h]
    mov word ptr [bp-0Ah],ax
    call mf21
    xor ax,ax
    push ax
    mov ax,5h
    push ax
    push word ptr [bp-0Ah]
    mov ax,word ptr [bp+0Eh]
    add ax,word ptr [bp+6h]
    dec ax
    push ax
    push word ptr [bp+8h]
    push word ptr [bp+6h]
    push word ptr [bp-2h]
    mov si,ax
    call mf35
    add sp,0Eh
    mov word ptr [bp-4h],ax
    mov ax,14h
    imul word ptr [bp-4h]
    mov bx,ax
    mov di,word ptr [bp-2h]
    add di,di
    add di,di
    les di, dword ptr [di+67C2h]
    mov ax,word ptr [bp+0Ah]
    mov dx,word ptr [bp+0Ch]
    mov word ptr es:[bx+di+0Ah],ax
    mov word ptr es:[bx+di+0Ch],dx
    mov ax,4h
    push ax
    push word ptr [bp-0Ah]
    push si
    push word ptr [bp+8h]
    push word ptr [bp+6h]
    call mf55
    add sp,0Ah
    push word ptr [bp-4h]
    push word ptr [bp-2h]
    call mf59
    add sp,4h
    call mf61
    mov ax,word ptr [bp-4h]
    pop si
    pop di
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
