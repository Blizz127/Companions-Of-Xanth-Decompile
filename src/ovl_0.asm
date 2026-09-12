_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf9:FAR
    EXTRN mf20:FAR
    EXTRN mf22:FAR
    EXTRN mf27:FAR
    EXTRN mf29:FAR
    EXTRN mf35:FAR
    EXTRN mf43:FAR
    EXTRN mf56:FAR
    EXTRN mf78:FAR
    EXTRN mf88:FAR
    EXTRN mf98:FAR
    EXTRN mf126:FAR
    EXTRN mf128:FAR
    EXTRN mi129:NEAR
    EXTRN mf133:FAR
    EXTRN mf137:FAR
    EXTRN mf148:FAR
    EXTRN mf152:FAR
    EXTRN mf160:FAR
    EXTRN mf166:FAR
    EXTRN mf168:FAR
    EXTRN mf180:FAR
    EXTRN mf187:FAR
    EXTRN mf194:FAR
    EXTRN mf199:FAR
    EXTRN mf201:FAR
    EXTRN mf239:FAR
    EXTRN mf250:FAR
    EXTRN mf261:FAR
    EXTRN mf267:FAR
    EXTRN mf272:FAR
    EXTRN mf274:FAR
    EXTRN mf277:FAR
    EXTRN mf280:FAR
    EXTRN mf293:FAR
    EXTRN mf297:FAR
    EXTRN mf299:FAR
    EXTRN mf300:FAR
    EXTRN mf301:FAR
    EXTRN mf302:FAR
    EXTRN mi303:NEAR
    EXTRN mf312:FAR
    EXTRN mf312:FAR
    EXTRN mf312:FAR
    EXTRN mf312:FAR
    EXTRN mf312:FAR
    EXTRN mf312:FAR
    EXTRN mf312:FAR
    EXTRN mf312:FAR
    EXTRN mf312:FAR
    EXTRN mf312:FAR
    EXTRN mf312:FAR
    EXTRN mf312:FAR
    EXTRN mf312:FAR
    EXTRN mf312:FAR
    EXTRN mf312:FAR
    EXTRN mf312:FAR
    EXTRN mf312:FAR
    EXTRN mf312:FAR
    EXTRN mf312:FAR
    EXTRN mf312:FAR
    EXTRN mf312:FAR
    EXTRN mf312:FAR
    EXTRN mf312:FAR
    EXTRN mf312:FAR
    EXTRN mf312:FAR
    EXTRN mf312:FAR
    EXTRN mf312:FAR
    EXTRN mf312:FAR
    EXTRN mf312:FAR
    EXTRN mf312:FAR
    EXTRN mf312:FAR
    EXTRN mf312:FAR
    EXTRN mf312:FAR
    EXTRN mf312:FAR
    EXTRN mf312:FAR
    EXTRN mf312:FAR
    EXTRN mf312:FAR
    EXTRN mf312:FAR
    EXTRN mf312:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,318h
    push di
    push si
    mov ax,398h
    cwd
    push dx
    push ax
    call mf9
    add sp,4h
    mov word ptr [bp-4h],ax
    mov word ptr [bp-2h],dx
    or dx,ax
    jnz short lbl24f
    jmp near ptr lbl37Ef
lbl24f:
    mov ax,2Eh
    push ax
    push word ptr [bp-2h]
    push word ptr [bp-4h]
    call mf20
    add sp,6h
    call mf22
    mov ax,1h
    push ax
    mov ax,6201h
    push ax
    call mf27
    add sp,4h
    call mf29
    or ax,ax
    jz short lbl57f
    jmp near ptr lbl340f
