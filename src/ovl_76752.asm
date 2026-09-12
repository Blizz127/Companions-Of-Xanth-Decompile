_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi4:NEAR
    EXTRN mi12:NEAR
    EXTRN mi16:NEAR
    EXTRN mi18:NEAR
    EXTRN mf23:FAR
    EXTRN mf30:FAR
    EXTRN mf38:FAR
    EXTRN mf46:FAR
    EXTRN mf54:FAR
    EXTRN mi59:NEAR
    EXTRN mi63:NEAR
    EXTRN mi72:NEAR
    EXTRN mi78:NEAR
    EXTRN mi81:NEAR
    EXTRN mf90:FAR
    EXTRN mf97:FAR
    EXTRN mf107:FAR
    EXTRN mf121:FAR
    EXTRN mf129:FAR
    EXTRN mf136:FAR
    EXTRN mf144:FAR
    EXTRN mf150:FAR
    EXTRN mf158:FAR
    EXTRN mf171:FAR
    EXTRN mf177:FAR
    EXTRN mf185:FAR
    EXTRN mf206:FAR
    EXTRN mf214:FAR
    EXTRN mf222:FAR
    EXTRN mf236:FAR
    EXTRN mf240:FAR
    EXTRN mf246:FAR
    EXTRN mf250:FAR
    EXTRN mf256:FAR
    EXTRN mf264:FAR
    EXTRN mf269:FAR
    EXTRN mf278:FAR
    EXTRN mf283:FAR
    EXTRN mf288:FAR
    EXTRN mf294:FAR
    EXTRN mf302:FAR
    EXTRN mf311:FAR
    EXTRN mf319:FAR
    EXTRN mf327:FAR
    EXTRN mf331:FAR
    EXTRN mf337:FAR
    EXTRN mf350:FAR
    EXTRN mf363:FAR
    EXTRN mf371:FAR
    EXTRN mf380:FAR
    EXTRN mf390:FAR
    EXTRN mf398:FAR
    EXTRN mf411:FAR
    EXTRN mf428:FAR
    EXTRN mf428:FAR
    EXTRN mf428:FAR
    EXTRN mf428:FAR
    EXTRN mf428:FAR
    EXTRN mf428:FAR
    EXTRN mf428:FAR
    EXTRN mf428:FAR
    EXTRN mf428:FAR
    EXTRN mf428:FAR
    EXTRN mf428:FAR
    EXTRN mf428:FAR
    EXTRN mf428:FAR
    EXTRN mf428:FAR
    EXTRN mf428:FAR
    EXTRN mf428:FAR
    EXTRN mf428:FAR
    EXTRN mf428:FAR
    EXTRN mf428:FAR
    EXTRN mf428:FAR
    EXTRN mf428:FAR
    EXTRN mf428:FAR
    EXTRN mf428:FAR
    EXTRN mf428:FAR
    EXTRN mf428:FAR
    EXTRN mf428:FAR
    EXTRN mf428:FAR
    EXTRN mf428:FAR
    EXTRN mf428:FAR
    EXTRN mf428:FAR
    EXTRN mf428:FAR
    EXTRN mf428:FAR
    EXTRN mf428:FAR
    EXTRN mf428:FAR
    EXTRN mf428:FAR
    EXTRN mf428:FAR
    EXTRN mf428:FAR
    EXTRN mf428:FAR
    EXTRN mf428:FAR
    EXTRN mf428:FAR
    EXTRN mf428:FAR
    EXTRN mf428:FAR
    EXTRN mf428:FAR
    EXTRN mf428:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,4h
    mov ax,word ptr [bp+6h]
    sub ax, offset mi4
    jz short lbl18f
    dec ax
    dec ax
    jnz short lbl15f
    jmp near ptr lbl98f
lbl15f:
    jmp near ptr lbl426f
lbl18f:
    mov ax,word ptr ds:[6A06h]
    sub ax, offset mi12
    jz short lbl23f
    jmp near ptr lbl426f
lbl23f:
    mov ax,word ptr ds:[6A04h]
    sub ax, offset mi16
    jz short lbl6Af
    sub ax, offset mi18
    jz short lbl80f
    push word ptr ds:[6A02h]
    mov ax,2h
    push ax
    call mf23
    add sp,4h
    push dx
    push ax
    push word ptr ds:[6A04h]
    mov ax,12h
    push ax
    call mf30
    add sp,4h
    push dx
    push ax
    mov ax,9h
