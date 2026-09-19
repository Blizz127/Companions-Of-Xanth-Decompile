_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mfa9c:FAR
    EXTRN mn19b:NEAR
    EXTRN mfa46:FAR
    EXTRN mfb56:FAR
    EXTRN mibb5:NEAR
    EXTRN mn291:NEAR
    EXTRN mf91d:FAR
    EXTRN mf8da:FAR
    EXTRN mic07:NEAR
    EXTRN mn5dc:NEAR
    EXTRN mic0c:NEAR
    EXTRN mfad4:FAR
    EXTRN mj4a5:FAR
    EXTRN mfa17:FAR
    EXTRN mn685:NEAR
    EXTRN mibb0:NEAR
    EXTRN mn2d7:NEAR
    EXTRN mn3c2:NEAR
    EXTRN mj880:FAR
    EXTRN mfb34:FAR
    EXTRN mn57c:NEAR
    EXTRN mfa5d:FAR
    EXTRN mn539:NEAR
    EXTRN mfa2e:FAR
    EXTRN mibc9:NEAR
    EXTRN mn335:NEAR
    EXTRN mn66b:NEAR
    EXTRN mic55:NEAR
    EXTRN mn87:NEAR
    EXTRN mn3ed:NEAR
    EXTRN mi9be:NEAR
    EXTRN mf422:FAR
    EXTRN mi9cc:NEAR
    EXTRN mf903:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,2h
    push ds
    push es
    push si
    push di
    mov ax,38AFh
    mov ds,ax
    mov si,52A6h
    les di, dword ptr [bp+12h]
    mov ax,word ptr [si+1Ah]
    mov word ptr es:[di],ax
    les di, dword ptr [bp+0Eh]
    mov ax,word ptr [si+1Ch]
    mov word ptr es:[di],ax
    les di, dword ptr [bp+0Ah]
    mov ax,word ptr [si+1Eh]
    mov word ptr es:[di],ax
    les di, dword ptr [bp+6h]
    mov ax,word ptr [si+20h]
    mov word ptr es:[di],ax
    mov word ptr [bp-2h],0h
    mov ax,word ptr [bp-2h]
    pop di
    pop si
    pop es
    pop ds
    mov sp,bp
    pop bp
    retf 10h
    push ds
    push si
    push ax
    mov ax,38AFh
    mov ds,ax
    mov si,52A6h
    pop ax
    cmp ax,word ptr [si+1Ah]
    jl short lbl6Bf
    cmp bx,word ptr [si+1Ch]
    jl short lbl6Bf
    cmp ax,word ptr [si+1Eh]
    jg short lbl6Bf
    cmp bx,word ptr [si+20h]
    jg short lbl6Bf
    clc
    jmp short lbl6Cf
lbl6Bf:
    stc
lbl6Cf:
    pop si
    pop ds
    retf
    push bp
    mov bp,sp
    sub sp,6h
    push ds
    push es
    push si
    push di
    mov ax,38AFh
    mov ds,ax
    mov word ptr [bp-6h],0h
    mov si,52A6h
lbl86b:
    push cs
    call mn87
    mov word ptr [bp-4h],ax
    or ah,al
    jnz short lbl94f
    jmp near ptr lbl156f
lbl94f:
    mov ax,word ptr [bp-4h]
    and ah,al
    jz short lbl9Ef
    jmp near ptr lbl156f
lbl9Ef:
    mov ax,word ptr [bp-4h]
    test al,0Fh
    jnz short lblC1f
    mov ax,word ptr [bp+0Ch]
    xchg ax,word ptr [bp+8h]
    mov word ptr [bp+0Ch],ax
    mov ax,word ptr [bp+0Ah]
    xchg ax,word ptr [bp+6h]
    mov word ptr [bp+0Ah],ax
    mov ax,word ptr [bp-4h]
    db 86h, 0E0h ; override
    mov word ptr [bp-6h],1h
lblC1f:
    test al,1h
    jz short lblE6f
    mov ax,word ptr [bp+6h]
    sub ax,word ptr [bp+0Ah]
    mov bx,word ptr [si+1Ah]
    sub bx,word ptr [bp+0Ch]
    imul bx
    mov bx,word ptr [bp+8h]
    sub bx,word ptr [bp+0Ch]
    idiv bx
    add word ptr [bp+0Ah],ax
    mov ax,word ptr [si+1Ah]
    mov word ptr [bp+0Ch],ax
    jmp short lbl153f
lblE6f:
    test al,2h
    jz short lbl10Bf
    mov ax,word ptr [bp+8h]
    sub ax,word ptr [bp+0Ch]
    mov bx,word ptr [si+1Ch]
    sub bx,word ptr [bp+0Ah]
    imul bx
    mov bx,word ptr [bp+6h]
    sub bx,word ptr [bp+0Ah]
    idiv bx
    add word ptr [bp+0Ch],ax
    mov ax,word ptr [si+1Ch]
    mov word ptr [bp+0Ah],ax
    jmp short lbl153f
lbl10Bf:
    test al,4h
    jz short lbl130f
    mov ax,word ptr [bp+6h]
    sub ax,word ptr [bp+0Ah]
    mov bx,word ptr [si+1Eh]
    sub bx,word ptr [bp+0Ch]
    imul bx
    mov bx,word ptr [bp+8h]
    sub bx,word ptr [bp+0Ch]
    idiv bx
    add word ptr [bp+0Ah],ax
    mov ax,word ptr [si+1Eh]
    mov word ptr [bp+0Ch],ax
    jmp short lbl153f
