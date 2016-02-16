data segment
	stg db "DEADPOOL$"
	len db ?
data ends

code segment
assume ds: data, cs: code, es: data
start:  mov ax, data;
		mov ds, ax;

		lea di, stg;
		mov al, 24h;
		mov bl, 00h;

		do:
			inc bl;
			scasb;
			jnz do;
			jmp done;

		done:
			dec bl;
			mov len, bl;

		mov ah, 4ch
		int 21h

	code ends
end start