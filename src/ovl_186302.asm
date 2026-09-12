_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi3:NEAR
    EXTRN mi7:NEAR
    EXTRN mf34:FAR
    EXTRN mf42:FAR
    EXTRN mf46:FAR
    EXTRN mf50:FAR
    EXTRN mf58:FAR
    EXTRN mf68:FAR
    EXTRN mf77:FAR
    EXTRN mf85:FAR
    EXTRN mf93:FAR
    EXTRN mf100:FAR
    EXTRN mf106:FAR
    EXTRN mf112:FAR
    EXTRN mf114:FAR
    EXTRN mf117:FAR
    EXTRN mf124:FAR
    EXTRN mf132:FAR
    EXTRN mf137:FAR
    EXTRN md147:NEAR
    EXTRN mf153:FAR
    EXTRN mf166:FAR
    EXTRN mf175:FAR
    EXTRN mf182:FAR
    EXTRN mf190:FAR
    EXTRN mf204:FAR
    EXTRN mf223:FAR
    EXTRN mf232:FAR
    EXTRN mf240:FAR
    EXTRN mf246:FAR
    EXTRN mf254:FAR
    EXTRN mf262:FAR
    EXTRN mf270:FAR
    EXTRN mf275:FAR
    EXTRN mf284:FAR
    EXTRN mf290:FAR
    EXTRN mf297:FAR
    EXTRN mf302:FAR
    EXTRN mf307:FAR
    EXTRN mf313:FAR
    EXTRN mf321:FAR
    EXTRN mf331:FAR
    EXTRN mf344:FAR
    EXTRN mf358:FAR
    EXTRN mf365:FAR
    EXTRN mf371:FAR
    EXTRN mf377:FAR
    EXTRN mf382:FAR
    EXTRN mf382:FAR
    EXTRN mf382:FAR
    EXTRN mf382:FAR
    EXTRN mf382:FAR
    EXTRN mf382:FAR
    EXTRN mf382:FAR
    EXTRN mf382:FAR
    EXTRN mf382:FAR
    EXTRN mf382:FAR
    EXTRN mf382:FAR
    EXTRN mf382:FAR
    EXTRN mf382:FAR
    EXTRN mf382:FAR
    EXTRN mf382:FAR
    EXTRN mf382:FAR
    EXTRN mf382:FAR
    EXTRN mf382:FAR
    EXTRN mf382:FAR
    EXTRN mf382:FAR
    EXTRN mf382:FAR
    EXTRN mf382:FAR
    EXTRN mf382:FAR
    EXTRN mf382:FAR
    EXTRN mf382:FAR
    EXTRN mf382:FAR
    EXTRN mf382:FAR
    EXTRN mf382:FAR
    EXTRN mf382:FAR
    EXTRN mf382:FAR
    EXTRN mf382:FAR
    EXTRN mf382:FAR
    EXTRN mf382:FAR
    EXTRN mf382:FAR
    EXTRN mf382:FAR
    EXTRN mf382:FAR
    EXTRN mf382:FAR
    EXTRN mf382:FAR
    EXTRN mf382:FAR
    EXTRN mf382:FAR
    EXTRN mf382:FAR
    EXTRN mf382:FAR
    EXTRN mf382:FAR
    EXTRN mf382:FAR
mnem_unit:
    push bp
    mov bp,sp
    mov ax,word ptr [bp+6h]
    sub ax, offset mi3
    jz short lbl0Ef
    jmp near ptr lbl3DEf
lbl0Ef:
    mov ax,word ptr ds:[6A06h]
    cmp ax, offset mi7
    jnz short lbl19f
    jmp near ptr lbl372f
lbl19f:
    jna short lbl1Ef
    jmp near ptr lbl3DEf
lbl1Ef:
    cmp al,3Fh
    jnz short lbl25f
    jmp near ptr lbl1F6f
lbl25f:
    ja short lbl32f
    sub al,13h
    jz short lbl44f
    sub al,25h
    jz short lbl8Af
    jmp near ptr lbl3DEf
lbl32f:
    sub al,44h
    jnz short lbl39f
    jmp near ptr lbl22Ef
lbl39f:
    dec al
    jnz short lbl40f
    jmp near ptr lbl35Af
lbl40f:
    jmp near ptr lbl3DEf
    nop