lbl130f:
    test al,8h
    jz short lbl153f
    mov ax,word ptr [bp+8h]
    sub ax,word ptr [bp+0Ch]
    mov bx,word ptr [si+20h]
    sub bx,word ptr [bp+0Ah]
    imul bx
    mov bx,word ptr [bp+6h]
    sub bx,word ptr [bp+0Ah]
    idiv bx
    add word ptr [bp+0Ch],ax
    mov ax,word ptr [si+20h]
    mov word ptr [bp+0Ah],ax
lbl153f:
    jmp near ptr lbl86b
lbl156f:
    mov ax,word ptr [bp+0Ch]
    mov bx,word ptr [bp+0Ah]
    mov cx,word ptr [bp+8h]
    mov dx,word ptr [bp+6h]
    cmp word ptr [bp-6h],1h
    jnz short lbl16Bf
    xchg ax,cx
    db 87h, 0DAh ; override
lbl16Bf:
    mov word ptr [bp-2h],ax
    clc
    cmp word ptr [bp-4h],0h
    jz short lbl176f
    stc
lbl176f:
    mov ax,word ptr [bp-2h]
    pop di
    pop si
    pop es
    pop ds
    mov sp,bp
    pop bp
    retf 8h
    push bp
    mov bp,sp
    sub sp,6h
    push ds
    push es
    push si
    push di
    mov ax,38AFh
    mov ds,ax
    mov word ptr [bp-6h],0h
    mov si,52A6h
lbl19Ab:
    push cs
    call mn19b
    mov word ptr [bp-4h],ax
    or ah,al
    jnz short lbl1A7f
    jmp short lbl203f
lbl1A7f:
    mov ax,word ptr [bp-4h]
    and ah,al
    jz short lbl1B0f
    jmp short lbl203f
lbl1B0f:
    mov ax,word ptr [bp-4h]
    test al,0Fh
    jnz short lbl1D3f
    mov ax,word ptr [bp+0Ch]
    xchg ax,word ptr [bp+8h]
    mov word ptr [bp+0Ch],ax
    mov ax,word ptr [bp+0Ah]
    xchg ax,word ptr [bp+6h]
    mov word ptr [bp+0Ah],ax
    mov ax,word ptr [bp-4h]
    db 86h, 0E0h ; override
    mov word ptr [bp-6h],1h
lbl1D3f:
    test al,1h
    jz short lbl1DFf
    mov ax,word ptr [si+1Ah]
    mov word ptr [bp+0Ch],ax
    jmp short lbl201f
lbl1DFf:
    test al,2h
    jz short lbl1EBf
    mov ax,word ptr [si+1Ch]
    mov word ptr [bp+0Ah],ax
    jmp short lbl201f
lbl1EBf:
    test al,4h
    jz short lbl1F7f
    mov ax,word ptr [si+1Eh]
    mov word ptr [bp+0Ch],ax
    jmp short lbl201f
lbl1F7f:
    test al,8h
    jz short lbl201f
    mov ax,word ptr [si+20h]
    mov word ptr [bp+0Ah],ax
lbl201f:
    jmp short lbl19Ab
lbl203f:
    mov ax,word ptr [bp+0Ch]
    mov bx,word ptr [bp+0Ah]
    mov cx,word ptr [bp+8h]
    mov dx,word ptr [bp+6h]
    cmp word ptr [bp-6h],1h
    jnz short lbl218f
    xchg ax,cx
    db 87h, 0DAh ; override
lbl218f:
    mov word ptr [bp-2h],ax
    clc
    cmp word ptr [bp-4h],0h
    jz short lbl223f
    stc
lbl223f:
    mov ax,word ptr [bp-2h]
    pop di
    pop si
    pop es
    pop ds
    mov sp,bp
    pop bp
    retf 8h
    xor ax,ax
    mov cx,word ptr [bp+0Ch]
    mov dx,word ptr [bp+0Ah]
    cmp cx,word ptr [si+1Ah]
    jnl short lbl23Ff
    or al,1h
lbl23Ff:
    cmp dx,word ptr [si+1Ch]
    jnl short lbl246f
    or al,2h
lbl246f:
    cmp cx,word ptr [si+1Eh]
    jng short lbl24Df
    or al,4h
lbl24Df:
    cmp dx,word ptr [si+20h]
    jng short lbl254f
    or al,8h
lbl254f:
    mov cx,word ptr [bp+8h]
    mov dx,word ptr [bp+6h]
    cmp cx,word ptr [si+1Ah]
    jnl short lbl262f
    or ah,1h
lbl262f:
    cmp dx,word ptr [si+1Ch]
    jnl short lbl26Af
    or ah,2h
lbl26Af:
    cmp cx,word ptr [si+1Eh]
    jng short lbl272f
    or ah,4h
lbl272f:
    cmp dx,word ptr [si+20h]
    jng short lbl27Af
    or ah,8h
lbl27Af:
    retf
    push bp
    mov bp,sp
    sub sp,2h
    push ds
    push es
    push si
    push di
    mov ax,38AFh
    mov ds,ax
    mov ax,word ptr [bp+8h]
    mov bx,word ptr [bp+6h]
    push cs
    call mn291
    jnc short lbl29Df
    mov word ptr [bp-2h],0FFE5h
    jmp short lbl2A2f
lbl29Df:
    mov word ptr [bp-2h],0h
