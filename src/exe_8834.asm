_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi89a:NEAR
    EXTRN mn881:NEAR
    EXTRN mi89d:NEAR
    EXTRN mn467:NEAR
    EXTRN mn755:NEAR
    EXTRN mf47:FAR
    EXTRN mn4a5:NEAR
    EXTRN mn5ef:NEAR
    EXTRN mn450:NEAR
    EXTRN mn372:NEAR
    EXTRN mf20:FAR
    EXTRN mnb9:NEAR
    EXTRN mn47e:NEAR
    EXTRN mf5dc:FAR
    EXTRN mn524:NEAR
    EXTRN mn392:NEAR
    EXTRN mn599:NEAR
    EXTRN mf24c:FAR
    EXTRN mi1b7:NEAR
    EXTRN mn1cd:NEAR
    EXTRN mn7f1:NEAR
    EXTRN mn703:NEAR
    EXTRN mn3e5:NEAR
    EXTRN mf72:FAR
    EXTRN mn79a:NEAR
    EXTRN mi13d:NEAR
    EXTRN mn8f0:NEAR
    EXTRN mn6bf:NEAR
    EXTRN mn1dc:NEAR
    EXTRN mi1bc:NEAR
    EXTRN mnaf:NEAR
    EXTRN mn808:NEAR
    EXTRN mi148:NEAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,2h
    push di
    push si
    mov si,5420h
    xor di,di
    mov word ptr [bp-2h],di
    jmp short lbl33f
lbl12b:
    cmp word ptr [bp+4h],0h
    jnz short lbl30f
    test byte ptr [si+0Ah],2h
    jz short lbl30f
    push ds
    push si
    call mf20
    add sp,4h
    inc ax
    jnz short lbl30f
    mov word ptr [bp-2h],0FFFFh
lbl30b:
lbl30f:
    add si,0Ch
lbl33f:
    cmp word ptr ds:[5600h],si
    jc short lbl56f
    cmp word ptr [bp+4h],1h
    jnz short lbl12b
    test byte ptr [si+0Ah],83h
    jz short lbl12b
    push ds
    push si
    call mf47
    add sp,4h
    inc ax
    jz short lbl30b
    inc di
    jmp short lbl30b
    nop
lbl56f:
    cmp word ptr [bp+4h],1h
    jnz short lbl60f
    mov ax,di
    jmp short lbl63f
lbl60f:
    mov ax,word ptr [bp-2h]
lbl63f:
    pop si
    pop di
    mov sp,bp
    pop bp
    ret 2h
    nop
    push bp
    mov bp,sp
    mov ax,1B6h
    call mf72
    push di
    push si
    xor ax,ax
    mov byte ptr [bp-1AEh],al
    mov word ptr [bp-190h],ax
    mov word ptr [bp-192h],ax
lbl87b:
    les bx, dword ptr [bp+0Ah]
    cmp byte ptr es:[bx],0h
    jnz short lbl93f
    jmp near ptr lbl922f
lbl93f:
    mov bl,byte ptr es:[bx]
    sub bh,bh
    test byte ptr [bx+56A5h],8h
    jz short lblCEf
    dec word ptr [bp-190h]
    lea ax,word ptr [bp-190h]
    push ss
    push ax
    push word ptr [bp+8h]
    push word ptr [bp+6h]
    call mnaf
    push ax
    push word ptr [bp+8h]
    push word ptr [bp+6h]
    call mnb9
lblBCb:
    inc word ptr [bp+0Ah]
    les bx, dword ptr [bp+0Ah]
    mov bl,byte ptr es:[bx]
    sub bh,bh
    test byte ptr [bx+56A5h],8h
    jnz short lblBCb
lblCEf:
    mov bx,word ptr [bp+0Ah]
    cmp byte ptr es:[bx],25h
    jz short lblDAf
    jmp near ptr lbl8E6f
