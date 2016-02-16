
; Write an ALP to find smallest number in a 
; given block of data using near procedure.

data segment
	num db 12h, 14h, 03h, 69h, 42h, 22h, 19h, 20h, 24h, 04h
	siz db 0ah
	sml db ?
data ends

code segment
assume ds: data, cs: code
start:  mov ax, data;
		mov ds, ax;

		lea si, num;	Store address of list
		lea di, sml;	Store address of destination
		mov cl, siz;	Store the count

		call smallest;	Call the goddamn procedure
		jmp finnish;	Finnish it!

		mov ah, 00h;
		mov bh, 00h;

		smallest proc near
			mov al, [si];		Load into al the first element
			up:
				dec cl;			Decrement cl
				jz fns;			If zero, finish proceure
				inc si;			Increment si
				mov bl, [si];	Load [si] to bl
				cmp al, bl;		Compare, change al if bl is less
				jng up;

				mov al, [si];
				jmp up;

			fns:
				mov [di], al;	Copy al to destination
				ret;			Return!
		smallest endp

		finnish:				Finnish!
			mov ah, 4ch
			int 21h

	code ends
end start