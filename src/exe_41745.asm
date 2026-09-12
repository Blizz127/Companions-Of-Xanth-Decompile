_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf5:FAR
    EXTRN mf9:FAR
    EXTRN mf13:FAR
    EXTRN mf30:FAR
    EXTRN mi50:NEAR
    EXTRN mf70:FAR
    EXTRN mf90:FAR
    EXTRN mf96:FAR
    EXTRN mf98:FAR
    EXTRN mf103:FAR
    EXTRN mf108:FAR
    EXTRN mf116:FAR
    EXTRN mf122:FAR
    EXTRN mf124:FAR
    EXTRN mf129:FAR
    EXTRN mi132:NEAR
    EXTRN mf139:FAR
    EXTRN mf144:FAR
    EXTRN mf149:FAR
    EXTRN mf155:FAR
    EXTRN mf167:FAR
    EXTRN mf176:FAR
    EXTRN mf186:FAR
    EXTRN mf197:FAR
    EXTRN mf203:FAR
    EXTRN mf214:FAR
    EXTRN mi219:NEAR
    EXTRN mf237:FAR
    EXTRN mf249:FAR
    EXTRN mf255:FAR
    EXTRN mf264:FAR
    EXTRN mf287:FAR
    EXTRN mf295:FAR
    EXTRN mf303:FAR
    EXTRN mf317:FAR
    EXTRN mf320:FAR
    EXTRN mf320:FAR
    EXTRN mf320:FAR
    EXTRN mf320:FAR
    EXTRN mf320:FAR
    EXTRN mf320:FAR
    EXTRN mf320:FAR
    EXTRN mf320:FAR
    EXTRN mf320:FAR
    EXTRN mf320:FAR
    EXTRN mf320:FAR
    EXTRN mf320:FAR
    EXTRN mf320:FAR
    EXTRN mf320:FAR
    EXTRN mf320:FAR
    EXTRN mf320:FAR
    EXTRN mf320:FAR
    EXTRN mf320:FAR
    EXTRN mf320:FAR
    EXTRN mf320:FAR
    EXTRN mf320:FAR
    EXTRN mf320:FAR
    EXTRN mf320:FAR
    EXTRN mf320:FAR
    EXTRN mf320:FAR
    EXTRN mf320:FAR
    EXTRN mf320:FAR
    EXTRN mf320:FAR
    EXTRN mf320:FAR
    EXTRN mf320:FAR
    EXTRN mf320:FAR
    EXTRN mf320:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,16h
    mov ax,2h
    push ax
    call mf5
    add sp,2h
    xor ax,ax
    push ax
    call mf9
    add sp,2h
    cmp word ptr ds:[66h],0h
    jz short lbl2Ff
    call mf13
    mov word ptr ds:[66h],0h
lbl2Ff:
    lea ax,word ptr [bp-0Ch]
    push ss
    push ax
    lea ax,word ptr [bp-0Ah]
    push ss
    push ax
    lea ax,word ptr [bp-8h]
    push ss
    push ax
    mov ax,word ptr ds:[69E6h]
    mov word ptr [bp-6h],ax
    push ax
    mov ax,word ptr ds:[69E4h]
    mov word ptr [bp-4h],ax
    push ax
    call mf30
    add sp,10h
    mov word ptr [bp-2h],0h
    mov word ptr [bp-14h],0h
    test byte ptr ds:[69E8h],2h
    jz short lbl8Cf
    cmp word ptr [bp-8h],0h
    jnz short lbl7Af
    cmp word ptr [bp-0Ch],1h
    jnz short lbl7Af
    mov word ptr ds:[5Eh],0h
    jmp short lbl8Cf
    nop
lbl7Af:
    cmp word ptr [bp-0Ch],8h
    jz short lbl8Cf
    cmp word ptr ds:[5Eh],0h
    jnz short lbl8Cf
    mov word ptr [bp-0Ch],0h
lbl8Cf:
    mov ax,word ptr [bp-0Ch]
    dec ax
    cmp ax, offset mi50
    jna short lbl98f
    jmp near ptr lbl378f
