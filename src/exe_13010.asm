_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mnf2:NEAR
    EXTRN mjn113:NEAR
    EXTRN mjn47:NEAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,4h
    xor bh,bh
    mov byte ptr [bp-2h],bh
    mov ax,word ptr [bp+0Ah]
    mov cx,ax
    mov byte ptr [bp-4h],0h
    test ax,8000h
    jnz short lbl29f
    test ax,4000h
    jnz short lbl25f
    test byte ptr ds:[567Bh],80h
    jnz short lbl29f
lbl25f:
    mov byte ptr [bp-4h],80h
lbl29f:
    push ds
    lds dx, dword ptr [bp+6h]
    and al,3h
    or al,bh
    mov ah,3Dh
    int 21h
    pop ds
    jnc short lbl4Af
    cmp ax,2h
    jnz short lbl46f
    test cx,100h
    jz short lbl46f
    jmp near ptr lblEBf
lbl46b:
lbl46f:
    stc
    jmp mjn47
lbl4Af:
    xchg ax,bx
    mov ax,cx
    and ax,500h
    cmp ax,500h
    jnz short lbl5Ef
    mov ah,3Eh
    int 21h
    mov ax,1100h
    jmp short lbl46b
lbl5Ef:
    mov byte ptr [bp-3h],1h
    mov ax,4400h
    int 21h
    test dl,80h
    jz short lbl70f
    or byte ptr [bp-4h],40h
lbl70f:
    test byte ptr [bp-4h],40h
    jz short lbl79f
    jmp near ptr lbl158f
lbl79f:
    mov ax,word ptr [bp+0Ah]
    test ax,200h
    jz short lbl9Ff
    test ax,3h
    jz short lbl8Ff
    xor cx,cx
    mov ah,40h
    int 21h
    jmp near ptr lbl158f
lbl8Ff:
    mov ah,3Eh
    int 21h
    push ds
    lds dx, dword ptr [bp+6h]
    mov ax,4300h
    int 21h
    pop ds
    jmp short lbl108f
lbl9Ff:
    test byte ptr [bp-4h],80h
    jnz short lblA8f
    jmp near ptr lbl158f
lblA8f:
    test ax,2h
    jnz short lblB0f
    jmp near ptr lbl158f
lblB0f:
    mov cx,0FFFFh
    mov dx,cx
    mov ax,4202h
    int 21h
    neg cx
    push ds
    push ss
    pop ds
    lea dx,word ptr [bp-1h]
    mov ah,3Fh
    int 21h
    pop ds
    or ax,ax
    jz short lblE0f
    cmp byte ptr [bp-1h],1Ah
    jnz short lblE0f
    neg cx
    mov dx,cx
    mov ax,4202h
    int 21h
    xor cx,cx
    mov ah,40h
    int 21h
lblE0f:
    xor cx,cx
    mov dx,cx
    mov ax,4200h
    int 21h
    jmp short lbl158f
lblEBf:
    mov byte ptr [bp-3h],0h
    mov cx,word ptr [bp+0Ch]
    call mnf2
    mov word ptr [bp+0Ch],cx
    test byte ptr [bp-2h],0FFh
    jnz short lbl105f
    test word ptr [bp+0Ah],2h
    jnz short lbl108f
lbl105f:
    and cl,0FEh
lbl108f:
    push ds
    lds dx, dword ptr [bp+6h]
    mov ah,3Ch
    int 21h
    pop ds
    jnc short lbl116f
lbl113b:
    jmp mjn113
lbl116f:
    xchg ax,bx
    test byte ptr [bp-2h],0FFh
    jnz short lbl124f
    test word ptr [bp+0Ah],2h
    jnz short lbl158f
lbl124f:
    mov ah,3Eh
    int 21h
    mov al,byte ptr [bp+0Ah]
    and al,3h
    or al,byte ptr [bp-2h]
    push ds
    lds dx, dword ptr [bp+6h]
    mov ah,3Dh
    int 21h
    pop ds
    jc short lbl113b
    xchg ax,bx
    test byte ptr [bp-3h],1h
    jnz short lbl158f
    test word ptr [bp+0Ch],1h
    jz short lbl158f
    or cl,1h
    push ds
    lds dx, dword ptr [bp+6h]
    mov ax,4301h
    int 21h
    pop ds
    jc short lbl113b
lbl158f:
    test byte ptr [bp-4h],40h
    jnz short lbl19Df
    push ds
    lds dx, dword ptr [bp+6h]
    mov ax,4300h
    int 21h
    pop ds
    mov ax,cx
    xor cl,cl
    and ax,1h
    jz short lbl173f
    mov cl,10h
lbl173f:
    test word ptr [bp+0Ah],8h
    jz short lbl17Df
    or cl,20h
lbl17Df:
    cmp bx,word ptr ds:[53CAh]
    jc short lbl18Df
    mov ah,3Eh
    int 21h
    mov ax,1800h
    jmp near ptr lbl46b
lbl18Df:
    or cl,byte ptr [bp-4h]
    or cl,1h
    mov byte ptr [bx+53CCh],cl
    mov ax,bx
    mov sp,bp
    pop bp
    retf
lbl19Df:
lblE599f:
_TEXT ENDS
    END
