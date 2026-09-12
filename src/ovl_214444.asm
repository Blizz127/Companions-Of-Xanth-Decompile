_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf4:FAR
    EXTRN mf7:FAR
    EXTRN mf13:FAR
    EXTRN mf22:FAR
    EXTRN mf32:FAR
    EXTRN mf36:FAR
    EXTRN mf48:FAR
    EXTRN mf58:FAR
    EXTRN mf71:FAR
    EXTRN mf83:FAR
    EXTRN mf93:FAR
    EXTRN mf97:FAR
    EXTRN mf108:FAR
    EXTRN mf111:FAR
    EXTRN mf115:FAR
    EXTRN mf128:FAR
    EXTRN mf130:FAR
    EXTRN mf131:FAR
    EXTRN mf140:FAR
    EXTRN mf155:FAR
    EXTRN mf166:FAR
    EXTRN mf170:FAR
    EXTRN mf173:FAR
    EXTRN mf176:FAR
    EXTRN mf178:FAR
    EXTRN mf187:FAR
    EXTRN mf189:FAR
    EXTRN mf196:FAR
    EXTRN mf201:FAR
    EXTRN mf205:FAR
    EXTRN mf205:FAR
    EXTRN mf205:FAR
    EXTRN mf205:FAR
    EXTRN mf205:FAR
    EXTRN mf205:FAR
    EXTRN mf205:FAR
    EXTRN mf205:FAR
    EXTRN mf205:FAR
    EXTRN mf205:FAR
    EXTRN mf205:FAR
    EXTRN mf205:FAR
    EXTRN mf205:FAR
    EXTRN mf205:FAR
    EXTRN mf205:FAR
    EXTRN mf205:FAR
    EXTRN mf205:FAR
    EXTRN mf205:FAR
    EXTRN mf205:FAR
    EXTRN mf205:FAR
    EXTRN mf205:FAR
    EXTRN mf205:FAR
    EXTRN mf205:FAR
    EXTRN mf205:FAR
    EXTRN mf205:FAR
    EXTRN mf205:FAR
    EXTRN mf205:FAR
    EXTRN mf205:FAR
    EXTRN mf205:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,12h
    push si
    call mf4
    mov ax,0Ah
    push ax
    call mf7
    add sp,2h
    mov ax,17h
    push ax
    mov ax,0Fh
    push ax
    call mf13
    add sp,4h
    mov ax,0A3h
    push ax
    mov ax,13Fh
    push ax
    xor ax,ax
    push ax
    push ax
    call mf22
    add sp,8h
    mov ax,0C7h
    push ax
    mov ax,109h
    push ax
    mov ax,0A4h
    push ax
    xor ax,ax
    push ax
    call mf32
    add sp,8h
    xor ax,ax
    push ax
    call mf36
    add sp,2h
    mov ax,0C1h
    push ax
    mov cx,100h
    push cx
    mov dx,1Ah
    push dx
    mov bx,8h
    push bx
    mov si,1h
    push si
    call mf48
    add sp,0Ah
    mov ax,0C1h
    push ax
    mov ax,100h
    push ax
    mov ax,1Ah
    push ax
    mov ax,8h
    push ax
    call mf58
    add sp,8h
    mov word ptr [bp-4h],ax
    mov ax,14h
    push ax
    mov ax,0C0h
    push ax
    mov ax,0FFh
    push ax
    mov ax,1Bh
    push ax
    mov ax,9h
    push ax
    call mf71
    add sp,0Ah
    mov ax,18h
    push ax
    mov ax,0ABh
    push ax
    mov ax,0F8h
    push ax
    mov ax,22h
    push ax
    mov ax,10h
    push ax
    call mf83
    add sp,0Ah
    mov ax,0AAh
    push ax
    mov ax,0F7h
    push ax
    mov ax,23h
    push ax
    mov ax,11h
    push ax
    call mf93
    add sp,8h
    mov word ptr [bp-6h],ax
    push ax
    call mf97
    add sp,2h
    mov ax,30h
    push ax
    mov ax,3239h
    push ds
    push ax
    mov ax,0B0h
    push ax
    mov ax,6Ch
    push ax
    call mf108
    add sp,0Ah
    push word ptr [bp-6h]
    call mf111
    add sp,2h
    mov ax,9h
    push ax
    call mf115
    add sp,2h
    cmp word ptr ds:[6DDCh],0h
    jz short lbl12Cf
    mov ax,si
    jmp short lbl12Ff
lbl12Cf:
    mov ax,2h
lbl12Ff:
    mov dx,0F02Ah
    push dx
    push ax
    xor ax,ax
    push dx
    push ax
    call mf128
    add sp,8h
    call mf130
lbl145b:
    call mf131
    or ax,ax
    jnz short lbl196f
    lea ax,word ptr [bp-0Ah]
    push ss
    push ax
    lea ax,word ptr [bp-8h]
    push ss
    push ax
    call mf140
    add sp,8h
    or ax,ax
    jz short lbl145b
    lea ax,word ptr [bp-10h]
    push ss
    push ax
    lea ax,word ptr [bp-0Eh]
    push ss
    push ax
    lea ax,word ptr [bp-0Ch]
    push ss
    push ax
    push word ptr [bp-0Ah]
    push word ptr [bp-8h]
    call mf155
    add sp,10h
    or ax,ax
    jz short lbl145b
    cmp word ptr [bp-10h],5h
    jnz short lbl145b
    mov ax,word ptr [bp-4h]
    cmp word ptr [bp-0Ch],ax
    jnz short lbl145b
    jmp short lbl19Bf
    nop
lbl196f:
    call mf166
lbl19Bf:
    mov ax,1h
    push ax
    push word ptr [bp-4h]
    call mf170
    add sp,4h
    push word ptr [bp-6h]
    call mf173
    add sp,2h
    push word ptr [bp-4h]
    call mf176
    add sp,2h
    call mf178
    mov ax,0C1h
    push ax
    mov ax,109h
    push ax
    mov ax,1Ah
    push ax
    xor ax,ax
    push ax
    call mf187
    add sp,8h
    call mf189
    mov word ptr [bp-12h],46E4h
lbl1E6b:
    mov ax,1h
    push ax
    mov ax,3420h
    push ax
    push word ptr [bp-12h]
    call mf196
    add sp,6h
    add word ptr [bp-12h],9h
    cmp word ptr [bp-12h],4750h
    jc short lbl1E6b
    call mf201
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
