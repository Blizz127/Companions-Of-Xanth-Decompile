_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf11:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,4h
    push di
    push si
    mov byte ptr ds:[638Ch],0h
    push word ptr ds:[4D38h]
    call mf11
    add sp,2h
    mov word ptr [bp-2h],ax
    or ax,ax
    jnl short lbl23f
    jmp near ptr lblB2f
lbl23f:
    mov bx,ax
    add bx,ax
    cmp word ptr [bx+6378h],1h
    jnl short lbl31f
    jmp near ptr lblB2f
lbl31f:
    mov bx,ax
    add bx,ax
    add bx,bx
    les si, dword ptr [bx+6364h]
    mov bx,ax
    add bx,ax
    mov bx,word ptr [bx+636Ch]
    add bx,bx
    add bx,bx
    mov di,word ptr es:[bx+si]
    mov cx,word ptr es:[bx+si+2h]
    mov si,638Ch
    mov es,cx
    push ds
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
    mov ax,638Ch
    mov di,ax
    mov ax,ds
    mov es,ax
    mov cx,0FFFFh
    xor ax,ax
    repne scasb
    not cx
    dec cx
    mov word ptr [bp-4h],cx
lbl84b:
    dec word ptr [bp-4h]
    mov bx,word ptr [bp-4h]
    cmp byte ptr [bx+638Ch],20h
    jz short lbl84b
    mov byte ptr [bx+638Dh],0h
    mov bx,word ptr [bp-2h]
    test byte ptr [bx+6376h],1h
    jz short lblB2f
    mov al,byte ptr ds:[638Ch]
    cbw
    mov bx,ax
    test byte ptr [bx+56A5h],2h
    jz short lblB2f
    sub byte ptr ds:[638Ch],20h
lblB2f:
    mov ax,638Ch
    mov dx,ds
    pop si
    pop di
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
