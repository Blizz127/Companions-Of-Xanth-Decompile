_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN md10:NEAR
    EXTRN mi14:NEAR
    EXTRN mf32:FAR
    EXTRN mf39:FAR
    EXTRN mf46:FAR
    EXTRN mf53:FAR
    EXTRN mf60:FAR
    EXTRN mf69:FAR
    EXTRN mf69:FAR
    EXTRN mf69:FAR
    EXTRN mf69:FAR
    EXTRN mf69:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,2h
    mov es, ds:[5A40h]
    mov bx,word ptr [bp+6h]
    mov ax,bx
    add bx,bx
    add bx,ax
    add bx,bx
    sub ah,ah
    mov al,byte ptr es:[bx+md10]
    mov word ptr [bp-2h],ax
    dec ax
    jz short lblA0f
    sub ax, offset mi14
    jz short lblA0f
    mov ax,word ptr [bp+8h]
    or ax,ax
    jz short lblA0f
    dec ax
    jnz short lbl9Cf
    mov ax,word ptr [bp-2h]
    dec ax
    dec ax
    jz short lbl3Ef
    dec ax
    jz short lbl50f
    jmp short lbl9Cf
    nop
lbl3Ef:
    mov ax,0Bh
    push ax
    push word ptr [bp+6h]
    call mf32
    add sp,4h
    jmp short lblA3f
    nop
lbl50f:
    mov ax,11h
    push ax
    push word ptr [bp+6h]
    call mf39
    add sp,4h
    or ax,ax
    jz short lbl89f
    mov ax,0Eh
    push ax
    push word ptr [bp+6h]
    call mf46
    add sp,4h
    or ax,ax
    jnz short lblA0f
    mov ax,0Dh
    push ax
    push word ptr [bp+6h]
    call mf53
    add sp,4h
    or ax,ax
    jnz short lblA0f
lbl89f:
    mov ax,0Bh
    push ax
    push word ptr [bp+6h]
    call mf60
    add sp,4h
    or ax,ax
    jnz short lblA0f
lbl9Cf:
    xor ax,ax
    jmp short lblA3f
lblA0f:
    mov ax,1h
lblA3f:
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
