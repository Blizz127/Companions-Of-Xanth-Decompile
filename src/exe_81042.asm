_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi2:NEAR
    EXTRN mf5:FAR
    EXTRN md12:NEAR
    EXTRN md13:NEAR
    EXTRN mf14:FAR
    EXTRN md20:NEAR
    EXTRN md21:NEAR
    EXTRN mi24:NEAR
    EXTRN mf31:FAR
    EXTRN mf31:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp, offset mi2
    push si
    push di
    call mf5
    mov word ptr [bp-4h],0h
    jmp near ptr lbl50f
lbl16b:
    mov bx,word ptr [bp-4h]
    shl bx,1
    shl bx,1
    mov es, ds:[5B44h]
    push word ptr es:[bx+md12]
    push word ptr es:[bx+md13]
    call mf14
    add sp,4h
    mov bx,word ptr [bp-4h]
    shl bx,1
    shl bx,1
    mov es, ds:[5B44h]
    mov word ptr es:[bx+md20],0h
    mov word ptr es:[bx+md21],0h
    add word ptr [bp-4h],1h
lbl50f:
    mov ax,word ptr [bp-4h]
    cmp ax, offset mi24
    jnc short lbl5Bf
    jmp near ptr lbl16b
lbl5Bf:
    pop di
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
