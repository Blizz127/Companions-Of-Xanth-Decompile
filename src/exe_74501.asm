_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi2:NEAR
    EXTRN mf8:FAR
    EXTRN mf16:FAR
    EXTRN mf22:FAR
    EXTRN mi23:NEAR
    EXTRN mf31:FAR
    EXTRN mi33:NEAR
    EXTRN mf39:FAR
    EXTRN mf47:FAR
    EXTRN md61:NEAR
    EXTRN md62:NEAR
    EXTRN md67:NEAR
    EXTRN md68:NEAR
    EXTRN mf75:FAR
    EXTRN mf79:FAR
    EXTRN mf85:FAR
    EXTRN mf89:FAR
    EXTRN mi91:NEAR
    EXTRN mi98:NEAR
    EXTRN mf104:FAR
    EXTRN mi113:NEAR
    EXTRN mf124:FAR
    EXTRN mf124:FAR
    EXTRN mf124:FAR
    EXTRN mf124:FAR
    EXTRN mf124:FAR
    EXTRN mf124:FAR
    EXTRN mf124:FAR
    EXTRN mf124:FAR
    EXTRN mf124:FAR
    EXTRN mf124:FAR
    EXTRN mf124:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp, offset mi2
    push si
    push di
    cmp word ptr ds:[411Eh],0h
    jnz short lbl13f
    jmp near ptr lbl1Bf
lbl13f:
    call mf8
    jmp near ptr lbl147f
lbl1Bf:
    cmp word ptr ds:[411Ah],0h
    jnz short lbl25f
    jmp near ptr lbl147f
lbl25f:
    mov si,0h
    jmp near ptr lbl37f
lbl2Bb:
    push si
    call mf16
    add sp,2h
    add si,1h
lbl37f:
    cmp si,word ptr ds:[62AAh]
    jnl short lbl40f
    jmp near ptr lbl2Bb
lbl40f:
    call mf22
    cmp ax, offset mi23
    jnz short lbl4Df
    jmp near ptr lbl147f
lbl4Df:
    cmp word ptr ds:[416Ah],0h
    jnz short lbl57f
    jmp near ptr lblF6f
lbl57b:
lbl57f:
    mov ax,5h
    push ax
    call mf31
    add sp,2h
    cmp ax, offset mi33
    jz short lbl6Bf
    jmp near ptr lbl6Ef
lbl6Bf:
    jmp near ptr lbl57b
lbl6Ef:
    mov ax,0ECh
    push ax
    call mf39
    add sp,2h
    mov cx,word ptr ds:[62AAh]
    mov ax,0FFh
    shl ax,cl
    not ax
    and ax,0FFh
    push ax
    call mf47
    add sp,2h
    mov si,0h
    jmp near ptr lblD2f
lbl97b:
    mov bx,si
    shl bx,1
    mov ax,word ptr [bx+628Ah]
    mov bx,si
    shl bx,1
    mov word ptr [bx+62BAh],ax
    mov bx,si
    shl bx,1
    shl bx,1
    mov es, ds:[5B3Ah]
    mov ax,word ptr es:[bx+md61]
    mov dx,word ptr es:[bx+md62]
    mov bx,si
    shl bx,1
    shl bx,1
    mov es, ds:[5B3Ah]
    mov word ptr es:[bx+md67],ax
    mov word ptr es:[bx+md68],dx
    add si,1h
lblD2f:
    cmp si,word ptr ds:[62AAh]
    jnl short lblDBf
    jmp near ptr lbl97b
lblDBf:
    mov ax,0B8h
    push ax
    call mf75
    add sp,2h
    mov ax,0Ah
    push ax
    call mf79
    add sp,2h
    jmp near ptr lbl147f
lblF6f:
    cmp word ptr ds:[415Ah],0h
    jnz short lbl100f
    jmp near ptr lbl108f
lbl100f:
    call mf85
    jmp near ptr lbl147f
lbl108b:
lbl108f:
    mov ax,5h
    push ax
    call mf89
    add sp,2h
    cmp ax, offset mi91
    jz short lbl11Cf
    jmp near ptr lbl11Ff
lbl11Cf:
    jmp near ptr lbl108b
lbl11Ff:
    mov word ptr ds:[411Ch],0h
    mov ax,word ptr ds:[416Eh]
    and ax,80h
    cmp ax, offset mi98
    jnz short lbl133f
    jmp near ptr lbl142f
lbl133f:
    mov word ptr ds:[411Eh],1h
    mov word ptr ds:[6DF2h],0h
    jmp near ptr lbl147f
lbl142f:
    call mf104
lbl147f:
    cmp word ptr ds:[411Ch],0h
    jz short lbl151f
    jmp near ptr lbl16Ff
lbl151f:
    cmp word ptr ds:[411Eh],0h
    jz short lbl15Bf
    jmp near ptr lbl16Ff
lbl15Bf:
    mov ax,word ptr ds:[416Eh]
    and ax,80h
    cmp ax, offset mi113
    jnz short lbl169f
    jmp near ptr lbl16Ff
lbl169f:
    mov word ptr ds:[411Ah],0h
lbl16Ff:
    mov ax,word ptr ds:[411Ch]
    or ax,word ptr ds:[411Eh]
    jmp near ptr lbl179f
lbl179f:
    pop di
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
