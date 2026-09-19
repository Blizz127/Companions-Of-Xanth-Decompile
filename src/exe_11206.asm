_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mn549:NEAR
    EXTRN mn22f:NEAR
    EXTRN mn26e:NEAR
    EXTRN mn512:NEAR
    EXTRN mi16:NEAR
    EXTRN mn4d9:NEAR
    EXTRN mn3cc:NEAR
    EXTRN mn28c:NEAR
    EXTRN mn2d7:NEAR
    EXTRN mn4a1:NEAR
    EXTRN mn287:NEAR
    EXTRN mn4e1:NEAR
    EXTRN mf68:FAR
    EXTRN mn481:NEAR
    EXTRN mn3c7:NEAR
    EXTRN mn2b8:NEAR
    EXTRN mn240:NEAR
    EXTRN mn4a8:NEAR
    EXTRN mn418:NEAR
    EXTRN mn2a8:NEAR
    EXTRN mn48d:NEAR
    EXTRN mf4a:FAR
    EXTRN mn52d:NEAR
    EXTRN mn84:NEAR
    EXTRN mnaf:NEAR
    EXTRN mn4b6:NEAR
mnem_unit:
    push bp
    mov bp,sp
    mov bx,word ptr [bp+4h]
    test byte ptr [bx+56A5h],4h
    jz short lbl12f
    mov ax,bx
    jmp short lbl19f
    nop
lbl12f:
    mov ax,bx
    and al,0DFh
    sub ax, offset mi16
lbl19f:
    pop bp
    ret 2h
    nop
    push bp
    mov bp,sp
    sub sp,4h
    les bx, dword ptr [bp+4h]
    dec word ptr es:[bx+4h]
    js short lbl48f
    mov ax,word ptr es:[bx]
    mov dx,word ptr es:[bx+2h]
    inc word ptr es:[bx]
    mov bx,ax
    mov es,dx
    mov word ptr [bp-4h],ax
    mov word ptr [bp-2h],es
    mov al,byte ptr es:[bx]
    sub ah,ah
    jmp short lbl4Ff
lbl48f:
    push es
    push bx
    call mf4a
lbl4Ff:
    mov sp,bp
    pop bp
    ret 4h
    nop
    push bp
    mov bp,sp
    cmp word ptr [bp+8h],0FFFFFFFFFFFFFFFFh
    jz short lbl6Df
    push word ptr [bp+6h]
    push word ptr [bp+4h]
    push word ptr [bp+8h]
    call mf68
lbl6Df:
    mov sp,bp
    pop bp
    ret 6h
    nop
    push bp
    mov bp,sp
    push si
lbl78b:
    les bx, dword ptr [bp+8h]
    inc word ptr es:[bx]
    push word ptr [bp+6h]
    push word ptr [bp+4h]
    call mn84
    mov si,ax
    test byte ptr [si+56A5h],8h
    jnz short lbl78b
    pop si
    mov sp,bp
    pop bp
    ret 8h
    nop
    xchg ah,byte ptr [si]
    xchg ax,cx
    and al,0A7h
    and al,0DBh
    and al,7h
    and ax,250Fh
    cmp byte ptr [di],ah
    push 25h
    push bp
    mov bp,sp
    mov ax,214h
    push cs
    call mnaf
    push si
    push di
    xor ax,ax
    mov word ptr [bp-8h],ax
    mov byte ptr [bp-5h],al
lblBCb:
    les si, dword ptr [bp+0Ah]
    db 26h, 0ACh ; override
    mov word ptr [bp+0Ah],si
    mov byte ptr [bp-2h],al
    or al,al
    jz short lblD1f
    cmp word ptr [bp-8h],0h
    jnl short lblD7f
lblD1f:
    mov ax,word ptr [bp-8h]
    db 0E9h, 0B5h, 04h ; override
lblD7f:
    mov bx,5618h
    sub al,20h
    cmp al,58h
    ja short lblE5f
    xlatb
    and al,0Fh
    jmp short lblE7f
