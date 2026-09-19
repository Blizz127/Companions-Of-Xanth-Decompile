_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mjna4:NEAR
    EXTRN mjn9b:NEAR
    EXTRN mn44:NEAR
    EXTRN mnb9:NEAR
    EXTRN mjn8e:NEAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,0Eh
    push di
    push si
    les bx, dword ptr ds:[449Ch]
    add bx,word ptr es:[bx+0Ch]
    lea ax,word ptr [bx+25B0h]
    mov word ptr [bp-6h],ax
    mov bx,word ptr ds:[449Ch]
    mov al,byte ptr es:[bx+0Ah]
    mov byte ptr es:[bx+1BAAh],al
    mov al,byte ptr es:[bx+6h]
    mov byte ptr es:[bx+1BABh],al
    mov word ptr es:[bx+2h],2h
    lea ax,word ptr [bx+1BACh]
    push es
    push ax
    sub ax,ax
    mov word ptr [bp-0Eh],ax
    mov word ptr [bp-0Ch],ax
    mov dx,800h
    call mn44
    les bx, dword ptr ds:[449Ch]
    mov word ptr es:[bx+4h],0h
    mov word ptr [bp-0Ah],1000h
    sub si,si
lbl58b:
    les bx, dword ptr ds:[449Ch]
    add bx,word ptr es:[bx+0Ch]
    lea di,word ptr [bp-0Ah]
    push word ptr [bp-0Ah]
    push si
    lea bx,word ptr [bx+si+25B0h]
    push es
    push bx
    push ss
    push di
    mov bx,word ptr ds:[449Ch]
    db 26h, 0FFh, 9Fh, 0A0h, 09h ; override
    pop si
    pop word ptr [bp-0Ah]
    mov di,ax
    or di,di
    jz short lbl92f
    add si,di
    sub word ptr [bp-0Ah],di
    jnz short lbl58b
    mov word ptr [bp-2h],si
    mov cx,si
    jmp mjn8e
    db 0C7h
lbl92f:
    mov word ptr [bp-2h],si
    mov cx,si
    or cx,cx
    jz short lbl9Ef
    jmp mjn9b
lbl9Ef:
    cmp word ptr [bp-0Eh],0h
    jz short lblA7f
    jmp mjna4
lblA7f:
    les bx, dword ptr ds:[449Ch]
    push es
    push bx
    mov al,byte ptr es:[bx+393h]
    sub ah,ah
    mov dx,word ptr es:[bx+99Eh]
    call mnb9
    pop bx
    pop es
    cmp word ptr es:[bx+4h],0h
    jz short lblC9f
    inc word ptr es:[bx+2h]
lblC9f:
    lea ax,word ptr [bx+1BAAh]
    push es
    push ax
    lea ax,word ptr [bx+2h]
    push es
    push ax
    db 26h, 0FFh, 9Fh, 0A4h, 09h ; override
    pop si
    pop di
    mov sp,bp
    pop bp
    ret
lbl211f:
lbl216f:
_TEXT ENDS
    END
