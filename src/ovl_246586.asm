_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf4a5:FAR
    EXTRN mf30e:FAR
    EXTRN mf414:FAR
    EXTRN mf5e0:FAR
    EXTRN mf58a:FAR
    EXTRN mf1d0:FAR
    EXTRN mf326:FAR
    EXTRN mf114:FAR
    EXTRN mfe3:FAR
    EXTRN mf367:FAR
    EXTRN mi9:NEAR
    EXTRN mf71:FAR
    EXTRN mf44:FAR
    EXTRN mf4db:FAR
    EXTRN mf550:FAR
    EXTRN mf24b:FAR
    EXTRN mfb8:FAR
    EXTRN mf471:FAR
    EXTRN mf47e:FAR
    EXTRN mf243:FAR
    EXTRN mf5c5:FAR
    EXTRN mf349:FAR
    EXTRN mf38d:FAR
    EXTRN mf12b:FAR
    EXTRN mf351:FAR
    EXTRN mf336:FAR
    EXTRN mf11f:FAR
    EXTRN mf93:FAR
    EXTRN mf4f6:FAR
    EXTRN mf126:FAR
    EXTRN mi6:NEAR
    EXTRN mfc8:FAR
    EXTRN mf1e0:FAR
    EXTRN mf198:FAR
    EXTRN mf1fa:FAR
    EXTRN mf5ed:FAR
    EXTRN mf1bb:FAR
    EXTRN mf2d6:FAR
    EXTRN mf500:FAR
    EXTRN mf48b:FAR
    EXTRN mf465:FAR
    EXTRN mf138:FAR
    EXTRN mf479:FAR
    EXTRN mfd4:FAR
    EXTRN mf43f:FAR
    EXTRN mf1a8:FAR
    EXTRN mf52d:FAR
    EXTRN mf268:FAR
    EXTRN mf53:FAR
    EXTRN mf510:FAR
    EXTRN mf230:FAR
    EXTRN mf2a8:FAR
    EXTRN mf53d:FAR
    EXTRN mf44f:FAR
    EXTRN mf576:FAR
    EXTRN mf1c3:FAR
    EXTRN mf3dd:FAR
    EXTRN mf5a5:FAR
    EXTRN mf57e:FAR
    EXTRN mf80:FAR
    EXTRN mf150:FAR
    EXTRN mf4b5:FAR
    EXTRN mf437:FAR
    EXTRN mf3a1:FAR
    EXTRN mf2bb:FAR
    EXTRN mf563:FAR
    EXTRN mf3f4:FAR
    EXTRN mfa3:FAR
    EXTRN mf255:FAR
    EXTRN mf20a:FAR
    EXTRN mf407:FAR
    EXTRN mf5fe:FAR
    EXTRN mf3ef:FAR
    EXTRN mf37b:FAR
    EXTRN mf2ce:FAR
    EXTRN mffe:FAR
    EXTRN mf285:FAR
    EXTRN mf17c:FAR
    EXTRN mf295:FAR
    EXTRN mff9:FAR
    EXTRN mf380:FAR
    EXTRN mf4c8:FAR
    EXTRN mf21d:FAR
    EXTRN mf3c4:FAR
    EXTRN mf2ee:FAR
    EXTRN mf160:FAR
    EXTRN mf4ee:FAR
    EXTRN mf5b1:FAR
    EXTRN mf2fa:FAR
mnem_unit:
    push bp
    mov bp,sp
    mov ax,word ptr [bp+6h]
    sub ax, offset mi6
    cmp ax, offset mi9
    jna short lbl11f
    jmp near ptr lbl603f
lbl11f:
    add ax,ax
    xchg ax,bx
    jmp word ptr cs:[bx+0D4h]
    nop
    db 0F6h, 00h, 0A8h, 01h, 0A8h, 01h, 0A8h, 01h, 0BDh, 06h, 0BDh, 06h, 0BDh, 06h, 0AEh, 01h
    db 0BDh, 06h, 0BDh, 06h, 0BDh, 06h, 0BDh, 06h, 0BDh, 06h, 0BDh, 06h, 0C0h, 01h, 0A2h, 04h
    db 0AEh, 01h
    mov ax,0Ah
    push ax
    mov ax,125h
    push ax
    call mf44
    mov sp,bp
    mov ax,128h
    push ax
    mov ax,12Dh
    push ax
    call mf53
    mov sp,bp
    or ax,ax
    jz short lbl64f
    mov ax,33CFh
    jmp short lbl67f
    nop
