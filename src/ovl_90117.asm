_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi3:NEAR
    EXTRN mi7:NEAR
    EXTRN mf44:FAR
    EXTRN mf53:FAR
    EXTRN mf67:FAR
    EXTRN mf77:FAR
    EXTRN mf101:FAR
    EXTRN mf108:FAR
    EXTRN mf116:FAR
    EXTRN mf121:FAR
    EXTRN mf128:FAR
    EXTRN mf143:FAR
    EXTRN mf152:FAR
    EXTRN mf161:FAR
    EXTRN mf174:FAR
    EXTRN mf183:FAR
    EXTRN mf190:FAR
    EXTRN mf200:FAR
    EXTRN mf208:FAR
    EXTRN mf211:FAR
    EXTRN mf219:FAR
    EXTRN mf227:FAR
    EXTRN mf240:FAR
    EXTRN mf240:FAR
    EXTRN mf240:FAR
    EXTRN mf240:FAR
    EXTRN mf240:FAR
    EXTRN mf240:FAR
    EXTRN mf240:FAR
    EXTRN mf240:FAR
    EXTRN mf240:FAR
    EXTRN mf240:FAR
    EXTRN mf240:FAR
    EXTRN mf240:FAR
    EXTRN mf240:FAR
    EXTRN mf240:FAR
    EXTRN mf240:FAR
    EXTRN mf240:FAR
    EXTRN mf240:FAR
    EXTRN mf240:FAR
    EXTRN mf240:FAR
    EXTRN mf240:FAR
mnem_unit:
    push bp
    mov bp,sp
    mov ax,word ptr [bp+6h]
    sub ax, offset mi3
    jz short lbl0Ef
    jmp near ptr lbl258f
lbl0Ef:
    mov ax,word ptr ds:[6A06h]
    cmp ax, offset mi7
    jnz short lbl19f
    jmp near ptr lbl252f
lbl19f:
    jna short lbl1Ef
    jmp near ptr lbl258f
lbl1Ef:
    cmp al,2Ch
    jz short lbl5Af
    ja short lbl3Af
    sub al,8h
    jz short lbl5Af
    sub al,7h
    jnz short lbl2Ff
    jmp near ptr lbl13Cf
lbl2Ff:
    sub al,4h
    jnz short lbl36f
    jmp near ptr lbl18Ef
lbl36f:
    jmp near ptr lbl258f
    nop
lbl3Af:
    sub al,38h
    jnz short lbl41f
    jmp near ptr lbl1BCf
lbl41f:
    sub al,7h
    jnz short lbl48f
    jmp near ptr lbl13Cf
lbl48f:
    sub al,2h
    jnz short lbl4Ff
    jmp near ptr lbl1BCf
lbl4Ff:
    sub al,3h
    jnz short lbl56f
    jmp near ptr lbl1F0f
lbl56f:
    jmp near ptr lbl258f
    nop
lbl5Af:
    cmp word ptr ds:[6A06h],2Ch
    jnz short lbl74f
    mov ax,0Eh
    push ax
    push word ptr ds:[6A04h]
    call mf44
    mov sp,bp
    or ax,ax
    jnz short lbl8Ef
lbl74f:
    cmp word ptr ds:[6A06h],8h
    jnz short lblB8f
    mov ax,0Eh
    push ax
    push word ptr ds:[6A04h]
    call mf53
    mov sp,bp
    or ax,ax
    jnz short lblB8f
lbl8Ef:
    cmp word ptr ds:[6A06h],2Ch
    jnz short lbl9Af
    mov ax,2317h
    jmp short lbl9Df
lbl9Af:
    mov ax,231Ch
lbl9Df:
    push ds
    push ax
    push word ptr ds:[6A04h]
    mov ax,12h
    push ax
    call mf67
    add sp,4h
    push dx
    push ax
    mov ax,5Dh
    jmp near ptr lbl1AEf
    nop
lblB8f:
    push word ptr ds:[6A04h]
    mov ax,2h
    push ax
    call mf77
    mov sp,bp
    push dx
    push ax
    cmp word ptr ds:[6A06h],2Ch
    jnz short lblD6f
    mov ax,2322h
    jmp short lblD9f
    nop
