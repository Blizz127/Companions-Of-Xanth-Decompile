_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf34e:FAR
    EXTRN mf339:FAR
    EXTRN mf287:FAR
    EXTRN mf3f9:FAR
    EXTRN mf2f5:FAR
    EXTRN mf26b:FAR
    EXTRN mf411:FAR
    EXTRN mf240:FAR
    EXTRN mf2dd:FAR
    EXTRN mf1f0:FAR
    EXTRN mf188:FAR
    EXTRN mf11d:FAR
    EXTRN mf3ea:FAR
    EXTRN mf305:FAR
    EXTRN mf35b:FAR
    EXTRN mf27b:FAR
    EXTRN mf371:FAR
    EXTRN mf42a:FAR
    EXTRN mf15e:FAR
    EXTRN mf3a0:FAR
    EXTRN mf22a:FAR
    EXTRN mf32b:FAR
    EXTRN mf19c:FAR
    EXTRN mf211:FAR
    EXTRN mf311:FAR
    EXTRN mf14e:FAR
    EXTRN mf250:FAR
    EXTRN mfbe:FAR
    EXTRN mf295:FAR
    EXTRN mf330:FAR
    EXTRN mf3ae:FAR
    EXTRN mf2a1:FAR
    EXTRN mf440:FAR
    EXTRN mf381:FAR
    EXTRN mf3bd:FAR
    EXTRN mf3d3:FAR
    EXTRN mf3a8:FAR
    EXTRN mf86:FAR
    EXTRN mf2cd:FAR
    EXTRN mf1a7:FAR
    EXTRN mf1f5:FAR
    EXTRN mf1c2:FAR
    EXTRN mf389:FAR
    EXTRN mif:NEAR
    EXTRN mf21d:FAR
    EXTRN mf3c2:FAR
    EXTRN mi12:NEAR
    EXTRN mf2e5:FAR
    EXTRN mfff:FAR
    EXTRN mf20c:FAR
    EXTRN mf146:FAR
    EXTRN mf28f:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,14h
    push si
    mov word ptr [bp-2h],0h
    mov ax,word ptr [bp+6h]
    sub ax, offset mif
    cmp ax, offset mi12
    jna short lbl1Af
    jmp near ptr lbl448f
lbl1Af:
    add ax,ax
    xchg ax,bx
    jmp word ptr cs:[bx+3FFh]
    db 21h, 04h, 33h, 05h, 33h, 05h, 33h, 05h, 25h, 08h, 25h, 08h, 45h, 05h, 0CDh, 05h
    db 25h, 08h, 25h, 08h, 25h, 08h, 25h, 08h, 25h, 08h, 25h, 08h, 0DFh, 05h, 11h, 08h
    db 0CDh, 05h
    mov word ptr [bp-10h],2D5Bh
    mov bx,word ptr ds:[2EAh]
    mov ax,bx
    add bx,bx
    add bx,bx
    add bx,ax
    add bx,bx
    add bx,word ptr ds:[2ECh]
    add bx,bx
    mov ax,word ptr [bx+2C90h]
    mov word ptr [bp-14h],ax
lbl64b:
    mov bx,word ptr [bp-10h]
    sub ah,ah
    mov al,byte ptr [bx]
    test word ptr [bp-14h],ax
    jz short lbl73f
    inc word ptr [bp-2h]
lbl73f:
    add word ptr [bp-10h],6h
    cmp word ptr [bp-10h],2D73h
    jc short lbl64b
    mov ax,4h
    mov dx,0F01Dh
    push dx
    push ax
    call mf86
    add sp,4h
    cmp word ptr [bp-2h],1h
    jng short lbl9Af
    xor ax,ax
    cwd
    jmp short lbl9Ff
    nop
lbl9Af:
    mov ax,2D8Ch
    mov dx,ds
lbl9Ff:
    push dx
    push ax
    cmp word ptr [bp-2h],1h
    jng short lblAEf
    mov ax,2D8Eh
    mov dx,ds
    jmp short lblB4f
lblAEf:
    mov ax,6h
    mov dx,0F01Dh
