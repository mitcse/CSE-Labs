data segment
	str1 db "Enter string: $";
	str2 db 20, ?, 20 dup(0);
	str3 db "Number of words = ", ?, ?, "$";
	cnt db ?
data ends

code segment
	assume cs: code, ds: data, es: data;
	start:
		mov ax, data;
		mov ds, ax;
		mov es, ax;
		
		mov ah, 09h;
		lea dx, str1;
		int 21h;
		
		mov ah, 0ah;
		lea dx, str2;
		int 21h;
		
		lea si, str2;
		mov ah, '$';
		mov al, ' ';
		mov cl, 01h;
		
		do:
			cmp [si], ah;
			je done;
			cmp [si], al;
			je space;
			inc si;
			jmp do;
		jmp done;
		space:
			inc cl;
			inc si;
			jmp do;
			
		done:
			;mov cnt, cl;
			
			add cl, 30h;
			lea si, str3;
			add si, 18;
			mov [si], cl;
			lea dx, str3;
			mov ah, 09h;
			int 21h;
			
			mov ah, 4ch;
			int 21h;
			
	code ends;
end start;