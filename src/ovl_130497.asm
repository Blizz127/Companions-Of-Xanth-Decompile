_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi6:NEAR
    EXTRN mf113:FAR
    EXTRN mf7d:FAR
    EXTRN mf176:FAR
    EXTRN mf1a9:FAR
    EXTRN mfe6:FAR
    EXTRN mf1f0:FAR
    EXTRN mi9:NEAR
    EXTRN mf1d4:FAR
    EXTRN mf44:FAR
    EXTRN md14:NEAR
    EXTRN mf129:FAR
    EXTRN mf219:FAR
    EXTRN mf184:FAR
    EXTRN mf1b9:FAR
    EXTRN mf57:FAR
    EXTRN mfb8:FAR
    EXTRN mf231:FAR
    EXTRN mfa9:FAR
    EXTRN mf6a:FAR
    EXTRN mf194:FAR
    EXTRN mf208:FAR
    EXTRN mf253:FAR
    EXTRN mf1c9:FAR
    EXTRN mf1f7:FAR
    EXTRN mf246:FAR
    EXTRN mf16c:FAR
    EXTRN mf1c0:FAR
    EXTRN mf96:FAR
    EXTRN mf203:FAR
    EXTRN mf24e:FAR
    EXTRN mf100:FAR
    EXTRN mf146:FAR
    EXTRN mfd0:FAR
mnem_unit:
    push bp
    mov bp,sp
    mov ax,word ptr [bp+6h]
    sub ax, offset mi6
    cmp ax, offset mi9
    jna short lbl11f
    db 0E9h, 4Ch, 02h ; override
lbl11f:
    add ax,ax
    xchg ax,bx
    jmp word ptr cs:[bx+md14]
    nop
    db 4Dh, 00h, 0D3h, 00h, 0D3h, 00h, 0D3h, 00h, 6Eh, 02h, 0D9h, 00h, 6Eh, 02h, 19h, 01h
    db 6Eh, 02h, 6Eh, 02h, 6Eh, 02h, 6Eh, 02h, 6Eh, 02h, 6Eh, 02h, 73h, 01h, 4Bh, 02h
    db 5Fh, 02h
    mov ax,2h
    mov dx,0F00Fh
    push dx
    push ax
    call mf44
    mov sp,bp
    mov ax,1h
    push ax
    mov ax,99h
    push ax
    mov ax,73h
    push ax
    call mf57
    mov sp,bp
    or ax,ax
    jz short lbl8Ef
    mov ax,3h
    mov dx,0F00Fh
    push dx
    push ax
    call mf6a
    mov sp,bp
    mov ax,1h
    push ax
    mov ax,73h
    push ax
    mov ax,8Ah
    push ax
    call mf7d
    mov sp,bp
    or ax,ax
    jz short lblB0f
    mov ax,4h
    jmp short lblA4f
    nop
lbl8Ef:
    mov ax,98h
    push ax
    mov ax,73h
    push ax
    call mf96
    mov sp,bp
    or ax,ax
    jz short lblB0f
    mov ax,5h
lblA4f:
    mov dx,0F00Fh
    push dx
    push ax
    call mfa9
    mov sp,bp
lblB0f:
    mov ax,6h
lblB3b:
    mov dx,0F00Fh
    push dx
    push ax
    call mfb8
lblBDb:
    mov sp,bp
    jmp near ptr lbl25Df
    mov ax,1h
    jmp short lblB3b
    nop
    mov ax,99h
    push ax
    mov ax,73h
    push ax
    call mfd0
    mov sp,bp
    or ax,ax
    jnz short lblDEf
    jmp near ptr lbl25Df
lblDEf:
    mov ax,0Ah
    push ax
    mov ax,73h
    push ax
    call mfe6
    mov sp,bp
    or ax,ax
    jz short lblF4f
    jmp near ptr lbl25Df
lblF4f:
    mov ax,1h
    push ax
    mov ax,5h
    push ax
    mov ax,8026h
    push ax
    call mf100
    jmp short lblBDb
    nop
    xor ax,ax
    push ax
    mov ax,5h
    push ax
    mov ax,8026h
    push ax
    call mf113
    mov sp,bp
    cmp byte ptr ds:[2F2h],0h
    jz short lbl134f
    mov ax,9Bh
    push ax
    mov ax,8Ah
    push ax
    call mf129
    mov sp,bp
    or ax,ax
    jz short lbl14Df
lbl134f:
    cmp byte ptr ds:[6E5Ch],2h
    jnz short lbl14Df
    xor ax,ax
    push ax
    mov ax,9Ah
    push ax
    mov ax,9Bh
    push ax
    call mf146
    mov sp,bp
lbl14Df:
    xor al,al
    mov word ptr ds:[2A4h],0h
    mov byte ptr ds:[278Ah],al
    mov byte ptr ds:[278Bh],al
    mov byte ptr ds:[278Ch],al
    jmp near ptr lbl24Ef
    nop
    cmp byte ptr ds:[308h],0h
    jnz short lbl16Cf
    jmp near ptr lbl1FCf
lbl16Cf:
    call mf16c
    mov ax,278Eh
    push ds
    push ax
    call mf176
    mov sp,bp
    xor ax,ax
    mov dx,0F00Fh
    push dx
    push ax
    call mf184
    mov sp,bp
    mov ax,1h
    push ax
    push ax
    mov ax,8h
    push ax
    call mf194
    mov sp,bp
    cmp word ptr ds:[58h],0h
    jnz short lbl1D0f
    cmp word ptr ds:[56h],1h
    jz short lbl1D0f
    call mf1a9
    xor al,al
    push ax
    mov ax,18h
    push ax
    mov ax,504h
    push ax
    call mf1b9
    mov sp,bp
    call mf1c0
    mov ax,1h
    push ax
    call mf1c9
    mov sp,bp
lbl1D0f:
    mov ax,0BB8h
    push ax
    call mf1d4
    mov sp,bp
    mov byte ptr ds:[308h],0h
    mov byte ptr ds:[2F2h],1h
    xor ax,ax
    push ax
    mov ax,5h
    push ax
    mov ax,8026h
    push ax
    call mf1f0
    mov sp,bp
    call mf1f7
lbl1FCf:
    cmp byte ptr ds:[278Dh],0h
    jnz short lbl225f
    call mf203
    call mf208
    xor ax,ax
    push ax
    push ax
    mov ax,44h
    push ax
    mov ax,51Ch
    push ax
    call mf219
    mov sp,bp
    mov byte ptr ds:[278Dh],1h
lbl225f:
    mov ax,3h
    push ax
    mov ax,0h
    mov cx,3384h
    push cx
    push ax
    call mf231
    mov sp,bp
    jmp short lbl25Ff
    mov ax,3h
    push ax
    mov ax,24h
    mov cx,3384h
    push cx
    push ax
    call mf246
    jmp near ptr lblBDb
lbl24Ef:
    call mf24e
    call mf253
    mov byte ptr ds:[278Dh],0h
lbl25Df:
    xor ax,ax
lbl25Ff:
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
