_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mn439:NEAR
    EXTRN mi831:NEAR
    EXTRN mf1e0:FAR
    EXTRN mi150:NEAR
    EXTRN mn43:NEAR
    EXTRN mn4d:NEAR
    EXTRN mid1:NEAR
    EXTRN mi82e:NEAR
    EXTRN mn170:NEAR
    EXTRN mn412:NEAR
    EXTRN mn3fb:NEAR
    EXTRN mn379:NEAR
    EXTRN mn653:NEAR
    EXTRN midc:NEAR
    EXTRN mf6:FAR
    EXTRN mn3e4:NEAR
    EXTRN mn326:NEAR
    EXTRN mn583:NEAR
    EXTRN mn306:NEAR
    EXTRN mf570:FAR
    EXTRN mn884:NEAR
    EXTRN mn52d:NEAR
    EXTRN mn6e9:NEAR
    EXTRN mn697:NEAR
    EXTRN mn72e:NEAR
    EXTRN mn161:NEAR
    EXTRN mn815:NEAR
    EXTRN mi14b:NEAR
    EXTRN mn785:NEAR
    EXTRN mn4b8:NEAR
    EXTRN mn79c:NEAR
mnem_unit:
    push bp
    mov bp,sp
    mov ax,1B6h
    call mf6
    push di
    push si
    xor ax,ax
    mov byte ptr [bp-1AEh],al
    mov word ptr [bp-190h],ax
    mov word ptr [bp-192h],ax
lbl1Bb:
    les bx, dword ptr [bp+0Ah]
    cmp byte ptr es:[bx],0h
    jnz short lbl27f
    jmp near ptr lbl8B6f
lbl27f:
    mov bl,byte ptr es:[bx]
    sub bh,bh
    test byte ptr [bx+56A5h],8h
    jz short lbl62f
    dec word ptr [bp-190h]
    lea ax,word ptr [bp-190h]
    push ss
    push ax
    push word ptr [bp+8h]
    push word ptr [bp+6h]
    call mn43
    push ax
    push word ptr [bp+8h]
    push word ptr [bp+6h]
    call mn4d
lbl50b:
    inc word ptr [bp+0Ah]
    les bx, dword ptr [bp+0Ah]
    mov bl,byte ptr es:[bx]
    sub bh,bh
    test byte ptr [bx+56A5h],8h
    jnz short lbl50b
lbl62f:
    mov bx,word ptr [bp+0Ah]
    cmp byte ptr es:[bx],25h
    jz short lbl6Ef
    jmp near ptr lbl87Af
lbl6Ef:
    xor al,al
    mov byte ptr [bp-1A8h],al
    mov byte ptr [bp-19Ch],al
    mov byte ptr [bp-1AAh],al
    mov byte ptr [bp-1A6h],al
    mov byte ptr [bp-1A4h],al
    mov byte ptr [bp-1ACh],al
    mov byte ptr [bp-1A0h],al
    xor ax,ax
    mov word ptr [bp-196h],ax
    mov word ptr [bp-19Ah],ax
    mov word ptr [bp-198h],ax
    mov word ptr [bp-180h],ax
    mov word ptr [bp-182h],ax
lblA2b:
    cmp byte ptr [bp-1A0h],0h
    jnz short lbl118f
    inc word ptr [bp+0Ah]
    les bx, dword ptr [bp+0Ah]
    sub ah,ah
    mov al,byte ptr es:[bx]
    mov bx,ax
    test byte ptr [bx+56A5h],4h
    jz short lblDCf
    inc word ptr [bp-19Ah]
    mov cx,word ptr [bp-198h]
    mov dx,cx
    add cx,cx
    add cx,cx
    add cx,dx
    add cx,cx
    add ax,cx
    sub ax, offset mid1
    mov word ptr [bp-198h],ax
    jmp short lblA2b
    nop
    nop
lblDCf:
    cmp ax, offset midc
    jz short lblFEf
    ja short lbl112f
    cmp al,4Ch
    jz short lblFAf
    jg short lbl10Af
    sub al,2Ah
    jz short lbl104f
    sub al,1Ch
    jz short lblA2b
    jmp short lbl112f
    nop