lbl2A2f:
    mov ax,word ptr [bp-2h]
    pop di
    pop si
    pop es
    pop ds
    mov sp,bp
    pop bp
    retf 4h
    push bp
    mov bp,sp
    sub sp,2h
    push ds
    push es
    push si
    push di
    mov ax,38AFh
    mov ds,ax
    les di, dword ptr [bp+12h]
    push word ptr es:[di]
    les di, dword ptr [bp+0Eh]
    push word ptr es:[di]
    les di, dword ptr [bp+0Ah]
    push word ptr es:[di]
    les di, dword ptr [bp+6h]
    push word ptr es:[di]
    push cs
    call mn2d7
    jnc short lbl2E3f
    mov word ptr [bp-2h],0FFE5h
    jmp short lbl300f
lbl2E3f:
    les di, dword ptr [bp+12h]
    mov word ptr es:[di],ax
    les di, dword ptr [bp+0Eh]
    mov word ptr es:[di],bx
    les di, dword ptr [bp+0Ah]
    mov word ptr es:[di],cx
    les di, dword ptr [bp+6h]
    mov word ptr es:[di],dx
    mov word ptr [bp-2h],0h
lbl300f:
    mov ax,word ptr [bp-2h]
    pop di
    pop si
    pop es
    pop ds
    mov sp,bp
    pop bp
    retf 10h
    push bp
    mov bp,sp
    sub sp,2h
    push ds
    push es
    push si
    push di
    mov ax,38AFh
    mov ds,ax
    les di, dword ptr [bp+12h]
    push word ptr es:[di]
    les di, dword ptr [bp+0Eh]
    push word ptr es:[di]
    les di, dword ptr [bp+0Ah]
    push word ptr es:[di]
    les di, dword ptr [bp+6h]
    push word ptr es:[di]
    push cs
    call mn335
    jnc short lbl341f
    mov word ptr [bp-2h],0FFE5h
    jmp short lbl35Ef
lbl341f:
    les di, dword ptr [bp+12h]
    mov word ptr es:[di],ax
    les di, dword ptr [bp+0Eh]
    mov word ptr es:[di],bx
    les di, dword ptr [bp+0Ah]
    mov word ptr es:[di],cx
    les di, dword ptr [bp+6h]
    mov word ptr es:[di],dx
    mov word ptr [bp-2h],0h
lbl35Ef:
    mov ax,word ptr [bp-2h]
    pop di
    pop si
    pop es
    pop ds
    mov sp,bp
    pop bp
    retf 10h
    push bp
    mov bp,sp
    sub sp,2h
    push ds
    push es
    push si
    push di
    mov ax,38AFh
    mov ds,ax
    mov si,52A6h
    mov ax,word ptr [bp+8h]
    mov word ptr [si+12h],ax
    mov ax,word ptr [bp+6h]
    mov word ptr [si+14h],ax
    mov word ptr [bp-2h],0h
    mov ax,word ptr [bp-2h]
    pop di
    pop si
    pop es
    pop ds
    mov sp,bp
    pop bp
    retf 4h
    push bp
    mov bp,sp
    sub sp,4h
    push ds
    push es
    push si
    push di
    mov ax,38AFh
    mov ds,ax
    mov si,52A6h
    push word ptr [si+12h]
    push word ptr [si+14h]
    mov ax,word ptr [bp+8h]
    push ax
    mov word ptr [si+12h],ax
    mov ax,word ptr [bp+6h]
    push ax
    mov word ptr [si+14h],ax
    push cs
    call mn3c2
    mov word ptr [bp-2h],ax
    mov ax,word ptr [bp-2h]
    pop di
    pop si
    pop es
    pop ds
    mov sp,bp
    pop bp
    retf 4h
    push bp
    mov bp,sp
    sub sp,4Ch
    push ds
    push es
    push si
    push di
    mov ax,38AFh
    mov ds,ax
    cld
    cmp byte ptr ds:[52FFh],1h
    jz short lbl3F0f
    push cs
    call mn3ed
lbl3F0f:
    mov si,52A6h
    mov ax,word ptr [si+28h]
    mov word ptr [bp-2Ah],ax
    cmp word ptr [si+18h],1h
    jnz short lbl44Ff
    mov ax,word ptr [bp+0Ch]
    cmp ax,word ptr [bp+8h]
    jng short lbl416f
    xchg ax,word ptr [bp+8h]
    mov word ptr [bp+0Ch],ax
    mov ax,word ptr [bp+0Ah]
    xchg ax,word ptr [bp+6h]
    mov word ptr [bp+0Ah],ax
lbl416f:
    push word ptr [bp+0Ch]
    push word ptr [bp+0Ah]
    push word ptr [bp+8h]
    push word ptr [bp+6h]
    call mf422
    jnc short lbl431f
    mov word ptr [bp-2h],0h
    jmp short lbl4ADf
    nop
lbl431f:
    cmp ax,word ptr [bp+0Ch]
    jz short lbl443f
    push cx
    mov cl,byte ptr [bp+0Ch]
    sub cl,al
    and cl,7h
    ror word ptr [bp-2Ah],cl
    pop cx
lbl443f:
    mov word ptr [bp+0Ch],ax
    mov word ptr [bp+0Ah],bx
    mov word ptr [bp+8h],cx
    mov word ptr [bp+6h],dx
lbl44Ff:
    mov ax,word ptr [si+16h]
    mov word ptr [bp-24h],ax
    mov ax,word ptr [si+0Ch]
    mov word ptr [bp-26h],ax
    mov ax,word ptr [si+10h]
    mov word ptr [bp-28h],ax
    mov ax,word ptr [si+2Ah]
    shr ax,1
    mov word ptr [bp-2Ch],ax
    mov si,5365h
    mov dx,word ptr ds:[5244h]
    cmp dx,0h
    jc short lbl47Af
    cmp dx,0h
    jna short lbl481f
