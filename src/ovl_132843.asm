_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi4:NEAR
    EXTRN mi12:NEAR
    EXTRN mf32:FAR
    EXTRN mf40:FAR
    EXTRN mf56:FAR
    EXTRN mf65:FAR
    EXTRN mf77:FAR
    EXTRN mf86:FAR
    EXTRN mf91:FAR
    EXTRN mf100:FAR
    EXTRN mf108:FAR
    EXTRN mf112:FAR
    EXTRN mi119:NEAR
    EXTRN mi123:NEAR
    EXTRN mf140:FAR
    EXTRN mi158:NEAR
    EXTRN mi169:NEAR
    EXTRN mi174:NEAR
    EXTRN mf183:FAR
    EXTRN mf190:FAR
    EXTRN mf198:FAR
    EXTRN mi207:NEAR
    EXTRN mf215:FAR
    EXTRN mf229:FAR
    EXTRN mf237:FAR
    EXTRN mf247:FAR
    EXTRN mf256:FAR
    EXTRN mf270:FAR
    EXTRN mf280:FAR
    EXTRN mf284:FAR
    EXTRN mf291:FAR
    EXTRN mf298:FAR
    EXTRN mf306:FAR
    EXTRN mf310:FAR
    EXTRN mf318:FAR
    EXTRN mf324:FAR
    EXTRN mf336:FAR
    EXTRN mf354:FAR
    EXTRN mf361:FAR
    EXTRN mf369:FAR
    EXTRN mf374:FAR
    EXTRN mf384:FAR
    EXTRN mf391:FAR
    EXTRN mf398:FAR
    EXTRN mf407:FAR
    EXTRN mf420:FAR
    EXTRN mf428:FAR
    EXTRN mf434:FAR
    EXTRN mf439:FAR
    EXTRN mf446:FAR
    EXTRN mf454:FAR
    EXTRN mf461:FAR
    EXTRN mi469:NEAR
    EXTRN mf475:FAR
    EXTRN mf481:FAR
    EXTRN mf486:FAR
    EXTRN mf495:FAR
    EXTRN mf500:FAR
    EXTRN mf507:FAR
    EXTRN mf514:FAR
    EXTRN mf518:FAR
    EXTRN mf525:FAR
    EXTRN mf532:FAR
    EXTRN mf540:FAR
    EXTRN mf548:FAR
    EXTRN mf555:FAR
    EXTRN mf563:FAR
    EXTRN mf570:FAR
    EXTRN mf582:FAR
    EXTRN mf592:FAR
    EXTRN mf600:FAR
    EXTRN mf607:FAR
    EXTRN mf613:FAR
    EXTRN mf619:FAR
    EXTRN mf621:FAR
    EXTRN mf628:FAR
    EXTRN mf634:FAR
    EXTRN mf642:FAR
    EXTRN mf650:FAR
    EXTRN mf673:FAR
    EXTRN mi679:NEAR
    EXTRN mf687:FAR
    EXTRN mf694:FAR
    EXTRN mf702:FAR
    EXTRN mf721:FAR
    EXTRN mf728:FAR
    EXTRN mf736:FAR
    EXTRN mf745:FAR
    EXTRN mi759:NEAR
    EXTRN mf804:FAR
    EXTRN mf811:FAR
    EXTRN mf870:FAR
    EXTRN mf877:FAR
    EXTRN mi886:NEAR
    EXTRN mf902:FAR
    EXTRN mf912:FAR
    EXTRN mi915:NEAR
    EXTRN mf935:FAR
    EXTRN mf966:FAR
    EXTRN mf988:FAR
    EXTRN mf997:FAR
    EXTRN mf1009:FAR
    EXTRN mf1015:FAR
    EXTRN mf1023:FAR
    EXTRN mf1027:FAR
    EXTRN mf1032:FAR
    EXTRN mf1037:FAR
    EXTRN mf1046:FAR
    EXTRN mf1053:FAR
    EXTRN mf1059:FAR
    EXTRN mf1069:FAR
    EXTRN mf1073:FAR
    EXTRN mf1079:FAR
    EXTRN mf1086:FAR
    EXTRN mf1102:FAR
    EXTRN mf1110:FAR
    EXTRN mf1120:FAR
    EXTRN mf1132:FAR
    EXTRN mf1139:FAR
    EXTRN mf1146:FAR
    EXTRN mf1154:FAR
    EXTRN mf1162:FAR
    EXTRN mf1169:FAR
    EXTRN mf1173:FAR
    EXTRN mf1188:FAR
    EXTRN mf1201:FAR
    EXTRN mf1206:FAR
    EXTRN mf1206:FAR
    EXTRN mf1206:FAR
    EXTRN mf1206:FAR
    EXTRN mf1206:FAR
    EXTRN mf1206:FAR
    EXTRN mf1206:FAR
    EXTRN mf1206:FAR
    EXTRN mf1206:FAR
    EXTRN mf1206:FAR
    EXTRN mf1206:FAR
    EXTRN mf1206:FAR
    EXTRN mf1206:FAR
    EXTRN mf1206:FAR
    EXTRN mf1206:FAR
    EXTRN mf1206:FAR
    EXTRN mf1206:FAR
    EXTRN mf1206:FAR
    EXTRN mf1206:FAR
    EXTRN mf1206:FAR
    EXTRN mf1206:FAR
    EXTRN mf1206:FAR
    EXTRN mf1206:FAR
    EXTRN mf1206:FAR
    EXTRN mf1206:FAR
    EXTRN mf1206:FAR
    EXTRN mf1206:FAR
    EXTRN mf1206:FAR
    EXTRN mf1206:FAR
    EXTRN mf1206:FAR
    EXTRN mf1206:FAR
    EXTRN mf1206:FAR
    EXTRN mf1206:FAR
    EXTRN mf1206:FAR
    EXTRN mf1206:FAR
    EXTRN mf1206:FAR
    EXTRN mf1206:FAR
    EXTRN mf1206:FAR
    EXTRN mf1206:FAR
    EXTRN mf1206:FAR
    EXTRN mf1206:FAR
    EXTRN mf1206:FAR
    EXTRN mf1206:FAR
    EXTRN mf1206:FAR
    EXTRN mf1206:FAR
    EXTRN mf1206:FAR
    EXTRN mf1206:FAR
    EXTRN mf1206:FAR
    EXTRN mf1206:FAR
    EXTRN mf1206:FAR
    EXTRN mf1206:FAR
    EXTRN mf1206:FAR
    EXTRN mf1206:FAR
    EXTRN mf1206:FAR
    EXTRN mf1206:FAR
    EXTRN mf1206:FAR
    EXTRN mf1206:FAR
    EXTRN mf1206:FAR
    EXTRN mf1206:FAR
    EXTRN mf1206:FAR
    EXTRN mf1206:FAR
    EXTRN mf1206:FAR
    EXTRN mf1206:FAR
    EXTRN mf1206:FAR
    EXTRN mf1206:FAR
    EXTRN mf1206:FAR
    EXTRN mf1206:FAR
    EXTRN mf1206:FAR
    EXTRN mf1206:FAR
    EXTRN mf1206:FAR
    EXTRN mf1206:FAR
    EXTRN mf1206:FAR
    EXTRN mf1206:FAR
    EXTRN mf1206:FAR
    EXTRN mf1206:FAR
    EXTRN mf1206:FAR
    EXTRN mf1206:FAR
    EXTRN mf1206:FAR
    EXTRN mf1206:FAR
    EXTRN mf1206:FAR
    EXTRN mf1206:FAR
    EXTRN mf1206:FAR
    EXTRN mf1206:FAR
    EXTRN mf1206:FAR
    EXTRN mf1206:FAR
    EXTRN mf1206:FAR
    EXTRN mf1206:FAR
    EXTRN mf1206:FAR
    EXTRN mf1206:FAR
    EXTRN mf1206:FAR
    EXTRN mf1206:FAR
    EXTRN mf1206:FAR
    EXTRN mf1206:FAR
    EXTRN mf1206:FAR
    EXTRN mf1206:FAR
    EXTRN mf1206:FAR
    EXTRN mf1206:FAR
    EXTRN mf1206:FAR
    EXTRN mf1206:FAR
    EXTRN mf1206:FAR
    EXTRN mf1206:FAR
    EXTRN mf1206:FAR
    EXTRN mf1206:FAR
    EXTRN mf1206:FAR
    EXTRN mf1206:FAR
    EXTRN mf1206:FAR
    EXTRN mf1206:FAR
    EXTRN mf1206:FAR
    EXTRN mf1206:FAR
    EXTRN mf1206:FAR
    EXTRN mf1206:FAR
    EXTRN mf1206:FAR
    EXTRN mf1206:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,14h
    mov ax,word ptr [bp+6h]
    sub ax, offset mi4
    jz short lbl18f
    dec ax
    dec ax
    jnz short lbl15f
    jmp near ptr lbl7CEf