lblDAf:
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
lbl10Eb:
    cmp byte ptr [bp-1A0h],0h
    jnz short lbl184f
    inc word ptr [bp+0Ah]
    les bx, dword ptr [bp+0Ah]
    sub ah,ah
    mov al,byte ptr es:[bx]
    mov bx,ax
    test byte ptr [bx+56A5h],4h
    jz short lbl148f
    inc word ptr [bp-19Ah]
    mov cx,word ptr [bp-198h]
    mov dx,cx
    add cx,cx
    add cx,cx
    add cx,dx
    add cx,cx
    add ax,cx
    sub ax, offset mi13d
    mov word ptr [bp-198h],ax
    jmp short lbl10Eb
    nop
    nop
lbl148f:
    cmp ax, offset mi148
    jz short lbl16Af
    ja short lbl17Ef
    cmp al,4Ch
    jz short lbl166f
    jg short lbl176f
    sub al,2Ah
    jz short lbl170f
    sub al,1Ch
    jz short lbl10Eb
    jmp short lbl17Ef
    nop
lbl160b:
    inc byte ptr [bp-19Ch]
    jmp short lbl10Eb
lbl166f:
    inc byte ptr [bp-1A4h]
lbl16Af:
    inc byte ptr [bp-1A4h]
    jmp short lbl10Eb
lbl170f:
    inc byte ptr [bp-1ACh]
    jmp short lbl10Eb
lbl176f:
    sub al,4Eh
    jz short lbl10Eb
    sub al,1Ah
    jz short lbl160b
lbl17Ef:
    inc byte ptr [bp-1A0h]
    jmp short lbl10Eb
lbl184f:
    cmp byte ptr [bp-1ACh],0h
    jnz short lbl1A1f
    les bx, dword ptr [bp+0Eh]
    add word ptr [bp+0Eh],4h
    mov ax,word ptr es:[bx]
    mov dx,word ptr es:[bx+2h]
    mov word ptr [bp-186h],ax
    mov word ptr [bp-184h],dx
lbl1A1f:
    mov byte ptr [bp-1A0h],0h
    les bx, dword ptr [bp+0Ah]
    mov al,byte ptr es:[bx]
    or al,20h
    sub ah,ah
    mov di,ax
    cmp di,6Eh
    jz short lbl1E1f
    cmp ax, offset mi1b7
    jz short lbl1D2f
    cmp ax, offset mi1bc
    jz short lbl1D2f
    lea ax,word ptr [bp-190h]
    push ss
    push ax
    push word ptr [bp+8h]
    push word ptr [bp+6h]
    call mn1cd
    jmp short lbl1DFf
lbl1D2f:
    inc word ptr [bp-190h]
    push word ptr [bp+8h]
    push word ptr [bp+6h]
    call mn1dc
lbl1DFf:
    mov si,ax
lbl1E1f:
    cmp word ptr [bp-19Ah],0h
    jz short lbl1F2f
    cmp word ptr [bp-198h],0h
    jnz short lbl1F2f
    jmp near ptr lbl876f
lbl1F2f:
    mov ax,di
    jmp near ptr lbl89Af
    nop
    cmp word ptr [bp-19Ah],0h
    jnz short lbl207f
    inc word ptr [bp-19Ah]
    inc word ptr [bp-198h]
lbl207f:
    mov word ptr [bp-18Eh],5616h
lbl20Db:
    mov word ptr [bp-18Ch],ds
    jmp short lbl23Cf
    nop
    mov word ptr [bp-18Eh],5610h
    jmp short lbl20Db
    inc word ptr [bp+0Ah]
    mov ax,word ptr [bp+0Ah]
    mov dx,word ptr [bp+0Ch]
    mov word ptr [bp-18Eh],ax
    mov word ptr [bp-18Ch],dx
    mov es,dx
    mov bx,ax
    cmp byte ptr es:[bx],5Eh
    jnz short lbl240f
    inc ax
    mov word ptr [bp-18Eh],ax
lbl23Cf:
    dec byte ptr [bp-1AAh]
lbl240f:
    mov ax,20h
    push ax
    xor ax,ax
    push ax
    lea ax,word ptr [bp-20h]
    push ss
    push ax
    call mf24c
    add sp,8h
    cmp di,7Bh
    jz short lbl25Cf
    jmp near ptr lbl336f
