_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf5:FAR
    EXTRN mf30:FAR
    EXTRN mi43:NEAR
    EXTRN mf54:FAR
    EXTRN mf57:FAR
    EXTRN mf69:FAR
    EXTRN mi77:NEAR
    EXTRN mf82:FAR
    EXTRN mf85:FAR
    EXTRN mi88:NEAR
    EXTRN mf94:FAR
    EXTRN mi97:NEAR
    EXTRN mf100:FAR
    EXTRN mi102:NEAR
    EXTRN mf106:FAR
    EXTRN mf109:FAR
    EXTRN mf112:FAR
    EXTRN mf115:FAR
    EXTRN mf117:FAR
    EXTRN mf124:FAR
    EXTRN mf130:FAR
    EXTRN mf133:FAR
    EXTRN mf136:FAR
    EXTRN mf139:FAR
    EXTRN mf142:FAR
    EXTRN mf154:FAR
    EXTRN mf162:FAR
    EXTRN mf174:FAR
    EXTRN mf182:FAR
    EXTRN mf193:FAR
    EXTRN mf198:FAR
    EXTRN mf201:FAR
    EXTRN mf209:FAR
    EXTRN mf214:FAR
    EXTRN mf218:FAR
    EXTRN mf220:FAR
    EXTRN mf225:FAR
    EXTRN mf225:FAR
    EXTRN mf225:FAR
    EXTRN mf225:FAR
    EXTRN mf225:FAR
    EXTRN mf225:FAR
    EXTRN mf225:FAR
    EXTRN mf225:FAR
    EXTRN mf225:FAR
    EXTRN mf225:FAR
    EXTRN mf225:FAR
    EXTRN mf225:FAR
    EXTRN mf225:FAR
    EXTRN mf225:FAR
    EXTRN mf225:FAR
    EXTRN mf225:FAR
    EXTRN mf225:FAR
    EXTRN mf225:FAR
    EXTRN mf225:FAR
    EXTRN mf225:FAR
    EXTRN mf225:FAR
    EXTRN mf225:FAR
    EXTRN mf225:FAR
    EXTRN mf225:FAR
    EXTRN mf225:FAR
    EXTRN mf225:FAR
    EXTRN mf225:FAR
    EXTRN mf225:FAR
    EXTRN mf225:FAR
    EXTRN mf225:FAR
    EXTRN mf225:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,22h
    push di
    push si
    call mf5
    mov word ptr [bp-8h],0Ah
    mov word ptr [bp-0Ah],2Ch
    mov word ptr [bp-0Ch],3254h
    mov word ptr [bp-0Eh],3248h
lbl21b:
    cmp word ptr [bp-0Eh],3250h
    jnz short lbl32f
    mov word ptr [bp-8h],0A8h
    mov word ptr [bp-0Ah],2Ch
