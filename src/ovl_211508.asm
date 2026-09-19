_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi335:NEAR
    EXTRN mf518:FAR
    EXTRN mf206:FAR
    EXTRN mf241:FAR
    EXTRN mi4db:NEAR
    EXTRN mf1b2:FAR
    EXTRN miab:NEAR
    EXTRN mf227:FAR
    EXTRN mi3db:NEAR
    EXTRN mf7:FAR
    EXTRN mi2c3:NEAR
    EXTRN mf289:FAR
    EXTRN mi360:NEAR
    EXTRN mf48f:FAR
    EXTRN mi359:NEAR
    EXTRN mf3aa:FAR
    EXTRN mf431:FAR
    EXTRN mf259:FAR
    EXTRN mf36e:FAR
    EXTRN mf608:FAR
    EXTRN mf2a1:FAR
    EXTRN mf21e:FAR
    EXTRN mf162:FAR
    EXTRN mf2b3:FAR
    EXTRN mf271:FAR
    EXTRN mf14a:FAR
    EXTRN mf3bf:FAR
    EXTRN mf47a:FAR
    EXTRN mf1ee:FAR
    EXTRN mf1d3:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,48h
    push si
    call mf7
    les bx, dword ptr [bp+6h]
    mov al,byte ptr es:[bx+8h]
    cbw
    mov word ptr [bp-6h],ax
    mov cx,ax
    imul word ptr ds:[320Eh]
    mov word ptr [bp-0Eh],ax
    add ax,word ptr ds:[320Eh]
    dec ax
    mov word ptr [bp-12h],ax
    mov word ptr [bp-2h],0h
    mov ax,cx
    mov cx,17h
    imul cx
    mov word ptr [bp-34h],ax
lbl37b:
    cmp word ptr [bp-34h],0h
    jnl short lbl40f
    db 0E9h, 03h, 05h ; override
lbl40f:
    mov ax,word ptr ds:[3212h]
    cmp word ptr [bp-6h],ax
    jl short lbl4Bf
    db 0E9h, 0F8h, 04h ; override
lbl4Bf:
    les bx, dword ptr [bp+6h]
    mov al,byte ptr es:[bx+7h]
    cbw
    mov word ptr [bp-8h],ax
    imul word ptr ds:[320Ch]
    mov word ptr [bp-0Ch],ax
    add ax,word ptr ds:[320Ch]
    dec ax
    mov word ptr [bp-10h],ax
    mov word ptr [bp-0Ah],10h
    mov word ptr [bp-32h],5h
lbl6Fb:
    cmp word ptr [bp-8h],0h
    jnl short lbl78f
    db 0E9h, 0B4h, 04h ; override
lbl78f:
    mov ax,word ptr ds:[3210h]
    cmp word ptr [bp-8h],ax
    jl short lbl83f
    db 0E9h, 0A9h, 04h ; override
lbl83f:
    les bx, dword ptr [bp+6h]
    mov si,word ptr [bp-2h]
    mov al,byte ptr es:[bx+si]
    sub ah,ah
    mov word ptr [bp-3Ah],ax
    test word ptr [bp-0Ah],ax
    jnz short lbl99f
    db 0E9h, 93h, 04h ; override
lbl99f:
    mov es, ds:[5ADEh]
    mov bx,word ptr [bp-8h]
    add bx,word ptr [bp-34h]
    mov al,byte ptr es:[bx+4750h]
    mov byte ptr [bp-3Ch],al
    and ax, offset miab
    mov word ptr [bp-14h],ax
    mov word ptr [bp-18h],0h
    mov ax,word ptr [bp-0Ah]
    sar ax,1
    mov word ptr [bp-3Eh],ax
    test word ptr [bp-3Ah],ax
    jz short lblC8f
    mov word ptr [bp-18h],1h
lblC8f:
    mov ax,word ptr [bp-0Ah]
    add ax,ax
    mov word ptr [bp-40h],ax
    test word ptr [bp-3Ah],ax
    jz short lblD9f
    or byte ptr [bp-18h],10h
lblD9f:
    or si,si
    jz short lbl10Cf
    les bx, dword ptr [bp+6h]
    add bx,si
    sub ah,ah
    mov al,byte ptr es:[bx-1h]
    mov word ptr [bp-42h],ax
    test word ptr [bp-0Ah],ax
    jz short lblF4f
    or byte ptr [bp-18h],4h
