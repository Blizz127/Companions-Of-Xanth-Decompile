_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
mnem_unit:
    push bp
    mov bp,sp
    sub sp,0Eh
    push si
    sub ax,ax
    mov word ptr [bp-8h],ax
    mov word ptr [bp-0Ah],ax
    mov word ptr [bp-6h],ax
    mov ax,word ptr ds:[4DAEh]
    inc ax
    or ax,ax
    jng short lbl97f
    mov ax,word ptr ds:[63DCh]
    mov dx,word ptr ds:[63DEh]
    mov word ptr [bp-0Eh],ax
    mov word ptr [bp-0Ch],dx
lbl27b:
    les bx, dword ptr [bp-0Eh]
    mov word ptr [bp-4h],bx
    mov word ptr [bp-2h],es
    test byte ptr es:[bx+0Ah],80h
    jz short lbl59f
    test byte ptr es:[bx+0Ah],10h
    jnz short lbl59f
    test byte ptr es:[bx+0Ah],20h
    jz short lbl59f
    mov bl,byte ptr es:[bx+0Bh]
    sub bh,bh
    add bx,bx
    add bx,bx
    mov ax,word ptr [bx+63EAh]
    or ax,word ptr [bx+63E8h]
    jnz short lbl6Cf
lbl59f:
    add word ptr [bp-0Eh],0Ch
    mov ax,word ptr ds:[4DAEh]
    inc ax
    inc word ptr [bp-6h]
    cmp ax,word ptr [bp-6h]
    jg short lbl27b
    jmp short lbl97f
    nop
lbl6Cf:
    les bx, dword ptr [bp-4h]
    sub ah,ah
    mov al,byte ptr es:[bx+0Bh]
    les bx, dword ptr [bp+0Ah]
    mov word ptr es:[bx],ax
    les bx, dword ptr [bp-4h]
    mov bx,word ptr es:[bx+4h]
    add bx,bx
    add bx,bx
    les si, dword ptr ds:[63E4h]
    mov ax,word ptr es:[bx+si]
    mov dx,word ptr es:[bx+si+2h]
    mov word ptr [bp-0Ah],ax
    mov word ptr [bp-8h],dx
lbl97f:
    mov ax,word ptr [bp-0Ah]
    mov dx,word ptr [bp-8h]
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
