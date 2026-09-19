_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf3b:FAR
    EXTRN mf1e9:FAR
    EXTRN mf22b:FAR
    EXTRN mf44:FAR
    EXTRN mf210:FAR
    EXTRN mf2e:FAR
    EXTRN mf1fc:FAR
    EXTRN mifd:NEAR
    EXTRN mf164:FAR
    EXTRN mf1d9:FAR
    EXTRN mf68:FAR
    EXTRN mf1a3:FAR
    EXTRN mf1b6:FAR
    EXTRN mf240:FAR
    EXTRN mf92:FAR
    EXTRN mf50:FAR
    EXTRN mfa:FAR
    EXTRN mf1c9:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,6h
    push si
    xor ax,ax
    push ax
    call mfa
    add sp,2h
    or ax,ax
    jz short lbl5Ef
    cmp byte ptr ds:[6E5Ch],1h
    jnz short lbl5Ef
    cmp byte ptr ds:[311h],0h
    jz short lbl5Ef
    cmp word ptr [bp+6h],0Fh
    jnz short lbl58f
    mov ax,8Bh
    push ax
    call mf2e
    add sp,2h
    cmp ax,140h
    jnz short lbl58f
    call mf3b
    mov ax,0Bh
    push ax
    call mf44
    add sp,2h
    mov ax,1388h
    push ax
    call mf50
    add sp,2h
lbl58f:
    mov ax,0F4h
    jmp near ptr lbl24Bf
lbl5Ef:
    cmp byte ptr ds:[6E5Ch],0Ah
    jnz short lbl92f
    xor ax,ax
    push ax
    call mf68
    add sp,2h
    or ax,ax
    jz short lbl82f
    cmp byte ptr ds:[312h],0h
    jz short lbl82f
    mov ax,0EDh
    jmp near ptr lbl24Bf
    nop
lbl82f:
    cmp word ptr [bp+6h],0Fh
    jz short lbl8Bf
    jmp near ptr lbl16Cf
lbl8Bf:
    mov ax,0FFFFh
    jmp near ptr lbl24Bf
    nop
lbl92f:
    call mf92
    or ax,ax
    jz short lblA8f
    cmp byte ptr ds:[6E5Ch],5h
    jnz short lblA8f
    mov ax,0C9h
    jmp near ptr lbl24Bf
lblA8f:
    cmp word ptr [bp+6h],0Fh
    jz short lbl10Af
    mov word ptr [bp-2h],0h
    mov word ptr [bp-4h],2D5Ah
lblB8b:
    mov al,byte ptr ds:[6E5Ch]
    mov bx,word ptr [bp-4h]
    cmp byte ptr [bx],al
    jz short lblD4f
    inc word ptr [bp-2h]
    add word ptr [bp-4h],6h
    cmp word ptr [bp-4h],2D72h
    jc short lblB8b
    jmp near ptr lbl24Bf
    nop
lblD4f:
    mov bx,word ptr ds:[2EAh]
    mov ax,bx
    add bx,bx
    add bx,bx
    add bx,ax
    add bx,bx
    add bx,word ptr ds:[2ECh]
    add bx,bx
    mov si,word ptr [bp-2h]
    mov ax,si
    add si,si
    add si,ax
    add si,si
    sub ah,ah
    mov al,byte ptr [si+2D5Bh]
    and ax,word ptr [bx+2C90h]
    cmp ax, offset mifd
    cmc
    db 1Bh, 0C0h ; override
    and ax,0CDh
    jmp near ptr lbl24Bf
    nop
lbl10Af:
    mov word ptr [bp-6h],2D5Ah
lbl10Fb:
    mov al,byte ptr ds:[6E5Ch]
    mov bx,word ptr [bp-6h]
    cmp byte ptr [bx],al
    jnz short lbl13Bf
    mov bx,word ptr ds:[2EAh]
    mov ax,bx
    add bx,bx
    add bx,bx
    add bx,ax
    add bx,bx
    add bx,word ptr ds:[2ECh]
    mov si,word ptr [bp-6h]
    add bx,bx
    mov al,byte ptr [si+1h]
    sub ah,ah
    test word ptr [bx+2C90h],ax
    jz short lbl15Cf
lbl13Bf:
    add word ptr [bp-6h],6h
    cmp word ptr [bp-6h],2D72h
    jc short lbl10Fb
    mov al,byte ptr ds:[6E5Ch]
    sub ah,ah
    dec ax
    jz short lbl172f
    dec ax
    dec ax
    jz short lbl178f
    dec ax
    dec ax
    jz short lbl17Ef
    dec ax
    dec ax
    jz short lbl184f
    jmp short lbl188f
lbl15Cf:
    mov ax,1Bh
    mov dx,0F01Dh
    push dx
    push ax
    call mf164
    add sp,4h
lbl16Cf:
    xor ax,ax
    jmp near ptr lbl24Bf
    nop
lbl172f:
    inc word ptr ds:[2EAh]
    jmp short lbl188f
lbl178f:
    inc word ptr ds:[2ECh]
    jmp short lbl188f
lbl17Ef:
    dec word ptr ds:[2EAh]
    jmp short lbl188f
lbl184f:
    dec word ptr ds:[2ECh]
lbl188f:
    mov cl,byte ptr ds:[2ECh]
    mov ax,1h
    shl ax,cl
    mov bx,word ptr ds:[2EAh]
    add bx,bx
    or word ptr [bx+2C7Eh],ax
    mov ax,0Fh
    push ax
    push word ptr ds:[256h]
    call mf1a3
    add sp,4h
    xor ax,ax
    push ax
    push word ptr ds:[256h]
    mov cx,1h
    push cx
    call mf1b6
    add sp,6h
    mov ax,0Dh
    push ax
    mov ax,word ptr ds:[256h]
    mov word ptr ds:[6A22h],ax
    push ax
    call mf1c9
    add sp,4h
    mov ax,0Ah
    push ax
    push word ptr ds:[256h]
    call mf1d9
    add sp,4h
    mov ax,0Eh
    push ax
    push word ptr ds:[256h]
    call mf1e9
    add sp,4h
    xor ax,ax
    push ax
    mov cx,1h
    push cx
    mov cx,0F2h
    push cx
    call mf1fc
    add sp,6h
    or ax,ax
    jz short lbl238f
    mov ax,0Ah
    push ax
    mov ax,0F2h
    push ax
    call mf210
    add sp,4h
    or ax,ax
    jz short lbl238f
    cmp word ptr ds:[290h],5h
    jz short lbl238f
    push word ptr ds:[2ECh]
    push word ptr ds:[2EAh]
    call mf22b
    add sp,4h
    add ax,16Eh
    jmp short lbl23Bf
lbl238f:
    mov ax,16Eh
lbl23Bf:
    push ax
    mov ax,0F2h
    push ax
    call mf240
    add sp,4h
    mov ax,0CDh
lbl24Bf:
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
