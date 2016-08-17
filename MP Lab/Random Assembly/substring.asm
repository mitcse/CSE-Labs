data segment
	str db "DEADPOOL$" 
	subs db "POO$"
	lent equ 08h
	lens equ 04h 
	fnd db "FOUND!$"
	nfd db "NOT FOUND!$"
data ends

code segment
assume ds: data, cs: code, es: data
start:  mov ax, data;
		mov ds, ax;

		lea si, str 
		mov cx, lent
		
		outer:
		    dec cx
		    jz nfound
		    lea di, subs
		    mov dx, lens
		    inner:
		        dec dx
		        jz found
		        mov al, [si]
		        mov bl, [di]
		        inc si
		        inc di
		        cmp al, bl
		        jz inner
		        jmp outer    
		jmp done
		    
		nfound:
		    lea dx, nfd
		    jmp disp
        
        found:
            lea dx, fnd
        	
        disp:
            mov ah, 09h
		    int 21h
        		    
        done:
    		mov ah, 4ch
    		int 21h

	code ends
end start