lbl57f:
    mov ax,6200h
    push ax
    call mf35
    add sp,2h
    xor ax,ax
    push ax
    mov cx,7Fh
    push cx
    mov cx,20Ah
    push cx
    call mf43
    add sp,6h
    xor ax,ax
    mov cx,180h
    lea di,word ptr [bp-310h]
    push ss
    pop es
    rep stosw
    sub cx,cx
    mov word ptr [bp-6h],cx
    mov word ptr [bp-8h],cx
    mov word ptr [bp-0Ah],ax
    mov word ptr [bp-0Ch],ax
    call mf56
    or ax,ax
    jz short lbl9Df
    jmp near ptr lbl186f
lbl9Df:
    mov ax,word ptr [bp-4h]
    mov dx,word ptr [bp-2h]
    mov word ptr [bp-316h],ax
    mov word ptr [bp-314h],dx
lblABb:
    cmp word ptr [bp-0Ah],2Eh
    jl short lblBAf
    cmp word ptr [bp-0Ch],20h
    jl short lblBAf
    jmp near ptr lbl186f
lblBAf:
    cmp word ptr [bp-0Ah],2Eh
    jnl short lblEAf
    mov ax,1h
    push ax
    mov ax,word ptr [bp-0Ah]
    add ax,6202h
    push ax
    push word ptr [bp-314h]
    push word ptr [bp-316h]
    call mf78
    add sp,8h
    or ax,ax
    jnz short lblE2f
    jmp near ptr lbl186f
lblE2f:
    add word ptr [bp-316h],14h
    inc word ptr [bp-0Ah]
lblEAf:
    cmp word ptr [bp-0Ch],20h
    jl short lblF3f
    jmp near ptr lbl17Af
lblF3f:
    call mf88
    cmp dx,word ptr [bp-6h]
    jl short lbl17Af
    jg short lbl104f
    cmp ax,word ptr [bp-8h]
    jna short lbl17Af
lbl104f:
    test byte ptr ds:[416Eh],60h
    jz short lbl11Af
    xor ax,ax
    push ax
    call mf98
    add sp,2h
    or ax,ax
    jz short lbl17Af
lbl11Af:
    inc word ptr [bp-0Ch]
    mov word ptr [bp-0Eh],0h
    lea ax,word ptr [bp-310h]
    mov word ptr [bp-312h],ax
    mov es, ds:[5A64h]
lbl12Eb:
    mov bx,word ptr [bp-0Eh]
    mov al,byte ptr es:[bx+6A24h]
    cbw
    imul word ptr [bp-0Ch]
    cwd
    and dx,1Fh
    add ax,dx
    mov cx,5h
    sar ax,cl
    mov bx,word ptr [bp-312h]
    inc word ptr [bp-312h]
    mov byte ptr [bx],al
    inc word ptr [bp-0Eh]
    lea ax,word ptr [bp-10h]
    cmp word ptr [bp-312h],ax
    jc short lbl12Eb
    lea ax,word ptr [bp-310h]
    push ss
    push ax
    call mf126
    add sp,4h
    call mf128
    add ax, offset mi129
    adc dx,0h
    mov word ptr [bp-8h],ax
    mov word ptr [bp-6h],dx
lbl17Af:
    call mf133
    or ax,ax
    jnz short lbl186f
    jmp near ptr lblABb
lbl186f:
    call mf137
    or ax,ax
    jz short lbl192f
    jmp near ptr lbl330f
lbl192f:
    cmp word ptr [bp-0Ah],2Eh
    jnl short lbl19Bf
    jmp near ptr lbl330f
lbl19Bb:
lbl19Bf:
    test byte ptr ds:[416Eh],60h
    jz short lbl1B2f
    mov ax,1h
    push ax
    call mf148
    add sp,2h
    or ax,ax
    jz short lbl19Bb
lbl1B2f:
    call mf152
    or ax,ax
    jz short lbl1BEf
    jmp near ptr lbl340f
lbl1BEf:
    mov ax,2Eh
    push ax
    push word ptr [bp-2h]
    push word ptr [bp-4h]
    call mf160
    add sp,6h
    mov ax,2Eh
    push ax
    push word ptr [bp-2h]
    push word ptr [bp-4h]
    call mf166
    add sp,6h
    call mf168
    or ax,ax
    jz short lbl1EEf
    jmp near ptr lbl340f
