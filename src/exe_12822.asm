_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mn1ae:NEAR
    EXTRN mjn1cf:NEAR
    EXTRN mjn9e:NEAR
    EXTRN mjn103:NEAR
    EXTRN mjn1d:NEAR
mnem_unit:
    push bp
    mov bp,sp
    mov bx,word ptr [bp+6h]
    cmp bx,word ptr ds:[53CAh]
    jc short lbl12f
    mov ax,900h
    stc
    jmp short lbl1Df
lbl12f:
    mov ah,3Eh
    int 21h
    jc short lbl1Df
    mov byte ptr [bx+53CCh],0h
lbl1Df:
    jmp mjn1d
    push bp
    mov bp,sp
    sub sp,4h
    mov bx,word ptr [bp+6h]
    cmp bx,word ptr ds:[53CAh]
    jc short lbl34f
    mov ax,900h
    jmp short lbl65f
lbl34f:
    cmp word ptr ds:[567Eh],0h
    jz short lbl8Af
    test word ptr [bp+0Ah],8000h
    jz short lbl8Af
    cmp word ptr [bp+0Ch],0h
    jz short lbl62f
    xor cx,cx
    mov dx,cx
    mov ax,4201h
    int 21h
    jc short lbl9Ef
    test word ptr [bp+0Ch],2h
    jnz short lbl68f
    add ax,word ptr [bp+8h]
    adc dx,word ptr [bp+0Ah]
    jns short lbl8Af
lbl62b:
lbl62f:
    mov ax,1600h
lbl65f:
    stc
    jmp short lbl9Ef
lbl68f:
    mov word ptr [bp-2h],dx
    mov word ptr [bp-4h],ax
    mov dx,cx
    mov ax,4202h
    int 21h
    add ax,word ptr [bp+8h]
    adc dx,word ptr [bp+0Ah]
    jns short lbl8Af
    mov cx,word ptr [bp-2h]
    mov dx,word ptr [bp-4h]
    mov ax,4200h
    int 21h
    jmp short lbl62b
lbl8Af:
    mov dx,word ptr [bp+8h]
    mov cx,word ptr [bp+0Ah]
    mov al,byte ptr [bp+0Ch]
    mov ah,42h
    int 21h
    jc short lbl9Ef
    and byte ptr [bx+53CCh],0FDh
lbl9Ef:
    jmp mjn9e
    add byte ptr [di-75h],dl
    in al,dx
    sub sp,4h
    xor bh,bh
    cmp byte ptr ds:[53C3h],3h
    jc short lblB4f
    mov bh,byte ptr [bp+0Ch]
lblB4f:
    mov ax,word ptr [bp+0Eh]
    mov word ptr [bp+0Ch],ax
    jmp short lblC4f
    push bp
    mov bp,sp
    sub sp,4h
    xor bh,bh
lblC4f:
    mov byte ptr [bp-2h],bh
    mov ax,word ptr [bp+0Ah]
    mov cx,ax
    mov byte ptr [bp-4h],0h
    test ax,8000h
    jnz short lblE5f
    test ax,4000h
    jnz short lblE1f
    test byte ptr ds:[567Bh],80h
    jnz short lblE5f
lblE1f:
    mov byte ptr [bp-4h],80h
lblE5f:
    push ds
    lds dx, dword ptr [bp+6h]
    and al,3h
    or al,bh
    mov ah,3Dh
    int 21h
    pop ds
    jnc short lbl106f
    cmp ax,2h
    jnz short lbl102f
    test cx,100h
    jz short lbl102f
    jmp near ptr lbl1A7f
lbl102b:
lbl102f:
    stc
    jmp mjn103
lbl106f:
    xchg ax,bx
    mov ax,cx
    and ax,500h
    cmp ax,500h
    jnz short lbl11Af
    mov ah,3Eh
    int 21h
    mov ax,1100h
    jmp short lbl102b
lbl11Af:
    mov byte ptr [bp-3h],1h
    mov ax,4400h
    int 21h
    test dl,80h
    jz short lbl12Cf
    or byte ptr [bp-4h],40h
lbl12Cf:
    test byte ptr [bp-4h],40h
    jz short lbl135f
    jmp near ptr lbl214f
lbl135f:
    mov ax,word ptr [bp+0Ah]
    test ax,200h
    jz short lbl15Bf
    test ax,3h
    jz short lbl14Bf
    xor cx,cx
    mov ah,40h
    int 21h
    jmp near ptr lbl214f
lbl14Bf:
    mov ah,3Eh
    int 21h
    push ds
    lds dx, dword ptr [bp+6h]
    mov ax,4300h
    int 21h
    pop ds
    jmp short lbl1C4f
lbl15Bf:
    test byte ptr [bp-4h],80h
    jnz short lbl164f
    jmp near ptr lbl214f
lbl164f:
    test ax,2h
    jnz short lbl16Cf
    jmp near ptr lbl214f
lbl16Cf:
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
    jz short lbl19Cf
    cmp byte ptr [bp-1h],1Ah
    jnz short lbl19Cf
    neg cx
    mov dx,cx
    mov ax,4202h
    int 21h
    xor cx,cx
    mov ah,40h
    int 21h
lbl19Cf:
    xor cx,cx
    mov dx,cx
    mov ax,4200h
    int 21h
    jmp short lbl214f
lbl1A7f:
    mov byte ptr [bp-3h],0h
    mov cx,word ptr [bp+0Ch]
    call mn1ae
    mov word ptr [bp+0Ch],cx
    test byte ptr [bp-2h],0FFh
    jnz short lbl1C1f
    test word ptr [bp+0Ah],2h
    jnz short lbl1C4f
lbl1C1f:
    and cl,0FEh
lbl1C4f:
    push ds
    lds dx, dword ptr [bp+6h]
    mov ah,3Ch
    int 21h
    pop ds
    jnc short lbl1D2f
lbl1CFb:
    jmp mjn1cf
lbl1D2f:
    xchg ax,bx
    test byte ptr [bp-2h],0FFh
    jnz short lbl1E0f
    test word ptr [bp+0Ah],2h
    jnz short lbl214f
lbl1E0f:
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
    jc short lbl1CFb
    xchg ax,bx
    test byte ptr [bp-3h],1h
    jnz short lbl214f
    test word ptr [bp+0Ch],1h
    jz short lbl214f
    or cl,1h
    push ds
    lds dx, dword ptr [bp+6h]
    mov ax,4301h
    int 21h
    pop ds
    jc short lbl1CFb
lbl214f:
    test byte ptr [bp-4h],40h
    jnz short lbl259f
    push ds
    lds dx, dword ptr [bp+6h]
    mov ax,4300h
    int 21h
    pop ds
    mov ax,cx
    xor cl,cl
    and ax,1h
    jz short lbl22Ff
    mov cl,10h
lbl22Ff:
    test word ptr [bp+0Ah],8h
    jz short lbl239f
    or cl,20h
lbl239f:
    cmp bx,word ptr ds:[53CAh]
    jc short lbl249f
    mov ah,3Eh
    int 21h
    mov ax,1800h
    jmp near ptr lbl102b
lbl249f:
    or cl,byte ptr [bp-4h]
    or cl,1h
    mov byte ptr [bx+53CCh],cl
    mov ax,bx
    mov sp,bp
    pop bp
    retf
lbl259f:
lblE640f:
lblE655f:
_TEXT ENDS
    END
