void far helper_0(void);
int far exe_95987(int a)
{
    _asm {
        sub sp,0x10
        mov ax,[bp+0x6]
        mov dx,[bp+0x8]
        cmp [bp+0xa],ax
        jnz short $+10
        cmp [bp+0xc],dx
        jnz short $+5
        jmp lbl11D
lbl16:
        test word ptr [bp+0x10],0xffff
        jnz short $+5
        jmp lbl10D
lbl20:
        mov [bp-0x4],ax
        mov [bp-0x2],dx
        mov cx,[bp+0xa]
        mov bx,[bp+0xc]
        mov [bp-0x8],cx
        mov [bp-0x6],bx
        cmp bx,dx
        jna short $+5
        jmp lblD1
lbl39:
        jc short $+9
        cmp cx,ax
        jc short $+5
        jmp lblD1
lbl42:
        mov ax,[bp+0xe]
        mov dx,[bp+0x10]
        add ax,[bp-0x8]
        adc dx,0x0
        mov cx,0xc
        shl dx,cl
        add dx,[bp-0x6]
        cmp dx,[bp-0x2]
        jc short $+120
        ja short $+7
        cmp ax,[bp-0x4]
        jna short $+113
lbl62:
        mov ax,[bp+0xe]
        mov dx,[bp+0x10]
        add ax,[bp-0x8]
        adc dx,0x0
        shl dx,cl
        add dx,[bp-0x6]
        mov [bp-0x8],ax
        mov [bp-0x6],dx
        sub ax,ax
        mov cx,[bp+0xe]
        add [bp-0x4],cx
        adc ax,[bp+0x10]
        mov cx,0xc
        shl ax,cl
        add [bp-0x2],ax
lbl8C:
        mov ax,[bp+0xe]
        mov dx,[bp+0x10]
        sub word ptr [bp+0xe],0x1
        sbb word ptr [bp+0x10],0x0
        or dx,dx
        jl short $+129
        jg short $+6
        or ax,ax
        jz short $+123
lblA4:
        add word ptr [bp-0x8],-1
        sbb ax,ax
        not ax
        and ax,0x1000
        sub [bp-0x6],ax
        les bx, [bp-0x8]
        mov al,es:[bx]
        add word ptr [bp-0x4],-1
        sbb cx,cx
        not cx
        and cx,0x1000
        sub [bp-0x2],cx
        les bx, [bp-0x4]
        mov es:[bx],al
        jmp short $-65
        nop
        nop
lblD1:
        mov ax,[bp+0xe]
        mov dx,[bp+0x10]
        sub word ptr [bp+0xe],0x1
        sbb word ptr [bp+0x10],0x0
        or dx,dx
        jl short $+60
        jg short $+6
        or ax,ax
        jz short $+54
lblE9:
        les bx, [bp-0x8]
        add word ptr [bp-0x8],0x1
        jnc short $+7
        add word ptr [bp-0x6],0x1000
lblF7:
        mov al,es:[bx]
        les bx, [bp-0x4]
        add word ptr [bp-0x4],0x1
        jnc short $+7
        add word ptr [bp-0x2],0x1000
lbl108:
        mov es:[bx],al
        jmp short $-58
lbl10D:
        push word ptr [bp+0xe]
        push word ptr [bp+0xc]
        push word ptr [bp+0xa]
        push dx
        push ax
        call far ptr helper_0
lbl11D:
    }
}
