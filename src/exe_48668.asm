_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi13:NEAR
    EXTRN mf31:FAR
    EXTRN mf86:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,0Eh
    push si
    mov word ptr [bp-0Eh],0h
    mov byte ptr [bp-4h],0h
    mov word ptr [bp-0Ch],0FFFFh
lbl15b:
    cmp word ptr [bp+0Ah],0h
    jnz short lbl24f
    cmp word ptr [bp-0Ch],0h
    jnz short lbl24f
    jmp near ptr lblEEf
lbl24f:
    mov ax,word ptr [bp+12h]
    sub ax, offset mi13
    mov word ptr [bp-0Ah],ax
lbl2Db:
    cmp word ptr [bp+0Ah],0h
    jnz short lbl39f
    cmp word ptr [bp-0Ch],0h
    jz short lbl15b
lbl39f:
    cmp byte ptr [bp-4h],0h
    jnz short lbl64f
    cmp word ptr [bp+0Ah],0h
    jnz short lbl48f
    jmp near ptr lblD4f
lbl48f:
    push word ptr [bp+0Ch]
    mov ax,1h
    push ax
    push ax
    lea cx,word ptr [bp-2h]
    push ss
    push cx
    call mf31
    add sp,0Ah
    dec word ptr [bp+0Ah]
    mov byte ptr [bp-4h],8h
lbl64f:
    mov bl,byte ptr [bp-2h]
    and bx,1h
    or bx,word ptr [bp-0Ah]
    add bx,bx
    les si, dword ptr [bp+0Eh]
    mov ax,word ptr es:[bx+si]
    mov word ptr [bp-0Ah],ax
    shr byte ptr [bp-2h],1
    dec byte ptr [bp-4h]
    or ax,ax
    jnl short lbl2Db
    mov ax,0FFFFh
    sub ax,word ptr [bp-0Ah]
    mov word ptr [bp-0Ch],ax
    cmp ax,80h
    jl short lblDCf
    sub ax,80h
    cmp ax,word ptr [bp+18h]
    jnc short lblDCf
    mov si,word ptr [bp-0Ch]
    add si,si
    add si,si
    les bx, dword ptr [bp+14h]
    les bx, dword ptr es:[bx+si-200h]
    mov word ptr [bp-8h],bx
    mov word ptr [bp-6h],es
    cmp byte ptr es:[bx],0h
    jnz short lblB6f
    jmp near ptr lbl15b
lblB6b:
lblB6f:
    inc word ptr [bp-8h]
    mov al,byte ptr es:[bx]
    les bx, dword ptr [bp+6h]
    inc word ptr [bp+6h]
    mov byte ptr es:[bx],al
    inc word ptr [bp-0Eh]
    les bx, dword ptr [bp-8h]
    cmp byte ptr es:[bx],0h
    jnz short lblB6b
    jmp near ptr lbl15b
lblD4f:
    mov word ptr [bp-0Ch],0h
    jmp near ptr lbl15b
lblDCf:
    mov al,byte ptr [bp-0Ch]
    les bx, dword ptr [bp+6h]
    inc word ptr [bp+6h]
    mov byte ptr es:[bx],al
    inc word ptr [bp-0Eh]
    jmp near ptr lbl15b
lblEEf:
    mov ax,word ptr [bp-0Eh]
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
