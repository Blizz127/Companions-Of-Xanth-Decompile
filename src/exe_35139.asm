_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf298:FAR
    EXTRN mf201:FAR
    EXTRN mf414:FAR
    EXTRN mi197:NEAR
    EXTRN mf2c8:FAR
    EXTRN mibe:NEAR
    EXTRN mi6e:NEAR
    EXTRN mf186:FAR
    EXTRN mf144:FAR
    EXTRN mf317:FAR
    EXTRN mi2f8:NEAR
    EXTRN mf179:FAR
    EXTRN mf223:FAR
    EXTRN mf1d4:FAR
    EXTRN mf3f6:FAR
    EXTRN mf27a:FAR
    EXTRN mf38a:FAR
    EXTRN mf2b2:FAR
    EXTRN mi2f3:NEAR
    EXTRN mf372:FAR
    EXTRN mf231:FAR
    EXTRN mf28a:FAR
    EXTRN mf23b:FAR
    EXTRN mf44d:FAR
    EXTRN mf2ba:FAR
    EXTRN mf1c4:FAR
    EXTRN mffe:FAR
    EXTRN mf285:FAR
    EXTRN mf32b:FAR
    EXTRN mf3cb:FAR
    EXTRN mi14c:NEAR
    EXTRN mf3da:FAR
    EXTRN mf159:FAR
    EXTRN mi2fd:NEAR
    EXTRN mf381:FAR
    EXTRN mf3b3:FAR
    EXTRN mf33b:FAR
    EXTRN mf3e8:FAR
    EXTRN mi2eb:NEAR
    EXTRN mf343:FAR
    EXTRN mf406:FAR
    EXTRN mf363:FAR
    EXTRN mf15:FAR
    EXTRN mf13c:FAR
    EXTRN mf1f5:FAR
    EXTRN mnb2:NEAR
    EXTRN mi2da:NEAR
    EXTRN mf30f:FAR
    EXTRN mf31f:FAR
    EXTRN mf1b2:FAR
    EXTRN mf34b:FAR
    EXTRN mf16b:FAR
    EXTRN mf1e1:FAR
    EXTRN mf1dc:FAR
    EXTRN mi69:NEAR
    EXTRN mf445:FAR
    EXTRN mf217:FAR
    EXTRN mf28f:FAR
    EXTRN mf255:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,2h
    push ds
    push es
    push si
    push di
    mov ax,38AFh
    mov ds,ax
    mov ax,word ptr [bp+8h]
    mov bx,word ptr [bp+0Ah]
    call mf15
    mov al,byte ptr [bp+6h]
    mov si,52A6h
    mov dx,word ptr [si+16h]
    cmp dl,0h
    jz short lbl41f
    cmp dl,3h
    jz short lbl3Cf
    cmp dl,1h
    jz short lbl37f
    or byte ptr es:[bx],al
    jmp short lbl44f
lbl37f:
    and byte ptr es:[bx],al
    jmp short lbl44f
lbl3Cf:
    xor byte ptr es:[bx],al
    jmp short lbl44f
lbl41f:
    mov byte ptr es:[bx],al
lbl44f:
    mov word ptr [bp-2h],0h
    mov ax,word ptr [bp-2h]
    pop di
    pop si
    pop es
    pop ds
    mov sp,bp
    pop bp
    retf 6h
    add byte ptr [di-75h],dl
    in al,dx
    sub sp,2h
    push ds
    push es
    push si
    push di
    mov ax,38AFh
    mov ds,ax
    mov ax,word ptr [bp+6h]
    cmp ax, offset mi69
    jc short lbl73f
    cmp ax, offset mi6e
    jna short lbl7Bf
lbl73f:
    mov word ptr [bp-2h],0FFFAh
    stc
    jmp short lbl8Df
lbl7Bf:
    mov si,5365h
    mov dx,10h
    mul dx
    add si,ax
    mov ax,si
    mov dx,ds
    mov word ptr [bp-2h],ax
    clc
lbl8Df:
    mov ax,word ptr [bp-2h]
    pop di
    pop si
    pop es
    pop ds
    mov sp,bp
    pop bp
    retf 2h
    add byte ptr [di-75h],dl
    in al,dx
    sub sp,2h
    push ds
    push es
    push si
    push di
    mov ax,38AFh
    mov ds,ax
    cmp byte ptr ds:[52FEh],1h
    jz short lblB5f
    push cs
    call mnb2
lblB5f:
    mov si,52A6h
    mov si,537Ah
    mov ax,word ptr ds:[5242h]
    cmp ax, offset mibe
    jna short lblCAf
    mov word ptr [bp-2h],0FFFAh
    jmp short lblDBf
