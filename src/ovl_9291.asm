_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf18:FAR
    EXTRN mf22:FAR
    EXTRN mf31:FAR
    EXTRN mf65:FAR
    EXTRN mf69:FAR
    EXTRN md77:NEAR
    EXTRN mf85:FAR
    EXTRN mf100:FAR
    EXTRN mf100:FAR
    EXTRN mf100:FAR
    EXTRN mf100:FAR
    EXTRN mf100:FAR
    EXTRN mf100:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,1Eh
    mov ax,word ptr ds:[266h]
    cmp word ptr [bp+6h],ax
    jnz short lbl11f
    jmp near ptr lbl110f
lbl11f:
    mov word ptr [bp-14h],0FFFFh
    mov word ptr [bp-18h],0h
    mov word ptr [bp-2h],ax
    or ax,ax
    jz short lbl77f
    lea ax,word ptr [bp-12h]
    mov word ptr [bp-1Ch],ax
lbl28b:
    mov bx,word ptr [bp-1Ch]
    mov ax,word ptr [bp-2h]
    mov word ptr [bx],ax
    push ax
    call mf18
    add sp,2h
    mov word ptr [bp-1Ah],ax
    push word ptr [bp-2h]
    call mf22
    add sp,2h
    mov word ptr [bp-2h],ax
    cmp word ptr [bp-14h],0h
    jnz short lbl6Af
    or ax,ax
    jz short lbl6Af
    push word ptr [bp-1Ah]
    push ax
    call mf31
    add sp,4h
    or ax,ax
    jnz short lbl6Af
    mov ax,word ptr [bp-18h]
    mov word ptr [bp-14h],ax
lbl6Af:
    add word ptr [bp-1Ch],2h
    inc word ptr [bp-18h]
    cmp word ptr [bp-2h],0h
    jnz short lbl28b
lbl77f:
    mov ax,word ptr ds:[256h]
    cmp word ptr [bp+6h],ax
    jnz short lbl82f
    jmp near ptr lbl110f
lbl82f:
    mov ax,word ptr [bp+6h]
    mov word ptr [bp-2h],ax
lbl88b:
    cmp word ptr [bp-2h],0h
    jnz short lbl91f
    jmp near ptr lbl116f
lbl91f:
    mov word ptr [bp-16h],0h
    cmp word ptr [bp-18h],0h
    jz short lblBBf
    lea ax,word ptr [bp-12h]
    mov word ptr [bp-1Eh],ax
lblA2b:
    mov ax,word ptr [bp-2h]
    mov bx,word ptr [bp-1Eh]
    cmp word ptr [bx],ax
    jz short lbl108f
    add word ptr [bp-1Eh],2h
    mov ax,word ptr [bp-18h]
    inc word ptr [bp-16h]
    cmp word ptr [bp-16h],ax
    jc short lblA2b
lblBBf:
    push word ptr [bp-2h]
    call mf65
    add sp,2h
    mov word ptr [bp-1Ah],ax
    push word ptr [bp-2h]
    call mf69
    add sp,2h
    mov bx,ax
    mov word ptr [bp-2h],ax
    add bx,ax
    add bx,ax
    add bx,bx
    mov es, ds:[5A6Eh]
    cmp byte ptr es:[bx+md77],1h
    jnz short lblF1f
    cmp word ptr [bp+8h],0h
    jnz short lbl88b
lblF1f:
    or ax,ax
    jz short lbl88b
    push word ptr [bp-1Ah]
    push ax
    call mf85
    add sp,4h
    or ax,ax
    jnz short lbl88b
    jmp short lbl118f
    nop
lbl108f:
    mov ax,word ptr [bp-14h]
    cmp word ptr [bp-16h],ax
    jnc short lbl116f
lbl110f:
    mov ax,1h
    jmp short lbl118f
    nop
lbl116f:
    xor ax,ax
lbl118f:
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
