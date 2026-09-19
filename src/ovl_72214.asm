_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf201:FAR
    EXTRN mf122:FAR
    EXTRN mf3c0:FAR
    EXTRN mf38b:FAR
    EXTRN mf2ac:FAR
    EXTRN mf14a:FAR
    EXTRN mf133:FAR
    EXTRN mf26e:FAR
    EXTRN mf191:FAR
    EXTRN mf112:FAR
    EXTRN mf30a:FAR
    EXTRN mi9:NEAR
    EXTRN mf17f:FAR
    EXTRN mf1d4:FAR
    EXTRN mf241:FAR
    EXTRN mf266:FAR
    EXTRN mf37a:FAR
    EXTRN mf24d:FAR
    EXTRN mf3cd:FAR
    EXTRN mf335:FAR
    EXTRN mf67:FAR
    EXTRN mf2c9:FAR
    EXTRN mf48:FAR
    EXTRN mf350:FAR
    EXTRN mf236:FAR
    EXTRN mf97:FAR
    EXTRN mf32d:FAR
    EXTRN mf2ec:FAR
    EXTRN mic:NEAR
    EXTRN mf2a4:FAR
    EXTRN mf2b1:FAR
    EXTRN mf1ba:FAR
    EXTRN mf3ae:FAR
    EXTRN mf1e6:FAR
    EXTRN mf39e:FAR
    EXTRN mf361:FAR
    EXTRN mf3b6:FAR
    EXTRN mf220:FAR
    EXTRN mfc9:FAR
    EXTRN mf79:FAR
    EXTRN mf2fe:FAR
    EXTRN mf2dc:FAR
    EXTRN mf31d:FAR
    EXTRN mfb9:FAR
    EXTRN mf2f4:FAR
    EXTRN mf34b:FAR
    EXTRN mf1a3:FAR
    EXTRN mf3de:FAR
    EXTRN mfff:FAR
    EXTRN mf33f:FAR
    EXTRN mf28f:FAR
    EXTRN mff3:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,8h
    mov ax,word ptr [bp+6h]
    sub ax, offset mi9
    cmp ax, offset mic
    jna short lbl14f
    jmp near ptr lbl3F0f
lbl14f:
    add ax,ax
    xchg ax,bx
    jmp word ptr cs:[bx+102h]
    db 26h, 01h, 0F0h, 01h, 0F0h, 01h, 0F0h, 01h, 0D6h, 04h, 54h, 02h, 3Eh, 03h, 92h, 03h
    db 0D6h, 04h, 0D6h, 04h, 0D6h, 04h, 0D6h, 04h, 0D6h, 04h, 0D6h, 04h, 0A8h, 03h, 6Ah, 04h
    db 92h, 03h, 0CEh, 04h
    mov ax,0Eh
    push ax
    mov ax,31h
    push ax
    call mf48
    add sp,4h
    or ax,ax
    jz short lbl5Af
    mov ax,1EEEh
    jmp short lbl5Df
    nop
lbl5Af:
    mov ax,1EF3h
lbl5Df:
    push ds
    push ax
    mov ax,56h
    push ax
    mov ax,1h
    push ax
    call mf67
    add sp,4h
    push dx
    push ax
    mov ax,0Ah
    push ax
    mov ax,29h
    push ax
    call mf79
    add sp,4h
    or ax,ax
    jz short lbl8Af
    mov ax,1EFAh
    jmp short lbl8Df
lbl8Af:
    mov ax,1EFCh
lbl8Df:
    push ds
    push ax
    mov ax,23h
    push ax
    mov ax,24h
    push ax
    call mf97
    add sp,4h
    or ax,ax
    jz short lblACf
    mov ax,8h
    mov dx,0F003h
    jmp short lblAFf
    nop
lblACf:
    xor ax,ax
    cwd
lblAFf:
    push dx
    push ax
    mov ax,7h
    mov dx,0F003h
    push dx
    push ax
    call mfb9
    add sp,14h
    mov ax,0Ah
    push ax
    mov ax,29h
    push ax
    call mfc9
    add sp,4h
    or ax,ax
    jnz short lblDCf
    mov ax,1EFFh
    push ds
    jmp short lblF2f
    nop
lblDCf:
    cmp byte ptr ds:[324h],0h
    jz short lblECf
    mov ax,9h
    mov dx,0F003h
    jmp short lblF1f
    nop
lblECf:
    mov ax,1F07h
    mov dx,ds
lblF1f:
    push dx
lblF2f:
    push ax
    call mff3
    add sp,4h
    mov ax,2Eh
    push ax
    call mfff
    add sp,2h
    jmp near ptr lbl3F0f
    mov ax,2h
    mov dx,0F003h
    push dx
    push ax
    call mf112
    add sp,4h
    mov ax,0Ah
    push ax
    mov ax,29h
    push ax
    call mf122
    add sp,4h
    or ax,ax
    jz short lbl168f
    mov ax,1EDEh
    push ds
    push ax
    call mf133
    add sp,4h
    cmp byte ptr ds:[36Eh],0h
    jz short lbl156f
    mov ax,3h
lbl145b:
    mov dx,0F003h
    push dx
    push ax
    call mf14a
lbl14Fb:
    add sp,4h
    jmp near ptr lbl3F0f
    nop
lbl156f:
    cmp byte ptr ds:[324h],0h
    jz short lbl162f
    mov ax,4h
    jmp short lbl145b
lbl162f:
    mov ax,5h
    jmp short lbl145b
    nop
lbl168f:
    mov ax,6h
    jmp short lbl145b
    nop
    cmp byte ptr ds:[28Eh],0h
    jnz short lbl178f
    jmp near ptr lbl3E8f
