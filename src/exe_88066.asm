_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf15:FAR
    EXTRN mf23:FAR
    EXTRN mf37:FAR
    EXTRN mf47:FAR
    EXTRN mf58:FAR
    EXTRN mf68:FAR
    EXTRN mf80:FAR
    EXTRN mf90:FAR
    EXTRN mf102:FAR
    EXTRN mf112:FAR
    EXTRN mf125:FAR
    EXTRN mf135:FAR
    EXTRN mf146:FAR
    EXTRN mf156:FAR
    EXTRN mf167:FAR
    EXTRN mf177:FAR
    EXTRN mf190:FAR
    EXTRN mf200:FAR
    EXTRN mf208:FAR
    EXTRN mf217:FAR
    EXTRN mf220:FAR
    EXTRN mf226:FAR
    EXTRN mf229:FAR
    EXTRN mf235:FAR
    EXTRN mf238:FAR
    EXTRN mf244:FAR
    EXTRN mf247:FAR
    EXTRN mf266:FAR
    EXTRN mf272:FAR
    EXTRN mf276:FAR
    EXTRN mf279:FAR
    EXTRN mf282:FAR
    EXTRN mf289:FAR
    EXTRN mf293:FAR
    EXTRN mf296:FAR
    EXTRN mf299:FAR
    EXTRN mf302:FAR
    EXTRN mf308:FAR
    EXTRN mf311:FAR
    EXTRN mf316:FAR
    EXTRN mf320:FAR
    EXTRN mf320:FAR
    EXTRN mf320:FAR
    EXTRN mf320:FAR
    EXTRN mf320:FAR
    EXTRN mf320:FAR
    EXTRN mf320:FAR
    EXTRN mf320:FAR
    EXTRN mf320:FAR
    EXTRN mf320:FAR
    EXTRN mf320:FAR
    EXTRN mf320:FAR
    EXTRN mf320:FAR
    EXTRN mf320:FAR
    EXTRN mf320:FAR
    EXTRN mf320:FAR
    EXTRN mf320:FAR
    EXTRN mf320:FAR
    EXTRN mf320:FAR
    EXTRN mf320:FAR
    EXTRN mf320:FAR
    EXTRN mf320:FAR
    EXTRN mf320:FAR
    EXTRN mf320:FAR
    EXTRN mf320:FAR
    EXTRN mf320:FAR
    EXTRN mf320:FAR
    EXTRN mf320:FAR
    EXTRN mf320:FAR
    EXTRN mf320:FAR
    EXTRN mf320:FAR
    EXTRN mf320:FAR
    EXTRN mf320:FAR
    EXTRN mf320:FAR
    EXTRN mf320:FAR
    EXTRN mf320:FAR
    EXTRN mf320:FAR
    EXTRN mf320:FAR
    EXTRN mf320:FAR
    EXTRN mf320:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,6h
    push si
    test byte ptr [bp+0Eh],20h
    jnz short lbl1Ff
    mov al,byte ptr [bp+0Eh]
    and al,4h
    cmp al,4h
    jnz short lbl43f
    mov al,byte ptr [bp+0Eh]
    and al,10h
    cmp al,10h
    jz short lbl43f
lbl1Ff:
    push word ptr ds:[432Ch]
    call mf15
    add sp,2h
    push word ptr [bp+0Ch]
    push word ptr [bp+0Ah]
    push word ptr [bp+8h]
    push word ptr [bp+6h]
    mov ax,2h
    push ax
    call mf23
    add sp,0Ah
lbl43f:
    test byte ptr [bp+0Eh],10h
    jnz short lbl4Cf
    jmp near ptr lbl26Cf
lbl4Cf:
    test byte ptr [bp+0Eh],4h
    jnz short lbl55f
    jmp near ptr lbl160f
lbl55f:
    mov ax,word ptr [bp+0Ch]
    mov word ptr [bp-4h],ax
    cmp ax,word ptr [bp+8h]
    jng short lbl96f
lbl60b:
    push word ptr [bp+6h]
    push word ptr [bp-4h]
    call mf37
    add ax,word ptr ds:[432Eh]
    mov word ptr [bp-6h],ax
    mov ax,word ptr ds:[4334h]
    cmp word ptr [bp-6h],ax
    jng short lbl7Df
    mov word ptr [bp-6h],ax
lbl7Df:
    push word ptr [bp+6h]
    push word ptr [bp-4h]
    push word ptr [bp-6h]
    call mf47
    mov ax,word ptr [bp+8h]
    dec word ptr [bp-4h]
    cmp word ptr [bp-4h],ax
    jg short lbl60b
