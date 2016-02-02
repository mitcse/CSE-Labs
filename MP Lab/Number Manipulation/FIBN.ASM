data segment
n db ?
a db ?
data ends

code segment
assume ds:data, cs:code

start: 	mov ax, data
	mov ds, ax

	mov dl, n;
	sub dl, 2;
	lea si, a;
	
	mov al, 00h;
	mov bl, 01h;
	mov [si], al;
	inc si;
	mov [si], bl;
	inc si;
	
	floop:
		mov cl, al;
		add cl, bl;
		mov al, bl;
		mov bl, cl;
		mov [si], cl;
		inc si;
		dec dl;
		jnz floop;
		
	mov ah, 4ch
	int 21h
code ends
end start
