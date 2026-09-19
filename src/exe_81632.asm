_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf19f:FAR
    EXTRN mf16:FAR
    EXTRN mf37e:FAR
    EXTRN mf16d:FAR
    EXTRN mf122:FAR
    EXTRN mi332:NEAR
    EXTRN mf15f:FAR
    EXTRN mf114:FAR
    EXTRN mibb:NEAR
    EXTRN mf26e:FAR
    EXTRN mf2d3:FAR
    EXTRN mf27b:FAR
    EXTRN mi273:NEAR
    EXTRN mi325:NEAR
    EXTRN mf383:FAR
    EXTRN mf3a0:FAR
    EXTRN mf32d:FAR
    EXTRN mi35d:NEAR
    EXTRN mf376:FAR
    EXTRN mfc3:FAR
    EXTRN mf320:FAR
    EXTRN mi50:NEAR
    EXTRN mf3ae:FAR
    EXTRN mi318:NEAR
    EXTRN mf2f0:FAR
    EXTRN mf23a:FAR
    EXTRN mf59:FAR
    EXTRN mid4:NEAR
    EXTRN mi1aa:NEAR
    EXTRN mi3:NEAR
    EXTRN mfdc:FAR
    EXTRN mf2d:FAR
    EXTRN mf365:FAR
    EXTRN mi266:NEAR
    EXTRN mf358:FAR
    EXTRN mf2bb:FAR
    EXTRN mi36a:NEAR
    EXTRN mf261:FAR
    EXTRN mi280:NEAR
    EXTRN mi2c7:NEAR
    EXTRN mf313:FAR
    EXTRN mf1f:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp, offset mi3
    push si
    push di
    cmp word ptr ds:[4232h],0h
    jz short lbl13f
    jmp near ptr lbl16f
lbl13f:
    jmp near ptr lbl3B6f
lbl16f:
    call mf16
    mov ax,10h
    push ax
    call mf1f
    add sp,2h
    mov dx,0h
    mov cx,4h
    call mf2d
    mov word ptr [bp-6h],ax
    mov word ptr [bp-4h],dx
    mov word ptr [bp-26h],4000h
    jmp near ptr lbl4Df
lbl40b:
    mov cx,2h
    mov ax,word ptr [bp-26h]
    sub dx,dx
    div cx
    mov word ptr [bp-26h],ax
lbl4Df:
    mov ax,word ptr [bp-26h]
    add ax, offset mi50
    mov dx,0h
    mov cx,1h
    call mf59
    cmp dx,word ptr [bp-4h]
    jnl short lbl66f
    jmp near ptr lbl80f
lbl66f:
    jng short lbl6Bf
    jmp near ptr lbl73f
lbl6Bf:
    cmp ax,word ptr [bp-6h]
    ja short lbl73f
    jmp near ptr lbl80f
lbl73f:
    cmp word ptr [bp-26h],1000h
    ja short lbl7Df
    jmp near ptr lbl80f
lbl7Df:
    jmp near ptr lbl40b
lbl80f:
    mov word ptr [bp-18h],0h
    mov word ptr [bp-16h],0h
    mov word ptr [bp-1Ch],0h
    mov word ptr [bp-1Ah],0h
    mov ax,word ptr ds:[423Ch]
    mov dx,word ptr ds:[423Eh]
    mov word ptr [bp-24h],ax
    mov word ptr [bp-22h],dx
    mov ax,word ptr ds:[4240h]
    mov dx,word ptr ds:[4242h]
    mov word ptr [bp-20h],ax
    mov word ptr [bp-1Eh],dx
    cmp word ptr [bp-26h],1000h
    ja short lblB8f
    jmp near ptr lbl159f
lblB8f:
    mov ax,word ptr [bp-26h]
    add ax, offset mibb
    mov dx,0h
    push dx
    push ax
    call mfc3
    add sp,4h
    mov word ptr [bp-18h],ax
    mov word ptr [bp-16h],dx
    mov ax,word ptr [bp-26h]
    add ax, offset mid4
    mov dx,0h
    push dx
    push ax
    call mfdc
    add sp,4h
    mov word ptr [bp-1Ch],ax
    mov word ptr [bp-1Ah],dx
    cmp word ptr [bp-18h],0h
    jz short lblF3f
    jmp near ptr lblFCf
