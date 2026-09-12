_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi4:NEAR
    EXTRN mi5:NEAR
    EXTRN md10:NEAR
    EXTRN md28:NEAR
    EXTRN mf32:FAR
    EXTRN mf38:FAR
    EXTRN mf46:FAR
    EXTRN mf59:FAR
    EXTRN mf76:FAR
    EXTRN mf82:FAR
    EXTRN mf90:FAR
    EXTRN mf96:FAR
    EXTRN mf103:FAR
    EXTRN mf111:FAR
    EXTRN mf122:FAR
    EXTRN mf129:FAR
    EXTRN mf133:FAR
    EXTRN mf135:FAR
    EXTRN mf142:FAR
    EXTRN mf151:FAR
    EXTRN mf155:FAR
    EXTRN mf155:FAR
    EXTRN mf155:FAR
    EXTRN mf155:FAR
    EXTRN mf155:FAR
    EXTRN mf155:FAR
    EXTRN mf155:FAR
    EXTRN mf155:FAR
    EXTRN mf155:FAR
    EXTRN mf155:FAR
    EXTRN mf155:FAR
    EXTRN mf155:FAR
    EXTRN mf155:FAR
    EXTRN mf155:FAR
    EXTRN mf155:FAR
    EXTRN mf155:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,8h
    mov ax,word ptr [bp+6h]
    sub ax, offset mi4
    cmp ax, offset mi5
    jna short lbl14f
    jmp near ptr lbl183f
lbl14f:
    add ax,ax
    xchg ax,bx
    jmp word ptr cs:[bx+md10]
    jo short lbl1Ef
lbl1Ef:
    and byte ptr [bx+di],al
    and byte ptr [bx+di],al
    and byte ptr [bx+di],al
    mov bl,1h
    and al,1h
    mov bl,1h
    mov bl,1h
    mov bl,1h
    mov bl,1h
    mov bl,1h
    mov bl,1h
    mov bl,1h
    mov bl,1h
    inc sp
    add word ptr [bp+si-4CFFh],sp
    add word ptr [si],sp
    add word ptr [bx+si+md28],di
    push ax
    mov ax,1CEh
    push ax
    call mf32
    add sp,4h
    mov ax,1B1h
    push ax
    mov ax,1B7h
    push ax
    call mf38
    add sp,4h
    or ax,ax
    jz short lbl76f
    mov ax,1B7h
    push ax
    mov ax,3h
    push ax
    call mf46
    add sp,4h
    jmp short lbl7Bf
lbl76f:
    mov ax,3A8Bh
    mov dx,ds
lbl7Bf:
    mov word ptr [bp-4h],ax
    mov word ptr [bp-2h],dx
    push dx
    push ax
    mov ax,1CEh
    push ax
    mov ax,1D4h
    push ax
    call mf59
    add sp,4h
    or ax,ax
    jz short lbl9Cf
    xor ax,ax
    cwd
    jmp short lblA1f
lbl9Cf:
    mov ax,3A9Bh
    mov dx,ds
lblA1f:
    mov word ptr [bp-8h],ax
    mov word ptr [bp-6h],dx
    push dx
    push ax
    mov ax,1h
    mov dx,0F04Ah
    push dx
    push ax
    call mf76
    add sp,0Ch
    mov ax,1CEh
    push ax
    mov ax,1C3h
    push ax
    call mf82
    add sp,4h
    or ax,ax
    jz short lblDDf
    mov ax,2h
    mov dx,0F04Ah
    push dx
    push ax
    call mf90
    add sp,4h
lblDDf:
    mov ax,3h
lblE0b:
    mov dx,0F04Ah
    push dx
    push ax
    call mf96
lblEAb:
    add sp,4h
    jmp near ptr lbl183f
    xor ax,ax
    jmp short lblE0b
    mov ax,29h
    push ax
    call mf103
    add sp,2h
    or ax,ax
    jnz short lbl183f
    mov ax,2h
    push ax
    mov ax,29h
    push ax
    call mf111
    jmp short lblEAb
    nop
    cmp byte ptr ds:[3A8Ah],0h
    jz short lbl15Cf
    mov byte ptr ds:[3A8Ah],0h
    mov byte ptr ds:[36Dh],1h
    cmp word ptr ds:[58h],0h
    jnz short lbl15Cf
    cmp word ptr ds:[56h],1h
    jz short lbl15Cf
    call mf122
    xor al,al
    push ax
    mov ax,17h
    push ax
    mov ax,1218h
    push ax
    call mf129
    add sp,6h
    mov ax,0FA0h
    push ax
    call mf133
    add sp,2h
    call mf135
lbl15Cf:
    mov ax,3h
    push ax
    mov ax,0h
    mov cx,32A4h
    push cx
    push ax
    call mf142
    add sp,6h
    jmp short lbl185f
    mov ax,3h
    push ax
    mov ax,24h
    mov cx,32A4h
    push cx
    push ax
    call mf151
lbl183f:
    xor ax,ax
lbl185f:
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
