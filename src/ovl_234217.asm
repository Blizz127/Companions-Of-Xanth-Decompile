_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
mnem_unit:
    push bp
    mov bp,sp
    sub sp,0Eh
    push si
    mov word ptr [bp-2h],0h
    les bx, dword ptr [bp+6h]
    mov si,word ptr es:[bx]
    add si,si
    mov ax,word ptr [si+32E6h]
    mov word ptr [bp-6h],ax
    mov ax,word ptr [si+32DEh]
    mov word ptr [bp-4h],ax
    mov cl,byte ptr es:[bx+2h]
    sub ch,ch
    mov word ptr [bp-8h],cx
    add ax,cx
    les bx, dword ptr ds:[5E12h]
    mov cl,byte ptr es:[bx]
    cmp ax,cx
    jc short lbl3Bf
    jmp near ptr lbl119f
lbl3Bb:
lbl3Bf:
    mov ax,word ptr [bp+0Ch]
    cmp word ptr [bp-8h],ax
    jl short lbl46f
    jmp near ptr lbl119f
lbl46f:
    les bx, dword ptr [bp+6h]
    cmp word ptr es:[bx],1h
    jz short lbl55f
    cmp word ptr es:[bx],3h
    jnz short lbl76f
lbl55f:
    mov si,word ptr es:[bx+3h]
    and si,0FFh
    mov ax,si
    add si,si
    add si,ax
    add si,si
    add si,word ptr [bp-8h]
    les bx, dword ptr ds:[5E2Ah]
    cmp byte ptr es:[bx+si+1h],0h
    jz short lbl76f
    jmp near ptr lbl119f
lbl76f:
    les bx, dword ptr [bp+6h]
    cmp word ptr es:[bx],3h
    jnz short lbl9Df
    mov si,word ptr es:[bx+3h]
    and si,0FFh
    mov ax,si
    add si,si
    add si,ax
    add si,si
    add si,word ptr [bp-8h]
    les bx, dword ptr ds:[5E2Ah]
    cmp byte ptr es:[bx+si+7h],0h
    jnz short lbl119f
lbl9Df:
    les bx, dword ptr [bp+6h]
    cmp word ptr es:[bx],4h
    jz short lblACf
    cmp word ptr es:[bx],2h
    jnz short lblCAf
lblACf:
    mov si,word ptr es:[bx+3h]
    and si,0FFh
    mov ax,si
    add si,si
    add si,ax
    add si,si
    add si,word ptr [bp-8h]
    les bx, dword ptr ds:[5E2Ah]
    cmp byte ptr es:[bx+si+2h],0h
    jnz short lbl119f
lblCAf:
    les bx, dword ptr [bp+6h]
    cmp word ptr es:[bx],4h
    jnz short lblF1f
    mov si,word ptr es:[bx+3h]
    and si,0FFh
    mov ax,si
    add si,si
    add si,ax
    add si,si
    add si,word ptr [bp-8h]
    les bx, dword ptr ds:[5E2Ah]
    cmp byte ptr es:[bx+si+8h],0h
    jnz short lbl119f
lblF1f:
    les bx, dword ptr [bp+6h]
    inc byte ptr es:[bx+2h]
    mov word ptr [bp-2h],1h
    mov al,byte ptr es:[bx+2h]
    sub ah,ah
    mov word ptr [bp-8h],ax
    add ax,word ptr [bp-4h]
    les bx, dword ptr ds:[5E12h]
    sub ch,ch
    mov cl,byte ptr es:[bx]
    cmp ax,cx
    jnc short lbl119f
    jmp near ptr lbl3Bb
lbl119f:
    les bx, dword ptr [bp+6h]
    cmp byte ptr es:[bx+2h],0h
    jz short lbl183f
lbl123b:
    les bx, dword ptr [bp+6h]
    sub ah,ah
    mov al,byte ptr es:[bx+2h]
    mov word ptr [bp-8h],ax
    cmp ax,word ptr [bp+0Ch]
    jng short lbl183f
    mov bl,byte ptr es:[bx+3h]
    sub bh,bh
    mov word ptr [bp-0Eh],bx
    mov ax,bx
    add bx,bx
    add bx,ax
    add bx,bx
    add bx,word ptr [bp-8h]
    mov es, ds:[5E2Ch]
    add bx,word ptr ds:[5E2Ah]
    mov word ptr [bp-0Ch],bx
    mov word ptr [bp-0Ah],es
    cmp byte ptr es:[bx-1h],ah
    jnz short lbl183f
    les bx, dword ptr [bp+6h]
    cmp word ptr es:[bx],4h
    jz short lbl16Bf
    cmp word ptr es:[bx],3h
    jnz short lbl175f
lbl16Bf:
    les bx, dword ptr [bp-0Ch]
    cmp byte ptr es:[bx+5h],0h
    jnz short lbl183f
lbl175f:
    mov word ptr [bp-2h],1h
    les bx, dword ptr [bp+6h]
    dec byte ptr es:[bx+2h]
    jnz short lbl123b
