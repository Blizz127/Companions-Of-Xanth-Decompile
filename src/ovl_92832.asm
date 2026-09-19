_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf14:FAR
    EXTRN mf193:FAR
    EXTRN mfaf:FAR
    EXTRN mff6:FAR
    EXTRN mi18d:NEAR
    EXTRN mf71:FAR
    EXTRN mf3d:FAR
    EXTRN mf1a9:FAR
    EXTRN mf177:FAR
    EXTRN mi1a5:NEAR
    EXTRN md141:NEAR
    EXTRN mf5a:FAR
    EXTRN mi146:NEAR
    EXTRN mfbd:FAR
    EXTRN mf8e:FAR
    EXTRN mf17c:FAR
    EXTRN mi12b:NEAR
    EXTRN mi14b:NEAR
    EXTRN mi66:NEAR
    EXTRN mf35:FAR
    EXTRN mf29:FAR
    EXTRN mie6:NEAR
    EXTRN mf181:FAR
    EXTRN mf11f:FAR
    EXTRN mf16f:FAR
    EXTRN mf79:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,1Ah
    mov word ptr ds:[6A20h],5Ah
    mov ax,0Fh
    push ax
    push word ptr ds:[256h]
    call mf14
    add sp,4h
    mov ax,word ptr ds:[256h]
    mov word ptr ds:[6A22h],ax
    mov ax,5Ah
    mov word ptr ds:[256h],ax
    push ax
    call mf29
    add sp,2h
    mov ax,301h
    push ax
    call mf35
    add sp,2h
    call mf3d
    mov word ptr [bp-16h],4h
lbl47b:
    xor al,al
    push ax
    mov es, ds:[5ABEh]
    mov bx,word ptr [bp-16h]
    push word ptr es:[bx]
    sub bx,2h
    push word ptr es:[bx]
    call mf5a
    add sp,6h
    add word ptr [bp-16h],6h
    cmp word ptr [bp-16h], offset mi66
    jc short lbl47b
    mov ax,301h
    push ax
    call mf71
    add sp,2h
    call mf79
    mov word ptr ds:[290h],0h
lbl84b:
    lea ax,word ptr [bp-0Ah]
    push ss
    push ax
    lea ax,word ptr [bp-8h]
    push ss
    push ax
    call mf8e
    add sp,8h
    or ax,ax
    jz short lbl84b
    lea ax,word ptr [bp-10h]
    push ss
    push ax
    lea ax,word ptr [bp-0Eh]
    push ss
    push ax
    lea cx,word ptr [bp-0Ch]
    push ss
    push cx
    push word ptr [bp-0Ah]
    push word ptr [bp-8h]
    call mfaf
    add sp,10h
    push word ptr [bp-0Eh]
    push word ptr [bp-0Ch]
    call mfbd
    add sp,4h
    mov word ptr [bp-2h],ax
    mov word ptr [bp-18h],0h
lblCDb:
    mov ax,word ptr [bp-2h]
    mov es, ds:[5ABEh]
    mov bx,word ptr [bp-18h]
    cmp word ptr es:[bx],ax
    jnz short lblE2f
    mov word ptr ds:[292h],ax
    mov word ptr ds:[290h],ax
lblE2f:
    add word ptr [bp-18h],6h
    cmp word ptr [bp-18h], offset mie6
    jc short lblCDb
    cmp word ptr ds:[290h],0h
    jz short lbl84b
    db 74h, 75h ; override
    call mff6
    mov word ptr [bp-1Ah],0h
    mov word ptr [bp-4h],4h
lbl105b:
    mov ax,word ptr ds:[290h]
    mov es, ds:[5ABEh]
    mov bx,word ptr [bp-1Ah]
    cmp word ptr es:[bx],ax
    jz short lbl127f
    mov al,1h
    push ax
    push word ptr es:[bx+4h]
    push word ptr es:[bx+2h]
    call mf11f
    add sp,6h
lbl127f:
    add word ptr [bp-1Ah],6h
    cmp word ptr [bp-1Ah], offset mi12b
    jc short lbl105b
    mov es, ds:[5ABEh]
    mov bx,word ptr [bp-4h]
    mov ax,bx
    add bx,bx
    add bx,ax
    add bx,bx
    mov ax,word ptr es:[bx+md141]
    sub ax, offset mi146
    jz short lbl156f
    sub ax, offset mi14b
    jz short lbl15Ef
    dec ax
    jz short lbl166f
    jmp short lbl16Bf
    nop
lbl156f:
    mov byte ptr ds:[346h],1h
    jmp short lbl16Bf
    nop
lbl15Ef:
    mov byte ptr ds:[348h],1h
    jmp short lbl16Bf
    nop
lbl166f:
    mov byte ptr ds:[347h],1h
lbl16Bf:
    mov ax,7D0h
    push ax
    call mf16f
    add sp,2h
    call mf177
    call mf17c
    call mf181
    cmp word ptr ds:[290h],1h
    db 1Bh, 0C0h ; override
    add ax, offset mi18d
    mov word ptr ds:[256h],ax
    call mf193
    mov word ptr ds:[256h],5Ah
    cmp word ptr ds:[290h],1h
    db 1Bh, 0C0h ; override
    add ax, offset mi1a5
    push ax
    call mf1a9
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
