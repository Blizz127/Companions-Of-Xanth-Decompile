_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi137:NEAR
    EXTRN mi134:NEAR
    EXTRN mf18e:FAR
    EXTRN mid7:NEAR
    EXTRN mf642:FAR
    EXTRN mf127:FAR
    EXTRN mf5da:FAR
    EXTRN mf7e3:FAR
    EXTRN mf8c0:FAR
    EXTRN mi924:NEAR
    EXTRN mida:NEAR
    EXTRN mf2fe:FAR
    EXTRN mf1f5:FAR
    EXTRN mf816:FAR
    EXTRN mi1ac:NEAR
    EXTRN mf8f8:FAR
    EXTRN mf34e:FAR
    EXTRN mf7cc:FAR
    EXTRN mf316:FAR
    EXTRN mf82a:FAR
    EXTRN mf562:FAR
    EXTRN mf47:FAR
    EXTRN mfef:FAR
    EXTRN md96f:NEAR
    EXTRN mf36e:FAR
    EXTRN mf4e0:FAR
    EXTRN mi1a7:NEAR
    EXTRN mf3ba:FAR
    EXTRN mf546:FAR
    EXTRN mf74c:FAR
    EXTRN mf8dc:FAR
    EXTRN mf8a2:FAR
    EXTRN mf6e8:FAR
    EXTRN md96a:NEAR
    EXTRN mf6cc:FAR
    EXTRN mf17a:FAR
    EXTRN mf768:FAR
    EXTRN mfca:FAR
    EXTRN mf24:FAR
    EXTRN mf7fa:FAR
    EXTRN mid2:NEAR
    EXTRN mf2e2:FAR
    EXTRN mf113:FAR
    EXTRN mf4fa:FAR
    EXTRN mf7b0:FAR
    EXTRN mf2b2:FAR
    EXTRN mf784:FAR
    EXTRN mf273:FAR
    EXTRN md94a:NEAR
    EXTRN mf5be:FAR
    EXTRN mf60a:FAR
    EXTRN mf216:FAR
    EXTRN mf296:FAR
    EXTRN mf57e:FAR
    EXTRN mf1bd:FAR
    EXTRN mi921:NEAR
    EXTRN mf2c6:FAR
    EXTRN mf914:FAR
    EXTRN mi12f:NEAR
    EXTRN mf1e1:FAR
    EXTRN mi91c:NEAR
    EXTRN mf3e6:FAR
    EXTRN mf720:FAR
    EXTRN mf5ee:FAR
    EXTRN mf19f:FAR
    EXTRN mfad:FAR
    EXTRN mf955:FAR
    EXTRN mf856:FAR
    EXTRN mf626:FAR
    EXTRN mf332:FAR
    EXTRN mi2ef:NEAR
    EXTRN mf15e:FAR
    EXTRN mf886:FAR
    EXTRN mf25e:FAR
    EXTRN mf672:FAR
    EXTRN mf402:FAR
    EXTRN mf59a:FAR
    EXTRN mi2ea:NEAR
    EXTRN mf656:FAR
    EXTRN mff:FAR
    EXTRN mf704:FAR
    EXTRN mf205:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,2h
    push si
    mov ax,13h
    push ax
    push word ptr ds:[256h]
    call mff
    add sp,4h
    or ax,ax
    jnz short lbl38f
    mov ax,1h
    push ax
    push ax
    mov ax,54h
    push ax
    call mf24
    add sp,6h
    or ax,ax
    jnz short lbl38f
    mov word ptr [bp-2h],37h
    jmp near ptr lbl937f
lbl38f:
    cmp byte ptr ds:[2FFh],0h
    jnz short lbl5Ef
    mov ax,5h
    push ax
    mov ax,0BEh
    push ax
    call mf47
    add sp,4h
    or ax,ax
    jnz short lbl5Ef
    mov byte ptr ds:[2FFh],1h
