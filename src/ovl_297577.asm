_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf56:FAR
    EXTRN mfc1:FAR
    EXTRN mfd5:FAR
    EXTRN mfdd:FAR
    EXTRN mf14a:FAR
    EXTRN mff5:FAR
    EXTRN mf90:FAR
    EXTRN mf46:FAR
    EXTRN mi9:NEAR
    EXTRN mf11d:FAR
    EXTRN mf131:FAR
    EXTRN mic:NEAR
    EXTRN mf107:FAR
    EXTRN mf66:FAR
    EXTRN md17:NEAR
    EXTRN mf160:FAR
    EXTRN mfe2:FAR
    EXTRN mffa:FAR
    EXTRN mfa3:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,4h
    mov ax,word ptr [bp+6h]
    sub ax, offset mi9
    cmp ax, offset mic
    jna short lbl14f
    db 0E9h, 51h, 01h ; override
lbl14f:
    add ax,ax
    xchg ax,bx
    jmp word ptr cs:[bx+md17]
    db 67h, 00h, 0C5h, 00h, 0C5h, 00h, 0C5h, 00h, 8Eh, 01h, 0D7h, 00h, 8Eh, 01h, 0F3h, 00h
    db 8Eh, 01h, 8Eh, 01h, 8Eh, 01h, 8Eh, 01h, 8Eh, 01h, 8Eh, 01h, 17h, 01h, 7Dh, 01h
    db 0F3h, 00h
    mov ax,0Ah
    push ax
    mov ax,193h
    push ax
    call mf46
    add sp,4h
    mov ax,1h
    mov dx,0F046h
    push dx
    push ax
    call mf56
    add sp,4h
    mov ax,0Ah
    push ax
    mov ax,195h
    push ax
    call mf66
    add sp,4h
    or ax,ax
    jz short lbl7Af
    mov ax,38EFh
    mov dx,ds
    jmp short lbl80f
    nop
lbl7Af:
    mov ax,3h
    mov dx,0F046h
lbl80f:
    mov word ptr [bp-4h],ax
    mov word ptr [bp-2h],dx
    push dx
    push ax
    mov ax,2h
    mov dx,0F046h
    push dx
    push ax
    call mf90
    add sp,8h
    jmp near ptr lbl165f
    nop
    xor ax,ax
    mov dx,0F046h
    push dx
    push ax
    call mfa3
    add sp,4h
    jmp near ptr lbl165f
    cmp byte ptr ds:[36Ch],0h
    jz short lblB8f
    jmp near ptr lbl165f
lblB8f:
    mov ax,1h
    push ax
    push ax
    mov ax,8104h
    push ax
    call mfc1
    jmp near ptr lbl165f
    nop
    xor ax,ax
    push ax
    mov ax,1h
    push ax
    mov ax,8104h
    push ax
    call mfd5
    add sp,6h
    call mfdd
    call mfe2
    mov byte ptr ds:[38EEh],0h
    jmp short lbl165f
    cmp byte ptr ds:[38EEh],0h
    jnz short lbl13Ef
    call mff5
    call mffa
    mov ax,0Ah
    push ax
    mov ax,195h
    push ax
    call mf107
    add sp,4h
    or ax,ax
    jnz short lbl139f
    push ax
    push ax
    mov cx,4h
    push cx
    mov cx,1175h
    push cx
    call mf11d
    add sp,8h
    xor ax,ax
    push ax
    push ax
    mov ax,6h
    push ax
    mov ax,1179h
    push ax
    call mf131
    add sp,8h
lbl139f:
    mov byte ptr ds:[38EEh],1h
lbl13Ef:
    mov ax,2h
    push ax
    mov ax,0h
    mov cx,32A5h
    push cx
    push ax
    call mf14a
    add sp,6h
    jmp short lbl167f
    mov ax,2h
    push ax
    mov ax,18h
    mov cx,32A5h
    push cx
    push ax
    call mf160
lbl165f:
    xor ax,ax
lbl167f:
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
