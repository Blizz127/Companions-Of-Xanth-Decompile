_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi26:NEAR
    EXTRN mi49:NEAR
    EXTRN mf53:FAR
    EXTRN mf76:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,4h
    push si
    les bx, dword ptr [bp+6h]
    cmp word ptr es:[bx+0Ah],43h
    jnl short lbl14f
    jmp near ptr lblC7f
lbl14f:
    cmp word ptr es:[bx+8h],3h
    jnl short lbl1Ef
    jmp near ptr lblC7f
lbl1Ef:
    cmp word ptr es:[bx+8h],9h
    jng short lbl28f
    jmp near ptr lblC7f
lbl28f:
    cmp word ptr es:[bx+8h],3h
    jng short lbl36f
    cmp word ptr es:[bx+8h],9h
    jl short lblB2f
lbl36f:
    mov si,word ptr es:[bx+0Ah]
    cmp si,56h
    jng short lbl56f
    cmp word ptr es:[bx+8h],3h
    jnz short lbl56f
    mov bx,word ptr es:[bx+8h]
    add bx,bx
    mov ax,word ptr [bx+57C0h]
    add ax, offset mi26
    jmp short lbl60f
    nop
lbl56f:
    mov bx,word ptr es:[bx+8h]
    add bx,bx
    mov ax,word ptr [bx+57C2h]
lbl60f:
    mov word ptr [bp-2h],ax
    test si,3h
    jnz short lbl6Cf
    inc word ptr [bp-2h]
lbl6Cf:
    mov ax,7h
    cwd
    push dx
    push ax
    mov cx,16Dh
    lea ax,word ptr [si-46h]
    imul cx
    lea cx,word ptr [si-1h]
    sar cx,1
    sar cx,1
    add ax,cx
    add ax,word ptr [bp-2h]
    cwd
    sub ax, offset mi49
    sbb dx,0h
    push dx
    push ax
    call mf53
    sub ax,word ptr [bp-2h]
    neg ax
    les bx, dword ptr [bp+6h]
    cmp word ptr es:[bx+8h],3h
    jnz short lblB8f
    cmp ax,word ptr es:[bx+0Eh]
    jl short lblB2f
    jnz short lblC7f
    cmp word ptr es:[bx+4h],2h
    jl short lblC7f
lblB2b:
lblB2f:
    mov ax,1h
    jmp short lblC9f
    nop
lblB8f:
    cmp word ptr es:[bx+0Eh],ax
    jl short lblB2b
    jnz short lblC7f
    cmp word ptr es:[bx+4h],1h
    jl short lblB2b
lblC7f:
    xor ax,ax
lblC9f:
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
