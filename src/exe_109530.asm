_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf45:FAR
    EXTRN mf78:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,20h
    push di
    push si
    mov ax,0FFFFh
    les bx, dword ptr [bp+0Ah]
    mov word ptr es:[bx],ax
    les bx, dword ptr [bp+0Eh]
    mov word ptr es:[bx],ax
    xor ax,ax
    mov word ptr [bp-1Ah],ax
    les bx, dword ptr [bp+12h]
    mov word ptr es:[bx],ax
    mov word ptr [bp-16h],ax
    cmp word ptr ds:[51DEh],ax
    jg short lbl2Ef
    jmp near ptr lblCAf
lbl2Ef:
    mov word ptr [bp-1Eh],67C2h
    mov word ptr [bp-20h],67E2h
lbl38b:
    mov word ptr [bp-18h],0h
    mov bx,word ptr [bp-20h]
    cmp word ptr [bx],0h
    jng short lblB4f
    mov word ptr [bp-1Ch],0h
lbl4Ab:
    mov bx,word ptr [bp-1Eh]
    mov ax,word ptr [bx]
    mov dx,word ptr [bx+2h]
    add ax,word ptr [bp-1Ch]
    push ds
    lea di,word ptr [bp-14h]
    mov si,ax
    push ss
    pop es
    mov ds,dx
    mov cx,0Ah
    rep movsw
    pop ds
    test byte ptr [bp-13h],80h
    jnz short lblA3f
    push word ptr [bp+8h]
    push word ptr [bp+6h]
    lea ax,word ptr [bp-14h]
    push ss
    push ax
    call mf45
    add sp,8h
    or ax,ax
    jz short lblA3f
    mov al,byte ptr [bp-14h]
    cbw
    les bx, dword ptr [bp+12h]
    mov word ptr es:[bx],ax
    mov ax,word ptr [bp-18h]
    les bx, dword ptr [bp+0Eh]
    mov word ptr es:[bx],ax
    mov ax,word ptr [bp-16h]
    les bx, dword ptr [bp+0Ah]
    mov word ptr es:[bx],ax
    mov word ptr [bp-1Ah],1h
lblA3f:
    add word ptr [bp-1Ch],14h
    mov bx,word ptr [bp-20h]
    mov ax,word ptr [bx]
    inc word ptr [bp-18h]
    cmp word ptr [bp-18h],ax
    jl short lbl4Ab
lblB4f:
    add word ptr [bp-1Eh],4h
    add word ptr [bp-20h],2h
    mov ax,word ptr ds:[51DEh]
    inc word ptr [bp-16h]
    cmp word ptr [bp-16h],ax
    jnl short lblCAf
    jmp near ptr lbl38b
lblCAf:
    mov ax,word ptr [bp-1Ah]
    pop si
    pop di
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