lblF4b:
    inc byte ptr [bp-19Ch]
    jmp short lblA2b
lblFAf:
    inc byte ptr [bp-1A4h]
lblFEf:
    inc byte ptr [bp-1A4h]
    jmp short lblA2b
lbl104f:
    inc byte ptr [bp-1ACh]
    jmp short lblA2b
lbl10Af:
    sub al,4Eh
    jz short lblA2b
    sub al,1Ah
    jz short lblF4b
lbl112f:
    inc byte ptr [bp-1A0h]
    jmp short lblA2b
lbl118f:
    cmp byte ptr [bp-1ACh],0h
    jnz short lbl135f
    les bx, dword ptr [bp+0Eh]
    add word ptr [bp+0Eh],4h
    mov ax,word ptr es:[bx]
    mov dx,word ptr es:[bx+2h]
    mov word ptr [bp-186h],ax
    mov word ptr [bp-184h],dx
lbl135f:
    mov byte ptr [bp-1A0h],0h
    les bx, dword ptr [bp+0Ah]
    mov al,byte ptr es:[bx]
    or al,20h
    sub ah,ah
    mov di,ax
    cmp di,6Eh
    jz short lbl175f
    cmp ax, offset mi14b
    jz short lbl166f
    cmp ax, offset mi150
    jz short lbl166f
    lea ax,word ptr [bp-190h]
    push ss
    push ax
    push word ptr [bp+8h]
    push word ptr [bp+6h]
    call mn161
    jmp short lbl173f
lbl166f:
    inc word ptr [bp-190h]
    push word ptr [bp+8h]
    push word ptr [bp+6h]
    call mn170
lbl173f:
    mov si,ax
lbl175f:
    cmp word ptr [bp-19Ah],0h
    jz short lbl186f
    cmp word ptr [bp-198h],0h
    jnz short lbl186f
    jmp near ptr lbl80Af
lbl186f:
    mov ax,di
    jmp near ptr lbl82Ef
    nop
    cmp word ptr [bp-19Ah],0h
    jnz short lbl19Bf
    inc word ptr [bp-19Ah]
    inc word ptr [bp-198h]
lbl19Bf:
    mov word ptr [bp-18Eh],5616h
lbl1A1b:
    mov word ptr [bp-18Ch],ds
    jmp short lbl1D0f
    nop
    mov word ptr [bp-18Eh],5610h
    jmp short lbl1A1b
    inc word ptr [bp+0Ah]
    mov ax,word ptr [bp+0Ah]
    mov dx,word ptr [bp+0Ch]
    mov word ptr [bp-18Eh],ax
    mov word ptr [bp-18Ch],dx
    mov es,dx
    mov bx,ax
    cmp byte ptr es:[bx],5Eh
    jnz short lbl1D4f
    inc ax
    mov word ptr [bp-18Eh],ax
lbl1D0f:
    dec byte ptr [bp-1AAh]
lbl1D4f:
    mov ax,20h
    push ax
    xor ax,ax
    push ax
    lea ax,word ptr [bp-20h]
    push ss
    push ax
    call mf1e0
    add sp,8h
    cmp di,7Bh
    jz short lbl1F0f
    jmp near ptr lbl2CAf
lbl1F0f:
    les bx, dword ptr [bp-18Eh]
    cmp byte ptr es:[bx],5Dh
    jz short lbl1FDf
    jmp near ptr lbl2CAf
lbl1FDf:
    mov byte ptr [bp-1A8h],5Dh
    inc word ptr [bp-18Eh]
    mov byte ptr [bp-15h],20h
    jmp near ptr lbl2CAf
    nop
lbl20Eb:
    mov al,byte ptr es:[bx]
    mov byte ptr [bp-19Eh],al
    inc word ptr [bp-18Eh]
    cmp al,2Dh
    jnz short lbl22Ef
    cmp byte ptr [bp-1A8h],0h
    jz short lbl22Ef
    mov bx,word ptr [bp-18Eh]
    cmp byte ptr es:[bx],5Dh
    jnz short lbl26Cf
