_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi9:NEAR
    EXTRN mfef:FAR
    EXTRN mic:NEAR
    EXTRN mf156:FAR
    EXTRN mf140:FAR
    EXTRN mfd6:FAR
    EXTRN mf10c:FAR
    EXTRN mf127:FAR
    EXTRN md17:NEAR
    EXTRN mfb5:FAR
    EXTRN mfcf:FAR
    EXTRN mff4:FAR
    EXTRN mfa3:FAR
    EXTRN mfdb:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,8h
    mov ax,word ptr [bp+6h]
    sub ax, offset mi9
    cmp ax, offset mic
    jna short lbl14f
    db 0E9h, 47h, 01h ; override
lbl14f:
    add ax,ax
    xchg ax,bx
    jmp word ptr cs:[bx+md17]
    db 57h, 00h, 0C7h, 00h, 0C7h, 00h, 0C7h, 00h, 74h, 01h, 74h, 01h, 0D9h, 00h, 0EFh, 00h
    db 74h, 01h, 74h, 01h, 74h, 01h, 74h, 01h, 74h, 01h, 74h, 01h, 01h, 01h, 63h, 01h
    db 0EFh, 00h
    cmp word ptr ds:[2A6h],2h
    jl short lbl4Cf
    mov ax,26F9h
    mov dx,ds
    jmp short lbl52f
lbl4Cf:
    mov ax,4h
    mov dx,0F00Eh
lbl52f:
    mov word ptr [bp-4h],ax
    mov word ptr [bp-2h],dx
    cmp word ptr ds:[2A6h],0h
    jnz short lbl66f
    mov ax,2706h
    mov dx,ds
    jmp short lbl69f
lbl66f:
    xor ax,ax
    cwd
lbl69f:
    mov word ptr [bp-8h],ax
    mov word ptr [bp-6h],dx
    push word ptr [bp-2h]
    push word ptr [bp-4h]
    push dx
    push ax
    cmp word ptr ds:[2A6h],2h
    jl short lbl84f
    mov ax,270Fh
    jmp short lbl87f
    nop
lbl84f:
    mov ax,270Ch
lbl87f:
    push ds
    push ax
    cmp word ptr ds:[2A6h],0h
    jnz short lbl96f
    mov ax,2h
    jmp short lbl99f
    nop
lbl96f:
    mov ax,3h
lbl99f:
    mov dx,0F00Eh
    push dx
    push ax
    mov ax,1h
    push dx
    push ax
    call mfa3
    add sp,14h
    jmp near ptr lbl15Bf
    xor ax,ax
    mov dx,0F00Eh
    push dx
    push ax
    call mfb5
lblBAb:
    add sp,4h
    jmp near ptr lbl15Bf
    cmp word ptr ds:[2A6h],0h
    jz short lblCAf
    jmp near ptr lbl15Bf
lblCAf:
    mov ax,26EFh
    push ds
    push ax
    call mfcf
    jmp short lblBAb
    call mfd6
    call mfdb
    mov byte ptr ds:[26EEh],0h
    jmp short lbl15Bf
    nop
    cmp byte ptr ds:[26EEh],0h
    jnz short lbl134f
    call mfef
    call mff4
    cmp word ptr ds:[2A6h],2h
    jnl short lbl114f
    xor ax,ax
    push ax
    push ax
    mov ax,6h
    push ax
    mov ax,484h
    push ax
    call mf10c
    add sp,8h
lbl114f:
    cmp word ptr ds:[2A6h],1h
    jnl short lbl12Ff
    xor ax,ax
    push ax
    push ax
    mov ax,6h
    push ax
    mov ax,47Eh
    push ax
    call mf127
    add sp,8h
lbl12Ff:
    mov byte ptr ds:[26EEh],1h
lbl134f:
    mov ax,2h
    push ax
    mov ax,0h
    mov cx,32CEh
    push cx
    push ax
    call mf140
    add sp,6h
    jmp short lbl15Df
    mov ax,2h
    push ax
    mov ax,18h
    mov cx,32CEh
    push cx
    push ax
    call mf156
lbl15Bf:
    xor ax,ax
lbl15Df:
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
