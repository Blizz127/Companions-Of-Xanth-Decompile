_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mjnc:NEAR
    EXTRN mn84:NEAR
mnem_unit:
    push bp
    mov bp,sp
    push ds
    lds dx, dword ptr [bp+6h]
    mov ah,41h
    int 21h
    pop ds
    jmp mjnc
    add byte ptr [di-75h],dl
    in al,dx
    push si
    push di
    sub sp,0Ah
    mov byte ptr [bp-0Ah],0CDh
    mov ax,word ptr [bp+6h]
    mov byte ptr [bp-9h],al
    cmp al,25h
    jz short lbl30f
    cmp al,26h
    jz short lbl30f
    mov byte ptr [bp-8h],0CBh
    jmp short lbl3Cf
lbl30f:
    mov byte ptr [bp-6h],0CBh
    mov byte ptr [bp-7h],44h
    mov byte ptr [bp-8h],44h
lbl3Cf:
    mov word ptr [bp-0Ch],ss
    lea ax,word ptr [bp-0Ah]
    mov word ptr [bp-0Eh],ax
    push ds
    lds di, dword ptr [bp+8h]
    mov ax,word ptr [di]
    mov bx,word ptr [di+2h]
    mov cx,word ptr [di+4h]
    mov dx,word ptr [di+6h]
    mov si,word ptr [di+8h]
    mov di,word ptr [di+0Ah]
    pop ds
    push bp
    clc
    db 0FFh, 5Eh, 0F2h ; override
    pop bp
    cld
    push ds
    push di
    lds di, dword ptr [bp+0Ch]
    mov word ptr [di],ax
    mov word ptr [di+2h],bx
    mov word ptr [di+4h],cx
    mov word ptr [di+6h],dx
    mov word ptr [di+8h],si
    pop word ptr [di+0Ah]
    jc short lbl7Ef
    xor si,si
    jmp short lbl8Df
lbl7Ef:
    pop cx
    push cx
    push ds
    mov ds,cx
    push cs
    call mn84
    pop ds
    mov si,1h
    mov ax,word ptr [di]
lbl8Df:
    mov word ptr [di+0Ch],si
    pop ds
    add sp,0Ah
    pop di
    pop si
    mov sp,bp
    pop bp
    retf
lblCAEAf:
_TEXT ENDS
    END
