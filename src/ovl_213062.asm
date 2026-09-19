_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi263:NEAR
    EXTRN mf399:FAR
    EXTRN mf400:FAR
    EXTRN mf518:FAR
    EXTRN mf14f:FAR
    EXTRN mi134:NEAR
    EXTRN mi209:NEAR
    EXTRN mi191:NEAR
    EXTRN mf1c8:FAR
    EXTRN mi321:NEAR
    EXTRN mf362:FAR
    EXTRN mi1b8:NEAR
    EXTRN mf457:FAR
    EXTRN mf294:FAR
    EXTRN mi3ef:NEAR
    EXTRN mf2e3:FAR
    EXTRN mf55c:FAR
    EXTRN mi254:NEAR
    EXTRN mi3f6:NEAR
    EXTRN mf4cd:FAR
    EXTRN mi198:NEAR
    EXTRN mi2d4:NEAR
    EXTRN mf3ae:FAR
    EXTRN mi12e:NEAR
    EXTRN mf1ed:FAR
    EXTRN mi281:NEAR
    EXTRN mf2bb:FAR
    EXTRN mi4f5:NEAR
    EXTRN mi31a:NEAR
    EXTRN mi4bf:NEAR
    EXTRN mf47f:FAR
    EXTRN mf7:FAR
    EXTRN mf32f:FAR
    EXTRN mi472:NEAR
    EXTRN mi1bf:NEAR
    EXTRN mi290:NEAR
    EXTRN mi4c6:NEAR
    EXTRN mf215:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,2Ah
    push si
    call mf7
    mov word ptr [bp-4h],0h
    les bx, dword ptr [bp+6h]
    mov al,byte ptr es:[bx+8h]
    cbw
    mov word ptr [bp-8h],ax
    mov cx,17h
    imul cx
    mov word ptr [bp-1Ch],ax
lbl24b:
    cmp word ptr [bp-1Ch],0h
    jl short lbl80f
    mov ax,word ptr ds:[3212h]
    cmp word ptr [bp-8h],ax
    jnl short lbl80f
    les bx, dword ptr [bp+6h]
    mov al,byte ptr es:[bx+7h]
    cbw
    mov word ptr [bp-0Ah],ax
    mov word ptr [bp-0Ch],10h
    mov word ptr [bp-1Ah],5h
lbl47b:
    cmp word ptr [bp-0Ah],0h
    jl short lbl75f
    mov ax,word ptr ds:[3210h]
    cmp word ptr [bp-0Ah],ax
    jnl short lbl75f
    les bx, dword ptr [bp+6h]
    mov si,word ptr [bp-4h]
    mov al,byte ptr es:[bx+si]
    sub ah,ah
    test word ptr [bp-0Ch],ax
    jz short lbl75f
    mov es, ds:[5ADEh]
    mov bx,word ptr [bp-0Ah]
    add bx,word ptr [bp-1Ch]
    and byte ptr es:[bx+4750h],0F0h
lbl75f:
    inc word ptr [bp-0Ah]
    sar word ptr [bp-0Ch],1
    dec word ptr [bp-1Ah]
    jnz short lbl47b
lbl80f:
    add word ptr [bp-1Ch],17h
    inc word ptr [bp-8h]
    inc word ptr [bp-4h]
    cmp word ptr [bp-4h],5h
    jl short lbl24b
    les bx, dword ptr [bp+6h]
    mov al,byte ptr es:[bx+8h]
    cbw
    mov cx,ax
    imul word ptr ds:[320Eh]
    mov word ptr [bp-10h],ax
    add ax,word ptr ds:[320Eh]
    dec ax
    mov word ptr [bp-14h],ax
    mov word ptr [bp-8h],cx
    mov word ptr [bp-4h],0h
    mov ax,cx
    mov cx,17h
    imul cx
    mov word ptr [bp-20h],ax
lblBBb:
    cmp word ptr [bp-20h],0h
    jnl short lblC4f
    jmp near ptr lbl540f
lblC4f:
    mov ax,word ptr ds:[3212h]
    cmp word ptr [bp-8h],ax
    jl short lblCFf
    jmp near ptr lbl540f
lblCFf:
    les bx, dword ptr [bp+6h]
    mov al,byte ptr es:[bx+7h]
    cbw
    mov cx,ax
    imul word ptr ds:[320Ch]
    mov word ptr [bp-0Eh],ax
    add ax,word ptr ds:[320Ch]
    dec ax
    mov word ptr [bp-12h],ax
    mov word ptr [bp-0Ah],cx
    mov word ptr [bp-0Ch],10h
    mov word ptr [bp-1Eh],5h
