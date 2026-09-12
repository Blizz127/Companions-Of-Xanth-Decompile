_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf13:FAR
    EXTRN mi71:NEAR
    EXTRN mi77:NEAR
    EXTRN mf113:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,2h
    push ds
    push es
    push si
    push di
    mov ax,38AFh
    mov ds,ax
    mov word ptr [bp-2h],0FFE8h
    les di, dword ptr [bp+10h]
    mov ax,word ptr [bp+0Ah]
    push ax
    call mf13
    jnc short lbl2Af
    mov word ptr [bp-2h],0FC19h
    jmp near ptr lbl137f
lbl2Af:
    mov ds,dx
    mov si,ax
    mov word ptr es:[di],0CA00h
    mov byte ptr es:[di+2h],0h
    mov byte ptr es:[di+3h],2h
    mov ax,word ptr [bp+0Ah]
    mov word ptr es:[di+4h],ax
    xor ax,ax
    mov word ptr es:[di+6h],ax
    mov word ptr es:[di+8h],ax
    mov ax,word ptr [bp+8h]
    mov word ptr es:[di+2Ch],ax
    dec ax
    mov word ptr es:[di+0Ah],ax
    mov ax,word ptr [bp+6h]
    mov word ptr es:[di+2Eh],ax
    dec ax
    mov word ptr es:[di+0Ch],ax
    xor ah,ah
    mov al,byte ptr [si+1Eh]
    mov byte ptr es:[di+12h],al
    mul word ptr [bp+6h]
    mov word ptr es:[di+34h],ax
    mov ax,word ptr [si+18h]
    mov word ptr es:[di+0Eh],ax
    mov ax,word ptr [si+1Ah]
    mov word ptr es:[di+10h],ax
    xor ah,ah
    mov al,byte ptr [si+17h]
    mov byte ptr es:[di+13h],al
    mul word ptr [bp+8h]
    mov bx,8h
    div bx
    or dx,dx
    jz short lbl9Af
    inc ax
lbl9Af:
    mov word ptr es:[di+30h],ax
    test ax,1h
    jz short lblA4f
    inc ax
lblA4f:
    mov word ptr es:[di+14h],ax
    mov cl,dl
    xor cl,7h
    inc cl
    and cl,7h
    mov ch,0FFh
    shl ch,cl
    mov cl,ch
    not ch
    mov word ptr es:[di+32h],cx
    mov word ptr es:[di+28h],0h
    mov word ptr es:[di+2Ah],4h
    mov ax,word ptr [bp+14h]
    mov word ptr es:[di+16h],ax
    cmp ax, offset mi71
    jnz short lblDFf
    mov bx,word ptr [bp+0Eh]
    mov ax,word ptr [bp+0Ch]
    jmp short lbl110f
    nop
lblDFf:
    cmp ax, offset mi77
    jnz short lbl10Ef
    mov dx,word ptr [bp+0Ch]
    mov word ptr es:[di+22h],dx
    mov ah,4Ch
    int 67h
    or ah,ah
    jnz short lbl106f
    mov word ptr es:[di+24h],bx
    mov word ptr es:[di+26h],0h
    mov ah,41h
    int 67h
    and ax,0FF00h
    jz short lbl110f
lbl106f:
    mov word ptr [bp-2h],0FFEAh
    jmp short lbl137f
    nop
lbl10Ef:
    jmp short lbl137f
lbl110f:
    mov word ptr es:[di+1Ah],bx
    mov word ptr es:[di+18h],ax
    mov ax,word ptr [si+24h]
    mov word ptr es:[di+1Ch],ax
    xor ax,ax
    mov word ptr es:[di+1Eh],ax
    mov word ptr es:[di+20h],ax
    mov al,byte ptr [si+15h]
    xor ah,ah
    mov word ptr es:[di+74h],ax
    mov word ptr [bp-2h],0h
lbl137f:
    mov ax,word ptr [bp-2h]
    pop di
    pop si
    pop es
    pop ds
    mov sp,bp
    pop bp
    retf 10h
_TEXT ENDS
    END
