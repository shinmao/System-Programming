global _start:

_start:
	xor rax, rax
	xor rdi, rdi
	xor rsi, rsi
	xor rdx, rdx
	call str
write:
	pop rsi
	mov rax, 1
	mov rdi, 1
	mov rdx, 11
	syscall

; exit
	mov rax, 60
	syscall
str:
	call write
	db "helloworld",0