lbl15f:
    jmp near ptr lblC82f
lbl18f:
    mov ax,word ptr ds:[6A06h]
    cmp ax, offset mi12
    jnz short lbl23f
    jmp near ptr lbl6F0f
lbl23f:
    jna short lbl28f
    jmp near ptr lblC82f
lbl28f:
    sub al,9h
    jz short lbl38f
    sub al,2Ah
    jz short lbl5Af
    sub al,5h
    jz short lbl5Af
    jmp near ptr lblC82f
    nop
lbl38f:
    cmp word ptr ds:[6A04h],0B1h
    jz short lbl43f
    jmp near ptr lblC82f
lbl43f:
    push word ptr ds:[6A02h]
    push word ptr ds:[6A04h]
lbl4Bb:
    mov ax,38h
    push ax
    call mf32
    add sp,6h
    jmp near ptr lblC84f
lbl5Af:
    cmp byte ptr ds:[2F2h],0h
    jnz short lblE0f
    push word ptr ds:[6A04h]
    mov ax,2h
    push ax
    call mf40
    add sp,4h
    push dx
    push ax
    cmp word ptr ds:[6A06h],38h
    jnz short lbl80f
    mov ax,2880h
    jmp short lbl83f
    nop
lbl80f:
    mov ax,2883h
