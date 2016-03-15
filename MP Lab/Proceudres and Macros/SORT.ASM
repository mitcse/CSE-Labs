data segment
list db 15h,03h,08h,01h,14h
count equ 4
data ends

code segment
assume cs:code,ds:data
start: 
	mov ax,data
    mov ds,ax
    mov dx,count
    call sort
    mov ah,4ch
    int 21h
    sort proc near
   
rep1: 
	mov cx,dx
	lea si,list
rep2: 
	mov al,[si]
    cmp al,[si+1]
	jl do
	xchg [si+1],al
	mov [si],al
	do: inc si
	loop rep2
	dec dx
	jnz rep1
	ret
	sort endp
    
    
	code ends
	end start

