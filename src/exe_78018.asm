_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi2:NEAR
    EXTRN mi6:NEAR
    EXTRN mi7:NEAR
    EXTRN mf23:FAR
    EXTRN mf30:FAR
    EXTRN mf32:FAR
    EXTRN mf33:FAR
    EXTRN mf38:FAR
    EXTRN mi58:NEAR
    EXTRN mi59:NEAR
    EXTRN mi64:NEAR
    EXTRN mi68:NEAR
    EXTRN mi69:NEAR
    EXTRN mi78:NEAR
    EXTRN mi79:NEAR
    EXTRN mf84:FAR
    EXTRN mi87:NEAR
    EXTRN mf95:FAR
    EXTRN mi98:NEAR
    EXTRN mi99:NEAR
    EXTRN mf102:FAR
    EXTRN mf122:FAR
    EXTRN mf154:FAR
    EXTRN mf172:FAR
    EXTRN mf172:FAR
    EXTRN mf172:FAR
    EXTRN mf172:FAR
    EXTRN mf172:FAR
    EXTRN mf172:FAR
    EXTRN mf172:FAR
    EXTRN mf172:FAR
    EXTRN mf172:FAR
    EXTRN mf172:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp, offset mi2
    push si
    push di
    mov ax,word ptr ds:[416Eh]
    and ax, offset mi6
    cmp ax, offset mi7
    jnz short lbl17f
    jmp near ptr lbl14Ff
lbl17f:
    mov ax,word ptr ds:[416Ch]
    cmp word ptr [bp+6h],ax
    jnz short lbl22f
    jmp near ptr lbl2Bf
lbl22f:
    cmp word ptr [bp+6h],0FFFFFFFFFFFFFFFFh
    jz short lbl2Bf
    jmp near ptr lbl14Ff
lbl2Bf:
    cmp word ptr ds:[4176h],2h
    jz short lbl35f
    jmp near ptr lbl3Ff
lbl35f:
    cmp word ptr ds:[4178h],0h
    jnz short lbl3Ff
    jmp near ptr lbl5Df
lbl3Ff:
    call mf23
    mov ax,0h
    push ax
    mov ax,1h
    push ax
    mov ax,2h
    push ax
    call mf30
    add sp,6h
    call mf32
lbl5Df:
    call mf33
    add ax,7D0h
    adc dx,0h
    mov word ptr [bp-8h],ax
    mov word ptr [bp-6h],dx
lbl6Eb:
    call mf38
    cmp dx,word ptr [bp-6h]
    jng short lbl7Bf
    jmp near ptr lblA9f
lbl7Bf:
    jnl short lbl80f
    jmp near ptr lbl88f
lbl80f:
    cmp ax,word ptr [bp-8h]
    jc short lbl88f
    jmp near ptr lblA9f
lbl88f:
    cmp word ptr ds:[4176h],2h
    jz short lbl92f
    jmp near ptr lblA9f
lbl92f:
    cmp word ptr ds:[4178h],0h
    jz short lbl9Cf
    jmp near ptr lblA9f
lbl9Cf:
    cmp word ptr ds:[4168h],0h
    jg short lblA6f
    jmp near ptr lblA9f
lblA6f:
    jmp near ptr lbl6Eb
lblA9f:
    mov ax,word ptr ds:[416Eh]
    and ax, offset mi58
    cmp ax, offset mi59
    jnz short lblB7f
    jmp near ptr lbl12Bf
lblB7f:
    mov ax,word ptr ds:[416Eh]
    and ax,80h
    cmp ax, offset mi64
    jnz short lblC5f
    jmp near ptr lblFDf
lblC5f:
    mov ax,word ptr ds:[416Eh]
    and ax, offset mi68
    cmp ax, offset mi69
    jnz short lblD3f
    jmp near ptr lblFDf
lblD3f:
    cmp word ptr ds:[418Ah],1h
    jz short lblDDf
    jmp near ptr lblFDf