lbl83f:
    push ds
    push ax
    mov ax,32h
    mov dx,0F00Fh
    push dx
    push ax
    call mf56
    add sp,0Ch
    cmp word ptr ds:[256h],9Ah
    jnz short lblB8f
    xor ax,ax
    push ax
    mov ax,9Ch
    push ax
    push word ptr ds:[6A02h]
    call mf65
    add sp,6h
    mov byte ptr ds:[278Ah],1h
    jmp short lblD8f
    nop
lblB8f:
    cmp word ptr ds:[256h],9Ch
    jnz short lblD8f
    xor ax,ax
    push ax
    mov ax,9Ah
    push ax
    push word ptr ds:[6A02h]
    call mf77
    add sp,6h
    mov byte ptr ds:[278Bh],1h
lblD8f:
    mov byte ptr ds:[278Ch],1h
    jmp near ptr lbl297f
lblE0f:
    mov ax,1h
    push ax
    mov ax,0BDh
    push ax
    call mf86
    add sp,4h
    or ax,ax
    jnz short lbl130f
    push word ptr ds:[6A04h]
    call mf91
    add sp,2h
    or al,al
    jz short lbl10Af
    mov ax,33h
    jmp near ptr lbl28Af
lbl10Af:
    push word ptr ds:[6A04h]
    mov ax,2h
    push ax
    call mf100
    add sp,4h
    push dx
    push ax
    mov ax,34h
lbl11Fb:
    mov dx,0F00Fh
    push dx
    push ax
    call mf108
    add sp,8h
    jmp near ptr lbl297f
    nop
lbl130f:
    call mf112
    or ax,ax
    jz short lbl140f
    mov ax,35h
    jmp near ptr lbl28Af
    nop
lbl140f:
    mov ax,word ptr ds:[6A04h]
    cmp ax, offset mi119
    jnz short lbl14Bf
    jmp near ptr lbl5E6f
lbl14Bf:
    jg short lbl192f
    cmp ax, offset mi123
    jnz short lbl155f
    jmp near ptr lbl360f
lbl155f:
    ja short lbl166f
    cmp al,6Fh
    jg short lbl182f
    cmp al,6Eh
    jl short lbl162f
    jmp near ptr lbl20Ef
lbl162f:
    sub al,17h
    jz short lbl1CEf
lbl166b:
lbl166f:
    mov ax,28FBh
    push ds
    push ax
    push word ptr ds:[6A04h]
    mov ax,52h
    push ax
    call mf140
    add sp,8h
    push dx
    push ax
    mov ax,4Ah
    jmp short lbl11Fb
lbl182f:
    sub al,75h
    jnz short lbl189f
    jmp near ptr lbl270f
lbl189f:
    dec al
    jnz short lbl190f
    jmp near ptr lbl29Ef
lbl190f:
    jmp short lbl166b
lbl192f:
    cmp ax,89h
    jg short lbl1B0f
    cmp ax,88h
    jl short lbl19Ff
    jmp near ptr lbl400f
lbl19Ff:
    sub ax, offset mi158
    jnz short lbl1A7f
    jmp near ptr lbl392f
lbl1A7f:
    dec ax
    jnz short lbl1ADf
    jmp near ptr lbl3FAf
lbl1ADf:
    jmp short lbl166b
    nop
lbl1B0f:
    sub ax,8Fh
    jnz short lbl1B8f
    jmp near ptr lbl47Cf
lbl1B8f:
    sub ax, offset mi169
    jl short lbl166b
    dec ax
    jg short lbl1C3f
    jmp near ptr lbl4CAf
lbl1C3f:
    sub ax, offset mi174
    jnz short lbl1CBf
    jmp near ptr lbl598f
lbl1CBf:
    jmp short lbl166b
    nop
lbl1CEf:
    mov ax,1h
    push ax
    mov ax,0BDh
    push ax
    call mf183
    add sp,4h
    or ax,ax
    jnz short lbl208f
    push word ptr ds:[6A02h]
    mov ax,22h
    push ax
    call mf190
    add sp,4h
    push dx
    push ax
    mov ax,3Eh
lbl1F7b:
    mov dx,0F00Fh
    push dx
    push ax
    call mf198
    add sp,8h
    jmp near ptr lbl659f
    nop
lbl208f:
    mov ax,3Fh
    jmp near ptr lbl4D8f
lbl20Ef:
    mov al,byte ptr ds:[6A14h]
    sub ah,ah
    inc ax
    cmp ax, offset mi207
    jng short lbl220f
    mov ax,40h
    jmp near ptr lbl4D8f
    nop
lbl220f:
    push word ptr ds:[6A04h]
    mov ax,2h
    push ax
    call mf215
    add sp,4h
    push dx
    push ax
    cmp word ptr ds:[6A04h],6Fh
    jnz short lbl23Ef
    mov ax,28BBh
    jmp short lbl241f
lbl23Ef:
    mov ax,28C1h
lbl241f:
    push ds
    push ax
    push word ptr ds:[6A02h]
    mov ax,2h
    push ax
    call mf229
    add sp,4h
    push dx
    push ax
    mov ax,41h
    mov dx,0F00Fh
    push dx
    push ax
    call mf237
    add sp,10h
    inc byte ptr ds:[6A14h]
    mov ax,28C4h
    jmp near ptr lbl64Ff
    nop
