_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf20d:FAR
    EXTRN mf10d:FAR
    EXTRN mf395:FAR
    EXTRN mf5ea:FAR
    EXTRN mfb8:FAR
    EXTRN mfc:FAR
    EXTRN mf29a:FAR
    EXTRN mf515:FAR
    EXTRN mf3ad:FAR
    EXTRN mf23f:FAR
    EXTRN mf259:FAR
    EXTRN mf190:FAR
    EXTRN mf38d:FAR
    EXTRN mfdb:FAR
    EXTRN mf5fc:FAR
    EXTRN mf5c3:FAR
    EXTRN mf51d:FAR
    EXTRN mfc8:FAR
    EXTRN mf9d:FAR
    EXTRN mf5d:FAR
    EXTRN mf141:FAR
    EXTRN mf1f4:FAR
    EXTRN mf2fb:FAR
    EXTRN mi2af:NEAR
    EXTRN mf226:FAR
    EXTRN mfe7:FAR
    EXTRN mf4a9:FAR
    EXTRN mf5d2:FAR
    EXTRN mi2c5:NEAR
    EXTRN mf357:FAR
    EXTRN mf5b7:FAR
    EXTRN mf48b:FAR
    EXTRN mf14c:FAR
    EXTRN mf428:FAR
    EXTRN mf1cc:FAR
    EXTRN mf2ea:FAR
    EXTRN mf41b:FAR
    EXTRN mf1a8:FAR
    EXTRN mi2c0:NEAR
    EXTRN mf174:FAR
    EXTRN mf268:FAR
    EXTRN mf4fa:FAR
    EXTRN mf30c:FAR
    EXTRN mf2df:FAR
    EXTRN mf62d:FAR
    EXTRN mf371:FAR
    EXTRN mf451:FAR
    EXTRN mf19c:FAR
    EXTRN mf260:FAR
    EXTRN mf535:FAR
    EXTRN mf3a1:FAR
    EXTRN mf91:FAR
    EXTRN mf75:FAR
    EXTRN mf168:FAR
    EXTRN mf346:FAR
    EXTRN mff3:FAR
    EXTRN mfad:FAR
    EXTRN mf619:FAR
    EXTRN mf592:FAR
    EXTRN mi59a:NEAR
    EXTRN mi496:NEAR
    EXTRN mf125:FAR
    EXTRN mf4d7:FAR
    EXTRN mf48:FAR
    EXTRN mf639:FAR
    EXTRN mf605:FAR
    EXTRN mffe:FAR
    EXTRN mf40f:FAR
    EXTRN mf381:FAR
    EXTRN mf40:FAR
    EXTRN mf406:FAR
    EXTRN mf5cb:FAR
    EXTRN mf1d8:FAR
    EXTRN mf360:FAR
    EXTRN mf26d:FAR
    EXTRN mf251:FAR
    EXTRN mf322:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,22h
    push di
    push si
    xor ax,ax
    push ax
    push ax
    call mfc
    add sp,4h
    cmp word ptr [bp+6h],1h
    jnz short lbl28f
    cmp word ptr ds:[18F6h],1h
    jnl short lbl28f
    mov ax,0FFFFh
    jmp near ptr lbl644f
    nop
lbl28f:
    cmp word ptr [bp+6h],0h
    jnz short lbl34f
    mov ax,18F8h
    jmp short lbl37f
    nop
lbl34f:
    mov ax,1902h
lbl37f:
    mov word ptr [bp-22h],ax
    mov word ptr [bp-20h],ds
