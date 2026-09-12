_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf5:FAR
    EXTRN mf26:FAR
    EXTRN mf38:FAR
    EXTRN mi45:NEAR
    EXTRN mf48:FAR
    EXTRN mi50:NEAR
    EXTRN mf55:FAR
    EXTRN mi57:NEAR
    EXTRN mf62:FAR
    EXTRN mf66:FAR
    EXTRN mf78:FAR
    EXTRN mf89:FAR
    EXTRN mi91:NEAR
    EXTRN mf97:FAR
    EXTRN mf99:FAR
    EXTRN mf105:FAR
    EXTRN mf110:FAR
    EXTRN mf112:FAR
    EXTRN mi116:NEAR
    EXTRN mf121:FAR
    EXTRN mf123:FAR
    EXTRN mi127:NEAR
    EXTRN mf135:FAR
    EXTRN mf137:FAR
    EXTRN mf143:FAR
    EXTRN mi146:NEAR
    EXTRN mf152:FAR
    EXTRN mi155:NEAR
    EXTRN mf161:FAR
    EXTRN mf172:FAR
    EXTRN mf184:FAR
    EXTRN mf194:FAR
    EXTRN mi197:NEAR
    EXTRN mf201:FAR
    EXTRN mi204:NEAR
    EXTRN mf211:FAR
    EXTRN mf223:FAR
    EXTRN mf234:FAR
    EXTRN mi237:NEAR
    EXTRN mf242:FAR
    EXTRN mf244:FAR
    EXTRN mf250:FAR
    EXTRN mf255:FAR
    EXTRN mf257:FAR
    EXTRN mi260:NEAR
    EXTRN mf266:FAR
    EXTRN mf268:FAR
    EXTRN mi271:NEAR
    EXTRN mf280:FAR
    EXTRN mf282:FAR
    EXTRN mf288:FAR
    EXTRN mi290:NEAR
    EXTRN mi295:NEAR
    EXTRN mf297:FAR
    EXTRN mi301:NEAR
    EXTRN mf306:FAR
    EXTRN mf312:FAR
    EXTRN mf314:FAR
    EXTRN mf319:FAR
    EXTRN mf319:FAR
    EXTRN mf319:FAR
    EXTRN mf319:FAR
    EXTRN mf319:FAR
    EXTRN mf319:FAR
    EXTRN mf319:FAR
    EXTRN mf319:FAR
    EXTRN mf319:FAR
    EXTRN mf319:FAR
    EXTRN mf319:FAR
    EXTRN mf319:FAR
    EXTRN mf319:FAR
    EXTRN mf319:FAR
    EXTRN mf319:FAR
    EXTRN mf319:FAR
    EXTRN mf319:FAR
    EXTRN mf319:FAR
    EXTRN mf319:FAR
    EXTRN mf319:FAR
    EXTRN mf319:FAR
    EXTRN mf319:FAR
    EXTRN mf319:FAR
    EXTRN mf319:FAR
    EXTRN mf319:FAR
    EXTRN mf319:FAR
    EXTRN mf319:FAR
    EXTRN mf319:FAR
    EXTRN mf319:FAR
    EXTRN mf319:FAR
    EXTRN mf319:FAR
    EXTRN mf319:FAR
    EXTRN mf319:FAR
    EXTRN mf319:FAR
    EXTRN mf319:FAR
    EXTRN mf319:FAR
    EXTRN mf319:FAR
    EXTRN mf319:FAR
    EXTRN mf319:FAR
    EXTRN mf319:FAR
    EXTRN mf319:FAR
    EXTRN mf319:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,1Ah
    push di
    push si
    call mf5
    mov al,byte ptr [bp+8h]
    cbw
    imul word ptr ds:[5AFCh]
    add ax,word ptr ds:[5AF8h]
    mov word ptr [bp-2h],ax
    mov al,byte ptr [bp+9h]
    mov cl,2h
    cbw
    idiv cl
    cbw
    imul word ptr ds:[5AFEh]
    add ax,word ptr ds:[5AFAh]
    mov word ptr [bp-4h],ax
    test byte ptr [bp+9h],1h
    jnz short lbl39f
    jmp near ptr lbl1BEf
