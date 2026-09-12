_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi31:NEAR
    EXTRN mi44:NEAR
    EXTRN mi46:NEAR
    EXTRN mf54:FAR
    EXTRN mf64:FAR
    EXTRN mf72:FAR
    EXTRN mf80:FAR
    EXTRN mi95:NEAR
    EXTRN mi97:NEAR
    EXTRN mf99:FAR
    EXTRN mi106:NEAR
    EXTRN mi108:NEAR
    EXTRN mf112:FAR
    EXTRN mf117:FAR
    EXTRN mf126:FAR
    EXTRN mf130:FAR
    EXTRN mf134:FAR
    EXTRN mf138:FAR
    EXTRN mf152:FAR
    EXTRN mi168:NEAR
    EXTRN mi170:NEAR
    EXTRN mf180:FAR
    EXTRN mf200:FAR
    EXTRN mf205:FAR
    EXTRN mf215:FAR
    EXTRN mf219:FAR
    EXTRN mf227:FAR
    EXTRN mf242:FAR
    EXTRN mf256:FAR
    EXTRN mi260:NEAR
    EXTRN mi265:NEAR
    EXTRN mf268:FAR
    EXTRN mf272:FAR
    EXTRN mf278:FAR
    EXTRN mf290:FAR
    EXTRN mf296:FAR
    EXTRN mf311:FAR
    EXTRN mf345:FAR
    EXTRN md351:NEAR
    EXTRN md352:NEAR
    EXTRN mf359:FAR
    EXTRN mf359:FAR
    EXTRN mf359:FAR
    EXTRN mf359:FAR
    EXTRN mf359:FAR
    EXTRN mf359:FAR
    EXTRN mf359:FAR
    EXTRN mf359:FAR
    EXTRN mf359:FAR
    EXTRN mf359:FAR
    EXTRN mf359:FAR
    EXTRN mf359:FAR
    EXTRN mf359:FAR
    EXTRN mf359:FAR
    EXTRN mf359:FAR
    EXTRN mf359:FAR
    EXTRN mf359:FAR
    EXTRN mf359:FAR
    EXTRN mf359:FAR
    EXTRN mf359:FAR
    EXTRN mf359:FAR
    EXTRN mf359:FAR
    EXTRN mf359:FAR
    EXTRN mf359:FAR
    EXTRN mf359:FAR
    EXTRN mf359:FAR
    EXTRN mf359:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,3Ah
    mov word ptr [bp-38h],5Bh
    mov word ptr [bp-36h],63h
    mov word ptr [bp-34h],69h
    mov word ptr [bp-32h],9Dh
    mov word ptr [bp-30h],0B8h
    mov word ptr [bp-2Eh],0BEh
    mov word ptr [bp-2Ch],0C7h
    mov word ptr [bp-2Ah],0CDh
    mov word ptr [bp-28h],0EDh
    mov word ptr [bp-26h],0FBh
    mov word ptr [bp-24h],107h
    mov word ptr [bp-22h],10Ch
    mov word ptr [bp-20h],112h
    mov word ptr [bp-1Eh],125h
    mov word ptr [bp-1Ch],139h
    mov word ptr [bp-1Ah],13Eh
    mov word ptr [bp-18h],14Fh
    mov word ptr [bp-16h],160h
    mov word ptr [bp-14h],162h
    mov word ptr [bp-12h],166h
    mov word ptr [bp-10h],169h
    mov word ptr [bp-0Eh],170h
    mov word ptr [bp-0Ch],174h
    mov word ptr [bp-0Ah],178h
    mov word ptr [bp-8h],17Ah
    mov word ptr [bp-6h],17Ch
    mov word ptr [bp-4h],17Fh
    mov ax,word ptr [bp+6h]
    cmp ax, offset mi31
    jnz short lbl98f
    jmp near ptr lbl396f
lbl98f:
    jna short lbl9Df
    jmp near ptr lbl3EEf
lbl9Df:
    sub al,4h
    jz short lblACf
    sub al,2h
    jnz short lblA8f
    jmp near ptr lbl1E4f
lblA8f:
    jmp near ptr lbl3EEf
    nop
lblACf:
    mov ax,word ptr ds:[6A06h]
    sub ax, offset mi44
    jz short lblC0f
    sub ax, offset mi46
    jnz short lblBCf
    jmp near ptr lbl1C8f
lblBCf:
    jmp near ptr lbl3EEf
    nop
