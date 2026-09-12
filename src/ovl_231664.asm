_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf4:FAR
    EXTRN mf79:FAR
    EXTRN mf87:FAR
    EXTRN mi119:NEAR
    EXTRN mf127:FAR
    EXTRN mi133:NEAR
    EXTRN mi136:NEAR
    EXTRN mf143:FAR
    EXTRN mi163:NEAR
    EXTRN mf165:FAR
    EXTRN mi194:NEAR
    EXTRN mf203:FAR
    EXTRN mi208:NEAR
    EXTRN mi215:NEAR
    EXTRN mf219:FAR
    EXTRN mi237:NEAR
    EXTRN mf240:FAR
    EXTRN mi271:NEAR
    EXTRN mi274:NEAR
    EXTRN mf284:FAR
    EXTRN mi299:NEAR
    EXTRN mf302:FAR
    EXTRN mf321:FAR
    EXTRN mf326:FAR
    EXTRN mi353:NEAR
    EXTRN mi356:NEAR
    EXTRN mf362:FAR
    EXTRN mf396:FAR
    EXTRN mi403:NEAR
    EXTRN mf410:FAR
    EXTRN mf446:FAR
    EXTRN mi454:NEAR
    EXTRN mi461:NEAR
    EXTRN mi464:NEAR
    EXTRN mf469:FAR
    EXTRN mf487:FAR
    EXTRN mf491:FAR
    EXTRN mf491:FAR
    EXTRN mf491:FAR
    EXTRN mf491:FAR
    EXTRN mf491:FAR
    EXTRN mf491:FAR
    EXTRN mf491:FAR
    EXTRN mf491:FAR
    EXTRN mf491:FAR
    EXTRN mf491:FAR
    EXTRN mf491:FAR
    EXTRN mf491:FAR
    EXTRN mf491:FAR
    EXTRN mf491:FAR
    EXTRN mf491:FAR
    EXTRN mf491:FAR
    EXTRN mf491:FAR
    EXTRN mf491:FAR
    EXTRN mf491:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,2Ah
    push si
    call mf4
    mov bx,word ptr [bp+6h]
    add bx,bx
    mov ax,word ptr [bx+32E6h]
    mov word ptr [bp-6h],ax
    mov cx,word ptr [bx+32DEh]
    mov word ptr [bp-4h],cx
    mov cl,byte ptr [bp+9h]
    sub ch,ch
    mov word ptr [bp-0Ch],cx
    or ax,ax
    jz short lbl73f
    mov ax,cx
    add ax,cx
    add ax,cx
    add ax,ax
    mov word ptr [bp-1Ah],ax
    mov ax,word ptr [bp-6h]
    mov word ptr [bp-1Ch],ax
lbl3Cb:
    mov al,byte ptr [bp+8h]
    sub ah,ah
    mov word ptr [bp-0Eh],ax
    cmp word ptr [bp-4h],0h
    jz short lbl6Af
    mov ax,word ptr [bp-4h]
    mov word ptr [bp-18h],ax
    mov es, ds:[5E2Ch]
lbl54b:
    mov bx,word ptr ds:[5E2Ah]
    add bx,word ptr [bp-0Eh]
    mov si,word ptr [bp-1Ah]
    mov byte ptr es:[bx+si],0h
    inc word ptr [bp-0Eh]
    dec word ptr [bp-18h]
    jnz short lbl54b
lbl6Af:
    add word ptr [bp-1Ah],6h
    dec word ptr [bp-1Ch]
    jnz short lbl3Cb
lbl73f:
    mov al,byte ptr [bp+9h]
    sub ah,ah
    mov word ptr [bp-0Ch],ax
    imul word ptr ds:[5B1Eh]
    add ax,word ptr ds:[3330h]
    mov word ptr [bp-12h],ax
    add ax,word ptr ds:[5B1Eh]
    dec ax
    mov word ptr [bp-16h],ax
    cmp word ptr [bp-6h],0h
    jnz short lbl97f
    jmp near ptr lbl553f
