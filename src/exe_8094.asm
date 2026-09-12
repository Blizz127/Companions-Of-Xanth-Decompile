_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi11:NEAR
    EXTRN mi35:NEAR
    EXTRN mf86:FAR
    EXTRN mf120:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,0Ch
    push di
    push si
    mov al,byte ptr ds:[567Ch]
    mov byte ptr [bp-4h],al
    mov word ptr [bp-6h],0h
    les bx, dword ptr [bp+0Ah]
    mov al,byte ptr es:[bx]
    cbw
    cmp ax, offset mi11
    jz short lbl76f
    ja short lbl29f
    sub al,61h
    jz short lbl80f
    sub al,11h
    jz short lbl30f
lbl29b:
lbl29f:
    xor ax,ax
    cwd
    jmp near ptr lbl135f
    nop
lbl30f:
    xor si,si
    mov byte ptr [bp-2h],1h
lbl36b:
    mov word ptr [bp-8h],1h
lbl3Bb:
    inc word ptr [bp+0Ah]
    les bx, dword ptr [bp+0Ah]
    cmp byte ptr es:[bx],0h
    jnz short lbl4Af
    jmp near ptr lblD4f
lbl4Af:
    cmp word ptr [bp-8h],0h
    jnz short lbl53f
    jmp near ptr lblD4f
lbl53f:
    mov al,byte ptr es:[bx]
    cbw
    cmp ax, offset mi35
    jz short lbl98f
    ja short lbl6Ef
    sub al,2Bh
    jz short lbl86f
    sub al,37h
    jz short lblA4f
    dec al
    jz short lblB0f
    sub al,0Bh
    jz short lblC2f
lbl6Eb:
lbl6Ef:
    mov word ptr [bp-8h],0h
    jmp short lbl3Bb
    nop
lbl76f:
    mov si,301h
lbl79b:
    mov byte ptr [bp-2h],2h
    jmp short lbl36b
    nop
lbl80f:
    mov si,109h
    jmp short lbl79b
    nop
lbl86f:
    test si,2h
    jnz short lbl6Eb
    or si,2h
    and si,0FFFFFFFFFFFFFFFEh
    mov byte ptr [bp-2h],80h
    jmp short lbl3Bb
lbl98f:
    test si,0C000h
    jnz short lbl6Eb
    or si,4000h
    jmp short lbl3Bb
lblA4f:
    test si,0C000h
    jnz short lbl6Eb
    or si,8000h
    jmp short lbl3Bb
lblB0f:
    cmp word ptr [bp-6h],0h
    jnz short lbl6Eb
    mov word ptr [bp-6h],1h
    or byte ptr [bp-4h],40h
    jmp near ptr lbl3Bb
lblC2f:
    cmp word ptr [bp-6h],0h
    jnz short lbl6Eb
    mov word ptr [bp-6h],1h
    and byte ptr [bp-4h],0BFh
    jmp near ptr lbl3Bb
lblD4f:
    mov ax,1A4h
    push ax
    push word ptr [bp+0Eh]
    push si
    push word ptr [bp+8h]
    push word ptr [bp+6h]
    call mf86
    add sp,0Ah
    mov word ptr [bp-0Ah],ax
    or ax,ax
    jnl short lblF4f
    jmp near ptr lbl29b
lblF4f:
    inc word ptr ds:[541Eh]
    mov ax,word ptr [bp+10h]
    mov di,ax
    mov cx,ax
    sub cx,5420h
    add cx,5510h
    mov bx,ax
    mov al,byte ptr [bp-2h]
    mov byte ptr [bx+0Ah],al
    sub ax,ax
    mov word ptr [di+2h],ax
    mov word ptr [di],ax
    mov word ptr [di+8h],ax
    mov word ptr [di+6h],ax
    mov al,byte ptr [bp-0Ah]
    mov byte ptr [di+0Bh],al
    mov bx,cx
    mov al,byte ptr [bp-4h]
    mov byte ptr [bx],al
    xor ax,ax
    mov word ptr [di+4h],ax
    mov word ptr [bx+4h],ax
    mov ax,di
    mov dx,ds
lbl135f:
    pop si
    pop di
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
