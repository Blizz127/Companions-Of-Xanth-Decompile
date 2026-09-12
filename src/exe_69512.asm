_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi2:NEAR
    EXTRN mi11:NEAR
    EXTRN mf36:FAR
    EXTRN mf46:FAR
    EXTRN mf56:FAR
    EXTRN mf62:FAR
    EXTRN mf62:FAR
    EXTRN mf62:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp, offset mi2
    push si
    push di
    cmp word ptr [bp+6h],1h
    jz short lbl12f
    jmp near ptr lbl68f
lbl12f:
    mov word ptr [bp-3Ch],0h
    jmp near ptr lbl43f
lbl1Ab:
    mov ax,word ptr [bp-3Ch]
    add ax, offset mi11
    mov bx,word ptr [bp+8h]
    mov cx,word ptr [bp+0Ah]
    add bx,ax
    mov es,cx
    mov al,byte ptr es:[bx]
    and ax,0FFh
    and ax,0FFh
    mov dx,word ptr [bp-3Ch]
    shl dx,1
    lea bx,word ptr [bp-3Ah]
    add bx,dx
    mov word ptr [bx],ax
    add word ptr [bp-3Ch],1h
lbl43f:
    cmp word ptr [bp-3Ch],1Ch
    jnl short lbl4Cf
    jmp near ptr lbl1Ab
lbl4Cf:
    lea ax,word ptr [bp-3Ah]
    mov dx,ss
    push dx
    push ax
    les bx, dword ptr [bp+8h]
    mov al,byte ptr es:[bx]
    and ax,0FFh
    push ax
    call mf36
    add sp,6h
    jmp near ptr lblA1f
lbl68f:
    cmp word ptr [bp+6h],2h
    jz short lbl71f
    jmp near ptr lbl86f
lbl71f:
    les bx, dword ptr [bp+8h]
    mov al,byte ptr es:[bx]
    and ax,0FFh
    push ax
    call mf46
    add sp,2h
    jmp near ptr lblA1f
lbl86f:
    cmp word ptr [bp+6h],3h
    jz short lbl8Ff
    jmp near ptr lblA1f
lbl8Ff:
    les bx, dword ptr [bp+8h]
    mov al,byte ptr es:[bx]
    and ax,0FFh
    push ax
    call mf56
    add sp,2h
lblA1f:
    pop di
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
