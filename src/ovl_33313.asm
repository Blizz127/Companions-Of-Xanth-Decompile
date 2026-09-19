_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi6:NEAR
    EXTRN md11:NEAR
    EXTRN mf15f:FAR
    EXTRN mf186:FAR
    EXTRN mfd7:FAR
    EXTRN mfe3:FAR
    EXTRN mi111:NEAR
    EXTRN mff2:FAR
    EXTRN mi1a1:NEAR
    EXTRN mf19c:FAR
    EXTRN mf140:FAR
    EXTRN mf61:FAR
    EXTRN mf7b:FAR
    EXTRN mfc5:FAR
    EXTRN mfb3:FAR
    EXTRN mf4d:FAR
    EXTRN mi11b:NEAR
    EXTRN mf172:FAR
    EXTRN mf12d:FAR
    EXTRN mf8e:FAR
    EXTRN mffa:FAR
mnem_unit:
    push bp
    mov bp,sp
    mov ax,word ptr [bp+8h]
    cmp ax, offset mi6
    jna short lbl0Ef
    db 0E9h, 99h, 01h ; override
lbl0Ef:
    add ax,ax
    xchg ax,bx
    jmp word ptr cs:[bx+md11]
    db 75h, 00h, 75h, 00h, 75h, 00h, 0D8h, 01h, 0D8h, 01h, 0D8h, 01h, 0D8h, 01h, 0D8h, 01h
    db 0D8h, 01h, 89h, 00h, 0A3h, 00h, 0C7h, 00h, 75h, 00h, 0CFh, 00h, 2Bh, 01h, 3Fh, 01h
    db 55h, 01h, 75h, 00h, 81h, 01h, 0D8h, 01h, 0D8h, 01h, 0D8h, 01h, 0CDh, 01h
    xor ax,ax
    push ax
    push word ptr [bp+8h]
lbl4Ab:
    push word ptr [bp+6h]
lbl4Db:
    call mf4d
    mov sp,bp
    jmp near ptr lbl1A7f
    nop
    xor ax,ax
    push ax
    push word ptr [bp+8h]
    push word ptr [bp+6h]
    call mf61
    mov sp,bp
    mov ax,1h
    push ax
    mov ax,0Ah
    push ax
    jmp short lbl4Ab
    xor ax,ax
    push ax
    push word ptr [bp+8h]
    push word ptr [bp+6h]
    call mf7b
    add sp,6h
    mov ax,1h
    push ax
    mov ax,0Bh
    push ax
    push word ptr [bp+6h]
    call mf8e
    add sp,6h
    mov byte ptr ds:[316h],1h
    jmp near ptr lbl1A7f
    add word ptr ds:[2ACh],5h
    cmp word ptr ds:[2ACh],15h
    jl short lblFAf
    xor ax,ax
    push ax
    push word ptr [bp+8h]
    push word ptr [bp+6h]
    call mfb3
    add sp,6h
    xor ax,ax
    push ax
    mov cx,0Eh
    push cx
    push word ptr [bp+6h]
    call mfc5
    add sp,6h
    xor ax,ax
    push ax
    mov cx,0Fh
    push cx
    push word ptr [bp+6h]
    call mfd7
    add sp,6h
    mov ax,0Fh
    push ax
    call mfe3
    add sp,2h
    xor ax,ax
    push ax
    mov ax,0Fh
    push ax
    call mff2
    add sp,4h
lblFAb:
lblFAf:
    call mffa
    mov cx,5h
    sub dx,dx
    div cx
    mov word ptr ds:[2B0h],dx
    jmp near ptr lbl1A7f
    nop
    mov ax,word ptr ds:[2ACh]
    sub ax, offset mi111
    or ax,ax
    jng short lblFAb
    mov ax,word ptr ds:[2ACh]
    sub ax, offset mi11b
    mov word ptr ds:[2ACh],ax
    jmp short lblFAb
    nop
    xor ax,ax
    push ax
    push word ptr [bp+8h]
    push word ptr [bp+6h]
    call mf12d
    add sp,6h
    mov ax,1h
    push ax
    mov ax,11h
    push ax
    push word ptr [bp+6h]
    call mf140
    add sp,6h
    mov byte ptr ds:[31Ch],1h
    jmp short lbl1A7f
    nop
    mov ax,1h
    mov byte ptr ds:[320h],al
    push ax
    mov cx,3h
    push cx
    mov cx,8122h
    push cx
    call mf15f
    add sp,6h
    mov ax,1h
    push ax
    xor cx,cx
    push cx
    mov dx,8123h
    push dx
    call mf172
    add sp,6h
    mov ax,1h
    push ax
    mov cx,2h
    push cx
    mov cx,8126h
    push cx
    call mf186
    add sp,6h
    mov ax,1h
    push ax
    xor ax,ax
    push ax
    mov ax,8127h
    push ax
    jmp near ptr lbl4Db
    call mf19c
    and ax, offset mi1a1
    mov word ptr ds:[2B2h],ax
lbl1A7f:
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
