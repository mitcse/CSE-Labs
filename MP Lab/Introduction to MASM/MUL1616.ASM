data segment
a dw ?
b dw ?
c dw ?
data ends

code segment
assume ds:data, cs:code

start: 	mov ax,data
	mov ds,ax

	mov ax, a
	mov bx, b
	mul bx
	mov c, ax
	mov c+2, dx

	mov ah, 4ch
	int 21h
code ends
end start
