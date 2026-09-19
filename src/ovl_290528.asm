_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi6:NEAR
    EXTRN mf1e7:FAR
    EXTRN mf60:FAR
    EXTRN mf2fb:FAR
    EXTRN mf19d:FAR
    EXTRN mf9f:FAR
    EXTRN mf112:FAR
    EXTRN mf46:FAR
    EXTRN mf81:FAR
    EXTRN mi9:NEAR
    EXTRN mf1d4:FAR
    EXTRN mf2b6:FAR
    EXTRN mf2c2:FAR
    EXTRN mf2d7:FAR
    EXTRN mf204:FAR
    EXTRN mf158:FAR
    EXTRN mf148:FAR
    EXTRN mf242:FAR
    EXTRN mf22a:FAR
    EXTRN mf273:FAR
    EXTRN mfcc:FAR
    EXTRN mf1c4:FAR
    EXTRN mf1ef:FAR
    EXTRN mf293:FAR
    EXTRN mf175:FAR
    EXTRN mf280:FAR
    EXTRN mfbd:FAR
    EXTRN mf72:FAR
    EXTRN mf190:FAR
    EXTRN mf232:FAR
    EXTRN mf2a6:FAR
    EXTRN mf2e7:FAR
    EXTRN mf310:FAR
    EXTRN mf2ca:FAR
    EXTRN mf169:FAR
    EXTRN mf1a2:FAR
    EXTRN mf267:FAR
    EXTRN mfe2:FAR
    EXTRN mfff:FAR
    EXTRN mf21a:FAR
    EXTRN mf134:FAR
mnem_unit:
    push bp
    mov bp,sp
    mov ax,word ptr [bp+6h]
    sub ax, offset mi6
    cmp ax, offset mi9
    jna short lbl11f
    jmp near ptr lbl315f
lbl11f:
    add ax,ax
    xchg ax,bx
    jmp word ptr cs:[bx+0DAh]
    nop
    db 0FEh, 00h, 0D5h, 03h, 2Ah, 01h, 0CAh, 01h, 0CAh, 01h, 0CAh, 01h, 0D5h, 03h, 0D5h, 03h
    db 0ECh, 01h, 0D5h, 03h, 0D5h, 03h, 0D5h, 03h, 0D5h, 03h, 0D5h, 03h, 0D5h, 03h, 0D5h, 03h
    db 6Ah, 02h, 0C4h, 03h
    mov ax,0Eh
    push ax
    mov ax,187h
    push ax
    call mf46
    mov sp,bp
    or ax,ax
    jz short lbl54f
    jmp near ptr lbl315f
lbl54f:
    push word ptr ds:[6A02h]
    mov ax,187h
    push ax
    push word ptr ds:[6A06h]
    call mf60
lbl65b:
    mov sp,bp
    jmp near ptr lbl317f
    mov ax,0Ah
    push ax
    mov ax,184h
    push ax
    call mf72
    mov sp,bp
    mov ax,0Eh
    push ax
    mov ax,18Ch
    push ax
    call mf81
    mov sp,bp
    or ax,ax
    jz short lbl92f
    mov ax,380Fh
    jmp short lbl95f
    nop
lbl92f:
    mov ax,3817h
lbl95f:
    push ds
    push ax
    mov ax,0Eh
    push ax
    mov ax,187h
    push ax
    call mf9f
    add sp,4h
    or ax,ax
    jz short lblB0f
    mov ax,381Eh
    jmp short lblB3f
lblB0f:
    mov ax,3825h
lblB3f:
    push ds
    push ax
    mov ax,4h
    mov dx,0F045h
    push dx
    push ax
    call mfbd
    mov sp,bp
    mov ax,184h
    push ax
    mov ax,189h
    push ax
    call mfcc
    mov sp,bp
    or ax,ax
    jnz short lblDAf
    jmp near ptr lbl315f
lblDAf:
    mov ax,0Eh
    push ax
    mov ax,187h
    push ax
    call mfe2
    mov sp,bp
    or ax,ax
    jz short lblF2f
    mov ax,382Dh
    jmp short lblF5f
lblF2f:
    mov ax,3833h
lblF5f:
    push ds
    push ax
    mov ax,5h
