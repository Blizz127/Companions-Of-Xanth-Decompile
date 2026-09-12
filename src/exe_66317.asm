_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi2:NEAR
    EXTRN mf33:FAR
    EXTRN mf39:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp, offset mi2
    push si
    push di
    mov word ptr [bp-4h],0h
    mov ax,0Eh
    imul word ptr [bp+6h]
    mov cx,0h
    mov dx,2E8Eh
    add cx,ax
    mov word ptr [bp-8h],cx
    mov word ptr [bp-6h],dx
    mov ax,cx
    jmp near ptr lbl45f
lbl27b:
    mov bx,word ptr [bp+8h]
    mov es, [bp+0Ah]
    add word ptr [bp+8h],2h
    mov ax,word ptr es:[bx]
    mov bx,word ptr [bp-8h]
    mov es, [bp-6h]
    add word ptr [bp-8h],1h
    mov byte ptr es:[bx],al
    add word ptr [bp-4h],1h
lbl45f:
    cmp word ptr [bp-4h],0Dh
    jnl short lbl4Ef
    jmp near ptr lbl27b
lbl4Ef:
    and word ptr [bp+0Ch],3h
    mov ax,word ptr [bp+0Ch]
    les bx, dword ptr [bp-8h]
    mov byte ptr es:[bx],al
    mov ax,word ptr [bp+6h]
    push ax
    call mf33
    add sp,2h
    pop di
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
