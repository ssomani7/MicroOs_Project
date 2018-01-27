; Global Descriptor Table
gdt_null : 
	dd 0x0 
	dd 0x0

gdt_code : 
dw 0xffff
dw 0x0
db 0x0
db 10011010b ; 1 st flags , type flags
db 11001111b ; 2 nd flags , Limit ( bits 16 -19)
db 0x0


gdt_data : 
		dw 0xffff
		dw 0x0
		db 0x0
		db 10010010b ; 1 st flags , type flags
		db 11001111b ; 2 nd flags , Limit ( bits 16 -19)
		db 0x0
gdt_end :

		gdt_descriptor :
				dw gdt_end - gdt_null - 1
				dd gdt_null



CODE_SEG equ 0x8
DATA_SEG equ 0x10