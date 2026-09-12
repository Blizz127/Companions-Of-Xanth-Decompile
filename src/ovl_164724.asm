_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi3:NEAR
    EXTRN mi4:NEAR
    EXTRN md9:NEAR
    EXTRN md22:NEAR
    EXTRN mf26:FAR
    EXTRN mf32:FAR
    EXTRN mf40:FAR
    EXTRN mf61:FAR
    EXTRN mf69:FAR
    EXTRN mf77:FAR
    EXTRN mf85:FAR
    EXTRN mf93:FAR
    EXTRN mf101:FAR
    EXTRN mf109:FAR
    EXTRN mf111:FAR
    EXTRN mf114:FAR
    EXTRN mf118:FAR
    EXTRN mf124:FAR
    EXTRN mf126:FAR
    EXTRN mf127:FAR
    EXTRN mf133:FAR
    EXTRN mf134:FAR
    EXTRN mf142:FAR
    EXTRN mf150:FAR
    EXTRN mf160:FAR
    EXTRN mf164:FAR
    EXTRN mf164:FAR
    EXTRN mf164:FAR
    EXTRN mf164:FAR
    EXTRN mf164:FAR
    EXTRN mf164:FAR
    EXTRN mf164:FAR
    EXTRN mf164:FAR
    EXTRN mf164:FAR
    EXTRN mf164:FAR
    EXTRN mf164:FAR
    EXTRN mf164:FAR
    EXTRN mf164:FAR
    EXTRN mf164:FAR
    EXTRN mf164:FAR
    EXTRN mf164:FAR
    EXTRN mf164:FAR
    EXTRN mf164:FAR
    EXTRN mf164:FAR
    EXTRN mf164:FAR
    EXTRN mf164:FAR
mnem_unit:
    push bp
    mov bp,sp
    mov ax,word ptr [bp+6h]
    sub ax, offset mi3
    cmp ax, offset mi4
    jna short lbl11f
    jmp near ptr lbl195f
lbl11f:
    add ax,ax
    xchg ax,bx
    jmp word ptr cs:[bx+md9]
    nop
    pusha
    add byte ptr [bp+si-7E00h],al
    add byte ptr [bp+si-4700h],al
    add word ptr [si-4700h],sp
    add word ptr [bx+si+1h],bx
    mov cx,0B901h
    add word ptr [bx+di-46FFh],di
    add word ptr [bx+di-46FFh],di
    add word ptr [bp+si+1h],bp
    test al,1h
    pop ax
    add word ptr [bx+si+md22],di
    push ax
    mov ax,0C5h
    push ax
    call mf26
    mov sp,bp
    mov ax,1h
lbl4Eb:
    mov dx,0F01Ah
    push dx
    push ax
    call mf32
lbl58b:
    mov sp,bp
    jmp near ptr lbl195f
    nop
    mov ax,0Eh
    push ax
    mov ax,0CAh
    push ax
    call mf40
    mov sp,bp
    or ax,ax
    jz short lbl76f
    mov ax,2BC4h
    jmp short lbl79f
lbl76f:
    mov ax,2BCBh
lbl79f:
    push ds
    push ax
    xor ax,ax
    jmp short lbl4Eb
    nop
    cmp word ptr ds:[6A22h],0BEh
    jz short lbl8Bf
    jmp near ptr lbl195f
lbl8Bf:
    xor ax,ax
    push ax
    mov cx,0Ch
    push cx
    mov cx,8026h
    push cx
    call mf61
    mov sp,bp
    xor ax,ax
    push ax
    mov cx,0Dh
    push cx
    mov cx,8026h
    push cx
    call mf69
    mov sp,bp
    xor ax,ax
    push ax
    mov cx,0Eh
    push cx
    mov cx,8026h
    push cx
    call mf77
    mov sp,bp
    xor ax,ax
    push ax
    mov cx,0Fh
    push cx
    mov cx,8026h
    push cx
    call mf85
    mov sp,bp
    xor ax,ax
    push ax
    mov cx,10h
    push cx
    mov cx,8026h
    push cx
    call mf93
    mov sp,bp
    xor ax,ax
    push ax
    mov cx,11h
    push cx
    mov cx,8026h
    push cx
    call mf101
    mov sp,bp
    xor ax,ax
    push ax
    mov ax,0C7h
    push ax
    mov ax,0Ah
    push ax
    call mf109
    mov sp,bp
    call mf111
    mov ax,0Bh
    push ax
    call mf114
    mov sp,bp
    mov ax,1388h
    push ax
    call mf118
    mov sp,bp
    mov ax,5A03h
    push ax
    mov ax,15Dh
    push ax
    call mf124
    jmp near ptr lbl58b
    call mf126
    call mf127
    mov byte ptr ds:[2BB6h],0h
    jmp short lbl195f
    nop
    cmp byte ptr ds:[2BB6h],0h
    jnz short lbl170f
    call mf133
    call mf134
    xor ax,ax
    push ax
    push ax
    mov ax,31h
    push ax
    mov ax,802h
    push ax
    call mf142
    add sp,8h
    mov byte ptr ds:[2BB6h],1h
lbl170f:
    mov ax,1h
    push ax
    mov ax,2BB8h
    push ds
    push ax
    call mf150
    add sp,6h
    jmp short lbl197f
    nop
    mov ax,4h
    push ax
    mov ax,0h
    mov cx,32FCh
    push cx
    push ax
    call mf160
lbl195f:
    xor ax,ax
lbl197f:
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
