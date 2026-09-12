_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi2:NEAR
    EXTRN mf15:FAR
    EXTRN mf25:FAR
    EXTRN mi28:NEAR
    EXTRN mf34:FAR
    EXTRN mf39:FAR
    EXTRN mf45:FAR
    EXTRN mf51:FAR
    EXTRN mf59:FAR
    EXTRN mf63:FAR
    EXTRN mf67:FAR
    EXTRN mf73:FAR
    EXTRN mf73:FAR
    EXTRN mf73:FAR
    EXTRN mf73:FAR
    EXTRN mf73:FAR
    EXTRN mf73:FAR
    EXTRN mf73:FAR
    EXTRN mf73:FAR
    EXTRN mf73:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp, offset mi2
    push si
    push di
    mov word ptr ds:[411Ah],1h
    mov word ptr ds:[411Ch],1h
    mov word ptr ds:[411Eh],0h
    mov word ptr ds:[4122h],0h
    mov ax,word ptr ds:[62BAh]
    mov word ptr [bp-4h],ax
lbl27b:
    mov ax,0h
    push ax
    mov ax,0h
    push ax
    call mf15
    add sp,4h
    and ax,0FFh
    cmp ax,0FFh
    jz short lbl42f
    jmp near ptr lbl5Df
lbl42f:
    mov ax,1h
    push ax
    mov ax,0h
    push ax
    call mf25
    add sp,4h
    and ax,0FFh
    cmp ax, offset mi28
    jnz short lbl5Df
    jmp near ptr lbl81f
lbl5Df:
    add word ptr ds:[62BAh],2h
    mov ax,0h
    push ax
    call mf34
    add sp,2h
    add word ptr ds:[62BAh],ax
    mov ax,0h
    push ax
    call mf39
    add sp,2h
    jmp near ptr lbl27b
lbl81f:
    add word ptr ds:[62BAh],1h
    mov ax,0h
    push ax
    call mf45
    add sp,2h
    mov ax,word ptr [bp-4h]
    mov word ptr ds:[62BAh],ax
    mov ax,0ECh
    push ax
    call mf51
    add sp,2h
    mov cx,word ptr ds:[62AAh]
    mov ax,0FFh
    shl ax,cl
    not ax
    and ax,0FFh
    push ax
    call mf59
    add sp,2h
    mov ax,0B8h
    push ax
    call mf63
    add sp,2h
    mov ax,0Ah
    push ax
    call mf67
    add sp,2h
    pop di
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
