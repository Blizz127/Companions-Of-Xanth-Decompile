_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi2:NEAR
    EXTRN mi6:NEAR
    EXTRN mi7:NEAR
    EXTRN mf43:FAR
    EXTRN mi46:NEAR
    EXTRN mi56:NEAR
    EXTRN mi57:NEAR
    EXTRN mf74:FAR
    EXTRN mf78:FAR
    EXTRN mf87:FAR
    EXTRN mi93:NEAR
    EXTRN mf104:FAR
    EXTRN mf121:FAR
    EXTRN mf127:FAR
    EXTRN mf137:FAR
    EXTRN mf140:FAR
    EXTRN mf174:FAR
    EXTRN mi177:NEAR
    EXTRN mi184:NEAR
    EXTRN mi185:NEAR
    EXTRN mf202:FAR
    EXTRN mf206:FAR
    EXTRN mf215:FAR
    EXTRN mi221:NEAR
    EXTRN mf230:FAR
    EXTRN mf241:FAR
    EXTRN mf247:FAR
    EXTRN mf254:FAR
    EXTRN mf257:FAR
    EXTRN mi264:NEAR
    EXTRN mi265:NEAR
    EXTRN mf272:FAR
    EXTRN mi274:NEAR
    EXTRN mf283:FAR
    EXTRN mi284:NEAR
    EXTRN mi295:NEAR
    EXTRN mi305:NEAR
    EXTRN mi306:NEAR
    EXTRN mf311:FAR
    EXTRN mi313:NEAR
    EXTRN mf325:FAR
    EXTRN mf325:FAR
    EXTRN mf325:FAR
    EXTRN mf325:FAR
    EXTRN mf325:FAR
    EXTRN mf325:FAR
    EXTRN mf325:FAR
    EXTRN mf325:FAR
    EXTRN mf325:FAR
    EXTRN mf325:FAR
    EXTRN mf325:FAR
    EXTRN mf325:FAR
    EXTRN mf325:FAR
    EXTRN mf325:FAR
    EXTRN mf325:FAR
    EXTRN mf325:FAR
    EXTRN mf325:FAR
    EXTRN mf325:FAR
    EXTRN mf325:FAR
    EXTRN mf325:FAR
    EXTRN mf325:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp, offset mi2
    push si
    push di
    mov ax,word ptr ds:[416Eh]
    and ax, offset mi6
    cmp ax, offset mi7
    jz short lbl17f
    jmp near ptr lbl1Af
lbl17f:
    jmp near ptr lbl3D7f
lbl1Af:
    cmp word ptr ds:[416Ch],0h
    jz short lbl24f
    jmp near ptr lbl27f
lbl24f:
    jmp near ptr lbl3D7f
lbl27f:
    mov word ptr [bp-6h],0h
    mov word ptr ds:[6DEEh],0h
    mov word ptr ds:[6DF0h],0h
    cmp word ptr ds:[415Ah],0h
    jnz short lbl42f
    jmp near ptr lbl1E8f
lbl42f:
    mov word ptr [bp-8h],0h
    jmp near ptr lbl1C2f
lbl4Ab:
    mov bx,word ptr [bp-8h]
    shl bx,1
    cmp word ptr [bx+4124h],0h
    jnz short lbl59f
    jmp near ptr lbl1BEf
lbl59f:
    mov bx,word ptr [bp-8h]
    shl bx,1
    mov ax,word ptr [bx+4124h]
    mov cx,8h
    sar ax,cl
    and ax,0FFh
    mov word ptr [bp-0Eh],ax
    mov bx,word ptr [bp-8h]
    shl bx,1
    mov ax,word ptr [bx+4124h]
    and ax,0FFh
    mov word ptr [bp-0Ch],ax
    push word ptr [bp-0Eh]
    mov ax,3h
    push ax
    call mf43
    add sp,4h
    mov word ptr [bp-0Ah],ax
    cmp ax, offset mi46
    jz short lbl96f
    jmp near ptr lblACf
lbl96f:
    mov bx,word ptr [bp-8h]
    shl bx,1
    shl bx,1
    mov word ptr [bx+4134h],0h
    mov word ptr [bx+4136h],0h
    jmp near ptr lbl1BEf
lblACf:
    mov ax,word ptr ds:[416Eh]
    and ax, offset mi56
    cmp ax, offset mi57
    jnz short lblBAf
    jmp near ptr lblC0f
lblBAf:
    mov ax,1h
    jmp near ptr lblC3f
lblC0f:
    mov ax,2h
