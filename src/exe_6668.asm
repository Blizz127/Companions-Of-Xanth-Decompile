_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mn36:NEAR
    EXTRN mn57:NEAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,4h
    push si
    push di
    mov ax,word ptr [bp+0Ah]
    mul word ptr [bp+0Ch]
    mov cx,ax
    or cx,dx
    jz short lbl77f
    mov word ptr [bp-4h],ax
    mov word ptr [bp-2h],dx
    les bx, dword ptr [bp+6h]
    mov si,word ptr [bp+0Eh]
lbl20b:
    or dx,dx
    jnz short lbl45f
    cmp ax,0FFFFFFFFFFFFFFFFh
    jz short lbl45f
    mov cx,bx
    add cx,ax
    jcxz lbl31f
    jc short lbl45f
lbl31f:
    push ax
    push bx
    push dx
    mov cx,ax
    call mn36
    mov cx,ax
    pop dx
    pop bx
    pop ax
    sub ax,cx
    sbb dx,0h
    jmp short lbl81f
lbl45f:
    cmp bx,1h
    ja short lbl4Ff
    mov cx,8000h
    jmp short lbl53f
lbl4Ff:
    mov cx,bx
    neg cx
lbl53f:
    push cx
    push ax
    push bx
    push dx
    call mn57
    mov cx,ax
    pop dx
    pop bx
    pop ax
    pop di
    sub ax,cx
    sbb dx,0h
    cmp cx,di
    jc short lbl81f
    add bx,cx
    jnc short lbl79f
    mov cx,es
    add cx,1000h
    mov es,cx
    jmp short lbl79f
lbl77f:
    jmp short lbl9Df
lbl79f:
    mov cx,ax
    or cx,dx
    jnz short lbl20b
    jmp short lbl81f
lbl81f:
    mov cx,ax
    or cx,dx
    jz short lbl9Af
    mov cx,word ptr [bp-4h]
    sub cx,ax
    mov ax,cx
    mov cx,word ptr [bp-2h]
    db 1Bh, 0CAh ; override
    mov dx,cx
    div word ptr [bp+0Ah]
    jmp short lbl9Df
lbl9Af:
    mov ax,word ptr [bp+0Ch]
lbl9Df:
    pop di
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
