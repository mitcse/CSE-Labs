data segment
	arr db 01h, 07h, 05h, 06h, 03h, 02h
	pos dw 03h
	siz dw 06h
data ends

code segment
assume cs:code, ds:data
start:	mov ax, data
		mov ds, ax
	   
		lea si, arr
		mov cx, siz;
		sub cx, pos;
		add si, cx
		
		dloop: 
			mov al, [si + 1]
			xchg [si], al
			inc si
			dec cx
			jnz dloop
			and al, 00h
			mov [si], al
                   
		mov ah, 4ch
		int 21h
	code ends
end start