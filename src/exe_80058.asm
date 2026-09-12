_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi2:NEAR
    EXTRN mi6:NEAR
    EXTRN mi7:NEAR
    EXTRN mi11:NEAR
    EXTRN mi12:NEAR
    EXTRN mf19:FAR
    EXTRN mf24:FAR
    EXTRN mf32:FAR
    EXTRN mi35:NEAR
    EXTRN mf46:FAR
    EXTRN mf49:FAR
    EXTRN mf60:FAR
    EXTRN mf107:FAR
    EXTRN md113:NEAR
    EXTRN md114:NEAR
    EXTRN md119:NEAR
    EXTRN md122:NEAR
    EXTRN md145:NEAR
    EXTRN md146:NEAR
    EXTRN mf152:FAR
    EXTRN md163:NEAR
    EXTRN md164:NEAR
    EXTRN mf165:FAR
    EXTRN md172:NEAR
    EXTRN md173:NEAR
    EXTRN md183:NEAR
    EXTRN md184:NEAR
    EXTRN mf186:FAR
    EXTRN md193:NEAR
    EXTRN md194:NEAR
    EXTRN mi200:NEAR
    EXTRN md206:NEAR
    EXTRN mi211:NEAR
    EXTRN md218:NEAR
    EXTRN md219:NEAR
    EXTRN mf220:FAR
    EXTRN md231:NEAR
    EXTRN md232:NEAR
    EXTRN mf234:FAR
    EXTRN mf240:FAR
    EXTRN mf240:FAR
    EXTRN mf240:FAR
    EXTRN mf240:FAR
    EXTRN mf240:FAR
    EXTRN mf240:FAR
    EXTRN mf240:FAR
    EXTRN mf240:FAR
    EXTRN mf240:FAR
    EXTRN mf240:FAR
    EXTRN mf240:FAR
    EXTRN mf240:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp, offset mi2
    push si
    push di
    mov ax,word ptr ds:[416Eh]
    and ax, offset mi6
    cmp ax, offset mi7
    jnz short lbl17f
    jmp near ptr lbl2Ff
lbl17f:
    mov ax,word ptr ds:[416Eh]
    and ax, offset mi11
    cmp ax, offset mi12
    jnz short lbl25f
    jmp near ptr lbl32f
lbl25f:
    cmp word ptr ds:[4196h],4h
    jnz short lbl2Ff
    jmp near ptr lbl32f
lbl2Ff:
    jmp near ptr lbl2DBf
lbl32f:
    call mf19
    push word ptr [bp+8h]
    push word ptr [bp+6h]
    mov ax,7h
    push ax
    call mf24
    add sp,6h
    mov word ptr [bp-10h],ax
    mov word ptr [bp-0Eh],dx
    mov ax,0h
    push ax
    push word ptr [bp-0Eh]
    push word ptr [bp-10h]
    call mf32
    add sp,6h
    mov word ptr [bp-4h],ax
    cmp ax, offset mi35
    jz short lbl6Cf
    jmp near ptr lbl6Ff
lbl6Cf:
    jmp near ptr lbl2DBf
lbl6Ff:
    mov ax,0h
    mov dx,0h
    push dx
    push ax
    mov ax,2h
    push ax
    push word ptr [bp-4h]
    call mf46
    add sp,8h
    push word ptr [bp-4h]
    call mf49
    add sp,2h
    mov word ptr [bp-0Ch],ax
    mov word ptr [bp-0Ah],dx
    mov ax,0h
    mov dx,0h
    push dx
    push ax
    mov ax,0h
    push ax
    push word ptr [bp-4h]
    call mf60
    add sp,8h
    mov word ptr [bp-12h],0h
    jmp near ptr lblBAf
lblB6b:
    add word ptr [bp-12h],1h
lblBAf:
    cmp word ptr [bp-0Ah],0h
    jnl short lblC3f
    jmp near ptr lbl2B7f
lblC3f:
    jng short lblC8f
    jmp near ptr lblD1f
lblC8f:
    cmp word ptr [bp-0Ch],0h
    ja short lblD1f
    jmp near ptr lbl2B7f
lblD1f:
    cmp word ptr [bp-12h],7h
    jc short lblDAf
    jmp near ptr lbl2B7f
lblDAf:
    cmp word ptr [bp-12h],0h
    jnz short lblE3f
    jmp near ptr lblE9f
lblE3f:
    mov ax,20h
    jmp near ptr lblECf
lblE9f:
    mov ax,0h
lblECf:
    mov word ptr [bp-6h],ax
    mov ax,0FFF0h
    sub ax,word ptr [bp-6h]
    mov dx,0h
    cmp word ptr [bp-0Ah],dx
    jnl short lbl100f
    jmp near ptr lbl119f
lbl100f:
    jng short lbl105f
    jmp near ptr lbl10Df
lbl105f:
    cmp word ptr [bp-0Ch],ax
    ja short lbl10Df
    jmp near ptr lbl119f
lbl10Df:
    mov ax,0FFF0h
    sub ax,word ptr [bp-6h]
    mov word ptr [bp-8h],ax
    jmp near ptr lbl122f
