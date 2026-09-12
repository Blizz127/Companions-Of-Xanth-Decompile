_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf8:FAR
    EXTRN mf104:FAR
    EXTRN mf122:FAR
    EXTRN mf148:FAR
    EXTRN mf168:FAR
    EXTRN mf197:FAR
    EXTRN mf200:FAR
    EXTRN mf200:FAR
    EXTRN mf200:FAR
    EXTRN mf200:FAR
    EXTRN mf200:FAR
    EXTRN mf200:FAR
mnem_unit:
    push bp
    mov bp,sp
    les bx, dword ptr [bp+6h]
    push word ptr es:[bx]
    push word ptr [bp+0Ch]
    push word ptr [bp+0Ah]
    push word ptr ds:[644Ch]
    push word ptr ds:[644Ah]
    call mf8
    les bx, dword ptr [bp+6h]
    sub dx,dx
    mov ax,word ptr es:[bx]
    sub bx,bx
    mov cx,ax
    add word ptr ds:[644Ah],cx
    adc bx,dx
    mov cx,0Ch
    shl bx,cl
    add word ptr ds:[644Ch],bx
    mov sp,bp
    pop bp
    retf 8h
    push bp
    mov bp,sp
    sub sp,6h
    push di
    push si
    mov ax,word ptr [bp+0Ah]
    mov dx,word ptr [bp+0Ch]
    mov word ptr [bp-4h],ax
    mov word ptr [bp-2h],dx
    les bx, dword ptr [bp+6h]
    mov ax,word ptr es:[bx]
    mov word ptr [bp-6h],ax
    cmp ax,word ptr ds:[6454h]
    jc short lbl9Ff
lbl60b:
    mov ax,word ptr ds:[6450h]
    mov dx,word ptr ds:[6452h]
    mov bx,word ptr [bp-4h]
    mov si,word ptr [bp-2h]
    mov cx,word ptr ds:[6454h]
    push ds
    push si
    mov di,ax
    mov si,bx
    mov es,dx
    pop ds
    shr cx,1
    rep movsw
    adc cx,cx
    rep movsb
    pop ds
    mov ax,word ptr ds:[6454h]
    add word ptr [bp-4h],ax
    sub word ptr [bp-6h],ax
    add ax,word ptr ds:[6458h]
    add word ptr ds:[6450h],ax
    mov ax,word ptr ds:[6456h]
    mov word ptr ds:[6454h],ax
    cmp ax,word ptr [bp-6h]
    jna short lbl60b
lbl9Ff:
    cmp word ptr [bp-6h],0h
    jz short lblD2f
    mov ax,word ptr ds:[6450h]
    mov dx,word ptr ds:[6452h]
    mov bx,word ptr [bp-4h]
    mov si,word ptr [bp-2h]
    mov cx,word ptr [bp-6h]
    push ds
    push si
    mov di,ax
    mov si,bx
    mov es,dx
    pop ds
    shr cx,1
    rep movsw
    adc cx,cx
    rep movsb
    pop ds
    mov ax,word ptr [bp-6h]
    add word ptr ds:[6450h],ax
    sub word ptr ds:[6454h],ax
lblD2f:
    pop si
    pop di
    mov sp,bp
    pop bp
    retf 8h
    push bp
    mov bp,sp
    sub sp,6h
    mov ax,word ptr [bp+0Ah]
    mov dx,word ptr [bp+0Ch]
    mov word ptr [bp-4h],ax
    mov word ptr [bp-2h],dx
    les bx, dword ptr [bp+6h]
    mov ax,word ptr es:[bx]
    mov word ptr [bp-6h],ax
    cmp ax,word ptr ds:[6454h]
    jc short lbl131f
lblFBb:
    push word ptr ds:[6454h]
    push word ptr [bp-2h]
    push word ptr [bp-4h]
    push word ptr ds:[6452h]
    push word ptr ds:[6450h]
    call mf104
    add sp,0Ah
    mov ax,word ptr ds:[6454h]
    add word ptr [bp-4h],ax
    sub word ptr [bp-6h],ax
    add ax,word ptr ds:[6458h]
    add word ptr ds:[6450h],ax
    mov ax,word ptr ds:[6456h]
    mov word ptr ds:[6454h],ax
    cmp ax,word ptr [bp-6h]
    jna short lblFBb
lbl131f:
    cmp word ptr [bp-6h],0h
    jz short lbl158f
    push word ptr [bp-6h]
    push word ptr [bp-2h]
    push word ptr [bp-4h]
    push word ptr ds:[6452h]
    push word ptr ds:[6450h]
    call mf122
    mov ax,word ptr [bp-6h]
    add word ptr ds:[6450h],ax
    sub word ptr ds:[6454h],ax
lbl158f:
    mov sp,bp
    pop bp
    retf 8h
    push bp
    mov bp,sp
    sub sp,6h
    mov ax,word ptr [bp+0Ah]
    mov dx,word ptr [bp+0Ch]
    mov word ptr [bp-4h],ax
    mov word ptr [bp-2h],dx
    les bx, dword ptr [bp+6h]
    mov ax,word ptr es:[bx]
    mov word ptr [bp-6h],ax
    cmp ax,word ptr ds:[6454h]
    jc short lbl1B9f
lbl17Fb:
    mov ax,0FEh
    push ax
    push word ptr ds:[6454h]
    push word ptr [bp-2h]
    push word ptr [bp-4h]
    push word ptr ds:[6452h]
    push word ptr ds:[6450h]
    call mf148
    add sp,0Ch
    mov ax,word ptr ds:[6454h]
    add word ptr [bp-4h],ax
    sub word ptr [bp-6h],ax
    add ax,word ptr ds:[6458h]
    add word ptr ds:[6450h],ax
    mov ax,word ptr ds:[6456h]
    mov word ptr ds:[6454h],ax
    cmp ax,word ptr [bp-6h]
    jna short lbl17Fb
lbl1B9f:
    cmp word ptr [bp-6h],0h
    jz short lbl1E4f
    mov ax,0FEh
    push ax
    push word ptr [bp-6h]
    push word ptr [bp-2h]
    push word ptr [bp-4h]
    push word ptr ds:[6452h]
    push word ptr ds:[6450h]
    call mf168
    mov ax,word ptr [bp-6h]
    add word ptr ds:[6450h],ax
    sub word ptr ds:[6454h],ax
lbl1E4f:
    mov sp,bp
    pop bp
    retf 8h
    add byte ptr [bx+si],al
    add byte ptr [bx+si],al
    add byte ptr [bx+si],al
    push bp
    mov bp,sp
    sub sp,2h
    mov ax,word ptr [bp+6h]
    mov dx,word ptr [bp+8h]
    mov word ptr ds:[644Ah],ax
    mov word ptr ds:[644Ch],dx
    mov ax,0FD85h
    mov dx,8A7h
    push dx
    push ax
    mov ax,0FDF0h
    mov dx,8A7h
    push dx
    push ax
    mov ax,1596h
    mov cx,3420h
    push cx
    push ax
    call mf197
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
