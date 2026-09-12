_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
mnem_unit:
    push bp
    mov bp,sp
    sub sp,2h
    push si
    push di
    push ds
    les di, dword ptr [bp+0Ah]
    push es
    pop ds
    xor ax,ax
    mov cx,0FFFFh
    repne scasb
    not cx
    jnz short lbl1Af
    dec cx
lbl1Af:
    jcxz lbl5Af
    dec cx
    mov word ptr [bp-2h],cx
    les di, dword ptr [bp+6h]
    mov bx,di
    xor ax,ax
    mov cx,0FFFFh
    repne scasb
    not cx
    jnz short lbl31f
    dec cx
lbl31f:
    mov dx,cx
    sub dx,word ptr [bp-2h]
    jna short lbl61f
    mov di,bx
lbl3Ab:
    mov si,word ptr [bp+0Ah]
    lodsb
    mov di,bx
    mov cx,dx
    repne scasb
    jnz short lbl61f
    mov dx,cx
    mov bx,di
    mov cx,word ptr [bp-2h]
    jcxz lbl53f
    repe cmpsb
    jnz short lbl3Ab
lbl53f:
    lea ax,word ptr [bx-1h]
    mov dx,es
    jmp short lbl64f
lbl5Af:
    les ax, dword ptr [bp+6h]
    mov dx,es
    jmp short lbl64f
lbl61f:
    xor ax,ax
    cwd
lbl64f:
    pop ds
    pop di
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
