_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mn28:NEAR
    EXTRN mn32:NEAR
    EXTRN mn78:NEAR
    EXTRN mn78:NEAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,4h
    push ds
    mov es, ds:[53C0h]
    mov bx,word ptr es:[2Ch]
    mov es,bx
    mov word ptr [bp-2h],es
    xor ax,ax
    xor si,si
    xor di,di
    mov cx,0FFFFh
    or bx,bx
    jz short lbl30f
    cmp byte ptr es:[0h],0h
    jz short lbl30f
lbl2Ab:
    repne scasb
    inc si
    scasb
    jnz short lbl2Ab
lbl30f:
    mov ax,di
    inc ax
    and al,0FEh
    inc si
    mov di,si
    shl si,1
    shl si,1
    mov cx,9h
    call mn28
    push dx
    push ax
    mov ax,si
    call mn32
    mov word ptr ds:[53E6h],ax
    mov word ptr ds:[53E8h],dx
    mov word ptr [bp-4h],dx
    push es
    pop ds
    mov cx,di
    mov bx,ax
    xor si,si
    pop di
    pop es
    dec cx
    jcxz lbl93f
lbl60b:
    mov ax,word ptr [si]
    cmp ax,word ptr ss:[539Eh]
    jnz short lbl7Df
    push cx
    push si
    push di
    push es
    push ss
    pop es
    mov di,539Eh
    mov cx,6h
    repe cmpsw
    pop es
    pop di
    pop si
    pop cx
    jz short lbl88f
lbl7Df:
    mov ds, [bp-4h]
    mov word ptr [bx],di
    mov word ptr [bx+2h],es
    add bx,4h
lbl88f:
    mov ds, [bp-2h]
lbl8Bb:
    lodsb
    stosb
    or al,al
    jnz short lbl8Bb
    loop lbl60b
lbl93f:
    mov ds, [bp-4h]
    mov word ptr [bx],cx
    mov word ptr [bx+2h],cx
    pop ds
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
