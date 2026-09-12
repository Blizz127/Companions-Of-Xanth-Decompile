_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mn7:NEAR
    EXTRN mf18:FAR
    EXTRN mn25:NEAR
    EXTRN mn31:NEAR
    EXTRN mf31:FAR
    EXTRN mn31:NEAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,6h
    push di
    mov ax,542Ch
    push ds
    push ax
    call mn7
    add sp,4h
    mov di,ax
    lea ax,word ptr [bp+0Ah]
    push ss
    push ax
    push word ptr [bp+8h]
    push word ptr [bp+6h]
    mov ax,542Ch
    push ds
    push ax
    call mf18
    add sp,0Ch
    mov word ptr [bp-6h],ax
    mov ax,542Ch
    push ds
    push ax
    push di
    call mn25
    add sp,6h
    mov ax,word ptr [bp-6h]
    pop di
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
