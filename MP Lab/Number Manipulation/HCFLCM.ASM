data segment
a dw ?
b dw ?
hcf dw ?
lcm dw ?
data ends

code segment
assume ds:data, cs:code

start: 	mov ax, data
	mov ds, ax

	mov ax, a
	mov bx, b
	
	gloop:
		cmp ax, bx;		Compare	
		je hcfe;		Jump if equal
		jb excg;		Jump to exchange if bx is greater
		
		l2:
			mov dx, 0
			div bx;		Check if ax is divisible by bx
			
			cmp dx, 0;
			je hcfe;	If no remainder, jump to end
			
			mov ax, dx;	Else move the remainder to ax
			
			jmp gloop;	Repeat
		
		excg:
			mov cx, ax;
			mov ax, bx;
			mov bx, cx;
			jmp l2;
	
	hcfe:
		mov hcf, bx;
		mov ax, a;
		mul b;
		div bx;
		mov lcm, ax;	Calculate LCM = a * b / HCF
	
	mov ah, 4ch
	int 21h
code ends
end start
