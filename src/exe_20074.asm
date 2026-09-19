_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mjn1e:NEAR
mnem_unit:
    push bp
    mov bp,sp
    push ds
    lds dx, dword ptr [bp+6h]
    mov ax,4300h
    int 21h
    pop ds
    jc short lbl1Ef
    test byte ptr [bp+0Ah],2h
    jz short lbl1Ef
    test cl,1h
    jz short lbl1Ef
    mov ax,0D00h
    stc
lbl1Ef:
    jmp mjn1e
    add byte ptr [di-75h],dl
    in al,dx
    push ds
    test byte ptr [bp+0Ah],80h
    jz short lbl32f
    mov ah,3Ch
    sub cx,cx
    jmp short lbl37f
lbl32f:
    mov ah,3Dh
    mov al,byte ptr [bp+0Ah]
lbl37f:
    mov dx,word ptr [bp+8h]
    mov ds,dx
    mov dx,word ptr [bp+6h]
    int 21h
    jnc short lbl45f
    sub ax,ax
lbl45f:
    pop ds
    mov sp,bp
    pop bp
    retf
lblC9ECf:
_TEXT ENDS
    END