lblCAf:
    shl ax,1
    shl ax,1
    add si,ax
    mov bx,word ptr [bp+8h]
    mov ax,word ptr [bp+6h]
    db 0FFh, 1Ch ; override
    mov word ptr [bp-2h],ax
lblDBf:
    mov ax,word ptr [bp-2h]
    pop di
    pop si
    pop es
    pop ds
    mov sp,bp
    pop bp
    retf 4h
    mov bx,537Ah
    mov word ptr [bx],70h
    mov word ptr [bx+2h],89Dh
    add bx,4h
    mov byte ptr ds:[52FEh],1h
    retf
    push es
    call mffe
    mov word ptr ds:[5376h],bx
    mov word ptr ds:[5378h],es
    mov al,byte ptr es:[bx]
    xor ah,ah
    pop es
    retf
    add byte ptr [bx+si],al
    add byte ptr [bx+si],al
    add byte ptr [bx+si],al
    add byte ptr [bx+si],al
    add byte ptr [bx+si],al
    db 00h, 0CBh ; override
    xor byte ptr [bx+si],al
    add byte ptr [bx+si],al
    add byte ptr [bx+si],al
    add byte ptr [bx+si],al
    add byte ptr [bx+si],al
    add byte ptr [bx+si],al
    add byte ptr [bx+si],al
    add byte ptr [di-75h],dl
    in al,dx
    sub sp,6h
    push word ptr [bp+0Ah]
    push word ptr [bp+8h]
    push word ptr [bp+6h]
    call mf13c
    add sp,6h
    call mf144
    mov word ptr ds:[69E0h],ax
    cmp ax, offset mi14c
    ja short lbl163f
    mov ax,12h
    mov cx,3420h
    push cx
    push ax
    call mf159
    add sp,4h
    jmp short lbl179f
lbl163f:
    mov ax,0h
    mov cx,2197h
    push cx
    push ax
    call mf16b
    add sp,4h
    mov word ptr ds:[69E0h],0h
lbl179f:
    call mf179
    mov ax,0h
    mov cx,3420h
    push cx
    push ax
    call mf186
    add sp,4h
    mov word ptr [bp-4h],ax
    mov word ptr ds:[100h],0h
    cmp ax, offset mi197
    jg short lbl19Ff
    jmp near ptr lbl285f
lbl19Ff:
    cmp word ptr ds:[69E0h],0h
    jz short lbl1BAf
    push word ptr ds:[69E0h]
    mov ax,12h
    mov cx,3420h
    push cx
    push ax
    call mf1b2
    add sp,6h
lbl1BAf:
    cmp word ptr [bp-4h],3h
    jz short lbl1CCf
    mov ax,0FFFFh
    push ax
    call mf1c4
    add sp,2h
lbl1CCf:
    mov ax,20h
    mov cx,2199h
    push cx
    push ax
    call mf1d4
    add sp,4h
    call mf1dc
    call mf1e1
    cmp word ptr [bp-4h],2h
    jnz short lbl1F1f
    mov ax,10h
    jmp short lbl1F4f
lbl1F1f:
    mov ax,20h
lbl1F4f:
    push ax
    call mf1f5
    add sp,2h
    mov ax,1h
    push ax
    call mf201
    add sp,2h
    cmp word ptr [bp-4h],2h
    jnz short lbl22Bf
    mov ax,0Ah
    push ax
    push word ptr ds:[256h]
    call mf217
    add sp,4h
    mov ax,0Bh
    push ax
    call mf223
    add sp,2h
lbl22Bf:
    cmp word ptr [bp-4h],3h
    jnz short lbl243f
    call mf231
    mov ax,44h
    push ds
    push ax
    call mf23b
    add sp,4h
lbl243f:
    cmp word ptr ds:[69F0h],0h
    jnz short lbl25Ff
    cmp word ptr ds:[69EEh],0h
    jnz short lbl25Ff
    push word ptr ds:[256h]
    call mf255
    add sp,2h
    jmp short lbl28Af
lbl25Ff:
    cmp word ptr ds:[69F0h],0h
    jz short lbl26Bf
    mov ax,word ptr ds:[69F0h]
    jmp short lbl26Ef
lbl26Bf:
    mov ax,word ptr ds:[69EEh]
lbl26Ef:
    mov word ptr [bp-6h],ax
    push word ptr ds:[69ECh]
    push word ptr ds:[69EAh]
    push ax
    call mf27a
    add sp,6h
    jmp short lbl28Af
    nop
