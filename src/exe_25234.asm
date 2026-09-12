_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf17:FAR
    EXTRN mf27:FAR
    EXTRN mn51:NEAR
    EXTRN mi78:NEAR
    EXTRN mf82:FAR
    EXTRN mi88:NEAR
    EXTRN mf129:FAR
    EXTRN mf162:FAR
    EXTRN mf186:FAR
    EXTRN mn219:NEAR
    EXTRN mn221:NEAR
    EXTRN mf312:FAR
    EXTRN mi441:NEAR
    EXTRN mf497:FAR
    EXTRN mf497:FAR
    EXTRN mn497:NEAR
    EXTRN mf497:FAR
    EXTRN mf497:FAR
    EXTRN mf497:FAR
    EXTRN mf497:FAR
    EXTRN mn497:NEAR
    EXTRN mn497:NEAR
    EXTRN mf497:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,8h
    push ds
    push es
    push si
    push di
    mov ax,38AFh
    mov ds,ax
    mov word ptr [bp-2h],0FFE8h
    les di, dword ptr [bp+0Ch]
    mov ax,word ptr [bp+0Ah]
    push ax
    mov ax,word ptr [bp+8h]
    push ax
    mov ax,word ptr [bp+6h]
    push ax
    call mf17
    or dx,dx
    jnl short lbl32f
    mov word ptr [bp-2h],ax
    jmp short lbl71f
    nop
lbl32f:
    cmp dx,10h
    jnc short lbl48f
    push dx
    push ax
    call mf27
    add sp,4h
    or dx,dx
    jz short lbl48f
    jmp short lbl50f
    nop
lbl48f:
    mov word ptr [bp-2h],0FFE6h
    jmp short lbl71f
    nop
lbl50f:
    mov bx,word ptr [bp+10h]
    push bx
    mov bx,word ptr [bp+0Eh]
    push bx
    mov bx,word ptr [bp+0Ch]
    push bx
    push dx
    push ax
    mov ax,word ptr [bp+0Ah]
    push ax
    mov ax,word ptr [bp+8h]
    push ax
    mov ax,word ptr [bp+6h]
    push ax
    push cs
    call mn51
    mov word ptr [bp-2h],ax
lbl71f:
    mov ax,word ptr [bp-2h]
    pop di
    pop si
    pop es
    pop ds
    mov sp,bp
    pop bp
    retf 0Ch
    push bp
    mov bp,sp
    sub sp,2h
    push ds
    push es
    push si
    push di
    mov ax,38AFh
    mov ds,ax
    mov word ptr [bp-2h],0FFE8h
    les di, dword ptr [bp+6h]
    cmp word ptr es:[di],0CA00h
    jz short lblA4f
    mov word ptr [bp-2h],0FFE4h
    jmp short lblF2f
    nop
lblA4f:
    mov ax,word ptr es:[di+16h]
    cmp ax, offset mi78
    jnz short lblC8f
    push word ptr es:[di+1Ah]
    push word ptr es:[di+18h]
    call mf82
    add sp,4h
    or ah,ah
    jz short lblE2f
    mov word ptr [bp-2h],0FFE7h
    jmp short lblF2f
lblC8f:
    cmp ax, offset mi88
    jnz short lblE0f
    mov dx,word ptr es:[di+22h]
    mov ah,45h
    int 67h
    or ah,ah
    jz short lblE2f
    mov word ptr [bp-2h],0FFEAh
    jmp short lblF2f
lblE0f:
    jmp short lblF2f
lblE2f:
    les di, dword ptr [bp+6h]
    mov cx,80h
    mov al,0FFh
    cld
    rep stosb
    mov word ptr [bp-2h],0h
lblF2f:
    mov ax,word ptr [bp-2h]
    pop di
    pop si
    pop es
    pop ds
    mov sp,bp
    pop bp
    retf 4h
    add byte ptr [di-75h],dl
    in al,dx
    sub sp,0Eh
    push ds
    push es
    push si
    push di
    mov ax,38AFh
    mov ds,ax
    les di, dword ptr [bp+8h]
    push es
    push di
    xor ax,ax
    push ax
    push ax
    mov ax,1h
    push ax
    call mf129
    or dx,dx
    jnz short lbl12Bf
    mov word ptr [bp-2h],ax
    jmp near ptr lbl1B5f
