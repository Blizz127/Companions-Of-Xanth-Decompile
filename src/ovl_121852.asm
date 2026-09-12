_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi3:NEAR
    EXTRN mi10:NEAR
    EXTRN mf20:FAR
    EXTRN mi24:NEAR
    EXTRN mf56:FAR
    EXTRN mf63:FAR
    EXTRN mf72:FAR
    EXTRN mf81:FAR
    EXTRN mf91:FAR
    EXTRN mf102:FAR
    EXTRN mi110:NEAR
    EXTRN mf116:FAR
    EXTRN mf123:FAR
    EXTRN mf132:FAR
    EXTRN mf139:FAR
    EXTRN mf146:FAR
    EXTRN mf154:FAR
    EXTRN mf161:FAR
    EXTRN mf168:FAR
    EXTRN mf178:FAR
    EXTRN mf186:FAR
    EXTRN mf192:FAR
    EXTRN mf198:FAR
    EXTRN mf206:FAR
    EXTRN mf212:FAR
    EXTRN mf223:FAR
    EXTRN mf234:FAR
    EXTRN mf244:FAR
    EXTRN mf255:FAR
    EXTRN md270:NEAR
    EXTRN mf275:FAR
    EXTRN mf283:FAR
    EXTRN mf292:FAR
    EXTRN mf292:FAR
    EXTRN mf292:FAR
    EXTRN mf292:FAR
    EXTRN mf292:FAR
    EXTRN mf292:FAR
    EXTRN mf292:FAR
    EXTRN mf292:FAR
    EXTRN mf292:FAR
    EXTRN mf292:FAR
    EXTRN mf292:FAR
    EXTRN mf292:FAR
    EXTRN mf292:FAR
    EXTRN mf292:FAR
    EXTRN mf292:FAR
    EXTRN mf292:FAR
    EXTRN mf292:FAR
    EXTRN mf292:FAR
    EXTRN mf292:FAR
    EXTRN mf292:FAR
    EXTRN mf292:FAR
    EXTRN mf292:FAR
    EXTRN mf292:FAR
    EXTRN mf292:FAR
    EXTRN mf292:FAR
    EXTRN mf292:FAR
    EXTRN mf292:FAR
mnem_unit:
    push bp
    mov bp,sp
    mov ax,word ptr [bp+6h]
    sub ax, offset mi3
    jz short lbl12f
    dec ax
    dec ax
    jz short lbl3Ef
    jmp near ptr lbl2D8f
lbl12f:
    mov ax,word ptr ds:[6A06h]
    sub ax, offset mi10
    jz short lbl1Df
    jmp near ptr lbl2D8f
lbl1Df:
    cmp word ptr ds:[6A04h],92h
    jz short lbl28f
    jmp near ptr lbl2D8f
lbl28f:
    push word ptr ds:[6A04h]
    push word ptr ds:[6A02h]
    mov ax,48h
    push ax
    call mf20
    mov sp,bp
    jmp near ptr lbl2DAf
lbl3Ef:
    mov ax,word ptr ds:[6A06h]
    cmp ax, offset mi24
    jnz short lbl49f
    jmp near ptr lbl108f
lbl49f:
    jna short lbl4Ef
    jmp near ptr lbl2D8f
lbl4Ef:
    cmp al,38h
    jnz short lbl55f
    jmp near ptr lbl108f
lbl55f:
    ja short lbl6Af
    sub al,7h
    jz short lbl82f
    sub al,0Ch
    jz short lblBEf
    sub al,19h
    jnz short lbl66f
    jmp near ptr lbl102f
lbl66f:
    jmp near ptr lbl2D8f
    nop
lbl6Af:
    sub al,44h
    jnz short lbl71f
    jmp near ptr lbl20Ef
lbl71f:
    dec al
    jnz short lbl78f
    jmp near ptr lbl256f
lbl78f:
    sub al,2h
    jnz short lbl7Ff
    jmp near ptr lbl25Cf
lbl7Ff:
    jmp near ptr lbl2D8f
lbl82f:
    mov ax,105h
    push ax
    mov ax,90h
    push ax
    call mf56
    mov sp,bp
    or ax,ax
    jnz short lblACf
    push word ptr ds:[6A04h]
    mov ax,2h
    push ax
    call mf63
    mov sp,bp
    push dx
    push ax
    mov ax,31h
    jmp short lblF5f
    nop
lblACf:
    mov ax,9h
    push ax
    call mf72
lblB5b:
    mov sp,bp
lblB7b:
    mov ax,1h
    jmp near ptr lbl2DAf
    nop
lblBEf:
    mov ax,105h
    push ax
    mov ax,90h
    push ax
    call mf81
    mov sp,bp
    or ax,ax
    jz short lblD8f
    mov ax,21h
    jmp near ptr lbl245f
    nop