lblE5f:
    mov al,0h
lblE7f:
    mov cl,3h
    shl al,cl
    add al,byte ptr [bp-5h]
    xlatb
    inc cl
    shr al,cl
    mov byte ptr [bp-5h],al
    cbw
    mov bx,ax
    shl bx,1
    jmp word ptr cs:[bx+241Eh]
    db 8Ah, 56h, 0FEh, 0B9h, 01h, 00h, 0E8h, 36h, 04h, 0EBh, 0B1h, 33h, 0C0h, 89h, 46h, 0F0h
    db 89h, 46h, 0F6h, 89h, 46h, 0EEh, 0C7h, 46h, 0FCh, 20h, 00h, 48h, 89h, 46h, 0F4h, 0EBh
    db 9Bh, 8Ah, 46h, 0FEh, 3Ch, 2Dh, 75h, 06h, 80h, 4Eh, 0FCh, 04h, 0EBh, 8Eh, 3Ch, 2Bh
    db 75h, 06h, 80h, 4Eh, 0FCh, 01h, 0EBh, 84h, 3Ch, 20h, 75h, 07h, 80h, 4Eh, 0FCh, 02h
    db 0E9h, 79h, 0FFh, 3Ch, 23h, 75h, 07h, 80h, 4Eh, 0FCh, 80h, 0E9h, 6Eh, 0FFh, 80h, 4Eh
    db 0FCh, 08h, 0E9h, 67h, 0FFh, 8Ah, 4Eh, 0FEh, 80h, 0F9h, 2Ah, 75h, 0Fh, 0E8h, 5Ch, 03h
    db 0Bh, 0C0h, 79h, 17h, 0F7h, 0D8h, 80h, 4Eh, 0FCh, 04h, 0EBh, 0Fh, 80h, 0E9h, 30h, 32h
    db 0EDh, 8Bh, 46h, 0F6h, 0BBh, 0Ah, 00h, 0F7h, 0E3h, 03h, 0C1h, 89h, 46h, 0F6h, 0E9h, 3Bh
    db 0FFh, 0C7h, 46h, 0F4h, 00h, 00h, 0E9h, 33h, 0FFh, 8Ah, 4Eh, 0FEh, 80h, 0F9h, 2Ah, 75h
    db 0Ch, 0E8h, 28h, 03h, 0Bh, 0C0h, 79h, 14h, 0B8h, 0FFh, 0FFh, 0EBh, 0Fh, 80h, 0E9h, 30h
    db 32h, 0EDh, 8Bh, 46h, 0F4h, 0BBh, 0Ah, 00h, 0F7h, 0E3h, 03h, 0C1h, 89h, 46h, 0F4h, 0E9h
    db 0Ah, 0FFh
    mov al,byte ptr [bp-2h]
    cmp al,6Ch
    jnz short lbl1BFf
    or byte ptr [bp-4h],10h
    jmp short lbl1E1f
lbl1BFf:
    cmp al,46h
    jnz short lbl1C9f
    or byte ptr [bp-4h],20h
    jmp short lbl1E1f
lbl1C9f:
    cmp al,4Eh
    jnz short lbl1D3f
    or byte ptr [bp-3h],10h
    jmp short lbl1E1f
lbl1D3f:
    cmp al,4Ch
    jnz short lbl1DDf
    or byte ptr [bp-3h],4h
    jmp short lbl1E1f
lbl1DDf:
    or byte ptr [bp-3h],8h
lbl1E1f:
    jmp near ptr lblBCb
    mov al,byte ptr [bp-2h]
    cmp al,64h
    jnz short lbl1EEf
    jmp near ptr lbl382f
lbl1EEf:
    cmp al,69h
    jnz short lbl1F5f
    jmp near ptr lbl382f
lbl1F5f:
    cmp al,75h
    jnz short lbl1FCf
    jmp near ptr lbl386f
lbl1FCf:
    cmp al,58h
    jnz short lbl203f
    jmp near ptr lbl38Cf
