_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mjn88:NEAR
    EXTRN mn106:NEAR
    EXTRN mn15c:NEAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,2h
    mov bx,word ptr [bp+6h]
    cmp bx,word ptr ds:[53CAh]
    jc short lbl15f
    stc
    mov ax,900h
    jmp short lbl88f
lbl15f:
    xor ax,ax
    mov cx,word ptr [bp+0Ch]
    jcxz lbl88f
    test byte ptr [bx+53CCh],2h
    jnz short lbl88f
    cmp word ptr ds:[59FAh],0D6D6h
    jnz short lbl2Ff
    call word ptr ds:[59FCh]
lbl2Ff:
    mov cx,word ptr [bp+0Ch]
    push ds
    lds dx, dword ptr [bp+8h]
    mov ah,3Fh
    int 21h
    pop ds
    jnc short lbl41f
    mov ah,9h
    jmp short lbl88f
lbl41f:
    test byte ptr [bx+53CCh],80h
    jz short lbl88f
    and byte ptr [bx+53CCh],0FBh
    push si
    push di
    push ds
    pop es
    mov ds, [bp+0Ah]
    cld
    mov si,dx
    mov di,dx
    mov cx,ax
    jcxz lbl84f
    mov ah,0Dh
    cmp byte ptr [si],0Ah
    jnz short lbl6Af
    or byte ptr es:[bx+53CCh],4h
lbl6Ab:
lbl6Af:
    lodsb
    cmp al,ah
    jz short lbl8Bf
    cmp al,1Ah
    jnz short lbl7Bf
    or byte ptr es:[bx+53CCh],2h
    jmp short lbl80f
lbl7Bb:
lbl7Bf:
    mov byte ptr [di],al
    inc di
lbl7Eb:
    loop lbl6Ab
lbl80f:
    mov ax,di
    sub ax,dx
lbl84f:
    push es
    pop ds
lbl86b:
    pop di
    pop si
lbl88f:
    jmp mjn88
lbl8Bf:
    cmp cx,1h
    jz short lbl97f
    cmp byte ptr [si],0Ah
    jz short lbl7Eb
    jmp short lbl7Bb
lbl97f:
    push es
    pop ds
    test byte ptr [bx+53CCh],40h
    jz short lblBCf
    mov ax,4400h
    int 21h
    test dx,20h
    jnz short lblB8f
    push ds
    push ss
    pop ds
    lea dx,word ptr [bp-1h]
    mov ah,3Fh
    int 21h
    pop ds
    jc short lbl86b
lblB8b:
lblB8f:
    mov al,0Ah
    jmp short lblECf
lblBCf:
    push ds
    push ss
    pop ds
    mov byte ptr [bp-1h],0h
    lea dx,word ptr [bp-1h]
    mov ah,3Fh
    int 21h
    pop ds
    jc short lbl86b
    or ax,ax
    jz short lblEAf
    cmp word ptr [bp+0Ch],1h
    jz short lblF6f
lblD7b:
    mov cx,0FFFFh
    mov dx,cx
    mov ax,4201h
    int 21h
    mov cx,1h
    cmp byte ptr [bp-1h],0Ah
    jz short lblF1f
lblEAf:
    mov al,0Dh
lblECf:
    lds dx, dword ptr [bp+8h]
    jmp short lbl7Bb
lblF1f:
    lds dx, dword ptr [bp+8h]
    jmp short lbl7Eb
lblF6f:
    cmp byte ptr [bp-1h],0Ah
    jnz short lblD7b
    jmp short lblB8b
    push cx
    push di
    test byte ptr [bx+2h],1h
    jz short lbl16Cf
    call mn106
    mov di,si
    mov ax,word ptr [si]
    test al,1h
    jz short lbl114f
    sub cx,ax
    dec cx
lbl114f:
    inc cx
    inc cx
    mov si,word ptr [bx+4h]
    or si,si
    jz short lbl16Cf
    add cx,si
    jnc short lbl12Af
    xor ax,ax
    mov dx,0FFF0h
    jcxz lbl15Bf
    jmp short lbl16Cf
lbl12Af:
    mov ax,38AFh
    mov es,ax
    mov ax,word ptr es:[5680h]
    cmp ax,2000h
    jz short lbl14Ef
    mov dx,8000h
lbl13Bb:
    cmp dx,ax
    jc short lbl145f
    shr dx,1
    jnz short lbl13Bb
    jmp short lbl167f
lbl145f:
    cmp dx,8h
    jc short lbl167f
    shl dx,1
    mov ax,dx
lbl14Eb:
lbl14Ef:
    dec ax
    mov dx,ax
    add ax,cx
    jnc short lbl157f
    xor ax,ax
lbl157f:
    not dx
    and ax,dx
lbl15Bf:
    push dx
    call mn15c
    pop dx
    jnc short lbl16Ff
    cmp dx,0FFFFFFFFFFFFFFF0h
    jz short lbl16Cf
lbl167f:
    mov ax,10h
    jmp short lbl14Eb
lbl16Cf:
    stc
    jmp short lbl18Af
lbl16Ff:
    mov dx,ax
    sub dx,word ptr [bx+4h]
    mov word ptr [bx+4h],ax
    mov word ptr [bx+8h],di
    mov si,word ptr [bx+0Ah]
    dec dx
    mov word ptr [si],dx
    inc dx
    add si,dx
    mov word ptr [si],0FFFEh
    mov word ptr [bx+0Ah],si
lbl18Af:
    pop di
    pop cx
    ret
    mov dx,ax
    test byte ptr [bx+2h],4h
    jz short lbl1A4f
    dec dx
    mov si,word ptr [bx+4h]
    dec si
    cmp dx,si
    jna short lbl1A3f
    cmp word ptr [bx-2h],dx
    jnc short lbl1D9f
lbl1A3f:
    inc dx
lbl1A4f:
    push bx
    push cx
    mov si,ds
    mov es,si
    mov cl,4h
    shr ax,cl
    jnz short lbl1B3f
    mov ax,1000h
lbl1B3f:
    test byte ptr [bx+2h],4h
    jz short lbl1C3f
    add ax,si
    mov bx,word ptr ds:[53C0h]
    sub ax,bx
    mov es,bx
lbl1C3f:
    mov bx,ax
    mov ah,4Ah
    int 21h
    pop cx
    pop bx
    jc short lbl1DDf
    mov ax,dx
    test byte ptr [bx+2h],4h
    jz short lbl1D9f
    dec dx
    mov word ptr [bx-2h],dx
lbl1D9f:
    clc
    jmp short lbl1DDf
    stc
lbl1DDf:
    ret
    push di
    mov si,word ptr [bx+8h]
    cmp si,word ptr [bx+0Ah]
    jnz short lbl1EAf
    mov si,word ptr [bx+6h]
lbl1EAb:
lbl1EAf:
    lodsw
    cmp ax,0FFFFFFFFFFFFFFFEh
    jz short lbl1F8f
    mov di,si
    and al,0FEh
    add si,ax
    jmp short lbl1EAb
lbl1F8f:
    dec di
    dec di
    mov si,di
    pop di
    ret
lblE3E7f:
_TEXT ENDS
    END
