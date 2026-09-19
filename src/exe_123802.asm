_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mnbb:NEAR
    EXTRN mn1d2:NEAR
    EXTRN mf14e:FAR
    EXTRN mffb:FAR
    EXTRN mf212:FAR
    EXTRN mjef:FAR
    EXTRN mn93:NEAR
    EXTRN mnd6:NEAR
    EXTRN mn20f:NEAR
    EXTRN mn40:NEAR
    EXTRN mn10d:NEAR
    EXTRN mn17d:NEAR
    EXTRN mn1fb:NEAR
    EXTRN mjna8:NEAR
    EXTRN mf105:FAR
mnem_unit:
    push bp
    mov bp,sp
    push ax
    push bx
    push cx
    push si
    push ds
    mov si,word ptr cs:[0B78h]
    add si,word ptr cs:[0B7Ah]
    mov ds, cs:[0B7Ch]
    mov ax,word ptr [si-6h]
    inc ax
    lds si, dword ptr cs:[0B88h]
    mov byte ptr [si],al
    mov ax,word ptr [bp+2h]
    mov word ptr [bp-2h],ax
    mov ax,word ptr [bp+4h]
    mov word ptr [bp+2h],ax
    mov ax,7C5h
    mov word ptr [bp+4h],ax
    lea bp,word ptr [bx-4h]
    jmp short lbl5Cf
    pop ax
    popf
    db 2Eh, 0FFh, 2Eh, 8Ch, 0Bh ; override
    call mn40
    retf
    pushf
    sub sp,4h
    push bp
    mov bp,sp
    push ax
    push bx
    push cx
    push si
    push ds
    mov ax,word ptr [bp+6h]
    mov word ptr [bp+2h],ax
    mov ax,word ptr [bp+8h]
    mov word ptr [bp+4h],ax
lbl5Cf:
    mov ax,1DC1h
    mov ds,ax
    mov si,word ptr ds:[0B78h]
    sub si,6h
    jc short lbl9Ef
    mov word ptr ds:[0B78h],si
    add si,word ptr ds:[0B7Ah]
    mov ds, ds:[0B7Ch]
    mov ax,word ptr [si+2h]
    mov word ptr [bp+6h],ax
    mov ax,word ptr [si+4h]
    mov word ptr [bp+8h],ax
    test word ptr cs:[0B78h],0FFFFh
    jz short lbl96f
    sub si,6h
    mov ax,word ptr [si]
    push cs
    pop ds
    push cs
    call mn93
lbl96f:
    pop ds
    pop si
    pop cx
    pop bx
    pop ax
    pop bp
    popf
    ret
lbl9Ef:
    mov ax,3h
    mov cx,2h
    mov bx,word ptr ds:[18h]
    jmp mjna8
    mov word ptr cs:[0B9Eh],es
    mov word ptr cs:[0BA0h],ds
    mov bx,1DC1h
    mov ds,bx
    push ds
    call mnbb
    pop ds
    mov bx,word ptr ds:[0D29h]
    or bx,bx
    jz short lblD2f
    mov cx,ss
    mov dx,sp
    cli
    mov ss,bx
    mov sp,200h
    sti
lblD2f:
    push bx
    push cx
    push dx
    push ds
    call mnd6
    pop ds
    pop dx
    pop cx
    pop bx
    or bx,bx
    jz short lblE7f
    cli
    mov ss,cx
    mov sp,dx
    sti
lblE7f:
    mov es, ds:[0B9Eh]
    mov ds, ds:[0BA0h]
    jmp mjef
    pushf
    cld
    mov es, cs:[0B9Eh]
    call mffb
    mov al,1h
    mov dx,0AE8h
    call mf105
    mov ax,word ptr ds:[0D33h]
    call mn10d
    mov word ptr ds:[0BA8h],bx
    mov ax,word ptr ds:[0D35h]
    mov bx,ax
    shl bx,1
    shl bx,1
    shl bx,1
    shl bx,1
    shl bx,1
    add bx,word ptr cs:[0BA8h]
    mov word ptr ds:[0B78h],0h
    mov word ptr ds:[0B7Ah],bx
    mov ax,word ptr ds:[0D37h]
    add bx,ax
    mov word ptr ds:[0B7Eh],ax
    push ds
    mov ax,cs
    mov es,ax
    xor ax,ax
    mov ds,ax
    mov dx,ax
    mov ax,word ptr cs:[0D33h]
    mov cx,word ptr cs:[0B9Eh]
    call mf14e
    pop ds
    jnc short lbl15Ef
    test word ptr ds:[0D35h],0FFFFh
    jz short lbl163f
lbl15Ef:
    mov byte ptr ds:[0B9Ch],0FFh
lbl163f:
    popf
    ret
    pushf
    cld
    mov ax,3000h
    int 21h
    cmp al,3h
    jc short lbl175f
    mov byte ptr ds:[0B9Dh],0A0h
