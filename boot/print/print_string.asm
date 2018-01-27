[bits 16]

print_string:
   pusha
    repeat:
        mov al,[SI]
        inc SI
        mov bl,al
        cmp al,0
        je next
        mov ah,0x0e
        mov al,bl
        int 0x10 
        jmp repeat
    next:
       popa
        ret
        


