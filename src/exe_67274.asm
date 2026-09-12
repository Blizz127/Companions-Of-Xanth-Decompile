_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi2:NEAR
    EXTRN mi13:NEAR
    EXTRN mi28:NEAR
    EXTRN mi43:NEAR
    EXTRN mi58:NEAR
    EXTRN mi73:NEAR
    EXTRN mi81:NEAR
    EXTRN mf83:FAR
    EXTRN mf89:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp, offset mi2
    push si
    push di
    mov ax,0Eh
    imul word ptr [bp+6h]
    mov bx,0h
    mov cx,2E8Eh
    add bx,ax
    mov es,cx
    mov al,byte ptr es:[bx+9h]
    cbw
    cmp ax, offset mi13
    jnz short lbl26f
    jmp near ptr lbl2Cf
lbl26f:
    mov ax,80h
    jmp near ptr lbl2Ff
lbl2Cf:
    mov ax,0h
lbl2Ff:
    mov word ptr [bp-4h],ax
    mov ax,0Eh
    imul word ptr [bp+6h]
    mov bx,0h
    mov cx,2E8Eh
    add bx,ax
    mov es,cx
    mov al,byte ptr es:[bx+0Ah]
    cbw
    cmp ax, offset mi28
    jnz short lbl4Ff
    jmp near ptr lbl55f
lbl4Ff:
    mov ax,40h
    jmp near ptr lbl58f
lbl55f:
    mov ax,0h
lbl58f:
    add word ptr [bp-4h],ax
    mov ax,0Eh
    imul word ptr [bp+6h]
    mov bx,0h
    mov cx,2E8Eh
    add bx,ax
    mov es,cx
    mov al,byte ptr es:[bx+5h]
    cbw
    cmp ax, offset mi43
    jnz short lbl78f
    jmp near ptr lbl7Ef
lbl78f:
    mov ax,20h
    jmp near ptr lbl81f
lbl7Ef:
    mov ax,0h
lbl81f:
    add word ptr [bp-4h],ax
    mov ax,0Eh
    imul word ptr [bp+6h]
    mov bx,0h
    mov cx,2E8Eh
    add bx,ax
    mov es,cx
    mov al,byte ptr es:[bx+0Bh]
    cbw
    cmp ax, offset mi58
    jnz short lblA1f
    jmp near ptr lblA7f
lblA1f:
    mov ax,10h
    jmp near ptr lblAAf
lblA7f:
    mov ax,0h
lblAAf:
    add word ptr [bp-4h],ax
    mov ax,0Eh
    imul word ptr [bp+6h]
    mov bx,0h
    mov cx,2E8Eh
    add bx,ax
    mov es,cx
    mov al,byte ptr es:[bx+1h]
    cbw
    and ax, offset mi73
    add word ptr [bp-4h],ax
    mov ax,word ptr [bp-4h]
    push ax
    mov bx,word ptr [bp+6h]
    mov es, ds:[5B36h]
    mov al,byte ptr es:[bx+194h]
    cbw
    add ax, offset mi81
    push ax
    call mf83
    add sp,4h
    pop di
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