lbl58b:
    mov word ptr [bp-2h],ax
    jmp near ptr lbl937f
lbl5Ef:
    cmp byte ptr ds:[300h],0h
    jnz short lbl6Ef
    mov word ptr [bp-2h],1h
    jmp near ptr lbl937f
    nop
lbl6Ef:
    cmp byte ptr ds:[302h],0h
    jz short lbl83f
    cmp byte ptr ds:[303h],0h
    jz short lbl83f
    cmp byte ptr ds:[304h],0h
    jnz short lbl92f
lbl83f:
    cmp byte ptr ds:[305h],0h
    jnz short lbl92f
    mov word ptr [bp-2h],2h
    jmp near ptr lbl937f
lbl92f:
    cmp byte ptr ds:[305h],0h
    jnz short lblA2f
    mov word ptr [bp-2h],3h
    jmp near ptr lbl937f
    nop
lblA2f:
    cmp byte ptr ds:[2F2h],0h
    jnz short lblE0f
    mov ax,7h
    push ax
    call mfad
    add sp,2h
    or ax,ax
    jz short lblC2f
    mov word ptr [bp-2h],36h
    jmp near ptr lbl937f
    nop
lblC2f:
    mov ax,5h
    push ax
    mov ax,9Ah
    push ax
    call mfca
    add sp,4h
    cmp ax, offset mid2
    db 1Bh, 0C0h ; override
    and ax, offset mid7
    add ax, offset mida
    jmp near ptr lbl58b
lblE0f:
    cmp byte ptr ds:[313h],0h
    jnz short lbl146f
    mov ax,5h
    push ax
    mov ax,9Dh
    push ax
    call mfef
    add sp,4h
    or ax,ax
    jz short lbl104f
    mov word ptr [bp-2h],6h
    jmp near ptr lbl937f
    nop
lbl104f:
    cmp byte ptr ds:[31Fh],0h
    jnz short lbl13Ef
    mov ax,1h
    push ax
    mov ax,9Bh
    push ax
    call mf113
    add sp,4h
    or ax,ax
    jnz short lbl13Ef
    push word ptr ds:[256h]
    mov ax,9Bh
    push ax
    call mf127
    add sp,4h
    cmp ax, offset mi12f
    db 1Bh, 0C0h ; override
    and ax, offset mi134
    add ax, offset mi137
    jmp near ptr lbl58b
    nop
lbl13Ef:
    mov word ptr [bp-2h],7h
    jmp near ptr lbl937f
lbl146f:
    cmp byte ptr ds:[314h],0h
    jnz short lbl156f
    mov word ptr [bp-2h],9h
    jmp near ptr lbl937f
    nop
lbl156f:
    mov ax,5h
    push ax
    mov ax,0B8h
    push ax
    call mf15e
    add sp,4h
    or ax,ax
    jnz short lbl172f
    mov word ptr [bp-2h],0Ah
    jmp near ptr lbl937f
lbl172f:
    mov ax,0Ah
    push ax
    mov ax,0BDh
    push ax
    call mf17a
    add sp,4h
    or ax,ax
    jnz short lbl18Ef
    mov word ptr [bp-2h],0Bh
    jmp near ptr lbl937f
lbl18Ef:
    call mf18e
    or ax,ax
    jnz short lbl1B2f
    mov ax,1h
    push ax
    mov ax,9Bh
    push ax
    call mf19f
    add sp,4h
    cmp ax, offset mi1a7
    db 1Bh, 0C0h ; override
    add ax, offset mi1ac
    jmp near ptr lbl58b
lbl1B2f:
    xor ax,ax
    push ax
    mov cx,1h
    push cx
    mov cx,9Bh
    push cx
    call mf1bd
    add sp,6h
    or ax,ax
    jz short lbl1D2f
    mov word ptr [bp-2h],0Eh
    jmp near ptr lbl937f
    nop