lbl47Af:
    mov word ptr [bp-2h],0FFFAh
    jmp short lbl4ADf
lbl481f:
    mov ax,10h
    mul dx
    add si,ax
    cmp word ptr [bp-2Ch],0h
    jnz short lbl4A0f
    cmp word ptr [bp-2Ah],0FFFFFFFFFFFFFFFFh
    jz short lbl497f
    jmp short lbl4A5f
    nop
lbl497f:
    mov ax,word ptr [si+2h]
    mov word ptr [bp-20h],ax
    db 0FFh, 6Ch, 04h ; override
lbl4A0f:
    jmp short lbl4D0f
    nop
    nop
    nop
lbl4A5f:
    jmp mj4a5
    mov word ptr [bp-2h],ax
lbl4ADf:
    mov ax,word ptr [bp-2h]
    pop di
    pop si
    pop es
    pop ds
    mov sp,bp
    pop bp
    retf 8h
    mov bx,5365h
    mov word ptr [bx+4h],517h
    mov word ptr [bx+6h],7E1h
    add bx,10h
    mov byte ptr ds:[52FFh],1h
    retf
lbl4D0f:
    mov si,52A6h
    mov ax,word ptr [si+3Ch]
    mov word ptr [bp-44h],ax
    mov word ptr [si+3Ch],0h
    mov ax,word ptr [si+30h]
    mov word ptr [bp-32h],ax
    mov ax,word ptr [si+32h]
    mov word ptr [bp-34h],ax
    mov word ptr [si+30h],0h
    mov word ptr [si+32h],0h
    mov ax,word ptr [si+28h]
    mov word ptr [bp-2Eh],ax
    mov ax,word ptr [si+2Ah]
    mov word ptr [bp-30h],ax
    mov word ptr [si+2Ah],1h
    mov ax,word ptr [bp+8h]
    sub ax,word ptr [bp+0Ch]
    mov bx,ax
    or bx,bx
    jnl short lbl513f
    neg bx
lbl513f:
    mov word ptr [bp-4h],bx
    or ax,ax
    jz short lbl526f
    jl short lbl521f
    mov ax,1h
    jmp short lbl545f
lbl521f:
    mov ax,0FFFFh
    jmp short lbl545f
lbl526f:
    mov di,word ptr [bp-2Ch]
    neg di
lbl52Bb:
    mov ax,word ptr [bp+0Ch]
    add ax,di
    push ax
    push word ptr [bp+0Ah]
    push ax
    push word ptr [bp+6h]
    push cs
    call mn539
    inc di
    cmp di,word ptr [bp-2Ch]
    jng short lbl52Bb
    jmp near ptr lbl68Ef
lbl545f:
    mov word ptr [bp-0Ch],ax
    mov ax,word ptr [bp+6h]
    sub ax,word ptr [bp+0Ah]
    mov bx,ax
    or bx,bx
    jnl short lbl556f
    neg bx
lbl556f:
    mov word ptr [bp-6h],bx
    or ax,ax
    jz short lbl569f
    jl short lbl564f
    mov ax,1h
    jmp short lbl588f
lbl564f:
    mov ax,0FFFFh
    jmp short lbl588f
lbl569f:
    mov di,word ptr [bp-2Ch]
    neg di
lbl56Eb:
    push word ptr [bp+0Ch]
    mov bx,word ptr [bp+0Ah]
    add bx,di
    push bx
    push word ptr [bp+8h]
    push bx
    push cs
    call mn57c
    inc di
    cmp di,word ptr [bp-2Ch]
    jng short lbl56Eb
    jmp near ptr lbl68Ef
lbl588f:
    mov word ptr [bp-0Eh],ax
    mov ax,word ptr [bp-6h]
    cmp ax,word ptr [bp-4h]
    ja short lbl596f
    mov ax,word ptr [bp-4h]
lbl596f:
    mov word ptr [bp-8h],ax
    cmp word ptr [bp-24h],0h
    jnz short lbl5F7f
    jmp short lbl5F7f
    mov ax,word ptr [bp-4h]
    cmp ax,word ptr [bp-6h]
    ja short lbl5B7f
    mov si,word ptr [bp-2Ch]
    neg si
    xor di,di
    mov word ptr [bp-4h],1h
    jmp short lbl5C3f
lbl5B7f:
    xor si,si
    mov di,word ptr [bp-2Ch]
    neg di
    mov word ptr [bp-4h],0h
lbl5C3b:
lbl5C3f:
    mov ax,word ptr [bp+0Ch]
    add ax,si
    push ax
    mov ax,word ptr [bp+0Ah]
    add ax,di
    push ax
    mov ax,word ptr [bp+8h]
    add ax,si
    push ax
    mov ax,word ptr [bp+6h]
    add ax,di
    push ax
    push cs
    call mn5dc
    cmp word ptr [bp-4h],1h
    jnz short lbl5EEf
    inc si
    cmp si,word ptr [bp-2Ch]
    jng short lbl5C3b
    jmp near ptr lbl68Ef
lbl5EEf:
    inc di
    cmp di,word ptr [bp-2Ch]
    jl short lbl5C3b
    jmp near ptr lbl68Ef
