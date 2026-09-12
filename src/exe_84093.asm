_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf25:FAR
    EXTRN mf44:FAR
    EXTRN mf59:FAR
    EXTRN mf64:FAR
    EXTRN mf69:FAR
    EXTRN mf74:FAR
    EXTRN mf79:FAR
    EXTRN mf84:FAR
    EXTRN mf89:FAR
    EXTRN mf94:FAR
    EXTRN mf99:FAR
    EXTRN mf104:FAR
    EXTRN mf117:FAR
    EXTRN mf132:FAR
    EXTRN mf141:FAR
    EXTRN mf155:FAR
    EXTRN mf176:FAR
    EXTRN mf184:FAR
    EXTRN mf186:FAR
    EXTRN mf200:FAR
    EXTRN mf203:FAR
    EXTRN mf223:FAR
    EXTRN mf226:FAR
    EXTRN mf243:FAR
    EXTRN mf243:FAR
    EXTRN mf243:FAR
    EXTRN mf243:FAR
    EXTRN mf243:FAR
    EXTRN mf243:FAR
    EXTRN mf243:FAR
    EXTRN mf243:FAR
    EXTRN mf243:FAR
    EXTRN mf243:FAR
    EXTRN mf243:FAR
    EXTRN mf243:FAR
    EXTRN mf243:FAR
    EXTRN mf243:FAR
    EXTRN mf243:FAR
    EXTRN mf243:FAR
    EXTRN mf243:FAR
    EXTRN mf243:FAR
    EXTRN mf243:FAR
    EXTRN mf243:FAR
    EXTRN mf243:FAR
    EXTRN mf243:FAR
    EXTRN mf243:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,12h
    push si
    mov word ptr [bp-10h],630Ch
lbl0Cb:
    mov bx,word ptr [bp-10h]
    mov word ptr [bp-6h],bx
    mov word ptr [bp-4h],ds
    cmp word ptr [bx],0h
    jz short lbl20f
    mov es, [bp-4h]
    inc word ptr es:[bx]
lbl20f:
    add word ptr [bp-10h],1Ah
    cmp word ptr [bp-10h],6340h
    jc short lbl0Cb
    mov word ptr [bp-12h],630Ch
lbl30b:
    mov al,byte ptr [bp+6h]
    mov bx,word ptr [bp-12h]
    mov word ptr [bp-6h],bx
    mov word ptr [bp-4h],ds
    cmp byte ptr [bx+3h],al
    jz short lbl70f
    add word ptr [bp-12h],1Ah
    cmp word ptr [bp-12h],6340h
    jc short lbl30b
    call mf25
    mov word ptr [bp-6h],ax
    mov word ptr [bp-4h],dx
    mov word ptr ds:[6340h],ax
    mov word ptr ds:[6342h],dx
    mov word ptr [bp-0Eh],0h
lbl63b:
    cmp word ptr [bp+6h],0FFFFFFFFFFFFFFFFh
    jnz short lbl84f
    mov word ptr [bp-2h],0h
    jmp short lbl96f
lbl70f:
    les bx, dword ptr [bp-6h]
    mov word ptr es:[bx],1h
    mov word ptr ds:[6340h],bx
    mov word ptr ds:[6342h],es
    jmp near ptr lbl2CDf
    nop
lbl84f:
    push word ptr [bp+6h]
    mov ax,2h
    push ax
    call mf44
    add sp,4h
    mov word ptr [bp-2h],ax
lbl96f:
    les bx, dword ptr [bp-6h]
    mov word ptr es:[bx],1h
    cmp word ptr [bp+6h],0FFFFFFFFFFFFFFFFh
    jnz short lblA7f
    jmp near ptr lbl298f
lblA7f:
    cmp word ptr [bp-2h],0h
    jnz short lblB0f
    jmp near ptr lbl298f
lblB0f:
    mov al,byte ptr [bp+6h]
    les bx, dword ptr [bp-6h]
    mov byte ptr es:[bx+3h],al
    push word ptr [bp-2h]
    call mf59
    add sp,2h
    les bx, dword ptr [bp-6h]
    mov byte ptr es:[bx+4h],al
    push word ptr [bp-2h]
    call mf64
    add sp,2h
    les bx, dword ptr [bp-6h]
    mov byte ptr es:[bx+5h],al
    push word ptr [bp-2h]
    call mf69
    add sp,2h
    les bx, dword ptr [bp-6h]
    mov byte ptr es:[bx+6h],al
    push word ptr [bp-2h]
    call mf74
    add sp,2h
    les bx, dword ptr [bp-6h]
    mov byte ptr es:[bx+7h],al
    push word ptr [bp-2h]
    call mf79
    add sp,2h
    les bx, dword ptr [bp-6h]
    mov byte ptr es:[bx+8h],al
    push word ptr [bp-2h]
    call mf84
    add sp,2h
    les bx, dword ptr [bp-6h]
    mov byte ptr es:[bx+9h],al
    push word ptr [bp-2h]
    call mf89
    add sp,2h
    les bx, dword ptr [bp-6h]
    mov byte ptr es:[bx+0Ah],al
    push word ptr [bp-2h]
    call mf94
    add sp,2h
    les bx, dword ptr [bp-6h]
    mov byte ptr es:[bx+0Bh],al
    push word ptr [bp-2h]
    call mf99
    add sp,2h
    les bx, dword ptr [bp-6h]
    mov byte ptr es:[bx+0Ch],al
    push word ptr [bp-2h]
    call mf104
    add sp,2h
    les bx, dword ptr [bp-6h]
    mov byte ptr es:[bx+0Dh],al
    mov al,byte ptr es:[bx+8h]
    sub ah,ah
    inc ax
    mov word ptr [bp-0Ch],ax
    cmp byte ptr es:[bx+0Bh],0h
    jnl short lbl1BCf
    cwd
    push dx
    push ax
    call mf117
    add sp,4h
    les bx, dword ptr [bp-6h]
    mov word ptr es:[bx+0Eh],ax
    mov word ptr es:[bx+10h],dx
    mov ax,dx
    or ax,word ptr es:[bx+0Eh]
    jnz short lbl1A0f
    jmp near ptr lbl248f
