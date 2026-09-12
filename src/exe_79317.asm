_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi2:NEAR
    EXTRN mi11:NEAR
    EXTRN mi16:NEAR
    EXTRN mi28:NEAR
    EXTRN mi33:NEAR
    EXTRN mf56:FAR
    EXTRN mf78:FAR
    EXTRN mf99:FAR
    EXTRN mf110:FAR
    EXTRN mf117:FAR
    EXTRN mf136:FAR
    EXTRN md148:NEAR
    EXTRN md149:NEAR
    EXTRN mf154:FAR
    EXTRN mi159:NEAR
    EXTRN mi160:NEAR
    EXTRN mi168:NEAR
    EXTRN mi169:NEAR
    EXTRN mi173:NEAR
    EXTRN mi174:NEAR
    EXTRN mi178:NEAR
    EXTRN mf185:FAR
    EXTRN mi187:NEAR
    EXTRN mi193:NEAR
    EXTRN mi194:NEAR
    EXTRN mi198:NEAR
    EXTRN mi199:NEAR
    EXTRN mf206:FAR
    EXTRN mi208:NEAR
    EXTRN mf219:FAR
    EXTRN mf219:FAR
    EXTRN mf219:FAR
    EXTRN mf219:FAR
    EXTRN mf219:FAR
    EXTRN mf219:FAR
    EXTRN mf219:FAR
    EXTRN mf219:FAR
    EXTRN mf219:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp, offset mi2
    push si
    push di
    mov word ptr [bp-4h],1h
    jmp near ptr lblA8f
lbl11b:
    mov word ptr [bp-0Ch],0h
    mov word ptr [bp-0Ah],0h
    mov word ptr [bp-8h],0h
    mov ax,word ptr [bp-4h]
    add ax, offset mi11
    cmp ax,word ptr [bp+6h]
    jl short lbl2Ef
    jmp near ptr lbl7Bf
lbl2Ef:
    mov ax,word ptr [bp-4h]
    add ax, offset mi16
    shl ax,1
    shl ax,1
    mov bx,word ptr [bp+8h]
    mov cx,word ptr [bp+0Ah]
    add bx,ax
    mov es,cx
    les bx, dword ptr es:[bx]
    mov al,byte ptr es:[bx]
    cbw
    mov word ptr [bp-0Ch],ax
    mov ax,word ptr [bp-4h]
    add ax, offset mi28
    cmp ax,word ptr [bp+6h]
    jl short lbl5Af
    jmp near ptr lbl7Bf
lbl5Af:
    mov ax,word ptr [bp-4h]
    add ax, offset mi33
    shl ax,1
    shl ax,1
    mov bx,word ptr [bp+8h]
    mov cx,word ptr [bp+0Ah]
    add bx,ax
    mov es,cx
    mov ax,word ptr es:[bx]
    mov dx,word ptr es:[bx+2h]
    mov word ptr [bp-0Ah],ax
    mov word ptr [bp-8h],dx
lbl7Bf:
    push word ptr [bp-8h]
    push word ptr [bp-0Ah]
    push word ptr [bp-0Ch]
    mov ax,word ptr [bp-4h]
    shl ax,1
    shl ax,1
    mov bx,word ptr [bp+8h]
    mov cx,word ptr [bp+0Ah]
    add bx,ax
    mov es,cx
    push word ptr es:[bx+2h]
    push word ptr es:[bx]
    call mf56
    add sp,0Ah
    add word ptr [bp-4h],1h
lblA8f:
    mov ax,word ptr [bp+6h]
    cmp word ptr [bp-4h],ax
    jnl short lblB3f
    jmp near ptr lbl11b
lblB3f:
    cmp word ptr ds:[4190h],0FFFFFFFFFFFFFFFFh
    jz short lblBDf
    jmp near ptr lblEFf
lblBDf:
    mov ax,12h
    mov dx,2EC4h
    push dx
    push ax
    mov es, ds:[5B3Eh]
    mov al,byte ptr es:[10h]
    cbw
    push ax
    mov ax,8h
    mov dx,2EC4h
    push dx
    push ax
    call mf78
    add sp,0Ah
    cmp word ptr ds:[4190h],0FFFFFFFFFFFFFFFFh
    jz short lblE9f
    jmp near ptr lblEFf
lblE9f:
    mov word ptr ds:[4190h],9h
lblEFf:
    cmp word ptr ds:[4196h],0FFFFFFFFFFFFFFFFh
    jz short lblF9f
    jmp near ptr lbl12Bf
