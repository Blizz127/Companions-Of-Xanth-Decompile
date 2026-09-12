_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf4:FAR
    EXTRN mf11:FAR
    EXTRN mf26:FAR
    EXTRN mf45:FAR
    EXTRN mf72:FAR
    EXTRN mf74:FAR
    EXTRN mf75:FAR
    EXTRN mf80:FAR
    EXTRN mf84:FAR
    EXTRN mf106:FAR
    EXTRN mf110:FAR
    EXTRN mf116:FAR
    EXTRN mf121:FAR
    EXTRN mf126:FAR
    EXTRN mf128:FAR
    EXTRN mf131:FAR
    EXTRN mf135:FAR
    EXTRN mf141:FAR
    EXTRN mf142:FAR
    EXTRN mf146:FAR
    EXTRN mf146:FAR
    EXTRN mf146:FAR
    EXTRN mf146:FAR
    EXTRN mf146:FAR
    EXTRN mf146:FAR
    EXTRN mf146:FAR
    EXTRN mf146:FAR
    EXTRN mf146:FAR
    EXTRN mf146:FAR
    EXTRN mf146:FAR
    EXTRN mf146:FAR
    EXTRN mf146:FAR
    EXTRN mf146:FAR
    EXTRN mf146:FAR
    EXTRN mf146:FAR
    EXTRN mf146:FAR
    EXTRN mf146:FAR
    EXTRN mf146:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,414h
    push si
    call mf4
    mov word ptr [bp-14h],ax
    cmp ax,1000h
    jc short lbl18f
    jmp near ptr lbl189f
lbl18f:
    mov ax,1h
    push ax
    call mf11
    add sp,2h
    mov ax,1000h
    sub ax,word ptr [bp-14h]
    sub dx,dx
    add ax,ax
    adc dx,dx
    add ax,ax
    adc dx,dx
    add ax,ax
    adc dx,dx
    add ax,ax
    adc dx,dx
    push dx
    push ax
    call mf26
    add sp,4h
    push dx
    push ax
    cmp word ptr [bp-14h],800h
    jnc short lbl58f
    mov ax,156h
    mov dx,311Fh
    jmp short lbl5Ef
    nop
lbl58f:
    mov ax,1Ch
    mov dx,311Fh
lbl5Ef:
    mov word ptr [bp-4h],ax
    mov word ptr [bp-2h],dx
    push dx
    push ax
    lea ax,word ptr [bp-414h]
    push ss
    push ax
    call mf45
    add sp,0Ch
    xor ax,ax
    mov word ptr [bp-6h],ax
    mov word ptr [bp-0Ah],ax
    mov word ptr [bp-10h],ax
    mov word ptr [bp-12h],ax
    cmp byte ptr [bp-414h],al
    jz short lblB8f
lbl88b:
    mov si,word ptr [bp-6h]
    cmp byte ptr [bp+si-414h],0Ah
    jnz short lblA8f
    mov ax,word ptr [bp-0Ah]
    cmp word ptr [bp-10h],ax
    jnl short lbl9Df
    mov word ptr [bp-10h],ax
lbl9Df:
    mov word ptr [bp-0Ah],0h
    inc word ptr [bp-12h]
    jmp short lblABf
    nop
lblA8f:
    inc word ptr [bp-0Ah]
lblABf:
    inc word ptr [bp-6h]
    mov si,word ptr [bp-6h]
    cmp byte ptr [bp+si-414h],0h
    jnz short lbl88b
lblB8f:
    add word ptr [bp-10h],2h
    add word ptr [bp-12h],2h
    call mf72
    mov byte ptr ds:[1766h],1h
    call mf74
    call mf75
    mov ax,0Ah
    push ax
    xor cx,cx
    push cx
    call mf80
    add sp,4h
    mov ax,0Ah
    push ax
    call mf84
    add sp,2h
    mov ax,4h
    push ax
    mov ax,19h
    sub ax,word ptr [bp-12h]
    cwd
    sub ax,dx
    sar ax,1
    mov cx,ax
    add ax,word ptr [bp-12h]
    push ax
    mov ax,28h
    sub ax,word ptr [bp-10h]
    cwd
    sub ax,dx
    sar ax,1
    mov dx,ax
    add ax,word ptr [bp-10h]
    push ax
    push cx
    push dx
    call mf106
    add sp,8h
    mov word ptr [bp-0Ah],ax
    push ax
    call mf110
    add sp,4h
    mov ax,0Ah
    push ax
    xor ax,ax
    push ax
    call mf116
    add sp,4h
    lea ax,word ptr [bp-414h]
    push ss
    push ax
    call mf121
    add sp,4h
    xor ax,ax
    push ax
    push ax
    call mf126
    add sp,4h
    call mf128
    mov word ptr [bp-8h],ax
    push word ptr [bp-0Ah]
    call mf131
    add sp,2h
    xor ax,ax
    push ax
    call mf135
    add sp,2h
    cmp word ptr [bp-8h],1Bh
    jz short lbl17Ff
    cmp word ptr [bp-14h],800h
    jnc short lbl184f
lbl17Ff:
    call mf141
lbl184f:
    call mf142
lbl189f:
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
