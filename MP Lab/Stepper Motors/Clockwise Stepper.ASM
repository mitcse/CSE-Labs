data segment
bas equ 0ce00h
porta equ bas+00h
portb equ bas+01h
portc equ bas+02h
ctrl equ bas+03h
phase_a equ 07h
phase_b equ 0bh
phase_c equ 0dh
phase_d equ 0eh
data ends

code segment
assume cs:code, ds:data
start:  mov ax, data
        mov ds, ax
        mov dx, ctrl
        mov al, 80h
        out dx, al
up:     mov al, phase_a
        mov dx, portc
        out dx, al
        call dly
        mov al, phase_b
        mov dx, portc
        out dx, al
        call dly
        mov al, phase_c
        mov dx, portc
        out dx, al
        call dly
        mov al, phase_d
        mov dx, portc
        out dx, al
        call dly

        mov ah, 0bh
        int 21h
        or al, al
        jz up

        mov ah, 4ch
        int 21h

        dly proc near
        mov cx, 4fh
        abv:    push cx
                call help
                pop cx
                loop abv
                ret
        dly endp

        help proc near
        mov cx, 0ffffh
        dly1:   loop dly1
                ret
        help endp

code ends
end start
