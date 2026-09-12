_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mn36:NEAR
    EXTRN mn66:NEAR
    EXTRN mn84:NEAR
    EXTRN mn104:NEAR
    EXTRN mn104:NEAR
    EXTRN mn104:NEAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,4h
    mov word ptr [bp-2h],cx
    mov di,5510h
    mov ax,si
    sub ax,5420h
    add di,ax
    test byte ptr [si+0Ah],0Ch
    jnz short lbl1Ef
    test byte ptr [di],1h
    jz short lbl23f
lbl1Ef:
    mov ax,word ptr [di+2h]
    jmp short lbl26f
lbl23f:
    mov ax,200h
lbl26f:
    mov word ptr [bp-4h],ax
lbl29b:
    test byte ptr [si+0Ah],0Ch
    jnz short lbl34f
    test byte ptr [di],1h
    jz short lbl67f
lbl34f:
    mov ax,word ptr [si+4h]
    or ax,ax
    jz short lbl67f
    cmp ax,cx
    jna short lbl41f
    mov ax,cx
lbl41f:
    push ax
    push bx
    push cx
    push es
    push ax
    push word ptr [si+2h]
    push word ptr [si]
    push es
    push bx
    push cs
    call mn36
    add sp,0Ah
    pop es
    pop cx
    pop bx
    pop ax
    sub cx,ax
    sub word ptr [si+4h],ax
    add bx,ax
    add word ptr [si],ax
    jmp short lbl63f
lbl63b:
lbl63f:
    jcxz lblC7f
    jmp short lbl29b
lbl67f:
    cmp cx,word ptr [bp-4h]
    jc short lbl9Cf
    xor dx,dx
    mov ax,cx
    div word ptr [bp-4h]
    mov ax,cx
    sub ax,dx
    push bx
    push cx
    push es
    push ax
    push es
    push bx
    xor ax,ax
    mov al,byte ptr [si+0Bh]
    push ax
    push cs
    call mn66
    add sp,8h
    pop es
    pop cx
    pop bx
    or ax,ax
    jz short lblBDf
    cmp ax,0FFFFFFFFFFFFFFFFh
    jz short lblC3f
    sub cx,ax
    add bx,ax
    jmp short lbl63b
lbl9Cf:
    push bx
    push cx
    push es
    push ds
    push si
    push cs
    call mn84
    add sp,4h
    pop es
    pop cx
    pop bx
    cmp ax,0FFFFFFFFFFFFFFFFh
    jz short lblC7f
    mov byte ptr es:[bx],al
    inc bx
    dec cx
    mov ax,word ptr [di+2h]
    mov word ptr [bp-4h],ax
    jmp short lbl63b
lblBDf:
    or byte ptr [si+0Ah],10h
    jmp short lblC7f
lblC3f:
    or byte ptr [si+0Ah],20h
lblC7f:
    mov ax,word ptr [bp-2h]
    sub ax,cx
    mov sp,bp
    pop bp
    ret
_TEXT ENDS
    END