lbl57b:
    mov dx,0F032h
    push dx
    push ax
    call mf38
    add sp,0Ch
lbl64b:
    mov ax,1h
    jmp near ptr lbl428f
lbl6Af:
    mov ax,1h
    push ax
    push word ptr ds:[6A02h]
    push word ptr ds:[6A04h]
    call mf46
    add sp,6h
    jmp short lbl64b
lbl80f:
    mov ax,31h
    push ax
    push word ptr ds:[6A04h]
    mov ax,38h
lbl8Bb:
    push ax
lbl8Cb:
    call mf54
    add sp,6h
    jmp near ptr lbl428f
    nop
lbl98f:
    mov ax,word ptr ds:[6A06h]
    cmp ax, offset mi59
    jnz short lblA3f
    jmp near ptr lbl1E4f
lblA3f:
    ja short lblBAf
    cmp ax, offset mi63
    jz short lblDCf
    jna short lblAFf
    jmp near ptr lbl426f
lblAFf:
    sub al,8h
    jz short lblDCf
    sub al,0Bh
    jz short lbl106f
    jmp near ptr lbl426f
lblBAf:
    sub ax, offset mi72
    jnz short lblC2f
    jmp near ptr lbl1F2f
lblC2f:
    dec ax
    jnz short lblC8f
    jmp near ptr lbl218f
lblC8f:
    sub ax, offset mi78
    jnc short lblD0f
    jmp near ptr lbl426f
lblD0f:
    sub ax, offset mi81
    ja short lblD8f
    jmp near ptr lbl3AAf
lblD8f:
    jmp near ptr lbl426f
    nop
lblDCf:
    mov ax,56h
    push ax
    mov ax,2h
    push ax
    call mf90
    add sp,4h
    push dx
    push ax
    push word ptr ds:[6A04h]
    mov ax,12h
    push ax
    call mf97
    add sp,4h
    push dx
    push ax
    mov ax,8h
    jmp near ptr lbl57b
lbl106f:
    mov ax,0Ah
    push ax
    mov ax,29h
    push ax
    call mf107
    add sp,4h
    or ax,ax
    jz short lbl120f
    mov ax,1F4Ch
    jmp short lbl123f
    nop
lbl120f:
    mov ax,1F4Eh
lbl123f:
    push ds
    push ax
    mov ax,29h
    push ax
    mov ax,3h
    push ax
    call mf121
    add sp,4h
    push dx
    push ax
    mov ax,31h
    push ax
    mov cx,3h
    push cx
    call mf129
    add sp,4h
    push dx
    push ax
    push word ptr ds:[6A04h]
    mov ax,1h
    push ax
    call mf136
    add sp,4h
    push dx
    push ax
    xor ax,ax
    mov dx,0F032h
    push dx
    push ax
    call mf144
    add sp,14h
    mov ax,31h
    push ax
    mov ax,56h
    push ax
    call mf150
    add sp,4h
    or ax,ax
    jz short lbl190f
    mov ax,56h
    push ax
    mov ax,3h
    push ax
    call mf158
    add sp,4h
    jmp short lbl195f
lbl190f:
    mov ax,1F51h
    mov dx,ds
lbl195f:
    mov word ptr [bp-4h],ax
    mov word ptr [bp-2h],dx
    push dx
    push ax
    mov ax,1h
    mov dx,0F032h
    push dx
    push ax
    call mf171
    add sp,8h
    mov ax,31h
    push ax
    mov ax,1h
    push ax
    call mf177
    add sp,4h
    push dx
    push ax
    mov ax,0Eh
    push ax
    mov ax,31h
    push ax
    call mf185
    add sp,4h
    or ax,ax
    jz short lbl1D8f
    mov ax,1F59h
    jmp short lbl1DBf
lbl1D8f:
    mov ax,1F5Eh
lbl1DBf:
    push ds
    push ax
    mov ax,2h
    jmp near ptr lbl57b
    nop
lbl1E4f:
    xor ax,ax
    push ax
    mov ax,28h
    push ax
    push word ptr ds:[6A06h]
    jmp near ptr lbl8Cb
lbl1F2f:
    push word ptr ds:[6A04h]
    mov ax,2h
    push ax
    call mf206
    add sp,4h
    push dx
    push ax
    mov ax,3h
    mov dx,0F032h
    push dx
    push ax
    call mf214
    add sp,8h
    jmp near ptr lbl64b
    nop