lblC3f:
    mov word ptr [bp-4h],ax
    mov ax,0Ch
    mov dx,0h
    push dx
    push ax
    mov ax,word ptr [bp-0Ch]
    shl ax,1
    sub ax,word ptr [bp-4h]
    cwd
    push dx
    push ax
    call mf74
    push dx
    push ax
    push word ptr [bp-0Ah]
    call mf78
    add sp,6h
    mov ax,0Ch
    push ax
    mov ax,62CAh
    mov dx,ds
    push dx
    push ax
    push word ptr [bp-0Ah]
    call mf87
    add sp,8h
    mov cx,10h
    mov ax,word ptr ds:[62CEh]
    sub dx,dx
    div cx
    add ax, offset mi93
    add word ptr [bp-6h],ax
    mov ax,word ptr ds:[4164h]
    cmp word ptr [bp-6h],ax
    ja short lbl11Cf
    jmp near ptr lbl11Ff
lbl11Cf:
    jmp near ptr lbl1BEf
lbl11Ff:
    mov ax,word ptr ds:[62CEh]
    mov dx,0h
    push dx
    push ax
    call mf104
    add sp,4h
    mov bx,word ptr [bp-8h]
    shl bx,1
    shl bx,1
    mov word ptr [bx+4134h],ax
    mov word ptr [bx+4136h],dx
    mov bx,word ptr [bp-8h]
    shl bx,1
    shl bx,1
    cmp word ptr [bx+4134h],0h
    jz short lbl14Ff
    jmp near ptr lbl167f
lbl14Ff:
    cmp word ptr [bx+4136h],0h
    jz short lbl159f
    jmp near ptr lbl167f
lbl159f:
    push word ptr [bp-0Ah]
    call mf121
    add sp,2h
    jmp near ptr lbl1BEf
lbl167f:
    push word ptr ds:[62CCh]
    push word ptr ds:[62CAh]
    push word ptr [bp-0Ah]
    call mf127
    add sp,6h
    push word ptr ds:[62CEh]
    mov bx,word ptr [bp-8h]
    shl bx,1
    shl bx,1
    les bx, dword ptr [bx+4134h]
    push word ptr es:[bx+2h]
    push word ptr es:[bx]
    push word ptr [bp-0Ah]
    call mf137
    add sp,8h
    push word ptr [bp-0Ah]
    call mf140
    add sp,2h
    mov bx,word ptr [bp-8h]
    shl bx,1
    mov ax,word ptr ds:[62D2h]
    mov word ptr [bx+4148h],ax
    mov bx,word ptr [bp-8h]
    shl bx,1
    mov ax,word ptr ds:[62D4h]
    mov word ptr [bx+4150h],ax
lbl1BEf:
    add word ptr [bp-8h],1h
lbl1C2f:
    cmp word ptr [bp-8h],4h
    jnl short lbl1CBf
    jmp near ptr lbl4Ab
lbl1CBf:
    mov ax,word ptr ds:[4134h]
    mov dx,word ptr ds:[4136h]
    mov word ptr ds:[4144h],ax
    mov word ptr ds:[4146h],dx
    mov ax,word ptr ds:[4148h]
    mov word ptr ds:[415Eh],ax
    mov ax,word ptr ds:[4150h]
    mov word ptr ds:[4160h],ax
    jmp near ptr lbl313f
lbl1E8f:
    mov cx,8h
    mov ax,word ptr ds:[416Ch]
    sar ax,cl
    and ax,0FFh
    mov word ptr [bp-0Eh],ax
    mov ax,word ptr ds:[416Ch]
    and ax,0FFh
    mov word ptr [bp-0Ch],ax
    push word ptr [bp-0Eh]
    mov ax,3h
    push ax
    call mf174
    add sp,4h
    mov word ptr [bp-0Ah],ax
    cmp ax, offset mi177
    jz short lbl219f
    jmp near ptr lbl228f
lbl219f:
    mov word ptr ds:[4144h],0h
    mov word ptr ds:[4146h],0h
    jmp near ptr lbl313f
lbl228f:
    mov ax,word ptr ds:[416Eh]
    and ax, offset mi184
    cmp ax, offset mi185
    jnz short lbl236f
    jmp near ptr lbl23Cf
lbl236f:
    mov ax,1h
    jmp near ptr lbl23Ff
lbl23Cf:
    mov ax,2h
