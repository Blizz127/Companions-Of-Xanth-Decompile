_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi2:NEAR
    EXTRN mi7:NEAR
    EXTRN mi29:NEAR
    EXTRN mi35:NEAR
    EXTRN mi49:NEAR
    EXTRN mi60:NEAR
    EXTRN mi70:NEAR
    EXTRN md81:NEAR
    EXTRN mi92:NEAR
    EXTRN mf94:FAR
    EXTRN mf100:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp, offset mi2
    push si
    push di
    mov al,byte ptr ds:[5E7Bh]
    cbw
    cmp ax, offset mi7
    jnz short lbl15f
    jmp near ptr lbl28f
lbl15f:
    mov bx,word ptr [bp+6h]
    mov es, ds:[5B36h]
    mov al,byte ptr es:[bx+1CAh]
    cbw
    mov word ptr [bp-8h],ax
    jmp near ptr lbl38f
lbl28f:
    mov bx,word ptr [bp+6h]
    mov es, ds:[5B36h]
    mov al,byte ptr es:[bx+1B8h]
    cbw
    mov word ptr [bp-8h],ax
lbl38f:
    mov ax,0Eh
    imul word ptr [bp+6h]
    mov bx,0h
    mov cx,2E8Eh
    add bx,ax
    mov es,cx
    mov al,byte ptr es:[bx+8h]
    cbw
    and ax, offset mi29
    mov cx,3Fh
    sub cx,ax
    mov word ptr [bp-4h],cx
    mov al,byte ptr ds:[5E7Bh]
    cbw
    cmp ax, offset mi35
    jnz short lbl64f
    jmp near ptr lbl73f
lbl64f:
    cmp word ptr [bp-8h],6h
    ja short lbl6Df
    jmp near ptr lbl73f
lbl6Df:
    mov ax,1h
    jmp near ptr lbl76f
lbl73f:
    mov ax,0h
lbl76f:
    mov word ptr [bp-6h],ax
    mov bx,word ptr [bp+6h]
    mov es, ds:[5B36h]
    mov al,byte ptr es:[bx+1A6h]
    cbw
    cmp ax, offset mi49
    jz short lbl8Ef
    jmp near ptr lblB4f
lbl8Ef:
    mov ax,0Eh
    imul word ptr [bp+6h]
    mov bx,0h
    mov cx,2E8Eh
    add bx,ax
    mov es,cx
    mov al,byte ptr es:[bx+0Ch]
    cbw
    cmp ax, offset mi60
    jnz short lblABf
    jmp near ptr lblB4f
lblABf:
    cmp word ptr [bp-6h],0h
    jnz short lblB4f
    jmp near ptr lblCAf
lblB4f:
    mov bx,word ptr [bp-8h]
    mov al,byte ptr [bx+5E6Ah]
    cbw
    imul word ptr [bp-4h]
    add ax, offset mi70
    mov cx,7h
    shr ax,cl
    mov word ptr [bp-4h],ax
lblCAf:
    mov ax,3Fh
    sub ax,word ptr [bp-4h]
    mov word ptr [bp-4h],ax
    mov ax,0Eh
    imul word ptr [bp+6h]
    mov bx,ax
    mov es, ds:[5B36h]
    mov al,byte ptr es:[bx+md81]
    cbw
    mov cx,6h
    shl ax,cl
    or word ptr [bp-4h],ax
    mov ax,word ptr [bp-4h]
    push ax
    mov bx,word ptr [bp+6h]
    mov es, ds:[5B36h]
    mov al,byte ptr es:[bx+194h]
    cbw
    add ax, offset mi92
    push ax
    call mf94
    add sp,4h
    pop di
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
