_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mfad:FAR
    EXTRN mf2a3:FAR
    EXTRN mf1f:FAR
    EXTRN mf266:FAR
    EXTRN mf2a8:FAR
    EXTRN mf2d7:FAR
    EXTRN mf1ca:FAR
    EXTRN mi1d5:NEAR
    EXTRN mi10a:NEAR
    EXTRN mf9e:FAR
    EXTRN mfbc:FAR
    EXTRN mf250:FAR
    EXTRN mf1ab:FAR
    EXTRN mf7f:FAR
    EXTRN mf3f:FAR
    EXTRN mf2ca:FAR
    EXTRN mf258:FAR
    EXTRN mf27e:FAR
    EXTRN mf2d2:FAR
    EXTRN mf28f:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,18h
    push di
    xor ax,ax
    mov word ptr ds:[5D9Ch],ax
    mov word ptr ds:[5D9Eh],ax
    mov ax,7Dh
    push ax
    mov ax,13Ah
    push ax
    mov ax,4h
    push ax
    mov ax,33h
    push ax
    call mf1f
    add sp,8h
    mov ax,word ptr ds:[256h]
    cmp word ptr ds:[1920h],ax
    jz short lbl46f
    mov word ptr ds:[1920h],ax
    xor ax,ax
    mov cx,0Ah
    mov di,5DA0h
    push ds
    pop es
    rep stosw
    call mf3f
    jmp short lblA9f
lbl46f:
    mov word ptr [bp-2h],0h
    cmp word ptr ds:[108h],0h
    jz short lblA9f
    mov word ptr [bp-16h],0h
lbl57b:
    mov ax,word ptr ds:[256h]
    mov es, ds:[5A7Ah]
    mov bx,word ptr [bp-16h]
    cmp word ptr es:[bx],ax
    jz short lbl78f
    add word ptr [bp-16h],2h
    mov ax,word ptr ds:[108h]
    inc word ptr [bp-2h]
    cmp word ptr [bp-2h],ax
    jc short lbl57b
    jmp short lblA9f
    nop
lbl78f:
    xor ax,ax
    push ax
    push word ptr ds:[256h]
    call mf7f
    add sp,4h
    mov word ptr [bp-6h],ax
    mov ax,word ptr ds:[1922h]
    cmp word ptr [bp-6h],ax
    jz short lblA9f
    xor ax,ax
    mov cx,0Ah
    mov di,5DA0h
    push ds
    pop es
    rep stosw
    call mf9e
    mov ax,word ptr [bp-6h]
    mov word ptr ds:[1922h],ax
lblA9f:
    push word ptr ds:[256h]
    call mfad
    add sp,2h
    mov word ptr [bp-8h],ax
    push word ptr ds:[256h]
    call mfbc
    add sp,2h
    mov word ptr [bp-0Ah],ax
    or ax,ax
    jnz short lblCEf
    jmp near ptr lbl24Cf
lblCEf:
    dec word ptr [bp-0Ah]
    mov ax,word ptr [bp-0Ah]
    add ax,ax
    add ax,ax
    add ax,10FAh
    mov word ptr [bp-18h],ax
lblDEb:
    mov ax,word ptr [bp-8h]
    dec word ptr [bp-8h]
    or ax,ax
    jnz short lblEBf
    jmp near ptr lbl24Cf
lblEBf:
    mov bx,word ptr [bp-18h]
    mov es, ds:[5A7Ch]
    mov al,byte ptr es:[bx]
    mov byte ptr [bp-12h],al
    mov cx,word ptr es:[bx+2h]
    mov word ptr [bp-0Ch],cx
    xor cx,cx
    mov word ptr [bp-10h],cx
    mov word ptr [bp-0Eh],cx
    sub ah,ah
    dec ax
    cmp ax, offset mi10a
    ja short lbl168f
    add ax,ax
    xchg ax,bx
    jmp word ptr cs:[bx+1A6h]
    nop
    db 0BAh, 01h, 0C0h, 01h, 0C6h, 01h, 0CCh, 01h, 0D2h, 01h, 0D8h, 01h, 0DEh, 01h, 0E4h, 01h
    db 0EAh, 01h, 0F0h, 01h
    mov ax,word ptr ds:[5DA0h]
    jmp short lbl165f
    nop
    mov ax,word ptr ds:[5DA2h]
    jmp short lbl165f
    nop
    mov ax,word ptr ds:[5DA4h]
    jmp short lbl165f
    nop
    mov ax,word ptr ds:[5DA6h]
    jmp short lbl165f
    nop
    mov ax,word ptr ds:[5DA8h]
    jmp short lbl165f
    nop
    mov ax,word ptr ds:[5DAAh]
    jmp short lbl165f
    nop
    mov ax,word ptr ds:[5DACh]
    jmp short lbl165f
    nop
    mov ax,word ptr ds:[5DAEh]
    jmp short lbl165f
    nop
    mov ax,word ptr ds:[5DB0h]
    jmp short lbl165f
    nop
    mov ax,word ptr ds:[5DB2h]
