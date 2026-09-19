_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi130:NEAR
    EXTRN mi588:NEAR
    EXTRN mf16:FAR
    EXTRN mf414:FAR
    EXTRN mf447:FAR
    EXTRN mia8:NEAR
    EXTRN mf424:FAR
    EXTRN mf4d0:FAR
    EXTRN mf543:FAR
    EXTRN mf55b:FAR
    EXTRN mf207:FAR
    EXTRN mf176:FAR
    EXTRN mf19d:FAR
    EXTRN mi10e:NEAR
    EXTRN mf494:FAR
    EXTRN mf3b0:FAR
    EXTRN mf502:FAR
    EXTRN mi40:NEAR
    EXTRN mf25:FAR
    EXTRN mf247:FAR
    EXTRN mf39d:FAR
    EXTRN mf1d3:FAR
    EXTRN mf481:FAR
    EXTRN mf401:FAR
    EXTRN mf3c3:FAR
    EXTRN mf52a:FAR
    EXTRN mf165:FAR
    EXTRN mf51b:FAR
    EXTRN mi56:NEAR
    EXTRN mf38a:FAR
    EXTRN mf35b:FAR
    EXTRN mi583:NEAR
    EXTRN mf1b9:FAR
    EXTRN mf5dc:FAR
    EXTRN mif4:NEAR
    EXTRN midc:NEAR
    EXTRN mf5a2:FAR
    EXTRN mf1e9:FAR
    EXTRN mf3ee:FAR
    EXTRN mf270:FAR
    EXTRN mf578:FAR
    EXTRN mf45c:FAR
    EXTRN mf157:FAR
    EXTRN mf17b:FAR
    EXTRN mf194:FAR
    EXTRN mf1f8:FAR
    EXTRN mi4c:NEAR
    EXTRN mf299:FAR
    EXTRN mf356:FAR
    EXTRN mf265:FAR
    EXTRN mf4e3:FAR
    EXTRN mi3b:NEAR
    EXTRN mf1f1:FAR
    EXTRN mf232:FAR
    EXTRN mf3d6:FAR
    EXTRN mf437:FAR
    EXTRN mf1da:FAR
    EXTRN mfb:FAR
    EXTRN mf22b:FAR
    EXTRN mf288:FAR
    EXTRN mf258:FAR
    EXTRN mf4f6:FAR
    EXTRN mf152:FAR
    EXTRN mf5e4:FAR
    EXTRN mf160:FAR
    EXTRN mie4:NEAR
    EXTRN mf379:FAR
    EXTRN mf23b:FAR
    EXTRN mf1cb:FAR
    EXTRN mf222:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,14h
    push si
    mov ax,2h
    push ax
    call mfb
    add sp,2h
    xor ax,ax
    push ax
    call mf16
    add sp,2h
    cmp word ptr ds:[66h],0h
    jz short lbl30f
    call mf25
    mov word ptr ds:[66h],0h
lbl30f:
    mov word ptr [bp-2h],0h
    mov ax,word ptr ds:[69E8h]
    mov word ptr [bp-4h],ax
    cmp ax, offset mi3b
    jl short lbl49f
    cmp ax, offset mi40
    jg short lbl49f
    sub word ptr [bp-4h],20h
lbl49f:
    mov ax,word ptr [bp-4h]
    cmp ax, offset mi4c
    jnz short lbl54f
    jmp near ptr lbl258f
lbl54f:
    jg short lblC8f
    cmp ax, offset mi56
    jnz short lbl5Ef
    jmp near ptr lbl250f
lbl5Ef:
    jna short lbl63f
    jmp near ptr lbl50Af
lbl63f:
    cmp al,48h
    jnz short lbl6Af
    jmp near ptr lbl160f
lbl6Af:
    jg short lblA6f
    cmp al,3Fh
    jnz short lbl73f
    jmp near ptr lbl160f
lbl73f:
    jg short lbl8Ef
    sub al,3h
    jnz short lbl7Cf
    jmp near ptr lbl152f
lbl7Cf:
    sub al,18h
    jnz short lbl83f
    jmp near ptr lbl152f
lbl83f:
    sub al,14h
    jnz short lbl8Af
    jmp near ptr lbl160f
lbl8Af:
    jmp near ptr lbl50Af
    nop
lbl8Ef:
    sub al,43h
    jnz short lbl95f
    jmp near ptr lbl16Ef
lbl95f:
    dec al
    jnz short lbl9Cf
    jmp near ptr lbl176f