lbl270f:
    mov ax,75h
    push ax
    mov ax,78h
    push ax
    call mf247
    add sp,4h
    or ax,ax
    jz short lbl287f
    jmp near ptr lbl5E6f
lbl287f:
    mov ax,47h
lbl28Ab:
lbl28Af:
    mov dx,0F00Fh
    push dx
    push ax
    call mf256
lbl294b:
    add sp,4h
lbl297b:
lbl297f:
    mov ax,1h
    jmp near ptr lblC84f
    nop
lbl29Ef:
    cmp byte ptr ds:[6A13h],0h
    jz short lbl2ACf
    mov ax,3Ah
    jmp near ptr lbl4D8f
    nop
lbl2ACf:
    mov ax,75h
    push ax
    mov ax,76h
    push ax
    call mf270
    add sp,4h
    or ax,ax
    jz short lbl2C6f
    mov ax,3Bh
    jmp near ptr lbl4D8f
lbl2C6f:
    mov ax,3Ch
    mov dx,0F00Fh
    push dx
    push ax
    call mf280
    add sp,4h
    mov ax,8h
    push ax
    call mf284
    add sp,2h
    xor ax,ax
    push ax
    push ax
    mov ax,76h
    push ax
    call mf291
    add sp,6h
    cmp byte ptr ds:[343h],0h
    jz short lbl2FEf
    mov byte ptr ds:[343h],0h
lbl2FEf:
    mov ax,88h
    push ax
    call mf298
    add sp,2h
    cmp ax,146h
    jnz short lbl31Ff
    mov ax,122h
    push ax
    mov ax,88h
    push ax
    call mf306
    add sp,4h
lbl31Ff:
    mov ax,89h
    push ax
    call mf310
    add sp,2h
    cmp ax,146h
    jnz short lbl340f
    mov ax,122h
    push ax
    mov ax,89h
    push ax
    call mf318
    add sp,4h
lbl340f:
    mov ax,136h
    push ax
    mov ax,76h
    push ax
    call mf324
    add sp,4h
    mov word ptr ds:[2C6h],0h
    inc byte ptr ds:[6A13h]
    mov ax,28B1h
    jmp near ptr lbl64Ff
lbl360f:
    cmp byte ptr ds:[6A18h],0h
    jnz short lbl38Cf
    mov ax,1h
    push ax
    mov ax,78h
    push ax
    call mf336
    add sp,4h
    or ax,ax
    jz short lbl386f
    push word ptr ds:[6A02h]
    mov ax,78h
    push ax
    jmp near ptr lbl4Bb
lbl386f:
    mov ax,45h
    jmp near ptr lbl28Ab
lbl38Cf:
    mov ax,46h
    jmp near ptr lbl28Ab
lbl392f:
    mov ax,28D8h
    push ds
    push ax
    push word ptr ds:[6A04h]
    mov ax,44h
    push ax
    call mf354
    add sp,8h
    push dx
    push ax
    push word ptr ds:[6A04h]
    mov ax,2h
    push ax
    call mf361
    add sp,4h
    push dx
    push ax
    mov ax,43h
    mov dx,0F00Fh
    push dx
    push ax
    call mf369
    add sp,0Ch
    inc byte ptr ds:[6A16h]
    mov ax,7Eh
    push ax
    call mf374
    add sp,2h
    cmp ax,13Dh
    jnz short lbl3E4f
    inc byte ptr ds:[6A16h]
lbl3E4f:
    xor ax,ax
    push ax
    push ax
    mov ax,7Eh
    push ax
    call mf384
    add sp,6h
    mov ax,28DDh
    jmp near ptr lbl64Ff
lbl3FAf:
    mov ax,3Dh
    jmp near ptr lbl4D8f
lbl400f:
    push ax
    call mf391
    add sp,2h
    cmp ax,122h
    jnz short lbl426f
    push word ptr ds:[6A04h]
    mov ax,2h
    push ax
    call mf398
    add sp,4h
    push dx
    push ax
    mov ax,36h
    jmp near ptr lbl1F7b
lbl426f:
    mov ax,15h
    push ax
    push word ptr ds:[256h]
    call mf407
    add sp,4h
    or ax,ax
    jz short lbl440f
    mov ax,2887h
    jmp short lbl443f
    nop
lbl440f:
    mov ax,288Eh
lbl443f:
    push ds
    push ax
    push word ptr ds:[6A04h]
    mov ax,2h
    push ax
    call mf420
    add sp,4h
    push dx
    push ax
    mov ax,37h
    mov dx,0F00Fh
    push dx
    push ax
    call mf428
    add sp,0Ch
    mov byte ptr ds:[343h],0h
    mov ax,122h
    push ax
    push word ptr ds:[6A04h]
    call mf434
    jmp near ptr lbl656f
lbl47Cf:
    push word ptr ds:[6A02h]
    mov ax,22h
    push ax
    call mf439
    add sp,4h
    push dx
    push ax
    push word ptr ds:[6A04h]
    mov ax,2h
    push ax
    call mf446
    add sp,4h
    push dx
    push ax
    mov ax,44h
    mov dx,0F00Fh
    push dx
    push ax
    call mf454
    add sp,0Ch
    xor ax,ax
    push ax
    push ax
    mov ax,8Fh
    push ax
    call mf461
    add sp,6h
    inc byte ptr ds:[6A17h]
    mov ax,28E7h
    jmp near ptr lbl64Ff
