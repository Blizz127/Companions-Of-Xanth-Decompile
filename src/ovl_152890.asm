_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi3:NEAR
    EXTRN mi12:NEAR
    EXTRN mf18:FAR
    EXTRN mf25:FAR
    EXTRN mf33:FAR
    EXTRN mi38:NEAR
    EXTRN mf50:FAR
    EXTRN mf57:FAR
    EXTRN mf64:FAR
    EXTRN mf74:FAR
    EXTRN mf82:FAR
    EXTRN mf87:FAR
    EXTRN mf95:FAR
    EXTRN mf106:FAR
    EXTRN mf113:FAR
    EXTRN mf124:FAR
    EXTRN mf131:FAR
    EXTRN mf139:FAR
    EXTRN mf146:FAR
    EXTRN mf152:FAR
    EXTRN mi159:NEAR
    EXTRN mi187:NEAR
    EXTRN mi190:NEAR
    EXTRN mi193:NEAR
    EXTRN mi196:NEAR
    EXTRN mi199:NEAR
    EXTRN mf205:FAR
    EXTRN mf213:FAR
    EXTRN mi222:NEAR
    EXTRN mi229:NEAR
    EXTRN mi241:NEAR
    EXTRN mi244:NEAR
    EXTRN mi247:NEAR
    EXTRN mi250:NEAR
    EXTRN mi258:NEAR
    EXTRN mi261:NEAR
    EXTRN mi264:NEAR
    EXTRN mi267:NEAR
    EXTRN mf277:FAR
    EXTRN mf286:FAR
    EXTRN mf297:FAR
    EXTRN mf305:FAR
    EXTRN mf312:FAR
    EXTRN mf316:FAR
    EXTRN mf322:FAR
    EXTRN mf326:FAR
    EXTRN mf333:FAR
    EXTRN mf342:FAR
    EXTRN mf349:FAR
    EXTRN mf359:FAR
    EXTRN mf368:FAR
    EXTRN mf377:FAR
    EXTRN mf393:FAR
    EXTRN mf401:FAR
    EXTRN mf407:FAR
    EXTRN mf416:FAR
    EXTRN mf425:FAR
    EXTRN mf444:FAR
    EXTRN mf451:FAR
    EXTRN mf460:FAR
    EXTRN mf475:FAR
    EXTRN mf484:FAR
    EXTRN mf493:FAR
    EXTRN mf493:FAR
    EXTRN mf493:FAR
    EXTRN mf493:FAR
    EXTRN mf493:FAR
    EXTRN mf493:FAR
    EXTRN mf493:FAR
    EXTRN mf493:FAR
    EXTRN mf493:FAR
    EXTRN mf493:FAR
    EXTRN mf493:FAR
    EXTRN mf493:FAR
    EXTRN mf493:FAR
    EXTRN mf493:FAR
    EXTRN mf493:FAR
    EXTRN mf493:FAR
    EXTRN mf493:FAR
    EXTRN mf493:FAR
    EXTRN mf493:FAR
    EXTRN mf493:FAR
    EXTRN mf493:FAR
    EXTRN mf493:FAR
    EXTRN mf493:FAR
    EXTRN mf493:FAR
    EXTRN mf493:FAR
    EXTRN mf493:FAR
    EXTRN mf493:FAR
    EXTRN mf493:FAR
    EXTRN mf493:FAR
    EXTRN mf493:FAR
    EXTRN mf493:FAR
    EXTRN mf493:FAR
    EXTRN mf493:FAR
    EXTRN mf493:FAR
    EXTRN mf493:FAR
    EXTRN mf493:FAR
    EXTRN mf493:FAR
    EXTRN mf493:FAR
    EXTRN mf493:FAR
    EXTRN mf493:FAR
    EXTRN mf493:FAR
    EXTRN mf493:FAR
    EXTRN mf493:FAR
mnem_unit:
    push bp
    mov bp,sp
    mov ax,word ptr [bp+6h]
    sub ax, offset mi3
    jz short lbl16f
    dec ax
    dec ax
    jnz short lbl12f
    jmp near ptr lbl18Ef
lbl12f:
    jmp near ptr lbl4E4f
    nop
lbl16f:
    mov ax,word ptr ds:[6A06h]
    sub ax, offset mi12
    jz short lbl21f
    jmp near ptr lbl4E4f
