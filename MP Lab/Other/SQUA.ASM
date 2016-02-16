; Using MACRO, write ALP to solve 
; P = X^2 + Y^2 where X and Y are 8 bit numbers.

data segment
	xy db 32h, 49h
	p dw ?
data ends

code segment
assume ds: data, cs: code
start:  mov ax, data;
		mov ds, ax;

		; Very frakking important, macros are defined before using them

		sqc macro src, cnt, dest	; Define the macro

			push ax;				; Push regs
			push cx;

			lea si, src;			; Load address of source
			mov cl, cnt;			; Load the count

			mov dest, 0000h;		; Clear the dest

			sqcalc:
				xor ax, ax;			; Clear AX
				mov al, [si];		; Load the numbers
				mul al;				; Multiply by self
				add dest, ax;		; Add to destination
				inc si;				; Increment and decrement
				dec cl;
				jnz sqcalc;

			pop cx;					; Pop regs
			pop ax;

		endm						; end the macro

		sqc xy, 02h, p;				; Call the goddamn macro

		mov ah, 4ch
		int 21h

	code ends
end start