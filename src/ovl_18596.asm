_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf17:FAR
    EXTRN mf27:FAR
    EXTRN mf34:FAR
    EXTRN mf42:FAR
    EXTRN mf42:FAR
    EXTRN mf42:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,6h
    push si
    mov word ptr [bp-2h],0h
    cmp word ptr ds:[18F6h],0h
    jng short lbl50f
    xor ax,ax
    mov word ptr [bp-4h],ax
    mov word ptr [bp-6h],ax
lbl1Bb:
    les bx, dword ptr ds:[18EEh]
    mov si,word ptr [bp-6h]
    mov word ptr es:[bx+si],0FFFFh
    les bx, dword ptr ds:[18F2h]
    mov si,word ptr [bp-4h]
    push word ptr es:[bx+si+2h]
    push word ptr es:[bx+si]
    call mf17
    add sp,4h
    add word ptr [bp-4h],4h
    add word ptr [bp-6h],2h
    mov ax,word ptr ds:[18F6h]
    inc word ptr [bp-2h]
    cmp word ptr [bp-2h],ax
    jl short lbl1Bb
lbl50f:
    push word ptr ds:[18F0h]
    push word ptr ds:[18EEh]
    call mf27
    add sp,4h
    sub ax,ax
    mov word ptr ds:[18F0h],ax
    mov word ptr ds:[18EEh],ax
    push word ptr ds:[18F4h]
    push word ptr ds:[18F2h]
    call mf34
    add sp,4h
    sub ax,ax
    mov word ptr ds:[18F4h],ax
    mov word ptr ds:[18F2h],ax
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
