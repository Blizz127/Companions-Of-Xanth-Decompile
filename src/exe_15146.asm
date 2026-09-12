_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf4:FAR
    EXTRN mf11:FAR
    EXTRN mf17:FAR
    EXTRN mf22:FAR
    EXTRN mf31:FAR
    EXTRN mi37:NEAR
    EXTRN mf79:FAR
    EXTRN mf89:FAR
    EXTRN mf101:FAR
    EXTRN mf101:FAR
    EXTRN mf101:FAR
    EXTRN mf101:FAR
    EXTRN mf101:FAR
    EXTRN mf101:FAR
    EXTRN mf101:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,22h
    push si
    call mf4
    mov ax,3Ch
    cwd
    push dx
    push ax
    push word ptr ds:[57F2h]
    push word ptr ds:[57F0h]
    call mf11
    les bx, dword ptr [bp+6h]
    mov word ptr es:[bx+6h],ax
    lea ax,word ptr [bp-0Ch]
    push ss
    push ax
    call mf17
    add sp,4h
    lea ax,word ptr [bp-10h]
    push ss
    push ax
    call mf22
    add sp,4h
    cmp byte ptr [bp-10h],0h
    jnz short lbl59f
    cmp byte ptr [bp-0Fh],0h
    jnz short lbl59f
    lea ax,word ptr [bp-0Ch]
    push ss
    push ax
    call mf31
    add sp,4h
lbl59f:
    mov ax,word ptr [bp-0Ah]
    sub ax,7BCh
    mov cx,ax
    mov word ptr [bp-2h],ax
    add ax, offset mi37
    mov word ptr [bp-18h],ax
    mov al,byte ptr [bp-0Ch]
    sub ah,ah
    mov dx,ax
    mov word ptr [bp-6h],ax
    mov word ptr [bp-1Ch],ax
    mov bl,byte ptr [bp-0Bh]
    sub bh,bh
    mov word ptr [bp-4h],bx
    lea si,word ptr [bx-1h]
    mov word ptr [bp-1Ah],si
    add si,si
    add dx,word ptr [si+57C0h]
    mov word ptr [bp-14h],dx
    test cl,3h
    jnz short lbl9Cf
    cmp bx,2h
    jng short lbl9Cf
    inc dx
    mov word ptr [bp-14h],dx
lbl9Cf:
    mov al,byte ptr [bp-10h]
    sub ah,ah
    mov word ptr [bp-1Eh],ax
    mov al,byte ptr [bp-0Dh]
    mov cx,ax
    add ax,ax
    add ax,ax
    add ax,cx
    add ax,ax
    les bx, dword ptr [bp+6h]
    mov word ptr es:[bx+4h],ax
    mov al,byte ptr [bp-0Eh]
    sub ah,ah
    push ax
    mov al,byte ptr [bp-0Fh]
    push ax
    mov al,byte ptr [bp-10h]
    push ax
    push word ptr [bp-6h]
    push word ptr [bp-4h]
    push word ptr [bp-2h]
    call mf79
    add sp,0Ch
    les bx, dword ptr [bp+6h]
    mov word ptr es:[bx],ax
    mov word ptr es:[bx+2h],dx
    cmp word ptr ds:[57F4h],0h
    jz short lbl104f
    lea ax,word ptr [bp-22h]
    push ss
    push ax
    call mf89
    add sp,4h
    or ax,ax
    jz short lbl104f
    les bx, dword ptr [bp+6h]
    mov word ptr es:[bx+8h],1h
    jmp short lbl10Df
lbl104f:
    les bx, dword ptr [bp+6h]
    mov word ptr es:[bx+8h],0h
lbl10Df:
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
