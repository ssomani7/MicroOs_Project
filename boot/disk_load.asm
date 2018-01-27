
disk_load:
	push dx
	
	mov ah,0x02
	mov al,dh
	mov dh,0x00
	mov ch,0x00
	mov cl,0x02
	int 0x13
	
	jc disk_error
	pop dx
	cmp dh,al
	jne disk_error
	
	ret

disk_error:
	mov SI,DISK_ERROR_MSG
	call print_string
	jmp $

DISK_ERROR_MSG db "Disk Read Error!!",0