lbl22Ef:
    mov bl,byte ptr [bp-19Eh]
    mov byte ptr [bp-1A8h],bl
    mov cl,3h
    mov dx,cx
    mov cl,bl
    and cl,7h
    mov bx,cx
    mov cl,dl
    mov word ptr [bp-1B0h],cx
    mov cl,bl
    mov bl,1h
    shl bl,cl
    mov cl,byte ptr [bp-1B0h]
    mov word ptr [bp-1B2h],bx
    mov bl,byte ptr [bp-19Eh]
    shr bl,cl
    sub bh,bh
    lea ax,word ptr [bp-20h]
    add bx,ax
    mov al,byte ptr [bp-1B2h]
    or byte ptr ss:[bx],al
    jmp short lbl2CAf
    nop
lbl26Cf:
    inc word ptr [bp-18Eh]
    mov al,byte ptr es:[bx]
    mov byte ptr [bp-19Eh],al
    cmp al,byte ptr [bp-1A8h]
    jna short lbl284f
    mov byte ptr [bp-1A2h],al
    jmp short lbl294f
    nop
lbl284f:
    mov al,byte ptr [bp-1A8h]
    mov byte ptr [bp-1A2h],al
    mov al,byte ptr [bp-19Eh]
    mov byte ptr [bp-1A8h],al
lbl294f:
    mov al,byte ptr [bp-1A8h]
    mov byte ptr [bp-19Eh],al
    jmp short lbl2BBf
lbl29Eb:
    mov bl,al
    mov cl,3h
    shr bl,cl
    sub bh,bh
    lea cx,word ptr [bp-20h]
    add bx,cx
    mov cl,al
    and cl,7h
    mov al,1h
    shl al,cl
    or byte ptr ss:[bx],al
    inc byte ptr [bp-19Eh]
lbl2BBf:
    mov al,byte ptr [bp-19Eh]
    cmp byte ptr [bp-1A2h],al
    jnc short lbl29Eb
    mov byte ptr [bp-1A8h],0h
lbl2CAf:
    les bx, dword ptr [bp-18Eh]
    cmp byte ptr es:[bx],5Dh
    jz short lbl2D7f
    jmp near ptr lbl20Eb
lbl2D7f:
    cmp byte ptr es:[bx],0h
    jnz short lbl2E0f
    jmp near ptr lbl8B6f
lbl2E0f:
    cmp di,7Bh
    jnz short lbl2EBf
    mov word ptr [bp+0Ah],bx
    mov word ptr [bp+0Ch],es
lbl2EBf:
    mov ax,word ptr [bp-186h]
    mov dx,word ptr [bp-184h]
    mov word ptr [bp-18Ah],ax
    mov word ptr [bp-188h],dx
    dec word ptr [bp-190h]
    push si
    push word ptr [bp+8h]
    push word ptr [bp+6h]
    call mn306
lbl309b:
    cmp word ptr [bp-19Ah],0h
    jz short lbl31Cf
    mov ax,word ptr [bp-198h]
    dec word ptr [bp-198h]
    or ax,ax
    jz short lbl37Cf
lbl31Cf:
    inc word ptr [bp-190h]
    push word ptr [bp+8h]
    push word ptr [bp+6h]
    call mn326
    mov si,ax
    cmp si,0FFFFFFFFFFFFFFFFh
    jz short lbl36Ef
    mov cl,3h
    mov bx,ax
    sar bx,cl
    lea ax,word ptr [bp-20h]
    add bx,ax
    mov al,byte ptr ss:[bx]
    xor al,byte ptr [bp-1AAh]
    cbw
    mov cx,si
    and cl,7h
    mov dx,1h
    shl dx,cl
    db 85h, 0C2h ; override
    jz short lbl36Ef
    cmp byte ptr [bp-1ACh],0h
    jnz short lbl368f
    mov ax,si
    les bx, dword ptr [bp-186h]
    inc word ptr [bp-186h]
    mov byte ptr es:[bx],al
    jmp short lbl309b
    nop
lbl368f:
    inc word ptr [bp-18Ah]
    jmp short lbl309b
lbl36Ef:
    dec word ptr [bp-190h]
    push si
    push word ptr [bp+8h]
    push word ptr [bp+6h]
    call mn379
