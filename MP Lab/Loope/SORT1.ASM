data segment
arr db 05h, 08h, 03h, 02h, 01h, 09h, 07h, 04h
siz db 08h
data ends

code segment
assume cs: code, ds: data;
start: mov ax, data;
	mov ds, ax;
	
	lea si, arr;
	mov dl, siz;
	
	mov ch, 07h;
	mov cl, 00h;
	
	inc si;
	
	oloop:
		mov dh, [si];
		mov cl, ch;
		
		iloop:
			dec cl;
			jz ile;
		
			cmp dh, cl[si];
			jng ile;
		
			mov cl[si + 1], cl[si];
			jmp iloop;
		
		ile: 
			mov cl[si], dh
		
		inc si
		dec ch;
		
		jnz oloop;
	
	mov ah, 4ch;
	int 21h;
code ends
end start;