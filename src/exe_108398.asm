_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf155:FAR
    EXTRN mf2e:FAR
    EXTRN mf63:FAR
    EXTRN mfe2:FAR
    EXTRN mibb:NEAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,0Ah
    push si
    cmp word ptr [bp+6h],0h
    jnl short lbl14f
    mov ax,0FFFFh
    jmp near ptr lbl160f
    nop
lbl14f:
    mov bx,word ptr [bp+6h]
    add bx,bx
    mov ax,word ptr [bx+67E2h]
    inc word ptr [bx+67E2h]
    mov word ptr [bp-6h],ax
    or ax,ax
    jnz short lbl48f
    mov ax,14h
    cwd
    push dx
    push ax
    call mf2e
    add sp,4h
    mov bx,word ptr [bp+6h]
    add bx,bx
    add bx,bx
    mov word ptr [bx+67C2h],ax
    mov word ptr [bx+67C4h],dx
    jmp short lbl73f
    nop
lbl48f:
    inc ax
    mov cx,14h
    imul cx
    sub dx,dx
    push dx
    push ax
    mov bx,word ptr [bp+6h]
    add bx,bx
    add bx,bx
    push word ptr [bx+67C4h]
    push word ptr [bx+67C2h]
    mov si,bx
    call mf63
    add sp,8h
    mov word ptr [si+67C2h],ax
    mov word ptr [si+67C4h],dx
lbl73f:
    mov ax,14h
    imul word ptr [bp-6h]
    mov bx,word ptr [bp+6h]
    add bx,bx
    add bx,bx
    les bx, dword ptr [bx+67C2h]
    add bx,ax
    mov word ptr [bp-4h],bx
    mov word ptr [bp-2h],es
    mov ax,word ptr [bp+8h]
    mov word ptr es:[bx+2h],ax
    mov ax,word ptr [bp+0Ah]
    les bx, dword ptr [bp-4h]
    mov word ptr es:[bx+4h],ax
    mov ax,word ptr [bp+0Ch]
    mov word ptr es:[bx+6h],ax
    mov ax,word ptr [bp+0Eh]
    mov word ptr es:[bx+8h],ax
    mov al,byte ptr [bp+10h]
    mov byte ptr es:[bx],al
    mov al,byte ptr [bp+12h]
    mov byte ptr es:[bx+1h],al
    mov ax,word ptr [bp+10h]
    cmp ax, offset mibb
    jna short lblC3f
    jmp near ptr lbl15Df
lblC3f:
    add ax,ax
    xchg ax,bx
    jmp word ptr cs:[bx+1DEAh]
    nop
    db 0FAh, 1Dh, 0FAh, 1Dh, 7Bh, 1Eh, 0Ch, 1Eh, 2Ah, 1Eh, 7Bh, 1Eh, 7Bh, 1Eh, 0Ch, 1Eh
lblDCb:
    push word ptr [bp-6h]
    push word ptr [bp+6h]
    call mfe2
    add sp,4h
    jmp short lbl15Df
    nop
    nop
    mov ax,word ptr [bp+14h]
    les bx, dword ptr [bp-4h]
    mov word ptr es:[bx+0Ah],ax
    xor ax,ax
    mov word ptr es:[bx+0Ch],ax
    mov word ptr es:[bx+0Eh],ax
    mov word ptr es:[bx+12h],ax
    mov word ptr es:[bx+10h],ax
    jmp short lbl15Df
    mov ax,word ptr [bp-6h]
    dec ax
    jz short lblDCb
    dec ax
    jz short lbl120f
    dec ax
    jl short lbl15Df
    jo short lbl15Df
    dec ax
    jng short lbl136f
    jmp short lbl15Df
    nop
lbl120f:
    test byte ptr [bp+12h],80h
    jnz short lbl15Df
    push word ptr [bp+0Ah]
    push word ptr [bp+8h]
    push word ptr ds:[67FCh]
    push word ptr ds:[67FAh]
    jmp short lbl155f
lbl136f:
    push word ptr [bp+0Ah]
    push word ptr [bp+8h]
    cmp word ptr [bp-6h],3h
    jnz short lbl14Cf
    mov ax,word ptr ds:[67F2h]
    mov dx,word ptr ds:[67F4h]
    jmp short lbl153f
    nop
lbl14Cf:
    mov ax,word ptr ds:[67F6h]
    mov dx,word ptr ds:[67F8h]
lbl153f:
    push dx
    push ax
lbl155f:
    call mf155
    add sp,8h
lbl15Df:
    mov ax,word ptr [bp-6h]
lbl160f:
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