lbl37Cf:
    mov ax,word ptr [bp-186h]
    mov dx,word ptr [bp-184h]
    cmp word ptr [bp-18Ah],ax
    jnz short lbl393f
    cmp word ptr [bp-188h],dx
    jnz short lbl393f
    jmp near ptr lbl8B6f
lbl393f:
    cmp byte ptr [bp-1ACh],0h
    jz short lbl39Df
    jmp near ptr lbl870f
lbl39Df:
    inc word ptr [bp-192h]
    cmp di,63h
    jnz short lbl3A9f
    jmp near ptr lbl870f
lbl3A9f:
    mov bx,ax
    mov es,dx
    mov byte ptr es:[bx],0h
    jmp near ptr lbl870f
    mov di,64h
    cmp si,2Dh
    jnz short lbl3C2f
    inc byte ptr [bp-1A6h]
    jmp short lbl3C7f
lbl3C2f:
    cmp si,2Bh
    jnz short lbl3E9f
lbl3C7f:
    dec word ptr [bp-198h]
    jnz short lbl3DAf
    cmp word ptr [bp-19Ah],0h
    jz short lbl3DAf
    inc byte ptr [bp-1A0h]
    jmp short lbl3E9f
lbl3DAf:
    inc word ptr [bp-190h]
    push word ptr [bp+8h]
    push word ptr [bp+6h]
    call mn3e4
    mov si,ax
lbl3E9f:
    cmp si,30h
    jz short lbl3F1f
    jmp near ptr lbl586f
lbl3F1f:
    inc word ptr [bp-190h]
    push word ptr [bp+8h]
    push word ptr [bp+6h]
    call mn3fb
    mov si,ax
    cmp al,78h
    jz short lbl408f
    cmp al,58h
    jnz short lbl41Ef
lbl408f:
    inc word ptr [bp-190h]
    push word ptr [bp+8h]
    push word ptr [bp+6h]
    call mn412
    mov si,ax
    mov di,78h
    jmp near ptr lbl586f
    nop
lbl41Ef:
    inc word ptr [bp-196h]
    cmp di,78h
    jz short lbl42Ef
    mov di,6Fh
    jmp near ptr lbl586f
    nop
lbl42Ef:
    dec word ptr [bp-190h]
    push ax
    push word ptr [bp+8h]
    push word ptr [bp+6h]
    call mn439
    mov si,30h
    jmp near ptr lbl586f
    cmp byte ptr [bp-19Ch],0h
    jnz short lbl450f
    inc byte ptr [bp-1A4h]
    mov di,46h
lbl450f:
    cmp si,2Dh
    jnz short lbl45Cf
    inc byte ptr [bp-1A6h]
    jmp short lbl464f
    nop
lbl45Cf:
    cmp si,2Bh
    jz short lbl464f
    jmp near ptr lbl586f
lbl464f:
    dec word ptr [bp-198h]
    jz short lbl46Df
    jmp near ptr lbl523f
lbl46Df:
    cmp word ptr [bp-19Ah],0h
    jnz short lbl477f
    jmp near ptr lbl523f
lbl477b:
lbl477f:
    inc byte ptr [bp-1A0h]
    jmp near ptr lbl586f
lbl47Eb:
    cmp di,78h
    jz short lbl490f
    cmp di,70h
    jz short lbl490f
    cmp di,46h
    jz short lbl490f
    jmp near ptr lbl534f
lbl490f:
    test byte ptr [si+56A5h],80h
    jz short lbl4C0f
    mov ax,word ptr [bp-182h]
    mov dx,word ptr [bp-180h]
    add ax,ax
    rcl dx,1
    add ax,ax
    rcl dx,1
    add ax,ax
    rcl dx,1
    add ax,ax
    rcl dx,1
    mov word ptr [bp-182h],ax
    mov word ptr [bp-180h],dx
    push si
    call mn4b8
    mov si,ax
    jmp short lbl4FCf
    nop
lbl4C0f:
    cmp di,46h
    jnz short lbl4F8f
    cmp word ptr [bp-196h],0h
    jz short lbl4F8f
    cmp si,3Ah
    jnz short lbl4F2f
    mov ax,word ptr [bp-182h]
    mov word ptr [bp-194h],ax
    sub ax,ax
    mov word ptr [bp-180h],ax
    mov word ptr [bp-182h],ax
    mov word ptr [bp-196h],0FFFFh
    mov di,70h
    mov si,30h
    jmp short lbl4FCf
    nop
