_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
mnem_unit:
    push bp
    mov bp,sp
    sub sp,0Ch
    push si
    mov word ptr [bp-2h],0h
    les bx, dword ptr [bp+6h]
    mov al,byte ptr es:[bx+8h]
    cbw
    mov word ptr [bp-6h],ax
    mov cx,17h
    imul cx
    mov word ptr [bp-0Ch],ax
lbl1Fb:
    cmp word ptr [bp-0Ch],0h
    jl short lbl81f
    mov ax,word ptr ds:[3212h]
    cmp word ptr [bp-6h],ax
    jnl short lbl81f
    mov word ptr [bp-4h],0h
    les bx, dword ptr [bp+6h]
    mov al,byte ptr es:[bx+7h]
    cbw
    mov word ptr [bp-8h],ax
    mov word ptr [bp-0Ah],10h
lbl42b:
    cmp word ptr [bp-8h],0h
    jl short lbl72f
    mov ax,word ptr ds:[3210h]
    cmp word ptr [bp-8h],ax
    jnl short lbl72f
    les bx, dword ptr [bp+6h]
    mov si,word ptr [bp-2h]
    mov al,byte ptr es:[bx+si]
    sub ah,ah
    test word ptr [bp-0Ah],ax
    jz short lbl72f
    mov es, ds:[5ADEh]
    mov bx,word ptr [bp-8h]
    add bx,word ptr [bp-0Ch]
    test byte ptr es:[bx+4750h],6Fh
    jnz short lbl94f
lbl72f:
    inc word ptr [bp-8h]
    sar word ptr [bp-0Ah],1
    inc word ptr [bp-4h]
    cmp word ptr [bp-4h],5h
    jl short lbl42b
lbl81f:
    add word ptr [bp-0Ch],17h
    inc word ptr [bp-6h]
    inc word ptr [bp-2h]
    cmp word ptr [bp-2h],5h
    jl short lbl1Fb
    jmp short lbl9Af
    nop
lbl94f:
    mov ax,1h
    jmp short lbl9Cf
    nop
lbl9Af:
    xor ax,ax
lbl9Cf:
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
