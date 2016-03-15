data segment
	num dw ?
	fct dw ?, ?
data ends

code segment
assume cs:code, ds:data;
	start :
		mov ax, data;
		mov ds, ax;

		mov ax, num;
		mov bx, num;
		
        fact proc near

			dec bx;
			jz done;
			mul bx;
			call fact;
			
			ret;
		fact endp
 
		done:
			mov fct, ax;
			mov fct + 1, dx;
			
        mov ah, 4ch;
        int 21h;
		
    code ends
end start
