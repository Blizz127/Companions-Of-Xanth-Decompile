_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi79:NEAR
    EXTRN mi3a:NEAR
    EXTRN md9b:NEAR
    EXTRN md8d:NEAR
    EXTRN mi59:NEAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,8h
    mov ax,word ptr ds:[5CE2h]
    sub ax,0CDh
    jz short lbl11f
    db 0E9h, 91h, 00h ; override
lbl11f:
    mov word ptr [bp-2h],0h
    mov word ptr [bp-6h],22h
lbl1Bb:
    mov ax,word ptr ds:[5CDEh]
    mov es, ds:[5A34h]
    mov bx,word ptr [bp-6h]
    cmp word ptr es:[bx],ax
    jnz short lbl33f
    mov ax,word ptr ds:[5CE0h]
    cmp word ptr es:[bx+2h],ax
    db 74h, 4Fh ; override
lbl33f:
    inc word ptr [bp-2h]
    add word ptr [bp-6h],6h
    cmp word ptr [bp-6h], offset mi3a
    jc short lbl1Bb
    mov bx,word ptr ds:[5CDEh]
    mov ax,bx
    add bx,bx
    add bx,bx
    add bx,ax
    add bx,bx
    add bx,word ptr ds:[5CE0h]
    add bx,bx
    mov al,byte ptr [bx+2C90h]
    and ax, offset mi59
    mov word ptr [bp-2h],0h
    mov word ptr [bp-8h],2h
lbl66b:
    mov es, ds:[5A36h]
    mov bx,word ptr [bp-8h]
    cmp word ptr es:[bx],ax
    db 74h, 22h ; override
    inc word ptr [bp-2h]
    add word ptr [bp-8h],4h
    cmp word ptr [bp-8h], offset mi79
    jc short lbl66b
    db 0EBh, 20h ; override
lbl82f:
    mov bx,word ptr [bp-2h]
    mov ax,bx
    add bx,bx
    add bx,ax
    add bx,bx
    mov ax,word ptr es:[bx+md8d]
    db 0EBh, 10h ; override
lbl94f:
    mov bx,word ptr [bp-2h]
    add bx,bx
    add bx,bx
    mov ax,word ptr es:[bx+md9b]
    jmp short lblA4f
lblA2f:
    xor ax,ax
lblA4f:
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