lblF5b:
    cmp word ptr [bp-0Ah],0h
    jnl short lblFEf
    jmp near ptr lbl529f
lblFEf:
    mov ax,word ptr ds:[3210h]
    cmp word ptr [bp-0Ah],ax
    jl short lbl109f
    jmp near ptr lbl529f
lbl109f:
    les bx, dword ptr [bp+6h]
    mov si,word ptr [bp-4h]
    mov al,byte ptr es:[bx+si]
    sub ah,ah
    test word ptr [bp-0Ch],ax
    jnz short lbl11Cf
    jmp near ptr lbl529f
lbl11Cf:
    mov es, ds:[5ADEh]
    mov bx,word ptr [bp-0Ah]
    add bx,word ptr [bp-20h]
    mov word ptr [bp-22h],bx
    mov al,byte ptr es:[bx+4750h]
    and ax, offset mi12e
    mov word ptr [bp-16h],ax
    cmp ax, offset mi134
    db 1Bh, 0C9h ; override
    and cl,0E0h
    add cx,2Fh
    mov word ptr [bp-18h],cx
    push ax
    push word ptr [bp-14h]
    push word ptr [bp-12h]
    push word ptr [bp-10h]
    push word ptr [bp-0Eh]
    call mf14f
    add sp,0Ah
    mov bx,word ptr [bp-22h]
    add bx,4751h
    mov es, ds:[5ADEh]
    mov word ptr [bp-26h],bx
    mov word ptr [bp-24h],es
    mov al,byte ptr es:[bx]
    sub ah,ah
    test word ptr [bp-18h],ax
    jz short lbl175f
    jmp near ptr lbl21Df
lbl175f:
    cmp word ptr [bp-20h],0h
    jz short lbl19Ef
    mov bx,word ptr [bp-22h]
    mov al,byte ptr es:[bx+4739h]
    test word ptr [bp-18h],ax
    jz short lbl19Ef
    push word ptr [bp-16h]
    push word ptr [bp-14h]
    mov ax,word ptr [bp-12h]
    add ax, offset mi191
    push ax
    mov ax,word ptr [bp-10h]
    add ax, offset mi198
    push ax
    jmp short lbl210f
lbl19Ef:
    cmp word ptr [bp-20h],0h
    jz short lbl200f
    mov bx,word ptr [bp-22h]
    test byte ptr es:[bx+473Ah],0Fh
    jz short lbl200f
    push word ptr [bp-16h]
    push word ptr [bp-14h]
    mov ax,word ptr [bp-12h]
    add ax, offset mi1b8
    push ax
    mov ax,word ptr [bp-10h]
    add ax, offset mi1bf
    push ax
    mov ax,word ptr [bp-12h]
    inc ax
    push ax
    call mf1c8
    add sp,0Ah
    mov word ptr [bp-2h],0h
lbl1D5b:
    push word ptr [bp-16h]
    mov ax,word ptr [bp-10h]
    add ax,word ptr [bp-2h]
    push ax
    mov cx,word ptr [bp-12h]
    add cx,word ptr [bp-2h]
    inc cx
    push cx
    push ax
    mov ax,word ptr [bp-12h]
    inc ax
    push ax
    call mf1ed
    add sp,0Ah
    inc word ptr [bp-2h]
    cmp word ptr [bp-2h],3h
    jl short lbl1D5b
    jmp short lbl21Df
lbl200f:
    push word ptr [bp-16h]
    push word ptr [bp-14h]
    mov ax,word ptr [bp-12h]
    add ax, offset mi209
    push ax
    push word ptr [bp-10h]
lbl210f:
    mov ax,word ptr [bp-12h]
    inc ax
    push ax
    call mf215
    add sp,0Ah
lbl21Df:
    mov bx,word ptr [bp-22h]
    add bx,4767h
    mov es, ds:[5ADEh]
    mov word ptr [bp-2Ah],bx
    mov word ptr [bp-28h],es
    mov al,byte ptr es:[bx]
    sub ah,ah
    test word ptr [bp-18h],ax
    jz short lbl23Bf
    jmp near ptr lbl2EBf
lbl23Bf:
    cmp word ptr [bp-0Ah],0h
    jz short lbl26Af
    mov bx,word ptr [bp-22h]
    mov al,byte ptr es:[bx+474Fh]
    test word ptr [bp-18h],ax
    jz short lbl26Af
    push word ptr [bp-16h]
    mov ax,word ptr [bp-14h]
    add ax, offset mi254
    push ax
    push word ptr [bp-12h]
    mov ax,word ptr [bp-14h]
    inc ax
    push ax
    mov ax,word ptr [bp-0Eh]
    add ax, offset mi263
    push ax
    jmp short lbl2E3f
    nop
