_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf19:FAR
    EXTRN mf33:FAR
    EXTRN mi55:NEAR
    EXTRN mi63:NEAR
    EXTRN mf71:FAR
    EXTRN mf74:FAR
    EXTRN mf82:FAR
    EXTRN mf89:FAR
    EXTRN mf98:FAR
    EXTRN mf109:FAR
    EXTRN mf118:FAR
    EXTRN mf136:FAR
    EXTRN mi150:NEAR
    EXTRN mf158:FAR
    EXTRN mf162:FAR
    EXTRN mf168:FAR
    EXTRN mf174:FAR
    EXTRN mf180:FAR
    EXTRN mf186:FAR
    EXTRN mf190:FAR
    EXTRN mf200:FAR
    EXTRN mi215:NEAR
    EXTRN mf222:FAR
    EXTRN mf226:FAR
    EXTRN mf232:FAR
    EXTRN mf238:FAR
    EXTRN mf244:FAR
    EXTRN mf250:FAR
    EXTRN mf256:FAR
    EXTRN mf260:FAR
    EXTRN mf266:FAR
    EXTRN mf271:FAR
    EXTRN mf271:FAR
    EXTRN mf271:FAR
    EXTRN mf271:FAR
    EXTRN mf271:FAR
    EXTRN mf271:FAR
    EXTRN mf271:FAR
    EXTRN mf271:FAR
    EXTRN mf271:FAR
    EXTRN mf271:FAR
    EXTRN mf271:FAR
    EXTRN mf271:FAR
    EXTRN mf271:FAR
    EXTRN mf271:FAR
    EXTRN mf271:FAR
    EXTRN mf271:FAR
    EXTRN mf271:FAR
    EXTRN mf271:FAR
    EXTRN mf271:FAR
    EXTRN mf271:FAR
    EXTRN mf271:FAR
    EXTRN mf271:FAR
    EXTRN mf271:FAR
    EXTRN mf271:FAR
    EXTRN mf271:FAR
    EXTRN mf271:FAR
    EXTRN mf271:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,16h
    push di
    push si
    cmp word ptr [bp+0Ah],0h
    jnl short lbl11f
    dec word ptr [bp+6h]
lbl11f:
    cmp word ptr [bp+0Ch],0h
    jnl short lbl1Af
    dec word ptr [bp+8h]
lbl1Af:
    cmp word ptr [bp+0Eh],0h
    jng short lbl23f
    dec word ptr [bp+0Eh]
lbl23f:
    cmp word ptr [bp+10h],0h
    jng short lbl2Cf
    dec word ptr [bp+10h]
lbl2Cf:
    mov ax,0Ah
    push ax
    call mf19
    add sp,2h
    cmp word ptr [bp+0Ah],0h
    jnz short lbl41f
    jmp near ptr lbl14Ef
lbl41f:
    cmp word ptr [bp+0Ch],0h
    jnz short lbl4Af
    jmp near ptr lbl14Ef
lbl4Af:
    jl short lbl52f
    mov ax,6h
    jmp short lbl55f
    nop
lbl52f:
    mov ax,0Fh
lbl55f:
    push ax
    call mf33
    add sp,2h
    mov ax,word ptr [bp+0Ah]
    mov cx,ax
    add ax,ax
    add ax,ax
    add ax,cx
    add ax,ax
    add ax,word ptr [bp+6h]
    push ax
    mov cx,word ptr [bp+0Ch]
    mov dx,cx
    add cx,cx
    add cx,cx
    add cx,dx
    add cx,cx
    add cx,word ptr [bp+8h]
    push cx
    mov dx,ax
    mov ax,1Eh
    mov bx,dx
    imul word ptr [bp+0Eh]
    add ax, offset mi55
    imul word ptr [bp+0Ah]
    mov dx,bx
    add bx,ax
    push bx
    mov ax,19h
    mov si,dx
    imul word ptr [bp+10h]
    add ax, offset mi63
    imul word ptr [bp+0Ch]
    mov dx,cx
    add cx,ax
    push cx
    mov di,cx
    mov word ptr [bp-0Ah],dx
    mov word ptr [bp-0Ch],bx
    call mf71
    mov ax,0Ah
    push ax
    call mf74
    add sp,2h
    add si,word ptr [bp+0Ah]
    push si
    push word ptr [bp-0Ah]
    push word ptr [bp-0Ch]
    sub di,word ptr [bp+0Ch]
    push di
    call mf82
    add si,word ptr [bp+0Ah]
    push si
    push word ptr [bp-0Ah]
    push word ptr [bp-0Ch]
    sub di,word ptr [bp+0Ch]
    push di
    call mf89
    push si
    mov ax,word ptr [bp-0Ah]
    sub ax,word ptr [bp+0Ch]
    push ax
    push word ptr [bp-0Ch]
    sub di,word ptr [bp+0Ch]
    push di
    mov word ptr [bp-0Eh],ax
    call mf98
    push si
    mov ax,word ptr [bp-0Eh]
    sub ax,word ptr [bp+0Ch]
    push ax
    mov cx,word ptr [bp-0Ch]
    add cx,word ptr [bp+0Ah]
    push cx
    push di
    mov word ptr [bp-10h],ax
    mov word ptr [bp-12h],cx
    call mf109
    mov word ptr [bp-14h],si
    mov word ptr [bp-16h],di
    cmp word ptr [bp+0Ch],0h
    jl short lbl12Af
    mov ax,0Fh
    jmp short lbl12Df
