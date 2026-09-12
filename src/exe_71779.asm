_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi2:NEAR
    EXTRN mi53:NEAR
    EXTRN mf58:FAR
    EXTRN mf60:FAR
    EXTRN mf67:FAR
    EXTRN mf67:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp, offset mi2
    push si
    push di
    les bx, dword ptr [bp+6h]
    mov al,byte ptr es:[bx+7h]
    and ax,0FFh
    les bx, dword ptr [bp+6h]
    mov cl,byte ptr es:[bx+6h]
    mov word ptr [bp-8h],ax
    mov ax,cx
    and ax,0FFh
    mov cx,8h
    shl ax,cl
    mov cx,word ptr [bp-8h]
    add ax,cx
    mov dx,0h
    mov word ptr [bp-6h],ax
    mov word ptr [bp-4h],dx
    les bx, dword ptr [bp+6h]
    mov al,byte ptr es:[bx+0Bh]
    and ax,0FFh
    les bx, dword ptr [bp+6h]
    mov cl,byte ptr es:[bx+0Ah]
    mov word ptr [bp-8h],ax
    mov ax,cx
    and ax,0FFh
    mov cx,8h
    shl ax,cl
    mov cx,word ptr [bp-8h]
    add ax,cx
    mov word ptr ds:[62AAh],ax
    les bx, dword ptr [bp+6h]
    mov al,byte ptr es:[bx+0Dh]
    and ax,0FFh
    les bx, dword ptr [bp+6h]
    mov cl,byte ptr es:[bx+0Ch]
    mov word ptr [bp-8h],ax
    mov ax,cx
    and ax,0FFh
    mov cx,8h
    shl ax,cl
    mov cx,word ptr [bp-8h]
    add ax,cx
    mov word ptr ds:[62ACh],ax
    cmp word ptr ds:[62AAh],8h
    jg short lbl8Bf
    jmp near ptr lbl91f
lbl8Bf:
    mov ax,0h
    jmp near ptr lblB9f
lbl91f:
    mov ax,word ptr [bp-6h]
    mov dx,word ptr [bp-4h]
    add ax, offset mi53
    adc dx,0h
    add word ptr [bp+6h],ax
    push word ptr [bp+8h]
    push word ptr [bp+6h]
    call mf58
    add sp,4h
    call mf60
    mov ax,1h
    jmp near ptr lblB9f
lblB9f:
    pop di
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