lbl203f:
    cmp al,78h
    jnz short lbl20Af
    jmp near ptr lbl392f
lbl20Af:
    cmp al,6Fh
    jnz short lbl211f
    jmp near ptr lbl3B3f
lbl211f:
    cmp al,63h
    jz short lbl22Ff
    cmp al,73h
    jz short lbl240f
    cmp al,6Eh
    jz short lbl26Ef
    cmp al,70h
    jz short lbl281f
    cmp al,45h
    jz short lbl22Cf
    cmp al,47h
    jz short lbl22Cf
    jmp near ptr lbl2E7f
lbl22Cf:
    jmp near ptr lbl2E4f
lbl22Ff:
    call mn22f
    lea di,word ptr [bp-214h]
    push ss
    pop es
    stosb
    dec di
    mov cx,1h
    jmp near ptr lbl431f
lbl240f:
    call mn240
    or di,di
    jnz short lbl259f
    mov ax,es
    or ax,ax
    jnz short lbl259f
    push ds
    pop es
    mov di,5671h
    mov cx,word ptr ds:[5677h]
    jmp near ptr lbl431f
lbl259f:
    push di
    mov cx,word ptr [bp-0Ch]
    jcxz lbl266f
    xor al,al
    repne scasb
    jnz short lbl266f
    dec di
lbl266f:
    pop cx
    sub di,cx
    db 87h, 0CFh ; override
    jmp near ptr lbl431f
lbl26Ef:
    call mn26e
    mov ax,word ptr [bp-8h]
    stosw
    test byte ptr [bp-4h],10h
    jz short lbl27Ef
    xor ax,ax
    stosw
lbl27Ef:
    jmp near ptr lblBCb
lbl281f:
    test byte ptr [bp-4h],30h
    jnz short lbl28Cf
    call mn287
    jmp short lbl2C5f
lbl28Cf:
    call mn28c
    test byte ptr [bp-3h],18h
    jnz short lbl2C5f
    mov byte ptr [bp-1h],7h
    mov cx,10h
    push ss
    pop es
    push dx
    xor dx,dx
    lea di,word ptr [bp-20Ch]
    mov si,4h
    call mn2a8
    mov cx,10h
    lea di,word ptr [bp-211h]
    pop ax
    xor dx,dx
    mov si,4h
    call mn2b8
    mov byte ptr [bp-210h],3Ah
    mov cx,9h
    jmp short lbl2DDf
lbl2C5f:
    mov byte ptr [bp-1h],7h
    mov cx,10h
    push ss
    pop es
    xor dx,dx
    lea di,word ptr [bp-211h]
    mov si,4h
    call mn2d7
    mov cx,4h
lbl2DDf:
    lea di,word ptr [bp-214h]
    jmp near ptr lbl431f
lbl2E4f:
    inc word ptr [bp-12h]
lbl2E7f:
    or byte ptr [bp-4h],40h
    mov al,byte ptr [bp-2h]
    or al,20h
    cbw
    mov si,ax
    cmp word ptr [bp-0Ch],0h
    jg short lbl30Cf
    jz short lbl302f
    mov word ptr [bp-0Ch],6h
    jmp short lbl30Cf
lbl302f:
    cmp ax,67h
    jnz short lbl30Cf
    mov word ptr [bp-0Ch],1h
lbl30Cf:
    lea di,word ptr [bp-214h]
    push word ptr [bp-12h]
    push word ptr [bp-0Ch]
    push si
    push ss
    push di
    push word ptr [bp+10h]
    push word ptr [bp+0Eh]
    test byte ptr [bp-3h],4h
    jz short lbl32Ff
    db 0FFh, 1Eh, 96h, 56h ; override
    add word ptr [bp+0Eh],0Ah
    jmp short lbl337f
lbl32Ff:
    db 0FFh, 1Eh, 82h, 56h ; override
    add word ptr [bp+0Eh],8h
