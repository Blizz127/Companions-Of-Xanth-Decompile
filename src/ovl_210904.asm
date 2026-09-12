_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
mnem_unit:
    push bp
    mov bp,sp
    sub sp,14h
    push di
    push si
    mov ax,word ptr [bp+6h]
    mov dx,word ptr [bp+8h]
    push ds
    lea di,word ptr [bp-12h]
    mov si,ax
    push ss
    pop es
    mov ds,dx
    movsw
    movsw
    movsw
    movsw
    movsb
    pop ds
    xor ax,ax
    mov cx,2h
    lea di,word ptr [bp-12h]
    rep stosw
    stosb
    mov word ptr [bp-2h],ax
lbl2Cb:
    mov word ptr [bp-6h],1h
    mov word ptr [bp-8h],10h
    mov word ptr [bp-14h],5h
lbl3Bb:
    les bx, dword ptr [bp+6h]
    mov si,word ptr [bp-2h]
    mov al,byte ptr es:[bx+si]
    sub ah,ah
    test word ptr [bp-6h],ax
    jz short lbl51f
    mov al,byte ptr [bp-8h]
    or byte ptr [bp+si-12h],al
lbl51f:
    shr word ptr [bp-8h],1
    shl word ptr [bp-6h],1
    dec word ptr [bp-14h]
    jnz short lbl3Bb
    inc word ptr [bp-2h]
    cmp word ptr [bp-2h],5h
    jc short lbl2Cb
    lea si,word ptr [bp-12h]
    les di, dword ptr [bp+6h]
    movsw
    movsw
    movsw
    movsw
    movsb
    pop si
    pop di
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
