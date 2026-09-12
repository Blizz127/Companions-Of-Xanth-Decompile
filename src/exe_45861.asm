_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN md18:NEAR
    EXTRN md20:NEAR
    EXTRN md21:NEAR
    EXTRN md28:NEAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,6h
    push si
    cmp word ptr [bp+6h],0h
    jg short lbl10f
    jmp near ptr lblA5f
lbl10f:
    mov ax,word ptr ds:[84Ch]
    cmp word ptr [bp+6h],ax
    jna short lbl1Bf
    jmp near ptr lblA5f
lbl1Bf:
    mov es, ds:[5A24h]
    mov bx,word ptr [bp+6h]
    mov ax,bx
    add bx,bx
    add bx,ax
    add bx,bx
    sub ah,ah
    mov al,byte ptr es:[bx+md18]
    mov word ptr [bp-2h],ax
    mov cx,word ptr es:[bx+md20]
    mov dx,word ptr es:[bx+md21]
    mov word ptr [bp-6h],cx
    mov word ptr [bp-4h],dx
    mov bx,ax
    add bx,bx
    add bx,ax
    mov es, ds:[5A28h]
    mov al,byte ptr es:[bx+md28]
    cmp ax,word ptr [bp+8h]
    jng short lblA5f
    mov ax,word ptr [bp-2h]
    dec ax
    jz short lbl8Af
    dec ax
    jz short lbl6Cf
    dec ax
    jz short lbl78f
    dec ax
    jz short lbl8Af
    dec ax
    jz short lbl96f
    jmp short lblA5f
lbl6Cf:
    mov ax,word ptr [bp+0Ah]
    les bx, dword ptr [bp-6h]
    mov word ptr es:[bx+0Eh],ax
    jmp short lblA5f
lbl78f:
    mov ax,word ptr [bp+0Ah]
    mov si,word ptr [bp+8h]
    add si,si
    les bx, dword ptr [bp-6h]
    mov word ptr es:[bx+si+0Eh],ax
    jmp short lblA5f
    nop
lbl8Af:
    mov ax,word ptr [bp+0Ah]
    les bx, dword ptr [bp-6h]
    mov word ptr es:[bx+6h],ax
    jmp short lblA5f
lbl96f:
    mov ax,word ptr [bp+0Ah]
    mov si,word ptr [bp+8h]
    add si,si
    les bx, dword ptr [bp-6h]
    mov word ptr es:[bx+si+0Ch],ax
lblA5f:
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
