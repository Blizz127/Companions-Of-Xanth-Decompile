_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mf348:FAR
    EXTRN mf2f8:FAR
    EXTRN mf53:FAR
    EXTRN mf196:FAR
    EXTRN mf370:FAR
    EXTRN mf3f9:FAR
    EXTRN mf142:FAR
    EXTRN mf2df:FAR
    EXTRN mf2a0:FAR
    EXTRN mf3ce:FAR
    EXTRN mf3a2:FAR
    EXTRN mf11a:FAR
    EXTRN mf1f0:FAR
    EXTRN mfd2:FAR
    EXTRN mf46:FAR
    EXTRN mf8:FAR
    EXTRN mf284:FAR
    EXTRN mf3aa:FAR
    EXTRN mf7e:FAR
    EXTRN mf306:FAR
    EXTRN mf15e:FAR
    EXTRN mf35e:FAR
    EXTRN mf5e:FAR
    EXTRN mf23b:FAR
    EXTRN mf3c9:FAR
    EXTRN mf1d1:FAR
    EXTRN mf3ed:FAR
    EXTRN mf136:FAR
    EXTRN mf1b5:FAR
    EXTRN mf382:FAR
    EXTRN mf3d3:FAR
    EXTRN mf72:FAR
    EXTRN mf3b:FAR
    EXTRN mf2bc:FAR
    EXTRN mf300:FAR
    EXTRN mf31d:FAR
    EXTRN mf3d8:FAR
    EXTRN mf274:FAR
    EXTRN mf258:FAR
    EXTRN mf314:FAR
    EXTRN mf3b7:FAR
    EXTRN mfba:FAR
    EXTRN mfa2:FAR
    EXTRN mf17a:FAR
    EXTRN mfea:FAR
    EXTRN mf102:FAR
    EXTRN mf1e1:FAR
    EXTRN mf218:FAR
    EXTRN mi10:NEAR
    EXTRN mf8e:FAR
    EXTRN mf1a6:FAR
    EXTRN mf32f:FAR
    EXTRN mf20c:FAR
    EXTRN mf3e1:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,4h
    push di
    push si
    call mf8
    mov ax,word ptr [bp+6h]
    cmp ax, offset mi10
    jnz short lbl18f
    jmp near ptr lbl38Df
lbl18f:
    jna short lbl1Df
    jmp near ptr lbl3DDf
lbl1Df:
    sub al,10h
    jz short lbl2Cf
    sub al,10h
    jnz short lbl28f
    jmp near ptr lbl300f
lbl28f:
    jmp near ptr lbl3DDf
    nop
lbl2Cf:
    cmp word ptr ds:[70h],0h
    jnz short lbl46f
    mov ax,987h
    mov dx,8A7h
    push dx
    push ax
    call mf3b
    add sp,4h
    mov word ptr ds:[70h],ax
