_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mfd3:FAR
    EXTRN md10b:NEAR
    EXTRN mfc7:FAR
    EXTRN mfa0:FAR
    EXTRN mfdf:FAR
    EXTRN mi30:NEAR
    EXTRN mfec:FAR
    EXTRN mf6a:FAR
    EXTRN mi3b:NEAR
    EXTRN mf127:FAR
    EXTRN mf90:FAR
    EXTRN mfb4:FAR
    EXTRN md110:NEAR
    EXTRN md11a:NEAR
    EXTRN mi26:NEAR
    EXTRN md115:NEAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,4h
    mov word ptr [bp-2h],0h
    mov word ptr [bp-4h],0h
lbl10b:
    mov ax,word ptr ds:[6A04h]
    mov es, ds:[5B34h]
    mov bx,word ptr [bp-4h]
    cmp word ptr es:[bx],ax
    db 74h, 0Eh ; override
    inc word ptr [bp-2h]
    add word ptr [bp-4h],0Ah
    cmp word ptr [bp-4h], offset mi26
    jc short lbl10b
lbl2Df:
    mov ax,word ptr [bp+6h]
    sub ax, offset mi30
    jz short lbl38f
    db 0E9h, 00h, 01h ; override
lbl38f:
    mov ax,word ptr ds:[6A06h]
    cmp ax, offset mi3b
    jnz short lbl43f
    db 0E9h, 0EFh, 00h ; override
lbl43f:
    jna short lbl48f
    db 0E9h, 0F0h, 00h ; override
lbl48f:
    cmp al,2Ch
    jz short lbl78f
    ja short lbl5Af
    sub al,8h
    jz short lbl62f
    sub al,0Bh
lbl54b:
    jz short lbl78f
    db 0E9h, 0DFh, 00h ; override
    nop
lbl5Af:
    sub al,3Ah
    jz short lbl78f
    sub al,0Ah
    jmp short lbl54b
lbl62f:
    mov ax,18h
lbl65b:
    mov dx,0F04Ch
    push dx
    push ax
    call mf6a
    add sp,4h
lbl72b:
    mov ax,1h
    db 0E9h, 0C2h, 00h ; override
lbl78f:
    cmp word ptr ds:[6A04h],1E3h
    jnz short lblFAf
    cmp word ptr ds:[256h],1DEh
    jnz short lblFAf
    mov ax,16h
    mov dx,0F04Ch
    push dx
    push ax
    call mf90
    add sp,4h
    mov ax,0Ah
    push ax
    mov ax,1DEh
    push ax
    call mfa0
    add sp,4h
    or ax,ax
    jnz short lblCFf
    mov ax,0Ah
    push ax
    mov ax,1DEh
    push ax
    call mfb4
    add sp,4h
    xor ax,ax
    push ax
    mov ax,1h
    push ax
    mov ax,0Fh
    push ax
    call mfc7
    add sp,6h
lblCFf:
    mov ax,0Bh
    push ax
    call mfd3
    add sp,2h
    mov ax,1388h
    push ax
    call mfdf
    add sp,2h
    mov byte ptr ds:[3AF2h],1h
    call mfec
    mov byte ptr ds:[371h],1h
    jmp near ptr lbl72b
    nop
lblFAf:
    mov es, ds:[5B34h]
    mov bx,word ptr [bp-2h]
    mov ax,bx
    add bx,bx
    add bx,bx
    add bx,ax
    add bx,bx
    push word ptr es:[bx+md10b]
    push word ptr es:[bx+md110]
    push word ptr es:[bx+md115]
    push word ptr es:[bx+md11a]
    mov ax,17h
    mov dx,0F04Ch
    push dx
    push ax
    call mf127
    add sp,0Ch
    jmp near ptr lbl72b
lbl132f:
    mov ax,19h
    jmp near ptr lbl65b
lbl138f:
    xor ax,ax
lbl13Af:
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