lbl4F2f:
    mov word ptr [bp-196h],0h
lbl4F8b:
lbl4F8f:
    inc byte ptr [bp-1A0h]
lbl4FCb:
lbl4FCf:
    cmp byte ptr [bp-1A0h],0h
    jnz short lbl578f
    inc word ptr [bp-196h]
    lea ax,word ptr [si-30h]
    cwd
    add word ptr [bp-182h],ax
    adc word ptr [bp-180h],dx
    cmp word ptr [bp-19Ah],0h
    jz short lbl523f
    dec word ptr [bp-198h]
    jnz short lbl523f
    jmp near ptr lbl477b
lbl523f:
    inc word ptr [bp-190h]
    push word ptr [bp+8h]
    push word ptr [bp+6h]
    call mn52d
    mov si,ax
    jmp short lbl586f
lbl534f:
    test byte ptr [si+56A5h],4h
    jz short lbl4F8b
    cmp di,6Fh
    jnz short lbl564f
    cmp si,38h
    jnl short lbl4F8b
    mov ax,word ptr [bp-182h]
    mov dx,word ptr [bp-180h]
    add ax,ax
    rcl dx,1
    add ax,ax
    rcl dx,1
    add ax,ax
    rcl dx,1
    mov word ptr [bp-182h],ax
    mov word ptr [bp-180h],dx
    jmp short lbl4FCb
    nop
lbl564f:
    mov ax,0Ah
    cwd
    push dx
    push ax
    lea ax,word ptr [bp-182h]
    push ss
    push ax
    call mf570
    jmp short lbl4FCb
    nop
lbl578f:
    dec word ptr [bp-190h]
    push si
    push word ptr [bp+8h]
    push word ptr [bp+6h]
    call mn583
lbl586f:
    cmp byte ptr [bp-1A0h],0h
    jnz short lbl590f
    jmp near ptr lbl47Eb
lbl590f:
    cmp di,70h
    jnz short lbl5A8f
    cmp byte ptr [bp-1A4h],0h
    jz short lbl5A8f
    mov ax,word ptr [bp-194h]
    mov cx,word ptr [bp-182h]
    mov word ptr [bp-180h],ax
lbl5A8f:
    cmp byte ptr [bp-1A6h],0h
    jz short lbl5BCf
    neg word ptr [bp-182h]
    adc word ptr [bp-180h],0h
    neg word ptr [bp-180h]
lbl5BCf:
    cmp di,46h
    jnz short lbl5C7f
    mov word ptr [bp-196h],0h
lbl5C7f:
    cmp word ptr [bp-196h],0h
    jnz short lbl5D1f
    jmp near ptr lbl8B6f
lbl5D1f:
    cmp byte ptr [bp-1ACh],0h
    jz short lbl5DBf
    jmp near ptr lbl870f
lbl5DBf:
    inc word ptr [bp-192h]
lbl5DFb:
    cmp byte ptr [bp-1A4h],0h
    jz short lbl5FCf
    mov ax,word ptr [bp-182h]
    mov dx,word ptr [bp-180h]
    les bx, dword ptr [bp-186h]
    mov word ptr es:[bx],ax
    mov word ptr es:[bx+2h],dx
    jmp near ptr lbl870f
lbl5FCf:
    mov ax,word ptr [bp-182h]
    les bx, dword ptr [bp-186h]
    mov word ptr es:[bx],ax
    jmp near ptr lbl870f
    mov ax,word ptr [bp-190h]
    cwd
    mov word ptr [bp-182h],ax
    mov word ptr [bp-180h],dx
    jmp short lbl5DFb
    nop
    lea ax,word ptr [bp-17Eh]
    mov word ptr [bp-18Eh],ax
    mov word ptr [bp-18Ch],ss
    cmp si,2Dh
    jnz short lbl640f
    mov bx,ax
    mov byte ptr ss:[bx],2Dh
    lea ax,word ptr [bp-17Dh]
    mov word ptr [bp-18Eh],ax
    mov word ptr [bp-18Ch],ss
    jmp short lbl645f
    nop
