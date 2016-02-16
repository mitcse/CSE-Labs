data segment
	stg db "TACOCAT$"
	len db 7
	pal db 00, 00, 00
data ends

extra segment
	rst db 8 dup(00)
extra ends

code segment
assume ds: data, cs: code, es: data
start:  mov ax, data;
		mov ds, ax;

		lea si, stg;
		lea di, rst;

		mov cl, len;

		do:
			movsb;
			dec cl;
			jnz do;

		lea si, stg;
		lea di, rst;

		mov ch, 00h;
		mov cl, len;

		add di, cx;

		cpr:
			cmpsb;
			jne npali;
			sub di, 2;
			dec cl;
			jnz cpr;
			jz pali;

		npali:
			mov pal+2, 99h;
			jmp done;

		pali:
			mov pal+2, 11h;

		done:

		mov ah, 4ch
		int 21h

	code ends
end start