_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mna1:NEAR
mnem_unit:
    push bp
    mov bp,sp
    push di
    push si
    xchg ax,cx
    jcxz lbl21f
    push ds
    cld
    lds si, dword ptr [bp+4h]
    les di, dword ptr [bp+8h]
    test di,1h
    jz short lbl18f
    movsb
    dec cx
lbl18f:
    shr cx,1
    rep movsw
    rcl cx,1
    rep movsb
    pop ds
lbl21f:
    pop si
    pop di
    pop bp
    ret 8h
    adc word ptr [di-75h],57ECh
    db 87h, 0CAh ; override
    jcxz lbl45f
    les di, dword ptr [bp+4h]
    mov ah,al
    test di,1h
    jz short lbl3Df
    stosb
    dec cx
lbl3Df:
    shr cx,1
    rep stosw
    shl cx,1
    rep stosb
lbl45f:
    pop di
    pop bp
    ret 4h
    not word ptr [di-75h]
    in al,dx
    sub sp,4h
    push si
    mov word ptr [bp-4h],800h
    push si
    push di
    mov ax,word ptr ds:[449Ch]
    add ax,1BAAh
    push word ptr ds:[449Eh]
    push ax
    lea ax,word ptr [bp-4h]
    push ss
    push ax
    les bx, dword ptr ds:[449Ch]
    db 26h, 0FFh, 9Fh, 0A4h, 09h ; override
    pop di
    pop si
    les bx, dword ptr ds:[449Ch]
    add bx,word ptr es:[bx+2h]
    mov al,byte ptr es:[bx+1BAAh]
    mov byte ptr [bp-1h],al
    mov bx,word ptr ds:[449Ch]
    mov al,byte ptr es:[bx+23AAh]
    mov byte ptr [bp-2h],al
    sub word ptr es:[bx+2h],800h
    lea ax,word ptr [bx+1BAAh]
    push es
    push ax
    sub ax,ax
    mov dx,802h
    call mna1
    les bx, dword ptr ds:[449Ch]
    cmp word ptr es:[bx+2h],0h
    jnz short lblB4f
    mov si,bx
    jmp short lblBEf
    db 81h
lblB4f:
    mov si,bx
    mov al,byte ptr [bp-2h]
    mov byte ptr es:[si+1BAAh],al
lblBEf:
    cmp word ptr es:[si+4h],0h
    jz short lblD3f
    mov bx,word ptr es:[si+2h]
    add bx,si
    mov al,byte ptr [bp-1h]
    mov byte ptr es:[bx+1BAAh],al
lblD3f:
    pop si
    mov sp,bp
    pop bp
    ret
_TEXT ENDS
    END
