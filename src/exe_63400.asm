_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf116:FAR
    EXTRN mi6d:NEAR
    EXTRN mf136:FAR
    EXTRN mfa9:FAR
    EXTRN mff0:FAR
    EXTRN mf106:FAR
    EXTRN mf156:FAR
    EXTRN mfe0:FAR
    EXTRN mf61:FAR
    EXTRN mf92:FAR
    EXTRN mf146:FAR
    EXTRN mfd0:FAR
    EXTRN mf126:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,24h
    mov word ptr [bp-20h],0h
    mov word ptr [bp-1Eh],236Dh
    mov word ptr [bp-1Ch],1Ch
    mov word ptr [bp-1Ah],236Dh
    mov word ptr [bp-18h],2Eh
    mov word ptr [bp-16h],236Dh
    mov word ptr [bp-14h],4Ch
    mov word ptr [bp-12h],236Dh
    mov word ptr [bp-10h],64h
    mov word ptr [bp-0Eh],236Dh
    mov word ptr [bp-0Ch],7FAh
    mov word ptr [bp-0Ah],ds
    mov word ptr [bp-8h],78h
    mov word ptr [bp-6h],236Dh
    mov word ptr [bp-4h],809h
    mov word ptr [bp-2h],ds
    mov word ptr [bp-24h],1h
lbl57b:
    lea ax,word ptr [bp-20h]
    push ss
    push ax
    mov ax,80Ah
    push ds
    push ax
    call mf61
    add sp,8h
    mov word ptr [bp-22h],ax
    dec ax
    cmp ax, offset mi6d
    jna short lbl75f
    jmp near ptr lbl15Ef
lbl75f:
    add ax,ax
    xchg ax,bx
    jmp word ptr cs:[bx+6DB6h]
    nop
    db 0C2h, 6Dh, 0D8h, 6Dh, 0ECh, 6Dh, 0F6h, 6Dh, 00h, 6Eh, 36h, 6Eh
    mov ax,8h
    mov dx,0F001h
    push dx
    push ax
    call mf92
    add sp,4h
    mov ax,9h
    jmp near ptr lbl151f
    mov ax,1h
    push ax
    mov ax,80Fh
lblA7b:
    push ds
    push ax
    call mfa9
    add sp,6h
    jmp near ptr lbl15Ef
    mov ax,1h
    push ax
    mov ax,81Ch
    jmp short lblA7b
    nop
    mov ax,1h
    push ax
    mov ax,829h
    jmp short lblA7b
    nop
    mov ax,0Ah
    mov dx,0F001h
    push dx
    push ax
    call mfd0
    add sp,4h
    mov ax,0Bh
    mov dx,0F001h
    push dx
    push ax
    call mfe0
    add sp,4h
    mov ax,0Ch
    mov dx,0F001h
    push dx
    push ax
    call mff0
    add sp,4h
    mov ax,0Dh
    jmp short lbl151f
    nop
    mov ax,0Eh
    mov dx,0F001h
    push dx
    push ax
    call mf106
    add sp,4h
    mov ax,0Fh
    mov dx,0F001h
    push dx
    push ax
    call mf116
    add sp,4h
    mov ax,10h
    mov dx,0F001h
    push dx
    push ax
    call mf126
    add sp,4h
    mov ax,11h
    mov dx,0F001h
    push dx
    push ax
    call mf136
    add sp,4h
    mov ax,12h
    mov dx,0F001h
    push dx
    push ax
    call mf146
    add sp,4h
    mov ax,13h
lbl151f:
    mov dx,0F001h
    push dx
    push ax
    call mf156
    add sp,4h
lbl15Ef:
    cmp word ptr [bp-22h],7h
    jz short lbl167f
    jmp near ptr lbl57b
lbl167f:
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
