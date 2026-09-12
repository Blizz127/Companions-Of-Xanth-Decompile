_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mn23:NEAR
    EXTRN mn34:NEAR
    EXTRN mn66:NEAR
    EXTRN mn66:NEAR
mnem_unit:
    push bp
    mov bp,sp
    push si
    push di
    mov si,word ptr [bp+6h]
    mov al,byte ptr [si+0Ah]
    test al,83h
    jz short lbl6Ef
    test al,40h
    jnz short lbl6Ef
    test al,2h
    jnz short lbl5Ff
    or al,1h
    mov byte ptr [si+0Ah],al
    mov di,si
    sub di,5420h
    add di,5510h
    test al,0Ch
    jnz short lbl37f
    test byte ptr [di],1h
    jnz short lbl37f
    push ds
    push si
    call mn23
    add sp,4h
lbl37f:
    mov ax,word ptr [si+6h]
    mov word ptr [si],ax
    push word ptr [di+2h]
    push word ptr [si+8h]
    push ax
    xor bx,bx
    mov bl,byte ptr [si+0Bh]
    push bx
    push cs
    call mn34
    add sp,8h
    or ax,ax
    jz short lbl65f
    cmp ax,0FFFFFFFFFFFFFFFFh
    jnz short lbl73f
    or byte ptr [si+0Ah],20h
    jmp short lbl69f
lbl5Ff:
    or byte ptr [si+0Ah],20h
    jmp short lbl6Ef
lbl65f:
    or byte ptr [si+0Ah],10h
lbl69f:
    mov word ptr [si+4h],0h
lbl6Ef:
    mov ax,0FFFFh
    jmp short lbl98f
lbl73f:
    mov bh,byte ptr [bx+53CCh]
    and bh,82h
    cmp bh,82h
    jnz short lbl8Af
    mov bh,byte ptr [si+0Ah]
    test bh,82h
    jnz short lbl8Af
    or byte ptr [di],20h
lbl8Af:
    dec ax
    mov word ptr [si+4h],ax
    les bx, dword ptr [si]
    xor ax,ax
    mov al,byte ptr es:[bx]
    inc bx
    mov word ptr [si],bx
lbl98f:
    pop di
    pop si
    pop bp
    retf
_TEXT ENDS
    END
