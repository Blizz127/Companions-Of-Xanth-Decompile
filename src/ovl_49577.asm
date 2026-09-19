_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mfc8:FAR
    EXTRN mf2f8:FAR
    EXTRN mf1d0:FAR
    EXTRN mf35:FAR
    EXTRN mf114:FAR
    EXTRN mf240:FAR
    EXTRN mi33f:NEAR
    EXTRN mf188:FAR
    EXTRN mff8:FAR
    EXTRN mfe4:FAR
    EXTRN mf294:FAR
    EXTRN mf25c:FAR
    EXTRN mf1e:FAR
    EXTRN mf67:FAR
    EXTRN mf50:FAR
    EXTRN mf2c0:FAR
    EXTRN mfb4:FAR
    EXTRN mf19c:FAR
    EXTRN mf330:FAR
    EXTRN mf130:FAR
    EXTRN mf14c:FAR
    EXTRN mf208:FAR
    EXTRN mf2dc:FAR
    EXTRN mfb:FAR
    EXTRN mf16c:FAR
    EXTRN mf84:FAR
    EXTRN mf1ec:FAR
    EXTRN mf314:FAR
    EXTRN mf224:FAR
    EXTRN mf278:FAR
    EXTRN mf353:FAR
    EXTRN mfa0:FAR
    EXTRN mf379:FAR
    EXTRN mf1b3:FAR
    EXTRN mi338:NEAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,2h
    push si
    mov ax,26h
    push ax
    call mfb
    add sp,2h
    or ax,ax
    jz short lbl1Af
    jmp near ptr lbl346f
lbl1Af:
    mov ax,27h
    push ax
    call mf1e
    add sp,2h
    or ax,ax
    jz short lbl2Df
    jmp near ptr lbl346f
lbl2Df:
    mov ax,184h
    push ax
    mov ax,189h
    push ax
    call mf35
    add sp,4h
    or ax,ax
    jnz short lbl48f
lbl41b:
    mov word ptr [bp-2h],ax
    jmp near ptr lbl35Bf
    nop
lbl48f:
    mov ax,5h
    push ax
    mov ax,1A8h
    push ax
    call mf50
    add sp,4h
    or ax,ax
    jz short lbl5Ff
    jmp near ptr lbl164f
lbl5Ff:
    mov ax,5h
    push ax
    mov ax,18Ah
    push ax
    call mf67
    add sp,4h
    or ax,ax
    jnz short lbl7Cf
lbl73b:
    mov word ptr [bp-2h],3h
    jmp near ptr lbl35Bf
    nop
lbl7Cf:
    mov ax,0Eh
    push ax
    mov ax,18Ch
    push ax
    call mf84
    add sp,4h
    or ax,ax
    jnz short lbl98f
    mov word ptr [bp-2h],4h
    jmp near ptr lbl35Bf
lbl98f:
    mov ax,5h
    push ax
    mov ax,193h
    push ax
    call mfa0
    add sp,4h
    or ax,ax
    jnz short lblC0f
    mov ax,5h
    push ax
    mov ax,197h
    push ax
    call mfb4
    add sp,4h
    or ax,ax
    jz short lbl73b
lblC0f:
    mov ax,193h
    push ax
    mov ax,0CEh
    push ax
    call mfc8
    add sp,4h
    or ax,ax
    jnz short lblDCf
    mov word ptr [bp-2h],6h
    jmp near ptr lbl35Bf
lblDCf:
    mov ax,5h
    push ax
    mov ax,18Dh
    push ax
    call mfe4
    add sp,4h
    or ax,ax
    jnz short lbl10Cf
    mov ax,5h
    push ax
    mov ax,19Ah
    push ax
    call mff8
    add sp,4h
    or ax,ax
    jnz short lbl10Cf
    mov word ptr [bp-2h],7h
    jmp near ptr lbl35Bf
lbl10Cf:
    mov ax,0Eh
    push ax
    mov ax,19Bh
    push ax
    call mf114
    add sp,4h
    or ax,ax
    jnz short lbl128f
    mov word ptr [bp-2h],8h
    jmp near ptr lbl35Bf
lbl128f:
    mov ax,1h
    push ax
    mov ax,199h
    push ax
    call mf130
    add sp,4h
    or ax,ax
    jnz short lbl144f
    mov word ptr [bp-2h],9h
    jmp near ptr lbl35Bf
lbl144f:
    mov ax,5h
    push ax
    mov ax,1A8h
    push ax
    call mf14c
    add sp,4h
    or ax,ax
    jz short lbl15Bf
    jmp near ptr lbl35Bf
lbl15Bf:
    mov word ptr [bp-2h],0Ah
    jmp near ptr lbl35Bf
    nop
lbl164f:
    mov ax,5h
    push ax
    mov ax,1AEh
    push ax
    call mf16c
    add sp,4h
    or ax,ax
    jnz short lbl180f
    mov word ptr [bp-2h],0Bh
    jmp near ptr lbl35Bf
