data segment
    dt db ? 
    str db ?, ?, ?, '$'
    data ends

code segment
    start:
    assume cs: code, ds: data
    mov ax, data
    mov ds, ax
    
    mov al, 00h
  
    repeat:
    mov bl, al
    mov dt, al
    call disp
    inc al
    cmp al, 100
    jz quit
    jmp repeat
    
    quit:
    mov ah, 4ch
    int 21h 
    
    disp proc near
        push ax
        lea si, str
        add si, 2   
        mov ah, 00h
        mov al, dt
        mov bx, 10
    convert:
        mov dx, 0000h
        div bx
        add dl, '0'
        cmp dl, '9'
        jbe store
        add dl, 'A'-'0'-10
    store:
        dec si
        mov [si], dl
        and ax, ax
        jnz convert
        lea dx, str
        mov ah, 09h
        int 21h
        mov ah, 02h
        mov dl, 0ah
        int 21h
        mov dl, 0dh
        int 21h
        pop ax 
        ret
    disp endp
    
    code ends
end start