_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mn19:NEAR
    EXTRN mn28:NEAR
    EXTRN mf33:FAR
    EXTRN mf45:FAR
    EXTRN mf58:FAR
    EXTRN mf68:FAR
    EXTRN mf73:FAR
    EXTRN mn84:NEAR
    EXTRN mn84:NEAR
    EXTRN mf84:FAR
    EXTRN mf84:FAR
    EXTRN mf84:FAR
    EXTRN mf84:FAR
    EXTRN mf84:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,10h
    push di
    push si
    mov di,0FFFFh
    mov ax,word ptr [bp+6h]
    mov si,ax
    mov bx,ax
    test byte ptr [bx+0Ah],40h
    jz short lbl20f
    mov byte ptr [bx+0Ah],0h
    jmp near ptr lblC6f
    nop
lbl20f:
    test byte ptr [si+0Ah],83h
    jnz short lbl29f
    jmp near ptr lblC2f
lbl29f:
    push ds
    push si
    call mn19
    add sp,4h
    mov di,ax
    mov bx,si
    sub bx,5420h
    mov ax,word ptr [bx+5514h]
    mov word ptr [bp-2h],ax
    push ds
    push si
    call mn28
    add sp,4h
    mov al,byte ptr [si+0Bh]
    sub ah,ah
    push ax
    call mf33
    add sp,2h
    or ax,ax
    jl short lblBFf
    cmp word ptr [bp-2h],0h
    jz short lblC2f
    mov ax,541Ah
    push ds
    push ax
    lea cx,word ptr [bp-0Ch]
    push ss
    push cx
    call mf45
    add sp,8h
    lea ax,word ptr [bp-0Ah]
    mov word ptr [bp-10h],ax
    mov word ptr [bp-0Eh],ss
    cmp byte ptr [bp-0Ch],5Ch
    jz short lbl96f
    mov ax,541Ch
    push ds
    push ax
    lea ax,word ptr [bp-0Ch]
    push ss
    push ax
    call mf58
    add sp,8h
    jmp short lbl99f
    nop
lbl96f:
    dec word ptr [bp-10h]
lbl99f:
    mov ax,0Ah
    push ax
    push word ptr [bp-0Eh]
    push word ptr [bp-10h]
    push word ptr [bp-2h]
    call mf68
    add sp,8h
    lea ax,word ptr [bp-0Ch]
    push ss
    push ax
    call mf73
    add sp,4h
    or ax,ax
    jz short lblC2f
lblBFf:
    mov di,0FFFFh
lblC2f:
    mov byte ptr [si+0Ah],0h
lblC6f:
    mov ax,di
    pop si
    pop di
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