lbl12Bf:
    mov word ptr [bp-4h],dx
    mov word ptr [bp-6h],ax
    mov ax,word ptr [bp+6h]
    mov bx,word ptr es:[di+34h]
    mov word ptr [bp-0Ah],bx
    xor bx,bx
    mov bl,byte ptr es:[di+12h]
    mov word ptr [bp-8h],bx
    mov byte ptr [bp-0Eh],al
    jmp short lbl149f
lbl149f:
    xor si,si
    mov dx,word ptr es:[di+14h]
    mov bx,dx
    not bx
    les di, dword ptr [bp-6h]
    cld
lbl157b:
    mov al,byte ptr [bp+si-0Eh]
    mov cx,dx
    cmp di,bx
    ja short lbl17Df
    jmp short lbl182f
lbl162b:
    or di,di
    jnz short lbl17Df
    push dx
    push ax
    mov dx,word ptr [bp+0Ah]
    mov ax,word ptr [bp+8h]
    stc
    call mf162
    mov word ptr [bp-2h],ax
    pop ax
    pop dx
    jnc short lbl17Df
    jmp short lbl1B5f
lbl17Df:
    stosb
    loop lbl162b
    jmp short lbl188f
lbl182f:
    shr cx,1
    mov ah,al
    rep stosw
lbl188f:
    inc si
    cmp si,word ptr [bp-8h]
    jc short lbl190f
    xor si,si
lbl190f:
    dec word ptr [bp-0Ah]
    jz short lbl1B0f
    or di,di
    jnz short lbl1AEf
    push dx
    mov dx,word ptr [bp+0Ah]
    mov ax,word ptr [bp+8h]
    stc
    call mf186
    pop dx
    jnc short lbl1AEf
    mov word ptr [bp-2h],ax
    jmp short lbl1B5f
lbl1AEf:
    jmp short lbl157b
lbl1B0f:
    mov word ptr [bp-2h],0h
lbl1B5f:
    mov ax,word ptr [bp-2h]
    pop di
    pop si
    pop es
    pop ds
    mov sp,bp
    pop bp
    retf 6h
    push bp
    mov bp,sp
    sub sp,0Ah
    push ds
    push es
    push si
    push di
    mov ax,38AFh
    mov ds,ax
    les di, dword ptr [bp+6h]
    mov word ptr es:[di],0h
    mov word ptr es:[di+2h],0h
    mov byte ptr [bp-4h],1h
    mov byte ptr [bp-6h],1h
    mov byte ptr [bp-8h],0h
    mov byte ptr [bp-0Ah],0h
    cmp byte ptr [bp-4h],1h
    push cs
    call mn219
    push cs
    call mn221
    mov word ptr [bp-2h],0h
    mov ax,word ptr [bp-2h]
    pop di
    pop si
    pop es
    pop ds
    mov sp,bp
    pop bp
    retf 4h
    xor al,al
    push bp
    mov ah,1Ah
    int 10h
    pop bp
    cmp al,1Ah
    jz short lbl21Cf
    jmp near ptr lbl2E8f
lbl21Cf:
    mov cx,2h
lbl21Fb:
    or bl,bl
    jnz short lbl22Ff
    mov byte ptr es:[di],0h
    mov byte ptr es:[di+1h],0h
    jmp near ptr lbl2BDf
lbl22Ff:
    cmp bl,1h
    jnz short lbl23Ff
    mov byte ptr es:[di],1h
    mov byte ptr es:[di+1h],1h
    jmp short lbl2BDf
lbl23Ff:
    cmp bl,2h
    jnz short lbl24Ff
    mov byte ptr es:[di],2h
    mov byte ptr es:[di+1h],2h
    jmp short lbl2BDf
