_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf4:FAR
    EXTRN mf38:FAR
    EXTRN mf54:FAR
    EXTRN mf63:FAR
    EXTRN mf69:FAR
    EXTRN mf72:FAR
    EXTRN mf77:FAR
    EXTRN mf84:FAR
    EXTRN mf88:FAR
    EXTRN mf91:FAR
    EXTRN mf94:FAR
    EXTRN mf99:FAR
    EXTRN mi139:NEAR
    EXTRN mi142:NEAR
    EXTRN mf152:FAR
    EXTRN mf234:FAR
    EXTRN mf260:FAR
    EXTRN mf346:FAR
    EXTRN mf370:FAR
    EXTRN mf425:FAR
    EXTRN mf429:FAR
    EXTRN mf429:FAR
    EXTRN mf429:FAR
    EXTRN mf429:FAR
    EXTRN mf429:FAR
    EXTRN mf429:FAR
    EXTRN mf429:FAR
    EXTRN mf429:FAR
    EXTRN mf429:FAR
    EXTRN mf429:FAR
    EXTRN mf429:FAR
    EXTRN mf429:FAR
    EXTRN mf429:FAR
    EXTRN mf429:FAR
    EXTRN mf429:FAR
    EXTRN mf429:FAR
    EXTRN mf429:FAR
    EXTRN mf429:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,28h
    push si
    call mf4
    mov bx,word ptr [bp+6h]
    add bx,bx
    mov ax,word ptr [bx+32E6h]
    mov word ptr [bp-6h],ax
    mov cx,word ptr [bx+32DEh]
    mov word ptr [bp-4h],cx
    mov al,byte ptr [bp+8h]
    sub ah,ah
    imul word ptr ds:[5B1Ch]
    add ax,word ptr ds:[332Eh]
    mov word ptr [bp-0Ch],ax
    mov al,byte ptr [bp+9h]
    sub ah,ah
    imul word ptr ds:[5B1Eh]
    add ax,word ptr ds:[3330h]
    mov word ptr [bp-0Eh],ax
    mov ax,cx
    imul word ptr ds:[5B1Ch]
    add ax,word ptr [bp-0Ch]
    dec ax
    mov word ptr [bp-10h],ax
    mov ax,word ptr [bp-6h]
    imul word ptr ds:[5B1Eh]
    add ax,word ptr [bp-0Eh]
    dec ax
    mov word ptr [bp-12h],ax
    cmp word ptr [bp+0Ah],0h
    jnz short lbl66f
    mov ax,word ptr ds:[5B18h]
    jmp short lbl69f
    nop
lbl66f:
    mov ax,word ptr ds:[5B0Ah]
lbl69f:
    push ax
    call mf38
    add sp,2h
    mov ax,word ptr [bp-12h]
    dec ax
    push ax
    mov ax,word ptr [bp-10h]
    dec ax
    push ax
    mov ax,word ptr [bp-0Eh]
    inc ax
    push ax
    mov ax,word ptr [bp-0Ch]
    inc ax
    push ax
    mov ax,2h
    push ax
    call mf54
    add sp,0Ah
    cmp word ptr [bp+0Ah],0h
    jnz short lbl9Ef
    mov ax,word ptr ds:[5B16h]
    jmp short lblA1f
    nop
lbl9Ef:
    mov ax,word ptr ds:[5B08h]
lblA1f:
    push ax
    call mf63
    add sp,2h
    push word ptr [bp-0Ch]
    mov ax,word ptr [bp-12h]
    dec ax
    push ax
    call mf69
    push word ptr [bp-0Ch]
    push word ptr [bp-0Eh]
    call mf72
    mov ax,word ptr [bp-10h]
    dec ax
    push ax
    push word ptr [bp-0Eh]
    call mf77
    cmp word ptr [bp+0Ah],0h
    jnz short lblDAf
    mov ax,word ptr ds:[5B1Ah]
    jmp short lblDDf
lblDAf:
    mov ax,word ptr ds:[5B0Ch]
lblDDf:
    push ax
    call mf84
    add sp,2h
    push word ptr [bp-0Ch]
    push word ptr [bp-12h]
    call mf88
    push word ptr [bp-10h]
    push word ptr [bp-12h]
    call mf91
    push word ptr [bp-10h]
    push word ptr [bp-0Eh]
    call mf94
    cmp word ptr [bp+0Ah],0h
    jnz short lbl110f
    jmp near ptr lbl492f
