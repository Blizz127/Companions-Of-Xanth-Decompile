_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf4:FAR
    EXTRN mf7:FAR
    EXTRN mf13:FAR
    EXTRN mf23:FAR
    EXTRN mf27:FAR
    EXTRN mf39:FAR
    EXTRN mf49:FAR
    EXTRN mf62:FAR
    EXTRN mf74:FAR
    EXTRN mf84:FAR
    EXTRN mf88:FAR
    EXTRN mf99:FAR
    EXTRN mf102:FAR
    EXTRN mf106:FAR
    EXTRN mf112:FAR
    EXTRN mf114:FAR
    EXTRN mf115:FAR
    EXTRN mf124:FAR
    EXTRN mf139:FAR
    EXTRN mf150:FAR
    EXTRN mf154:FAR
    EXTRN mf157:FAR
    EXTRN mf160:FAR
    EXTRN mf162:FAR
    EXTRN mf171:FAR
    EXTRN mf173:FAR
    EXTRN mf174:FAR
    EXTRN mf178:FAR
    EXTRN mf178:FAR
    EXTRN mf178:FAR
    EXTRN mf178:FAR
    EXTRN mf178:FAR
    EXTRN mf178:FAR
    EXTRN mf178:FAR
    EXTRN mf178:FAR
    EXTRN mf178:FAR
    EXTRN mf178:FAR
    EXTRN mf178:FAR
    EXTRN mf178:FAR
    EXTRN mf178:FAR
    EXTRN mf178:FAR
    EXTRN mf178:FAR
    EXTRN mf178:FAR
    EXTRN mf178:FAR
    EXTRN mf178:FAR
    EXTRN mf178:FAR
    EXTRN mf178:FAR
    EXTRN mf178:FAR
    EXTRN mf178:FAR
    EXTRN mf178:FAR
    EXTRN mf178:FAR
    EXTRN mf178:FAR
    EXTRN mf178:FAR
    EXTRN mf178:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,0Eh
    push si
    call mf4
    mov ax,0Ah
    push ax
    call mf7
    add sp,2h
    mov ax,17h
    push ax
    mov ax,0Fh
    push ax
    call mf13
    add sp,4h
    mov ax,0C1h
    push ax
    mov cx,109h
    push cx
    mov cx,1Ah
    push cx
    xor dx,dx
    push dx
    call mf23
    add sp,8h
    xor ax,ax
    push ax
    call mf27
    add sp,2h
    mov ax,0C1h
    push ax
    mov cx,100h
    push cx
    mov dx,1Ah
    push dx
    mov bx,8h
    push bx
    mov si,1h
    push si
    call mf39
    add sp,0Ah
    mov ax,0C1h
    push ax
    mov ax,100h
    push ax
    mov ax,1Ah
    push ax
    mov ax,8h
    push ax
    call mf49
    add sp,8h
    mov word ptr [bp-2h],ax
    mov ax,14h
    push ax
    mov ax,0C0h
    push ax
    mov ax,0FFh
    push ax
    mov ax,1Bh
    push ax
    mov ax,9h
    push ax
    call mf62
    add sp,0Ah
    mov ax,18h
    push ax
    mov ax,0ABh
    push ax
    mov ax,0F8h
    push ax
    mov ax,22h
    push ax
    mov ax,10h
    push ax
    call mf74
    add sp,0Ah
    mov ax,0AAh
    push ax
    mov ax,0F7h
    push ax
    mov ax,23h
    push ax
    mov ax,11h
    push ax
    call mf84
    add sp,8h
    mov word ptr [bp-4h],ax
    push ax
    call mf88
    add sp,2h
    mov ax,30h
    push ax
    mov ax,3265h
    push ds
    push ax
    mov ax,0B0h
    push ax
    mov ax,6Ch
    push ax
    call mf99
    add sp,0Ah
    push word ptr [bp-4h]
    call mf102
    add sp,2h
    mov ax,9h
    push ax
    call mf106
    add sp,2h
    xor ax,ax
    mov dx,0F043h
    push dx
    push ax
    call mf112
    add sp,4h
    call mf114
lbl121b:
    call mf115
    or ax,ax
    jnz short lbl172f
    lea ax,word ptr [bp-8h]
    push ss
    push ax
    lea ax,word ptr [bp-6h]
    push ss
    push ax
    call mf124
    add sp,8h
    or ax,ax
    jz short lbl121b
    lea ax,word ptr [bp-0Eh]
    push ss
    push ax
    lea ax,word ptr [bp-0Ch]
    push ss
    push ax
    lea ax,word ptr [bp-0Ah]
    push ss
    push ax
    push word ptr [bp-8h]
    push word ptr [bp-6h]
    call mf139
    add sp,10h
    or ax,ax
    jz short lbl121b
    cmp word ptr [bp-0Eh],5h
    jnz short lbl121b
    mov ax,word ptr [bp-2h]
    cmp word ptr [bp-0Ah],ax
    jnz short lbl121b
    jmp short lbl177f
    nop
lbl172f:
    call mf150
lbl177f:
    mov ax,1h
    push ax
    push word ptr [bp-2h]
    call mf154
    add sp,4h
    push word ptr [bp-4h]
    call mf157
    add sp,2h
    push word ptr [bp-2h]
    call mf160
    add sp,2h
    call mf162
    mov ax,0C1h
    push ax
    mov ax,109h
    push ax
    mov ax,1Ah
    push ax
    xor ax,ax
    push ax
    call mf171
    add sp,8h
    call mf173
    call mf174
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
