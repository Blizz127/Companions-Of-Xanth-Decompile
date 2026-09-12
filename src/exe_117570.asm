_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf8:FAR
    EXTRN mf44:FAR
    EXTRN mf68:FAR
    EXTRN mf77:FAR
    EXTRN mi97:NEAR
    EXTRN mf140:FAR
    EXTRN mf165:FAR
    EXTRN mf165:FAR
    EXTRN mf165:FAR
    EXTRN mf165:FAR
    EXTRN mf165:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,10h
    mov ax,word ptr ds:[6DDAh]
    mov word ptr [bp-2h],ax
    mov word ptr [bp-4h],1h
    push word ptr [bp+8h]
    push word ptr [bp+6h]
    call mf8
    add sp,4h
    mov es,dx
    mov bx,ax
    mov word ptr [bp-0Ch],ax
    mov word ptr [bp-0Ah],es
    cmp byte ptr es:[bx],0h
    jnz short lbl32f
    jmp near ptr lbl1BDf
lbl32b:
lbl32f:
    mov ax,word ptr [bp-0Ch]
    mov word ptr [bp-10h],ax
    mov word ptr [bp-0Eh],es
    mov bx,ax
    cmp byte ptr es:[bx],0h
    jz short lbl6Af
lbl43b:
    mov es, [bp-0Eh]
    cmp byte ptr es:[bx],20h
    jz short lbl6Af
    cmp byte ptr es:[bx],9h
    jz short lbl6Af
    cmp byte ptr es:[bx],0Ah
    jz short lbl6Af
    cmp byte ptr es:[bx],2Dh
    jz short lbl6Af
    inc word ptr [bp-10h]
    mov bx,word ptr [bp-10h]
    cmp byte ptr es:[bx],0h
    jnz short lbl43b
lbl6Af:
    mov es, [bp-0Eh]
    cmp byte ptr es:[bx],2Dh
    jnz short lbl76f
    inc word ptr [bp-10h]
lbl76f:
    push es
    push word ptr [bp-10h]
    push word ptr [bp-0Ah]
    push word ptr [bp-0Ch]
    call mf44
    add sp,8h
    mov word ptr [bp-6h],ax
    mov ax,word ptr [bp+0Eh]
    sub ax,word ptr [bp+0Ah]
    sub ax,word ptr ds:[6DDAh]
    mov word ptr [bp-8h],ax
    sub ax,word ptr ds:[6DDAh]
    cmp ax,word ptr [bp-6h]
    jnl short lblF8f
    mov ax,word ptr [bp-2h]
    sub word ptr [bp-8h],ax
    mov word ptr [bp-6h],0h
    mov ax,word ptr [bp-0Ch]
    mov dx,word ptr [bp-0Ah]
    mov word ptr [bp-10h],ax
    mov word ptr [bp-0Eh],dx
    mov es,dx
    mov bx,ax
    cmp byte ptr es:[bx],0h
    jz short lbl10Cf
lblC2b:
    mov al,byte ptr es:[bx]
    cbw
    push ax
    call mf68
    add sp,2h
    add ax,word ptr [bp-6h]
    cmp ax,word ptr [bp-8h]
    jg short lbl10Cf
    les bx, dword ptr [bp-10h]
    mov al,byte ptr es:[bx]
    cbw
    push ax
    call mf77
    add sp,2h
    add word ptr [bp-6h],ax
    inc word ptr [bp-10h]
    les bx, dword ptr [bp-10h]
    cmp byte ptr es:[bx],0h
    jnz short lblC2b
    jmp short lbl10Cf
lblF8f:
    mov ax,word ptr [bp-8h]
    sub ax,word ptr [bp-2h]
    cmp ax,word ptr [bp-6h]
    jnl short lbl10Cf
    mov ax,word ptr ds:[6DDAh]
    mov word ptr [bp-2h],ax
    inc word ptr [bp-4h]
lbl10Cf:
    mov ax,word ptr [bp-6h]
    add word ptr [bp-2h],ax
    les bx, dword ptr [bp-10h]
    mov al,byte ptr es:[bx]
    cbw
    cmp ax, offset mi97
    jz short lbl176f
    ja short lbl128f
    sub al,9h
    jz short lbl134f
    dec al
    jz short lbl16Af
lbl128f:
    mov ax,bx
    mov word ptr [bp-0Ch],ax
    mov word ptr [bp-0Ah],es
    jmp short lbl1B1f
    nop
    nop
lbl134f:
    mov ax,bx
    inc ax
    mov word ptr [bp-0Ch],ax
    mov word ptr [bp-0Ah],es
    mov ax,word ptr [bp+0Eh]
    sub ax,word ptr [bp-2h]
    sub ax,word ptr [bp+0Ah]
    sub ax,word ptr ds:[6DDAh]
    cmp ax,word ptr ds:[6DFCh]
    jng short lbl1B1f
    mov ax,word ptr [bp-2h]
    sub ax,word ptr ds:[6DDAh]
    cwd
    idiv word ptr ds:[6DFCh]
    inc ax
    imul word ptr ds:[6DFCh]
    add ax,word ptr ds:[6DDAh]
    mov word ptr [bp-2h],ax
    jmp short lbl1B1f
lbl16Af:
    mov ax,bx
    inc ax
    mov word ptr [bp-0Ch],ax
    mov word ptr [bp-0Ah],es
    jmp short lbl1A8f
    nop
lbl176f:
    lea ax,word ptr [bx+1h]
    mov word ptr [bp-0Ch],ax
    mov word ptr [bp-0Ah],es
    mov ax,20h
    push ax
    call mf140
    add sp,2h
    mov word ptr [bp-6h],ax
    mov ax,word ptr [bp+0Eh]
    sub ax,word ptr [bp-2h]
    sub ax,word ptr [bp+0Ah]
    sub ax,word ptr ds:[6DDAh]
    cmp ax,word ptr [bp-6h]
    jl short lbl1A8f
    mov ax,word ptr [bp-6h]
    add word ptr [bp-2h],ax
    jmp short lbl1B1f
lbl1A8f:
    mov ax,word ptr ds:[6DDAh]
    mov word ptr [bp-2h],ax
    inc word ptr [bp-4h]
lbl1B1f:
    les bx, dword ptr [bp-0Ch]
    cmp byte ptr es:[bx],0h
    jz short lbl1BDf
    jmp near ptr lbl32b
lbl1BDf:
    mov ax,word ptr [bp-4h]
    imul word ptr ds:[69F8h]
    add ax,word ptr [bp+0Ch]
    add ax,word ptr ds:[6D48h]
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