lblC0f:
    mov ax,1h
    push ax
    push word ptr ds:[6A04h]
    call mf54
    add sp,4h
    or ax,ax
    jnz short lblFEf
    mov ax,2B8Dh
    push ds
    push ax
    push word ptr ds:[6A04h]
    mov ax,52h
    push ax
    call mf64
    add sp,8h
    push dx
    push ax
    mov ax,0Eh
lblEEb:
    mov dx,0F006h
    push dx
lblF2b:
    push ax
    call mf72
    add sp,8h
    jmp near ptr lbl19Cf
lblFEf:
    cmp word ptr ds:[256h],1AAh
    jnz short lbl11Ef
    push word ptr ds:[6A02h]
    mov ax,11h
    push ax
    call mf80
    add sp,4h
    push dx
    push ax
    mov ax,0Fh
    jmp short lblEEb
    nop
lbl11Ef:
    cmp word ptr ds:[256h],1F0h
    jnz short lbl12Cf
    mov ax,10h
    jmp near ptr lbl1BBf
lbl12Cf:
    mov ax,word ptr ds:[6A04h]
    cmp ax,91h
    jz short lbl176f
    jg short lbl14Cf
    sub ax, offset mi95
    jz short lbl15Ef
    sub ax, offset mi97
    jz short lbl16Af
lbl140b:
    call mf99
    push ax
    mov ax,15Bh
    jmp short lbl193f
    nop
lbl14Cf:
    sub ax,0F1h
    jz short lbl1A2f
    sub ax, offset mi106
    jz short lbl1AEf
    sub ax, offset mi108
    jz short lbl1B8f
    jmp short lbl140b
    nop
lbl15Ef:
    call mf112
    push ax
    mov ax,181h
    jmp short lbl193f
    nop
lbl16Af:
    call mf117
    push ax
    mov ax,159h
    jmp short lbl193f
    nop
lbl176f:
    mov ax,1h
    push ax
    mov ax,91h
    push ax
    call mf126
    add sp,4h
    or ax,ax
    jnz short lbl19Cf
    call mf130
    push ax
    mov ax,182h
lbl193b:
lbl193f:
    push ax
    call mf134
lbl199b:
    add sp,4h
lbl19Cb:
lbl19Cf:
    mov ax,1h
    jmp near ptr lbl3F0f
lbl1A2f:
    call mf138
    push ax
    mov ax,15Ah
    jmp short lbl193b
    nop
lbl1AEf:
    mov ax,5A03h
    push ax
    mov ax,158h
    jmp short lbl193b
    nop
lbl1B8f:
    mov ax,11h
lbl1BBb:
lbl1BBf:
    mov dx,0F006h
    push dx
    push ax
    call mf152
    jmp short lbl199b
    nop
lbl1C8f:
    mov ax,word ptr ds:[6A04h]
    sub ax,88h
    jnl short lbl1D3f
    jmp near ptr lbl3EEf
lbl1D3f:
    jno short lbl1D8f
    jmp near ptr lbl3EEf
lbl1D8f:
    dec ax
    jng short lbl1DEf
    jmp near ptr lbl3EEf
lbl1DEf:
    mov ax,12h
    jmp short lbl1BBb
    nop
lbl1E4f:
    mov ax,word ptr ds:[6A06h]
    sub ax, offset mi168
    jz short lbl1F8f
    sub ax, offset mi170
    jnz short lbl1F4f
    jmp near ptr lbl2DCf
lbl1F4f:
    jmp near ptr lbl3EEf
    nop
lbl1F8f:
    cmp word ptr ds:[256h],1AAh
    jnz short lbl218f
    push word ptr ds:[6A04h]
    mov ax,11h
    push ax
    call mf180
    add sp,4h
    push dx
    push ax
    mov ax,5h
    jmp near ptr lblEEb
lbl218f:
    cmp word ptr ds:[256h],0EDh
    jnz short lbl25Ef
    cmp byte ptr ds:[321h],0h
    jz short lbl25Ef
    cmp byte ptr ds:[32Eh],0h
    jnz short lbl234f
    mov ax,6h
    jmp short lbl1BBb
    nop
lbl234f:
    mov byte ptr ds:[1D00h],0h
    mov ax,9ACh
    push ax
    mov ax,14Bh
    push ax
    call mf200
    add sp,4h
    mov word ptr ds:[2A8h],0Bh
    mov ax,5Ah
    push ax
    call mf205
    add sp,2h
    jmp near ptr lbl19Cb
