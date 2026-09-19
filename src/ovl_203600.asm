_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mic:NEAR
    EXTRN mi23f:NEAR
    EXTRN mf22f:FAR
    EXTRN mi9:NEAR
    EXTRN mf27b:FAR
    EXTRN mfbb:FAR
    EXTRN mf198:FAR
    EXTRN mfe0:FAR
    EXTRN mf254:FAR
    EXTRN mf1b8:FAR
    EXTRN mf1a8:FAR
    EXTRN mf115:FAR
    EXTRN mf125:FAR
    EXTRN mf2aa:FAR
    EXTRN mf294:FAR
    EXTRN mf95:FAR
    EXTRN mf56:FAR
    EXTRN mia8:NEAR
    EXTRN mf26a:FAR
    EXTRN mf164:FAR
    EXTRN mf2b9:FAR
    EXTRN mf1c0:FAR
    EXTRN mf265:FAR
    EXTRN mf1e8:FAR
    EXTRN mfcd:FAR
    EXTRN mf2b4:FAR
    EXTRN mf102:FAR
    EXTRN mf138:FAR
    EXTRN mf18c:FAR
    EXTRN mf178:FAR
    EXTRN mf150:FAR
    EXTRN mf7c:FAR
    EXTRN mf46:FAR
    EXTRN md17:NEAR
    EXTRN mf180:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,0Eh
    mov ax,word ptr [bp+6h]
    sub ax, offset mi9
    cmp ax, offset mic
    jna short lbl14f
    db 0E9h, 0AFh, 02h ; override
lbl14f:
    add ax,ax
    xchg ax,bx
    jmp word ptr cs:[bx+md17]
    db 3Eh, 00h, 0D8h, 00h, 0D8h, 00h, 0D8h, 00h, 0C3h, 02h, 0C3h, 02h, 0ECh, 00h, 0C8h, 01h
    db 0C3h, 02h, 0C3h, 02h, 0C3h, 02h, 0C3h, 02h, 0C3h, 02h, 0C3h, 02h, 5Eh, 02h, 9Eh, 02h
    db 0B4h, 02h
    mov ax,0Ah
    push ax
    mov ax,112h
    push ax
    call mf46
    add sp,4h
    mov ax,3h
    mov dx,0F025h
    push dx
    push ax
    call mf56
    add sp,4h
    mov word ptr [bp-4h],0h
    mov word ptr [bp-8h],0h
lbl68b:
    mov ax,112h
    push ax
    mov bx,word ptr [bp-8h]
    mov es, ds:[5ADCh]
    mov word ptr [bp-0Eh],bx
    mov word ptr [bp-0Ch],es
    push word ptr es:[bx]
    call mf7c
    add sp,4h
    or ax,ax
    jz short lblA4f
    xor ax,ax
    push ax
    mov cx,1h
    push cx
    les bx, dword ptr [bp-0Eh]
    push word ptr es:[bx]
    call mf95
    add sp,6h
    or ax,ax
    jnz short lblA4f
    inc word ptr [bp-4h]
lblA4f:
    add word ptr [bp-8h],6h
    cmp word ptr [bp-8h], offset mia8
    jc short lbl68b
    cmp word ptr [bp-4h],0h
    jnz short lblB8f
    db 0E9h, 0Bh, 02h ; override
lblB8f:
    push word ptr [bp-4h]
    call mfbb
    add sp,2h
    push dx
    push ax
    mov ax,4h
    mov dx,0F025h
    push dx
    push ax
    call mfcd
    add sp,8h
    db 0E9h, 0EBh, 01h ; override
    mov ax,2h
    mov dx,0F025h
    push dx
    push ax
    call mfe0
    add sp,4h
    db 0E9h, 0D8h, 01h ; override
    nop
    cmp word ptr ds:[6A22h],125h
    jz short lblF7f
    db 0E9h, 0CCh, 01h ; override
lblF7f:
    xor ax,ax
    push ax
    mov cx,11h
    push cx
    mov cx,127h
    push cx
    call mf102
    add sp,6h
    or ax,ax
    jz short lbl111f
    db 0E9h, 0B2h, 01h ; override