lbl337f:
    add sp,0Eh
    test byte ptr [bp-4h],80h
    jz short lbl34Ff
    cmp word ptr [bp-0Ch],0h
    jnz short lbl34Ff
    push ss
    push di
    db 0FFh, 1Eh, 8Eh, 56h ; override
    add sp,4h
lbl34Ff:
    cmp si,67h
    jnz short lbl364f
    test word ptr [bp-4h],80h
    jnz short lbl364f
    push ss
    push di
    db 0FFh, 1Eh, 8Ah, 56h ; override
    add sp,4h
lbl364f:
    push ss
    pop es
    cmp byte ptr es:[di],2Dh
    jnz short lbl371f
    inc di
    or byte ptr [bp-3h],1h
lbl371f:
    mov cx,0FFFFh
    push di
    mov al,0h
    repne scasb
    dec di
    pop cx
    sub di,cx
    db 87h, 0CFh ; override
    jmp near ptr lbl431f
lbl382f:
    or byte ptr [bp-4h],40h
lbl386f:
    mov byte ptr [bp-6h],0Ah
    jmp short lbl3C1f
lbl38Cf:
    mov byte ptr [bp-1h],7h
    jmp short lbl396f
lbl392f:
    mov byte ptr [bp-1h],27h
lbl396f:
    test byte ptr [bp-4h],80h
    jz short lbl3ADf
    mov word ptr [bp-10h],2h
    mov byte ptr [bp-0Eh],30h
    mov dl,51h
    add dl,byte ptr [bp-1h]
    mov byte ptr [bp-0Dh],dl
lbl3ADf:
    mov byte ptr [bp-6h],10h
    jmp short lbl3C1f
lbl3B3f:
    test byte ptr [bp-4h],80h
    jz short lbl3BDf
    or byte ptr [bp-3h],2h
lbl3BDf:
    mov byte ptr [bp-6h],8h
lbl3C1f:
    test byte ptr [bp-4h],10h
    jz short lbl3CCf
    call mn3c7
    jmp short lbl3DAf
lbl3CCf:
    call mn3cc
    test byte ptr [bp-4h],40h
    jz short lbl3D8f
    cwd
    jmp short lbl3DAf
lbl3D8f:
    xor dx,dx
lbl3DAf:
    test byte ptr [bp-4h],40h
    jz short lbl3EFf
    or dx,dx
    jnl short lbl3EFf
    or byte ptr [bp-3h],1h
    neg ax
    adc dx,0h
    neg dx
lbl3EFf:
    cmp word ptr [bp-0Ch],0h
    jnl short lbl3FCf
    mov word ptr [bp-0Ch],1h
    jmp short lbl400f
lbl3FCf:
    and byte ptr [bp-4h],0F7h
lbl400f:
    mov bx,ax
    or bx,dx
    jnz short lbl40Bf
    mov word ptr [bp-10h],0h
lbl40Bf:
    lea di,word ptr [bp-15h]
    push ss
    pop es
    mov cl,byte ptr [bp-6h]
    xor ch,ch
    mov si,word ptr [bp-0Ch]
    call mn418
    test byte ptr [bp-3h],2h
    jz short lbl42Ff
    jcxz lbl429f
    cmp byte ptr es:[di],30h
    jz short lbl42Ff
lbl429f:
    dec di
    mov byte ptr es:[di],30h
    inc cx
lbl42Ff:
    jmp short lbl431f
lbl431f:
    test byte ptr [bp-4h],40h
    jz short lbl468f
    test byte ptr [bp-3h],1h
    jz short lbl448f
    mov byte ptr [bp-0Eh],2Dh
    mov word ptr [bp-10h],1h
    jmp short lbl468f
lbl448f:
    test byte ptr [bp-4h],1h
    jz short lbl459f
    mov byte ptr [bp-0Eh],2Bh
    mov word ptr [bp-10h],1h
    jmp short lbl468f
lbl459f:
    test byte ptr [bp-4h],2h
    jz short lbl468f
    mov byte ptr [bp-0Eh],20h
    mov word ptr [bp-10h],1h