lbl178f:
    xor ax,ax
    push ax
    mov cx,1h
    push cx
    call mf17f
    add sp,4h
    mov word ptr [bp-2h],ax
    or ax,ax
    jz short lbl1CCf
lbl18Eb:
    push word ptr [bp-2h]
    call mf191
    add sp,2h
    mov word ptr [bp-4h],ax
    mov ax,12h
    push ax
    push word ptr [bp-2h]
    call mf1a3
    add sp,4h
    or ax,ax
    jz short lbl1C2f
    mov ax,1h
    push ax
    mov ax,68h
    push ax
    push word ptr [bp-2h]
    call mf1ba
    add sp,6h
lbl1C2f:
    mov ax,word ptr [bp-4h]
    mov word ptr [bp-2h],ax
    or ax,ax
    jnz short lbl18Eb
lbl1CCf:
    mov ax,1h
    push ax
    mov ax,2Eh
    push ax
    call mf1d4
    add sp,4h
    mov word ptr [bp-2h],ax
    or ax,ax
    jz short lbl213f
lbl1E3b:
    push word ptr [bp-2h]
    call mf1e6
    add sp,2h
    mov word ptr [bp-4h],ax
    cmp word ptr [bp-2h],2Fh
    jz short lbl209f
    xor ax,ax
    push ax
    mov ax,1h
    push ax
    push word ptr [bp-2h]
    call mf201
    add sp,6h
lbl209f:
    mov ax,word ptr [bp-4h]
    mov word ptr [bp-2h],ax
    or ax,ax
    jnz short lbl1E3b
lbl213f:
    mov byte ptr ds:[28Eh],0h
    mov ax,7h
    push ax
    mov ax,1h
    push ax
    call mf220
    add sp,4h
    cmp byte ptr ds:[298h],0h
    jnz short lbl232f
    jmp near ptr lbl3E8f
lbl232f:
    mov ax,40h
    push ax
    call mf236
    mov ax,2h
    add sp,ax
    push ax
    call mf241
    add sp,2h
    mov ax,10h
    push ax
    call mf24d
    add sp,2h
    jmp near ptr lbl3E8f
    cmp byte ptr ds:[36Fh],0h
    jz short lbl273f
    xor ax,ax
    mov dx,0F003h
    push dx
    push ax
    call mf266
    add sp,4h
    call mf26e
lbl273f:
    cmp byte ptr ds:[36Eh],0h
    jnz short lbl27Df
    jmp near ptr lbl3F0f
lbl27Df:
    cmp byte ptr ds:[370h],0h
    jz short lbl287f
    jmp near ptr lbl3F0f
lbl287f:
    mov ax,1h
    mov dx,0F003h
    push dx
    push ax
    call mf28f
    add sp,4h
    mov byte ptr ds:[370h],1h
    mov ax,2h
    push ax
    mov ax,2Ah
    push ax
    call mf2a4
    jmp near ptr lbl14Fb
    call mf2ac
    call mf2b1
    xor al,al
    mov byte ptr ds:[325h],al
    mov byte ptr ds:[1ED2h],al
    jmp near ptr lbl3F0f
    nop
    cmp byte ptr ds:[29Dh],0h
    jz short lbl303f
    call mf2c9
    cmp word ptr ds:[58h],0h
    jnz short lbl2F9f
    cmp word ptr ds:[56h],1h
    jz short lbl2F9f
    call mf2dc
    mov al,1h
    push ax
    mov ax,9h
    push ax
    mov ax,20Bh
    push ax
    call mf2ec
    add sp,6h
    call mf2f4
lbl2F9f:
    mov byte ptr ds:[29Dh],0h
    call mf2fe
lbl303f:
    cmp byte ptr ds:[29Eh],0h
    jz short lbl344f
    call mf30a
    cmp word ptr ds:[58h],0h
    jnz short lbl33Af
    cmp word ptr ds:[56h],1h
    jz short lbl33Af
    call mf31d
    xor al,al
    push ax
    mov ax,9h
    push ax
    mov ax,20Bh
    push ax
    call mf32d
    add sp,6h
    call mf335
lbl33Af:
    mov byte ptr ds:[29Eh],0h
    call mf33f
lbl344f:
    cmp byte ptr ds:[1ED2h],0h
    jnz short lbl36Ef
    call mf34b
    call mf350
    xor ax,ax
    push ax
    push ax
    mov ax,0Ah
    push ax
    mov ax,214h
    push ax
    call mf361
    add sp,8h
    mov byte ptr ds:[1ED2h],1h
lbl36Ef:
    mov ax,9h
    push ax
    mov ax,0h
    mov cx,32FBh
    push cx
    push ax
    call mf37a
    add sp,6h
    jmp short lbl3F2f
    cmp byte ptr ds:[325h],0h
    jz short lbl3D2f
    call mf38b
    cmp word ptr ds:[58h],0h
    jnz short lbl3BBf
    cmp word ptr ds:[56h],1h
    jz short lbl3BBf
    call mf39e
    xor al,al
    push ax
    mov ax,0Bh
    push ax
    mov ax,21Eh
    push ax
    call mf3ae
    add sp,6h
    call mf3b6
lbl3BBf:
    mov ax,1ED3h
    push ds
    push ax
    call mf3c0
    add sp,4h
    mov byte ptr ds:[325h],0h
    call mf3cd
lbl3D2f:
    mov ax,9h
    push ax
    mov ax,6Ch
    mov cx,32FBh
    push cx
    push ax
    call mf3de
    add sp,6h
    jmp short lbl3F0f
lbl3E8f:
    xor al,al
    mov byte ptr ds:[309h],al
    mov byte ptr ds:[29Ah],al
lbl3F0f:
    xor ax,ax
lbl3F2f:
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