lbl97f:
    mov ax,word ptr [bp-0Ch]
    mov cx,ax
    add ax,ax
    add ax,cx
    add ax,ax
    mov word ptr [bp-20h],ax
    mov ax,word ptr [bp-6h]
    mov word ptr [bp-22h],ax
lblABb:
    mov al,byte ptr [bp+8h]
    sub ah,ah
    mov word ptr [bp-0Eh],ax
    imul word ptr ds:[5B1Ch]
    add ax,word ptr ds:[332Eh]
    mov word ptr [bp-10h],ax
    add ax,word ptr ds:[5B1Ch]
    dec ax
    mov word ptr [bp-14h],ax
    cmp word ptr [bp-4h],0h
    jnz short lblCFf
    jmp near ptr lbl53Bf
lblCFf:
    mov ax,word ptr [bp-0Ch]
    inc ax
    mov word ptr [bp-24h],ax
    mov ax,word ptr [bp-4h]
    mov word ptr [bp-1Eh],ax
lblDCb:
    push word ptr ds:[5B10h]
    call mf79
    add sp,2h
    push word ptr [bp-16h]
    push word ptr [bp-14h]
    push word ptr [bp-12h]
    push word ptr [bp-10h]
    mov ax,2h
    push ax
    call mf87
    add sp,0Ah
    les bx, dword ptr ds:[5E12h]
    sub ah,ah
    mov al,byte ptr es:[bx]
    mov cx,word ptr [bp-0Eh]
    inc cx
    mov word ptr [bp-26h],cx
    cmp ax,cx
    ja short lbl117f
    jmp near ptr lbl1D4f
lbl117f:
    les bx, dword ptr ds:[5E2Ah]
    add bx,word ptr [bp-20h]
    mov word ptr [bp-2Ah],bx
    mov word ptr [bp-28h],es
    add bx,word ptr [bp-0Eh]
    cmp byte ptr es:[bx+1h],ah
    jz short lbl130f
    jmp near ptr lbl1D4f
lbl130f:
    cmp word ptr [bp-20h],0h
    jz short lbl170f
    mov bx,word ptr [bp-2Ah]
    sub bx,6h
    mov si,word ptr [bp-0Eh]
    cmp byte ptr es:[bx+si],ah
    jnz short lbl170f
    mov bx,word ptr [bp-2Ah]
    add bx,si
    cmp byte ptr es:[bx-5h],ah
    jnz short lbl170f
    push word ptr [bp-16h]
    mov ax,word ptr [bp-14h]
    add ax, offset mi119
    push ax
    push word ptr [bp-12h]
    mov ax,word ptr [bp-14h]
    inc ax
    push ax
    mov ax,2h
    push ax
    call mf127
    add sp,0Ah
    jmp short lbl1D4f
    nop
lbl170f:
    push word ptr [bp-16h]
    mov ax,word ptr [bp-14h]
    add ax, offset mi133
    push ax
    mov ax,word ptr [bp-12h]
    add ax, offset mi136
    push ax
    mov ax,word ptr [bp-14h]
    inc ax
    push ax
    mov ax,2h
    push ax
    call mf143
    add sp,0Ah
    cmp word ptr [bp-20h],0h
    jz short lbl1D4f
    les bx, dword ptr ds:[5E2Ah]
    add bx,word ptr [bp-20h]
    sub bx,6h
    mov si,word ptr [bp-0Eh]
    cmp byte ptr es:[bx+si],0h
    jnz short lbl1D4f
    mov word ptr [bp-2h],1h
lbl1B0b:
    mov ax,word ptr [bp-14h]
    mov cx,word ptr [bp-2h]
    add ax,cx
    push ax
    add cx,word ptr [bp-12h]
    dec cx
    push cx
    push ax
    mov ax,word ptr [bp-12h]
    add ax, offset mi163
    push ax
    call mf165
    inc word ptr [bp-2h]
    cmp word ptr [bp-2h],4h
    jc short lbl1B0b