lbl4CAf:
    mov al,byte ptr ds:[6A12h]
    sub ah,ah
    inc ax
    cmp ax, offset mi469
    jng short lbl4E6f
    mov ax,38h
lbl4D8f:
    mov dx,0F00Fh
    push dx
    push ax
    call mf475
    jmp near ptr lbl656f
    nop
lbl4E6f:
    mov ax,2894h
    push ds
    push ax
    call mf481
    add sp,4h
    mov ax,1h
    push ax
    push word ptr ds:[6A04h]
    call mf486
    add sp,4h
    or ax,ax
    jz short lbl55Af
    xor ax,ax
    push ax
    mov ax,9Dh
    push ax
    push word ptr ds:[6A04h]
    call mf495
    add sp,6h
    push word ptr ds:[6A02h]
    mov ax,22h
    push ax
    call mf500
    add sp,4h
    push dx
    push ax
    push word ptr ds:[6A04h]
    mov ax,2h
    push ax
    call mf507
    add sp,4h
    push dx
    push ax
    mov ax,2899h
    push ds
    push ax
    call mf514
    add sp,0Ch
    mov ax,0Eh
    push ax
    call mf518
    add sp,2h
    jmp short lbl58Ef
    nop
lbl55Af:
    push word ptr ds:[6A02h]
    mov ax,22h
    push ax
    call mf525
    add sp,4h
    push dx
    push ax
    push word ptr ds:[6A04h]
    mov ax,1h
    push ax
    call mf532
    add sp,4h
    push dx
    push ax
    mov ax,39h
    mov dx,0F00Fh
    push dx
    push ax
    call mf540
    add sp,0Ch
lbl58Ef:
    inc byte ptr ds:[6A12h]
    mov ax,28A7h
    jmp near ptr lbl64Ff
lbl598f:
    push word ptr ds:[6A02h]
    mov ax,2h
    push ax
    call mf548
    add sp,4h
    push dx
    push ax
    push word ptr ds:[6A04h]
    mov ax,2h
    push ax
    call mf555
    add sp,4h
    push dx
    push ax
    mov ax,42h
    mov dx,0F00Fh
    push dx
    push ax
    call mf563
    add sp,0Ch
    xor ax,ax
    push ax
    push ax
    mov ax,0B1h
    push ax
    call mf570
    add sp,6h
    inc byte ptr ds:[6A15h]
    mov ax,28CEh
    jmp short lbl64Ff
    nop
lbl5E6f:
    cmp byte ptr ds:[6A18h],0h
    jz short lbl606f
    mov ax,78h
    push ax
    mov ax,3h
    push ax
    call mf582
    add sp,4h
    push dx
    push ax
    mov ax,48h
    jmp near ptr lbl1F7b
    nop
lbl606f:
    push word ptr ds:[6A02h]
    mov ax,22h
    push ax
    call mf592
    add sp,4h
    push dx
    push ax
    mov ax,49h
    mov dx,0F00Fh
    push dx
    push ax
    call mf600
    add sp,8h
    xor ax,ax
    push ax
    push ax
    mov ax,78h
    push ax
    call mf607
    add sp,6h
    mov ax,116h
    push ax
    mov ax,75h
    push ax
    call mf613
    add sp,4h
    inc byte ptr ds:[6A18h]
    mov ax,28F1h
lbl64Ff:
    push ds
    push ax
    call mf619
lbl656f:
    add sp,4h
lbl659f:
    call mf621
    or ax,ax
    jz short lbl6ACf
    mov ax,4Bh
    mov dx,0F00Fh
    push dx
    push ax
    call mf628
    add sp,4h
    mov ax,12Bh
    push ax
    mov ax,9Bh
    push ax
    call mf634
    add sp,4h
    xor ax,ax
    push ax
    mov cx,8h
    push cx
    mov cx,8026h
    push cx
    call mf642
    add sp,6h
    xor ax,ax
    push ax
    mov ax,1h
    push ax
    mov ax,19h
    push ax
    call mf650
    add sp,6h
    jmp near ptr lbl297b
    nop
lbl6ACf:
    cmp byte ptr ds:[6A12h],0h
    jnz short lbl6E0f
    cmp byte ptr ds:[6A13h],0h
    jnz short lbl6E0f
    cmp byte ptr ds:[6A14h],0h
    jnz short lbl6E0f
    cmp byte ptr ds:[6A15h],0h
    jnz short lbl6E0f
    cmp byte ptr ds:[6A16h],0h
    jnz short lbl6E0f
    cmp byte ptr ds:[6A17h],0h
    jnz short lbl6E0f
    cmp byte ptr ds:[6A18h],0h
    jnz short lbl6E0f
    jmp near ptr lbl297b
lbl6E0f:
    mov ax,121h
    push ax
    mov ax,9Bh
    push ax
    call mf673
    jmp near ptr lbl294b
lbl6F0f:
    mov ax,word ptr ds:[6A04h]
    sub ax,8Ah
    jnz short lbl6FBf
    jmp near ptr lblC82f