lblF4f:
    mov ax,word ptr [bp-3Eh]
    test word ptr [bp-42h],ax
    jz short lbl100f
    or byte ptr [bp-18h],2h
lbl100f:
    mov ax,word ptr [bp-40h]
    test word ptr [bp-42h],ax
    jz short lbl10Cf
    or byte ptr [bp-18h],8h
lbl10Cf:
    cmp si,4h
    jnl short lbl140f
    les bx, dword ptr [bp+6h]
    add bx,si
    sub ah,ah
    mov al,byte ptr es:[bx+1h]
    mov word ptr [bp-44h],ax
    test word ptr [bp-0Ah],ax
    jz short lbl128f
    or byte ptr [bp-18h],40h
lbl128f:
    mov ax,word ptr [bp-3Eh]
    test word ptr [bp-44h],ax
    jz short lbl134f
    or byte ptr [bp-18h],80h
lbl134f:
    mov ax,word ptr [bp-40h]
    test word ptr [bp-44h],ax
    jz short lbl140f
    or byte ptr [bp-18h],20h
lbl140f:
    cmp word ptr [bp+0Ah],0h
    jz short lbl16Cf
    push word ptr ds:[3204h]
    call mf14a
    add sp,2h
    push word ptr [bp-12h]
    push word ptr [bp-10h]
    push word ptr [bp-0Eh]
    push word ptr [bp-0Ch]
    mov ax,2h
    push ax
    call mf162
    add sp,0Ah
    jmp short lbl1CFf
lbl16Cf:
    test byte ptr [bp-3Ch],0Fh
    jz short lbl1CFf
    cmp word ptr [bp-14h],0h
    jz short lbl17Ef
    mov ax,word ptr ds:[31FCh]
    jmp short lbl181f
    nop
lbl17Ef:
    mov ax,11h
lbl181f:
    mov word ptr [bp-1Eh],ax
    mov word ptr [bp-1Ch],0h
    cmp word ptr ds:[320Eh],0h
    jng short lbl1CFf
lbl190b:
    mov word ptr [bp-1Ah],0h
    cmp word ptr ds:[320Ch],0h
    jng short lbl1C3f
    mov ax,word ptr [bp-1Ch]
    add ax,word ptr [bp-0Eh]
    mov word ptr [bp-46h],ax
lbl1A5b:
    mov ax,word ptr [bp-1Ah]
    add ax,word ptr [bp-0Ch]
    push ax
    push word ptr [bp-46h]
    push word ptr [bp-1Eh]
    call mf1b2
    mov ax,word ptr ds:[320Ch]
    add word ptr [bp-1Ah],2h
    cmp word ptr [bp-1Ah],ax
    jl short lbl1A5b
lbl1C3f:
    mov ax,word ptr ds:[320Eh]
    add word ptr [bp-1Ch],3h
    cmp word ptr [bp-1Ch],ax
    jl short lbl190b
lbl1CFf:
    push word ptr ds:[3206h]
    call mf1d3
    add sp,2h
    mov al,byte ptr [bp-18h]
    and al,10h
    jnz short lbl1F3f
    push word ptr [bp-0Ch]
    push word ptr [bp-12h]
    push word ptr [bp-0Ch]
    push word ptr [bp-0Eh]
    call mf1ee
lbl1F3f:
    mov al,byte ptr [bp-18h]
    and al,4h
    jnz short lbl20Bf
    push word ptr [bp-0Ch]
    push word ptr [bp-0Eh]
    push word ptr [bp-10h]
    push word ptr [bp-0Eh]
    call mf206
lbl20Bf:
    mov al,byte ptr [bp-18h]
    and al,1Ch
    cmp al,14h
    jnz short lbl223f
    push word ptr [bp-0Ch]
    push word ptr [bp-0Eh]
    push word ptr ds:[3206h]
    call mf21e
lbl223f:
    push word ptr ds:[3208h]
    call mf227
    add sp,2h
    test byte ptr [bp-18h],40h
    jnz short lbl246f
    push word ptr [bp-0Ch]
    push word ptr [bp-12h]
    push word ptr [bp-10h]
    push word ptr [bp-12h]
    call mf241
