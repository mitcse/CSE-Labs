data segment
	a0 dw ?; lower word of number
	a1 dw ?; higher word of number
	b db ?; byte
	quo dw ?
	rem dw ?
data ends

code segment
assume ds: data, cs: code
start:  mov ax, data
		mov ds, ax
		
		mov ax, 0000h; 	clear ax
		mov al, b; 		move the byte to al
		cbw;			convery byte to word
		mov bx, ax;		copy newly formed word to bx
		mov ax, a0;		copy the lower word of dividend to ax
		mov dx, a1;		copy the higher word of dividend to dx
		xor dx, dx;		prevents overflow (maybe?)
		idiv bx;		signed divide dx:ax by bx;
		mov quo, ax;	copy quotient to quo
		mov rem, dx;	copy remainder to rem

		mov ah, 4ch
		int 21h
	code ends
end start