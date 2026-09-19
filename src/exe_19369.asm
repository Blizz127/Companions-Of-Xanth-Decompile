_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mn62:NEAR
    EXTRN mn67:NEAR
mnem_unit:
    push bp
    mov bp,sp
    push si
    push di
lbl05b:
    mov cx,word ptr [bp+6h]
    cmp cx,0FFFFFFFFFFFFFFE8h
    ja short lbl76f
    push ds
    mov ax,word ptr ds:[581Ch]
    or ax,ax
    jz short lbl5Df
    mov di,446Ch
lbl18b:
    mov si,word ptr ds:[5824h]
    lds bx, dword ptr ds:[581Eh]
lbl20b:
    push ds
lbl21b:
    push si
    push di
    call di
    pop di
    pop si
    jnc short lbl54f
    mov dx,ds
    lds bx, dword ptr [bx+0Ch]
    cmp dx,si
    jnz short lbl21b
    pop ax
    pop ds
    push ds
    les si, dword ptr ds:[581Eh]
    mov si,word ptr es:[si+12h]
    lds bx, dword ptr ds:[581Ah]
    mov dx,ds
    cmp dx,ax
    jnz short lbl20b
    pop ds
    push ds
    cmp di,2D42h
    jz short lbl5Df
    mov di,2D42h
    jmp short lbl18b
lbl54f:
    pop si
    cmp di,446Ch
    jz short lbl6Af
    jmp short lbl67f
lbl5Df:
    pop es
    push es
    mov di,581Ah
    call mn62
    jc short lbl75f
lbl67f:
    call mn67
lbl6Af:
    pop ds
    mov word ptr ds:[5820h],dx
    mov word ptr ds:[581Eh],bx
    jmp short lbl95f
lbl75f:
    pop ds
lbl76f:
    xor ax,ax
    cwd
    mov cx,word ptr ds:[5818h]
    or cx,word ptr ds:[5816h]
    jz short lbl95f
    push word ptr [bp+6h]
    db 0FFh, 1Eh, 16h, 58h ; override
    add sp,2h
    cwd
    or ax,ax
    jz short lbl95f
    jmp near ptr lbl05b
lbl95f:
    pop di
    pop si
    pop bp
    retf
_TEXT ENDS
    END