lbl26Af:
    cmp word ptr [bp-0Ah],0h
    jz short lbl2CEf
    mov bx,word ptr [bp-22h]
    test byte ptr es:[bx+4766h],0Fh
    jz short lbl2CEf
    push word ptr [bp-16h]
    mov ax,word ptr [bp-14h]
    add ax, offset mi281
    push ax
    push word ptr [bp-12h]
    mov ax,word ptr [bp-14h]
    inc ax
    push ax
    mov ax,word ptr [bp-0Eh]
    add ax, offset mi290
    push ax
    call mf294
    add sp,0Ah
    mov word ptr [bp-2h],0h
lbl2A1b:
    push word ptr [bp-16h]
    mov ax,word ptr [bp-14h]
    add ax,word ptr [bp-2h]
    inc ax
    push ax
    mov cx,word ptr [bp-0Eh]
    add cx,2h
    push cx
    push ax
    mov ax,word ptr [bp-0Eh]
    add ax,word ptr [bp-2h]
    push ax
    call mf2bb
    add sp,0Ah
    inc word ptr [bp-2h]
    cmp word ptr [bp-2h],3h
    jl short lbl2A1b
    jmp short lbl2EBf
lbl2CEf:
    push word ptr [bp-16h]
    mov ax,word ptr [bp-14h]
    add ax, offset mi2d4
    push ax
    push word ptr [bp-12h]
    mov ax,word ptr [bp-14h]
    inc ax
    push ax
    push word ptr [bp-0Eh]
lbl2E3f:
    call mf2e3
    add sp,0Ah
lbl2EBf:
    mov bx,word ptr [bp-22h]
    mov es, ds:[5ADEh]
    mov al,byte ptr es:[bx+4768h]
    sub ah,ah
    test word ptr [bp-18h],ax
    jz short lbl301f
    jmp near ptr lbl3AAf
lbl301f:
    les bx, dword ptr [bp-26h]
    mov al,byte ptr es:[bx]
    and al,0Fh
    jnz short lbl33Af
    les bx, dword ptr [bp-2Ah]
    test byte ptr es:[bx],0Fh
    jnz short lbl33Af
    push word ptr [bp-16h]
    mov ax,word ptr [bp-14h]
    add ax, offset mi31a
    push ax
    mov ax,word ptr [bp-12h]
    add ax, offset mi321
    push ax
    mov ax,word ptr [bp-14h]
    inc ax
    push ax
    mov ax,word ptr [bp-12h]
    inc ax
    push ax
    call mf32f
    add sp,0Ah
    jmp short lbl3AAf
    nop
lbl33Af:
    les bx, dword ptr [bp-26h]
    mov al,byte ptr es:[bx]
    and al,0Fh
    jnz short lbl376f
    mov word ptr [bp-2h],1h
lbl349b:
    push word ptr [bp-16h]
    mov ax,word ptr [bp-14h]
    add ax,word ptr [bp-2h]
    push ax
    mov cx,word ptr [bp-12h]
    add cx,3h
    push cx
    push ax
    mov ax,word ptr [bp-12h]
    add ax,word ptr [bp-2h]
    push ax
    call mf362
    add sp,0Ah
    inc word ptr [bp-2h]
    cmp word ptr [bp-2h],4h
    jl short lbl349b
    jmp short lbl3AAf
    nop
lbl376f:
    les bx, dword ptr [bp-2Ah]
    test byte ptr es:[bx],0Fh
    jnz short lbl3AAf
    mov word ptr [bp-2h],1h
lbl384b:
    push word ptr [bp-16h]
    mov ax,word ptr [bp-14h]
    add ax,word ptr [bp-2h]
    push ax
    mov cx,word ptr [bp-12h]
    add cx,word ptr [bp-2h]
    push cx
    push ax
    push word ptr [bp-12h]
    call mf399
    add sp,0Ah
    inc word ptr [bp-2h]
    cmp word ptr [bp-2h],4h
    jl short lbl384b
lbl3AAf:
    push word ptr ds:[31FEh]
    call mf3ae
    add sp,2h
    cmp word ptr [bp-20h],0h
    jz short lbl408f
    cmp word ptr [bp-0Ah],0h
    jz short lbl408f
    mov bx,word ptr [bp-22h]
    mov es, ds:[5ADEh]
    mov al,byte ptr es:[bx+4738h]
    sub ah,ah
    test word ptr [bp-18h],ax
    jz short lbl408f
    mov al,byte ptr es:[bx+4739h]
    test word ptr [bp-18h],ax
    jnz short lbl408f
    mov al,byte ptr es:[bx+474Fh]
    test word ptr [bp-18h],ax
    jnz short lbl408f
    push word ptr [bp-16h]
    mov ax,word ptr [bp-10h]
    add ax, offset mi3ef
    push ax
    mov ax,word ptr [bp-0Eh]
    add ax, offset mi3f6
    push ax
    push word ptr [bp-10h]
    push word ptr [bp-0Eh]
    call mf400
    add sp,0Ah