lbl21f:
    mov ax,1h
    push ax
    push word ptr ds:[6A04h]
    call mf18
    mov sp,bp
    or ax,ax
    jnz short lbl5Af
    push word ptr ds:[6A04h]
    mov ax,23h
    push ax
    call mf25
    mov sp,bp
    push dx
    push ax
    mov ax,1Eh
lbl48b:
    mov dx,0F008h
    push dx
    push ax
    call mf33
    mov sp,bp
lbl54b:
    mov ax,1h
    jmp near ptr lbl4E6f
lbl5Af:
    mov ax,word ptr ds:[6A04h]
    sub ax, offset mi38
    jnz short lbl65f
    jmp near ptr lbl4E4f
lbl65f:
    dec ax
    dec ax
    jz short lblACf
    sub ax,8Ch
    jnz short lbl71f
    jmp near ptr lblF8f
lbl71f:
    push word ptr ds:[6A02h]
    mov ax,22h
    push ax
    call mf50
    mov sp,bp
    push dx
    push ax
    push word ptr ds:[6A04h]
    mov ax,6h
    push ax
    call mf57
    add sp,4h
    push dx
    push ax
    push word ptr ds:[6A04h]
    mov ax,2h
    push ax
    call mf64
    add sp,4h
    push dx
    push ax
    mov ax,23h
    jmp short lbl48b
    nop
lblACf:
    push word ptr ds:[6A04h]
    mov ax,12h
    push ax
    call mf74
    mov sp,bp
    push dx
    push ax
    mov ax,22h
    mov dx,0F008h
    push dx
    push ax
    call mf82
    mov sp,bp
    mov ax,75h
    push ax
    push word ptr ds:[6A04h]
    call mf87
    mov sp,bp
    or ax,ax
    jz short lblEEf
    mov ax,116h
    push ax
    mov ax,75h
    push ax
    call mf95
    mov sp,bp
lblEEf:
    xor ax,ax
    push ax
    push ax
    mov ax,78h
    push ax
    jmp short lbl16Bf
lblF8f:
    mov ax,1h
    push ax
    push word ptr ds:[6A04h]
    call mf106
    add sp,4h
    or ax,ax
    jnz short lbl124f
    push word ptr ds:[6A04h]
    mov ax,22h
    push ax
    call mf113
    add sp,4h
    push dx
    push ax
    mov ax,1Fh
    jmp near ptr lbl48b
lbl124f:
    cmp word ptr ds:[256h],102h
    jnz short lbl176f
    push word ptr ds:[6A02h]
    mov ax,22h
    push ax
    call mf124
    add sp,4h
    push dx
    push ax
    push word ptr ds:[6A04h]
    mov ax,2h
    push ax
    call mf131
    add sp,4h
    push dx
    push ax
    mov ax,20h
    mov dx,0F008h
    push dx
    push ax
    call mf139
    add sp,0Ch
    xor ax,ax
    push ax
    mov ax,102h
    push ax
    push word ptr ds:[6A04h]
lbl16Bf:
    call mf146
    add sp,6h
    jmp near ptr lbl54b
lbl176f:
    push word ptr ds:[6A04h]
    mov ax,12h
    push ax
    call mf152
    add sp,4h
    push dx
    push ax
    mov ax,21h
    jmp near ptr lbl212f
lbl18Ef:
    mov ax,word ptr ds:[6A06h]
    cmp ax, offset mi159
    jnz short lbl199f
    jmp near ptr lbl4CCf
lbl199f:
    jna short lbl19Ef
    jmp near ptr lbl4E4f
lbl19Ef:
    sub al,8h
    jz short lbl1B8f
    sub al,0Bh
    jz short lbl1BEf
    sub al,16h
    jnz short lbl1ADf
    jmp near ptr lbl4AEf
lbl1ADf:
    sub al,1Bh
    jnz short lbl1B4f
    jmp near ptr lbl4B4f
lbl1B4f:
    jmp near ptr lbl4E4f
    nop
lbl1B8f:
    mov ax,1Dh
    jmp near ptr lbl467f
lbl1BEf:
    mov ax,word ptr ds:[256h]
    cmp ax,0F8h
    jnz short lbl1C9f
    jmp near ptr lbl3BCf