lbl6FBf:
    sub ax, offset mi679
    jnz short lbl703f
    jmp near ptr lbl796f
lbl703f:
    cmp byte ptr ds:[2F2h],0h
    jnz short lbl75Af
    push word ptr ds:[6A02h]
    mov ax,2h
    push ax
    call mf687
    add sp,4h
    push dx
    push ax
    push word ptr ds:[6A04h]
    mov ax,2h
    push ax
    call mf694
    add sp,4h
    push dx
    push ax
    mov ax,30h
    mov dx,0F00Fh
    push dx
    push ax
    call mf702
    add sp,0Ch
    jmp short lbl7ADf
lbl740b:
    cmp word ptr ds:[256h],9Ch
    jz short lbl74Bf
    jmp near ptr lbl297b
lbl74Bf:
    xor ax,ax
    push ax
    mov ax,9Ah
    push ax
    push word ptr ds:[6A02h]
    jmp near ptr lblBC2f
    nop
lbl75Af:
    mov ax,287Ch
    push ds
    push ax
    push word ptr ds:[6A02h]
    mov ax,52h
    push ax
    call mf721
    add sp,8h
    push dx
    push ax
    push word ptr ds:[6A04h]
    mov ax,22h
    push ax
    call mf728
    add sp,4h
    push dx
    push ax
    mov ax,31h
    mov dx,0F00Fh
    push dx
    push ax
    call mf736
    add sp,0Ch
    jmp near ptr lbl297b
lbl796f:
    cmp byte ptr ds:[2F2h],0h
    jnz short lbl7C8f
    mov ax,2Eh
    mov dx,0F00Fh
    push dx
    push ax
    call mf745
    add sp,4h
lbl7ADf:
    mov byte ptr ds:[278Ch],1h
    cmp word ptr ds:[256h],9Ah
    jnz short lbl740b
    xor ax,ax
    push ax
    mov ax,9Ch
    push ax
    push word ptr ds:[6A02h]
    jmp near ptr lblB9Cf
lbl7C8f:
    mov ax,2Fh
    jmp near ptr lbl28Ab
lbl7CEf:
    mov ax,word ptr ds:[6A06h]
    cmp ax, offset mi759
    jnz short lbl7D9f
    jmp near ptr lblC44f
lbl7D9f:
    jna short lbl7DEf
    jmp near ptr lblC82f
lbl7DEf:
    cmp al,1Dh
    jnz short lbl7E5f
    jmp near ptr lblA5Af
lbl7E5f:
    ja short lbl7FAf
    sub al,8h
    jz short lbl826f
    sub al,0Bh
    jz short lbl82Cf
    dec al
    jnz short lbl7F6f
    jmp near ptr lblA4Ef
lbl7F6f:
    jmp near ptr lblC82f
    nop
lbl7FAf:
    cmp al,33h
    jnz short lbl801f
    jmp near ptr lblACCf
lbl801f:
    ja short lbl80Ef
    sub al,2Ch
    jnz short lbl80Af
    jmp near ptr lblAB4f
lbl80Af:
    jmp near ptr lblC82f
    nop
lbl80Ef:
    sub al,36h
    jnc short lbl815f
    jmp near ptr lblC82f
lbl815f:
    sub al,1h
    ja short lbl81Cf
    jmp near ptr lblB50f
lbl81Cf:
    sub al,0Dh
    jnz short lbl823f
    jmp near ptr lblB56f
lbl823f:
    jmp near ptr lblC82f
lbl826f:
    mov ax,26h
    jmp near ptr lbl28Ab
lbl82Cf:
    mov ax,27D8h
    push ds
    push ax
    push word ptr ds:[6A04h]
    mov ax,52h
    push ax
    call mf804
    add sp,8h
    push dx
    push ax
    mov ax,27E0h
    push ds
    push ax
    call mf811
    add sp,8h
    mov al,byte ptr ds:[6A12h]
    sub ah,ah
    mov word ptr ds:[5DFCh],ax
    mov al,byte ptr ds:[6A13h]
    mov word ptr ds:[5DFEh],ax
    mov al,byte ptr ds:[6A14h]
    mov word ptr ds:[5E00h],ax
    mov al,byte ptr ds:[6A15h]
    mov word ptr ds:[5E02h],ax
    mov al,byte ptr ds:[6A16h]
    mov word ptr ds:[5E04h],ax
    mov al,byte ptr ds:[6A17h]
    mov word ptr ds:[5E06h],ax
    mov al,byte ptr ds:[6A18h]
    mov word ptr ds:[5E08h],ax
    mov ax,0FFFFh
    mov word ptr [bp-0Ah],ax
    mov word ptr [bp-8h],ax
    xor ax,ax
    mov word ptr [bp-0Ch],ax
    mov word ptr [bp-6h],ax
    mov word ptr [bp-0Eh],5DFCh
lbl892b:
    mov bx,word ptr [bp-0Eh]
    cmp word ptr [bx],0h
    jnz short lbl8AAf
    inc word ptr [bp-6h]
    add word ptr [bp-0Eh],2h
    cmp word ptr [bp-0Eh],5E0Ah
    jc short lbl892b
    jmp short lbl8B0f
lbl8AAf:
    mov ax,word ptr [bp-6h]
    mov word ptr [bp-8h],ax
