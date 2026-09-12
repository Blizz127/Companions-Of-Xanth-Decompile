_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi18:NEAR
    EXTRN mf26:FAR
    EXTRN mf36:FAR
    EXTRN mf85:FAR
    EXTRN mf107:FAR
    EXTRN mf107:FAR
    EXTRN mf107:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,1Ah
    push di
    push si
    cmp word ptr ds:[4DB2h],0h
    jz short lbl12f
    jmp near ptr lbl128f
lbl12f:
    mov word ptr [bp-16h],0h
    cmp word ptr ds:[4DAEh],0h
    jg short lbl21f
    jmp near ptr lbl128f
lbl21f:
    mov word ptr [bp-1Ah],0h
lbl26b:
    mov ax,word ptr ds:[63DCh]
    mov dx,word ptr ds:[63DEh]
    add ax,word ptr [bp-1Ah]
    mov word ptr [bp-4h],ax
    mov word ptr [bp-2h],dx
    add ax, offset mi18
    mov word ptr [bp-8h],ax
    mov word ptr [bp-6h],dx
    les bx, dword ptr [bp-4h]
    push word ptr es:[bx+8h]
    push word ptr es:[bx+6h]
    push word ptr es:[bx+2h]
    push word ptr es:[bx]
    call mf26
    add sp,8h
    mov word ptr [bp-10h],ax
    mov word ptr [bp-0Eh],dx
    sub ax,ax
    push ax
    push ax
    les bx, dword ptr [bp-8h]
    push word ptr es:[bx+2h]
    push word ptr es:[bx]
    call mf36
    add sp,8h
    cmp dx,word ptr [bp-0Eh]
    jnl short lbl7Df
    jmp near ptr lbl116f
lbl7Df:
    jg short lbl87f
    cmp ax,word ptr [bp-10h]
    ja short lbl87f
    jmp near ptr lbl116f
lbl87f:
    les bx, dword ptr [bp-8h]
    test byte ptr es:[bx+0Ah],80h
    jnz short lbl94f
    jmp near ptr lbl116f
lbl94f:
    test byte ptr es:[bx+0Ah],10h
    jnz short lbl116f
    mov bx,word ptr es:[bx+4h]
    add bx,bx
    add bx,bx
    les si, dword ptr ds:[63E4h]
    les si, dword ptr [bp-8h]
    les di, dword ptr ds:[63E4h]
    mov ax,word ptr es:[bx+di]
    mov dx,word ptr es:[bx+di+2h]
    les bx, dword ptr [bp-8h]
    cmp ax,word ptr es:[bx]
    jnz short lbl116f
    cmp dx,word ptr es:[bx+2h]
    jnz short lbl116f
    push word ptr es:[bx+8h]
    push word ptr es:[bx+6h]
    push dx
    push ax
    mov ax,word ptr [bp-10h]
    mov dx,word ptr [bp-0Eh]
    shr dx,1
    rcr ax,1
    rcr dx,1
    rcr ax,1
    rcr dx,1
    rcr ax,1
    rcr dx,1
    rcr ax,1
    rcr dx,1
    xchg ax,dx
    and ax,0F000h
    push dx
    push ax
    mov si,ax
    mov di,dx
    call mf85
    add sp,0Ch
    les bx, dword ptr [bp-8h]
    mov word ptr es:[bx],si
    mov word ptr es:[bx+2h],di
    mov bx,word ptr es:[bx+4h]
    add bx,bx
    add bx,bx
    mov ax,si
    les si, dword ptr ds:[63E4h]
    mov word ptr es:[bx+si],ax
    mov word ptr es:[bx+si+2h],di
lbl116f:
    add word ptr [bp-1Ah],0Ch
    mov ax,word ptr ds:[4DAEh]
    inc word ptr [bp-16h]
    cmp word ptr [bp-16h],ax
    jnl short lbl128f
    jmp near ptr lbl26b
lbl128f:
    pop si
    pop di
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