lbl1C9f:
    jg short lbl24Af
    cmp ax,9Ah
    jnz short lbl1D3f
    jmp near ptr lbl2E8f
lbl1D3f:
    jg short lbl222f
    sub ax, offset mi187
    jnz short lbl1DDf
    jmp near ptr lbl2ACf
lbl1DDf:
    sub ax, offset mi190
    jnz short lbl1E5f
    jmp near ptr lbl2B2f
lbl1E5f:
    sub ax, offset mi193
    jnz short lbl1EDf
    jmp near ptr lbl2CAf
lbl1EDf:
    sub ax, offset mi196
    jnz short lbl1F5f
    jmp near ptr lbl2E2f
lbl1F5f:
    sub ax, offset mi199
    jnz short lbl1FDf
    jmp near ptr lbl2E8f
lbl1FDb:
lbl1FDf:
    push word ptr ds:[6A04h]
    mov ax,3h
    push ax
    call mf205
    add sp,4h
    push dx
    push ax
    mov ax,19h
lbl212f:
    mov dx,0F008h
    push dx
    push ax
    call mf213
    add sp,8h
    jmp near ptr lbl54b
lbl222f:
    sub ax,9Ch
    jnz short lbl22Af
    jmp near ptr lbl2E8f
lbl22Af:
    dec ax
    jnz short lbl230f
    jmp near ptr lbl32Ef
lbl230f:
    sub ax, offset mi222
    jnz short lbl238f
    jmp near ptr lbl362f
lbl238f:
    dec ax
    dec ax
    jnz short lbl23Ff
    jmp near ptr lbl38Cf
lbl23Ff:
    sub ax, offset mi229
    jnz short lbl247f
    jmp near ptr lbl3A4f
lbl247f:
    jmp short lbl1FDb
    nop
lbl24Af:
    cmp ax,160h
    jnz short lbl252f
    jmp near ptr lbl458f
lbl252f:
    jg short lbl280f
    sub ax,102h
    jnz short lbl25Cf
    jmp near ptr lbl3D4f
lbl25Cf:
    sub ax, offset mi241
    jnz short lbl264f
    jmp near ptr lbl40Af
lbl264f:
    sub ax, offset mi244
    jnz short lbl26Cf
    jmp near ptr lbl422f
lbl26Cf:
    sub ax, offset mi247
    jnz short lbl274f
    jmp near ptr lbl43Af
lbl274f:
    sub ax, offset mi250
    jnz short lbl27Cf
    jmp near ptr lbl452f
lbl27Cf:
    jmp near ptr lbl1FDb
    nop
lbl280f:
    sub ax,162h
    jnz short lbl288f
    jmp near ptr lbl45Ef
lbl288f:
    sub ax, offset mi258
    jnz short lbl290f
    jmp near ptr lbl464f
lbl290f:
    sub ax, offset mi261
    jnz short lbl298f
    jmp near ptr lbl478f
lbl298f:
    sub ax, offset mi264
    jnz short lbl2A0f
    jmp near ptr lbl490f
lbl2A0f:
    sub ax, offset mi267
    jnz short lbl2A8f
    jmp near ptr lbl4A8f
lbl2A8f:
    jmp near ptr lbl1FDb
    nop
lbl2ACf:
    mov ax,4h
    jmp near ptr lbl467f
lbl2B2f:
    push word ptr ds:[6A04h]
    mov ax,1h
    push ax
    call mf277
    add sp,4h
    push dx
    push ax
    mov ax,5h
    jmp near ptr lbl48b
lbl2CAf:
    push word ptr ds:[6A04h]
    mov ax,12h
    push ax
    call mf286
    add sp,4h
    push dx
    push ax
    mov ax,6h
    jmp near ptr lbl48b
lbl2E2f:
    mov ax,7h
    jmp near ptr lbl467f
lbl2E8f:
    push word ptr ds:[6A04h]
    mov ax,12h
    push ax
    call mf297
    add sp,4h
    push dx
    push ax
    mov ax,8h
    mov dx,0F008h
    push dx
    push ax
    call mf305
    add sp,8h
    cmp word ptr ds:[256h],98h
    jz short lbl31Ff
    mov ax,2A71h
    push ds
    push ax
    call mf312
    add sp,4h