lblB4f:
    push dx
    push ax
    mov ax,5h
    mov dx,0F01Dh
    push dx
    push ax
    call mfbe
    add sp,0Ch
    mov ax,word ptr [bp-2h]
    mov word ptr [bp-4h],ax
    mov word ptr [bp-12h],2D5Bh
lblD1b:
    mov bx,word ptr ds:[2EAh]
    mov ax,bx
    add bx,bx
    add bx,bx
    add bx,ax
    add bx,bx
    add bx,word ptr ds:[2ECh]
    mov si,word ptr [bp-12h]
    add bx,bx
    mov al,byte ptr [si]
    sub ah,ah
    test word ptr [bx+2C90h],ax
    jz short lbl125f
    mov bx,si
    push word ptr [bx+3h]
    push word ptr [bx+1h]
    mov ax,2D97h
    push ds
    push ax
    call mfff
    add sp,8h
    dec word ptr [bp-4h]
    jz short lbl125f
    cmp word ptr [bp-4h],1h
    jng short lbl118f
    mov ax,2D9Dh
    jmp short lbl11Bf
    nop
lbl118f:
    mov ax,2DA0h
lbl11Bf:
    push ds
    push ax
    call mf11d
    add sp,4h
lbl125f:
    add word ptr [bp-12h],6h
    cmp word ptr [bp-12h],2D73h
    jc short lblD1b
    cmp word ptr [bp-2h],1h
    jng short lbl13Cf
    mov ax,2DA6h
    jmp short lbl13Ff
    nop
lbl13Cf:
    mov ax,2DA8h
lbl13Ff:
    push ds
    push ax
    mov ax,2DA9h
    push ds
    push ax
    call mf146
    add sp,8h
lbl14Eb:
    call mf14e
    jmp near ptr lbl448f
    mov ax,3h
    mov dx,0F01Dh
    push dx
    push ax
    call mf15e
    add sp,4h
    jmp short lbl14Eb
    cmp word ptr ds:[6A22h],0EDh
    jnz short lbl175f
    mov byte ptr ds:[2D73h],1h
lbl175f:
    cmp word ptr ds:[6A22h],0C9h
    jnz short lbl1A4f
    cmp word ptr ds:[2B8h],1h
    jnz short lbl1A4f
    mov ax,14h
    push ax
    call mf188
    add sp,2h
    or ax,ax
    jnz short lbl1A4f
    mov ax,6h
    push ax
    mov ax,14h
    push ax
    call mf19c
    add sp,4h
lbl1A4f:
    xor ax,ax
    push ax
    call mf1a7
    add sp,2h
    or ax,ax
    jz short lbl1BFf
    cmp byte ptr ds:[336h],0h
    jnz short lbl1BFf
    mov byte ptr ds:[336h],1h
lbl1BFf:
    xor ax,ax
    push ax
    call mf1c2
    add sp,2h
    or ax,ax
    jz short lbl1DAf
    cmp byte ptr ds:[340h],0h
    jnz short lbl1DAf
    mov byte ptr ds:[340h],1h
lbl1DAf:
    mov cl,byte ptr ds:[2ECh]
    mov ax,1h
    shl ax,cl
    mov bx,word ptr ds:[2EAh]
    add bx,bx
    or word ptr [bx+2C7Eh],ax
    jmp near ptr lbl448f
    call mf1f0
    call mf1f5
    mov byte ptr ds:[2D72h],0h
    jmp near ptr lbl448f
    cmp byte ptr ds:[2D73h],0h
    jnz short lbl20Cf
    jmp near ptr lbl2AEf
lbl20Cf:
    call mf20c
    call mf211
    xor ax,ax
    mov dx,0F01Dh
    push dx
    push ax
    call mf21d
    add sp,4h
    mov ax,2D74h
    push ds
    push ax
    call mf22a
    add sp,4h
    cmp word ptr ds:[58h],0h
    jnz short lbl258f
    cmp word ptr ds:[56h],1h
    jz short lbl258f
    call mf240
    mov al,1h
    push ax
    mov ax,12h
    push ax
    mov ax,985h
    push ax
    call mf250
    add sp,6h
