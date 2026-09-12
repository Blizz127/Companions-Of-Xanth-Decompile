_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi3:NEAR
    EXTRN mi4:NEAR
    EXTRN md9:NEAR
    EXTRN mf32:FAR
    EXTRN mf38:FAR
    EXTRN mf46:FAR
    EXTRN mf52:FAR
    EXTRN mf53:FAR
    EXTRN mf62:FAR
    EXTRN mf66:FAR
    EXTRN mf67:FAR
    EXTRN mf75:FAR
    EXTRN mf85:FAR
    EXTRN mf89:FAR
    EXTRN mf89:FAR
    EXTRN mf89:FAR
    EXTRN mf89:FAR
    EXTRN mf89:FAR
    EXTRN mf89:FAR
    EXTRN mf89:FAR
    EXTRN mf89:FAR
    EXTRN mf89:FAR
    EXTRN mf89:FAR
mnem_unit:
    push bp
    mov bp,sp
    mov ax,word ptr [bp+6h]
    sub ax, offset mi3
    cmp ax, offset mi4
    jna short lbl11f
    jmp near ptr lblD2f
lbl11f:
    add ax,ax
    xchg ax,bx
    jmp word ptr cs:[bx+md9]
    nop
    cmp al,0h
    jo short lbl1Ef
lbl1Ef:
    jo short lbl20f
lbl20f:
    jo short lbl22f
lbl22f:
    rol byte ptr [bx+si],cl
    rol byte ptr [bx+si],cl
    rol byte ptr [bx+si],cl
    jz short lbl2Af
lbl2Af:
    rol byte ptr [bx+si],cl
    rol byte ptr [bx+si],cl
    rol byte ptr [bx+si],cl
    rol byte ptr [bx+si],cl
    rol byte ptr [bx+si],cl
    rol byte ptr [bx+si],cl
    xchg al,byte ptr [bx+si]
    les ax, dword ptr [bx+si]
    jz short lbl3Cf
lbl3Cf:
    mov ax,1h
    mov dx,0F011h
    push dx
    push ax
    call mf32
    mov sp,bp
    mov ax,0A9h
    push ax
    mov ax,0ADh
    push ax
    call mf38
    mov sp,bp
    or ax,ax
    jz short lblD2f
    mov ax,2h
lbl61b:
    mov dx,0F011h
    push dx
    push ax
    call mf46
    mov sp,bp
    jmp short lblD2f
    nop
    xor ax,ax
    jmp short lbl61b
    call mf52
    call mf53
    mov byte ptr ds:[299Ah],0h
    jmp short lblD2f
    nop
    mov ax,1h
    push ax
    mov ax,299Ch
    push ds
    push ax
    call mf62
    mov sp,bp
    cmp byte ptr ds:[299Ah],0h
    jnz short lblBFf
    call mf66
    call mf67
    xor ax,ax
    push ax
    push ax
    mov ax,18h
    push ax
    mov ax,611h
    push ax
    call mf75
    mov sp,bp
    mov byte ptr ds:[299Ah],1h
lblBFf:
    mov ax,1h
    jmp short lblD4f
    mov ax,1h
    push ax
    mov ax,29A8h
    push ds
    push ax
    call mf85
lblD2f:
    xor ax,ax
lblD4f:
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