lblFAb:
    mov dx,0F045h
    push dx
    push ax
    call mfff
    mov sp,bp
    jmp near ptr lbl315f
    nop
    mov ax,0Eh
    push ax
    mov ax,187h
    push ax
    call mf112
    mov sp,bp
    or ax,ax
    jz short lbl122f
    mov ax,3800h
    jmp short lbl125f
lbl122f:
    mov ax,3807h
lbl125f:
    push ds
    push ax
    mov ax,3h
    jmp short lblFAb
    mov ax,0Ah
    push ax
    mov ax,184h
    push ax
    call mf134
    add sp,4h
    or ax,ax
    jnz short lbl17Df
    mov ax,0Ah
    push ax
    mov ax,184h
    push ax
    call mf148
    add sp,4h
    mov ax,2h
    mov dx,0F045h
    push dx
    push ax
    call mf158
    add sp,4h
    mov ax,1h
    push ax
    push ax
    mov ax,0Fh
    push ax
    call mf169
    add sp,6h
    mov ax,1770h
    push ax
    call mf175
    add sp,2h
lbl17Df:
    cmp word ptr ds:[6A22h],180h
    jz short lbl188f
    jmp near ptr lbl315f
lbl188f:
    mov ax,5A01h
    push ax
    mov ax,2C1h
    push ax
    call mf190
    add sp,4h
    mov byte ptr ds:[364h],1h
    call mf19d
    call mf1a2
    jmp near ptr lbl315f
    cmp byte ptr ds:[364h],0h
    jz short lbl1F4f
    mov byte ptr ds:[364h],0h
    cmp word ptr ds:[56h],1h
    jz short lbl1F4f
    cmp word ptr ds:[58h],0h
    jnz short lbl1F4f
    call mf1c4
    xor al,al
    push ax
    mov ax,1Ch
    push ax
    mov cx,1105h
    push cx
    call mf1d4
    add sp,6h
    mov al,1h
    push ax
    mov ax,1Ch
    push ax
    mov ax,1105h
    push ax
    call mf1e7
    add sp,6h
    call mf1ef
lbl1F4f:
    cmp byte ptr ds:[365h],0h
    jz short lbl24Af
    mov byte ptr ds:[365h],0h
    mov ax,0Bh
    push ax
    call mf204
    add sp,2h
    cmp word ptr ds:[56h],1h
    jz short lbl237f
    cmp word ptr ds:[58h],0h
    jnz short lbl237f
    call mf21a
    xor al,al
    push ax
    mov ax,0Ch
    push ax
    mov ax,1121h
    push ax
    call mf22a
    add sp,6h
    call mf232
lbl237f:
    xor ax,ax
    push ax
    mov ax,184h
    push ax
    mov ax,189h
    push ax
    call mf242
    add sp,6h
lbl24Af:
    cmp byte ptr ds:[366h],0h
    jnz short lbl254f
    jmp near ptr lbl2EFf
lbl254f:
    mov byte ptr ds:[366h],0h
    cmp word ptr ds:[56h],1h
    jz short lbl2CFf
    cmp word ptr ds:[58h],0h
    jnz short lbl2CFf
    call mf267
    xor ax,ax
    mov dx,0F045h
    push dx
    push ax
    call mf273
    add sp,4h
    mov ax,37F4h
    push ds
    push ax
    call mf280
    add sp,4h
    xor al,al
    push ax
    mov cx,8h
    push cx
    mov cx,112Dh
    push cx
    call mf293
    add sp,6h
    xor al,al
    push ax
    mov ax,0Ch
    push ax
    mov ax,1135h
    push ax
    call mf2a6
    add sp,6h
    mov ax,1h
    mov dx,0F045h
    push dx
    push ax
    call mf2b6
    add sp,4h
    mov ax,0BB8h
    push ax
    call mf2c2
    add sp,2h
    call mf2ca
lbl2CFf:
    mov ax,0Eh
    push ax
    mov cx,187h
    push cx
    call mf2d7
    add sp,4h
    mov ax,0Eh
    push ax
    mov ax,18Ch
    push ax
    call mf2e7
    add sp,4h
lbl2EFf:
    mov ax,4h
    push ax
    mov ax,0h
    mov cx,32A8h
    push cx
    push ax
    call mf2fb
    jmp near ptr lbl65b
    nop
    mov ax,9h
    push ax
    mov ax,30h
    mov cx,32A8h
    push cx
    push ax
    call mf310
lbl315f:
    xor ax,ax
lbl317f:
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
