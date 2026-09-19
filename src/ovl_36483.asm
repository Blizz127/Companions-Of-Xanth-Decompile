_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf2f:FAR
    EXTRN mf66:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,8h
    push di
    push si
    mov bx,1396h
    mov es, ds:[5A8Eh]
    mov word ptr [bp-8h],bx
    mov word ptr [bp-6h],es
    mov byte ptr es:[bx],0h
    cmp byte ptr ds:[304h],0h
    jz short lbl2Af
    mov ax,5h
    mov dx,0F036h
    push dx
    jmp short lbl2Ef
    nop
lbl2Af:
    mov ax,1B5Ah
    push ds
lbl2Ef:
    push ax
    call mf2f
    add sp,4h
    mov word ptr [bp-4h],ax
    mov word ptr [bp-2h],dx
    les di, dword ptr [bp-4h]
    push ds
    lds si, dword ptr [bp-8h]
    mov cx,0FFFFh
    xor ax,ax
    repne scasb
    not cx
    sub di,cx
    db 87h, 0FEh ; override
    push ds
    push es
    pop ds
    pop es
    shr cx,1
    rep movsw
    adc cx,cx
    rep movsb
    pop ds
    mov ax,6h
    mov dx,0F036h
    push dx
    push ax
    call mf66
    add sp,4h
    mov di,ax
    mov es,dx
    push ds
    lds si, dword ptr [bp-8h]
    mov cx,0FFFFh
    xor ax,ax
    repne scasb
    not cx
    sub di,cx
    mov bx,cx
    db 87h, 0FEh ; override
    push ds
    push dx
    pop ds
    pop es
    mov cx,0FFFFh
    repne scasb
    dec di
    mov cx,bx
    shr cx,1
    rep movsw
    adc cx,cx
    rep movsb
    pop ds
    mov byte ptr ds:[304h],1h
    mov ax,word ptr [bp-8h]
    mov dx,word ptr [bp-6h]
    pop si
    pop di
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
