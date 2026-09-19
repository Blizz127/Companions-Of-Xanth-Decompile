_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf56:FAR
    EXTRN mi9:NEAR
    EXTRN mic:NEAR
    EXTRN mfd5:FAR
    EXTRN mf82:FAR
    EXTRN mfe9:FAR
    EXTRN mfff:FAR
    EXTRN mfee:FAR
    EXTRN md17:NEAR
    EXTRN mfc5:FAR
    EXTRN mf9e:FAR
    EXTRN mfd0:FAR
    EXTRN mfae:FAR
    EXTRN mf46:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,4h
    mov ax,word ptr [bp+6h]
    sub ax, offset mi9
    cmp ax, offset mic
    jna short lbl14f
    db 0E9h, 0FCh, 00h ; override
lbl14f:
    add ax,ax
    xchg ax,bx
    jmp word ptr cs:[bx+md17]
    db 3Eh, 00h, 62h, 00h, 62h, 00h, 62h, 00h, 10h, 01h, 10h, 01h, 8Eh, 00h, 0D0h, 00h
    db 10h, 01h, 10h, 01h, 10h, 01h, 10h, 01h, 10h, 01h, 10h, 01h, 0E2h, 00h, 10h, 01h
    db 0D0h, 00h
    mov ax,0Ah
    push ax
    mov ax,170h
    push ax
    call mf46
    add sp,4h
    mov ax,1h
    mov dx,0F03Fh
    push dx
    push ax
    call mf56
    add sp,4h
    jmp near ptr lbl110f
    nop
    cmp byte ptr ds:[363h],0h
    jz short lbl6Ef
    xor ax,ax
    cwd
    jmp short lbl73f
lbl6Ef:
    mov ax,36C5h
    mov dx,ds
lbl73f:
    mov word ptr [bp-4h],ax
    mov word ptr [bp-2h],dx
    push dx
    push ax
    xor ax,ax
    mov dx,0F03Fh
    push dx
    push ax
    call mf82
    add sp,8h
    jmp near ptr lbl110f
    nop
    cmp byte ptr ds:[363h],0h
    jnz short lbl110f
    mov byte ptr ds:[363h],1h
    mov ax,1388h
    push ax
    call mf9e
    add sp,2h
    mov ax,5A18h
    push ax
    mov ax,3E8h
    push ax
    call mfae
    add sp,4h
    cmp word ptr ds:[2D8h],0Ah
    jnz short lbl110f
    xor ax,ax
    push ax
    push ax
    mov ax,7h
    push ax
    call mfc5
    add sp,6h
    jmp short lbl110f
    nop
    call mfd0
    call mfd5
    mov byte ptr ds:[36C4h],0h
    jmp short lbl110f
    nop
    cmp byte ptr ds:[36C4h],0h
    jnz short lbl110f
    call mfe9
    call mfee
    xor ax,ax
    push ax
    push ax
    mov ax,14h
    push ax
    mov ax,0FB4h
    push ax
    call mfff
    add sp,8h
    mov ax,1h
    mov byte ptr ds:[36C4h],al
    jmp short lbl112f
    nop
lbl110f:
    xor ax,ax
lbl112f:
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
