_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf6:FAR
    EXTRN mf13:FAR
    EXTRN mf24:FAR
    EXTRN mf31:FAR
    EXTRN mf39:FAR
    EXTRN md51:NEAR
    EXTRN mf56:FAR
    EXTRN mf63:FAR
    EXTRN mf71:FAR
    EXTRN mf78:FAR
    EXTRN mf85:FAR
    EXTRN mf95:FAR
    EXTRN mf102:FAR
    EXTRN mf109:FAR
    EXTRN mf116:FAR
    EXTRN mf123:FAR
    EXTRN mf131:FAR
    EXTRN mf138:FAR
    EXTRN mf146:FAR
    EXTRN mf152:FAR
    EXTRN mf159:FAR
    EXTRN mf167:FAR
    EXTRN mf176:FAR
    EXTRN mf183:FAR
    EXTRN mf194:FAR
    EXTRN mf202:FAR
    EXTRN mf210:FAR
    EXTRN mf214:FAR
    EXTRN mf214:FAR
    EXTRN mf214:FAR
    EXTRN mf214:FAR
    EXTRN mf214:FAR
    EXTRN mf214:FAR
    EXTRN mf214:FAR
    EXTRN mf214:FAR
    EXTRN mf214:FAR
    EXTRN mf214:FAR
    EXTRN mf214:FAR
    EXTRN mf214:FAR
    EXTRN mf214:FAR
    EXTRN mf214:FAR
    EXTRN mf214:FAR
    EXTRN mf214:FAR
    EXTRN mf214:FAR
    EXTRN mf214:FAR
    EXTRN mf214:FAR
    EXTRN mf214:FAR
    EXTRN mf214:FAR
    EXTRN mf214:FAR
    EXTRN mf214:FAR
    EXTRN mf214:FAR
    EXTRN mf214:FAR
    EXTRN mf214:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,2h
    mov ax,11h
    push ax
    push word ptr ds:[6A02h]
    call mf6
    add sp,4h
    or ax,ax
    jnz short lbl36f
    mov ax,1h
    push ax
    push word ptr ds:[6A02h]
    call mf13
    add sp,4h
    or ax,ax
    jnz short lbl36f
    mov word ptr [bp-2h],6Fh
    jmp short lbl3Bf
    nop
lbl36f:
    mov word ptr [bp-2h],69h
lbl3Bf:
    mov ax,0Ch
    push ax
    push word ptr ds:[6A04h]
    call mf24
    add sp,4h
    or ax,ax
    jnz short lbl7Cf
    push word ptr ds:[6A02h]
    mov ax,2h
    push ax
    call mf31
    add sp,4h
    push dx
    push ax
    push word ptr [bp-2h]
    push word ptr ds:[6A04h]
    mov ax,2h
    push ax
    call mf39
    add sp,4h
    push dx
    push ax
    mov ax,11h
    jmp near ptr lbl22Af
lbl7Cf:
    mov es, ds:[5AB8h]
    mov bx,word ptr ds:[6A02h]
    mov ax,bx
    add bx,bx
    add bx,ax
    add bx,bx
    cmp byte ptr es:[bx+md51],1h
    jnz short lblCCf
    push word ptr ds:[6A04h]
    mov ax,2h
    push ax
    call mf56
    add sp,4h
    push dx
    push ax
    push word ptr ds:[6A02h]
    mov ax,12h
    push ax
    call mf63
    add sp,4h
    push dx
    push ax
    mov ax,12h
    mov dx,0F029h
    push dx
    push ax
    call mf71
    add sp,0Ch
    jmp near ptr lbl234f
    nop
lblCCf:
    mov ax,11h
    push ax
    push word ptr ds:[6A02h]
    call mf78
    add sp,4h
    or ax,ax
    jz short lbl11Cf
    mov ax,0Eh
    push ax
    push word ptr ds:[6A02h]
    call mf85
    add sp,4h
    or ax,ax
    jnz short lbl11Cf
    mov ax,1DB6h
    push ds
    push ax
    push word ptr ds:[6A02h]
    mov ax,52h
    push ax
    call mf95
    add sp,8h
    push dx
    push ax
    mov ax,1DBAh
    push ds
lbl10Fb:
    push ax
    call mf102
    add sp,8h
    jmp near ptr lbl234f
    nop
lbl11Cf:
    mov ax,11h
    push ax
    push word ptr ds:[6A02h]
    call mf109
    add sp,4h
    or ax,ax
    jnz short lbl190f
    mov ax,0Bh
    push ax
    push word ptr ds:[6A02h]
    call mf116
    add sp,4h
    or ax,ax
    jnz short lbl190f
    push word ptr ds:[6A02h]
    mov ax,2h
    push ax
    call mf123
    add sp,4h
    push dx
    push ax
    push word ptr [bp-2h]
    push word ptr ds:[6A04h]
    mov ax,2h
    push ax
    call mf131
    add sp,4h
    push dx
    push ax
    push word ptr ds:[258h]
    mov ax,12h
    push ax
    call mf138
    add sp,4h
    push dx
    push ax
    mov ax,13h
    mov dx,0F029h
    push dx
    push ax
    call mf146
    add sp,12h
    jmp near ptr lbl234f
lbl190f:
    mov ax,0Bh
    push ax
    push word ptr ds:[6A02h]
    call mf152
    add sp,4h
    or ax,ax
    jnz short lbl1D0f
    push word ptr ds:[6A02h]
    mov ax,2h
    push ax
    call mf159
    add sp,4h
    push dx
    push ax
    push word ptr [bp-2h]
    push word ptr ds:[6A04h]
    mov ax,2h
    push ax
    call mf167
    add sp,4h
    push dx
    push ax
    mov ax,14h
    jmp short lbl22Af
lbl1D0f:
    mov ax,1h
    push ax
    push word ptr ds:[6A04h]
    call mf176
    add sp,4h
    or ax,ax
    jnz short lbl200f
    push word ptr ds:[6A04h]
    mov ax,2h
    push ax
    call mf183
    add sp,4h
    push dx
    push ax
    mov ax,15h
    mov dx,0F029h
    push dx
    jmp near ptr lbl10Fb
lbl200f:
    push word ptr ds:[6A02h]
    mov ax,2h
    push ax
    call mf194
    add sp,4h
    push dx
    push ax
    push word ptr [bp-2h]
    push word ptr ds:[6A04h]
    mov ax,2h
    push ax
    call mf202
    add sp,4h
    push dx
    push ax
    mov ax,18h
lbl22Af:
    mov dx,0F029h
    push dx
    push ax
    call mf210
lbl234f:
    mov ax,1h
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
