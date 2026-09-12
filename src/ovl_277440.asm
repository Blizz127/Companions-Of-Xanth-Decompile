_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi3:NEAR
    EXTRN mi4:NEAR
    EXTRN md9:NEAR
    EXTRN md21:NEAR
    EXTRN mf25:FAR
    EXTRN mf31:FAR
    EXTRN mf37:FAR
    EXTRN mf45:FAR
    EXTRN mf55:FAR
    EXTRN mf63:FAR
    EXTRN mf67:FAR
    EXTRN mf67:FAR
    EXTRN mf67:FAR
    EXTRN mf67:FAR
    EXTRN mf67:FAR
    EXTRN mf67:FAR
mnem_unit:
    push bp
    mov bp,sp
    mov ax,word ptr [bp+6h]
    sub ax, offset mi3
    cmp ax, offset mi4
    jna short lbl11f
    jmp near ptr lblA0f
lbl11f:
    add ax,ax
    xchg ax,bx
    jmp word ptr cs:[bx+md9]
    nop
    cmp al,byte ptr [bx+si]
    jl short lbl1Ef
lbl1Ef:
    jl short lbl20f
lbl20f:
    jl short lbl22f
lbl22f:
    mov al,byte ptr ds:[0A000h]
    add byte ptr [bx+si-6000h],ah
    add byte ptr [bx+si-6000h],ah
    add byte ptr [bx+si-6000h],ah
    add byte ptr [bx+si-6000h],ah
    add byte ptr [bx+si-6E00h],al
    add byte ptr [bx+si+md21],bh
    push ax
    mov ax,166h
    push ax
    call mf25
    mov sp,bp
    mov ax,1h
    mov dx,0F03Dh
    push dx
    push ax
    call mf31
    mov sp,bp
    mov ax,166h
    push ax
    mov ax,168h
    push ax
    call mf37
    mov sp,bp
    or ax,ax
    jz short lblA0f
    mov ax,2h
lbl6Eb:
    mov dx,0F03Dh
    push dx
    push ax
    call mf45
    mov sp,bp
    jmp short lblA0f
    xor ax,ax
    jmp short lbl6Eb
    mov ax,1h
    push ax
    mov ax,3658h
    push ds
    push ax
    call mf55
    mov sp,bp
    jmp short lblA2f
    mov ax,1h
    push ax
    mov ax,3664h
    push ds
    push ax
    call mf63
lblA0f:
    xor ax,ax
lblA2f:
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
