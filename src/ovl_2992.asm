_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf6:FAR
    EXTRN mf18:FAR
    EXTRN mf24:FAR
    EXTRN mf26:FAR
    EXTRN mf27:FAR
    EXTRN mi28:NEAR
    EXTRN md39:NEAR
    EXTRN md59:NEAR
    EXTRN mf71:FAR
    EXTRN mf86:FAR
    EXTRN mf101:FAR
    EXTRN mf123:FAR
    EXTRN mf140:FAR
    EXTRN mf160:FAR
    EXTRN mf164:FAR
    EXTRN mf171:FAR
    EXTRN mf171:FAR
    EXTRN mf171:FAR
    EXTRN mf171:FAR
    EXTRN mf171:FAR
    EXTRN mf171:FAR
    EXTRN mf171:FAR
    EXTRN mf171:FAR
    EXTRN mf171:FAR
    EXTRN mf171:FAR
    EXTRN mf171:FAR
    EXTRN mf171:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,0Ah
    push si
    cmp word ptr ds:[13ECh],0h
    jnz short lbl69f
    call mf6
    cmp dx,word ptr ds:[13EAh]
    jnl short lbl1Cf
    jmp near ptr lbl221f
lbl1Cf:
    jg short lbl27f
    cmp ax,word ptr ds:[13E8h]
    ja short lbl27f
    jmp near ptr lbl221f
lbl27f:
    cmp word ptr ds:[5D80h],3Fh
    jl short lbl3Cf
    cmp word ptr ds:[6D26h],0h
    jnl short lbl3Cf
    call mf18
    jmp short lbl4Cf
lbl3Cf:
    mov ax,6A24h
    mov cx,38AFh
    push cx
    push ax
    call mf24
    add sp,4h
lbl4Cf:
    call mf26
    call mf27
    add ax, offset mi28
    adc dx,0h
    mov word ptr ds:[13E8h],ax
    mov word ptr ds:[13EAh],dx
    mov word ptr ds:[13ECh],1h
lbl69f:
    mov word ptr ds:[13ECh],0h
    cmp word ptr ds:[6D26h],0h
    jl short lblAEf
    mov word ptr [bp-6h],0h
lbl7Bb:
    mov bx,word ptr [bp-6h]
    mov es, ds:[5A68h]
    mov al,byte ptr es:[bx+md39]
    sub ah,ah
    imul word ptr ds:[6D26h]
    mov cx,3Fh
    cwd
    idiv cx
    mov es, ds:[5A6Ah]
    mov byte ptr es:[bx+6A24h],al
    inc word ptr [bp-6h]
    cmp word ptr [bp-6h],300h
    jc short lbl7Bb
    sub word ptr ds:[6D26h],4h
    jmp short lblE9f
    nop
lblAEf:
    cmp word ptr ds:[5D80h],3Fh
    jnl short lblE9f
    inc word ptr ds:[5D80h]
    mov word ptr [bp-6h],0h
lblBEb:
    mov bx,word ptr [bp-6h]
    mov es, ds:[5A68h]
    mov al,byte ptr es:[bx+md59]
    sub ah,ah
    imul word ptr ds:[5D80h]
    mov cx,3Fh
    cwd
    idiv cx
    mov es, ds:[5A6Ah]
    mov byte ptr es:[bx+6A24h],al
    inc word ptr [bp-6h]
    cmp word ptr [bp-6h],300h
    jc short lblBEb
lblE9f:
    mov word ptr [bp-6h],4h
    call mf71
    or ax,ax
    jz short lblFAf
    jmp near ptr lbl221f
lblFAf:
    mov word ptr [bp-0Ah],348h
lblFFb:
    cmp word ptr [bp-6h],0h
    jnl short lbl108f
    jmp near ptr lbl221f
lbl108f:
    mov bx,word ptr [bp-0Ah]
    mov es, ds:[5A68h]
    mov word ptr [bp-4h],bx
    mov word ptr [bp-2h],es
    mov ax,word ptr es:[bx+2h]
    or ax,word ptr es:[bx]
    jz short lbl19Cf
    call mf86
    les bx, dword ptr [bp-4h]
    cmp dx,word ptr es:[bx+2h]
    jnl short lbl12Ff
    jmp near ptr lbl20Ef
lbl12Ff:
    jg short lbl139f
    cmp ax,word ptr es:[bx]
    ja short lbl139f
    jmp near ptr lbl20Ef
lbl139f:
    mov ax,14h
    imul word ptr es:[bx+0Ch]
    add ax,word ptr es:[bx+0Eh]
    mov dx,word ptr es:[bx+10h]
    push dx
    push ax
    call mf101
    add sp,4h
    les bx, dword ptr [bp-4h]
    inc word ptr es:[bx+0Ch]
    mov ax,word ptr es:[bx+0Ch]
    cmp word ptr es:[bx+0Ah],ax
    jng short lbl166f
    jmp near ptr lbl20Ef
lbl166f:
    cmp word ptr [bp-6h],0h
    jnz short lbl17Af
    les bx, dword ptr [bp-4h]
    mov word ptr es:[bx+0Ch],0h
    jmp near ptr lbl20Ef
    nop
    nop
lbl17Af:
    les bx, dword ptr [bp-4h]
    sub ax,ax
    mov word ptr es:[bx+2h],ax
    mov word ptr es:[bx],ax
    push word ptr es:[bx+0Ah]
    push word ptr es:[bx+10h]
    push word ptr es:[bx+0Eh]
    call mf123
    add sp,6h
    jmp short lbl20Ef
lbl19Cf:
    les bx, dword ptr [bp-4h]
    mov ax,word ptr es:[bx+4h]
    mov word ptr [bp-8h],ax
    cmp word ptr es:[bx+0Ch],0h
    jnz short lbl20Ef
    or ax,ax
    jl short lbl1C9f
    mov ax,12h
    imul word ptr [bp-8h]
    mov bx,ax
    mov es, ds:[5A68h]
    mov ax,word ptr es:[bx+30Ch]
    cmp word ptr es:[bx+30Ah],ax
    jg short lbl20Ef
lbl1C9f:
    call mf140
    les bx, dword ptr [bp-4h]
    mov cx,ax
    mov ax,word ptr es:[bx+6h]
    mov si,dx
    cwd
    add ax,cx
    adc dx,si
    mov word ptr es:[bx],ax
    mov word ptr es:[bx+2h],dx
    les bx, dword ptr es:[bx+0Eh]
    cmp byte ptr es:[bx],0h
    jnz short lbl20Ef
    mov ax,1h
    push ax
    les bx, dword ptr [bp-4h]
    push word ptr es:[bx+8h]
    push word ptr es:[bx+0Ah]
    push word ptr es:[bx+10h]
    push word ptr es:[bx+0Eh]
    call mf160
    add sp,0Ah
lbl20Ef:
    sub word ptr [bp-0Ah],12h
    dec word ptr [bp-6h]
    call mf164
    or ax,ax
    jnz short lbl221f
    jmp near ptr lblFFb
lbl221f:
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