lbl39f:
    add word ptr [bp-4h],4h
    cmp word ptr [bp+0Ah],0h
    jz short lblA8f
    push word ptr ds:[5AF6h]
    call mf26
    add sp,2h
    push word ptr [bp-2h]
    mov ax,word ptr [bp-4h]
    inc ax
    push ax
    push word ptr [bp-2h]
    mov cx,word ptr [bp-4h]
    add cx,3h
    push cx
    mov si,ax
    mov di,cx
    call mf38
    mov ax,word ptr [bp-2h]
    inc ax
    push ax
    push word ptr [bp-4h]
    push ax
    mov ax,word ptr [bp-4h]
    add ax, offset mi45
    push ax
    mov word ptr [bp-6h],ax
    call mf48
    mov ax,word ptr [bp-2h]
    add ax, offset mi50
    push ax
    push word ptr [bp-4h]
    push ax
    push word ptr [bp-6h]
    call mf55
    mov ax,word ptr [bp-2h]
    add ax, offset mi57
    push ax
    push si
    push ax
    push di
lbl9Fb:
    call mf62
    jmp near ptr lbl34Af
    nop
lblA8f:
    push word ptr ds:[5AF0h]
    call mf66
    add sp,2h
    mov ax,word ptr [bp-2h]
    inc ax
    push ax
    push word ptr [bp-4h]
    mov cx,word ptr [bp-2h]
    add cx,2h
    push cx
    push word ptr [bp-4h]
    mov si,ax
    mov di,cx
    call mf78
    push word ptr [bp-2h]
    mov ax,word ptr [bp-4h]
    inc ax
    push ax
    push word ptr [bp-2h]
    mov cx,word ptr [bp-4h]
    add cx,3h
    push cx
    mov word ptr [bp-8h],ax
    mov word ptr [bp-0Ah],cx
    call mf89
    mov ax,word ptr [bp-2h]
    add ax, offset mi91
    push ax
    push word ptr [bp-8h]
    push ax
    push word ptr [bp-0Ah]
    mov word ptr [bp-0Ch],ax
    call mf97
    push word ptr ds:[5AEEh]
    call mf99
    add sp,2h
    push si
    push word ptr [bp-8h]
    push si
    push word ptr [bp-0Ah]
    call mf105
    push di
    push word ptr [bp-8h]
    push di
    push word ptr [bp-0Ah]
    call mf110
    push word ptr ds:[5AECh]
    call mf112
    add sp,2h
    push si
    mov ax,word ptr [bp-4h]
    add ax, offset mi116
    push ax
    push di
    push ax
    mov word ptr [bp-0Eh],ax
    call mf121
    push word ptr ds:[5AF2h]
    call mf123
    add sp,2h
    push si
    mov ax,word ptr [bp-4h]
    add ax, offset mi127
    push ax
    push si
    mov cx,word ptr [bp-4h]
    add cx,18h
    push cx
    mov si,ax
    mov word ptr [bp-10h],cx
    call mf135
    push word ptr ds:[5AF4h]
    call mf137
    add sp,2h
    push di
    push si
    push di
    push word ptr [bp-10h]
    call mf143
    push word ptr [bp-0Eh]
    mov ax,word ptr [bp-2h]
    add ax, offset mi146
    push ax
    mov cx,word ptr [bp-4h]
    add cx,2h
    push cx
    push ax
    call mf152
    add sp,8h
    mov ax,word ptr [bp-4h]
    add ax, offset mi155
    push ax
    push word ptr [bp-0Ch]
    push word ptr [bp-0Eh]
    push word ptr [bp-0Ch]
    mov si,ax
    call mf161
    add sp,8h
    push si
    push di
    push si
    push di
    jmp near ptr lbl342f
