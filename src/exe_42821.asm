_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf7:FAR
    EXTRN mf17:FAR
    EXTRN mf23:FAR
    EXTRN mf27:FAR
    EXTRN mf37:FAR
    EXTRN mf41:FAR
    EXTRN mf46:FAR
    EXTRN mf68:FAR
    EXTRN mf75:FAR
    EXTRN mi77:NEAR
    EXTRN mi94:NEAR
    EXTRN mf139:FAR
    EXTRN mf144:FAR
    EXTRN mf149:FAR
    EXTRN mf158:FAR
    EXTRN mf164:FAR
    EXTRN mf171:FAR
    EXTRN mf179:FAR
    EXTRN mf193:FAR
    EXTRN mf199:FAR
    EXTRN mi202:NEAR
    EXTRN mf207:FAR
    EXTRN mf211:FAR
    EXTRN mf215:FAR
    EXTRN mf242:FAR
    EXTRN mf248:FAR
    EXTRN mf251:FAR
    EXTRN mf259:FAR
    EXTRN mi264:NEAR
    EXTRN mf268:FAR
    EXTRN mi271:NEAR
    EXTRN mf309:FAR
    EXTRN mf323:FAR
    EXTRN mf326:FAR
    EXTRN mf331:FAR
    EXTRN mf336:FAR
    EXTRN mf339:FAR
    EXTRN mf346:FAR
    EXTRN mf346:FAR
    EXTRN mf346:FAR
    EXTRN mf346:FAR
    EXTRN mf346:FAR
    EXTRN mf346:FAR
    EXTRN mf346:FAR
    EXTRN mf346:FAR
    EXTRN mf346:FAR
    EXTRN mf346:FAR
    EXTRN mf346:FAR
    EXTRN mf346:FAR
    EXTRN mf346:FAR
    EXTRN mf346:FAR
    EXTRN mf346:FAR
    EXTRN mf346:FAR
    EXTRN mf346:FAR
    EXTRN mf346:FAR
    EXTRN mf346:FAR
    EXTRN mf346:FAR
    EXTRN mf346:FAR
    EXTRN mf346:FAR
    EXTRN mf346:FAR
    EXTRN mf346:FAR
    EXTRN mf346:FAR
    EXTRN mf346:FAR
    EXTRN mf346:FAR
    EXTRN mf346:FAR
    EXTRN mf346:FAR
    EXTRN mf346:FAR
    EXTRN mf346:FAR
    EXTRN mf346:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,58h
    push di
    push si
    xor ax,ax
    push ax
    call mf7
    add sp,2h
    mov word ptr [bp-46h],ax
    mov ax,word ptr [bp+0Ch]
    or ax,word ptr [bp+0Ah]
    jnz short lbl26f
    mov word ptr [bp+0Ah],0DEh
    mov word ptr [bp+0Ch],ds
lbl26f:
    mov ax,1h
    push ax
    call mf17
    add sp,2h
    mov ax,0FFFFh
    push ax
    mov ax,0Fh
    push ax
    call mf23
    add sp,4h
    push word ptr [bp+8h]
    push word ptr [bp+6h]
    call mf27
    add sp,4h
    mov es,dx
    mov bx,ax
    mov word ptr [bp+6h],ax
    mov word ptr [bp+8h],es
    cmp byte ptr es:[bx],0h
    jz short lbl8Af
    xor ax,ax
    push ax
    call mf37
    add sp,2h
    push word ptr [bp+8h]
    push word ptr [bp+6h]
    call mf41
    add sp,4h
    mov word ptr [bp-2Ch],ax
    mov ax,0FFFFh
    push ax
    call mf46
    add sp,2h
    jmp short lbl8Ff
lbl8Af:
    mov word ptr [bp-2Ch],0h
lbl8Ff:
    mov word ptr [bp-2Eh],3Ch
    mov word ptr [bp-28h],0h
    les bx, dword ptr [bp+0Ah]
    mov ax,word ptr es:[bx+2h]
    or ax,word ptr es:[bx]
    jz short lbl103f
    mov word ptr [bp-4Ah],bx
    mov word ptr [bp-48h],es