lbl285f:
    call mf285
lbl28Af:
    call mf28a
    call mf28f
lbl294b:
    mov ax,1h
    push ax
    call mf298
    add sp,2h
    cmp word ptr ds:[42h],0h
    jnz short lbl2BAf
    cmp word ptr ds:[56h],1h
    jz short lbl2BAf
    mov ax,1h
    push ax
    call mf2b2
    add sp,2h
lbl2BAf:
    call mf2ba
    mov ax,69E2h
    push ds
    push ax
    mov ax,3FFh
    push ax
    call mf2c8
    add sp,6h
    mov word ptr [bp-2h],ax
    or ax,ax
    jz short lbl294b
    mov ax,word ptr ds:[69E2h]
    cmp ax, offset mi2da
    jz short lbl327f
    jg short lbl2F3f
    dec ax
    jz short lbl30Ff
    dec ax
    jz short lbl317f
    dec ax
    dec ax
    jz short lbl31Ff
    sub ax, offset mi2eb
    jz short lbl317f
    jmp short lbl294b
    nop
lbl2F3f:
    sub ax, offset mi2f3
    jz short lbl327f
    sub ax, offset mi2f8
    jz short lbl327f
    sub ax, offset mi2fd
    jz short lbl337f
    sub ax,80h
    jz short lbl343f
    sub ax,100h
    jz short lbl34Bf
    jmp short lbl294b
    nop
lbl30Ff:
    call mf30f
    jmp near ptr lbl294b
lbl317f:
    call mf317
    jmp near ptr lbl294b
lbl31Ff:
    call mf31f
    jmp near ptr lbl294b
lbl327f:
    push word ptr ds:[69E2h]
    call mf32b
lbl330b:
    add sp,2h
    jmp near ptr lbl294b
    nop
lbl337f:
    push word ptr ds:[69E8h]
    call mf33b
    jmp short lbl330b
    nop
lbl343f:
    call mf343
    jmp near ptr lbl294b
lbl34Bf:
    call mf34b
    jmp near ptr lbl294b
    push word ptr ds:[5Ch]
    mov ax,31h
    push ax
    push word ptr ds:[5Ah]
    mov ax,2h
    push ax
    call mf363
    add sp,8h
    mov ax,7h
    push ax
    xor ax,ax
    push ax
    call mf372
    add sp,4h
    retf
    push bp
    mov bp,sp
    sub sp,0Ch
    call mf381
    mov ax,1h
    push ax
    call mf38a
    add sp,2h
    mov ax,word ptr ds:[69F8h]
    mov word ptr ds:[5C32h],ax
    mov ax,word ptr [bp+0Ch]
    mov word ptr [bp-4h],ax
    les bx, dword ptr [bp+6h]
    cmp word ptr es:[bx],0h
    jnz short lbl3AAf
    jmp near ptr lbl42Ff
lbl3AAf:
    mov word ptr [bp-0Ch],bx
    mov word ptr [bp-0Ah],es
lbl3B0b:
    push word ptr es:[bx]
    call mf3b3
    add sp,2h
    mov word ptr [bp-8h],ax
    mov word ptr [bp-6h],dx
    mov ax,word ptr [bp-4h]
    inc ax
    push ax
    mov ax,word ptr [bp+0Ah]
    inc ax
    push ax
    call mf3cb
    add sp,4h
    mov ax,0FFFFh
    push ax
    xor cx,cx
    push cx
    call mf3da
    add sp,4h
    push word ptr [bp-6h]
    push word ptr [bp-8h]
    call mf3e8
    add sp,4h
    push word ptr [bp-4h]
    push word ptr [bp+0Ah]
    call mf3f6
    add sp,4h
    mov ax,0FFFFh
    push ax
    mov ax,0Fh
    push ax
    call mf406
    add sp,4h
    push word ptr [bp-6h]
    push word ptr [bp-8h]
    call mf414
    add sp,4h
    mov ax,word ptr ds:[69F8h]
    add word ptr [bp-4h],ax
    add word ptr [bp-0Ch],2h
    les bx, dword ptr [bp-0Ch]
    cmp word ptr es:[bx],0h
    jnz short lbl3B0b
lbl42Ff:
    xor ax,ax
    push ax
    mov cx,8h
    push cx
    push word ptr [bp-4h]
    mov cx,31h
    push cx
    push word ptr [bp+0Ch]
    mov cx,2h
    push cx
    push ax
    call mf445
    add sp,0Eh
    call mf44d
    mov ax,word ptr [bp-4h]
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
