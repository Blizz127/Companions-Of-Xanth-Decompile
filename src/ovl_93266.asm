_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf116:FAR
    EXTRN mf201:FAR
    EXTRN mf1d0:FAR
    EXTRN mf46e:FAR
    EXTRN mf2c7:FAR
    EXTRN mfe7:FAR
    EXTRN mf54:FAR
    EXTRN mi9:NEAR
    EXTRN mf179:FAR
    EXTRN mf223:FAR
    EXTRN mi2e8:NEAR
    EXTRN mf4a0:FAR
    EXTRN mf13d:FAR
    EXTRN mf48:FAR
    EXTRN mf490:FAR
    EXTRN mf20f:FAR
    EXTRN mf236:FAR
    EXTRN mfa7:FAR
    EXTRN mic:NEAR
    EXTRN mf296:FAR
    EXTRN mf3ae:FAR
    EXTRN mf104:FAR
    EXTRN mf480:FAR
    EXTRN mf458:FAR
    EXTRN mf12b:FAR
    EXTRN mf1f5:FAR
    EXTRN mf78:FAR
    EXTRN mf1c2:FAR
    EXTRN mf1b4:FAR
    EXTRN mf24e:FAR
    EXTRN mf95:FAR
    EXTRN mf433:FAR
    EXTRN mf2a9:FAR
    EXTRN mf43f:FAR
    EXTRN mf1a8:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,0Eh
    mov ax,word ptr [bp+6h]
    sub ax, offset mi9
    cmp ax, offset mic
    jna short lbl14f
    jmp near ptr lbl4ADf
lbl14f:
    add ax,ax
    xchg ax,bx
    jmp word ptr cs:[bx+1CEh]
    db 0F2h, 01h, 06h, 02h, 06h, 02h, 06h, 02h, 5Fh, 06h, 36h, 02h, 5Fh, 06h, 2Ah, 06h
    db 5Fh, 06h, 5Fh, 06h, 5Fh, 06h, 5Fh, 06h, 5Fh, 06h, 5Fh, 06h, 5Fh, 06h, 5Fh, 06h
    db 5Fh, 06h, 5Ah, 06h
    mov ax,3h
    mov dx,0F014h
    push dx
    push ax
    call mf48
lbl4Db:
    add sp,4h
    jmp near ptr lbl4ADf
    nop
    call mf54
    cmp byte ptr ds:[301h],0h
    jz short lbl68f
    mov ax,2366h
    mov dx,ds
    jmp short lbl6Ef
    nop
lbl68f:
    mov ax,2h
    mov dx,0F014h
lbl6Ef:
    push dx
    push ax
    mov ax,1h
    mov dx,0F014h
    push dx
    push ax
    call mf78
    add sp,8h
    jmp near ptr lbl4ADf
    nop
    cmp byte ptr ds:[28Eh],0h
    jz short lbl8Ef
    jmp near ptr lbl13Df
lbl8Ef:
    xor ax,ax
    push ax
    mov cx,1h
    push cx
    call mf95
    add sp,4h
    mov word ptr [bp-2h],ax
    or ax,ax
    jz short lblF9f
lblA4b:
    push word ptr [bp-2h]
    call mfa7
    add sp,2h
    mov word ptr [bp-4h],ax
    mov byte ptr [bp-6h],0h
    mov word ptr [bp-0Eh],235Ah
lblBBb:
    mov ax,word ptr [bp-2h]
    mov bx,word ptr [bp-0Eh]
    cmp word ptr [bx],ax
    jz short lblD2f
    add word ptr [bp-0Eh],2h
    cmp word ptr [bp-0Eh],2366h
    jc short lblBBb
    jmp short lblD6f
lblD2f:
    mov byte ptr [bp-6h],1h
lblD6f:
    cmp byte ptr [bp-6h],0h
    jnz short lblEFf
    mov ax,1h
    push ax
    mov ax,2Eh
    push ax
    push word ptr [bp-2h]
    call mfe7
    add sp,6h
lblEFf:
    mov ax,word ptr [bp-4h]
    mov word ptr [bp-2h],ax
    or ax,ax
    jnz short lblA4b
lblF9f:
    mov ax,1h
    mov byte ptr ds:[28Eh],al
    push ax
    mov ax,68h
    push ax
    call mf104
    add sp,4h
    mov word ptr [bp-2h],ax
    or ax,ax
    jz short lbl13Df
