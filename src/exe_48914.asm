_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN md2b9:NEAR
    EXTRN mf1fd:FAR
    EXTRN md349:NEAR
    EXTRN md24b:NEAR
    EXTRN mfe6:FAR
    EXTRN md23c:NEAR
    EXTRN md246:NEAR
    EXTRN mf3ba:FAR
    EXTRN mf2ed:FAR
    EXTRN md359:NEAR
    EXTRN mf104:FAR
    EXTRN mf194:FAR
    EXTRN mf39e:FAR
    EXTRN mf308:FAR
    EXTRN md2c1:NEAR
    EXTRN md34e:NEAR
    EXTRN md35e:NEAR
    EXTRN md237:NEAR
    EXTRN mf3c2:FAR
    EXTRN mf1a3:FAR
    EXTRN mi303:NEAR
    EXTRN mi294:NEAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,38h
    push di
    push si
    cmp word ptr [bp+8h],0F000h
    jnc short lbl12f
    db 0E9h, 0BAh, 03h ; override
lbl12f:
    cmp word ptr [bp+8h],0F100h
    jc short lbl1Cf
    db 0E9h, 0B0h, 03h ; override
lbl1Cf:
    mov ax,word ptr [bp+6h]
    mov dx,word ptr [bp+8h]
    sub dh,dh
    mov word ptr [bp-10h],ax
    mov word ptr [bp-0Eh],dx
    mov word ptr [bp-2h],0h
    cmp word ptr ds:[0F2h],0h
    jz short lbl65f
    mov word ptr [bp-1Ah],0h
lbl3Bb:
    mov ax,word ptr [bp-10h]
    mov dx,word ptr [bp-0Eh]
    mov es, ds:[5A2Ah]
    mov bx,word ptr [bp-1Ah]
    cmp word ptr es:[bx],ax
    jnz short lbl56f
    cmp word ptr es:[bx+2h],dx
    jnz short lbl56f
    db 0E9h, 04h, 02h ; override
lbl56f:
    add word ptr [bp-1Ah],8h
    mov ax,word ptr ds:[0F2h]
    inc word ptr [bp-2h]
    cmp word ptr [bp-2h],ax
    jc short lbl3Bb
lbl65f:
    mov ax,dx
    mov word ptr [bp-6h],dx
    mov cx,word ptr [bp-10h]
    mov word ptr [bp-8h],cx
    cmp ax,word ptr ds:[0F4h]
    jc short lbl79f
    db 0E9h, 4Eh, 03h ; override
lbl79f:
    mov ax,cx
    mov bx,dx
    mov cx,dx
    add bx,dx
    add bx,dx
    add bx,bx
    add bx,100h
    mov es, ds:[5A2Ah]
    mov word ptr [bp-38h],bx
    mov word ptr [bp-36h],es
    cmp word ptr es:[bx],ax
    ja short lbl9Bf
    db 0E9h, 2Ch, 03h ; override
lbl9Bf:
    mov ax,word ptr ds:[0F6h]
    cmp cx,ax
    jz short lbl112f
    mov ax,word ptr ds:[5C52h]
    mov dx,word ptr ds:[5C54h]
    mov word ptr [bp-14h],ax
    mov word ptr [bp-12h],dx
    mov word ptr [bp-2h],0h
    or cx,cx
    jz short lblD9f
    mov word ptr [bp-24h],100h
    mov word ptr [bp-26h],cx
lblC0b:
    mov bx,word ptr [bp-24h]
    mov ax,word ptr es:[bx]
    add ax,ax
    sub dx,dx
    add word ptr [bp-14h],ax
    adc word ptr [bp-12h],dx
    add word ptr [bp-24h],6h
    dec word ptr [bp-26h]
    jnz short lblC0b
lblD9f:
    push word ptr [bp-12h]
    push word ptr [bp-14h]
    xor ax,ax
    push ax
    push word ptr ds:[5C38h]
    call mfe6
    add sp,8h
    push word ptr ds:[5C38h]
    les bx, dword ptr [bp-38h]
    push word ptr es:[bx]
    mov ax,2h
    push ax
    push word ptr ds:[5C3Ch]
    push word ptr ds:[5C3Ah]
    call mf104
    add sp,0Ah
    mov ax,word ptr [bp-6h]
    mov word ptr ds:[0F6h],ax
