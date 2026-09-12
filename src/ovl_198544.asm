_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi3:NEAR
    EXTRN mi4:NEAR
    EXTRN mf22:FAR
    EXTRN mf34:FAR
    EXTRN mf45:FAR
    EXTRN mf51:FAR
    EXTRN mf60:FAR
    EXTRN mf67:FAR
    EXTRN mf73:FAR
    EXTRN mf81:FAR
    EXTRN mf82:FAR
    EXTRN mf87:FAR
    EXTRN mf88:FAR
    EXTRN mf93:FAR
    EXTRN mf103:FAR
    EXTRN mf110:FAR
    EXTRN mf120:FAR
    EXTRN mf128:FAR
    EXTRN mf135:FAR
    EXTRN mf139:FAR
    EXTRN mf139:FAR
    EXTRN mf139:FAR
    EXTRN mf139:FAR
    EXTRN mf139:FAR
    EXTRN mf139:FAR
    EXTRN mf139:FAR
    EXTRN mf139:FAR
    EXTRN mf139:FAR
    EXTRN mf139:FAR
    EXTRN mf139:FAR
    EXTRN mf139:FAR
    EXTRN mf139:FAR
    EXTRN mf139:FAR
    EXTRN mf139:FAR
    EXTRN mf139:FAR
    EXTRN mf139:FAR
mnem_unit:
    push bp
    mov bp,sp
    mov ax,word ptr [bp+6h]
    sub ax, offset mi3
    cmp ax, offset mi4
    jna short lbl11f
    jmp near ptr lbl162f
lbl11f:
    add ax,ax
    xchg ax,bx
    jmp word ptr cs:[bx+3EAh]
    nop
    adc al,4h
    xor al,byte ptr [di]
    sub al,byte ptr [si]
    xor al,byte ptr [di]
    xor al,4h
    outsb
    add al,6Eh
    add al,6Eh
    add al,32h
    add ax,532h
    xor al,byte ptr [di]
    call mf22
    add ax,532h
    xor al,byte ptr [di]
    xor al,byte ptr [di]
    xor al,byte ptr [di]
    lodsb
    add al,24h
    add ax,49Ah
    mov ax,106h
    push ax
    push word ptr ds:[6A04h]
lbl4Cb:
    push word ptr ds:[6A06h]
    call mf34
lbl55b:
    mov sp,bp
    jmp near ptr lbl164f
    push word ptr ds:[6A02h]
    mov ax,106h
    push ax
    jmp short lbl4Cb
    mov ax,2h
    mov dx,0F023h
    push dx
    push ax
    call mf45
    add sp,4h
    mov ax,105h
    push ax
    mov ax,90h
    push ax
    call mf51
    add sp,4h
    or ax,ax
    jnz short lbl8Bf
    jmp near ptr lbl162f
lbl8Bf:
    mov ax,3h
lbl8Eb:
    mov dx,0F023h
    push dx
    push ax
    call mf60
    add sp,4h
    jmp near ptr lbl162f
    xor ax,ax
    mov dx,0F023h
    push dx
    push ax
    call mf67
    add sp,4h
    mov ax,105h
    push ax
    mov ax,90h
    push ax
    call mf73
    add sp,4h
    or ax,ax
    jnz short lblC4f
    jmp near ptr lbl162f
lblC4f:
    mov ax,1h
    jmp short lbl8Eb
    nop
    call mf81
    call mf82
    mov byte ptr ds:[3142h],0h
    jmp near ptr lbl162f
    cmp byte ptr ds:[3142h],0h
    jnz short lbl143f
    call mf87
    call mf88
    mov ax,105h
    push ax
    mov ax,90h
    push ax
    call mf93
    add sp,4h
    or ax,ax
    jnz short lbl12Af
    push ax
    push ax
    mov ax,13h
    push ax
    mov ax,0AD3h
    push ax
    call mf103
    add sp,8h
    cmp word ptr ds:[256h],105h
    jnz short lbl13Ef
    mov ax,315Ch
    push ds
    push ax
    call mf110
    add sp,4h
    jmp short lbl13Ef
lbl12Af:
    xor ax,ax
    push ax
    push ax
    mov ax,6h
    push ax
    mov ax,0AE6h
    push ax
    call mf120
    add sp,8h
lbl13Ef:
    mov byte ptr ds:[3142h],1h
lbl143f:
    mov ax,1h
    push ax
    mov ax,3144h
    push ds
    push ax
    call mf128
    jmp near ptr lbl55b
    mov ax,1h
    push ax
    mov ax,3150h
    push ds
    push ax
    call mf135
lbl162f:
    xor ax,ax
lbl164f:
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
