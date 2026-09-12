_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf18:FAR
    EXTRN mi31:NEAR
    EXTRN md40:NEAR
    EXTRN mf46:FAR
    EXTRN md67:NEAR
    EXTRN mi69:NEAR
    EXTRN mi84:NEAR
    EXTRN mi89:NEAR
    EXTRN mf92:FAR
    EXTRN mf114:FAR
    EXTRN mf128:FAR
    EXTRN mf134:FAR
    EXTRN mf147:FAR
    EXTRN mf147:FAR
    EXTRN mf147:FAR
    EXTRN mf147:FAR
    EXTRN mf147:FAR
    EXTRN mf147:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,12h
    cmp byte ptr ds:[0EBh],0h
    jz short lbl16f
    mov byte ptr ds:[0EBh],0h
    jmp near ptr lbl1AEf
    nop
lbl16f:
    mov ax,word ptr ds:[0EEh]
    mov word ptr [bp-0Ah],ax
    mov word ptr [bp-2h],0h
    cmp word ptr [bp+8h],0h
    jg short lbl2Af
    jmp near ptr lbl1A8f
lbl2Ab:
lbl2Af:
    mov word ptr [bp-4h],0h
    mov ax,1Bh
    push ax
    push word ptr ds:[256h]
    call mf18
    add sp,4h
    or ax,ax
    jz short lbl48f
    mov word ptr [bp-4h],1h
lbl48f:
    mov word ptr ds:[0EEh],0h
    cmp word ptr ds:[0ECh],0h
    jg short lbl58f
    jmp near ptr lbl152f
lbl58b:
lbl58f:
    mov bx,word ptr ds:[0EEh]
    add bx,bx
    add bx,bx
    mov word ptr [bp-12h],bx
    add bx, offset mi31
    mov es, ds:[5A22h]
    mov word ptr [bp-10h],bx
    mov word ptr [bp-0Eh],es
    cmp word ptr es:[bx],0h
    jng short lbl7Af
    jmp near ptr lbl13Cf
lbl7Af:
    mov bx,word ptr [bp-12h]
    sub ah,ah
    mov al,byte ptr es:[bx+md40]
    mov word ptr [bp-8h],ax
    mov bx,word ptr [bp-10h]
    mov ax,word ptr es:[bx]
    mov word ptr [bp-6h],ax
    push word ptr [bp-8h]
    call mf46
    add sp,2h
    or ax,ax
    jz short lblA2f
    inc word ptr [bp-4h]
lblA2f:
    cmp word ptr ds:[262h],1h
    jng short lblBFf
    mov ax,word ptr ds:[262h]
    cmp word ptr [bp+8h],ax
    jnl short lblB4f
    mov word ptr [bp+8h],ax
lblB4f:
    mov word ptr ds:[262h],1h
    mov word ptr [bp+6h],0h
lblBFf:
    cmp word ptr ds:[0EEh],0h
    jl short lbl142f
    mov al,byte ptr [bp-8h]
    mov es, ds:[5A22h]
    mov bx,word ptr ds:[0EEh]
    add bx,bx
    add bx,bx
    mov word ptr [bp-12h],bx
    cmp byte ptr es:[bx+md67],al
    jnz short lbl142f
    add bx, offset mi69
    mov word ptr [bp-10h],bx
    mov word ptr [bp-0Eh],es
    cmp word ptr es:[bx],0h
    jnz short lbl12Af
    cmp word ptr [bp-6h],0h
    jnz short lbl12Af
    mov ax,word ptr ds:[0ECh]
    sub ax,word ptr ds:[0EEh]
    dec ax
    jz short lbl11Ff
    add ax,ax
    add ax,ax
    push ax
    mov ax,word ptr [bp-12h]
    add ax, offset mi84
    mov cx,3420h
    push cx
    push ax
    mov ax,word ptr [bp-12h]
    add ax, offset mi89
    push cx
    push ax
    call mf92
    add sp,0Ah
lbl11Ff:
    dec word ptr ds:[0ECh]
lbl123b:
    dec word ptr ds:[0EEh]
    jmp short lbl142f
    nop
lbl12Af:
    mov es, [bp-0Eh]
    cmp word ptr es:[bx],0FFFFFFFFFFFFFFFFh
    jz short lbl142f
    cmp word ptr [bp-6h],0h
    jg short lbl142f
    jmp short lbl123b
    nop
lbl13Cf:
    mov es, [bp-0Eh]
    dec word ptr es:[bx]
lbl142f:
    mov ax,word ptr ds:[0ECh]
    inc word ptr ds:[0EEh]
    cmp word ptr ds:[0EEh],ax
    jnl short lbl152f
    jmp near ptr lbl58b
lbl152f:
    mov ax,1h
    push ax
    call mf114
    add sp,2h
    cmp word ptr [bp+6h],0h
    jz short lbl19Af
    mov ax,word ptr [bp-2h]
    inc ax
    cmp ax,word ptr [bp+8h]
    jnl short lbl19Af
    cmp word ptr [bp-4h],0h
    jz short lbl19Af
    cmp byte ptr ds:[0EAh],0h
    jz short lbl1A8f
    mov ax,20h
    push ax
    call mf128
    add sp,2h
    mov ax,18h
    mov cx,21A6h
    push cx
    push ax
    call mf134
    add sp,4h
    or ax,ax
    jz short lbl1A8f
lbl19Af:
    mov ax,word ptr [bp+8h]
    inc word ptr [bp-2h]
    cmp word ptr [bp-2h],ax
    jnl short lbl1A8f
    jmp near ptr lbl2Ab
lbl1A8f:
    mov ax,word ptr [bp-0Ah]
    mov word ptr ds:[0EEh],ax
lbl1AEf:
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