lbl9Cf:
    sub al,3h
    jnz short lblA3f
    jmp near ptr lbl184f
lblA3f:
    jmp near ptr lbl50Af
lblA6f:
    sub al,4Ch
    cmp ax, offset mia8
    jna short lblB0f
    jmp near ptr lbl50Af
lblB0f:
    add ax,ax
    xchg ax,bx
    jmp word ptr cs:[bx+1229h]
    db 0FDh, 12h, 05h, 13h, 7Bh, 16h, 83h, 13h, 8Bh, 13h, 0C3h, 12h, 93h, 13h, 0A3h, 13h
lblC8f:
    cmp ax,149h
    jnz short lblD0f
    jmp near ptr lbl2E6f
lblD0f:
    jg short lbl120f
    cmp ax,13Fh
    jnz short lblDAf
    jmp near ptr lbl232f
lblDAf:
    jg short lbl100f
    sub ax, offset midc
    jnz short lblE4f
    jmp near ptr lbl270f
lblE4f:
    sub ax, offset mie4
    jnz short lblECf
    jmp near ptr lbl282f
lblECf:
    sub ax,0E1h
    jnl short lblF4f
    jmp near ptr lbl50Af
lblF4f:
    sub ax, offset mif4
    jg short lblFCf
    jmp near ptr lbl288f
lblFCf:
    jmp near ptr lbl50Af
    nop
lbl100f:
    sub ax,140h
    jnz short lbl108f
    jmp near ptr lbl222f
lbl108f:
    dec ax
    jnz short lbl10Ef
    jmp near ptr lbl2A4f
lbl10Ef:
    sub ax, offset mi10e
    jnz short lbl116f
    jmp near ptr lbl2CAf
lbl116f:
    dec ax
    jnz short lbl11Cf
    jmp near ptr lbl2D8f
lbl11Cf:
    jmp near ptr lbl50Af
    nop
lbl120f:
    cmp ax,171h
    jnz short lbl128f
    jmp near ptr lbl356f
lbl128f:
    jng short lbl12Df
    jmp near ptr lbl50Af
lbl12Df:
    sub ax,14Bh
    cmp ax, offset mi130
    jna short lbl138f
    jmp near ptr lbl50Af
lbl138f:
    add ax,ax
    xchg ax,bx
    jmp word ptr cs:[bx+12B1h]
    db 65h, 14h, 7Bh, 16h, 73h, 14h, 7Bh, 16h, 81h, 14h, 8Fh, 14h, 9Dh, 14h, 0ABh, 14h
    db 0B9h, 14h
lbl152f:
    call mf152
    call mf157
    jmp near ptr lbl50Af
    nop
lbl160f:
    call mf160
    call mf165
    jmp near ptr lbl50Af
    nop
lbl16Ef:
    mov word ptr [bp-2h],8h
    jmp near ptr lbl50Af
lbl176f:
    call mf176
    call mf17b
    jmp near ptr lbl50Af
    nop
lbl184f:
    mov word ptr [bp-2h],44h
    jmp near ptr lbl50Af
    mov word ptr [bp-2h],26h
    jmp near ptr lbl50Af
    call mf194
    mov ax,10h
    push ax
    call mf19d
    add sp,2h
    sub dx,dx
    add ax,ax
    adc dx,dx
    add ax,ax
    adc dx,dx
    add ax,ax
    adc dx,dx
    add ax,ax
    adc dx,dx
    push dx
    push ax
    call mf1b9
    add sp,4h
    push dx
    push ax
    mov ax,92h
    mov cx,2199h
    push cx
    push ax
    call mf1cb
    add sp,8h
    call mf1d3
    push dx
    push ax
    call mf1da
    add sp,4h
    push dx
    push ax
    mov ax,0A2h
    push ds
    push ax
    call mf1e9
    add sp,8h
    call mf1f1
    push dx
    push ax
    call mf1f8
    add sp,4h
    push dx
    push ax
    mov ax,0B2h
lbl205b:
    push ds
lbl206b:
    push ax
    call mf207
    add sp,8h
    jmp near ptr lbl50Af
    mov word ptr [bp-2h],2Ch
    jmp near ptr lbl50Af
    mov word ptr [bp-2h],38h
    jmp near ptr lbl50Af
lbl222f:
    call mf222
    mov ax,2h
    push ax
    call mf22b
    jmp short lbl240f
lbl232f:
    call mf232
    mov ax,2h
    push ax
    call mf23b
lbl240f:
    add sp,2h
    mov ax,10h
    push ax
    call mf247
    jmp near ptr lbl507f
    nop
