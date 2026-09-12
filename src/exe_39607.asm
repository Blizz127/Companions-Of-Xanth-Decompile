_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf12:FAR
    EXTRN mi22:NEAR
    EXTRN mf39:FAR
    EXTRN mf45:FAR
    EXTRN mf51:FAR
    EXTRN mf56:FAR
    EXTRN mf68:FAR
    EXTRN mf81:FAR
    EXTRN mf106:FAR
    EXTRN mf106:FAR
    EXTRN mf106:FAR
    EXTRN mf106:FAR
    EXTRN mf106:FAR
    EXTRN mf106:FAR
    EXTRN mf106:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,8h
    push di
    push si
    mov word ptr [bp-2h],1h
    lea ax,word ptr [bp-6h]
    push ss
    push ax
    lea ax,word ptr [bp-4h]
    push ss
    push ax
    call mf12
    add sp,8h
    mov word ptr [bp-8h],ax
    test word ptr [bp+6h],3F0h
    jz short lbl60f
    mov ax,word ptr ds:[72h]
    cmp word ptr ds:[74h],ax
    jz short lbl60f
    mov cl,3h
    shl ax,cl
    add ax, offset mi22
    mov cx,2199h
    push ds
    mov si,ax
    mov ds,cx
    les di, dword ptr [bp+8h]
    movsw
    movsw
    movsw
    movsw
    pop ds
    inc word ptr ds:[72h]
    cmp word ptr ds:[72h],4h
    jnc short lbl57f
    jmp near ptr lbl11Bf
lbl57f:
    mov word ptr ds:[72h],0h
    jmp near ptr lbl11Bf
lbl60f:
    call mf39
    or ax,ax
    jz short lbl80f
    push word ptr [bp+0Ah]
    push word ptr [bp+8h]
    push word ptr [bp+6h]
    call mf45
    add sp,6h
    mov word ptr [bp-2h],ax
    jmp near ptr lbl11Bf
lbl80f:
    test byte ptr [bp+6h],1h
    jz short lblA6f
    call mf51
    or ax,ax
    jz short lblA6f
    les bx, dword ptr [bp+8h]
    mov word ptr es:[bx],1h
    call mf56
    les bx, dword ptr [bp+8h]
lbl9Fb:
    mov word ptr es:[bx+6h],ax
    jmp short lbl11Bf
    nop
lblA6f:
    test byte ptr [bp+6h],4h
    jz short lblE0f
    cmp word ptr [bp-8h],0h
    jz short lblE0f
    cmp word ptr ds:[76h],0h
    jnz short lblE0f
    push word ptr [bp-8h]
    call mf68
    add sp,2h
    les bx, dword ptr [bp+8h]
    mov word ptr es:[bx],4h
lblCCb:
    mov ax,word ptr [bp-4h]
    mov word ptr es:[bx+2h],ax
    mov ax,word ptr [bp-6h]
    mov word ptr es:[bx+4h],ax
    mov ax,word ptr [bp-8h]
    jmp short lbl9Fb
    nop
lblE0f:
    test byte ptr [bp+6h],2h
    jz short lblFAf
    call mf81
    or ax,ax
    jz short lblFAf
    les bx, dword ptr [bp+8h]
    mov word ptr es:[bx],2h
    jmp short lblCCb
    nop
lblFAf:
    test byte ptr [bp+6h],8h
    jz short lbl110f
    cmp word ptr [bp-8h],0h
    jnz short lbl110f
    les bx, dword ptr [bp+8h]
    mov word ptr es:[bx],8h
    jmp short lblCCb
lbl110f:
    xor ax,ax
    mov word ptr [bp-2h],ax
    les bx, dword ptr [bp+8h]
    mov word ptr es:[bx],ax
lbl11Bf:
    mov ax,word ptr [bp-8h]
    mov word ptr ds:[76h],ax
    mov ax,word ptr [bp-2h]
    pop si
    pop di
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
