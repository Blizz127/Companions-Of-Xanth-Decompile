_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mn56:NEAR
mnem_unit:
    push bp
    mov bp,sp
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
    call mn56
    les bx, dword ptr ds:[449Ch]
    cmp word ptr es:[bx+2h],0h
    jnz short lbl69f
    mov si,bx
    jmp short lbl73f
    db 81h
lbl69f:
    mov si,bx
    mov al,byte ptr [bp-2h]
    mov byte ptr es:[si+1BAAh],al
lbl73f:
    cmp word ptr es:[si+4h],0h
    jz short lbl88f
    mov bx,word ptr es:[si+2h]
    add bx,si
    mov al,byte ptr [bp-1h]
    mov byte ptr es:[bx+1BAAh],al
lbl88f:
    pop si
    mov sp,bp
    pop bp
    ret
_TEXT ENDS
    END
