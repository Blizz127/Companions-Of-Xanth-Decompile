_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
mnem_unit:
    push bp
    mov bp,sp
    sub sp,2h
    push di
    push si
    mov word ptr [bp-2h],0h
    mov es, ds:[5B4Eh]
lbl11b:
    mov cx,3Fh
    mov ax,word ptr [bp-2h]
    mov dx,3h
    mov bx,dx
    cwd
    idiv bx
    imul cx
    mov cx,0Fh
    cwd
    idiv cx
    mov bx,word ptr [bp-2h]
    mov byte ptr es:[bx+6A24h],al
    inc word ptr [bp-2h]
    cmp word ptr [bp-2h],30h
    jl short lbl11b
    mov ax,6A54h
    mov cx,38AFh
    mov dx,3420h
    mov bx,cx
    push ds
    mov di,ax
    mov si,46B4h
    mov es,cx
    mov ds,dx
    mov cx,18h
    rep movsw
    pop ds
    mov es,bx
    mov dx,38AFh
    push ds
    mov di,6A84h
    mov si,6D4Ah
    mov ds,dx
    mov cx,48h
    rep movsw
    pop ds
    mov es,bx
    mov byte ptr es:[6A56h],0h
    mov cl,10h
    mov byte ptr es:[6D1Eh],cl
    mov byte ptr es:[6D1Fh],cl
    mov byte ptr es:[6D20h],cl
    mov si,ax
    mov al,3Fh
    mov byte ptr es:[si],al
    mov byte ptr es:[6A55h],al
    mov byte ptr es:[6D21h],al
    mov byte ptr es:[6D22h],al
    mov byte ptr es:[6D23h],al
    mov word ptr ds:[4F4Eh],1h
    pop si
    pop di
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
