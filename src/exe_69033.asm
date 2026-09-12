_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi2:NEAR
    EXTRN mi10:NEAR
    EXTRN mi13:NEAR
    EXTRN mf22:FAR
    EXTRN mf27:FAR
    EXTRN mf46:FAR
    EXTRN mf51:FAR
    EXTRN mf56:FAR
    EXTRN mf83:FAR
    EXTRN mf93:FAR
    EXTRN mf120:FAR
    EXTRN mf130:FAR
    EXTRN mf136:FAR
    EXTRN mf146:FAR
    EXTRN mi150:NEAR
    EXTRN mi153:NEAR
    EXTRN mi156:NEAR
    EXTRN mi159:NEAR
    EXTRN mi162:NEAR
    EXTRN mf174:FAR
    EXTRN mf174:FAR
    EXTRN mf174:FAR
    EXTRN mf174:FAR
    EXTRN mf174:FAR
    EXTRN mf174:FAR
    EXTRN mf174:FAR
    EXTRN mf174:FAR
    EXTRN mf174:FAR
    EXTRN mf174:FAR
    EXTRN mf174:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp, offset mi2
    push si
    push di
    mov ax,word ptr [bp+6h]
    shr ax,1
    shr ax,1
    shr ax,1
    shr ax,1
    and ax, offset mi10
    mov word ptr [bp-4h],ax
    mov ax,word ptr [bp+6h]
    and ax, offset mi13
    mov word ptr [bp-6h],ax
    cmp word ptr [bp-6h],0Bh
    jl short lbl2Cf
    jmp near ptr lbl1D9f
lbl2Cf:
    mov ax,word ptr [bp-4h]
    jmp near ptr lbl1A1f
lbl32b:
    mov ax,word ptr [bp-6h]
    push ax
    call mf22
    add sp,2h
    jmp near ptr lbl1CCf
lbl41b:
    mov ax,1h
    push ax
    call mf27
    add sp,2h
    and ax,0FFh
    mov word ptr [bp-0Ah],ax
    mov ax,word ptr ds:[4168h]
    imul word ptr ds:[27Eh]
    mov cx,7Fh
    cwd
    idiv cx
    mov cx,ax
    mov ax,word ptr [bp-0Ah]
    imul cx
    mov cx,7Fh
    cwd
    idiv cx
    mov word ptr [bp-8h],ax
    push word ptr [bp-8h]
    mov ax,0h
    push ax
    call mf46
    add sp,2h
    and ax,0FFh
    push ax
    push word ptr [bp-6h]
    call mf51
    add sp,6h
    jmp near ptr lbl1CCf
lbl91b:
    mov ax,1h
    push ax
    call mf56
    add sp,2h
    and ax,0FFh
    mov word ptr [bp-0Ah],ax
    mov ax,word ptr ds:[4168h]
    imul word ptr ds:[27Eh]
    mov cx,7Fh
    cwd
    idiv cx
    mov cx,ax
    mov ax,word ptr [bp-0Ah]
    imul cx
    mov cx,7Fh
    cwd
    idiv cx
    mov word ptr [bp-8h],ax
    mov bx,word ptr [bp-6h]
    shl bx,1
    mov ax,word ptr [bp-8h]
    mov es, ds:[5B38h]
    cmp word ptr es:[bx+48D8h],ax
    jnz short lblD6f
    jmp near ptr lblF7f
lblD6f:
    mov ax,word ptr [bp-8h]
    push ax
    mov ax,word ptr [bp-6h]
    push ax
    call mf83
    add sp,4h
    mov bx,word ptr [bp-6h]
    shl bx,1
    mov ax,word ptr [bp-8h]
    mov es, ds:[5B38h]
    mov word ptr es:[bx+48D8h],ax
lblF7f:
    jmp near ptr lbl1CCf
lblFAb:
    mov ax,0h
    push ax
    call mf93
    add sp,2h
    and ax,0FFh
    mov word ptr [bp-0Ah],ax
    mov ax,word ptr ds:[4168h]
    imul word ptr ds:[27Eh]
    mov cx,7Fh
    cwd
    idiv cx
    mov cx,ax
    mov ax,word ptr [bp-0Ah]
    imul cx
    mov cx,7Fh
    cwd
    idiv cx
    mov word ptr [bp-8h],ax
    mov bx,word ptr [bp-6h]
    shl bx,1
    mov ax,word ptr [bp-8h]
    mov es, ds:[5B38h]
    cmp word ptr es:[bx+48D8h],ax
    jnz short lbl13Ff
    jmp near ptr lbl160f
lbl13Ff:
    mov ax,word ptr [bp-8h]
    push ax
    mov ax,word ptr [bp-6h]
    push ax
    call mf120
    add sp,4h
    mov bx,word ptr [bp-6h]
    shl bx,1
    mov ax,word ptr [bp-8h]
    mov es, ds:[5B38h]
    mov word ptr es:[bx+48D8h],ax
lbl160f:
    jmp near ptr lbl1CCf
lbl163b:
    mov ax,0h
    push ax
    call mf130
    add sp,2h
    and ax,0FFh
    mov word ptr [bp-0Ah],ax
    mov ax,1h
    push ax
    call mf136
    add sp,2h
    and ax,0FFh
    mov cx,7h
    shl ax,cl
    mov cx,word ptr [bp-0Ah]
    or ax,cx
    push ax
    mov ax,word ptr [bp-6h]
    push ax
    call mf146
    add sp,4h
    jmp near ptr lbl1CCf
    jmp near ptr lbl1CCf
lbl1A1f:
    cmp ax, offset mi150
    jnz short lbl1A9f
    jmp near ptr lbl32b
lbl1A9f:
    cmp ax, offset mi153
    jnz short lbl1B1f
    jmp near ptr lbl41b
lbl1B1f:
    cmp ax, offset mi156
    jnz short lbl1B9f
    jmp near ptr lbl91b
lbl1B9f:
    cmp ax, offset mi159
    jnz short lbl1C1f
    jmp near ptr lblFAb
lbl1C1f:
    cmp ax, offset mi162
    jnz short lbl1C9f
    jmp near ptr lbl163b
lbl1C9f:
    jmp near ptr lbl1CCf
lbl1CCf:
    mov bx,word ptr [bp-4h]
    shl bx,1
    mov ax,word ptr [bx+40FAh]
    add word ptr ds:[627Ch],ax
lbl1D9f:
    pop di
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
