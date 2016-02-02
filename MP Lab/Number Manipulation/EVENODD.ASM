data segment
num db ?
evenx db "   Yer number Even!  $"
oddx db "   Yer number Odd!  $"
data ends

code segment
assume ds:data, cs:code

start: 	mov ax, data
	mov ds, ax

	mov al, num;
	and al, 1;
	xor al, 1;
	
	jz nodd;
	
	neven:
	lea dx, evenx;
	mov ah, 09h;
	int 21h;
	jmp endd
	
	nodd:
	lea dx, oddx;
	mov ah, 09h;
	int 21h;
	
	endd:
	mov ah, 4ch
	int 21h
code ends
end start
