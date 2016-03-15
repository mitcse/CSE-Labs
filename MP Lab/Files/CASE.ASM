data segment
	str1 db "Enter string: $";
	str2 db 15, ?, 15 dup(0);
	str3 db 15, ?, 15 dup(0), '$';
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
		lea di, str3;
		
		mov ch, '$';
		
		do:
			mov al, [si];
			cmp al, ch;
			je done;
			mov ah, [si];
			and al, 40h;
			cmp al, 40h;
			jne next;
			mov al, [si];
			xor al, 20h;
			mov ah, al;
			next:
				mov [di], ah;
				inc di;
				inc si;
				jmp do;
			
		jmp done;
			
		done:
			
			lea dx, str3;
			mov ah, 09h;
			int 21h;
			
			mov ah, 4ch;
			int 21h;
			
	code ends;
end start;