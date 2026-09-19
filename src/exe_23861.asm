_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mn13:NEAR
    EXTRN mn3b:NEAR
    EXTRN mn9c:NEAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,2h
    push si
    push di
    les si, dword ptr ds:[44A0h]
    mov word ptr es:[si+4h],1000h
lbl12b:
    push es
    call mn13
    pop es
    cmp ax,305h
    jc short lbl1Ff
    jmp near ptr lblA8f
lbl1Ff:
    cmp ax,100h
    jnc short lbl35f
    lea bx,word ptr [si+1Ah]
    mov di,word ptr es:[si+4h]
    mov byte ptr es:[bx+di],al
    inc di
    mov word ptr es:[si+4h],di
    jmp short lbl65f
lbl35f:
    sub ax,0FEh
    mov di,ax
    push es
    call mn3b
    pop es
    or ax,ax
    jz short lblA3f
    mov cx,di
    lea bx,word ptr [si+1Ah]
    mov di,word ptr es:[si+4h]
    add di,bx
    mov dx,si
    mov si,di
    sub si,ax
    cld
    push ds
    mov ax,es
    mov ds,ax
    rep movsb
    pop ds
    mov si,dx
    sub di,bx
    mov word ptr es:[si+4h],di
lbl65f:
    cmp di,2000h
    jc short lbl12b
    mov word ptr [bp-2h],1000h
    push si
    push di
    lea ax,word ptr [si+101Ah]
    push es
    push ax
    lea ax,word ptr [bp-2h]
    push ss
    push ax
    db 26h, 0FFh, 5Ch, 16h ; override
    pop di
    pop si
    mov es, ds:[44A2h]
    lea ax,word ptr [si+1Ah]
    push es
    push ax
    add ax,1000h
    push es
    push ax
    mov ax,word ptr es:[si+4h]
    sub ax,1000h
    mov word ptr es:[si+4h],ax
    call mn9c
    jmp near ptr lbl12b
    db 0F7h
lblA3f:
    mov word ptr [bp-2h],306h
lblA8f:
    db 0FFh
lblA9b:
    jna short lblA9b
    mov ax,word ptr es:[si+4h]
    sub ax,1000h
    mov word ptr [bp-2h],ax
    lea ax,word ptr [si+101Ah]
    push es
    push ax
    lea ax,word ptr [bp-2h]
    push ss
    push ax
    db 26h, 0FFh, 5Ch, 16h ; override
    pop ax
    pop di
    pop si
    mov sp,bp
    pop bp
    ret
_TEXT ENDS
    END
