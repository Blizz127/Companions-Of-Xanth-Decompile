_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf4:FAR
    EXTRN mf12:FAR
    EXTRN mf16:FAR
    EXTRN mf28:FAR
    EXTRN mf38:FAR
    EXTRN mf51:FAR
    EXTRN mf63:FAR
    EXTRN mf67:FAR
    EXTRN mf73:FAR
    EXTRN mf83:FAR
    EXTRN mf87:FAR
    EXTRN mf98:FAR
    EXTRN mf101:FAR
    EXTRN mf105:FAR
    EXTRN mf159:FAR
    EXTRN mf161:FAR
    EXTRN mf162:FAR
    EXTRN mf171:FAR
    EXTRN mf186:FAR
    EXTRN mf196:FAR
    EXTRN mf200:FAR
    EXTRN mf203:FAR
    EXTRN mf206:FAR
    EXTRN mf208:FAR
    EXTRN mf216:FAR
    EXTRN mf224:FAR
    EXTRN mf238:FAR
    EXTRN mf244:FAR
    EXTRN mf248:FAR
    EXTRN mf248:FAR
    EXTRN mf248:FAR
    EXTRN mf248:FAR
    EXTRN mf248:FAR
    EXTRN mf248:FAR
    EXTRN mf248:FAR
    EXTRN mf248:FAR
    EXTRN mf248:FAR
    EXTRN mf248:FAR
    EXTRN mf248:FAR
    EXTRN mf248:FAR
    EXTRN mf248:FAR
    EXTRN mf248:FAR
    EXTRN mf248:FAR
    EXTRN mf248:FAR
    EXTRN mf248:FAR
    EXTRN mf248:FAR
    EXTRN mf248:FAR
    EXTRN mf248:FAR
    EXTRN mf248:FAR
    EXTRN mf248:FAR
    EXTRN mf248:FAR
    EXTRN mf248:FAR
    EXTRN mf248:FAR
    EXTRN mf248:FAR
    EXTRN mf248:FAR
    EXTRN mf248:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,16h
    push si
    call mf4
    mov ax,0B0h
    push ax
    mov cx,109h
    push cx
    xor cx,cx
    push cx
    push cx
    call mf12
    add sp,8h
    xor ax,ax
    push ax
    call mf16
    add sp,2h
    mov ax,0B0h
    push ax
    mov cx,100h
    push cx
    mov dx,6h
    push dx
    mov bx,8h
    push bx
    mov si,1h
    push si
    call mf28
    add sp,0Ah
    mov ax,0B0h
    push ax
    mov ax,100h
    push ax
    mov ax,6h
    push ax
    mov ax,8h
    push ax
    call mf38
    add sp,8h
    mov word ptr [bp-4h],ax
    mov ax,14h
    push ax
    mov ax,0AFh
    push ax
    mov ax,0FFh
    push ax
    mov ax,7h
    push ax
    mov ax,9h
    push ax
    call mf51
    add sp,0Ah
    mov ax,18h
    push ax
    mov ax,9Ah
    push ax
    mov ax,0F8h
    push ax
    mov ax,0Eh
    push ax
    mov ax,10h
    push ax
    call mf63
    mov ax,0Ah
    add sp,ax
    push ax
    call mf67
    add sp,2h
    mov ax,17h
    push ax
    mov ax,0Fh
    push ax
    call mf73
    add sp,4h
    mov ax,99h
    push ax
    mov ax,0F7h
    push ax
    mov ax,0Fh
    push ax
    mov ax,11h
    push ax
    call mf83
    add sp,8h
    mov word ptr [bp-6h],ax
    push ax
    call mf87
    add sp,2h
    mov ax,30h
    push ax
    mov ax,3345h
    push ds
    push ax
    mov ax,9Fh
    push ax
    mov ax,6Ch
    push ax
    call mf98
    add sp,0Ah
    push word ptr [bp-6h]
    call mf101
    add sp,2h
    mov ax,9h
    push ax
    call mf105
    add sp,2h
    les bx, dword ptr ds:[5E12h]
    cmp byte ptr es:[bx+4h],0h
    jz short lbl11Af
    mov ax,331Ch
    jmp short lbl11Df
    nop