lbl44f:
    cmp byte ptr ds:[31Eh],0h
    jz short lbl6Ef
    push word ptr ds:[6A04h]
    mov ax,2h
    push ax
    call mf34
    mov sp,bp
    push dx
    push ax
    mov ax,7h
    mov dx,0F01Fh
    push dx
    push ax
    call mf42
lbl69b:
    mov sp,bp
    jmp short lbl84f
    nop
lbl6Ef:
    call mf46
    push ax
    mov ax,155h
    push ax
    call mf50
    mov sp,bp
    mov byte ptr ds:[31Eh],1h
lbl84b:
lbl84f:
    mov ax,1h
    jmp near ptr lbl3E0f
lbl8Af:
    mov ax,0CEh
    push ax
    push word ptr ds:[6A04h]
    call mf58
    mov sp,bp
    or ax,ax
    jnz short lblB8f
    cmp word ptr ds:[6A02h],0CEh
    jnz short lblB8f
    push ax
    push word ptr ds:[6A04h]
    mov ax,44h
lblADb:
    push ax
lblAEb:
    call mf68
    mov sp,bp
    jmp near ptr lbl3E0f
lblB8f:
    cmp word ptr ds:[6A02h],0D8h
    jz short lblC3f
    jmp near ptr lbl158f
lblC3f:
    push word ptr ds:[6A02h]
    mov ax,2h
    push ax
    call mf77
    mov sp,bp
    push dx
    push ax
    mov ax,0Dh
    mov dx,0F01Fh
    push dx
    push ax
    call mf85
    mov sp,bp
    xor ax,ax
    push ax
    mov cx,0EDh
    push cx
    mov cx,0EEh
    push cx
    call mf93
    mov sp,bp
    xor ax,ax
    push ax
    push ax
    mov ax,0D8h
    push ax
    call mf100
    mov sp,bp
    mov ax,163h
    push ax
    mov ax,0CEh
    push ax
    call mf106
    mov sp,bp
    mov byte ptr ds:[311h],1h
    mov ax,2FFFh
    push ds
    push ax
    call mf112
    mov sp,bp
lbl124b:
    call mf114
    or ax,ax
    jnz short lbl124b
    call mf117
    xor ax,ax
    push ax
    mov ax,1h
    push ax
    mov cx,8h
    push cx
    call mf124
    mov sp,bp
    mov ax,1h
    push ax
    mov ax,13h
    push ax
    mov ax,8026h
    push ax
    call mf132
    jmp near ptr lbl69b
lbl158f:
    mov ax,8h
    push ax
    push word ptr ds:[6A02h]
    call mf137
    mov sp,bp
    or ax,ax
    jnz short lbl1BEf
    mov es, ds:[5AD6h]
    mov bx,word ptr ds:[6A02h]
    mov ax,bx
    add bx,bx
    add bx,ax
    add bx,bx
    cmp byte ptr es:[bx+md147],5h
    jz short lbl1BEf
    mov ax,1h
    push ax
    mov ax,0CEh
    push ax
    call mf153
    mov sp,bp
    or ax,ax
    jz short lbl1A6f
    push word ptr ds:[6A02h]
    mov ax,0CEh
    push ax
    push word ptr ds:[6A06h]
    jmp near ptr lblAEb
    nop
lbl1A6f:
    push word ptr ds:[6A04h]
    mov ax,22h
    push ax
    call mf166
    add sp,4h
    push dx
    push ax
    mov ax,0Fh
    jmp near ptr lbl29Df
lbl1BEf:
    push word ptr ds:[6A02h]
    mov ax,2h
    push ax
    call mf175
    add sp,4h
    push dx
    push ax
    push word ptr ds:[6A04h]
    mov ax,2h
    push ax
    call mf182
    add sp,4h
    push dx
    push ax
    mov ax,0Eh
    mov dx,0F01Fh
    push dx
    push ax
    call mf190
    add sp,0Ch
    jmp near ptr lbl84b
    nop
lbl1F6f:
    cmp byte ptr ds:[31Eh],0h
    jnz short lbl20Af
lbl1FDb:
    xor ax,ax
    push ax
    push word ptr ds:[6A04h]
    mov ax,13h
    jmp near ptr lblADb
