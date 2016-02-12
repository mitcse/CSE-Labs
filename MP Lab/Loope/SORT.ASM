data segment
	arr db 05h, 08h, 03h, 02h, 01h, 09h, 07h, 04h
	siz equ 7
data ends

code segment
assume cs:code,  ds:data
start:  mov ax, data
        mov ds, ax
		
        mov dx, siz
		
        oloop:     
			mov cx, dx
			lea si, arr
			
        iloop:    
                mov al, [si]
                cmp al, [si + 1]
                jl eloop
                xchg al, [si + 1]
                mov [si], al
        eloop:
			add si, 1
			loop iloop;
            dec dx
            jnz oloop;
				
		mov ah, 4ch
		int 21h
		
	code ends
end start
