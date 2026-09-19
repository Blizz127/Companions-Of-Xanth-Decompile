_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi3f:NEAR
    EXTRN mib:NEAR
    EXTRN mn13:NEAR
    EXTRN mn6d:NEAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,2h
    push ax
    push di
    push si
    mov di,dx
    cmp ax, offset mib
    jna short lbl1Ef
    mov ax,8h
    call mn13
    sub word ptr [bp-4h],8h
    mov cl,8h
    shr di,cl
lbl1Ef:
    les bx, dword ptr ds:[449Ch]
    mov cx,word ptr es:[bx+4h]
    mov word ptr [bp-2h],cx
    mov ax,di
    shl al,cl
    mov si,word ptr es:[bx+2h]
    or byte ptr es:[bx+si+1BAAh],al
    mov ax,cx
    add ax,word ptr [bp-4h]
    mov word ptr es:[bx+4h],ax
    cmp ax, offset mi3f
    jna short lbl5Bf
    inc si
    mov cl,8h
    sub cl,byte ptr [bp-2h]
    shr di,cl
    mov ax,di
    mov byte ptr es:[bx+si+1BAAh],al
    and word ptr es:[bx+4h],7h
    jmp short lbl63f
    db 0C7h
lbl5Bf:
    and word ptr es:[bx+4h],7h
    jnz short lbl63f
    inc si
lbl63f:
    mov word ptr es:[bx+2h],si
    cmp si,800h
    jc short lbl70f
    call mn6d
lbl70f:
    pop si
    pop di
    mov sp,bp
    pop bp
    ret
_TEXT ENDS
    END
