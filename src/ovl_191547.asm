_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi6:NEAR
    EXTRN mf4ae:FAR
    EXTRN mfad:FAR
    EXTRN mf4c4:FAR
    EXTRN mf9d:FAR
    EXTRN mf173:FAR
    EXTRN mf2b5:FAR
    EXTRN mf4dc:FAR
    EXTRN mf4e1:FAR
    EXTRN mf53:FAR
    EXTRN mf144:FAR
    EXTRN mf36a:FAR
    EXTRN mf316:FAR
    EXTRN mf24a:FAR
    EXTRN mf47d:FAR
    EXTRN mf2a5:FAR
    EXTRN mi9:NEAR
    EXTRN mf42:FAR
    EXTRN mf37a:FAR
    EXTRN mf1d4:FAR
    EXTRN mf3f6:FAR
    EXTRN mfec:FAR
    EXTRN mf289:FAR
    EXTRN mf333:FAR
    EXTRN mf306:FAR
    EXTRN mf442:FAR
    EXTRN mf110:FAR
    EXTRN mf25e:FAR
    EXTRN mf470:FAR
    EXTRN mf236:FAR
    EXTRN mf3d2:FAR
    EXTRN mf183:FAR
    EXTRN mf295:FAR
    EXTRN mf12a:FAR
    EXTRN mf382:FAR
    EXTRN mf3da:FAR
    EXTRN mf3e3:FAR
    EXTRN mf40e:FAR
    EXTRN mf4d4:FAR
    EXTRN mf3a3:FAR
    EXTRN mf150:FAR
    EXTRN mf2f0:FAR
    EXTRN mf343:FAR
    EXTRN mf1b0:FAR
    EXTRN mfc0:FAR
    EXTRN mf200:FAR
    EXTRN mf3b6:FAR
    EXTRN mf426:FAR
    EXTRN mf406:FAR
    EXTRN mf432:FAR
    EXTRN mf458:FAR
    EXTRN mf48d:FAR
    EXTRN mf2c5:FAR
    EXTRN mf49d:FAR
    EXTRN mfdc:FAR
    EXTRN mf62:FAR
    EXTRN mf84:FAR
    EXTRN mf512:FAR
    EXTRN mf354:FAR
    EXTRN mf38e:FAR
    EXTRN mf468:FAR
    EXTRN mf75:FAR
    EXTRN mf31e:FAR
    EXTRN mf3c2:FAR
    EXTRN mf100:FAR
    EXTRN mf4e7:FAR
    EXTRN mf4fb:FAR
    EXTRN mf197:FAR
    EXTRN mf279:FAR
mnem_unit:
    push bp
    mov bp,sp
    mov ax,word ptr [bp+6h]
    sub ax, offset mi6
    cmp ax, offset mi9
    jna short lbl11f
    jmp near ptr lbl517f
lbl11f:
    add ax,ax
    xchg ax,bx
    jmp word ptr cs:[bx+1C5h]
    nop
    db 0E5h, 01h, 7Fh, 02h, 7Fh, 02h, 7Fh, 02h, 0C2h, 06h, 0C2h, 06h, 07h, 03h, 0F1h, 03h
    db 0C2h, 06h, 0C2h, 06h, 0C2h, 06h, 0C2h, 06h, 0C2h, 06h, 0C2h, 06h, 89h, 04h, 0B1h, 06h
    mov ax,0FCh
    push ax
    mov ax,1h
    push ax
    call mf42
    mov sp,bp
    push dx
    push ax
    mov ax,12h
    mov dx,0F021h
    push dx
    push ax
    call mf53
    mov sp,bp
    mov ax,0FBh
    push ax
    mov ax,0Eh
    push ax
    call mf62
    mov sp,bp
    or ax,ax
    jz short lblB8f
    mov ax,13h
    mov dx,0F021h
    push dx
    push ax
    call mf75
    mov sp,bp
    mov ax,0FBh
    push ax
    mov ax,0Fh
    push ax
    call mf84
    mov sp,bp
    or ax,ax
    jz short lbl98f
    mov ax,14h
    mov dx,0F021h
    push dx
    jmp short lbl9Cf
lbl98f:
    mov ax,3083h
    push ds
lbl9Cf:
    push ax
    call mf9d
    add sp,4h
    mov ax,15h
lblA8b:
    mov dx,0F021h
    push dx
    push ax
    call mfad
    add sp,4h
    jmp near ptr lbl517f
lblB8f:
    mov ax,0FBh
    push ax
    mov ax,10h
    push ax
    call mfc0
    add sp,4h
    or ax,ax
    jnz short lblCFf
    jmp near ptr lbl517f