lbl5F7f:
    mov word ptr [si+28h],0FFFFh
    mov ax,word ptr [bp+0Ch]
    mov word ptr [bp-12h],ax
    mov ax,word ptr [bp+0Ah]
    mov word ptr [bp-14h],ax
    xor si,si
    xor di,di
    mov cx,word ptr [bp-8h]
    inc cx
lbl610b:
    add si,word ptr [bp-4h]
    add di,word ptr [bp-6h]
    mov word ptr [bp-10h],0h
    cmp si,word ptr [bp-8h]
    jng short lbl62Ef
    mov word ptr [bp-10h],1h
    sub si,word ptr [bp-8h]
    mov ax,word ptr [bp-0Ch]
    add word ptr [bp-12h],ax
lbl62Ef:
    cmp di,word ptr [bp-8h]
    jng short lbl641f
    mov word ptr [bp-10h],1h
    sub di,word ptr [bp-8h]
    mov ax,word ptr [bp-0Eh]
    add word ptr [bp-14h],ax
lbl641f:
    cmp word ptr [bp-10h],1h
    jnz short lbl689f
    rol word ptr [bp-2Ah],1
    jnc short lbl689f
    mov dx,word ptr [bp-2Ch]
    mov ax,word ptr [bp-4h]
    cmp ax,word ptr [bp-6h]
    jl short lbl671f
    push cx
    push word ptr [bp-12h]
    mov ax,word ptr [bp-14h]
    sub ax,dx
    push ax
    push word ptr [bp-12h]
    mov ax,word ptr [bp-14h]
    add ax,dx
    push ax
    push cs
    call mn66b
    pop cx
    jmp short lbl689f
lbl671f:
    push cx
    mov ax,word ptr [bp-12h]
    sub ax,dx
    push ax
    push word ptr [bp-14h]
    mov ax,word ptr [bp-12h]
    add ax,dx
    push ax
    push word ptr [bp-14h]
    push cs
    call mn685
    pop cx
lbl689f:
    dec cx
    jz short lbl68Ef
    jmp short lbl610b
lbl68Ef:
    mov bx,52A6h
    mov ax,word ptr [bp-44h]
    mov word ptr [bx+3Ch],ax
    mov ax,word ptr [bp-32h]
    mov word ptr [bx+30h],ax
    mov ax,word ptr [bp-34h]
    mov word ptr [bx+32h],ax
    mov ax,word ptr [bp-2Eh]
    mov word ptr [bx+28h],ax
    mov ax,word ptr [bp-30h]
    mov word ptr [bx+2Ah],ax
    mov word ptr [bp-2h],0h
    mov ax,word ptr [bp-2h]
    pop di
    pop si
    pop es
    pop ds
    mov sp,bp
    pop bp
    retf 8h
    mov si,52A6h
    cmp word ptr [si+16h],0h
    jnz short lbl6CFf
    mov word ptr [bp-28h],1h
lbl6CFf:
    mov si,52A2h
    mov ax,word ptr ds:[5242h]
    shl ax,1
    shl ax,1
    add si,ax
    mov ax,word ptr [bp+6h]
    cmp ax,word ptr [bp+0Ah]
    jnz short lbl719f
    mov di,word ptr [bp+0Ch]
    cmp di,word ptr [bp+8h]
    jng short lbl6EEf
    xchg di,word ptr [bp+8h]
lbl6EEf:
    mov ax,word ptr [si]
    mov word ptr [bp-4Ch],ax
    mov ax,word ptr [si+2h]
    mov word ptr [bp-4Ah],ax
    mov es, [bp-26h]
    mov ds, [bp+0Ah]
    cmp word ptr [bp-28h],1h
    jnz short lbl710f
lbl705b:
    rol word ptr [bp-2Ah],1
    jnc short lbl710f
    push di
    push ds
    push es
    db 0FFh, 5Eh, 0B4h ; override
lbl710f:
    inc di
    cmp di,word ptr [bp+8h]
    jng short lbl705b
    jmp near ptr lbl868f
lbl719f:
    mov ax,word ptr [bp+8h]
    sub ax,word ptr [bp+0Ch]
    jns short lbl735f
    neg ax
    mov bx,word ptr [bp+0Ch]
    xchg bx,word ptr [bp+8h]
    mov word ptr [bp+0Ch],bx
    mov bx,word ptr [bp+0Ah]
    xchg bx,word ptr [bp+6h]
    mov word ptr [bp+0Ah],bx
lbl735f:
    mov bx,word ptr [bp+6h]
    sub bx,word ptr [bp+0Ah]
    jns short lbl740f
    jmp near ptr lbl7D6f
lbl740f:
    cmp ax,bx
    jl short lbl78Df
    shl bx,1
    mov word ptr [bp-48h],bx
    mov dx,bx
    sub dx,ax
    mov cx,dx
    sub cx,ax
    mov word ptr [bp-46h],cx
    mov cx,ax
    inc cx
    mov bx,si
    mov si,word ptr [bp+0Ch]
    mov di,word ptr [bp+0Ah]
    cmp word ptr [bp-28h],1h
    jnz short lbl777f
lbl765b:
    rol word ptr [bp-2Ah],1
    jnc short lbl777f
    push bx
    push cx
    push dx
    push si
    push di
    push word ptr [bp-26h]
    db 0FFh, 1Fh ; override
    pop dx
    pop cx
    pop bx
lbl777f:
    inc si
    or dx,dx
    jns short lbl784f
    add dx,word ptr [bp-48h]
    loop lbl765b
    jmp near ptr lbl868f
lbl784f:
    inc di
    add dx,word ptr [bp-46h]
    loop lbl765b
    jmp near ptr lbl868f