lbl96f:
    mov ax,word ptr [bp+6h]
    mov word ptr [bp-2h],ax
    cmp ax,word ptr [bp+0Ah]
    jg short lblD7f
lblA1b:
    push word ptr [bp-2h]
    push word ptr [bp+8h]
    call mf58
    add ax,word ptr ds:[432Eh]
    mov word ptr [bp-6h],ax
    mov ax,word ptr ds:[4334h]
    cmp word ptr [bp-6h],ax
    jng short lblBEf
    mov word ptr [bp-6h],ax
lblBEf:
    push word ptr [bp-2h]
    push word ptr [bp+8h]
    push word ptr [bp-6h]
    call mf68
    mov ax,word ptr [bp+0Ah]
    inc word ptr [bp-2h]
    cmp word ptr [bp-2h],ax
    jng short lblA1b
lblD7f:
    mov ax,word ptr [bp+8h]
    inc ax
    mov word ptr [bp-4h],ax
    cmp ax,word ptr [bp+0Ch]
    jnl short lbl119f
lblE3b:
    push word ptr [bp+0Ah]
    push word ptr [bp-4h]
    call mf80
    sub ax,word ptr ds:[4330h]
    mov word ptr [bp-6h],ax
    mov ax,word ptr ds:[4332h]
    cmp word ptr [bp-6h],ax
    jnl short lbl100f
    mov word ptr [bp-6h],ax
lbl100f:
    push word ptr [bp+0Ah]
    push word ptr [bp-4h]
    push word ptr [bp-6h]
    call mf90
    mov ax,word ptr [bp+0Ch]
    inc word ptr [bp-4h]
    cmp word ptr [bp-4h],ax
    jl short lblE3b
lbl119f:
    mov ax,word ptr [bp+0Ah]
    mov word ptr [bp-2h],ax
    cmp ax,word ptr [bp+6h]
    jg short lbl127f
    jmp near ptr lbl3A2f
lbl127b:
lbl127f:
    push word ptr [bp-2h]
    push word ptr [bp+0Ch]
    call mf102
    sub ax,word ptr ds:[4330h]
    mov word ptr [bp-6h],ax
    mov ax,word ptr ds:[4332h]
    cmp word ptr [bp-6h],ax
    jnl short lbl144f
    mov word ptr [bp-6h],ax
lbl144f:
    push word ptr [bp-2h]
    push word ptr [bp+0Ch]
    push word ptr [bp-6h]
    call mf112
    mov ax,word ptr [bp+6h]
    dec word ptr [bp-2h]
    cmp word ptr [bp-2h],ax
    jg short lbl127b
    jmp near ptr lbl3A2f
lbl160f:
    mov ax,word ptr [bp+0Ch]
    dec ax
    mov word ptr [bp-4h],ax
    cmp ax,word ptr [bp+8h]
    jng short lbl1A2f
lbl16Cb:
    push word ptr [bp+6h]
    push word ptr [bp-4h]
    call mf125
    sub ax,word ptr ds:[4330h]
    mov word ptr [bp-6h],ax
    mov ax,word ptr ds:[4332h]
    cmp word ptr [bp-6h],ax
    jnl short lbl189f
    mov word ptr [bp-6h],ax
lbl189f:
    push word ptr [bp+6h]
    push word ptr [bp-4h]
    push word ptr [bp-6h]
    call mf135
    mov ax,word ptr [bp+8h]
    dec word ptr [bp-4h]
    cmp word ptr [bp-4h],ax
    jg short lbl16Cb
lbl1A2f:
    mov ax,word ptr [bp+6h]
    mov word ptr [bp-2h],ax
    cmp ax,word ptr [bp+0Ah]
    jnl short lbl1E3f
lbl1ADb:
    push word ptr [bp-2h]
    push word ptr [bp+8h]
    call mf146
    sub ax,word ptr ds:[4330h]
    mov word ptr [bp-6h],ax
    mov ax,word ptr ds:[4332h]
    cmp word ptr [bp-6h],ax
    jnl short lbl1CAf
    mov word ptr [bp-6h],ax
lbl1CAf:
    push word ptr [bp-2h]
    push word ptr [bp+8h]
    push word ptr [bp-6h]
    call mf156
    mov ax,word ptr [bp+0Ah]
    inc word ptr [bp-2h]
    cmp word ptr [bp-2h],ax
    jl short lbl1ADb
lbl1E3f:
    mov ax,word ptr [bp+8h]
    mov word ptr [bp-4h],ax
    cmp word ptr [bp+0Ch],ax
    jl short lbl224f