lbl408f:
    cmp word ptr [bp-20h],0h
    jz short lbl487f
    mov bx,word ptr [bp-22h]
    mov es, ds:[5ADEh]
    mov al,byte ptr es:[bx+4739h]
    sub ah,ah
    test word ptr [bp-18h],ax
    jz short lbl487f
    cmp word ptr [bp-0Ah],0h
    jz short lbl431f
    mov al,byte ptr es:[bx+4738h]
    test word ptr [bp-18h],ax
    jnz short lbl46Cf
lbl431f:
    mov al,byte ptr es:[bx+474Fh]
    sub ah,ah
    test word ptr [bp-18h],ax
    jnz short lbl46Cf
    mov word ptr [bp-2h],0h
lbl442b:
    push word ptr [bp-16h]
    mov ax,word ptr [bp-10h]
    add ax,word ptr [bp-2h]
    push ax
    push word ptr [bp-12h]
    push ax
    mov ax,word ptr [bp-0Eh]
    add ax,word ptr [bp-2h]
    push ax
    call mf457
    add sp,0Ah
    inc word ptr [bp-2h]
    cmp word ptr [bp-2h],3h
    jl short lbl442b
    jmp short lbl487f
    nop
    nop
lbl46Cf:
    push word ptr [bp-16h]
    mov ax,word ptr [bp-10h]
    add ax, offset mi472
    push ax
    push word ptr [bp-12h]
    push word ptr [bp-10h]
    push word ptr [bp-0Eh]
    call mf47f
    add sp,0Ah
lbl487f:
    cmp word ptr [bp-0Ah],0h
    jnz short lbl490f
    jmp near ptr lbl529f
lbl490f:
    mov bx,word ptr [bp-22h]
    mov es, ds:[5ADEh]
    mov al,byte ptr es:[bx+474Fh]
    sub ah,ah
    test word ptr [bp-18h],ax
    jnz short lbl4A6f
    jmp near ptr lbl529f
lbl4A6f:
    cmp word ptr [bp-20h],0h
    jz short lbl4DAf
    mov al,byte ptr es:[bx+4739h]
    test word ptr [bp-18h],ax
    jz short lbl4DAf
    push word ptr [bp-16h]
    push word ptr [bp-14h]
    mov ax,word ptr [bp-0Eh]
    add ax, offset mi4bf
    push ax
    mov ax,word ptr [bp-10h]
    add ax, offset mi4c6
    push ax
lbl4CAb:
    push word ptr [bp-0Eh]
    call mf4cd
    add sp,0Ah
    jmp short lbl529f
    nop
    nop
    nop
lbl4DAf:
    cmp word ptr [bp-20h],0h
    jz short lbl4FEf
    mov al,byte ptr es:[bx+4738h]
    sub ah,ah
    test word ptr [bp-18h],ax
    jz short lbl4FEf
    push word ptr [bp-16h]
    push word ptr [bp-14h]
    mov ax,word ptr [bp-0Eh]
    add ax, offset mi4f5
    push ax
    push word ptr [bp-10h]
    jmp short lbl4CAb
lbl4FEf:
    mov word ptr [bp-2h],0h
lbl503b:
    push word ptr [bp-16h]
    push word ptr [bp-14h]
    mov ax,word ptr [bp-0Eh]
    add ax,word ptr [bp-2h]
    push ax
    mov cx,word ptr [bp-10h]
    add cx,word ptr [bp-2h]
    push cx
    push ax
    call mf518
    add sp,0Ah
    inc word ptr [bp-2h]
    cmp word ptr [bp-2h],3h
    jl short lbl503b
lbl529f:
    inc word ptr [bp-0Ah]
    mov ax,word ptr ds:[320Ch]
    add word ptr [bp-0Eh],ax
    add word ptr [bp-12h],ax
    sar word ptr [bp-0Ch],1
    dec word ptr [bp-1Eh]
    jz short lbl540f
    jmp near ptr lblF5b
lbl540f:
    add word ptr [bp-20h],17h
    inc word ptr [bp-8h]
    mov ax,word ptr ds:[320Eh]
    add word ptr [bp-10h],ax
    add word ptr [bp-14h],ax
    inc word ptr [bp-4h]
    cmp word ptr [bp-4h],5h
    jnl short lbl55Cf
    jmp near ptr lblBBb
lbl55Cf:
    call mf55c
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
