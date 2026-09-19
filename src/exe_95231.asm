_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi15:NEAR
    EXTRN mf87:FAR
    EXTRN mf14e:FAR
    EXTRN mff6:FAR
    EXTRN mf117:FAR
    EXTRN mf67:FAR
    EXTRN mf197:FAR
    EXTRN mf16f:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,18h
    push si
    sub ax,ax
    mov word ptr [bp-2h],ax
    mov word ptr [bp-4h],ax
    mov ax,word ptr [bp+6h]
    mov dx,word ptr [bp+8h]
    add ax, offset mi15
    adc dx,0h
    and al,0F0h
    and dx,0Fh
    mov word ptr [bp+6h],ax
    mov word ptr [bp+8h],dx
    or dx,ax
    jnz short lbl2Df
    jmp near ptr lbl1A7f
lbl2Db:
lbl2Df:
    cmp word ptr [bp+0Ah],0h
    jz short lbl36f
    jmp near ptr lblCCf
lbl36f:
    mov ax,word ptr ds:[4DAEh]
    mov word ptr [bp-0Eh],ax
    or ax,ax
    jg short lbl43f
    jmp near ptr lbl15Cf
lbl43f:
    mov cx,ax
    add ax,ax
    add ax,cx
    add ax,ax
    add ax,ax
    mov word ptr [bp-16h],ax
lbl50b:
    les bx, dword ptr ds:[63DCh]
    add bx,word ptr [bp-16h]
    push word ptr es:[bx-4h]
    push word ptr es:[bx-6h]
    push word ptr es:[bx-0Ah]
    push word ptr es:[bx-0Ch]
    call mf67
    add sp,8h
    mov word ptr [bp-8h],ax
    mov word ptr [bp-6h],dx
    sub ax,ax
    push ax
    push ax
    les bx, dword ptr ds:[63DCh]
    mov si,word ptr [bp-16h]
    push word ptr es:[bx+si+2h]
    push word ptr es:[bx+si]
    call mf87
    add sp,8h
    mov word ptr [bp-0Ch],ax
    mov word ptr [bp-0Ah],dx
    sub ax,word ptr [bp-8h]
    sbb dx,word ptr [bp-6h]
    cmp dx,word ptr [bp+8h]
    jg short lblB4f
    jl short lblA7f
    cmp ax,word ptr [bp+6h]
    jnc short lblB4f
lblA7f:
    sub word ptr [bp-16h],0Ch
    cmp word ptr [bp-16h],0h
    jg short lbl50b
    jmp near ptr lbl15Cf
lblB4f:
    push word ptr [bp+8h]
    push word ptr [bp+6h]
    mov ax,word ptr [bp-0Ch]
    mov dx,word ptr [bp-0Ah]
    sub ax,word ptr [bp+6h]
    sbb dx,word ptr [bp+8h]
    push dx
    push ax
    jmp near ptr lbl14Ef
    nop
lblCCf:
    mov word ptr [bp-0Eh],0h
    cmp word ptr ds:[4DAEh],0h
    jg short lblDBf
    jmp near ptr lbl15Cf
lblDBf:
    mov word ptr [bp-18h],0h
lblE0b:
    les bx, dword ptr ds:[63DCh]
    add bx,word ptr [bp-18h]
    push word ptr es:[bx+8h]
    push word ptr es:[bx+6h]
    push word ptr es:[bx+2h]
    push word ptr es:[bx]
    call mff6
    add sp,8h
    mov word ptr [bp-8h],ax
    mov word ptr [bp-6h],dx
    sub ax,ax
    push ax
    push ax
    les bx, dword ptr ds:[63DCh]
    mov si,word ptr [bp-18h]
    push word ptr es:[bx+si+0Eh]
    push word ptr es:[bx+si+0Ch]
    call mf117
    add sp,8h
    sub ax,word ptr [bp-8h]
    sbb dx,word ptr [bp-6h]
    cmp dx,word ptr [bp+8h]
    jg short lbl142f
    jl short lbl131f
    cmp ax,word ptr [bp+6h]
    jnc short lbl142f
lbl131f:
    add word ptr [bp-18h],0Ch
    mov ax,word ptr ds:[4DAEh]
    inc word ptr [bp-0Eh]
    cmp word ptr [bp-0Eh],ax
    jl short lblE0b
    jmp short lbl15Cf
lbl142f:
    push word ptr [bp+8h]
    push word ptr [bp+6h]
    push word ptr [bp-6h]
    push word ptr [bp-8h]
lbl14Ef:
    call mf14e
    add sp,8h
    mov word ptr [bp-4h],ax
    mov word ptr [bp-2h],dx
lbl15Cf:
    mov ax,word ptr [bp-2h]
    or ax,word ptr [bp-4h]
    jnz short lbl1A7f
    lea ax,word ptr [bp-14h]
    push ss
    push ax
    push word ptr [bp+8h]
    push word ptr [bp+6h]
    call mf16f
    add sp,8h
    mov word ptr [bp-12h],ax
    mov word ptr [bp-10h],dx
    or dx,ax
    jz short lbl1A7f
    push word ptr [bp-10h]
    push ax
    mov bx,word ptr [bp-14h]
    add bx,bx
    add bx,bx
    db 0FFh, 9Fh, 0E8h, 63h ; override
    add sp,4h
    or ax,ax
    jz short lbl1A7f
    call mf197
    mov ax,word ptr [bp+8h]
    or ax,word ptr [bp+6h]
    jz short lbl1A7f
    jmp near ptr lbl2Db
lbl1A7f:
    mov ax,word ptr [bp-4h]
    mov dx,word ptr [bp-2h]
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
