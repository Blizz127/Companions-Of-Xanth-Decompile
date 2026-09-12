_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf22:FAR
    EXTRN md45:NEAR
    EXTRN md60:NEAR
    EXTRN mf67:FAR
    EXTRN mf79:FAR
    EXTRN mf86:FAR
    EXTRN mf95:FAR
    EXTRN mf104:FAR
    EXTRN mf111:FAR
    EXTRN mf120:FAR
    EXTRN mf128:FAR
    EXTRN mf136:FAR
    EXTRN mf144:FAR
    EXTRN mf152:FAR
    EXTRN mf160:FAR
    EXTRN mf166:FAR
    EXTRN mf178:FAR
    EXTRN mf178:FAR
    EXTRN mf178:FAR
    EXTRN mf178:FAR
    EXTRN mf178:FAR
    EXTRN mf178:FAR
    EXTRN mf178:FAR
    EXTRN mf178:FAR
    EXTRN mf178:FAR
    EXTRN mf178:FAR
    EXTRN mf178:FAR
    EXTRN mf178:FAR
    EXTRN mf178:FAR
    EXTRN mf178:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,0Ah
    inc word ptr ds:[100h]
    cmp word ptr ds:[100h],1h
    jng short lbl4Af
    mov ax,word ptr ds:[6A06h]
    cmp word ptr [bp+6h],ax
    jnz short lbl4Af
    mov ax,word ptr ds:[6A04h]
    cmp word ptr [bp+8h],ax
    jnz short lbl4Af
    mov ax,word ptr ds:[6A02h]
    cmp word ptr [bp+0Ah],ax
    jnz short lbl4Af
    inc word ptr ds:[5C5Ch]
    cmp word ptr ds:[5C5Ch],4h
    jng short lbl50f
    mov ax,0h
    mov cx,2241h
    push cx
    push ax
    call mf22
    add sp,4h
    mov ax,2h
    jmp near ptr lbl200f
lbl4Af:
    mov word ptr ds:[5C5Ch],0h
lbl50f:
    mov ax,word ptr ds:[6A06h]
    mov word ptr [bp-6h],ax
    mov ax,word ptr ds:[6A04h]
    mov word ptr [bp-8h],ax
    mov ax,word ptr ds:[6A02h]
    mov word ptr [bp-0Ah],ax
    mov ax,word ptr [bp+6h]
    mov word ptr ds:[6A06h],ax
    mov ax,word ptr [bp+8h]
    mov word ptr ds:[6A04h],ax
    or ax,ax
    jz short lbl88f
    mov es, ds:[5A30h]
    mov bx,ax
    add bx,ax
    add bx,ax
    add bx,bx
    sub ah,ah
    mov al,byte ptr es:[bx+md45]
    jmp short lbl8Af
    nop
lbl88f:
    xor ax,ax
lbl8Af:
    mov word ptr ds:[69FEh],ax
    mov ax,word ptr [bp+0Ah]
    mov word ptr ds:[6A02h],ax
    or ax,ax
    jz short lblACf
    mov es, ds:[5A30h]
    mov bx,ax
    add bx,ax
    add bx,ax
    add bx,bx
    sub ah,ah
    mov al,byte ptr es:[bx+md60]
    jmp short lblAEf
lblACf:
    xor ax,ax
lblAEf:
    mov word ptr ds:[6A00h],ax
    mov ax,1h
    push ax
    push word ptr ds:[256h]
    call mf67
    add sp,4h
    mov word ptr [bp-2h],ax
    or ax,ax
    jz short lblCBf
    jmp near ptr lbl1E7f
lblCBf:
    mov ax,word ptr ds:[258h]
    cmp word ptr ds:[266h],ax
    jz short lblEEf
    mov ax,1h
    push ax
    push word ptr ds:[266h]
    call mf79
    add sp,4h
    mov word ptr [bp-2h],ax
    or ax,ax
    jz short lblEEf
    jmp near ptr lbl1E7f
lblEEf:
    push word ptr ds:[258h]
    call mf86
    add sp,2h
    mov word ptr [bp-4h],ax
    mov ax,word ptr ds:[256h]
    cmp word ptr [bp-4h],ax
    jz short lbl11Ef
    mov ax,1h
    push ax
    push word ptr [bp-4h]
    call mf95
    add sp,4h
    mov word ptr [bp-2h],ax
    or ax,ax
    jz short lbl11Ef
    jmp near ptr lbl1E7f
lbl11Ef:
    mov ax,2h
    push ax
    push word ptr ds:[258h]
    call mf104
    add sp,4h
    mov word ptr [bp-2h],ax
    or ax,ax
    jz short lbl138f
    jmp near ptr lbl1E7f
lbl138f:
    push word ptr ds:[6A06h]
    call mf111
    add sp,2h
    mov word ptr [bp-2h],ax
    or ax,ax
    jz short lbl14Ef
    jmp near ptr lbl1E7f
lbl14Ef:
    cmp word ptr ds:[6A02h],ax
    jz short lbl194f
    push word ptr ds:[6A02h]
    call mf120
    add sp,2h
    mov word ptr [bp-4h],ax
    or ax,ax
    jz short lbl17Df
    mov ax,3h
    push ax
    push word ptr [bp-4h]
    call mf128
    add sp,4h
    mov word ptr [bp-2h],ax
    or ax,ax
    jnz short lbl1E7f
lbl17Df:
    mov ax,4h
    push ax
    push word ptr ds:[6A02h]
    call mf136
    add sp,4h
    mov word ptr [bp-2h],ax
    or ax,ax
    jnz short lbl1E7f
lbl194f:
    cmp word ptr ds:[6A04h],0h
    jz short lbl1DBf
    push word ptr ds:[6A04h]
    call mf144
    add sp,2h
    mov word ptr [bp-4h],ax
    or ax,ax
    jz short lbl1C4f
    mov ax,5h
    push ax
    push word ptr [bp-4h]
    call mf152
    add sp,4h
    mov word ptr [bp-2h],ax
    or ax,ax
    jnz short lbl1E7f
lbl1C4f:
    mov ax,6h
    push ax
    push word ptr ds:[6A04h]
    call mf160
    add sp,4h
    mov word ptr [bp-2h],ax
    or ax,ax
    jnz short lbl1E7f
lbl1DBf:
    push word ptr ds:[6A06h]
    call mf166
    mov word ptr [bp-2h],ax
lbl1E7f:
    mov ax,word ptr [bp-6h]
    mov word ptr ds:[6A06h],ax
    mov ax,word ptr [bp-8h]
    mov word ptr ds:[6A04h],ax
    mov ax,word ptr [bp-0Ah]
    mov word ptr ds:[6A02h],ax
    dec word ptr ds:[100h]
    mov ax,word ptr [bp-2h]
lbl200f:
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