lbl110f:
    push word ptr ds:[5B12h]
    call mf99
    add sp,2h
    mov al,byte ptr [bp+9h]
    sub ah,ah
    add ax,word ptr [bp-6h]
    mov word ptr [bp-8h],ax
    mov al,byte ptr [bp+8h]
    sub ah,ah
    add ax,word ptr [bp-4h]
    mov word ptr [bp-0Ah],ax
    les bx, dword ptr ds:[5E12h]
    sub ch,ch
    mov cl,byte ptr es:[bx]
    cmp ax,cx
    jnc short lbl1A6f
    sub ah,ah
    mov al,byte ptr es:[bx+1h]
    cmp ax,word ptr [bp-8h]
    jna short lbl1A6f
    mov bx,word ptr [bp-8h]
    mov ax,bx
    add bx,bx
    add bx,ax
    add bx,bx
    mov word ptr [bp-24h],bx
    mov es, ds:[5E2Ch]
    add bx,word ptr ds:[5E2Ah]
    mov word ptr [bp-22h],bx
    add bx,word ptr [bp-0Ah]
    cmp byte ptr es:[bx-1h],ch
    jz short lbl1A6f
    mov bx,word ptr [bp-22h]
    sub bx,6h
    mov si,word ptr [bp-0Ah]
    cmp byte ptr es:[bx+si],ch
    jz short lbl1A6f
    mov bx,word ptr [bp-22h]
    cmp byte ptr es:[bx+si],ch
    jnz short lbl1A6f
    mov ax,word ptr [bp-12h]
    add ax, offset mi139
    push ax
    mov ax,word ptr [bp-10h]
    add ax, offset mi142
    push ax
    mov ax,word ptr [bp-12h]
    inc ax
    push ax
    mov ax,word ptr [bp-10h]
    inc ax
    push ax
    mov ax,2h
    push ax
    call mf152
    add sp,0Ah
lbl1A6f:
    les bx, dword ptr ds:[5E12h]
    sub ah,ah
    mov al,byte ptr es:[bx+1h]
    mov cl,byte ptr [bp+9h]
    sub ch,ch
    add cx,word ptr [bp-6h]
    cmp ax,cx
    ja short lbl1BFf
    jmp near ptr lbl2F5f
lbl1BFf:
    mov al,byte ptr [bp+9h]
    mov cx,ax
    add ax,word ptr [bp-6h]
    mov word ptr [bp-8h],ax
    mov al,byte ptr [bp+8h]
    sub ah,ah
    mov bx,ax
    imul word ptr ds:[5B1Ch]
    add ax,word ptr ds:[332Eh]
    mov word ptr [bp-0Ch],ax
    add ax,word ptr ds:[5B1Ch]
    dec ax
    mov word ptr [bp-10h],ax
    mov ax,word ptr [bp-6h]
    imul word ptr ds:[5B1Eh]
    mov dx,ax
    mov ax,cx
    mov cx,dx
    imul word ptr ds:[5B1Eh]
    add cx,ax
    add cx,word ptr ds:[3330h]
    dec cx
    mov word ptr [bp-12h],cx
    mov word ptr [bp-0Ah],bx
    mov ax,bx
    add bx,word ptr [bp-4h]
    cmp bx,ax
    ja short lbl20Ef
    jmp near ptr lbl2F5f
lbl20Ef:
    mov ax,word ptr [bp-8h]
    mov cx,ax
    add ax,ax
    add ax,cx
    add ax,ax
    mov word ptr [bp-24h],ax
lbl21Cb:
    mov bx,word ptr [bp-24h]
    mov es, ds:[5E2Ch]
    add bx,word ptr ds:[5E2Ah]
    mov si,word ptr [bp-0Ah]
    cmp byte ptr es:[bx+si],0h
    jz short lbl233f
    jmp near ptr lbl2D9f
lbl233f:
    mov word ptr [bp-2h],1h