lblABb:
    les bx, dword ptr es:[bx]
    cmp byte ptr es:[bx],0h
    jz short lbl103f
    les bx, dword ptr [bp-4Ah]
    les bx, dword ptr es:[bx]
    mov al,byte ptr es:[bx]
    cbw
    push ax
    mov si,bx
    mov di,es
    call mf68
    add sp,2h
    mov es,di
    mov byte ptr es:[si],al
    les bx, dword ptr [bp-4Ah]
    push word ptr es:[bx+2h]
    push word ptr es:[bx]
    call mf75
    add sp,4h
    add ax, offset mi77
    mov word ptr [bp-30h],ax
    cmp ax,word ptr [bp-2Eh]
    jng short lblF0f
    mov word ptr [bp-2Eh],ax
lblF0f:
    inc word ptr [bp-28h]
    add word ptr [bp-4Ah],4h
    les bx, dword ptr [bp-4Ah]
    mov ax,word ptr es:[bx+2h]
    or ax,word ptr es:[bx]
    jnz short lblABb
lbl103f:
    mov ax,word ptr [bp-28h]
    mov word ptr [bp-32h],ax
    mov ax,word ptr [bp-2Eh]
    cmp ax,word ptr [bp-2Ch]
    jnl short lbl114f
    mov ax,word ptr [bp-2Ch]
lbl114f:
    add ax, offset mi94
    mov cx,ax
    sub ax,word ptr [bp-2Ch]
    cwd
    sub ax,dx
    sar ax,1
    mov word ptr [bp-42h],ax
    mov ax,cx
    sub ax,word ptr [bp-2Eh]
    cwd
    sub ax,dx
    sar ax,1
    mov word ptr [bp-44h],ax
    mov ax,140h
    sub ax,cx
    cwd
    sub ax,dx
    sar ax,1
    mov word ptr [bp-3Ah],ax
    mov word ptr [bp-56h],cx
    cmp word ptr [bp-2Ch],0h
    jng short lbl14Cf
    mov ax,12h
    jmp short lbl14Ff
lbl14Cf:
    mov ax,4h
lbl14Ff:
    mov cl,4h
    mov dx,word ptr [bp-32h]
    shl dx,cl
    add ax,dx
    mov cx,ax
    mov ax,0C3h
    sub ax,cx
    cwd
    sub ax,dx
    sar ax,1
    mov word ptr [bp-3Ch],ax
    add ax,cx
    push ax
    mov cx,word ptr [bp-3Ah]
    add cx,word ptr [bp-56h]
    push cx
    push word ptr [bp-3Ch]
    push word ptr [bp-3Ah]
    mov si,ax
    mov di,cx
    call mf139
    add sp,8h
    lea ax,word ptr [bp-14h]
    push ss
    push ax
    call mf144
    add sp,4h
    xor ax,ax
    push ax
    push ax
    call mf149
    add sp,4h
    push si
    push di
    push word ptr [bp-3Ch]
    push word ptr [bp-3Ah]
    lea ax,word ptr [bp-14h]
    push ss
    push ax
    call mf158
    add sp,0Ch
    push si
    push di
    push word ptr [bp-3Ch]
    push word ptr [bp-3Ah]
    call mf164
    add sp,8h
    mov word ptr [bp-1Eh],ax
    push si
    push di
    push word ptr [bp-3Ch]
    push word ptr [bp-3Ah]
    call mf171
    add sp,8h
    mov ax,14h
    push ax
    push si
    push di
    push word ptr [bp-3Ch]
    push word ptr [bp-3Ah]
    call mf179
    add sp,0Ah
    mov ax,14h
    push ax
    lea ax,word ptr [si-1h]
    push ax
    lea ax,word ptr [di-1h]
    push ax
    mov ax,word ptr [bp-3Ch]
    inc ax
    push ax
    mov ax,word ptr [bp-3Ah]
    inc ax
    push ax
    call mf193
    add sp,0Ah
    cmp word ptr [bp-2Ch],0h
    jng short lbl247f
    xor ax,ax
    push ax
    call mf199
    add sp,2h
    mov ax,word ptr [bp-3Ch]
    add ax, offset mi202
    push ax
    mov ax,word ptr [bp-42h]
    add ax,word ptr [bp-3Ah]
    push ax
    call mf207
    add sp,4h
    push word ptr [bp+8h]
    push word ptr [bp+6h]
    call mf211
    add sp,4h
    mov ax,0FFFFh
    push ax
    call mf215
    add sp,2h