lbl78Df:
    shl ax,1
    mov word ptr [bp-48h],ax
    mov dx,ax
    sub dx,bx
    mov cx,dx
    sub cx,bx
    mov word ptr [bp-46h],cx
    mov cx,bx
    inc cx
    mov bx,si
    mov si,word ptr [bp+0Ch]
    mov di,word ptr [bp+0Ah]
    cmp word ptr [bp-28h],1h
    jnz short lbl7C0f
lbl7AEb:
    rol word ptr [bp-2Ah],1
    jnc short lbl7C0f
    push bx
    push cx
    push dx
    push si
    push di
    push word ptr [bp-26h]
    db 0FFh, 1Fh ; override
    pop dx
    pop cx
    pop bx
lbl7C0f:
    inc di
    or dx,dx
    jns short lbl7CDf
    add dx,word ptr [bp-48h]
    loop lbl7AEb
    jmp near ptr lbl868f
lbl7CDf:
    inc si
    add dx,word ptr [bp-46h]
    loop lbl7AEb
    jmp near ptr lbl868f
lbl7D6f:
    neg bx
    cmp bx,ax
    jnl short lbl823f
    shl bx,1
    mov word ptr [bp-48h],bx
    mov dx,bx
    sub dx,ax
    mov cx,dx
    sub cx,ax
    mov word ptr [bp-46h],cx
    mov cx,ax
    inc cx
    mov bx,si
    mov si,word ptr [bp+0Ch]
    mov di,word ptr [bp+0Ah]
    cmp word ptr [bp-28h],1h
    jnz short lbl80Ff
lbl7FDb:
    rol word ptr [bp-2Ah],1
    jnc short lbl80Ff
    push bx
    push cx
    push dx
    push si
    push di
    push word ptr [bp-26h]
    db 0FFh, 1Fh ; override
    pop dx
    pop cx
    pop bx
lbl80Ff:
    inc si
    or dx,dx
    jns short lbl81Bf
    add dx,word ptr [bp-48h]
    loop lbl7FDb
    jmp short lbl868f
lbl81Bf:
    dec di
    add dx,word ptr [bp-46h]
    loop lbl7FDb
    jmp short lbl868f
lbl823f:
    shl ax,1
    mov word ptr [bp-48h],ax
    mov dx,ax
    sub dx,bx
    mov cx,dx
    sub cx,bx
    mov word ptr [bp-46h],cx
    mov cx,bx
    inc cx
    mov bx,si
    mov si,word ptr [bp+0Ch]
    mov di,word ptr [bp+0Ah]
    cmp word ptr [bp-28h],1h
    jnz short lbl856f
lbl844b:
    rol word ptr [bp-2Ah],1
    jnc short lbl856f
    push bx
    push cx
    push dx
    push si
    push di
    push word ptr [bp-26h]
    db 0FFh, 1Fh ; override
    pop dx
    pop cx
    pop bx
lbl856f:
    dec di
    or dx,dx
    jns short lbl862f
    add dx,word ptr [bp-48h]
    loop lbl844b
    jmp short lbl868f
lbl862f:
    inc si
    add dx,word ptr [bp-46h]
    loop lbl844b
lbl868f:
    mov word ptr [bp-2h],0h
    mov ax,word ptr [bp-2h]
    pop di
    pop si
    pop es
    pop ds
    mov sp,bp
    pop bp
    retf 8h
    cmp word ptr [bp-24h],0h
    jz short lbl885f
    jmp mj880
lbl885f:
    mov si,140h
    mov cx,word ptr [bp+8h]
    sub cx,word ptr [bp+0Ch]
    jz short lbl8EEf
    jns short lbl8A6f
    neg cx
    mov bx,word ptr [bp+8h]
    xchg bx,word ptr [bp+0Ch]
    mov word ptr [bp+8h],bx
    mov bx,word ptr [bp+6h]
    xchg bx,word ptr [bp+0Ah]
    mov word ptr [bp+6h],bx
lbl8A6f:
    mov bx,word ptr [bp+6h]
    sub bx,word ptr [bp+0Ah]
    jz short lbl916f
    jns short lbl8B4f
    neg bx
    neg si
lbl8B4f:
    push si
    mov word ptr [bp-1Ch],0h
    cmp bx,cx
    jng short lbl8C5f
    mov word ptr [bp-1Ch],1h
    db 87h, 0D9h ; override
lbl8C5f:
    shl bx,1
    mov word ptr [bp-18h],bx
    sub bx,cx
    mov si,bx
    sub bx,cx
    mov word ptr [bp-1Ah],bx
    push cx
    mov ax,word ptr [bp+0Ah]
    mov bx,word ptr [bp+0Ch]
    call mf8da
    mov di,bx
    pop cx
    inc cx
    pop bx
    cmp word ptr [bp-1Ch],0h
    jnz short lbl8ECf
    jmp short lbl92Df
lbl8ECf:
    jmp short lbl945f
lbl8EEf:
    mov ax,word ptr [bp+0Ah]
    mov bx,word ptr [bp+6h]
    mov cx,bx
    sub cx,ax
    jnl short lbl8FEf
    neg cx
    mov ax,bx
lbl8FEf:
    inc cx
    mov bx,word ptr [bp+0Ch]
    push cx
    call mf903
    pop cx
    mov di,bx
    dec si
    mov al,byte ptr [bp-26h]
lbl90Fb:
    stosb
    add di,si
    loop lbl90Fb
    jmp short lbl95Cf
