_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf115:FAR
    EXTRN mi118:NEAR
    EXTRN mi121:NEAR
    EXTRN mi124:NEAR
    EXTRN mf133:FAR
    EXTRN mf136:FAR
    EXTRN mi139:NEAR
    EXTRN mf146:FAR
    EXTRN mi149:NEAR
    EXTRN mf152:FAR
    EXTRN mi154:NEAR
    EXTRN mf158:FAR
    EXTRN mf164:FAR
    EXTRN mf170:FAR
    EXTRN mf173:FAR
    EXTRN mf175:FAR
    EXTRN mf179:FAR
    EXTRN mf182:FAR
    EXTRN mf185:FAR
    EXTRN mf191:FAR
    EXTRN mf197:FAR
    EXTRN mf200:FAR
    EXTRN mf202:FAR
    EXTRN mi205:NEAR
    EXTRN mf212:FAR
    EXTRN mi216:NEAR
    EXTRN mi219:NEAR
    EXTRN mf224:FAR
    EXTRN mf241:FAR
    EXTRN mi246:NEAR
    EXTRN mi251:NEAR
    EXTRN mf257:FAR
    EXTRN mf266:FAR
    EXTRN mf266:FAR
    EXTRN mf266:FAR
    EXTRN mf266:FAR
    EXTRN mf266:FAR
    EXTRN mf266:FAR
    EXTRN mf266:FAR
    EXTRN mf266:FAR
    EXTRN mf266:FAR
    EXTRN mf266:FAR
    EXTRN mf266:FAR
    EXTRN mf266:FAR
    EXTRN mf266:FAR
    EXTRN mf266:FAR
    EXTRN mf266:FAR
    EXTRN mf266:FAR
    EXTRN mf266:FAR
    EXTRN mf266:FAR
    EXTRN mf266:FAR
    EXTRN mf266:FAR
    EXTRN mf266:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,24h
    push di
    push si
    xor ax,ax
    mov es, ds:[5AE6h]
    mov cx,0C3h
    mov di,4750h
    rep stosw
    stosb
    cmp word ptr ds:[6DDCh],ax
    jnz short lbl20f
    jmp near ptr lbl2CCf
lbl20f:
    cmp word ptr ds:[6DDEh],ax
    jnz short lbl29f
    jmp near ptr lbl2CCf
lbl29f:
    mov ax,word ptr ds:[3210h]
    cmp word ptr ds:[6DDCh],ax
    jc short lbl36f
    dec ax
    mov word ptr ds:[6DDCh],ax
lbl36f:
    mov ax,word ptr ds:[3212h]
    cmp word ptr ds:[6DDEh],ax
    jc short lbl43f
    dec ax
    mov word ptr ds:[6DDEh],ax
lbl43f:
    mov ax,word ptr ds:[3212h]
    sub ax,word ptr ds:[6DDEh]
    shr ax,1
    mov word ptr [bp-18h],ax
    dec ax
    mov word ptr [bp-4h],ax
    mov cx,word ptr ds:[3210h]
    sub cx,word ptr ds:[6DDCh]
    shr cx,1
    dec cx
    mov word ptr [bp-6h],cx
    mov bx,17h
    mul bx
    mov bx,ax
    add bx,cx
    mov ax,bx
    add bx,4750h
    mov cx,ax
    mov ax,2020h
    mov dx,cx
    mov cx,word ptr ds:[6DDCh]
    add cx,2h
    mov di,bx
    shr cx,1
    rep stosw
    jnc short lbl87f
    stosb
lbl87f:
    mov word ptr [bp-14h],bx
    add dx,word ptr ds:[6DDCh]
    add dx,4751h
    mov word ptr [bp-16h],dx
    jmp short lblBFf
    nop
lbl98b:
    mov al,20h
    mov bx,word ptr [bp-14h]
    mov es, ds:[5AE6h]
    mov byte ptr es:[bx],al
    mov bx,word ptr [bp-16h]
    mov ax,1010h
    mov byte ptr es:[bx],20h
    mov bx,word ptr [bp-14h]
    mov cx,word ptr ds:[6DDCh]
    lea di,word ptr [bx+1h]
    shr cx,1
    rep stosw
    jnc short lblBFf
    stosb
lblBFf:
    add word ptr [bp-14h],17h
    add word ptr [bp-16h],17h
    mov ax,word ptr [bp-18h]
    add ax,word ptr ds:[6DDEh]
    inc word ptr [bp-4h]
    cmp ax,word ptr [bp-4h]
    ja short lbl98b
    mov ax,17h
    mul word ptr [bp-4h]
    mov bx,ax
    add bx,word ptr [bp-6h]
    mov ax,2020h
    mov cx,word ptr ds:[6DDCh]
    add cx,2h
    lea di,word ptr [bx+4750h]
    shr cx,1
    rep stosw
    jnc short lblF6f
    stosb
