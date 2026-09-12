_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mn9:NEAR
    EXTRN mn10:NEAR
    EXTRN mn11:NEAR
    EXTRN mn27:NEAR
    EXTRN mn32:NEAR
    EXTRN mn40:NEAR
    EXTRN mn45:NEAR
    EXTRN mn49:NEAR
    EXTRN mn60:NEAR
    EXTRN mn60:NEAR
    EXTRN mn60:NEAR
    EXTRN mn60:NEAR
    EXTRN mn60:NEAR
    EXTRN mn60:NEAR
    EXTRN mn60:NEAR
    EXTRN mn60:NEAR
mnem_unit:
    push bp
    mov bp,sp
    push si
    push di
    push es
    mov bx,word ptr [bp+6h]
    mov byte ptr ds:[41F5h],bl
    cmp bx,4h
    jz short lbl1Bf
    call mn9
    call mn10
    call mn11
lbl1Bf:
    or bx,bx
    jnz short lbl33f
    mov word ptr ds:[41FAh],65Bh
    mov word ptr ds:[41FCh],65Bh
    mov byte ptr ds:[41FEh],0h
    jmp short lbl9Ef
    nop
lbl33f:
    cmp bx,1h
    jnz short lbl55f
    cmp word ptr ds:[4204h],160h
    ja short lbl43f
    jmp short lbl98f
    nop
lbl43f:
    mov word ptr ds:[41FAh],26h
    mov word ptr ds:[41FCh],189h
    call mn27
    jmp short lbl9Ef
    nop
lbl55f:
    cmp bx,2h
    jnz short lbl7Cf
    call mn32
    jnc short lbl62f
    jmp short lbl98f
    nop
lbl62f:
    cmp word ptr ds:[4204h],160h
    jna short lbl98f
    mov word ptr ds:[41FAh],281h
    mov word ptr ds:[41FCh],189h
    call mn40
    jmp short lbl9Ef
    nop
lbl7Cf:
    cmp bx,4h
    jnz short lbl98f
    call mn45
    jc short lbl98f
    mov word ptr ds:[41FAh],710h
    mov word ptr ds:[41FCh],9F1h
    call mn49
    jmp short lbl9Ef
    nop
lbl98f:
    mov ax,0h
    jmp short lblA1f
    nop
lbl9Ef:
    mov ax,1h
lblA1f:
    pop es
    pop di
    pop si
    pop bp
    retf
_TEXT ENDS
    END