lbl64f:
    mov ax,33DDh
lbl67f:
    push ds
    push ax
    mov ax,3h
    mov dx,0F026h
    push dx
    push ax
    call mf71
    mov sp,bp
    mov ax,126h
    push ax
    mov ax,12Eh
    push ax
    call mf80
    mov sp,bp
    or ax,ax
    jz short lblB0f
    mov ax,128h
    push ax
    mov ax,12Dh
    push ax
    call mf93
    mov sp,bp
    or ax,ax
    jz short lblAAf
    mov ax,33E3h
    push ds
    push ax
    call mfa3
    mov sp,bp
lblAAf:
    mov ax,33E9h
    jmp short lblD2f
    nop
lblB0f:
    mov ax,128h
    push ax
    mov ax,12Dh
    push ax
    call mfb8
    mov sp,bp
    or ax,ax
    jnz short lblCFf
    mov ax,33F0h
    push ds
    push ax
    call mfc8
    mov sp,bp
lblCFf:
    mov ax,33F6h
lblD2f:
    push ds
    push ax
    call mfd4
    mov ax,4h
    mov sp,bp
lblDEb:
    mov dx,0F026h
    push dx
    push ax
    call mfe3
    mov sp,bp
    jmp near ptr lbl603f
    nop
    mov ax,2h
    jmp short lblDEb
    nop
    mov byte ptr ds:[33CEh],0h
    call mff9
    call mffe
    jmp near ptr lbl603f
    cmp byte ptr ds:[34Dh],0h
    jnz short lbl110f
    jmp near ptr lbl374f
lbl110f:
    mov ax,0Bh
    push ax
    call mf114
    mov sp,bp
    mov ax,1388h
    push ax
    call mf11f
    mov sp,bp
    call mf126
    call mf12b
    mov ax,128h
    push ax
    mov ax,138h
    push ax
    call mf138
    mov sp,bp
    or ax,ax
    jnz short lbl174f
    cmp word ptr ds:[58h],ax
    jnz short lbl174f
    cmp word ptr ds:[56h],1h
    jz short lbl174f
    call mf150
    xor al,al
    push ax
    mov cx,24h
    push cx
    mov cx,0C0Bh
    push cx
    call mf160
    mov sp,bp
    xor al,al
    push ax
    mov ax,1Eh
    push ax
    mov ax,0C2Fh
    jmp near ptr lbl348f
lbl174f:
    mov ax,126h
    push ax
    mov ax,12Eh
    push ax
    call mf17c
    add sp,4h
    or ax,ax
    jz short lbl18Bf
    jmp near ptr lbl318f
lbl18Bf:
    cmp word ptr ds:[58h],ax
    jnz short lbl1C8f
    cmp word ptr ds:[56h],1h
    jz short lbl1C8f
    call mf198
    xor al,al
    push ax
    mov cx,24h
    push cx
    mov cx,0C75h
    push cx
    call mf1a8
    add sp,6h
    xor al,al
    push ax
    mov ax,1Dh
    push ax
    mov ax,0C99h
    push ax
    call mf1bb
    add sp,6h
    call mf1c3
lbl1C8f:
    mov ax,1h
    mov dx,0F026h
    push dx
    push ax
    call mf1d0
    add sp,4h
    mov ax,0Ah
    push ax
    mov ax,131h
    push ax
    call mf1e0
    add sp,4h
    or ax,ax
    jz short lbl260f
    cmp word ptr ds:[58h],0h
    jnz short lbl250f
    cmp word ptr ds:[56h],1h
    jz short lbl250f
    call mf1fa
    xor al,al
    push ax
    mov cx,1Ah
    push cx
    mov cx,0D48h
    push cx
    call mf20a
    add sp,6h
    xor al,al
    push ax
    mov cx,11h
    push cx
    mov dx,0D62h
    push dx
    call mf21d
    add sp,6h
    xor al,al
    push ax
    mov cx,11h
    push cx
    mov cx,0D73h
    push cx
    call mf230
    add sp,6h
    xor al,al
    push ax
    mov ax,12h
    push ax
    mov ax,0D84h
    push ax
    call mf243
    add sp,6h
    call mf24b