lbl1EEf:
    mov ax,1h
    push ax
    mov ax,6230h
    push ax
    mov ax,0Ah
    push ax
    push word ptr [bp-2h]
    push word ptr [bp-4h]
    call mf180
    add sp,0Ah
    mov word ptr [bp-10h],ax
lbl20Bb:
    test byte ptr ds:[416Eh],60h
    jz short lbl222f
    mov ax,2h
    push ax
    call mf187
    add sp,2h
    or ax,ax
    jz short lbl20Bb
lbl222f:
    push word ptr [bp-10h]
    push word ptr [bp-2h]
    push word ptr [bp-4h]
    call mf194
    add sp,6h
    push word ptr [bp-10h]
    push word ptr [bp-2h]
    push word ptr [bp-4h]
    call mf199
    add sp,6h
    call mf201
    or ax,ax
    jz short lbl250f
    jmp near ptr lbl340f
lbl250f:
    mov ax,38AFh
    push ds
    lea di,word ptr [bp-310h]
    mov si,6A24h
    push ss
    pop es
    mov ds,ax
    mov cx,180h
    rep movsw
    pop ds
    mov word ptr [bp-0Ah],3Fh
lbl26Ab:
    mov word ptr [bp-0Ch],2D3h
    lea ax,word ptr [bp-3Dh]
    mov word ptr [bp-318h],ax
    mov es, ds:[5A64h]
lbl27Ab:
    mov bx,word ptr [bp-0Ch]
    mov al,byte ptr es:[bx+6A24h]
    cbw
    imul word ptr [bp-0Ah]
    cwd
    and dx,3Fh
    add ax,dx
    mov cx,6h
    sar ax,cl
    mov bx,word ptr [bp-318h]
    inc word ptr [bp-318h]
    mov byte ptr [bx],al
    inc word ptr [bp-0Ch]
    lea ax,word ptr [bp-29h]
    cmp word ptr [bp-318h],ax
    jna short lbl27Ab
    lea ax,word ptr [bp-310h]
    push ss
    push ax
    call mf239
    add sp,4h
    dec word ptr [bp-0Ah]
    jns short lbl26Ab
    mov ax,6A24h
    mov cx,38AFh
    mov di,ax
    lea si,word ptr [bp-310h]
    mov es,cx
    mov cx,180h
    rep movsw
    call mf250
    or ax,ax
    jnz short lbl340f
    mov ax,1h
    push ax
    mov ax,623Ah
    push ax
    mov ax,14h
    push ax
    push word ptr [bp-2h]
    push word ptr [bp-4h]
    call mf261
    add sp,0Ah
    mov word ptr [bp-10h],ax
    push ax
    push word ptr [bp-2h]
    push word ptr [bp-4h]
    call mf267
    add sp,6h
    push word ptr [bp-10h]
    push word ptr [bp-2h]
    push word ptr [bp-4h]
    call mf272
    add sp,6h
    call mf274
    or ax,ax
    jnz short lbl340f
    call mf277
    mov ax,0BB8h
    push ax
    call mf280
    add sp,2h
    jmp short lbl340f
    nop
lbl330f:
    mov es, ds:[5A64h]
    mov di,6A24h
    lea si,word ptr [bp-310h]
    mov cx,180h
    rep movsw
lbl340f:
    mov ax,2Eh
    push ax
    push word ptr [bp-2h]
    push word ptr [bp-4h]
    call mf293
    add sp,6h
    push word ptr [bp-2h]
    push word ptr [bp-4h]
    call mf297
    add sp,4h
    call mf299
    call mf300
    call mf301
    call mf302
    cmp ax, offset mi303
    jnz short lbl37Ef
    mov ax,1h
    jmp short lbl380f
lbl37Ef:
    xor ax,ax
lbl380f:
    pop si
    pop di
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
