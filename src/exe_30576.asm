_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mn47:NEAR
    EXTRN mi69:NEAR
    EXTRN mn79:NEAR
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
    les di, dword ptr [bp+0Ah]
    mov word ptr es:[di],2h
    les di, dword ptr [bp+6h]
    mov word ptr es:[di],0h
    mov word ptr [bp-2h],0h
    mov ax,word ptr [bp-2h]
    pop di
    pop si
    pop es
    pop ds
    mov sp,bp
    pop bp
    retf 8h
    push bp
    mov bp,sp
    sub sp,4h
    push ds
    push es
    push si
    push di
    mov ax,38AFh
    mov ds,ax
    mov si,word ptr [bp+6h]
    cmp si,0h
    jna short lbl50f
    mov word ptr [bp-2h],0FFFAh
    jmp short lbl74f
    nop
lbl50f:
    mov ax,word ptr ds:[524Ah]
    mov word ptr [bp-4h],ax
    mov ax,38AFh
    mov ds,ax
    mov ax,word ptr [bp-4h]
    mov word ptr ds:[524Ah],ax
    mov ax,word ptr [bp+6h]
    mov word ptr ds:[5242h],ax
    push ax
    push cs
    call mn47
    mov word ptr ds:[5244h],ax
    mov word ptr [bp-2h],0h
lbl74f:
    mov ax,word ptr [bp-2h]
    pop di
    pop si
    pop es
    pop ds
    mov sp,bp
    pop bp
    retf 2h
    push bp
    mov bp,sp
    sub sp,2h
    push ds
    push es
    push si
    push di
    mov ax,38AFh
    mov ds,ax
    mov word ptr [bp-2h],0FFFAh
    mov ax,word ptr ds:[5242h]
    cmp ax, offset mi69
    ja short lblA0f
    mov word ptr [bp-2h],ax
lblA0f:
    mov ax,word ptr [bp-2h]
    pop di
    pop si
    pop es
    pop ds
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
