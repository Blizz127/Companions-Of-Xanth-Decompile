_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf31:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,4h
    push di
    push si
    mov bx,word ptr [bp+6h]
    add bx,bx
    add bx,bx
    les bx, dword ptr [bx+4264h]
    mov word ptr [bp-4h],bx
    mov word ptr [bp-2h],es
    cmp byte ptr es:[bx],0h
    jz short lbl3Cf
    push word ptr [bp+0Ah]
    push word ptr [bp+8h]
    push es
    push bx
    mov ax,4284h
    push ds
    push ax
    mov ax,62DCh
    push ds
    push ax
    call mf31
    add sp,10h
    jmp short lbl5Df
    nop
lbl3Cf:
    mov si,62DCh
    push ds
    les di, dword ptr [bp+8h]
    mov cx,0FFFFh
    xor ax,ax
    repne scasb
    not cx
    sub di,cx
    db 87h, 0FEh ; override
    push ds
    push es
    pop ds
    pop es
    shr cx,1
    rep movsw
    adc cx,cx
    rep movsb
    pop ds
lbl5Df:
    mov ax,62DCh
    mov dx,ds
    pop si
    pop di
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