lbl8B0f:
    mov word ptr [bp-6h],6h
    mov word ptr [bp-10h],5E08h
lbl8BAb:
    mov bx,word ptr [bp-10h]
    cmp word ptr [bx],0h
    jnz short lbl8D2f
    dec word ptr [bp-6h]
    sub word ptr [bp-10h],2h
    cmp word ptr [bp-10h],5DFCh
    jnc short lbl8BAb
    jmp short lbl8D8f
lbl8D2f:
    mov ax,word ptr [bp-6h]
    mov word ptr [bp-0Ah],ax
lbl8D8f:
    mov word ptr [bp-12h],5DFCh
lbl8DDb:
    mov bx,word ptr [bp-12h]
    cmp word ptr [bx],0h
    jng short lbl8E8f
    inc word ptr [bp-0Ch]
lbl8E8f:
    add word ptr [bp-12h],2h
    cmp word ptr [bp-12h],5E0Ah
    jc short lbl8DDb
    cmp word ptr [bp-0Ch],0h
    jnz short lbl924f
    push word ptr ds:[6A04h]
    mov ax,8Ah
    push ax
    call mf870
    add sp,4h
    or ax,ax
    jz short lbl91Ef
    mov ax,27E4h
lbl910b:
    push ds
    push ax
    call mf877
    add sp,4h
    jmp near ptr lblA42f
    nop
lbl91Ef:
    mov ax,27EBh
    jmp short lbl910b
    nop
lbl924f:
    mov ax,word ptr [bp-8h]
    mov word ptr [bp-6h],ax
    cmp ax, offset mi886
    jc short lbl932f
    jmp near ptr lblA42f
lbl932f:
    add ax,ax
    add ax,5DFCh
    mov word ptr [bp-14h],ax
lbl93Ab:
    mov bx,word ptr [bp-14h]
    cmp word ptr [bx],0h
    jnz short lbl945f
    jmp near ptr lblA31f
lbl945f:
    mov ax,word ptr [bp-6h]
    cmp word ptr [bp-8h],ax
    jz short lbl95Af
    mov ax,27F3h
    push ds
    push ax
    call mf902
    add sp,4h
lbl95Af:
    mov ax,word ptr [bp-6h]
    cmp word ptr [bp-0Ah],ax
    jnz short lbl975f
    cmp word ptr [bp-0Ch],1h
    jng short lbl975f
    mov ax,27F6h
    push ds
    push ax
    call mf912
    add sp,4h
lbl975f:
    mov ax,word ptr [bp-6h]
    cmp ax, offset mi915
    jna short lbl980f
    jmp near ptr lblA31f
lbl980f:
    add ax,ax
    xchg ax,bx
    jmp word ptr cs:[bx+12C3h]
    rcl word ptr [bp+si],1
    out dx,ax
    adc dh,ch
    adc bh,byte ptr [di]
    adc ax,word ptr [bp+di+13h]
    push bp
    adc bx,word ptr [bx+13h]
    cmp byte ptr ds:[6A12h],1h
    jnz short lbl9A2f
    mov ax,27FBh
    jmp short lbl9A5f
lbl9A2f:
    mov ax,2804h
lbl9A5f:
    push ds
    push ax
    call mf935
    add sp,4h
    mov ax,280Fh
    jmp short lblA27f
    mov ax,1Fh
    jmp short lblA1Df
    nop
    mov al,byte ptr ds:[6A14h]
    sub ah,ah
    dec ax
    jz short lbl9D4f
    dec ax
    jz short lbl9DCf
    dec ax
    jz short lbl9E4f
    mov word ptr [bp-4h],20h
    mov word ptr [bp-2h],0F00Fh
    jmp short lbl9ECf
lbl9D4f:
    mov word ptr [bp-4h],281Eh
    jmp short lbl9E9f
    nop
lbl9DCf:
    mov word ptr [bp-4h],2825h
    jmp short lbl9E9f
    nop
lbl9E4f:
    mov word ptr [bp-4h],282Fh
lbl9E9f:
    mov word ptr [bp-2h],ds
lbl9ECf:
    push word ptr [bp-2h]
    push word ptr [bp-4h]
    mov ax,283Bh
    push ds
    push ax
    call mf966
    add sp,8h
    jmp short lblA31f
    nop
    mov ax,2847h
    jmp short lblA27f
    nop
    cmp byte ptr ds:[6A16h],1h
    jnz short lblA14f
    mov ax,284Eh
    jmp short lblA27f
lblA14f:
    mov ax,285Dh
    jmp short lblA27f
    nop
    mov ax,21h
lblA1Df:
    mov dx,0F00Fh
    push dx
    jmp short lblA28f
    nop
    mov ax,286Dh
lblA27f:
    push ds
lblA28f:
    push ax
    call mf988
    add sp,4h
lblA31f:
    inc word ptr [bp-6h]
    add word ptr [bp-14h],2h
    cmp word ptr [bp-14h],5E0Ah
    jnc short lblA42f
    jmp near ptr lbl93Ab
lblA42f:
    mov ax,2Eh
    push ax
    call mf997
    jmp near ptr lblC37f
lblA4Ef:
    push word ptr ds:[6A04h]
    push word ptr ds:[6A02h]
    jmp near ptr lbl4Bb
    nop
