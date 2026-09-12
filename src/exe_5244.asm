_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mn11:NEAR
    EXTRN mn14:NEAR
    EXTRN mn20:NEAR
    EXTRN mn23:NEAR
    EXTRN mf24:FAR
    EXTRN mn34:NEAR
    EXTRN mn44:NEAR
    EXTRN mn44:NEAR
    EXTRN mn44:NEAR
    EXTRN mn44:NEAR
    EXTRN mf44:FAR
    EXTRN mn44:NEAR
mnem_unit:
    push bp
    mov bp,sp
    push si
    push di
    mov cx,101h
    mov byte ptr ds:[53F7h],ch
    push cx
    or cl,cl
    jnz short lbl2Ff
    mov si,69DEh
    mov di,69DEh
    call mn11
    mov si,5A18h
    mov di,5A1Ch
    call mn14
    cmp word ptr ds:[59FAh],0D6D6h
    jnz short lbl2Ff
    call word ptr ds:[5A00h]
lbl2Ff:
    mov si,5A1Ch
    mov di,5A1Ch
    call mn20
    mov si,5A1Ch
    mov di,5A1Ch
    call mn23
    call mf24
    or ax,ax
    jz short lbl5Bf
    pop ax
    or ah,ah
    push ax
    jnz short lbl5Bf
    cmp word ptr [bp+6h],0h
    jnz short lbl5Bf
    mov word ptr [bp+6h],0FFh
lbl5Bf:
    call mn34
    pop ax
    or ah,ah
    jnz short lbl6Af
    mov ax,word ptr [bp+6h]
    mov ah,4Ch
    int 21h
lbl6Af:
    pop di
    pop si
    pop bp
    retf
_TEXT ENDS
    END
