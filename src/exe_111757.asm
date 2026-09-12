_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
mnem_unit:
    push bp
    mov bp,sp
    sub sp,8h
    push si
    les bx, dword ptr [bp+6h]
    cmp byte ptr es:[bx],3h
    jz short lbl13f
    jmp near ptr lblE8f
lbl13f:
    cmp word ptr es:[bx+0Eh],1h
    jnl short lbl1Df
    jmp near ptr lblE8f
lbl1Df:
    les bx, dword ptr es:[bx+10h]
    mov ax,word ptr es:[bx]
    les bx, dword ptr [bp+6h]
    mov word ptr es:[bx+2h],ax
    les bx, dword ptr es:[bx+10h]
    mov ax,word ptr es:[bx+2h]
    les bx, dword ptr [bp+6h]
    mov word ptr es:[bx+4h],ax
    les bx, dword ptr es:[bx+10h]
    mov ax,word ptr es:[bx]
    les bx, dword ptr [bp+6h]
    mov word ptr es:[bx+6h],ax
    les bx, dword ptr es:[bx+10h]
    mov ax,word ptr es:[bx+2h]
    les bx, dword ptr [bp+6h]
    mov word ptr es:[bx+8h],ax
    mov word ptr [bp-2h],1h
    cmp word ptr es:[bx+0Eh],1h
    jg short lbl66f
    jmp near ptr lblE8f
lbl66f:
    mov word ptr [bp-4h],4h
lbl6Bb:
    les bx, dword ptr [bp+6h]
    les bx, dword ptr es:[bx+10h]
    mov si,word ptr [bp-4h]
    mov ax,word ptr es:[bx+si]
    les bx, dword ptr [bp+6h]
    cmp ax,word ptr es:[bx+2h]
    jnl short lbl85f
    mov word ptr es:[bx+2h],ax
lbl85f:
    les bx, dword ptr [bp+6h]
    les bx, dword ptr es:[bx+10h]
    mov si,word ptr [bp-4h]
    mov ax,word ptr es:[bx+si+2h]
    les bx, dword ptr [bp+6h]
    cmp ax,word ptr es:[bx+4h]
    jnl short lblA0f
    mov word ptr es:[bx+4h],ax
lblA0f:
    les bx, dword ptr [bp+6h]
    les bx, dword ptr es:[bx+10h]
    mov si,word ptr [bp-4h]
    mov ax,word ptr es:[bx+si]
    les bx, dword ptr [bp+6h]
    cmp ax,word ptr es:[bx+6h]
    jng short lblBAf
    mov word ptr es:[bx+6h],ax
lblBAf:
    les bx, dword ptr [bp+6h]
    les bx, dword ptr es:[bx+10h]
    mov si,word ptr [bp-4h]
    mov ax,word ptr es:[bx+si+2h]
    les bx, dword ptr [bp+6h]
    cmp ax,word ptr es:[bx+8h]
    jng short lblD5f
    mov word ptr es:[bx+8h],ax
lblD5f:
    add word ptr [bp-4h],4h
    inc word ptr [bp-2h]
    mov ax,word ptr [bp-2h]
    les bx, dword ptr [bp+6h]
    cmp word ptr es:[bx+0Eh],ax
    jg short lbl6Bb
lblE8f:
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
