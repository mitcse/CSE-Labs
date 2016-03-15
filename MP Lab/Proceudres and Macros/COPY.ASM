data segment
	str db 20, ?, 20 dup(0)
	str1 db 'pool.txt'
	blank db ?
	str2 db 'pooh.txt'
data ends

code segment
	assume cs:code, ds:data
	start: 
		mov ax, data
		mov ds, ax
		mov es, ax

		mov dx, offset str1
		mov al, 0
		mov ah, 3dh
		int 21h

		mov bx, ax
		mov ax, 0
		mov ah, 3fh
		mov cx, 20
		mov dx, offset str
		int 21h

		mov dx, offset str
		mov ah, 09h
		int 21h

		lea dx, str2
		mov cx, 0
		mov ah, 3ch

		int 21h

		mov bx, ax
		mov cx, 20
		lea dx, str
		mov ah, 40h
		int 21h

	mov ah, 4ch
	int 21h

	code ends
end start
