_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mfd3:FAR
    EXTRN mf60:FAR
    EXTRN mf4c:FAR
    EXTRN mfef:FAR
    EXTRN mfce:FAR
    EXTRN mf12:FAR
    EXTRN md31:NEAR
    EXTRN mf57:FAR
    EXTRN mf80:FAR
    EXTRN mfb2:FAR
    EXTRN mf68:FAR
    EXTRN mfc0:FAR
    EXTRN mfa4:FAR
    EXTRN mf78:FAR
    EXTRN mfd8:FAR
    EXTRN mf96:FAR
    EXTRN mi26:NEAR
    EXTRN mf70:FAR
    EXTRN mf88:FAR
    EXTRN mie4:NEAR
    EXTRN mff4:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,2h
    mov ax,word ptr ds:[6A1Ah]
    mov word ptr [bp-2h],ax
    mov word ptr ds:[6A1Ah],1h
    call mf12
    mov word ptr ds:[5E2Eh],0h
    mov word ptr ds:[337Eh],1h
    mov ax,word ptr [bp+6h]
    cmp ax, offset mi26
    jna short lbl2Ef
    db 0E9h, 0A5h, 00h ; override
lbl2Ef:
    add ax,ax
    xchg ax,bx
    jmp word ptr cs:[bx+md31]
    db 4Ch, 00h, 68h, 00h, 70h, 00h, 78h, 00h, 80h, 00h, 88h, 00h, 90h, 00h, 9Eh, 00h
    db 0ACh, 00h, 0BAh, 00h, 0C8h, 00h
    call mf4c
    mov word ptr ds:[5E2Eh],1h
    call mf57
    or ax,ax
    jnz short lblD3f
    call mf60
    jmp short lblD3f
    nop
    call mf68
    jmp short lblD3f
    nop
    call mf70
    jmp short lblD3f
    nop
    call mf78
    jmp short lblD3f
    nop
    call mf80
    jmp short lblD3f
    nop
    call mf88
    jmp short lblD3f
    nop
    mov word ptr ds:[337Eh],2h
    call mf96
    jmp short lblD3f
    nop
    mov word ptr ds:[337Eh],3h
    call mfa4
    jmp short lblD3f
    nop
    mov word ptr ds:[337Eh],4h
    call mfb2
    jmp short lblD3f
    nop
    mov word ptr ds:[337Eh],5h
    call mfc0
    jmp short lblD3f
    nop
    mov word ptr ds:[337Eh],6h
    call mfce
lblD3f:
    call mfd3
    call mfd8
    mov ax,word ptr [bp+6h]
    or ax,ax
    jz short lblF4f
    sub ax, offset mie4
    jl short lblEFf
    jo short lblEFf
    dec ax
    dec ax
    jng short lblF4f
lblEFf:
    call mfef
lblF4f:
    call mff4
    mov ax,word ptr [bp-2h]
    mov word ptr ds:[6A1Ah],ax
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