lbl3Db:
    xor ax,ax
    push ax
    call mf40
    add sp,2h
    call mf48
    mov ax,0B8h
    push ax
    mov cx,134h
    push cx
    mov dx,16h
    push dx
    mov bx,0Ch
    push bx
    call mf5d
    add sp,8h
    mov ax,0B8h
    push ax
    mov cx,134h
    push cx
    mov dx,16h
    push dx
    mov bx,0Ch
    push bx
    call mf75
    add sp,8h
    mov ax,14h
    push ax
    mov cx,0B8h
    push cx
    mov cx,134h
    push cx
    mov cx,16h
    push cx
    mov cx,0Ch
    push cx
    call mf91
    add sp,0Ah
    mov ax,1h
    push ax
    call mf9d
    add sp,2h
    mov ax,0FFFFh
    push ax
    mov cx,0Fh
    push cx
    call mfad
    add sp,4h
    xor ax,ax
    push ax
    call mfb8
    add sp,2h
    mov ax,1Ch
    push ax
    push ds
    push word ptr [bp-22h]
    call mfc8
    add sp,4h
    cwd
    sub ax,dx
    sar ax,1
    sub ax,0A0h
    neg ax
    push ax
    call mfdb
    add sp,4h
    push ds
    push word ptr [bp-22h]
    call mfe7
    add sp,4h
    mov ax,0FFFFh
    push ax
    call mff3
    add sp,2h
    xor ax,ax
    push ax
    call mffe
    add sp,2h
    mov ax,0Dh
    push ax
    xor cx,cx
    push cx
    call mf10d
    add sp,4h
    mov ax,3Ch
    push ax
    mov cx,124h
    push cx
    mov dx,2Ch
    push dx
    mov bx,1Ch
    push bx
    call mf125
    add sp,8h
    mov ax,18h
    push ax
    mov cx,3Dh
    push cx
    mov cx,125h
    push cx
    mov dx,2Bh
    push dx
    mov dx,1Bh
    push dx
    call mf141
    add sp,0Ah
    xor ax,ax
    push ax
    call mf14c
    add sp,2h
    mov ax,3Ch
    push ax
    mov ax,124h
    push ax
    mov ax,2Ch
    push ax
    mov ax,1Ch
    push ax
    mov ax,1h
    push ax
    call mf168
    add sp,0Ah
    mov ax,0Dh
    push ax
    call mf174
    add sp,2h
    mov ax,3Bh
    push ax
    mov ax,123h
    push ax
    mov ax,2Dh
    push ax
    mov ax,1Dh
    push ax
    mov ax,2h
    push ax
    call mf190
    add sp,0Ah
    mov ax,1h
    push ax
    call mf19c
    add sp,2h
    mov ax,0Dh
    push ax
    call mf1a8
    add sp,2h
    xor ax,ax
    push ax
    push ax
    push word ptr ds:[18F4h]
    push word ptr ds:[18F2h]
    mov cx,14h
    push cx
    mov cx,25h
    push cx
    mov cx,9h
    push cx
    mov cx,4h
    push cx
    call mf1cc
    add sp,10h
    mov ax,0Fh
    push ax
    call mf1d8
    add sp,2h
    mov ax,18h
    push ax
    mov ax,9Dh
    push ax
    mov ax,125h
    push ax
    mov ax,43h
    push ax
    mov ax,1Bh
    push ax
    call mf1f4
    add sp,0Ah
    mov ax,46h
    push ax
    mov cx,190Fh
    push ds
    push cx
    mov cx,0A4h
    push cx
    mov dx,1Bh
    push dx
    call mf20d
    add sp,0Ah
    mov ax,46h
    push ax
    mov cx,1912h
    push ds
    push cx
    mov cx,0A4h
    push cx
    mov dx,0DFh
    push dx
    call mf226
    add sp,0Ah
    mov ax,46h
    push ax
    mov ax,1919h
    push ds
    push ax
    mov ax,0A4h
    push ax
    mov ax,7Dh
    push ax
    call mf23f
    add sp,0Ah
    cmp word ptr [bp+6h],0h
    jnz short lbl268f
    mov ax,1h
    push ax
    call mf251
    add sp,2h
    call mf259
    push dx
    push ax
    call mf260
    add sp,4h
lbl268f:
    call mf268
    call mf26d
lbl272b:
    mov byte ptr ds:[6D28h],0h
    mov ax,6D28h
    mov word ptr ds:[5D98h],ax
    mov word ptr ds:[5D9Ah],ds
    mov word ptr [bp-16h],0h
lbl286b:
    cmp word ptr [bp+6h],0h
    jnz short lbl291f
    mov byte ptr ds:[6D28h],0h
lbl291b:
lbl291f:
    lea ax,word ptr [bp-8h]
    push ss
    push ax
    mov ax,3FFh
    push ax
    call mf29a
    add sp,6h
    or ax,ax
    jnz short lbl2A9f
    jmp near ptr lbl4C8f
lbl2A9f:
    mov ax,word ptr [bp-8h]
    dec ax
    jz short lbl2BAf
    sub ax, offset mi2af
    jnz short lbl2B7f
    jmp near ptr lbl46Ef
lbl2B7f:
    jmp near ptr lbl4C8f
lbl2BAf:
    mov ax,word ptr [bp-2h]
    mov word ptr [bp-0Ah],ax
    cmp ax, offset mi2c0
    jl short lbl2CAf
    cmp ax, offset mi2c5
    jl short lbl2D3f
lbl2CAf:
    cmp word ptr [bp-0Ah],8h
    jz short lbl2D3f
    jmp near ptr lbl39Ef
lbl2D3f:
    cmp word ptr [bp+6h],0h
    jz short lbl2DCf
    jmp near ptr lbl3E4f
