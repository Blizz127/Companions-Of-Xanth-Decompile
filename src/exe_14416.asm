_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf15:FAR
    EXTRN mf24:FAR
    EXTRN mf38:FAR
    EXTRN mf56:FAR
    EXTRN mf56:FAR
    EXTRN mf56:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,4h
    push si
    mov ax,word ptr ds:[53E6h]
    mov dx,word ptr ds:[53E8h]
    mov word ptr [bp-4h],ax
    mov word ptr [bp-2h],dx
    or dx,ax
    jz short lbl8Ef
    mov ax,word ptr [bp+8h]
    or ax,word ptr [bp+6h]
    jz short lbl8Ef
    push word ptr [bp+8h]
    push word ptr [bp+6h]
    call mf15
    add sp,4h
    mov si,ax
lbl30b:
    les bx, dword ptr [bp-4h]
    mov ax,word ptr es:[bx+2h]
    or ax,word ptr es:[bx]
    jz short lbl8Ef
    push word ptr es:[bx+2h]
    push word ptr es:[bx]
    call mf24
    add sp,4h
    cmp ax,si
    jna short lbl88f
    les bx, dword ptr [bp-4h]
    les bx, dword ptr es:[bx]
    cmp byte ptr es:[bx+si],3Dh
    jnz short lbl88f
    push si
    push word ptr [bp+8h]
    push word ptr [bp+6h]
    les bx, dword ptr [bp-4h]
    push word ptr es:[bx+2h]
    push word ptr es:[bx]
    call mf38
    add sp,0Ah
    or ax,ax
    jnz short lbl88f
    les bx, dword ptr [bp-4h]
    mov ax,word ptr es:[bx]
    mov dx,word ptr es:[bx+2h]
    add ax,si
    inc ax
    jmp short lbl91f
    nop
lbl88f:
    add word ptr [bp-4h],4h
    jmp short lbl30b
lbl8Ef:
    xor ax,ax
    cwd
lbl91f:
    pop si
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