lbl32f:
    mov bx,word ptr [bp-0Eh]
    mov ax,word ptr [bx]
    mov cx,ax
    add ax,ax
    add ax,cx
    add ax,ax
    add ax,cx
    mov word ptr [bp-4h],ax
    mov bx,word ptr [bp-0Ch]
    mov ax,word ptr [bx]
    mov cx,ax
    add ax,ax
    add ax,cx
    add ax,ax
    mov word ptr [bp-6h],ax
    push word ptr ds:[31FCh]
    call mf30
    add sp,2h
    mov ax,word ptr [bp-0Ah]
    add ax,word ptr [bp-6h]
    mov cx,ax
    inc ax
    push ax
    mov ax,word ptr [bp-8h]
    add ax,word ptr [bp-4h]
    mov dx,ax
    inc ax
    push ax
    mov ax,word ptr [bp-0Ah]
    sub ax, offset mi43
    push ax
    mov bx,word ptr [bp-8h]
    sub bx,2h
    push bx
    mov si,2h
    push si
    mov di,ax
    mov si,cx
    mov word ptr [bp-10h],dx
    mov word ptr [bp-12h],bx
    call mf54
    add sp,0Ah
    push word ptr ds:[31FEh]
    call mf57
    add sp,2h
    mov ax,word ptr [bp-0Ah]
    inc ax
    push ax
    mov ax,word ptr [bp-10h]
    dec ax
    push ax
    push word ptr [bp-0Ah]
    push word ptr [bp-8h]
    mov ax,2h
    push ax
    call mf69
    add sp,0Ah
    lea ax,word ptr [si-1h]
    push ax
    mov ax,word ptr [bp-8h]
    inc ax
    push ax
    mov ax,word ptr [bp-0Ah]
    add ax, offset mi77
    push ax
    push word ptr [bp-8h]
    mov ax,2h
    push ax
    call mf82
    add sp,0Ah
    push word ptr ds:[3200h]
    call mf85
    add sp,2h
    mov ax,word ptr [bp-8h]
    sub ax, offset mi88
    push ax
    lea cx,word ptr [si+2h]
    push cx
    mov word ptr [bp-14h],ax
    mov word ptr [bp-16h],cx
    call mf94
    push word ptr [bp-14h]
    mov ax,word ptr [bp-0Ah]
    sub ax, offset mi97
    push ax
    mov word ptr [bp-18h],ax
    call mf100
    mov ax,word ptr [bp-10h]
    add ax, offset mi102
    push ax
    push word ptr [bp-18h]
    mov word ptr [bp-1Ah],ax
    call mf106
    push word ptr [bp-8h]
    push si
    call mf109
    push word ptr [bp-10h]
    push si
    call mf112
    push word ptr [bp-10h]
    push word ptr [bp-0Ah]
    call mf115
    push word ptr ds:[3202h]
    call mf117
    add sp,2h
    mov ax,word ptr [bp-8h]
    dec ax
    push ax
    push si
    mov word ptr [bp-1Ch],ax
    call mf124
    push word ptr [bp-1Ch]
    mov ax,word ptr [bp-0Ah]
    dec ax
    push ax
    mov word ptr [bp-1Eh],ax
    call mf130
    push word ptr [bp-10h]
    push word ptr [bp-1Eh]
    call mf133
    push word ptr [bp-12h]
    push word ptr [bp-16h]
    call mf136
    push word ptr [bp-1Ah]
    push word ptr [bp-16h]
    call mf139
    push word ptr [bp-1Ah]
    push di
    call mf142
    xor ax,ax
    push ax
    lea cx,word ptr [si+3h]
    push cx
    mov dx,word ptr [bp-10h]
    add dx,3h
    push dx
    push cx
    push word ptr [bp-12h]
    mov word ptr [bp-20h],cx
    mov word ptr [bp-22h],dx
    call mf154
    add sp,0Ah
    xor ax,ax
    push ax
    push word ptr [bp-16h]
    push word ptr [bp-22h]
    push di
    push word ptr [bp-22h]
    call mf162
    add sp,0Ah
    xor ax,ax
    push ax
    lea cx,word ptr [si+4h]
    push cx
    mov dx,word ptr [bp-10h]
    add dx,4h
    push dx
    push cx
    push word ptr [bp-1Ch]
    mov di,dx
    call mf174
    add sp,0Ah
    xor ax,ax
    push ax
    push word ptr [bp-20h]
    push di
    push word ptr [bp-1Eh]
    push di
    call mf182
    add sp,0Ah
    lea ax,word ptr [si+0Ch]
    mov word ptr [bp-0Ah],ax
    add word ptr [bp-0Ch],2h
    add word ptr [bp-0Eh],2h
    cmp word ptr [bp-0Eh],3252h
    jnc short lbl212f
    jmp near ptr lbl21b
lbl212f:
    mov ax,0Dh
    push ax
    call mf193
    add sp,2h
    mov ax,0FFFFh
    push ax
    push word ptr ds:[3200h]
    call mf198
    add sp,4h
    push word ptr ds:[3202h]
    call mf201
    add sp,2h
    mov ax,word ptr ds:[6D48h]
    add ax,86h
    push ax
    mov ax,word ptr ds:[6DDAh]
    add ax,0B6h
    push ax
    call mf209
    add sp,4h
    mov ax,3260h
    push ds
    push ax
    call mf214
    add sp,4h
    mov ax,0FFFFh
    push ax
    call mf218
    add sp,2h
    call mf220
    pop si
    pop di
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
