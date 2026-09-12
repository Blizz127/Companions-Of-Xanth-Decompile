_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf3:FAR
    EXTRN md19:NEAR
    EXTRN mf37:FAR
    EXTRN mi41:NEAR
    EXTRN mf49:FAR
    EXTRN mf59:FAR
    EXTRN mf59:FAR
    EXTRN mf59:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,0Eh
    call mf3
    cmp word ptr ds:[84Ch],0h
    jng short lbl49f
    mov word ptr [bp-8h],6Ch
    mov ax,word ptr ds:[84Ch]
    mov word ptr [bp-0Ah],ax
lbl1Db:
    mov bx,word ptr [bp-8h]
    mov es, ds:[5A74h]
    mov al,byte ptr es:[bx]
    sub ah,ah
    or ax,ax
    jng short lbl40f
    mov es, ds:[5A76h]
    mov bx,ax
    add bx,ax
    add bx,ax
    mov al,byte ptr es:[bx+md19]
    add word ptr ds:[18A0h],ax
lbl40f:
    add word ptr [bp-8h],6h
    dec word ptr [bp-0Ah]
    jnz short lbl1Db
lbl49f:
    cmp word ptr ds:[376h],0h
    jng short lbl72f
    mov word ptr [bp-0Ch],11Ah
    mov ax,word ptr ds:[376h]
    mov word ptr [bp-0Eh],ax
    mov es, ds:[5A78h]
lbl5Fb:
    mov bx,word ptr [bp-0Ch]
    mov ax,word ptr es:[bx]
    add word ptr ds:[18A0h],ax
    add word ptr [bp-0Ch],6h
    dec word ptr [bp-0Eh]
    jnz short lbl5Fb
lbl72f:
    add word ptr ds:[18A0h],4Ah
    call mf37
    mov word ptr [bp-6h],ax
    mov cl,4h
    mov ax,word ptr ds:[18A0h]
    add ax, offset mi41
    shr ax,cl
    cmp ax,word ptr [bp-6h]
    jnc short lblB1f
    mov ax,word ptr ds:[18A0h]
    sub dx,dx
    push dx
    push ax
    call mf49
    add sp,4h
    mov word ptr ds:[189Ch],ax
    mov word ptr ds:[189Eh],dx
    mov ax,dx
    or ax,word ptr ds:[189Ch]
    jz short lblB1f
    mov byte ptr ds:[18A2h],1h
lblB1f:
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