lbl1D2f:
    cmp byte ptr ds:[31Dh],0h
    jz short lbl236f
    mov ax,1h
    push ax
    mov ax,88h
    push ax
    call mf1e1
    add sp,4h
    or ax,ax
    jz short lbl22Ef
    mov ax,1h
    push ax
    mov ax,89h
    push ax
    call mf1f5
    add sp,4h
    or ax,ax
    jz short lbl22Ef
    mov ax,88h
    push ax
    call mf205
    add sp,2h
    cmp ax,147h
    jnz short lbl226f
    mov ax,89h
    push ax
    call mf216
    add sp,2h
    cmp ax,147h
    jnz short lbl226f
    jmp near ptr lbl937f
lbl226f:
    mov word ptr [bp-2h],10h
    jmp near ptr lbl937f
lbl22Ef:
    mov word ptr [bp-2h],0Fh
    jmp near ptr lbl937f
lbl236f:
    cmp word ptr ds:[2A6h],0h
    jnz short lbl246f
    mov word ptr [bp-2h],11h
    jmp near ptr lbl937f
    nop
lbl246f:
    cmp word ptr ds:[2A6h],2h
    jnl short lbl256f
    mov word ptr [bp-2h],12h
    jmp near ptr lbl937f
    nop
lbl256f:
    mov ax,1h
    push ax
    mov ax,8Bh
    push ax
    call mf25e
    add sp,4h
    or ax,ax
    jnz short lbl27Ef
    mov word ptr [bp-2h],13h
    mov ax,11h
    push ax
    call mf273
    add sp,2h
    jmp near ptr lbl937f
lbl27Ef:
    cmp byte ptr ds:[30Dh],0h
    jnz short lbl28Ef
    mov word ptr [bp-2h],14h
    jmp near ptr lbl937f
    nop
lbl28Ef:
    mov ax,5h
    push ax
    mov ax,0BEh
    push ax
    call mf296
    add sp,4h
    or ax,ax
    jnz short lbl2AAf
    mov word ptr [bp-2h],15h
    jmp near ptr lbl937f
lbl2AAf:
    mov ax,0BEh
    push ax
    mov ax,1h
    push ax
    call mf2b2
    add sp,4h
    or ax,ax
    jz short lbl2F6f
    mov ax,0BEh
    push ax
    mov ax,0BFh
    push ax
    call mf2c6
    add sp,4h
    or ax,ax
    jnz short lbl2DAf
    mov word ptr [bp-2h],16h
    jmp near ptr lbl937f
lbl2DAf:
    mov ax,0Eh
    push ax
    mov ax,0BFh
    push ax
    call mf2e2
    add sp,4h
    cmp ax, offset mi2ea
    db 1Bh, 0C0h ; override
    add ax, offset mi2ef
    jmp near ptr lbl58b
    nop
lbl2F6f:
    mov ax,5h
    push ax
    mov ax,0C7h
    push ax
    call mf2fe
    add sp,4h
    or ax,ax
    jnz short lbl312f
    mov word ptr [bp-2h],19h
    jmp near ptr lbl937f
lbl312f:
    mov ax,13h
    push ax
    call mf316
    add sp,2h
    or ax,ax
    jz short lbl32Af
    mov word ptr [bp-2h],1Ah
    jmp near ptr lbl937f
lbl32Af:
    mov ax,5h
    push ax
    mov ax,0CDh
    push ax
    call mf332
    add sp,4h
    or ax,ax
    jnz short lbl346f
    mov word ptr [bp-2h],1Bh
    jmp near ptr lbl937f
lbl346f:
    mov ax,0CDh
    push ax
    mov ax,1h
    push ax
    call mf34e
    add sp,4h
    or ax,ax
    jz short lbl36Af
    cmp byte ptr ds:[342h],0h
    jnz short lbl36Af
    mov word ptr [bp-2h],39h
    jmp near ptr lbl937f
    nop
lbl36Af:
    mov ax,14h
    push ax
    call mf36e
    add sp,2h
    or ax,ax
    jz short lbl382f
    mov word ptr [bp-2h],1Ch
    jmp near ptr lbl937f
