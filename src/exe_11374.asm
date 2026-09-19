_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mn439:NEAR
    EXTRN mn324:NEAR
    EXTRN mn210:NEAR
    EXTRN mn22f:NEAR
    EXTRN mn46a:NEAR
    EXTRN mn1e4:NEAR
    EXTRN mn40e:NEAR
    EXTRN mn31f:NEAR
    EXTRN mn400:NEAR
    EXTRN mn7:NEAR
    EXTRN mn187:NEAR
    EXTRN mn198:NEAR
    EXTRN mn4a1:NEAR
    EXTRN mn485:NEAR
    EXTRN mn3e5:NEAR
    EXTRN mn1c6:NEAR
    EXTRN mn3d9:NEAR
    EXTRN mn1df:NEAR
    EXTRN mn370:NEAR
    EXTRN mn3f9:NEAR
    EXTRN mn200:NEAR
    EXTRN mn431:NEAR
mnem_unit:
    push bp
    mov bp,sp
    mov ax,214h
    push cs
    call mn7
    push si
    push di
    xor ax,ax
    mov word ptr [bp-8h],ax
    mov byte ptr [bp-5h],al
lbl14b:
    les si, dword ptr [bp+0Ah]
    db 26h, 0ACh ; override
    mov word ptr [bp+0Ah],si
    mov byte ptr [bp-2h],al
    or al,al
    jz short lbl29f
    cmp word ptr [bp-8h],0h
    jnl short lbl2Ff
lbl29f:
    mov ax,word ptr [bp-8h]
    db 0E9h, 0B5h, 04h ; override
lbl2Ff:
    mov bx,5618h
    sub al,20h
    cmp al,58h
    ja short lbl3Df
    xlatb
    and al,0Fh
    jmp short lbl3Ff
lbl3Df:
    mov al,0h
lbl3Ff:
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
    jnz short lbl117f
    or byte ptr [bp-4h],10h
    jmp short lbl139f
lbl117f:
    cmp al,46h
    jnz short lbl121f
    or byte ptr [bp-4h],20h
    jmp short lbl139f
lbl121f:
    cmp al,4Eh
    jnz short lbl12Bf
    or byte ptr [bp-3h],10h
    jmp short lbl139f
lbl12Bf:
    cmp al,4Ch
    jnz short lbl135f
    or byte ptr [bp-3h],4h
    jmp short lbl139f
lbl135f:
    or byte ptr [bp-3h],8h
lbl139f:
    jmp near ptr lbl14b
    mov al,byte ptr [bp-2h]
    cmp al,64h
    jnz short lbl146f
    jmp near ptr lbl2DAf
lbl146f:
    cmp al,69h
    jnz short lbl14Df
    jmp near ptr lbl2DAf
lbl14Df:
    cmp al,75h
    jnz short lbl154f
    jmp near ptr lbl2DEf
lbl154f:
    cmp al,58h
    jnz short lbl15Bf
    jmp near ptr lbl2E4f
lbl15Bf:
    cmp al,78h
    jnz short lbl162f
    jmp near ptr lbl2EAf
lbl162f:
    cmp al,6Fh
    jnz short lbl169f
    jmp near ptr lbl30Bf
lbl169f:
    cmp al,63h
    jz short lbl187f
    cmp al,73h
    jz short lbl198f
    cmp al,6Eh
    jz short lbl1C6f
    cmp al,70h
    jz short lbl1D9f
    cmp al,45h
    jz short lbl184f
    cmp al,47h
    jz short lbl184f
    jmp near ptr lbl23Ff
lbl184f:
    jmp near ptr lbl23Cf
lbl187f:
    call mn187
    lea di,word ptr [bp-214h]
    push ss
    pop es
    stosb
    dec di
    mov cx,1h
    jmp near ptr lbl389f
lbl198f:
    call mn198
    or di,di
    jnz short lbl1B1f
    mov ax,es
    or ax,ax
    jnz short lbl1B1f
    push ds
    pop es
    mov di,5671h
    mov cx,word ptr ds:[5677h]
    jmp near ptr lbl389f
lbl1B1f:
    push di
    mov cx,word ptr [bp-0Ch]
    jcxz lbl1BEf
    xor al,al
    repne scasb
    jnz short lbl1BEf
    dec di
lbl1BEf:
    pop cx
    sub di,cx
    db 87h, 0CFh ; override
    jmp near ptr lbl389f
lbl1C6f:
    call mn1c6
    mov ax,word ptr [bp-8h]
    stosw
    test byte ptr [bp-4h],10h
    jz short lbl1D6f
    xor ax,ax
    stosw
lbl1D6f:
    jmp near ptr lbl14b
lbl1D9f:
    test byte ptr [bp-4h],30h
    jnz short lbl1E4f
    call mn1df
    jmp short lbl21Df