lbl246f:
    mov al,byte ptr [bp-18h]
    and al,1h
    jnz short lbl25Ef
    push word ptr [bp-10h]
    push word ptr [bp-12h]
    push word ptr [bp-10h]
    push word ptr [bp-0Eh]
    call mf259
lbl25Ef:
    mov al,byte ptr [bp-18h]
    and al,70h
    cmp al,50h
    jnz short lbl276f
    push word ptr [bp-0Ch]
    push word ptr [bp-12h]
    push word ptr ds:[3208h]
    call mf271
lbl276f:
    mov al,byte ptr [bp-18h]
    and al,0C1h
    cmp al,41h
    jnz short lbl28Ef
    push word ptr [bp-10h]
    push word ptr [bp-12h]
    push word ptr ds:[3208h]
    call mf289
lbl28Ef:
    mov al,byte ptr [bp-18h]
    and al,7h
    cmp al,5h
    jnz short lbl2A6f
    push word ptr [bp-10h]
    push word ptr [bp-0Eh]
    push word ptr ds:[3208h]
    call mf2a1
lbl2A6f:
    cmp word ptr [bp+0Ah],0h
    jnz short lbl2AFf
    db 0E9h, 7Dh, 02h ; override
lbl2AFf:
    push word ptr ds:[31FEh]
    call mf2b3
    add sp,2h
    cmp word ptr [bp-14h],1h
    db 1Bh, 0C0h ; override
    and al,0E0h
    add ax, offset mi2c3
    mov word ptr [bp-22h],ax
    mov word ptr [bp-16h],0h
    mov word ptr [bp-30h],2h
lbl2D3b:
    mov bx,word ptr [bp-30h]
    mov es, ds:[5AE0h]
    mov al,byte ptr es:[bx]
    cbw
    add ax,word ptr [bp-8h]
    mov cx,ax
    mov al,byte ptr es:[bx+1h]
    cbw
    add ax,word ptr [bp-6h]
    mov word ptr [bp-26h],ax
    or cx,cx
    jl short lbl331f
    mov ax,word ptr ds:[3210h]
    cmp cx,ax
    jg short lbl331f
    cmp word ptr [bp-26h],0h
    jl short lbl331f
    mov ax,word ptr ds:[3212h]
    cmp word ptr [bp-26h],ax
    jg short lbl331f
    mov ax,17h
    imul word ptr [bp-26h]
    mov bx,ax
    add bx,cx
    mov es, ds:[5ADEh]
    mov al,byte ptr es:[bx+4750h]
    sub ah,ah
    test word ptr [bp-22h],ax
    jz short lbl331f
    mov es, ds:[5AE0h]
    mov bx,word ptr [bp-30h]
    sub bx,2h
    mov ax,word ptr es:[bx]
    or word ptr [bp-16h],ax
lbl331f:
    add word ptr [bp-30h],4h
    cmp word ptr [bp-30h], offset mi335
    jc short lbl2D3b
    mov al,byte ptr [bp-16h]
    and al,40h
    jz short lbl376f
    test byte ptr [bp-16h],1h
    jz short lbl376f
    mov al,byte ptr [bp-18h]
    or al,byte ptr [bp-16h]
    test al,80h
    jnz short lbl376f
    push word ptr [bp-14h]
    mov ax,word ptr [bp-12h]
    add ax, offset mi359
    push ax
    mov ax,word ptr [bp-10h]
    add ax, offset mi360
    push ax
    mov ax,word ptr [bp-12h]
    inc ax
    push ax
    mov ax,word ptr [bp-10h]
    inc ax
    push ax
    call mf36e
    add sp,0Ah
lbl376f:
    mov ax,word ptr [bp-18h]
    or ax,word ptr [bp-16h]
    mov word ptr [bp-48h],ax
    test al,40h
    jz short lbl386f
    jmp near ptr lbl445f
lbl386f:
    mov word ptr [bp-20h],1h
lbl38Bb:
    cmp word ptr [bp-14h],0h
    jz short lbl3D2f
    test byte ptr [bp-48h],30h
    jz short lbl39Cf
    push word ptr [bp-0Ch]
    jmp short lbl3A3f
lbl39Cf:
    mov ax,word ptr [bp-20h]
    add ax,word ptr [bp-0Ch]
    push ax
