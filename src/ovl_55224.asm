_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf5:FAR
    EXTRN mf8:FAR
    EXTRN mf14:FAR
    EXTRN mf18:FAR
    EXTRN mf28:FAR
    EXTRN mi31:NEAR
    EXTRN mf37:FAR
    EXTRN mf42:FAR
    EXTRN mi49:NEAR
    EXTRN mi53:NEAR
    EXTRN mf68:FAR
    EXTRN mf76:FAR
    EXTRN mf86:FAR
    EXTRN mf99:FAR
    EXTRN mf107:FAR
    EXTRN mf111:FAR
    EXTRN mf114:FAR
    EXTRN mf118:FAR
    EXTRN mf120:FAR
    EXTRN mf126:FAR
    EXTRN mf140:FAR
    EXTRN mf145:FAR
    EXTRN mf148:FAR
    EXTRN mf152:FAR
    EXTRN mf154:FAR
    EXTRN mf159:FAR
    EXTRN mf163:FAR
    EXTRN mf170:FAR
    EXTRN mf174:FAR
    EXTRN mf179:FAR
    EXTRN mf181:FAR
    EXTRN mf186:FAR
    EXTRN mf186:FAR
    EXTRN mf186:FAR
    EXTRN mf186:FAR
    EXTRN mf186:FAR
    EXTRN mf186:FAR
    EXTRN mf186:FAR
    EXTRN mf186:FAR
    EXTRN mf186:FAR
    EXTRN mf186:FAR
    EXTRN mf186:FAR
    EXTRN mf186:FAR
    EXTRN mf186:FAR
    EXTRN mf186:FAR
    EXTRN mf186:FAR
    EXTRN mf186:FAR
    EXTRN mf186:FAR
    EXTRN mf186:FAR
    EXTRN mf186:FAR
    EXTRN mf186:FAR
    EXTRN mf186:FAR
    EXTRN mf186:FAR
    EXTRN mf186:FAR
    EXTRN mf186:FAR
    EXTRN mf186:FAR
    EXTRN mf186:FAR
    EXTRN mf186:FAR
    EXTRN mf186:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,2Eh
    push di
    push si
    call mf5
    mov ax,0Ah
    push ax
    call mf8
    add sp,2h
    mov ax,17h
    push ax
    mov ax,0Fh
    push ax
    call mf14
    add sp,4h
    mov ax,9h
    push ax
    call mf18
    add sp,2h
    mov word ptr [bp-22h],ax
    mov ax,0F0h
    push ax
    xor ax,ax
    push ax
    push ax
    push word ptr [bp+8h]
    push word ptr [bp+6h]
    call mf28
    add sp,0Ah
    mov word ptr [bp-16h],ax
    cmp ax, offset mi31
    jng short lbl5Bf
    mov word ptr [bp-16h],70h
lbl5Bf:
    lea ax,word ptr [bp-14h]
    push ss
    push ax
    call mf37
    add sp,4h
    xor ax,ax
    push ax
    push ax
    call mf42
    add sp,4h
    mov ax,7Dh
    sub ax,word ptr [bp-16h]
    cwd
    sub ax,dx
    sar ax,1
    add ax, offset mi49
    mov cx,ax
    add ax,word ptr [bp-16h]
    mov dx,ax
    add ax, offset mi53
    push ax
    mov bx,133h
    push bx
    mov si,cx
    sub cx,4h
    push cx
    mov di,39h
    push di
    lea bx,word ptr [bp-14h]
    push ss
    push bx
    mov di,ax
    mov word ptr [bp-2Ch],cx
    mov word ptr [bp-2Eh],dx
    call mf68
    add sp,0Ch
    push di
    mov ax,133h
    push ax
    push word ptr [bp-2Ch]
    mov cx,39h
    push cx
    call mf76
    add sp,8h
    mov ax,14h
    push ax
    push di
    mov ax,133h
    push ax
    push word ptr [bp-2Ch]
    mov ax,39h
    push ax
    call mf86
    add sp,0Ah
    mov ax,18h
    push ax
    mov ax,word ptr [bp-2Eh]
    inc ax
    push ax
    mov ax,12Fh
    push ax
    lea ax,word ptr [si-1h]
    push ax
    mov ax,3Dh
    push ax
    call mf99
    add sp,0Ah
    push word ptr [bp-2Eh]
    mov ax,12Eh
    push ax
    push si
    mov ax,3Eh
    push ax
    call mf107
    add sp,8h
    mov word ptr [bp-18h],ax
    push ax
    call mf111
    add sp,2h
    push word ptr [bp-18h]
    call mf114
    add sp,2h
    push word ptr [bp+8h]
    push word ptr [bp+6h]
    call mf118
    add sp,4h
    call mf120
lbl137b:
    lea ax,word ptr [bp-2Ah]
    push ss
    push ax
    mov ax,3FFh
    push ax
    call mf126
    add sp,6h
    or ax,ax
    jz short lbl137b
    cmp word ptr [bp-2Ah],4h
    jz short lbl15Af
    cmp word ptr [bp-2Ah],1h
    jnz short lbl137b
    jmp short lbl16Ff
lbl15Ab:
lbl15Af:
    lea ax,word ptr [bp-2Ah]
    push ss
    push ax
    mov ax,8h
    push ax
    call mf140
    add sp,6h
    or ax,ax
    jz short lbl15Ab
lbl16Ff:
    push word ptr [bp-22h]
    call mf145
    add sp,2h
    push word ptr [bp-18h]
    call mf148
    mov ax,2h
    add sp,ax
    push ax
    call mf152
    add sp,2h
    call mf154
    cmp byte ptr [bp-14h],0h
    jnz short lbl1B6f
    mov ax,1h
    push ax
    call mf159
    add sp,2h
    mov ax,40h
    push ax
    call mf163
    add sp,2h
    jmp short lbl1DCf
    nop
lbl1B6f:
    lea ax,word ptr [bp-14h]
    push ss
    push ax
    call mf170
    add sp,4h
    mov ax,1h
    push ax
    call mf174
    add sp,2h
    lea ax,word ptr [bp-14h]
    push ss
    push ax
    call mf179
    add sp,4h
lbl1DCf:
    call mf181
    pop si
    pop di
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