lbl46f:
    call mf46
    mov ax,20h
    mov cx,2199h
    push cx
    push ax
    call mf53
    add sp,4h
    xor ax,ax
    push ax
    call mf5e
    add sp,2h
    mov ax,0C7h
    push ax
    mov cx,13Fh
    push cx
    xor dx,dx
    push dx
    push dx
    call mf72
    add sp,8h
    mov ax,0Ah
    push ax
    call mf7e
    add sp,2h
    mov ax,17h
    push ax
    mov cx,0Fh
    push cx
    call mf8e
    add sp,4h
    mov ax,0C7h
    push ax
    mov ax,13Fh
    push ax
    xor ax,ax
    push ax
    push ax
    call mfa2
    add sp,8h
    mov ax,7Dh
    push ax
    mov ax,13Ah
    push ax
    mov cx,4h
    push cx
    mov dx,33h
    push dx
    call mfba
    add sp,8h
    mov ax,97h
    push ax
    mov cx,13Ah
    push cx
    mov dx,80h
    push dx
    mov bx,33h
    push bx
    call mfd2
    add sp,8h
    mov ax,0C3h
    push ax
    mov cx,52h
    push cx
    mov cx,98h
    push cx
    mov dx,33h
    push dx
    call mfea
    add sp,8h
    mov ax,0C3h
    push ax
    mov cx,11Fh
    push cx
    mov cx,98h
    push cx
    mov dx,58h
    push dx
    call mf102
    add sp,8h
    mov ax,0C3h
    push ax
    mov cx,13Ah
    push cx
    mov dx,98h
    push dx
    mov bx,125h
    push bx
    call mf11a
    add sp,8h
    mov ax,10h
    push ax
    mov cx,95h
    push cx
    mov cx,13Bh
    push cx
    mov dx,80h
    push dx
    mov bx,32h
    push bx
    call mf136
    add sp,0Ah
    mov ax,17h
    push ax
    call mf142
    add sp,2h
    mov ax,94h
    push ax
    mov ax,13Ah
    push ax
    mov cx,81h
    push cx
    mov dx,33h
    push dx
    mov bx,2h
    push bx
    call mf15e
    add sp,0Ah
    mov ax,10h
    push ax
    mov cx,7Eh
    push cx
    mov cx,13Bh
    push cx
    mov dx,3h
    push dx
    mov bx,32h
    push bx
    call mf17a
    add sp,0Ah
    mov ax,10h
    push ax
    mov cx,0C4h
    push cx
    mov dx,53h
    push dx
    mov dx,97h
    push dx
    mov bx,32h
    push bx
    call mf196
    add sp,0Ah
    mov ax,98h
    push ax
    mov cx,33h
    push cx
    call mf1a6
    add sp,4h
    xor ax,ax
    push ax
    mov cx,101h
    push cx
    call mf1b5
    add sp,4h
    mov ax,10h
    push ax
    mov cx,0C4h
    push cx
    mov dx,120h
    push dx
    mov dx,97h
    push dx
    mov bx,57h
    push bx
    call mf1d1
    add sp,0Ah
    mov ax,98h
    push ax
    mov cx,58h
    push cx
    call mf1e1
    add sp,4h
    xor ax,ax
    push ax
    mov cx,102h
    push cx
    call mf1f0
    add sp,4h
    mov ax,10h
    push ax
    mov cx,0C4h
    push cx
    mov dx,13Bh
    push dx
    mov dx,97h
    push dx
    mov dx,124h
    push dx
    call mf20c
    add sp,0Ah
    xor ax,ax
    push ax
    push ax
    call mf218
    add sp,4h
    xor ax,ax
    push ax
    mov cx,1h
    push cx
    mov dx,0ADh
    push dx
    mov bx,13Ah
    push bx
    mov si,98h
    push si
    mov si,125h
    push si
    mov di,5h
    push di
    call mf23b
    add sp,0Eh
    xor ax,ax
    push ax
    mov ax,1h
    push ax
    mov ax,0C3h
    push ax
    mov cx,13Ah
    push cx
    mov cx,0ADh
    push cx
    push si
    push di
    call mf258
    add sp,0Eh
    mov ax,10h
    push ax
    mov ax,0C4h
    push ax
    mov ax,2Eh
    push ax
    mov ax,80h
    push ax
    mov ax,3h
    push ax
    call mf274
    add sp,0Ah
    mov ax,81h
    push ax
    mov ax,4h
    push ax
    call mf284
    add sp,4h
    mov ax,0B5h
    push ax
    mov cx,18h
    push cx
    mov dx,0A8h
    push dx
    mov bx,4h
    push bx
    mov si,15h
    push si
    call mf2a0
    add sp,0Ah
    mov ax,0B5h
    push ax
    mov ax,2Dh
    push ax
    mov cx,0A8h
    push cx
    mov cx,19h
    push cx
    mov dx,16h
    push dx
    call mf2bc
    add sp,0Ah
    mov ax,0C3h
    push ax
    mov cx,18h
    push cx
    mov cx,0B6h
    push cx
    mov dx,4h
    push dx
    cmp word ptr ds:[56h],1h
    db 1Bh, 0D2h ; override
    add dx,18h
    push dx
    call mf2df
    add sp,0Ah
    mov ax,0C3h
    push ax
    mov ax,2Dh
    push ax
    mov ax,0B6h
    push ax
    mov ax,19h
    push ax
    push ax
    call mf2f8
    add sp,0Ah
lbl300f:
    call mf300
    push ax
    call mf306
    add sp,2h
    cmp word ptr [bp+6h],10h
    jz short lbl31Df
    call mf314
    or ax,ax
    jz short lbl370f
lbl31Df:
    call mf31d
    mov word ptr [bp-4h],ax
    mov word ptr [bp-2h],dx
    mov ax,6h
    push ax
    xor ax,ax
    push ax
    call mf32f
    add sp,4h
    mov ax,word ptr ds:[5Ah]
    dec ax
    push ax
    mov ax,31h
    push ax
    mov ax,4h
    push ax
    mov cx,2h
    push cx
    call mf348
    add sp,8h
    mov ax,4h
    push ax
    mov ax,2h
    push ax
    push word ptr [bp-2h]
    push word ptr [bp-4h]
    call mf35e
    add sp,8h
    add ax,word ptr ds:[69F8h]
    mov word ptr ds:[5Ah],ax
    mov word ptr ds:[5Ch],ax
lbl370f:
    call mf370
    or ax,ax
    jz short lbl382f
    mov word ptr ds:[66h],1h
    jmp short lbl38Df
    nop
lbl382f:
    call mf382
    mov word ptr ds:[66h],0h
lbl38Df:
    cmp word ptr ds:[56h],0h
    jnz short lbl3C2f
    mov word ptr ds:[69F4h],0h
    mov ax,20h
    mov cx,2199h
    push cx
    push ax
    call mf3a2
    add sp,4h
    call mf3aa
    mov ax,17h
    push ax
    push word ptr ds:[256h]
    call mf3b7
    add sp,4h
    jmp short lbl3DDf
    nop
lbl3C2f:
    cmp word ptr ds:[56h],1h
    jnz short lbl3DDf
    call mf3c9
    call mf3ce
    call mf3d3
    call mf3d8
lbl3DDf:
    mov ax,2h
    push ax
    call mf3e1
    add sp,2h
    mov ax,1h
    push ax
    call mf3ed
    add sp,2h
    mov ax,1h
    push ax
    call mf3f9
    add sp,2h
    pop si
    pop di
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
