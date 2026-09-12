_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf9:FAR
    EXTRN mf20:FAR
    EXTRN mf28:FAR
    EXTRN mf58:FAR
    EXTRN mf62:FAR
    EXTRN mf67:FAR
    EXTRN mf141:FAR
    EXTRN mf141:FAR
    EXTRN mf141:FAR
    EXTRN mf141:FAR
    EXTRN mf141:FAR
    EXTRN mf141:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,12h
    push di
    push si
    mov ax,190h
    cwd
    push dx
    push ax
    call mf9
    add sp,4h
    mov word ptr ds:[18EEh],ax
    mov word ptr ds:[18F0h],dx
    mov ax,dx
    or ax,word ptr ds:[18EEh]
    jnz short lbl3Af
    mov ax,95h
    mov cx,3181h
lbl2Bb:
    push cx
    push ax
    call mf20
    add sp,4h
    xor ax,ax
    jmp near ptr lbl182f
lbl3Af:
    mov ax,320h
    cwd
    push dx
    push ax
    call mf28
    add sp,4h
    mov word ptr ds:[18F2h],ax
    mov word ptr ds:[18F4h],dx
    mov ax,dx
    or ax,word ptr ds:[18F2h]
    jnz short lbl60f
    mov ax,0D4h
    mov cx,3181h
    jmp short lbl2Bb
    nop
lbl60f:
    xor ax,ax
    mov word ptr [bp-0Ch],ax
    mov word ptr [bp-0Eh],ax
lbl68b:
    les bx, dword ptr ds:[18EEh]
    mov si,word ptr [bp-0Eh]
    mov word ptr es:[bx+si],0FFFFh
    les bx, dword ptr ds:[18F2h]
    mov si,word ptr [bp-0Ch]
    mov word ptr es:[bx+si+2h],ax
    mov word ptr es:[bx+si],ax
    add word ptr [bp-0Ch],4h
    add word ptr [bp-0Eh],2h
    cmp word ptr [bp-0Eh],190h
    jl short lbl68b
    mov word ptr ds:[18F6h],ax
    mov word ptr [bp-2h],ax
lbl97b:
    push word ptr [bp-2h]
    mov ax,4h
    push ax
    call mf58
    add sp,4h
    push dx
    push ax
    call mf62
    add sp,4h
    or ax,ax
    jz short lblC3f
    push word ptr [bp-2h]
    call mf67
    add sp,2h
    or ax,ax
    jz short lblCDf
lblC3f:
    inc word ptr [bp-2h]
    cmp word ptr [bp-2h],0C7h
    jl short lbl97b
lblCDf:
    mov word ptr [bp-2h],0h
    mov ax,word ptr ds:[18F6h]
    cwd
    sub ax,dx
    sar ax,1
    or ax,ax
    jg short lblE1f
    jmp near ptr lbl17Ff
lblE1f:
    xor ax,ax
    mov word ptr [bp-10h],ax
    mov word ptr [bp-12h],ax
lblE9b:
    mov ax,word ptr ds:[18F6h]
    sub ax,word ptr [bp-2h]
    dec ax
    mov word ptr [bp-4h],ax
    les bx, dword ptr ds:[18EEh]
    mov si,word ptr [bp-12h]
    mov cx,word ptr es:[bx+si]
    mov word ptr [bp-6h],cx
    les bx, dword ptr ds:[18F2h]
    mov di,word ptr [bp-10h]
    mov cx,word ptr es:[bx+di]
    mov dx,word ptr es:[bx+di+2h]
    mov word ptr [bp-0Ah],cx
    mov word ptr [bp-8h],dx
    mov bx,ax
    add bx,ax
    les di, dword ptr ds:[18EEh]
    mov ax,word ptr es:[bx+di]
    add di,si
    mov word ptr es:[di],ax
    mov bx,word ptr [bp-4h]
    add bx,bx
    add bx,bx
    les si, dword ptr ds:[18F2h]
    mov ax,word ptr es:[bx+si]
    mov dx,word ptr es:[bx+si+2h]
    mov cx,bx
    mov bx,word ptr [bp-10h]
    mov word ptr es:[bx+si],ax
    mov word ptr es:[bx+si+2h],dx
    mov bx,word ptr [bp-4h]
    add bx,bx
    les si, dword ptr ds:[18EEh]
    mov ax,word ptr [bp-6h]
    mov word ptr es:[bx+si],ax
    mov bx,cx
    les si, dword ptr ds:[18F2h]
    mov ax,word ptr [bp-0Ah]
    mov dx,word ptr [bp-8h]
    mov word ptr es:[bx+si],ax
    mov word ptr es:[bx+si+2h],dx
    add word ptr [bp-10h],4h
    add word ptr [bp-12h],2h
    mov ax,word ptr ds:[18F6h]
    cwd
    sub ax,dx
    sar ax,1
    inc word ptr [bp-2h]
    cmp ax,word ptr [bp-2h]
    jng short lbl17Ff
    jmp near ptr lblE9b
lbl17Ff:
    mov ax,1h
lbl182f:
    pop si
    pop di
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