lbl382f:
    cmp byte ptr ds:[321h],0h
    jz short lbl392f
    mov word ptr [bp-2h],1Dh
    jmp near ptr lbl937f
    nop
lbl392f:
    cmp byte ptr ds:[336h],0h
    jnz short lbl3A2f
    mov word ptr [bp-2h],1Eh
    jmp near ptr lbl937f
    nop
lbl3A2f:
    cmp byte ptr ds:[310h],0h
    jnz short lbl3B2f
    mov word ptr [bp-2h],1Fh
    jmp near ptr lbl937f
    nop
lbl3B2f:
    mov ax,0Ah
    push ax
    mov ax,0EEh
    push ax
    call mf3ba
    add sp,4h
    or ax,ax
    jnz short lbl3CEf
    mov word ptr [bp-2h],20h
    jmp near ptr lbl937f
lbl3CEf:
    cmp byte ptr ds:[311h],0h
    jnz short lbl3DEf
    mov word ptr [bp-2h],21h
    jmp near ptr lbl937f
    nop
lbl3DEf:
    mov ax,5h
    push ax
    mov ax,0F8h
    push ax
    call mf3e6
    add sp,4h
    or ax,ax
    jnz short lbl3FAf
    mov word ptr [bp-2h],22h
    jmp near ptr lbl937f
lbl3FAf:
    mov ax,5h
    push ax
    mov ax,0FBh
    push ax
    call mf402
    add sp,4h
    or ax,ax
    jnz short lbl416f
    mov word ptr [bp-2h],23h
    jmp near ptr lbl937f
lbl416f:
    cmp byte ptr ds:[339h],0h
    jnz short lbl426f
    mov word ptr [bp-2h],24h
    jmp near ptr lbl937f
    nop
lbl426f:
    cmp byte ptr ds:[327h],0h
    jnz short lbl436f
    mov word ptr [bp-2h],25h
    jmp near ptr lbl937f
    nop
lbl436f:
    cmp byte ptr ds:[334h],0h
    jnz short lbl44Cf
    cmp byte ptr ds:[326h],0h
    jnz short lbl44Cf
    mov word ptr [bp-2h],26h
    jmp near ptr lbl937f
lbl44Cf:
    cmp byte ptr ds:[340h],0h
    jnz short lbl45Cf
    mov word ptr [bp-2h],27h
    jmp near ptr lbl937f
    nop
lbl45Cf:
    cmp byte ptr ds:[33Ah],0h
    jnz short lbl46Cf
    mov word ptr [bp-2h],28h
    jmp near ptr lbl937f
    nop
lbl46Cf:
    cmp byte ptr ds:[32Dh],0h
    jnz short lbl47Cf
    mov word ptr [bp-2h],29h
    jmp near ptr lbl937f
    nop
lbl47Cf:
    cmp byte ptr ds:[33Bh],0h
    jnz short lbl48Cf
    mov word ptr [bp-2h],2Ah
    jmp near ptr lbl937f
    nop
lbl48Cf:
    cmp byte ptr ds:[33Ch],0h
    jnz short lbl49Cf
    mov word ptr [bp-2h],2Bh
    jmp near ptr lbl937f
    nop
lbl49Cf:
    cmp byte ptr ds:[33Dh],0h
    jnz short lbl4ACf
    mov word ptr [bp-2h],2Ch
    jmp near ptr lbl937f
    nop
lbl4ACf:
    cmp byte ptr ds:[333h],0h
    jnz short lbl4BCf
    mov word ptr [bp-2h],2Dh
    jmp near ptr lbl937f
    nop
lbl4BCf:
    cmp byte ptr ds:[332h],0h
    jnz short lbl4CCf
    mov word ptr [bp-2h],2Eh
    jmp near ptr lbl937f
    nop