lbl1E4f:
    call mn1e4
    test byte ptr [bp-3h],18h
    jnz short lbl21Df
    mov byte ptr [bp-1h],7h
    mov cx,10h
    push ss
    pop es
    push dx
    xor dx,dx
    lea di,word ptr [bp-20Ch]
    mov si,4h
    call mn200
    mov cx,10h
    lea di,word ptr [bp-211h]
    pop ax
    xor dx,dx
    mov si,4h
    call mn210
    mov byte ptr [bp-210h],3Ah
    mov cx,9h
    jmp short lbl235f
lbl21Df:
    mov byte ptr [bp-1h],7h
    mov cx,10h
    push ss
    pop es
    xor dx,dx
    lea di,word ptr [bp-211h]
    mov si,4h
    call mn22f
    mov cx,4h
lbl235f:
    lea di,word ptr [bp-214h]
    jmp near ptr lbl389f
lbl23Cf:
    inc word ptr [bp-12h]
lbl23Ff:
    or byte ptr [bp-4h],40h
    mov al,byte ptr [bp-2h]
    or al,20h
    cbw
    mov si,ax
    cmp word ptr [bp-0Ch],0h
    jg short lbl264f
    jz short lbl25Af
    mov word ptr [bp-0Ch],6h
    jmp short lbl264f
lbl25Af:
    cmp ax,67h
    jnz short lbl264f
    mov word ptr [bp-0Ch],1h
lbl264f:
    lea di,word ptr [bp-214h]
    push word ptr [bp-12h]
    push word ptr [bp-0Ch]
    push si
    push ss
    push di
    push word ptr [bp+10h]
    push word ptr [bp+0Eh]
    test byte ptr [bp-3h],4h
    jz short lbl287f
    db 0FFh, 1Eh, 96h, 56h ; override
    add word ptr [bp+0Eh],0Ah
    jmp short lbl28Ff
lbl287f:
    db 0FFh, 1Eh, 82h, 56h ; override
    add word ptr [bp+0Eh],8h
lbl28Ff:
    add sp,0Eh
    test byte ptr [bp-4h],80h
    jz short lbl2A7f
    cmp word ptr [bp-0Ch],0h
    jnz short lbl2A7f
    push ss
    push di
    db 0FFh, 1Eh, 8Eh, 56h ; override
    add sp,4h
lbl2A7f:
    cmp si,67h
    jnz short lbl2BCf
    test word ptr [bp-4h],80h
    jnz short lbl2BCf
    push ss
    push di
    db 0FFh, 1Eh, 8Ah, 56h ; override
    add sp,4h
lbl2BCf:
    push ss
    pop es
    cmp byte ptr es:[di],2Dh
    jnz short lbl2C9f
    inc di
    or byte ptr [bp-3h],1h
lbl2C9f:
    mov cx,0FFFFh
    push di
    mov al,0h
    repne scasb
    dec di
    pop cx
    sub di,cx
    db 87h, 0CFh ; override
    jmp near ptr lbl389f
lbl2DAf:
    or byte ptr [bp-4h],40h
lbl2DEf:
    mov byte ptr [bp-6h],0Ah
    jmp short lbl319f
lbl2E4f:
    mov byte ptr [bp-1h],7h
    jmp short lbl2EEf
lbl2EAf:
    mov byte ptr [bp-1h],27h
lbl2EEf:
    test byte ptr [bp-4h],80h
    jz short lbl305f
    mov word ptr [bp-10h],2h
    mov byte ptr [bp-0Eh],30h
    mov dl,51h
    add dl,byte ptr [bp-1h]
    mov byte ptr [bp-0Dh],dl
lbl305f:
    mov byte ptr [bp-6h],10h
    jmp short lbl319f
lbl30Bf:
    test byte ptr [bp-4h],80h
    jz short lbl315f
    or byte ptr [bp-3h],2h
lbl315f:
    mov byte ptr [bp-6h],8h
lbl319f:
    test byte ptr [bp-4h],10h
    jz short lbl324f
    call mn31f
    jmp short lbl332f
lbl324f:
    call mn324
    test byte ptr [bp-4h],40h
    jz short lbl330f
    cwd
    jmp short lbl332f
lbl330f:
    xor dx,dx
lbl332f:
    test byte ptr [bp-4h],40h
    jz short lbl347f
    or dx,dx
    jnl short lbl347f
    or byte ptr [bp-3h],1h
    neg ax
    adc dx,0h
    neg dx
lbl347f:
    cmp word ptr [bp-0Ch],0h
    jnl short lbl354f
    mov word ptr [bp-0Ch],1h
    jmp short lbl358f
lbl354f:
    and byte ptr [bp-4h],0F7h
lbl358f:
    mov bx,ax
    or bx,dx
    jnz short lbl363f
    mov word ptr [bp-10h],0h
