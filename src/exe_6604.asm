_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mn8:NEAR
    EXTRN mf18:FAR
    EXTRN mn24:NEAR
    EXTRN mn31:NEAR
    EXTRN mf31:FAR
    EXTRN mn31:NEAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,6h
    push di
    push si
    mov si,word ptr [bp+6h]
    push ds
    push si
    call mn8
    add sp,4h
    mov di,ax
    lea ax,word ptr [bp+0Eh]
    push ss
    push ax
    push word ptr [bp+0Ch]
    push word ptr [bp+0Ah]
    push ds
    push si
    call mf18
    add sp,0Ch
    mov word ptr [bp-6h],ax
    push ds
    push si
    push di
    call mn24
    add sp,6h
    mov ax,word ptr [bp-6h]
    pop si
    pop di
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