lbl916f:
    push cx
    mov ax,word ptr [bp+0Ah]
    mov bx,word ptr [bp+0Ch]
    call mf91d
    mov di,bx
    pop cx
    inc cx
    mov al,byte ptr [bp-26h]
    rep stosb
    jmp short lbl95Cf
lbl92Df:
    mov al,byte ptr [bp-26h]
lbl930b:
    stosb
    or si,si
    jns short lbl93Cf
    add si,word ptr [bp-18h]
    loop lbl930b
    jmp short lbl95Cf
lbl93Cf:
    add si,word ptr [bp-1Ah]
    add di,bx
    loop lbl930b
    jmp short lbl95Cf
lbl945f:
    mov al,byte ptr [bp-26h]
lbl948b:
    stosb
    add di,bx
    or si,si
    jns short lbl957f
    add si,word ptr [bp-18h]
    dec di
    loop lbl948b
    jmp short lbl95Cf
lbl957f:
    add si,word ptr [bp-1Ah]
    loop lbl948b
lbl95Cf:
    mov word ptr [bp-2h],0h
    mov ax,word ptr [bp-2h]
    pop di
    pop si
    pop es
    pop ds
    mov sp,bp
    pop bp
    retf 8h
    add byte ptr [di-75h],dl
    in al,dx
    sub sp,0Ch
    push ds
    push es
    push si
    push di
    mov ax,38AFh
    mov ds,ax
    mov si,52A6h
    mov ax,word ptr [bp+8h]
    cmp ax,word ptr [bp+0Ch]
    jnl short lbl98Ff
    xchg ax,word ptr [bp+0Ch]
    mov word ptr [bp+8h],ax
lbl98Ff:
    mov ax,word ptr [bp+0Ah]
    cmp ax,word ptr [bp+0Eh]
    jnl short lbl99Df
    xchg ax,word ptr [bp+0Eh]
    mov word ptr [bp+0Ah],ax
lbl99Df:
    mov ax,word ptr [si+3Ch]
    mov word ptr [bp-4h],ax
    mov word ptr [si+3Ch],0h
    cmp word ptr [bp+6h],2h
    jnz short lbl9B1f
    jmp near ptr lblA78f
lbl9B1f:
    mov bx,word ptr [si+2Ah]
    dec bx
    mov ax,word ptr [bp+8h]
    sub ax,word ptr [bp+0Ch]
    dec ax
    sub ax,bx
    cmp ax, offset mi9be
    jl short lbl9D1f
    mov ax,word ptr [bp+0Ah]
    sub ax,word ptr [bp+0Eh]
    dec ax
    sub ax,bx
    cmp ax, offset mi9cc
    jnl short lblA00f
lbl9D1f:
    mov bx,word ptr [si+2Ah]
    shr bx,1
    sub word ptr [bp+0Eh],bx
    sub word ptr [bp+0Ch],bx
    add word ptr [bp+0Ah],bx
    add word ptr [bp+8h],bx
    mov ax,word ptr [si+28h]
    mov word ptr [bp-0Ah],ax
    mov bx,word ptr [si+0Ch]
    cmp word ptr [si+28h],0FFFFFFFFFFFFFFFFh
    jz short lbl9F4f
    jmp near ptr lblAB5f
lbl9F4f:
    cmp word ptr [si+16h],0h
    jnz short lbl9FDf
    jmp near ptr lblA87f
lbl9FDf:
    jmp near ptr lblAB5f
lblA00f:
    mov di,word ptr [si+2Ah]
    shr di,1
    mov ax,word ptr [bp+0Eh]
    sub ax,di
    push ax
    push word ptr [bp+8h]
    mov ax,word ptr [bp+0Ah]
    add ax,di
    push ax
    push word ptr [bp+8h]
    call mfa17
    mov ax,word ptr [bp+0Ah]
    add ax,di
    push ax
    push word ptr [bp+0Ch]
    mov ax,word ptr [bp+0Eh]
    sub ax,di
    push ax
    push word ptr [bp+0Ch]
    call mfa2e
    inc di
    push word ptr [bp+0Eh]
    mov ax,word ptr [bp+0Ch]
    add ax,di
    push ax
    push word ptr [bp+0Eh]
    mov ax,word ptr [bp+8h]
    sub ax,di
    push ax
    call mfa46
    push word ptr [bp+0Ah]
    mov ax,word ptr [bp+8h]
    sub ax,di
    push ax
    push word ptr [bp+0Ah]
    mov ax,word ptr [bp+0Ch]
    add ax,di
    push ax
    call mfa5d
    test word ptr [bp+6h],2h
    jnz short lblA6Cf
    jmp near ptr lblB7Af
lblA6Cf:
    add word ptr [bp+0Eh],di
    add word ptr [bp+0Ch],di
    sub word ptr [bp+0Ah],di
    sub word ptr [bp+8h],di
lblA78f:
    mov bx,word ptr [si+24h]
    cmp word ptr [si+22h],0h
    jnz short lblAE2f
    cmp word ptr [si+16h],0h
    jnz short lblAAAf
lblA87f:
    mov ax,word ptr [si+0Eh]
    mov word ptr [bp-8h],ax
    mov word ptr [si+0Eh],bx
    push word ptr [bp+0Eh]
    push word ptr [bp+0Ch]
    push word ptr [bp+0Ah]
    push word ptr [bp+8h]
    call mfa9c
    mov ax,word ptr [bp-8h]
    mov word ptr [si+0Eh],ax
    jmp near ptr lblB7Af
