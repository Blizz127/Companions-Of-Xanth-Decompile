_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi10:NEAR
    EXTRN mf12:FAR
    EXTRN mf34:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,2h
    push ds
    push es
    push si
    push di
    mov ax,38AFh
    mov ds,ax
    mov ax,word ptr [bp+6h]
    cmp ax, offset mi10
    jnz short lbl23f
    call mf12
    mov bx,10h
    mul bx
    jmp short lbl38f
lbl23f:
    mov ah,42h
    int 67h
    or ah,ah
    jnz short lbl32f
    mov ax,4000h
    mul bx
    jmp short lbl38f
lbl32f:
    mov ax,0FFEAh
    cwd
    jmp short lbl38f
lbl38f:
    mov word ptr [bp-2h],ax
    mov ax,word ptr [bp-2h]
    pop di
    pop si
    pop es
    pop ds
    mov sp,bp
    pop bp
    retf 2h
_TEXT ENDS
    END
