; Convert dec to binary, Works for decimals upto 65535

data segment
    bcd db 0 dup(10)
    dno dw ?
    bs db ?  
    bin db 0 dup(20)
    mult dw 00h 
    input db "Enter the bcd number: $"
    output db "Binary equivalent: $"
    data ends

code segment
    assume cs: code, ds: data
    start:
        mov ax, data
        mov ds, ax
        
        lea dx, input   
        mov ah, 09h
        int 21h
        
        lea si, bcd
        add si, 09h
        
        ; Get the input character by character
        mov bs, 00h
        inp:
            mov ah, 01h
            int 21h
            cmp al, 0dh
            je fininp
            cmp al, '0'
            jl fininp
            cmp al, '9'
            jg fininp
            inc bs   
            sub al, 30h
            mov [si], al
            dec si
            jmp inp
        
        ; Get the next multiplier
        proc mplier near
            push ax
            push bx
            push cx
            push dx
            mov ax, mult
            cmp ax, 0000h
            jne mply
            mov ax, 000ah
            mov mult, ax
            jmp emplier
            mply:
                mov bx, 000ah
                mov dx, 0000h
                mul bx
                mov mult, ax
            emplier:
                pop dx
                pop cx
                pop bx
                pop ax
            ret
            mplier endp
            
        ; Convert the array like -- 01h 06h 09h -- to 169 = A9H    
        fininp:            
            lea si, bcd
            add si, 09h
            mov ch, 00
            mov cl, bs
            sub si, cx
            inc si
            
            mov dno, 0000
            mov ax, 0000h
            add al, [si]
            mov dno, ax; Store the last digit in the memory
            
            mov ch, 00       
            mov cl, bs
            dec cx
            getdec:
                inc si
                mov ax, 0000h
                mov al, [si]
                call mplier; Get the next multiplier
                mov bx, mult
                mul bx
                add dno, ax
                loop getdec
        
        ; Next line stuff
        mov dl, 0bh
        mov ah, 02h
        int 21h
        mov dl, 0dh
        int 21h
        mov dl, 0ah
        int 21h
        
        ; Print output
        lea dx, output
        mov ah, 09h
        int 21h
         
        ; Convert and store printable string in the memory        
        convert:
            mov ax, dno
            mov bx, 0002h; divisor
            
            lea di, bin
            add di, 19h; Go to the end of bin
            mov [di], '$'; String ending
            dec di
            mov cx, 0000; Store number of binary digits, better for printing
            
            rpconv:
                mov dx, 0000h
                div bx; repeated division
                inc cx
                add dl, '0'; ASCII value
                mov [di], dl
                dec di
                and ax, ax
                jnz rpconv
                
        lea dx, bin
        add dx, 19h
        sub dx, cx; Adjust the digits
        mov ah, 09h
        int 21h; Print the number
        
        ; Store the result in bx, cx, and dx for the glory of Satan
        mov bx, dno
        mov cx, dno
        mov dx, dno            
            
        mov ah, 4ch
        int 21h
      
    code ends
end start
            