lbl4CCf:
    cmp byte ptr ds:[33Eh],0h
    jnz short lbl4DCf
    mov word ptr [bp-2h],2Fh
    jmp near ptr lbl937f
    nop
lbl4DCf:
    mov ax,0D9h
    push ax
    call mf4e0
    add sp,2h
    cmp ax,155h
    jz short lbl4F6f
    mov word ptr [bp-2h],30h
    jmp near ptr lbl937f
    nop
lbl4F6f:
    mov ax,1Ah
    push ax
    call mf4fa
    add sp,2h
    or ax,ax
    jz short lbl50Ef
    mov word ptr [bp-2h],46h
    jmp near ptr lbl937f
lbl50Ef:
    cmp byte ptr ds:[328h],0h
    jnz short lbl51Ef
    mov word ptr [bp-2h],31h
    jmp near ptr lbl937f
    nop
lbl51Ef:
    cmp byte ptr ds:[33Fh],0h
    jnz short lbl52Ef
    mov word ptr [bp-2h],32h
    jmp near ptr lbl937f
    nop
lbl52Ef:
    cmp byte ptr ds:[329h],0h
    jnz short lbl53Ef
    mov word ptr [bp-2h],33h
    jmp near ptr lbl937f
    nop
lbl53Ef:
    mov ax,105h
    push ax
    mov ax,90h
    push ax
    call mf546
    add sp,4h
    or ax,ax
    jnz short lbl55Af
    mov word ptr [bp-2h],34h
    jmp near ptr lbl937f
lbl55Af:
    mov ax,5h
    push ax
    mov ax,107h
    push ax
    call mf562
    add sp,4h
    or ax,ax
    jnz short lbl576f
    mov word ptr [bp-2h],35h
    jmp near ptr lbl937f
lbl576f:
    mov ax,5h
    push ax
    mov ax,10Ch
    push ax
    call mf57e
    add sp,4h
    or ax,ax
    jnz short lbl592f
    mov word ptr [bp-2h],3Ah
    jmp near ptr lbl937f
lbl592f:
    mov ax,126h
    push ax
    mov ax,127h
    push ax
    call mf59a
    add sp,4h
    or ax,ax
    jz short lbl5B6f
    cmp byte ptr ds:[356h],0h
    jnz short lbl5B6f
    mov word ptr [bp-2h],3Ch
    jmp near ptr lbl937f
    nop
lbl5B6f:
    mov ax,0Ah
    push ax
    mov ax,138h
    push ax
    call mf5be
    add sp,4h
    or ax,ax
    jnz short lbl5D2f
    mov word ptr [bp-2h],3Dh
    jmp near ptr lbl937f
lbl5D2f:
    mov ax,128h
    push ax
    mov ax,138h
    push ax
    call mf5da
    add sp,4h
    or ax,ax
    jnz short lbl602f
    mov ax,0Ah
    push ax
    mov ax,127h
    push ax
    call mf5ee
    add sp,4h
    or ax,ax
    jnz short lbl602f
    mov word ptr [bp-2h],3Eh
    jmp near ptr lbl937f
lbl602f:
    mov ax,0Ah
    push ax
    mov ax,127h
    push ax
    call mf60a
    add sp,4h
    or ax,ax
    jnz short lbl61Ef
    mov word ptr [bp-2h],3Fh
    jmp near ptr lbl937f
lbl61Ef:
    mov ax,1h
    push ax
    mov ax,127h
    push ax
    call mf626
    add sp,4h
    or ax,ax
    jz short lbl63Af
    mov word ptr [bp-2h],5Bh
    jmp near ptr lbl937f
lbl63Af:
    mov ax,11h
    push ax
    mov ax,127h
    push ax
    call mf642
    add sp,4h
    or ax,ax
    jz short lbl66Af
    mov ax,0Ah
    push ax
    mov ax,124h
    push ax
    call mf656
    add sp,4h
    or ax,ax
    jnz short lbl66Af
    mov word ptr [bp-2h],40h
    jmp near ptr lbl937f
