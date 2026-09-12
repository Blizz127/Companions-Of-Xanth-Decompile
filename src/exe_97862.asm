_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf19:FAR
    EXTRN mf30:FAR
    EXTRN mf55:FAR
    EXTRN mf59:FAR
    EXTRN mf59:FAR
    EXTRN mf59:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,16h
    push si
    sub ax,ax
    mov word ptr [bp-0Eh],ax
    mov word ptr [bp-10h],ax
    mov word ptr [bp-12h],ax
    mov cx,word ptr ds:[4DAEh]
    dec cx
    cmp cx,ax
    jng short lbl88f
    mov word ptr [bp-16h],ax
lbl1Eb:
    les bx, dword ptr ds:[63DCh]
    add bx,word ptr [bp-16h]
    push word ptr es:[bx+8h]
    push word ptr es:[bx+6h]
    push word ptr es:[bx+2h]
    push word ptr es:[bx]
    call mf19
    add sp,8h
    mov word ptr [bp-4h],ax
    mov word ptr [bp-2h],dx
    sub ax,ax
    push ax
    push ax
    les bx, dword ptr ds:[63DCh]
    mov si,word ptr [bp-16h]
    push word ptr es:[bx+si+0Eh]
    push word ptr es:[bx+si+0Ch]
    call mf30
    add sp,8h
    sub ax,word ptr [bp-4h]
    sbb dx,word ptr [bp-2h]
    mov cx,word ptr [bp+6h]
    sub bx,bx
    cmp dx,bx
    jl short lbl78f
    jg short lbl72f
    cmp ax,cx
    jc short lbl78f
lbl72f:
    add word ptr [bp-10h],ax
    adc word ptr [bp-0Eh],dx
lbl78f:
    add word ptr [bp-16h],0Ch
    mov ax,word ptr ds:[4DAEh]
    dec ax
    inc word ptr [bp-12h]
    cmp ax,word ptr [bp-12h]
    jg short lbl1Eb
lbl88f:
    mov ax,10h
    cwd
    push dx
    push ax
    push word ptr [bp-0Eh]
    push word ptr [bp-10h]
    call mf55
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
