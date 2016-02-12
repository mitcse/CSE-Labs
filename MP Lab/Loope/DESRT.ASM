data segment
	arr db 01h, 02h, 05h, 06h, 07h, 08h
	num db 05h
	siz dw 06h
data ends

code segment
assume cs:code, ds:data
start:	mov ax, data
		mov ds, ax
	   
		lea si, arr
		mov dl, num
		mov dh, 00;
	   
		ploop:
			cmp dl, [si]
			je del
			inc si
			jmp ploop;

		del:
			mov dx, si;
			lea si, arr
			sub dx, si;
			mov cx, siz;
			sub cx, dx;
			add si, dx
		
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