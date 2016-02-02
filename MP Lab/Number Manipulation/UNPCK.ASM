data segment
bcd db ?, ?
asc dw ?, ?
n db 02
data ends

code segment
assume ds:data, cs:code

start: 	mov ax, data
	mov ds, ax

	mov cl, 04h
	
	lea si, bcd
	lea di, asc
	
	up: 
	mov ah, 00h
	mov al, [si]
	rol ax, cl;
	shr al, cl;
	add ax, 3030h;
	mov [di], ax;
	inc si
	add di, 2h
	dec n
	jnz up
	
	mov ah, 4ch
	int 21h
code ends
end start
