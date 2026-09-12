_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi2:NEAR
    EXTRN mf32:FAR
    EXTRN mf41:FAR
    EXTRN mf106:FAR
    EXTRN mf106:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp, offset mi2
    push si
    push di
    cmp word ptr ds:[4186h],0h
    jz short lbl13f
    jmp near ptr lbl9Cf
lbl13f:
    cmp word ptr ds:[4188h],0h
    jz short lbl1Df
    jmp near ptr lbl9Cf
lbl1Df:
    cmp word ptr ds:[4176h],2h
    jz short lbl27f
    jmp near ptr lbl33f
lbl27f:
    mov ax,word ptr ds:[4178h]
    cmp word ptr ds:[4168h],ax
    jng short lbl33f
    jmp near ptr lbl49f
lbl33f:
    cmp word ptr ds:[4176h],1h
    jz short lbl3Df
    jmp near ptr lbl87f
lbl3Df:
    mov ax,word ptr ds:[4178h]
    cmp word ptr ds:[4168h],ax
    jl short lbl49f
    jmp near ptr lbl87f
lbl49f:
    mov ax,word ptr ds:[417Eh]
    mov dx,word ptr ds:[4180h]
    mov word ptr ds:[6DEAh],ax
    mov word ptr ds:[6DECh],dx
    mov ax,word ptr ds:[4168h]
    sub ax,word ptr ds:[4178h]
    push ax
    call mf32
    add sp,2h
    mov word ptr [bp-4h],ax
    mov ax,word ptr [bp-4h]
    cwd
    push dx
    push ax
    push word ptr ds:[417Ch]
    push word ptr ds:[417Ah]
    call mf41
    mov word ptr ds:[4186h],ax
    mov word ptr ds:[4188h],dx
    jmp near ptr lbl99f
lbl87f:
    mov word ptr ds:[4176h],0h
    mov word ptr ds:[417Ah],0h
    mov word ptr ds:[417Ch],0h
lbl99f:
    jmp near ptr lbl157f
lbl9Cf:
    mov ax,word ptr ds:[4182h]
    mov dx,word ptr ds:[4184h]
    sub ax,word ptr ds:[6DEAh]
    sbb dx,word ptr ds:[6DECh]
    cmp dx,word ptr ds:[4188h]
    jnc short lblB4f
    jmp near ptr lbl157f
lblB4f:
    jna short lblB9f
    jmp near ptr lblC2f
lblB9f:
    cmp ax,word ptr ds:[4186h]
    ja short lblC2f
    jmp near ptr lbl157f
lblC2f:
    cmp word ptr ds:[4176h],1h
    jz short lblCCf
    jmp near ptr lblE0f
lblCCf:
    mov ax,word ptr ds:[4178h]
    cmp word ptr ds:[4168h],ax
    jl short lblD8f
    jmp near ptr lblE0f
lblD8f:
    add word ptr ds:[4168h],1h
    jmp near ptr lblFBf
lblE0f:
    cmp word ptr ds:[4176h],2h
    jz short lblEAf
    jmp near ptr lblFBf
lblEAf:
    mov ax,word ptr ds:[4178h]
    cmp word ptr ds:[4168h],ax
    jg short lblF6f
    jmp near ptr lblFBf
lblF6f:
    sub word ptr ds:[4168h],1h
lblFBf:
    mov ax,word ptr ds:[4178h]
    cmp word ptr ds:[4168h],ax
    jnl short lbl107f
    jmp near ptr lbl111f
lbl107f:
    cmp word ptr ds:[4176h],1h
    jnz short lbl111f
    jmp near ptr lbl127f
lbl111f:
    mov ax,word ptr ds:[4178h]
    cmp word ptr ds:[4168h],ax
    jng short lbl11Df
    jmp near ptr lbl148f
lbl11Df:
    cmp word ptr ds:[4176h],2h
    jz short lbl127f
    jmp near ptr lbl148f
lbl127f:
    mov word ptr ds:[4176h],0h
    mov word ptr ds:[417Ah],0h
    mov word ptr ds:[417Ch],0h
    mov word ptr ds:[4186h],0h
    mov word ptr ds:[4188h],0h
    jmp near ptr lbl157f
lbl148f:
    mov ax,word ptr ds:[4186h]
    mov dx,word ptr ds:[4188h]
    add word ptr ds:[6DEAh],ax
    adc word ptr ds:[6DECh],dx
lbl157f:
    pop di
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
