_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf30:FAR
    EXTRN mf50:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,2h
    push di
    push si
    xor di,di
    mov ax,word ptr [bp+4h]
    mov bx,ax
    mov si,ax
    mov cl,byte ptr [bx+0Ah]
    mov dx,cx
    and cl,3h
    cmp cl,2h
    jnz short lbl67f
    test dl,8h
    jnz short lbl2Ef
    sub bx,5420h
    test byte ptr [bx+5510h],1h
    jz short lbl67f
lbl2Ef:
    mov ax,word ptr [si]
    sub ax,word ptr [si+6h]
    mov word ptr [bp-2h],ax
    or ax,ax
    jng short lbl67f
    push ax
    push word ptr [si+8h]
    push word ptr [si+6h]
    mov al,byte ptr [si+0Bh]
    sub ah,ah
    push ax
    call mf30
    add sp,8h
    cmp ax,word ptr [bp-2h]
    jnz short lbl60f
    test byte ptr [si+0Ah],80h
    jz short lbl67f
    and byte ptr [si+0Ah],0FDh
    jmp short lbl67f
lbl60f:
    or byte ptr [si+0Ah],20h
    mov di,0FFFFh
lbl67f:
    mov ax,word ptr [si+6h]
    mov dx,word ptr [si+8h]
    mov word ptr [si],ax
    mov word ptr [si+2h],dx
    mov word ptr [si+4h],0h
    mov ax,di
    pop si
    pop di
    mov sp,bp
    pop bp
    ret
_TEXT ENDS
    END