lbl238b:
    mov al,byte ptr [bp+8h]
    sub ah,ah
    cmp ax,word ptr [bp-0Ah]
    jc short lbl27Af
    cmp word ptr [bp-0Ah],0h
    jz short lbl27Af
    mov bx,word ptr [bp-24h]
    mov es, ds:[5E2Ch]
    add bx,word ptr ds:[5E2Ah]
    mov word ptr [bp-22h],bx
    add bx,word ptr [bp-0Ah]
    cmp byte ptr es:[bx-7h],ah
    jnz short lbl27Af
    mov bx,word ptr [bp-22h]
    add bx,word ptr [bp-0Ah]
    cmp byte ptr es:[bx-1h],ah
    jnz short lbl27Af
    mov ax,word ptr [bp-0Ch]
    mov cx,word ptr [bp-2h]
    add ax,cx
    push ax
    add cx,word ptr [bp-12h]
    push cx
    jmp short lbl284f
lbl27Af:
    push word ptr [bp-0Ch]
    mov ax,word ptr [bp-12h]
    add ax,word ptr [bp-2h]
    push ax
lbl284f:
    call mf234
    les bx, dword ptr ds:[5E12h]
    sub ah,ah
    mov al,byte ptr es:[bx]
    mov cx,word ptr [bp-0Ah]
    inc cx
    cmp ax,cx
    jna short lbl2BEf
    mov bx,word ptr [bp-24h]
    mov es, ds:[5E2Ch]
    add bx,word ptr ds:[5E2Ah]
    mov si,word ptr [bp-0Ah]
    cmp byte ptr es:[bx+si+1h],ah
    jnz short lbl2BEf
    mov ax,word ptr [bp-10h]
    mov cx,word ptr [bp-2h]
    add ax,cx
    push ax
    add cx,word ptr [bp-12h]
    push cx
    jmp short lbl2C8f
    nop
lbl2BEf:
    push word ptr [bp-10h]
    mov ax,word ptr [bp-12h]
    add ax,word ptr [bp-2h]
    push ax
lbl2C8f:
    call mf260
    inc word ptr [bp-2h]
    cmp word ptr [bp-2h],4h
    jnc short lbl2D9f
    jmp near ptr lbl238b
lbl2D9f:
    mov ax,word ptr ds:[5B1Ch]
    add word ptr [bp-0Ch],ax
    add word ptr [bp-10h],ax
    mov al,byte ptr [bp+8h]
    sub ah,ah
    add ax,word ptr [bp-4h]
    inc word ptr [bp-0Ah]
    cmp ax,word ptr [bp-0Ah]
    jna short lbl2F5f
    jmp near ptr lbl21Cb
lbl2F5f:
    mov al,byte ptr [bp+8h]
    sub ah,ah
    mov word ptr [bp-28h],ax
    add ax,word ptr [bp-4h]
    mov word ptr [bp-26h],ax
    les bx, dword ptr ds:[5E12h]
    sub ch,ch
    mov cl,byte ptr es:[bx]
    cmp ax,cx
    jc short lbl313f
    jmp near ptr lbl429f
lbl313f:
    mov word ptr [bp-0Ah],ax
    mov ax,word ptr [bp-28h]
    add ax,word ptr [bp-4h]
    imul word ptr ds:[5B1Ch]
    add ax,word ptr ds:[332Eh]
    dec ax
    mov word ptr [bp-10h],ax
    mov al,byte ptr [bp+9h]
    sub ah,ah
    mov cx,ax
    imul word ptr ds:[5B1Eh]
    add ax,word ptr ds:[3330h]
    mov word ptr [bp-0Eh],ax
    add ax,word ptr ds:[5B1Eh]
    dec ax
    mov word ptr [bp-12h],ax
    mov word ptr [bp-8h],cx
    mov ax,cx
    add cx,word ptr [bp-6h]
    cmp cx,ax
    ja short lbl351f
    jmp near ptr lbl429f
lbl351f:
    mov cx,ax
    add ax,cx
    add ax,cx
    add ax,ax
    mov word ptr [bp-1Ah],ax
lbl35Cb:
    les bx, dword ptr ds:[5E2Ah]
    add bx,word ptr [bp-1Ah]
    mov si,word ptr [bp-0Ah]
    cmp byte ptr es:[bx+si],0h
    jz short lbl36Ff
    jmp near ptr lbl409f