lbl640f:
    cmp si,2Bh
    jnz short lbl658f
lbl645f:
    dec word ptr [bp-198h]
    inc word ptr [bp-190h]
    push word ptr [bp+8h]
    push word ptr [bp+6h]
    call mn653
    mov si,ax
lbl658f:
    cmp word ptr [bp-19Ah],0h
    jz short lbl667f
    cmp word ptr [bp-198h],15Dh
    jng short lbl69Cf
lbl667f:
    mov word ptr [bp-198h],15Dh
    jmp short lbl69Cf
    nop
lbl670b:
    mov ax,word ptr [bp-198h]
    dec word ptr [bp-198h]
    or ax,ax
    jz short lbl6A3f
    inc word ptr [bp-196h]
    mov ax,si
    les bx, dword ptr [bp-18Eh]
    inc word ptr [bp-18Eh]
    mov byte ptr es:[bx],al
    inc word ptr [bp-190h]
    push word ptr [bp+8h]
    push word ptr [bp+6h]
    call mn697
    mov si,ax
lbl69Cf:
    test byte ptr [si+56A5h],4h
    jnz short lbl670b
lbl6A3f:
    cmp si,2Eh
    jnz short lbl6F5f
    mov ax,word ptr [bp-198h]
    dec word ptr [bp-198h]
    or ax,ax
    jz short lbl6F5f
    les bx, dword ptr [bp-18Eh]
    inc word ptr [bp-18Eh]
    mov byte ptr es:[bx],2Eh
    jmp short lbl6DFf
lbl6C2b:
    mov ax,word ptr [bp-198h]
    dec word ptr [bp-198h]
    or ax,ax
    jz short lbl6F5f
    inc word ptr [bp-196h]
    mov ax,si
    les bx, dword ptr [bp-18Eh]
    inc word ptr [bp-18Eh]
    mov byte ptr es:[bx],al
lbl6DFf:
    inc word ptr [bp-190h]
    push word ptr [bp+8h]
    push word ptr [bp+6h]
    call mn6e9
    mov si,ax
    test byte ptr [si+56A5h],4h
    jnz short lbl6C2b
lbl6F5f:
    cmp word ptr [bp-196h],0h
    jnz short lbl6FFf
    jmp near ptr lbl791f
lbl6FFf:
    mov ax,si
    cmp al,65h
    jz short lbl70Cf
    cmp al,45h
    jz short lbl70Cf
    jmp near ptr lbl791f
lbl70Cf:
    mov ax,word ptr [bp-198h]
    dec word ptr [bp-198h]
    or ax,ax
    jz short lbl791f
    les bx, dword ptr [bp-18Eh]
    inc word ptr [bp-18Eh]
    mov byte ptr es:[bx],65h
    inc word ptr [bp-190h]
    push word ptr [bp+8h]
    push word ptr [bp+6h]
    call mn72e
    mov si,ax
    cmp si,2Dh
    jnz short lbl746f
    les bx, dword ptr [bp-18Eh]
    inc word ptr [bp-18Eh]
    mov byte ptr es:[bx],2Dh
    jmp short lbl74Bf
lbl746f:
    cmp si,2Bh
    jnz short lbl78Af
lbl74Bf:
    mov ax,word ptr [bp-198h]
    dec word ptr [bp-198h]
    or ax,ax
    jnz short lbl77Bf
    inc word ptr [bp-198h]
    jmp short lbl78Af
    nop
lbl75Eb:
    mov ax,word ptr [bp-198h]
    dec word ptr [bp-198h]
    or ax,ax
    jz short lbl791f
    inc word ptr [bp-196h]
    mov ax,si
    les bx, dword ptr [bp-18Eh]
    inc word ptr [bp-18Eh]
    mov byte ptr es:[bx],al
lbl77Bf:
    inc word ptr [bp-190h]
    push word ptr [bp+8h]
    push word ptr [bp+6h]
    call mn785
    mov si,ax
lbl78Af:
    test byte ptr [si+56A5h],4h
    jnz short lbl75Eb
lbl791f:
    dec word ptr [bp-190h]
    push si
    push word ptr [bp+8h]
    push word ptr [bp+6h]
    call mn79c
    cmp word ptr [bp-196h],0h
    jnz short lbl7A9f
    jmp near ptr lbl8B6f
