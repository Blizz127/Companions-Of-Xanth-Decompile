_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf29:FAR
    EXTRN mf53:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,0Ch
    push si
    xor ax,ax
    mov word ptr ds:[5E20h],ax
    mov word ptr [bp-2h],ax
    cmp word ptr ds:[5E1Ah],ax
    jz short lbl88f
    mov word ptr [bp-0Ch],ax
lbl18b:
    les bx, dword ptr ds:[5E16h]
    mov si,word ptr [bp-0Ch]
    mov ax,word ptr es:[bx+si]
    mov dx,word ptr es:[bx+si+2h]
    mov word ptr [bp-8h],ax
    mov word ptr [bp-6h],dx
    mov word ptr [bp-0Ah],3332h
lbl31b:
    mov al,byte ptr [bp-6h]
    mov bx,word ptr [bp-0Ah]
    sub ah,ah
    add ax,word ptr [bx]
    push ax
    mov al,byte ptr [bp-5h]
    sub ah,ah
    add ax,word ptr [bx+2h]
    push ax
    lea ax,word ptr [bp-8h]
    push ss
    push ax
    call mf29
    add sp,8h
    or ax,ax
    jnz short lbl64f
    add word ptr [bp-0Ah],4h
    cmp word ptr [bp-0Ah],3342h
    jc short lbl31b
    jmp short lbl79f
    nop
lbl64f:
    mov bx,word ptr ds:[5E20h]
    add bx,bx
    les si, dword ptr ds:[5E1Ch]
    mov ax,word ptr [bp-2h]
    inc ax
    mov word ptr es:[bx+si],ax
    inc word ptr ds:[5E20h]
lbl79f:
    add word ptr [bp-0Ch],4h
    mov ax,word ptr ds:[5E1Ah]
    inc word ptr [bp-2h]
    cmp word ptr [bp-2h],ax
    jc short lbl18b
lbl88f:
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
