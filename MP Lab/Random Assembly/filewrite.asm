data segment
    fname db "DATFILE.txt", 0
    fdata db "OJSORFHOIEWIFJOUHWEOFIJWOEFHSNOIUWFOEYWUEYFGSWNFGYWU$"
    fhand dw ?
    data ends

code segment
    assume cs: code, ds: data   
    
    start:
        mov ax, data
        mov ds, ax
        mov es, ax
        
        lea dx, fname
        mov cx, 0
        mov ah, 3ch
        int 21h
        
        mov fhand, ax
   
        lea dx, fname
        mov al, 0
        mov ah, 3dh
        int 21h
        
        lea dx, fdata
        mov cx, '$'-fdata
        mov bx, fhand
        mov ah, 40h
        int 21h
        
        mov ah, 3eh
        int 21h
        
        mov ah, 4ch
        int 21h
        
        code ends
end start