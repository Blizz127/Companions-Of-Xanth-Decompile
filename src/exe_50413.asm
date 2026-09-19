_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mfd3:FAR
    EXTRN mfa2:FAR
    EXTRN mi6e:NEAR
    EXTRN md57:NEAR
    EXTRN md120:NEAR
    EXTRN mf90:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,56h
    push si
    mov ax,word ptr [bp+6h]
    mov word ptr [bp-0Eh],ax
    mov cx,0FFFFh
    mov word ptr [bp-4h],cx
    mov word ptr [bp-0Ah],cx
    xor cx,cx
    mov word ptr [bp-8h],cx
    mov word ptr [bp-6h],cx
    cmp ax,cx
    jnz short lbl25f
    db 0E9h, 7Fh, 01h ; override
lbl25b:
lbl25f:
    push word ptr [bp-0Ah]
    push word ptr [bp-8h]
    push word ptr [bp-0Eh]
    db 0FFh, 5Eh, 08h ; override
    add sp,6h
    or ax,ax
    jz short lbl3Bf
    db 0E9h, 69h, 01h ; override
lbl3Bf:
    mov si,word ptr [bp-4h]
    add si,si
    add si,si
    lea ax,word ptr [bp+si-4Eh]
    mov word ptr [bp-52h],ax
lbl48b:
    mov es, ds:[5A2Ch]
    mov bx,word ptr [bp-0Eh]
    mov ax,bx
    add bx,bx
    add bx,ax
    add bx,bx
    mov al,byte ptr es:[bx+md57]
    mov byte ptr [bp-2h],al
    mov word ptr [bp-10h],0h
    mov bl,al
    sub bh,bh
    mov ax,bx
    add bx,bx
    add bx,ax
    add bx, offset mi6e
    mov es, ds:[5A2Eh]
    mov word ptr [bp-56h],bx
    mov word ptr [bp-54h],es
    mov al,byte ptr es:[bx]
    cmp ax,word ptr [bp-6h]
    jng short lblC1f
lbl84b:
    cmp word ptr [bp+0Ch],0h
    jz short lbl9Cf
    push word ptr [bp-6h]
    push word ptr [bp-0Eh]
    call mf90
    add sp,4h
    or ax,ax
    jz short lblB1f
lbl9Cf:
    push word ptr [bp-6h]
    push word ptr [bp-0Eh]
    call mfa2
    add sp,4h
    mov word ptr [bp-10h],ax
    or ax,ax
    jnz short lblC1f
lblB1f:
    les bx, dword ptr [bp-56h]
    sub ah,ah
    mov al,byte ptr es:[bx]
    inc word ptr [bp-6h]
    cmp ax,word ptr [bp-6h]
    jg short lbl84b
lblC1f:
    cmp word ptr [bp-10h],0h
    jnz short lbl10Cf
    cmp word ptr [bp-4h],0h
    jnl short lblD0f
    db 0E9h, 0C6h, 00h ; override
lblD0f:
    push word ptr [bp-0Eh]
    call mfd3
    add sp,2h
    mov word ptr [bp-10h],ax
    or ax,ax
    jz short lblE5f
    db 0E9h, 0A7h, 00h ; override
lblE5f:
    mov bx,word ptr [bp-52h]
    mov ax,word ptr [bx]
    mov word ptr [bp-0Eh],ax
    sub ah,ah
    mov al,byte ptr [bx-2h]
    mov word ptr [bp-6h],ax
    mov al,byte ptr [bx-1h]
    mov word ptr [bp-0Ah],ax
    sub word ptr [bp-52h],4h
    dec word ptr [bp-4h]
    dec word ptr [bp-8h]
    inc word ptr [bp-6h]
    jmp near ptr lbl48b
    nop
lbl10Cf:
    mov ax,word ptr [bp+6h]
    cmp word ptr [bp-0Eh],ax
    db 75h, 1Ch ; override
    mov es, ds:[5A2Ch]
    mov bx,ax
    add bx,ax
    add bx,ax
    add bx,bx
    cmp byte ptr es:[bx+md120],1h
    jnz short lbl130f
    mov word ptr [bp-0Ch],0h
    jmp short lbl159f
    nop
lbl130f:
    mov ax,word ptr ds:[258h]
    cmp word ptr [bp-0Eh],ax
    jnz short lbl140f
    mov word ptr [bp-0Ch],1h
    jmp short lbl159f
    nop
lbl140f:
    cmp word ptr [bp-0Ah],0h
    jnz short lbl14Ef
    mov word ptr [bp-0Ch],2h
    jmp short lbl159f
    nop
lbl14Ef:
    cmp word ptr [bp-0Ah],1h
    jnz short lbl159f
    mov word ptr [bp-0Ch],3h
lbl159f:
    mov ax,word ptr [bp-0Eh]
    inc word ptr [bp-4h]
    mov si,word ptr [bp-4h]
    add si,si
    add si,si
    mov word ptr [bp+si-4Eh],ax
    mov al,byte ptr [bp-6h]
    mov byte ptr [bp+si-50h],al
    mov al,byte ptr [bp-0Ah]
    mov byte ptr [bp+si-4Fh],al
    mov ax,word ptr [bp-10h]
    mov word ptr [bp-0Eh],ax
    mov word ptr [bp-6h],0h
    mov ax,word ptr [bp-0Ch]
    mov word ptr [bp-0Ah],ax
    inc word ptr [bp-8h]
    jmp short lbl19Bf
    nop
lbl18Cf:
    mov word ptr [bp-0Eh],ax
    mov word ptr [bp-6h],0h
    jmp short lbl19Bf
lbl196f:
    mov word ptr [bp-0Eh],0h
lbl19Bf:
    cmp word ptr [bp-0Eh],0h
    jz short lbl1A4f
    jmp near ptr lbl25b
lbl1A4f:
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
