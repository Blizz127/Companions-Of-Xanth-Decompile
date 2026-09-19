_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mnf0:NEAR
    EXTRN mn61:NEAR
    EXTRN mn137:NEAR
    EXTRN mn18e:NEAR
    EXTRN mndf:NEAR
    EXTRN mn1ef:NEAR
    EXTRN mj152:FAR
    EXTRN mn134:NEAR
    EXTRN mn166:NEAR
    EXTRN mn123:NEAR
    EXTRN mn101:NEAR
    EXTRN mncb:NEAR
    EXTRN mnce:NEAR
    EXTRN mj58:FAR
    EXTRN mi4d:NEAR
    EXTRN mi8f:NEAR
    EXTRN mn112:NEAR
    EXTRN mi97:NEAR
mnem_unit:
    push bp
    mov bp,sp
    push si
    push di
    mov ax,word ptr [bp+0Ah]
    mov dx,word ptr [bp+0Ch]
    les si, dword ptr [bp+6h]
    mov di,es
    mov word ptr ds:[44A0h],si
    mov word ptr ds:[44A2h],es
    mov word ptr es:[si+16h],ax
    mov word ptr es:[si+18h],dx
    mov word ptr es:[si+0Eh],800h
    push si
    push di
    lea ax,word ptr [si+221Eh]
    push es
    push ax
    lea ax,word ptr [si+0Eh]
    push es
    push ax
    mov ax,word ptr [bp+0Eh]
    mov dx,word ptr [bp+10h]
    mov word ptr es:[si+12h],ax
    mov word ptr es:[si+14h],dx
    db 26h, 0FFh, 5Ch, 12h ; override
    pop di
    pop si
    mov es,di
    mov word ptr es:[si+10h],ax
    cmp ax, offset mi4d
    ja short lbl66f
    mov ax,3h
    jmp near ptr lbl14Cf
    jmp mj58
    mov ax,0CB2h
    push ax
    call mn61
    retf
    db 0C7h
lbl66f:
    mov al,byte ptr es:[si+221Eh]
    sub ah,ah
    mov word ptr es:[si+2h],ax
    mov al,byte ptr es:[si+2220h]
    mov word ptr es:[si+0Ah],ax
    mov al,byte ptr es:[si+221Fh]
    mov word ptr es:[si+6h],ax
    mov word ptr es:[si+0Ch],0h
    mov word ptr es:[si+0Eh],3h
    cmp ax, offset mi8f
    jnc short lbl97f
    jmp near ptr lbl149f
lbl97f:
    cmp ax, offset mi97
    jna short lbl9Ff
    jmp near ptr lbl149f
lbl9Ff:
    mov cl,10h
    sub cl,al
    mov ax,0FFFFh
    shr ax,cl
    mov word ptr es:[si+8h],ax
    mov ax,word ptr es:[si+2h]
    or ax,ax
    jz short lblD1f
    dec ax
    jz short lblBDf
    mov ax,2h
    jmp near ptr lbl14Cf
lblBDf:
    lea ax,word ptr [si+2F9Eh]
    push es
    push ax
    mov ax,161h
    push cs
    push ax
    mov ax,100h
    call mncb
    call mnce
lblD1f:
    push di
    lea ax,word ptr [si+30DEh]
    push ax
    mov ax,141h
    push cs
    push ax
    mov ax,10h
    call mndf
    lea bx,word ptr [si+30DEh]
    mov cx,151h
    lea dx,word ptr [si+2B1Eh]
    mov ax,10h
    call mnf0
    push di
    lea ax,word ptr [si+30EEh]
    push ax
    mov ax,111h
    push cs
    push ax
    mov ax,10h
    call mn101
    push di
    lea ax,word ptr [si+30FEh]
    push ax
    mov ax,121h
    push cs
    push ax
    mov ax,20h
    call mn112
    push di
    lea ax,word ptr [si+309Eh]
    push ax
    mov ax,91h
    push cs
    push ax
    mov ax,40h
    call mn123
    lea bx,word ptr [si+309Eh]
    mov cx,0D1h
    lea dx,word ptr [si+2A1Eh]
    mov ax,40h
    call mn134
    call mn137
    cmp ax,306h
    jnz short lbl145f
    mov ax,4h
    jmp short lbl14Cf
    db 81h
lbl145f:
    sub ax,ax
    jmp short lbl14Cf
lbl149f:
    mov ax,1h
lbl14Cf:
    pop di
    pop si
    pop bp
    retf 0Ch
    jmp mj152
    in al,dx
    add dl,byte ptr [bp+57h]
    les si, dword ptr ds:[44A0h]
    mov word ptr es:[si+4h],1000h
lbl165b:
    push es
    call mn166
    pop es
    cmp ax,305h
    jc short lbl172f
    jmp near ptr lbl1FBf
lbl172f:
    cmp ax,100h
    jnc short lbl188f
    lea bx,word ptr [si+1Ah]
    mov di,word ptr es:[si+4h]
    mov byte ptr es:[bx+di],al
    inc di
    mov word ptr es:[si+4h],di
    jmp short lbl1B8f
lbl188f:
    sub ax,0FEh
    mov di,ax
    push es
    call mn18e
    pop es
    or ax,ax
    jz short lbl1F6f
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
lbl1B8f:
    cmp di,2000h
    jc short lbl165b
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
    call mn1ef
    jmp near ptr lbl165b
    db 0F7h
lbl1F6f:
    mov word ptr [bp-2h],306h
lbl1FBf:
    db 0FFh
lbl1FCb:
    jna short lbl1FCb
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