lbl20Af:
    mov ax,0CEh
    push ax
    push word ptr ds:[6A04h]
    call mf204
    add sp,4h
    or ax,ax
    jz short lbl224f
    mov ax,300Ah
    jmp short lbl227f
    nop
lbl224f:
    mov ax,300Eh
lbl227f:
    push ds
    push ax
    mov ax,10h
    jmp short lbl29Df
lbl22Ef:
    cmp word ptr ds:[256h],0EDh
    jz short lbl239f
    jmp near ptr lbl32Af
lbl239f:
    mov ax,0CEh
    push ax
    mov ax,0EEh
    push ax
    call mf223
    add sp,4h
    or ax,ax
    jz short lbl250f
    jmp near ptr lbl32Af
lbl250f:
    mov ax,1h
    push ax
    mov ax,0CEh
    push ax
    call mf232
    add sp,4h
    or ax,ax
    jnz short lbl274f
    mov ax,8h
    mov dx,0F01Fh
    push dx
    push ax
    call mf240
    jmp near ptr lbl324f
lbl274f:
    mov ax,0Eh
    push ax
    mov ax,0CEh
    push ax
    call mf246
    add sp,4h
    or ax,ax
    jnz short lbl2AEf
    mov ax,0CEh
    push ax
    mov ax,12h
    push ax
    call mf254
    add sp,4h
    push dx
    push ax
    mov ax,9h
lbl29Db:
lbl29Df:
    mov dx,0F01Fh
    push dx
    push ax
    call mf262
    add sp,8h
    jmp near ptr lbl84b
    nop
lbl2AEf:
    mov ax,0Ah
    mov dx,0F01Fh
    push dx
    push ax
    call mf270
    add sp,4h
    mov ax,0Ah
    push ax
    push word ptr ds:[6A04h]
    call mf275
    add sp,4h
    or ax,ax
    jnz short lbl2E3f
    push ax
    mov ax,1h
    push ax
    mov ax,7h
    push ax
    call mf284
    add sp,6h
lbl2E3f:
    mov ax,164h
    push ax
    mov ax,0CEh
    push ax
    call mf290
    add sp,4h
    mov ax,1h
    push ax
    mov ax,0CEh
    push ax
    push word ptr ds:[6A04h]
    call mf297
    add sp,6h
    mov ax,0Ah
    push ax
    push word ptr ds:[6A04h]
    call mf302
    add sp,4h
    mov ax,5h
    push ax
    push word ptr ds:[6A04h]
    call mf307
lbl324b:
lbl324f:
    add sp,4h
    jmp near ptr lbl84b
lbl32Af:
    mov ax,0CEh
    push ax
    push word ptr ds:[6A04h]
    call mf313
    add sp,4h
    or ax,ax
    jnz short lbl341f
    jmp near ptr lbl84b
lbl341f:
    push word ptr ds:[6A04h]
    mov ax,2h
    push ax
    call mf321
    add sp,4h
    push dx
    push ax
    mov ax,0Bh
    jmp near ptr lbl29Db
    nop
lbl35Af:
    push word ptr ds:[6A04h]
    mov ax,2h
    push ax
    call mf331
    add sp,4h
    push dx
    push ax
    mov ax,0Ch
    jmp near ptr lbl29Db
lbl372f:
    cmp byte ptr ds:[31Eh],0h
    jnz short lbl37Cf
    jmp near ptr lbl1FDb
lbl37Cf:
    mov ax,0CEh
    push ax
    mov ax,0EEh
    push ax
    call mf344
    add sp,4h
    or ax,ax
    jz short lbl396f
    mov ax,12h
    jmp short lbl399f
    nop
lbl396f:
    mov ax,13h
lbl399f:
    mov dx,0F01Fh
    push dx
    push ax
    mov ax,11h
    push dx
    push ax
    call mf358
    add sp,8h
    xor ax,ax
    push ax
    mov ax,0EDh
    push ax
    push word ptr ds:[6A04h]
    call mf365
    add sp,6h
    mov ax,163h
    push ax
    mov ax,0CEh
    push ax
    call mf371
    add sp,4h
    mov ax,2h
    push ax
    mov ax,19h
    push ax
    call mf377
    jmp near ptr lbl324b
lbl3DEf:
    xor ax,ax
lbl3E0f:
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