lbl250f:
    mov byte ptr ds:[34Ch],1h
    call mf255
    mov ax,1h
    jmp near ptr lbl605f
lbl260f:
    mov ax,0Ah
    push ax
    mov ax,130h
    push ax
    call mf268
    add sp,4h
    or ax,ax
    jnz short lbl277f
    jmp near ptr lbl356f
lbl277f:
    cmp word ptr ds:[58h],0h
    jnz short lbl2DBf
    cmp word ptr ds:[56h],1h
    jz short lbl2DBf
    call mf285
    xor al,al
    push ax
    mov cx,19h
    push cx
    mov cx,0D00h
    push cx
    call mf295
    add sp,6h
    xor al,al
    push ax
    mov cx,10h
    push cx
    mov dx,0D19h
    push dx
    call mf2a8
    add sp,6h
    xor al,al
    push ax
    mov cx,10h
    push cx
    mov cx,0D29h
    push cx
    call mf2bb
    add sp,6h
    xor al,al
    push ax
    mov ax,0Fh
    push ax
    mov ax,0D39h
    push ax
    call mf2ce
    add sp,6h
    call mf2d6
lbl2DBf:
    cmp byte ptr ds:[355h],0h
    jnz short lbl302f
    mov ax,1h
    mov byte ptr ds:[355h],al
    push ax
    push ax
    mov ax,14h
    push ax
    call mf2ee
    add sp,6h
    mov ax,0BB8h
    push ax
    call mf2fa
    add sp,2h
lbl302f:
    mov ax,1h
    push ax
    mov ax,126h
    push ax
    mov ax,12Eh
    push ax
    call mf30e
    add sp,6h
    jmp short lbl356f
lbl318f:
    cmp word ptr ds:[58h],0h
    jnz short lbl356f
    cmp word ptr ds:[56h],1h
    jz short lbl356f
    call mf326
    xor al,al
    push ax
    mov cx,24h
    push cx
    mov cx,0C75h
    push cx
    call mf336
    add sp,6h
    xor al,al
    push ax
    mov ax,1Dh
    push ax
    mov ax,0C99h
lbl348f:
    push ax
    call mf349
    add sp,6h
    call mf351
lbl356f:
    mov byte ptr ds:[34Dh],0h
    mov ax,1h
    push ax
    mov ax,128h
    push ax
    mov ax,12Dh
    push ax
    call mf367
    add sp,6h
    mov byte ptr ds:[33CEh],0h
lbl374f:
    cmp byte ptr ds:[33CEh],0h
    jnz short lbl3D1f
    call mf37b
    call mf380
    mov ax,0Ah
    push ax
    mov ax,129h
    push ax
    call mf38d
    add sp,4h
    or ax,ax
    jz short lbl3CCf
    mov ax,128h
    push ax
    mov ax,138h
    push ax
    call mf3a1
    add sp,4h
    or ax,ax
    jnz short lbl3B8f
    push ax
    push ax
    mov ax,0Ah
    push ax
    mov ax,0C4Dh
    jmp short lbl3C3f
lbl3B8f:
    xor ax,ax
    push ax
    push ax
    mov ax,0Ah
    push ax
    mov ax,0CB6h
lbl3C3f:
    push ax
    call mf3c4
    add sp,8h
lbl3CCf:
    mov byte ptr ds:[33CEh],1h
lbl3D1f:
    mov ax,0Bh
    push ax
    mov ax,0h
    mov cx,3373h
    push cx
    push ax
    call mf3dd
    add sp,6h
    jmp near ptr lbl605f
    cmp byte ptr ds:[34Fh],0h
    jz short lbl457f
    call mf3ef
    call mf3f4
    cmp word ptr ds:[58h],0h
    jnz short lbl444f
    cmp word ptr ds:[56h],1h
    jz short lbl444f
    call mf407
    mov ax,128h
    push ax
    mov ax,138h
    push ax
    call mf414
    add sp,4h
    or ax,ax
    jnz short lbl42Cf
    xor al,al
    push ax
    mov ax,1Eh
    push ax
    mov ax,0C57h
    jmp short lbl436f
