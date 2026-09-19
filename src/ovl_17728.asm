_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf69:FAR
    EXTRN mf26:FAR
    EXTRN mf40:FAR
    EXTRN mf57:FAR
    EXTRN mfa1:FAR
    EXTRN mff:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,22h
    push di
    push si
    push word ptr [bp+6h]
    mov ax,4h
    push ax
    call mff
    add sp,4h
    mov word ptr [bp-2h],ax
    or ax,ax
    jnz short lbl34f
    mov ax,0h
    mov cx,3181h
lbl24b:
    push cx
    push ax
    call mf26
    add sp,4h
    mov ax,1h
    jmp near ptr lbl100f
lbl34f:
    mov ax,20h
    push ax
    lea ax,word ptr [bp-22h]
    push ss
    push ax
    push word ptr [bp-2h]
    call mf40
    add sp,8h
    or ax,ax
    jnz short lbl54f
    mov ax,22h
    mov cx,3181h
    jmp short lbl24b
lbl54f:
    push word ptr [bp-2h]
    call mf57
    add sp,2h
    mov byte ptr [bp-3h],0h
    mov ax,20h
    cwd
    push dx
    push ax
    call mf69
    add sp,4h
    mov bx,word ptr ds:[18F6h]
    add bx,bx
    add bx,bx
    les si, dword ptr ds:[18F2h]
    mov word ptr es:[bx+si],ax
    mov word ptr es:[bx+si+2h],dx
    mov bx,word ptr ds:[18F6h]
    add bx,bx
    add bx,bx
    les si, dword ptr ds:[18F2h]
    mov ax,word ptr es:[bx+si+2h]
    or ax,word ptr es:[bx+si]
    jnz short lblAEf
    mov ax,54h
    mov cx,3181h
    push cx
    push ax
    call mfa1
    add sp,4h
    xor ax,ax
    jmp short lbl100f
    nop
lblAEf:
    mov bx,word ptr ds:[18F6h]
    add bx,bx
    les si, dword ptr ds:[18EEh]
    mov ax,word ptr [bp+6h]
    mov word ptr es:[bx+si],ax
    mov bx,word ptr ds:[18F6h]
    add bx,bx
    add bx,bx
    les si, dword ptr ds:[18F2h]
    mov di,word ptr es:[bx+si]
    mov cx,word ptr es:[bx+si+2h]
    mov dx,cx
    push ds
    mov si,di
    lea di,word ptr [bp-22h]
    mov cx,ss
    mov es,cx
    mov ds,dx
    mov cx,0FFFFh
    xor ax,ax
    repne scasb
    not cx
    sub di,cx
    db 87h, 0FEh ; override
    push dx
    push es
    pop ds
    pop es
    shr cx,1
    rep movsw
    adc cx,cx
    rep movsb
    pop ds
    inc word ptr ds:[18F6h]
    mov ax,0FFFFh
lbl100f:
    pop si
    pop di
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
