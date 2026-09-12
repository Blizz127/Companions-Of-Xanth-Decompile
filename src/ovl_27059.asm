_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf7:FAR
    EXTRN mf12:FAR
    EXTRN mi21:NEAR
    EXTRN mf32:FAR
    EXTRN mf38:FAR
    EXTRN md48:NEAR
    EXTRN md49:NEAR
    EXTRN mf64:FAR
    EXTRN mf69:FAR
    EXTRN mf69:FAR
    EXTRN mf69:FAR
    EXTRN mf69:FAR
    EXTRN mf69:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,0Ah
    push si
    lea ax,word ptr [bp-8h]
    push ss
    push ax
    call mf7
    add sp,4h
    lea ax,word ptr [bp-8h]
    push ss
    push ax
    call mf12
    add sp,4h
    mov es,dx
    mov bx,ax
    mov word ptr [bp-4h],ax
    mov word ptr [bp-2h],es
    cmp word ptr es:[bx+4h],0Ch
    jng short lbl3Cf
    mov ax,word ptr es:[bx+4h]
    sub ax, offset mi21
    jmp short lbl42f
    nop
lbl3Cf:
    mov bx,ax
    mov ax,word ptr es:[bx+4h]
lbl42f:
    mov word ptr [bp-0Ah],ax
    mov bx,word ptr [bp-4h]
    mov ax,word ptr es:[bx+0Ah]
    add ax,76Ch
    push ax
    push word ptr es:[bx+8h]
    call mf32
    add sp,2h
    push dx
    push ax
    les bx, dword ptr [bp-4h]
    push word ptr es:[bx+6h]
    call mf38
    add sp,2h
    push dx
    push ax
    les bx, dword ptr [bp-4h]
    push word ptr es:[bx+6h]
    mov si,word ptr es:[bx+0Ch]
    mov es, ds:[5A84h]
    add si,si
    add si,si
    push word ptr es:[si+md48]
    push word ptr es:[si+md49]
    mov es, [bp-2h]
    cmp word ptr es:[bx+4h],0Ch
    jng short lbl9Cf
    mov ax,70h
    jmp short lbl9Ff
    nop
lbl9Cf:
    mov ax,61h
lbl9Ff:
    push ax
    push word ptr es:[bx+2h]
    push word ptr [bp-0Ah]
    mov ax,1Ch
    mov cx,314Fh
    push cx
    push ax
    call mf64
    add sp,1Ah
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