lblAAAf:
    mov ax,word ptr [si+28h]
    mov word ptr [bp-0Ah],ax
    mov word ptr [si+28h],0FFFFh
lblAB5f:
    mov ax,word ptr [si+0Ch]
    mov word ptr [bp-6h],ax
    mov word ptr [si+0Ch],bx
    mov ax,word ptr [si+2Ah]
    mov word ptr [bp-0Ch],ax
    mov word ptr [si+2Ah],1h
    mov di,word ptr [bp+0Ch]
lblACCb:
    push word ptr [bp+0Eh]
    push di
    push word ptr [bp+0Ah]
    push di
    call mfad4
    inc di
    cmp di,word ptr [bp+8h]
    jng short lblACCb
    jmp near ptr lblB68f
lblAE2f:
    mov ax,word ptr [si+0Ch]
    mov word ptr [bp-6h],ax
    mov word ptr [si+0Ch],bx
    mov bx,word ptr [si+28h]
    mov word ptr [bp-0Ah],bx
    mov bx,word ptr [si+2Ah]
    mov word ptr [bp-0Ch],bx
    mov word ptr [si+2Ah],1h
    mov ax,word ptr [si+22h]
    mov bx,8h
    mul bx
    mov di,5305h
    add di,ax
    mov cx,word ptr [bp+0Eh]
    and cx,7h
    mov bx,word ptr [bp+0Ch]
    and bx,7h
    mov dx,word ptr [bp+0Ch]
lblB18b:
    cmp word ptr [si+26h],1h
    jz short lblB42f
    mov word ptr [si+28h],0FFFFh
    mov ax,word ptr [si+0Eh]
    mov word ptr [si+0Ch],ax
    push bx
    push cx
    push dx
    push word ptr [bp+0Eh]
    push dx
    push word ptr [bp+0Ah]
    push dx
    call mfb34
    pop dx
    pop cx
    pop bx
    mov ax,word ptr [si+24h]
    mov word ptr [si+0Ch],ax
lblB42f:
    mov al,byte ptr [bx+di]
    mov ah,al
    rol ax,cl
    mov word ptr [si+28h],ax
    push bx
    push cx
    push dx
    push word ptr [bp+0Eh]
    push dx
    push word ptr [bp+0Ah]
    push dx
    call mfb56
    pop dx
    pop cx
    pop bx
    inc bx
    and bx,7h
    inc dx
    cmp dx,word ptr [bp+8h]
    jng short lblB18b
lblB68f:
    mov ax,word ptr [bp-6h]
    mov word ptr [si+0Ch],ax
    mov ax,word ptr [bp-0Ah]
    mov word ptr [si+28h],ax
    mov ax,word ptr [bp-0Ch]
    mov word ptr [si+2Ah],ax
lblB7Af:
    mov si,52A6h
    mov word ptr [si+10h],1h
    mov ax,word ptr [bp-4h]
    mov word ptr [si+3Ch],ax
    mov word ptr [bp-2h],0h
    mov ax,word ptr [bp-2h]
    pop di
    pop si
    pop es
    pop ds
    mov sp,bp
    pop bp
    retf 0Ah
    add byte ptr [di-75h],dl
    in al,dx
    sub sp,2h
    push ds
    push es
    push si
    push di
    mov ax,38AFh
    mov ds,ax
    mov si,52A6h
    mov ax,word ptr [bp+0Ah]
    cmp ax, offset mibb0
    jl short lblBDBf
    cmp ax, offset mibb5
    jg short lblBDBf
    mov word ptr [si+22h],ax
    mov ax,word ptr [bp+8h]
    mov word ptr [si+24h],ax
    mov ax,word ptr [bp+6h]
    mov bx,1h
    cmp ax, offset mibc9
    jz short lblBD1f
    mov bx,0h
lblBD1f:
    mov word ptr [si+26h],bx
    mov word ptr [bp-2h],0h
    jmp short lblBE0f
lblBDBf:
    mov word ptr [bp-2h],0F05Fh
lblBE0f:
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
    sub sp,2h
    push ds
    push es
    push si
    push di
    mov ax,38AFh
    mov ds,ax
    mov ax,38AFh
    mov es,ax
    mov di,5305h
    mov ax,word ptr [bp+0Ah]
    cmp ax, offset mic07
    jl short lblC11f
    cmp ax, offset mic0c
    jng short lblC18f
lblC11f:
    mov word ptr [bp-2h],0F05Fh
    jmp short lblC2Df
lblC18f:
    mov bx,8h
    mul bx
    add di,ax
    lds si, dword ptr [bp+6h]
    mov cx,4h
    cld
    rep movsw
    mov word ptr [bp-2h],0h
lblC2Df:
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
    sub sp,2h
    push ds
    push es
    push si
    push di
    mov ax,38AFh
    mov ds,ax
    mov si,52A6h
    mov ax,word ptr [bp+8h]
    mov word ptr [si+28h],ax
    mov ax,word ptr [bp+6h]
    or ax, offset mic55
    mov word ptr [si+2Ah],ax
    mov word ptr [bp-2h],0h
    mov ax,word ptr [bp-2h]
    pop di
    pop si
    pop es
    pop ds
    mov sp,bp
    pop bp
    retf 4h
    push bp
    mov bp,sp
    sub sp,2h
    push ds
    push es
    push si
    push di
    mov ax,38AFh
    mov ds,ax
    mov si,52A6h
    mov ax,word ptr [si+16h]
    mov word ptr [bp-2h],ax
    mov ax,word ptr [bp-2h]
    pop di
    pop si
    pop es
    pop ds
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
