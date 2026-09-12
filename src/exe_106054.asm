_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf8:FAR
    EXTRN mf11:FAR
    EXTRN mf22:FAR
    EXTRN mf30:FAR
    EXTRN mf35:FAR
    EXTRN mf37:FAR
    EXTRN mf41:FAR
    EXTRN mf58:FAR
    EXTRN mf63:FAR
    EXTRN mf66:FAR
    EXTRN mf69:FAR
    EXTRN mf75:FAR
    EXTRN mf79:FAR
    EXTRN mf84:FAR
    EXTRN mf86:FAR
    EXTRN mf106:FAR
    EXTRN mf117:FAR
    EXTRN mf123:FAR
    EXTRN mf123:FAR
    EXTRN mf123:FAR
    EXTRN mf123:FAR
    EXTRN mf123:FAR
    EXTRN mf123:FAR
    EXTRN mf123:FAR
    EXTRN mf123:FAR
    EXTRN mf123:FAR
    EXTRN mf123:FAR
    EXTRN mf123:FAR
    EXTRN mf123:FAR
    EXTRN mf123:FAR
    EXTRN mf123:FAR
    EXTRN mf123:FAR
    EXTRN mf123:FAR
    EXTRN mf123:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,1Ch
    push di
    push si
    mov byte ptr [bp-14h],0h
    cmp word ptr [bp+6h],0h
    jl short lbl6Cf
    call mf8
    xor ax,ax
    push ax
    call mf11
    add sp,2h
    mov ax,0C7h
    push ax
    mov ax,13Fh
    push ax
    xor ax,ax
    push ax
    push ax
    mov cx,2h
    push cx
    call mf22
    add sp,0Ah
    xor ax,ax
    push ax
    push word ptr [bp+6h]
    lea ax,word ptr [bp-14h]
    push ss
    push ax
    call mf30
    add sp,8h
    lea ax,word ptr [bp-14h]
    push ss
    push ax
    call mf35
    add sp,4h
    call mf37
    lea ax,word ptr [bp-14h]
    push ss
    push ax
    call mf41
    add sp,4h
lbl6Cf:
    sub ax,ax
    mov word ptr [bp-16h],ax
    mov word ptr [bp-18h],ax
lbl74b:
    mov ax,word ptr [bp+0Ah]
    dec word ptr [bp+0Ah]
    or ax,ax
    jg short lbl81f
    jmp near ptr lbl12Bf
lbl81f:
    mov ax,1h
    push ax
    push word ptr [bp+8h]
    inc word ptr [bp+8h]
    lea ax,word ptr [bp-14h]
    push ss
    push ax
    call mf58
    add sp,8h
    or ax,ax
    jnz short lbl9Ff
    jmp near ptr lbl12Bf
lbl9Fb:
lbl9Ff:
    call mf63
    or ax,ax
    jnz short lbl11Ef
    call mf66
    or ax,ax
    jnz short lbl11Ef
    call mf69
    cmp dx,word ptr [bp-16h]
    jl short lbl9Fb
    jg short lblC2f
    cmp ax,word ptr [bp-18h]
    jc short lbl9Fb
lblC2f:
    call mf75
    lea ax,word ptr [bp-14h]
    push ss
    push ax
    call mf79
    add sp,4h
    lea ax,word ptr [bp-14h]
    push ss
    push ax
    call mf84
    add sp,4h
    call mf86
    mov cx,ax
    mov al,32h
    mov dx,ax
    mul byte ptr [bp-0Ah]
    mov bx,dx
    cwd
    mov si,ax
    mov al,byte ptr [bp-9h]
    mul bl
    mov bx,ax
    inc bx
    mov di,dx
    mov ax,cx
    cwd
    idiv bx
    mov ax,dx
    cwd
    add si,ax
    adc di,dx
    call mf106
    add si,ax
    adc di,dx
    mov word ptr [bp-18h],si
    mov word ptr [bp-16h],di
    jmp near ptr lbl74b
    nop
    nop
lbl11Ef:
    lea ax,word ptr [bp-14h]
    push ss
    push ax
    call mf117
    add sp,4h
lbl12Bf:
    pop si
    pop di
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
