_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf19:FAR
    EXTRN mf33:FAR
    EXTRN mf50:FAR
    EXTRN mf50:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,6h
    push si
    mov word ptr [bp-4h],0FFFFh
    mov word ptr [bp-2h],0h
    cmp word ptr ds:[18F6h],0h
    jng short lbl8Af
    mov word ptr [bp-6h],0h
lbl1Db:
    cmp word ptr [bp+0Ah],0h
    jnz short lbl52f
    cmp word ptr [bp-4h],0h
    jnl short lbl52f
    push word ptr [bp+8h]
    push word ptr [bp+6h]
    les bx, dword ptr ds:[18F2h]
    mov si,word ptr [bp-6h]
    push word ptr es:[bx+si+2h]
    push word ptr es:[bx+si]
    call mf19
    add sp,8h
    or ax,ax
    jz short lbl52f
    mov ax,word ptr [bp-2h]
    mov word ptr [bp-4h],ax
    jmp short lbl72f
    nop
lbl52f:
    push word ptr [bp+8h]
    push word ptr [bp+6h]
    les bx, dword ptr ds:[18F2h]
    mov si,word ptr [bp-6h]
    push word ptr es:[bx+si+2h]
    push word ptr es:[bx+si]
    call mf33
    add sp,8h
    or ax,ax
    jz short lbl84f
lbl72f:
    add word ptr [bp-6h],4h
    mov ax,word ptr ds:[18F6h]
    inc word ptr [bp-2h]
    cmp word ptr [bp-2h],ax
    jl short lbl1Db
    jmp short lbl8Af
    nop
lbl84f:
    mov ax,word ptr [bp-2h]
    mov word ptr [bp-4h],ax
lbl8Af:
    mov ax,word ptr [bp-4h]
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