lbl250f:
    mov word ptr [bp-2h],45h
    jmp near ptr lbl50Af
lbl258f:
    call mf258
    mov ax,5h
lbl260b:
    push ax
lbl261b:
    mov ax,100h
    push ax
    call mf265
    add sp,4h
    jmp near ptr lbl50Af
lbl270f:
    call mf270
    mov ax,0h
    mov cx,2195h
    push cx
    push ax
    mov ax,0B8h
    jmp short lbl205b
lbl282f:
    mov ax,2h
    jmp short lbl260b
    nop
lbl288f:
    call mf288
    mov ax,word ptr [bp-4h]
    sub ax,139h
    push ax
    xor cx,cx
    push cx
    mov si,ax
    call mf299
    add sp,4h
    push si
    jmp short lbl261b
lbl2A4f:
    cmp word ptr ds:[42h],1h
    db 1Bh, 0C0h ; override
    neg ax
    mov word ptr ds:[42h],ax
    or ax,ax
    jz short lbl2BAf
    mov ax,0C5h
    jmp short lbl2BDf
    nop
lbl2BAf:
    mov ax,0C9h
lbl2BDf:
    push ds
    push ax
    mov ax,0A3h
    mov cx,2199h
    push cx
    jmp near ptr lbl206b
    nop
lbl2CAf:
    mov word ptr [bp-2h],51h
    mov word ptr [bp-8h],8h
    jmp near ptr lbl50Af
    nop
lbl2D8f:
    mov word ptr [bp-2h],51h
    mov word ptr [bp-8h],1h
    jmp near ptr lbl50Af
    nop
lbl2E6f:
    mov word ptr [bp-2h],51h
    mov word ptr [bp-8h],2h
    jmp near ptr lbl50Af
    nop
    mov word ptr [bp-2h],51h
    mov word ptr [bp-8h],7h
    jmp near ptr lbl50Af
    nop
    mov word ptr [bp-2h],51h
    mov word ptr [bp-8h],3h
    jmp near ptr lbl50Af
    nop
    mov word ptr [bp-2h],51h
    mov word ptr [bp-8h],6h
    jmp near ptr lbl50Af
    nop
    mov word ptr [bp-2h],51h
    mov word ptr [bp-8h],5h
    jmp near ptr lbl50Af
    nop
    mov word ptr [bp-2h],51h
    mov word ptr [bp-8h],4h
    jmp near ptr lbl50Af
    nop
    mov word ptr [bp-2h],51h
    mov word ptr [bp-8h],9h
    jmp near ptr lbl50Af
    nop
    mov word ptr [bp-2h],51h
    mov word ptr [bp-8h],0Ah
    jmp near ptr lbl50Af
    nop
lbl356f:
    call mf356
    call mf35b
    mov ax,5h
    mov word ptr ds:[798h],ax
    mov word ptr ds:[290h],ax
    mov byte ptr ds:[28Eh],1h
    xor ax,ax
    push ax
    mov cx,1h
    push cx
    mov dx,8Bh
    push dx
    call mf379
    add sp,6h
    mov ax,1h
    push ax
    push ax
    mov cx,54h
    push cx
    call mf38a
    add sp,6h
    xor ax,ax
    push ax
    mov cx,1h
    push cx
    mov dx,58h
    push dx
    call mf39d
    add sp,6h
    xor ax,ax
    push ax
    mov cx,1h
    push cx
    mov dx,57h
    push dx
    call mf3b0
    add sp,6h
    xor ax,ax
    push ax
    mov cx,1h
    push cx
    mov dx,55h
    push dx
    call mf3c3
    add sp,6h
    xor ax,ax
    push ax
    mov cx,1h
    push cx
    mov dx,0ADh
    push dx
    call mf3d6
    add sp,6h
    mov byte ptr ds:[32Ah],1h
    xor ax,ax
    push ax
    mov cx,8h
    push cx
    mov dx,15Fh
    push dx
    call mf3ee
    add sp,6h
    xor ax,ax
    push ax
    mov cx,1h
    push cx
    mov dx,124h
    push dx
    call mf401
    add sp,6h
    xor ax,ax
    push ax
    mov cx,1h
    push cx
    mov cx,0CEh
    push cx
    call mf414
    add sp,6h
    mov ax,0Eh
    push ax
    mov ax,0CEh
    push ax
    call mf424
    add sp,4h
    xor ax,ax
    push ax
    mov ax,8h
    push ax
    mov ax,15Fh
    push ax
    call mf437
    add sp,6h
    mov ax,34h
    mov cx,2199h
    push cx
    push ax
    call mf447
    add sp,4h
    mov ax,76h
    mov cx,2199h
    push cx
    push ax
    mov ax,0CCh
    push ds
    push ax
    call mf45c
    add sp,8h
    dec ax
    jz short lbl476f
    dec ax
    jz short lbl4A2f
    dec ax
    jz short lbl4A8f
    dec ax
    jz short lbl4AEf
    dec ax
    jz short lbl4BCf
    jmp near ptr lbl50Af