lbl1EEb:
    push word ptr [bp+0Ah]
    push word ptr [bp-4h]
    call mf167
    add ax,word ptr ds:[432Eh]
    mov word ptr [bp-6h],ax
    mov ax,word ptr ds:[4334h]
    cmp word ptr [bp-6h],ax
    jng short lbl20Bf
    mov word ptr [bp-6h],ax
lbl20Bf:
    push word ptr [bp+0Ah]
    push word ptr [bp-4h]
    push word ptr [bp-6h]
    call mf177
    mov ax,word ptr [bp+0Ch]
    inc word ptr [bp-4h]
    cmp word ptr [bp-4h],ax
    jng short lbl1EEb
lbl224f:
    mov ax,word ptr [bp+0Ah]
    dec ax
    mov word ptr [bp-2h],ax
    cmp ax,word ptr [bp+6h]
    jnl short lbl233f
    jmp near ptr lbl3A2f
lbl233b:
lbl233f:
    push word ptr [bp-2h]
    push word ptr [bp+0Ch]
    call mf190
    add ax,word ptr ds:[432Eh]
    mov word ptr [bp-6h],ax
    mov ax,word ptr ds:[4334h]
    cmp word ptr [bp-6h],ax
    jng short lbl250f
    mov word ptr [bp-6h],ax
lbl250f:
    push word ptr [bp-2h]
    push word ptr [bp+0Ch]
    push word ptr [bp-6h]
    call mf200
    mov ax,word ptr [bp+6h]
    dec word ptr [bp-2h]
    cmp word ptr [bp-2h],ax
    jnl short lbl233b
    jmp near ptr lbl3A2f
lbl26Cf:
    xor ax,ax
    push ax
    call mf208
    add sp,2h
    test byte ptr [bp+0Eh],2h
    jz short lbl2E0f
    push word ptr [bp+6h]
    mov ax,word ptr [bp+8h]
    dec ax
    push ax
    mov si,ax
    call mf217
    push word ptr [bp+0Ah]
    push si
    call mf220
    push word ptr [bp+6h]
    mov ax,word ptr [bp+0Ch]
    inc ax
    push ax
    mov si,ax
    call mf226
    push word ptr [bp+0Ah]
    push si
    call mf229
    mov ax,word ptr [bp+6h]
    dec ax
    push ax
    push word ptr [bp+8h]
    mov si,ax
    call mf235
    push si
    push word ptr [bp+0Ch]
    call mf238
    mov ax,word ptr [bp+0Ah]
    inc ax
    push ax
    push word ptr [bp+8h]
    mov si,ax
    call mf244
    push si
    push word ptr [bp+0Ch]
    call mf247
    jmp short lbl306f
    nop
lbl2E0f:
    test byte ptr [bp+0Eh],1h
    jz short lbl306f
    mov ax,word ptr [bp+0Ch]
    inc ax
    push ax
    mov ax,word ptr [bp+0Ah]
    inc ax
    push ax
    mov ax,word ptr [bp+8h]
    dec ax
    push ax
    mov ax,word ptr [bp+6h]
    dec ax
    push ax
    mov ax,1h
    push ax
    call mf266
    add sp,0Ah
lbl306f:
    test byte ptr [bp+0Eh],4h
    jz short lbl33Ef
    mov ax,0Fh
    push ax
    call mf272
    add sp,2h
    push word ptr [bp+6h]
    push word ptr [bp+0Ch]
    call mf276
    push word ptr [bp+6h]
    push word ptr [bp+8h]
    call mf279
    push word ptr [bp+0Ah]
    push word ptr [bp+8h]
    call mf282
    mov ax,6h
    jmp short lbl374f
lbl33Ef:
    test byte ptr [bp+0Eh],8h
    jz short lbl3A2f
    mov ax,6h
    push ax
    call mf289
    add sp,2h
    push word ptr [bp+6h]
    push word ptr [bp+0Ch]
    call mf293
    push word ptr [bp+6h]
    push word ptr [bp+8h]
    call mf296
    push word ptr [bp+0Ah]
    push word ptr [bp+8h]
    call mf299
    mov ax,0Fh
lbl374f:
    push ax
    call mf302
    add sp,2h
    mov ax,word ptr [bp+6h]
    inc ax
    push ax
    push word ptr [bp+0Ch]
    call mf308
    push word ptr [bp+0Ah]
    push word ptr [bp+0Ch]
    call mf311
    push word ptr [bp+0Ah]
    mov ax,word ptr [bp+8h]
    inc ax
    push ax
    call mf316
lbl3A2f:
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
