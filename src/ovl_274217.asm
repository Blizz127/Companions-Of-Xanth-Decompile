_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi3:NEAR
    EXTRN mi4:NEAR
    EXTRN mf32:FAR
    EXTRN mf38:FAR
    EXTRN mf46:FAR
    EXTRN mf53:FAR
    EXTRN mf59:FAR
    EXTRN mf66:FAR
    EXTRN mf72:FAR
    EXTRN mf79:FAR
    EXTRN mf85:FAR
    EXTRN mf92:FAR
    EXTRN mf97:FAR
    EXTRN mf103:FAR
    EXTRN mf110:FAR
    EXTRN mf126:FAR
    EXTRN mf134:FAR
    EXTRN mf136:FAR
    EXTRN mf137:FAR
    EXTRN mf142:FAR
    EXTRN mf143:FAR
    EXTRN mf148:FAR
    EXTRN mf165:FAR
    EXTRN mf174:FAR
    EXTRN mf182:FAR
    EXTRN mf190:FAR
    EXTRN mf196:FAR
    EXTRN mf197:FAR
    EXTRN mf198:FAR
    EXTRN mf205:FAR
    EXTRN mf212:FAR
    EXTRN mf214:FAR
    EXTRN mf221:FAR
    EXTRN mf225:FAR
    EXTRN mf225:FAR
    EXTRN mf225:FAR
    EXTRN mf225:FAR
    EXTRN mf225:FAR
    EXTRN mf225:FAR
    EXTRN mf225:FAR
    EXTRN mf225:FAR
    EXTRN mf225:FAR
    EXTRN mf225:FAR
    EXTRN mf225:FAR
    EXTRN mf225:FAR
    EXTRN mf225:FAR
    EXTRN mf225:FAR
    EXTRN mf225:FAR
    EXTRN mf225:FAR
    EXTRN mf225:FAR
    EXTRN mf225:FAR
    EXTRN mf225:FAR
    EXTRN mf225:FAR
    EXTRN mf225:FAR
    EXTRN mf225:FAR
    EXTRN mf225:FAR
    EXTRN mf225:FAR
    EXTRN mf225:FAR
    EXTRN mf225:FAR
    EXTRN mf225:FAR
    EXTRN mf225:FAR
    EXTRN mf225:FAR
    EXTRN mf225:FAR
    EXTRN mf225:FAR
mnem_unit:
    push bp
    mov bp,sp
    mov ax,word ptr [bp+6h]
    sub ax, offset mi3
    cmp ax, offset mi4
    jna short lbl11f
    jmp near ptr lbl22Af
lbl11f:
    add ax,ax
    xchg ax,bx
    jmp word ptr cs:[bx+2E3h]
    nop
    add ax,0C103h
    add ax,cx
    add ax,cx
    add si,bx
    add al,0F3h
    add al,0E5h
    add ax,word ptr [bx]
    add al,0F3h
    add al,0F3h
    add al,0F3h
    add al,0F3h
    add al,0F3h
    add al,0F3h
    add al,19h
    add al,79h
    add al,7h
    add al,0B8h
    or al,byte ptr [bx+si]
    push ax
    mov ax,162h
    push ax
    call mf32
    mov sp,bp
    mov ax,162h
    push ax
    mov ax,9h
    push ax
    call mf38
    mov sp,bp
    or ax,ax
    jnz short lbl71f
    mov ax,162h
    push ax
    mov ax,165h
    push ax
    call mf46
    mov sp,bp
    or ax,ax
    jz short lblE6f
lbl71f:
    mov ax,3605h
    push ds
    push ax
    call mf53
    mov sp,bp
    mov ax,162h
    push ax
    mov ax,9h
    push ax
    call mf59
    mov sp,bp
    or ax,ax
    jz short lblBBf
    mov ax,3610h
    push ds
    push ax
    call mf66
    mov sp,bp
    mov ax,162h
    push ax
    mov ax,165h
    push ax
    call mf72
    mov sp,bp
    or ax,ax
    jz short lblBBf
    mov ax,361Ch
    push ds
    push ax
    call mf79
    mov sp,bp
lblBBf:
    mov ax,162h
    push ax
    mov ax,165h
    push ax
    call mf85
    mov sp,bp
    or ax,ax
    jz short lblDAf
    mov ax,3622h
    push ds
    push ax
    call mf92
    mov sp,bp
lblDAf:
    mov ax,3629h
    push ds
    push ax
    call mf97
    mov sp,bp
lblE6f:
    mov ax,3h
    mov dx,0F03Ch
lblECb:
    push dx
    push ax
    call mf103
lblF3b:
    mov sp,bp
    jmp near ptr lbl22Af
    mov ax,163h
    push ax
    mov ax,15Eh
    push ax
    call mf110
    mov sp,bp
    or ax,ax
    jz short lbl110f
    mov ax,1h
    jmp short lbl113f
lbl110f:
    mov ax,2h
lbl113f:
    mov dx,0F03Ch
    push dx
    push ax
    xor ax,ax
    jmp short lblECb
    mov ax,164h
    push ax
    mov ax,165h
    push ax
    call mf126
    mov sp,bp
    or ax,ax
    jnz short lbl132f
    jmp near ptr lbl22Af
lbl132f:
    mov ax,35FDh
    push ds
    push ax
    call mf134
    jmp short lblF3b
    call mf136
    call mf137
    mov byte ptr ds:[35FCh],0h
    jmp near ptr lbl22Af
    cmp byte ptr ds:[35FCh],0h
    jnz short lbl199f
    call mf142
    call mf143
    mov ax,163h
    push ax
    mov ax,15Eh
    push ax
    call mf148
    add sp,4h
    or ax,ax
    jnz short lbl180f
    push ax
    push ax
    mov ax,0Ah
    push ax
    mov ax,0F71h
    jmp short lbl18Bf
lbl180f:
    xor ax,ax
    push ax
    push ax
    mov ax,8h
    push ax
    mov ax,0F8Bh
lbl18Bf:
    push ax
    call mf165
    add sp,8h
    mov byte ptr ds:[35FCh],1h
lbl199f:
    mov ax,3h
    push ax
    mov ax,0h
    mov cx,32BAh
    push cx
    push ax
    call mf174
    add sp,6h
    jmp short lbl22Cf
    nop
    mov ax,0Ah
    push ax
    mov ax,165h
    push ax
    call mf182
    add sp,4h
    or ax,ax
    jz short lbl219f
    mov ax,0Ah
    push ax
    mov ax,165h
    push ax
    call mf190
    add sp,4h
    cmp word ptr ds:[56h],1h
    jz short lbl219f
    cmp word ptr ds:[58h],0h
    jnz short lbl219f
    call mf196
    call mf197
    call mf198
    xor al,al
    push ax
    mov ax,10h
    push ax
    mov ax,0F7Bh
    push ax
    call mf205
    add sp,6h
    xor ax,ax
    push ax
    push ax
    mov ax,164h
    push ax
    call mf212
    add sp,6h
    call mf214
lbl219f:
    mov ax,4h
    push ax
    mov ax,24h
    mov cx,32BAh
    push cx
    push ax
    call mf221
lbl22Af:
    xor ax,ax
lbl22Cf:
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