lbl2DCf:
    xor ax,ax
    push ax
    call mf2df
    add sp,2h
    push word ptr [bp-0Ah]
    call mf2ea
    add sp,2h
    mov byte ptr ds:[6D28h],0h
    mov ax,1h
    push ax
    call mf2fb
    add sp,2h
    mov ax,20h
    push ax
    mov ax,6D28h
    push ds
    push ax
    call mf30c
    add sp,6h
    or ax,ax
    jz short lbl37Df
lbl318b:
    lea ax,word ptr [bp-0Eh]
    push ss
    push ax
    lea ax,word ptr [bp-0Ch]
    push ss
    push ax
    call mf322
    add sp,8h
    or ax,ax
    jnz short lbl331f
    jmp near ptr lbl3CAf
lbl331f:
    lea ax,word ptr [bp-14h]
    push ss
    push ax
    lea cx,word ptr [bp-12h]
    push ss
    push cx
    lea cx,word ptr [bp-10h]
    push ss
    push cx
    push word ptr [bp-0Eh]
    push word ptr [bp-0Ch]
    call mf346
    add sp,10h
    cmp word ptr [bp-14h],1h
    jz short lbl357f
    jmp near ptr lbl291b
lbl357f:
    call mf357
    mov ax,1h
    push ax
    call mf360
    add sp,2h
    mov ax,20h
    push ax
    mov ax,6D28h
    push ds
    push ax
    call mf371
    add sp,6h
    or ax,ax
    jnz short lbl318b
lbl37Df:
    mov ax,1h
    push ax
    call mf381
    add sp,2h
    mov ax,1h
    push ax
    call mf38d
    add sp,2h
    call mf395
    push dx
    jmp near ptr lbl427f
lbl39Ef:
    push word ptr [bp-0Ah]
    call mf3a1
    add sp,2h
    or ax,ax
    jz short lbl3B6f
lbl3ADb:
    call mf3ad
    jmp near ptr lbl4C8f
    nop
lbl3B6f:
    cmp word ptr [bp-0Ah],1Bh
    jnz short lbl3C4f
    mov word ptr [bp-16h],2h
    jmp near ptr lbl4C8f
lbl3C4f:
    cmp word ptr [bp-0Ah],0Dh
    jnz short lbl3D2f
lbl3CAf:
    mov word ptr [bp-16h],1h
    jmp near ptr lbl4C8f
lbl3D2f:
    cmp word ptr [bp-0Ah],120h
    jz short lbl3DCf
    jmp near ptr lbl4C8f
lbl3DCf:
    mov word ptr [bp-16h],3h
    jmp near ptr lbl4C8f
lbl3E4f:
    cmp word ptr [bp-0Ah],8h
    jnz short lbl434f
    cmp word ptr ds:[5D98h],6D28h
    jna short lbl3FEf
    dec word ptr ds:[5D98h]
    les bx, dword ptr ds:[5D98h]
    mov byte ptr es:[bx],0h
lbl3FEf:
    xor ax,ax
    push ax
    mov ax,6D28h
    push ds
    push ax
    call mf406
    add sp,6h
lbl40Eb:
    push ax
    call mf40f
    add sp,2h
    mov ax,1h
    push ax
    call mf41b
    add sp,2h
    mov ax,6D28h
    push ds
lbl427f:
    push ax
    call mf428
    add sp,4h
    jmp near ptr lbl4C8f
    nop
lbl434f:
    mov al,byte ptr [bp-0Ah]
    les bx, dword ptr ds:[5D98h]
    mov byte ptr es:[bx],al
    inc word ptr ds:[5D98h]
    les bx, dword ptr ds:[5D98h]
    xor ax,ax
    mov byte ptr es:[bx],al
    push ax
    mov cx,6D28h
    push ds
    push cx
    call mf451
    add sp,6h
    mov word ptr [bp-1Ah],ax
    or ax,ax
    jnl short lbl40Eb
    dec word ptr ds:[5D98h]
    les bx, dword ptr ds:[5D98h]
    mov byte ptr es:[bx],0h
    jmp short lbl4C8f
lbl46Ef:
    lea ax,word ptr [bp-14h]
    push ss
    push ax
    lea cx,word ptr [bp-12h]
    push ss
    push cx
    lea cx,word ptr [bp-10h]
    push ss
    push cx
    mov cx,word ptr [bp-4h]
    mov word ptr [bp-0Eh],cx
    push cx
    mov cx,word ptr [bp-6h]
    mov word ptr [bp-0Ch],cx
    push cx
    call mf48b
    add sp,10h
    mov ax,word ptr [bp-14h]
    sub ax, offset mi496
    jz short lbl4A0f
    dec ax
    jz short lbl4C2f
    jmp short lbl4C8f