lbl175f:
    test word ptr ds:[0D27h],100h
    jz short lbl180f
    call mn17d
lbl180f:
    test word ptr ds:[0D27h],2h
    jnz short lbl199f
    mov ax,word ptr ds:[0D2Bh]
    or ax,word ptr ds:[0D2Dh]
    or ax,word ptr ds:[0D2Fh]
    or ax,word ptr ds:[0D31h]
    jz short lbl1D5f
lbl199f:
    mov cx,word ptr ds:[0D33h]
    xor ax,ax
    mov bx,0D39h
    mov ax,0FFFFh
    xor dx,dx
lbl1A7b:
    push cx
    mov cx,word ptr [bx]
    or cx,cx
    jz short lbl1BDf
    cmp ax,cx
    jna short lbl1B4f
    mov ax,cx
lbl1B4f:
    add cx,word ptr [bx+8h]
    cmp dx,cx
    jnc short lbl1BDf
    mov dx,cx
lbl1BDf:
    pop cx
    add bx,12h
    loop lbl1A7b
    mov word ptr ds:[0D0Bh],ax
    mov word ptr ds:[0D0Dh],dx
    test word ptr ds:[0D27h],2h
    jz short lbl1D5f
    call mn1d2
lbl1D5f:
    mov cx,word ptr cs:[0D33h]
    xor ax,ax
    xor si,si
    mov bx,0D39h
lbl1E1b:
    or si,si
    jnz short lbl1F4f
    mov si,word ptr [bx+2h]
    or si,si
    jz short lbl1F4f
    test byte ptr [bx+7h],8h
    jz short lbl1F4f
    mov si,word ptr [si]
lbl1F4f:
    test byte ptr [bx+7h],1h
    jz short lbl1FEf
    push cs
    call mn1fb
lbl1FEf:
    add bx,12h
    inc ax
    loop lbl1E1b
    cmp word ptr ds:[0BA4h],0h
    jnz short lbl212f
    or si,si
    jz short lbl212f
    call mn20f
lbl212f:
    call mf212
    mov ax,word ptr ds:[0D2Bh]
    or ax,word ptr ds:[0D2Dh]
    jz short lbl22Af
    les bx, dword ptr ds:[0D2Bh]
    mov ax,word ptr ds:[0D0Bh]
    mov word ptr es:[bx],ax
lbl22Af:
    mov ax,word ptr ds:[0D2Fh]
    or ax,word ptr ds:[0D31h]
    jz short lbl23Df
    les bx, dword ptr ds:[0D2Fh]
    mov ax,word ptr ds:[0D0Dh]
    mov word ptr es:[bx],ax
lbl23Df:
    push ds
    push si
    lds si, dword ptr cs:[0B84h]
    mov word ptr [si],76Ch
    mov word ptr [si+2h],cs
    lds si, dword ptr cs:[0B80h]
    mov ax,778h
    mov bx,cs
    xchg ax,word ptr [si]
    xchg bx,word ptr [si+2h]
    pop si
    pop ds
    mov word ptr ds:[0B8Ch],ax
    mov word ptr ds:[0B8Eh],bx
    popf
    ret
    push bx
    push cx
    push ds
    mov ax,1DC1h
    mov ds,ax
    mov cx,word ptr ds:[0D33h]
    dec cx
    xor ax,ax
    mov bx,0D39h
lbl277b:
    test byte ptr [bx+7h],2h
    jz short lbl289f
    add ax,2h
    test byte ptr [bx+7h],8h
    jz short lbl289f
    add ax,2h
lbl289f:
    add bx,12h
    loop lbl277b
    add ax,2h
    pop ds
    pop cx
    pop bx
    retf
    push bp
    mov bp,sp
    push ds
    lds dx, dword ptr [bp+6h]
    jmp short lbl2A0f
    push bp
    push ds
lbl2A0f:
    pushf
    push ax
    push bx
    push cx
    push dx
    push di
    push si
    push es
    cld
    mov ax,ds
    mov es,ax
    mov di,dx
    mov ax,1DC1h
    mov ds,ax
    mov ax,word ptr ds:[0B78h]
    stosw
    mov cx,word ptr ds:[0D33h]
    dec cx
    xor dx,dx
    mov bx,0D39h
lbl2C2b:
    test byte ptr [bx+7h],2h
    jz short lbl2D8f
    mov ax,dx
    stosw
    test byte ptr [bx+7h],8h
    jz short lbl2D8f
    mov si,word ptr [bx+2h]
    mov ax,word ptr [si+0Ah]
    stosw
lbl2D8f:
    add bx,12h
    inc dx
    loop lbl2C2b
    pop es
    pop si
    pop di
    pop dx
    pop cx
    pop bx
    pop ax
    popf
    pop ds
    pop bp
    retf
lbl3C6f:
_TEXT ENDS
    END
