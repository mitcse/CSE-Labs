data segment
	a dw ?
	b dw ?
	p dw ?, ?
data ends

stck segment stack
	dw 100 dup(0)
	tos label word
stck ends

code segment
assume cs:code, ds:data, ss:stck
	start: 
		mov ax, data;
		mov ds, ax;
		mov ax, stck;
		mov ss, ax;
		
		lea sp, tos;
		
		mov ax, a;
		push ax;
		mov ax, b;
		push ax;
		
		call multiply;
		mov p, ax;
		mov p + 2, dx;
		
		mov ah, 4ch;
		int 21h;
		
    multiply proc near
		pop cx;
		pop ax;
		pop bx;
		mul bx;
		push cx;
		ret;
    multiply endp
	
    code ends
end start

