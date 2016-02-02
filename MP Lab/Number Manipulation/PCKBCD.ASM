data segment
bcd db ?, ?, ?, ?
asc db ?, ?
data ends

code segment
assume ds:data, cs:code

start: 	mov ax, data
	mov ds, ax

	mov dl, 2;
	lea si, bcd;
	lea di, asc;
	
	bloop:
		mov al, [si];
		mov ah, [si+1];
		sub ax, 3030h;
		mov cl, 4;
		rol ah, cl;
		add al, ah;
		daa;
		mov [di], al;
		inc di;
		add si, 2;
		dec dl;
		jnz bloop;
		
	mov ah, 4ch
	int 21h
code ends
end start