lbl180f:
    mov ax,5h
    push ax
    mov ax,1B1h
    push ax
    call mf188
    add sp,4h
    or ax,ax
    jnz short lbl1ABf
    mov ax,5h
    push ax
    mov ax,1B8h
    push ax
    call mf19c
    add sp,4h
    or ax,ax
    jnz short lbl1ABf
    jmp near ptr lbl73b
lbl1ABf:
    mov ax,1BAh
    push ax
    mov ax,1BBh
    push ax
    call mf1b3
    add sp,4h
    or ax,ax
    jz short lbl1C8f
    mov word ptr [bp-2h],0Ch
    jmp near ptr lbl35Bf
    nop
lbl1C8f:
    mov ax,5h
    push ax
    mov ax,1BDh
    push ax
    call mf1d0
    add sp,4h
    or ax,ax
    jnz short lbl1E4f
    mov word ptr [bp-2h],0Dh
    jmp near ptr lbl35Bf
lbl1E4f:
    mov ax,0Eh
    push ax
    mov ax,1BEh
    push ax
    call mf1ec
    add sp,4h
    or ax,ax
    jnz short lbl200f
    mov word ptr [bp-2h],0Eh
    jmp near ptr lbl35Bf
lbl200f:
    mov ax,5h
    push ax
    mov ax,1CEh
    push ax
    call mf208
    add sp,4h
    or ax,ax
    jnz short lbl21Cf
    mov word ptr [bp-2h],0Fh
    jmp near ptr lbl35Bf
lbl21Cf:
    mov ax,1BDh
    push ax
    mov ax,1C3h
    push ax
    call mf224
    add sp,4h
    or ax,ax
    jz short lbl238f
    mov word ptr [bp-2h],10h
    jmp near ptr lbl35Bf
lbl238f:
    mov ax,1CEh
    push ax
    mov ax,1C3h
    push ax
    call mf240
    add sp,4h
    or ax,ax
    jnz short lbl254f
    mov word ptr [bp-2h],11h
    jmp near ptr lbl35Bf
lbl254f:
    mov ax,5h
    push ax
    mov ax,1D5h
    push ax
    call mf25c
    add sp,4h
    or ax,ax
    jnz short lbl270f
    mov word ptr [bp-2h],12h
    jmp near ptr lbl35Bf
lbl270f:
    mov ax,5h
    push ax
    mov ax,1DEh
    push ax
    call mf278
    add sp,4h
    or ax,ax
    jnz short lbl28Cf
    mov word ptr [bp-2h],13h
    jmp near ptr lbl35Bf
lbl28Cf:
    mov ax,1DEh
    push ax
    mov ax,1EEh
    push ax
    call mf294
    add sp,4h
    or ax,ax
    jz short lbl2A8f
    mov word ptr [bp-2h],14h
    jmp near ptr lbl35Bf
lbl2A8f:
    cmp byte ptr ds:[371h],0h
    jnz short lbl2B8f
    mov word ptr [bp-2h],15h
    jmp near ptr lbl35Bf
    nop
lbl2B8f:
    mov ax,1CEh
    push ax
    mov ax,1D4h
    push ax
    call mf2c0
    add sp,4h
    or ax,ax
    jz short lbl2D4f
    mov word ptr [bp-2h],16h
    jmp near ptr lbl35Bf
lbl2D4f:
    mov ax,1B1h
    push ax
    mov ax,1B7h
    push ax
    call mf2dc
    add sp,4h
    or ax,ax
    jz short lbl2F0f
    mov word ptr [bp-2h],17h
    jmp short lbl35Bf
    nop
lbl2F0f:
    mov ax,1D5h
    push ax
    mov ax,1DCh
    push ax
    call mf2f8
    add sp,4h
    or ax,ax
    jnz short lbl30Cf
    mov word ptr [bp-2h],18h
    jmp short lbl35Bf
    nop
lbl30Cf:
    mov ax,5h
    push ax
    mov ax,1F0h
    push ax
    call mf314
    add sp,4h
    or ax,ax
    jnz short lbl328f
    mov word ptr [bp-2h],19h
    jmp short lbl35Bf
    nop
lbl328f:
    mov ax,1h
    push ax
    mov ax,8Bh
    push ax
    call mf330
    add sp,4h
    cmp ax, offset mi338
    db 1Bh, 0C0h ; override
    and al,0E7h
    add ax, offset mi33f
    jmp near ptr lbl41b
    nop
lbl346f:
    mov word ptr [bp-2h],2h
    mov ax,0Ah
    push ax
    mov ax,183h
    push ax
    call mf353
    add sp,4h
lbl35Bf:
    mov ax,1h
    push ax
    mov es, ds:[5AA6h]
    mov bx,word ptr [bp-2h]
    mov ax,bx
    add bx,bx
    add bx,ax
    add bx,bx
    push word ptr es:[bx+234h]
    mov ax,8108h
    push ax
    mov si,bx
    call mf379
    add sp,6h
    mov ax,word ptr [bp-2h]
    add ax,4A3h
    mov word ptr ds:[6A10h],ax
    mov es, ds:[5AA6h]
    mov ax,word ptr es:[si+236h]
    mov dx,word ptr es:[si+238h]
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