lblF3f:
    cmp word ptr [bp-16h],0h
    jnz short lblFCf
    jmp near ptr lbl10Ef
lblFCf:
    cmp word ptr [bp-1Ch],0h
    jz short lbl105f
    jmp near ptr lbl141f
lbl105f:
    cmp word ptr [bp-1Ah],0h
    jz short lbl10Ef
    jmp near ptr lbl141f
lbl10Ef:
    push word ptr [bp-16h]
    push word ptr [bp-18h]
    call mf114
    add sp,4h
    push word ptr [bp-1Ah]
    push word ptr [bp-1Ch]
    call mf122
    add sp,4h
    mov word ptr [bp-18h],0h
    mov word ptr [bp-16h],0h
    mov word ptr [bp-1Ch],0h
    mov word ptr [bp-1Ah],0h
    jmp near ptr lbl159f
lbl141f:
    mov ax,word ptr [bp-18h]
    mov dx,word ptr [bp-16h]
    mov word ptr [bp-24h],ax
    mov word ptr [bp-22h],dx
    mov ax,word ptr [bp-1Ch]
    mov dx,word ptr [bp-1Ah]
    mov word ptr [bp-20h],ax
    mov word ptr [bp-1Eh],dx
lbl159f:
    push word ptr [bp-22h]
    push word ptr [bp-24h]
    call mf15f
    add sp,4h
    push word ptr [bp-1Eh]
    push word ptr [bp-20h]
    call mf16d
    add sp,4h
    mov ax,word ptr [bp+6h]
    shl ax,1
    shl ax,1
    mov bx,word ptr ds:[4238h]
    mov cx,word ptr ds:[423Ah]
    add bx,ax
    mov es,cx
    mov ax,word ptr es:[bx]
    mov dx,word ptr es:[bx+2h]
    mov word ptr [bp-0Eh],ax
    mov word ptr [bp-0Ch],dx
    push word ptr [bp-0Ch]
    push word ptr [bp-0Eh]
    push word ptr ds:[4234h]
    call mf19f
    add sp,6h
    mov ax,word ptr [bp+6h]
    add ax, offset mi1aa
    shl ax,1
    shl ax,1
    mov bx,word ptr ds:[4238h]
    mov cx,word ptr ds:[423Ah]
    add bx,ax
    mov es,cx
    mov ax,word ptr es:[bx]
    mov dx,word ptr es:[bx+2h]
    sub ax,word ptr [bp-0Eh]
    sbb dx,word ptr [bp-0Ch]
    mov word ptr [bp-0Ah],ax
    mov word ptr [bp-8h],dx
    mov word ptr [bp-10h],0h
    jmp near ptr lbl2FCf
lbl1D8b:
    mov ax,word ptr [bp-26h]
    mov dx,0h
    cmp word ptr [bp-8h],dx
    jnl short lbl1E6f
    jmp near ptr lbl208f
lbl1E6f:
    jng short lbl1EBf
    jmp near ptr lbl1F3f
lbl1EBf:
    cmp word ptr [bp-0Ah],ax
    ja short lbl1F3f
    jmp near ptr lbl208f
lbl1F3f:
    mov ax,word ptr [bp-26h]
    mov word ptr [bp-14h],ax
    mov ax,word ptr [bp-26h]
    mov dx,0h
    sub word ptr [bp-0Ah],ax
    sbb word ptr [bp-8h],dx
    jmp near ptr lbl21Bf
lbl208f:
    mov ax,word ptr [bp-0Ah]
    mov dx,word ptr [bp-8h]
    mov word ptr [bp-14h],ax
    mov word ptr [bp-0Ah],0h
    mov word ptr [bp-8h],0h
lbl21Bf:
    push word ptr [bp-14h]
    mov ax,word ptr [bp-10h]
    shl ax,1
    shl ax,1
    lea bx,word ptr [bp-24h]
    add bx,ax
    mov ax,word ptr [bx]
    mov dx,word ptr [bx+2h]
    mov cx,20h
    add ax,cx
    push dx
    push ax
    push word ptr ds:[4234h]
    call mf23a
    add sp,8h
    mov word ptr [bp-12h],ax
    mov ax,word ptr [bp-14h]
    mov dx,0h
    mov bx,word ptr [bp-10h]
    shl bx,1
    shl bx,1
    lea si,word ptr [bp-24h]
    add si,bx
    les si, dword ptr [si]
    mov word ptr es:[si+7h],ax
    mov word ptr es:[si+9h],dx