lbl1A0f:
    push word ptr [bp-0Ch]
    les bx, dword ptr [bp-6h]
    les bx, dword ptr es:[bx+0Eh]
    push word ptr es:[bx+2h]
    push word ptr es:[bx]
    push word ptr [bp-2h]
    call mf132
    add sp,8h
lbl1BCf:
    les bx, dword ptr [bp-6h]
    cmp byte ptr es:[bx+0Ch],0h
    jnl short lbl203f
    mov ax,word ptr [bp-0Ch]
    cwd
    push dx
    push ax
    call mf141
    add sp,4h
    les bx, dword ptr [bp-6h]
    mov word ptr es:[bx+12h],ax
    mov word ptr es:[bx+14h],dx
    mov ax,dx
    or ax,word ptr es:[bx+12h]
    jz short lbl248f
    push word ptr [bp-0Ch]
    les bx, dword ptr [bp-6h]
    les bx, dword ptr es:[bx+12h]
    push word ptr es:[bx+2h]
    push word ptr es:[bx]
    push word ptr [bp-2h]
    call mf155
    add sp,8h
lbl203f:
    les bx, dword ptr [bp-6h]
    mov al,byte ptr es:[bx+0Ah]
    cbw
    mov cx,ax
    mov al,byte ptr es:[bx+6h]
    cbw
    mov si,ax
    mov al,byte ptr es:[bx+8h]
    sub ah,ah
    mov dl,byte ptr es:[bx+7h]
    sub dh,dh
    sub ax,dx
    inc ax
    imul si
    imul cx
    mov word ptr [bp-0Ah],ax
    cwd
    push dx
    push ax
    call mf176
    add sp,4h
    les bx, dword ptr [bp-6h]
    mov word ptr es:[bx+16h],ax
    mov word ptr es:[bx+18h],dx
    mov ax,dx
    or ax,word ptr es:[bx+16h]
    jnz short lbl26Ef
lbl248f:
    call mf184
    push word ptr [bp-2h]
    call mf186
    add sp,2h
    cmp word ptr [bp-0Eh],0h
    jz short lbl266f
    mov word ptr [bp+6h],0FFFFh
    jmp near ptr lbl63b
lbl266f:
    mov word ptr [bp-0Eh],1h
    jmp near ptr lbl63b
lbl26Ef:
    push word ptr [bp-0Ah]
    les bx, dword ptr [bp-6h]
    les bx, dword ptr es:[bx+16h]
    push word ptr es:[bx+2h]
    push word ptr es:[bx]
    push word ptr [bp-2h]
    call mf200
    add sp,8h
    push word ptr [bp-2h]
    call mf203
    add sp,2h
    jmp short lbl2CDf
    nop
lbl298f:
    les bx, dword ptr [bp-6h]
    xor al,al
    mov byte ptr es:[bx+3h],0FFh
    mov byte ptr es:[bx+4h],al
    mov byte ptr es:[bx+5h],al
    mov byte ptr es:[bx+6h],al
    mov byte ptr es:[bx+7h],al
    mov byte ptr es:[bx+8h],0FFh
    mov byte ptr es:[bx+9h],al
    mov cl,8h
    mov byte ptr es:[bx+0Ah],cl
    mov byte ptr es:[bx+0Bh],cl
    mov byte ptr es:[bx+0Ch],al
    mov byte ptr es:[bx+0Dh],al
lbl2CDf:
    mov ax,4Dh
    push ax
    call mf223
    add sp,2h
    mov word ptr ds:[6D24h],ax
    call mf226
    mov word ptr ds:[69F8h],ax
    mov ax,word ptr ds:[6D24h]
    cwd
    sub ax,dx
    sar ax,1
    mov word ptr ds:[6DDAh],ax
    mov ax,word ptr ds:[69F8h]
    cwd
    sub ax,dx
    sar ax,1
    mov word ptr ds:[6D48h],ax
    mov ax,word ptr [bp-6h]
    mov dx,word ptr [bp-4h]
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
