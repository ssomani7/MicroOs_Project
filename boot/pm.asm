[ bits 16]

switch_to_pm :							; Switch to protected mode

	cli
	lgdt [ gdt_descriptor ] 			; Load our global descriptor table 	                      
	mov eax , cr0 						; To make the switch to protected mode
	or eax , 0x1 						; the first bit of CR0 , a control register
	mov cr0 , eax
	jmp CODE_SEG : init_pm 


[ bits 32]

; Initialise registers and the stack once in PM.

init_pm :
		mov ax, DATA_SEG
		mov ds, ax
		mov ss,ax
		mov es,ax
		mov fs,ax
		mov gs,ax
		mov ebp, 0x90000
		mov esp, ebp
		call BEGIN_PM 					; Finally , call some well - known label
		%include "gdt.asm"


	