lbl23Ff:
    mov word ptr [bp-4h],ax
    mov ax,0Ch
    mov dx,0h
    push dx
    push ax
    mov ax,word ptr [bp-0Ch]
    shl ax,1
    sub ax,word ptr [bp-4h]
    cwd
    push dx
    push ax
    call mf202
    push dx
    push ax
    push word ptr [bp-0Ah]
    call mf206
    add sp,6h
    mov ax,0Ch
    push ax
    mov ax,62CAh
    mov dx,ds
    push dx
    push ax
    push word ptr [bp-0Ah]
    call mf215
    add sp,8h
    mov cx,10h
    mov ax,word ptr ds:[62CEh]
    sub dx,dx
    div cx
    add ax, offset mi221
    cmp ax,word ptr ds:[4164h]
    ja short lbl293f
    jmp near ptr lbl296f
lbl293f:
    jmp near ptr lbl3D7f
lbl296f:
    mov ax,word ptr ds:[62CEh]
    mov dx,0h
    push dx
    push ax
    call mf230
    add sp,4h
    mov word ptr ds:[4144h],ax
    mov word ptr ds:[4146h],dx
    cmp word ptr ds:[4144h],0h
    jz short lbl2B7f
    jmp near ptr lbl2CFf
lbl2B7f:
    cmp word ptr ds:[4146h],0h
    jz short lbl2C1f
    jmp near ptr lbl2CFf
lbl2C1f:
    push word ptr [bp-0Ah]
    call mf241
    add sp,2h
    jmp near ptr lbl3D7f
lbl2CFf:
    push word ptr ds:[62CCh]
    push word ptr ds:[62CAh]
    push word ptr [bp-0Ah]
    call mf247
    add sp,6h
    push word ptr ds:[62CEh]
    les bx, dword ptr ds:[4144h]
    push word ptr es:[bx+2h]
    push word ptr es:[bx]
    push word ptr [bp-0Ah]
    call mf254
    add sp,8h
    push word ptr [bp-0Ah]
    call mf257
    add sp,2h
    mov ax,word ptr ds:[62D2h]
    mov word ptr ds:[415Eh],ax
    mov ax,word ptr ds:[62D4h]
    mov word ptr ds:[4160h],ax
lbl313f:
    mov ax,word ptr ds:[416Eh]
    and ax, offset mi264
    cmp ax, offset mi265
    jnz short lbl321f
    jmp near ptr lbl39Ef
lbl321f:
    push word ptr ds:[4160h]
    push word ptr ds:[415Eh]
    push word ptr ds:[4146h]
    push word ptr ds:[4144h]
    call mf272
    add sp,8h
    cmp ax, offset mi274
    jnz short lbl341f
    jmp near ptr lbl39Bf
lbl341f:
    mov word ptr [bp-8h],0h
    jmp near ptr lbl34Df
lbl349b:
    add word ptr [bp-8h],1h
lbl34Df:
    cmp word ptr [bp-8h],100h
    jl short lbl357f
    jmp near ptr lbl367f
lbl357f:
    call mf283
    cmp ax, offset mi284
    jnz short lbl364f
    jmp near ptr lbl367f
lbl364f:
    jmp near ptr lbl349b
lbl367f:
    mov ax,word ptr ds:[4182h]
    mov dx,word ptr ds:[4184h]
    mov word ptr ds:[6DEEh],ax
    mov word ptr ds:[6DF0h],dx
    or word ptr ds:[416Eh],30h
    mov ax,word ptr ds:[416Eh]
    and ax,80h
    cmp ax, offset mi295
    jnz short lbl388f
    jmp near ptr lbl39Bf
lbl388f:
    mov word ptr ds:[418Ch],1h
    jmp near ptr lbl391f
lbl391b:
lbl391f:
    cmp word ptr ds:[418Ah],1h
    jz short lbl39Bf
    jmp near ptr lbl391b
lbl39Bf:
    jmp near ptr lbl3D7f
lbl39Ef:
    mov ax,word ptr ds:[416Eh]
    and ax, offset mi305
    cmp ax, offset mi306
    jnz short lbl3ACf
    jmp near ptr lbl3D7f
lbl3ACf:
    push word ptr ds:[4146h]
    push word ptr ds:[4144h]
    call mf311
    add sp,4h
    cmp ax, offset mi313
    jnz short lbl3C4f
    jmp near ptr lbl3D7f
lbl3C4f:
    or word ptr ds:[416Eh],10h
    mov ax,word ptr ds:[4182h]
    mov dx,word ptr ds:[4184h]
    mov word ptr ds:[6DEEh],ax
    mov word ptr ds:[6DF0h],dx
lbl3D7f:
    pop di
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
