_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi259:NEAR
    EXTRN mi28d:NEAR
    EXTRN mj24c:FAR
    EXTRN mn2bb:NEAR
    EXTRN mi79:NEAR
    EXTRN mn261:NEAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,0Eh
    push bx
    push di
    push si
    mov word ptr [bp-6h],1h
    push ds
    mov ds, ds:[449Eh]
    cld
    mov di,bx
    mov al,byte ptr [bx+1h]
    mov bl,byte ptr [bx]
    sub bh,bh
    sub ah,ah
    mov cl,3h
    shl bx,cl
    add bx,ax
    shl bx,1
    mov word ptr [bp-0Ah],bx
    pop es
    push es
    mov si,word ptr es:[449Ch]
    mov bx,word ptr [bx+si+9A8h]
    mov word ptr [bp-8h],bx
    sub di,word ptr [si+0Ch]
    inc di
    push ds
    pop es
    cmp word ptr [bx],di
    jnc short lbl53f
lbl42b:
    inc bx
    inc bx
    cmp word ptr [bx],di
    jc short lbl42b
    mov word ptr [bp-8h],bx
    xchg ax,bx
    mov bx,word ptr [bp-0Ah]
    mov word ptr [bx+si+9A8h],ax
lbl53f:
    mov bx,word ptr [bp-8h]
    mov di,word ptr [bx]
    mov dx,word ptr [bp-10h]
    dec dx
    cmp di,dx
    jc short lbl66f
    sub ax,ax
    jmp near ptr lbl22Bf
    db 81h
lbl66f:
    mov si,word ptr [bp-10h]
    mov cx,si
    mov word ptr [bp-4h],si
    mov bx,word ptr [bp-6h]
    dec bx
    mov al,byte ptr [bx+si]
    jmp short lblA2f
lbl76b:
    mov ax,word ptr [bp-6h]
    cmp ax, offset mi79
    jc short lbl81f
    jmp near ptr lbl22Bf
lbl81f:
    xor ax,ax
    jmp near ptr lbl22Bf
lbl86b:
    mov bx,word ptr [bp-6h]
    dec bx
    mov si,word ptr [bp-4h]
    mov al,byte ptr [bx+si]
    mov cx,si
    nop
lbl92b:
    mov si,cx
lbl94b:
    mov di,word ptr [bp-8h]
    inc di
    inc di
    mov word ptr [bp-8h],di
    mov di,word ptr [di]
    cmp di,dx
    jnc short lbl76b
lblA2f:
    cmp byte ptr [bx+di],al
    jnz short lbl94b
    cmpsb
    jnz short lbl92b
    mov cx,202h
    inc si
    inc di
    repe cmpsb
    jz short lblB3f
    inc cx
lblB3f:
    sub cx,205h
    not cx
    cmp word ptr [bp-6h],cx
    ja short lbl86b
    lea ax,word ptr [si-1h]
    sub ax,di
    mov bx,word ptr ss:[449Ch]
    mov word ptr [bx],ax
    mov word ptr [bp-6h],cx
    cmp cx,0Eh
    jc short lbl86b
    cmp cx,204h
    jnz short lblE4f
lblD8b:
    xchg ax,cx
    jmp near ptr lbl22Bf
    db 0F7h
lblDDb:
    mov ax,word ptr [bp-6h]
    jmp near ptr lbl22Bf
    nop
lblE4f:
    mov bx,word ptr [bp-8h]
    cmp word ptr [bx+2h],dx
    jnc short lblDDb
    cmp word ptr [bx+4h],dx
    jnc short lbl86b
    sub si,si
    mov word ptr ss:[44A6h],si
    mov word ptr ss:[44A4h],0FFFFh
    mov di,1h
    mov bx,word ptr [bp-4h]
    mov cx,word ptr [bp-6h]
lbl108b:
    mov al,byte ptr [bx+di]
    cmp byte ptr [bx+si],al
    jz short lbl119f
    shl si,1
    mov si,word ptr ss:[si+44A4h]
    test si,si
    jns short lbl124f
lbl119f:
    inc si
    inc di
    shl di,1
    mov word ptr ss:[di+44A4h],si
    shr di,1
lbl124f:
    cmp cx,di
    ja short lbl108b
    mov word ptr [bp-0Eh],si
    mov word ptr [bp-0Ch],di
    mov bx,word ptr [bp-8h]
    mov di,word ptr [bx]
    add di,cx
    inc di
lbl136b:
    dec di
    mov si,cx
    mov bx,si
    mov si,word ptr ss:[bx+si+44A4h]
    cmp si,0FFFFFFFFFFFFFFFFh
    jnz short lbl146f
    inc si