lbl24Ff:
    cmp bl,4h
    jnz short lbl25Ff
    mov byte ptr es:[di],3h
    mov byte ptr es:[di+1h],3h
    jmp short lbl2BDf
lbl25Ff:
    cmp bl,5h
    jnz short lbl26Ff
    mov byte ptr es:[di],3h
    mov byte ptr es:[di+1h],1h
    jmp short lbl2BDf
lbl26Ff:
    cmp bl,7h
    jnz short lbl27Ff
    mov byte ptr es:[di],5h
    mov byte ptr es:[di+1h],4h
    jmp short lbl2BDf
lbl27Ff:
    cmp bl,8h
    jnz short lbl28Ff
    mov byte ptr es:[di],5h
    mov byte ptr es:[di+1h],5h
    jmp short lbl2BDf
lbl28Ff:
    cmp bl,0Ah
    jnz short lbl29Ff
    mov byte ptr es:[di],4h
    mov byte ptr es:[di+1h],3h
    jmp short lbl2BDf
lbl29Ff:
    cmp bl,0Bh
    jnz short lbl2AFf
    mov byte ptr es:[di],4h
    mov byte ptr es:[di+1h],4h
    jmp short lbl2BDf
lbl2AFf:
    cmp bl,0Ch
    jnz short lbl2BDf
    mov byte ptr es:[di],4h
    mov byte ptr es:[di+1h],5h
lbl2BDf:
    dec cx
    jz short lbl2C8f
    mov bl,bh
    add di,2h
    jmp near ptr lbl21Fb
lbl2C8f:
    sub di,2h
    mov byte ptr [bp-6h],0h
    mov byte ptr [bp-8h],0h
    mov byte ptr [bp-0Ah],0h
    push di
    cmp byte ptr es:[di],1h
    jz short lbl2E7f
    add di,2h
    cmp byte ptr es:[di],1h
    jnz short lbl2E7f
lbl2E7f:
    pop di
lbl2E8f:
    retf
    cmp byte ptr es:[di+2h],0h
    jz short lbl322f
    cmp byte ptr es:[di],4h
    jnl short lbl322f
    cmp byte ptr es:[di+2h],4h
    jnl short lbl322f
    call mf312
    and al,7h
    cmp al,7h
    jz short lbl311f
    cmp byte ptr es:[di+1h],1h
    jnz short lbl322f
    jmp short lbl318f
lbl311f:
    cmp byte ptr es:[di+1h],1h
    jz short lbl322f
lbl318f:
    mov ax,word ptr es:[di]
    xchg ax,word ptr es:[di+2h]
    mov word ptr es:[di],ax
lbl322f:
    retf
    add byte ptr [di-75h],dl
    in al,dx
    sub sp,8h
    push ds
    push es
    push si
    push di
    mov ax,38AFh
    mov ds,ax
    les di, dword ptr [bp+0Ch]
    cmp word ptr es:[di],0CA00h
    jz short lbl354f
    xor dx,dx
    mov ax,0FFE4h
    jmp near ptr lbl41Ef
    cmp word ptr es:[di+16h],3h
    jna short lbl354f
    xor dx,dx
    mov ax,0FFE8h
    jmp near ptr lbl41Ef
lbl354f:
    mov ax,word ptr es:[di+0Ah]
    cmp word ptr [bp+0Ah],ax
    ja short lbl366f
    mov ax,word ptr es:[di+0Ch]
    cmp word ptr [bp+8h],ax
    jna short lbl36Ef
lbl366f:
    xor dx,dx
    mov ax,0FFE5h
    jmp near ptr lbl41Ef
lbl36Ef:
    xor ax,ax
    mov al,byte ptr es:[di+13h]
    mul word ptr [bp+0Ah]
    mov cl,3h
    shr ax,cl
    push ax
    xor ax,ax
    mov al,byte ptr es:[di+12h]
    mul word ptr es:[di+14h]
    mul word ptr [bp+8h]
    pop bx
    add ax,bx
    adc dx,0h
    mov word ptr [bp-4h],dx
    mov word ptr [bp-6h],ax
    cmp word ptr es:[di+16h],0h
    jnz short lbl3B3f
    mov bx,10h
    div bx
    xchg ax,dx
    add dx,word ptr es:[di+1Ah]
    add ax,word ptr es:[di+18h]
    jnc short lbl3B0f
    add dx,1000h