lbl363f:
    lea di,word ptr [bp-15h]
    push ss
    pop es
    mov cl,byte ptr [bp-6h]
    xor ch,ch
    mov si,word ptr [bp-0Ch]
    call mn370
    test byte ptr [bp-3h],2h
    jz short lbl387f
    jcxz lbl381f
    cmp byte ptr es:[di],30h
    jz short lbl387f
lbl381f:
    dec di
    mov byte ptr es:[di],30h
    inc cx
lbl387f:
    jmp short lbl389f
lbl389f:
    test byte ptr [bp-4h],40h
    jz short lbl3C0f
    test byte ptr [bp-3h],1h
    jz short lbl3A0f
    mov byte ptr [bp-0Eh],2Dh
    mov word ptr [bp-10h],1h
    jmp short lbl3C0f
lbl3A0f:
    test byte ptr [bp-4h],1h
    jz short lbl3B1f
    mov byte ptr [bp-0Eh],2Bh
    mov word ptr [bp-10h],1h
    jmp short lbl3C0f
lbl3B1f:
    test byte ptr [bp-4h],2h
    jz short lbl3C0f
    mov byte ptr [bp-0Eh],20h
    mov word ptr [bp-10h],1h
lbl3C0f:
    mov ax,word ptr [bp-0Ah]
    sub ax,cx
    sub ax,word ptr [bp-10h]
    jnl short lbl3CCf
    xor ax,ax
lbl3CCf:
    push es
    push di
    push cx
    test byte ptr [bp-4h],0Ch
    jnz short lbl3DCf
    mov cx,ax
    mov dl,20h
    call mn3d9
lbl3DCf:
    push ax
    push ss
    pop es
    lea di,word ptr [bp-0Eh]
    mov cx,word ptr [bp-10h]
    call mn3e5
    pop ax
    test byte ptr [bp-4h],8h
    jz short lbl3FCf
    test byte ptr [bp-4h],4h
    jnz short lbl3FCf
    mov cx,ax
    mov dl,30h
    call mn3f9
lbl3FCf:
    pop cx
    pop di
    pop es
    push ax
    call mn400
    pop ax
    test byte ptr [bp-4h],4h
    jz short lbl411f
    mov cx,ax
    mov dl,20h
    call mn40e
lbl411f:
    jmp near ptr lbl14b
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
    jz short lbl439f
    call mn431
    mov es,dx
    mov di,ax
    ret
lbl439f:
    call mn439
    mov di,ax
    or ax,ax
    jnz short lbl445f
    mov es,ax
    ret
lbl445f:
    push ds
    pop es
    ret
    cbw
    push es
    push di
    les bx, dword ptr [bp+6h]
    dec word ptr es:[bx+4h]
    js short lbl464f
    mov di,word ptr es:[bx]
    inc word ptr es:[bx]
    mov es, es:[bx+2h]
    stosb
lbl45Fb:
    xor ax,ax
lbl461b:
    pop di
    pop es
    ret
lbl464f:
    push cx
    push dx
    push es
    push bx
    push ax
    push cs
    call mn46a
    add sp,6h
    pop dx
    pop cx
    cmp ax,0FFFFFFFFFFFFFFFFh
    jnz short lbl45Fb
    jmp short lbl461b
    db 0E3h, 1Bh ; override
    mov si,di
    add word ptr [bp-8h],cx
    push di
    xor di,di
lbl483b:
    db 26h, 0ACh ; override
    call mn485
    or di,ax
    loop lbl483b
    or di,di
    pop di
    jz short lbl496f
    mov word ptr [bp-8h],0FFFFh
lbl496f:
    ret
    jcxz lbl4B2f
    add word ptr [bp-8h],cx
    push di
    xor di,di
lbl49Fb:
    mov al,dl
    call mn4a1
    or di,ax
    loop lbl49Fb
    or di,di
    pop di
    jz short lbl4B2f
    mov word ptr [bp-8h],0FFFFh
lbl4B2f:
    ret
    std
    push di
    xchg ax,bx
lbl4B6b:
    or si,si
    jg short lbl4C4f
    or bx,bx
    jnz short lbl4C4f
    or dx,dx
    jnz short lbl4C4f
    jmp short lbl4DEf
lbl4C4f:
    xchg ax,dx
    xor dx,dx
    div cx
    xchg ax,bx
    div cx
    xchg ax,dx
    db 87h, 0D3h ; override
    add al,30h
    cmp al,39h
    jna short lbl4D8f
    add al,byte ptr [bp-1h]
lbl4D8f:
    stosb
    mov ax,dx
    dec si
    jmp short lbl4B6b
lbl4DEf:
    pop cx
    sub cx,di
    inc di
    cld
    ret
lbl4E4f:
    pop di
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
