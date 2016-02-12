data segment
	lst db 12h, 23h, 34h, 45h, 56h, 67h, ?
	num db 88h
	pos db 3h
data ends

code segment
assume cs:code,ds:data
start: 
	mov ax, data
	mov ds, ax
	
	lea si, lst
	
	dec pos
	mov cl, pos
	mov al, num
      
	dloop: 
		inc si
		dec cl
		jnz dloop
		xchg al, [si]
		xchg al, [si + 1]
	
	mov ah, 4ch	
	int 21h
	
	code ends
end start
