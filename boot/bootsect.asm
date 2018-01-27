
[ org 0x7c00 ]
[bits 16]  
VIDEO_MEMORY equ 0xb8000
KERNEL_OFFSET equ 0x1000
mov bp , 0x9000							;Initializing Stack Location 
mov sp , bp
mov [ BOOT_DRIVE ] , dl
mov si , MSG_REAL_MODE
call print_string 
call load_kernel
mov ax, 0x2401							;enable A20 lines
int 0x15

call switch_to_pm						; Switching to Protected Mode
jmp $									; Jump on current instruciton

;Headers

%include "print/print_string.asm"
%include "print/print_string_pm.asm"
%include "hex/print_hex.asm"
%include "disk_load.asm"
%include "pm.asm"

[ bits 16]

load_kernel :
	mov si , MSG_LOAD_KERNEL
	call print_string
	mov bx , KERNEL_OFFSET
	mov dh , 15
	mov dl , [ BOOT_DRIVE ]
	call disk_load
ret


[ bits 32]

BEGIN_PM :
	push	ax
	mov	al, 2
	out	0x92, al

mov si , MSG_PROT_MODE	
call Putstr					; Use our 32 - bit print routine.
mov si , MSG_PROT_MODE	
call Putstr	
call KERNEL_OFFSET
jmp $
BOOT_DRIVE db 0
MSG_REAL_MODE db "Started in 16 - bit Real Mode " , 0
MSG_PROT_MODE db "Successfully landed in 32 " , 0
MSG_LOAD_KERNEL db "Loading Kernel..", 0
times 510 -( $ - $$ ) db 0 				; Bootsector padding
dw 0xaa55								; Bootsector Magic Number
