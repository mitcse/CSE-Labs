data segment
	fname db "DATFILE2.TXT", 0;
	str1 db "Enter string: $";
	fdata db 50, ?, 50 dup(0);
	fhand dw ?;
data ends

code segment
	assume cs: code, ds: data, es: data;
	start:
		mov ax, data;
		mov ds, ax;
		mov es, ax;
		
		; get string
		
		lea dx, str1;
		mov ah, 09h;
		int 21h;
		
		lea dx, fdata;
		mov ah, 0ah;
		int 21h;
		
		; open
		
		lea dx, fname;
		mov al, 02h;
		mov ah, 3dh;
		int 21h;
		
		mov fhand, ax;
		mov bx, fhand;
		
		; write
		
		mov al, 02h;
		mov ah, 42h;
		mov cx, 00h;
		mov dx, 00h;
		int 21h;
		
		mov bx, fhand;
		
		lea dx, fdata + 2
		mov cl, [fdata + 1]
		mov ch, 00h
		mov ah, 40h;
		int 21h;
		
		mov ah, 3eh;
		int 21h;
			
		done:
			
			mov ah, 4ch;
			int 21h;
			
	code ends;
end start;