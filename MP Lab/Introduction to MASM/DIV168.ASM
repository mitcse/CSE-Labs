data segment
a dw ?
b db ?
c db ?
data ends

code segment
assume ds:data, cs:code

start: 	mov ax, data
	mov ds, ax

	mov ax, a
	mov bl, b
	div bl
	mov c, al
	mov c+1, ah

	mov ah, 4ch
	int 21h
code ends
end start
