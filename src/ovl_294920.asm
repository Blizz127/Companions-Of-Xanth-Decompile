_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi6:NEAR
    EXTRN mf10e:FAR
    EXTRN mi9:NEAR
    EXTRN mf78:FAR
    EXTRN mf62:FAR
    EXTRN mf8a:FAR
    EXTRN mfa9:FAR
    EXTRN mf44:FAR
    EXTRN mfd3:FAR
    EXTRN mf53:FAR
    EXTRN mff9:FAR
    EXTRN mf124:FAR
    EXTRN mfbd:FAR
    EXTRN mfc2:FAR
    EXTRN mfe2:FAR
    EXTRN mfa4:FAR
mnem_unit:
    push bp
    mov bp,sp
    mov ax,word ptr [bp+6h]
    sub ax, offset mi6
    cmp ax, offset mi9
    jna short lbl11f
    jmp near ptr lbl129f
lbl11f:
    add ax,ax
    xchg ax,bx
    jmp word ptr cs:[bx+552h]
    nop
    db 74h, 05h, 0BAh, 05h, 0BAh, 05h, 0BAh, 05h, 61h, 06h, 61h, 06h, 61h, 06h, 0DCh, 05h
    db 61h, 06h, 61h, 06h, 61h, 06h, 61h, 06h, 61h, 06h, 61h, 06h, 0EEh, 05h, 50h, 06h
    db 0DCh, 05h
    mov ax,0Ah
    push ax
    mov ax,18Dh
    push ax
    call mf44
    mov sp,bp
    mov ax,1h
    mov dx,0F02Bh
    push dx
    push ax
    call mf53
    mov sp,bp
    mov ax,0Eh
    push ax
    mov ax,190h
    push ax
    call mf62
    mov sp,bp
    or ax,ax
    jnz short lbl70f
    jmp near ptr lbl129f
lbl70f:
    mov ax,2h
lbl73b:
    mov dx,0F02Bh
    push dx
    push ax
    call mf78
    mov sp,bp
    jmp near ptr lbl129f
    mov ax,0Eh
    push ax
    mov ax,190h
    push ax
    call mf8a
    mov sp,bp
    or ax,ax
    jz short lbl9Af
    mov ax,38D4h
    jmp short lbl9Df
lbl9Af:
    mov ax,38D9h
lbl9Df:
    push ds
    push ax
    xor ax,ax
    jmp short lbl73b
    nop
    call mfa4
    call mfa9
    mov byte ptr ds:[38C6h],0h
    jmp short lbl129f
    nop
    cmp byte ptr ds:[38C6h],0h
    jnz short lbl105f
    call mfbd
    call mfc2
    xor ax,ax
    push ax
    push ax
    mov cx,26h
    push cx
    mov cx,114Ch
    push cx
    call mfd3
    mov sp,bp
    mov ax,0Eh
    push ax
    mov ax,190h
    push ax
    call mfe2
    mov sp,bp
    or ax,ax
    jz short lbl100f
    xor ax,ax
    push ax
    push ax
    mov ax,5h
    push ax
    mov ax,1147h
    push ax
    call mff9
    mov sp,bp
lbl100f:
    mov byte ptr ds:[38C6h],1h
lbl105f:
    mov ax,1h
    push ax
    mov ax,38C8h
    push ds
    push ax
    call mf10e
    mov sp,bp
    jmp short lbl12Bf
    nop
    mov ax,2h
    push ax
    mov ax,0h
    mov cx,32E8h
    push cx
    push ax
    call mf124
lbl129f:
    xor ax,ax
lbl12Bf:
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