lbl11Af:
    mov ax,3316h
lbl11Df:
    push ds
    push ax
    cmp byte ptr es:[bx+5h],0h
    jz short lbl12Cf
    mov ax,3328h
    jmp short lbl12Ff
    nop
lbl12Cf:
    mov ax,3322h
lbl12Ff:
    push ds
    push ax
    mov si,word ptr es:[bx+2h]
    add si,si
    add si,si
    mov cx,word ptr es:[bx+8h]
    mov dx,word ptr es:[bx+0Ah]
    mov es,dx
    add si,cx
    mov word ptr [bp-16h],si
    mov word ptr [bp-14h],es
    cmp byte ptr es:[si+2h],0h
    jz short lbl158f
    mov ax,331Ch
    jmp short lbl15Bf
    nop
lbl158f:
    mov ax,3316h
lbl15Bf:
    push ds
    push ax
    mov bx,si
    cmp byte ptr es:[bx+3h],0h
    jz short lbl16Cf
    mov ax,3328h
    jmp short lbl16Ff
    nop
lbl16Cf:
    mov ax,3322h
lbl16Ff:
    push ds
    push ax
    mov bx,word ptr es:[bx]
    add bx,bx
    add bx,bx
    push word ptr [bx+3304h]
    push word ptr [bx+3302h]
    xor ax,ax
    mov dx,0F044h
    push dx
    push ax
    call mf159
    add sp,18h
    call mf161
lbl194b:
    call mf162
    or ax,ax
    jnz short lbl1E4f
    lea ax,word ptr [bp-0Ah]
    push ss
    push ax
    lea ax,word ptr [bp-8h]
    push ss
    push ax
    call mf171
    add sp,8h
    or ax,ax
    jz short lbl194b
    lea ax,word ptr [bp-10h]
    push ss
    push ax
    lea ax,word ptr [bp-0Eh]
    push ss
    push ax
    lea ax,word ptr [bp-0Ch]
    push ss
    push ax
    push word ptr [bp-0Ah]
    push word ptr [bp-8h]
    call mf186
    add sp,10h
    or ax,ax
    jz short lbl194b
    cmp word ptr [bp-10h],5h
    jnz short lbl194b
    mov ax,word ptr [bp-4h]
    cmp word ptr [bp-0Ch],ax
    jnz short lbl194b
    jmp short lbl1E9f
lbl1E4f:
    call mf196
lbl1E9f:
    mov ax,1h
    push ax
    push word ptr [bp-4h]
    call mf200
    add sp,4h
    push word ptr [bp-6h]
    call mf203
    add sp,2h
    push word ptr [bp-4h]
    call mf206
    add sp,2h
    call mf208
    mov ax,0B0h
    push ax
    mov ax,109h
    push ax
    xor ax,ax
    push ax
    push ax
    call mf216
    add sp,8h
    les bx, dword ptr ds:[5E12h]
    sub ah,ah
    mov al,byte ptr es:[bx+1h]
    push ax
    mov al,byte ptr es:[bx]
    push ax
    call mf224
    add sp,4h
    mov word ptr [bp-2h],0h
    cmp word ptr ds:[5E1Ah],0h
    jz short lbl279f
    mov word ptr [bp-12h],0h
lbl24Fb:
    mov ax,word ptr [bp-2h]
    inc ax
    push ax
    les bx, dword ptr ds:[5E16h]
    mov si,word ptr [bp-12h]
    push word ptr es:[bx+si+2h]
    push word ptr es:[bx+si]
    mov si,ax
    call mf238
    add sp,6h
    add word ptr [bp-12h],4h
    mov word ptr [bp-2h],si
    cmp si,word ptr ds:[5E1Ah]
    jc short lbl24Fb
lbl279f:
    call mf244
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
