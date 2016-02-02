data segment
a0 dw ?
a1 dw ?
b dw ?
c dw ?
data ends

code segment
assume ds:data, cs:code

start: 	mov ax, data
	mov ds, ax

	mov ax, a0
	mov dx, a1
	mov bx, b
	div bx
	mov c, ax
	mov c+2, dx

	mov ah, 4ch
	int 21h
code ends
end start
