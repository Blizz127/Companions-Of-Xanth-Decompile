_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi2:NEAR
    EXTRN mi9:NEAR
    EXTRN mi31:NEAR
    EXTRN mf46:FAR
    EXTRN mf52:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp, offset mi2
    push si
    push di
    mov bx,word ptr [bp+6h]
    mov es, ds:[5B36h]
    mov al,byte ptr es:[bx+1A6h]
    cbw
    cmp ax, offset mi9
    jnz short lbl1Ef
    jmp near ptr lbl21f
lbl1Ef:
    jmp near ptr lbl81f
lbl21f:
    mov ax,0Eh
    imul word ptr [bp+6h]
    mov bx,0h
    mov cx,2E8Eh
    add bx,ax
    mov es,cx
    mov al,byte ptr es:[bx+2h]
    cbw
    shl ax,1
    mov word ptr [bp-4h],ax
    mov ax,0Eh
    imul word ptr [bp+6h]
    mov bx,0h
    mov cx,2E8Eh
    add bx,ax
    mov es,cx
    mov al,byte ptr es:[bx+0Ch]
    cbw
    cmp ax, offset mi31
    jnz short lbl58f
    jmp near ptr lbl5Ef
lbl58f:
    mov ax,0h
    jmp near ptr lbl61f
lbl5Ef:
    mov ax,1h
lbl61f:
    or word ptr [bp-4h],ax
    mov ax,word ptr [bp-4h]
    push ax
    mov bx,word ptr [bp+6h]
    mov es, ds:[5B36h]
    mov al,byte ptr es:[bx+1B8h]
    cbw
    add ax,0C0h
    push ax
    call mf46
    add sp,4h
lbl81f:
    pop di
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
