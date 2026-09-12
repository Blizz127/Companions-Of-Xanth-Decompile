_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf63:FAR
    EXTRN mf70:FAR
    EXTRN mf84:FAR
    EXTRN mf84:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,0Eh
    push di
    push si
    mov word ptr [bp-2h],0h
    mov word ptr [bp-0Ah],434Ah
lbl12b:
    mov ax,word ptr [bp+6h]
    mov bx,word ptr [bp-0Ah]
    cmp word ptr [bx],ax
    jz short lbl6Af
    inc word ptr [bp-2h]
    add word ptr [bp-0Ah],18h
    cmp word ptr [bp-0Ah],449Ah
    jc short lbl12b
    mov word ptr [bp-0Ch],4360h
lbl2Fb:
    mov bx,word ptr [bp-0Ch]
    cmp word ptr [bx],0h
    jz short lbl39f
    inc word ptr [bx]
lbl39f:
    add word ptr [bp-0Ch],18h
    cmp word ptr [bp-0Ch],44B0h
    jc short lbl2Fb
    xor ax,ax
    mov word ptr [bp-8h],ax
    mov word ptr [bp-6h],ax
    mov word ptr [bp-2h],ax
    mov word ptr [bp-0Eh],4360h
lbl54b:
    mov bx,word ptr [bp-0Eh]
    mov ax,word ptr [bx]
    cmp ax,word ptr [bp-8h]
    jng short lbl80f
    mov word ptr [bp-8h],ax
    mov ax,word ptr [bp-2h]
    mov word ptr [bp-6h],ax
    jmp short lbl84f
    nop
lbl6Af:
    mov ax,18h
    imul word ptr [bp-2h]
    add ax,434Ch
    mov si,ax
    les di, dword ptr [bp+8h]
    mov cx,0Ah
    rep movsw
    jmp short lblDAf
    nop
lbl80f:
    or ax,ax
    jz short lbl94f
lbl84f:
    inc word ptr [bp-2h]
    add word ptr [bp-0Eh],18h
    cmp word ptr [bp-0Eh],44B0h
    jc short lbl54b
    jmp short lbl9Af
lbl94f:
    mov ax,word ptr [bp-2h]
    mov word ptr [bp-6h],ax
lbl9Af:
    mov ax,18h
    imul word ptr [bp-6h]
    mov cx,ax
    add ax,434Ch
    push ds
    push ax
    mov si,ax
    mov di,cx
    call mf63
    add sp,4h
    xor ax,ax
    push ax
    push word ptr [bp+6h]
    push ds
    push si
    call mf70
    add sp,8h
    mov ax,word ptr [bp+6h]
    mov word ptr [di+434Ah],ax
    mov word ptr [di+4360h],1h
    push ds
    les di, dword ptr [bp+8h]
    mov cx,0Ah
    rep movsw
    pop ds
lblDAf:
    pop si
    pop di
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
