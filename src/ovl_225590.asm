_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf4:FAR
    EXTRN mf12:FAR
    EXTRN mf16:FAR
    EXTRN mf28:FAR
    EXTRN mf38:FAR
    EXTRN mf51:FAR
    EXTRN mf63:FAR
    EXTRN mf67:FAR
    EXTRN mf73:FAR
    EXTRN mf83:FAR
    EXTRN mf87:FAR
    EXTRN mf98:FAR
    EXTRN mf101:FAR
    EXTRN mf105:FAR
    EXTRN mf111:FAR
    EXTRN mf113:FAR
    EXTRN mf114:FAR
    EXTRN mf124:FAR
    EXTRN mf139:FAR
    EXTRN mf151:FAR
    EXTRN mf154:FAR
    EXTRN mf157:FAR
    EXTRN mf159:FAR
    EXTRN mf167:FAR
    EXTRN mf179:FAR
    EXTRN mf192:FAR
    EXTRN mf202:FAR
    EXTRN mf204:FAR
    EXTRN mf208:FAR
    EXTRN mf208:FAR
    EXTRN mf208:FAR
    EXTRN mf208:FAR
    EXTRN mf208:FAR
    EXTRN mf208:FAR
    EXTRN mf208:FAR
    EXTRN mf208:FAR
    EXTRN mf208:FAR
    EXTRN mf208:FAR
    EXTRN mf208:FAR
    EXTRN mf208:FAR
    EXTRN mf208:FAR
    EXTRN mf208:FAR
    EXTRN mf208:FAR
    EXTRN mf208:FAR
    EXTRN mf208:FAR
    EXTRN mf208:FAR
    EXTRN mf208:FAR
    EXTRN mf208:FAR
    EXTRN mf208:FAR
    EXTRN mf208:FAR
    EXTRN mf208:FAR
    EXTRN mf208:FAR
    EXTRN mf208:FAR
    EXTRN mf208:FAR
    EXTRN mf208:FAR
    EXTRN mf208:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,12h
    push si
    call mf4
    mov ax,0C7h
    push ax
    mov ax,109h
    push ax
    xor ax,ax
    push ax
    push ax
    call mf12
    add sp,8h
    xor ax,ax
    push ax
    call mf16
    add sp,2h
    mov ax,0C1h
    push ax
    mov cx,100h
    push cx
    mov dx,6h
    push dx
    mov bx,8h
    push bx
    mov si,1h
    push si
    call mf28
    add sp,0Ah
    mov ax,0C1h
    push ax
    mov ax,100h
    push ax
    mov ax,6h
    push ax
    mov ax,8h
    push ax
    call mf38
    add sp,8h
    mov word ptr [bp-4h],ax
    mov ax,14h
    push ax
    mov ax,0C0h
    push ax
    mov ax,0FFh
    push ax
    mov ax,7h
    push ax
    mov ax,9h
    push ax
    call mf51
    add sp,0Ah
    mov ax,18h
    push ax
    mov ax,0AFh
    push ax
    mov ax,0F8h
    push ax
    mov ax,0Eh
    push ax
    mov ax,10h
    push ax
    call mf63
    mov ax,0Ah
    add sp,ax
    push ax
    call mf67
    add sp,2h
    mov ax,17h
    push ax
    mov ax,0Fh
    push ax
    call mf73
    add sp,4h
    mov ax,0AEh
    push ax
    mov ax,0F7h
    push ax
    mov ax,0Fh
    push ax
    mov ax,11h
    push ax
    call mf83
    add sp,8h
    mov word ptr [bp-6h],ax
    push ax
    call mf87
    add sp,2h
    mov ax,30h
    push ax
    mov ax,328Bh
    push ds
    push ax
    mov ax,0B2h
    push ax
    mov ax,6Ch
    push ax
    call mf98
    add sp,0Ah
    push word ptr [bp-6h]
    call mf101
    add sp,2h
    mov ax,9h
    push ax
    call mf105
    add sp,2h
    xor ax,ax
    mov dx,0F041h
    push dx
    push ax
    call mf111
    add sp,4h
    call mf113
lbl11Db:
    call mf114
    or ax,ax
    jz short lbl129f
    jmp near ptr lbl1F6f
lbl129f:
    lea ax,word ptr [bp-0Ah]
    push ss
    push ax
    lea ax,word ptr [bp-8h]
    push ss
    push ax
    call mf124
    add sp,8h
    or ax,ax
    jz short lbl11Db
    lea ax,word ptr [bp-10h]
    push ss
    push ax
    lea ax,word ptr [bp-0Eh]
    push ss
    push ax
    lea ax,word ptr [bp-0Ch]
    push ss
    push ax
    push word ptr [bp-0Ah]
    push word ptr [bp-8h]
    call mf139
    add sp,10h
    or ax,ax
    jz short lbl11Db
    cmp word ptr [bp-10h],5h
    jnz short lbl11Db
    mov ax,word ptr [bp-4h]
    cmp word ptr [bp-0Ch],ax
    jnz short lbl11Db
lbl16Eb:
    mov ax,1h
    push ax
    push word ptr [bp-4h]
    call mf151
    add sp,4h
    push word ptr [bp-6h]
    call mf154
    add sp,2h
    push word ptr [bp-4h]
    call mf157
    add sp,2h
    call mf159
    mov ax,0C7h
    push ax
    mov ax,109h
    push ax
    xor ax,ax
    push ax
    push ax
    call mf167
    add sp,8h
    mov word ptr [bp-2h],0h
    cmp word ptr ds:[5E0Ah],0h
    jz short lbl1E5f
    mov word ptr [bp-12h],0h
lbl1BDb:
    xor ax,ax
    push ax
    mov es, ds:[5B04h]
    mov bx,word ptr [bp-12h]
    push word ptr es:[bx+2h]
    push word ptr es:[bx]
    call mf179
    add sp,6h
    add word ptr [bp-12h],4h
    mov ax,word ptr ds:[5E0Ah]
    inc word ptr [bp-2h]
    cmp word ptr [bp-2h],ax
    jc short lbl1BDb
lbl1E5f:
    push word ptr ds:[5E0Eh]
    cmp word ptr ds:[5E0Ch],1h
    jnz short lbl1FEf
    mov ax,328Eh
    jmp short lbl201f
    nop
lbl1F6f:
    call mf192
    jmp near ptr lbl16Eb
lbl1FEf:
    mov ax,328Fh
lbl201f:
    push ds
    push ax
    push word ptr ds:[5E0Ch]
    mov ax,1h
    mov dx,0F041h
    push dx
    push ax
    call mf202
    add sp,0Ch
    call mf204
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
