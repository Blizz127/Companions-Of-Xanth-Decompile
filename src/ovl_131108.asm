_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi3:NEAR
    EXTRN mi4:NEAR
    EXTRN mf32:FAR
    EXTRN mf38:FAR
    EXTRN mf47:FAR
    EXTRN mf70:FAR
    EXTRN mf87:FAR
    EXTRN mf99:FAR
    EXTRN mf102:FAR
    EXTRN mf113:FAR
    EXTRN mf131:FAR
    EXTRN mf138:FAR
    EXTRN mf146:FAR
    EXTRN mf148:FAR
    EXTRN mf152:FAR
    EXTRN mf159:FAR
    EXTRN mf168:FAR
    EXTRN mf172:FAR
    EXTRN mf172:FAR
    EXTRN mf172:FAR
    EXTRN mf172:FAR
    EXTRN mf172:FAR
    EXTRN mf172:FAR
    EXTRN mf172:FAR
    EXTRN mf172:FAR
    EXTRN mf172:FAR
    EXTRN mf172:FAR
    EXTRN mf172:FAR
    EXTRN mf172:FAR
    EXTRN mf172:FAR
    EXTRN mf172:FAR
    EXTRN mf172:FAR
mnem_unit:
    push bp
    mov bp,sp
    mov ax,word ptr [bp+6h]
    sub ax, offset mi3
    cmp ax, offset mi4
    jna short lbl11f
    jmp near ptr lbl1C1f
lbl11f:
    add ax,ax
    xchg ax,bx
    jmp word ptr cs:[bx+28Eh]
    nop
    scasb
    add ah,dh
    add ah,dh
    add ah,dh
    add dh,byte ptr [di]
    add al,0ECh
    add bh,dh
    add bh,byte ptr [bp+si]
    add si,word ptr [di]
    add al,35h
    add al,35h
    add al,35h
    add al,35h
    add al,35h
    add al,0B6h
    add sp,word ptr [si]
    add al,0B8h
    or ax,word ptr [bx+si]
    mov dx,0F00Fh
    push dx
    push ax
    call mf32
    mov sp,bp
    mov ax,9Ah
    push ax
    mov ax,9Bh
    push ax
    call mf38
    mov sp,bp
    or ax,ax
    jnz short lbl5Ff
    jmp near ptr lbl1C1f
lbl5Ff:
    mov ax,0Ch
lbl62b:
    mov dx,0F00Fh
    push dx
    push ax
    call mf47
    mov sp,bp
    jmp near ptr lbl1C1f
    nop
    mov ax,0Ah
    jmp short lbl62b
    nop
    cmp byte ptr ds:[6E5Ch],2h
    jz short lbl82f
    jmp near ptr lbl1C1f
lbl82f:
    inc word ptr ds:[2A4h]
    jmp near ptr lbl1C1f
    nop
    cmp word ptr ds:[2A4h],6h
    jnz short lbl96f
    mov ax,7h
    jmp short lbl62b
lbl96f:
    cmp word ptr ds:[2A4h],0Ch
    jnz short lblB6f
    mov ax,8h
    mov dx,0F00Fh
    push dx
    push ax
    call mf70
    mov sp,bp
    mov word ptr ds:[2A4h],1h
    jmp near ptr lbl1C1f
    nop
lblB6f:
    cmp word ptr ds:[2A4h],1Eh
    jz short lblC0f
    jmp near ptr lbl1C1f
lblC0f:
    mov ax,9h
    jmp short lbl62b
    nop
    cmp byte ptr ds:[2F2h],0h
    jnz short lbl103f
    mov ax,9Ah
    push ax
    mov ax,9Bh
    push ax
    call mf87
    mov sp,bp
    or ax,ax
    jz short lbl103f
    cmp byte ptr ds:[6E5Ch],2h
    jnz short lbl103f
    xor ax,ax
    push ax
    mov ax,9Ch
    push ax
    mov ax,9Bh
    push ax
    call mf99
    mov sp,bp
    mov byte ptr ds:[278Ah],1h
    call mf102
lbl103f:
    cmp byte ptr ds:[6E5Ch],2h
    jnz short lbl130f
    cmp byte ptr ds:[31Fh],0h
    jnz short lbl130f
    cmp byte ptr ds:[2F2h],0h
    jz short lbl130f
    mov ax,9Ah
    push ax
    mov ax,9Bh
    push ax
    call mf113
    mov sp,bp
    or ax,ax
    jz short lbl130f
    mov byte ptr ds:[31Fh],1h
lbl130f:
    cmp byte ptr ds:[6E5Ch],6h
    jz short lbl13Af
    jmp near ptr lbl1C1f
lbl13Af:
    dec word ptr ds:[2A4h]
    jmp near ptr lbl1C1f
    nop
    cmp byte ptr ds:[278Ah],0h
    jz short lbl19Bf
    mov byte ptr ds:[278Ah],0h
    cmp word ptr ds:[58h],0h
    jnz short lbl18Af
    cmp word ptr ds:[56h],1h
    jz short lbl18Af
    call mf131
    xor al,al
    push ax
    mov cx,20h
    push cx
    mov cx,563h
    push cx
    call mf138
    mov sp,bp
    xor al,al
    push ax
    mov ax,14h
    push ax
    mov ax,583h
    push ax
    call mf146
    mov sp,bp
    call mf148
lbl18Af:
    cmp byte ptr ds:[278Ch],0h
    jz short lbl19Bf
    mov byte ptr ds:[278Ch],0h
    call mf152
lbl19Bf:
    mov ax,2h
    push ax
    mov ax,48h
    mov cx,3384h
    push cx
    push ax
    call mf159
    mov sp,bp
    jmp short lbl1C3f
    mov ax,2h
    push ax
    mov ax,60h
    mov cx,3384h
    push cx
    push ax
    call mf168
lbl1C1f:
    xor ax,ax
lbl1C3f:
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
