_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi25:NEAR
    EXTRN mi61:NEAR
    EXTRN mf65:FAR
    EXTRN mf90:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,6h
    push di
    push si
    mov ax,word ptr [bp+6h]
    mov dx,word ptr [bp+8h]
    shr dx,1
    rcr ax,1
    rcr dx,1
    rcr ax,1
    rcr dx,1
    rcr ax,1
    rcr dx,1
    rcr ax,1
    rcr dx,1
    xchg ax,dx
    and ax,0F000h
    mov word ptr [bp+6h],ax
    mov word ptr [bp+8h],dx
    mov word ptr [bp-2h],1h
    cmp word ptr ds:[4DAEh],1h
    jng short lbl6Bf
    mov ax,word ptr ds:[63DCh]
    mov dx,word ptr ds:[63DEh]
    add ax, offset mi25
    mov word ptr [bp-6h],ax
    mov word ptr [bp-4h],dx
lbl46b:
    mov ax,word ptr [bp+6h]
    mov dx,word ptr [bp+8h]
    les bx, dword ptr [bp-6h]
    cmp word ptr es:[bx+2h],dx
    ja short lbl6Bf
    jc short lbl5Cf
    cmp word ptr es:[bx],ax
    jnc short lbl6Bf
lbl5Cf:
    add word ptr [bp-6h],0Ch
    mov ax,word ptr ds:[4DAEh]
    inc word ptr [bp-2h]
    cmp word ptr [bp-2h],ax
    jl short lbl46b
lbl6Bf:
    mov ax,word ptr ds:[4DAEh]
    sub ax,word ptr [bp-2h]
    inc ax
    mov cx,ax
    add ax,ax
    add ax,cx
    add ax,ax
    add ax,ax
    push ax
    mov ax,word ptr [bp-2h]
    mov cx,ax
    add ax,ax
    add ax,cx
    add ax,ax
    add ax,ax
    mov cx,ax
    add ax,word ptr ds:[63DCh]
    mov dx,word ptr ds:[63DEh]
    push dx
    push ax
    add ax, offset mi61
    push dx
    push ax
    mov si,cx
    call mf65
    add sp,0Ah
    inc word ptr ds:[4DAEh]
    les bx, dword ptr ds:[63DCh]
    xor ax,ax
    mov cx,6h
    lea di,word ptr [bx+si]
    rep stosw
    mov bx,word ptr ds:[63DCh]
    mov ax,word ptr [bp+6h]
    mov dx,word ptr [bp+8h]
    mov word ptr es:[bx+si],ax
    mov word ptr es:[bx+si+2h],dx
    les bx, dword ptr ds:[63DCh]
    mov ax,word ptr [bp+0Ah]
    mov dx,word ptr [bp+0Ch]
    mov word ptr es:[bx+si+6h],ax
    mov word ptr es:[bx+si+8h],dx
    mov ax,si
    add ax,word ptr ds:[63DCh]
    mov dx,word ptr ds:[63DEh]
    pop si
    pop di
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