lbl261b:
    call mf261
    cmp ax, offset mi266
    jnz short lbl26Ef
    jmp near ptr lbl2A6f
lbl26Ef:
    call mf26e
    cmp ax, offset mi273
    jz short lbl27Bf
    jmp near ptr lbl288f
lbl27Bf:
    call mf27b
    cmp ax, offset mi280
    jnz short lbl288f
    jmp near ptr lbl28Ef
lbl288f:
    jmp near ptr lbl358f
    jmp near ptr lbl2A3f
lbl28Ef:
    cmp word ptr [bp+8h],0h
    jz short lbl297f
    jmp near ptr lbl2A0f
lbl297f:
    cmp word ptr [bp+0Ah],0h
    jnz short lbl2A0f
    jmp near ptr lbl2A3f
lbl2A0f:
    db 0FFh, 5Eh, 08h ; override
lbl2A3f:
    jmp near ptr lbl261b
lbl2A6f:
    mov ax,0h
    push ax
    mov ax,word ptr [bp-10h]
    shl ax,1
    shl ax,1
    lea bx,word ptr [bp-24h]
    add bx,ax
    push word ptr [bx+2h]
    push word ptr [bx]
    call mf2bb
    add sp,6h
    mov al,byte ptr ds:[41F4h]
    cbw
    cmp ax, offset mi2c7
    jz short lbl2CFf
    jmp near ptr lbl2F8f
lbl2CFf:
    push word ptr ds:[4196h]
    call mf2d3
    add sp,2h
    mov ax,0h
    push ax
    mov ax,word ptr [bp-10h]
    shl ax,1
    shl ax,1
    lea bx,word ptr [bp-24h]
    add bx,ax
    push word ptr [bx+2h]
    push word ptr [bx]
    call mf2f0
    add sp,6h
lbl2F8f:
    xor word ptr [bp-10h],1h
lbl2FCf:
    cmp word ptr [bp-8h],0h
    jng short lbl305f
    jmp near ptr lbl1D8b
lbl305f:
    jnl short lbl30Af
    jmp near ptr lbl313f
lbl30Af:
    cmp word ptr [bp-0Ah],0h
    jna short lbl313f
    jmp near ptr lbl1D8b
lbl313b:
lbl313f:
    call mf313
    cmp ax, offset mi318
    jnz short lbl320f
    jmp near ptr lbl358f
lbl320f:
    call mf320
    cmp ax, offset mi325
    jz short lbl32Df
    jmp near ptr lbl33Af
lbl32Df:
    call mf32d
    cmp ax, offset mi332
    jnz short lbl33Af
    jmp near ptr lbl340f
lbl33Af:
    jmp near ptr lbl358f
    jmp near ptr lbl355f
lbl340f:
    cmp word ptr [bp+8h],0h
    jz short lbl349f
    jmp near ptr lbl352f
lbl349f:
    cmp word ptr [bp+0Ah],0h
    jnz short lbl352f
    jmp near ptr lbl355f
lbl352f:
    db 0FFh, 5Eh, 08h ; override
lbl355f:
    jmp near ptr lbl313b
lbl358f:
    call mf358
    cmp ax, offset mi35d
    jnz short lbl365f
    jmp near ptr lbl37Ef
lbl365f:
    call mf365
    cmp ax, offset mi36a
    jz short lbl372f
    jmp near ptr lbl37Ef
lbl372f:
    mov ax,1Bh
    push ax
    call mf376
    add sp,2h
lbl37Ef:
    call mf37e
    call mf383
    cmp word ptr [bp-18h],0h
    jz short lbl391f
    jmp near ptr lbl39Af
lbl391f:
    cmp word ptr [bp-16h],0h
    jnz short lbl39Af
    jmp near ptr lbl3B6f
lbl39Af:
    push word ptr [bp-16h]
    push word ptr [bp-18h]
    call mf3a0
    add sp,4h
    push word ptr [bp-1Ah]
    push word ptr [bp-1Ch]
    call mf3ae
    add sp,4h
lbl3B6f:
    pop di
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