lbl4A0f:
    push word ptr [bp-0Eh]
    push word ptr [bp-12h]
    push word ptr [bp-10h]
    call mf4a9
    add sp,6h
    cmp ax,200h
    jz short lbl4B9f
    jmp near ptr lbl3ADb
lbl4B9f:
    mov word ptr [bp-16h],1h
    jmp near ptr lbl3ADb
    nop
lbl4C2f:
    mov ax,word ptr [bp-12h]
    mov word ptr [bp-16h],ax
lbl4C8f:
    cmp word ptr [bp-16h],0h
    jnz short lbl4D1f
    jmp near ptr lbl286b
lbl4D1f:
    push word ptr [bp-16h]
    xor ax,ax
    push ax
    call mf4d7
    add sp,4h
    mov word ptr [bp-18h],0FFFFh
    cmp word ptr [bp+6h],0h
    jnz short lbl525f
    cmp byte ptr ds:[6D28h],0h
    jz short lbl525f
    mov ax,1h
    push ax
    mov ax,6D28h
    push ds
    push ax
    call mf4fa
    add sp,6h
    mov word ptr [bp-1Ah],ax
    or ax,ax
    jnl short lbl51Cf
    les bx, dword ptr ds:[18EEh]
    mov ax,word ptr es:[bx]
    inc ax
    mov word ptr [bp-18h],ax
    push ax
    call mf515
    jmp short lbl522f
lbl51Cf:
    push ax
    call mf51d
lbl522f:
    add sp,2h
lbl525f:
    cmp word ptr [bp-16h],1h
    jnz short lbl5A4f
    cmp word ptr [bp-18h],0FFFFFFFFFFFFFFFFh
    jnz short lbl5A4f
    mov ax,2h
    push ax
    call mf535
    add sp,2h
    mov word ptr [bp-1Ah],ax
    mov bx,ax
    add bx,ax
    les si, dword ptr ds:[18EEh]
    mov ax,word ptr es:[bx+si]
    mov word ptr [bp-18h],ax
    mov bx,word ptr [bp-1Ah]
    add bx,bx
    add bx,bx
    les si, dword ptr ds:[18F2h]
    mov di,word ptr es:[bx+si]
    mov cx,word ptr es:[bx+si+2h]
    mov si,6D28h
    mov es,cx
    push ds
    mov cx,0FFFFh
    xor ax,ax
    repne scasb
    not cx
    sub di,cx
    db 87h, 0FEh ; override
    push ds
    push es
    pop ds
    pop es
    shr cx,1
    rep movsw
    adc cx,cx
    rep movsb
    pop ds
    cmp word ptr [bp+6h],ax
    jz short lbl588f
    jmp near ptr lbl635f
lbl588f:
    push ax
    push ax
    mov ax,160h
    mov cx,3181h
    push cx
    push ax
    call mf592
    add sp,8h
    cmp ax, offset mi59a
    jnz short lbl5A2f
    jmp near ptr lbl272b
lbl5A2f:
    jmp short lbl610f
lbl5A4f:
    cmp word ptr [bp-16h],3h
    jz short lbl5ADf
    jmp near ptr lbl635f
lbl5ADf:
    cmp word ptr [bp-18h],0h
    jl short lbl5DEf
    mov ax,1h
    push ax
    call mf5b7
    add sp,2h
    mov ax,1h
    push ax
    call mf5c3
    add sp,2h
    call mf5cb
    push dx
    push ax
    call mf5d2
    add sp,4h
    jmp near ptr lbl272b
    nop
lbl5DEf:
    sub ax,ax
    push ax
    push ax
    mov ax,17Ah
    mov cx,3181h
    push cx
    push ax
    call mf5ea
    add sp,8h
    dec ax
    jz short lbl5F8f
    jmp near ptr lbl272b
lbl5F8f:
    mov ax,2h
    push ax
    call mf5fc
    add sp,2h
    push ax
    call mf605
    add sp,2h
    jmp near ptr lbl3Db
lbl610f:
    cmp word ptr [bp-1Ah],0h
    jng short lbl635f
    push word ptr [bp-1Ah]
    call mf619
    add sp,2h
    les bx, dword ptr ds:[18EEh]
    mov ax,word ptr es:[bx]
    inc ax
    mov word ptr [bp-18h],ax
    push ax
    call mf62d
    add sp,2h
lbl635f:
    mov ax,17h
    push ax
    call mf639
    add sp,2h
    mov ax,word ptr [bp-18h]
lbl644f:
    pop si
    pop di
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
