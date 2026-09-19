_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mjn123:NEAR
    EXTRN mn97:NEAR
    EXTRN mf65:FAR
    EXTRN mnad:NEAR
    EXTRN mjn13:NEAR
    EXTRN mjn12f:NEAR
    EXTRN mnbd:NEAR
    EXTRN mna2:NEAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,8h
    mov bx,word ptr [bp+6h]
    cmp bx,word ptr ds:[53CAh]
    jc short lbl16f
    mov ax,900h
    stc
lbl13b:
    jmp mjn13
lbl16f:
    cmp word ptr ds:[59FAh],0D6D6h
    jnz short lbl22f
    call word ptr ds:[59FCh]
lbl22f:
    test byte ptr [bx+53CCh],20h
    jz short lbl34f
    mov ax,4202h
    xor cx,cx
    mov dx,cx
    int 21h
    jc short lbl13b
lbl34f:
    test byte ptr [bx+53CCh],80h
    jz short lblB7f
    mov word ptr [bp-6h],ds
    mov es, [bp+0Ah]
    lds dx, dword ptr [bp+8h]
    xor ax,ax
    mov word ptr [bp-2h],ax
    mov word ptr [bp-4h],ax
    cld
    push di
    push si
    mov di,dx
    mov si,dx
    mov word ptr [bp-8h],sp
    mov cx,word ptr [bp+0Ch]
    jcxz lbl9Af
    mov al,0Ah
    repne scasb
    jnz short lblB2f
    push ds
    mov ds, [bp-6h]
    call mf65
    cmp ax,0A8h
    jna short lblB9f
    pop ds
    sub sp,2h
    mov bx,sp
    mov dx,200h
    cmp ax,228h
    jnc short lbl80f
    mov dx,80h
lbl80f:
    sub sp,dx
    mov dx,sp
    mov di,dx
    push ss
    pop es
    mov cx,word ptr [bp+0Ch]
lbl8Bb:
    lodsb
    cmp al,0Ah
    jz short lbl9Cf
lbl90b:
    cmp di,bx
    jz short lblADf
lbl94b:
    stosb
    loop lbl8Bb
    call mn97
lbl9Af:
    jmp short lbl115f
lbl9Cf:
    mov al,0Dh
    cmp di,bx
    jnz short lblA5f
    call mna2
lblA5f:
    stosb
    mov al,0Ah
    inc word ptr [bp-4h]
    jmp short lbl90b
lblADf:
    call mnad
    jmp short lbl94b
lblB2f:
    pop si
    pop di
    mov ds, [bp-6h]
lblB7f:
    jmp short lbl126f
lblB9f:
    mov ax,0FFFCh
    push cs
    call mnbd
    push ax
    push bx
    push cx
    push ds
    push es
    pop ds
    mov cx,di
    sub cx,dx
    jcxz lblDEf
    push cx
    mov bx,word ptr [bp+6h]
    mov ah,40h
    int 21h
    pop cx
    jc short lblE5f
    add word ptr [bp-2h],ax
    cmp cx,ax
    ja short lblE5f
lblDEf:
    pop ds
    pop cx
    pop bx
    pop ax
    mov di,dx
    ret
lblE5f:
    lahf
    pop ds
    add sp,8h
    cmp word ptr [bp-2h],0h
    jnz short lbl115f
    sahf
    jnc short lblF7f
    mov ah,9h
    jmp short lbl11Bf
lblF7f:
    mov ds, [bp-6h]
    test byte ptr [bx+53CCh],40h
    jz short lbl10Ff
    mov ds, [bp+0Ah]
    mov bx,word ptr [bp+8h]
    cmp byte ptr [bx],1Ah
    jnz short lbl10Ff
    clc
    jmp short lbl11Bf
lbl10Ff:
    stc
    mov ax,1C00h
    jmp short lbl11Bf
lbl115f:
    mov ax,word ptr [bp-2h]
    sub ax,word ptr [bp-4h]
lbl11Bf:
    mov sp,word ptr [bp-8h]
    pop si
    pop di
    mov ds, [bp-6h]
lbl123b:
    jmp mjn123
lbl126f:
    mov cx,word ptr [bp+0Ch]
    or cx,cx
    jnz short lbl132f
    mov ax,cx
    jmp mjn12f
lbl132f:
    push ds
    lds dx, dword ptr [bp+8h]
    mov ah,40h
    int 21h
    push ds
    pop es
    pop ds
    jnc short lbl143f
    mov ah,9h
    jmp short lbl123b
lbl143f:
    or ax,ax
    jnz short lbl123b
    test byte ptr [bx+53CCh],40h
    jz short lbl159f
    mov bx,dx
    cmp byte ptr es:[bx],1Ah
    jnz short lbl159f
    clc
    jmp short lbl123b
lbl159f:
    stc
    mov ax,1C00h
    jmp short lbl123b
    add byte ptr [bx+di+5Ah],bl
    mov ax,word ptr ds:[5400h]
    cmp ax,sp
    jnc short lbl170f
    sub ax,sp
    neg ax
lbl16Db:
    push dx
    push cx
    retf
lbl170f:
    xor ax,ax
    jmp short lbl16Db
    push bp
    mov bp,sp
    push si
    les si, dword ptr [bp+6h]
    mov cx,es
    jcxz lbl184f
    or byte ptr es:[si-2h],1h
lbl184f:
    pop si
    pop bp
    retf
lblCE49f:
_TEXT ENDS
    END