lbl113b:
    push word ptr [bp-2h]
    call mf116
    add sp,2h
    mov word ptr [bp-4h],ax
    xor ax,ax
    push ax
    mov cx,1h
    push cx
    push word ptr [bp-2h]
    call mf12b
    add sp,6h
    mov ax,word ptr [bp-4h]
    mov word ptr [bp-2h],ax
    or ax,ax
    jnz short lbl113b
lbl13Df:
    call mf13d
    cmp word ptr ds:[6A22h],22h
    jz short lbl158f
    cmp word ptr ds:[290h],0h
    jz short lbl158f
    xor ax,ax
    mov word ptr ds:[798h],ax
    mov word ptr ds:[290h],ax
lbl158f:
    cmp byte ptr ds:[298h],0h
    jnz short lbl162f
    jmp near ptr lbl25Af
lbl162f:
    cmp word ptr ds:[6A22h],22h
    jnz short lbl16Cf
    jmp near ptr lbl22Ef
lbl16Cf:
    mov byte ptr ds:[1D00h],0h
    mov ax,5A00h
    push ax
    mov ax,43h
lbl178b:
    push ax
    call mf179
    add sp,4h
    xor ax,ax
    mov word ptr ds:[798h],ax
    mov word ptr ds:[290h],ax
    mov byte ptr ds:[29Ah],1h
lbl18Eb:
    cmp byte ptr ds:[29Ah],0h
    jz short lbl1D8f
    mov byte ptr ds:[29Ah],0h
    mov word ptr ds:[256h],22h
    mov ax,20h
    mov cx,2199h
    push cx
    push ax
    call mf1a8
    add sp,4h
    mov ax,10h
    push ax
    call mf1b4
    add sp,2h
    mov word ptr ds:[256h],5Ah
    call mf1c2
    mov byte ptr ds:[783h],1h
    mov ax,22h
    push ax
    call mf1d0
    add sp,2h
lbl1D8f:
    cmp byte ptr ds:[29Bh],0h
    jnz short lbl1E2f
    jmp near ptr lbl4A8f
lbl1E2f:
    mov byte ptr ds:[29Bh],0h
    mov word ptr ds:[256h],5Bh
    mov ax,20h
    mov cx,2199h
    push cx
    push ax
    call mf1f5
    add sp,4h
    mov ax,10h
    push ax
    call mf201
    add sp,2h
    mov word ptr ds:[256h],5Ah
    call mf20f
    mov byte ptr ds:[783h],1h
    mov word ptr ds:[798h],5h
    mov ax,5Bh
    push ax
    call mf223
    add sp,2h
    jmp near ptr lbl4A8f
lbl22Ef:
    mov ax,5A00h
    push ax
    mov ax,44h
lbl235b:
    push ax
    call mf236
    add sp,4h
    mov ax,word ptr ds:[296h]
    mov word ptr ds:[798h],ax
    mov word ptr ds:[290h],ax
    xor ax,ax
    push ax
    mov ax,2Dh
    push ax
    call mf24e
    add sp,4h
    jmp near ptr lbl18Eb
    nop
lbl25Af:
    cmp byte ptr ds:[299h],0h
    jz short lbl282f
    cmp word ptr ds:[6A22h],22h
    jz short lbl278f
    mov byte ptr ds:[1D00h],0h
    mov ax,5A00h
    push ax
    mov ax,45h
    jmp near ptr lbl178b
    nop
lbl278f:
    mov ax,5A00h
    push ax
    mov ax,47h
    jmp short lbl235b
    nop
lbl282f:
    cmp byte ptr ds:[341h],0h
    jz short lbl2D2f
    mov byte ptr ds:[1D00h],0h
    mov ax,5A00h
    push ax
    mov ax,5Bh
    push ax
    call mf296
    add sp,4h
    xor ax,ax
    push ax
    mov ax,1h
    push ax
    mov ax,14Eh
    push ax
    call mf2a9
    add sp,6h
    mov ax,5h
    mov word ptr ds:[798h],ax
    mov word ptr ds:[290h],ax
    mov byte ptr ds:[341h],ah
    mov byte ptr ds:[783h],1h
    mov ax,13Eh
    push ax
    call mf2c7
    add sp,2h
    jmp near ptr lbl18Eb
lbl2D2f:
    cmp word ptr ds:[6A22h],22h
    jnz short lbl2DCf
    jmp near ptr lbl18Eb
lbl2DCf:
    xor al,al
    mov byte ptr ds:[29Ah],al
    mov byte ptr ds:[1D00h],al
    mov ax,word ptr ds:[2A8h]
    dec ax
    cmp ax, offset mi2e8
    jna short lbl2F0f
    jmp near ptr lbl460f
