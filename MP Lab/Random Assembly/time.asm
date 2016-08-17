data segment
    year dw ?
    month db ?
    day db ?
    hour db ?
    min db ?
    sec db ?
    dt dw ? 
    str db ?, ?, ?, ?, ?, '$'
    data ends

code segment
    assume cs: code, ds: data
    
    start:
        mov ax, data
        mov ds, ax
        
        repeat:
            mov ah, 2ah
            int 21h
            
            mov year, cx
            mov month, dh
            mov day, dl
            
            mov ah, 2ch
            int 21h
            
            mov hour, ch
            mov min, cl
            mov sec, dh
            
            call showtime
            
            mov ah, 0bh
            int 21h
            or al, al
            jz repeat
            
        mov ah, 4ch
        int 21h
        
        showtime proc near
            
            mov ax, year
            mov dt, ax
            call disphx
            
            mov ah, 00
            mov al, month
            mov dt, ax
            call disphx
            
            mov al, day
            mov dt, ax
            call disphx
            
            mov ah, 00
            mov al, hour
            mov dt, ax
            call disphx
            
            mov al, min
            mov dt, ax
            call disphx
            
            mov al, sec
            mov dt, ax
            call disphx
            
            push ax
            mov ah, 02h
            mov dl, 0dh
            int 21h
            pop ax
            
            ret
        endp
        
        disphx proc near
            push ax
            lea si, str
            mov [si], 00
            mov [si+1], 00
            mov [si+2], 00
            mov [si+3], 00
            add si, 4   
            mov ax, dt
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
            pop ax 
            ret
        disphx endp
          
        code ends
end start