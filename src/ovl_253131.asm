_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi3:NEAR
    EXTRN mi4:NEAR
    EXTRN md9:NEAR
    EXTRN mf29:FAR
    EXTRN mf35:FAR
    EXTRN mf41:FAR
    EXTRN mf42:FAR
    EXTRN mf47:FAR
    EXTRN mf48:FAR
    EXTRN mf53:FAR
    EXTRN mf61:FAR
    EXTRN mf79:FAR
    EXTRN mf88:FAR
    EXTRN mf98:FAR
    EXTRN mf102:FAR
    EXTRN mf102:FAR
    EXTRN mf102:FAR
    EXTRN mf102:FAR
    EXTRN mf102:FAR
    EXTRN mf102:FAR
    EXTRN mf102:FAR
    EXTRN mf102:FAR
    EXTRN mf102:FAR
    EXTRN mf102:FAR
    EXTRN mf102:FAR
mnem_unit:
    push bp
    mov bp,sp
    mov ax,word ptr [bp+6h]
    sub ax, offset mi3
    cmp ax, offset mi4
    jna short lbl11f
    jmp near ptr lblF9f
lbl11f:
    add ax,ax
    xchg ax,bx
    jmp word ptr cs:[bx+md9]
    nop
    xchg ax,di
    add byte ptr [bx+di-4700h],bh
    add byte ptr [bx+di+5400h],bh
    add word ptr [si+1h],dx
    push sp
    add word ptr [di+5400h],di
    add word ptr [si+1h],dx
    push sp
    add word ptr [si+1h],dx
    push sp
    add word ptr [si+1h],dx
    iret
    add byte ptr [bp+di+1h],al
    mov bp,0B800h
    or al,byte ptr [bx+si]
    push ax
    mov ax,132h
    push ax
    call mf29
    mov sp,bp
    mov ax,1h
lbl4Eb:
    mov dx,0F027h
    push dx
    push ax
    call mf35
    mov sp,bp
    jmp near ptr lblF9f
    nop
    xor ax,ax
    jmp short lbl4Eb
    call mf41
    call mf42
    mov byte ptr ds:[3480h],0h
    jmp near ptr lblF9f
    cmp byte ptr ds:[3480h],0h
    jnz short lblD1f
    call mf47
    call mf48
    mov ax,0Ah
    push ax
    mov ax,137h
    push ax
    call mf53
    mov sp,bp
    or ax,ax
    jz short lblCCf
    mov ax,137h
    push ax
    mov ax,138h
    push ax
    call mf61
    mov sp,bp
    or ax,ax
    jz short lblB8f
    xor ax,ax
    push ax
    push ax
    mov ax,0Bh
    push ax
    mov ax,0B3Bh
    jmp short lblC3f
lblB8f:
    xor ax,ax
    push ax
    push ax
    mov ax,0Bh
    push ax
    mov ax,0B30h
lblC3f:
    push ax
    call mf79
    add sp,8h
lblCCf:
    mov byte ptr ds:[3480h],1h
lblD1f:
    mov ax,3h
    push ax
    mov ax,0h
    mov cx,32ECh
    push cx
    push ax
    call mf88
    add sp,6h
    jmp short lblFBf
    nop
    mov ax,2h
    push ax
    mov ax,24h
    mov cx,32ECh
    push cx
    push ax
    call mf98
lblF9f:
    xor ax,ax
lblFBf:
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