lbl36Ff:
    mov word ptr [bp-2h],1h
lbl374b:
    mov al,byte ptr [bp+9h]
    sub ah,ah
    cmp ax,word ptr [bp-8h]
    jc short lbl3AEf
    cmp word ptr [bp-1Ah],0h
    jz short lbl3AEf
    les bx, dword ptr ds:[5E2Ah]
    add bx,word ptr [bp-1Ah]
    mov word ptr [bp-22h],bx
    mov si,word ptr [bp-0Ah]
    cmp byte ptr es:[bx+si-7h],ah
    jnz short lbl3AEf
    sub bx,6h
    cmp byte ptr es:[bx+si],ah
    jnz short lbl3AEf
    mov ax,word ptr [bp-10h]
    mov cx,word ptr [bp-2h]
    add ax,cx
    push ax
    add cx,word ptr [bp-0Eh]
    push cx
    jmp short lbl3B8f
lbl3AEf:
    mov ax,word ptr [bp-10h]
    add ax,word ptr [bp-2h]
    push ax
    push word ptr [bp-0Eh]
lbl3B8f:
    call mf346
    les bx, dword ptr ds:[5E12h]
    sub ah,ah
    mov al,byte ptr es:[bx+1h]
    mov cx,word ptr [bp-8h]
    inc cx
    cmp ax,cx
    jna short lbl3EEf
    les bx, dword ptr ds:[5E2Ah]
    add bx,word ptr [bp-0Ah]
    mov si,word ptr [bp-1Ah]
    cmp byte ptr es:[bx+si+6h],ah
    jnz short lbl3EEf
    mov ax,word ptr [bp-10h]
    mov cx,word ptr [bp-2h]
    add ax,cx
    push ax
    add cx,word ptr [bp-12h]
    push cx
    jmp short lbl3F8f
lbl3EEf:
    mov ax,word ptr [bp-10h]
    add ax,word ptr [bp-2h]
    push ax
    push word ptr [bp-12h]
lbl3F8f:
    call mf370
    inc word ptr [bp-2h]
    cmp word ptr [bp-2h],4h
    jnc short lbl409f
    jmp near ptr lbl374b
lbl409f:
    add word ptr [bp-1Ah],6h
    mov ax,word ptr ds:[5B1Eh]
    add word ptr [bp-0Eh],ax
    add word ptr [bp-12h],ax
    mov al,byte ptr [bp+9h]
    sub ah,ah
    add ax,word ptr [bp-6h]
    inc word ptr [bp-8h]
    cmp ax,word ptr [bp-8h]
    jna short lbl429f
    jmp near ptr lbl35Cb
lbl429f:
    mov al,byte ptr [bp+9h]
    sub ah,ah
    mov word ptr [bp-8h],ax
    mov cx,ax
    add ax,word ptr [bp-6h]
    cmp ax,cx
    jna short lbl492f
    mov ax,cx
    add ax,cx
    add ax,cx
    add ax,ax
    mov word ptr [bp-1Ch],ax
    mov al,byte ptr [bp+8h]
    sub ah,ah
    mov word ptr [bp-28h],ax
    add ax,word ptr [bp-4h]
    mov word ptr [bp-26h],ax
    mov al,cl
    sub ah,ah
    sub ax,cx
    add ax,word ptr [bp-6h]
    mov word ptr [bp-1Eh],ax
lbl45Fb:
    mov ax,word ptr [bp-28h]
    mov word ptr [bp-0Ah],ax
    cmp word ptr [bp-26h],ax
    jna short lbl489f
    mov es, ds:[5E2Ch]
lbl46Eb:
    mov al,byte ptr [bp+0Ah]
    mov bx,word ptr ds:[5E2Ah]
    add bx,word ptr [bp-0Ah]
    mov si,word ptr [bp-1Ch]
    mov byte ptr es:[bx+si],al
    inc word ptr [bp-0Ah]
    mov ax,word ptr [bp-0Ah]
    cmp word ptr [bp-26h],ax
    ja short lbl46Eb
lbl489f:
    add word ptr [bp-1Ch],6h
    dec word ptr [bp-1Eh]
    jnz short lbl45Fb
lbl492f:
    call mf425
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