lblCFf:
    mov ax,16h
    jmp short lblA8b
    mov ax,0Dh
    mov dx,0F021h
    push dx
    push ax
    call mfdc
    add sp,4h
    mov ax,0FBh
    push ax
    mov ax,0Eh
    push ax
    call mfec
    add sp,4h
    or ax,ax
    jz short lbl122f
    mov ax,0Eh
    mov dx,0F021h
    push dx
    push ax
    call mf100
    add sp,4h
    mov ax,0FBh
    push ax
    mov ax,0Fh
    push ax
    call mf110
    add sp,4h
    or ax,ax
    jz short lbl14Cf
    mov ax,0Fh
    jmp short lbl13Ff
    nop
lbl122f:
    mov ax,0FBh
    push ax
    mov ax,10h
    push ax
    call mf12a
    add sp,4h
    or ax,ax
    jz short lbl13Cf
    mov ax,10h
    jmp short lbl13Ff
    nop
lbl13Cf:
    mov ax,11h
lbl13Ff:
    mov dx,0F021h
    push dx
    push ax
    call mf144
    add sp,4h
lbl14Cf:
    mov ax,2Eh
    push ax
    call mf150
    add sp,2h
    jmp near ptr lbl517f
    nop
    cmp byte ptr ds:[327h],0h
    jnz short lbl1BDf
    mov byte ptr ds:[3077h],1h
    xor ax,ax
    push ax
    mov cx,0FBh
    push cx
    mov cx,0Fh
    push cx
    call mf173
    add sp,6h
    mov ax,0Ah
    push ax
    mov ax,0FAh
    push ax
    call mf183
    add sp,4h
    or ax,ax
    jz short lbl1BDf
    mov ax,1h
    push ax
    mov ax,0FAh
    push ax
    call mf197
    add sp,4h
    or ax,ax
    jz short lbl1BDf
    mov byte ptr ds:[3078h],1h
    xor ax,ax
    push ax
    push ax
    mov ax,0Fh
    push ax
    call mf1b0
    add sp,6h
    mov byte ptr ds:[327h],1h
lbl1BDf:
    cmp byte ptr ds:[326h],0h
    jnz short lbl208f
    mov byte ptr ds:[3079h],1h
    xor ax,ax
    push ax
    mov ax,0FBh
    push ax
    mov ax,0Eh
    push ax
    call mf1d4
    add sp,6h
    cmp byte ptr ds:[327h],0h
    jz short lbl208f
    cmp byte ptr ds:[32Dh],0h
    jz short lbl208f
    cmp byte ptr ds:[332h],0h
    jz short lbl1F8f
    cmp byte ptr ds:[331h],0h
    jnz short lbl208f
lbl1F8f:
    mov ax,2h
    push ax
    mov ax,1Ch
    push ax
    call mf200
    add sp,4h
lbl208f:
    cmp byte ptr ds:[327h],0h
    jnz short lbl212f
    jmp near ptr lbl517f
lbl212f:
    cmp byte ptr ds:[326h],0h
    jnz short lbl21Cf
    jmp near ptr lbl517f
lbl21Cf:
    cmp byte ptr ds:[328h],0h
    jz short lbl226f
    jmp near ptr lbl517f
lbl226f:
    mov byte ptr ds:[307Ah],1h
    xor ax,ax
    push ax
    mov ax,0FBh
    push ax
    mov ax,10h
    push ax
    call mf236
    add sp,6h
    mov byte ptr ds:[328h],1h
    jmp near ptr lbl517f
    mov ax,1Ch
    push ax
    call mf24a
    add sp,2h
    or ax,ax
    jz short lbl29Df
    mov ax,1h
    push ax
    mov ax,100h
    push ax
    call mf25e
    add sp,4h
    or ax,ax
    jz short lbl291f
    cmp word ptr ds:[2A8h],0h
    jnz short lbl291f
    mov ax,5A07h
    push ax
    mov ax,20Dh
    push ax
    call mf279
    add sp,4h
    xor ax,ax
    push ax
    push ax
    mov ax,100h
    push ax
    call mf289
    add sp,6h
lbl291f:
    mov ax,1Ch
    push ax
    call mf295
    add sp,2h
lbl29Df:
    xor ax,ax
    push ax
    push ax
    mov cx,0Eh
    push cx
    call mf2a5
    add sp,6h
    xor ax,ax
    push ax
    push ax
    mov cx,0Fh
    push cx
    call mf2b5
    add sp,6h
    xor ax,ax
    push ax
    push ax
    mov ax,10h
    push ax
    call mf2c5
    add sp,6h
    xor al,al
    mov byte ptr ds:[3077h],al
    mov byte ptr ds:[3078h],al
    mov byte ptr ds:[3079h],al
    mov byte ptr ds:[307Ah],al
    jmp near ptr lbl517f
    cmp byte ptr ds:[3077h],0h
    jnz short lbl2E8f
    jmp near ptr lbl3ABf