lbl3A3f:
    mov ax,word ptr [bp-20h]
    add ax,word ptr [bp-12h]
    push ax
    call mf3aa
    test byte ptr [bp-48h],80h
    jz short lbl3C8f
    push word ptr [bp-10h]
lbl3B8b:
    mov ax,word ptr [bp-20h]
    add ax,word ptr [bp-12h]
    push ax
    call mf3bf
    jmp short lbl439f
    nop
    nop
lbl3C8f:
    mov ax,word ptr [bp-20h]
    add ax,word ptr [bp-10h]
    push ax
    jmp short lbl3B8b
    nop
lbl3D2f:
    test byte ptr [bp-16h],10h
    jz short lbl3E0f
    mov ax,word ptr [bp-0Ch]
    add ax, offset mi3db
    jmp short lbl402f
lbl3E0f:
    test byte ptr [bp-16h],20h
    jz short lbl3F0f
    mov ax,word ptr [bp-20h]
    add ax,word ptr [bp-0Ch]
    dec ax
    jmp short lbl402f
    nop
lbl3F0f:
    mov al,byte ptr [bp-18h]
    and al,10h
    jz short lbl3FCf
    mov ax,word ptr [bp-0Ch]
    jmp short lbl402f
lbl3FCf:
    mov ax,word ptr [bp-20h]
    add ax,word ptr [bp-0Ch]
lbl402f:
    mov word ptr [bp-28h],ax
    test byte ptr [bp-48h],80h
    jnz short lbl41Af
    mov al,byte ptr [bp-18h]
    and al,1h
    jnz short lbl41Af
    mov ax,word ptr [bp-20h]
    add ax,word ptr [bp-10h]
    jmp short lbl41Df
lbl41Af:
    mov ax,word ptr [bp-10h]
lbl41Df:
    mov word ptr [bp-2Ah],ax
    push word ptr [bp-14h]
    mov ax,word ptr [bp-20h]
    add ax,word ptr [bp-12h]
    push ax
    push word ptr [bp-2Ah]
    push ax
    push word ptr [bp-28h]
    call mf431
    add sp,0Ah
lbl439f:
    inc word ptr [bp-20h]
    cmp word ptr [bp-20h],4h
    jnl short lbl445f
    jmp near ptr lbl38Bb
lbl445f:
    test byte ptr [bp-48h],1h
    jz short lbl44Ef
    jmp near ptr lbl52Cf
lbl44Ef:
    mov word ptr [bp-20h],1h
lbl453b:
    cmp word ptr [bp-14h],0h
    jz short lbl4A8f
    test byte ptr [bp-48h],6h
    jz short lbl46Cf
    mov ax,word ptr [bp-20h]
    add ax,word ptr [bp-10h]
    push ax
    push word ptr [bp-0Eh]
    jmp short lbl47Af
    nop
lbl46Cf:
    mov ax,word ptr [bp-20h]
    add ax,word ptr [bp-10h]
    push ax
    mov ax,word ptr [bp-20h]
    add ax,word ptr [bp-0Eh]
    push ax
lbl47Af:
    call mf47a
    test byte ptr [bp-48h],80h
    jz short lbl498f
    mov ax,word ptr [bp-20h]
    add ax,word ptr [bp-10h]
    push ax
    push word ptr [bp-12h]
lbl48Fb:
    call mf48f
    jmp near ptr lbl520f
    nop
lbl498f:
    mov ax,word ptr [bp-20h]
    add ax,word ptr [bp-10h]
    push ax
    mov ax,word ptr [bp-20h]
    add ax,word ptr [bp-12h]
    push ax
    jmp short lbl48Fb
lbl4A8f:
    test byte ptr [bp-16h],4h
    jnz short lbl4D8f
    test byte ptr [bp-18h],2h
    jnz short lbl4D8f
    test byte ptr [bp-16h],2h
    jz short lbl4C4f
    mov ax,word ptr [bp-20h]
    add ax,word ptr [bp-0Eh]
    dec ax
    jmp short lbl4DEf
    nop
lbl4C4f:
    mov al,byte ptr [bp-18h]
    and al,4h
    jz short lbl4D0f
    mov ax,word ptr [bp-0Eh]
    jmp short lbl4DEf