lbl247f:
    cmp word ptr [bp-2Ch],0h
    jng short lbl252f
    mov ax,12h
    jmp short lbl255f
lbl252f:
    mov ax,4h
lbl255f:
    add ax,word ptr [bp-3Ch]
    mov word ptr [bp-34h],ax
    mov word ptr [bp-28h],0h
    cmp word ptr [bp-32h],0h
    jng short lbl2A9f
    mov ax,word ptr [bp+0Ah]
    mov dx,word ptr [bp+0Ch]
    mov word ptr [bp-4Eh],ax
    mov word ptr [bp-4Ch],dx
    mov ax,word ptr [bp-44h]
    add ax,word ptr [bp-3Ah]
    mov word ptr [bp-58h],ax
    mov ax,word ptr [bp-32h]
    mov word ptr [bp-50h],ax
lbl281b:
    push word ptr [bp-2Eh]
    les bx, dword ptr [bp-4Eh]
    push word ptr es:[bx+2h]
    push word ptr es:[bx]
    push word ptr [bp-34h]
    push word ptr [bp-58h]
    call mf242
    add sp,0Ah
    add word ptr [bp-34h],10h
    add word ptr [bp-4Eh],4h
    dec word ptr [bp-50h]
    jnz short lbl281b
lbl2A9f:
    call mf248
    mov ax,1h
    push ax
    call mf251
    add sp,2h
    mov word ptr [bp-20h],0h
lbl2BFb:
    lea ax,word ptr [bp-1Ch]
    push ss
    push ax
    mov cx,3FFh
    push cx
    call mf259
    add sp,6h
    mov ax,word ptr [bp-1Ch]
    dec ax
    jz short lbl2DEf
    sub ax, offset mi264
    jz short lbl334f
    jmp near ptr lbl365f
lbl2DEf:
    push word ptr [bp-16h]
    call mf268
    add sp,2h
    mov word ptr [bp-2Ah],ax
    cmp ax, offset mi271
    jnz short lbl2F6f
    mov ax,word ptr [bp-32h]
    jmp short lbl362f
lbl2F6f:
    mov word ptr [bp-28h],0h
    cmp word ptr [bp-32h],0h
    jng short lbl365f
    mov ax,word ptr [bp+0Ah]
    mov dx,word ptr [bp+0Ch]
    mov word ptr [bp-54h],ax
    mov word ptr [bp-52h],dx
lbl30Db:
    les bx, dword ptr [bp-54h]
    les bx, dword ptr es:[bx]
    mov al,byte ptr es:[bx]
    cbw
    cmp ax,word ptr [bp-2Ah]
    jz short lbl32Ef
    add word ptr [bp-54h],4h
    mov ax,word ptr [bp-32h]
    inc word ptr [bp-28h]
    cmp word ptr [bp-28h],ax
    jl short lbl30Db
    jmp short lbl365f
    nop
lbl32Ef:
    mov ax,word ptr [bp-28h]
    inc ax
    jmp short lbl362f
lbl334f:
    lea ax,word ptr [bp-26h]
    push ss
    push ax
    lea ax,word ptr [bp-24h]
    push ss
    push ax
    lea ax,word ptr [bp-22h]
    push ss
    push ax
    push word ptr [bp-18h]
    push word ptr [bp-1Ah]
    call mf309
    add sp,10h
    mov ax,word ptr [bp-1Eh]
    cmp word ptr [bp-22h],ax
    jnz short lbl365f
    cmp word ptr [bp-26h],5h
    jnz short lbl365f
    mov ax,word ptr [bp-24h]
lbl362f:
    mov word ptr [bp-20h],ax
lbl365f:
    cmp word ptr [bp-20h],0h
    jnz short lbl36Ef
    jmp near ptr lbl2BFb
lbl36Ef:
    push word ptr [bp-20h]
    push word ptr [bp-1Eh]
    call mf323
    add sp,4h
    push word ptr [bp-1Eh]
    call mf326
    add sp,2h
    lea ax,word ptr [bp-14h]
    push ss
    push ax
    call mf331
    add sp,4h
    lea ax,word ptr [bp-14h]
    push ss
    push ax
    call mf336
    add sp,4h
    push word ptr [bp-46h]
    call mf339
    add sp,2h
    mov ax,word ptr [bp-20h]
    pop si
    pop di
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