lbl218f:
    mov ax,0Ah
    push ax
    mov ax,29h
    push ax
    call mf222
    add sp,4h
    or ax,ax
    jz short lbl232f
    mov ax,1F68h
    jmp short lbl235f
    nop
lbl232f:
    mov ax,1F6Bh
lbl235f:
    push ds
    push ax
    mov ax,5h
    mov dx,0F032h
    push dx
    push ax
    call mf236
    add sp,8h
    mov ax,0BB8h
    push ax
    call mf240
    add sp,2h
    mov ax,6h
    mov dx,0F032h
    push dx
    push ax
    call mf246
    add sp,4h
    mov ax,0BB8h
    push ax
    call mf250
    add sp,2h
    mov ax,0Ah
    push ax
    mov ax,29h
    push ax
    call mf256
    add sp,4h
    or ax,ax
    jz short lbl2ACf
    mov ax,0Ah
    push ax
    mov ax,29h
    push ax
    call mf264
    add sp,4h
    mov ax,4Ch
    push ax
    push word ptr ds:[6A04h]
    call mf269
    add sp,4h
    mov byte ptr ds:[324h],0h
    jmp near ptr lbl33Df
    nop
lbl2ACf:
    mov ax,0Ah
    push ax
    mov ax,29h
    push ax
    call mf278
    add sp,4h
    mov ax,4Bh
    push ax
    push word ptr ds:[6A04h]
    call mf283
    add sp,4h
    mov ax,1F6Dh
    push ds
    push ax
    call mf288
    add sp,4h
    mov ax,31h
    push ax
    mov ax,56h
    push ax
    call mf294
    add sp,4h
    or ax,ax
    jz short lbl33Df
    mov ax,0Eh
    push ax
    mov ax,31h
    push ax
    call mf302
    add sp,4h
    or ax,ax
    jnz short lbl33Df
    mov byte ptr ds:[324h],1h
    mov ax,0Ah
    push ax
    mov ax,27h
    push ax
    call mf311
    add sp,4h
    or ax,ax
    jnz short lbl33Df
    mov ax,0Ah
    push ax
    mov ax,27h
    push ax
    call mf319
    add sp,4h
    xor ax,ax
    push ax
    mov ax,1h
    push ax
    mov ax,9h
    push ax
    call mf327
    add sp,6h
lbl33Df:
    mov ax,40h
    push ax
    call mf331
    add sp,2h
    mov ax,0Ah
    push ax
    mov ax,29h
    push ax
    call mf337
    add sp,4h
    or ax,ax
    jz short lbl362f
    mov ax,1F75h
    jmp short lbl365f
lbl362f:
    mov ax,1F85h
lbl365f:
    push ds
    push ax
    mov ax,0Ah
    push ax
    mov ax,29h
    push ax
    call mf350
    add sp,4h
    or ax,ax
    jz short lbl380f
    mov ax,1F8Dh
    jmp short lbl383f
lbl380f:
    mov ax,1F90h
lbl383f:
    push ds
    push ax
    mov ax,29h
    push ax
    mov ax,2h
    push ax
    call mf363
    add sp,4h
    push dx
    push ax
    mov ax,7h
    mov dx,0F032h
    push dx
    push ax
    call mf371
    add sp,10h
    jmp near ptr lbl64b
lbl3AAf:
    cmp word ptr ds:[6A06h],4Ch
    jnz short lbl3C5f
    mov ax,0Ah
    push ax
    mov ax,29h
    push ax
    call mf380
    add sp,4h
    or ax,ax
    jnz short lbl3E0f
lbl3C5f:
    cmp word ptr ds:[6A06h],4Bh
    jnz short lbl418f
    mov ax,0Ah
    push ax
    mov ax,29h
    push ax
    call mf390
    add sp,4h
    or ax,ax
    jnz short lbl418f
lbl3E0f:
    mov ax,0Ah
    push ax
    mov ax,29h
    push ax
    call mf398
    add sp,4h
    or ax,ax
    jz short lbl3FAf
    mov ax,1F63h
    jmp short lbl3FDf
    nop
lbl3FAf:
    mov ax,1F65h
lbl3FDf:
    push ds
    push ax
    push word ptr ds:[6A04h]
    mov ax,12h
    push ax
    call mf411
    add sp,4h
    push dx
    push ax
    mov ax,4h
    jmp near ptr lbl57b
    nop
lbl418f:
    xor ax,ax
    push ax
    mov ax,29h
    push ax
    mov ax,17h
    jmp near ptr lbl8Bb
    nop
lbl426f:
    xor ax,ax
lbl428f:
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