lbl111f:
    mov ax,7D0h
    push ax
    call mf115
    add sp,2h
    mov ax,5A0Fh
    push ax
    mov ax,3A4h
    push ax
    call mf125
    add sp,4h
    xor ax,ax
    push ax
    mov cx,11h
    push cx
    mov cx,127h
    push cx
    call mf138
    add sp,6h
    or ax,ax
    jz short lbl1C0f
    mov ax,1h
    push ax
    mov cx,11Bh
    push cx
    mov cx,123h
    push cx
    call mf150
    add sp,6h
    mov ax,1h
    push ax
    mov cx,11Ch
    push cx
    mov dx,121h
    push dx
    call mf164
    add sp,6h
    mov ax,1h
    push ax
    mov ax,11Ch
    push ax
    mov ax,122h
    push ax
    call mf178
    add sp,6h
    call mf180
    xor ax,ax
    mov dx,0F025h
    push dx
    push ax
    call mf18c
    add sp,4h
    mov ax,2710h
    push ax
    call mf198
    add sp,2h
    mov ax,5A0Fh
    push ax
    mov ax,3ACh
    push ax
    call mf1a8
    add sp,4h
    xor ax,ax
    push ax
    push ax
    mov ax,5h
    push ax
    call mf1b8
    add sp,6h
lbl1C0f:
    call mf1c0
    db 0E9h, 0FBh, 00h ; override
    mov byte ptr [bp-6h],0h
    mov word ptr [bp-0Ah],0h
lbl1D1b:
    xor ax,ax
    push ax
    mov cx,1h
    push cx
    mov bx,word ptr [bp-0Ah]
    mov es, ds:[5ADCh]
    mov word ptr [bp-0Eh],bx
    mov word ptr [bp-0Ch],es
    push word ptr es:[bx]
    call mf1e8
    add sp,6h
    or ax,ax
    jz short lbl23Bf
    mov es, ds:[5ADCh]
    mov bx,word ptr [bp-0Ah]
    les bx, dword ptr es:[bx+2h]
    cmp byte ptr es:[bx],0h
    jnz short lbl23Bf
    les bx, dword ptr [bp-0Eh]
    mov ax,word ptr es:[bx]
    sub ax,121h
    jl short lbl237f
    jo short lbl237f
    dec ax
    jng short lbl21Af
    dec ax
    jz short lbl224f
    jmp short lbl237f
lbl21Af:
    mov ax,1h
    push ax
    mov ax,11Ch
    jmp short lbl22Bf
    nop
lbl224f:
    mov ax,1h
    push ax
    mov ax,11Bh
lbl22Bf:
    push ax
    push word ptr es:[bx]
    call mf22f
    add sp,6h
lbl237f:
    mov byte ptr [bp-6h],1h
lbl23Bf:
    add word ptr [bp-0Ah],6h
    cmp word ptr [bp-0Ah], offset mi23f
    jc short lbl1D1b
    cmp byte ptr [bp-6h],0h
    jz short lbl2B4f
    mov ax,1h
    mov dx,0F025h
    push dx
    push ax
    call mf254
    add sp,4h
    jmp short lbl2B4f
    cmp byte ptr ds:[31C2h],0h
    jnz short lbl288f
    call mf265
    call mf26a
    xor ax,ax
    push ax
    push ax
    mov ax,13h
    push ax
    mov ax,0B19h
    push ax
    call mf27b
    add sp,8h
    mov byte ptr ds:[31C2h],1h
lbl288f:
    mov ax,3h
    push ax
    mov ax,12h
    mov cx,3366h
    push cx
    push ax
    call mf294
    add sp,6h
    jmp short lbl2C5f
    mov ax,3h
    push ax
    mov ax,36h
    mov cx,3366h
    push cx
    push ax
    call mf2aa
    add sp,6h
    jmp short lbl2C3f
lbl2B4f:
    call mf2b4
    call mf2b9
    mov byte ptr ds:[31C2h],0h
lbl2C3f:
    xor ax,ax
lbl2C5f:
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
