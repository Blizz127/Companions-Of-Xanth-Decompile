_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi15:NEAR
    EXTRN mf20:FAR
    EXTRN mf38:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,4h
    push di
    push si
    mov ax,word ptr ds:[4DAEh]
    mov cx,ax
    add ax,ax
    add ax,cx
    add ax,ax
    add ax,ax
    sub ax,word ptr [bp+6h]
    push ax
    mov ax,word ptr [bp+6h]
    mov dx,word ptr [bp+8h]
    add ax, offset mi15
    push dx
    push ax
    push dx
    push word ptr [bp+6h]
    call mf20
    add sp,0Ah
    mov bx,word ptr ds:[4DAEh]
    mov ax,bx
    add bx,bx
    add bx,ax
    add bx,bx
    add bx,bx
    les si, dword ptr ds:[63DCh]
    xor ax,ax
    mov cx,6h
    lea di,word ptr [bx+si]
    rep stosw
    dec word ptr ds:[4DAEh]
    pop si
    pop di
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
