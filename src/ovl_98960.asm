_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi4:NEAR
    EXTRN mi5:NEAR
    EXTRN md10:NEAR
    EXTRN mf27:FAR
    EXTRN mf42:FAR
    EXTRN mf48:FAR
    EXTRN mf53:FAR
    EXTRN mf54:FAR
    EXTRN mf59:FAR
    EXTRN mf60:FAR
    EXTRN mf68:FAR
    EXTRN mf76:FAR
    EXTRN mf87:FAR
    EXTRN mf97:FAR
    EXTRN mf107:FAR
    EXTRN mf116:FAR
    EXTRN mf120:FAR
    EXTRN mf120:FAR
    EXTRN mf120:FAR
    EXTRN mf120:FAR
    EXTRN mf120:FAR
    EXTRN mf120:FAR
    EXTRN mf120:FAR
    EXTRN mf120:FAR
    EXTRN mf120:FAR
    EXTRN mf120:FAR
    EXTRN mf120:FAR
    EXTRN mf120:FAR
    EXTRN mf120:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,2h
    mov ax,word ptr [bp+6h]
    sub ax, offset mi4
    cmp ax, offset mi5
    jna short lbl14f
    jmp near ptr lbl130f
lbl14f:
    add ax,ax
    xchg ax,bx
    jmp word ptr cs:[bx+md10]
    add byte ptr ds:[bp+si-7E00h],al
    add byte ptr [bp+si+3000h],al
    add word ptr [bx+si],si
    add word ptr [bx+si],si
    add word ptr [bp+3000h],ax
    add word ptr [bx+si],si
    add word ptr [bx+si],si
    add word ptr [bx+si],si
    add word ptr [bx+si],si
    add word ptr [bx+si],si
    add word ptr [bx+si+2200h],bx
    add word ptr [bp-4800h],ax
    jc short lbl41f
lbl41f:
    push ax
    mov ax,73h
    push ax
    call mf27
    add sp,4h
    or ax,ax
    jz short lbl5Af
    mov ax,2h
    mov dx,0F009h
    jmp short lbl5Df
lbl5Af:
    xor ax,ax
    cwd
lbl5Df:
    push dx
    push ax
    mov ax,1h
    mov dx,0F009h
    push dx
    push ax
    call mf42
    add sp,8h
    mov ax,3h
lbl72b:
    mov dx,0F009h
    push dx
    push ax
    call mf48
    add sp,4h
    jmp near ptr lbl130f
    xor ax,ax
    jmp short lbl72b
    call mf53
    call mf54
    mov byte ptr ds:[23D6h],0h
    jmp near ptr lbl130f
    cmp byte ptr ds:[23D6h],0h
    jnz short lblC2f
    call mf59
    call mf60
    xor ax,ax
    push ax
    push ax
    mov ax,14h
    push ax
    mov ax,402h
    push ax
    call mf68
    add sp,8h
    mov byte ptr ds:[23D6h],1h
lblC2f:
    mov ax,1h
    push ax
    mov cx,23D8h
    push ds
    push cx
    call mf76
    add sp,6h
    mov word ptr [bp-2h],ax
    xor ax,ax
    push ax
    mov ax,82h
    push ax
    mov ax,0A4h
    push ax
    mov ax,0A0h
    push ax
    call mf87
    add sp,8h
    mov ax,1h
    push ax
    mov ax,6Eh
    push ax
    mov ax,0A6h
    push ax
    mov ax,0A5h
    push ax
    call mf97
    add sp,8h
    mov ax,2h
    push ax
    mov ax,5Ah
    push ax
    mov ax,0AAh
    push ax
    mov ax,0A7h
    push ax
    call mf107
    add sp,8h
    mov ax,word ptr [bp-2h]
    jmp short lbl132f
    mov ax,1h
    push ax
    mov ax,23E4h
    push ds
    push ax
    call mf116
lbl130f:
    xor ax,ax
lbl132f:
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
