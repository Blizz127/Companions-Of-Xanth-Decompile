_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf9:FAR
    EXTRN md25:NEAR
    EXTRN md32:NEAR
    EXTRN md38:NEAR
    EXTRN mi40:NEAR
    EXTRN mf55:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,8h
    cmp word ptr [bp+6h],0h
    jng short lbl8Af
    mov ax,word ptr ds:[84Ch]
    cmp word ptr [bp+6h],ax
    ja short lbl8Af
    push word ptr [bp+6h]
    call mf9
    add sp,2h
    mov word ptr [bp-8h],ax
    mov word ptr [bp-6h],dx
    cmp word ptr [bp+8h],0h
    jz short lbl8Af
    mov ax,dx
    or ax,word ptr [bp-8h]
    jz short lbl8Af
    mov es, ds:[5A24h]
    mov bx,word ptr [bp+6h]
    mov ax,bx
    add bx,bx
    add bx,ax
    add bx,bx
    mov ax,1h
    mov cl,byte ptr es:[bx+md25]
    dec cl
    shl ax,cl
    mov es, ds:[5A26h]
    mov bx,word ptr [bp+8h]
    add bx,bx
    add bx,bx
    test word ptr es:[bx+md32],ax
    jz short lbl8Af
    mov bx,word ptr [bp+8h]
    add bx,bx
    add bx,bx
    sub ah,ah
    mov al,byte ptr es:[bx+md38]
    mov word ptr [bp-2h],ax
    and ax, offset mi40
    les bx, dword ptr [bp+0Ah]
    mov word ptr es:[bx],ax
    mov ax,word ptr [bp-2h]
    mov cl,3h
    shr ax,cl
    add ax,word ptr [bp-8h]
    mov dx,word ptr [bp-6h]
    jmp short lbl8Df
    nop
    nop
lbl8Af:
    xor ax,ax
    cwd
lbl8Df:
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
