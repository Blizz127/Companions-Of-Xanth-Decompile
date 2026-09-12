_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi2:NEAR
    EXTRN mi11:NEAR
    EXTRN mf22:FAR
    EXTRN mf33:FAR
    EXTRN mi41:NEAR
    EXTRN mf52:FAR
    EXTRN mf62:FAR
    EXTRN mf72:FAR
    EXTRN mf82:FAR
    EXTRN mf92:FAR
    EXTRN mf102:FAR
    EXTRN mf108:FAR
    EXTRN mf108:FAR
    EXTRN mf108:FAR
    EXTRN mf108:FAR
    EXTRN mf108:FAR
    EXTRN mf108:FAR
    EXTRN mf108:FAR
    EXTRN mf108:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp, offset mi2
    push si
    push di
    mov word ptr [bp-4h],0h
    jmp near ptr lbl5Df
lbl11b:
    mov bx,word ptr [bp-4h]
    mov es, ds:[5B36h]
    mov al,byte ptr es:[bx+1A6h]
    cbw
    cmp ax, offset mi11
    jnz short lbl26f
    jmp near ptr lbl41f
lbl26f:
    mov ax,0h
    push ax
    mov ax,10Ah
    mov dx,2E8Eh
    push dx
    push ax
    mov ax,word ptr [bp-4h]
    push ax
    call mf22
    add sp,8h
    jmp near ptr lbl59f
lbl41f:
    mov ax,0h
    push ax
    mov ax,0FCh
    mov dx,2E8Eh
    push dx
    push ax
    mov ax,word ptr [bp-4h]
    push ax
    call mf33
    add sp,8h
lbl59f:
    add word ptr [bp-4h],1h
lbl5Df:
    cmp word ptr [bp-4h],12h
    jnl short lbl66f
    jmp near ptr lbl11b
lbl66f:
    mov al,byte ptr ds:[5E7Bh]
    cbw
    cmp ax, offset mi41
    jnz short lbl72f
    jmp near ptr lbl102f
lbl72f:
    mov ax,0h
    push ax
    mov ax,118h
    mov dx,2E8Eh
    push dx
    push ax
    mov ax,0Ch
    push ax
    call mf52
    add sp,8h
    mov ax,0h
    push ax
    mov ax,126h
    mov dx,2E8Eh
    push dx
    push ax
    mov ax,0Fh
    push ax
    call mf62
    add sp,8h
    mov ax,0h
    push ax
    mov ax,134h
    mov dx,2E8Eh
    push dx
    push ax
    mov ax,10h
    push ax
    call mf72
    add sp,8h
    mov ax,0h
    push ax
    mov ax,142h
    mov dx,2E8Eh
    push dx
    push ax
    mov ax,0Eh
    push ax
    call mf82
    add sp,8h
    mov ax,0h
    push ax
    mov ax,150h
    mov dx,2E8Eh
    push dx
    push ax
    mov ax,11h
    push ax
    call mf92
    add sp,8h
    mov ax,0h
    push ax
    mov ax,15Eh
    mov dx,2E8Eh
    push dx
    push ax
    mov ax,0Dh
    push ax
    call mf102
    add sp,8h
lbl102f:
    pop di
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