lbl1D4f:
    les bx, dword ptr ds:[5E12h]
    sub ah,ah
    mov al,byte ptr es:[bx+1h]
    cmp ax,word ptr [bp-24h]
    ja short lbl1E6f
    jmp near ptr lbl2A0f
lbl1E6f:
    les bx, dword ptr ds:[5E2Ah]
    add bx,word ptr [bp-20h]
    mov word ptr [bp-2Ah],bx
    mov word ptr [bp-28h],es
    add bx,word ptr [bp-0Eh]
    cmp byte ptr es:[bx+6h],ah
    jz short lbl1FFf
    jmp near ptr lbl2A0f
lbl1FFf:
    cmp word ptr [bp-0Eh],0h
    jz short lbl23Ef
    mov bx,word ptr [bp-2Ah]
    add bx,word ptr [bp-0Eh]
    cmp byte ptr es:[bx-1h],ah
    jnz short lbl23Ef
    mov bx,word ptr [bp-2Ah]
    add bx,word ptr [bp-0Eh]
    cmp byte ptr es:[bx+5h],ah
    jnz short lbl23Ef
    mov ax,word ptr [bp-16h]
    add ax, offset mi194
    push ax
    push word ptr [bp-14h]
    mov ax,word ptr [bp-16h]
    inc ax
    push ax
    push word ptr [bp-10h]
    mov ax,2h
    push ax
    call mf203
    add sp,0Ah
    jmp short lbl2A0f
    nop
lbl23Ef:
    mov ax,word ptr [bp-16h]
    add ax, offset mi208
    push ax
    push word ptr [bp-14h]
    mov ax,word ptr [bp-12h]
    inc ax
    push ax
    mov ax,word ptr [bp-10h]
    add ax, offset mi215
    push ax
    mov ax,2h
    push ax
    call mf219
    add sp,0Ah
    cmp word ptr [bp-0Eh],0h
    jz short lbl2A0f
    les bx, dword ptr ds:[5E2Ah]
    add bx,word ptr [bp-0Eh]
    mov si,word ptr [bp-20h]
    cmp byte ptr es:[bx+si-1h],0h
    jnz short lbl2A0f
    mov word ptr [bp-2h],1h
lbl27Cb:
    mov ax,word ptr [bp-10h]
    mov cx,word ptr [bp-2h]
    add ax,cx
    dec ax
    push ax
    add cx,word ptr [bp-16h]
    push cx
    mov ax,word ptr [bp-10h]
    add ax, offset mi237
    push ax
    push cx
    call mf240
    inc word ptr [bp-2h]
    cmp word ptr [bp-2h],4h
    jc short lbl27Cb
lbl2A0f:
    les bx, dword ptr ds:[5E12h]
    sub ah,ah
    mov al,byte ptr es:[bx]
    cmp ax,word ptr [bp-26h]
    ja short lbl2B1f
    jmp near ptr lbl37Df
lbl2B1f:
    mov al,byte ptr es:[bx+1h]
    cmp ax,word ptr [bp-24h]
    ja short lbl2BDf
    jmp near ptr lbl37Df
lbl2BDf:
    les bx, dword ptr ds:[5E2Ah]
    add bx,word ptr [bp-20h]
    mov word ptr [bp-2Ah],bx
    mov word ptr [bp-28h],es
    add bx,word ptr [bp-0Eh]
    cmp byte ptr es:[bx+7h],ah
    jz short lbl2D6f
    jmp near ptr lbl37Df
