_TEXT SEGMENT BYTE PUBLIC 'CODE'
    ASSUME CS:_TEXT, DS:_TEXT
    PUBLIC mnem_unit
    EXTRN mi4:NEAR
    EXTRN mi12:NEAR
    EXTRN mf18:FAR
    EXTRN mf25:FAR
    EXTRN mf33:FAR
    EXTRN mi39:NEAR
    EXTRN mf56:FAR
    EXTRN mf59:FAR
    EXTRN mi63:NEAR
    EXTRN mi65:NEAR
    EXTRN mi67:NEAR
    EXTRN mf80:FAR
    EXTRN mf84:FAR
    EXTRN mf91:FAR
    EXTRN mf101:FAR
    EXTRN mf110:FAR
    EXTRN mf117:FAR
    EXTRN mf125:FAR
    EXTRN mf142:FAR
    EXTRN mf150:FAR
    EXTRN mf157:FAR
    EXTRN mf167:FAR
    EXTRN md180:NEAR
    EXTRN mi182:NEAR
    EXTRN mf192:FAR
    EXTRN mf213:FAR
    EXTRN mf225:FAR
    EXTRN mf235:FAR
    EXTRN mf247:FAR
    EXTRN mi251:NEAR
    EXTRN mf259:FAR
    EXTRN mi265:NEAR
    EXTRN mi267:NEAR
    EXTRN mi269:NEAR
    EXTRN mf274:FAR
    EXTRN mf282:FAR
    EXTRN mf289:FAR
    EXTRN mf299:FAR
    EXTRN mf299:FAR
    EXTRN mf299:FAR
    EXTRN mf299:FAR
    EXTRN mf299:FAR
    EXTRN mf299:FAR
    EXTRN mf299:FAR
    EXTRN mf299:FAR
    EXTRN mf299:FAR
    EXTRN mf299:FAR
    EXTRN mf299:FAR
    EXTRN mf299:FAR
    EXTRN mf299:FAR
    EXTRN mf299:FAR
    EXTRN mf299:FAR
    EXTRN mf299:FAR
    EXTRN mf299:FAR
    EXTRN mf299:FAR
    EXTRN mf299:FAR
    EXTRN mf299:FAR
    EXTRN mf299:FAR
    EXTRN mf299:FAR
    EXTRN mf299:FAR
    EXTRN mf299:FAR
    EXTRN mf299:FAR
mnem_unit:
    push bp
    mov bp,sp
    sub sp,4h
    mov ax,word ptr [bp+6h]
    sub ax, offset mi4
    jz short lbl16f
    dec ax
    dec ax
    jz short lbl5Cf
    jmp near ptr lbl302f
    nop
lbl16f:
    mov ax,word ptr ds:[6A06h]
    sub ax, offset mi12
    jz short lbl21f
    jmp near ptr lbl302f
lbl21f:
    push word ptr ds:[6A04h]
    mov ax,3h
    push ax
    call mf18
    add sp,4h
    push dx
    push ax
    push word ptr ds:[6A02h]
    mov ax,2h
    push ax
    call mf25
    add sp,4h
    push dx
    push ax
    mov ax,57h
    mov dx,0F00Ch
    push dx
    push ax
    call mf33
    add sp,0Ch
lbl55b:
    mov ax,1h
    jmp near ptr lbl304f
    nop
lbl5Cf:
    mov ax,word ptr ds:[6A06h]
    cmp ax, offset mi39
    jnz short lbl67f
    jmp near ptr lbl1A2f
lbl67f:
    jna short lbl6Cf
    jmp near ptr lbl302f
lbl6Cf:
    sub al,13h
    jz short lbl7Ef
    sub al,31h
    jz short lblDAf
    dec al
    jnz short lbl7Bf
    jmp near ptr lbl19Cf
lbl7Bf:
    jmp near ptr lbl302f
lbl7Ef:
    mov ax,43h
    mov dx,0F00Ch
    push dx
    push ax
    call mf56
    add sp,4h
    push word ptr ds:[6A04h]
    call mf59
    add sp,2h
    dec ax
    jz short lblAEf
    sub ax, offset mi63
    jz short lblB4f
    sub ax, offset mi65
    jz short lblBAf
    sub ax, offset mi67
    jz short lblBAf
    jmp short lblCAf
lblAEf:
    mov ax,45h
    jmp short lblBDf
    nop
lblB4f:
    mov ax,46h
    jmp short lblBDf
    nop
lblBAf:
    mov ax,44h
lblBDf:
    mov dx,0F00Ch
    push dx
    push ax
    call mf80
    add sp,4h
lblCAf:
    mov ax,2Eh
    push ax
    call mf84
    add sp,2h
    jmp near ptr lbl55b
    nop
lblDAf:
    mov ax,1h
    push ax
    push word ptr ds:[6A04h]
    call mf91
    add sp,4h
    or ax,ax
    jz short lblF4f
    mov ax,47h
    jmp near ptr lbl217f
lblF4f:
    mov ax,1h
    push ax
    mov ax,8Bh
    push ax
    call mf101
    add sp,4h
    or ax,ax
    jz short lbl10Ef
    mov ax,48h
    jmp near ptr lbl217f