lbl12Af:
    mov ax,6h
lbl12Df:
    push ax
    call mf118
    add sp,2h
    push word ptr [bp-14h]
    mov ax,word ptr [bp-10h]
    sub ax,word ptr [bp+0Ch]
    push ax
    mov ax,word ptr [bp-12h]
    add ax,word ptr [bp+0Ah]
    push ax
    push word ptr [bp-16h]
    jmp near ptr lbl2B6f
    nop
lbl14Ef:
    cmp word ptr [bp+0Ah],0h
    jnz short lbl157f
    jmp near ptr lbl200f
lbl157f:
    sub word ptr [bp+8h],3h
    mov ax,0Fh
    push ax
    call mf136
    add sp,2h
    mov ax,word ptr [bp+0Ah]
    mov cx,ax
    add ax,ax
    add ax,cx
    add ax,ax
    add ax,ax
    add ax,word ptr [bp+6h]
    push ax
    push word ptr [bp+8h]
    mov cx,ax
    mov ax,1Eh
    imul word ptr [bp+0Eh]
    add ax, offset mi150
    imul word ptr [bp+0Ah]
    mov dx,cx
    add cx,ax
    push cx
    push word ptr [bp+8h]
    mov si,cx
    mov di,dx
    call mf158
    inc word ptr [bp+8h]
    mov ax,0Ah
    push ax
    call mf162
    add sp,2h
    push di
    push word ptr [bp+8h]
    push si
    push word ptr [bp+8h]
    call mf168
    inc word ptr [bp+8h]
    push di
    push word ptr [bp+8h]
    push si
    push word ptr [bp+8h]
    call mf174
    inc word ptr [bp+8h]
    push di
    push word ptr [bp+8h]
    push si
    push word ptr [bp+8h]
    call mf180
    inc word ptr [bp+8h]
    push di
    push word ptr [bp+8h]
    push si
    push word ptr [bp+8h]
    call mf186
    inc word ptr [bp+8h]
    mov ax,6h
    push ax
    call mf190
    add sp,2h
    push di
    push word ptr [bp+8h]
    push si
    push word ptr [bp+8h]
    jmp near ptr lbl2B6f
lbl200f:
    sub word ptr [bp+6h],3h
    mov ax,0Fh
    push ax
    call mf200
    add sp,2h
    push word ptr [bp+6h]
    mov ax,word ptr [bp+0Ch]
    mov cx,ax
    add ax,ax
    add ax,ax
    add ax,cx
    add ax,ax
    add ax,word ptr [bp+8h]
    push ax
    push word ptr [bp+6h]
    mov cx,ax
    mov ax,19h
    imul word ptr [bp+10h]
    add ax, offset mi215
    imul word ptr [bp+0Ch]
    mov dx,cx
    add cx,ax
    push cx
    mov si,cx
    mov di,dx
    call mf222
    inc word ptr [bp+6h]
    mov ax,0Ah
    push ax
    call mf226
    add sp,2h
    push word ptr [bp+6h]
    push di
    push word ptr [bp+6h]
    push si
    call mf232
    inc word ptr [bp+6h]
    push word ptr [bp+6h]
    push di
    push word ptr [bp+6h]
    push si
    call mf238
    inc word ptr [bp+6h]
    push word ptr [bp+6h]
    push di
    push word ptr [bp+6h]
    push si
    call mf244
    inc word ptr [bp+6h]
    push word ptr [bp+6h]
    push di
    push word ptr [bp+6h]
    push si
    call mf250
    inc word ptr [bp+6h]
    push word ptr [bp+6h]
    push di
    push word ptr [bp+6h]
    push si
    call mf256
    inc word ptr [bp+6h]
    mov ax,6h
    push ax
    call mf260
    add sp,2h
    push word ptr [bp+6h]
    push di
    push word ptr [bp+6h]
    push si
lbl2B6f:
    call mf266
    pop si
    pop di
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