lbl2D6f:
    mov bx,word ptr [bp-2Ah]
    add bx,word ptr [bp-0Eh]
    cmp byte ptr es:[bx+1h],ah
    jnz short lbl314f
    mov bx,word ptr [bp-2Ah]
    add bx,word ptr [bp-0Eh]
    cmp byte ptr es:[bx+6h],ah
    jnz short lbl314f
    mov ax,word ptr [bp-16h]
    add ax, offset mi271
    push ax
    mov ax,word ptr [bp-14h]
    add ax, offset mi274
    push ax
    mov ax,word ptr [bp-16h]
    inc ax
    push ax
    mov ax,word ptr [bp-14h]
    inc ax
    push ax
    mov ax,2h
    push ax
    call mf284
    add sp,0Ah
    jmp short lbl37Df
lbl314f:
    les bx, dword ptr [bp-2Ah]
    add bx,word ptr [bp-0Eh]
    cmp byte ptr es:[bx+1h],0h
    jnz short lbl34Cf
    mov word ptr [bp-2h],1h
lbl326b:
    mov ax,word ptr [bp-14h]
    mov cx,word ptr [bp-2h]
    add ax,cx
    push ax
    add cx,word ptr [bp-16h]
    push cx
    mov ax,word ptr [bp-14h]
    add ax, offset mi299
    push ax
    push cx
    call mf302
    inc word ptr [bp-2h]
    cmp word ptr [bp-2h],4h
    jc short lbl326b
    jmp short lbl37Df
    nop
lbl34Cf:
    mov bx,word ptr [bp-2Ah]
    add bx,word ptr [bp-0Eh]
    cmp byte ptr es:[bx+6h],0h
    jnz short lbl37Df
    mov word ptr [bp-2h],1h
lbl35Eb:
    push word ptr [bp-14h]
    mov ax,word ptr [bp-16h]
    mov cx,word ptr [bp-2h]
    add ax,cx
    push ax
    add cx,word ptr [bp-14h]
    push cx
    push ax
    call mf321
    inc word ptr [bp-2h]
    cmp word ptr [bp-2h],4h
    jc short lbl35Eb
lbl37Df:
    push word ptr ds:[5B12h]
    call mf326
    add sp,2h
    cmp word ptr [bp-0Eh],0h
    jnz short lbl395f
    cmp word ptr [bp-20h],0h
    jz short lbl3D4f
lbl395f:
    cmp word ptr [bp-0Eh],0h
    jz short lbl3F4f
    cmp word ptr [bp-20h],0h
    jz short lbl3F4f
    les bx, dword ptr ds:[5E2Ah]
    add bx,word ptr [bp-20h]
    mov word ptr [bp-2Ah],bx
    mov word ptr [bp-28h],es
    add bx,word ptr [bp-0Eh]
    cmp byte ptr es:[bx-7h],0h
    jz short lbl3F4f
    mov bx,word ptr [bp-2Ah]
    add bx,word ptr [bp-0Eh]
    cmp byte ptr es:[bx-1h],0h
    jnz short lbl3F4f
    mov bx,word ptr [bp-2Ah]
    sub bx,6h
    mov si,word ptr [bp-0Eh]
    cmp byte ptr es:[bx+si],0h
    jnz short lbl3F4f
lbl3D4f:
    mov ax,word ptr [bp-12h]
    add ax, offset mi353
    push ax
    mov ax,word ptr [bp-10h]
    add ax, offset mi356
    push ax
    push word ptr [bp-12h]
    push word ptr [bp-10h]
    mov ax,2h
    push ax
    call mf362
    add sp,0Ah
lbl3F4f:
    cmp word ptr [bp-20h],0h
    jz short lbl40Df
    les bx, dword ptr ds:[5E2Ah]
    add bx,word ptr [bp-20h]
    sub bx,6h
    mov si,word ptr [bp-0Eh]
    cmp byte ptr es:[bx+si],0h
    jz short lbl480f