lblA5Af:
    cmp byte ptr ds:[2F2h],0h
    jnz short lblA74f
    mov ax,28h
    mov dx,0F00Fh
    push dx
    push ax
    call mf1009
    add sp,4h
    jmp near ptr lblB89f
lblA74f:
    push word ptr ds:[6A04h]
    mov ax,2h
    push ax
    call mf1015
    add sp,4h
    push dx
    push ax
    mov ax,29h
    mov dx,0F00Fh
    push dx
    push ax
    call mf1023
    add sp,8h
    mov ax,1770h
    push ax
    call mf1027
    add sp,2h
    mov word ptr ds:[2A8h],12h
    mov ax,5Ah
    push ax
    call mf1032
    jmp near ptr lblC37f
lblAB4f:
    push word ptr ds:[6A04h]
    mov ax,12h
    push ax
    call mf1037
    add sp,4h
    push dx
    push ax
    mov ax,25h
    jmp near ptr lbl11Fb
lblACCf:
    mov ax,1h
    push ax
    push word ptr ds:[6A04h]
    call mf1046
    add sp,4h
    or ax,ax
    jnz short lblAF8f
    push word ptr ds:[6A04h]
    mov ax,2h
    push ax
    call mf1053
    add sp,4h
    push dx
    push ax
    mov ax,2Ah
    jmp near ptr lbl11Fb
lblAF8f:
    call mf1059
    or ax,ax
    jz short lblB08f
    mov ax,2Bh
    jmp near ptr lbl28Ab
    nop
lblB08f:
    mov ax,1h
    push ax
    mov ax,0BDh
    push ax
    call mf1069
    add sp,4h
    or ax,ax
    jz short lblB2Cf
    call mf1073
    or al,al
    jnz short lblB2Cf
    mov ax,2Ch
    jmp near ptr lbl28Ab
    nop
lblB2Cf:
    call mf1079
    or al,al
    jnz short lblB38f
    jmp near ptr lbl297b
lblB38f:
    push word ptr ds:[6A04h]
    mov ax,22h
    push ax
    call mf1086
    add sp,4h
    push dx
    push ax
    mov ax,2Dh
    jmp near ptr lbl11Fb
lblB50f:
    mov ax,27h
    jmp near ptr lbl28Ab
lblB56f:
    cmp byte ptr ds:[2F2h],0h
    jnz short lblBD2f
    mov ax,2877h
    push ds
    push ax
    push word ptr ds:[6A04h]
    mov ax,56h
    push ax
    call mf1102
    add sp,8h
    push dx
    push ax
    mov ax,22h
    mov dx,0F00Fh
    push dx
    push ax
    call mf1110
    add sp,8h
    mov byte ptr ds:[278Ch],1h
lblB89f:
    cmp word ptr ds:[256h],9Ah
    jnz short lblBACf
    xor ax,ax
    push ax
    mov ax,9Ch
    push ax
    push word ptr ds:[6A04h]
lblB9Cf:
    call mf1120
    add sp,6h
    mov byte ptr ds:[278Ah],1h
    jmp near ptr lbl297b
lblBACf:
    cmp word ptr ds:[256h],9Ch
    jz short lblBB7f
    jmp near ptr lbl297b
lblBB7f:
    xor ax,ax
    push ax
    mov ax,9Ah
    push ax
    push word ptr ds:[6A04h]
lblBC2f:
    call mf1132
    add sp,6h
    mov byte ptr ds:[278Bh],1h
    jmp near ptr lbl297b
lblBD2f:
    mov ax,1h
    push ax
    push word ptr ds:[6A04h]
    call mf1139
    add sp,4h
    or ax,ax
    jnz short lblC3Ef
    push word ptr ds:[6A04h]
    mov ax,2h
    push ax
    call mf1146
    add sp,4h
    push dx
    push ax
    mov ax,23h
    mov dx,0F00Fh
    push dx
    push ax
    call mf1154
    add sp,8h
    xor ax,ax
    push ax
    mov cx,1h
    push cx
    mov dx,7h
    push dx
    call mf1162
    add sp,6h
    xor ax,ax
    push ax
    mov ax,1h
    push ax
    push word ptr ds:[6A04h]
    call mf1169
    add sp,6h
    mov ax,8Ah
    push ax
    call mf1173
lblC37f:
    add sp,2h
    jmp near ptr lbl297b
    nop
lblC3Ef:
    mov ax,24h
    jmp near ptr lbl28Ab
lblC44f:
    cmp byte ptr ds:[2F2h],0h
    jnz short lblC54f
    mov ax,5A0Ch
    push ax
    mov ax,20Ah
    jmp short lblC79f
lblC54f:
    mov ax,1h
    push ax
    push word ptr ds:[6A04h]
    call mf1188
    add sp,4h
    or ax,ax
    jnz short lblC72f
    mov ax,5A0Ch
    push ax
    mov ax,20Bh
    jmp short lblC79f
    nop
lblC72f:
    mov ax,5A0Ch
    push ax
    mov ax,20Ch
lblC79f:
    push ax
    call mf1201
    jmp near ptr lbl294b
lblC82f:
    xor ax,ax
lblC84f:
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
