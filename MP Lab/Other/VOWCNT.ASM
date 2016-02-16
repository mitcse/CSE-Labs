; Write an assembly language program to count 
; number of vowels in a given string.

data segment
	string db "NOW YOU LOOK AT THAT, OKAY NO$"
	len db 29
	vowel db "AEIOUaeiou$"
	count db ?
data ends

code segment
assume ds: data, cs: code
start:  mov ax, data;
		mov ds, ax;

		mov count, 00h;

		mov cl, len;
		lea si, string;

		oloop:
			
			lea di, vowel;
			mov dl, 0Ah;

			iloop:
				mov al, [si];
				mov bl, [di];
				cmp al, bl;
				jne endil;
				add count, 01h;
				endil:
					inc di;
					dec dl;
				jnz iloop;

			inc si;
			dec cl;
			jnz oloop;

		mov ah, 4ch
		int 21h

	code ends
end start