lbl146b:
lbl146f:
    add word ptr [bp-8h],2h
    mov bx,word ptr [bp-8h]
    mov ax,word ptr [bx]
    mov word ptr [bp-0Ah],ax
    cmp ax,dx
    jnc short lblDDb
    add ax,si
    cmp ax,di
    jc short lbl146b
    mov bx,word ptr [bp-6h]
    add bx,word ptr [bp-0Ah]
    mov ax,word ptr [bx-2h]
    mov bx,word ptr [bp-4h]
    add bx,word ptr [bp-6h]
    cmp word ptr [bx-2h],ax
    jz short lbl1A0f
    mov bx,word ptr [bp-6h]
    dec bx
    dec bx
    mov si,word ptr [bp-4h]
lbl178b:
    mov di,word ptr [bp-8h]
    inc di
    inc di
    mov word ptr [bp-8h],di
    mov di,word ptr [di]
    cmp di,dx
    jc short lbl18Af
    jmp near ptr lblDDb
    db 0EAh
lbl18Af:
    mov ax,word ptr [bx+di]
    cmp word ptr [bx+si],ax
    jnz short lbl178b
    mov al,byte ptr [di]
    cmp byte ptr [si],al
    jnz short lbl178b
    mov cx,2h
    mov word ptr [bp-0Ah],di
    add di,cx
    jmp short lbl1B0f
lbl1A0f:
    mov cx,si
    mov ax,word ptr [bp-0Ah]
    add ax,cx
    cmp ax,di
    jz short lbl1B0f
    sub cx,cx
    mov di,word ptr [bp-0Ah]
lbl1B0f:
    mov si,word ptr [bp-4h]
    add si,cx
    sub cx,205h
    not cx
    repe cmpsb
    jz short lbl1C0f
    inc cx
lbl1C0f:
    sub cx,205h
    not cx
    cmp cx,204h
    jna short lbl1CDf
    int 3
lbl1CDf:
    cmp word ptr [bp-6h],cx
    jna short lbl1D6f
    jmp near ptr lbl136b
    db 9Ah
lbl1D6f:
    lea ax,word ptr [si-1h]
    sub ax,di
    mov bx,word ptr ss:[449Ch]
    mov word ptr [bx],ax
    cmp word ptr [bp-6h],cx
    jc short lbl1EAf
    jmp near ptr lbl136b
lbl1EAf:
    cmp cx,204h
    jnz short lbl1F3f
    jmp near ptr lblD8b
lbl1F3f:
    mov word ptr [bp-6h],cx
lbl1F6b:
    mov si,word ptr [bp-4h]
    mov bx,word ptr [bp-0Ch]
    mov al,byte ptr [bx+si]
    mov bx,word ptr [bp-0Eh]
    cmp byte ptr [bx+si],al
    jz short lbl210f
    shl bx,1
    mov bx,word ptr ss:[bx+44A4h]
    test bx,bx
    jns short lbl21Ef
lbl210f:
    inc bx
    inc word ptr [bp-0Ch]
    mov si,word ptr [bp-0Ch]
    shl si,1
    mov word ptr ss:[si+44A4h],bx
lbl21Ef:
    mov word ptr [bp-0Eh],bx
    mov ax,word ptr [bp-0Ch]
    cmp cx,ax
    ja short lbl1F6b
    jmp near ptr lbl136b
lbl22Bf:
    pop ds
    pop si
    pop di
    mov sp,bp
    pop bp
    cmp word ptr ds:[449Ah],0h
    jz short lbl243f
    cli
    mov ss, ds:[4CAEh]
    mov sp,word ptr ds:[4CB0h]
    sti
    ret
lbl243f:
    mov ss, ds:[4CAEh]
    mov sp,word ptr ds:[4CB0h]
    ret
    jmp mj24c
    sub sp,2h
    push ax
    push di
    push si
    mov di,dx
    cmp ax, offset mi259
    jna short lbl26Cf
    mov ax,8h
    call mn261
    sub word ptr [bp-4h],8h
    mov cl,8h
    shr di,cl
lbl26Cf:
    les bx, dword ptr ds:[449Ch]
    mov cx,word ptr es:[bx+4h]
    mov word ptr [bp-2h],cx
    mov ax,di
    shl al,cl
    mov si,word ptr es:[bx+2h]
    or byte ptr es:[bx+si+1BAAh],al
    mov ax,cx
    add ax,word ptr [bp-4h]
    mov word ptr es:[bx+4h],ax
    cmp ax, offset mi28d
    jna short lbl2A9f
    inc si
    mov cl,8h
    sub cl,byte ptr [bp-2h]
    shr di,cl
    mov ax,di
    mov byte ptr es:[bx+si+1BAAh],al
    and word ptr es:[bx+4h],7h
    jmp short lbl2B1f
    db 0C7h
lbl2A9f:
    and word ptr es:[bx+4h],7h
    jnz short lbl2B1f
    inc si
lbl2B1f:
    mov word ptr es:[bx+2h],si
    cmp si,800h
    jc short lbl2BEf
    call mn2bb
lbl2BEf:
    pop si
    pop di
    mov sp,bp
    pop bp
    ret
_TEXT ENDS
    END
