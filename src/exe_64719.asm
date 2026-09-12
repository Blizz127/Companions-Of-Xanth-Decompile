_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi2:NEAR
    EXTRN mf10:FAR
    EXTRN mf20:FAR
    EXTRN mf45:FAR
    EXTRN mf53:FAR
    EXTRN mf57:FAR
    EXTRN mf61:FAR
    EXTRN mf67:FAR
    EXTRN mf67:FAR
    EXTRN mf67:FAR
    EXTRN mf67:FAR
    EXTRN mf67:FAR
    EXTRN mf67:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp, offset mi2
    push si
    push di
    mov word ptr [bp-4h],1h
    jmp near ptr lbl24f
lbl11b:
    mov ax,0h
    push ax
    push word ptr [bp-4h]
    call mf10
    add sp,4h
    add word ptr [bp-4h],1h
lbl24f:
    cmp word ptr [bp-4h],0F5h
    jg short lbl2Ef
    jmp near ptr lbl11b
lbl2Ef:
    mov ax,6h
    push ax
    mov ax,4h
    push ax
    call mf20
    add sp,4h
    mov word ptr [bp-4h],0h
    jmp near ptr lbl65f
lbl46b:
    mov bx,word ptr [bp-4h]
    shl bx,1
    mov word ptr [bx+5E4Eh],2000h
    mov bx,word ptr [bp-4h]
    mov byte ptr [bx+5E44h],0h
    mov bx,word ptr [bp-4h]
    mov byte ptr [bx+5E3Ah],0h
    add word ptr [bp-4h],1h
lbl65f:
    cmp word ptr [bp-4h],9h
    jnl short lbl6Ef
    jmp near ptr lbl46b
lbl6Ef:
    mov word ptr [bp-4h],0h
    jmp near ptr lbl82f
lbl76b:
    mov bx,word ptr [bp-4h]
    mov byte ptr [bx+5E6Ah],7Fh
    add word ptr [bp-4h],1h
lbl82f:
    cmp word ptr [bp-4h],0Bh
    jnl short lbl8Bf
    jmp near ptr lbl76b
lbl8Bf:
    mov ax,0h
    push ax
    call mf45
    add sp,2h
    mov ax,0h
    push ax
    mov ax,0h
    push ax
    mov ax,0h
    push ax
    call mf53
    add sp,6h
    mov ax,1h
    push ax
    call mf57
    add sp,2h
    mov ax,1h
    push ax
    call mf61
    add sp,2h
    pop di
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
