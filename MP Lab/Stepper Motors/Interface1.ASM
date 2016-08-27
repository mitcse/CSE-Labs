data segment
bas equ 0ce00h
porta equ bas+00h
portb equ bas+01h
portc equ bas+02h
ctrl equ bas+03h
data ends

code segment
assume cs:code, ds:data
start:  mov ax, data
        mov ds, ax
        mov dx, ctrl
        mov al, 82h
        out dx, al
rpt:    mov dx, portb
        in al, dx
        cmp al, 1
        jae dispff
        mov dx, porta
        mov al, 00h
        out dx, al
        jmp delay
dispff: mov dx, porta
        mov al, 0ffh
        out dx, al
delay:  mov bx, 0fff1h
lp:     dec bx
        jnz lp

        mov ah, 0bh
        int 21h
        or al, al
        jz rpt
        mov ah, 4ch
        int 21h
code ends
end start
