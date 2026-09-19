_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
mnem_unit:
    mov cx,word ptr [bp+0Eh]
    mov ax,word ptr [bp+6h]
    mov dx,word ptr [bp+8h]
    push ds
    lds di, dword ptr [bp+0Ah]
    push di
    push ds
    pop es
    cld
    xchg ax,bx
    or al,al
    jz short lbl29f
    cmp cx,0Ah
    jnz short lbl29f
    or dx,dx
    jns short lbl29f
    mov al,2Dh
    stosb
    neg bx
    adc dx,0h
    neg dx
lbl29f:
    mov si,di
lbl2Bb:
    xchg ax,dx
    xor dx,dx
    or ax,ax
    jz short lbl34f
    div cx
lbl34f:
    xchg ax,bx
    div cx
    xchg ax,dx
    db 87h, 0D3h ; override
    add al,30h
    cmp al,39h
    jna short lbl42f
    add al,27h
lbl42f:
    stosb
    mov ax,dx
    or ax,bx
    jnz short lbl2Bb
    mov byte ptr [di],al
lbl4Bb:
    dec di
    lodsb
    xchg al,byte ptr [di]
    mov byte ptr [si-1h],al
    lea ax,word ptr [si+1h]
    cmp ax,di
    jc short lbl4Bb
    mov dx,ds
    pop ax
    pop ds
    pop di
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