lbl2E8f:
    mov ax,8h
    mov dx,0F021h
    push dx
    push ax
    call mf2f0
    add sp,4h
    cmp word ptr ds:[58h],0h
    jnz short lbl323f
    cmp word ptr ds:[56h],1h
    jz short lbl323f
    call mf306
    xor al,al
    push ax
    mov ax,16h
    push ax
    mov ax,0A85h
    push ax
    call mf316
    add sp,6h
    call mf31e
lbl323f:
    mov byte ptr ds:[3077h],0h
    cmp byte ptr ds:[3078h],0h
    jz short lbl39Ef
    mov ax,0Bh
    push ax
    call mf333
    add sp,2h
    mov ax,9h
    mov dx,0F021h
    push dx
    push ax
    call mf343
    add sp,4h
    mov ax,1h
    push ax
    push ax
    mov ax,0Fh
    push ax
    call mf354
    add sp,6h
    cmp word ptr ds:[58h],0h
    jnz short lbl38Af
    cmp word ptr ds:[56h],1h
    jz short lbl38Af
    call mf36a
    mov al,1h
    push ax
    mov ax,16h
    push ax
    mov ax,0A85h
    push ax
    call mf37a
    add sp,6h
    call mf382
    jmp short lbl396f
    nop
lbl38Af:
    mov ax,1388h
    push ax
    call mf38e
    add sp,2h
lbl396f:
    mov byte ptr ds:[3078h],0h
    jmp short lbl3ABf
    nop
lbl39Ef:
    mov ax,307Bh
    push ds
    push ax
    call mf3a3
    add sp,4h
lbl3ABf:
    cmp byte ptr ds:[3079h],0h
    jz short lbl418f
    mov ax,0Bh
    push ax
    call mf3b6
    add sp,2h
    mov ax,7D0h
    push ax
    call mf3c2
    add sp,2h
    mov ax,0Ah
    mov dx,0F021h
    push dx
    push ax
    call mf3d2
    add sp,4h
lbl3DAb:
    call mf3da
    or ax,ax
    jnz short lbl3DAb
    call mf3e3
    cmp word ptr ds:[58h],0h
    jnz short lbl413f
    cmp word ptr ds:[56h],1h
    jz short lbl413f
    call mf3f6
    xor al,al
    push ax
    mov ax,1Bh
    push ax
    mov ax,0A6Ah
    push ax
    call mf406
    add sp,6h
    call mf40e
lbl413f:
    mov byte ptr ds:[3079h],0h
lbl418f:
    cmp byte ptr ds:[307Ah],0h
    jnz short lbl422f
    jmp near ptr lbl4EFf
lbl422f:
    mov ax,0Bh
    push ax
    call mf426
    add sp,2h
    mov ax,7D0h
    push ax
    call mf432
    add sp,2h
    mov ax,0Bh
    mov dx,0F021h
    push dx
    push ax
    call mf442
    add sp,4h
    cmp word ptr ds:[58h],0h
    jnz short lbl475f
    cmp word ptr ds:[56h],1h
    jz short lbl475f
    call mf458
    xor al,al
    push ax
    mov ax,1Bh
    push ax
    mov ax,0A9Bh
    push ax
    call mf468
    add sp,6h
    call mf470
lbl475f:
    mov ax,5A09h
    push ax
    mov ax,223h
    push ax
    call mf47d
    add sp,4h
    xor ax,ax
    push ax
    push ax
    mov cx,10h
    push cx
    call mf48d
    add sp,6h
    mov ax,0Ch
    mov dx,0F021h
    push dx
    push ax
    call mf49d
    add sp,4h
    mov ax,1h
    push ax
    push ax
    mov ax,3h
    push ax
    call mf4ae
    add sp,6h
    cmp word ptr ds:[58h],0h
    jnz short lbl4E1f
    cmp word ptr ds:[56h],1h
    jz short lbl4E1f
    call mf4c4
    mov al,1h
    push ax
    mov ax,1Bh
    push ax
    mov ax,0A9Bh
    push ax
    call mf4d4
    add sp,6h
    call mf4dc
lbl4E1f:
    call mf4e1
    push ax
    call mf4e7
    add sp,2h
lbl4EFf:
    mov ax,7h
    push ax
    mov ax,0h
    mov cx,3351h
    push cx
    push ax
    call mf4fb
    add sp,6h
    jmp short lbl519f
    nop
    mov ax,4h
    push ax
    mov ax,54h
    mov cx,3351h
    push cx
    push ax
    call mf512
lbl517f:
    xor ax,ax
lbl519f:
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
