_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf7:FAR
    EXTRN mf12:FAR
    EXTRN mf18:FAR
    EXTRN mf25:FAR
    EXTRN mf37:FAR
    EXTRN mf44:FAR
    EXTRN mf56:FAR
    EXTRN mf63:FAR
    EXTRN mf72:FAR
    EXTRN mf78:FAR
    EXTRN mf83:FAR
    EXTRN mf89:FAR
    EXTRN mf118:FAR
    EXTRN mf145:FAR
    EXTRN mf150:FAR
    EXTRN mi153:NEAR
    EXTRN mi156:NEAR
    EXTRN mi159:NEAR
    EXTRN mi162:NEAR
    EXTRN mf167:FAR
    EXTRN mf175:FAR
    EXTRN mf178:FAR
    EXTRN mf193:FAR
    EXTRN mf209:FAR
    EXTRN mf211:FAR
    EXTRN mf213:FAR
    EXTRN mf217:FAR
    EXTRN mf219:FAR
    EXTRN mi228:NEAR
    EXTRN mf237:FAR
    EXTRN mf243:FAR
    EXTRN mf246:FAR
    EXTRN mf249:FAR
    EXTRN mf250:FAR
    EXTRN mi251:NEAR
    EXTRN mf254:FAR
    EXTRN mf257:FAR
    EXTRN mf262:FAR
    EXTRN mf267:FAR
    EXTRN mf269:FAR
    EXTRN mf271:FAR
    EXTRN mf278:FAR
    EXTRN mf284:FAR
    EXTRN mf284:FAR
    EXTRN mf284:FAR
    EXTRN mf284:FAR
    EXTRN mf284:FAR
    EXTRN mf284:FAR
    EXTRN mf284:FAR
    EXTRN mf284:FAR
    EXTRN mf284:FAR
    EXTRN mf284:FAR
    EXTRN mf284:FAR
    EXTRN mf284:FAR
    EXTRN mf284:FAR
    EXTRN mf284:FAR
    EXTRN mf284:FAR
    EXTRN mf284:FAR
    EXTRN mf284:FAR
    EXTRN mf284:FAR
    EXTRN mf284:FAR
    EXTRN mf284:FAR
    EXTRN mf284:FAR
    EXTRN mf284:FAR
    EXTRN mf284:FAR
    EXTRN mf284:FAR
    EXTRN mf284:FAR
    EXTRN mf284:FAR
    EXTRN mf284:FAR
    EXTRN mf284:FAR
    EXTRN mf284:FAR
    EXTRN mf284:FAR
    EXTRN mf284:FAR
    EXTRN mf284:FAR
    EXTRN mf284:FAR
    EXTRN mf284:FAR
    EXTRN mf284:FAR
    EXTRN mf284:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,28h
    push di
    push si
    xor ax,ax
    push ax
    call mf7
    add sp,2h
    mov word ptr [bp-26h],ax
    push word ptr [bp+8h]
    push word ptr [bp+6h]
    call mf12
    add sp,4h
    mov word ptr [bp+6h],ax
    mov word ptr [bp+8h],dx
    push dx
    push ax
    call mf18
    add sp,4h
    mov word ptr [bp-1Eh],ax
    mov ax,2Ch
    push ax
    push word ptr [bp+8h]
    push word ptr [bp+6h]
    call mf25
    add sp,6h
    mov word ptr [bp+6h],ax
    mov word ptr [bp+8h],dx
    or dx,ax
    jnz short lbl56f
    jmp near ptr lbl2F2f
lbl56f:
    inc word ptr [bp+6h]
    mov ax,word ptr [bp+6h]
    mov dx,word ptr [bp+8h]
    push dx
    push ax
    call mf37
    add sp,4h
    mov word ptr [bp-20h],ax
    mov ax,2Ch
    push ax
    push word ptr [bp+8h]
    push word ptr [bp+6h]
    call mf44
    add sp,6h
    mov word ptr [bp+6h],ax
    mov word ptr [bp+8h],dx
    or dx,ax
    jnz short lbl8Bf
    jmp near ptr lbl2F2f
lbl8Bf:
    inc word ptr [bp+6h]
    mov ax,word ptr [bp+6h]
    mov dx,word ptr [bp+8h]
    push dx
    push ax
    call mf56
    add sp,4h
    mov word ptr [bp-1Ch],ax
    mov ax,2Ch
    push ax
    push word ptr [bp+8h]
    push word ptr [bp+6h]
    call mf63
    add sp,6h
    mov word ptr [bp+6h],ax
    mov word ptr [bp+8h],dx
    or dx,ax
    jnz short lblC0f
    jmp near ptr lbl2F2f
lblC0f:
    mov ax,0Dh
    push ax
    call mf72
    add sp,2h
    mov ax,0FFFFh
    push ax
    xor ax,ax
    push ax
    call mf78
    add sp,4h
    add word ptr [bp+6h],2h
    push word ptr [bp+8h]
    push word ptr [bp+6h]
    call mf83
    add sp,4h
    cmp ax,word ptr [bp-1Ch]
    jnl short lbl107f
    push word ptr [bp+8h]
    push word ptr [bp+6h]
    call mf89
    add sp,4h
    add ax,word ptr ds:[6D24h]
    mov word ptr [bp-1Ch],ax
