_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf53:FAR
    EXTRN mfdd:FAR
    EXTRN mfed:FAR
    EXTRN mi9:NEAR
    EXTRN mf44:FAR
    EXTRN mf143:FAR
    EXTRN mf110:FAR
    EXTRN mfa7:FAR
    EXTRN mic:NEAR
    EXTRN mfc3:FAR
    EXTRN mf12e:FAR
    EXTRN mf101:FAR
    EXTRN mfd1:FAR
    EXTRN mf66:FAR
    EXTRN mf152:FAR
    EXTRN mfb6:FAR
    EXTRN mf18a:FAR
    EXTRN md17:NEAR
    EXTRN mf174:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,8h
    mov ax,word ptr [bp+6h]
    sub ax, offset mi9
    cmp ax, offset mic
    jna short lbl14f
    db 0E9h, 7Bh, 01h ; override
lbl14f:
    add ax,ax
    xchg ax,bx
    jmp word ptr cs:[bx+md17]
    db 3Ch, 00h, 5Eh, 00h, 5Eh, 00h, 5Eh, 00h, 8Fh, 01h, 0B2h, 00h, 8Fh, 01h, 8Fh, 01h
    db 8Fh, 01h, 8Fh, 01h, 8Fh, 01h, 8Fh, 01h, 8Fh, 01h, 8Fh, 01h, 68h, 01h, 7Eh, 01h
    mov ax,0Ah
    push ax
    push word ptr ds:[256h]
    call mf44
    mov ax,4h
    add sp,ax
    mov dx,0F02Ch
    push dx
    push ax
    call mf53
    add sp,4h
    jmp near ptr lbl18Ff
    mov ax,1h
    mov dx,0F02Ch
    push dx
    push ax
    call mf66
    add sp,4h
    mov ax,word ptr ds:[256h]
    sub ax,178h
    jz short lbl80f
    dec ax
    dec ax
    jz short lbl8Cf
    dec ax
    dec ax
    jz short lbl94f
    jmp short lbl9Cf
lbl80f:
    mov word ptr [bp-6h],2h
lbl85b:
    mov word ptr [bp-4h],0F02Ch
    jmp short lbl9Cf
lbl8Cf:
    mov word ptr [bp-6h],3h
    jmp short lbl85b
    nop
lbl94f:
    mov word ptr [bp-6h],3744h
    mov word ptr [bp-4h],ds
lbl9Cf:
    push word ptr [bp-4h]
    push word ptr [bp-6h]
    mov ax,374Fh
    push ds
    push ax
    call mfa7
    add sp,8h
    jmp near ptr lbl18Ff
    mov ax,8Bh
    push ax
    call mfb6
    add sp,2h
    cmp ax,143h
    jnz short lblE5f
    call mfc3
    mov ax,1h
    push ax
    push ax
    mov ax,4h
    push ax
    call mfd1
    add sp,6h
    mov ax,1388h
    push ax
    call mfdd
    add sp,2h
lblE5f:
    mov ax,0Ah
    push ax
    mov ax,178h
    push ax
    call mfed
    add sp,4h
    or ax,ax
    jnz short lbl118f
    mov ax,0Ah
    push ax
    mov ax,178h
    push ax
    call mf101
    add sp,4h
    xor ax,ax
    mov dx,0F02Ch
    push dx
    push ax
    call mf110
    add sp,4h
lbl118f:
    mov word ptr [bp-8h],373Ah
lbl11Db:
    mov ax,word ptr ds:[256h]
    mov bx,word ptr [bp-8h]
    cmp word ptr [bx-2h],ax
    jnz short lbl15Af
    mov ax,0Ah
    push ax
    push word ptr [bx]
    call mf12e
    add sp,4h
    or ax,ax
    jnz short lbl15Af
    mov ax,0Ah
    push ax
    mov bx,word ptr [bp-8h]
    push word ptr [bx]
    call mf143
    add sp,4h
    xor ax,ax
    push ax
    mov ax,22h
    push ax
    call mf152
    add sp,4h
lbl15Af:
    add word ptr [bp-8h],4h
    cmp word ptr [bp-8h],3746h
    jc short lbl11Db
    jmp short lbl18Ff
    nop
    mov ax,3h
    push ax
    mov ax,0h
    mov cx,32E2h
    push cx
    push ax
    call mf174
    add sp,6h
    jmp short lbl191f
    mov ax,3h
    push ax
    mov ax,24h
    mov cx,32E2h
    push cx
    push ax
    call mf18a
lbl18Ff:
    xor ax,ax
lbl191f:
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
