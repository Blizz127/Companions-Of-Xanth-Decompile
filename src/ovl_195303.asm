_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf32:FAR
    EXTRN mf44:FAR
    EXTRN mf56:FAR
    EXTRN mf64:FAR
    EXTRN mf70:FAR
    EXTRN mf70:FAR
    EXTRN mf70:FAR
    EXTRN mf70:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,22h
    push si
    mov word ptr [bp-1Ch],4Ah
    mov word ptr [bp-1Ah],0F021h
    mov word ptr [bp-18h],155h
    mov word ptr [bp-16h],160h
    mov word ptr [bp-14h],4Bh
    mov word ptr [bp-12h],0F021h
    mov word ptr [bp-10h],156h
    mov word ptr [bp-0Eh],161h
    mov word ptr [bp-0Ch],4Ch
    mov word ptr [bp-0Ah],0F021h
    xor ax,ax
    mov word ptr [bp-20h],ax
    mov word ptr [bp-1Eh],ax
    mov word ptr [bp-8h],ax
    mov word ptr [bp-6h],ax
    mov word ptr [bp-4h],4Dh
    mov word ptr [bp-2h],0F021h
    inc word ptr ds:[2C0h]
    cmp word ptr ds:[256h],0FBh
    jnz short lbl78f
    mov cl,3h
    mov si,word ptr ds:[2C0h]
    shl si,cl
    push word ptr [bp+si-22h]
    push word ptr [bp+si-24h]
    mov ax,30F9h
    push ds
    push ax
    call mf32
    add sp,8h
lbl78f:
    cmp word ptr ds:[2C0h],3h
    jnl short lbl88f
    mov ax,1h
    push ax
    mov ax,1Ah
    jmp short lbl8Ff
lbl88f:
    mov ax,2h
    push ax
    mov ax,1Dh
lbl8Ff:
    push ax
    call mf44
    add sp,4h
    mov cl,3h
    mov si,word ptr ds:[2C0h]
    shl si,cl
    mov ax,word ptr [bp+si-28h]
    mov word ptr [bp-22h],ax
    or ax,ax
    jz short lblCEf
    push ax
    mov ax,0D9h
    push ax
    call mf56
    add sp,4h
    mov cl,3h
    mov si,word ptr ds:[2C0h]
    shl si,cl
    push word ptr [bp+si-26h]
    mov ax,0FEh
    push ax
    call mf64
    add sp,4h
lblCEf:
    mov ax,1h
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
