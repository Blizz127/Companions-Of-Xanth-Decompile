_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mn18c:NEAR
    EXTRN mn137:NEAR
    EXTRN mjn1e3:NEAR
    EXTRN mn201:NEAR
    EXTRN mjn1ec:NEAR
    EXTRN mn124:NEAR
    EXTRN mn70:NEAR
    EXTRN mn13a:NEAR
    EXTRN mjn1d6:NEAR
    EXTRN mf67:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,14h
    push di
    push si
    mov si,word ptr [bp+0Eh]
    mov word ptr ds:[449Ch],si
    push ds
    mov ds, [bp+10h]
    les ax, dword ptr [bp+16h]
    mov word ptr [si+9A0h],ax
    mov word ptr [si+9A2h],es
    les ax, dword ptr [bp+12h]
    mov word ptr [si+9A4h],ax
    mov word ptr [si+9A6h],es
    les di, dword ptr [bp+6h]
    mov ax,word ptr es:[di]
    mov word ptr [si+0Ch],ax
    les bx, dword ptr [bp+0Ah]
    mov cx,word ptr es:[bx]
    mov word ptr [si+0Ah],cx
    mov word ptr [si+6h],4h
    mov word ptr [si+8h],0Fh
    pop es
    mov word ptr es:[449Eh],ds
    push ds
    pop es
    sub ax,400h
    jz short lbl83f
    sub ax,400h
    jz short lbl7Cf
    sub ax,800h
    jz short lbl75f
    mov ax,1h
lbl5Fb:
    mov bx,38AFh
    mov ds,bx
    jmp near ptr lbl13Ff
    call mf67
    mov ax,461h
    push ax
    call mn70
    retf
    db 81h
lbl75f:
    inc word ptr [si+6h]
    or byte ptr [si+8h],20h
lbl7Cf:
    inc word ptr [si+6h]
    or byte ptr [si+8h],10h
lbl83f:
    jcxz lbl8Df
    dec cx
    jz short lblABf
    mov ax,2h
    jmp short lbl5Fb
lbl8Df:
    cld
    lea di,word ptr [si+8Eh]
    mov ax,909h
    mov cx,80h
    rep stosw
    mov cx,100h
    lea di,word ptr [si+394h]
    xor ax,ax
lblA3b:
    stosw
    inc ax
    inc ax
    loop lblA3b
    jmp short lblCBf
    db 0EAh
lblABf:
    mov bx,0FFh
lblAEb:
    mov al,byte ptr cs:[bx+161h]
    inc al
    mov byte ptr [bx+si+8Eh],al
    shl bx,1
    mov ax,word ptr cs:[bx+261h]
    shl ax,1
    mov word ptr [bx+si+394h],ax
    shr bx,1
    dec bx
    jnl short lblAEb
lblCBf:
    xor di,di
    mov bx,100h
lblD0b:
    mov cl,byte ptr cs:[di+111h]
    mov dx,1h
    shl dx,cl
    mov word ptr [bp-0Ah],dx
    xor dx,dx
lblDFb:
    mov al,byte ptr cs:[di+141h]
    mov cl,al
    inc al
    add al,byte ptr cs:[di+111h]
    mov byte ptr [bx+si+8Eh],al
    mov ax,dx
    shl ax,cl
    or al,byte ptr cs:[di+151h]
    shl ax,1
    inc ax
    shl bx,1
    mov word ptr [bx+si+394h],ax
    shr bx,1
    inc bx
    inc dx
    cmp word ptr [bp-0Ah],dx
    ja short lblDFb
    inc di
    cmp di,10h
    jc short lblD0b
    mov ax,38AFh
    mov ds,ax
    lea ax,word ptr [si+4Eh]
    push es
    push ax
    mov ax,0D1h
    push cs
    push ax
    mov ax,40h
    call mn124
    lea ax,word ptr [si+0Eh]
    push word ptr ds:[449Eh]
    push ax
    mov ax,91h
    push cs
    push ax
    mov ax,40h
    call mn137
    call mn13a
    sub ax,ax
lbl13Ff:
    pop si
    pop di
    mov sp,bp
    pop bp
    retf 14h
    db 0C7h
    push bp
    mov bp,sp
    sub sp,0Eh
    push di
    push si
    les bx, dword ptr ds:[449Ch]
    add bx,word ptr es:[bx+0Ch]
    lea ax,word ptr [bx+25B0h]
    mov word ptr [bp-6h],ax
    mov bx,word ptr ds:[449Ch]
    mov al,byte ptr es:[bx+0Ah]
    mov byte ptr es:[bx+1BAAh],al
    mov al,byte ptr es:[bx+6h]
    mov byte ptr es:[bx+1BABh],al
    mov word ptr es:[bx+2h],2h
    lea ax,word ptr [bx+1BACh]
    push es
    push ax
    sub ax,ax
    mov word ptr [bp-0Eh],ax
    mov word ptr [bp-0Ch],ax
    mov dx,800h
    call mn18c
    les bx, dword ptr ds:[449Ch]
    mov word ptr es:[bx+4h],0h
    mov word ptr [bp-0Ah],1000h
    sub si,si
lbl1A0b:
    les bx, dword ptr ds:[449Ch]
    add bx,word ptr es:[bx+0Ch]
    lea di,word ptr [bp-0Ah]
    push word ptr [bp-0Ah]
    push si
    lea bx,word ptr [bx+si+25B0h]
    push es
    push bx
    push ss
    push di
    mov bx,word ptr ds:[449Ch]
    db 26h, 0FFh, 9Fh, 0A0h, 09h ; override
    pop si
    pop word ptr [bp-0Ah]
    mov di,ax
    or di,di
    jz short lbl1DAf
    add si,di
    sub word ptr [bp-0Ah],di
    jnz short lbl1A0b
    mov word ptr [bp-2h],si
    mov cx,si
    jmp mjn1d6
    db 0C7h
lbl1DAf:
    mov word ptr [bp-2h],si
    mov cx,si
    or cx,cx
    jz short lbl1E6f
    jmp mjn1e3
lbl1E6f:
    cmp word ptr [bp-0Eh],0h
    jz short lbl1EFf
    jmp mjn1ec
lbl1EFf:
    les bx, dword ptr ds:[449Ch]
    push es
    push bx
    mov al,byte ptr es:[bx+393h]
    sub ah,ah
    mov dx,word ptr es:[bx+99Eh]
    call mn201
    pop bx
    pop es
    cmp word ptr es:[bx+4h],0h
    jz short lbl211f
    inc word ptr es:[bx+2h]
lbl211f:
    lea ax,word ptr [bx+1BAAh]
    push es
    push ax
    lea ax,word ptr [bx+2h]
    push es
    push ax
    db 26h, 0FFh, 9Fh, 0A4h, 09h ; override
    pop si
    pop di
    mov sp,bp
    pop bp
    ret
lbl359f:
lbl35Ef:
_TEXT ENDS
    END
