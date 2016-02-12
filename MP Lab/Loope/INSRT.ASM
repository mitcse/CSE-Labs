data segment
	arr db 01h, 02h, 05h, 06h, 07h, 08h, ?
	num db 03h
	siz equ 6
data ends

code segment
assume cs:code, ds:data
start: mov ax, data
       mov ds, ax
       
	   mov dx, siz
	   
       mov bl, num
       
	   oloop: 
			mov cx, dx
			lea si, arr
		   
			iloop: 
				mov al, [si]
				cmp al, bl
				jl eloop
				
				push ax
				mov al, bl;
				pop bx;
				
				mov [si], al
            
			eloop:
				inc si
				loop iloop
				dec dx
				
				mov [arr + siz], bl;
          
		jnz oloop
                   
		mov ah, 4ch
		int 21h
	code ends
end start