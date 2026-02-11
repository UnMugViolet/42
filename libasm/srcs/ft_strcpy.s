section .text
	global ft_strcpy

ft_strcpy:
	mov rax, rdi
	xor rcx, rcx

_loop:
	mov bl, BYTE [rsi + rcx]
	mov BYTE [rdi + rcx], bl
	inc rcx
	cmp bl, 0
	je _return
	jne _loop

_return:
	ret

section .note.GNU-stack
