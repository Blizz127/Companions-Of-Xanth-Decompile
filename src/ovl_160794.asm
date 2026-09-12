_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi3:NEAR
    EXTRN mi12:NEAR
    EXTRN mi16:NEAR
    EXTRN mi18:NEAR
    EXTRN mf25:FAR
    EXTRN mf33:FAR
    EXTRN mf40:FAR
    EXTRN mf53:FAR
    EXTRN mf64:FAR
    EXTRN mi69:NEAR
    EXTRN mi71:NEAR
    EXTRN mf78:FAR
    EXTRN mf83:FAR
    EXTRN mf94:FAR
    EXTRN mf107:FAR
    EXTRN mf115:FAR
    EXTRN mf121:FAR
    EXTRN mf131:FAR
    EXTRN mf139:FAR
    EXTRN mf147:FAR
    EXTRN mf150:FAR
    EXTRN mf163:FAR
    EXTRN mf163:FAR
    EXTRN mf163:FAR
    EXTRN mf163:FAR
    EXTRN mf163:FAR
    EXTRN mf163:FAR
    EXTRN mf163:FAR
    EXTRN mf163:FAR
    EXTRN mf163:FAR
    EXTRN mf163:FAR
    EXTRN mf163:FAR
    EXTRN mf163:FAR
    EXTRN mf163:FAR
    EXTRN mf163:FAR
    EXTRN mf163:FAR
mnem_unit:
    push bp
    mov bp,sp
    mov ax,word ptr [bp+6h]
    sub ax, offset mi3
    jz short lbl16f
    dec ax
    dec ax
    jnz short lbl12f
    jmp near ptr lblA2f
lbl12f:
    jmp near ptr lbl18Cf
    nop
lbl16f:
    mov ax,word ptr ds:[6A06h]
    sub ax, offset mi12
    jz short lbl21f
    jmp near ptr lbl18Cf
lbl21f:
    mov ax,word ptr ds:[6A04h]
    sub ax, offset mi16
    jz short lbl56f
    sub ax, offset mi18
    jz short lbl6Cf
    sub ax,153h
    jz short lbl72f
    push word ptr ds:[6A04h]
    mov ax,23h
    push ax
    call mf25
    mov sp,bp
    push dx
    push ax
    mov ax,30h
lbl47b:
    mov dx,0F006h
    push dx
    push ax
    call mf33
    mov sp,bp
    jmp short lbl9Cf
    nop
lbl56f:
    push word ptr ds:[6A04h]
    mov ax,2h
    push ax
    call mf40
    mov sp,bp
    push dx
    push ax
    mov ax,2Eh
    jmp short lbl47b
lbl6Cf:
    mov ax,2Fh
    jmp short lbl8Ff
    nop
lbl72f:
    mov ax,164h
    push ax
    mov ax,165h
    push ax
    call mf53
    add sp,4h
    or ax,ax
    jz short lbl8Cf
    mov ax,2Ch
    jmp short lbl8Ff
    nop
lbl8Cf:
    mov ax,2Dh
lbl8Fb:
lbl8Ff:
    mov dx,0F006h
    push dx
    push ax
    call mf64
lbl99b:
    add sp,4h
lbl9Cf:
    mov ax,1h
    jmp near ptr lbl18Ef
lblA2f:
    mov ax,word ptr ds:[6A06h]
    sub ax, offset mi69
    jz short lblB2f
    sub ax, offset mi71
    jz short lblFCf
    jmp near ptr lbl18Cf
lblB2f:
    mov ax,28h
    mov dx,0F006h
    push dx
    push ax
    call mf78
    add sp,4h
    push word ptr ds:[6A04h]
    mov ax,165h
    push ax
    call mf83
    add sp,4h
    or ax,ax
    jnz short lblDCf
    mov ax,29h
    jmp short lbl8Fb
    nop
lblDCf:
    mov ax,0Ah
    push ax
    mov ax,155h
    push ax
    call mf94
    add sp,4h
    or ax,ax
    jnz short lblF6f
    mov ax,2Ah
    jmp short lbl8Fb
    nop
lblF6f:
    mov ax,2Bh
    jmp short lbl8Fb
    nop
lblFCf:
    push word ptr ds:[6A04h]
    mov ax,165h
    push ax
    call mf107
    add sp,4h
    or ax,ax
    jnz short lbl120f
    mov ax,5A14h
    push ax
    mov ax,3E2h
lbl117b:
    push ax
    call mf115
    jmp near ptr lbl99b
lbl120f:
    mov ax,0Ah
    push ax
    mov ax,155h
    push ax
    call mf121
    add sp,4h
    or ax,ax
    jnz short lbl182f
    cmp word ptr ds:[256h],14Fh
    jnz short lbl176f
    mov ax,0Ah
    push ax
    mov ax,155h
    push ax
    call mf131
    add sp,4h
    or ax,ax
    jnz short lbl176f
    mov ax,5A15h
    push ax
    mov ax,3E5h
    push ax
    call mf139
    add sp,4h
    mov ax,155h
    push ax
    mov ax,156h
    push ax
    mov ax,2h
    push ax
    call mf147
    add sp,6h
    jmp short lbl18Ef
lbl176f:
    call mf150
    push ax
    mov ax,3E4h
    jmp short lbl117b
    nop
lbl182f:
    mov ax,5A15h
    push ax
    mov ax,3E7h
    jmp short lbl117b
    nop
lbl18Cf:
    xor ax,ax
lbl18Ef:
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