lbl3B0f:
    jmp short lbl41Ef
    nop
lbl3B3f:
    mov bx,word ptr es:[di+28h]
    mov word ptr [bp-8h],bx
    shl ax,1
    rcl dx,1
    shl ax,1
    rcl dx,1
    mov word ptr es:[di+26h],dx
    shr ax,1
    shr ax,1
    mov word ptr [bp-6h],ax
    mov cx,word ptr es:[di+24h]
    sub cx,word ptr es:[di+26h]
    ja short lbl3DFf
    xor dx,dx
    mov ax,0FC19h
    jmp short lbl41Ef
    nop
lbl3DFf:
    cmp cx,word ptr es:[di+2Ah]
    jna short lbl3E9f
    mov cx,word ptr es:[di+2Ah]
lbl3E9b:
lbl3E9f:
    mov dx,word ptr es:[di+22h]
    mov bx,word ptr es:[di+26h]
    inc word ptr es:[di+26h]
    mov ax,word ptr [bp-8h]
    inc word ptr [bp-8h]
    mov ah,44h
    int 67h
    or ah,ah
    loope lbl3E9b
    jz short lbl40Af
    xor dx,dx
    mov ax,0FFEAh
lbl40Af:
    mov ax,4000h
    mul word ptr es:[di+28h]
    mov cl,4h
    shr ax,cl
    add ax,word ptr es:[di+1Ah]
    mov dx,ax
    mov ax,word ptr [bp-6h]
lbl41Ef:
    mov word ptr [bp-2h],ax
    mov ax,word ptr [bp-2h]
    pop di
    pop si
    pop es
    pop ds
    mov sp,bp
    pop bp
    retf 0Ah
    push bp
    mov bp,sp
    push bx
    push cx
    push di
    push es
    mov bx,0h
    jnc short lbl43Df
    mov bx,1h
lbl43Df:
    push bx
    mov es,dx
    mov di,ax
    mov ax,word ptr es:[di+16h]
    cmp ax, offset mi441
    jnz short lbl463f
    cmp word ptr [bp-0Ah],0h
    jnz short lbl45Bf
    mov ax,ds
    add ax,1000h
    mov ds,ax
    jmp short lbl4BDf
    nop
lbl45Bf:
    add word ptr [bp-8h],1000h
    jmp short lbl4BDf
    nop
lbl463f:
    mov ax,word ptr es:[di+2Ah]
    mov bx,4000h
    mul bx
    cmp word ptr [bp-0Ah],0h
    jnz short lbl476f
    sub si,ax
    jmp short lbl479f
lbl476f:
    sub word ptr [bp-6h],ax
lbl479f:
    mov cx,word ptr es:[di+24h]
    sub cx,word ptr es:[di+26h]
    ja short lbl489f
    mov ax,0FC19h
    jmp short lbl4BAf
    nop
lbl489f:
    mov ax,word ptr es:[di+28h]
    dec ax
    cmp cx,word ptr es:[di+2Ah]
    jna short lbl498f
    mov cx,word ptr es:[di+2Ah]
lbl498b:
lbl498f:
    mov dx,word ptr es:[di+22h]
    mov bx,word ptr es:[di+26h]
    inc word ptr es:[di+26h]
    inc ax
    push ax
    mov ah,44h
    int 67h
    or ah,ah
    pop ax
    loope lbl498b
    jnz short lbl4B4f
    jmp short lbl4BDf
    nop
lbl4B4f:
    mov ax,0FFEAh
    jmp short lbl4BAf
    nop
lbl4BAf:
    stc
    jmp short lbl4BEf
lbl4BDf:
    clc
lbl4BEf:
    mov es, [bp-8h]
    mov di,word ptr [bp-6h]
    mov cx,word ptr [bp-4h]
    mov bx,word ptr [bp-2h]
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
