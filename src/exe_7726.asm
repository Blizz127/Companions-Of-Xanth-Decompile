_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mn47:NEAR
    EXTRN mn57:NEAR
    EXTRN mn77:NEAR
    EXTRN mn97:NEAR
    EXTRN mn105:NEAR
    EXTRN mn105:NEAR
    EXTRN mn105:NEAR
    EXTRN mn105:NEAR
mnem_unit:
    push bp
    mov bp,sp
    push si
    push di
    mov si,word ptr [bp+8h]
    mov al,byte ptr [si+0Ah]
    test al,82h
    jz short lbl79f
    test al,40h
    jnz short lbl79f
    mov word ptr [si+4h],0h
    test al,1h
    jz short lbl27f
    test al,10h
    jz short lbl79f
    mov cx,word ptr [si+6h]
    mov word ptr [si],cx
    and al,0FEh
lbl27f:
    or al,2h
    and al,0EFh
    mov byte ptr [si+0Ah],al
    mov di,si
    sub di,5420h
    add di,5510h
    xor bx,bx
    mov bl,byte ptr [si+0Bh]
    test al,8h
    jnz short lbl92f
    test al,4h
    jnz short lbl63f
    test byte ptr [di],1h
    jnz short lbl92f
    cmp si,542Ch
    jz short lbl5Cf
    cmp si,5438h
    jz short lbl5Cf
    cmp si,5450h
    jnz short lbl82f
lbl5Cf:
    test byte ptr [bx+53CCh],40h
    jz short lbl82f
lbl63b:
lbl63f:
    mov cx,1h
    lea di,word ptr [bp+6h]
    push cx
    push ss
    push di
    push bx
    push cs
    call mn47
    add sp,8h
    mov cx,1h
    jmp short lblBFf
lbl79b:
lbl79f:
    mov ax,0FFFFh
    or byte ptr [si+0Ah],20h
    jmp short lblE7f
lbl82f:
    push bx
    push ds
    push si
    call mn57
    add sp,4h
    pop bx
    test byte ptr [si+0Ah],8h
    jz short lbl63b
lbl92f:
    mov cx,word ptr [si]
    mov dx,word ptr [si+6h]
    sub cx,dx
    inc dx
    mov word ptr [si],dx
    mov dx,word ptr [di+2h]
    dec dx
    mov word ptr [si+4h],dx
    jcxz lblCAf
    push cx
    push cx
    push word ptr [si+8h]
    push word ptr [si+6h]
    push bx
    push cs
    call mn77
    add sp,8h
    pop cx
lblB6b:
    les di, dword ptr [si+6h]
    mov dx,word ptr [bp+6h]
    mov byte ptr es:[di],dl
lblBFf:
    cmp ax,cx
    jnz short lbl79b
    xor ax,ax
    mov al,byte ptr [bp+6h]
    jmp short lblE7f
lblCAf:
    xor ax,ax
    test byte ptr [bx+53CCh],20h
    jz short lblB6b
    mov cx,2h
    push cx
    push ax
    push ax
    push bx
    push cs
    call mn97
    add sp,8h
    xor ax,ax
    mov cx,ax
    jmp short lblB6b
lblE7f:
    pop di
    pop si
    pop bp
    retf
_TEXT ENDS
    END
