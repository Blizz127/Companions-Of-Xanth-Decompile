_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
mnem_unit:
    push bp
    mov bp,sp
    sub sp,12h
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
    mov word ptr [bp-6h],10h
    mov word ptr [bp-2h],ax
lbl31b:
    mov word ptr [bp-8h],1h
    mov word ptr [bp-4h],0h
lbl3Bb:
    les bx, dword ptr [bp+6h]
    mov si,word ptr [bp-4h]
    mov al,byte ptr es:[bx+si]
    sub ah,ah
    test word ptr [bp-6h],ax
    jz short lbl54f
    mov al,byte ptr [bp-8h]
    mov si,word ptr [bp-2h]
    or byte ptr [bp+si-12h],al
lbl54f:
    shl word ptr [bp-8h],1
    inc word ptr [bp-4h]
    cmp word ptr [bp-4h],5h
    jc short lbl3Bb
    shr word ptr [bp-6h],1
    inc word ptr [bp-2h]
    cmp word ptr [bp-2h],5h
    jc short lbl31b
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