lbl25Cf:
    les bx, dword ptr [bp-18Eh]
    cmp byte ptr es:[bx],5Dh
    jz short lbl269f
    jmp near ptr lbl336f
lbl269f:
    mov byte ptr [bp-1A8h],5Dh
    inc word ptr [bp-18Eh]
    mov byte ptr [bp-15h],20h
    jmp near ptr lbl336f
    nop
lbl27Ab:
    mov al,byte ptr es:[bx]
    mov byte ptr [bp-19Eh],al
    inc word ptr [bp-18Eh]
    cmp al,2Dh
    jnz short lbl29Af
    cmp byte ptr [bp-1A8h],0h
    jz short lbl29Af
    mov bx,word ptr [bp-18Eh]
    cmp byte ptr es:[bx],5Dh
    jnz short lbl2D8f
lbl29Af:
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
    jmp short lbl336f
    nop
lbl2D8f:
    inc word ptr [bp-18Eh]
    mov al,byte ptr es:[bx]
    mov byte ptr [bp-19Eh],al
    cmp al,byte ptr [bp-1A8h]
    jna short lbl2F0f
    mov byte ptr [bp-1A2h],al
    jmp short lbl300f
    nop
lbl2F0f:
    mov al,byte ptr [bp-1A8h]
    mov byte ptr [bp-1A2h],al
    mov al,byte ptr [bp-19Eh]
    mov byte ptr [bp-1A8h],al
lbl300f:
    mov al,byte ptr [bp-1A8h]
    mov byte ptr [bp-19Eh],al
    jmp short lbl327f
lbl30Ab:
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
lbl327f:
    mov al,byte ptr [bp-19Eh]
    cmp byte ptr [bp-1A2h],al
    jnc short lbl30Ab
    mov byte ptr [bp-1A8h],0h
lbl336f:
    les bx, dword ptr [bp-18Eh]
    cmp byte ptr es:[bx],5Dh
    jz short lbl343f
    jmp near ptr lbl27Ab
lbl343f:
    cmp byte ptr es:[bx],0h
    jnz short lbl34Cf
    jmp near ptr lbl922f
lbl34Cf:
    cmp di,7Bh
    jnz short lbl357f
    mov word ptr [bp+0Ah],bx
    mov word ptr [bp+0Ch],es
lbl357f:
    mov ax,word ptr [bp-186h]
    mov dx,word ptr [bp-184h]
    mov word ptr [bp-18Ah],ax
    mov word ptr [bp-188h],dx
    dec word ptr [bp-190h]
    push si
    push word ptr [bp+8h]
    push word ptr [bp+6h]
    call mn372
lbl375b:
    cmp word ptr [bp-19Ah],0h
    jz short lbl388f
    mov ax,word ptr [bp-198h]
    dec word ptr [bp-198h]
    or ax,ax
    jz short lbl3E8f
lbl388f:
    inc word ptr [bp-190h]
    push word ptr [bp+8h]
    push word ptr [bp+6h]
    call mn392
    mov si,ax
    cmp si,0FFFFFFFFFFFFFFFFh
    jz short lbl3DAf
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
    jz short lbl3DAf
    cmp byte ptr [bp-1ACh],0h
    jnz short lbl3D4f
    mov ax,si
    les bx, dword ptr [bp-186h]
    inc word ptr [bp-186h]
    mov byte ptr es:[bx],al
    jmp short lbl375b
    nop
lbl3D4f:
    inc word ptr [bp-18Ah]
    jmp short lbl375b
lbl3DAf:
    dec word ptr [bp-190h]
    push si
    push word ptr [bp+8h]
    push word ptr [bp+6h]
    call mn3e5
lbl3E8f:
    mov ax,word ptr [bp-186h]
    mov dx,word ptr [bp-184h]
    cmp word ptr [bp-18Ah],ax
    jnz short lbl3FFf
    cmp word ptr [bp-188h],dx
    jnz short lbl3FFf
    jmp near ptr lbl922f