lbl112f:
    mov ax,word ptr ds:[5C4Eh]
    mov dx,word ptr ds:[5C50h]
    mov word ptr [bp-14h],ax
    mov word ptr [bp-12h],dx
    mov word ptr [bp-2h],0h
    cmp word ptr [bp-6h],0h
    jz short lbl152f
    mov word ptr [bp-28h],102h
    mov ax,word ptr [bp-6h]
    mov word ptr [bp-2Ah],ax
    mov es, ds:[5A2Ah]
lbl139b:
    mov bx,word ptr [bp-28h]
    mov ax,word ptr es:[bx]
    mov dx,word ptr es:[bx+2h]
    add word ptr [bp-14h],ax
    adc word ptr [bp-12h],dx
    add word ptr [bp-28h],6h
    dec word ptr [bp-2Ah]
    jnz short lbl139b
lbl152f:
    mov word ptr [bp-2h],0h
    cmp word ptr [bp-8h],0h
    jz short lbl187f
    mov ax,word ptr ds:[5C3Ah]
    mov dx,word ptr ds:[5C3Ch]
    mov word ptr [bp-2Eh],ax
    mov word ptr [bp-2Ch],dx
    mov ax,word ptr [bp-8h]
    mov word ptr [bp-30h],ax
lbl170b:
    les bx, dword ptr [bp-2Eh]
    add word ptr [bp-2Eh],2h
    mov ax,word ptr es:[bx]
    sub dx,dx
    add word ptr [bp-14h],ax
    adc word ptr [bp-12h],dx
    dec word ptr [bp-30h]
    jnz short lbl170b
lbl187f:
    push word ptr [bp-12h]
    push word ptr [bp-14h]
    xor ax,ax
    push ax
    push word ptr ds:[5C38h]
    call mf194
    add sp,8h
    mov ax,word ptr ds:[5C42h]
    sub dx,dx
    push dx
    push ax
    call mf1a3
    add sp,4h
    mov word ptr [bp-18h],ax
    mov word ptr [bp-16h],dx
    or dx,ax
    jnz short lbl1CFf
    mov ax,word ptr ds:[0F2h]
    add word ptr ds:[0FEh],ax
    mov word ptr ds:[0F2h],0h
    mov ax,word ptr ds:[5C3Eh]
    mov dx,word ptr ds:[5C40h]
    mov word ptr [bp-18h],ax
    mov word ptr [bp-16h],dx
lbl1CFf:
    push word ptr ds:[5C4Ch]
    mov ax,700h
    mov cx,21AAh
    push cx
    push ax
    push word ptr ds:[5C5Ah]
    push word ptr ds:[5C58h]
    push word ptr ds:[5C56h]
    push word ptr ds:[5C38h]
    mov bx,word ptr [bp-8h]
    add bx,bx
    les si, dword ptr ds:[5C3Ah]
    push word ptr es:[bx+si]
    push word ptr [bp-16h]
    push word ptr [bp-18h]
    call mf1fd
    add sp,14h
    mov bx,ax
    mov word ptr [bp-0Ah],ax
    les si, dword ptr [bp-18h]
    mov byte ptr es:[bx+si],0h
    mov ax,es
    cmp si,word ptr ds:[5C3Eh]
    jz short lbl21Cf
    db 0E9h, 0BAh, 00h ; override
lbl21Cf:
    cmp ax,word ptr ds:[5C40h]
    jz short lbl225f
    db 0E9h, 0B1h, 00h ; override
lbl225f:
    mov ax,word ptr [bp-10h]
    mov dx,word ptr [bp-0Eh]
    mov es, ds:[5A2Ah]
    mov cl,3h
    mov bx,word ptr ds:[0F2h]
    shl bx,cl
    mov word ptr es:[bx+md237],ax
    mov word ptr es:[bx+md23c],dx
    xor ax,ax
    mov word ptr [bp-0Ch],ax
    mov word ptr es:[bx+md246],ax
    mov word ptr es:[bx+md24b],ax
    mov ax,word ptr [bp-0Ah]
    mov word ptr ds:[5C44h],ax
    db 0E9h, 4Dh, 01h ; override
    nop
lbl25Af:
    mov word ptr [bp-4h],0h
    cmp word ptr [bp-2h],0h
    jz short lbl282f
    mov word ptr [bp-1Ch],6h
    mov ax,word ptr [bp-2h]
    mov word ptr [bp-1Eh],ax
    add word ptr [bp-4h],ax