lbl165f:
    mov word ptr [bp-10h],ax
lbl168f:
    mov bx,word ptr [bp-18h]
    sub ah,ah
    mov al,byte ptr es:[bx+1h]
    dec ax
    jz short lbl17Ef
    dec ax
    jz short lbl186f
    dec ax
    dec ax
    jz short lbl198f
    jmp short lbl1BCf
    nop
lbl17Ef:
    mov ax,word ptr [bp-0Ch]
lbl181b:
    mov word ptr [bp-0Eh],ax
    jmp short lbl1BCf
lbl186f:
    mov es, ds:[5A7Eh]
    mov bx,word ptr [bp-0Ch]
    add bx,bx
    add bx,bx
    mov ax,word ptr es:[bx+84Eh]
    jmp short lbl181b
lbl198f:
    mov al,byte ptr ds:[6E5Ch]
    mov byte ptr [bp-4h],al
    mov al,byte ptr [bp-12h]
    mov byte ptr ds:[6E5Ch],al
    mov ax,1h
    push ax
    push word ptr [bp-0Ch]
    call mf1ab
    add sp,4h
    mov word ptr [bp-0Eh],ax
    mov al,byte ptr [bp-4h]
    mov byte ptr ds:[6E5Ch],al
lbl1BCf:
    mov ax,word ptr [bp-0Eh]
    cmp word ptr [bp-10h],ax
    jz short lbl1CFf
    cmp word ptr [bp-10h],0h
    jz short lbl1CFf
    call mf1ca
lbl1CFf:
    mov al,byte ptr [bp-12h]
    sub ah,ah
    dec ax
    cmp ax, offset mi1d5
    ja short lbl244f
    add ax,ax
    xchg ax,bx
    jmp word ptr cs:[bx+270h]
    db 84h, 02h, 8Ch, 02h, 94h, 02h, 9Ch, 02h, 0A4h, 02h, 0ACh, 02h, 0B4h, 02h, 0BCh, 02h
    db 0C4h, 02h, 0CCh, 02h
    mov ax,word ptr [bp-0Eh]
    mov word ptr ds:[5DA0h],ax
    jmp short lbl244f
    mov ax,word ptr [bp-0Eh]
    mov word ptr ds:[5DA2h],ax
    jmp short lbl244f
    mov ax,word ptr [bp-0Eh]
    mov word ptr ds:[5DA4h],ax
    jmp short lbl244f
    mov ax,word ptr [bp-0Eh]
    mov word ptr ds:[5DA6h],ax
    jmp short lbl244f
    mov ax,word ptr [bp-0Eh]
    mov word ptr ds:[5DA8h],ax
    jmp short lbl244f
    mov ax,word ptr [bp-0Eh]
    mov word ptr ds:[5DAAh],ax
    jmp short lbl244f
    mov ax,word ptr [bp-0Eh]
    mov word ptr ds:[5DACh],ax
    jmp short lbl244f
    mov ax,word ptr [bp-0Eh]
    mov word ptr ds:[5DAEh],ax
    jmp short lbl244f
    mov ax,word ptr [bp-0Eh]
    mov word ptr ds:[5DB0h],ax
    jmp short lbl244f
    mov ax,word ptr [bp-0Eh]
    mov word ptr ds:[5DB2h],ax
lbl244f:
    add word ptr [bp-18h],4h
    jmp near ptr lblDEb
    nop
lbl24Cf:
    mov ax,1h
    push ax
    call mf250
    add sp,2h
    call mf258
    xor ax,ax
    push ax
    mov cx,1h
    push cx
    push ax
    push cx
    call mf266
    add sp,8h
    mov ax,33h
    push ax
    mov ax,4h
    push ax
    mov ax,13Ah
    push ax
    mov ax,7Dh
    push ax
    call mf27e
    mov ax,41h
    push ax
    mov ax,0B7h
    push ax
    push word ptr ds:[256h]
    call mf28f
    add sp,6h
    xor ax,ax
    push ax
    push ax
    mov cx,13Fh
    push cx
    mov cx,0C7h
    push cx
    call mf2a3
    call mf2a8
    or ax,ax
    jz short lbl2D7f
    mov ax,4h
    push ax
    mov cx,33h
    push cx
    xor dx,dx
    push dx
    mov dx,7Ah
    push dx
    mov dx,108h
    push dx
    push ax
    push cx
    mov ax,1h
    push ax
    call mf2ca
    add sp,10h
    call mf2d2
lbl2D7f:
    call mf2d7
    pop di
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