lbl10Ef:
    mov ax,99h
    push ax
    push word ptr ds:[6A04h]
    call mf110
    add sp,4h
    or ax,ax
    jz short lbl146f
    push word ptr ds:[6A04h]
    mov ax,2h
    push ax
    call mf117
    add sp,4h
    push dx
    push ax
    mov ax,49h
    mov dx,0F00Ch
    push dx
    push ax
    call mf125
    add sp,8h
    jmp short lbl185f
lbl146f:
    cmp word ptr ds:[256h],80h
    jnz short lbl156f
    mov ax,4Bh
    mov dx,0F00Ch
    jmp short lbl15Bf
lbl156f:
    mov ax,2630h
    mov dx,ds
lbl15Bf:
    mov word ptr [bp-4h],ax
    mov word ptr [bp-2h],dx
    push dx
    push ax
    push word ptr ds:[6A04h]
    mov ax,2h
    push ax
    call mf142
    add sp,4h
    push dx
    push ax
    mov ax,4Ah
    mov dx,0F00Ch
    push dx
    push ax
    call mf150
    add sp,0Ch
lbl185f:
    xor ax,ax
    push ax
    mov ax,1h
lbl18Bb:
    push ax
    push word ptr ds:[6A04h]
    call mf157
    add sp,6h
    jmp near ptr lbl55b
    nop
lbl19Cf:
    mov ax,56h
    jmp short lbl217f
    nop
lbl1A2f:
    mov ax,1h
    push ax
    push word ptr ds:[6A04h]
    call mf167
    add sp,4h
    or ax,ax
    jnz short lbl1BCf
    mov ax,4Ch
    jmp short lbl217f
    nop
lbl1BCf:
    mov es, ds:[5AC4h]
    mov bx,word ptr ds:[6A02h]
    mov ax,bx
    add bx,bx
    add bx,ax
    add bx,bx
    cmp byte ptr es:[bx+md180],5h
    jnz short lbl228f
    cmp ax, offset mi182
    jz short lbl214f
    ja short lbl1E3f
    sub al,3h
    jz short lbl1FCf
    sub al,2h
    jz short lbl20Ef
lbl1E3f:
    push word ptr ds:[6A02h]
    mov ax,22h
    push ax
    call mf192
    add sp,4h
    push dx
    push ax
    mov ax,51h
    jmp near ptr lbl2D9f
    nop
lbl1FCf:
    cmp byte ptr ds:[30Ch],0h
    jz short lbl208f
    mov ax,4Fh
    jmp short lbl217f
lbl208f:
    mov ax,50h
    jmp short lbl217f
    nop
lbl20Ef:
    mov ax,4Dh
    jmp short lbl217f
    nop
lbl214f:
    mov ax,4Eh
lbl217f:
    mov dx,0F00Ch
    push dx
    push ax
    call mf213
    add sp,4h
    jmp near ptr lbl55b
    nop
lbl228f:
    cmp ax,9Bh
    jnz short lbl292f
    cmp byte ptr ds:[2F2h],0h
    jnz short lbl292f
    mov ax,52h
    mov dx,0F00Ch
    push dx
    push ax
    call mf225
    add sp,4h
    mov byte ptr ds:[278Ch],1h
    cmp word ptr ds:[256h],9Ah
    jnz short lbl26Cf
    xor ax,ax
    push ax
    mov ax,9Ch
    push ax
    push word ptr ds:[6A02h]
    call mf235
    add sp,6h
    mov byte ptr ds:[278Ah],1h
    jmp near ptr lbl55b
lbl26Cf:
    cmp word ptr ds:[256h],9Ch
    jz short lbl277f
    jmp near ptr lbl55b
lbl277f:
    xor ax,ax
    push ax
    mov ax,9Ah
    push ax
    push word ptr ds:[6A02h]
    call mf247
    add sp,6h
    mov byte ptr ds:[278Bh],1h
    jmp near ptr lbl55b
lbl292f:
    cmp ax, offset mi251
    jnz short lbl2B8f
    cmp word ptr ds:[256h],98h
    jnz short lbl2B8f
    mov ax,53h
    mov dx,0F00Ch
    push dx
    push ax
    call mf259
    add sp,4h
    xor ax,ax
    push ax
    mov ax,9Ah
    jmp near ptr lbl18Bb
lbl2B8f:
    cmp ax, offset mi265
    jz short lbl2EAf
    cmp ax, offset mi267
    jz short lbl2EAf
    cmp ax, offset mi269
    jz short lbl2EAf
    push ax
    mov ax,22h
    push ax
    call mf274
    add sp,4h
    push dx
    push ax
    mov ax,55h
lbl2D9b:
lbl2D9f:
    mov dx,0F00Ch
    push dx
    push ax
    call mf282
    add sp,8h
    jmp near ptr lbl55b
    nop
lbl2EAf:
    push word ptr ds:[6A04h]
    mov ax,2h
    push ax
    call mf289
    add sp,4h
    push dx
    push ax
    mov ax,54h
    jmp short lbl2D9b
    nop
lbl302f:
    xor ax,ax
lbl304f:
    mov sp,bp
    pop bp
    retf
_TEXT ENDS
    END