lbl183f:
    les bx, dword ptr [bp+6h]
    sub ah,ah
    mov al,byte ptr es:[bx+3h]
    mov word ptr [bp-0Eh],ax
    add ax,word ptr [bp-6h]
    les bx, dword ptr ds:[5E12h]
    sub ch,ch
    mov cl,byte ptr es:[bx+1h]
    cmp ax,cx
    jc short lbl1A3f
    jmp near ptr lbl27Ef
lbl1A3b:
lbl1A3f:
    mov ax,word ptr [bp+0Ah]
    cmp word ptr [bp-0Eh],ax
    jl short lbl1AEf
    jmp near ptr lbl27Ef
lbl1AEf:
    les bx, dword ptr [bp+6h]
    cmp word ptr es:[bx],1h
    jz short lbl1BDf
    cmp word ptr es:[bx],2h
    jnz short lbl1DDf
lbl1BDf:
    mov si,word ptr [bp-0Eh]
    mov ax,si
    add si,si
    add si,ax
    add si,si
    sub ah,ah
    mov al,byte ptr es:[bx+2h]
    add si,ax
    les bx, dword ptr ds:[5E2Ah]
    cmp byte ptr es:[bx+si+6h],ah
    jz short lbl1DDf
    jmp near ptr lbl27Ef
lbl1DDf:
    les bx, dword ptr [bp+6h]
    cmp word ptr es:[bx],2h
    jnz short lbl203f
    mov si,word ptr [bp-0Eh]
    mov ax,si
    add si,si
    add si,ax
    add si,si
    sub ah,ah
    mov al,byte ptr es:[bx+2h]
    add si,ax
    les bx, dword ptr ds:[5E2Ah]
    cmp byte ptr es:[bx+si+7h],ah
    jnz short lbl27Ef
lbl203f:
    les bx, dword ptr [bp+6h]
    cmp word ptr es:[bx],4h
    jz short lbl212f
    cmp word ptr es:[bx],3h
    jnz short lbl22Ff
lbl212f:
    mov si,word ptr [bp-0Eh]
    mov ax,si
    add si,si
    add si,ax
    add si,si
    sub ah,ah
    mov al,byte ptr es:[bx+2h]
    add si,ax
    les bx, dword ptr ds:[5E2Ah]
    cmp byte ptr es:[bx+si+0Ch],ah
    jnz short lbl27Ef
lbl22Ff:
    les bx, dword ptr [bp+6h]
    cmp word ptr es:[bx],4h
    jnz short lbl255f
    mov si,word ptr [bp-0Eh]
    mov ax,si
    add si,si
    add si,ax
    add si,si
    sub ah,ah
    mov al,byte ptr es:[bx+2h]
    add si,ax
    les bx, dword ptr ds:[5E2Ah]
    cmp byte ptr es:[bx+si+0Dh],ah
    jnz short lbl27Ef
lbl255f:
    les bx, dword ptr [bp+6h]
    inc byte ptr es:[bx+3h]
    mov word ptr [bp-2h],1h
    mov al,byte ptr es:[bx+3h]
    sub ah,ah
    mov word ptr [bp-0Eh],ax
    add ax,word ptr [bp-6h]
    les bx, dword ptr ds:[5E12h]
    sub ch,ch
    mov cl,byte ptr es:[bx+1h]
    cmp ax,cx
    jnc short lbl27Ef
    jmp near ptr lbl1A3b
lbl27Ef:
    les bx, dword ptr [bp+6h]
    cmp byte ptr es:[bx+3h],0h
    jz short lbl2E8f
lbl288b:
    les bx, dword ptr [bp+6h]
    sub ah,ah
    mov al,byte ptr es:[bx+3h]
    mov word ptr [bp-0Eh],ax
    cmp ax,word ptr [bp+0Ah]
    jng short lbl2E8f
    mov bx,ax
    add bx,ax
    add bx,ax
    mov si,word ptr [bp+6h]
    add bx,bx
    mov al,byte ptr es:[si+2h]
    mov word ptr [bp-8h],ax
    add bx,ax
    mov es, ds:[5E2Ch]
    add bx,word ptr ds:[5E2Ah]
    mov word ptr [bp-0Ch],bx
    mov word ptr [bp-0Ah],es
    cmp byte ptr es:[bx-6h],ah
    jnz short lbl2E8f
    les bx, dword ptr [bp+6h]
    cmp word ptr es:[bx],4h
    jz short lbl2D0f
    cmp word ptr es:[bx],2h
    jnz short lbl2DAf
lbl2D0f:
    les bx, dword ptr [bp-0Ch]
    cmp byte ptr es:[bx-5h],0h
    jnz short lbl2E8f
lbl2DAf:
    mov word ptr [bp-2h],1h
    les bx, dword ptr [bp+6h]
    dec byte ptr es:[bx+3h]
    jnz short lbl288b
lbl2E8f:
    mov ax,word ptr [bp-2h]
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