lbl4D0f:
    mov ax,word ptr [bp-20h]
    add ax,word ptr [bp-0Eh]
    jmp short lbl4DEf
lbl4D8f:
    mov ax,word ptr [bp-0Eh]
    add ax, offset mi4db
lbl4DEf:
    mov word ptr [bp-2Ch],ax
    test byte ptr [bp-18h],0C0h
    jnz short lbl506f
    test byte ptr [bp-16h],80h
    jnz short lbl506f
    mov al,byte ptr [bp-16h]
    and al,40h
    jz short lbl4FCf
    mov ax,word ptr [bp-20h]
    add ax,word ptr [bp-12h]
    jmp short lbl509f
lbl4FCf:
    mov ax,word ptr [bp-20h]
    add ax,word ptr [bp-12h]
    dec ax
    jmp short lbl509f
    nop
lbl506f:
    mov ax,word ptr [bp-12h]
lbl509f:
    push word ptr [bp-14h]
    push ax
    mov ax,word ptr [bp-20h]
    add ax,word ptr [bp-10h]
    push ax
    push word ptr [bp-2Ch]
    push ax
    call mf518
    add sp,0Ah
lbl520f:
    inc word ptr [bp-20h]
    cmp word ptr [bp-20h],4h
    jnl short lbl52Cf
    jmp near ptr lbl453b
lbl52Cf:
    inc word ptr [bp-8h]
    mov ax,word ptr ds:[320Ch]
    add word ptr [bp-0Ch],ax
    add word ptr [bp-10h],ax
    sar word ptr [bp-0Ah],1
    dec word ptr [bp-32h]
    jz short lbl543f
    jmp near ptr lbl6Fb
lbl543f:
    add word ptr [bp-34h],17h
    inc word ptr [bp-6h]
    mov ax,word ptr ds:[320Eh]
    add word ptr [bp-0Eh],ax
    add word ptr [bp-12h],ax
    inc word ptr [bp-2h]
    cmp word ptr [bp-2h],5h
    jnl short lbl55Ff
    jmp near ptr lbl37b
lbl55Ff:
    cmp word ptr [bp+0Ah],0h
    jnz short lbl568f
    jmp near ptr lbl608f
lbl568f:
    les bx, dword ptr [bp+6h]
    mov byte ptr es:[bx+6h],1h
    mov al,byte ptr es:[bx+8h]
    cbw
    mov word ptr [bp-6h],ax
    mov word ptr [bp-2h],0h
    mov cx,17h
    imul cx
    mov word ptr [bp-38h],ax
lbl585b:
    cmp word ptr [bp-38h],0h
    jl short lbl5F5f
    mov ax,word ptr ds:[3212h]
    cmp word ptr [bp-6h],ax
    jnl short lbl5F5f
    les bx, dword ptr [bp+6h]
    mov al,byte ptr es:[bx+7h]
    cbw
    mov word ptr [bp-8h],ax
    mov word ptr [bp-0Ah],10h
    mov word ptr [bp-36h],5h
lbl5A8b:
    cmp word ptr [bp-8h],0h
    jl short lbl5EAf
    mov ax,word ptr ds:[3210h]
    cmp word ptr [bp-8h],ax
    jnl short lbl5EAf
    les bx, dword ptr [bp+6h]
    mov si,word ptr [bp-2h]
    mov al,byte ptr es:[bx+si]
    sub ah,ah
    test word ptr [bp-0Ah],ax
    jz short lbl5EAf
    mov al,byte ptr es:[bx+5h]
    and al,0Fh
    mov es, ds:[5ADEh]
    mov bx,word ptr [bp-8h]
    add bx,word ptr [bp-38h]
    or byte ptr es:[bx+4750h],al
    test byte ptr es:[bx+4750h],10h
    jnz short lbl5EAf
    les bx, dword ptr [bp+6h]
    mov byte ptr es:[bx+6h],ah
lbl5EAf:
    inc word ptr [bp-8h]
    sar word ptr [bp-0Ah],1
    dec word ptr [bp-36h]
    jnz short lbl5A8b
lbl5F5f:
    add word ptr [bp-38h],17h
    inc word ptr [bp-6h]
    inc word ptr [bp-2h]
    cmp word ptr [bp-2h],5h
    jnl short lbl608f
    jmp near ptr lbl585b
lbl608f:
    call mf608
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
