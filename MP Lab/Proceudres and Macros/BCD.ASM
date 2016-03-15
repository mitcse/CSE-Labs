data segment
	a db ?
	b db ?
data ends

code segment
assume cs:code, ds:data
	start:
        mov ax, data
        mov ds, ax

        mov al, a
        mov bl, al
		
        mov cl, 04h
        mov bh, 0ah
		
        call bcdp
        jmp done

        bcdp proc near
			and bl, 0fh
			and al, 0f0h
			ror al, cl
			mul bh
			add al, bl
			mov b, al
			ret
        bcdp endp

		done:
			mov ah, 4ch
			int 21h
		
	code ends
end start
