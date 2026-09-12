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
    mov ax,38AFh
    mov es,ax
    mov di,52A6h
    mov word ptr es:[di],0h
    mov word ptr es:[di+8h],0h
    mov word ptr es:[di+0Ah],0h
    mov word ptr es:[di+0Ch],1h
    mov word ptr es:[di+0Eh],0h
    mov word ptr es:[di+10h],1h
    mov word ptr es:[di+12h],0h
    mov word ptr es:[di+14h],0h
    mov word ptr es:[di+16h],0h
    mov word ptr es:[di+18h],0h
    mov word ptr es:[di+1Ah],0h
    mov word ptr es:[di+1Ch],0h
    mov word ptr es:[di+1Eh],3FFh
    mov word ptr es:[di+20h],3FFh
    mov word ptr es:[di+22h],0h
    mov word ptr es:[di+24h],0h
    mov word ptr es:[di+26h],1h
    mov word ptr es:[di+28h],0FFFFh
    mov word ptr es:[di+2Ah],1h
    mov word ptr es:[di+2Ch],0h
    mov word ptr es:[di+2Eh],0h
    mov word ptr es:[di+30h],0h
    mov word ptr es:[di+32h],0h
    mov word ptr es:[di+34h],0h
    mov word ptr es:[di+36h],0h
    mov word ptr es:[di+38h],3FFh
    mov word ptr es:[di+3Ah],3FFh
    mov word ptr es:[di+3Ch],0h
    mov word ptr es:[di+4Eh],1h
    mov word ptr es:[di+50h],3h
    mov word ptr es:[di+52h],1h
    mov word ptr es:[di+54h],1h
    mov word ptr es:[di+56h],1h
    mov word ptr [bp-2h],0h
    mov ax,word ptr [bp-2h]
    pop di
    pop si
    pop es
    pop ds
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
