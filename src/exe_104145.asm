_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf15:FAR
    EXTRN mf19:FAR
    EXTRN mf147:FAR
    EXTRN mf152:FAR
    EXTRN mf152:FAR
    EXTRN mf152:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,20h
    push di
    push si
    les bx, dword ptr [bp+6h]
    test byte ptr es:[bx+1h],80h
    jz short lbl15f
    jmp near ptr lbl1B8f
lbl15f:
    les bx, dword ptr [bp+0Ah]
    test byte ptr es:[bx+1h],80h
    jz short lbl22f
    jmp near ptr lbl1B8f
lbl22f:
    push word ptr [bp+8h]
    push word ptr [bp+6h]
    call mf15
    add sp,4h
    push word ptr [bp+0Ch]
    push word ptr [bp+0Ah]
    call mf19
    add sp,4h
    les bx, dword ptr [bp+6h]
    mov ax,word ptr es:[bx+10h]
    mov dx,word ptr es:[bx+12h]
    mov word ptr [bp-4h],ax
    mov word ptr [bp-2h],dx
    mov es,dx
    mov word ptr [bp-20h],ax
    mov word ptr [bp-1Eh],es
    mov es, [bp+8h]
    mov ax,es
    les si, dword ptr [bp-20h]
    mov dx,es
    mov cx,word ptr es:[si+6h]
    mov es,ax
    add cx,word ptr es:[bx+2h]
    mov word ptr [bp-0Ah],cx
    mov es,dx
    mov ax,word ptr es:[si+8h]
    mov es, [bp+8h]
    add ax,word ptr es:[bx+4h]
    mov word ptr [bp-0Ch],ax
    les bx, dword ptr [bp-20h]
    mov ax,word ptr es:[bx+0Ah]
    les bx, dword ptr [bp+6h]
    add ax,word ptr es:[bx+2h]
    mov word ptr [bp-0Eh],ax
    les bx, dword ptr [bp-20h]
    mov cx,word ptr es:[bx+0Ch]
    les bx, dword ptr [bp+6h]
    add cx,word ptr es:[bx+4h]
    mov word ptr [bp-10h],cx
    les bx, dword ptr [bp+0Ah]
    mov cx,word ptr es:[bx+10h]
    mov dx,word ptr es:[bx+12h]
    mov word ptr [bp-8h],cx
    mov word ptr [bp-6h],dx
    mov si,word ptr es:[bx+2h]
    mov word ptr [bp-1Ah],si
    mov di,word ptr es:[bx+4h]
    mov word ptr [bp-1Ch],di
    mov es,dx
    mov bx,cx
    mov cx,si
    add si,word ptr es:[bx+6h]
    mov word ptr [bp-12h],si
    mov dx,di
    add di,word ptr es:[bx+8h]
    mov word ptr [bp-14h],di
    add cx,word ptr es:[bx+0Ah]
    mov word ptr [bp-16h],cx
    add dx,word ptr es:[bx+0Ch]
    mov word ptr [bp-18h],dx
    cmp si,ax
    jng short lblEAf
    jmp near ptr lbl1B8f
lblEAf:
    mov ax,word ptr [bp-10h]
    cmp di,ax
    jng short lblF4f
    jmp near ptr lbl1B8f
lblF4f:
    mov ax,word ptr [bp-0Ah]
    cmp cx,ax
    jnl short lblFEf
    jmp near ptr lbl1B8f
lblFEf:
    mov ax,word ptr [bp-0Ch]
    cmp dx,ax
    jnl short lbl108f
    jmp near ptr lbl1B8f
lbl108f:
    mov ax,word ptr [bp-0Eh]
    cmp cx,ax
    jg short lbl11Ef
    les bx, dword ptr [bp+6h]
    mov ax,word ptr es:[bx+2h]
    sub ax,word ptr [bp-1Ah]
    add word ptr [bp-16h],ax
    jmp short lbl124f
lbl11Ef:
    sub ax,word ptr [bp-1Ah]
    mov word ptr [bp-16h],ax
lbl124f:
    mov ax,word ptr [bp-10h]
    cmp dx,ax
    jg short lbl13Af
    les bx, dword ptr [bp+6h]
    mov ax,word ptr es:[bx+4h]
    sub ax,word ptr [bp-1Ch]
    add word ptr [bp-18h],ax
    jmp short lbl140f
lbl13Af:
    sub ax,word ptr [bp-1Ch]
    mov word ptr [bp-18h],ax
lbl140f:
    mov ax,word ptr [bp-0Ah]
    cmp si,ax
    jl short lbl15Af
    mov ax,si
    les bx, dword ptr [bp+6h]
    sub ax,word ptr es:[bx+2h]
    mov word ptr [bp-1Ah],ax
    mov word ptr [bp-12h],0h
    jmp short lbl165f
lbl15Af:
    sub ax,word ptr [bp-1Ah]
    mov word ptr [bp-12h],ax
    mov word ptr [bp-1Ah],0h
lbl165f:
    mov ax,word ptr [bp-0Ch]
    cmp di,ax
    jl short lbl180f
    mov ax,di
    les bx, dword ptr [bp+6h]
    sub ax,word ptr es:[bx+4h]
    mov word ptr [bp-1Ch],ax
    mov word ptr [bp-14h],0h
    jmp short lbl18Bf
    nop
lbl180f:
    sub ax,word ptr [bp-1Ch]
    mov word ptr [bp-14h],ax
    mov word ptr [bp-1Ch],0h
lbl18Bf:
    push word ptr [bp-6h]
    push word ptr [bp-8h]
    push word ptr [bp-12h]
    push word ptr [bp-14h]
    push word ptr [bp-16h]
    push word ptr [bp-18h]
    push word ptr [bp-2h]
    push word ptr [bp-4h]
    push word ptr [bp-1Ah]
    push word ptr [bp-1Ch]
    les bx, dword ptr [bp+0Ah]
    sub ah,ah
    mov al,byte ptr es:[bx+1h]
    push ax
    call mf147
lbl1B8f:
    pop si
    pop di
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
