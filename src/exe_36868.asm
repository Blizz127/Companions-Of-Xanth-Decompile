_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mfc1:FAR
    EXTRN mf141:FAR
    EXTRN mi1c5:NEAR
    EXTRN mf135:FAR
    EXTRN mf127:FAR
    EXTRN mf10a:FAR
    EXTRN mi1e0:NEAR
    EXTRN mf15c:FAR
    EXTRN mffe:FAR
    EXTRN mf167:FAR
    EXTRN mf22c:FAR
    EXTRN mf1bd:FAR
    EXTRN mf20b:FAR
    EXTRN mfd1:FAR
    EXTRN mf3b:FAR
    EXTRN mf224:FAR
    EXTRN mfea:FAR
    EXTRN mfa0:FAR
    EXTRN mf218:FAR
    EXTRN mf1ff:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,62h
    push di
    push si
    cmp word ptr [bp+8h],0h
    jnz short lbl6Af
    mov ax,word ptr [bp+0Eh]
    mov word ptr [bp+8h],ax
    or ax,ax
    jnz short lbl6Af
    cmp word ptr [bp+0Ah],ax
    jz short lbl22f
    cmp word ptr [bp+10h],ax
    jnz short lbl6Af
lbl22f:
    cmp word ptr [bp+0Ah],0h
    jnz short lbl38f
    mov ax,word ptr [bp+10h]
    mov word ptr [bp+0Ah],ax
    or ax,ax
    jnz short lbl38f
    mov byte ptr [bp-5Eh],0h
    jmp short lblA8f
lbl38f:
    push word ptr [bp+0Ah]
    call mf3b
    add sp,2h
    mov di,ax
    lea si,word ptr [bp-5Eh]
    mov es,dx
    push ds
    mov cx,0FFFFh
    xor ax,ax
    repne scasb
    not cx
    sub di,cx
    db 87h, 0FEh ; override
    push ds
    push dx
    pop ds
    pop es
    shr cx,1
    rep movsw
    adc cx,cx
    rep movsb
    pop ds
    mov word ptr ds:[69FAh],ax
    jmp short lblA8f
lbl6Af:
    cmp word ptr [bp+10h],0h
    jz short lbl92f
    cmp word ptr [bp+0Ah],0h
    jnz short lbl7Ef
    mov ax,word ptr [bp+10h]
    mov word ptr [bp+0Ah],ax
    jmp short lbl92f
lbl7Ef:
    cmp word ptr [bp+0Ch],0h
    jnz short lbl92f
    mov ax,word ptr [bp+0Ah]
    cmp word ptr [bp+10h],ax
    jz short lbl92f
    mov ax,word ptr [bp+10h]
    mov word ptr [bp+0Ch],ax
lbl92f:
    lea ax,word ptr [bp-5Eh]
    push ss
    push ax
    push word ptr [bp+0Ch]
    push word ptr [bp+0Ah]
    push word ptr [bp+8h]
    call mfa0
    add sp,0Ah
lblA8f:
    mov word ptr [bp-8h],ax
    cmp word ptr [bp+6h],0h
    jz short lblCCf
    or ax,ax
    jz short lblCCf
    mov word ptr [bp-0Ah],1h
    xor ax,ax
    push ax
    mov ax,200h
    push ax
    call mfc1
    add sp,4h
    jmp short lblD1f
    nop
lblCCf:
    mov word ptr [bp-0Ah],0h
lblD1f:
    call mfd1
    cmp word ptr [bp+8h],0h
    jnz short lbl106f
    cmp word ptr ds:[69FAh],0h
    jz short lblFAf
    push word ptr [bp+0Ah]
    push word ptr ds:[69FAh]
    call mfea
    add sp,4h
    push ax
    push word ptr ds:[69FAh]
    jmp short lblFEf
    nop
lblFAf:
    xor ax,ax
    push ax
    push ax
lblFEf:
    call mffe
    add sp,4h
lbl106f:
    xor ax,ax
    push ax
    push ax
    call mf10a
    add sp,4h
    mov bx,34h
    mov es, ds:[5A1Ch]
    mov word ptr [bp-62h],bx
    mov word ptr [bp-60h],es
    cmp byte ptr es:[bx],0h
    jz short lbl13Df
    push es
    push bx
    call mf127
    add sp,4h
    push word ptr [bp-60h]
    push word ptr [bp-62h]
    call mf135
    add sp,4h
lbl13Df:
    mov ax,1h
    push ax
    call mf141
    add sp,2h
    mov ax,0FFFFh
    push ax
    cmp word ptr [bp-8h],2h
    jnz short lbl158f
    mov ax,6h
    jmp short lbl15Bf
lbl158f:
    mov ax,0Fh
lbl15Bf:
    push ax
    call mf15c
    add sp,4h
    xor ax,ax
    push ax
    call mf167
    add sp,2h
    jmp short lbl1B8f
    nop
lbl172b:
    lea ax,word ptr [bp-5Eh]
    mov word ptr [bp-0Eh],ax
    mov word ptr [bp-0Ch],ss
    mov bx,ax
    cmp byte ptr [bx],0h
    jz short lbl18Ef
lbl182b:
    inc word ptr [bp-0Eh]
    les bx, dword ptr [bp-0Eh]
    cmp byte ptr es:[bx],0h
    jnz short lbl182b
lbl18Ef:
    lea ax,word ptr [bp-5Eh]
    cmp word ptr [bp-0Eh],ax
    jna short lbl1A7f
lbl196b:
    les bx, dword ptr [bp-0Eh]
    cmp byte ptr es:[bx],20h
    jz short lbl1A7f
    dec word ptr [bp-0Eh]
    cmp word ptr [bp-0Eh],ax
    ja short lbl196b
lbl1A7f:
    mov ax,word ptr ds:[6Ch]
    mov dx,word ptr ds:[6Eh]
    les bx, dword ptr [bp-0Eh]
    mov word ptr es:[bx],ax
    mov word ptr es:[bx+2h],dx
lbl1B8f:
    lea ax,word ptr [bp-5Eh]
    push ss
    push ax
    call mf1bd
    add sp,4h
    add ax, offset mi1c5
    mov word ptr [bp-2h],ax
    cmp ax,108h
    jnl short lbl172b
    mov ax,7Ch
    sub ax,word ptr ds:[69F8h]
    mov word ptr [bp-6h],ax
    mov cx,ax
    add ax,word ptr ds:[69F8h]
    add ax, offset mi1e0
    push ax
    mov ax,16Dh
    sub ax,word ptr [bp-2h]
    cwd
    sub ax,dx
    sar ax,1
    mov dx,ax
    add ax,word ptr [bp-2h]
    push ax
    push cx
    push dx
    push word ptr [bp-60h]
    push word ptr [bp-62h]
    mov si,dx
    call mf1ff
    add sp,0Ch
    push word ptr [bp-6h]
    push si
    call mf20b
    add sp,4h
    lea ax,word ptr [bp-5Eh]
    push ss
    push ax
    call mf218
    add sp,4h
    mov ax,0FFFFh
    push ax
    call mf224
    add sp,2h
    call mf22c
    mov ax,word ptr [bp-0Ah]
    pop si
    pop di
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