lbl42Cf:
    xor al,al
    push ax
    mov ax,1Eh
    push ax
    mov ax,0CC0h
lbl436f:
    push ax
    call mf437
    add sp,6h
    call mf43f
lbl444f:
    xor ax,ax
    mov byte ptr ds:[34Fh],al
    push ax
    push ax
    mov ax,12Dh
    push ax
    call mf44f
    add sp,6h
lbl457f:
    cmp byte ptr ds:[34Eh],0h
    jnz short lbl461f
    jmp near ptr lbl5F2f
lbl461f:
    mov ax,0Bh
    push ax
    call mf465
    add sp,2h
    mov ax,1388h
    push ax
    call mf471
    add sp,2h
    call mf479
    call mf47e
    mov ax,0Ah
    push ax
    mov ax,131h
    push ax
    call mf48b
    add sp,4h
    or ax,ax
    jz short lbl508f
    cmp word ptr ds:[58h],0h
    jnz short lbl4FBf
    cmp word ptr ds:[56h],1h
    jz short lbl4FBf
    call mf4a5
    xor al,al
    push ax
    mov cx,1Ah
    push cx
    mov cx,0D48h
    push cx
    call mf4b5
    add sp,6h
    xor al,al
    push ax
    mov cx,11h
    push cx
    mov dx,0D62h
    push dx
    call mf4c8
    add sp,6h
    xor al,al
    push ax
    mov cx,11h
    push cx
    mov cx,0D73h
    push cx
    call mf4db
    add sp,6h
    xor al,al
    push ax
    mov ax,12h
    push ax
    mov ax,0D84h
    push ax
    call mf4ee
    add sp,6h
    call mf4f6
lbl4FBf:
    mov byte ptr ds:[34Ch],1h
    call mf500
    jmp near ptr lbl603f
lbl508f:
    mov ax,0Ah
    push ax
    mov ax,130h
    push ax
    call mf510
    add sp,4h
    or ax,ax
    jnz short lbl51Ff
    jmp near ptr lbl5CDf
lbl51Ff:
    cmp word ptr ds:[58h],0h
    jnz short lbl583f
    cmp word ptr ds:[56h],1h
    jz short lbl583f
    call mf52d
    xor al,al
    push ax
    mov cx,19h
    push cx
    mov cx,0D00h
    push cx
    call mf53d
    add sp,6h
    xor al,al
    push ax
    mov cx,10h
    push cx
    mov dx,0D19h
    push dx
    call mf550
    add sp,6h
    xor al,al
    push ax
    mov cx,10h
    push cx
    mov cx,0D29h
    push cx
    call mf563
    add sp,6h
    xor al,al
    push ax
    mov ax,0Fh
    push ax
    mov ax,0D39h
    push ax
    call mf576
    add sp,6h
    call mf57e
lbl583f:
    xor ax,ax
    mov dx,0F026h
    push dx
    push ax
    call mf58a
    add sp,4h
    cmp byte ptr ds:[355h],0h
    jnz short lbl5B9f
    mov ax,1h
    mov byte ptr ds:[355h],al
    push ax
    push ax
    mov ax,14h
    push ax
    call mf5a5
    add sp,6h
    mov ax,1388h
    push ax
    call mf5b1
    add sp,2h
lbl5B9f:
    mov ax,1h
    push ax
    mov ax,126h
    push ax
    mov ax,12Eh
    push ax
    call mf5c5
    add sp,6h
lbl5CDf:
    mov byte ptr ds:[34Eh],0h
    mov word ptr ds:[69F4h],0h
    mov ax,20h
    mov cx,2199h
    push cx
    push ax
    call mf5e0
    add sp,4h
    mov byte ptr ds:[33CEh],0h
    call mf5ed
lbl5F2f:
    mov ax,6h
    push ax
    mov ax,84h
    mov cx,3373h
    push cx
    push ax
    call mf5fe
lbl603f:
    xor ax,ax
lbl605f:
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