lbl98f:
    add ax,ax
    xchg ax,bx
    jmp word ptr cs:[bx+1941h]
    push cx
    sbb word ptr [bx+di],bx
    sbb al,9Bh
    sbb bl,byte ptr [bx+di]
    sbb al,25h
    sbb al,byte ptr [di+1Ah]
    lea bx,word ptr [bp+si]
    sti
    sbb al,byte ptr [bp+di-782h]
    add word ptr [di+16h],si
    cmp word ptr ds:[56h],1h
    jnz short lblCCf
    push word ptr [bp-6h]
    push word ptr [bp-4h]
    call mf70
    jmp near ptr lbl1AFf
    nop
lblCCf:
    cmp word ptr [bp-8h],5h
    jz short lblD5f
    jmp near ptr lbl378f
lblD5f:
    cmp word ptr ds:[69FCh],0Eh
    ja short lblDFf
    jmp near ptr lbl378f
lblDFf:
    mov ax,word ptr [bp-0Ah]
    dec ax
    jz short lblECf
    dec ax
    jz short lbl13Cf
    jmp near ptr lbl378f
    nop
lblECf:
    mov ax,98h
    push ax
    mov ax,125h
    push ax
    call mf90
    add sp,4h
    mov ax,1h
    push ax
    mov cx,105h
    push cx
    call mf96
    add sp,4h
    call mf98
    mov ax,1h
    push ax
    mov ax,105h
    push ax
    call mf103
    add sp,4h
    sub word ptr ds:[64h],7h
    jns short lbl12Ef
    mov word ptr ds:[64h],0h
lbl12Eb:
lbl12Ef:
    call mf108
    mov word ptr [bp-2h],1h
    jmp near ptr lbl378f
    nop
lbl13Cf:
    mov ax,98h
    push ax
    mov ax,125h
    push ax
    call mf116
    add sp,4h
    mov ax,1h
    push ax
    mov cx,106h
    push cx
    call mf122
    add sp,4h
    call mf124
    mov ax,1h
    push ax
    mov ax,106h
    push ax
    call mf129
    add sp,4h
    mov ax,word ptr ds:[64h]
    add ax, offset mi132
    cmp ax,word ptr ds:[69FCh]
    jnc short lbl12Eb
    add word ptr ds:[64h],7h
    jmp short lbl12Eb
    push word ptr [bp-0Ah]
    push word ptr [bp-8h]
    call mf139
    add sp,4h
    push word ptr [bp-0Ah]
    mov ax,100h
lbl198b:
    push ax
    call mf144
    add sp,4h
    jmp near ptr lbl378f
    push word ptr [bp-6h]
    push word ptr [bp-4h]
    call mf149
lbl1AFf:
    add sp,4h
    mov word ptr [bp-10h],ax
    or ax,ax
    jnl short lbl1BCf
    jmp near ptr lbl378f
lbl1BCf:
    call mf155
    sub ax,ax
    push ax
    push ax
    push ax
    mov es, ds:[5A20h]
    mov bx,word ptr [bp-10h]
    add bx,bx
    push word ptr es:[bx+0B6h]
    mov cx,51h
    mov word ptr [bp-2h],cx
    push cx
    call mf167
    add sp,0Ah
    xor ax,ax
    push ax
    mov ax,200h
    jmp short lbl198b
    nop
    push word ptr [bp-0Ah]
    push word ptr [bp-8h]
    call mf176
    add sp,4h
    cmp word ptr ds:[50h],0h
    jnz short lbl20Ef
    test byte ptr ds:[69E8h],2h
    jz short lbl20Ef
    mov ax,word ptr ds:[5Eh]
    mov word ptr ds:[50h],ax
lbl20Ef:
    push word ptr [bp-0Ah]
    push word ptr [bp-8h]
    call mf186
    add sp,4h
    mov word ptr [bp-14h],ax
    push ax
    xor ax,ax
    push ax
    push word ptr ds:[54h]
    push word ptr ds:[52h]
    push word ptr ds:[50h]
    mov ax,1h
    push ax
    call mf197
    add sp,0Ch
    mov word ptr [bp-12h],ax
    or ax,ax
    jz short lbl245f
    jmp near ptr lbl302f
