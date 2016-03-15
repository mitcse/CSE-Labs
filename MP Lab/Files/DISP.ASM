data segment
	fname db "DATFILE.TXT", 0;
	fdata db 50, ?, 50 dup(0);
data ends

code segment
	assume cs: code, ds: data, es: data;
	start:
		mov ax, data;
		mov ds, ax;
		mov es, ax;
		
		; open
		
		lea dx, fname;
		mov al, 0;
		mov ah, 3dh;
		int 21h;
		
		mov bx, ax;
		
		; read
		
		lea dx, fdata;
		mov cx, 48;
		mov ah, 3fh;
		int 21h;
		
		mov ah, 3eh;
		int 21h;
		
		lea dx, fdata;
		mov ah, 09h;
		int 21h;
			
		done:
			
			mov ah, 4ch;
			int 21h;
			
	code ends;
end start;