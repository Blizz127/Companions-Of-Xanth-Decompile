_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi4:NEAR
    EXTRN mi5:NEAR
    EXTRN mi28:NEAR
    EXTRN mi30:NEAR
    EXTRN mf38:FAR
    EXTRN mf45:FAR
    EXTRN mf51:FAR
    EXTRN mf67:FAR
    EXTRN mf77:FAR
    EXTRN mf84:FAR
    EXTRN mf90:FAR
    EXTRN mf106:FAR
    EXTRN mf113:FAR
    EXTRN mf121:FAR
    EXTRN mf130:FAR
    EXTRN mf138:FAR
    EXTRN mf144:FAR
    EXTRN mf153:FAR
    EXTRN mf158:FAR
    EXTRN mf164:FAR
    EXTRN mf173:FAR
    EXTRN mf183:FAR
    EXTRN mf191:FAR
    EXTRN mf197:FAR
    EXTRN mf198:FAR
    EXTRN mf206:FAR
    EXTRN mf217:FAR
    EXTRN mf220:FAR
    EXTRN mf221:FAR
    EXTRN mf226:FAR
    EXTRN mf226:FAR
    EXTRN mf226:FAR
    EXTRN mf226:FAR
    EXTRN mf226:FAR
    EXTRN mf226:FAR
    EXTRN mf226:FAR
    EXTRN mf226:FAR
    EXTRN mf226:FAR
    EXTRN mf226:FAR
    EXTRN mf226:FAR
    EXTRN mf226:FAR
    EXTRN mf226:FAR
    EXTRN mf226:FAR
    EXTRN mf226:FAR
    EXTRN mf226:FAR
    EXTRN mf226:FAR
    EXTRN mf226:FAR
    EXTRN mf226:FAR
    EXTRN mf226:FAR
    EXTRN mf226:FAR
    EXTRN mf226:FAR
    EXTRN mf226:FAR
    EXTRN mf226:FAR
    EXTRN mf226:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,4h
    mov ax,word ptr [bp+6h]
    sub ax, offset mi4
    cmp ax, offset mi5
    jna short lbl14f
    jmp near ptr lbl243f
lbl14f:
    add ax,ax
    xchg ax,bx
    jmp word ptr cs:[bx+0E6h]
    push cs
    add word ptr [di],cx
    add si,word ptr [si]
    add word ptr [si-6BFFh],dx
    add word ptr [si+0D01h],dx
    add cx,word ptr [bp+si]
    add cl,byte ptr [di]
    add dx,word ptr [si+2h]
    or ax,0D03h
    add cx,word ptr [di]
    add cx,word ptr [di]
    add cx,word ptr [di]
    add cx,word ptr [di]
    add cx,word ptr [bp+si-17FEh]
    add bh,dh
    add cl,byte ptr [bp+si]
    add ah,byte ptr [bx+di+6A06h]
    sub ax, offset mi28
    jz short lbl54f
    sub ax, offset mi30
    jz short lbl54f
    jmp near ptr lbl243f
lbl54f:
    xor ax,ax
    push ax
    mov ax,9Fh
    push ax
    push word ptr ds:[6A06h]
    call mf38
    add sp,6h
    jmp near ptr lbl245f
    mov ax,0Ah
    push ax
    mov ax,9Dh
    push ax
    call mf45
    add sp,4h
    mov ax,0Eh
    push ax
    mov ax,0A3h
    push ax
    call mf51
    add sp,4h
    or ax,ax
    jz short lbl96f
    mov ax,2921h
    mov dx,ds
    jmp short lbl99f
    nop
lbl96f:
    xor ax,ax
    cwd
lbl99f:
    mov word ptr [bp-4h],ax
    mov word ptr [bp-2h],dx
    mov ax,0A3h
    push ax
    mov ax,1h
    push ax
    call mf67
    add sp,4h
    push dx
    push ax
    push word ptr [bp-2h]
    push word ptr [bp-4h]
    mov ax,4h
    mov dx,0F010h
    push dx
    push ax
    call mf77
    add sp,0Ch
    jmp near ptr lbl243f
    xor ax,ax
    mov dx,0F010h
    push dx
    push ax
    call mf84
    add sp,4h
    mov ax,0Eh
    push ax
    mov ax,9Fh
    push ax
    call mf90
    add sp,4h
    or ax,ax
    jnz short lbl112f
    cmp byte ptr ds:[314h],0h
    jz short lblFAf
    mov ax,290Fh
    jmp short lblFDf
    nop
lblFAf:
    mov ax,2917h
lblFDf:
    push ds
    push ax
    mov ax,1h
    mov dx,0F010h
    push dx
    push ax
    call mf106
    add sp,8h
    jmp near ptr lbl243f
lbl112f:
    mov ax,0Eh
    push ax
    mov ax,9Eh
    push ax
    call mf113
    add sp,4h
    or ax,ax
    jnz short lbl13Af
    mov ax,2h
lbl129b:
    mov dx,0F010h
    push dx
    push ax
    call mf121
lbl133b:
    add sp,4h
    jmp near ptr lbl243f
    nop
lbl13Af:
    mov ax,3h
    jmp short lbl129b
    nop
    mov ax,0Eh
    push ax
    call mf130
    add sp,2h
    or ax,ax
    jz short lbl170f
    mov ax,1h
    push ax
    mov ax,0A7h
    push ax
    call mf138
    add sp,4h
    or ax,ax
    jz short lbl170f
    mov ax,0Eh
    push ax
    call mf144
    add sp,2h
lbl170f:
    cmp byte ptr ds:[313h],0h
    jz short lbl17Af
    jmp near ptr lbl243f
lbl17Af:
    mov ax,0Fh
    push ax
    mov ax,0Bh
    push ax
    call mf153
    jmp short lbl133b
    nop
    mov ax,0Bh
    push ax
    call mf158
    add sp,2h
    mov ax,1h
    push ax
    mov ax,0A7h
    push ax
    call mf164
    add sp,4h
    or ax,ax
    jnz short lbl1ADf
    jmp near ptr lbl234f
lbl1ADf:
    mov ax,1h
    push ax
    mov ax,0Eh
    push ax
    call mf173
    add sp,4h
    jmp short lbl234f
    nop
    mov ax,6h
    push ax
    mov ax,0h
    mov cx,3344h
    push cx
    push ax
    call mf183
    add sp,6h
    cmp byte ptr ds:[290Eh],0h
    jnz short lbl219f
    mov ax,0Eh
    push ax
    mov ax,9Fh
    push ax
    call mf191
    add sp,4h
    or ax,ax
    jnz short lbl219f
    cmp byte ptr ds:[314h],0h
    jnz short lbl219f
    call mf197
    call mf198
    xor ax,ax
    push ax
    push ax
    mov ax,7h
    push ax
    mov ax,607h
    push ax
    call mf206
    add sp,8h
    mov byte ptr ds:[290Eh],1h
lbl219f:
    mov ax,1h
    jmp short lbl245f
    mov ax,0Bh
    push ax
    mov ax,48h
    mov cx,3344h
    push cx
    push ax
    call mf217
    add sp,6h
    jmp short lbl243f
lbl234f:
    call mf220
    call mf221
    mov byte ptr ds:[290Eh],0h
lbl243f:
    xor ax,ax
lbl245f:
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