lbl7A9f:
    cmp byte ptr [bp-1ACh],0h
    jz short lbl7B3f
    jmp near ptr lbl870f
lbl7B3f:
    inc word ptr [bp-192h]
    les bx, dword ptr [bp-18Eh]
    mov byte ptr es:[bx],0h
    cmp byte ptr [bp-1A4h],1h
    jng short lbl7E4f
    lea ax,word ptr [bp-17Eh]
    push ss
    push ax
    push word ptr [bp-184h]
    push word ptr [bp-186h]
    mov al,byte ptr [bp-1A4h]
    cbw
    push ax
    db 0FFh, 1Eh, 9Ah, 56h ; override
lbl7DEb:
    add sp,0Ah
    jmp near ptr lbl870f
lbl7E4f:
    lea ax,word ptr [bp-17Eh]
    push ss
    push ax
    push word ptr [bp-184h]
    push word ptr [bp-186h]
    mov al,byte ptr [bp-1A4h]
    cbw
    push ax
    db 0FFh, 1Eh, 86h, 56h ; override
    jmp short lbl7DEb
lbl7FEb:
    les bx, dword ptr [bp+0Ah]
    sub ah,ah
    mov al,byte ptr es:[bx]
    cmp ax,si
    jz short lbl81Cf
lbl80Ab:
lbl80Af:
    dec word ptr [bp-190h]
    push si
    push word ptr [bp+8h]
    push word ptr [bp+6h]
    call mn815
    jmp near ptr lbl8B6f
    nop
lbl81Cf:
    dec byte ptr [bp-1AEh]
    cmp byte ptr [bp-1ACh],0h
    jnz short lbl870f
    sub word ptr [bp+0Eh],4h
    jmp short lbl870f
    nop
lbl82Ef:
    sub ax, offset mi82e
    cmp ax, offset mi831
    ja short lbl7FEb
    add ax,ax
    xchg ax,bx
    jmp word ptr cs:[bx+22ECh]
    db 3Ah, 1Ch, 0FEh, 1Eh, 0C8h, 20h, 0C8h, 20h, 0C8h, 20h, 0ACh, 22h, 62h, 1Eh, 0ACh, 22h
    db 0ACh, 22h, 0ACh, 22h, 0ACh, 22h, 0B8h, 20h, 0FEh, 1Eh, 0F0h, 1Eh, 0ACh, 22h, 0ACh, 22h
    db 56h, 1Ch, 0ACh, 22h, 0FEh, 1Eh, 0ACh, 22h, 0ACh, 22h, 65h, 1Eh, 0ACh, 22h, 0ACh, 22h
    db 5Eh, 1Ch
lbl870f:
    inc byte ptr [bp-1AEh]
    inc word ptr [bp+0Ah]
    jmp short lbl89Bf
    nop
lbl87Af:
    inc word ptr [bp-190h]
    push word ptr [bp+8h]
    push word ptr [bp+6h]
    call mn884
    mov si,ax
    les bx, dword ptr [bp+0Ah]
    inc word ptr [bp+0Ah]
    mov al,byte ptr es:[bx]
    sub ah,ah
    cmp si,ax
    jz short lbl89Bf
    jmp near ptr lbl80Ab
lbl89Bf:
    cmp si,0FFFFFFFFFFFFFFFFh
    jz short lbl8A3f
    jmp near ptr lbl1Bb
lbl8A3f:
    les bx, dword ptr [bp+0Ah]
    cmp byte ptr es:[bx],25h
    jnz short lbl8B6f
    cmp byte ptr es:[bx+1h],6Eh
    jnz short lbl8B6f
    jmp near ptr lbl1Bb
lbl8B6f:
    cmp si,0FFFFFFFFFFFFFFFFh
    jnz short lbl8C9f
    cmp word ptr [bp-192h],0h
    jnz short lbl8C9f
    cmp byte ptr [bp-1AEh],0h
    jz short lbl8D0f
lbl8C9f:
    mov ax,word ptr [bp-192h]
    jmp short lbl8D2f
    nop
lbl8D0f:
    mov ax,si
lbl8D2f:
    pop si
    pop di
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