lbl107f:
    cmp word ptr [bp-1Eh],0h
    jnl short lbl11Ef
    mov ax,word ptr [bp-1Eh]
    add ax,13Fh
    mov word ptr [bp-22h],ax
    sub ax,word ptr [bp-1Ch]
    mov word ptr [bp-1Eh],ax
    jmp short lbl13Bf
lbl11Ef:
    cmp word ptr [bp-1Eh],0h
    jnz short lbl132f
    mov ax,13Fh
    sub ax,word ptr [bp-1Ch]
    cwd
    sub ax,dx
    sar ax,1
    mov word ptr [bp-1Eh],ax
lbl132f:
    mov ax,word ptr [bp-1Eh]
    add ax,word ptr [bp-1Ch]
    mov word ptr [bp-22h],ax
lbl13Bf:
    push word ptr [bp-22h]
    xor ax,ax
    push ax
    push word ptr [bp-1Eh]
    push word ptr [bp+8h]
    push word ptr [bp+6h]
    call mf118
    add sp,0Ah
    inc ax
    mov word ptr [bp-1Ah],ax
    cmp word ptr [bp-20h],0h
    jnl short lbl16Ef
    mov ax,word ptr [bp-20h]
    add ax,0C7h
    mov word ptr [bp-24h],ax
    sub ax,word ptr [bp-1Ah]
    mov word ptr [bp-20h],ax
    jmp short lbl18Bf
    nop
lbl16Ef:
    cmp word ptr [bp-20h],0h
    jnz short lbl182f
    mov ax,0C7h
    sub ax,word ptr [bp-1Ah]
    cwd
    sub ax,dx
    sar ax,1
    mov word ptr [bp-20h],ax
lbl182f:
    mov ax,word ptr [bp-20h]
    add ax,word ptr [bp-1Ah]
    mov word ptr [bp-24h],ax
lbl18Bf:
    xor ax,ax
    push ax
    push ax
    call mf145
    add sp,4h
    lea ax,word ptr [bp-14h]
    push ss
    push ax
    call mf150
    add sp,4h
    mov ax,word ptr [bp-24h]
    add ax, offset mi153
    push ax
    mov ax,word ptr [bp-22h]
    add ax, offset mi156
    push ax
    mov ax,word ptr [bp-20h]
    sub ax, offset mi159
    push ax
    mov ax,word ptr [bp-1Eh]
    sub ax, offset mi162
    push ax
    lea ax,word ptr [bp-14h]
    push ss
    push ax
    call mf167
    add sp,0Ch
    mov ax,word ptr [bp-24h]
    add ax,word ptr ds:[69F8h]
    push ax
    push word ptr [bp-22h]
    push word ptr [bp-20h]
    push word ptr [bp-1Eh]
    call mf175
    add sp,8h
    mov word ptr [bp-28h],ax
    call mf178
    mov ax,4h
    push ax
    mov cx,word ptr [bp-24h]
    add cx,2h
    push cx
    mov cx,word ptr [bp-22h]
    add cx,2h
    push cx
    mov cx,word ptr [bp-20h]
    sub cx,2h
    push cx
    mov cx,word ptr [bp-1Eh]
    sub cx,2h
    push cx
    call mf193
    add sp,0Ah
    mov ax,4h
    push ax
    mov ax,word ptr [bp-24h]
    inc ax
    push ax
    mov ax,word ptr [bp-22h]
    inc ax
    push ax
    mov ax,word ptr [bp-20h]
    dec ax
    push ax
    mov ax,word ptr [bp-1Eh]
    dec ax
    push ax
    call mf209
    add sp,0Ah
    call mf211
    push word ptr [bp-28h]
    call mf213
    add sp,2h
    push word ptr [bp+8h]
    push word ptr [bp+6h]
    call mf217
    add sp,4h
    call mf219
    mov bx,ax
    les di, dword ptr [bp+6h]
    mov cx,0FFFFh
    xor ax,ax
    repne scasb
    not cx
    dec cx
    mov ax,cx
    add ax, offset mi228
    mov cx,32h
    mov si,dx
    mul cx
    sub dx,dx
    add bx,ax
    adc si,dx
    mov word ptr [bp-18h],bx
    mov word ptr [bp-16h],si
lbl280b:
    call mf237
    cmp dx,word ptr [bp-16h]
    jg short lbl2A3f
    jl short lbl291f
    cmp ax,word ptr [bp-18h]
    jnc short lbl2A3f
lbl291f:
    call mf243
    or ax,ax
    jnz short lbl2A3f
    call mf246
    or ax,ax
    jz short lbl280b
lbl2A3f:
    call mf249
    call mf250
    cmp ax, offset mi251
    jnz short lbl2BBf
    push ax
    call mf254
    add sp,2h
lbl2BBf:
    push word ptr [bp-28h]
    call mf257
    add sp,2h
    lea ax,word ptr [bp-14h]
    push ss
    push ax
    call mf262
    add sp,4h
    lea ax,word ptr [bp-14h]
    push ss
    push ax
    call mf267
    add sp,4h
    call mf269
    push word ptr [bp-26h]
    call mf271
    add sp,2h
    jmp short lbl302f
lbl2F2f:
    mov ax,2h
    mov dx,0F001h
    push dx
    push ax
    call mf278
    add sp,4h
lbl302f:
    pop si
    pop di
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
