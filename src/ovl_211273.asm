_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
mnem_unit:
    push bp
    mov bp,sp
    sub sp,10h
    push si
    xor ax,ax
    mov word ptr [bp-0Ch],ax
    mov word ptr [bp-2h],ax
    les bx, dword ptr [bp+6h]
    mov al,byte ptr es:[bx+8h]
    cbw
    mov word ptr [bp-6h],ax
lbl1Ab:
    les bx, dword ptr [bp+6h]
    mov al,byte ptr es:[bx+7h]
    cbw
    mov word ptr [bp-8h],ax
    mov word ptr [bp-0Ah],10h
    mov si,word ptr [bp-2h]
    mov al,byte ptr es:[bx+si]
    sub ah,ah
    mov word ptr [bp-10h],ax
    mov word ptr [bp-0Eh],5h
lbl3Ab:
    mov ax,word ptr [bp-0Ah]
    test word ptr [bp-10h],ax
    jz short lbl6Ef
    cmp word ptr [bp-6h],0h
    jnl short lbl4Cf
    or byte ptr [bp-0Ch],4h
lbl4Cf:
    mov ax,word ptr ds:[3212h]
    cmp word ptr [bp-6h],ax
    jl short lbl58f
    or byte ptr [bp-0Ch],40h
lbl58f:
    cmp word ptr [bp-8h],0h
    jnl short lbl62f
    or byte ptr [bp-0Ch],10h
lbl62f:
    mov ax,word ptr ds:[3210h]
    cmp word ptr [bp-8h],ax
    jl short lbl6Ef
    or byte ptr [bp-0Ch],1h
lbl6Ef:
    inc word ptr [bp-8h]
    sar word ptr [bp-0Ah],1
    dec word ptr [bp-0Eh]
    jnz short lbl3Ab
    inc word ptr [bp-6h]
    inc word ptr [bp-2h]
    cmp word ptr [bp-2h],5h
    jl short lbl1Ab
    mov ax,word ptr [bp-0Ch]
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