lbl119f:
    mov ax,word ptr [bp-0Ch]
    mov dx,word ptr [bp-0Ah]
    mov word ptr [bp-8h],ax
lbl122f:
    jmp near ptr lbl18Cf
lbl125b:
    mov ax,word ptr [bp-8h]
    add ax,word ptr [bp-6h]
    mov dx,0h
    push dx
    push ax
    call mf107
    add sp,4h
    mov bx,word ptr [bp-12h]
    shl bx,1
    shl bx,1
    mov es, ds:[5B44h]
    mov word ptr es:[bx+md113],ax
    mov word ptr es:[bx+md114],dx
    mov bx,word ptr [bp-12h]
    shl bx,1
    shl bx,1
    mov es, ds:[5B44h]
    cmp word ptr es:[bx+md119],0h
    jz short lbl163f
    jmp near ptr lbl16Ef
lbl163f:
    cmp word ptr es:[bx+md122],0h
    jnz short lbl16Ef
    jmp near ptr lbl174f
lbl16Ef:
    jmp near ptr lbl18Ff
    jmp near ptr lbl18Cf
lbl174f:
    mov cx,2h
    mov ax,word ptr [bp-8h]
    sub dx,dx
    div cx
    mov word ptr [bp-8h],ax
    cmp ax,2000h
    jc short lbl189f
    jmp near ptr lbl18Cf
lbl189f:
    jmp near ptr lbl2D0f
lbl18Cf:
    jmp near ptr lbl125b
lbl18Ff:
    cmp word ptr [bp-12h],0h
    jnz short lbl198f
    jmp near ptr lbl215f
lbl198f:
    push word ptr [bp-8h]
    mov bx,word ptr [bp-12h]
    shl bx,1
    shl bx,1
    mov es, ds:[5B44h]
    mov ax,word ptr es:[bx+md145]
    mov dx,word ptr es:[bx+md146]
    mov cx,20h
    add ax,cx
    push dx
    push ax
    push word ptr [bp-4h]
    call mf152
    add sp,8h
    mov ax,20h
    push ax
    mov es, ds:[5B44h]
    push word ptr es:[2h]
    push word ptr es:[0h]
    mov bx,word ptr [bp-12h]
    shl bx,1
    shl bx,1
    mov es, ds:[5B44h]
    push word ptr es:[bx+md163]
    push word ptr es:[bx+md164]
    call mf165
    add sp,0Ah
    mov ax,word ptr [bp-8h]
    mov bx,word ptr [bp-12h]
    shl bx,1
    shl bx,1
    mov es, ds:[5B44h]
    mov cx,word ptr es:[bx+md172]
    mov bx,word ptr es:[bx+md173]
    add bx,ax
    mov es,cx
    mov byte ptr es:[bx+1Eh],0h
    jmp near ptr lbl259f
lbl215f:
    push word ptr [bp-8h]
    mov bx,word ptr [bp-12h]
    shl bx,1
    shl bx,1
    mov es, ds:[5B44h]
    push word ptr es:[bx+md183]
    push word ptr es:[bx+md184]
    push word ptr [bp-4h]
    call mf186
    add sp,8h
    mov ax,word ptr [bp-8h]
    mov bx,word ptr [bp-12h]
    shl bx,1
    shl bx,1
    mov es, ds:[5B44h]
    mov cx,word ptr es:[bx+md193]
    mov bx,word ptr es:[bx+md194]
    add bx,ax
    mov es,cx
    mov byte ptr es:[bx-2h],0h
lbl259f:
    mov ax,word ptr [bp-8h]
    add ax,word ptr [bp-6h]
    add ax, offset mi200
    mov dx,0h
    mov bx,word ptr [bp-12h]
    shl bx,1
    shl bx,1
    mov es, ds:[5B44h]
    les bx, dword ptr es:[bx+md206]
    mov word ptr es:[bx+7h],ax
    mov word ptr es:[bx+9h],dx
    mov al,byte ptr ds:[41F5h]
    and ax,0FFh
    cmp ax, offset mi211
    jz short lbl28Bf
    jmp near ptr lbl2A8f
lbl28Bf:
    mov bx,word ptr [bp-12h]
    shl bx,1
    shl bx,1
    mov es, ds:[5B44h]
    push word ptr es:[bx+md218]
    push word ptr es:[bx+md219]
    call mf220
    add sp,4h
lbl2A8f:
    mov ax,word ptr [bp-8h]
    mov dx,0h
    sub word ptr [bp-0Ch],ax
    sbb word ptr [bp-0Ah],dx
    jmp near ptr lblB6b
lbl2B7f:
    mov bx,word ptr [bp-12h]
    shl bx,1
    shl bx,1
    mov es, ds:[5B44h]
    mov word ptr es:[bx+md231],0h
    mov word ptr es:[bx+md232],0h
lbl2D0f:
    push word ptr [bp-4h]
    call mf234
    add sp,2h
lbl2DBf:
    pop di
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