lblDDf:
    mov word ptr ds:[6DF2h],0h
    mov word ptr ds:[411Eh],1h
lblE9b:
    mov ax,word ptr ds:[416Eh]
    and ax, offset mi78
    cmp ax, offset mi79
    jnz short lblF7f
    jmp near ptr lblFAf
lblF7f:
    jmp near ptr lblE9b
lblFAf:
    jmp near ptr lbl102f
lblFDf:
    call mf84
lbl102f:
    mov ax,word ptr ds:[416Eh]
    and ax,80h
    cmp ax, offset mi87
    jnz short lbl110f
    jmp near ptr lbl123f
lbl110f:
    mov word ptr ds:[418Ch],0h
    jmp near ptr lbl119f
lbl119b:
lbl119f:
    cmp word ptr ds:[418Ah],0h
    jz short lbl123f
    jmp near ptr lbl119b
lbl123f:
    call mf95
    jmp near ptr lbl13Ef
lbl12Bf:
    mov ax,word ptr ds:[416Eh]
    and ax, offset mi98
    cmp ax, offset mi99
    jnz short lbl139f
    jmp near ptr lbl13Ef
lbl139f:
    call mf102
lbl13Ef:
    and word ptr ds:[416Eh],0FFFFFFFFFFFFFF8Fh
    mov word ptr ds:[416Ch],0h
    mov word ptr ds:[415Ah],0h
lbl14Ff:
    mov word ptr [bp-4h],0h
    jmp near ptr lbl1CCf
lbl157b:
    mov bx,word ptr [bp-4h]
    shl bx,1
    shl bx,1
    cmp word ptr [bx+4134h],0h
    jz short lbl168f
    jmp near ptr lbl172f
lbl168f:
    cmp word ptr [bx+4136h],0h
    jnz short lbl172f
    jmp near ptr lbl1C8f
lbl172f:
    mov bx,word ptr [bp-4h]
    shl bx,1
    shl bx,1
    push word ptr [bx+4136h]
    push word ptr [bx+4134h]
    call mf122
    add sp,4h
    mov bx,word ptr [bp-4h]
    shl bx,1
    shl bx,1
    mov ax,word ptr ds:[4144h]
    mov dx,word ptr ds:[4146h]
    cmp word ptr [bx+4134h],ax
    jz short lbl1A0f
    jmp near ptr lbl1B5f
lbl1A0f:
    cmp word ptr [bx+4136h],dx
    jz short lbl1A9f
    jmp near ptr lbl1B5f
lbl1A9f:
    mov word ptr ds:[4144h],0h
    mov word ptr ds:[4146h],0h
lbl1B5f:
    mov bx,word ptr [bp-4h]
    shl bx,1
    shl bx,1
    mov word ptr [bx+4134h],0h
    mov word ptr [bx+4136h],0h
lbl1C8f:
    add word ptr [bp-4h],1h
lbl1CCf:
    cmp word ptr [bp-4h],4h
    jnl short lbl1D5f
    jmp near ptr lbl157b
lbl1D5f:
    cmp word ptr ds:[4144h],0h
    jz short lbl1DFf
    jmp near ptr lbl1E9f
lbl1DFf:
    cmp word ptr ds:[4146h],0h
    jnz short lbl1E9f
    jmp near ptr lbl205f
lbl1E9f:
    push word ptr ds:[4146h]
    push word ptr ds:[4144h]
    call mf154
    add sp,4h
    mov word ptr ds:[4144h],0h
    mov word ptr ds:[4146h],0h
lbl205f:
    mov word ptr ds:[4176h],0h
    mov word ptr ds:[417Ah],0h
    mov word ptr ds:[417Ch],0h
    mov word ptr ds:[4178h],7Fh
    mov word ptr ds:[4186h],0h
    mov word ptr ds:[4188h],0h
    mov ax,word ptr ds:[4162h]
    mov word ptr ds:[4168h],ax
    mov word ptr ds:[415Ah],0h
    mov word ptr ds:[4158h],0h
    pop di
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
