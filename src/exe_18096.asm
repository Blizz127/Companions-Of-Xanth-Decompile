_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mjn3b:NEAR
mnem_unit:
    push bp
    mov bp,sp
    push ds
    mov al,4Fh
    lds dx, dword ptr [bp+6h]
    jmp short lbl14f
    push bp
    mov bp,sp
    push ds
    mov al,4Eh
    lds dx, dword ptr [bp+0Ch]
lbl14f:
    mov ah,2Fh
    int 21h
    mov ah,1Ah
    int 21h
    cmp al,4Eh
    jnz short lbl26f
    lds dx, dword ptr [bp+6h]
    mov cx,word ptr [bp+0Ah]
lbl26f:
    mov ah,al
    int 21h
    push ax
    lahf
    push ax
    mov dx,es
    mov ds,dx
    mov dx,bx
    mov ah,1Ah
    int 21h
    pop ax
    sahf
    pop ax
    pop ds
    jmp mjn3b
    push bp
    mov bp,sp
    mov ax,word ptr [bp+6h]
    push ds
    lds dx, dword ptr [bp+8h]
    mov ah,25h
    int 21h
    pop ds
    xor ax,ax
    mov sp,bp
    pop bp
    retf
lblD1AEf:
_TEXT ENDS
    END