lbl1BEf:
    add word ptr [bp-2h],4h
    cmp word ptr [bp+0Ah],0h
    jz short lbl228f
    push word ptr ds:[5AF6h]
    call mf172
    add sp,2h
    mov ax,word ptr [bp-2h]
    inc ax
    push ax
    push word ptr [bp-4h]
    mov cx,word ptr [bp-2h]
    add cx,3h
    push cx
    push word ptr [bp-4h]
    mov si,ax
    mov di,cx
    call mf184
    push word ptr [bp-2h]
    mov ax,word ptr [bp-4h]
    inc ax
    push ax
    mov cx,word ptr [bp-2h]
    add cx,1Dh
    push cx
    push ax
    mov word ptr [bp-12h],cx
    call mf194
    push word ptr [bp-2h]
    mov ax,word ptr [bp-4h]
    add ax, offset mi197
    push ax
    push word ptr [bp-12h]
    push ax
    call mf201
    push si
    mov ax,word ptr [bp-4h]
    add ax, offset mi204
    push ax
    push di
    push ax
    jmp near ptr lbl9Fb
    nop
lbl228f:
    push word ptr ds:[5AF0h]
    call mf211
    add sp,2h
    mov ax,word ptr [bp-2h]
    inc ax
    push ax
    push word ptr [bp-4h]
    mov cx,word ptr [bp-2h]
    add cx,3h
    push cx
    push word ptr [bp-4h]
    mov si,ax
    mov di,cx
    call mf223
    push word ptr [bp-2h]
    mov ax,word ptr [bp-4h]
    inc ax
    push ax
    push word ptr [bp-2h]
    mov cx,word ptr [bp-4h]
    add cx,2h
    push cx
    mov word ptr [bp-14h],ax
    mov word ptr [bp-16h],cx
    call mf234
    push si
    mov ax,word ptr [bp-4h]
    add ax, offset mi237
    push ax
    push di
    push ax
    mov word ptr [bp-18h],ax
    call mf242
    push word ptr ds:[5AEEh]
    call mf244
    add sp,2h
    push si
    push word ptr [bp-14h]
    push di
    push word ptr [bp-14h]
    call mf250
    push si
    push word ptr [bp-16h]
    push di
    push word ptr [bp-16h]
    call mf255
    push word ptr ds:[5AECh]
    call mf257
    add sp,2h
    mov ax,word ptr [bp-2h]
    add ax, offset mi260
    push ax
    push word ptr [bp-14h]
    push ax
    push word ptr [bp-16h]
    mov si,ax
    call mf266
    push word ptr ds:[5AF2h]
    call mf268
    add sp,2h
    mov ax,word ptr [bp-2h]
    add ax, offset mi271
    push ax
    push word ptr [bp-14h]
    mov cx,word ptr [bp-2h]
    add cx,1Dh
    push cx
    push word ptr [bp-14h]
    mov di,ax
    mov word ptr [bp-1Ah],cx
    call mf280
    push word ptr ds:[5AF4h]
    call mf282
    add sp,2h
    push di
    push word ptr [bp-16h]
    push word ptr [bp-1Ah]
    push word ptr [bp-16h]
    call mf288
    mov ax,word ptr [bp-4h]
    add ax, offset mi290
    push ax
    push si
    push ax
    mov ax,word ptr [bp-2h]
    add ax, offset mi295
    push ax
    call mf297
    add sp,8h
    push word ptr [bp-18h]
    mov ax,word ptr [bp-2h]
    add ax, offset mi301
    push ax
    push word ptr [bp-18h]
    push si
    mov si,ax
    call mf306
    add sp,8h
    push word ptr [bp-16h]
    push si
    push word ptr [bp-16h]
    push si
lbl342f:
    call mf312
    add sp,8h
lbl34Af:
    call mf314
    pop si
    pop di
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