lblD8f:
    mov ax,8Dh
    push ax
    push word ptr ds:[6A04h]
    call mf91
    mov sp,bp
    or ax,ax
    jz short lblF2f
    mov ax,22h
    jmp near ptr lbl245f
    nop
lblF2f:
    mov ax,23h
lblF5f:
    mov dx,0F00Dh
    push dx
    push ax
    call mf102
    jmp short lblB5b
    nop
lbl102f:
    mov ax,27h
    jmp near ptr lbl245f
lbl108f:
    mov ax,word ptr ds:[6A02h]
    sub ax,8Dh
    jz short lbl140f
    sub ax, offset mi110
    jnz short lbl118f
    jmp near ptr lbl1B6f
lbl118f:
    push word ptr ds:[6A02h]
    mov ax,2h
    push ax
    call mf116
    mov sp,bp
    push dx
    push ax
    push word ptr ds:[6A04h]
    mov ax,2h
    push ax
    call mf123
    add sp,4h
    push dx
    push ax
    mov ax,2Ch
    jmp short lbl17Bf
lbl140f:
    mov ax,8Dh
    push ax
    push word ptr ds:[6A04h]
    call mf132
    add sp,4h
    or ax,ax
    jz short lbl18Cf
    push word ptr ds:[6A02h]
    mov ax,22h
    push ax
    call mf139
    add sp,4h
    push dx
    push ax
    push word ptr ds:[6A04h]
    mov ax,2h
    push ax
    call mf146
    add sp,4h
    push dx
    push ax
    mov ax,2Ah
lbl17Bb:
lbl17Bf:
    mov dx,0F00Dh
    push dx
    push ax
    call mf154
    add sp,0Ch
    jmp near ptr lblB7b
    nop
lbl18Cf:
    push word ptr ds:[6A02h]
    mov ax,2h
    push ax
    call mf161
    add sp,4h
    push dx
    push ax
    push word ptr ds:[6A04h]
    mov ax,2h
    push ax
    call mf168
    add sp,4h
    push dx
    push ax
    mov ax,2Bh
    jmp short lbl17Bb
    nop
lbl1B6f:
    push word ptr ds:[6A04h]
    mov ax,2h
    push ax
    call mf178
    add sp,4h
    push dx
    push ax
    mov ax,29h
    mov dx,0F00Dh
    push dx
    push ax
    call mf186
    add sp,8h
    xor ax,ax
    push ax
    push ax
    push word ptr ds:[6A04h]
    call mf192
    add sp,6h
    xor ax,ax
    push ax
    push ax
    push word ptr ds:[6A02h]
    call mf198
    add sp,6h
    xor ax,ax
    push ax
    mov ax,1h
    push ax
    mov cx,90h
    push cx
    call mf206
    add sp,6h
    jmp near ptr lblB7b
lbl20Ef:
    mov ax,1h
    push ax
    push word ptr ds:[6A04h]
    call mf212
    add sp,4h
    or ax,ax
    jz short lbl228f
    mov ax,24h
    jmp short lbl245f
    nop
lbl228f:
    mov ax,105h
    push ax
    mov ax,90h
    push ax
    call mf223
    add sp,4h
    or ax,ax
    jz short lbl242f
    mov ax,25h
    jmp short lbl245f
    nop
lbl242f:
    mov ax,26h
lbl245b:
lbl245f:
    mov dx,0F00Dh
    push dx
    push ax
    call mf234
    add sp,4h
    jmp near ptr lblB7b
    nop
lbl256f:
    mov ax,28h
    jmp short lbl245b
    nop
lbl25Cf:
    mov ax,1h
    push ax
    push word ptr ds:[6A04h]
    call mf244
    add sp,4h
    or ax,ax
    jnz short lbl276f
    mov ax,2Dh
    jmp short lbl245b
    nop
lbl276f:
    mov ax,105h
    push ax
    mov ax,90h
    push ax
    call mf255
    add sp,4h
    or ax,ax
    jz short lbl290f
    mov ax,2Eh
    jmp short lbl245b
    nop
lbl290f:
    cmp word ptr ds:[6A02h],0h
    jz short lbl2D2f
    mov es, ds:[5AC8h]
    mov bx,word ptr ds:[6A02h]
    mov ax,bx
    add bx,bx
    add bx,ax
    add bx,bx
    cmp byte ptr es:[bx+md270],5h
    jnz short lbl2D2f
    push ax
    mov ax,11h
    push ax
    call mf275
    add sp,4h
    push dx
    push ax
    mov ax,2Fh
    mov dx,0F00Dh
    push dx
    push ax
    call mf283
    add sp,8h
    jmp near ptr lblB7b
    nop
lbl2D2f:
    mov ax,30h
    jmp near ptr lbl245b
lbl2D8f:
    xor ax,ax
lbl2DAf:
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
