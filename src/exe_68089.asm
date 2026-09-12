_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi2:NEAR
    EXTRN mf20:FAR
    EXTRN mf24:FAR
    EXTRN mf44:FAR
    EXTRN mf53:FAR
    EXTRN mf62:FAR
    EXTRN mi105:NEAR
    EXTRN mf116:FAR
    EXTRN mf121:FAR
    EXTRN mf128:FAR
    EXTRN mf128:FAR
    EXTRN mf128:FAR
    EXTRN mf128:FAR
    EXTRN mf128:FAR
    EXTRN mf128:FAR
    EXTRN mf128:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp, offset mi2
    push si
    push di
    les bx, dword ptr ds:[6DE6h]
    mov ax,word ptr es:[bx]
    mov dx,word ptr es:[bx+2h]
    mov word ptr [bp-8h],ax
    mov word ptr [bp-6h],dx
    mov word ptr [bp-4h],0h
    jmp near ptr lbl52f
lbl22b:
    mov bx,word ptr [bp-4h]
    shl bx,1
    mov es, ds:[5B38h]
    mov word ptr es:[bx+48D8h],0h
    mov ax,0h
    push ax
    mov ax,word ptr [bp-4h]
    push ax
    call mf20
    add sp,4h
    mov ax,word ptr [bp-4h]
    push ax
    call mf24
    add sp,2h
    add word ptr [bp-4h],1h
lbl52f:
    cmp word ptr [bp-4h],0Bh
    jnl short lbl5Bf
    jmp near ptr lbl22b
lbl5Bf:
    mov word ptr ds:[40F4h],0h
    mov word ptr ds:[40F6h],0h
    les bx, dword ptr [bp-8h]
    mov al,byte ptr es:[bx+7h]
    and ax,0FFh
    cwd
    les bx, dword ptr [bp-8h]
    mov cl,byte ptr es:[bx+6h]
    mov word ptr [bp-12h],ax
    mov word ptr [bp-10h],dx
    mov ax,cx
    and ax,0FFh
    mov dx,0h
    mov cx,8h
    call mf44
    les bx, dword ptr [bp-8h]
    mov cl,byte ptr es:[bx+5h]
    mov word ptr [bp-16h],ax
    mov word ptr [bp-14h],dx
    mov ax,cx
    and ax,0FFh
    mov dx,0h
    mov cx,10h
    call mf53
    les bx, dword ptr [bp-8h]
    mov cl,byte ptr es:[bx+4h]
    mov word ptr [bp-1Ah],ax
    mov word ptr [bp-18h],dx
    mov ax,cx
    and ax,0FFh
    mov dx,0h
    mov cx,18h
    call mf62
    mov cx,word ptr [bp-1Ah]
    mov bx,word ptr [bp-18h]
    add ax,cx
    adc dx,bx
    mov cx,word ptr [bp-16h]
    mov bx,word ptr [bp-14h]
    add ax,cx
    adc dx,bx
    mov cx,word ptr [bp-12h]
    mov bx,word ptr [bp-10h]
    add ax,cx
    adc dx,bx
    mov word ptr [bp-0Ch],ax
    mov word ptr [bp-0Ah],dx
    les bx, dword ptr [bp-8h]
    mov al,byte ptr es:[bx+0Bh]
    and ax,0FFh
    les bx, dword ptr [bp-8h]
    mov cl,byte ptr es:[bx+0Ah]
    mov word ptr [bp-10h],ax
    mov ax,cx
    and ax,0FFh
    mov cx,8h
    shl ax,cl
    mov cx,word ptr [bp-10h]
    add ax,cx
    mov word ptr [bp-0Eh],ax
    les bx, dword ptr [bp-8h]
    mov al,byte ptr es:[bx+0Dh]
    and ax,0FFh
    les bx, dword ptr [bp-8h]
    mov cl,byte ptr es:[bx+0Ch]
    mov word ptr [bp-10h],ax
    mov ax,cx
    and ax,0FFh
    mov cx,8h
    shl ax,cl
    mov cx,word ptr [bp-10h]
    add ax,cx
    mov word ptr ds:[6286h],ax
    mov ax,word ptr [bp-0Ch]
    mov dx,word ptr [bp-0Ah]
    add ax, offset mi105
    adc dx,0h
    add word ptr [bp-8h],ax
    les bx, dword ptr ds:[6DE6h]
    mov ax,word ptr es:[bx]
    mov dx,word ptr es:[bx+2h]
    mov cx,word ptr [bp-8h]
    mov dx,word ptr [bp-6h]
    sub cx,ax
    add cx,8h
    mov word ptr ds:[627Ch],cx
    call mf116
    mov word ptr ds:[6280h],ax
    mov word ptr ds:[6282h],dx
    mov ax,0h
    push ax
    call mf121
    add sp,2h
    mov byte ptr ds:[627Eh],al
    pop di
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
