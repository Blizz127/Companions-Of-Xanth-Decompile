_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mn38:NEAR
    EXTRN mn66:NEAR
mnem_unit:
    push bp
    mov bp,sp
    push si
    push di
    mov dx,word ptr [bp+0Ah]
    or dx,dx
    jng short lbl62f
    dec dx
    mov bx,word ptr [bp+0Ch]
    les di, dword ptr [bp+6h]
lbl13b:
    or dx,dx
    jz short lbl6Cf
    mov cx,word ptr [bx+4h]
    jcxz lbl3Bf
    cmp cx,dx
    jna short lbl22f
    mov cx,dx
lbl22f:
    push ds
    lds si, dword ptr [bx]
    mov ah,0Ah
    push cx
lbl28b:
    lodsb
    stosb
    cmp al,ah
    loopne lbl28b
    pop ax
    pop ds
    mov word ptr [bx],si
    jz short lbl67f
    sub word ptr [bx+4h],ax
    sub dx,ax
    jmp short lbl13b
lbl3Bf:
    push es
    push bx
    push dx
    push ds
    push bx
    push cs
    call mn38
    add sp,4h
    pop dx
    pop bx
    pop es
    cmp ax,0FFFFFFFFFFFFFFFFh
    jz short lbl57f
    stosb
    cmp al,0Ah
    jz short lbl6Cf
    dec dx
    jmp short lbl13b
lbl57f:
    cmp di,word ptr [bp+6h]
    jz short lbl62f
    test byte ptr [bx+0Ah],20h
    jz short lbl6Cf
lbl62f:
    xor ax,ax
    cwd
    jmp short lbl75f
lbl67f:
    sub ax,cx
    sub word ptr [bx+4h],ax
lbl6Cf:
    xor ax,ax
    stosb
    mov ax,word ptr [bp+6h]
    mov dx,word ptr [bp+8h]
lbl75f:
    pop di
    pop si
    pop bp
    retf
_TEXT ENDS
    END