lbl245f:
    call mf203
    cmp word ptr ds:[52h],0h
    jnz short lbl254f
    jmp near ptr lbl2D4f
lbl254f:
    mov ax,word ptr ds:[52h]
    jmp short lbl2D7f
    nop
    lea ax,word ptr [bp-6h]
    push ss
    push ax
    push word ptr [bp-0Ah]
    call mf214
    add sp,6h
    mov word ptr [bp-2h],ax
    test byte ptr ds:[69E8h],2h
    jz short lbl294f
    cmp ax, offset mi219
    jnz short lbl27Ef
    mov word ptr [bp-2h],13h
lbl27Ef:
    mov ax,word ptr ds:[5Ah]
    cmp word ptr [bp-6h],ax
    jnl short lbl294f
    mov ax,word ptr [bp-2h]
    mov word ptr ds:[5Eh],ax
    mov word ptr [bp-2h],0h
    jmp near ptr lbl378f
lbl294f:
    mov ax,word ptr ds:[50h]
    cmp word ptr [bp-2h],ax
    jnz short lbl2A4f
    mov word ptr [bp-2h],0h
    jmp short lbl2B2f
    nop
lbl2A4f:
    push word ptr [bp-6h]
    push word ptr [bp-2h]
    call mf237
    add sp,4h
lbl2B2f:
    xor ax,ax
    push ax
    mov ax,word ptr [bp-2h]
    mov word ptr ds:[50h],ax
    push ax
    push word ptr ds:[54h]
    push word ptr ds:[52h]
    push ax
    mov ax,1h
    push ax
    call mf249
    add sp,0Ch
    jmp near ptr lbl378f
lbl2D4f:
    mov ax,word ptr [bp-14h]
lbl2D7f:
    mov word ptr [bp-16h],ax
    push ax
    call mf255
    add sp,2h
    mov word ptr ds:[5C34h],ax
    mov word ptr ds:[5C36h],dx
    push word ptr ds:[5Ah]
    mov ax,2h
    push ax
    push dx
    push word ptr ds:[5C34h]
    call mf264
    add sp,8h
    mov word ptr ds:[5Ch],ax
lbl302f:
    cmp word ptr ds:[52h],0h
    jz short lbl31Af
    mov ax,word ptr ds:[52h]
    cmp word ptr [bp-14h],ax
    jz short lbl31Af
    mov ax,word ptr [bp-14h]
    mov word ptr ds:[54h],ax
    jmp short lbl33Ff
    nop
lbl31Af:
    mov ax,word ptr [bp-14h]
    mov word ptr ds:[52h],ax
    cmp word ptr [bp-12h],0h
    jnz short lbl33Ff
    push ax
    xor ax,ax
    push ax
    push word ptr ds:[54h]
    push word ptr ds:[52h]
    push word ptr ds:[50h]
    push ax
    call mf287
    add sp,0Ch
lbl33Ff:
    cmp word ptr [bp-12h],0h
    jz short lbl358f
    test byte ptr ds:[69E8h],2h
    jz short lbl358f
    mov ax,1F4h
    push ax
    call mf295
    add sp,2h
lbl358f:
    cmp word ptr [bp-12h],0h
    jz short lbl378f
    xor ax,ax
    push ax
    xor cx,cx
    push cx
    call mf303
    add sp,4h
    mov word ptr ds:[60h],0h
    mov word ptr ds:[62h],0h
lbl378f:
    cmp word ptr [bp-2h],0h
    jnz short lbl39Ef
    cmp word ptr [bp-14h],0h
    jnz short lbl39Ef
    cmp word ptr ds:[50h],0h
    jnz short lbl399f
    cmp word ptr ds:[52h],0h
    jnz short lbl399f
    cmp word ptr ds:[54h],0h
    jz short lbl39Ef
lbl399f:
    call mf317
lbl39Ef:
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
