[bits 16]
print_hex:
    pusha
    mov al,'0'
    mov ah,0x0e
    int 0x10
    mov al ,'x'
    int 0x10
    mov cx,0x0004
    shift:
        mov bx, dx
        mov cx,0x0002
        mov si,TEMP
load_digit:
        shr dx,0x0004
        and dh, 0x0f
        add dh,0x30
        cmp dh,0x39
        jle nxt
        add dh, 0x07
        nxt:
        mov [si],dh
        inc si
        shl dx,0x0004
        and dh, 0x0f
        add dh,0x30
        cmp dh,0x39
        jle nxt2
        add dh, 0x07
        nxt2:
        mov [si],dh
        inc si
        mov dh,bl
        mov dl,00
        loop load_digit
        mov si,TEMP
        call print_string
    popa  
    ret 
    TEMP db "0000",0
