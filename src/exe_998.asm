_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf90:FAR
    EXTRN mf7b:FAR
    EXTRN mf84:FAR
    EXTRN mf37:FAR
mnem_unit:
    push bp
    mov bp,sp
    cmp byte ptr ds:[4002h],1h
    jnz short lbl0Df
    jmp near ptr lbl95f
lbl0Df:
    mov ax,word ptr [bp+6h]
    mov word ptr ds:[3FF6h],ax
    inc ax
    mov word ptr ds:[3FF8h],ax
    mov word ptr ds:[3FFAh],ax
    mov al,byte ptr [bp+8h]
    add al,8h
    mov byte ptr ds:[4004h],al
    mov cl,byte ptr [bp+8h]
    mov al,1h
    shl al,cl
    not al
    mov byte ptr ds:[4003h],al
    mov ax,5E7Ch
    mov word ptr ds:[3FFCh],ax
    mov word ptr ds:[3FFEh],ax
    call mf37
    mov ah,0FFh
    push es
    mov ah,35h
    mov al,byte ptr ds:[4004h]
    int 21h
    mov word ptr ds:[4005h],bx
    mov word ptr ds:[4007h],es
    pop es
    push ds
    mov dx,0FEh
    mov ah,25h
    mov al,byte ptr ds:[4004h]
    push cs
    pop ds
    int 21h
    pop ds
    in al, 21h
    and al,byte ptr ds:[4003h]
    out 21h, al
    mov ax,1h
    mov byte ptr ds:[4002h],1h
    mov word ptr ds:[4009h],13Ah
    mov word ptr ds:[400Bh],28h
    mov ah,0ACh
    call mf7b
    mov cx,0FFFFh
lbl83b:
    push cx
    call mf84
    pop cx
    cmp al,0FFh
    jnz short lbl95f
    loop lbl83b
    call mf90
lbl95f:
    mov word ptr ds:[4009h],139h
    mov word ptr ds:[400Bh],28h
    sub ah,ah
    mov al,byte ptr ds:[4002h]
    pop bp
    retf
_TEXT ENDS
    END
