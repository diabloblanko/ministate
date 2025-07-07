global outb
outb:
	mov dx, [esp + 4]
	mov al, [esp + 8]
	out dx, al
	ret
	; 2025:Diabloblanko