lbl273b:
    mov bx,word ptr [bp-1Ch]
    inc word ptr es:[bx]
    add word ptr [bp-1Ch],8h
    dec word ptr [bp-1Eh]
    jnz short lbl273b
lbl282f:
    mov ax,word ptr ds:[0F2h]
    inc word ptr [bp-4h]
    cmp word ptr [bp-4h],ax
    jnc short lbl2B2f
    mov cl,3h
    mov ax,word ptr [bp-4h]
    shl ax,cl
    add ax, offset mi294
    mov word ptr [bp-20h],ax
    mov ax,word ptr ds:[0F2h]
    sub ax,word ptr [bp-4h]
    mov word ptr [bp-22h],ax
lbl2A3b:
    mov bx,word ptr [bp-20h]
    inc word ptr es:[bx]
    add word ptr [bp-20h],8h
    dec word ptr [bp-22h]
    jnz short lbl2A3b
lbl2B2f:
    mov cl,3h
    mov bx,word ptr [bp-2h]
    shl bx,cl
    mov ax,word ptr es:[bx+md2b9]
    mov word ptr [bp-0Ch],ax
    mov word ptr es:[bx+md2c1],0h
lbl2C8b:
    mov ax,word ptr ds:[5C3Eh]
    mov dx,word ptr ds:[5C40h]
    add ax,word ptr [bp-0Ch]
    db 0E9h, 0FDh, 00h ; override
    nop
lbl2D6f:
    mov ax,word ptr [bp-0Ah]
    add ax,word ptr ds:[5C44h]
    cmp ax,word ptr ds:[5C42h]
    jc short lbl2FFf
lbl2E3b:
    cmp word ptr ds:[0F2h],0h
    jnz short lbl2EDf
    db 0E9h, 0C5h, 00h ; override
lbl2EDf:
    call mf2ed
    mov ax,word ptr [bp-0Ah]
    add ax,word ptr ds:[5C44h]
    cmp ax,word ptr ds:[5C42h]
    jnc short lbl2E3b
lbl2FFf:
    mov ax,word ptr ds:[0F2h]
    inc ax
    cmp ax, offset mi303
    jc short lbl30Df
    call mf308
lbl30Df:
    mov word ptr [bp-2h],0h
    cmp word ptr ds:[0F2h],0h
    jz short lbl337f
    mov word ptr [bp-32h],6h
    mov ax,word ptr ds:[0F2h]
    mov word ptr [bp-34h],ax
    mov es, ds:[5A2Ah]
lbl328b:
    mov bx,word ptr [bp-32h]
    inc word ptr es:[bx]
    add word ptr [bp-32h],8h
    dec word ptr [bp-34h]
    jnz short lbl328b
lbl337f:
    mov ax,word ptr [bp-10h]
    mov dx,word ptr [bp-0Eh]
    mov es, ds:[5A2Ah]
    mov cl,3h
    mov bx,word ptr ds:[0F2h]
    shl bx,cl
    mov word ptr es:[bx+md349],ax
    mov word ptr es:[bx+md34e],dx
    mov ax,word ptr ds:[5C44h]
    mov word ptr [bp-0Ch],ax
    mov word ptr es:[bx+md359],ax
    mov word ptr es:[bx+md35e],0h
    mov bx,word ptr ds:[5C3Eh]
    mov cx,word ptr ds:[5C40h]
    add bx,ax
    push ds
    mov si,bx
    mov ds,cx
    les di, dword ptr [bp-18h]
    mov cx,0FFFFh
    xor ax,ax
    repne scasb
    not cx
    sub di,cx
    db 87h, 0FEh ; override
    push ds
    push es
    pop ds
    pop es
    shr cx,1
    rep movsw
    adc cx,cx
    rep movsb
    pop ds
    mov ax,word ptr [bp-0Ah]
    add word ptr ds:[5C44h],ax
    push word ptr [bp-16h]
    push word ptr [bp-18h]
    call mf39e
    add sp,4h
lbl3A6f:
    inc word ptr ds:[0F2h]
    inc word ptr ds:[0FCh]
    jmp near ptr lbl2C8b
    nop
lbl3B2f:
    mov ax,951h
    mov cx,21AAh
    push cx
    push ax
    call mf3ba
    add sp,4h
    call mf3c2
lbl3C7f:
    xor ax,ax
    cwd
    jmp short lbl3D2f
lbl3CCf:
    mov ax,word ptr [bp+6h]
    mov dx,word ptr [bp+8h]
lbl3D2f:
    pop si
    pop di
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
