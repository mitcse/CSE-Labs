data segment
    a db 39h
    b db 37h
    c db ?, ?
data ends

code segment
start:
    assume cs: code, ds: data
    mov ax, data
    mov ds, ax
    
    mov bl, a
    sub bl, 30h
    mov al, bl
    
    mov cl, b
    sub cl, 30h
    mul cl
    
    aam
    
    mov c, al
    mov c+1, ah
    
    mov ah, 4ch
    int 21h
    
    code ends
end start