lbl3FFf:
    cmp byte ptr [bp-1ACh],0h
    jz short lbl409f
    jmp near ptr lbl8DCf
lbl409f:
    inc word ptr [bp-192h]
    cmp di,63h
    jnz short lbl415f
    jmp near ptr lbl8DCf
lbl415f:
    mov bx,ax
    mov es,dx
    mov byte ptr es:[bx],0h
    jmp near ptr lbl8DCf
    mov di,64h
    cmp si,2Dh
    jnz short lbl42Ef
    inc byte ptr [bp-1A6h]
    jmp short lbl433f
lbl42Ef:
    cmp si,2Bh
    jnz short lbl455f
lbl433f:
    dec word ptr [bp-198h]
    jnz short lbl446f
    cmp word ptr [bp-19Ah],0h
    jz short lbl446f
    inc byte ptr [bp-1A0h]
    jmp short lbl455f
lbl446f:
    inc word ptr [bp-190h]
    push word ptr [bp+8h]
    push word ptr [bp+6h]
    call mn450
    mov si,ax
lbl455f:
    cmp si,30h
    jz short lbl45Df
    jmp near ptr lbl5F2f
lbl45Df:
    inc word ptr [bp-190h]
    push word ptr [bp+8h]
    push word ptr [bp+6h]
    call mn467
    mov si,ax
    cmp al,78h
    jz short lbl474f
    cmp al,58h
    jnz short lbl48Af
lbl474f:
    inc word ptr [bp-190h]
    push word ptr [bp+8h]
    push word ptr [bp+6h]
    call mn47e
    mov si,ax
    mov di,78h
    jmp near ptr lbl5F2f
    nop
lbl48Af:
    inc word ptr [bp-196h]
    cmp di,78h
    jz short lbl49Af
    mov di,6Fh
    jmp near ptr lbl5F2f
    nop
lbl49Af:
    dec word ptr [bp-190h]
    push ax
    push word ptr [bp+8h]
    push word ptr [bp+6h]
    call mn4a5
    mov si,30h
    jmp near ptr lbl5F2f
    cmp byte ptr [bp-19Ch],0h
    jnz short lbl4BCf
    inc byte ptr [bp-1A4h]
    mov di,46h
lbl4BCf:
    cmp si,2Dh
    jnz short lbl4C8f
    inc byte ptr [bp-1A6h]
    jmp short lbl4D0f
    nop
lbl4C8f:
    cmp si,2Bh
    jz short lbl4D0f
    jmp near ptr lbl5F2f
lbl4D0f:
    dec word ptr [bp-198h]
    jz short lbl4D9f
    jmp near ptr lbl58Ff
lbl4D9f:
    cmp word ptr [bp-19Ah],0h
    jnz short lbl4E3f
    jmp near ptr lbl58Ff
lbl4E3b:
lbl4E3f:
    inc byte ptr [bp-1A0h]
    jmp near ptr lbl5F2f
lbl4EAb:
    cmp di,78h
    jz short lbl4FCf
    cmp di,70h
    jz short lbl4FCf
    cmp di,46h
    jz short lbl4FCf
    jmp near ptr lbl5A0f
lbl4FCf:
    test byte ptr [si+56A5h],80h
    jz short lbl52Cf
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
    call mn524
    mov si,ax
    jmp short lbl568f
    nop
lbl52Cf:
    cmp di,46h
    jnz short lbl564f
    cmp word ptr [bp-196h],0h
    jz short lbl564f
    cmp si,3Ah
    jnz short lbl55Ef
    mov ax,word ptr [bp-182h]
    mov word ptr [bp-194h],ax
    sub ax,ax
    mov word ptr [bp-180h],ax
    mov word ptr [bp-182h],ax
    mov word ptr [bp-196h],0FFFFh
    mov di,70h
    mov si,30h
    jmp short lbl568f
    nop
lbl55Ef:
    mov word ptr [bp-196h],0h
