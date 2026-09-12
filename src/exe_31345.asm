_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
mnem_unit:
    push bp
    mov bp,sp
    sub sp,2h
    push ds
    push es
    push si
    push di
    mov ax,38AFh
    mov ds,ax
    mov si,52A6h
    mov ax,word ptr [bp+0Ch]
    mov word ptr [si+1Ah],ax
    mov ax,word ptr [bp+0Ah]
    mov word ptr [si+1Ch],ax
    mov ax,word ptr [bp+8h]
    mov word ptr [si+1Eh],ax
    mov ax,word ptr [bp+6h]
    mov word ptr [si+20h],ax
    mov word ptr [bp-2h],0h
    mov ax,word ptr [bp-2h]
    pop di
    pop si
    pop es
    pop ds
    mov sp,bp
    pop bp
    retf 8h
_TEXT ENDS
    END
