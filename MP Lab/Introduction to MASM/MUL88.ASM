data segment
a db ?
b db ?
c db ?
data ends

code segment
assume ds:data, cs:code

start: 	mov ax, data
	mov ds, ax

	mov al, a
	mov bl, b
	mul bl
	mov c, al
	mov c+1, ah

	mov ah, 4ch
	int 21h
code ends
end start