lbl564b:
lbl564f:
    inc byte ptr [bp-1A0h]
lbl568b:
lbl568f:
    cmp byte ptr [bp-1A0h],0h
    jnz short lbl5E4f
    inc word ptr [bp-196h]
    lea ax,word ptr [si-30h]
    cwd
    add word ptr [bp-182h],ax
    adc word ptr [bp-180h],dx
    cmp word ptr [bp-19Ah],0h
    jz short lbl58Ff
    dec word ptr [bp-198h]
    jnz short lbl58Ff
    jmp near ptr lbl4E3b
lbl58Ff:
    inc word ptr [bp-190h]
    push word ptr [bp+8h]
    push word ptr [bp+6h]
    call mn599
    mov si,ax
    jmp short lbl5F2f
lbl5A0f:
    test byte ptr [si+56A5h],4h
    jz short lbl564b
    cmp di,6Fh
    jnz short lbl5D0f
    cmp si,38h
    jnl short lbl564b
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
    jmp short lbl568b
    nop
lbl5D0f:
    mov ax,0Ah
    cwd
    push dx
    push ax
    lea ax,word ptr [bp-182h]
    push ss
    push ax
    call mf5dc
    jmp short lbl568b
    nop
lbl5E4f:
    dec word ptr [bp-190h]
    push si
    push word ptr [bp+8h]
    push word ptr [bp+6h]
    call mn5ef
lbl5F2f:
    cmp byte ptr [bp-1A0h],0h
    jnz short lbl5FCf
    jmp near ptr lbl4EAb
lbl5FCf:
    cmp di,70h
    jnz short lbl614f
    cmp byte ptr [bp-1A4h],0h
    jz short lbl614f
    mov ax,word ptr [bp-194h]
    mov cx,word ptr [bp-182h]
    mov word ptr [bp-180h],ax
lbl614f:
    cmp byte ptr [bp-1A6h],0h
    jz short lbl628f
    neg word ptr [bp-182h]
    adc word ptr [bp-180h],0h
    neg word ptr [bp-180h]
lbl628f:
    cmp di,46h
    jnz short lbl633f
    mov word ptr [bp-196h],0h
lbl633f:
    cmp word ptr [bp-196h],0h
    jnz short lbl63Df
    jmp near ptr lbl922f
lbl63Df:
    cmp byte ptr [bp-1ACh],0h
    jz short lbl647f
    jmp near ptr lbl8DCf
lbl647f:
    inc word ptr [bp-192h]
lbl64Bb:
    cmp byte ptr [bp-1A4h],0h
    jz short lbl668f
    mov ax,word ptr [bp-182h]
    mov dx,word ptr [bp-180h]
    les bx, dword ptr [bp-186h]
    mov word ptr es:[bx],ax
    mov word ptr es:[bx+2h],dx
    jmp near ptr lbl8DCf
lbl668f:
    mov ax,word ptr [bp-182h]
    les bx, dword ptr [bp-186h]
    mov word ptr es:[bx],ax
    jmp near ptr lbl8DCf
    mov ax,word ptr [bp-190h]
    cwd
    mov word ptr [bp-182h],ax
    mov word ptr [bp-180h],dx
    jmp short lbl64Bb
    nop
    lea ax,word ptr [bp-17Eh]
    mov word ptr [bp-18Eh],ax
    mov word ptr [bp-18Ch],ss
    cmp si,2Dh
    jnz short lbl6ACf
    mov bx,ax
    mov byte ptr ss:[bx],2Dh
    lea ax,word ptr [bp-17Dh]
    mov word ptr [bp-18Eh],ax
    mov word ptr [bp-18Ch],ss
    jmp short lbl6B1f
    nop
lbl6ACf:
    cmp si,2Bh
    jnz short lbl6C4f
lbl6B1f:
    dec word ptr [bp-198h]
    inc word ptr [bp-190h]
    push word ptr [bp+8h]
    push word ptr [bp+6h]
    call mn6bf
    mov si,ax
