_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf3d:FAR
    EXTRN mfc8:FAR
    EXTRN mf92:FAR
    EXTRN mf66:FAR
    EXTRN mi7a:NEAR
    EXTRN mfaa:FAR
    EXTRN mfd4:FAR
    EXTRN mieb:NEAR
    EXTRN mf51:FAR
    EXTRN mf29:FAR
    EXTRN mf72:FAR
    EXTRN mf59:FAR
    EXTRN mf9e:FAR
    EXTRN mi3:NEAR
    EXTRN mi31:NEAR
    EXTRN mfbc:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp, offset mi3
    push si
    push di
    mov ax,word ptr ds:[6DF2h]
    jmp near ptr lblEBf
    jmp near ptr lbl124f
    cmp word ptr ds:[411Ch],0h
    jnz short lbl1Cf
    jmp near ptr lbl56f
lbl1Cf:
    mov word ptr ds:[411Ch],0h
    mov si,0h
    jmp near ptr lbl48f
lbl28b:
    push si
    call mf29
    add sp,2h
    cmp ax, offset mi31
    jnz short lbl39f
    jmp near ptr lbl45f
lbl39f:
    mov ax,0FCh
    push ax
    call mf3d
    add sp,2h
lbl45f:
    add si,1h
lbl48f:
    cmp si,word ptr ds:[62AAh]
    jnl short lbl51f
    jmp near ptr lbl28b
lbl51f:
    call mf51
lbl56f:
    jmp near ptr lbl124f
    call mf59
    mov ax,139h
    mov dx,28h
    push dx
    push ax
    call mf66
    add sp,4h
lbl6Eb:
    mov ax,3Fh
    push ax
    call mf72
    add sp,2h
    cmp ax, offset mi7a
    jz short lbl82f
    jmp near ptr lbl85f
lbl82f:
    jmp near ptr lbl6Eb
lbl85f:
    jmp near ptr lbl124f
    mov ax,word ptr ds:[6DF2h]
    add ax,0ADh
    and ax,0FFh
    push ax
    call mf92
    add sp,2h
    mov ax,7Bh
    push ax
    call mf9e
    add sp,2h
    mov ax,0h
    push ax
    call mfaa
    add sp,2h
    mov ax,word ptr ds:[6DF2h]
    add ax,0ADh
    and ax,0FFh
    push ax
    call mfbc
    add sp,2h
    mov ax,79h
    push ax
    call mfc8
    add sp,2h
    mov ax,0h
    push ax
    call mfd4
    add sp,2h
    jmp near ptr lbl124f
    mov word ptr ds:[411Eh],0h
    jmp near ptr lbl124f
    jmp near ptr lbl124f
lblEBf:
    cmp ax, offset mieb
    jna short lblF3f
    jmp near ptr lbl124f
lblF3f:
    shl ax,1
    mov bx,ax
    jmp word ptr cs:[bx-6399h]
    db 7Ah, 9Bh, 7Dh, 9Bh, 0C4h, 9Bh, 0F3h, 9Bh, 0F3h, 9Bh, 0F3h, 9Bh, 0F3h, 9Bh, 0F3h, 9Bh
    db 0F3h, 9Bh, 0F3h, 9Bh, 0F3h, 9Bh, 0F3h, 9Bh, 0F3h, 9Bh, 0F3h, 9Bh, 0F3h, 9Bh, 0F3h, 9Bh
    db 0F3h, 9Bh, 0F3h, 9Bh, 0F3h, 9Bh, 4Ah, 9Ch
lbl124f:
    add word ptr ds:[6DF2h],1h
    pop di
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