lbl66Af:
    mov ax,5h
    push ax
    mov ax,13Eh
    push ax
    call mf672
    add sp,4h
    or ax,ax
    jnz short lbl692f
    cmp word ptr ds:[256h],139h
    jnz short lbl68Cf
    mov ax,41h
    jmp near ptr lbl58b
lbl68Cf:
    mov ax,42h
    jmp near ptr lbl58b
lbl692f:
    cmp word ptr ds:[2D0h],1h
    jnz short lbl69Cf
    jmp near ptr lbl932f
lbl69Cf:
    cmp word ptr ds:[2D0h],2h
    jnz short lbl6ADf
    cmp word ptr ds:[2D2h],4h
    jnl short lbl6ADf
    jmp near ptr lbl932f
lbl6ADf:
    cmp word ptr ds:[2D0h],2h
    jnz short lbl6C4f
    cmp word ptr ds:[2D2h],4h
    jnz short lbl6C4f
    mov word ptr [bp-2h],44h
    jmp near ptr lbl937f
    nop
lbl6C4f:
    mov ax,1h
    push ax
    mov ax,14Eh
    push ax
    call mf6cc
    add sp,4h
    or ax,ax
    jz short lbl6E0f
    mov word ptr [bp-2h],45h
    jmp near ptr lbl937f
lbl6E0f:
    mov ax,5h
    push ax
    mov ax,14Fh
    push ax
    call mf6e8
    add sp,4h
    or ax,ax
    jnz short lbl6FCf
    mov word ptr [bp-2h],5Ch
    jmp near ptr lbl937f
lbl6FCf:
    mov ax,5h
    push ax
    mov ax,158h
    push ax
    call mf704
    add sp,4h
    or ax,ax
    jnz short lbl718f
    mov word ptr [bp-2h],47h
    jmp near ptr lbl937f
lbl718f:
    mov ax,5h
    push ax
    mov ax,160h
    push ax
    call mf720
    add sp,4h
    or ax,ax
    jnz short lbl734f
    mov word ptr [bp-2h],48h
    jmp near ptr lbl937f
lbl734f:
    cmp byte ptr ds:[35Bh],0h
    jnz short lbl744f
    mov word ptr [bp-2h],49h
    jmp near ptr lbl937f
    nop
lbl744f:
    mov ax,5h
    push ax
    mov ax,162h
    push ax
    call mf74c
    add sp,4h
    or ax,ax
    jnz short lbl760f
    mov word ptr [bp-2h],4Ah
    jmp near ptr lbl937f
lbl760f:
    mov ax,163h
    push ax
    mov ax,15Eh
    push ax
    call mf768
    add sp,4h
    or ax,ax
    jnz short lbl77Cf
    mov word ptr [bp-2h],4Ch
    jmp near ptr lbl937f
lbl77Cf:
    mov ax,0Ah
    push ax
    mov ax,155h
    push ax
    call mf784
    add sp,4h
    or ax,ax
    jnz short lbl798f
    mov word ptr [bp-2h],4Dh
    jmp near ptr lbl937f
lbl798f:
    cmp byte ptr ds:[357h],0h
    jnz short lbl7A8f
    mov word ptr [bp-2h],38h
    jmp near ptr lbl937f
    nop
lbl7A8f:
    mov ax,5h
    push ax
    mov ax,157h
    push ax
    call mf7b0
    add sp,4h
    or ax,ax
    jnz short lbl7C4f
    mov word ptr [bp-2h],4Fh
    jmp near ptr lbl937f
lbl7C4f:
    mov ax,5h
    push ax
    mov ax,166h
    push ax
    call mf7cc
    add sp,4h
    or ax,ax
    jnz short lbl7DBf
    jmp near ptr lbl92Af
lbl7DBf:
    mov ax,5h
    push ax
    mov ax,169h
    push ax
    call mf7e3
    add sp,4h
    or ax,ax
    jnz short lbl7F2f
    jmp near ptr lbl92Af