lbl6C4f:
    cmp word ptr [bp-19Ah],0h
    jz short lbl6D3f
    cmp word ptr [bp-198h],15Dh
    jng short lbl708f
lbl6D3f:
    mov word ptr [bp-198h],15Dh
    jmp short lbl708f
    nop
lbl6DCb:
    mov ax,word ptr [bp-198h]
    dec word ptr [bp-198h]
    or ax,ax
    jz short lbl70Ff
    inc word ptr [bp-196h]
    mov ax,si
    les bx, dword ptr [bp-18Eh]
    inc word ptr [bp-18Eh]
    mov byte ptr es:[bx],al
    inc word ptr [bp-190h]
    push word ptr [bp+8h]
    push word ptr [bp+6h]
    call mn703
    mov si,ax
lbl708f:
    test byte ptr [si+56A5h],4h
    jnz short lbl6DCb
lbl70Ff:
    cmp si,2Eh
    jnz short lbl761f
    mov ax,word ptr [bp-198h]
    dec word ptr [bp-198h]
    or ax,ax
    jz short lbl761f
    les bx, dword ptr [bp-18Eh]
    inc word ptr [bp-18Eh]
    mov byte ptr es:[bx],2Eh
    jmp short lbl74Bf
lbl72Eb:
    mov ax,word ptr [bp-198h]
    dec word ptr [bp-198h]
    or ax,ax
    jz short lbl761f
    inc word ptr [bp-196h]
    mov ax,si
    les bx, dword ptr [bp-18Eh]
    inc word ptr [bp-18Eh]
    mov byte ptr es:[bx],al
lbl74Bf:
    inc word ptr [bp-190h]
    push word ptr [bp+8h]
    push word ptr [bp+6h]
    call mn755
    mov si,ax
    test byte ptr [si+56A5h],4h
    jnz short lbl72Eb
lbl761f:
    cmp word ptr [bp-196h],0h
    jnz short lbl76Bf
    jmp near ptr lbl7FDf
lbl76Bf:
    mov ax,si
    cmp al,65h
    jz short lbl778f
    cmp al,45h
    jz short lbl778f
    jmp near ptr lbl7FDf
lbl778f:
    mov ax,word ptr [bp-198h]
    dec word ptr [bp-198h]
    or ax,ax
    jz short lbl7FDf
    les bx, dword ptr [bp-18Eh]
    inc word ptr [bp-18Eh]
    mov byte ptr es:[bx],65h
    inc word ptr [bp-190h]
    push word ptr [bp+8h]
    push word ptr [bp+6h]
    call mn79a
    mov si,ax
    cmp si,2Dh
    jnz short lbl7B2f
    les bx, dword ptr [bp-18Eh]
    inc word ptr [bp-18Eh]
    mov byte ptr es:[bx],2Dh
    jmp short lbl7B7f
lbl7B2f:
    cmp si,2Bh
    jnz short lbl7F6f
lbl7B7f:
    mov ax,word ptr [bp-198h]
    dec word ptr [bp-198h]
    or ax,ax
    jnz short lbl7E7f
    inc word ptr [bp-198h]
    jmp short lbl7F6f
    nop
lbl7CAb:
    mov ax,word ptr [bp-198h]
    dec word ptr [bp-198h]
    or ax,ax
    jz short lbl7FDf
    inc word ptr [bp-196h]
    mov ax,si
    les bx, dword ptr [bp-18Eh]
    inc word ptr [bp-18Eh]
    mov byte ptr es:[bx],al
lbl7E7f:
    inc word ptr [bp-190h]
    push word ptr [bp+8h]
    push word ptr [bp+6h]
    call mn7f1
    mov si,ax
lbl7F6f:
    test byte ptr [si+56A5h],4h
    jnz short lbl7CAb
lbl7FDf:
    dec word ptr [bp-190h]
    push si
    push word ptr [bp+8h]
    push word ptr [bp+6h]
    call mn808
    cmp word ptr [bp-196h],0h
    jnz short lbl815f
    jmp near ptr lbl922f
