_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mn56:NEAR
    EXTRN mn3b:NEAR
    EXTRN mndc:NEAR
    EXTRN mf196:FAR
    EXTRN mi1d7:NEAR
    EXTRN mn49:NEAR
    EXTRN mff4:FAR
    EXTRN mn19:NEAR
    EXTRN miac:NEAR
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
    mov word ptr [bp-2h],0h
    mov ax,word ptr ds:[5242h]
    push ax
    push cs
    call mn19
    jnc short lbl24f
    mov word ptr [bp-2h],ax
    jmp short lbl87f
    nop
lbl24f:
    mov es,dx
    mov di,ax
    cmp word ptr [bp+6h],1h
    jnz short lbl66f
    mov word ptr ds:[5246h],1h
    mov word ptr ds:[5248h],0h
    push cs
    call mn3b
    cmp ax,word ptr es:[di+4h]
    jz short lbl87f
    push word ptr es:[di+4h]
    push cs
    call mn49
    or ax,ax
    jz short lbl55f
    mov word ptr [bp-2h],ax
    jmp short lbl87f
lbl55f:
    push cs
    call mn56
    cmp ax,word ptr es:[di+4h]
    jz short lbl87f
    mov word ptr [bp-2h],0FFFAh
    jmp short lbl87f
lbl66f:
    cmp word ptr [bp+6h],0h
    jnz short lbl82f
    mov word ptr ds:[5246h],0h
    mov word ptr ds:[5248h],0h
    mov al,3h
    push bp
    mov ah,0h
    int 10h
    pop bp
    jmp short lbl87f
lbl82f:
    mov word ptr [bp-2h],0FFF9h
lbl87f:
    mov ax,word ptr [bp-2h]
    pop di
    pop si
    pop es
    pop ds
    mov sp,bp
    pop bp
    retf 2h
    push bp
    mov bp,sp
    sub sp,2h
    push ds
    push es
    push si
    push di
    mov ax,38AFh
    mov ds,ax
    mov ax,word ptr ds:[5256h]
    mov word ptr [bp-2h],ax
    mov ax,word ptr [bp+6h]
    cmp ax, offset miac
    jz short lblB4f
    mov ax,1h
lblB4f:
    mov word ptr ds:[5256h],ax
    mov ax,word ptr [bp-2h]
    pop di
    pop si
    pop es
    pop ds
    mov sp,bp
    pop bp
    retf 2h
    add byte ptr [di-75h],dl
    in al,dx
    sub sp,28h
    push ds
    push es
    push si
    push di
    mov ax,38AFh
    mov ds,ax
    cmp byte ptr ds:[5301h],1h
    jz short lblDFf
    push cs
    call mndc
lblDFf:
    mov si,52A6h
    cmp word ptr [si+18h],1h
    jnz short lbl10Ef
    push word ptr [bp+0Ch]
    push word ptr [bp+0Ah]
    push word ptr [bp+8h]
    push word ptr [bp+6h]
    call mff4
    jnc short lbl102f
    mov word ptr [bp-2h],0h
    jmp short lbl156f
lbl102f:
    mov word ptr [bp+0Ch],ax
    mov word ptr [bp+0Ah],bx
    mov word ptr [bp+8h],cx
    mov word ptr [bp+6h],dx
lbl10Ef:
    mov ax,word ptr [si+0Eh]
    mov word ptr [bp-10h],ax
    mov cx,word ptr [bp+6h]
    sub cx,word ptr [bp+0Ah]
    jns short lbl127f
    neg cx
    mov ax,word ptr [bp+6h]
    xchg ax,word ptr [bp+0Ah]
    mov word ptr [bp+6h],ax
lbl127f:
    inc cx
    mov word ptr [bp-0Ah],cx
    mov si,5365h
    mov dx,word ptr ds:[5244h]
    cmp dx,0h
    jc short lbl13Cf
    cmp dx,0h
    jna short lbl143f
lbl13Cf:
    mov word ptr [bp-2h],0FFFAh
    jmp short lbl156f
lbl143f:
    mov ax,10h
    mul dx
    add si,ax
    mov ax,word ptr [si+2h]
    mov word ptr [bp-8h],ax
    db 0FFh, 6Ch, 0Ch ; override
    mov word ptr [bp-2h],ax
lbl156f:
    mov ax,word ptr [bp-2h]
    pop di
    pop si
    pop es
    pop ds
    mov sp,bp
    pop bp
    retf 8h
    mov bx,5365h
    mov word ptr [bx+0Ch],0C0h
    mov word ptr [bx+0Eh],791h
    add bx,10h
    mov byte ptr ds:[5301h],1h
    retf
    mov si,word ptr [bp-8h]
    mov cx,word ptr [bp+8h]
    sub cx,word ptr [bp+0Ch]
    jns short lbl18Ff
    neg cx
    mov bx,word ptr [bp+8h]
    xchg bx,word ptr [bp+0Ch]
    mov word ptr [bp+8h],bx
lbl18Ff:
    push cx
    mov ax,word ptr [bp+0Ah]
    mov bx,word ptr [bp+0Ch]
    call mf196
    mov di,bx
    pop cx
    inc cx
    sub si,cx
    mov al,byte ptr [bp-10h]
    mov bx,word ptr [bp-0Ah]
lbl1A7b:
    push cx
    rep stosb
    pop cx
    dec bx
    jz short lbl1B2f
    add di,si
    jmp short lbl1A7b
lbl1B2f:
    mov word ptr [bp-2h],0h
    mov ax,word ptr [bp-2h]
    pop di
    pop si
    pop es
    pop ds
    mov sp,bp
    pop bp
    retf 8h
    add byte ptr [di-75h],dl
    in al,dx
    sub sp,2h
    push ds
    push es
    push si
    push di
    mov ax,38AFh
    mov ds,ax
    mov ax,word ptr [bp+6h]
    cmp ax, offset mi1d7
    jz short lbl1DFf
    mov ax,0h
lbl1DFf:
    mov si,52A6h
    mov word ptr [si+18h],ax
    mov word ptr [bp-2h],0h
    mov ax,word ptr [bp-2h]
    pop di
    pop si
    pop es
    pop ds
    mov sp,bp
    pop bp
    retf 2h
    push bp
    mov bp,sp
    sub sp,2h
    push ds
    push es
    push si
    push di
    mov ax,38AFh
    mov ds,ax
    mov si,52A6h
    mov ax,word ptr [si+18h]
    mov word ptr [bp-2h],ax
    mov ax,word ptr [bp-2h]
    pop di
    pop si
    pop es
    pop ds
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