lbl258f:
    xor al,al
    mov byte ptr ds:[2D73h],al
    mov byte ptr ds:[312h],al
    xor cx,cx
    push cx
    mov cx,0CDh
    push cx
    mov cx,0ECh
    push cx
    call mf26b
    add sp,6h
    mov ax,0Eh
    push ax
    mov ax,0D7h
    push ax
    call mf27b
    add sp,4h
    mov ax,0Bh
    push ax
    call mf287
    add sp,2h
    call mf28f
    push ax
    call mf295
    add sp,2h
    mov ax,1388h
    push ax
    call mf2a1
    add sp,2h
    mov byte ptr ds:[2D72h],0h
lbl2AEf:
    cmp byte ptr ds:[29Ch],0h
    jz short lbl321f
    mov byte ptr ds:[317h],1h
    mov byte ptr ds:[29Ch],0h
    cmp word ptr ds:[58h],0h
    jnz short lbl2EAf
    cmp word ptr ds:[56h],1h
    jz short lbl2EAf
    call mf2cd
    xor al,al
    push ax
    mov ax,10h
    push ax
    mov ax,960h
    push ax
    call mf2dd
    add sp,6h
    call mf2e5
lbl2EAf:
    xor ax,ax
    push ax
    mov ax,0CDh
    push ax
    mov ax,0ECh
    push ax
    call mf2f5
    add sp,6h
    mov ax,1h
    mov dx,0F01Dh
    push dx
    push ax
    call mf305
    add sp,4h
    mov ax,1770h
    push ax
    call mf311
    add sp,2h
    xor al,al
    mov byte ptr ds:[29Ch],al
    mov byte ptr ds:[2D72h],al
lbl321f:
    cmp byte ptr ds:[32Ch],0h
    jnz short lbl32Bf
    jmp near ptr lbl3B6f
lbl32Bf:
    call mf32b
    call mf330
    mov ax,0Bh
    push ax
    call mf339
    add sp,2h
    mov byte ptr ds:[2D72h],0h
    mov ax,2h
    mov dx,0F01Dh
    push dx
    push ax
    call mf34e
    add sp,4h
    mov ax,2D80h
    push ds
    push ax
    call mf35b
    add sp,4h
    cmp word ptr ds:[58h],0h
    jnz short lbl38Ef
    cmp word ptr ds:[56h],1h
    jz short lbl38Ef
    call mf371
    xor al,al
    push ax
    mov ax,12h
    push ax
    mov ax,985h
    push ax
    call mf381
    add sp,6h
    call mf389
lbl38Ef:
    mov byte ptr ds:[312h],1h
    mov byte ptr ds:[32Ch],0h
    mov ax,0Eh
    push ax
    mov ax,0D7h
    push ax
    call mf3a0
    add sp,4h
    call mf3a8
    push ax
    call mf3ae
    add sp,2h
lbl3B6f:
    cmp byte ptr ds:[2D72h],0h
    jnz short lbl41Ef
    call mf3bd
    call mf3c2
    xor ax,ax
    push ax
    push ax
    mov ax,14h
    push ax
    mov ax,902h
    push ax
    call mf3d3
    add sp,8h
    cmp byte ptr ds:[317h],0h
    jz short lbl419f
    mov ax,0CDh
    push ax
    mov ax,0ECh
    push ax
    call mf3ea
    add sp,4h
    or ax,ax
    jz short lbl419f
    xor ax,ax
    push ax
    call mf3f9
    add sp,2h
    or ax,ax
    jz short lbl419f
    xor ax,ax
    push ax
    push ax
    mov ax,13h
    push ax
    mov ax,971h
    push ax
    call mf411
    add sp,8h
lbl419f:
    mov byte ptr ds:[2D72h],1h
lbl41Ef:
    mov ax,4Ch
    push ax
    mov ax,0h
    mov cx,32FEh
    push cx
    push ax
    call mf42a
    add sp,6h
    jmp short lbl44Af
    mov ax,1Fh
    push ax
    mov ax,390h
    mov cx,32FEh
    push cx
    push ax
    call mf440
    add sp,6h
lbl448f:
    xor ax,ax
lbl44Af:
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
