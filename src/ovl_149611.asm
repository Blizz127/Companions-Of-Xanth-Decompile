_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi6:NEAR
    EXTRN mf2f9:FAR
    EXTRN mf20a:FAR
    EXTRN mf196:FAR
    EXTRN mf212:FAR
    EXTRN mf8d:FAR
    EXTRN mf64:FAR
    EXTRN mf164:FAR
    EXTRN mf1aa:FAR
    EXTRN mf30c:FAR
    EXTRN mf186:FAR
    EXTRN mfde:FAR
    EXTRN mf2d4:FAR
    EXTRN mf133:FAR
    EXTRN mf154:FAR
    EXTRN mf2a7:FAR
    EXTRN mi9:NEAR
    EXTRN mf42:FAR
    EXTRN mf241:FAR
    EXTRN mf266:FAR
    EXTRN mf2e9:FAR
    EXTRN mf19e:FAR
    EXTRN mf306:FAR
    EXTRN mf338:FAR
    EXTRN mfcc:FAR
    EXTRN mff0:FAR
    EXTRN mf320:FAR
    EXTRN mf2a1:FAR
    EXTRN mf299:FAR
    EXTRN mf2c4:FAR
    EXTRN mf1ce:FAR
    EXTRN mf1bd:FAR
    EXTRN mf259:FAR
    EXTRN mf51:FAR
    EXTRN mf2dc:FAR
    EXTRN mf1da:FAR
    EXTRN mf279:FAR
    EXTRN mf111:FAR
    EXTRN mf16c:FAR
    EXTRN mf224:FAR
    EXTRN mfba:FAR
    EXTRN mf1f6:FAR
    EXTRN mf102:FAR
    EXTRN mf251:FAR
    EXTRN mf217:FAR
    EXTRN mfa3:FAR
mnem_unit:
    push bp
    mov bp,sp
    mov ax,word ptr [bp+6h]
    sub ax, offset mi6
    cmp ax, offset mi9
    jna short lbl11f
    jmp near ptr lbl33Df
lbl11f:
    add ax,ax
    xchg ax,bx
    jmp word ptr cs:[bx+545h]
    nop
    db 65h, 05h, 87h, 05h, 87h, 05h, 87h, 05h, 68h, 08h, 0ADh, 05h, 35h, 06h, 68h, 08h
    db 68h, 08h, 68h, 08h, 68h, 08h, 68h, 08h, 68h, 08h, 68h, 08h, 67h, 06h, 57h, 08h
    mov ax,0Ah
    push ax
    mov ax,0BEh
    push ax
    call mf42
    mov sp,bp
    mov ax,3h
lbl4Cb:
    mov dx,0F019h
    push dx
    push ax
    call mf51
    mov sp,bp
    jmp near ptr lbl33Df
    nop
    mov ax,0BEh
    push ax
    mov ax,0BFh
    push ax
    call mf64
    mov sp,bp
    or ax,ax
    jz short lbl78f
    mov ax,2h
    mov dx,0F019h
    jmp short lbl7Bf
    nop
lbl78f:
    xor ax,ax
    cwd
lbl7Bf:
    push dx
    push ax
    mov ax,1h
    jmp short lbl4Cb
    mov ax,6h
    mov word ptr ds:[2ACh],ax
    push ax
    mov ax,0Fh
    push ax
    call mf8d
    mov sp,bp
    cmp byte ptr ds:[367h],0h
    jnz short lblAFf
    mov ax,2h
    push ax
    mov ax,10h
    push ax
    call mfa3
    mov sp,bp
    mov byte ptr ds:[367h],1h
lblAFf:
    xor ax,ax
    push ax
    mov cx,7h
    push cx
    mov cx,8026h
    push cx
    call mfba
    mov sp,bp
    xor ax,ax
    push ax
    mov cx,8h
    push cx
    mov cx,8026h
    push cx
    call mfcc
    mov sp,bp
    xor ax,ax
    push ax
    mov cx,9h
    push cx
    mov cx,8026h
    push cx
    call mfde
    mov sp,bp
    xor ax,ax
    push ax
    mov cx,0Ah
    push cx
    mov cx,8026h
    push cx
    call mff0
    mov sp,bp
    xor ax,ax
    push ax
    mov ax,0Bh
    push ax
    mov ax,8026h
    push ax
    call mf102
    jmp near ptr lbl33Df
    xor ax,ax
    mov dx,0F019h
    push dx
    push ax
    call mf111
    add sp,4h
    cmp byte ptr ds:[374h],0h
    jz short lbl123f
    jmp near ptr lbl33Df