lblF6f:
    mov ax,word ptr ds:[3210h]
    sub ax,word ptr ds:[6DDCh]
    shr ax,1
    mul word ptr ds:[320Ch]
    mov word ptr [bp-8h],ax
    mov cx,ax
    mov ax,word ptr [bp-18h]
    mul word ptr ds:[320Eh]
    mov word ptr [bp-0Ah],ax
    mov dx,ax
    mov ax,word ptr ds:[6DDCh]
    mov bx,dx
    mul word ptr ds:[320Ch]
    add cx,ax
    dec cx
    mov word ptr [bp-0Ch],cx
    mov ax,word ptr ds:[6DDEh]
    mul word ptr ds:[320Eh]
    add bx,ax
    dec bx
    mov word ptr [bp-0Eh],bx
    push word ptr ds:[31FCh]
    call mf115
    add sp,2h
    mov ax,word ptr [bp-0Eh]
    add ax, offset mi118
    push ax
    mov ax,word ptr [bp-0Ch]
    add ax, offset mi121
    push ax
    mov ax,word ptr [bp-0Ah]
    sub ax, offset mi124
    push ax
    mov cx,word ptr [bp-8h]
    sub cx,4h
    push cx
    mov dx,2h
    push dx
    mov si,ax
    mov di,cx
    call mf133
    add sp,0Ah
    push word ptr ds:[3200h]
    call mf136
    add sp,2h
    mov ax,word ptr [bp-8h]
    sub ax, offset mi139
    push ax
    mov cx,word ptr [bp-0Eh]
    add cx,5h
    push cx
    mov word ptr [bp-1Ah],ax
    mov word ptr [bp-1Ch],cx
    call mf146
    push word ptr [bp-1Ah]
    mov ax,word ptr [bp-0Ah]
    sub ax, offset mi149
    push ax
    mov word ptr [bp-1Eh],ax
    call mf152
    mov ax,word ptr [bp-0Ch]
    add ax, offset mi154
    push ax
    push word ptr [bp-1Eh]
    mov word ptr [bp-20h],ax
    call mf158
    push word ptr [bp-8h]
    mov ax,word ptr [bp-0Eh]
    inc ax
    push ax
    mov word ptr [bp-22h],ax
    call mf164
    mov ax,word ptr [bp-0Ch]
    inc ax
    push ax
    push word ptr [bp-22h]
    mov word ptr [bp-24h],ax
    call mf170
    push word ptr [bp-24h]
    push word ptr [bp-0Ah]
    call mf173
    push word ptr ds:[3202h]
    call mf175
    add sp,2h
    push di
    push word ptr [bp-1Ch]
    call mf179
    push word ptr [bp-20h]
    push word ptr [bp-1Ch]
    call mf182
    push word ptr [bp-20h]
    push si
    call mf185
    mov ax,word ptr [bp-8h]
    dec ax
    push ax
    push word ptr [bp-22h]
    mov si,ax
    call mf191
    push si
    mov ax,word ptr [bp-0Ah]
    dec ax
    push ax
    mov si,ax
    call mf197
    push word ptr [bp-24h]
    push si
    call mf200
    push word ptr ds:[31FEh]
    call mf202
    add sp,2h
    mov ax,word ptr [bp-0Ah]
    add ax, offset mi205
    push ax
    push word ptr [bp-0Ch]
    push word ptr [bp-0Ah]
    push word ptr [bp-8h]
    mov ax,2h
    push ax
    call mf212
    add sp,0Ah
    push word ptr [bp-0Eh]
    mov ax,word ptr [bp-8h]
    add ax, offset mi216
    push ax
    mov ax,word ptr [bp-0Ah]
    add ax, offset mi219
    push ax
    push word ptr [bp-8h]
    mov ax,2h
    push ax
    call mf224
    add sp,0Ah
    mov word ptr [bp-2h],0h
lbl277b:
    xor ax,ax
    push ax
    mov cx,word ptr [bp-0Eh]
    mov dx,word ptr [bp-2h]
    add cx,dx
    add cx,6h
    push cx
    mov bx,word ptr [bp-0Ch]
    add bx,8h
    push bx
    push cx
    add dx,word ptr [bp-8h]
    sub dx,4h
    push dx
    call mf241
    add sp,0Ah
    xor ax,ax
    push ax
    mov ax,word ptr [bp-0Eh]
    add ax, offset mi246
    push ax
    mov ax,word ptr [bp-0Ch]
    mov cx,word ptr [bp-2h]
    add ax,cx
    add ax, offset mi251
    push ax
    add cx,word ptr [bp-0Ah]
    sub cx,4h
    push cx
    push ax
    call mf257
    add sp,0Ah
    inc word ptr [bp-2h]
    cmp word ptr [bp-2h],3h
    jc short lbl277b
lbl2CCf:
    pop si
    pop di
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