lbl2F0f:
    add ax,ax
    xchg ax,bx
    jmp word ptr cs:[bx+4AAh]
    db 0E0h, 04h, 0E0h, 04h, 0EAh, 04h, 0F4h, 04h, 0FEh, 04h, 08h, 05h, 12h, 05h, 1Ch, 05h
    db 26h, 05h, 30h, 05h, 3Ah, 05h, 44h, 05h, 4Eh, 05h, 58h, 05h, 70h, 05h, 7Ah, 05h
    db 84h, 05h, 8Eh, 05h, 98h, 05h, 0A2h, 05h, 0ACh, 05h, 0B6h, 05h, 0C0h, 05h, 0CAh, 05h
    db 0D4h, 05h, 0DEh, 05h, 02h, 06h
    mov ax,5A00h
    push ax
    mov ax,36h
    jmp near ptr lbl457f
    mov ax,5A00h
    push ax
    mov ax,32h
    jmp near ptr lbl457f
    mov ax,5A00h
    push ax
    mov ax,38h
    jmp near ptr lbl457f
    mov ax,5A00h
    push ax
    mov ax,3Bh
    jmp near ptr lbl457f
    mov ax,5A00h
    push ax
    mov ax,3Fh
    jmp near ptr lbl457f
    mov ax,5A00h
    push ax
    mov ax,40h
    jmp near ptr lbl457f
    mov ax,5A00h
    push ax
    mov ax,39h
    jmp near ptr lbl457f
    mov ax,5A00h
    push ax
    mov ax,41h
    jmp near ptr lbl457f
    mov ax,5A00h
    push ax
    mov ax,42h
    jmp near ptr lbl457f
    mov ax,5A00h
    push ax
    mov ax,4Ah
    jmp near ptr lbl457f
    mov ax,5A00h
    push ax
    mov ax,48h
    jmp near ptr lbl457f
    mov ax,5A00h
    push ax
    mov ax,49h
    jmp near ptr lbl457f
    mov ax,5A00h
    push ax
    mov ax,4Bh
    push ax
    call mf3ae
    add sp,4h
    mov byte ptr ds:[29Ah],1h
    jmp near ptr lbl460f
    mov ax,5A00h
    push ax
    mov ax,4Ch
    jmp near ptr lbl457f
    mov ax,5A00h
    push ax
    mov ax,4Dh
    jmp near ptr lbl457f
    mov ax,5A00h
    push ax
    mov ax,4Eh
    jmp short lbl457f
    nop
    mov ax,5A00h
    push ax
    mov ax,4Fh
    jmp short lbl457f
    nop
    mov ax,5A00h
    push ax
    mov ax,37h
    jmp short lbl457f
    nop
    mov ax,5A00h
    push ax
    mov ax,50h
    jmp short lbl457f
    nop
    mov ax,5A00h
    push ax
    mov ax,51h
    jmp short lbl457f
    nop
    mov ax,5A00h
    push ax
    mov ax,52h
    jmp short lbl457f
    nop
    mov ax,5A00h
    push ax
    mov ax,53h
    jmp short lbl457f
    nop
    mov ax,5A00h
    push ax
    mov ax,54h
    jmp short lbl457f
    nop
    mov ax,5A00h
    push ax
    mov ax,55h
    jmp short lbl457f
    nop
    xor ax,ax
    mov dx,0F014h
    push dx
    push ax
    call mf433
    add sp,4h
    mov ax,1770h
    push ax
    call mf43f
    add sp,2h
    mov ax,5A00h
    push ax
    mov ax,3Ah
    jmp short lbl457f
    mov ax,5A00h
    push ax
    mov ax,57h
lbl457f:
    push ax
    call mf458
    add sp,4h
lbl460f:
    mov word ptr ds:[2A8h],0h
lbl466b:
    mov ax,5A00h
    push ax
    mov ax,58h
    push ax
    call mf46e
    add sp,4h
    jmp short lbl466b
    mov ax,0Eh
    push ax
    mov cx,5Ch
    push cx
    call mf480
    add sp,4h
    mov ax,0Eh
    push ax
    mov cx,5Dh
    push cx
    call mf490
    add sp,4h
    mov ax,0Eh
    push ax
    mov ax,5Eh
    push ax
    call mf4a0
    jmp near ptr lbl4Db
lbl4A8f:
    mov byte ptr ds:[309h],0h
lbl4ADf:
    xor ax,ax
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
