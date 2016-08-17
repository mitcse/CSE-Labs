data segment
    arr db 5, 8, 6, 3, 2, 1, 7, 4, 6, 4, 9, 0, 1, 6, 7, 3
    size equ 16
    nar db dup(0)    
    data ends

code segment
    start:
        assume cs: code, ds: data
        mov ax, data
        mov ds, ax
        
        lea si, arr
        lea di, nar
        
        call disp
        call sort 
        call disp
        
        mov ah, 4ch
        int 21h
        
        sort proc near
            mov dx, size
            outer:
                mov cx, dx
                lea si, arr
                inner:
                    mov al, [si]
                    cmp al, [si+1]
                    jl cont
                    xchg al, [si+1]
                    mov [si], al
                cont:
                    inc si
                    loop inner
                    dec dx
                    jnz outer
            ret
         sort endp
        
         disp proc near
            push ax
            push cx
            mov ch, 00
            mov cl, size
            rept:
                mov dl, [si]
                add dl, 30h
                mov ah, 02h
                int 21h
                mov dl, 32
                int 21h
                int 21h
                inc si
                loop rept
            mov ah, 02h
            mov dl, 0ah
            int 21h   
            mov dl, 0dh
            int 21h
            pop cx
            pop ax
            ret
         disp endp
         
         code ends
end start