lbl815f:
    cmp byte ptr [bp-1ACh],0h
    jz short lbl81Ff
    jmp near ptr lbl8DCf
lbl81Ff:
    inc word ptr [bp-192h]
    les bx, dword ptr [bp-18Eh]
    mov byte ptr es:[bx],0h
    cmp byte ptr [bp-1A4h],1h
    jng short lbl850f
    lea ax,word ptr [bp-17Eh]
    push ss
    push ax
    push word ptr [bp-184h]
    push word ptr [bp-186h]
    mov al,byte ptr [bp-1A4h]
    cbw
    push ax
    db 0FFh, 1Eh, 9Ah, 56h ; override
lbl84Ab:
    add sp,0Ah
    jmp near ptr lbl8DCf
lbl850f:
    lea ax,word ptr [bp-17Eh]
    push ss
    push ax
    push word ptr [bp-184h]
    push word ptr [bp-186h]
    mov al,byte ptr [bp-1A4h]
    cbw
    push ax
    db 0FFh, 1Eh, 86h, 56h ; override
    jmp short lbl84Ab
lbl86Ab:
    les bx, dword ptr [bp+0Ah]
    sub ah,ah
    mov al,byte ptr es:[bx]
    cmp ax,si
    jz short lbl888f
lbl876b:
lbl876f:
    dec word ptr [bp-190h]
    push si
    push word ptr [bp+8h]
    push word ptr [bp+6h]
    call mn881
    jmp near ptr lbl922f
    nop
lbl888f:
    dec byte ptr [bp-1AEh]
    cmp byte ptr [bp-1ACh],0h
    jnz short lbl8DCf
    sub word ptr [bp+0Eh],4h
    jmp short lbl8DCf
    nop
lbl89Af:
    sub ax, offset mi89a
    cmp ax, offset mi89d
    ja short lbl86Ab
    add ax,ax
    xchg ax,bx
    jmp word ptr cs:[bx+22ECh]
    db 3Ah, 1Ch, 0FEh, 1Eh, 0C8h, 20h, 0C8h, 20h, 0C8h, 20h, 0ACh, 22h, 62h, 1Eh, 0ACh, 22h
    db 0ACh, 22h, 0ACh, 22h, 0ACh, 22h, 0B8h, 20h, 0FEh, 1Eh, 0F0h, 1Eh, 0ACh, 22h, 0ACh, 22h
    db 56h, 1Ch, 0ACh, 22h, 0FEh, 1Eh, 0ACh, 22h, 0ACh, 22h, 65h, 1Eh, 0ACh, 22h, 0ACh, 22h
    db 5Eh, 1Ch
lbl8DCf:
    inc byte ptr [bp-1AEh]
    inc word ptr [bp+0Ah]
    jmp short lbl907f
    nop
lbl8E6f:
    inc word ptr [bp-190h]
    push word ptr [bp+8h]
    push word ptr [bp+6h]
    call mn8f0
    mov si,ax
    les bx, dword ptr [bp+0Ah]
    inc word ptr [bp+0Ah]
    mov al,byte ptr es:[bx]
    sub ah,ah
    cmp si,ax
    jz short lbl907f
    jmp near ptr lbl876b
lbl907f:
    cmp si,0FFFFFFFFFFFFFFFFh
    jz short lbl90Ff
    jmp near ptr lbl87b
lbl90Ff:
    les bx, dword ptr [bp+0Ah]
    cmp byte ptr es:[bx],25h
    jnz short lbl922f
    cmp byte ptr es:[bx+1h],6Eh
    jnz short lbl922f
    jmp near ptr lbl87b
lbl922f:
    cmp si,0FFFFFFFFFFFFFFFFh
    jnz short lbl935f
    cmp word ptr [bp-192h],0h
    jnz short lbl935f
    cmp byte ptr [bp-1AEh],0h
    jz short lbl93Cf
lbl935f:
    mov ax,word ptr [bp-192h]
    jmp short lbl93Ef
    nop
lbl93Cf:
    mov ax,si
lbl93Ef:
    pop si
    pop di
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
