_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf4e:FAR
    EXTRN mff9:FAR
    EXTRN mfa1:FAR
    EXTRN mf9a:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,1Eh
    push di
    push si
    mov ax,word ptr ds:[4F68h]
    mov word ptr [bp-8h],ax
    or ax,ax
    jnz short lbl15f
    jmp near ptr lbl1E2f
lbl15f:
    xor ax,ax
    mov word ptr [bp-14h],ax
    mov word ptr [bp-0Ah],ax
    cmp word ptr [bp-8h],ax
    jg short lbl25f
    jmp near ptr lbl1DAf
lbl25f:
    mov word ptr [bp-16h],ax
lbl28b:
    mov bx,word ptr [bp-16h]
    les bx, dword ptr [bx+678Ah]
    mov ax,word ptr es:[bx]
    mov dx,word ptr es:[bx+2h]
    mov word ptr [bp-4h],ax
    mov word ptr [bp-2h],dx
    mov bx,word ptr [bp-0Ah]
    mov al,byte ptr [bx+6770h]
    cbw
    mov word ptr [bp-0Ch],ax
    or ax,ax
    jnl short lbl4Ef
    jmp near ptr lbl1C8f
lbl4Ef:
    call mf4e
    mov bx,word ptr [bp-16h]
    cmp word ptr [bx+6778h],dx
    jng short lbl5Ff
    jmp near ptr lbl1C8f
lbl5Ff:
    jl short lbl6Af
    cmp word ptr [bx+6776h],ax
    jna short lbl6Af
    jmp near ptr lbl1C8f
lbl6Af:
    les bx, dword ptr [bp-4h]
    sub ah,ah
    mov al,byte ptr es:[bx+1h]
    mov word ptr [bp-10h],ax
    mov bx,word ptr [bp-0Ah]
    mov al,byte ptr [bx+676Ah]
    cbw
    mov word ptr [bp-12h],ax
    mov ax,word ptr [bp-0Ch]
    mov word ptr [bp-0Eh],ax
    or ax,ax
    jng short lbl9Af
    cmp word ptr [bp-12h],0h
    jnl short lbl9Af
    cmp word ptr [bp-10h],3h
    jnz short lbl9Af
    dec word ptr [bp-0Eh]
lbl9Af:
    call mf9a
    mov si,ax
    call mfa1
    mov cx,ax
    mov ax,14h
    mov bx,dx
    imul word ptr [bp-0Eh]
    mov di,ax
    mov es, [bp-2h]
    add di,word ptr [bp-4h]
    mov al,32h
    mul byte ptr es:[di+0Ah]
    cwd
    mov word ptr [bp-1Eh],ax
    mov word ptr [bp-1Ch],dx
    mov al,32h
    mul byte ptr es:[di+0Bh]
    mov di,ax
    inc di
    mov ax,si
    cwd
    idiv di
    mov ax,dx
    cwd
    add ax,word ptr [bp-1Eh]
    adc dx,word ptr [bp-1Ch]
    add cx,ax
    adc bx,dx
    mov si,word ptr [bp-16h]
    mov word ptr [si+6776h],cx
    mov word ptr [si+6778h],bx
    mov ax,14h
    imul word ptr [bp-0Ch]
    add ax,word ptr [bp-4h]
    mov dx,word ptr [bp-2h]
    push dx
    push ax
    call mff9
    mov bx,word ptr [bp-16h]
    add sp,4h
    mov ax,word ptr [bx+679Eh]
    mov dx,word ptr [bx+67A0h]
    mov word ptr [bp-1Ah],ax
    mov word ptr [bp-18h],dx
    or dx,ax
    jz short lbl11Ff
    push word ptr [bp-0Ch]
    db 0FFh, 5Eh, 0E6h ; override
    add sp,2h
lbl11Ff:
    cmp word ptr [bp-12h],0h
    jz short lbl16Ef
    mov ax,word ptr [bp-12h]
    add word ptr [bp-0Ch],ax
    js short lbl13Af
    mov bx,word ptr [bp-0Ah]
    mov al,byte ptr [bx+6764h]
    cbw
    cmp ax,word ptr [bp-0Ch]
    jg short lbl18Ef
lbl13Af:
    cmp word ptr [bp+6h],1h
    jnz short lbl166f
    cmp word ptr [bp-10h],3h
    jnz short lbl14Cf
    mov ax,1h
    jmp short lbl14Ff
    nop
lbl14Cf:
    mov ax,2h
lbl14Ff:
    mov cx,word ptr [bp-12h]
    neg cx
    mov word ptr [bp-12h],cx
    imul cx
    add word ptr [bp-0Ch],ax
    mov bx,word ptr [bp-0Ah]
    mov byte ptr [bx+676Ah],cl
    jmp short lbl18Ef
    nop
lbl166f:
    mov word ptr [bp-0Ch],0FFFFh
    jmp short lbl18Ef
    nop
lbl16Ef:
    mov bx,word ptr [bp-0Ah]
    mov al,byte ptr [bx+6764h]
    cbw
    inc word ptr [bp-0Ch]
    cmp ax,word ptr [bp-0Ch]
    jg short lbl18Ef
    cmp word ptr [bp+6h],1h
    jnz short lbl188f
    xor ax,ax
    jmp short lbl18Bf
lbl188f:
    mov ax,0FFFFh
lbl18Bf:
    mov word ptr [bp-0Ch],ax
lbl18Ef:
    mov bx,word ptr [bp-0Ah]
    mov al,byte ptr [bp-0Ch]
    mov byte ptr [bx+6770h],al
    cmp word ptr [bp-0Ch],0h
    jnl short lbl1C8f
    mov word ptr [bp-14h],1h
    mov word ptr [bp-6h],0h
    cmp word ptr [bp-8h],0h
    jng short lbl1C8f
lbl1AEb:
    mov bx,word ptr [bp-6h]
    cmp byte ptr [bx+6770h],0h
    jl short lbl1BDf
    mov word ptr [bp-14h],0h
lbl1BDf:
    mov ax,word ptr [bp-8h]
    inc word ptr [bp-6h]
    cmp word ptr [bp-6h],ax
    jl short lbl1AEb
lbl1C8f:
    add word ptr [bp-16h],4h
    mov ax,word ptr [bp-8h]
    inc word ptr [bp-0Ah]
    cmp word ptr [bp-0Ah],ax
    jnl short lbl1DAf
    jmp near ptr lbl28b
lbl1DAf:
    cmp word ptr [bp-14h],1h
    db 1Bh, 0C0h ; override
    neg ax
lbl1E2f:
    pop si
    pop di
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
