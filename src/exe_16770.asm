_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf14:FAR
    EXTRN mf50:FAR
    EXTRN mf59:FAR
    EXTRN mf68:FAR
    EXTRN mf94:FAR
    EXTRN mf106:FAR
    EXTRN mf106:FAR
    EXTRN mf106:FAR
    EXTRN mf106:FAR
    EXTRN mf106:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,1Ah
    push di
    push si
    mov si,word ptr [bp+6h]
    mov bx,word ptr [bp+8h]
    add bx,bx
    mov di,word ptr [bx+57BEh]
    test si,3h
    jnz short lbl21f
    cmp word ptr [bp+8h],2h
    jng short lbl21f
    inc di
lbl21f:
    call mf14
    mov ax,3Ch
    cwd
    push dx
    push ax
    push dx
    push ax
    mov ax,18h
    cwd
    push dx
    push ax
    mov ax,si
    mov cx,16Dh
    imul cx
    mov cx,ax
    mov ax,word ptr [bp+0Ah]
    mov bx,dx
    cwd
    mov word ptr [bp-1Ah],ax
    mov word ptr [bp-18h],dx
    lea ax,word ptr [si+3h]
    sar ax,1
    sar ax,1
    cwd
    add ax,word ptr [bp-1Ah]
    adc dx,word ptr [bp-18h]
    add cx,ax
    adc bx,dx
    mov ax,di
    cwd
    add cx,di
    adc bx,dx
    add cx,0E44h
    adc bx,0h
    push bx
    push cx
    call mf50
    mov cx,ax
    mov ax,word ptr [bp+0Ch]
    mov bx,dx
    cwd
    add cx,ax
    adc bx,dx
    push bx
    push cx
    call mf59
    mov cx,ax
    mov ax,word ptr [bp+0Eh]
    mov bx,dx
    cwd
    add cx,ax
    adc bx,dx
    push bx
    push cx
    call mf68
    mov cx,ax
    mov ax,word ptr [bp+10h]
    mov bx,dx
    cwd
    add cx,ax
    adc bx,dx
    add cx,word ptr ds:[57F0h]
    adc bx,word ptr ds:[57F2h]
    mov word ptr [bp-16h],cx
    mov word ptr [bp-14h],bx
    mov ax,word ptr [bp+0Ah]
    add ax,di
    mov word ptr [bp-4h],ax
    lea ax,word ptr [si+50h]
    mov word ptr [bp-8h],ax
    mov ax,word ptr [bp+8h]
    dec ax
    mov word ptr [bp-0Ah],ax
    mov ax,word ptr [bp+0Ch]
    mov word ptr [bp-0Eh],ax
    cmp word ptr ds:[57F4h],0h
    jz short lblECf
    lea ax,word ptr [bp-12h]
    push ss
    push ax
    call mf94
    add sp,4h
    or ax,ax
    jz short lblECf
    sub word ptr [bp-16h],0E10h
    sbb word ptr [bp-14h],0h
lblECf:
    mov ax,word ptr [bp-16h]
    mov dx,word ptr [bp-14h]
    pop si
    pop di
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
