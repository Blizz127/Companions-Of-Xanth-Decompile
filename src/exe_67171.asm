_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi2:NEAR
    EXTRN mi26:NEAR
    EXTRN mf36:FAR
    EXTRN mf42:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp, offset mi2
    push si
    push di
    mov ax,0Eh
    imul word ptr [bp+6h]
    mov bx,0h
    mov cx,2E8Eh
    add bx,ax
    mov es,cx
    mov al,byte ptr es:[bx+4h]
    cbw
    shl ax,1
    shl ax,1
    shl ax,1
    shl ax,1
    mov word ptr [bp-4h],ax
    mov ax,0Eh
    imul word ptr [bp+6h]
    mov bx,0h
    mov cx,2E8Eh
    add bx,ax
    mov es,cx
    mov al,byte ptr es:[bx+7h]
    cbw
    and ax, offset mi26
    or word ptr [bp-4h],ax
    mov ax,word ptr [bp-4h]
    push ax
    mov bx,word ptr [bp+6h]
    mov es, ds:[5B36h]
    mov al,byte ptr es:[bx+194h]
    cbw
    add ax,80h
    push ax
    call mf36
    add sp,4h
    pop di
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
