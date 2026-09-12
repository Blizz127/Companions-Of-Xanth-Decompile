_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf19:FAR
    EXTRN mf35:FAR
    EXTRN mf52:FAR
    EXTRN mf69:FAR
    EXTRN mf74:FAR
    EXTRN mf100:FAR
    EXTRN mf100:FAR
    EXTRN mf100:FAR
    EXTRN mf100:FAR
    EXTRN mf100:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,0Ch
    push si
    cmp word ptr ds:[4F68h],5h
    jnz short lbl14f
lbl0Eb:
    mov ax,0FFFFh
    jmp near ptr lbl127f
lbl14f:
    mov ax,word ptr ds:[4F68h]
    mov word ptr [bp-2h],ax
    mov bx,ax
    add bx,ax
    mov ax,word ptr [bp+8h]
    mov word ptr [bx+675Ah],ax
    mov cx,14h
    imul cx
    sub dx,dx
    push dx
    push ax
    call mf19
    add sp,4h
    mov bx,word ptr [bp-2h]
    add bx,bx
    add bx,bx
    mov word ptr [bp-0Ch],bx
    mov word ptr [bx+678Ah],ax
    mov word ptr [bx+678Ch],dx
    mov ax,dx
    or ax,word ptr [bx+678Ah]
    jz short lbl0Eb
    push word ptr [bp+8h]
    mov bx,word ptr [bp-0Ch]
    les bx, dword ptr [bx+678Ah]
    push word ptr es:[bx+2h]
    push word ptr es:[bx]
    call mf35
    add sp,6h
    mov word ptr [bp-4h],0h
    cmp word ptr [bp+8h],0h
    jng short lblB1f
    mov word ptr [bp-0Ah],0h
lbl79b:
    mov ax,1h
    push ax
    push word ptr [bp+6h]
    inc word ptr [bp+6h]
    mov bx,word ptr [bp-0Ch]
    les bx, dword ptr [bx+678Ah]
    mov ax,word ptr es:[bx]
    mov dx,word ptr es:[bx+2h]
    add ax,word ptr [bp-0Ah]
    push dx
    push ax
    call mf52
    add sp,8h
    or ax,ax
    jz short lblB1f
    add word ptr [bp-0Ah],14h
    mov ax,word ptr [bp+8h]
    inc word ptr [bp-4h]
    cmp word ptr [bp-4h],ax
    jl short lbl79b
lblB1f:
    mov ax,word ptr [bp+8h]
    cmp word ptr [bp-4h],ax
    jnl short lblF6f
    push word ptr [bp-4h]
    mov bx,word ptr [bp-0Ch]
    les si, dword ptr [bx+678Ah]
    push word ptr es:[si+2h]
    push word ptr es:[si]
    call mf69
    add sp,6h
    mov bx,word ptr [bp-0Ch]
    push word ptr [bx+678Ch]
    push word ptr [bx+678Ah]
    call mf74
    add sp,4h
    mov bx,word ptr [bp-0Ch]
    sub ax,ax
    mov word ptr [bx+678Ch],ax
    mov word ptr [bx+678Ah],ax
    jmp near ptr lbl0Eb
    nop
lblF6f:
    mov bx,word ptr [bp-2h]
    mov al,byte ptr [bp-4h]
    mov byte ptr [bx+6764h],al
    mov al,byte ptr [bp+0Ah]
    mov byte ptr [bx+676Ah],al
    mov ax,word ptr [bp+0Ch]
    cwd
    mov bx,word ptr [bp-0Ch]
    mov word ptr [bx+6776h],ax
    mov word ptr [bx+6778h],dx
    sub ax,ax
    mov word ptr [bx+67A0h],ax
    mov word ptr [bx+679Eh],ax
    mov ax,word ptr ds:[4F68h]
    inc word ptr ds:[4F68h]
lbl127f:
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
