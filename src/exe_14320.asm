_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mjn19:NEAR
    EXTRN mi22:NEAR
mnem_unit:
    push bp
    mov bp,sp
    push si
    push di
    mov bl,1h
    mov cx,word ptr [bp+0Ch]
    mov ax,word ptr [bp+6h]
    xor dx,dx
    cmp cx,0Ah
    jnz short lbl15f
    cwd
lbl15f:
    push ds
    lds di, dword ptr [bp+8h]
    jmp mjn19
    push bp
    mov bp,sp
    mov ax,word ptr [bp+6h]
    add ax, offset mi22
    pop bp
    retf
lblD47f:
_TEXT ENDS
    END
