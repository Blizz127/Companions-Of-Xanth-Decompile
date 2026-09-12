_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf8:FAR
    EXTRN mf25:FAR
    EXTRN mf40:FAR
    EXTRN mf44:FAR
    EXTRN mf66:FAR
    EXTRN mf70:FAR
    EXTRN mf85:FAR
    EXTRN mf114:FAR
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
    sub sp,4h
    push si
    xor si,si
    mov ax,57ECh
    push ds
    push ax
    call mf8
    add sp,4h
    mov word ptr [bp-4h],ax
    mov word ptr [bp-2h],dx
    or dx,ax
    jnz short lbl23f
    jmp near ptr lbl144f
lbl23f:
    les bx, dword ptr [bp-4h]
    cmp byte ptr es:[bx],0h
    jnz short lbl2Ff
    jmp near ptr lbl144f
lbl2Ff:
    mov ax,3h
    push ax
    push es
    push bx
    push word ptr ds:[5800h]
    push word ptr ds:[57FEh]
    call mf25
    add sp,0Ah
    add word ptr [bp-4h],3h
    les bx, dword ptr [bp-4h]
    cmp byte ptr es:[bx],2Dh
    jnz short lbl59f
    inc si
    lea ax,word ptr [bx+1h]
    mov word ptr [bp-4h],ax
lbl59f:
    mov ax,0E10h
    cwd
    push dx
    push ax
    push es
    push word ptr [bp-4h]
    call mf40
    add sp,4h
    push dx
    push ax
    call mf44
    mov word ptr ds:[57F0h],ax
    mov word ptr ds:[57F2h],dx
lbl79b:
    les bx, dword ptr [bp-4h]
    cmp byte ptr es:[bx],2Bh
    jz short lbl8Ef
    cmp byte ptr es:[bx],30h
    jl short lbl94f
    cmp byte ptr es:[bx],39h
    jg short lbl94f
lbl8Ef:
    inc word ptr [bp-4h]
    jmp short lbl79b
    nop
lbl94f:
    cmp byte ptr es:[bx],3Ah
    jnz short lbl104f
    mov ax,3Ch
    cwd
    push dx
    push ax
    inc word ptr [bp-4h]
    push es
    push word ptr [bp-4h]
    call mf66
    add sp,4h
    push dx
    push ax
    call mf70
    add word ptr ds:[57F0h],ax
    adc word ptr ds:[57F2h],dx
    jmp short lblC9f
lblC0b:
    cmp byte ptr es:[bx],39h
    jg short lblD2f
    inc word ptr [bp-4h]
lblC9f:
    les bx, dword ptr [bp-4h]
    cmp byte ptr es:[bx],30h
    jnl short lblC0b
lblD2f:
    cmp byte ptr es:[bx],3Ah
    jnz short lbl104f
    inc word ptr [bp-4h]
    push es
    push word ptr [bp-4h]
    call mf85
    add sp,4h
    add word ptr ds:[57F0h],ax
    adc word ptr ds:[57F2h],dx
    jmp short lblFBf
    nop
lblF2b:
    cmp byte ptr es:[bx],39h
    jg short lbl104f
    inc word ptr [bp-4h]
lblFBf:
    les bx, dword ptr [bp-4h]
    cmp byte ptr es:[bx],30h
    jnl short lblF2b
lbl104f:
    or si,si
    jz short lbl115f
    neg word ptr ds:[57F0h]
    adc word ptr ds:[57F2h],0h
    neg word ptr ds:[57F2h]
lbl115f:
    les bx, dword ptr [bp-4h]
    mov al,byte ptr es:[bx]
    cbw
    mov word ptr ds:[57F4h],ax
    or ax,ax
    jz short lbl13Cf
    mov ax,3h
    push ax
    push es
    push bx
    push word ptr ds:[5804h]
    push word ptr ds:[5802h]
    call mf114
    add sp,0Ah
    jmp short lbl144f
    nop
lbl13Cf:
    les bx, dword ptr ds:[5802h]
    mov byte ptr es:[bx],0h
lbl144f:
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