lbl31Ff:
    mov ax,2Eh
    push ax
    call mf316
    add sp,2h
    jmp near ptr lbl54b
lbl32Ef:
    push word ptr ds:[256h]
    mov ax,1h
    push ax
    call mf322
    add sp,4h
    push dx
    push ax
    call mf326
    add sp,4h
    push dx
    push ax
    push word ptr ds:[6A04h]
    mov ax,12h
    push ax
    call mf333
    add sp,4h
    push dx
    push ax
    mov ax,9h
    jmp near ptr lbl3FAf
lbl362f:
    push word ptr ds:[6A04h]
    mov ax,1h
    push ax
    call mf342
    add sp,4h
    push dx
    push ax
    push word ptr ds:[6A04h]
    mov ax,12h
    push ax
    call mf349
    add sp,4h
    push dx
    push ax
    mov ax,0Ah
    jmp short lbl3FAf
    nop
lbl38Cf:
    push word ptr ds:[6A04h]
    mov ax,12h
    push ax
    call mf359
    add sp,4h
    push dx
    push ax
    mov ax,0Bh
    jmp near ptr lbl48b
lbl3A4f:
    push word ptr ds:[6A04h]
    mov ax,12h
    push ax
    call mf368
    add sp,4h
    push dx
    push ax
    mov ax,0Ch
    jmp near ptr lbl48b
lbl3BCf:
    push word ptr ds:[6A04h]
    mov ax,12h
    push ax
    call mf377
    add sp,4h
    push dx
    push ax
    mov ax,0Dh
    jmp near ptr lbl48b
lbl3D4f:
    cmp byte ptr ds:[329h],0h
    jz short lbl3E0f
    mov ax,2A80h
    jmp short lbl3E3f
lbl3E0f:
    mov ax,2A8Eh
lbl3E3f:
    push ds
    push ax
    push word ptr ds:[6A04h]
    mov ax,12h
    push ax
    call mf393
    add sp,4h
    push dx
    push ax
    mov ax,0Eh
lbl3FAf:
    mov dx,0F008h
    push dx
    push ax
    call mf401
    add sp,0Ch
    jmp near ptr lbl54b
lbl40Af:
    push word ptr ds:[6A04h]
    mov ax,2h
    push ax
    call mf407
    add sp,4h
    push dx
    push ax
    mov ax,0Fh
    jmp near ptr lbl48b
lbl422f:
    push word ptr ds:[6A04h]
    mov ax,12h
    push ax
    call mf416
    add sp,4h
    push dx
    push ax
    mov ax,10h
    jmp near ptr lbl48b
lbl43Af:
    push word ptr ds:[6A04h]
    mov ax,12h
    push ax
    call mf425
    add sp,4h
    push dx
    push ax
    mov ax,11h
    jmp near ptr lbl48b
lbl452f:
    mov ax,12h
    jmp short lbl467f
    nop
lbl458f:
    mov ax,13h
    jmp short lbl467f
    nop
lbl45Ef:
    mov ax,14h
    jmp short lbl467f
    nop
lbl464f:
    mov ax,15h
lbl467b:
lbl467f:
    mov dx,0F008h
    push dx
    push ax
    call mf444
    add sp,4h
    jmp near ptr lbl54b
    nop
lbl478f:
    push word ptr ds:[6A04h]
    mov ax,12h
    push ax
    call mf451
    add sp,4h
    push dx
    push ax
    mov ax,16h
    jmp near ptr lbl48b
lbl490f:
    push word ptr ds:[6A04h]
    mov ax,12h
    push ax
    call mf460
    add sp,4h
    push dx
    push ax
    mov ax,17h
    jmp near ptr lbl48b
lbl4A8f:
    mov ax,18h
    jmp short lbl467b
    nop
lbl4AEf:
    mov ax,1Ah
    jmp short lbl467b
    nop
lbl4B4f:
    push word ptr ds:[6A04h]
    mov ax,1h
    push ax
    call mf475
    add sp,4h
    push dx
    push ax
    mov ax,1Ch
    jmp near ptr lbl48b
lbl4CCf:
    push word ptr ds:[6A04h]
    mov ax,2h
    push ax
    call mf484
    add sp,4h
    push dx
    push ax
    mov ax,1Bh
    jmp near ptr lbl48b
lbl4E4f:
    xor ax,ax
lbl4E6f:
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
