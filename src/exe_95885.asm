_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
mnem_unit:
    push bp
    mov bp,sp
    sub sp,8h
    push di
    test word ptr [bp+0Eh],0FFFFh
    jz short lbl48f
    mov ax,word ptr [bp+6h]
    mov dx,word ptr [bp+8h]
    mov word ptr [bp-4h],ax
    mov word ptr [bp-2h],dx
lbl1Ab:
    mov ax,word ptr [bp+0Ch]
    mov dx,word ptr [bp+0Eh]
    sub word ptr [bp+0Ch],1h
    sbb word ptr [bp+0Eh],0h
    or dx,dx
    jl short lbl61f
    jg short lbl32f
    or ax,ax
    jz short lbl61f
lbl32f:
    mov al,byte ptr [bp+0Ah]
    les bx, dword ptr [bp-4h]
    add word ptr [bp-4h],1h
    jnc short lbl43f
    add word ptr [bp-2h],1000h
lbl43f:
    mov byte ptr es:[bx],al
    jmp short lbl1Ab
lbl48f:
    mov al,byte ptr [bp+0Ah]
    mov cx,word ptr [bp+0Ch]
    mov bx,word ptr [bp+6h]
    mov dx,word ptr [bp+8h]
    mov di,bx
    mov es,dx
    mov ah,al
    shr cx,1
    rep stosw
    jnc short lbl61f
    stosb
lbl61f:
    pop di
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