lbl25Ef:
    cmp word ptr ds:[256h],1F0h
    jnz short lbl26Cf
    mov ax,7h
    jmp near ptr lbl1BBb
lbl26Cf:
    push word ptr ds:[256h]
    mov ax,2h
    push ax
    call mf215
    add sp,4h
    push dx
    push ax
    call mf219
    add sp,4h
    push dx
    push ax
    mov ax,0Ah
    push ax
    mov ax,5h
    push ax
    call mf227
    add sp,4h
    or ax,ax
    jz short lbl2A2f
    mov ax,9h
    jmp short lbl2A5f
    nop
lbl2A2f:
    mov ax,0Ah
lbl2A5f:
    mov dx,0F006h
    push dx
    push ax
    mov ax,0Ah
    push ax
    mov ax,5h
    push ax
    call mf242
    add sp,4h
    or ax,ax
    jz short lbl2C4f
    mov ax,2B82h
    jmp short lbl2C7f
    nop
lbl2C4f:
    mov ax,2B87h
lbl2C7f:
    push ds
    push ax
    mov ax,8h
    mov dx,0F006h
    push dx
    push ax
    call mf256
    add sp,10h
    jmp near ptr lbl19Cb
lbl2DCf:
    mov ax,word ptr ds:[256h]
    sub ax, offset mi260
    jz short lbl362f
    sub ax,14Fh
    jnz short lbl2ECf
    jmp near ptr lbl38Af
lbl2ECf:
    sub ax, offset mi265
    jnz short lbl2F4f
    jmp near ptr lbl390f
lbl2F4f:
    call mf268
    push ax
    mov ax,63h
    push ax
    call mf272
    add sp,4h
    mov ax,1h
    push ax
    mov ax,92h
    push ax
    call mf278
    add sp,4h
    or ax,ax
    jz short lbl336f
    cmp byte ptr ds:[337h],0h
    jnz short lbl336f
    mov byte ptr ds:[337h],1h
    xor ax,ax
    push ax
    push ax
    mov ax,8h
    push ax
    call mf290
    add sp,6h
lbl336f:
    mov ax,1h
    push ax
    mov ax,0FAh
    push ax
    call mf296
    add sp,4h
    or ax,ax
    jnz short lbl34Df
    jmp near ptr lbl19Cb
lbl34Df:
    cmp byte ptr ds:[339h],0h
    jz short lbl357f
    jmp near ptr lbl19Cb
lbl357f:
    mov byte ptr ds:[339h],1h
    mov ax,0Dh
    jmp near ptr lbl1BBb
lbl362f:
    mov ax,0Eh
    push ax
    mov ax,5Dh
    push ax
    call mf311
    add sp,4h
    or ax,ax
    jnz short lbl380f
    mov ax,5A03h
    push ax
    mov ax,112h
    jmp near ptr lbl193b
lbl380f:
    mov ax,5A03h
    push ax
    mov ax,11Eh
    jmp near ptr lbl193b
lbl38Af:
    mov ax,0Bh
    jmp near ptr lbl1BBb
lbl390f:
    mov ax,0Ch
    jmp near ptr lbl1BBb
lbl396f:
    cmp word ptr ds:[6A22h],5Ah
    jz short lbl3EEf
    cmp word ptr ds:[256h],0CDh
    jnz short lbl3ACf
    mov ax,4h
    jmp near ptr lbl1BBb
    nop
lbl3ACf:
    lea ax,word ptr [bp-38h]
    mov word ptr [bp-3Ah],ax
lbl3B2b:
    mov ax,word ptr ds:[256h]
    mov bx,word ptr [bp-3Ah]
    cmp word ptr [bx],ax
    jnz short lbl3BFf
    jmp near ptr lbl19Cb
lbl3BFf:
    lea ax,word ptr [bp-2h]
    add word ptr [bp-3Ah],2h
    cmp word ptr [bp-3Ah],ax
    jc short lbl3B2b
    call mf345
    mov bx,ax
    and bx,0Fh
    add bx,bx
    add bx,bx
    mov es, ds:[5ACAh]
    push word ptr es:[bx+md351]
    push word ptr es:[bx+md352]
    mov ax,2B78h
    push ds
    jmp near ptr lblF2b
lbl3EEf:
    xor ax,ax
lbl3F0f:
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
