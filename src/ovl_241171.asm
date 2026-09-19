_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mfad:FAR
    EXTRN md4f:NEAR
    EXTRN mf70:FAR
    EXTRN mf2e:FAR
    EXTRN mf23:FAR
    EXTRN mf8d:FAR
    EXTRN mfa1:FAR
    EXTRN mfc0:FAR
    EXTRN mfff:FAR
    EXTRN mfe3:FAR
    EXTRN mfdb:FAR
    EXTRN mf54:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,0Ch
    push si
    les bx, dword ptr [bp+6h]
    mov ax,word ptr es:[bx+8h]
    mov word ptr [bp-6h],ax
    mov ax,word ptr es:[bx+0Ah]
    mov word ptr [bp-8h],ax
    mov ax,word ptr es:[bx+0Ch]
    mov word ptr [bp-0Ah],ax
    mov ax,0FFFFh
    push ax
    call mf23
    add sp,2h
    xor ax,ax
    push ax
    call mf2e
    add sp,2h
    mov ax,0FFFFh
    push ax
    les bx, dword ptr [bp+6h]
    mov cl,3h
    mov si,word ptr ds:[337Eh]
    shl si,cl
    add si,word ptr es:[bx+0Eh]
    add si,si
    mov es, ds:[5B24h]
    push word ptr es:[si+md4f]
    call mf54
    add sp,4h
    push word ptr [bp-0Ah]
    push word ptr [bp-8h]
    push word ptr [bp-6h]
    les bx, dword ptr [bp+6h]
    push word ptr es:[bx+4h]
    push word ptr es:[bx+2h]
    call mf70
    add sp,0Ah
    mov word ptr [bp-0Ch],ax
    push ax
    push word ptr [bp-0Ah]
    push word ptr [bp-8h]
    push word ptr [bp-6h]
    mov cx,60h
    mov dx,328Eh
    push dx
    push cx
    call mf8d
    add sp,0Ch
    push word ptr [bp-0Ch]
    push word ptr [bp-0Ah]
    push word ptr [bp-8h]
    push word ptr [bp-6h]
    call mfa1
    add sp,8h
    mov word ptr ds:[3380h],ax
    push ax
    call mfad
    add sp,2h
    les bx, dword ptr [bp+6h]
    push word ptr es:[bx+4h]
    push word ptr es:[bx+2h]
    call mfc0
    add sp,4h
    cmp word ptr ds:[4232h],0h
    jz short lbl110f
    push word ptr [bp+0Ch]
    push word ptr [bp+0Ah]
    les bx, dword ptr [bp+6h]
    push word ptr es:[bx]
    call mfdb
    add sp,6h
    call mfe3
    add ax,12Ch
    adc dx,0h
    mov word ptr [bp-4h],ax
    mov word ptr [bp-2h],dx
lblF4b:
    mov ax,word ptr [bp+0Ch]
    or ax,word ptr [bp+0Ah]
    jz short lblFFf
    db 0FFh, 5Eh, 0Ah ; override
lblFFf:
    call mfff
    cmp dx,word ptr [bp-2h]
    jl short lblF4b
    jg short lbl110f
    cmp ax,word ptr [bp-4h]
    jc short lblF4b
lbl110f:
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