lbl468f:
    mov ax,word ptr [bp-0Ah]
    sub ax,cx
    sub ax,word ptr [bp-10h]
    jnl short lbl474f
    xor ax,ax
lbl474f:
    push es
    push di
    push cx
    test byte ptr [bp-4h],0Ch
    jnz short lbl484f
    mov cx,ax
    mov dl,20h
    call mn481
lbl484f:
    push ax
    push ss
    pop es
    lea di,word ptr [bp-0Eh]
    mov cx,word ptr [bp-10h]
    call mn48d
    pop ax
    test byte ptr [bp-4h],8h
    jz short lbl4A4f
    test byte ptr [bp-4h],4h
    jnz short lbl4A4f
    mov cx,ax
    mov dl,30h
    call mn4a1
lbl4A4f:
    pop cx
    pop di
    pop es
    push ax
    call mn4a8
    pop ax
    test byte ptr [bp-4h],4h
    jz short lbl4B9f
    mov cx,ax
    mov dl,20h
    call mn4b6
lbl4B9f:
    jmp near ptr lblBCb
    les si, dword ptr [bp+0Eh]
    db 26h, 0ADh ; override
    mov word ptr [bp+0Eh],si
    ret
    les si, dword ptr [bp+0Eh]
    db 26h, 0ADh ; override
    mov dx,ax
    db 26h, 0ADh ; override
    xchg ax,dx
    mov word ptr [bp+0Eh],si
    ret
    test byte ptr [bp-4h],20h
    jz short lbl4E1f
    call mn4d9
    mov es,dx
    mov di,ax
    ret
lbl4E1f:
    call mn4e1
    mov di,ax
    or ax,ax
    jnz short lbl4EDf
    mov es,ax
    ret
lbl4EDf:
    push ds
    pop es
    ret
    cbw
    push es
    push di
    les bx, dword ptr [bp+6h]
    dec word ptr es:[bx+4h]
    js short lbl50Cf
    mov di,word ptr es:[bx]
    inc word ptr es:[bx]
    mov es, es:[bx+2h]
    stosb
lbl507b:
    xor ax,ax
lbl509b:
    pop di
    pop es
    ret
lbl50Cf:
    push cx
    push dx
    push es
    push bx
    push ax
    push cs
    call mn512
    add sp,6h
    pop dx
    pop cx
    cmp ax,0FFFFFFFFFFFFFFFFh
    jnz short lbl507b
    jmp short lbl509b
    db 0E3h, 1Bh ; override
    mov si,di
    add word ptr [bp-8h],cx
    push di
    xor di,di
lbl52Bb:
    db 26h, 0ACh ; override
    call mn52d
    or di,ax
    loop lbl52Bb
    or di,di
    pop di
    jz short lbl53Ef
    mov word ptr [bp-8h],0FFFFh
lbl53Ef:
    ret
    jcxz lbl55Af
    add word ptr [bp-8h],cx
    push di
    xor di,di
lbl547b:
    mov al,dl
    call mn549
    or di,ax
    loop lbl547b
    or di,di
    pop di
    jz short lbl55Af
    mov word ptr [bp-8h],0FFFFh
lbl55Af:
    ret
    std
    push di
    xchg ax,bx
lbl55Eb:
    or si,si
    jg short lbl56Cf
    or bx,bx
    jnz short lbl56Cf
    or dx,dx
    jnz short lbl56Cf
    jmp short lbl586f
lbl56Cf:
    xchg ax,dx
    xor dx,dx
    div cx
    xchg ax,bx
    div cx
    xchg ax,dx
    db 87h, 0D3h ; override
    add al,30h
    cmp al,39h
    jna short lbl580f
    add al,byte ptr [bp-1h]
lbl580f:
    stosb
    mov ax,dx
    dec si
    jmp short lbl55Eb
lbl586f:
    pop cx
    sub cx,di
    inc di
    cld
    ret
lbl58Cf:
    pop di
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
