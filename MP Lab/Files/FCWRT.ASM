data segment
	fname db "DATFILE.TXT", 0;
	fdata db "DAT FILE HAS RANDOM TEXT - LOADS OF RANDOM TEXT$";
data ends

code segment
	assume cs: code, ds: data, es: data;
	start:
		mov ax, data;
		mov ds, ax;
		mov es, ax;
		
		; create
		
		lea dx, fname;
		mov cx, 0;
		mov ah, 3ch;
		int 21h;  
		
		mov bx, ax;
		
		; open
		
		lea dx, fname;
		mov al, 0;
		mov ah, 3dh;
		int 21h;
		
		; write
		
		lea dx, fdata;
		mov cx, 48;
		mov ah, 40h;
		int 21h;
		
		mov ah, 3eh;
		int 21h;
			
		done:
			
			mov ah, 4ch;
			int 21h;
			
	code ends;
end start;