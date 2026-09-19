_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
mnem_unit:
    push bp
    mov bp,sp
    mov dx,si
    push ds
    lds si, dword ptr [bp+0Ah]
    les bx, dword ptr [bp+6h]
    mov al,0FFh
lbl0Eb:
    or al,al
    jz short lbl3Ff
    lodsb
    mov ah,byte ptr es:[bx]
    inc bx
    cmp ah,al
    jz short lbl0Eb
    sub al,41h
    cmp al,1Ah
    db 1Ah, 0C9h ; override
    and cl,20h
    add al,cl
    add al,41h
    db 86h, 0E0h ; override
    sub al,41h
    cmp al,1Ah
    db 1Ah, 0C9h ; override
    and cl,20h
    add al,cl
    add al,41h
    cmp al,ah
    jz short lbl0Eb
    db 1Ah, 0C0h ; override
    sbb al,0FFh
lbl3Ff:
    cbw
    pop ds
    mov si,dx
    pop bp
    retf
_TEXT ENDS
    END