lbl7F2f:
    mov ax,5h
    push ax
    mov ax,168h
    push ax
    call mf7fa
    add sp,4h
    or ax,ax
    jnz short lbl80Ef
    mov word ptr [bp-2h],51h
    jmp near ptr lbl937f
lbl80Ef:
    mov ax,5h
    push ax
    mov ax,170h
    push ax
    call mf816
    add sp,4h
    or ax,ax
    jnz short lbl86Ef
    mov ax,16Dh
    push ax
    mov ax,157h
    push ax
    call mf82a
    add sp,4h
    or ax,ax
    jnz short lbl83Ef
    mov word ptr [bp-2h],52h
    jmp near ptr lbl937f
lbl83Ef:
    cmp byte ptr ds:[359h],0h
    jnz short lbl84Ef
    mov word ptr [bp-2h],53h
    jmp near ptr lbl937f
    nop
lbl84Ef:
    mov ax,16Ch
    push ax
    mov ax,16Eh
    push ax
    call mf856
    add sp,4h
    or ax,ax
    jnz short lbl865f
    jmp near ptr lbl937f
lbl865f:
    mov word ptr [bp-2h],54h
    jmp near ptr lbl937f
    nop
lbl86Ef:
    cmp word ptr ds:[2D8h],0Ah
    jnl short lbl87Ef
    mov word ptr [bp-2h],55h
    jmp near ptr lbl937f
    nop
lbl87Ef:
    mov ax,5h
    push ax
    mov ax,174h
    push ax
    call mf886
    add sp,4h
    or ax,ax
    jnz short lbl89Af
    mov word ptr [bp-2h],56h
    jmp near ptr lbl937f
lbl89Af:
    mov ax,5h
    push ax
    mov ax,177h
    push ax
    call mf8a2
    add sp,4h
    or ax,ax
    jnz short lbl8B8f
    mov word ptr [bp-2h],57h
    jmp near ptr lbl937f
    nop
    nop
lbl8B8f:
    mov ax,12h
    push ax
    mov ax,177h
    push ax
    call mf8c0
    add sp,4h
    or ax,ax
    jnz short lbl8D4f
    mov word ptr [bp-2h],58h
    jmp short lbl937f
    nop
lbl8D4f:
    mov ax,8h
    push ax
    mov ax,15Fh
    push ax
    call mf8dc
    add sp,4h
    or ax,ax
    jnz short lbl8F0f
    mov word ptr [bp-2h],59h
    jmp short lbl937f
    nop
lbl8F0f:
    mov ax,5h
    push ax
    mov ax,178h
    push ax
    call mf8f8
    add sp,4h
    or ax,ax
    jnz short lbl90Cf
    mov word ptr [bp-2h],5Ah
    jmp short lbl937f
    nop
lbl90Cf:
    mov ax,5h
    push ax
    mov ax,17Fh
    push ax
    call mf914
    add sp,4h
    cmp ax, offset mi91c
    db 1Bh, 0C0h ; override
    and ax, offset mi921
    add ax, offset mi924
    jmp near ptr lbl58b
lbl92Af:
    mov word ptr [bp-2h],50h
    jmp short lbl937f
    nop
lbl932f:
    mov word ptr [bp-2h],43h
lbl937f:
    mov ax,1h
    push ax
    mov es, ds:[5AA4h]
    mov bx,word ptr [bp-2h]
    mov ax,bx
    add bx,bx
    add bx,ax
    add bx,bx
    push word ptr es:[bx+md94a]
    mov ax,803Fh
    push ax
    mov si,bx
    call mf955
    add sp,6h
    mov ax,word ptr [bp-2h]
    add ax,4C7h
    mov word ptr ds:[6A10h],ax
    mov es, ds:[5AA4h]
    mov ax,word ptr es:[si+md96a]
    mov dx,word ptr es:[si+md96f]
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