lblD6f:
    mov ax,2327h
lblD9f:
    push ds
    push ax
    cmp word ptr ds:[6A06h],2Ch
    jnz short lblE8f
    mov ax,5Fh
    jmp short lblEBf
    nop
lblE8f:
    mov ax,60h
lblEBf:
    mov dx,0F005h
    push dx
    push ax
    mov ax,5Eh
    push dx
    push ax
    call mf101
    mov sp,bp
    cmp word ptr ds:[6A06h],2Ch
    jnz short lbl118f
    mov ax,0Eh
    push ax
    push word ptr ds:[6A04h]
    call mf108
    mov sp,bp
    mov ax,8h
    jmp short lbl12Af
    nop
lbl118f:
    mov ax,0Eh
    push ax
    push word ptr ds:[6A04h]
    call mf116
    mov sp,bp
    mov ax,2Ch
lbl12Af:
    push ax
    push word ptr ds:[6A04h]
    call mf121
lbl134b:
    mov sp,bp
lbl136b:
    mov ax,1h
    jmp near ptr lbl25Af
lbl13Cf:
    mov ax,0Eh
    push ax
    push word ptr ds:[6A04h]
    call mf128
    mov sp,bp
    or ax,ax
    jz short lbl178f
    cmp word ptr ds:[6A06h],0Fh
    jnz short lbl15Cf
    mov ax,232Dh
    jmp short lbl15Ff
    nop
lbl15Cf:
    mov ax,2333h
lbl15Ff:
    push ds
    push ax
    push word ptr ds:[6A04h]
    mov ax,12h
    push ax
    call mf143
    add sp,4h
    push dx
    push ax
    mov ax,64h
    jmp short lbl1AEf
lbl178f:
    push word ptr ds:[6A04h]
    mov ax,2h
    push ax
    call mf152
    mov sp,bp
    push dx
    push ax
    mov ax,65h
    jmp short lbl1AEf
lbl18Ef:
    mov ax,0Eh
    push ax
    push word ptr ds:[6A04h]
    call mf161
    mov sp,bp
    or ax,ax
    jz short lbl1A6f
    mov ax,2308h
    jmp short lbl1A9f
lbl1A6f:
    mov ax,230Fh
lbl1A9f:
    push ds
    push ax
    mov ax,5Bh
lbl1AEb:
lbl1AEf:
    mov dx,0F005h
    push dx
    push ax
    call mf174
    jmp near ptr lbl134b
    nop
lbl1BCf:
    cmp word ptr ds:[6A02h],0FAh
    jnz short lbl1C7f
    jmp near ptr lbl258f
lbl1C7f:
    push word ptr ds:[6A02h]
    mov ax,22h
    push ax
    call mf183
    mov sp,bp
    push dx
    push ax
    push word ptr ds:[6A04h]
    mov ax,2h
    push ax
    call mf190
    add sp,4h
    push dx
    push ax
    mov ax,66h
    jmp short lbl1AEb
    nop
lbl1F0f:
    mov ax,49h
    push ax
    push word ptr ds:[6A04h]
    call mf200
    add sp,4h
    or ax,ax
    jz short lbl224f
    mov ax,61h
    mov dx,0F005h
    push dx
    push ax
    call mf208
    add sp,4h
    push word ptr ds:[6A04h]
    call mf211
    add sp,2h
    jmp near ptr lbl136b
    nop
lbl224f:
    mov ax,0Ah
    push ax
    mov ax,0FAh
    push ax
    call mf219
    add sp,4h
    or ax,ax
    jz short lbl24Cf
    mov ax,62h
lbl23Bb:
    mov dx,0F005h
    push dx
    push ax
    call mf227
    add sp,4h
    jmp near ptr lbl136b
    nop
lbl24Cf:
    mov ax,63h
    jmp short lbl23Bb
    nop
lbl252f:
    mov ax,5Ch
    jmp short lbl23Bb
    nop
lbl258f:
    xor ax,ax
lbl25Af:
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
