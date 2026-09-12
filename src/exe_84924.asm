_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi5:NEAR
    EXTRN mi18:NEAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,4h
    push si
    mov ax,word ptr [bp+6h]
    sub ax, offset mi5
    jz short lbl7Af
    dec ax
    jz short lbl82f
    les bx, dword ptr ds:[6340h]
    cmp byte ptr es:[bx+0Ch],0h
    jnl short lbl54f
    les bx, dword ptr es:[bx+12h]
    les bx, dword ptr es:[bx]
    mov si,word ptr [bp+6h]
    mov al,byte ptr es:[bx+si]
    cbw
    mov cx,ax
    and ax, offset mi18
    and cx,0F0h
    mov dx,cx
    mov cl,4h
    sar dx,cl
    add ax,dx
    les bx, dword ptr ds:[6340h]
    les bx, dword ptr es:[bx+0Eh]
    les bx, dword ptr es:[bx]
lbl47b:
    mov cx,ax
    mov al,byte ptr es:[bx+si]
lbl4Cb:
    cbw
    add cx,ax
    mov word ptr [bp-2h],cx
    jmp short lbl87f
lbl54f:
    cmp byte ptr es:[bx+0Bh],0h
    jnl short lbl6Cf
    mov al,byte ptr es:[bx+0Ch]
    cbw
    les bx, dword ptr es:[bx+0Eh]
    les bx, dword ptr es:[bx]
    mov si,word ptr [bp+6h]
    jmp short lbl47b
lbl6Cf:
    mov al,byte ptr es:[bx+0Ch]
    cbw
    mov cx,ax
    mov al,byte ptr es:[bx+0Bh]
    jmp short lbl4Cb
    nop
lbl7Af:
    mov ax,word ptr ds:[6DFCh]
    mov word ptr [bp-2h],ax
    jmp short lbl87f
lbl82f:
    mov word ptr [bp-2h],0h
lbl87f:
    cmp word ptr ds:[6346h],0h
    jl short lbl91f
    inc word ptr [bp-2h]
lbl91f:
    mov ax,word ptr [bp-2h]
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