lblF9f:
    mov ax,24h
    mov dx,2EC4h
    push dx
    push ax
    mov es, ds:[5B40h]
    mov al,byte ptr es:[22h]
    cbw
    push ax
    mov ax,16h
    mov dx,2EC4h
    push dx
    push ax
    call mf99
    add sp,0Ah
    cmp word ptr ds:[4196h],0FFFFFFFFFFFFFFFFh
    jz short lbl125f
    jmp near ptr lbl12Bf
lbl125f:
    mov word ptr ds:[4196h],1h
lbl12Bf:
    mov ax,word ptr ds:[4194h]
    push ax
    mov ax,word ptr ds:[4192h]
    push ax
    push word ptr ds:[4190h]
    call mf110
    add sp,6h
    mov ax,word ptr ds:[4198h]
    push ax
    mov ax,word ptr ds:[419Ah]
    push ax
    push word ptr ds:[4196h]
    call mf117
    add sp,6h
    mov word ptr [bp-6h],ax
    cmp word ptr [bp-6h],0h
    jnz short lbl15Ff
    jmp near ptr lbl1C7f
lbl15Ff:
    cmp word ptr ds:[4196h],4h
    jz short lbl169f
    jmp near ptr lbl18Bf
lbl169f:
    push word ptr ds:[419Ah]
    push word ptr ds:[4198h]
    mov ax,0D0h
    mov dx,2EB0h
    push dx
    push ax
    lea ax,word ptr [bp-5Ch]
    mov dx,ss
    push dx
    push ax
    call mf136
    add sp,0Ch
    jmp near ptr lbl18Ff
lbl18Bf:
    mov byte ptr [bp-5Ch],0h
lbl18Ff:
    lea ax,word ptr [bp-5Ch]
    mov dx,ss
    push dx
    push ax
    mov bx,word ptr ds:[4196h]
    shl bx,1
    shl bx,1
    mov es, ds:[5B42h]
    push word ptr es:[bx+md148]
    push word ptr es:[bx+md149]
    mov ax,0E4h
    mov dx,2EB0h
    push dx
    push ax
    call mf154
    add sp,0Ch
    and word ptr ds:[416Eh],0FFFFFFFFFFFFFFF7h
    mov word ptr ds:[4196h],0h
lbl1C7f:
    mov ax,word ptr ds:[416Eh]
    and ax, offset mi159
    cmp ax, offset mi160
    jnz short lbl1D5f
    jmp near ptr lbl1E4f
lbl1D5f:
    cmp word ptr ds:[4196h],4h
    jnz short lbl1DFf
    jmp near ptr lbl1E4f
lbl1DFf:
    and word ptr ds:[416Eh],0FFFFFFFFFFFFFFF7h
lbl1E4f:
    mov ax,word ptr ds:[4190h]
    and ax, offset mi168
    cmp ax, offset mi169
    jnz short lbl1F2f
    jmp near ptr lbl22Cf
lbl1F2f:
    mov ax,word ptr ds:[416Eh]
    and ax, offset mi173
    cmp ax, offset mi174
    jz short lbl200f
    jmp near ptr lbl22Cf
lbl200f:
    mov ax,word ptr ds:[4192h]
    add ax, offset mi178
    mov es, ds:[5B42h]
    mov byte ptr es:[3Eh],al
    mov ax,14h
    mov dx,2EB0h
    push dx
    push ax
    call mf185
    add sp,4h
    cmp ax, offset mi187
    jz short lbl226f
    jmp near ptr lbl22Cf
lbl226f:
    mov ax,0h
    jmp near ptr lbl26Cf
lbl22Cf:
    mov ax,word ptr ds:[4190h]
    and ax, offset mi193
    cmp ax, offset mi194
    jnz short lbl23Af
    jmp near ptr lbl266f
lbl23Af:
    mov ax,word ptr ds:[416Eh]
    and ax, offset mi198
    cmp ax, offset mi199
    jz short lbl248f
    jmp near ptr lbl266f
lbl248f:
    mov ax,74h
    mov dx,2EB0h
    push dx
    push ax
    call mf206
    add sp,4h
    cmp ax, offset mi208
    jz short lbl260f
    jmp near ptr lbl266f
lbl260f:
    mov ax,0h
    jmp near ptr lbl26Cf
lbl266f:
    mov ax,1h
    jmp near ptr lbl26Cf
lbl26Cf:
    pop di
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