lbl40Df:
    cmp word ptr [bp-20h],0h
    jz short lbl464f
    cmp word ptr [bp-0Eh],0h
    jz short lbl464f
    les bx, dword ptr ds:[5E2Ah]
    add bx,word ptr [bp-20h]
    mov word ptr [bp-2Ah],bx
    mov word ptr [bp-28h],es
    add bx,word ptr [bp-0Eh]
    cmp byte ptr es:[bx-7h],0h
    jnz short lbl464f
    mov bx,word ptr [bp-2Ah]
    add bx,word ptr [bp-0Eh]
    cmp byte ptr es:[bx-1h],0h
    jnz short lbl464f
    mov word ptr [bp-2h],0h
lbl442b:
    mov ax,word ptr [bp-10h]
    mov cx,word ptr [bp-2h]
    add ax,cx
    push ax
    add cx,word ptr [bp-12h]
    push cx
    push word ptr [bp-14h]
    push cx
    call mf396
    inc word ptr [bp-2h]
    cmp word ptr [bp-2h],3h
    jc short lbl442b
    jmp short lbl480f
    nop
lbl464f:
    mov ax,word ptr [bp-12h]
    add ax, offset mi403
    push ax
    push word ptr [bp-14h]
    push word ptr [bp-12h]
    push word ptr [bp-10h]
    mov ax,2h
    push ax
    call mf410
    add sp,0Ah
lbl480f:
    cmp word ptr [bp-0Eh],0h
    jz short lbl49Af
    les bx, dword ptr ds:[5E2Ah]
    add bx,word ptr [bp-0Eh]
    mov si,word ptr [bp-20h]
    cmp byte ptr es:[bx+si-1h],0h
    jnz short lbl49Af
    jmp near ptr lbl524f
lbl49Af:
    cmp word ptr [bp-20h],0h
    jz short lbl504f
    les bx, dword ptr ds:[5E2Ah]
    add bx,word ptr [bp-20h]
    mov word ptr [bp-2Ah],bx
    mov word ptr [bp-28h],es
    sub bx,6h
    mov si,word ptr [bp-0Eh]
    cmp byte ptr es:[bx+si],0h
    jnz short lbl504f
    cmp word ptr [bp-20h],0h
    jz short lbl4F4f
    or si,si
    jz short lbl4F4f
    mov bx,word ptr [bp-2Ah]
    cmp byte ptr es:[bx+si-7h],0h
    jnz short lbl4F4f
    mov word ptr [bp-2h],0h
lbl4D2b:
    mov ax,word ptr [bp-10h]
    mov cx,word ptr [bp-2h]
    add ax,cx
    push ax
    add cx,word ptr [bp-12h]
    push cx
    push ax
    push word ptr [bp-16h]
    call mf446
    inc word ptr [bp-2h]
    cmp word ptr [bp-2h],3h
    jc short lbl4D2b
    jmp short lbl524f
    nop
lbl4F4f:
    push word ptr [bp-16h]
    mov ax,word ptr [bp-10h]
    add ax, offset mi454
    push ax
    push word ptr [bp-12h]
    jmp short lbl515f
    nop
lbl504f:
    push word ptr [bp-16h]
    mov ax,word ptr [bp-10h]
    add ax, offset mi461
    push ax
    mov ax,word ptr [bp-12h]
    add ax, offset mi464
    push ax
lbl515f:
    push word ptr [bp-10h]
    mov ax,2h
    push ax
    call mf469
    add sp,0Ah
lbl524f:
    mov ax,word ptr [bp-26h]
    mov word ptr [bp-0Eh],ax
    mov ax,word ptr ds:[5B1Ch]
    add word ptr [bp-10h],ax
    add word ptr [bp-14h],ax
    dec word ptr [bp-1Eh]
    jz short lbl53Bf
    jmp near ptr lblDCb
lbl53Bf:
    add word ptr [bp-20h],6h
    inc word ptr [bp-0Ch]
    mov ax,word ptr ds:[5B1Eh]
    add word ptr [bp-12h],ax
    add word ptr [bp-16h],ax
    dec word ptr [bp-22h]
    jz short lbl553f
    jmp near ptr lblABb
lbl553f:
    call mf487
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
