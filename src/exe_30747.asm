_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mn11:NEAR
    EXTRN mn29:NEAR
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
    push word ptr [bp+0Ah]
    push cs
    call mn11
    jnc short lbl1Df
    mov word ptr [bp-2h],ax
    jmp short lbl2Ff
lbl1Df:
    mov ds,dx
    mov si,ax
    les di, dword ptr [bp+6h]
    mov cx,26h
    cld
    rep movsb
    mov word ptr [bp-2h],0h
lbl2Ff:
    mov ax,word ptr [bp-2h]
    pop di
    pop si
    pop es
    pop ds
    mov sp,bp
    pop bp
    retf 6h
_TEXT ENDS
    END