lbl123f:
    mov byte ptr ds:[374h],1h
    xor ax,ax
    push ax
    mov ax,1h
    push ax
    mov ax,5h
    push ax
    call mf133
    jmp near ptr lbl33Df
    nop
    cmp byte ptr ds:[319h],0h
    jnz short lbl146f
    jmp near ptr lbl22Cf
lbl146f:
    cmp word ptr ds:[58h],0h
    jnz short lbl171f
    cmp word ptr ds:[56h],1h
    jz short lbl171f
    call mf154
    xor al,al
    push ax
    push word ptr ds:[2ACh]
    mov ax,703h
    push ax
    call mf164
    add sp,6h
    call mf16c
lbl171f:
    cmp word ptr ds:[2ACh],15h
    jnl short lbl1A6f
    cmp word ptr ds:[58h],0h
    jnz short lbl1E2f
    cmp word ptr ds:[56h],1h
    jz short lbl1E2f
    call mf186
    mov al,1h
    push ax
    push word ptr ds:[2ACh]
    mov ax,703h
    push ax
    call mf196
    add sp,6h
    call mf19e
    jmp short lbl1E2f
    nop
lbl1A6f:
    mov ax,0Fh
    push ax
    call mf1aa
    add sp,2h
    xor ax,ax
    push ax
    mov ax,0BEh
    push ax
    mov ax,0BFh
    push ax
    call mf1bd
    add sp,6h
    mov ax,1h
    push ax
    push ax
    mov ax,0Ah
    push ax
    call mf1ce
    add sp,6h
    mov ax,0BB8h
    push ax
    call mf1da
    add sp,2h
lbl1E2f:
    mov byte ptr ds:[319h],0h
    cmp byte ptr ds:[31Bh],0h
    jz short lbl22Cf
    mov ax,0Ah
    push ax
    mov ax,0BFh
    push ax
    call mf1f6
    add sp,4h
    or ax,ax
    jnz short lbl22Cf
    mov ax,0Ah
    push ax
    mov ax,0BFh
    push ax
    call mf20a
    add sp,4h
    call mf212
    call mf217
    mov ax,5A03h
    push ax
    mov ax,11Fh
    push ax
    call mf224
    add sp,4h
lbl22Cf:
    cmp byte ptr ds:[2A2Eh],0h
    jz short lbl2AFf
    cmp word ptr ds:[58h],0h
    jnz short lbl25Ef
    cmp word ptr ds:[56h],1h
    jz short lbl25Ef
    call mf241
    xor al,al
    push ax
    mov ax,2h
    push ax
    mov ax,718h
    push ax
    call mf251
    add sp,6h
    call mf259
lbl25Ef:
    mov ax,0Eh
    push ax
    mov ax,0BFh
    push ax
    call mf266
    add sp,4h
    xor ax,ax
    push ax
    mov ax,0BEh
    push ax
    mov ax,0C4h
    push ax
    call mf279
    add sp,6h
    mov byte ptr ds:[2A2Eh],0h
    cmp byte ptr ds:[31Ch],0h
    jnz short lbl2A1f
    mov ax,1h
    push ax
    mov ax,10h
    push ax
    mov ax,8026h
    push ax
    call mf299
    add sp,6h
lbl2A1f:
    call mf2a1
    push ax
    call mf2a7
    add sp,2h
lbl2AFf:
    cmp byte ptr ds:[2A2Fh],0h
    jz short lbl314f
    cmp word ptr ds:[58h],0h
    jnz short lbl2E1f
    cmp word ptr ds:[56h],1h
    jz short lbl2E1f
    call mf2c4
    mov al,1h
    push ax
    mov ax,2h
    push ax
    mov ax,718h
    push ax
    call mf2d4
    add sp,6h
    call mf2dc
lbl2E1f:
    mov ax,0Eh
    push ax
    mov ax,0BFh
    push ax
    call mf2e9
    add sp,4h
    xor ax,ax
    push ax
    push ax
    mov ax,0C4h
    push ax
    call mf2f9
    add sp,6h
    mov byte ptr ds:[2A2Fh],0h
    call mf306
    push ax
    call mf30c
    add sp,2h
lbl314f:
    mov ax,2h
    push ax
    mov ax,0h
    mov cx,3300h
    push cx
    push ax
    call mf320
    add sp,6h
    jmp short lbl33Ff
    nop
    nop
    mov ax,3h
    push ax
    mov ax,18h
    mov cx,3300h
    push cx
    push ax
    call mf338
lbl33Df:
    xor ax,ax
lbl33Ff:
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
