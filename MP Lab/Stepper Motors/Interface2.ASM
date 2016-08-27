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
        mov al, 8ah
        out dx, al

  rpt:
        mov dx, portb
        in al, dx
        cbw
        neg ax
        mov ah, 00h
        mov dx, porta
        out dx, al
        mov ah, 0bh
        int 21h
        or al, al
        jz rpt
        mov ah, 4ch
        int 21h
code ends
end start