lbl476f:
    xor ax,ax
    push ax
    mov cx,1h
    push cx
    mov dx,4Dh
    push dx
    call mf481
    add sp,6h
    xor ax,ax
    push ax
    mov ax,1h
    push ax
    mov ax,75h
    push ax
    call mf494
    add sp,6h
    mov ax,0C9h
    jmp short lbl501f
    nop
lbl4A2f:
    mov ax,139h
    jmp short lbl501f
    nop
lbl4A8f:
    mov ax,160h
    jmp short lbl501f
    nop
lbl4AEf:
    mov ax,6h
    mov word ptr ds:[798h],ax
    mov word ptr ds:[290h],ax
    mov ax,184h
    jmp short lbl501f
lbl4BCf:
    mov ax,6h
    mov word ptr ds:[798h],ax
    mov word ptr ds:[290h],ax
    xor ax,ax
    push ax
    mov cx,1h
    push cx
    mov dx,1A9h
    push dx
    call mf4d0
    add sp,6h
    xor ax,ax
    push ax
    mov cx,1h
    push cx
    mov cx,199h
    push cx
    call mf4e3
    add sp,6h
    xor ax,ax
    push ax
    mov ax,1D5h
    push ax
    mov ax,5h
    push ax
    call mf4f6
    add sp,6h
    mov ax,1AAh
lbl501f:
    push ax
    call mf502
lbl507f:
    add sp,2h
lbl50Af:
    cmp word ptr [bp-2h],51h
    jnz short lbl536f
    sub ax,ax
    push ax
    push ax
    push ax
    push word ptr [bp-8h]
    push word ptr [bp-2h]
    call mf51b
    add sp,0Ah
    xor ax,ax
    push ax
    mov ax,200h
    push ax
    call mf52a
    add sp,4h
    jmp near ptr lbl5E4f
    nop
lbl536f:
    cmp word ptr [bp-2h],0h
    jnz short lbl53Ff
    jmp near ptr lbl5E4f
lbl53Ff:
    xor ax,ax
    push ax
    push ax
    call mf543
    add sp,4h
    mov ax,word ptr [bp-2h]
    mov word ptr ds:[50h],ax
    lea ax,word ptr [bp-0Ch]
    push ss
    push ax
    lea cx,word ptr [bp-0Ah]
    push ss
    push cx
    call mf55b
    add sp,8h
    lea ax,word ptr [bp-12h]
    push ss
    push ax
    lea cx,word ptr [bp-10h]
    push ss
    push cx
    lea cx,word ptr [bp-0Eh]
    push ss
    push cx
    push word ptr [bp-0Ch]
    push word ptr [bp-0Ah]
    call mf578
    add sp,10h
    mov ax,word ptr [bp-12h]
    sub ax, offset mi583
    jz short lbl58Df
    sub ax, offset mi588
    jnz short lbl5C8f
lbl58Df:
    cmp word ptr ds:[50h],50h
    jnz short lbl59Cf
    xor ax,ax
    mov word ptr ds:[52h],ax
    jmp short lbl5C5f
    nop
lbl59Cf:
    push word ptr [bp-10h]
    push word ptr [bp-0Eh]
    call mf5a2
    add sp,4h
    mov word ptr [bp-14h],ax
    cmp word ptr ds:[52h],0h
    jnz short lbl5BAf
    mov word ptr ds:[52h],ax
    jmp short lbl5C8f
    nop
lbl5BAf:
    mov ax,word ptr ds:[52h]
    cmp word ptr [bp-14h],ax
    jz short lbl5C8f
    mov ax,word ptr [bp-14h]
lbl5C5f:
    mov word ptr ds:[54h],ax
lbl5C8f:
    xor ax,ax
    push ax
    push ax
    push word ptr ds:[54h]
    push word ptr ds:[52h]
    push word ptr ds:[50h]
    mov ax,1h
    push ax
    call mf5dc
    add sp,0Ch
lbl5E4f:
    call mf5e4
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
